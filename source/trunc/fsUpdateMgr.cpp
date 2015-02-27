/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsUpdateMgr.h"
#include "MainFrm.h"
#include "mfchelp.h"
#include "vmsSecurity.h"
#include "vmsAppMutex.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsUpdateMgr::fsUpdateMgr()
{
	m_bRunning = FALSE;
	m_pfnEvents = NULL;
	m_pfnDescEvents= NULL;
	m_dwFlags = 0;
}

fsUpdateMgr::~fsUpdateMgr()
{
	SAFE_DELETE (m_dldr);
}

void fsUpdateMgr::ReadSettings()
{
	m_enAUT = _App.Update_AutoUpdateType ();
	m_strDlFullInstallPath = m_strDlUpgradesPath = m_strUpdateUrl = _App.Update_URL ();
}

void fsUpdateMgr::SaveSettings()
{
	_App.Update_AutoUpdateType (m_enAUT);
	if (m_strUpdateUrl.GetLength ())
		_App.Update_URL (m_strUpdateUrl);
}

BOOL fsUpdateMgr::StartUpdater()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	ZeroMemory (&pi, sizeof (pi));

	extern vmsAppMutex _appMutex;

	CString strCmdLine;
	strCmdLine.Format ("\"%s\" \"%s\" \"%s\" \"%s\" \"/silent\" \"0\"",
		vmsGetAppFolder () + "updater.exe", 
		((CFdmApp*)AfxGetApp ())->m_strAppPath + "fdm.exe", 
		_appMutex.getName (), 
		m_strUpdateFile);

	if (FALSE == CreateProcess (NULL, (LPSTR)(LPCSTR)strCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		return FALSE;

	return TRUE;
}

void fsUpdateMgr::CheckForUpdate(bool bByUser)
{
	if (m_bRunning || IS_PORTABLE_MODE)
		return;

	m_bCheckingByUser = bByUser;

	SAFE_DELETE (m_dldr);
	fsnew1 (m_dldr, fsDownloadMgr (NULL));
	m_dldr->SetEventFunc (_DownloadMgrEvents, this);
	m_dldr->SetEventDescFunc (_DownloadMgrDescEvents, this);
	
	m_bRunning = TRUE;
	m_bChecking = TRUE;

	CMainFrame* pFrm = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	CString strUrl = m_strUpdateUrl;

	strUrl += "proupd2.lst";

	LPCSTR pszCustomizer = pFrm->get_Customizations ()->get_Customizer ();
	if (pszCustomizer != NULL && lstrlen (pszCustomizer) != 0)
	{
		strUrl += "?edition=";
		strUrl += pszCustomizer;
	}

	m_dldr->CreateByUrl (strUrl);
	
	fsDownload_Properties *dp = m_dldr->GetDP ();
	fsDownload_NetworkProperties *dnp = m_dldr->GetDNP ();

	SAFE_DELETE_ARRAY (dp->pszFileName);
	CString strFile = fsGetDataFilePath ("Update\\");	
	fsnew (dp->pszFileName, char, strFile.GetLength () + 1);
	strcpy (dp->pszFileName, strFile);
	dp->uMaxSections = 1;
	dp->uMaxAttempts = 1;
	dp->dwFlags |= DPF_DONTRESTARTIFNORESUME;
	dp->enSCR = SCR_STOP;
	dp->enAER = AER_REWRITE;
	*dp->pszAdditionalExt = 0;

	SAFE_DELETE_ARRAY (dnp->pszReferer);

	fsnew (dnp->pszReferer, char, 100);
	sprintf (dnp->pszReferer, "FDM - Build number = %s", vmsFdmAppMgr::getBuildNumberAsString ());

	Event (UME_CONNECTING);

	m_dldr->StartDownloading ();
}

DWORD fsUpdateMgr::_DownloadMgrEvents(fsDownloadMgr* pMgr, fsDownloaderEvent ev, UINT uInfo, LPVOID lp)
{
	fsUpdateMgr *pThis = (fsUpdateMgr*) lp;

	switch (ev)
	{
		case DE_SECTIONSTARTED:
			if (pMgr->GetDownloader ()->GetRunningSectionCount ())
			{
				if (pThis->m_bChecking)
					pThis->Event (UME_RETREIVINGUPDLST);
				else
					pThis->Event (UME_RETREIVINGUPDATE);
			}
		break;

		case DE_EXTERROR:
			if (uInfo == DMEE_STOPPEDORDONE)
			{
				if (pMgr->IsDone ())
				{
					if (pThis->m_bChecking)
					{
						SYSTEMTIME time;
						GetLocalTime (&time);
						_App.NewVerExists (TRUE);
						_App.Update_LastCheck (time);

						pThis->Event (UME_UPDLSTDONE);
						pThis->m_bChecking = FALSE;
						pThis->ProcessUpdateLstFile ();
					}
					else
					{
						CString strKeyFile = ((CFdmApp*)AfxGetApp ())->m_strAppPath;
						strKeyFile += "sigkey.dat";
						if (GetFileAttributes (strKeyFile) == DWORD (-1))
							strKeyFile = fsGetProgramFilePath ("sigkey.dat");
						if (false == vmsSecurity::VerifySign (pThis->m_dldr->GetDP ()->pszFileName, strKeyFile))
						{
							DeleteFile (pThis->m_dldr->GetDP ()->pszFileName);
							pThis->Event (UME_VERIFYSIGN_ERROR);
							pThis->m_bRunning = FALSE;
						}
						else
						{
							pThis->m_strUpdateFile = pThis->m_dldr->GetDP ()->pszFileName;
							pThis->Event (UME_UPDATEDONE);
							pThis->m_bRunning = FALSE;
						}
						
					}
				}
				else
				{
					pThis->Event (UME_FATALERROR);
					pThis->m_bRunning = FALSE;
				}
			}
			else
			{
				pThis->Event (UME_ERROR);
			}
		break;

		case DE_ERRFROMSERVER:
		case DE_ERROROCCURED:
		case DE_FAILCONNECT:
		case DE_WRITEERROR:
			pThis->Event (UME_ERROR);
		break;
	}

	return TRUE;
}

void fsUpdateMgr::ProcessUpdateLstFile()
{	
	char szSections [10000];
	*szSections = 0;
	char szValues [10000];

	if (::GetVersion () & 0x80000000)
		FixIniFileFor9x (fsGetDataFilePath ("Update\\proupd2.lst"));

	
	
	if (0 == GetPrivateProfileSectionNames (szSections, sizeof (szSections), 
		fsGetDataFilePath ("Update\\proupd2.lst")) || 
		atoi (szSections) <= (int)vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal)
	{
		ASSERT (GetPrivateProfileSectionNames (szSections, sizeof (szSections), fsGetDataFilePath ("Update\\proupd2.lst")));
		
		_App.NewVerExists (FALSE);
		Event (UME_NEWVERSIONNOTAVAIL);
		m_bRunning = FALSE;
		return;
	}

	
	m_strBN = szSections;

	CString strCurBN;	
	strCurBN = vmsFdmAppMgr::getBuildNumberAsString ();
	
	m_strUpgSize = "";
	m_strUpgFileName = "";
	m_vWN.clear ();

	LPCSTR pszSect = szSections;

	while (*pszSect)
	{
		
		GetPrivateProfileSection (pszSect, szValues, sizeof (szValues), 
			fsGetDataFilePath ("Update\\proupd2.lst"));
		LPSTR pszValue = szValues;

		
		BOOL bCommon = stricmp (pszSect, "Common") == 0;

		
		BOOL bNewBNNow = bCommon == FALSE && strcmp (pszSect, m_strBN) == 0;
		
		BOOL bBiggerBNNow = bCommon == FALSE && atoi (pszSect) > (int)vmsFdmAppMgr::getVersion ()->m_appVersion [2].dwVal;

		
		while (*pszValue)
		{
			
			LPSTR pszVVal = strchr (pszValue, '=');
			*pszVVal = 0;
			pszVVal++;	

			if (bCommon)
			{
				
				if (stricmp (pszValue, "DownloadPathForFullInstall") == 0)
				{
					m_strDlFullInstallPath = pszVVal;
					if (m_strDlFullInstallPath [m_strDlFullInstallPath.GetLength () - 1] != '\\' && 
							m_strDlFullInstallPath [m_strDlFullInstallPath.GetLength () - 1] != '/')
						m_strDlFullInstallPath += '/';
				}

				if (stricmp (pszValue, "DownloadPathForUpgrades") == 0)
				{
					m_strDlUpgradesPath = pszVVal;
					if (m_strDlUpgradesPath [m_strDlUpgradesPath.GetLength () - 1] != '\\' && 
							m_strDlUpgradesPath [m_strDlUpgradesPath.GetLength () - 1] != '/')
						m_strDlUpgradesPath += '/';
				}
			}

			if (bNewBNNow)
			{
				if (stricmp (pszValue, "Version") == 0)
					m_strVersion = pszVVal;	
				else if (stricmp (pszValue, "FullSize") == 0)
					m_strFullSize = pszVVal;	
				else if (stricmp (pszValue, strCurBN) == 0)
					m_strUpgSize = pszVVal;	
				else if (strnicmp (pszValue, strCurBN, strCurBN.GetLength ()) == 0)
				{
					
					
					if (stricmp (pszValue + strCurBN.GetLength (), "-name") == 0)
						m_strUpgFileName = pszVVal;
					
					
					else if (stricmp (pszValue + strCurBN.GetLength (), "-size") == 0)
						m_strUpgSize = pszVVal;
				}
				else if (stricmp (pszValue, "FrmtVer") == 0)
				{
					
					int nVer = atoi (pszVVal);
					if (nVer != 1)
					{
						
						_App.NewVerExists (FALSE);
						Event (UME_NEWVERSIONNOTAVAIL);
						m_bRunning = FALSE;
						return;
					}
				}
				else if (!stricmp (pszValue, "Flags"))
					m_dwFlags = strtoul (pszVVal, NULL, 10);
			}

			
			
			if (bBiggerBNNow && strncmp (pszValue, "WN", 2) == 0)
				m_vWN.add (pszVVal);

			pszValue = pszVVal;
			while (*pszValue++);	
		}

		while (*pszSect++); 
	}

	if ((m_dwFlags & IgnoreUpdateInAutomaticMode) && !m_bCheckingByUser)
	{
		
		_App.NewVerExists (FALSE);
		Event (UME_NEWVERSIONNOTAVAIL);
		m_bRunning = FALSE;
		return;
	}

	Event (UME_NEWVERSIONAVAIL);
}

void fsUpdateMgr::Event(fsUpdateMgrEvent ev)
{
	if (m_pfnEvents)
		m_pfnEvents (ev, m_lpEventsParam);
}

BOOL fsUpdateMgr::IsRunning()
{
	return m_bRunning;
}

void fsUpdateMgr::SetEventsFunc(fntUpdateMgrEventsFunc pfn, LPVOID lp)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lp;
}

LPCSTR fsUpdateMgr::GetVersion()
{
	return m_strVersion;
}

LPCSTR fsUpdateMgr::GetBuildNumber()
{
	return m_strBN;
}

void fsUpdateMgr::Stop()
{
	if (m_dldr && m_dldr->IsRunning ())
		m_dldr->StopDownloading ();
	else
		m_bRunning = FALSE;
}

LPCSTR fsUpdateMgr::GetFullSize()
{
	return m_strFullSize;
}

LPCSTR fsUpdateMgr::GetUpgSize()
{
	return m_strUpgSize;
}

fs::list <CString>* fsUpdateMgr::GetWhatNew()
{
	return &m_vWN;
}

void fsUpdateMgr::Update(BOOL bByFull)
{
	if (m_bRunning == FALSE || m_bChecking)
		return;

	SAFE_DELETE (m_dldr);
	fsnew1 (m_dldr, fsDownloadMgr (NULL));
	m_dldr->SetEventFunc (_DownloadMgrEvents, this);
	m_dldr->SetEventDescFunc (_DownloadMgrDescEvents, this);

	m_bChecking = FALSE;

	CString strUrl;	
	if (bByFull)
		strUrl.Format ("%sfdminst.exe", m_strDlFullInstallPath);
	else
	{
		
		if (m_strUpgFileName.GetLength () == 0)
			
			strUrl.Format ("%sfdm%sto%supg.exe", m_strDlUpgradesPath, vmsFdmAppMgr::getBuildNumberAsString (), m_strBN);
		else
			
			strUrl.Format ("%s%s", m_strDlUpgradesPath, m_strUpgFileName);
	}

	m_dldr->CreateByUrl (strUrl);
	
	fsDownload_Properties *dp = m_dldr->GetDP ();

	SAFE_DELETE_ARRAY (dp->pszFileName);
	CString strFile = fsGetDataFilePath ("Update\\");
	fsnew (dp->pszFileName, char, strFile.GetLength () + 1);
	strcpy (dp->pszFileName, strFile);
	dp->enAER = AER_REWRITE;
	dp->uMaxAttempts = 1;
	*dp->pszAdditionalExt = 0;

	Event (UME_CONNECTING);

	m_dldr->StartDownloading ();
}

void fsUpdateMgr::_DownloadMgrDescEvents(fsDownloadMgr* , fsDownloadMgr_EventDescType , LPCSTR pszDesc, LPVOID lp)
{
	fsUpdateMgr *pThis = (fsUpdateMgr*) lp;
	pThis->Event (pszDesc);
}

void fsUpdateMgr::SetDescEventsFunc(fntUpdateMgrDescEvents pfn, LPVOID lpParam)
{
	m_pfnDescEvents = pfn;
	m_lpDescEventsParam = lpParam;
}

void fsUpdateMgr::Event(LPCSTR pszEvent)
{
	if (m_pfnDescEvents)
		m_pfnDescEvents (pszEvent, m_lpDescEventsParam);
}

void fsUpdateMgr::UpdateOnNextStart()
{
	AfxGetApp ()->WriteProfileString ("Settings\\Update", "UpdateFile", m_strUpdateFile);
}

BOOL fsUpdateMgr::IsStartUpdaterNeeded (BOOL bUpdaterWillBeLaunchedNow)
{
	m_strUpdateFile = AfxGetApp ()->GetProfileString ("Settings\\Update", "UpdateFile", "");
	if (bUpdaterWillBeLaunchedNow)
		AfxGetApp ()->WriteProfileString ("Settings\\Update", "UpdateFile", "");
	return m_strUpdateFile.GetLength () != 0;
}

void fsUpdateMgr::FixIniFileFor9x(LPCSTR pszIni)
{
	HANDLE hFile = CreateFile (pszIni, GENERIC_READ | GENERIC_WRITE, 0, NULL, 
		OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	DWORD dwLen = GetFileSize (hFile, NULL);
	LPSTR psz = new char [dwLen + 1];
	DWORD dw;
	if (FALSE == ReadFile (hFile, psz, dwLen, &dw, NULL))
		return;
	psz [dwLen] = 0;

	CString str = psz;
	delete [] psz;

	str.Replace ("\r\n", "\n");
	str.Replace ("\n\r", "\n");
	str.Replace ("\n", "\r\n");

	SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
	WriteFile (hFile, (LPCSTR)str, str.GetLength (), &dw, NULL);
	SetEndOfFile (hFile);

	CloseHandle (hFile);
}
