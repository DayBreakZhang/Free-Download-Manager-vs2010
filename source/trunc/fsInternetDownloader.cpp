/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsInternetDownloader.h"
#include "fsTicksMgr.h"
#include "misc.h"
#include "inetutil.h"
#include <math.h>
#include "fsArchiveInternetStream.h"
#include "fsZipArchiveFastRebuilder.h"
#include "fsArchiveFileStream.h"
#include "vmsSpeedTracker.h"
#include "vmsInternetSession.h"
#include "InetFile/base64.h"
#include "QueryStoringServiceInfoGuard.h"
#include "vmsLogger.h"

using namespace fsArchive;

BOOL fsInternetDownloader::m_bPauseMode = FALSE;
UINT64 fsInternetDownloader::m_nTotalTraffic = 0;
fsSpeedMeter fsInternetDownloader::m_TotalSpeed;
vmsCriticalSection fsInternetDownloader::m_csDataRcvd;

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define TSECT(sect) ; 

fsInternetDownloader::fsInternetDownloader()
	: m_pManagerPersistObject(0)
{
	ZeroMemory (DNP (), sizeof (m_dnp));

	m_bErrDownloading = FALSE;
	m_uRetryTime = 5000;

	m_hOutFile = INVALID_HANDLE_VALUE;
	
	m_uSectionMinSize = 20000;
	m_bNeedStop = FALSE;
	m_cThreads = m_cRunningThreads = 0;
	m_uTrafficLimit = UINT_MAX;
	m_pfnEvents = NULL;
	m_uMaxAttempts = UINT_MAX;
	m_bDontRestartIfNoRanges = FALSE;

	m_pfnEvents = NULL;

	m_pOpeningFile = NULL;

	StopOnFileNotFound (TRUE);
	StopOnAccDenied (TRUE);

	m_enRST = RST_UNKNOWN;
	m_uSSFileSize = m_uLDFileSize = 0;

	m_cBaseSectCreatingNow = 0;

	m_bDetLog = FALSE;

	m_pMirrURLMgr = NULL;

	m_bSearchForMirrors = FALSE;
	m_bMirrMeasureSpeed = FALSE;
	m_uMirrFileMinSize = 1000*1024;
	m_dwBaseServerPingTime = UINT_MAX;
	m_dwState = 0;
	m_cMirrsFound = 0;

	m_strContentType = "";

	m_pZipPreviewStream = NULL;
	m_uTimeout = 120;

	m_bAddingSection = FALSE;

	ZeroMemory (&m_fileDate, sizeof (m_fileDate));

	m_bWasAccessedAtLeastOnce = FALSE;

	m_dwDataLenInCache = 0;
	m_dwForceCacheSizePerSection = DWORD (-1);
}

fsInternetDownloader::~fsInternetDownloader()
{
	StopDownloading ();

	while (m_cThreads)
		Sleep (10);

	for (int i = 0; i < m_vMirrs.size (); i++)
		fsDNP_GetByUrl_Free (&m_vMirrs [i].dnp);
}

fsDownload_NetworkProperties* fsInternetDownloader::DNP(int nSection)
{
	if (nSection == -1)
		return &m_dnp;

	return m_vSections [nSection].nMirrorURL == UINT_MAX ? &m_dnp : 
		&m_vMirrs [m_vSections [nSection].nMirrorURL].dnp;
}

fsInternetResult fsInternetDownloader::AddSection(BOOL bQueryCreation)
{
	if (m_bErrDownloading)
		return IR_ERROR;

	if (m_vSections.size ())
		return CreateAdditionalSection (bQueryCreation);
	else
		return CreateMainSection (bQueryCreation);
}

fsInternetResult fsInternetDownloader::CreateMainSection(UINT uStartFrom, BOOL bQueryCreation)
{
	fsSection sect;
	
	fsInternetResult ir;
	
	m_bNoNewSections = FALSE;
	m_bNeedStop = FALSE;

	
	if (bQueryCreation && Event (DE_QUERYNEWSECTION, UINT_MAX) == FALSE)
		return IR_S_FALSE;	

	m_cBaseSectCreatingNow++;
	vmsAUTOLOCKSECTION (m_csAddSection);

	Event (DE_STARTINGDOWNLOAD);

	Event (DE_STARTINGDOWNLOAD_CONNECTING);

	
	
	
	
	UINT u = UINT_MAX;
	ir = OpenUrl (uStartFrom, &sect.file, -1, u);

	if (ir != IR_SUCCESS)
	{
		m_cBaseSectCreatingNow--;
		Event (DE_STARTINGDOWNLOAD_FAILEDTOCONNECT);
		return ir;
	}

	m_uSSFileSize = m_uLDFileSize = sect.file->GetFileSize ();
	setDirty();

	sect.uStart = sect.uDStart = 0;
	sect.uCurrent = sect.uDCurrent = uStartFrom;
	sect.uEnd = sect.uDEnd = GetSSFileSize ();

	TSECT (&sect);

	Auto_SearchMirrors ();
	
	
	if (FALSE == CreateSection (sect))
	{
		m_cBaseSectCreatingNow--;
		
		if (m_vSections.size() == 1) {
			m_vSections[0].file = 0;
		}
		delete sect.file;

		return IR_S_FALSE;
	}

	return m_bNeedStop ? IR_S_FALSE : IR_SUCCESS;
}

fsInternetResult fsInternetDownloader::CreateAdditionalSection(BOOL bQueryCreation)
{
	if (m_bNoNewSections || m_bAddingSection)
		return IR_S_FALSE; 

	if (m_vSections.size () - GetDoneSectionCount () >= MAX_NOT_COMPLETED_SECTION_COUNT)
		return IR_S_FALSE; 

	if (GetSSFileSize () == _UI64_MAX)
		return IR_S_FALSE; 

	m_bAddingSection = TRUE;

	UINT64 uMaxSection = 0;
	int iSection = -1;
	fsInternetResult ir;

	if (IsMayZIP (TRUE) && m_vSections.size () == 1 && 
			m_vSections [0].uCurrent < ZIP_SFXMAXSIZE)
		
		
	{
		m_bAddingSection = FALSE;
		return IR_S_FALSE;
	}

	if (IsResumeSupported () == RST_NONE)
	{
		m_bAddingSection = FALSE;
		return IR_RANGESNOTAVAIL;
	}

	vmsAUTOLOCKSECTION (m_csAddSection);

	fsSection sect;
	sect.nMirrorURL = FindNotBusyMirrorIndex ();

	if (bQueryCreation && Event (DE_QUERYNEWSECTION, sect.nMirrorURL) == FALSE)
	{
		m_bAddingSection = FALSE;
		return IR_S_FALSE;
	}

	UINT nMirrorInc = sect.nMirrorURL;

	if (nMirrorInc == UINT_MAX)
		m_cBaseSectCreatingNow++;
	else
		m_vMirrs [nMirrorInc].cSectsCreatingNow ++;

	UINT64 uBiggestSectCurrentPosCorrection = 0;

	
	for (int i = 0; i < m_vSections.size (); i++)
	{
		const fsSectionEx &sect = m_vSections [i];

		if (sect.state == SS_DONE)
			continue;

		UINT uSpeed = sect.state == SS_DOWNLOADING ? sect.uSpeed : 0;
		
		
		UINT64 uCurrentPosCorrection = sect.dwCacheLen + uSpeed * 20;

		vmsAUTOLOCKSECTION (m_csSections);
		if (sect.uCurrent + uCurrentPosCorrection >= sect.uEnd)
		{
			vmsAUTOLOCKSECTION_UNLOCK (m_csSections);
			continue;
		}
		
		
		UINT64 uSectionNotDownloadedSize = sect.uEnd - (sect.uCurrent + uCurrentPosCorrection);
		ASSERT (sect.uCurrent + uCurrentPosCorrection < sect.uEnd);
		vmsAUTOLOCKSECTION_UNLOCK (m_csSections);

		if (uMaxSection < uSectionNotDownloadedSize)
		{
			uMaxSection = uSectionNotDownloadedSize;
			iSection = i;
			uBiggestSectCurrentPosCorrection = uCurrentPosCorrection;
		}
	}

	
	if (iSection == -1 || uMaxSection/2 < m_uSectionMinSize || uMaxSection < 100*1024) 
	{
		m_bAddingSection = FALSE;
		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow--;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow --;
		return IR_S_FALSE;
	}

	vmsAUTOLOCKSECTION (m_csSections);
	
	sect.uStart = sect.uCurrent = 
		m_vSections [iSection].uCurrent + uBiggestSectCurrentPosCorrection + uMaxSection / 2;
	sect.uEnd   = m_vSections [iSection].uEnd;

	sect.uDStart = sect.uDCurrent = 
		m_vSections [iSection].uDCurrent + uBiggestSectCurrentPosCorrection + uMaxSection / 2;
	sect.uDEnd   = m_vSections [iSection].uDEnd;
	vmsAUTOLOCKSECTION_UNLOCK (m_csSections);

	
	if (sect.uCurrent >= sect.uEnd || (sect.uEnd - sect.uCurrent) < m_uSectionMinSize)
	{
		m_bAddingSection = FALSE;
		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow--;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow --;

		setDirty(); 

		return IR_S_FALSE;
	}

	ASSERT (sect.uStart != 0);

	TSECT(&sect);

	ir = OpenUrl (sect.uStart, &sect.file, -1, sect.nMirrorURL, m_uSSFileSize != _UI64_MAX);

	
	
	
	if (IsDone () == TRUE || (m_vSections [iSection].uCurrent + m_vSections [iSection].dwCacheLen) >= sect.uCurrent)
	{
		SAFE_DELETE (sect.file);
		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow--;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow --;

		setDirty(); 

		m_bAddingSection = FALSE;
		return IR_S_FALSE;
	}

	if (ir != IR_SUCCESS)
	{
		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow--;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow --;

		setDirty(); 
		
		m_bAddingSection = FALSE;
		return ir;
	}

	
	EnterCriticalSection (&m_csSections);
	m_vSections [iSection].uEnd = sect.uStart;
	m_vSections [iSection].uDEnd = sect.uDStart;
	setDirty();
	LeaveCriticalSection (&m_csSections);

	if (sect.nMirrorURL != nMirrorInc)	
	{
		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow--;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow--;

		if (sect.nMirrorURL == UINT_MAX)
			m_cBaseSectCreatingNow++;
		else
			m_vMirrs [sect.nMirrorURL].cSectsCreatingNow++;
	}

	CreateSection (sect);

	EnterCriticalSection (&m_csSections);
	if (m_vSections [iSection].uEnd < m_vSections [iSection].uCurrent)
	{
		m_vSections [iSection].uEnd = m_vSections [iSection].uCurrent;
		m_vSections [iSection].uDEnd = m_vSections [iSection].uDCurrent;
		setDirty();
	}
	LeaveCriticalSection (&m_csSections);

	m_bAddingSection = FALSE;

	return IR_SUCCESS;
}

void fsInternetDownloader::CreateCompleteSection(UINT64 uFileSize)
{
	vmsAUTOLOCKSECTION (m_csAddSection);

	fsSection sect;

	sect.uStart = sect.uDStart = 0;
	sect.uCurrent = sect.uDCurrent = uFileSize;
	sect.uEnd = sect.uDEnd = uFileSize;

	sect.uSpeed = 0;
	sect.pThis = this;
	sect.lastErr = IR_SUCCESS;
	sect.uSpeedLimit = 0;
	sect.state = SS_DONE;
	sect.iSection = m_vSections.size ();

	m_vSections.add (sect);
	setDirty();
}

BOOL fsInternetDownloader::CreateSection(fsSection &sect, BOOL bCreateThread, BOOL bReduceSCN)
{
	sect.uSpeed = 0;
	sect.pThis = this;
	sect.lastErr = IR_SUCCESS;
	sect.uSpeedLimit = 0;
	sect.state = bCreateThread ? SS_CREATING : SS_STOPPED;
	sect.iSection = m_vSections.size ();

	
	if (sect.iSection == 0 && bCreateThread)
	{
		
		if (FALSE == Event (DE_NEEDFILE))
			return FALSE;
	}

	m_vSections.add (sect);

	setDirty();

	fsSection* pSect = &m_vSections [m_vSections.size ()-1];

	if (sect.iSection == 0 && bCreateThread)
	{
		if (FALSE == Event (DE_NEEDFILE_FINALINITIALIZATION))
			return FALSE;
	}

	if (bCreateThread)
	{
		Event (DE_SECTIONADDED, sect.iSection);
		DWORD dwThread;
		if (bReduceSCN)
		{
			if (sect.nMirrorURL == UINT_MAX)
				m_cBaseSectCreatingNow--;
			else
				m_vMirrs [sect.nMirrorURL].cSectsCreatingNow--;
		}
		m_cThreads++; m_cRunningThreads++;
		Event (DE_SECTIONSTARTED, sect.iSection);
		CloseHandle (CreateThread (NULL, 0, _threadDownload, pSect,	0, &dwThread));
	}

	return TRUE;
}

BOOL fsInternetDownloader::__threadDownload_flushdata (fsSectionEx* sect, 
	LPBYTE pBuffer, DWORD dwRead,
	LPBYTE &pbCache, DWORD &dwCacheSize, DWORD &dwCacheLen)
{
	if (pBuffer == NULL && pbCache == NULL)
		return TRUE;

	if (pBuffer && pbCache)
	{
		DWORD dwNewCacheSize = sect->pThis->m_dwForceCacheSizePerSection != DWORD (-1) ? 
			sect->pThis->m_dwForceCacheSizePerSection : 
		#ifndef FDM_DLDR__RAWCODEONLY
			_App.FileWriteCacheSize () / sect->pThis->GetRunningSectionCount ();
		#else
			0;
		#endif

		if (dwNewCacheSize < dwCacheSize)
		{
			
			if (FALSE == __threadDownload_flushdata (sect, NULL, 0, pbCache, dwCacheSize, dwCacheLen))
				return FALSE;
			return __threadDownload_flushdata (sect, pBuffer, dwRead, pbCache, dwCacheSize, dwCacheLen);
		}
	}

	
	__int64 iLenCorrection = 0;
	
	DWORD dwWrittenTotal = 0;

	
	if (pBuffer == NULL || dwCacheSize - dwCacheLen < dwRead)
	{
		

		vmsCriticalSectionAutoLock csal (&sect->pThis->m_csWriteToFile);

		if (!fsSetFilePointer (sect->pThis->m_hOutFile, sect->uDCurrent, FILE_BEGIN))
			return FALSE;

		BOOL bWriteOk = TRUE;
		DWORD dwWrite = 0;

		
		if (dwCacheLen)
		{
			bWriteOk = WriteFile (sect->pThis->m_hOutFile, pbCache, dwCacheLen, &dwWrite, NULL);
			bWriteOk = bWriteOk && (dwCacheLen == dwWrite);
		}

		
		if (bWriteOk && dwRead)
		{
			bWriteOk = WriteFile (sect->pThis->m_hOutFile, pBuffer, dwRead, &dwWrite, NULL);
			bWriteOk = bWriteOk && (dwRead == dwWrite);
		}

		csal.Unlock ();

		if (!bWriteOk)
			return FALSE;

		dwWrittenTotal = dwCacheLen + dwRead;

		iLenCorrection = - (__int64)dwCacheLen;

#ifndef FDM_DLDR__RAWCODEONLY

		

		
		DWORD dwNewCacheSize = sect->pThis->m_dwForceCacheSizePerSection != DWORD (-1) ? 
			sect->pThis->m_dwForceCacheSizePerSection : 
			_App.FileWriteCacheSize () / sect->pThis->GetRunningSectionCount ();

		dwCacheLen = 0; 

		
		if (dwCacheSize != dwNewCacheSize)
		{
			
			SAFE_DELETE_ARRAY (pbCache);
			dwCacheSize = 0;
		}
		
		if (pbCache == NULL && dwNewCacheSize) 
		{
			try 
			{
				pbCache = new BYTE [dwNewCacheSize];
				if (pbCache)
					dwCacheSize = dwNewCacheSize;	
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog(" " + tstring(ex.what()));
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog(" unknown exception");
			}
		}
#endif

	}
	else
	{
		

		CopyMemory (pbCache + dwCacheLen, pBuffer, dwRead);
		dwCacheLen += dwRead;
		iLenCorrection = dwRead;
	}

	EnterCriticalSection (&sect->pThis->m_csSections);

	
	__int64 i = sect->pThis->m_dwDataLenInCache;
	i += iLenCorrection;
	
	sect->pThis->m_dwDataLenInCache = (DWORD)i;

	if (dwWrittenTotal)
	{
		
		
		sect->uCurrent += dwWrittenTotal;
		sect->uDCurrent += dwWrittenTotal;
		sect->pThis->setDirty();
	}

	LeaveCriticalSection (&sect->pThis->m_csSections);

	return TRUE;
}

DWORD WINAPI fsInternetDownloader::_threadDownload(LPVOID lp)
{

#define CHECK_NEED_STOP if (sect->pThis->m_bNeedStop || sect->state == SS_NEEDSTOP) { sect->state = SS_STOPPED; goto _exit; }

	
	
	const int BufDivider = 8;

	fsSectionEx *sect = (fsSectionEx*) lp;
	fsDownload_NetworkProperties *dnp = sect->pThis->DNP (sect->iSection);

	TSECT (sect);

	DWORD dwBufSize = 2000;				
	BYTE *pBuffer = new BYTE [dwBufSize];	
	ZeroMemory (pBuffer, dwBufSize);
	DWORD dwMaxRead = dwBufSize;		
	DWORD dwRead;		
	DWORD dwLastRead = 0; 
	fsTicksMgr timeOld, timeNew;

	LPBYTE pbCache = NULL;		
	DWORD  dwCacheSize = 0;		
	sect->dwCacheLen = 0;		

	vmsSpeedTracker st;
	if (sect->pThis->m_dnp.dwFlags & DNPF_RESTARTSECTIONWHENSPEEDTOOLOW)
	{
		st.set_LowSpeedDuration (sect->pThis->m_dnp.wLowSpeed_Duration * 60);
		st.set_LowSpeedFactor   (sect->pThis->m_dnp.wLowSpeed_Factor);
	}
	else
		st.set_LowSpeedDuration (INT_MAX);	

	timeOld.Now ();
	timeNew.Now ();

	int cZeroReads;
	cZeroReads = 0;
	fsTicksMgr tickZRStart;	

	CHECK_NEED_STOP;

	if (sect->file)
	{
		sect->file->SetDialogFunc (_InetFileDialogFunc, sect->pThis, LPVOID (sect->iSection));
		sect->state = SS_DOWNLOADING;
		sect->pThis->setDirty();
		sect->pThis->Event (DE_SECTDOWNLOADING, sect->iSection);

		
		
		
		sect->file->Read (pBuffer, 0, &dwRead);
	}

	sect->pThis->UpdateTrafficLimit ();

	BOOL bMayZIP;
	bMayZIP = sect->uStart == 0 && sect->uCurrent < ZIP_SFXMAXSIZE &&
		sect->pThis->IsMayZIP (TRUE) && sect->pThis->m_vSections.size () == 1;
	UINT32 uLast3BytesRead;	
	uLast3BytesRead = 0;

	
	#define CURRENT_DL_POS (sect->uCurrent + sect->dwCacheLen)
	
	#define CURRENT_DW_POS (sect->uDCurrent + sect->dwCacheLen)

	
	while (sect->uEnd > CURRENT_DL_POS)
	{
		CHECK_NEED_STOP;
		while (sect->bSleep)
			Sleep (10);

		dwRead = dwMaxRead;
		if (dwRead >= sect->uEnd - CURRENT_DL_POS)	
		{
			dwRead = DWORD (sect->uEnd - CURRENT_DL_POS);	
			
			
			
			EnterCriticalSection (&sect->pThis->m_csSections);
			if (dnp->enProtocol == NP_FTP && sect->file->FtpGetTransferType () == FTT_ASCII && sect->uEnd == sect->file->GetFileSize ()) {
				sect->uEnd += 100;
				sect->pThis->setDirty();
			}
			LeaveCriticalSection (&sect->pThis->m_csSections);
		}

		
		if (sect->uEnd - CURRENT_DL_POS - dwRead < 100)
		{
			dwRead += (DWORD)(sect->uEnd - CURRENT_DL_POS - dwRead);
			if (dwRead > dwMaxRead)
			{
				
				delete [] pBuffer;
				dwMaxRead = dwRead;
				pBuffer = new BYTE [dwMaxRead];
			}
		}

		ASSERT (dwRead <= dwMaxRead);

		
		if (sect->file)
		{
			
			sect->lastErr = sect->file->Read (pBuffer, dwRead, &dwRead);
			sect->pThis->setDirty();
		}
		else
		{
			
			if (sect->lastErr == IR_SUCCESS || sect->lastErr == IR_S_FALSE) {
				sect->lastErr = IR_ERROR; 
				sect->pThis->setDirty();
			}
		}

		
		if (dwRead == 0 && sect->lastErr == IR_SUCCESS)
		{
			if (cZeroReads == 0)
				tickZRStart.Now ();
			else
			{
				fsTicksMgr tickNow; tickNow.Now ();
				
				if (tickNow - tickZRStart > 60*1000)
				{
					
					

					
					
					
					
					{
						fsInternetURLFile *file = sect->file;
						sect->file = NULL;
						delete file;
						sect->lastErr = IR_WININETUNKERROR;
						sect->state = SS_ERRSTOPPED;
						sect->pThis->setDirty();
						goto _exit;
					}
					
					cZeroReads = 101;	
				}
			}

			
			if (cZeroReads++ > 100)
			{
				
				
				

				if (sect->uEnd == _UI64_MAX || 
					(sect->uEnd >= sect->file->GetFileSize () && sect->file->FtpGetTransferType () == FTT_ASCII && dnp->enProtocol == NP_FTP))
				{
					EnterCriticalSection (&sect->pThis->m_csSections);
					sect->uEnd = CURRENT_DL_POS;
					sect->uDEnd = sect->pThis->m_uLDFileSize = CURRENT_DW_POS;
					sect->pThis->setDirty();
					LeaveCriticalSection (&sect->pThis->m_csSections);
					TSECT (sect);
					break;
				}
				else
				{
					sect->lastErr = IR_LOSTCONNECTION;
					sect->pThis->setDirty();
				}
			}
			else
			{
				Sleep (5);
				continue; 
			}
		}
	
		
		
		cZeroReads = 0;

		if (sect->lastErr == IR_LOSTCONNECTION)
		{
			if (sect->pThis->GetNumberOfSections () == 1)
			{
				LPCSTR pszHost = sect->pThis->DNP (0)->pszServerName;
				bool bDone = false;

				if (strlen (pszHost) > sizeof ("mail.yahoo.com") &&
						stricmp (pszHost+strlen (pszHost)-sizeof ("mail.yahoo.com"), ".mail.yahoo.com") == 0)
					bDone = true;
				else if (strstr (sect->pThis->DNP (0)->pszPathName, ".mail.yahoo.com/"))
					bDone = true;

				if (bDone)
				{
					sect->uDEnd = sect->uEnd = CURRENT_DL_POS;
					sect->lastErr = IR_SUCCESS;
					sect->pThis->setDirty();
					continue;
				}
			}
		}

		
		if (sect->lastErr != IR_SUCCESS)
		{
			sect->pThis->m_speed.Reset ();
			sect->uSpeed = 0;
			sect->pThis->setDirty();
			st.Reset ();

			if (sect->file)
			{
				
				
				DWORD dw = sect->pThis->DNP (sect->iSection)->wRollBackSize;
				DWORD dw2 = (WORD)(CURRENT_DL_POS - sect->uStart);
				DWORD dw3 = (WORD)(CURRENT_DW_POS - sect->uDStart);

				dw = min (dw, dw2); dw = min (dw, dw3);
				EnterCriticalSection (&sect->pThis->m_csSections);

				if (sect->dwCacheLen)
				{
					

					if (sect->dwCacheLen >= dw)
					{
						sect->dwCacheLen -= dw;	 
						dw = 0;	
					}
					else
					{
						dw -= sect->dwCacheLen;
						sect->dwCacheLen = 0;
					}
				}

				
				sect->uCurrent -= dw;
				sect->uDCurrent -= dw;
				sect->pThis->setDirty();

				LeaveCriticalSection (&sect->pThis->m_csSections);
				TSECT (sect);
			}

			CHECK_NEED_STOP;
			sect->state = SS_ERROR;
			if (sect->file)
				sect->pThis->Event (DE_ERROROCCURED, sect->iSection);
			
			SAFE_DELETE (sect->file);
			sect->pThis->setDirty();

			sect->pThis->UpdateTrafficLimit ();

			
			while (sect->pThis->m_bErrDownloading)
			{
				Sleep (100);
				CHECK_NEED_STOP;
			}

			CHECK_NEED_STOP;
			sect->state = SS_RECONNECTING;
			sect->pThis->setDirty();
			
			sect->pThis->m_bErrDownloading = TRUE;

			UINT cAttempts = sect->pThis->m_uMaxAttempts;

			
			do 
			{
				if (cAttempts == 0 || sect->pThis->m_bNeedStop || sect->state == SS_NEEDSTOP)
				{
					if (sect->pThis->m_bNeedStop || sect->state == SS_NEEDSTOP)
						sect->state = SS_STOPPED;
					else
						sect->state = SS_ERRSTOPPED;
					sect->pThis->setDirty();
					
					sect->pThis->m_bErrDownloading = FALSE;

					goto _exit;
				}

				sect->pThis->Event (DE_CONNECTING, sect->iSection);
				sect->lastErr = sect->pThis->OpenUrl (CURRENT_DL_POS, &sect->file, sect->iSection, sect->nMirrorURL, TRUE);
				sect->pThis->setDirty();
				
				if (sect->lastErr != IR_SUCCESS)
				{
					sect->pThis->Event (DE_FAILCONNECT, sect->iSection);

					if (sect->lastErr == IR_RANGESNOTAVAIL || sect->lastErr == IR_DOUBTFUL_RANGESRESPONSE)
					{
						sect->state = SS_ERRSTOPPED;
						sect->pThis->setDirty();
						sect->pThis->m_bErrDownloading = FALSE;						
						goto _exit;
					}

					cAttempts--;

					if (cAttempts && sect->pThis->m_uRetryTime)
					{
						sect->pThis->Event (DE_PAUSE, sect->iSection);
						sect->pThis->SleepInterval ();
					}
				}

			} while (sect->lastErr != IR_SUCCESS);

			sect->pThis->m_bErrDownloading = FALSE;
			CHECK_NEED_STOP;
			sect->state = SS_DOWNLOADING;
			sect->pThis->setDirty();
			sect->pThis->Event (DE_CONNECTED, sect->iSection);
			sect->pThis->Event (DE_SECTDOWNLOADING, sect->iSection);

			sect->pThis->UpdateTrafficLimit ();
			
			timeNew.Now ();
			timeOld.Now ();
			dwLastRead = 0;

			continue;
		}

		BOOL bWriteOk = __threadDownload_flushdata (sect, pBuffer, dwRead, pbCache, 
			dwCacheSize, sect->dwCacheLen);

		if (!bWriteOk)
		{
			CHECK_NEED_STOP;
			sect->state = SS_WRITEERROR;
			sect->lastErr = (fsInternetResult) GetLastError ();
			sect->pThis->setDirty();
			goto _exit;
		}

		TSECT (sect);
		dwLastRead += dwRead;
		sect->pThis->m_speed.Done (dwRead);
		fsInternetDownloader::OnDataDownloaded (dwRead);

		if (bMayZIP)
		{
			LPBYTE pBuf = pBuffer;
			BOOL bZIP = FALSE;
			
			UINT64 uZIPStart = 0;
			
			for (int i = 0; i <= (int)dwRead - (int)sizeof (UINT32); i++)
			{
				UINT32* p = (UINT32*)(pBuf++);
				if (*p == ZIP_BEGIN_SIG)
				{
					bZIP = TRUE; 
					uZIPStart = CURRENT_DL_POS - dwRead + i;
					break;
				}
			}

			
			
			
			
			
			
			
			
			if (bZIP == FALSE && uLast3BytesRead)
			{
				BYTE buf [3+3];	

				
				

				buf [0] = BYTE (uLast3BytesRead);
				buf [1] = BYTE (uLast3BytesRead >> 8);
				buf [2] = BYTE (uLast3BytesRead >> 16);
				buf [3] = pBuffer [0];
				buf [4] = pBuffer [1];
				buf [5] = pBuffer [2];

				

				for (UINT i = 0; i <= 6-sizeof(UINT32); i++)
				{
					UINT32* p = (UINT32*)(buf+i);
					if (*p == ZIP_BEGIN_SIG)
					{
						bZIP = TRUE; 
						uZIPStart = CURRENT_DL_POS - dwRead - i + 3;
						break;
					}
				}
			}

			
			uLast3BytesRead = UINT32 (pBuffer [dwRead-1]) << 16 | 
				UINT32 (pBuffer [dwRead-2]) << 8 | UINT32 (pBuffer [dwRead-3]);

			if (bZIP)
			{
				fsInternetDownloader* pThis = sect->pThis;

				pThis->m_speed.Reset ();

				
				
				
				fsInternetResult ir = sect->pThis->CheckIsZIP (uZIPStart, &sect->file);

				if (IR_SUCCESS == ir)
				{
					
					
					
					SAFE_DELETE_ARRAY (pBuffer);
					pThis->m_cRunningThreads--;
					pThis->Event (DE_SECTIONSTOPPED, 0);
					pThis->m_cThreads--;
					return 0;
				}
				else
				{
					if (ir == 0x1000)
					{
						
						

						sect->pThis->m_bNeedStop = TRUE;
						EnterCriticalSection (&sect->pThis->m_csSections);
						
						
						
						sect->uDCurrent -= CURRENT_DL_POS - uZIPStart;
						sect->uCurrent = uZIPStart;
						sect->dwCacheLen -= min (sect->dwCacheLen, (DWORD)(CURRENT_DL_POS - uZIPStart));
						sect->pThis->setDirty();
						LeaveCriticalSection (&sect->pThis->m_csSections);
						TSECT (sect);
						CHECK_NEED_STOP; 
					}
					else if (ir == IR_S_FALSE && sect->pThis->m_bNeedStop == FALSE)
					{
						

						bMayZIP = FALSE;
						sect->pThis->Event (DE_MAYADDSECTION);
					}
					else
					{
						

						sect->state = SS_ERRSTOPPED;
						EnterCriticalSection (&sect->pThis->m_csSections);
						sect->uDCurrent -= CURRENT_DL_POS - uZIPStart;
						sect->uCurrent = uZIPStart;
						sect->dwCacheLen -= min (sect->dwCacheLen, (DWORD)(CURRENT_DL_POS - uZIPStart));
						sect->pThis->setDirty();
						LeaveCriticalSection (&sect->pThis->m_csSections);
						TSECT (sect);
						goto _exit;
					}
				}
			}

			if (CURRENT_DL_POS > ZIP_SFXMAXSIZE)
			{
				
				
				bMayZIP = FALSE;
				sect->pThis->Event (DE_MAYADDSECTION);
			}
		}

		timeNew.Now ();

		
		UINT uSpeedLimit = sect->uSpeedLimit;
		if (timeNew - timeOld >= 1000 || dwLastRead >= uSpeedLimit)
		{
			if (timeNew - timeOld >= 1000)
			{
				
				sect->uSpeed = (UINT)((dwLastRead) / ((double)(timeNew - timeOld) / 1000.0f));
				
				st.CurrentSpeedIs (sect->uSpeed);
				if (st.CheckCurrentSpeedTooLow ())
				{
					sect->pThis->Event (DE_SPEEDISTOOLOW, sect->iSection);
					SAFE_DELETE (sect->file);
				}
				sect->pThis->setDirty();
			}
			else
			{
				sect->uSpeed = dwLastRead;
				sect->pThis->setDirty();
				st.Reset ();
			}

			dwLastRead = 0;

			if (timeNew - timeOld < 1000) 
			{
				dwMaxRead = uSpeedLimit / BufDivider;
				
				
				Sleep (1000 - (timeNew - timeOld));
			}
			else
			{
				dwMaxRead = sect->uSpeed / BufDivider;
			}

			
			if (dwMaxRead > 100000)
				dwMaxRead = 100000;
			else if (dwMaxRead == 0)
				dwMaxRead = 1;	

			
			if (dwBufSize < dwMaxRead)
			{
				
				delete [] pBuffer;
				pBuffer = new BYTE [dwMaxRead];
				dwBufSize = dwMaxRead;
			}

			
			timeOld.Now ();
		}
	}

	
	if (pbCache && sect->dwCacheLen)
	{
		
		BOOL bWriteOk = __threadDownload_flushdata (sect, NULL, 0, pbCache, dwCacheSize, sect->dwCacheLen);
		if (!bWriteOk)
		{
			CHECK_NEED_STOP;
			sect->state = SS_WRITEERROR;
			sect->lastErr = (fsInternetResult) GetLastError ();
			sect->pThis->setDirty();
			goto _exit;
		}
	}

	
	EnterCriticalSection (&sect->pThis->m_csSections);
	sect->uCurrent = sect->uEnd;
	if (sect->uDCurrent > sect->uDEnd)
		sect->uDCurrent = sect->uDEnd;
	LeaveCriticalSection (&sect->pThis->m_csSections);
	TSECT (sect);
	sect->state = SS_DONE;
	sect->pThis->setDirty();

_exit:
	fsInternetURLFile *file = sect->file;
	sect->file = NULL;
	delete file;
	sect->pThis->setDirty(); 
	SAFE_DELETE_ARRAY (pBuffer);

	if (pbCache && sect->dwCacheLen)
		__threadDownload_flushdata (sect, NULL, 0, pbCache, dwCacheSize, sect->dwCacheLen);
	if (sect->dwCacheLen)
	{
		EnterCriticalSection (&sect->pThis->m_csSections);
		sect->pThis->m_dwDataLenInCache -= sect->dwCacheLen;
		LeaveCriticalSection (&sect->pThis->m_csSections);
	}
	SAFE_DELETE_ARRAY (pbCache);

	EnterCriticalSection (&sect->pThis->m_csDone);

	sect->pThis->m_cRunningThreads--;

	switch (sect->state)
	{
		case SS_DONE:
			if (sect->nMirrorURL != UINT_MAX)
				sect->pThis->m_vMirrs [sect->nMirrorURL].bIsGood = TRUE;
			EnterCriticalSection (&sect->pThis->m_csSections);
			if (sect->uDEnd == _UI64_MAX || sect->uEnd == _UI64_MAX)
			{
				sect->uEnd = sect->uCurrent;
				sect->uDEnd = sect->uDCurrent;
			}
			sect->pThis->setDirty();
			LeaveCriticalSection (&sect->pThis->m_csSections);
			sect->pThis->Event (DE_SECTIONDONE, sect->iSection);
			break;

		case SS_WRITEERROR:
			sect->pThis->Event (DE_WRITEERROR, sect->iSection);
		case SS_STOPPED:
		case SS_ERRSTOPPED:
			sect->pThis->Event (DE_SECTIONSTOPPED, sect->iSection);
			sect->state = SS_STOPPED;
			sect->pThis->setDirty();
			break;
	}

	if (sect->pThis->m_cRunningThreads == 0) 
	{
		sect->pThis->m_speed.Reset ();	
		sect->pThis->m_dwDataLenInCache = 0;
		sect->pThis->Event (DE_ALLSTOPPEDORDONE);
	}

	sect->pThis->UpdateTrafficLimit ();

	sect->pThis->m_cThreads--;

	LeaveCriticalSection (&sect->pThis->m_csDone);

	return 0;
}

fsInternetResult fsInternetDownloader::OpenUrl(UINT64 uStartPos, fsInternetURLFile **ppFile,  int iSectIndex, UINT &nMirror, BOOL bCheckFileSize, LPCSTR pszContentTypeReq)
{
	return OpenUrl_imp (uStartPos, ppFile, iSectIndex, nMirror, bCheckFileSize, 0, pszContentTypeReq, NULL);
}

fsInternetResult fsInternetDownloader::OpenUrl_imp(UINT64 uStartPos, fsInternetURLFile **ppFile,  int iSectIndex, UINT &nMirror,  BOOL bCheckFileSize, int iAttempt, LPCSTR , fsDownload_NetworkProperties *pDNPRedirectedUrl, bool bIsRedirected)
{
	fsInternetResult ir;
	fsDownload_NetworkProperties* dnp;
	
	*ppFile = NULL;

	if (iAttempt > 15)
		return IR_ERROR;

	vmsAUTOLOCKSECTION (m_csOpenUrl);
	if (m_bNeedStop)
		return IR_S_FALSE;

	if (pDNPRedirectedUrl)
		dnp = pDNPRedirectedUrl;
	else
		dnp = nMirror == UINT_MAX ? DNP (iSectIndex) : &m_vMirrs [nMirror].dnp;

	ASSERT (m_pOpeningFile == NULL);
	fsnew1 (m_pOpeningFile, fsInternetURLFile);
	m_pOpeningFile->SetDialogFunc (_InetFileDialogFunc, this, LPVOID (iSectIndex));
	
	vmsInternetSession* pSession = new vmsInternetSession;
	char szProxy [10000];
	vmsMakeWinInetProxy (dnp->pszProxyName, dnp->enProtocol, dnp->enProtocol, szProxy);
	ir  = pSession->Create (dnp->pszAgent, dnp->enAccType, szProxy, dnp->enProtocol);
	if (ir != IR_SUCCESS)
	{
		delete pSession;
		SAFE_DELETE (m_pOpeningFile);
		return ir;
	}
	
	ApplyProxySettings (pSession, dnp);
	
	m_pOpeningFile->Initialize (pSession, TRUE);

	ApplyProperties (m_pOpeningFile, dnp);

	
	if (dnp->enProtocol == NP_FTP && dnp->enFtpTransferType == FTT_UNKNOWN)
	{
		int posPath = strlen (dnp->pszPathName) - 1;
		int posExt = 0;
		LPSTR pszExt = new char [MY_MAX_PATH];

		while (posPath && dnp->pszPathName [posPath] != '.')
			pszExt [posExt++] = dnp->pszPathName [posPath--];

		if (posPath)
		{
			LPSTR pszExtension = new char [MY_MAX_PATH];

			pszExt [posExt] = 0;

			int i = 0;
			for (i = 0; i < posExt; i++)
				pszExtension [i] = pszExt [posExt - i - 1];

			pszExtension [i] = 0;
			
			if (IsExtInExtsStr (dnp->pszASCIIExts, pszExtension))
				m_pOpeningFile->FtpSetTransferType (FTT_ASCII);
			else
				m_pOpeningFile->FtpSetTransferType (FTT_BINARY);

			delete [] pszExtension;
		}
		else 
		{
			m_pOpeningFile->FtpSetTransferType (FTT_BINARY);
		}

		delete [] pszExt;
	}

	_inc_tOU_param toup;
	toup.pthis = this;
	toup.uStartPos = uStartPos;
	toup.pFile = m_pOpeningFile;
	toup.dnp = dnp;
	DWORD dw;
	HANDLE hOpen = CreateThread (NULL, 0, _threadOpenUrl, &toup, 0, &dw);
	while (WAIT_TIMEOUT == WaitForSingleObject (hOpen, 333))
	{
		if (m_bNeedStop || IsDone ())
			TerminateThread (hOpen, IR_TIMEOUT);
	}
	GetExitCodeThread (hOpen, &dw);
	CloseHandle (hOpen);

	ir =  (fsInternetResult)dw; 

	

	if (m_bNeedStop)
	{
		SAFE_DELETE (m_pOpeningFile);
		return IR_S_FALSE;
	}

	if (ir == IR_SUCCESS && bCheckFileSize && m_uSSFileSize != _UI64_MAX)
	{
		if (m_pOpeningFile->GetFileSize () != m_uSSFileSize)
			ir = IR_BADFILESIZE; 
	}

	if (ir != IR_SUCCESS)
	{
		if (ir == IR_NEEDREDIRECT)
		{
			bool _bIsRedirected = false;
			if (0 == (m_dnp.dwFlags & DNPF_DONT_UPDATE_ORIGINAL_URL_AFTER_REDIRECT))
			{
				_bIsRedirected = true;
				
				
				
				int i = 0;
				bool bThereIsIdenticalServer = false;
				for (i = 0; i < GetNumberOfSections(); i++) {

					LPCSTR pszServerName = DNP(i)->pszServerName;
					if (fsIsServersEqual(pszServerName, dnp->pszServerName, FALSE)) {
						bThereIsIdenticalServer = true;
						break;
					}
				}

				if (bThereIsIdenticalServer)
				{
					SAFE_DELETE (m_pOpeningFile);
					return IR_SERVERUNKERROR;
				}
			}

			LPCSTR pszUrlTo = m_pOpeningFile->GetLastError ();

			fsURL url;
			LPSTR pszUrl = new char [10000];
			DWORD dwLen = 10000;

			if (url.Crack (pszUrlTo) != IR_SUCCESS) 
			{
				

				LPSTR pszUrlPath = new char [10000];

				if (*pszUrlTo == 0)
					strcpy (pszUrlPath, "/");
				else if (*pszUrlTo != '/' && *pszUrlTo != '\\') 
				{
					

					fsPathFromUrlPath (dnp->pszPathName, dnp->enProtocol == NP_FTP, FALSE, pszUrlPath, 10000);

					if (pszUrlPath [lstrlen (pszUrlPath)-1] != '\\' &&
							pszUrlPath [lstrlen (pszUrlPath)-1] != '/')
						lstrcat (pszUrlPath, "\\");
					
					strcat (pszUrlPath, pszUrlTo);
				}
				else
				{
					strcpy (pszUrlPath, pszUrlTo);	
				}

				
				url.Create (fsNPToScheme (dnp->enProtocol), dnp->pszServerName, dnp->uServerPort, 
					dnp->pszUserName, dnp->pszPassword, pszUrlPath, pszUrl, &dwLen);

				delete [] pszUrlPath;
			}
			else
			{
				strcpy (pszUrl, pszUrlTo);	
			}

			Event (DE_REDIRECTING);

			
			LPSTR pszUser = new char [10000], pszPassword = new char [10000];
			if (dnp->pszUserName)
				strcpy (pszUser, dnp->pszUserName);
			else
				*pszUser = 0;

			if (dnp->pszPassword)
				strcpy (pszPassword, dnp->pszPassword);
			else
				*pszPassword = 0;

			fsDownload_NetworkProperties *dnpRedirectedUrl = NULL;

			if (dnp->dwFlags & DNPF_DONT_UPDATE_ORIGINAL_URL_AFTER_REDIRECT)
			{
				dnpRedirectedUrl = new fsDownload_NetworkProperties;
				fsDNP_BuffersInfo buffs;

				ZeroMemory (dnpRedirectedUrl, sizeof (*dnpRedirectedUrl));

				ir = fsDNP_GetByUrl (dnpRedirectedUrl, &buffs, TRUE, pszUrl);

				if (ir == IR_SUCCESS)
				{
					fsDNP_CloneSettings (dnpRedirectedUrl, dnp);
					dnp = dnpRedirectedUrl;
					setDirty();
				}
			}
			else
			{
				
				ir = fsDNP_ApplyUrl (dnp, pszUrl);
				setDirty();
			}

			delete [] pszUrl;

			if (ir != IR_SUCCESS)
			{
				
				SAFE_DELETE (m_pOpeningFile);
				return ir;
			}

			if (dnp->pszUserName == NULL || *dnp->pszUserName == 0)
			{
				SAFE_DELETE_ARRAY (dnp->pszUserName);
				dnp->pszUserName = new char [strlen (pszUser) + 1];
				strcpy (dnp->pszUserName, pszUser);

				SAFE_DELETE_ARRAY (dnp->pszPassword);
				dnp->pszPassword = new char [strlen (pszPassword) + 1];
				strcpy (dnp->pszPassword, pszPassword);
				setDirty();
			}

			delete [] pszUser; delete [] pszPassword;

			Event (DE_REDIRECTINGOKCONTINUEOPENING);

			SAFE_DELETE (m_pOpeningFile);
			
			if (m_bNeedStop == FALSE)
				ir = OpenUrl_imp (uStartPos, ppFile, iSectIndex, nMirror, bCheckFileSize, ++iAttempt, NULL, dnp, _bIsRedirected);
			else
				ir = IR_S_FALSE;
			
			if (dnpRedirectedUrl)
				delete dnpRedirectedUrl;
			
			return ir;
		}
		else 
		{
			if (ir == IR_EXTERROR)
				Event (DE_ERRFROMSERVER, (UINT) m_pOpeningFile->GetLastError ());

			UINT nMirr = nMirror;	
			if (nMirr == UINT_MAX && iSectIndex != -1)
				nMirr = m_vSections [iSectIndex].nMirrorURL;

			if (nMirr != UINT_MAX) {
				m_vMirrs [nMirr].bIsGood = FALSE; 
				setDirty();
			} else if (m_vMirrs.size ()) {
				nMirr = 0;	
			}

			if (nMirr != UINT_MAX)
			{
				if (UINT (iAttempt) < m_uMaxAttempts && iAttempt < 10)
				{
					nMirr = FindNotBusyMirrorIndex ();

					if (nMirr != UINT_MAX && IsDone () == FALSE)
					{
						

						if (iSectIndex != -1) {
							m_vSections [iSectIndex].nMirrorURL = nMirr;
							setDirty();
						}

						nMirror = nMirr;

						SAFE_DELETE (m_pOpeningFile);
						if (ir == IR_BADFILESIZE)
							Event (DE_BADFILESIZE);
						Event (DE_TRYINGANOTHERMIRROR);
						return OpenUrl_imp (uStartPos, ppFile, iSectIndex, nMirror, bCheckFileSize, ++iAttempt);
					}
				}
			}
		}

		if (ir == IR_RANGESNOTAVAIL || ir == IR_DOUBTFUL_RANGESRESPONSE)
		{
			m_enRST = RST_NONE;
			m_bWasAccessedAtLeastOnce = TRUE;
		}

		if (ir != IR_BADFILESIZE)
		{
			SAFE_DELETE (m_pOpeningFile);
			return ir;
		}
	}

	if (pDNPRedirectedUrl != NULL && !bIsRedirected)
	{
		
		
		if (m_pOpeningFile->GetFileSize () != GetSSFileSize ())
		{
			
			
			SAFE_DELETE (m_pOpeningFile);
			return IR_SERVERUNKERROR;
		}
	}
	
	*ppFile = m_pOpeningFile;
	m_enRST = m_enRST == RST_NONE ? RST_NONE : m_pOpeningFile->IsResumeSupported ();
	m_strSuggFileName = m_pOpeningFile->GetSuggestedFileName ();
	CheckIfSuggFileNameEncoded ();
	m_bWasAccessedAtLeastOnce = TRUE;
	m_pOpeningFile = NULL;

	if (m_strContentType.Length () == 0)
	{
		char szContType [1000];
		if ((*ppFile)->GetContentType (szContType))
			m_strContentType = szContType;
	}

	if (m_strFileName.Length () == 0)
	{
		if (m_strSuggFileName.Length ())
			m_strFileName = m_strSuggFileName;
		else
		{
			char szFile [10000];
			fsFileNameFromUrlPath (dnp->pszPathName, dnp->enProtocol == NP_FTP,
				TRUE, szFile, sizeof (szFile));
			m_strFileName = szFile;
		}
		setDirty(); 
	}

	(*ppFile)->GetLastModifiedDate (&m_fileDate);

	return IR_SUCCESS;
}

void fsInternetDownloader::SetRetryTime(DWORD dwMilliseconds)
{
	m_uRetryTime = dwMilliseconds;
}

BOOL fsInternetDownloader::GetSectionInfo(int iSection, fsSection* pSection, BOOL bNoCacheAccounting)
{
	if (iSection >= m_vSections.size ())
		return FALSE;

	fsSectionEx *sect = &m_vSections [iSection];
	*pSection = *sect;
	
	if (!bNoCacheAccounting)
	{
		pSection->uCurrent += sect->dwCacheLen;
		pSection->uDCurrent += sect->dwCacheLen;
	}

	pSection->file = NULL;
	
	return TRUE;
}

BOOL fsInternetDownloader::SetSection_TrafficLimit(int iSection, UINT uLimit)
{
	if (iSection >= m_vSections.size ())
		return FALSE;

	m_vSections [iSection].uSpeedLimit = uLimit;
	setDirty();

	return TRUE;
}

int fsInternetDownloader::GetNumberOfSections()
{
	return m_vSections.size ();
}

void fsInternetDownloader::SetSectionMinSize(UINT uMinSize)
{
	m_uSectionMinSize = uMinSize;
}

void fsInternetDownloader::StopDownloading()
{
	m_bNeedStop = TRUE;

	m_cThreads++;

	try 
	{
		if (m_pOpeningFile)
		{
			m_pOpeningFile->CloseHandle ();
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading unknown exception");
	}

	try 
	{
		if (m_pZipPreviewStream)
			m_pZipPreviewStream->Stop ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading unknown exception");
	}
	

	try
	{
		if (m_pMirrURLMgr)
			m_pMirrURLMgr->Abort ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading unknown exception");
	}

	try
	{
		for (int i = 0; i < m_vSections.size (); i++)
		{
			fsSection *sect = &m_vSections [i];
			try
			{
				if (sect->file)
					sect->file->CloseHandle ();
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("fsInternetDownloader::StopDownloading " + tstring(ex.what()));
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("fsInternetDownloader::StopDownloading unknown exception");
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::StopDownloading unknown exception");
	}

	m_cThreads--;
}

BOOL fsInternetDownloader::SaveSectionsState(LPBYTE pBuffer, LPDWORD pdwSize)
{
	DWORD dwNeedSize = sizeof (int) + m_vSections.size () * sizeof (fsSection);

	dwNeedSize += sizeof (int) + m_strFileName.Length ();
	dwNeedSize += sizeof (DWORD); 
	dwNeedSize += 2*sizeof (UINT64); 

	if (dwNeedSize == 0 || pBuffer == NULL)
	{
		*pdwSize = dwNeedSize;
		return TRUE;
	}

	if (*pdwSize < dwNeedSize)
	{
		*pdwSize = dwNeedSize;
		return FALSE;
	}

	*((LPINT)pBuffer) = m_vSections.size ();
	pBuffer += sizeof (INT);

	fsSection* pBuf = (fsSection*) pBuffer;

	for (int i = 0; i < m_vSections.size (); i++)
	{
		*pBuf++ = m_vSections [i];
	}

	pBuffer = LPBYTE (pBuf);
	*((LPINT)pBuffer) = m_strFileName.Length ();
	pBuffer += sizeof (int);
	strncpy (LPSTR (pBuffer), m_strFileName, m_strFileName.Length ());
	pBuffer += m_strFileName.Length ();

	*((LPDWORD)pBuffer) = m_dwState;
	pBuffer += sizeof (DWORD);

	((UINT64*)pBuffer) [0] = m_uSSFileSize;
	((UINT64*)pBuffer) [1] = m_uLDFileSize;
	pBuffer += 2*sizeof (UINT64);

	*pdwSize = dwNeedSize;

	return TRUE;
}

BOOL fsInternetDownloader::RestoreSectionsState(LPBYTE pBuffer, DWORD dwSize, DWORD dwVer)
{
	if (dwVer < 5)
		return RestoreSectionsState_vlt5 (pBuffer, dwSize, dwVer);

	if (dwVer == 5)
		return RestoreSectionsState_v5 (pBuffer, dwSize);
	
	if (pBuffer == NULL || m_vSections.size ())
		return FALSE;

	int cSects = *((LPINT) pBuffer);
	fsSection *pSects = (fsSection*) (pBuffer + sizeof (int));

	for (int i = 0; i < cSects; i++)
	{
		ASSERT (pSects->iSection == i);
		if (pSects->iSection != i)
			return FALSE;

		m_vSections.add (*pSects++);

		fsSection *sect = &m_vSections [i];
		
		sect->file = NULL;
		if (sect->state != SS_DONE)
			sect->state = SS_STOPPED;

		sect->pThis = this;
		sect->uSpeed = 0;

		
	}

	pBuffer = LPBYTE (pSects);
	int iStrLen = *((LPINT) pBuffer);
	pBuffer += sizeof (int);

	if (iStrLen > MY_MAX_PATH || iStrLen < 0)
		return FALSE;
	
	char sz [10000];
	strncpy (sz, LPCSTR (pBuffer), iStrLen);
	sz [iStrLen] = 0;
	m_strFileName = sz;
	pBuffer += iStrLen;

	m_dwState = *((LPDWORD) pBuffer);
	pBuffer += sizeof (DWORD);

	m_uSSFileSize = ((UINT64*) pBuffer) [0];
	m_uLDFileSize = ((UINT64*) pBuffer) [1];
	pBuffer += 2*sizeof (UINT64);

	
	if (m_vSections.size () == 1 && m_vSections [0].uDEnd == _UI64_MAX &&
			m_uLDFileSize != _UI64_MAX)
		m_vSections [0].uDEnd = m_uLDFileSize;

	return TRUE;
}

BOOL fsInternetDownloader::RestoreSectionsState_vlt5(LPBYTE pBuffer, DWORD dwSize, DWORD dwVer)
{
	if (dwVer < 4)
		return RestoreSectionsState_vlt4 (pBuffer, dwSize);
	
	if (pBuffer == NULL || m_vSections.size ())
		return FALSE;

	int cSects = *((LPINT) pBuffer);
	fsSection_v2 *pSects = (fsSection_v2*) (pBuffer + sizeof (int));

	for (int i = 0; i < cSects; i++)
	{
		fsSection section;
		section = *pSects++;

		m_vSections.add (section);

		fsSection *sect = &m_vSections [i];
		
		sect->file = NULL;
		if (sect->state != SS_DONE)
			sect->state = SS_STOPPED;

		sect->pThis = this;
		sect->uSpeed = 0;
	}

	pBuffer = LPBYTE (pSects);
	int iStrLen = *((LPINT) pBuffer);
	pBuffer += sizeof (int);

	if (iStrLen > MY_MAX_PATH || iStrLen < 0)
		return FALSE;
	
	char sz [10000];
	strncpy (sz, LPCSTR (pBuffer), iStrLen);
	sz [iStrLen] = 0;
	m_strFileName = sz;
	pBuffer += iStrLen;

	m_dwState = *((LPDWORD) pBuffer);
	pBuffer += sizeof (DWORD);
	
	m_uSSFileSize = 0;
	while (cSects--)
		m_uSSFileSize = max (m_uSSFileSize, m_vSections [cSects].uEnd);
	m_uLDFileSize = m_uSSFileSize;

	return TRUE;
}

BOOL fsInternetDownloader::RestoreSectionsState_vlt4(LPVOID pBuffer, DWORD dwSize)
{
	if (pBuffer == NULL || dwSize % sizeof (fsSection_v1) || m_vSections.size ())
		return FALSE;

	fsSection_v1 *pSects = (fsSection_v1*) pBuffer;

	for (UINT i = 0; i < dwSize / sizeof (fsSection_v1); i++)
	{
		fsSection section;
		section = *pSects++;

		m_vSections.add (section);

		fsSection *sect = &m_vSections [i];
		
		sect->file = NULL;
		if (sect->state != SS_DONE)
			sect->state = SS_STOPPED;

		sect->pThis = this;
		sect->uSpeed = 0;

		
	}

	int cSects = m_vSections.size ();

	m_uSSFileSize = 0;
	while (cSects--)
		m_uSSFileSize = max (m_uSSFileSize, m_vSections [cSects].uEnd);
	m_uLDFileSize = m_uSSFileSize;

	return TRUE;
}

fsInternetResult fsInternetDownloader::StartDownloading(UINT uStartFrom)
{
	int size = m_vSections.size ();

	m_speed.Reset ();
	m_dwDataLenInCache = 0;

	if (size == 0)
		return CreateMainSection (uStartFrom);

	if (IsRunning () || IsDone ())
		return IR_S_FALSE;

	m_bNeedStop = FALSE;

	if (m_vMirrs.size () == 0)
		Auto_SearchMirrors ();

	DWORD dwThread;
	BOOL bQS = TRUE;		
	BOOL bAtLeast1Started = FALSE;	

	m_bNoNewSections = TRUE;

	
	int nSC = GetNumberOfSections () - GetDoneSectionCount ();
	if (nSC) 
		
		#ifndef FDM_DLDR__RAWCODEONLY
		m_dwForceCacheSizePerSection = _App.FileWriteCacheSize () / nSC;
		#else
		m_dwForceCacheSizePerSection = 0;
		#endif

	
	for (int i = 0; i < size && m_bNeedStop == FALSE; i++)
	{
		fsSection &sect = m_vSections [i];

		if (sect.state == SS_DONE)
			continue;

		if (bQS)
		{
			if (Event (DE_QUERYNEWSECTION, sect.nMirrorURL) == FALSE)
				continue;
		}
		else
			bQS = TRUE;

		sect.file = NULL;

		UINT nMirrorInc = sect.nMirrorURL;
		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow++;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow++;

		sect.lastErr = OpenUrl (sect.uCurrent, &sect.file, -1, sect.nMirrorURL, TRUE);
		setDirty();
		if (sect.lastErr == IR_SUCCESS)
		{
			bAtLeast1Started = TRUE;

			if (Event (DE_NEEDFILE) == FALSE || FALSE == Event (DE_NEEDFILE_FINALINITIALIZATION))
				return IR_S_FALSE;
		}
		else if (bAtLeast1Started)
		{
			
			
			

			if (nMirrorInc == UINT_MAX)
				m_cBaseSectCreatingNow--;
			else
				m_vMirrs [nMirrorInc].cSectsCreatingNow--;

			continue;
		}

		

		switch (sect.lastErr)
		{
			case IR_RANGESNOTAVAIL:
			case IR_DOUBTFUL_RANGESRESPONSE:
				if (m_bDontRestartIfNoRanges)
				{
					if (nMirrorInc == UINT_MAX)
						m_cBaseSectCreatingNow--;
					else
						m_vMirrs [nMirrorInc].cSectsCreatingNow--;
					return sect.lastErr;
				}
				else
				{
					Event (DE_RESTARTINGBECAUSENORANGES);
					StopDownloading ();
					while (IsRunning ())
						Sleep (5);
					m_vSections.clear ();
					setDirty();
					if (nMirrorInc == UINT_MAX)
						m_cBaseSectCreatingNow--;
					else
						m_vMirrs [nMirrorInc].cSectsCreatingNow--;
					return StartDownloading (); 
				}
			break;

			case IR_FILENOTFOUND:
				if (m_bStopOnFileNotFound)
				{
					if (nMirrorInc == UINT_MAX)
						m_cBaseSectCreatingNow--;
					else
						m_vMirrs [nMirrorInc].cSectsCreatingNow--;
					return IR_FILENOTFOUND;
				}
			break;

			case IR_LOGINFAILURE:
            case IR_INVALIDPASSWORD:
			case IR_INVALIDUSERNAME:
				if (m_bStopOnAccDenied)
				{
					if (nMirrorInc == UINT_MAX)
						m_cBaseSectCreatingNow--;
					else
						m_vMirrs [nMirrorInc].cSectsCreatingNow--;
					return IR_LOGINFAILURE;
				}
			break;
		}

		if (sect.lastErr != IR_BADFILESIZE && sect.file == NULL && bAtLeast1Started == FALSE)
		{
			
			

			fsInternetResult ir = OpenUrl (0, &sect.file, -1, sect.nMirrorURL, TRUE);
			if (ir == IR_SUCCESS)
			{
				if (sect.file->GetFileSize () != m_uSSFileSize) {
					sect.lastErr = IR_BADFILESIZE; 
					setDirty();
				} else {
					delete sect.file;
					sect.file = NULL;
				}
			}
		}

		if (sect.lastErr == IR_BADFILESIZE)
		{
			UINT64 uNewSize = sect.file->GetFileSize ();

			if (m_uSSFileSize != uNewSize)
			{
				UINT64 u = m_uSSFileSize;
				m_uSSFileSize = uNewSize;
				setDirty();

				
				DWORD dwSCR = Event (DE_SCR);

				m_uSSFileSize = u;
				setDirty();
				
				switch (dwSCR)
				{
					case SCR_RESTART:
						SAFE_DELETE (sect.file);
						m_vSections.clear ();
						setDirty();
						
						if (nMirrorInc == UINT_MAX)
							m_cBaseSectCreatingNow--;
						else
							m_vMirrs [nMirrorInc].cSectsCreatingNow--;
						return StartDownloading ();

					case SCR_STOP:
						SAFE_DELETE (sect.file);
						setDirty(); 
						
						if (nMirrorInc == UINT_MAX)
							m_cBaseSectCreatingNow--;
						else
							m_vMirrs [nMirrorInc].cSectsCreatingNow--;
						return IR_S_FALSE;

					case SCR_ADJUSTFORNEWSIZE:
						
						if (m_uSSFileSize > uNewSize)
						{
							
							for (int i = 0; i < size; i++)
							{
								fsSection &sect = m_vSections [i];

								if (sect.uEnd > uNewSize)
								{
									EnterCriticalSection (&m_csSections);
									sect.uEnd = sect.uDEnd = uNewSize;
									if (sect.uCurrent > sect.uEnd)
									{
										sect.uCurrent = sect.uDCurrent = sect.uEnd;
										sect.state = SS_DONE;
									}
									setDirty();
									LeaveCriticalSection (&m_csSections);
								}
							}
						}
						else for (int i = 0; i < size; i++)
						{
							
							if (m_vSections [i].uEnd == m_uSSFileSize)
							{
								m_vSections [i].uEnd = uNewSize;
								setDirty();
								break;
							}
						}
						SAFE_DELETE (sect.file);
						i--; 
						m_uSSFileSize = uNewSize;
						setDirty();
						bQS = FALSE;
						if (nMirrorInc == UINT_MAX)
							m_cBaseSectCreatingNow--;
						else
							m_vMirrs [nMirrorInc].cSectsCreatingNow--;
						continue;

					default:
						ASSERT (FALSE);
						if (nMirrorInc == UINT_MAX)
							m_cBaseSectCreatingNow--;
						else
							m_vMirrs [nMirrorInc].cSectsCreatingNow--;
						return IR_S_FALSE;
				}
			}
		}

		if (nMirrorInc == UINT_MAX)
			m_cBaseSectCreatingNow--;
		else
			m_vMirrs [nMirrorInc].cSectsCreatingNow--;

		if (sect.file == NULL && bAtLeast1Started == FALSE)
			return sect.lastErr; 

		m_cThreads++; m_cRunningThreads++;
		Event (DE_SECTIONSTARTED, i);
		m_vSections [i].state = SS_DOWNLOADING;
		setDirty();
		CloseHandle (CreateThread (NULL, 0, _threadDownload, &m_vSections [i], 0, &dwThread));
	}

	m_bNoNewSections = FALSE;
	m_dwForceCacheSizePerSection = DWORD (-1);
	return IsRunning () ? IR_SUCCESS : IR_S_FALSE;
}

BOOL fsInternetDownloader::IsDownloading()
{
	for (int i = 0; i < m_vSections.size (); i++)
	{
		if (m_vSections [i].state == SS_DOWNLOADING)
			return TRUE;
	}

	return FALSE;
}

void fsInternetDownloader::LimitTraffic(UINT uLimit)
{
	m_uTrafficLimit = uLimit;

	UpdateTrafficLimit ();
}

UINT fsInternetDownloader::GetSpeed()
{
	return m_speed.GetSpeed ();
}

void fsInternetDownloader::SetEventFunc(fsDownloaderEventFunc pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEvent = lpParam;
}

DWORD fsInternetDownloader::Event(fsDownloaderEvent enEvent, UINT uDesc)
{
	if (m_pfnEvents)
		return m_pfnEvents (enEvent, uDesc, m_lpEvent);

	return TRUE;
}

void fsInternetDownloader::SetMaxReconnectionNumber(UINT uMax)
{
	m_uMaxAttempts = uMax;
}

UINT64 fsInternetDownloader::GetSectionMaxSize()
{
	int size = m_vSections.size ();
	UINT64 uMax = 0;

	for (int i = 0; i < size; i++)
	{
		UINT64 uD = m_vSections [i].uEnd - m_vSections [i].uCurrent;

		if (uMax < uD)
			uMax = uD;
	}

	return uMax;
}

BOOL fsInternetDownloader::IsDone()
{
	int size = m_vSections.size ();

	for (int i = 0; i < size; i++)
	{
		if (m_vSections [i].state != SS_DONE)
			return FALSE;
	}

	return size != 0;
}

BOOL fsInternetDownloader::IsStoppedByUser()
{
	return m_bNeedStop;
}

BOOL fsInternetDownloader::IsHavingError()
{
	return m_bErrDownloading;
}

fsInternetResult fsInternetDownloader::GetSectionLastError(int iSection)
{
	return m_vSections [iSection].lastErr;
}

BOOL fsInternetDownloader::SleepInterval()
{
	int i = m_uRetryTime;

	while (i > 0)
	{
		Sleep (100);
		i -= 100;

		if (m_bNeedStop)
			return FALSE;
	}

	return TRUE;
}

BOOL fsInternetDownloader::IsRunning()
{
	return m_cRunningThreads > 0;
}

UINT64 fsInternetDownloader::GetSSFileSize()
{
	return m_uSSFileSize;
}

int fsInternetDownloader::GetRunningSectionCount()
{
	return m_cRunningThreads;
}

BOOL fsInternetDownloader::IsAllSectionsOk()
{
	int cSections = m_vSections.size ();

	for (int i = 0; i < cSections; i++)
	{
		fsSectionState state = m_vSections [i].state;

		if (state != SS_DOWNLOADING && state != SS_DONE)
			return FALSE;
	}

	return TRUE;
}

int fsInternetDownloader::GetDownloadingSectionCount()
{
	m_vSections.lock ();

	int cSections = m_vSections.size ();
	int cDlding = 0;

	for (int i = 0; i < cSections; i++)
		if (m_vSections [i].state == SS_DOWNLOADING)
			cDlding++;

    m_vSections.unlock ();

	return cDlding;
}

void fsInternetDownloader::UpdateTrafficLimit()
{
	UINT nSections = m_vSections.size ();
	UINT nGoodSects = GetDownloadingSectionCount ();

	if (nGoodSects == 0)
		return;

	for (UINT i = 0; i < nSections; i++)
	{
		m_vSections [i].uSpeedLimit = m_uTrafficLimit / nGoodSects;
		setDirty();
	}
}

void fsInternetDownloader::ApplyProperties(fsInternetURLFile *pFile, fsDownload_NetworkProperties* dnp)
{
	
	if (*dnp->pszReferer == 0 && (dnp->enProtocol == NP_HTTP || dnp->enProtocol == NP_HTTPS))
	{
		
		
		
		char szUrl [10000];
		char szRefUrl [10000];
		fsURL url;
		DWORD dw = sizeof (szUrl);
		if (*dnp->pszPathName && strcmp (dnp->pszPathName, "/") && strcmp (dnp->pszPathName, "\\") && 
			 IR_SUCCESS == url.Create (fsNPToScheme (dnp->enProtocol), dnp->pszServerName, dnp->uServerPort, NULL, NULL, dnp->pszPathName,
			szUrl, &dw))
		{
			if (fsFilePathFromUrlPath (szUrl, dnp->enProtocol == NP_FTP, 
					FALSE, szRefUrl, sizeof (szRefUrl)))
			{
				LPSTR psz1 = strrchr (szRefUrl, '\\');
				LPSTR psz2 = strrchr (szRefUrl, '/');
				if (psz2 > psz1) 
					psz1 = psz2;

				if (psz1)
				{
					*(psz1+1) = 0;
					pFile->SetReferer (szRefUrl);
				}
			}
		}
	}
	else
		pFile->SetReferer (dnp->pszReferer);
	
	pFile->UseHttp11 (dnp->bUseHttp11);
	pFile->UseCookie (dnp->bUseCookie);
	pFile->SetCookies (dnp->pszCookies);
	pFile->SetPostData (dnp->pszPostData);
	pFile->UseFtpPassiveMode (dnp->dwFtpFlags & FTP_USEPASSIVEMODE);
	pFile->FtpSetDontUseLIST (dnp->dwFtpFlags & FTP_DONTSENDLIST);

	if (dnp->enFtpTransferType != FTT_UNKNOWN && dnp->enProtocol == NP_FTP)
		pFile->FtpSetTransferType (dnp->enFtpTransferType);
}

int fsInternetDownloader::GetDoneSectionCount()
{
	int cSections = m_vSections.size ();
	int cDlding = 0;

	for (int i = 0; i < cSections; i++)
		if (m_vSections [i].state == SS_DONE)
			cDlding++;

	return cDlding;
}

UINT64 fsInternetDownloader::GetBytesLeft()
{
	try
	{
		UINT64 uLeft = 0;
		int cSections = m_vSections.size ();

		for (int i = cSections - 1; i >= 0; i--)
		{
			fsSection *sect = &m_vSections [i];

			if (sect->uDEnd == _UI64_MAX)
				return _UI64_MAX;

			if (sect->uDEnd > sect->uDCurrent)
				uLeft += sect->uDEnd - sect->uDCurrent;
		}

		return uLeft - m_dwDataLenInCache;
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::GetBytesLeft " + tstring(ex.what()));
		return _UI64_MAX;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::GetBytesLeft unknown exception");
		return _UI64_MAX;
	}
}

void fsInternetDownloader::SetOutputFile(HANDLE hOutFile)
{
	m_hOutFile = hOutFile;
}

void fsInternetDownloader::ResetSections()
{
	StopDownloading ();
	while (m_cThreads)
		Sleep (5);
	m_vSections.clear ();
	setDirty();
}	

void fsInternetDownloader::DontRestartIfNoRanges(BOOL b)
{
	m_bDontRestartIfNoRanges = b;
}

void fsInternetDownloader::StopOnFileNotFound(BOOL b)
{
	m_bStopOnFileNotFound = b;
}

void fsInternetDownloader::StopOnAccDenied(BOOL b)
{
	m_bStopOnAccDenied = b;
}

UINT fsInternetDownloader::GetTrafficLimit()
{
	return m_uTrafficLimit;
}

fsResumeSupportType fsInternetDownloader::IsResumeSupported()
{
	return m_enRST;
}

float fsInternetDownloader::GetPercentDone()
{
	UINT64 uDone = 0, uSize = GetLDFileSize ();

	UINT64 uBytesLeft = GetBytesLeft ();

	if (uSize != _UI64_MAX)
		uDone = uSize - uBytesLeft;

	return uSize ? float ((double)(INT64)uDone / (INT64)uSize * 100.0f) : 0;
}

int fsInternetDownloader::GetCreatingNowSectionCount(UINT nMirror)
{
	if (m_cBaseSectCreatingNow < 0)
		m_cBaseSectCreatingNow = 0;

	if (nMirror == UINT_MAX)
		return m_cBaseSectCreatingNow != 0;
	else
		return m_vMirrs [nMirror].cSectsCreatingNow != 0;
}

void fsInternetDownloader::DeleteAllSections()
{
	if (IsRunning ())
		return;

	m_vSections.clear ();
	RemoveAllMirrors ();

	m_dwState &= ~ IDS_ZIPPREVIEWPERFORMED;

	m_uSSFileSize = m_uLDFileSize = 0;
	setDirty();
}

void fsInternetDownloader::StopSection()
{
	fsSection *sectErr = NULL, *sectDl = NULL;
	UINT64 errMax = 0, dlMax = 0;
	
	for (int i = 0; i < m_vSections.size (); i++)
	{
		fsSection *sect = &m_vSections [i];

		if (sect->state == SS_ERROR || sect->state == SS_RECONNECTING || sect->state == SS_WRITEERROR)
		{
			if ((sect->uEnd - sect->uCurrent) > errMax)
			{
				sectErr = sect;
				errMax = sect->uEnd - sect->uCurrent;
			}
		}
		else if (sect->state == SS_DOWNLOADING)
		{
			if ((sect->uEnd - sect->uCurrent) > dlMax)
			{
				sectDl = sect;
				dlMax = sect->uEnd - sect->uCurrent;
			}
		}
	}

	
	if (sectErr)
	{
		
		sectErr->state = SS_NEEDSTOP;
		setDirty();
	}
	else if (sectDl)
	{
		
		sectDl->state = SS_NEEDSTOP;
		setDirty();
	}
}

LPCSTR fsInternetDownloader::GetSuggestedFileName()
{
	return m_strSuggFileName.Length () ? (LPTSTR)m_strSuggFileName : NULL ;
}

fsInternetResult fsInternetDownloader::QuerySize()
{
	if (IsRunning ())
		return IR_S_FALSE;

	vmsAUTOLOCKSECTION (m_csAddSection);
	vmsAUTOLOCKSECTION (m_csOpenUrl);

	
	if (m_pOpeningFile)
		return IR_S_FALSE;

	fsInternetURLFile file;
	m_pOpeningFile = &file;
	m_pOpeningFile->SetDialogFunc (_InetFileDialogFunc, this, NULL);

	fsInternetResult ir =  QuerySize (&file);

	m_pOpeningFile = NULL;
	if (ir != IR_SUCCESS)
		return ir;

	m_uSSFileSize = m_uLDFileSize = file.GetFileSize ();
	setDirty();

	if (m_vSections.size () == 0)
	{
		
		fsSection sect;
		sect.uStart = sect.uDStart = 0;
		sect.uCurrent = sect.uDCurrent = 0;
		sect.uEnd = sect.uDEnd = m_uSSFileSize;
		sect.file = NULL;
	
		CreateSection (sect, FALSE);
	}

	return IR_SUCCESS;
}

fsInternetResult fsInternetDownloader::QuerySize(fsInternetURLFile *file)
{
	fsInternetResult ir;

	vmsInternetSession* pSession = new vmsInternetSession;
	char szProxy [10000];
	vmsMakeWinInetProxy (DNP ()->pszProxyName, DNP ()->enProtocol, DNP ()->enProtocol, szProxy);
	ir  = pSession->Create (DNP ()->pszAgent, DNP ()->enAccType, szProxy, DNP ()->enProtocol);
	if (ir != IR_SUCCESS)
		return ir;
	ApplyProxySettings (pSession, DNP ());

	ir = file->Initialize (pSession, TRUE);
	if (ir != IR_SUCCESS)
		return ir;

	ApplyProperties (file, DNP ());

	ir = file->QuerySize (fsNPToScheme (DNP ()->enProtocol), DNP ()->pszServerName,
				DNP ()->pszUserName, DNP ()->pszPassword, DNP ()->uServerPort, DNP ()->pszPathName,
				DNP ()->dwFlags & DNPF_IMMEDIATELY_SEND_AUTH_AS_BASIC);

	if (ir != IR_SUCCESS)
	{
		if (ir == IR_NEEDREDIRECT)
		{
			if (m_vSections.size ()) 
				return IR_SERVERUNKERROR;

			LPCSTR pszUrl = file->GetLastError ();

			

			fsURL url;
			CHAR szUrl [10000];
			DWORD dwLen = sizeof (szUrl);

			if (url.Crack (pszUrl) != IR_SUCCESS) 
			{
				char szUrlPath [10000];

				if (*pszUrl == 0)
					strcpy (szUrlPath, "/");
				else if (*pszUrl != '/' && *pszUrl != '\\')
				{
					fsPathFromUrlPath (DNP()->pszPathName, DNP()->enProtocol == NP_FTP, FALSE, szUrlPath, 10000);

					if (szUrlPath [lstrlen (szUrlPath)-1] != '\\' &&
							szUrlPath [lstrlen (szUrlPath)-1] != '/')
						lstrcat (szUrlPath, "\\");
					
					strcat (szUrlPath, pszUrl);
				}
				else
					strcpy (szUrlPath, pszUrl);

				url.Create (fsNPToScheme (DNP ()->enProtocol), DNP ()->pszServerName, DNP ()->uServerPort, 
					DNP ()->pszUserName, DNP ()->pszPassword, szUrlPath, szUrl, &dwLen);
			}
			else
				strcpy (szUrl, pszUrl);	

			fsDownload_NetworkProperties *dnp = DNP ();

			
			LPSTR pszUser = new char [10000], pszPassword = new char [10000];
			if (dnp->pszUserName)
				strcpy (pszUser, dnp->pszUserName);
			else
				*pszUser = 0;
			
			if (dnp->pszPassword)
				strcpy (pszPassword, dnp->pszPassword);
			else
				*pszPassword = 0;
			
			
			ir = fsDNP_ApplyUrl (DNP (), szUrl);
			setDirty();
			
			if (ir != IR_SUCCESS)
				return ir;
			
			if (dnp->pszUserName == NULL || *dnp->pszUserName == 0)
			{
				SAFE_DELETE_ARRAY (dnp->pszUserName);
				dnp->pszUserName = new char [strlen (pszUser) + 1];
				strcpy (dnp->pszUserName, pszUser);
				
				SAFE_DELETE_ARRAY (dnp->pszPassword);
				dnp->pszPassword = new char [strlen (pszPassword) + 1];
				strcpy (dnp->pszPassword, pszPassword);
				setDirty();
			}
			
			delete [] pszUser; delete [] pszPassword;

			

			if (m_bNeedStop == FALSE)
				return QuerySize (file);
			else
				return IR_S_FALSE;
		}
		else if (ir == IR_EXTERROR)
		{
			
		}

		return ir;
	}

	m_bWasAccessedAtLeastOnce = TRUE;
	m_enRST = m_enRST == RST_NONE ? RST_NONE : file->IsResumeSupported ();
	m_strSuggFileName = file->GetSuggestedFileName ();
	CheckIfSuggFileNameEncoded ();

	if (m_strFileName.Length () == 0)
	{
		if (m_strSuggFileName.Length ())
			m_strFileName = m_strSuggFileName;
		else
		{
			char szFile [10000];
			fsFileNameFromUrlPath (DNP ()->pszPathName, DNP ()->enProtocol == NP_FTP,
				TRUE, szFile, sizeof (szFile));
			m_strFileName = szFile;
		}
		setDirty();
	}

	return IR_SUCCESS;
}

int fsInternetDownloader::GetStoppedSectionCount()
{
	int cStopped = 0;

	for (int i = 0; i < m_vSections.size (); i++)
		if (m_vSections [i].state == SS_STOPPED)
			cStopped++;

	return cStopped;
}

fsInternetResult fsInternetDownloader::LaunchOneMoreSection()
{
	for (int i = 0; i < m_vSections.size (); i++)
	{
		if (m_vSections [i].state == SS_STOPPED)
		{
			m_vSections [i].file = NULL;
			setDirty(); 
			m_cThreads++; m_cRunningThreads++;
			DWORD dwThread;
			Event (DE_SECTIONSTARTED, i);
			CloseHandle (CreateThread (NULL, 0, _threadDownload, &m_vSections [i],	0, &dwThread));
			return IR_SUCCESS;
		}
	}

	return IR_S_FALSE;
}

void fsInternetDownloader::_InetFileDialogFunc(fsInetFileDialogDirection dir, LPCSTR pszMsg, LPVOID lp1, LPVOID lp2)
{
	fsInternetDownloader* pThis = (fsInternetDownloader*) lp1;
	int sect = (int) lp2;

	if (pThis->m_bDetLog)
	{
		fsDlgWithServerInfo info;
		info.dir = dir;
		info.pszMsg = pszMsg;
		info.iSection = sect;
		pThis->Event (DE_DIALOGWITHSERVER, UINT (&info));
	}
}

void fsInternetDownloader::UseDetailedLog(BOOL b)
{
	m_bDetLog = b;
}

fsDownload_NetworkProperties* fsInternetDownloader::MirrorDNP(int iMirror)
{
	return &m_vMirrs [iMirror].dnp;
}

int fsInternetDownloader::GetMirrorURLCount()
{
	return m_vMirrs.size ();
}

fsInternetResult fsInternetDownloader::AddMirrorURL(LPCSTR pszUrl, LPCSTR pszUser, LPCSTR pszPassword, BOOL bDontMeasureSpeed)
{
	fsInternetResult ir;

	fsDownload_NetworkProperties dnp;
	fsDNP_BuffersInfo buffs;

	ZeroMemory (&dnp, sizeof (dnp));
		
	ir = fsDNP_GetByUrl (&dnp, &buffs, TRUE, pszUrl);

	if (ir != IR_SUCCESS)
		return ir;

	fsDNP_CloneSettings (&dnp, DNP ());

	if (pszUser)
	{
		SAFE_DELETE_ARRAY (dnp.pszUserName);
		SAFE_DELETE_ARRAY (dnp.pszPassword);

		dnp.pszUserName = new char [strlen (pszUser) + 1];
		strcpy (dnp.pszUserName, pszUser);

		dnp.pszPassword = new char [pszPassword ? strlen (pszPassword) + 1 : 1];
		strcpy (dnp.pszPassword, pszPassword ? pszPassword : "");
	}

	AddMirror (&dnp, TRUE, bDontMeasureSpeed);

	return IR_SUCCESS;
}

fsInternetResult fsInternetDownloader::FindMirrors()
{
	m_cMirrsFound = 0;

	if (m_dwState & IDS_MIRRSEARCHPERFORMED)
		return IR_SUCCESS;

	char szFileName [10000];

	if (m_strFileName.Length () == 0)
	{
		fsFileNameFromUrlPath (DNP ()->pszPathName, DNP ()->enProtocol == NP_FTP, TRUE,
			szFileName, sizeof (szFileName));
	}
	else
		strcpy (szFileName, m_strFileName);

	fsMirrorURLsMgr_FileMirrorsDotCom mirrors;
#ifndef FDM_DLDR__RAWCODEONLY
	mirrors.Set_SearchURL (_App.Mirr_Server ());
#else 
	mirrors.Set_SearchURL (0);
#endif

	Event (DE_STARTINGSEARCHINGFORMIRRORS);

	mirrors.Set_EventFunc (_MirrMgrEvents, this);

	vmsInternetSession* pSession = new vmsInternetSession;
	char szProxy [10000];
	vmsMakeWinInetProxy (DNP ()->pszProxyName, DNP ()->enProtocol, DNP ()->enProtocol, szProxy);
	fsInternetResult ir  = pSession->Create (DNP()->pszAgent, DNP()->enAccType, szProxy, DNP ()->enProtocol);
	if (ir != IR_SUCCESS)
	{
		delete pSession;
		Event (DE_MIRRFAILED);
		return ir;
	}
	
	ApplyProxySettings (pSession, DNP());

	mirrors.Initialize (szFileName, GetSSFileSize (), DNP ()->pszServerName,
		pSession);

	ir = mirrors.SearchForMirrors ();
	if (ir != IR_SUCCESS)
	{
		delete pSession;
		Event (DE_MIRRFAILED);
		return ir;
	}

	m_dwState |= IDS_MIRRSEARCHPERFORMED;
	setDirty();

	for (int i = 0; i < mirrors.Get_MirrorURLCount () && UINT (i) < m_cMaxMirrs; i++)
	{
		AddMirrorURL (mirrors.Get_MirrorURL (i), NULL, NULL, TRUE);
		m_cMirrsFound++;
	}

	if (m_cMirrsFound && m_bNeedStop == FALSE)
	{
		Event (DE_MIRRFOUND);
		if (m_bMirrMeasureSpeed)
		{
			Event (DE_MEASURINGMIRRSPEED);
			MeasureMirrorsSpeed ();
		}
		Event (DE_MIRRDONE);
	}
	else
		Event (DE_NOMIRRFOUND);

	delete pSession;
	return IR_SUCCESS;
}

void fsInternetDownloader::Set_SearchForMirrors(BOOL bSearch)
{
	m_bSearchForMirrors = bSearch;
}

void fsInternetDownloader::_MirrMgrEvents(fsMirrorURLsMgrEvent ev, LPVOID lp)
{
	fsInternetDownloader* pThis = (fsInternetDownloader*) lp;

	switch (ev)
	{
		case MUME_CONNECTINGSEARCHSERVER:
			pThis->Event (DE_CONNECTINGMIRRSERVER);
			break;

		case MUME_RETREIVINGSEARCHRESULTS:
			pThis->Event (DE_GETTINGMIRRSEARCHRESULTS);
			break;
	}
}

UINT fsInternetDownloader::FindNotBusyMirrorIndex()
{
	if (m_vMirrs.size () == 0)
		return UINT_MAX;

	int cMirrs = m_vMirrs.size ();

	
	double *pfWeight = new double [cMirrs];

	
	int i = 0;
	for (i = 0; i < cMirrs; i++)
		pfWeight [i] = 1;

	
	
	for (i = 0; i < m_vSections.size (); i++)
	{
		if (m_vSections [i].nMirrorURL != UINT_MAX)
			pfWeight [m_vSections [i].nMirrorURL]++;
	}

	
	

	
	for (i = 0; i < cMirrs; i++)
	{
		DWORD dwPingTime = m_vMirrs [i].dwPingTime;
		if (dwPingTime == UINT_MAX)
			dwPingTime = 50000;

		
		
		pfWeight [i] = 1.0 / 
			(pfWeight [i] * pow (double (dwPingTime) / 1000.0f, 2));
	}

	double fMax = -1;
	int iMax = -1;

	
	for (i = 0; i < cMirrs; i++)
	{
		if (pfWeight [i] > fMax && m_vMirrs [i].bIsGood)
		{
			fMax = pfWeight [i];
			iMax = i;
		}
	}

	delete [] pfWeight;

	return iMax;
}

BOOL fsInternetDownloader::MeasureMirrorsSpeed()
{
	fsSitePingMgr pinger;

	m_bNeedStop = FALSE;

	if (pinger.TestState () == FALSE)
	{
		return FALSE;
	}

	m_dwBaseServerPingTime = pinger.Ping (DNP ()->pszServerName);

	setDirty();

	for (int i = 0; i < m_vMirrs.size (); i++)
	{
		if (m_bNeedStop)
			return FALSE;

		m_vMirrs [i].dwPingTime = pinger.Ping (m_vMirrs [i].dnp.pszServerName);
		setDirty();
	}

	return TRUE;
}

int fsInternetDownloader::GetMirrorRefs(int iMirrorIndex)
{
	int cRefs = 0;
	for (int i = 0; i < m_vSections.size (); i++)
		if (m_vSections [i].nMirrorURL == UINT (iMirrorIndex))
			cRefs ++;

	return cRefs;
}

BOOL fsInternetDownloader::IsSectionCreatingNow()
{
	if (GetCreatingNowSectionCount (UINT_MAX))
		return TRUE;

	for (int i = 0; i < m_vMirrs.size (); i++)
	{
		if (GetCreatingNowSectionCount (i))
			return TRUE;
	}

	return FALSE;
}

void fsInternetDownloader::Set_MirrFileMinSize(UINT u)
{
	m_uMirrFileMinSize = u;
}

void fsInternetDownloader::Set_MirrCalcSpeed(BOOL b)
{
	m_bMirrMeasureSpeed = b;
}

void fsInternetDownloader::Set_MirrMaxCount(UINT u)
{
	m_cMaxMirrs = u;
}

void fsInternetDownloader::Set_MirrDontSearchIfSizeUnk(BOOL b)
{
	m_bMirrDontSearchIfSizeUnk = b;
}

fsInternetResult fsInternetDownloader::Auto_SearchMirrors()
{
	if (m_bSearchForMirrors == FALSE)
		return IR_S_FALSE;

	if (m_bMirrDontSearchIfSizeUnk && m_uSSFileSize == _UI64_MAX)
		return IR_S_FALSE;

	if (m_uLDFileSize < m_uMirrFileMinSize || m_uLDFileSize < 100*1024)
		return IR_S_FALSE;

	return FindMirrors ();
}

DWORD fsInternetDownloader::GetMirrorPingTime(int iMirr)
{
	return m_vMirrs [iMirr].dwPingTime;
}

BOOL fsInternetDownloader::GetMirrorIsGood(int iMirr)
{
	return m_vMirrs [iMirr].bIsGood;
}

void fsInternetDownloader::RemoveAllMirrors()
{
	for (int i = 0; i < m_vMirrs.size (); i++)
		fsDNP_GetByUrl_Free (&m_vMirrs [i].dnp);

	m_vMirrs.clear ();
	m_dwState &= ~ IDS_MIRRSEARCHPERFORMED;
	m_strFileName = "";
	setDirty();
}

void fsInternetDownloader::AddMirror(fsDownload_NetworkProperties *dnp, BOOL bIsGood, BOOL bDontMeasureSpeed)
{
	fsMirrorURLInfo mirr;
	
	if (m_bMirrMeasureSpeed && bDontMeasureSpeed == FALSE)
	{
		fsSitePingMgr pinger;
		if (pinger.TestState ())
			mirr.dwPingTime = pinger.Ping (dnp->pszServerName);
	}

	mirr.dnp = *dnp;
	mirr.bIsGood = bIsGood;

	if (dnp->enProtocol == NP_FILE)
		m_dwState |= IDS_MIRRORS_HAS_LOCAL_SOURCE;
	
	m_vMirrs.add (mirr);
	setDirty();
}

DWORD fsInternetDownloader::Get_BaseServerPingTime()
{
	return m_dwBaseServerPingTime;
}

void fsInternetDownloader::Set_BaseServerPingTime(DWORD dw)
{
	m_dwBaseServerPingTime = dw;
}

BOOL fsInternetDownloader::IsMirrSearchPerformed()
{
	return m_dwState & IDS_MIRRSEARCHPERFORMED;
}

void fsInternetDownloader::Set_MirrPingTime(int iMirr, DWORD dw)
{
	m_vMirrs [iMirr].dwPingTime = dw;
}

LPCSTR fsInternetDownloader::GetContentType()
{
	return m_strContentType;
}

int fsInternetDownloader::GetFoundMirrorCount()
{
	return m_cMirrsFound;
}

UINT64 fsInternetDownloader::GetDownloadedBytesCount()
{
	UINT64 size = GetLDFileSize ();
	if (size != _UI64_MAX)
		return size - GetBytesLeft ();

	return m_vSections.size () ? m_vSections [0].uDCurrent + m_dwDataLenInCache : 0;
}

LPCSTR fsInternetDownloader::Get_FileName()
{
	return m_strFileName;
}

BOOL fsInternetDownloader::RestoreSectionsState_v5(LPBYTE pBuffer, DWORD )
{
	if (pBuffer == NULL || m_vSections.size ())
		return FALSE;

	int cSects = *((LPINT) pBuffer);
	fsSection_v3 *pSects = (fsSection_v3*) (pBuffer + sizeof (int));

	for (int i = 0; i < cSects; i++)
	{
		fsSection section;
		section = *pSects++;

		m_vSections.add (section);
		

		fsSection *sect = &m_vSections [i];
		
		sect->file = NULL;
		if (sect->state != SS_DONE)
			sect->state = SS_STOPPED;

		sect->pThis = this;
		sect->uSpeed = 0;

		
	}

	pBuffer = LPBYTE (pSects);
	int iStrLen = *((LPINT) pBuffer);
	pBuffer += sizeof (int);

	if (iStrLen > MY_MAX_PATH || iStrLen < 0)
		return FALSE;
	
	char sz [10000];
	strncpy (sz, LPCSTR (pBuffer), iStrLen);
	sz [iStrLen] = 0;
	m_strFileName = sz;
	pBuffer += iStrLen;

	m_dwState = *((LPDWORD) pBuffer);
	pBuffer += sizeof (DWORD);
	
	m_uSSFileSize = 0;
	while (cSects--)
		m_uSSFileSize = max (m_uSSFileSize, m_vSections [cSects].uEnd);
	m_uLDFileSize = m_uSSFileSize;

	return TRUE;
}

fsInternetResult fsInternetDownloader::CheckIsZIP(UINT64 uStartPosition, fsInternetURLFile **ppFileToCloseIfNeed)
{

	if (FALSE == IsMayZIP (uStartPosition ? TRUE : FALSE))
		return IR_S_FALSE;

	if ((m_dwState & IDS_ZIPPREVIEWALLOWED) == 0 && 
			FALSE == Event (DE_CONFIRMARCHIVEDETECTION))
	{
		
		
		m_dwState |= IDS_ZIPPREVIEWPERFORMED;

		setDirty();

		return IR_S_FALSE;
	}

	SAFE_DELETE (*ppFileToCloseIfNeed);
	m_dwState |= IDS_ZIPPREVIEWALLOWED;

	setDirty();
	
	fsArchiveInternetStream file;
	fsZipArchiveFastRebuilder zip;
	zip.SetSFXSize ((DWORD)uStartPosition);
	zip.SetFileSize ((DWORD)m_uSSFileSize);

	m_pZipPreviewStream = &file;

	fsInternetResult ir;

	Event (DE_ZIPPREVIEWSTARTED, int ((fsArchiveRebuilder*)&zip));

	file.Set_MaxRetriesCount (m_uMaxAttempts);
	ir = file.Open (this, uStartPosition);
	if (ir != IR_SUCCESS)
	{
		m_pZipPreviewStream = NULL;
		
		m_dwState &= ~IDS_ZIPPREVIEWALLOWED;

		setDirty();
		
		Event (DE_ZIPPREVIEWFAILED);
		return ir;
	}

	
	DWORD dwRes = zip.OpenArchive (m_pZipPreviewStream);
	if (dwRes != NOERROR)
	{
		
		
		m_pZipPreviewStream = NULL;
		m_dwState &= ~IDS_ZIPPREVIEWALLOWED;

		setDirty();
		
		Event (DE_ZIPPREVIEWFAILED);

		if (dwRes == ARR_STREAMERROR)
			return file.GetLastNetworkErr ();

		return IR_S_FALSE;
	}

	file.Close ();
	m_pZipPreviewStream = NULL;

	if (FALSE == Event (DE_ARCHIVEDETECTED, int ((fsArchiveRebuilder*)&zip))) 
	{
		

		m_dwState &= ~IDS_ZIPPREVIEWALLOWED;

		setDirty();
		
		return (fsInternetResult) 0x1000;
	}

	m_dwState |= IDS_ZIPPREVIEWPERFORMED;

	setDirty();
	
	if (FALSE == Event (DE_NEEDFILE))
		return IR_S_FALSE;

	fsArchiveFileStream outfile;
	outfile.Attach (m_hOutFile);
	outfile.Seek (uStartPosition, ST_BEGIN);
	
	zip.SaveArchiveHeaders (&outfile);

	outfile.Detach ();

	
	ApplyArchiveRebuilding (&zip, uStartPosition);

	return IR_SUCCESS;
}

void fsInternetDownloader::UseZipPreview(BOOL b)
{
	if (b)
		m_dwState |= IDS_USEZIPPREVIEW;
	else
		m_dwState &= ~IDS_USEZIPPREVIEW;
	setDirty();
}

void fsInternetDownloader::ApplyArchiveRebuilding(fsArchiveRebuilder *ar, UINT64 uAddOffset)
{
	m_vSections.clear ();
	setDirty();
	
	
	
	int i = 0;
	for (i = 0; i < ar->GetFileCount (); i++)
	{
		const fsArchiveFilePosition* filepos = ar->GetFilePosition (i);

		fsSection sect;
		sect.file = NULL;
		sect.iSection = i;
		sect.lastErr = IR_SUCCESS;
		sect.nMirrorURL = UINT_MAX;
		sect.pThis = this;
		sect.state = SS_STOPPED;
		
		sect.uStart = sect.uCurrent = filepos->dwSrcBegin + uAddOffset;
		sect.uEnd = filepos->dwSrcEnd + uAddOffset;

		sect.uDStart = sect.uDCurrent = filepos->dwDstBegin + uAddOffset;
		sect.uDEnd = filepos->dwDstEnd + uAddOffset;

		TSECT (&sect);

		if (filepos->dwSrcBegin == 0)
			sect.uDStart = sect.uStart = 0;

		
		m_vSections.add (sect);

		setDirty();

	}

	
	
	
	
	
	
	for (i = 1; i < m_vSections.size (); i++)
	{
		fsSection* prev = &m_vSections [i-1];
		fsSection* cur  = &m_vSections [i];

		if (prev->uEnd == cur->uStart)
		{
			
			prev->uEnd = cur->uEnd;
			prev->uDEnd = cur->uDEnd;

			m_vSections.del (i);

			setDirty();
			
			for (int j = i; j < m_vSections.size (); j++)
				m_vSections [j].iSection--;

			if (m_vSections.size () > 0) {
				setDirty(); 
			}

			i--;
		}
	}

	UINT64 uMaxPos = m_vSections [m_vSections.size ()-1].uEnd;
	UINT64 uDMaxPos = m_vSections [m_vSections.size ()-1].uDEnd;

	
	

	fsSection sect;
	sect.file = NULL;
	sect.iSection = m_vSections.size ();
	sect.lastErr = IR_SUCCESS;
	sect.nMirrorURL = UINT_MAX;
	sect.pThis = this;
	sect.state = SS_DONE;
		
	sect.uStart = uMaxPos;
	sect.uEnd = sect.uCurrent = uMaxPos;

	m_uLDFileSize = ar->GetResultingArchiveSize () + uAddOffset;

	sect.uDStart = uDMaxPos;
	sect.uDEnd = sect.uDCurrent = GetLDFileSize ();

	TSECT (&sect);

	m_vSections.add (sect);

	setDirty();

}

DWORD fsInternetDownloader::GetState()
{
	return m_dwState;
}

UINT64 fsInternetDownloader::GetLDFileSize()
{
	return m_uLDFileSize;
}

BOOL fsInternetDownloader::IsMayZIP(BOOL bIsExeMay)
{
	bIsExeMay = FALSE;
	
	if ((m_dwState & IDS_USEZIPPREVIEW) == 0)
		return FALSE; 

	if (m_dwState & IDS_ZIPPREVIEWPERFORMED)
		return FALSE;

	if (GetSSFileSize () == _UI64_MAX)
		return FALSE;	

	LPCSTR pszExt = strrchr (m_strFileName, '.');
	if (pszExt++ == NULL)
		return FALSE;	
	
	if (stricmp (pszExt, "zip") == 0)
		return TRUE;	
	
	if (bIsExeMay && stricmp (pszExt, "exe") == 0)
		return TRUE; 

	return FALSE; 
}

void fsInternetDownloader::ApplyProxySettings(fsInternetSession *pSession, fsDownload_NetworkProperties* dnp)
{
	pSession->SetProxyAuth (dnp->pszProxyUserName, dnp->pszProxyPassword);
	pSession->SetTimeout (m_uTimeout);
}

void fsInternetDownloader::Set_Timeout(UINT u)
{
	m_uTimeout = u;
}

BOOL fsInternetDownloader::RemoveMirror(int iIndex)
{
	if (m_bAddingSection || m_cBaseSectCreatingNow || m_csOpenUrl.OwningThread != NULL ||
			m_vMirrs [iIndex].cSectsCreatingNow)
		return FALSE;

	EnterCriticalSection (&m_csOpenUrl);

	
	for (int i = 0; i < m_vSections.size (); i++)
	{
		if (m_vSections [i].nMirrorURL == (UINT)iIndex)
		{
			m_vSections [i].nMirrorURL = UINT_MAX;
			if (m_vSections [i].state == SS_DOWNLOADING) {
				m_vSections [i].state = SS_NEEDSTOP;
			}
			setDirty();
		}
		else if (m_vSections [i].nMirrorURL != UINT_MAX && 
			m_vSections [i].nMirrorURL > (UINT)iIndex)
		{
			m_vSections [i].nMirrorURL--;
			setDirty();
		}
	}

	
	fsDNP_GetByUrl_Free (&m_vMirrs [iIndex].dnp);
	m_vMirrs.del (iIndex);

	setDirty();

	LeaveCriticalSection (&m_csOpenUrl);
	return TRUE;
}

fsString fsInternetDownloader::get_URL(BOOL bIncludeAuthInfo)
{
	fsURL url;
	char szUrl [10000];
	DWORD dw = sizeof (szUrl);

	if (IR_SUCCESS != url.Create (fsNPToScheme (DNP ()->enProtocol), DNP ()->pszServerName, DNP ()->uServerPort,
			bIncludeAuthInfo ? DNP ()->pszUserName : "", bIncludeAuthInfo ? DNP ()->pszPassword : "", 
			DNP ()->pszPathName, szUrl, &dw))
	{
		return "";
	}

	return szUrl;
}

FILETIME fsInternetDownloader::get_FileDate()
{
	return m_fileDate;
}

BOOL fsInternetDownloader::is_WasAccessedAtLeastOnce()
{
	return m_bWasAccessedAtLeastOnce;
}

void fsInternetDownloader::OnDataDownloaded(UINT64 nDataSize)
{
	vmsAUTOLOCKSECTION (m_csDataRcvd);
	m_nTotalTraffic += nDataSize;
	m_TotalSpeed.Done ((DWORD)nDataSize);
}

UINT64 fsInternetDownloader::get_TotalTraffic()
{
	return m_nTotalTraffic;
}

UINT64 fsInternetDownloader::get_TotalSpeed()
{
	return m_TotalSpeed.GetSpeed ();
}

void fsInternetDownloader::ResetTotalTrafficInfo()
{
	vmsAUTOLOCKSECTION (m_csDataRcvd);
	m_nTotalTraffic = 0;
}

BOOL fsInternetDownloader::IsCompletelyStopped ()
{
	return m_cThreads != 0;
}

DWORD WINAPI fsInternetDownloader::_threadOpenUrl(LPVOID lp)
{
	_inc_tOU_param *p = (_inc_tOU_param*) lp;

	DWORD dw;
	
	try 
	{
		fsInternetSession::AdjustWinInetConnectionLimit ();
		dw = p->pFile->Open (fsNPToScheme (p->dnp->enProtocol), p->dnp->pszServerName,
				p->dnp->pszUserName, p->dnp->pszPassword, p->dnp->uServerPort, 
				p->dnp->pszPathName, p->uStartPos, p->dnp->dwFlags & DNPF_IMMEDIATELY_SEND_AUTH_AS_BASIC);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::_threadOpenUrl " + tstring(ex.what()));
		dw = IR_ERROR;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetDownloader::_threadOpenUrl unknown exception");
		dw = IR_ERROR;
	}

	return dw;
}

void fsInternetDownloader::LockWriteFile(BOOL bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csWriteToFile);
	else
		LeaveCriticalSection (&m_csWriteToFile);
}

void fsInternetDownloader::CheckIfSuggFileNameEncoded()
{
	if (m_strSuggFileName.Length () < 13)
		return;

	if (strnicmp (m_strSuggFileName, "=?UTF-8?", 8))
		return;

	LPCSTR psz = &m_strSuggFileName [8];
	if (*psz != 'B' && *psz != 'b') 
		return;
	if (psz [1] != '?')
		return; 

	psz += 2;

	fsString str;
	while (psz [1] && (*psz != '?' || psz [1] != '='))
		str += *psz++;
	
	if (*psz != '?' || psz [1] != '=')
		return; 

	LPBYTE pb = new BYTE [str.Length ()];

	int len = base64_decode (str, pb);
	if (len <= 0)
	{
		delete [] pb;
		return; 
	}

	LPWSTR pwsz = new wchar_t [len+1];
	*pwsz = 0;
	len = MultiByteToWideChar (CP_UTF8, 0, (LPCSTR)pb, len, pwsz, len);
	if (len > 0)
		pwsz [len] = 0;
	
	WideCharToMultiByte (CP_ACP, 0, pwsz, -1, (LPSTR)pb, str.Length (), NULL, NULL);

	m_strSuggFileName = (LPSTR)pb;

	delete [] pb;
	delete [] pwsz;
}

void fsInternetDownloader::SetFileSize(UINT64 uSize) 
{
	m_uSSFileSize = uSize; 
	m_uLDFileSize = uSize;
}

void fsInternetDownloader::AddSection(UINT64 uStart, UINT64 uEnd, UINT64 uCurrent)
{
	ASSERT((uStart < uEnd) && (uCurrent >= uStart) && (uCurrent <= uEnd));

	EnterCriticalSection (&m_csAddSection);

	fsSection sect;

	sect.uStart = sect.uDStart = uStart;
	sect.uCurrent = sect.uDCurrent = uCurrent;
	sect.uEnd = sect.uDEnd = uEnd;

	sect.uSpeed = 0;
	sect.pThis = this;
	sect.lastErr = IR_SUCCESS;
	sect.uSpeedLimit = 0;

	if (uCurrent == uEnd) {
		sect.state = SS_DONE;
	} else {
		sect.state = SS_STOPPED;
	}
	sect.iSection = m_vSections.size ();

	m_vSections.add (sect);
	setDirty();

	LeaveCriticalSection (&m_csAddSection);
}

void fsInternetDownloader::SetManagerPersistObject(vmsPersistObject* pManagerPersistObject)
{
	m_pManagerPersistObject = pManagerPersistObject;
}

void fsInternetDownloader::setDirty()
{
	if (m_pManagerPersistObject) m_pManagerPersistObject->setDirty();
}
