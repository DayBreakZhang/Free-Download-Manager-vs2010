/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsDownloadMgr.h"
#include "inetutil.h"
#include "misc.h"
#include "Hash\vmsHash.h"

#ifndef FDM_DLDR__RAWCODEONLY
#include "DownloadsWnd.h"
#include "AERDlg.h"
#include "SCRDlg.h"
#include "MyMessageBox.h"
#include "vmsMaliciousDownloadChecker.h"	
#endif

#include "fsdownloadsmgr.h"
#include <mlang.h>
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsCriticalSectionEx fsDownloadMgr::m_csRenameFile;

fsDownloadMgr::fsDownloadMgr(struct fsDownload* dld)
{
	m_iThread = 0;
	m_bThreadRunning = FALSE;
	m_dwState = DS_STOPPED;
	m_dld = dld;

	m_dldr.SetEventFunc (_DownloaderEvents, this);

	ZeroMemory (&m_dp, sizeof (m_dp));
	m_dp.wStructSize = sizeof (m_dp);
	fsDP_BuffersInfo bi;
	fsDP_GetDefaults (&m_dp, &bi, TRUE);

	ZeroMemory (m_dldr.DNP (), sizeof (fsDownload_NetworkProperties));

	m_dwState = 0;

	m_hOutFile = INVALID_HANDLE_VALUE;

	m_pfnEvents = NULL;
	m_pfnEventDesc = NULL;
	m_uNeedStartFrom = 0;
	m_dwDownloadFileFlags = DFF_NEED_INIT_FILE;
	m_bFatalError = FALSE;

	m_bCantStart = FALSE;

	m_uMirrRecalcSpeedTime = 60;

	m_tikLastMirrMeasureTime.Now ();
	m_bNeedStartAgain = FALSE;
	m_bRename_CheckIfRenamed = FALSE;

	#ifndef FDM_DLDR__RAWCODEONLY
	m_mdc = NULL;
	#endif

	m_bKnownFileSharingSiteSupportAdjusted = false;

	m_bDontCreateNewSections = FALSE;
	m_dldr.SetManagerPersistObject(this);

	m_bFailedToCreateDestinationFile = false;
	m_bIsNotEnoughDiskSpace = false;
}

fsDownloadMgr::~fsDownloadMgr()
{
	m_dldr.SetEventFunc (NULL, NULL);

	StopDownloading ();
	for (int i = 0; i < 10*1000 / 10 && m_iThread; i++)
	{
#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
		MSG msg;
		while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);
#endif

		Sleep (10);
	}

	CloseFile ();
	SAFE_DELETE_ARRAY (m_dp.pszFileName);
	SAFE_DELETE_ARRAY (m_dp.pszAdditionalExt);
	SAFE_DELETE_ARRAY (m_dp.pszCreateExt);
	fsDNP_GetByUrl_Free (m_dldr.DNP ());
}

fsDownload_NetworkProperties* fsDownloadMgr::GetDNP()
{
	return m_dldr.DNP ();
}

fsDownload_Properties* fsDownloadMgr::GetDP()
{
	return &m_dp;
}

fsInternetResult fsDownloadMgr::StartDownloading()
{
	if (IsRunning () || m_dldr.IsDone () || IsQueringSize ())
		return IR_S_FALSE;

	setStateFlagsTo (DS_NEEDSTART);
	setDirty();

	DWORD dwThread;
	m_bThreadRunning = TRUE;
	InterlockedIncrement (&m_iThread);
	CloseHandle (CreateThread (NULL, 0, _threadDownloadMgr, this, 0, &dwThread));
	
	return IR_SUCCESS;
}

fsInternetResult fsDownloadMgr::CreateInternetSession()
{
	InternetAutodial (INTERNET_AUTODIAL_FORCE_ONLINE, NULL);
	return IR_SUCCESS;
}

BOOL fsDownloadMgr::InternetAutodial(DWORD dwFlags, HWND hwndParent)
{
	HMODULE hDll = ::GetModuleHandle(_T("wininet.dll"));
	if (hDll == 0) {
		hDll = ::LoadLibrary("wininet.dll");
	}

	if (hDll == 0) {
		return FALSE;
	}
	
	typedef BOOL (WINAPI *FUN)(DWORD p1, HWND p2);

	FUN pfnFun = NULL;
	pfnFun = (FUN)GetProcAddress(hDll, "InternetAutodial");

	if (pfnFun == 0) {
		return FALSE;
	}

	return pfnFun(dwFlags, hwndParent);
}

void fsDownloadMgr::ApplyProperties()
{
	m_dldr.Set_Timeout (m_dp.uTimeout);
	m_dldr.SetRetryTime (m_dp.uRetriesTime);
	m_dldr.SetMaxReconnectionNumber (m_dp.uMaxAttempts);
	m_dldr.SetSectionMinSize (m_dp.uSectionMinSize);
	m_dldr.DontRestartIfNoRanges (m_dp.dwFlags & DPF_DONTRESTARTIFNORESUME);
	
	
#ifndef FDM_DLDR__RAWCODEONLY
	m_dldr.UseZipPreview (_App.NewDL_UseZIPPreview ());
#else
	m_dldr.UseZipPreview (FALSE);
#endif

	m_dldr.StopOnAccDenied (m_dp.aEP [DFE_ACCDENIED] == DFEP_STOP);
	m_dldr.StopOnFileNotFound (m_dp.aEP [DFE_NOTFOUND] == DFEP_STOP);

	if (m_dp.bIgnoreRestrictions == FALSE)
		m_dldr.LimitTraffic (m_dp.uTrafficRestriction);
	else
		m_dldr.LimitTraffic (UINT_MAX);

	AdjustKnownFileSharingSiteSupport ();

	if (m_dwState & DS_DOWNLOADING) {
		setStateFlags (DS_NEEDADDSECTION); 
		setDirty();
	}
}

DWORD WINAPI fsDownloadMgr::_threadDownloadMgr(LPVOID lp)
{
	fsDownloadMgr *pThis = (fsDownloadMgr*) lp;
	BOOL bAddSection = TRUE;	

	
	if (fsDownloadMgr::is_GlobalOffline ())
		fsDownloadMgr::set_GlobalOffline (FALSE);

	
	pThis->m_bThreadRunning = TRUE;

	BOOL bSSR = pThis->Event (DE_EXTERROR, DMEE_STARTING);

	#ifndef FDM_DLDR__RAWCODEONLY
	if (bSSR)
		bSSR = pThis->CheckIfMalicious ();
	#endif

	if (bSSR == FALSE)
	{
		pThis->m_bFatalError = TRUE;
		pThis->Event (DE_EXTERROR, DMEE_FATALERROR);
	}

	fsTicksMgr tick0SpeedStart;
	tick0SpeedStart.Now ();

	
	if (bSSR) while ((pThis->m_dwState & DS_DONE) == 0)
	{
		
		if (pThis->m_dwState & DS_NEEDSTART)
		{
			pThis->removeStateFlags (DS_NEEDSTART); 
			bAddSection = TRUE;	

			
			for (UINT i = 0; i < pThis->m_dp.uMaxAttempts; i++)
			{
				pThis->m_lastError = pThis->StartDownload ();
				tick0SpeedStart.Now ();

 				if (pThis->m_dwState & DS_NEEDSTOP || 
						pThis->m_lastError == IR_S_FALSE ||
						pThis->m_lastError == IR_RANGESNOTAVAIL ||
						pThis->m_lastError == IR_DOUBTFUL_RANGESRESPONSE)
					break;
				
				if (pThis->m_lastError == IR_SUCCESS)
				{
					pThis->setStateFlags (DS_DOWNLOADING);	
					if (pThis->m_dldr.IsResumeSupported () == RST_NONE)
						pThis->Event (LS (L_NORESUME), EDT_WARNING);
					break;
				}
				else
				{
					pThis->m_bCantStart = TRUE;	

					if (pThis->m_dp.uRetriesTime && i+1 != pThis->m_dp.uMaxAttempts)
					{
						CHAR szStr [1000];
						sprintf (szStr, LS (L_PAUSESECS), pThis->m_dp.uRetriesTime/1000);
						pThis->Event (szStr);
						if (pThis->SleepInterval () == FALSE)
							break; 
					}
				}
			}

			pThis->m_bCantStart = FALSE;

			
			if ((pThis->m_dwState & DS_DOWNLOADING) == 0 && pThis->m_lastError != IR_S_FALSE)
			{
				if ((pThis->m_dwState & DS_NEEDSTOP) == 0)
				{
					
					pThis->Event (LS (L_DLDSTOPPED), pThis->m_lastError == IR_S_FALSE ? EDT_RESPONSE_S : EDT_RESPONSE_E);
					pThis->Event (DE_EXTERROR, DMEE_FATALERROR);
					pThis->m_bFatalError = TRUE;
					pThis->setStateFlagsTo (0);
					break;
				}
			}
		}

		
		if (pThis->m_dwState & DS_NEEDSTOP)
		{
			pThis->StopDownload ();
			pThis->setStateFlagsTo (0);
			pThis->Event (LS (L_DLDSTOPPED), EDT_RESPONSE_S);
			break;
		}

		
		if (pThis->m_dwState & DS_DOWNLOADING)
		{
			if (bAddSection)	
			{
				fsTicksMgr curTicks;
				curTicks.Now ();

				
				if (curTicks - pThis->m_ticksStart > 1200)
				{
					bAddSection = FALSE;
					pThis->AddSection ();
				}
			}

			
			
			
			
			if (pThis->m_dldr.GetSpeed () == 0 && 
					pThis->m_dldr.GetDownloadingSectionCount () != 0 &&
					(pThis->m_dldr.IsResumeSupported () == RST_PRESENT || pThis->m_dldr.GetNumberOfSections () > 1))
			{
				fsTicksMgr tickNow; tickNow.Now ();
				if (tickNow - tick0SpeedStart > 120*1000)
				{
					pThis->m_bNeedStartAgain = TRUE;
					pThis->StopDownload ();
					tick0SpeedStart.Now ();
					continue;
				}
			}
			else
				tick0SpeedStart.Now ();
		}

		
		if (pThis->m_dwState & DS_NEEDADDSECTION)
		{
			pThis->removeStateFlags (DS_NEEDADDSECTION);
			pThis->AddSection ();
		}

		
		if (pThis->m_dwState & DS_NEEDADDSECTION2)
		{
			pThis->removeStateFlags (DS_NEEDADDSECTION2);
			if (pThis->m_dldr.GetStoppedSectionCount ())	
				pThis->m_dldr.LaunchOneMoreSection ();		
			else
				pThis->AddSection (FALSE);					
		}

		
		if (pThis->m_dwState & DS_NEEDRESTARTFROM)
		{
			pThis->removeStateFlags (DS_NEEDRESTARTFROM);
			
			pThis->setStateFlags (DS_NEEDSTART);
		}

		pThis->CheckMirrSpeedRecalcRequired ();

		Sleep (100);
	}

	if (bSSR)
	{
		if (pThis->m_dp.dwFlags & DPF_RETRDATEFROMSERVER)
		{
			if (pThis->m_hOutFile == INVALID_HANDLE_VALUE)
			{
				pThis->m_hOutFile = CreateFile (pThis->m_dp.pszFileName, GENERIC_WRITE, 
					FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
			}
		
			FILETIME time;
			GetFileTime (pThis->m_hOutFile, &time, NULL, NULL);
			::SetFileTime (pThis->m_hOutFile, NULL, NULL, &time);
		}

		pThis->CloseFile ();
	}

	pThis->m_bThreadRunning = FALSE; 
	pThis->Event (DE_EXTERROR, DMEE_STOPPEDORDONE);

	InterlockedDecrement (&pThis->m_iThread);	

	return 0;
}

DWORD fsDownloadMgr::_DownloaderEvents(fsDownloaderEvent enEvent, UINT uInfo, LPVOID lp)
{
	

	fsDownloadMgr *pThis = (fsDownloadMgr*) lp;
	fsTicksMgr curTicks;
	CHAR szEv [1000], szErr [1000];

	
	

	switch (enEvent)
	{
		case DE_SECTIONSTARTED:
			
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_STARTED));
			pThis->Event (szEv, EDT_RESPONSE_S);
			curTicks.Now ();
			if (curTicks - pThis->m_ticksStart < 1200)
				break;
		break;

		case DE_SECTDOWNLOADING:
			
			pThis->m_bCantStart = FALSE;
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_DOWNLOADING));
			pThis->Event (szEv, EDT_RESPONSE_S);
			pThis->AddSection ();
		break;

		case DE_MAYADDSECTION:
			pThis->AddSection ();
		break;

		case DE_SPEEDISTOOLOW:
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_SPEEDISTOOLOW));
			pThis->Event (szEv, EDT_WARNING);
		break;

		case DE_SECTIONSTOPPED:
			
			pThis->m_bCantStart = FALSE;
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_SHESTOPPED));
			pThis->Event (szEv, EDT_RESPONSE_S);
			pThis->OnSectionStopped ();
		break;

		case DE_SECTIONDONE:
			
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_DONE));
			pThis->Event (szEv, EDT_DONE);
			
			if (pThis->m_dldr.IsDone () && (pThis->m_dwState & DS_DONE) == 0 && pThis->m_dldr.IsRunning () == FALSE)
			{
				
				pThis->OnDone ();
				pThis->Event (LS (L_DLDCOMPLETED), EDT_DONE);
				pThis->Event (enEvent, uInfo);
				pThis->setStateFlagsTo (DS_DONE);	
				return 0; 
			}
			else
			{
				if (pThis->m_dldr.IsAllSectionsOk ())
					pThis->AddSection (); 
				else
					pThis->OnSectionStopped (); 
			}
		break;

		case DE_ERROROCCURED:
		{
			
			fsInternetResult ir = pThis->m_dldr.GetSectionLastError (uInfo);
			if (fsIRToStr (ir, szErr, sizeof (szErr)))
			{
				if (ir == IR_FILENOTFOUND)
					strcpy (szEv, szErr);
				else
					sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, szErr); 
				pThis->Event (szEv, EDT_RESPONSE_E);
			}

			if (pThis->m_dldr.GetDownloadingSectionCount () == 0)
				pThis->m_bCantStart = TRUE;
		}
		break;

		case DE_PAUSE:
		{
			
			char szPause [1000];
			sprintf (szPause, LS (L_PAUSESECS), pThis->m_dp.uRetriesTime/1000);
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, szPause);
			pThis->Event (szEv);
		}
		break;

		case DE_CONNECTING:
			
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_CONNECTING));
			pThis->Event (szEv);
		break;

		case DE_FAILCONNECT:
			
			if (fsIRToStr (pThis->m_dldr.GetSectionLastError (uInfo), szErr, sizeof (szErr)))
			{
				sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, szErr);
				pThis->Event (szEv, EDT_RESPONSE_E);
			}
		break;

		case DE_BADFILESIZE:
			pThis->Event (LS (L_FILESIZESARENOTEQUAL), EDT_RESPONSE_E);
		break;

		case DE_CONNECTED:
			
			sprintf (szEv, "[%s %d] - %s", LS (L_SECTION), uInfo+1, LS (L_CONNSUCC));
			pThis->Event (szEv, EDT_RESPONSE_S);
		break;

		case DE_WRITEERROR:
			
			SetLastError (pThis->m_dldr.GetSectionLastError (uInfo));
			fsErrorToStr (szErr, sizeof (szErr));
			sprintf (szEv, "[%s %d] - %s - %s", LS (L_SECTION), uInfo+1, LS (L_WRITEERR), szErr);
			pThis->Event (szEv, EDT_RESPONSE_E);
			pThis->Event (DE_EXTERROR, DMEE_FATALERROR);
			
			pThis->m_bFatalError = TRUE;
		break;

		case DE_REDIRECTING:
			
			pThis->Event (LS (L_REDIRECTING));
			break;

		case DE_REDIRECTINGOKCONTINUEOPENING:
			
			pThis->Event (LS (L_REDIRSUCC), EDT_RESPONSE_S);
			break;

		case DE_NEEDFILE:
			if (FALSE == pThis->Event (DE_NEEDFILE, uInfo))
				return FALSE;
			return pThis->OnNeedFile ();

		case DE_NEEDFILE_FINALINITIALIZATION:
			return pThis->OnNeedFile_FinalInit ();

		case DE_SCR:
			
			
			return pThis->OnSCR ();

		case DE_QUERYNEWSECTION:
			
			if (pThis->m_pfnEvents)
			{
				
				return pThis->Event (DE_QUERYNEWSECTION, uInfo);
			}
			break;

		case DE_ERRFROMSERVER:
		{
			
			pThis->m_strExtError = (LPCSTR) uInfo;
			LPCSTR pszErr1 = pThis->m_strExtError;
			CHAR szErr [1000];
			fsIRToStr (IR_EXTERROR, szErr, 1000);
			pThis->Event (szErr, EDT_RESPONSE_E);
			pThis->Event (pszErr1, EDT_RESPONSE_E);
		}
		break;

		case DE_RESTARTINGBECAUSENORANGES:
			
			pThis->Event (LS (L_NORESUMERESTARTING), EDT_WARNING);
			break;

		case DE_DIALOGWITHSERVER:
			
			fsDlgWithServerInfo *info;
			info = (fsDlgWithServerInfo*) uInfo;
			pThis->Event (info->pszMsg, info->dir == IFDD_TOSERVER ? EDT_INQUIRY2 : EDT_RESPONSE_S2);
			break;

		case DE_STARTINGSEARCHINGFORMIRRORS:
			pThis->Event (LS (L_SEARCHINGFORMIRRORS));
			break;

		case DE_CONNECTINGMIRRSERVER:
			pThis->Event (LS (L_CONNECTINGSEARCHSERVER));
			break;

		case DE_GETTINGMIRRSEARCHRESULTS:
			pThis->Event (LS (L_SUCCESS), EDT_RESPONSE_S);
			pThis->Event (LS (L_GETTINGRESULTS));
			break;

		case DE_MEASURINGMIRRSPEED:
			pThis->m_tikLastMirrMeasureTime.Now ();
			pThis->Event (LS (L_CALCULATINGMIRRORSSPEED));
			break;

		case DE_MIRRFOUND:
			char szEv [10000];
			sprintf (szEv, LS (L_NMIRRORSFOUND), pThis->m_dldr.GetFoundMirrorCount ());
			pThis->Event (szEv, EDT_RESPONSE_S);
			break;

		case DE_MIRRDONE:
			pThis->Event (LS (L_MIRRORSEARCHINGDONE));
			break;

		case DE_MIRRFAILED:
			pThis->Event (LS (L_FAILED), EDT_RESPONSE_E);
			break;

		case DE_NOMIRRFOUND:
			pThis->Event (LS (L_NOMIRRORSFOUND), EDT_WARNING);
			break;

		case DE_TRYINGANOTHERMIRROR:
			pThis->Event (LS (L_TRYINGANOTHERMIRROR));
			break;

		case DE_FILESIZETOOBIG:
			pThis->Event (LS (L_FILESIZEEXCEEDS2GB), EDT_WARNING);
			break;

		case DE_CONFIRMARCHIVEDETECTION:
			return pThis->Event (DE_CONFIRMARCHIVEDETECTION, uInfo);

		case DE_ZIPPREVIEWSTARTED:
			pThis->Event ("ZIP preview is in progress...");
			break;

		case DE_ZIPPREVIEWFAILED:
			pThis->Event ("ZIP preview failed", EDT_RESPONSE_E);
			pThis->Event (DE_EXTERROR, DMEE_FATALERROR);
			pThis->m_bFatalError = TRUE;
			break;

		case DE_ARCHIVEDETECTED:
			pThis->Event ("ZIP preview succeded", EDT_RESPONSE_S);
			return pThis->Event (DE_ARCHIVEDETECTED, uInfo);
	}

	pThis->Event (enEvent, uInfo);
	return TRUE;
}

fsInternetDownloader* fsDownloadMgr::GetDownloader()
{
	return &m_dldr;
}

fsInternetResult fsDownloadMgr::CreateByUrl(LPCSTR pszUrl, BOOL bAcceptHTMLPathes)
{
	fsDNP_BuffersInfo buffs;
	fsDNP_GetByUrl_Free (m_dldr.DNP ());
	setDirty();

	CString strURL = pszUrl;
	strURL.Replace ("&lt;", "<");
	strURL.Replace ("&gt;", ">");
	strURL.Replace ("&amp;", "&");
	strURL.Replace ("&quot;", "\"");

	
	fsInternetResult ir = fsDNP_GetByUrl (m_dldr.DNP (), &buffs, TRUE, strURL);
	setDirty();
	if (ir != IR_SUCCESS)
		return ir;

	LPCSTR pszPathName = m_dldr.DNP ()->pszPathName;
	int len = lstrlen (pszPathName);

	
	if (pszPathName == NULL || len == 0 || pszPathName [len-1] == '\\' || pszPathName [len-1] == '/')
	{
		if (bAcceptHTMLPathes == FALSE || (m_dldr.DNP ()->enProtocol != NP_HTTP && m_dldr.DNP ()->enProtocol != NP_HTTPS) )
			return IR_BADURL;
	}

	return IR_SUCCESS;
}

fsInternetResult fsDownloadMgr::StartDownload()
{
	fsInternetResult ir;

	Event (LS (L_STARTINGDLD));
	m_bFatalError = FALSE;

	ir = CreateInternetSession ();
	if (ir != IR_SUCCESS)
		return ir;

	ApplyProperties ();

	ir = m_dldr.StartDownloading (m_uNeedStartFrom);
	
	if (ir != IR_SUCCESS && ir != IR_S_FALSE && ir != IR_EXTERROR)
	{
		CHAR szEv [1000];
		BOOL bEv = FALSE;

		bEv = fsIRToStr (ir, szEv, sizeof (szEv));
			
		if (bEv)
			Event (szEv, EDT_RESPONSE_E);

		
		switch (ir)
		{
			case IR_FILENOTFOUND:	
				
				if (m_dp.aEP [DFE_NOTFOUND] == DFEP_STOP)
					ir = IR_S_FALSE;
			break;

			
			case IR_LOGINFAILURE:
			case IR_INVALIDPASSWORD:
			case IR_INVALIDUSERNAME:
				
				if (m_dp.aEP [DFE_ACCDENIED] == DFEP_STOP)
					ir = IR_S_FALSE;
			break;

		}

		if (ir == IR_S_FALSE)	
		{
			setStateFlags (DS_NEEDSTOP);	
			Event (DE_EXTERROR, DMEE_FATALERROR);
			m_bFatalError = TRUE;	
		}
	}

	if (ir == IR_S_FALSE && m_dldr.IsRunning () == FALSE && 
			(m_dwState & DS_NEEDRESTARTFROM) == 0) {
		setStateFlags (DS_NEEDSTOP);
	}

	m_ticksStart.Now ();

	return ir;
}

void fsDownloadMgr::StopDownloading()
{
	if (IsRunning ())
	{
		setStateFlags (DS_NEEDSTOP);
		m_dldr.StopDownloading ();
		#ifndef FDM_DLDR__RAWCODEONLY
		if (m_mdc)
			m_mdc->Stop ();
		#endif
	}
}

void fsDownloadMgr::StopDownload()
{
	if (m_dldr.IsRunning ())
	{
		#ifndef FDM_DLDR__RAWCODEONLY
		if (m_mdc)
			m_mdc->Stop ();
		#endif
		m_dldr.StopDownloading ();
		while (m_dldr.IsRunning ())
			Sleep (10);
	}
}

void fsDownloadMgr::SetOutputFileName(LPCSTR pszName)
{
	SAFE_DELETE_ARRAY (m_dp.pszFileName);

	fsnew (m_dp.pszFileName, CHAR, strlen (pszName)+1);
	strcpy (m_dp.pszFileName, pszName);
	setDirty();
}

void fsDownloadMgr::SetEventFunc(fntDownloadMgrEventFunc pfnEvents, LPVOID lpParam)
{
	m_pfnEvents = pfnEvents;
	m_lpParamEvents = lpParam;
}

void fsDownloadMgr::SetEventDescFunc(fntEventDescFunc pfn, LPVOID lpParam)
{
	m_pfnEventDesc = pfn;
	m_lpEventDescParam = lpParam;
}

void fsDownloadMgr::Event(LPCSTR pszEvent, fsDownloadMgr_EventDescType enType)
{
	if (m_pfnEventDesc && *pszEvent)
		m_pfnEventDesc (this, enType, pszEvent, m_lpEventDescParam);
}

void fsDownloadMgr::AddSection(BOOL bCheckAdm)
{
	if (m_bDontCreateNewSections || m_dldr.IsSectionCreatingNow ())
		return;

	
	if (bCheckAdm == FALSE || IsSectionCanBeAdded ())
	{
		if (m_dldr.GetSectionMaxSize () > m_dp.uSectionMinSize)
		{
			Event (LS (L_NEWSECTION));
			m_lastError = m_dldr.AddSection (bCheckAdm);
			
			if (m_lastError != IR_SUCCESS)
			{
				if (m_lastError == IR_S_FALSE)	
					Event (LS (L_CANCELED), EDT_RESPONSE_S);
				else
				{
					CHAR szEv [1000];
					if (fsIRToStr (m_lastError, szEv, sizeof (szEv)))
						Event (szEv, EDT_RESPONSE_E);
				}
			}
		}
	}
}

BOOL fsDownloadMgr::IsDone()
{
	return m_dldr.IsDone ();
}

BOOL fsDownloadMgr::LoadState(LPVOID lpBuffer, LPDWORD pdwSize, WORD wVer)
{
#define CHECK_BOUNDS(need) if (need < 0 || need > int(*pdwSize) - (pB - LPBYTE (lpBuffer))) return FALSE;

	DWORD dw = *pdwSize;
	LPBYTE pB = (LPBYTE) lpBuffer;

	CHECK_BOUNDS (sizeof (DWORD));

	CopyMemory (&dw, pB, sizeof (DWORD));
	pB += sizeof (DWORD);

	CHECK_BOUNDS (int (dw));	

	if (FALSE == m_dldr.RestoreSectionsState (pB, dw, wVer))
		return FALSE;
	pB += dw;

	CHECK_BOUNDS (sizeof (m_dp));

	DWORD dwDP = sizeof (fsDownload_Properties);
	if (wVer < 8)	
		dwDP -= sizeof (BOOL) + sizeof (vmsIntegrityCheckFailedReaction) + sizeof (LPSTR) + sizeof (DWORD);
	if (wVer == 2)
		dwDP -= sizeof (LPSTR); 
	CopyMemory (&m_dp, pB, dwDP);
	pB += dwDP;

	fsDownload_NetworkProperties *dnp = GetDNP ();
	DWORD dwDNP = sizeof (fsDownload_NetworkProperties);
	if (wVer < 7) 
		dwDNP -= 2 * sizeof (LPSTR) + sizeof (DWORD) + 2 * sizeof (WORD);
	CHECK_BOUNDS ((int)dwDNP);
	CopyMemory (dnp, pB, dwDNP);
	pB += dwDNP;

	CHECK_BOUNDS (sizeof (m_dwState));

	CopyMemory (&m_dwState, pB, sizeof (m_dwState));
	pB += sizeof (m_dwState);

	
	if (wVer == 0)	
	{
		m_dwDownloadFileFlags = m_dldr.GetNumberOfSections () == 0 ? DFF_NEED_INIT_FILE : 0;
	}
	else
	{
		CHECK_BOUNDS (sizeof (m_dwDownloadFileFlags));

		CopyMemory (&m_dwDownloadFileFlags, pB, sizeof (m_dwDownloadFileFlags));
		pB += sizeof (m_dwDownloadFileFlags);
	}

	int cMirrs = 0;
	if (wVer > 3)
	{
		CHECK_BOUNDS (sizeof (int));

		CopyMemory (&cMirrs, pB, sizeof (int));
		pB += sizeof (int);
	}

	dw = DWORD (m_dp.pszFileName);
	CHECK_BOUNDS (int (dw));
	fsnew (m_dp.pszFileName, CHAR, dw+1);
	CopyMemory (m_dp.pszFileName, pB, dw);
	m_dp.pszFileName [dw] = 0;
	pB += dw;
	if (m_dwDownloadFileFlags & DFF_USE_PORTABLE_DRIVE)
		m_dp.pszFileName [0] = vmsGetExeDriveLetter ();

	dw = DWORD (m_dp.pszAdditionalExt);
	CHECK_BOUNDS (int (dw));
	fsnew (m_dp.pszAdditionalExt, CHAR, dw+1);
	CopyMemory (m_dp.pszAdditionalExt, pB, dw);
	m_dp.pszAdditionalExt [dw] = 0;
	pB += dw;

	if (wVer > 2)	
	{
		dw = DWORD (m_dp.pszCreateExt);
		CHECK_BOUNDS (int (dw));
		fsnew (m_dp.pszCreateExt, CHAR, dw+1);
		CopyMemory (m_dp.pszCreateExt, pB, dw);
		m_dp.pszCreateExt [dw] = 0;
		pB += dw;
	}
	else
	{
		fsnew (m_dp.pszCreateExt, CHAR, 1);
		*m_dp.pszCreateExt = 0;
	}

	if (wVer > 7)
	{
		dw = DWORD (m_dp.pszCheckSum);
		CHECK_BOUNDS (int (dw));
		fsnew (m_dp.pszCheckSum, CHAR, dw+1);
		CopyMemory (m_dp.pszCheckSum, pB, dw);
		m_dp.pszCheckSum [dw] = 0;
		pB += dw;
	}
	else
	{
		fsnew (m_dp.pszCheckSum, CHAR, 1);
		*m_dp.pszCheckSum = 0;
		m_dp.bCheckIntegrityWhenDone = FALSE;
		m_dp.dwIntegrityCheckAlgorithm = HA_MD5;
	}

	int i = 0;
	for (i = 0; i < cMirrs + 1; i++)
	{
		fsDownload_NetworkProperties tmpdnp;
		BOOL bMirrIsGood;

		if (i)
		{
			dnp = &tmpdnp;

			CHECK_BOUNDS ((int)dwDNP);
			CopyMemory (dnp, pB, dwDNP);
			pB += dwDNP;

			CHECK_BOUNDS (sizeof (BOOL));

			CopyMemory (&bMirrIsGood, pB, sizeof (BOOL));
			pB += sizeof (BOOL);
		}

		dw = DWORD (dnp->pszAgent);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszAgent, CHAR, dw+1);
		CopyMemory (dnp->pszAgent, pB, dw);
		dnp->pszAgent [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszPassword);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszPassword, CHAR, dw+1);
		CopyMemory (dnp->pszPassword, pB, dw);
		dnp->pszPassword [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszPathName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszPathName, CHAR, dw+1);
		CopyMemory (dnp->pszPathName, pB, dw);
		dnp->pszPathName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszProxyName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszProxyName, CHAR, dw+1);
		CopyMemory (dnp->pszProxyName, pB, dw);
		dnp->pszProxyName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszProxyPassword);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszProxyPassword, CHAR, dw+1);
		CopyMemory (dnp->pszProxyPassword, pB, dw);
		dnp->pszProxyPassword [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszProxyUserName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszProxyUserName, CHAR, dw+1);
		CopyMemory (dnp->pszProxyUserName, pB, dw);
		dnp->pszProxyUserName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszReferer);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszReferer, CHAR, dw+1);
		CopyMemory (dnp->pszReferer, pB, dw);
		dnp->pszReferer [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszServerName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszServerName, CHAR, dw+1);
		CopyMemory (dnp->pszServerName, pB, dw);
		dnp->pszServerName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszUserName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszUserName, CHAR, dw+1);
		CopyMemory (dnp->pszUserName, pB, dw);
		dnp->pszUserName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszASCIIExts);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszASCIIExts, CHAR, dw+1);
		CopyMemory (dnp->pszASCIIExts, pB, dw);
		dnp->pszASCIIExts [dw] = 0;
		pB += dw;

		if (wVer > 6)
		{
			
			dw = DWORD (dnp->pszCookies);
			CHECK_BOUNDS (int (dw));
			fsnew (dnp->pszCookies, CHAR, dw+1);
			CopyMemory (dnp->pszCookies, pB, dw);
			dnp->pszCookies [dw] = 0;
			pB += dw;

			dw = DWORD (dnp->pszPostData);
			CHECK_BOUNDS (int (dw));
			fsnew (dnp->pszPostData, CHAR, dw+1);
			CopyMemory (dnp->pszPostData, pB, dw);
			dnp->pszPostData [dw] = 0;
			pB += dw;
		}
		else
		{
			dnp->pszCookies = new char [1];
			dnp->pszCookies [0] = 0;

			dnp->pszPostData = new char [1];
			dnp->pszPostData [0] = 0;

			dnp->dwFlags = 0;
			dnp->wLowSpeed_Factor = 4;
			dnp->wLowSpeed_Duration = 1;
		}

		if (i)
			m_dldr.AddMirror (dnp,  TRUE, TRUE);
	}

	if (cMirrs)
	{
		for (i = 0; i < cMirrs; i++)
		{
			DWORD dw;

			CHECK_BOUNDS (sizeof (dw));

			CopyMemory (&dw, pB, sizeof (dw));
			pB += sizeof (dw);

			m_dldr.Set_MirrPingTime (i, dw);
		}

		DWORD dw;

		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		pB += sizeof (dw);

		m_dldr.Set_BaseServerPingTime (dw);
	}

	*pdwSize = pB - (LPBYTE) lpBuffer;

	return TRUE;
}

BOOL fsDownloadMgr::IsRunning()
{
	return m_bThreadRunning || m_dldr.IsRunning ();
}

BOOL fsDownloadMgr::SleepInterval()
{
	int i = m_dp.uRetriesTime;

	while (i > 0)
	{
		Sleep (100);
		i -= 100;

		if (m_dwState & DS_NEEDSTOP)
			return FALSE;
	}

	return TRUE;
}

void fsDownloadMgr::OnSectionStopped()
{
	if (m_dldr.IsRunning () == FALSE) 
	{
		removeStateFlags (DS_DOWNLOADING);	
		
		if ((m_bNeedStartAgain || m_dldr.IsStoppedByUser () == FALSE) && 
				m_bFatalError == FALSE)
		{
			m_bNeedStartAgain = FALSE;
			Event (LS (L_RESTARTINGDLD)); 
			setStateFlags (DS_NEEDSTART);	
		}
		else
		{
			setStateFlags (DS_NEEDSTOP);	
		}
	}
}

BOOL fsDownloadMgr::OnNeedFile()
{
	BOOL bOk;

	
	if (m_hOutFile != INVALID_HANDLE_VALUE)
	{
		
		m_dldr.SetOutputFile (m_hOutFile);
		return TRUE;
	}

	

	Event (LS (L_OPENINGFILE));

	if (m_dwDownloadFileFlags & DFF_NEED_INIT_FILE)
	{
		if (FALSE == InitFile ())	
		{
			Event (DE_EXTERROR, DMEE_FATALERROR);
			m_bFatalError = TRUE;
			return FALSE;
		}
	}
	
	bOk = OpenFile ();	

	if (!bOk)
		goto _lErr;
	else if (bOk == BOOL (-1))
		return FALSE;

	m_dldr.SetOutputFile (m_hOutFile);
	Event (LS (L_SUCCESS), EDT_RESPONSE_S);

	return TRUE;

_lErr:	
	DescribeAPIError ();	
	setStateFlags (DS_NEEDSTOP);	
	Event (DE_EXTERROR, DMEE_FATALERROR);
	m_bFatalError = TRUE;
	return FALSE;
}

void fsDownloadMgr::RenameFile(BOOL bFormat1)
{
	int i = 1;
	DWORD dwResult;
	CHAR szFileWE [MY_MAX_PATH]; 
	CString strFile;

	
	
	strcpy (szFileWE, m_dp.pszFileName);

	if (m_dp.pszAdditionalExt && *m_dp.pszAdditionalExt)
	{
		int fl = strlen (szFileWE);
		int al = strlen (m_dp.pszAdditionalExt);

		if (fl > al && szFileWE [fl - al - 1] == '.' &&
			stricmp (szFileWE + fl - al, m_dp.pszAdditionalExt) == 0)
		{
			szFileWE [fl - al - 1] = 0;
		}

	}

	LPSTR pszExt = strrchr (szFileWE, '.');	
	LPSTR pszDirEnd = strrchr (szFileWE, '\\');	

	if (pszExt != NULL && pszDirEnd > pszExt)
		pszExt = NULL;	

	if (pszExt)
		*pszExt = 0;	

	if (m_bRename_CheckIfRenamed)
	{
		int l = lstrlen (szFileWE);
		if (szFileWE [l-1] == ')')
		{
			LPSTR psz = szFileWE + l - 2;
			while (*psz && *psz >= '0' && *psz <= '9')
				psz--;
			if (*psz == '(')
				
				
				*psz = 0;
		}
	}

	m_csRenameFile.Lock ();

	
	
	do
	{
		if (pszExt)
			strFile.Format ("%s(%d).%s", szFileWE, i++, pszExt+1);
		else
			strFile.Format ("%s(%d)", szFileWE, i++);

		dwResult = GetFileAttributes (strFile);
	}
	while (dwResult != DWORD (-1));

	SAFE_DELETE_ARRAY (m_dp.pszFileName);
	fsnew (m_dp.pszFileName, CHAR, strFile.GetLength () + 1);
	strcpy (m_dp.pszFileName, strFile);
	setDirty();

	HANDLE hFile = CreateFile (m_dp.pszFileName, GENERIC_WRITE, 0, NULL, 
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	m_csRenameFile.Unlock ();

	
	CHAR szFileName [MY_MAX_PATH];
	fsGetFileName (strFile, szFileName);
	CString strEv;
	if (bFormat1)
		strEv.Format ("%s \"%s\"", LS (L_FILEALREXISTSRENAMING), szFileName);
	else
		strEv.Format ("%s %s", LS (L_RENAMINGTO), szFileName);

	Event (strEv, EDT_WARNING);
	Event (DE_EXTERROR, DMEE_FILEUPDATED);
	
}

void fsDownloadMgr::RenameFile(const char* szFileName, BOOL bFormat1)
{
	int i = 1;
	DWORD dwResult;
	CHAR szFileWE [MY_MAX_PATH]; 
	CString strFile;
	
	
	
	strcpy (szFileWE, szFileName);

	if (m_dp.pszAdditionalExt && *m_dp.pszAdditionalExt)
	{
		int fl = strlen (szFileWE);
		int al = strlen (m_dp.pszAdditionalExt);

		if (fl > al && szFileWE [fl - al - 1] == '.' &&
			stricmp (szFileWE + fl - al, m_dp.pszAdditionalExt) == 0)
		{
			szFileWE [fl - al - 1] = 0;
		}

	}

	LPSTR pszExt = strrchr (szFileWE, '.');	
	LPSTR pszDirEnd = strrchr (szFileWE, '\\');	

	if (pszExt != NULL && pszDirEnd > pszExt)
		pszExt = NULL;	

	if (pszExt)
		*pszExt = 0;	

	if (m_bRename_CheckIfRenamed)
	{
		int l = lstrlen (szFileWE);
		if (szFileWE [l-1] == ')')
		{
			LPSTR psz = szFileWE + l - 2;
			while (*psz && *psz >= '0' && *psz <= '9')
				psz--;
			if (*psz == '(')
				
				
				*psz = 0;
		}
	}

	m_csRenameFile.Lock ();

	
	
	int nIndex = 0;
	do
	{
		if (pszExt)
			strFile.Format ("%s(%d).%s", szFileWE, i++, pszExt+1);
		else
			strFile.Format ("%s(%d)", szFileWE, i++);

		nIndex = i;
		dwResult = GetFileAttributes (strFile);
	}
	while (dwResult != DWORD (-1));

	int nExtIndex = 0;
	i = 1;
	do
	{
		if (pszExt)
			strFile.Format ("%s(%d).%s.%s", szFileWE, i++, pszExt+1, (LPCTSTR)m_dp.pszAdditionalExt);
		else
			strFile.Format ("%s(%d).%s", szFileWE, i++, (LPCTSTR)m_dp.pszAdditionalExt);

		nExtIndex = i;
		dwResult = GetFileAttributes (strFile);
	}
	while (dwResult != DWORD (-1));

	 nIndex = max(nIndex, nExtIndex) - 1;
	 if (pszExt)
		strFile.Format ("%s(%d).%s.%s", szFileWE, nIndex, pszExt+1, (LPCTSTR)m_dp.pszAdditionalExt);
	else
		strFile.Format ("%s(%d).%s", szFileWE, nIndex, (LPCTSTR)m_dp.pszAdditionalExt);

	SAFE_DELETE_ARRAY (m_dp.pszFileName);
	fsnew (m_dp.pszFileName, CHAR, strFile.GetLength () + 1);
	strcpy (m_dp.pszFileName, strFile);
	setDirty();

	HANDLE hFile = CreateFile (m_dp.pszFileName, GENERIC_WRITE, 0, NULL, 
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	m_csRenameFile.Unlock ();

	
	CHAR szFileName_ [MY_MAX_PATH];
	fsGetFileName (strFile, szFileName_);
	CString strEv;
	if (bFormat1)
		strEv.Format ("%s \"%s\"", LS (L_FILEALREXISTSRENAMING), szFileName_);
	else
		strEv.Format ("%s %s", LS (L_RENAMINGTO), szFileName_);

	Event (strEv, EDT_WARNING);
	Event (DE_EXTERROR, DMEE_FILEUPDATED);
	
}

BOOL fsDownloadMgr::OpenFile(BOOL bFailIfDeleted, BOOL bDisableEvents)
{
	if (m_hOutFile != INVALID_HANDLE_VALUE)
		return TRUE;

	
	if (bFailIfDeleted && GetFileAttributes (m_dp.pszFileName) == DWORD (-1) && m_dldr.GetNumberOfSections ())
	{
		fsSection sect;
		m_dldr.GetSectionInfo (0, &sect);
		
		
		if (m_dldr.GetNumberOfSections () != 1 || sect.uCurrent != sect.uStart)	
		{
			
			if (bDisableEvents == FALSE)
				Event (LS (L_WASDELETED), EDT_RESPONSE_E);
			setStateFlags (DS_NEEDSTOP);
			
			if (bDisableEvents == FALSE)
				Event (DE_EXTERROR, DMEE_FILEWASDELETED);
			return -1;
		}
	}

	DWORD dwFileAttribs = FILE_ATTRIBUTE_NORMAL;

	m_hOutFile = CreateFile (m_dp.pszFileName, GENERIC_WRITE, FILE_SHARE_READ,
				NULL, OPEN_ALWAYS, dwFileAttribs, NULL);
	
	DWORD dw = GetFileAttributes (m_dp.pszFileName);
	if ((m_dp.dwFlags & DPF_USEHIDDENATTRIB) && (dw & FILE_ATTRIBUTE_HIDDEN) == 0)
		SetFileAttributes (m_dp.pszFileName, dw | FILE_ATTRIBUTE_HIDDEN);

	if (m_hOutFile == INVALID_HANDLE_VALUE) {
		m_bFailedToCreateDestinationFile = true;
		return FALSE;
	}

	if (::GetLastError () != ERROR_ALREADY_EXISTS)
		SetFileTime (m_hOutFile);

	return TRUE;
}

BOOL fsDownloadMgr::TruncFile(const CString& sFileName)
{
	DWORD dwFileAttribs = FILE_ATTRIBUTE_NORMAL;

	HANDLE hFile = CreateFile ((LPCTSTR)sFileName, GENERIC_WRITE, FILE_SHARE_READ,
				NULL, OPEN_ALWAYS, dwFileAttribs, NULL);
	
	DWORD dw = GetFileAttributes ((LPCTSTR)sFileName);
	if ((m_dp.dwFlags & DPF_USEHIDDENATTRIB) && (dw & FILE_ATTRIBUTE_HIDDEN) == 0)
		SetFileAttributes ((LPCTSTR)sFileName, dw | FILE_ATTRIBUTE_HIDDEN);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	if (::GetLastError () != ERROR_ALREADY_EXISTS)
		SetFileTime (m_hOutFile);

	SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
	SetEndOfFile (hFile);  

	::CloseHandle(hFile);

	return TRUE;
}

void fsDownloadMgr::RemoveIncompleteFileExt()
{
	int fl = strlen (m_dp.pszFileName);
	int el = strlen (m_dp.pszAdditionalExt);
	if (fl > el && m_dp.pszFileName[fl - el - 1] == '.' &&
		stricmp (m_dp.pszFileName + fl - el, m_dp.pszAdditionalExt) == 0) {
		m_dp.pszFileName [fl - el - 1] = 0;
		setDirty();
	}
}

BOOL fsDownloadMgr::ApplyAER(fsAlreadyExistReaction enAER, bool bFirstCheck)
{
	

	
	switch (enAER)
	{
		case AER_ASKUSER:	
		{
#if !defined (FDM_DLDR__RAWCODEONLY)
			CAERDlg dlg;

			if (bFirstCheck)
				dlg.m_pszFile = m_dp.pszFileName;
			else
				dlg.m_pszFile = (LPCTSTR)m_sOriginalFile;

			_DlgMgr.OnDoModal (&dlg);
			dlg.DoModal ();	
			_DlgMgr.OnEndDialog (&dlg);
			if (dlg.m_bDontAskAgain)	
			{
				m_dp.enAER = dlg.m_enAER;	
				setDirty();
				_App.AlreadyExistReaction (dlg.m_enAER); 
				_DldsMgr.ApplyAER (dlg.m_enAER);
			}
			enAER = dlg.m_enAER;
#else
			enAER = AER_REWRITE;
#endif
			return ApplyAER (enAER, bFirstCheck);	
		}

		case AER_REWRITE:	

			if (!bFirstCheck) {
#ifndef FDM_DLDR__RAWCODEONLY
				if (m_sOriginalFile.CompareNoCase((LPCTSTR)m_dp.pszFileName) != 0)
					RemoveIncompleteFileExt();
#else
				if (_tcscmp((LPTSTR)m_sOriginalFile, (LPCTSTR)m_dp.pszFileName) != 0)
					RemoveIncompleteFileExt();
#endif
			}

			if (!OpenFile ())
				return FALSE;
			Event (LS (L_REWRITINGIT), EDT_WARNING);
			SetFilePointer (m_hOutFile, 0, NULL, FILE_BEGIN);
			SetEndOfFile (m_hOutFile);  
			return TRUE;

		case AER_RENAME_2:
		case AER_RENAME:

			if (!bFirstCheck) {
#ifndef FDM_DLDR__RAWCODEONLY
				RenameFile((LPCTSTR)m_sOriginalFile);
#else
				RenameFile((LPTSTR)m_sOriginalFile);
#endif
				return TRUE;
			}

			RenameFile ();
			return TRUE;

		case AER_RESUME: 

			if (!bFirstCheck) {
#ifndef FDM_DLDR__RAWCODEONLY
				
				if (m_sOriginalFile.CompareNoCase((LPCTSTR)m_dp.pszFileName) != 0)
					RemoveIncompleteFileExt();
#else
				
				if (_tcscmp((LPTSTR)m_sOriginalFile, (LPCTSTR)m_dp.pszFileName) != 0)
					RemoveIncompleteFileExt();
#endif
			}

			if (!OpenFile ())
				return FALSE;
			m_uNeedStartFrom = GetFileSize (m_hOutFile, NULL); 
			Event (LS (L_RESUMINGDLD), EDT_WARNING);
			setStateFlags (DS_NEEDRESTARTFROM);
			return -1;

		case AER_STOP:

#ifndef FDM_DLDR__RAWCODEONLY
			
			if (m_sOriginalFile.CompareNoCase((LPCTSTR)m_dp.pszFileName) != 0)
				RemoveIncompleteFileExt();
#else
			if (_tcscmp((LPTSTR)m_sOriginalFile, (LPCTSTR)m_dp.pszFileName) != 0)
					RemoveIncompleteFileExt();
#endif

			Event (LS (L_ALREXISTS), EDT_RESPONSE_E);
			setStateFlags (DS_NEEDSTOP);
			Event (DE_EXTERROR, DMEE_USERSTOP);
			return -1;

		default:
			ASSERT (FALSE);
			return FALSE;
	}
}

DWORD fsDownloadMgr::Event(fsDownloaderEvent ev, UINT uInfo)
{
	if (m_pfnEvents)
		return m_pfnEvents (this, ev, uInfo, m_lpParamEvents);

	return TRUE;
}

BOOL fsDownloadMgr::BuildFileName(LPCSTR pszSetExt)
{
	CHAR szFile [MY_MAX_PATH] = "";	
	CHAR szPath [MY_MAX_PATH] = "";	

	int fl = strlen (m_dp.pszFileName);

	
	
	if (fl > 1 && m_dp.pszFileName [fl - 1] != '/' && m_dp.pszFileName [fl - 1] != '\\')
		return TRUE;

	
	LPCSTR pszSuggFile = m_dldr.GetSuggestedFileName ();
	if (pszSuggFile && *pszSuggFile)	
	{
		strcpy (szFile, pszSuggFile);
	}
	else
	{
		
		if (!fsFileNameFromUrlPath (GetDNP ()->pszPathName, GetDNP ()->enProtocol == NP_FTP,
				TRUE, szFile, sizeof (szFile)))
			return FALSE;
	}

	if (*szFile)
	{
		
		_COM_SMARTPTR_TYPEDEF(IMultiLanguage2, __uuidof(IMultiLanguage2));
		IMultiLanguage2Ptr spML;
		HRESULT hrCoInit = CoInitialize (NULL);
		spML.CreateInstance (CLSID_CMultiLanguage);
		if (spML != NULL)
		{
			DetectEncodingInfo enc = {0};
			int iEncLen = 1;
			char *pszBuf = new char [max (strlen (szFile), 1024) + 1];
			strcpy (pszBuf, szFile);
			while (strlen (pszBuf) < 300)
				strcat (pszBuf, szFile);
			int iLen = strlen (pszBuf);
			if (S_OK == spML->DetectInputCodepage (MLDETECTCP_8BIT, 0, pszBuf, &iLen, &enc, &iEncLen) &&
				iEncLen == 1)
			{
				if (enc.nCodePage == CP_UTF8)
				{
					iLen = strlen (szFile);
					LPWSTR pwsz = new wchar_t [iLen+1];
					*pwsz = 0;
					iLen = MultiByteToWideChar (CP_UTF8, 0, (LPCSTR)szFile, iLen, pwsz, iLen);
					if (iLen > 0)
						pwsz [iLen] = 0;
					WideCharToMultiByte (CP_ACP, 0, pwsz, -1, szFile, sizeof (szFile), NULL, NULL);
					delete [] pwsz;
				}
			}
			delete [] pszBuf;
			spML = NULL;
		}
		if (SUCCEEDED (hrCoInit))
			CoUninitialize ();
		
	}

	
	
	if (*szFile == 0)
		strcpy (szFile, "index.html");

	
	LPSTR psz = szFile;
	char szSymbls [] = {":*?\"<>|"};
	while (*psz) {
		if (strchr (szSymbls, *psz))
			*psz = '_';
		psz++;
	}

	
	if (fl >= MY_MAX_PATH - 1)
		return FALSE;

	szFile [MY_MAX_PATH - 1 - fl] = 0; 

	char *pszExt = strrchr (szFile, '.');

	if (pszSetExt)	
	{
		if (pszExt == NULL)
		{
			strcat (szFile, ".");
			strcat (szFile, pszSetExt);
		}
		else
		{
			strcpy (pszExt+1, pszSetExt);
		}
	}
	else if (pszExt == NULL && m_dp.pszCreateExt && *m_dp.pszCreateExt)
	{
		
		strcat (szFile, ".");
		strcat (szFile, m_dp.pszCreateExt);
	}

	strcpy (szPath, m_dp.pszFileName);
	strcat (szPath, szFile);

	SAFE_DELETE_ARRAY (m_dp.pszFileName);
	fsnew (m_dp.pszFileName, CHAR, strlen (szPath)+1);
	strcpy (m_dp.pszFileName, szPath);
	setDirty();
	
	Event (DE_EXTERROR, DMEE_FILEUPDATED);

	return TRUE;
}

BOOL fsDownloadMgr::ReserveDiskSpace()
{
	
	
	

	if (FALSE == m_dp.bReserveDiskSpace || m_dldr.GetLDFileSize () == _UI64_MAX)
		return TRUE;

	ULARGE_INTEGER liSize = {0};
	liSize.LowPart = GetFileSize (m_hOutFile, &liSize.HighPart);
	if (liSize.QuadPart == 0)
	{
		m_dldr.LockWriteFile (TRUE);
		bool bOK = fsSetFilePointer (m_hOutFile, m_dldr.GetLDFileSize (), FILE_BEGIN) && 
				SetEndOfFile (m_hOutFile);
		m_dldr.LockWriteFile (FALSE);
		if (!bOK) {
			m_bIsNotEnoughDiskSpace = true;
			return FALSE;
		}
	}

	if (m_dldr.GetNumberOfSections () == 1 && m_dldr.GetLDFileSize () > 100 * 1024 * 1024)
	{
		m_bDontCreateNewSections = TRUE;
		InterlockedIncrement (&m_iThread);
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadReserveDiskSpace, this, 0, &dw));
	}

	return TRUE;
}

void fsDownloadMgr::ApplyAdditionalExt()
{
	CHAR szFile [MY_MAX_PATH];
	int fl = strlen (m_dp.pszFileName);
	int el = strlen (m_dp.pszAdditionalExt);

	if (el == 0) 
		return;

	if (fl > el)
	{
		
		if (stricmp (m_dp.pszFileName + fl - el, m_dp.pszAdditionalExt) == 0 &&
			m_dp.pszFileName [fl - el - 1] == '.' )
			return;

		if (fl + el >= MY_MAX_PATH) 
			return;
	}

	strcpy (szFile, m_dp.pszFileName);
	strcat (szFile, ".");
	strcat (szFile, m_dp.pszAdditionalExt);

	SAFE_DELETE_ARRAY (m_dp.pszFileName);
	fsnew (m_dp.pszFileName, CHAR, strlen (szFile) + 1);
	strcpy (m_dp.pszFileName, szFile);
	setDirty();
}

DWORD fsDownloadMgr::OnSCR()
{
	
	return ProcessSCR (m_dp.enSCR, TRUE);
}

DWORD fsDownloadMgr::ProcessSCR(fsSizeChangeReaction scr, BOOL bFirstCall)
{
	
	if (bFirstCall)
	{
		if (FALSE == OpenFile ()) 
		{
			DWORD dwLastError = GetLastError ();
			Event (LS (L_FAILEDTOOPEN), EDT_RESPONSE_E);
			DescribeAPIError (&dwLastError);
			setStateFlags (DS_NEEDSTOP);
			return SCR_STOP;
		}
		Event (LS (L_FILESIZEWASCHANGED), EDT_WARNING);
	}

	switch (scr)
	{
		case SCR_ASKUSER:
		{
#ifndef FDM_DLDR__RAWCODEONLY
			CSCRDlg dlg;
			dlg.m_dnp = GetDNP ();
			_DlgMgr.OnDoModal (&dlg);
			dlg.DoModal ();
			_DlgMgr.OnEndDialog (&dlg);
			if (dlg.m_bDontAskAgain)
			{
				m_dp.enSCR = dlg.m_enSCR;
				setDirty();
				_App.SizeChangeReaction (dlg.m_enSCR);
			}

			return ProcessSCR (dlg.m_enSCR, FALSE);	
#endif

		}

		case SCR_RESTART:	
			Event (LS (L_RESTARTINGDLD), EDT_WARNING);
			SetFilePointer (m_hOutFile, 0, NULL, FILE_BEGIN);
			SetEndOfFile (m_hOutFile);
			break;

		case SCR_ADJUSTFORNEWSIZE:	
		{
			Event (LS (L_ADJFORNEWSIZE), EDT_WARNING);

			UINT64 uNewSize = m_dldr.GetSSFileSize ();
			UINT64 uOldSize = GetFileSize (m_hOutFile, NULL);

			if (uOldSize > uNewSize)
			{
				fsSetFilePointer (m_hOutFile, uNewSize, FILE_BEGIN);
				SetEndOfFile (m_hOutFile);
			}
		}
			break;

		case SCR_STOP:
			setStateFlags (DS_NEEDSTOP);
			Event (DE_EXTERROR, DMEE_USERSTOP);
			break;

		default:
			ASSERT (5!=5);
	}

	return scr;
}

void fsDownloadMgr::DescribeAPIError(DWORD* pdwLastError)
{
	CHAR szErr [1000];
	fsErrorToStr (szErr, sizeof (szErr), pdwLastError);
	Event (szErr, EDT_RESPONSE_E);
}

void fsDownloadMgr::OnDone()
{
	CloseFile ();
	RemoveHiddenAttribute ();
	
	
	int fl = strlen (m_dp.pszFileName);
	int el = strlen (m_dp.pszAdditionalExt);

	if (el == 0 || el >= fl-1)
	{
		if (m_dp.dwFlags & DPF_APPENDCOMMENTTOFILENAME)
			AppendCommentToFileName (TRUE);
		return;
	}

	if (fsStrNCmpNC (m_dp.pszFileName +fl - el, m_dp.pszAdditionalExt, el))
	{
		if (m_dp.dwFlags & DPF_APPENDCOMMENTTOFILENAME)
			AppendCommentToFileName (TRUE);
		return;
	}

	CHAR szFileNameFrom [MY_MAX_PATH];	
	strcpy (szFileNameFrom, m_dp.pszFileName);

	

	m_dp.pszFileName [fl-el-1] = 0;	
	setDirty();

	if (m_dp.dwFlags & DPF_APPENDCOMMENTTOFILENAME)
		AppendCommentToFileName (FALSE);

	
	CheckDstFileExists ();

	if (DWORD (-1) != GetFileAttributes (m_dp.pszFileName))
		::DeleteFile (m_dp.pszFileName);	
	if (FALSE == ::MoveFile (szFileNameFrom, m_dp.pszFileName))	
	{
		DWORD dwLastError = GetLastError ();
		Event (LS (L_CANTRENAMEBACK), EDT_RESPONSE_E);
		DescribeAPIError (&dwLastError);
		lstrcpy (m_dp.pszFileName, szFileNameFrom);
		setDirty();
	}
}

BOOL fsDownloadMgr::DeleteFile()
{
	if (m_dwDownloadFileFlags & DFF_NEED_INIT_FILE) 
		return TRUE;

	StopDownloading ();

	CloseFile ();

	if (GetFileAttributes (m_dp.pszFileName) != DWORD (-1))
	{
		fsString str = m_dp.pszFileName;
		str += ".dsc.txt";	
		::DeleteFile (str);
		return ::DeleteFile (m_dp.pszFileName);
	}
	else
		return TRUE;
}

void fsDownloadMgr::CloseFile()
{
	if (m_hOutFile != INVALID_HANDLE_VALUE)
	{
		m_dldr.SetOutputFile (INVALID_HANDLE_VALUE);
		CloseHandle (m_hOutFile);
		m_hOutFile = INVALID_HANDLE_VALUE;
	}
}

void fsDownloadMgr::CreateCompleteDownload(UINT64 uFileSize)
{
	m_dldr.SetFileSize(uFileSize);
	m_dldr.CreateCompleteSection(uFileSize);
	setStateFlagsTo (DS_DONE);
}

void fsDownloadMgr::AddSection(UINT64 uStart, UINT64 uEnd, UINT64 uCurrent)
{
	m_dldr.AddSection(uStart, uEnd, uCurrent);
}

void fsDownloadMgr::SetFileSize(UINT64 uFileSize)
{
	m_dldr.SetFileSize(uFileSize);
}

DWORD fsDownloadMgr::GetDownloadFileFlag() const
{
	return m_dwDownloadFileFlags;
}

void fsDownloadMgr::SetDownloadFileFlag(DWORD dwFlag)
{
	m_dwDownloadFileFlags = dwFlag;
}

fsInternetResult fsDownloadMgr::GetLastError()
{
	return m_lastError;
}

BOOL fsDownloadMgr::InitFile(BOOL bCreateOnDisk, LPCSTR pszSetExt)
{
	CString strFileName;

	if (strlen(m_dp.pszFileName) > 0)
	{
		InitFile_ProcessMacroses ();
	}

	
	if (FALSE == BuildFileName (pszSetExt))
	{
		Event (LS (L_FILENAMETOOLONG), EDT_RESPONSE_E);
		setStateFlags (DS_NEEDSTOP);
		m_bFatalError = TRUE;
		return FALSE;
	}

	bool bIsIncFileExt = ((m_dp.pszAdditionalExt != NULL) && (*m_dp.pszAdditionalExt != 0)); 
	m_sOriginalFile = (LPCTSTR)m_dp.pszFileName;

	
	ApplyAdditionalExt ();

	

	if (!fsBuildPathToFile (m_dp.pszFileName))
		goto _lErr;

	if (DWORD (-1) != GetFileAttributes (m_dp.pszFileName)) 
	{
		fsAlreadyExistReaction enAER = m_dp.enAER;

		BOOL bRet = ApplyAER (enAER);

		if (bRet == FALSE)
			goto _lErr;
		else if (bRet == BOOL (-1))
			return FALSE;
	} else {

#ifndef FDM_DLDR__RAWCODEONLY
		if (bIsIncFileExt && DWORD (-1) != GetFileAttributes (m_sOriginalFile)) 
#else
		if (bIsIncFileExt && DWORD (-1) != GetFileAttributes ((LPTSTR)m_sOriginalFile)) 
#endif
		{
			fsAlreadyExistReaction enAER = m_dp.enAER;

			BOOL bRet = ApplyAER (enAER, false);

			if (bRet == FALSE)
				goto _lErr;
			else if (bRet == BOOL (-1))
				return FALSE;
		}
	}

	if (bCreateOnDisk)
	{
		HANDLE hFile = CreateFile (m_dp.pszFileName, GENERIC_READ, FILE_SHARE_READ, NULL,
			OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
			goto _lErr;

		SetFileTime (hFile);

		CloseHandle (hFile);
	}

	m_dwDownloadFileFlags &= ~DFF_NEED_INIT_FILE;	
	setDirty();

	return TRUE;

_lErr:
	DescribeAPIError ();
	m_bFatalError = TRUE;
	setStateFlags (DS_NEEDSTOP);
	return FALSE;
}

BOOL fsDownloadMgr::IsFileInit()
{
	return (m_dwDownloadFileFlags & DFF_NEED_INIT_FILE) == 0;
}

BOOL fsDownloadMgr::IsSectionCanBeAdded()
{
	
	
	if (m_dldr.IsHavingError ())
		return FALSE;

	
	if ((m_dwState & DS_NEEDSTOP) || ((m_dwState & DS_DOWNLOADING) == 0))
		return FALSE;

	
	if (m_dldr.IsAllSectionsOk () == FALSE)
		return FALSE;

	
	if (UINT (m_dldr.GetNumberOfSections () - m_dldr.GetDoneSectionCount ()) < m_dp.uMaxSections)
		return TRUE;	

	return FALSE;
}

fsInternetResult fsDownloadMgr::RestartDownloading()
{
	fsInternetResult ir = SetToRestartState ();

	std::string dir = m_dp.pszFileName;
	int dirEnd = dir.rfind("\\");
	if (dirEnd != -1 && dirEnd < dir.length() - 1)
	{
		m_dp.pszFileName[dirEnd + 1] = 0;
	}

	if (ir != IR_SUCCESS)
		return ir;

	return StartDownloading ();
}

void fsDownloadMgr::StopSection()
{
	if (IsRunning () == FALSE)
		return;

	if (m_dldr.GetRunningSectionCount () == 1)
		StopDownloading ();
	else
		m_dldr.StopSection ();
}

void fsDownloadMgr::CreateOneMoreSection()
{
	if (m_dldr.IsSectionCreatingNow () == FALSE) {
		setStateFlags (DS_NEEDADDSECTION2);
		setDirty();
	}
}

fsInternetResult fsDownloadMgr::QuerySize(BOOL bCheckPoss)
{
	if (bCheckPoss) 
		if (IsRunning () || IsQueringSize ())
			return IR_S_FALSE;

	fsInternetResult ir;

	setStateFlags (DS_QUERINGSIZE);
	
	ir = CreateInternetSession ();
	if (ir != IR_SUCCESS)
	{
		removeStateFlags (DS_QUERINGSIZE);
		return ir;
	}

	ApplyProperties ();

	ir = m_dldr.QuerySize ();

	removeStateFlags (DS_QUERINGSIZE);
	return ir;
}

BOOL fsDownloadMgr::IsQueringSize()
{
	return m_dwState & DS_QUERINGSIZE;
}

void fsDownloadMgr::QuerySize2()
{
	if (IsRunning () || IsQueringSize ())
		return;

	setStateFlags (DS_QUERINGSIZE);
	
	DWORD dw;
	InterlockedIncrement (&m_iThread);
	CloseHandle (CreateThread (NULL, 0, _threadQSize, this, 0, &dw));
}

DWORD WINAPI fsDownloadMgr::_threadQSize(LPVOID lp)
{
	fsDownloadMgr *pThis = (fsDownloadMgr*) lp;
	try
	{
		pThis->Event (LS (L_QUERINGSIZE));
		fsInternetResult ir = pThis->QuerySize (FALSE);
		if (ir != IR_SUCCESS)
		{
			char szErr [10000];
			fsIRToStr (ir, szErr, sizeof (szErr));
			pThis->Event (szErr, EDT_RESPONSE_E);
		}
		else
			pThis->Event (LS (L_DONE), EDT_DONE);
		pThis->Event (DE_EXTERROR, DMEE_FILEUPDATED);	
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadMgr::_threadQSize " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadMgr::_threadQSize unknown exception");
	}

	InterlockedDecrement (&pThis->m_iThread);
	return 0;
}

void fsDownloadMgr::StopQuering()
{
	if (IsQueringSize ())
	{
		m_dldr.StopDownloading (); 
	}
}

BOOL fsDownloadMgr::IsCantStart()
{
	return m_bCantStart;
}

void fsDownloadMgr::CloneSettings(fsDownloadMgr *src)
{
	fsDownload_Properties *dp = src->GetDP ();
	fsDownload_NetworkProperties *dnp = src->GetDNP ();
	fsDownload_NetworkProperties *mydnp = GetDNP ();

	CopyMemory (m_dp.aEP, dp->aEP, sizeof (m_dp.aEP));
	m_dp.dwFlags = dp->dwFlags;
	m_dp.bIgnoreRestrictions = dp->bIgnoreRestrictions;
	m_dp.bReserveDiskSpace = dp->bReserveDiskSpace;
	m_dp.bRestartSpeedLow = dp->bRestartSpeedLow;
	m_dp.enAER = dp->enAER;
	m_dp.enSCR = dp->enSCR;

	SAFE_DELETE_ARRAY (m_dp.pszAdditionalExt);
	m_dp.pszAdditionalExt = new char [strlen (dp->pszAdditionalExt) + 1];
	strcpy (m_dp.pszAdditionalExt, dp->pszAdditionalExt);

	SAFE_DELETE_ARRAY (m_dp.pszCreateExt);
	m_dp.pszCreateExt = new char [strlen (dp->pszCreateExt) + 1];
	strcpy (m_dp.pszCreateExt, dp->pszCreateExt);

	if (m_dp.pszFileName == NULL || *m_dp.pszFileName == 0 || m_dp.pszFileName [strlen (m_dp.pszFileName) - 1] == '\\' ||  m_dp.pszFileName [strlen (m_dp.pszFileName) - 1] == '/')
	{
		if (dp->pszFileName)
		{
			SAFE_DELETE_ARRAY (m_dp.pszFileName);
			m_dp.pszFileName = new char [strlen (dp->pszFileName) + 1];
			strcpy (m_dp.pszFileName, dp->pszFileName);
		}
	}
	m_dp.uMaxAttempts = dp->uMaxAttempts;
	m_dp.uMaxSections = dp->uMaxSections;
	m_dp.uRetriesTime = dp->uRetriesTime;
	m_dp.uSectionMinSize = dp->uSectionMinSize;
	m_dp.uTimeout = dp->uTimeout;
	m_dp.uTrafficRestriction = dp->uTrafficRestriction;

	mydnp->dwFtpFlags = dnp->dwFtpFlags;
	mydnp->bUseCookie = dnp->bUseCookie;
	mydnp->bUseHttp11 = dnp->bUseHttp11;
	mydnp->enAccType = dnp->enAccType;
	mydnp->enFtpTransferType = dnp->enFtpTransferType;

	SAFE_DELETE_ARRAY (mydnp->pszAgent);
	mydnp->pszAgent = new char [strlen (dnp->pszAgent) + 1];
	strcpy (mydnp->pszAgent, dnp->pszAgent);

	SAFE_DELETE_ARRAY (mydnp->pszASCIIExts);
	mydnp->pszASCIIExts = new char [strlen (dnp->pszASCIIExts) + 1];
	strcpy (mydnp->pszASCIIExts, dnp->pszASCIIExts);

	SAFE_DELETE_ARRAY (mydnp->pszReferer);
	mydnp->pszReferer = new char [strlen (dnp->pszReferer) + 1];
	strcpy (mydnp->pszReferer, dnp->pszReferer);

	SAFE_DELETE_ARRAY (mydnp->pszUserName);
	mydnp->pszUserName = new char [strlen (dnp->pszUserName) + 1];
	strcpy (mydnp->pszUserName, dnp->pszUserName);

	SAFE_DELETE_ARRAY (mydnp->pszPassword);
	mydnp->pszPassword = new char [strlen (dnp->pszPassword) + 1];
	strcpy (mydnp->pszPassword, dnp->pszPassword);
}

void fsDownloadMgr::Set_MirrRecalcSpeedTime(UINT u)
{
	m_uMirrRecalcSpeedTime = u;
}

fsInternetResult fsDownloadMgr::FindMirrors()
{
	fsInternetResult ir = CreateInternetSession ();
	if (ir != IR_SUCCESS)
	{
		removeStateFlags (DS_QUERINGSIZE);
		return ir;
	}

	ApplyProperties ();

	return m_dldr.FindMirrors ();
}

fsInternetResult fsDownloadMgr::SetToRestartState()
{
	if (IsRunning ())
		return IR_S_FALSE;

	if (IsFileInit ())
	{
		if (m_dp.enAER != AER_RENAME_2)
			DeleteFile ();
		else
			m_bRename_CheckIfRenamed = TRUE;
		m_dwDownloadFileFlags |= DFF_NEED_INIT_FILE;
		setDirty();
	}

	m_dldr.DeleteAllSections ();

	return IR_SUCCESS;
}

void fsDownloadMgr::CheckMirrSpeedRecalcRequired()
{
	if (m_uMirrRecalcSpeedTime == 0)
		return;

	fsTicksMgr tikNow;

	tikNow.Now ();

	if (tikNow - m_tikLastMirrMeasureTime > m_uMirrRecalcSpeedTime*60*1000)
	{
		m_tikLastMirrMeasureTime.Now ();
		DWORD dwThread;
		InterlockedIncrement (&m_iThread);
		CloseHandle (CreateThread (NULL, 0, _threadCalcMirrSpeed, this, 0, &dwThread));
	}
}

DWORD WINAPI fsDownloadMgr::_threadCalcMirrSpeed(LPVOID lp)
{
	fsDownloadMgr* pThis = (fsDownloadMgr*) lp;

	try 
	{
		pThis->MeasureMirrorsSpeed ();
	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadMgr::_threadCalcMirrSpeed " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadMgr::_threadCalcMirrSpeed unknown exception");
	}

	InterlockedDecrement (&pThis->m_iThread);

	return 0;
}

void fsDownloadMgr::MeasureMirrorsSpeed()
{
	Event (LS (L_CALCULATINGMIRRORSSPEED));
	m_dldr.MeasureMirrorsSpeed ();
	m_tikLastMirrMeasureTime.Now ();
	Event (LS (L_MIRRORSSPEEDWASMEASURED), EDT_RESPONSE_S);
}

BOOL fsDownloadMgr::OnNeedFile_FinalInit()
{
	SetFileTime (m_hOutFile);

	
	if (!ReserveDiskSpace ())
	{
		if (m_dwState & DS_NEEDSTOP)
			return FALSE;
		goto _lErr;
	}

	return TRUE;

_lErr:	
	DescribeAPIError ();	
	setStateFlags (DS_NEEDSTOP);	
	Event (DE_EXTERROR, DMEE_FATALERROR);
	m_bFatalError = TRUE;
	return FALSE;
}

void fsDownloadMgr::RemoveHiddenAttribute()
{
	if (m_dp.dwFlags & DPF_USEHIDDENATTRIB)
	{
		DWORD dw = GetFileAttributes (m_dp.pszFileName);
		dw &= ~ FILE_ATTRIBUTE_HIDDEN;
		SetFileAttributes (m_dp.pszFileName, dw);
	}
}

void fsDownloadMgr::CheckDstFileExists()
{
	
	if (GetFileAttributes (m_dp.pszFileName) != DWORD (-1))
	{
		fsAlreadyExistReaction enAER = m_dp.enAER;	

		if (enAER == AER_ASKUSER)
		{
			#ifndef FDM_DLDR__RAWCODEONLY
			CAERDlg dlg;

			dlg.m_pszFile = m_dp.pszFileName;
			dlg.DisableStopAndResume ();
			_DlgMgr.OnDoModal (&dlg);
			dlg.DoModal ();
			_DlgMgr.OnEndDialog (&dlg);

			if (dlg.m_bDontAskAgain)
			{
				m_dp.enAER = dlg.m_enAER;
				setDirty();
				_App.AlreadyExistReaction (dlg.m_enAER);
			}

			enAER = dlg.m_enAER;
			#else
			enAER = AER_REWRITE;
			#endif
		}

		switch (enAER)
		{
			case AER_REWRITE:
				Event (LS (L_REWRITINGIT), EDT_WARNING);
				if (FALSE == ::DeleteFile (m_dp.pszFileName))
				{
					DWORD dwLastError = GetLastError ();
					Event (LS (L_CANTREWRITE), EDT_RESPONSE_E);
					DescribeAPIError (&dwLastError);
					Event (LS (L_WILLBERENAMED), EDT_WARNING);
					RenameFile (FALSE); 
				}
				break;

			case AER_STOP:
			case AER_RESUME:
			case AER_RENAME:
			case AER_RENAME_2:
				RenameFile ();
				break;
		}
	}
}

void fsDownloadMgr::AppendCommentToFileName(BOOL bMoveFile)
{
	if (m_dld == NULL || m_dld->strComment.GetLength () == 0)
		return;
	
	char szOldName [MY_MAX_PATH];
	strcpy (szOldName, m_dp.pszFileName);

	LPCSTR pszExt = strrchr (szOldName, '.');

	delete [] m_dp.pszFileName;

	m_dp.pszFileName = new char [strlen (szOldName) + m_dld->strComment.GetLength () + 10 + 1];

	std::string strComment = m_dld->strComment;
	while (strComment.empty () == false && strComment [0] == ' ')
		strComment.erase (strComment.begin ());
	while (strComment.empty () == false && strComment [strComment.length ()-1] == ' ')
		strComment.erase (strComment.end ()-1);
	LPCSTR pszInvChars = ":*?\"<>|";
	for (size_t i = 0; i < strComment.length (); i++)
	{
		if (strchr (pszInvChars, strComment [i]))
			strComment [i] = ' ';
	}

	strcpy (m_dp.pszFileName, szOldName);
	if (pszExt)
	{
		strcpy (m_dp.pszFileName + (pszExt - szOldName), " (");
		strcat (m_dp.pszFileName, strComment.c_str ());
		strcat (m_dp.pszFileName, ")");
		strcat (m_dp.pszFileName, pszExt);
	}

	setDirty();

	if (bMoveFile)
	{
		CheckDstFileExists ();
	
		
		if (FALSE == ::MoveFile (szOldName, m_dp.pszFileName))
		{
			DWORD dwLastError = GetLastError ();
			Event (LS (L_CANTRENAMEBACK), EDT_RESPONSE_E);
			DescribeAPIError (&dwLastError);
		}
	}
}

void fsDownloadMgr::set_Download(fsDownload *dld)
{
	m_dld = dld;
}

BOOL fsDownloadMgr::is_GlobalOffline()
{
	DWORD dwState = 0; 
    DWORD dwSize = sizeof(DWORD);
    BOOL bRet = FALSE;

    if (InternetQueryOption (NULL, 
			INTERNET_OPTION_CONNECTED_STATE, &dwState, &dwSize))
    {
        if (dwState & INTERNET_STATE_DISCONNECTED_BY_USER)
            bRet = TRUE;
    }

    return bRet; 
}

void fsDownloadMgr::set_GlobalOffline(BOOL bOffline)
{
	INTERNET_CONNECTED_INFO ci;
    ZeroMemory (&ci, sizeof(ci));

    if (bOffline) 
    {
        ci.dwConnectedState = INTERNET_STATE_DISCONNECTED_BY_USER;
        ci.dwFlags = ISO_FORCE_DISCONNECTED;
    } 
    else 
    {
        ci.dwConnectedState = INTERNET_STATE_CONNECTED;
    }

    InternetSetOption (NULL, 
        INTERNET_OPTION_CONNECTED_STATE, &ci, sizeof(ci));
}

void fsDownloadMgr::SetFileTime(HANDLE hFile)
{
	if ((m_dp.dwFlags & DPF_RETRDATEFROMSERVER) == 0)
		return;

	FILETIME time = m_dldr.get_FileDate ();
	if (time.dwHighDateTime != 0 || time.dwLowDateTime != 0)
		::SetFileTime (hFile, &time, NULL, NULL);
}

BOOL fsDownloadMgr::MoveFile(LPCSTR pszNewFileName)
{
	if (IsRunning ()) 
	{
		SetLastError (0);
		return FALSE;
	}

	BOOL bOk = TRUE;

	
	if (IsFileInit ())
	{
		fsBuildPathToFile (pszNewFileName);
		
		if (GetFileAttributes (m_dp.pszFileName) != DWORD (-1))
			bOk = ::MoveFile (m_dp.pszFileName, pszNewFileName); 
		else
			bOk = TRUE;
	}
					
	if (bOk == FALSE)
		return FALSE;

	SAFE_DELETE_ARRAY (m_dp.pszFileName);
	fsnew (m_dp.pszFileName, char, lstrlen (pszNewFileName) + 1);
	lstrcpy (m_dp.pszFileName, pszNewFileName);
	setDirty();
	
	return TRUE;
}

BOOL fsDownloadMgr::MoveToFolder(LPCSTR pszPath)
{
	CString str = pszPath;
	ProcessFilePathMacroses (str);

	char szFile [MY_MAX_PATH] = "";
	fsGetFileName (m_dp.pszFileName, szFile);

	char szNewFile [MY_MAX_PATH];
	lstrcpy (szNewFile, str);

	if (szNewFile [lstrlen (szNewFile) - 1] != '\\' &&
			szNewFile [lstrlen (szNewFile) - 1] != '/')
		lstrcat (szNewFile, "\\");

	lstrcat (szNewFile, szFile);

	return MoveFile (szNewFile);
}

fsString fsDownloadMgr::get_URL()
{
	fsURL url;
	char szUrl [10000] = "";
	DWORD dwLen = sizeof (szUrl);

	fsDownload_NetworkProperties* dnp = GetDNP ();

	url.Create (fsNPToScheme (dnp->enProtocol), dnp->pszServerName, dnp->uServerPort,
		NULL, NULL, dnp->pszPathName, szUrl, &dwLen);

	return szUrl;
}

#ifndef FDM_DLDR__RAWCODEONLY
BOOL fsDownloadMgr::CheckIfMalicious()
{
	if (m_dld == NULL || (m_dld->dwFlags & DLD_MALICIOUS_DISABLE_CHECK) ||
			_App.Community_CheckIfMalBeforeDlding () == FALSE)
		return TRUE; 

	if (m_dld->dwFlags & (DLD_MALICIOUS_YES | DLD_MALICIOUS_NO))
		return TRUE; 

	Event (LS (L_CHECKINGIFDLDISMAL), EDT_INQUIRY);

	vmsMaliciousDownloadChecker mdc;
	m_mdc = &mdc;
	fsInternetResult ir = mdc.Check (get_URL ());
	m_mdc = NULL;

	if (ir != IR_SUCCESS)
	{
		char szErr [1000];
		fsIRToStr (ir, szErr, sizeof (szErr));
		Event (szErr, EDT_RESPONSE_E);
		return TRUE;
	}

	int nPerc = MulDiv (mdc.get_MaliciousOpinionCount (), 100, mdc.get_OpinionTotalCount ());
	if (nPerc < _App.Community_MalReportsMinPerc ())
	{
		m_dld->dwFlags |= DLD_MALICIOUS_NO;
		m_dld->setDirty();
		Event (LS (L_DLD_NO_USERS_MAL_REPS), EDT_RESPONSE_S);
		return TRUE;
	}

	m_dld->dwFlags |= DLD_MALICIOUS_YES;
	m_dld->setDirty();
	Event (LS (L_THTREAREMALOPINIONS2), EDT_WARNING);

	CString str;
	str.Format (LS (L_THEREAREMALOPINIONS), mdc.get_MaliciousOpinionCount (),
		mdc.get_OpinionTotalCount (), 2, mdc.get_AverageRating ());
	UINT nRet = MyMessageBox (NULL, str, LS (L_WARNING), NULL, IDI_WARNING, 
		LS (L_YES), LS (L_IGNORE), LS (L_STOP));

	bool bNeedStop = false;

	if (nRet == IDC_BTN3)
		bNeedStop = true;
	else if (nRet == IDC_BTN1)
	{
		m_dld->AddRef (); 
		if (FALSE == _pwndDownloads->SendMessage (WM_DLD_SHOWOPINIONS, 0, (LPARAM)(fsDownload*)m_dld))
			bNeedStop = true;
	}

	if (bNeedStop)
	{
		Event (LS (L_STOPPED), EDT_RESPONSE_S);
		m_dld->dwFlags &= ~DLD_MALICIOUS_YES;
		m_dld->setDirty();
		return FALSE;
	}

	return TRUE;
}
#endif

void fsDownloadMgr::Reset()
{
	ASSERT (IsRunning () == FALSE);
	if (IsRunning ())
		return;

	m_dldr.RemoveAllMirrors ();
	m_dldr.ResetSections ();

	m_dwDownloadFileFlags |= DFF_NEED_INIT_FILE;
	setDirty();
}

void fsDownloadMgr::InitFile_ProcessMacroses()
{
	CString str = m_dp.pszFileName;
	
	ProcessFilePathMacroses (str);

	delete [] m_dp.pszFileName;
	m_dp.pszFileName = new char [str.GetLength () + 1];
	lstrcpy (m_dp.pszFileName, str);
	setDirty();
}

void fsDownloadMgr::ProcessFilePathMacroses(CString &str)
{
#ifndef FDM_DLDR__RAWCODEONLY

	if (str.Find ('%', 0) == -1)
		return;	

	if (str.Find ("%sdrive%") != -1)
	{
		str.Replace ("%sdrive%", CString (vmsGetExeDriveLetter ()) + ":");
		m_dwDownloadFileFlags |= DFF_USE_PORTABLE_DRIVE;
		setDirty();
	}

	str.Replace ("%server%", GetDNP ()->pszServerName);

	char szUrlPath [MY_MAX_PATH];
	fsGetPath (GetDNP ()->pszPathName, szUrlPath);
	if (lstrlen (szUrlPath) > 1)
		str.Replace ("%path_on_server%", szUrlPath);
	else
		str.Replace ("%path_on_server%", "");
	str.Replace ("/", "\\");
	str.Replace ("\\\\", "\\");

	SYSTEMTIME st;
	GetLocalTime (&st);

	str.Replace ("%date%", "%year%-%month%-%day%");

	CString strY, strM, strD;
	strY.Format ("%04d", (int)st.wYear);
	strM.Format ("%02d", (int)st.wMonth);
	strD.Format ("%02d", (int)st.wDay);

	str.Replace ("%year%", strY);
	str.Replace ("%month%", strM);
	str.Replace ("%day%", strD);

	TCHAR szPath[MAX_PATH] = {0,};
	if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, szPath))) {
		str.Replace("%userprofile%", szPath);
	}

#endif
}

void fsDownloadMgr::AdjustKnownFileSharingSiteSupport()
{
	if (!m_bKnownFileSharingSiteSupportAdjusted)
		AdjustKnownFileSharingSiteSupport_RapidShare ();
	if (!m_bKnownFileSharingSiteSupportAdjusted)
		AdjustKnownFileSharingSiteSupport_FileSonic ();
}

int fsDownloadMgr::get_ReservingDiskSpaceProgress()
{
	return 0;
}

DWORD fsDownloadMgr::get_State()
{
	return m_dwState;
}

BOOL fsDownloadMgr::HasActivity()
{
	return m_iThread != 0;
}

DWORD WINAPI fsDownloadMgr::_threadReserveDiskSpace(LPVOID lp)
{
	fsDownloadMgr *pthis = (fsDownloadMgr*)lp;
	
	pthis->setStateFlags (DS_RESERVINGSPACE);
	
	ASSERT (pthis->m_dldr.GetNumberOfSections () == 1);
	ASSERT (pthis->m_dldr.GetLDFileSize () != _UI64_MAX);

	UINT64 uStartPos = pthis->m_dldr.GetDownloadedBytesCount () + 100 * 1024 * 1024;
	
	UINT64 uHundredthPart = pthis->m_dldr.GetLDFileSize () / 100;

	fsTicksMgr timeStart;
	bool bEvent = true;

	for (UINT64 uCurPos = uStartPos; uCurPos < pthis->m_dldr.GetLDFileSize (); uCurPos += uHundredthPart)
	{
		UINT64 uSectLastDownloadPos = pthis->m_dldr.GetDownloadedBytesCount ();

		pthis->m_dldr.LockWriteFile (TRUE);

		if (pthis->m_dldr.GetDownloadedBytesCount () < uCurPos)
		{
			if (!fsSetFilePointer (pthis->m_hOutFile, uCurPos, FILE_BEGIN))
			{
				pthis->m_dldr.LockWriteFile (FALSE);
				break;
			}

			BYTE b = 1; DWORD dw;
			if (FALSE == WriteFile (pthis->m_hOutFile, &b, sizeof (b), &dw, NULL))
			{
				pthis->m_dldr.LockWriteFile (FALSE);
				break;
			}
		}

		pthis->m_dldr.LockWriteFile (FALSE);

		if (pthis->m_dldr.GetDownloadedBytesCount () == uSectLastDownloadPos)
		{
			
			Sleep (50);
		}
		
		if (pthis->m_dldr.IsRunning () == FALSE)
			break;

		fsTicksMgr timeNow;
		if (bEvent && timeNow - timeStart > 3*1000)
		{
			bEvent = false;
			pthis->Event (LS (L_PREP_FILES_ONDISK));
		}
	}
	
	pthis->removeStateFlags (DS_RESERVINGSPACE);
	
	pthis->m_bDontCreateNewSections = FALSE;
	pthis->setStateFlags (DS_NEEDADDSECTION);

	InterlockedDecrement (&pthis->m_iThread);
	return 0;
}

fsString fsDownloadMgr::getFileName()
{
	char szFile [MY_MAX_PATH] = "";
	LPCSTR pszSuggFile = m_dldr.GetSuggestedFileName ();
	if (pszSuggFile && *pszSuggFile)	
	{
		strcpy (szFile, pszSuggFile);
	}
	else
	{
		
		fsFileNameFromUrlPath (GetDNP ()->pszPathName, GetDNP ()->enProtocol == NP_FTP,
			TRUE, szFile, sizeof (szFile));
	}
	if (*szFile == 0)
		fsGetFileName (GetDP ()->pszFileName, szFile);
	return szFile;
}

void fsDownloadMgr::AdjustKnownFileSharingSiteSupport_RapidShare(void)
{
	fsDownload_NetworkProperties *dnp = GetDNP ();

	if (dnp->pszUserName && dnp->pszPassword && *dnp->pszUserName && *dnp->pszPassword)
	{
		if (strnicmp (dnp->pszServerName, "rapidshare.", 11) == 0 ||
			strnicmp (dnp->pszServerName, "www.rapidshare.", 15) == 0)
		{
			char szCookies [1000];
			lstrcpy (szCookies, "user=");
			lstrcat (szCookies, dnp->pszUserName);
			lstrcat (szCookies, "-");
			LPCSTR psz = dnp->pszPassword;
			while (*psz)
				sprintf (szCookies + lstrlen (szCookies), "%%%x", *psz++);

			if (dnp->pszCookies == NULL || *dnp->pszCookies == 0)
			{
				SAFE_DELETE_ARRAY (dnp->pszCookies);
				dnp->pszCookies = new char [lstrlen (szCookies) + 1];
				*dnp->pszCookies = 0;
				setDirty();
			}
			else
			{
				if (strstr (dnp->pszCookies, szCookies) != NULL)
				{
					m_bKnownFileSharingSiteSupportAdjusted = true;
					return;	
				}

				char *psz = new char [lstrlen (dnp->pszCookies) + lstrlen (szCookies) + 10];
				lstrcpy (psz, dnp->pszCookies);
				if (psz [lstrlen (psz) - 1] != ';')
					lstrcat (psz, ";");
				delete [] dnp->pszCookies;
				dnp->pszCookies = psz;
				setDirty();
			}

			lstrcat (dnp->pszCookies, szCookies);

			dnp->dwFlags |= DNPF_IMMEDIATELY_SEND_AUTH_AS_BASIC;
			setDirty();
		}
	}
}

void fsDownloadMgr::AdjustKnownFileSharingSiteSupport_FileSonic(void)
{
	fsDownload_NetworkProperties *dnp = GetDNP ();

	if (!dnp->pszUserName || !dnp->pszPassword || !*dnp->pszUserName || !*dnp->pszPassword)
		return;

	int iServNameLen = strlen (dnp->pszServerName);

	if (iServNameLen < 13)
		return; 

	if (strcmp (dnp->pszServerName, "filesonic.com"))
	{
		if (iServNameLen < 15)
			return; 
		if (strcmp (dnp->pszServerName + iServNameLen - 14, ".filesonic.com"))
			return; 
	}

	dnp->dwFlags |= DNPF_IMMEDIATELY_SEND_AUTH_AS_BASIC | DNPF_DONT_UPDATE_ORIGINAL_URL_AFTER_REDIRECT;
	setDirty();
	m_bKnownFileSharingSiteSupportAdjusted = true;
}

void fsDownloadMgr::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwNeedSize;
	fsDownload_Properties dp = m_dp;
	fsDownload_NetworkProperties dnp = *GetDNP ();
	fs::list <fsDownload_NetworkProperties> vDNPs;

	
	
	
	
	LPCSTR ToSave    [3000];
	DWORD  ToSaveLen [3000];
	UINT   cToSave = 0;

	if (FALSE == m_dldr.SaveSectionsState (NULL, &dwNeedSize))
		return;

	dwNeedSize += sizeof (DWORD); 
	dwNeedSize += sizeof (dp);
	dwNeedSize += sizeof (dnp);
	dwNeedSize += sizeof (m_dwState);
	dwNeedSize += sizeof (m_dwDownloadFileFlags);
	dwNeedSize += sizeof (int);		

	

	dp.pszFileName = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dp.pszFileName));
	dwNeedSize += (DWORD) dp.pszFileName;

	dp.pszAdditionalExt = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dp.pszAdditionalExt));
	dwNeedSize += (DWORD) dp.pszAdditionalExt;

	dp.pszCreateExt = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dp.pszCreateExt));
	dwNeedSize += (DWORD) dp.pszCreateExt;

	dp.pszCheckSum = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dp.pszCheckSum));
	dwNeedSize += (DWORD) dp.pszCheckSum;

	int cDPStrings = cToSave;

	UINT i = 0;
	for (i = 0; int (i) < m_dldr.GetMirrorURLCount () + 1; i++)
	{
		if (i)
		{
			dnp = *m_dldr.MirrorDNP (i-1);
			dwNeedSize += sizeof (dnp);
		}
		
		dnp.pszAgent = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszAgent));
		dnp.pszPassword = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszPassword));
		dnp.pszPathName = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszPathName));
		dnp.pszProxyName = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszProxyName));
		dnp.pszProxyPassword = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszProxyPassword));
		dnp.pszProxyUserName = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszProxyUserName));
		dnp.pszReferer = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszReferer));
		dnp.pszServerName = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszServerName));
		dnp.pszUserName = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszUserName));
		dnp.pszASCIIExts = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszASCIIExts));
		dnp.pszCookies = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszCookies));
		dnp.pszPostData = LPSTR (ToSaveLen [cToSave++] = strlen (ToSave [cToSave] = dnp.pszPostData));

		vDNPs.add (dnp);

		dwNeedSize += (DWORD) dnp.pszAgent + (DWORD) dnp.pszPassword + 
			(DWORD) dnp.pszPathName + (DWORD) dnp.pszProxyName + 
			(DWORD) dnp.pszProxyPassword + (DWORD) dnp.pszProxyUserName + 
			(DWORD) dnp.pszReferer + (DWORD) dnp.pszServerName + (DWORD) dnp.pszUserName + 
			(DWORD) dnp.pszASCIIExts + (DWORD) dnp.pszCookies + (DWORD) dnp.pszPostData;
	}

	dwNeedSize += m_dldr.GetMirrorURLCount () * sizeof (BOOL);	

	if (m_dldr.GetMirrorURLCount ())
	{
		dwNeedSize += m_dldr.GetMirrorURLCount () * sizeof (DWORD); 
		dwNeedSize += sizeof (DWORD); 
	}

	if (pb == NULL)
	{
		*pdwSize = dwNeedSize;
		return;
	}

	if (*pdwSize < dwNeedSize)
	{
		*pdwSize = dwNeedSize;
		return;
	}

	int cDNPStrings;	
	cDNPStrings = (cToSave - cDPStrings) / (m_dldr.GetMirrorURLCount () + 1);

	
	DWORD dw = *pdwSize;
	LPBYTE pB = (LPBYTE) pb;

	if (FALSE == m_dldr.SaveSectionsState (pB + sizeof (DWORD), &dw))
		return;

	CopyMemory (pB, &dw, sizeof (dw));
	pB += dw + sizeof (dw);

	CopyMemory (pB, &dp, sizeof (dp));
	pB += sizeof (dp);

	CopyMemory (pB, &vDNPs [0], sizeof (dnp));
	pB += sizeof (dnp);

	fsDownloadState state = (m_dwState & DS_DONE) ? DS_DONE : 0;
	CopyMemory (pB, &state, sizeof (state));
	pB += sizeof (state);

	if ((m_dwDownloadFileFlags & DFF_USE_PORTABLE_DRIVE) &&
			m_dp.pszFileName [0] != vmsGetExeDriveLetter ())
		m_dwDownloadFileFlags &= ~DFF_USE_PORTABLE_DRIVE;
	CopyMemory (pB, &m_dwDownloadFileFlags, sizeof (m_dwDownloadFileFlags));
	pB += sizeof (m_dwDownloadFileFlags);

	int cMirrs = m_dldr.GetMirrorURLCount ();
	CopyMemory (pB, &cMirrs, sizeof (cMirrs));
	pB += sizeof (cMirrs);

	for (i = 0; i < cToSave; i++)
	{
		if (i > UINT (cDPStrings) && ((i-cDPStrings) % cDNPStrings) == 0)
		{
			CopyMemory (pB, &vDNPs [(i-cDPStrings) / cDNPStrings], sizeof (dnp));
			pB += sizeof (dnp);

			BOOL b = m_dldr.GetMirrorIsGood ((i-cDPStrings) / cDNPStrings - 1);
			CopyMemory (pB, &b, sizeof (b));
			pB += sizeof (b);
		}

		CopyMemory (pB, ToSave [i], ToSaveLen [i]);
		pB += ToSaveLen [i];
	}

	if (cMirrs)
	{
		for (i = 0; i < UINT (cMirrs); i++)
		{
			DWORD dw = m_dldr.GetMirrorPingTime (i);
			CopyMemory (pB, &dw, sizeof (dw));
			pB += sizeof (dw);
		}

		DWORD dw = m_dldr.Get_BaseServerPingTime ();
		CopyMemory (pB, &dw, sizeof (dw));
		pB += sizeof (dw);
	}

	*pdwSize = dwNeedSize;
}

bool fsDownloadMgr::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	#define CHECK_BOUNDS(need) if (need < 0 || need > int(*pdwSize) - (pB - LPBYTE (pb))) return false;

	if (dwVer <= 15)
		return false;

	DWORD dw = *pdwSize;
	LPBYTE pB = (LPBYTE) pb;

	CHECK_BOUNDS (sizeof (DWORD));

	CopyMemory (&dw, pB, sizeof (DWORD));
	pB += sizeof (DWORD);

	CHECK_BOUNDS (int (dw));	

	if (FALSE == m_dldr.RestoreSectionsState (pB, dw, dwVer))
		return FALSE;
	pB += dw;

	CHECK_BOUNDS (sizeof (m_dp));

	DWORD dwDP = sizeof (fsDownload_Properties);
	CopyMemory (&m_dp, pB, dwDP);
	pB += dwDP;

	fsDownload_NetworkProperties *dnp = GetDNP ();
	DWORD dwDNP = sizeof (fsDownload_NetworkProperties);
	CHECK_BOUNDS ((int)dwDNP);
	CopyMemory (dnp, pB, dwDNP);
	pB += dwDNP;

	CHECK_BOUNDS (sizeof (m_dwState));

	CopyMemory (&m_dwState, pB, sizeof (m_dwState));
	pB += sizeof (m_dwState);

	CHECK_BOUNDS (sizeof (m_dwDownloadFileFlags));

	CopyMemory (&m_dwDownloadFileFlags, pB, sizeof (m_dwDownloadFileFlags));
	pB += sizeof (m_dwDownloadFileFlags);

	int cMirrs = 0;
	CHECK_BOUNDS (sizeof (int));

	CopyMemory (&cMirrs, pB, sizeof (int));
	pB += sizeof (int);

	dw = DWORD (m_dp.pszFileName);
	CHECK_BOUNDS (int (dw));
	fsnew (m_dp.pszFileName, CHAR, dw+1);
	CopyMemory (m_dp.pszFileName, pB, dw);
	m_dp.pszFileName [dw] = 0;
	pB += dw;
	if (m_dwDownloadFileFlags & DFF_USE_PORTABLE_DRIVE)
		m_dp.pszFileName [0] = vmsGetExeDriveLetter ();

	dw = DWORD (m_dp.pszAdditionalExt);
	CHECK_BOUNDS (int (dw));
	fsnew (m_dp.pszAdditionalExt, CHAR, dw+1);
	CopyMemory (m_dp.pszAdditionalExt, pB, dw);
	m_dp.pszAdditionalExt [dw] = 0;
	pB += dw;

	
	dw = DWORD (m_dp.pszCreateExt);
	CHECK_BOUNDS (int (dw));
	fsnew (m_dp.pszCreateExt, CHAR, dw+1);
	CopyMemory (m_dp.pszCreateExt, pB, dw);
	m_dp.pszCreateExt [dw] = 0;
	pB += dw;
	

	dw = DWORD (m_dp.pszCheckSum);
	CHECK_BOUNDS (int (dw));
	fsnew (m_dp.pszCheckSum, CHAR, dw+1);
	CopyMemory (m_dp.pszCheckSum, pB, dw);
	m_dp.pszCheckSum [dw] = 0;
	pB += dw;

	int i = 0;
	for (i = 0; i < cMirrs + 1; i++)
	{
		fsDownload_NetworkProperties tmpdnp;
		BOOL bMirrIsGood;

		if (i)
		{
			dnp = &tmpdnp;

			CHECK_BOUNDS ((int)dwDNP);
			CopyMemory (dnp, pB, dwDNP);
			pB += dwDNP;

			CHECK_BOUNDS (sizeof (BOOL));

			CopyMemory (&bMirrIsGood, pB, sizeof (BOOL));
			pB += sizeof (BOOL);
		}

		dw = DWORD (dnp->pszAgent);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszAgent, CHAR, dw+1);
		CopyMemory (dnp->pszAgent, pB, dw);
		dnp->pszAgent [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszPassword);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszPassword, CHAR, dw+1);
		CopyMemory (dnp->pszPassword, pB, dw);
		dnp->pszPassword [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszPathName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszPathName, CHAR, dw+1);
		CopyMemory (dnp->pszPathName, pB, dw);
		dnp->pszPathName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszProxyName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszProxyName, CHAR, dw+1);
		CopyMemory (dnp->pszProxyName, pB, dw);
		dnp->pszProxyName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszProxyPassword);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszProxyPassword, CHAR, dw+1);
		CopyMemory (dnp->pszProxyPassword, pB, dw);
		dnp->pszProxyPassword [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszProxyUserName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszProxyUserName, CHAR, dw+1);
		CopyMemory (dnp->pszProxyUserName, pB, dw);
		dnp->pszProxyUserName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszReferer);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszReferer, CHAR, dw+1);
		CopyMemory (dnp->pszReferer, pB, dw);
		dnp->pszReferer [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszServerName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszServerName, CHAR, dw+1);
		CopyMemory (dnp->pszServerName, pB, dw);
		dnp->pszServerName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszUserName);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszUserName, CHAR, dw+1);
		CopyMemory (dnp->pszUserName, pB, dw);
		dnp->pszUserName [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszASCIIExts);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszASCIIExts, CHAR, dw+1);
		CopyMemory (dnp->pszASCIIExts, pB, dw);
		dnp->pszASCIIExts [dw] = 0;
		pB += dw;

		
		dw = DWORD (dnp->pszCookies);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszCookies, CHAR, dw+1);
		CopyMemory (dnp->pszCookies, pB, dw);
		dnp->pszCookies [dw] = 0;
		pB += dw;

		dw = DWORD (dnp->pszPostData);
		CHECK_BOUNDS (int (dw));
		fsnew (dnp->pszPostData, CHAR, dw+1);
		CopyMemory (dnp->pszPostData, pB, dw);
		dnp->pszPostData [dw] = 0;
		pB += dw;

		if (i)
			m_dldr.AddMirror (dnp,  TRUE, TRUE);
	}

	if (cMirrs)
	{
		for (i = 0; i < cMirrs; i++)
		{
			DWORD dw;

			CHECK_BOUNDS (sizeof (dw));

			CopyMemory (&dw, pB, sizeof (dw));
			pB += sizeof (dw);

			m_dldr.Set_MirrPingTime (i, dw);
		}

		DWORD dw;

		CHECK_BOUNDS (sizeof (dw));

		CopyMemory (&dw, pB, sizeof (dw));
		pB += sizeof (dw);

		m_dldr.Set_BaseServerPingTime (dw);
	}

	*pdwSize = pB - (LPBYTE) pb;

	return TRUE;
}

UINT64 fsDownloadMgr::getSpeed(bool bOfDownload)
{
	return bOfDownload ? GetDownloader ()->GetSpeed () : 0;
}

void fsDownloadMgr::setSpeedLimit(bool bForDownload, UINT64 uLimit)
{
	UINT uLimitUINT = uLimit == UINT64_MAX ? UINT_MAX : (UINT)uLimit;
	if (bForDownload)
		GetDownloader ()->LimitTraffic (uLimitUINT);
}

UINT64 fsDownloadMgr::getSpeedLimit(bool bOfDownload)
{
	UINT uLimit = bOfDownload ? GetDownloader ()->GetTrafficLimit () : UINT_MAX;
	return uLimit == UINT_MAX ? UINT64_MAX : uLimit;
}

bool fsDownloadMgr::isResumeSupported(void)
{
	return GetDownloader ()->IsResumeSupported () != RST_NONE;
}

bool fsDownloadMgr::isNoSpeedLimit(bool bOfDownload)
{
	return bOfDownload ? GetDP ()->bIgnoreRestrictions != FALSE : true;
}

UINT64 fsDownloadMgr::getInternalSpeedLimit(bool bOfDownload)
{
	return bOfDownload && GetDP ()->uTrafficRestriction != UINT_MAX ? 
		GetDP ()->uTrafficRestriction : _UI64_MAX;
}

bool fsDownloadMgr::isRequiresTraffic(bool bForDownload)
{
	return bForDownload;
}

bool fsDownloadMgr::isSpeedCanBeLimitedBySomeInternalReasons (bool bForDownload)
{
	return (m_dwState & DS_RESERVINGSPACE) != 0;
}

bool fsDownloadMgr::isInternetTraffic (bool bForDownload)
{
	return GetDNP ()->enProtocol != NP_FILE &&
		(m_dldr.GetState () & IDS_MIRRORS_HAS_LOCAL_SOURCE) == 0;
}

void fsDownloadMgr::setStateFlags (DWORD dwFlags)
{
	vmsAUTOLOCKSECTION (m_csState);
	m_dwState |= dwFlags;
	setDirty();
}

void fsDownloadMgr::setStateFlagsTo (DWORD dwFlags)
{
	vmsAUTOLOCKSECTION (m_csState);
	m_dwState = dwFlags;
	setDirty();
}

void fsDownloadMgr::removeStateFlags (DWORD dwFlags)
{
	vmsAUTOLOCKSECTION (m_csState);
	m_dwState &= ~dwFlags;
	setDirty();
}

bool fsDownloadMgr::IsFailedToCreateDestinationFile() const
{
	return m_bFailedToCreateDestinationFile;
}

bool fsDownloadMgr::IsNotEnoughDiskSpace() const
{
	return m_bIsNotEnoughDiskSpace;
}
