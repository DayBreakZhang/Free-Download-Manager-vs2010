/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "AERDlg.h"
#include "vmsTpDownloadMgr.h"
#include "msdl/network.h"

vmsTpDownloadMgr::vmsTpDownloadMgr()
{
	m_bThreadRunning = m_bDlThreadNeedStop = false;
	m_dldr = NULL;
	m_pfnEvHandler = NULL;
	m_info.nFileSize = 0;
	m_info.nNumSections = 0;
	m_info.nStreamingSpeed = 0;
	m_info.bDone = FALSE;
	m_info.fPercentDone = 0;
	m_info.nDownloadedBytes = 0;
	m_info.strOutputPath = "";
	m_info.strTorrentUrl = "";
	m_info.strFileName = "";
	m_uRetryTime = 5000;
	m_bRename_CheckIfRenamed = FALSE;
	m_bDontQueryStoringDownloadList = false;
	m_enAER = _App.AlreadyExistReaction ();
}

vmsTpDownloadMgr::~vmsTpDownloadMgr()
{
	StopDownloading();
	SAFE_RELEASE(m_dldr);
}

fsInternetResult vmsTpDownloadMgr::StartDownloading(BOOL bNeedFile)
{
	if (IsRunning () || IsDone ())
		return IR_S_FALSE;

	
	if (bNeedFile && 0 == GetDownloadedBytesCount()
		&& FALSE == RaiseEvent (DE_NEEDFILE))
		return IR_S_FALSE;
	
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_dldr) m_dldr->Start();

	DWORD dwThread;
	CloseHandle (
		CreateThread (NULL, 0, _threadDownloadMgr, this, 0, &dwThread));
	
	return IR_SUCCESS;
}

void vmsTpDownloadMgr::StopDownloading()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_bDlThreadNeedStop = true;
	if (m_dldr) m_dldr->Stop();
}

BOOL vmsTpDownloadMgr::IsRunning()
{
	return m_bThreadRunning;
}

int vmsTpDownloadMgr::get_ConnectionCount()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_dldr ? m_dldr->get_ConnectionCount () : 0;
}

DWORD WINAPI vmsTpDownloadMgr::_threadDownloadMgr(LPVOID lp)
{
	vmsTpDownloadMgr *pThis = (vmsTpDownloadMgr*) lp;
	TransportProtocolStateEx enPrevState =STREAMING_FINISHED;

	fsTicksMgr tick0SpeedStart;
	tick0SpeedStart.Now ();

	pThis->m_bThreadRunning = true;
	BOOL bSSR = pThis->RaiseEvent (DE_EXTERROR, DMEE_STARTING);

	if (bSSR == FALSE)
	{
		pThis->RaiseEvent (DE_EXTERROR, DMEE_FATALERROR);
	}

	UINT  uMaxAttempts = 20;

	
	if (bSSR) while (!pThis->m_bDlThreadNeedStop)
	{

		TransportProtocolStateEx enCurrState = pThis->get_State ();
		if (enCurrState != enPrevState)
		{
			CHAR szEv [1000];
			switch (enCurrState)
			{
				case STREAMING_HANDSHAKING:
					sprintf (szEv, LS (L_CONNECTING));
					pThis->RaiseEvent (szEv);
					pThis->m_bDlThreadNeedStop = false;
					break;

				case STREAMING_DOWNLOADING:
					sprintf (szEv, LS (L_DOWNLOADING));
					pThis->RaiseEvent (szEv);
					pThis->m_bDlThreadNeedStop = false;
					break;

				case STREAMING_FINISHED:
					pThis->m_bDlThreadNeedStop = true;
					break;

				case STREAMING_REWIND:
					pThis->m_bDlThreadNeedStop = false;
					break;

				case STREAMING_RESUME_BUFFERING:
					pThis->m_bDlThreadNeedStop = false;
					break;

				case STREAMING_NO_NEED_TO_DOWNLOAD:
					pThis->m_bDlThreadNeedStop = false;
					break;

				case STREAMING_OTHER_PROTOCOL:
					pThis->m_bDlThreadNeedStop = false;
					break;

				case STREAMING_REDIRECTED:
					pThis->m_bDlThreadNeedStop = false;
					break;
				case STREAMING_FAILED:
					pThis->RaiseEvent (DE_EXTERROR, DMEE_FATALERROR);
					CHAR szStr [1000];
					strcpy(szStr, pThis->get_LastError ());
					pThis->RaiseEvent (szStr);
					sprintf (szStr, LS (L_PAUSESECS), pThis->m_uRetryTime/1000);
					pThis->RaiseEvent (szStr);
					if (pThis->SleepInterval () == FALSE)
						break; 
					
					if(--uMaxAttempts)
					{
						pThis->RaiseEvent(DE_EXTERROR, DMEE_STOPPEDORDONE);
						enPrevState = STREAMING_FINISHED;
						if (pThis->m_dldr) pThis->m_dldr->Start();
						bSSR = pThis->RaiseEvent (DE_EXTERROR, DMEE_STARTING);
						if (bSSR == FALSE)
						{
							pThis->RaiseEvent (DE_EXTERROR, DMEE_FATALERROR);
							break;
						}
						sprintf (szEv, LS (L_CONNECTING));
						pThis->RaiseEvent (szEv);
						continue;
					}
					pThis->m_bDlThreadNeedStop = true;
					break;
			}
			enPrevState = enCurrState;
		}

		Sleep (100);
	}

	pThis->m_bThreadRunning = false; 
	pThis->m_bDlThreadNeedStop = false;
	pThis->RaiseEvent(DE_EXTERROR, DMEE_STOPPEDORDONE);

	return 0;
}

void vmsTpDownloadMgr::SetEventsHandler(fntTpDownloadManagerEventHandler pfn, LPVOID pData)
{
	m_pfnEvHandler = pfn;
	m_lpEvParam = pData;
}

void vmsTpDownloadMgr::SetEventDescFunc(fntTpDownloadManagerEventDescFunc pfn, LPVOID lpParam)
{
	m_pfnEventDesc = pfn;
	m_lpEventDescParam = lpParam;
}

DWORD vmsTpDownloadMgr::RaiseEvent(fsDownloaderEvent ev, DWORD dw)
{
	if (m_pfnEvHandler == NULL)
		return 0;

	return m_pfnEvHandler (this, ev, dw, m_lpEvParam);
}

void vmsTpDownloadMgr::RaiseEvent(LPCSTR pszEvent, fsDownloadMgr_EventDescType enType)
{
	if (m_pfnEventDesc && *pszEvent)
		m_pfnEventDesc (this, enType, pszEvent, m_lpEvParam);
}

std::string vmsTpDownloadMgr::getTPDllFileName(void)
{
	tstring tstrDll;

	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MAX_PATH);
	LPTSTR ptsz = _tcsrchr (tsz, '\\');
	if (ptsz)
	{
		_tcscpy (ptsz + 1, _T ("msdl.dll"));
		tstrDll = tsz;
	}

	if (GetFileAttributes (tstrDll.c_str ()) != DWORD (-1))
		return tstrDll;

	
	tstrDll = ((CFdmApp*)AfxGetApp ())->m_strAppPath;
	if (tstrDll [tstrDll.length () - 1] != '\\')
		tstrDll += '\\';
	tstrDll += _T ("msdl.dll");
	return tstrDll;
}

bool vmsTpDownloadMgr::LoadTPDll(vmsDLL &dll)
{
	return dll.Load (getTPDllFileName ().c_str ());
}

TransferProtocolDownloader* vmsTpDownloadMgr::CreateTransferProtocolDownloader()
{
	if (m_dllTPD.is_Loaded () == false && 
			false == LoadTPDll (m_dllTPD))
		return NULL;

	vmsAUTOLOCKSECTION (m_csDownload);
	
	typedef TransferProtocolDownloader* (WINAPI *FNTPD)();
	static FNTPD _pfnCreateTransferProtocolDownloaderObject = NULL;
	
	if (_pfnCreateTransferProtocolDownloaderObject == NULL)
	{
		_pfnCreateTransferProtocolDownloaderObject = (FNTPD) m_dllTPD.GetProcAddress ("createTransferProtocolDownloader");
		if (_pfnCreateTransferProtocolDownloaderObject == NULL)
			return NULL;
	}

	return _pfnCreateTransferProtocolDownloaderObject ();
}

BOOL vmsTpDownloadMgr::CreateTPDownload(LPCSTR pszUrl, LPCSTR pszOutputPath, LPCSTR pszFileName, int nStreamingSpeed)
{
	assert (pszUrl != NULL);
	if (!pszUrl)
		return FALSE;

	vmsAUTOLOCKSECTION (m_csDownload);

	m_dldr = CreateTransferProtocolDownloader();

	if (m_dldr == NULL)
		return FALSE;

	m_info.strTorrentUrl = pszUrl;
	m_info.strOutputPath = pszOutputPath;
	m_info.strFileName = pszFileName;
	
	m_dldr->InitTpStream(pszUrl, m_info.strOutputPath + m_info.strFileName, nStreamingSpeed);

	return TRUE;
}

UINT vmsTpDownloadMgr::GetSpeed()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_dldr ? m_dldr->get_DownloadSpeed () : 0;
}

BOOL vmsTpDownloadMgr::IsDone()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_dldr == NULL)
		return FALSE;

	BOOL bDone = m_dldr->IsDone();
	return bDone ? bDone : m_info.bDone;
}

BOOL vmsTpDownloadMgr::IsCantStart()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_dldr == NULL)
		return FALSE;

	return m_dldr->get_State () != STREAMING_DOWNLOADING;
}

BOOL vmsTpDownloadMgr::IsDownloading()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	
	if (m_dldr == NULL)
		return FALSE;

	return m_dldr->get_State () == STREAMING_DOWNLOADING;
}

fsString vmsTpDownloadMgr::get_OutputFilePathName()
{
	char sz [10000] = "";
	strcpy(sz, m_info.strOutputPath);
	strcat(sz, m_info.strFileName);
	return sz;
}

fsString vmsTpDownloadMgr::get_FileName()
{	
	return m_info.strFileName;
}

fsString vmsTpDownloadMgr::get_OutputPath()
{
	return m_info.strOutputPath;
}

fsString vmsTpDownloadMgr::get_URL()
{
	
	return m_info.strTorrentUrl;
}

float vmsTpDownloadMgr::GetPercentDone(bool bSetDirtyFlag)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_dldr == NULL)
		return 0.0;

	float percentDone = m_dldr->get_PercentDone ();

	if (percentDone != 0.f) {
		float fOldPercentDone = m_info.fPercentDone;
		m_info.fPercentDone = percentDone;
		if (bSetDirtyFlag && m_info.fPercentDone != fOldPercentDone)
			setDirty();
	}

	return m_info.fPercentDone;
}

TransportProtocolStateEx vmsTpDownloadMgr::get_State()
{
	return m_dldr ? m_dldr->get_State () : STREAMING_FINISHED;
}

LPCSTR vmsTpDownloadMgr::get_LastError()
{
	return m_dldr ? m_dldr->get_LastError () : "";
}

void vmsTpDownloadMgr::GetSectionInfo(int nIndex, vmsSectionInfo *sect)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	
	UINT64 uTotal = GetTotalFilesSize ();
	int ns = GetNumberOfSections();
	UINT64 uPerPiece = uTotal / ns;
	
	sect->uDStart = nIndex * uPerPiece;
	sect->uDEnd = nIndex == ns-1 ? uTotal : sect->uDStart + uPerPiece - 1;
	sect->uDCurrent = GetDownloadedBytesCount();
}

UINT64 vmsTpDownloadMgr::GetTotalFilesSize(bool bSetDirtyFlag)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_dldr == NULL)
		return 0;

	UINT64 fileSize = m_dldr->get_TotalFilesSize ();
	
	if (fileSize) {
		UINT64 uiOldSize = m_info.nFileSize;
		m_info.nFileSize = fileSize;
		if (bSetDirtyFlag && m_info.nFileSize != uiOldSize)
			setDirty();
	}

	return m_info.nFileSize;
}

UINT64 vmsTpDownloadMgr::GetDownloadedBytesCount(bool bSetDirtyFlag)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_dldr == NULL)
		return 0;

	UINT64 bytesCount = m_dldr->get_TotalDownloadedBytesCount ();
	
	if (bytesCount) {
		UINT64 uiOldDownloadedBytes = m_info.nDownloadedBytes;
		m_info.nDownloadedBytes = bytesCount;
		if (bSetDirtyFlag && m_info.nDownloadedBytes != uiOldDownloadedBytes)
			setDirty();
	}
	return m_info.nDownloadedBytes;
}

int vmsTpDownloadMgr::GetNumberOfSections(bool bSetDirtyFlag)
{
	if (m_dldr == NULL)
		return 0;

	int nNumSections = m_dldr->get_NumberOfSections ();
	
	if (nNumSections) {
		int nOldNumSections = m_info.nNumSections;
		m_info.nNumSections = nNumSections;
		if (bSetDirtyFlag && m_info.nNumSections != nOldNumSections)
			setDirty();
	}

	return m_info.nNumSections;
}

int vmsTpDownloadMgr::GetStreamingSpeed(bool bSetDirtyFlag)
{
	if (m_dldr == NULL)
		return 0;

	int nOldStreamingSpeed = m_info.nStreamingSpeed;
	m_info.nStreamingSpeed = m_dldr->get_StreamingSpeed ();
	if (bSetDirtyFlag && m_info.nStreamingSpeed != nOldStreamingSpeed)
		setDirty();

	return m_info.nStreamingSpeed;
}

void vmsTpDownloadMgr::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	#define CHECK_SIZE(need) {if (lpBuffer != NULL && *pdwSize < (UINT)(lpBuffer + need - pb)) return;}

	LPBYTE lpBuffer = pb;

	DWORD dwNeedSize;
	dwNeedSize = sizeof (int) + m_info.strTorrentUrl.GetLength();
	dwNeedSize += sizeof (int) + m_info.strOutputPath.GetLength();
	dwNeedSize += sizeof (int) + m_info.strFileName.GetLength();
	dwNeedSize += sizeof (int); 
	dwNeedSize += sizeof (int); 
	dwNeedSize += sizeof (UINT64); 

	dwNeedSize += sizeof (m_info.bDone);
	dwNeedSize += sizeof (m_info.fPercentDone);
	dwNeedSize += sizeof (m_info.nDownloadedBytes);
	
	
	
	

	*pdwSize = dwNeedSize;

	if (pb == NULL) {
		return;
	}

	int i;

	
	i = strlen(m_info.strTorrentUrl);
	CHECK_SIZE (sizeof (int));
	CopyMemory (lpBuffer, &i, sizeof (int));
	lpBuffer += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (lpBuffer, m_info.strTorrentUrl, i);
	lpBuffer += i;
	
	
	i = strlen(m_info.strOutputPath);
	CHECK_SIZE (sizeof (int));
	CopyMemory (lpBuffer, &i, sizeof (int));
	lpBuffer += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (lpBuffer, m_info.strOutputPath, i);
	lpBuffer += i;

	
	i = strlen(m_info.strFileName);
	CHECK_SIZE (sizeof (int));
	CopyMemory (lpBuffer, &i, sizeof (int));
	lpBuffer += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (lpBuffer, m_info.strFileName, i);
	lpBuffer += i;
	

	
	i = GetStreamingSpeed (false);
	CHECK_SIZE (sizeof (int));
	CopyMemory (lpBuffer, &i, sizeof (int));
	lpBuffer += sizeof (int);

	
	m_info.nNumSections = GetNumberOfSections (false);
	CHECK_SIZE (sizeof (int));
	CopyMemory (lpBuffer, &m_info.nNumSections, sizeof (int));
	lpBuffer += sizeof (int);

	
	UINT64 fileSize = GetTotalFilesSize (false);
	CHECK_SIZE (sizeof (UINT64));
	CopyMemory (lpBuffer, &fileSize, sizeof (UINT64));
	lpBuffer += sizeof (UINT64);

	m_info.bDone = IsDone();
	CHECK_SIZE (sizeof (m_info.bDone));
	CopyMemory (lpBuffer, &m_info.bDone, sizeof (m_info.bDone));
	lpBuffer += sizeof (m_info.bDone);

	m_info.fPercentDone = GetPercentDone(false);
	CHECK_SIZE (sizeof (m_info.fPercentDone));
	CopyMemory (lpBuffer, &m_info.fPercentDone, sizeof (m_info.fPercentDone));
	lpBuffer += sizeof (m_info.fPercentDone);

	m_info.nDownloadedBytes = GetDownloadedBytesCount(false);
	CHECK_SIZE (sizeof (m_info.nDownloadedBytes));
	CopyMemory (lpBuffer, &m_info.nDownloadedBytes, sizeof (m_info.nDownloadedBytes));
	lpBuffer += sizeof (m_info.nDownloadedBytes);

	*pdwSize = lpBuffer - pb;

	return;
}

bool vmsTpDownloadMgr::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	ASSERT (dwVer >= 14);

	#define CHECK_BOUNDS(need) if (need < 0 || need > int(*pdwSize) - (pB - pb)) return FALSE;

	LPBYTE pB = (LPBYTE) pb;
	
	int i;
	char sz [10000];

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CHECK_BOUNDS (int (i));
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	fsString pszUrl = sz;
	pB += i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CHECK_BOUNDS (int (i));
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	fsString pszOutputPath = sz;
	pB += i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CHECK_BOUNDS (int (i));
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	fsString pszFileName = sz;
	pB += i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	m_info.nStreamingSpeed = i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&m_info.nNumSections, pB, sizeof (int));
	pB += sizeof (int);

	
	CHECK_BOUNDS (sizeof (UINT64));
	CopyMemory (&m_info.nFileSize, pB, sizeof (UINT64));
	pB += sizeof (UINT64);

	CHECK_BOUNDS (sizeof (m_info.bDone));
	CopyMemory (&m_info.bDone, pB, sizeof (m_info.bDone));
	pB += sizeof (m_info.bDone);
	
	CHECK_BOUNDS (sizeof (m_info.fPercentDone));
	CopyMemory (&m_info.fPercentDone, pB, sizeof (m_info.fPercentDone));
	pB += sizeof (m_info.fPercentDone);

	CHECK_BOUNDS (sizeof (m_info.nDownloadedBytes));
	CopyMemory (&m_info.nDownloadedBytes, pB, sizeof (m_info.nDownloadedBytes));
	pB += sizeof (m_info.nDownloadedBytes);

	if(!CreateTPDownload(pszUrl, pszOutputPath, pszFileName, i))
		return FALSE;

	*pdwSize = pB - (LPBYTE) pb;

	return TRUE;
}

BOOL vmsTpDownloadMgr::LoadState(LPBYTE lpBuffer, LPDWORD pdwSize, WORD wVer)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	ASSERT (wVer >= 14);

	#define CHECK_BOUNDS(need) if (need < 0 || need > int(*pdwSize) - (pB - LPBYTE (lpBuffer))) return FALSE;

	LPBYTE pB = (LPBYTE) lpBuffer;
	
	int i;
	char sz [10000];

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CHECK_BOUNDS (int (i));
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	fsString pszUrl = sz;
	pB += i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CHECK_BOUNDS (int (i));
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	fsString pszOutputPath = sz;
	pB += i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CHECK_BOUNDS (int (i));
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	fsString pszFileName = sz;
	pB += i;

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&m_info.nStreamingSpeed, pB, sizeof (int));
	pB += sizeof (int);

	
	CHECK_BOUNDS (sizeof (int));
	CopyMemory (&m_info.nNumSections, pB, sizeof (int));
	pB += sizeof (int);

	
	CHECK_BOUNDS (sizeof (UINT64));
	CopyMemory (&m_info.nFileSize, pB, sizeof (UINT64));
	pB += sizeof (UINT64);

	CHECK_BOUNDS (sizeof (m_info.bDone));
	CopyMemory (&m_info.bDone, pB, sizeof (m_info.bDone));
	pB += sizeof (m_info.bDone);
	
	CHECK_BOUNDS (sizeof (m_info.fPercentDone));
	CopyMemory (&m_info.fPercentDone, pB, sizeof (m_info.fPercentDone));
	pB += sizeof (m_info.fPercentDone);

	CHECK_BOUNDS (sizeof (m_info.nDownloadedBytes));
	CopyMemory (&m_info.nDownloadedBytes, pB, sizeof (m_info.nDownloadedBytes));
	pB += sizeof (m_info.nDownloadedBytes);

	if(!CreateTPDownload(pszUrl, pszOutputPath, pszFileName, i))
		return FALSE;

	*pdwSize = pB - (LPBYTE) lpBuffer;

	return TRUE;
}

DWORD vmsTpDownloadMgr::get_Flags()
{
	return m_info.dwFlags;
}

void vmsTpDownloadMgr::enable_Flags(DWORD dw)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_info.dwFlags |= dw;
}

void vmsTpDownloadMgr::disable_Flags(DWORD dw)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_info.dwFlags &= ~dw;
}

fsInternetResult vmsTpDownloadMgr::RestartDownloading()
{
	fsInternetResult ir = SetToRestartState ();

	if (ir != IR_SUCCESS)
		return ir;

	return StartDownloading ();
}

fsInternetResult vmsTpDownloadMgr::SetToRestartState()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	
	m_info.dwFastResumeDataSize = 0;

	
		
	m_info.nUploadedBytes = 0;
	m_info.fShareRating = 0;
	m_info.nWastedBytes = 0;
	m_info.fPercentDone = 0;
	m_info.bDone = FALSE;
	m_info.nDownloadedBytes = 0;

	setDirty();

	if (m_enAER != AER_RENAME_2)
	{
		if (FALSE == DeleteFile ())
			return IR_ERROR;
	}
	else
		m_bRename_CheckIfRenamed = TRUE;

	if (m_dldr) m_dldr->ReStart();

	return IR_SUCCESS;
}

BOOL vmsTpDownloadMgr::DeleteFile()
{
	bool bMaySleep = false;

	if (m_dldr)
	{
		if (IsRunning ())
		{
			StopDownloading ();
			while (m_bThreadRunning)
				Sleep (10);
		}

		bMaySleep = true;
	}

	USES_CONVERSION;

	
	std::wstring wstrSrcPath = A2W (m_info.strOutputPath);
	if (wstrSrcPath [wstrSrcPath.length () - 1] != '\\')
		wstrSrcPath += '\\';

	return ::DeleteFile (get_OutputFilePathName());
}

int vmsTpDownloadMgr::GetDownloadingSectionCount()
{
	if (m_dldr == NULL)
		return 0;
	return m_dldr->get_DownloadingSectionCount ();
}

BOOL vmsTpDownloadMgr::MoveToFolder(LPCSTR pszPath)
{
	CString str = pszPath;
	

	char szNewFile [MY_MAX_PATH];
	lstrcpy (szNewFile, str);

	if (szNewFile [lstrlen (szNewFile) - 1] != '\\' &&
			szNewFile [lstrlen (szNewFile) - 1] != '/')
		lstrcat (szNewFile, "\\");

	lstrcat (szNewFile, m_info.strFileName);

	BOOL bRes = MoveFile (szNewFile);

	m_info.strOutputPath = pszPath;
	setDirty();
	return bRes;
}

BOOL vmsTpDownloadMgr::MoveFile(LPCSTR pszNewFileName)
{
	if (IsRunning ()) 
	{
		SetLastError (0);
		return FALSE;
	}

	BOOL bOk = TRUE;

	
	
	{
		fsBuildPathToFile (pszNewFileName);
		
		if (GetFileAttributes (m_info.strOutputPath) != DWORD (-1))
			bOk = ::MoveFile (get_OutputFilePathName(), pszNewFileName); 
		else
			bOk = TRUE;
	}
					
	if (bOk == FALSE)
		return FALSE;

	return TRUE;
}

BOOL vmsTpDownloadMgr::SleepInterval()
{
	int i = m_uRetryTime;

	while (i > 0)
	{
		Sleep (100);
		i -= 100;

		if (m_bDlThreadNeedStop)
			return FALSE;
	}

	return TRUE;
}

BOOL vmsTpDownloadMgr::ApplyAER(fsAlreadyExistReaction enAER, bool bFirstCheck)
{
	

	
	switch (enAER)
	{
		case AER_ASKUSER:	
		{
#if !defined (FDM_DLDR__RAWCODEONLY)
			CAERDlg dlg;

			dlg.m_pszFile = m_info.strFileName;

			_DlgMgr.OnDoModal (&dlg);
			dlg.DoModal ();	
			_DlgMgr.OnEndDialog (&dlg);
			if (dlg.m_bDontAskAgain)	
			{
				m_enAER = dlg.m_enAER;	
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

			RaiseEvent (LS (L_REWRITINGIT), EDT_WARNING);
			return 2;

		case AER_RENAME_2:
		case AER_RENAME:

			RenameFile ();
			return TRUE;

		case AER_RESUME: 

			
			RaiseEvent (LS (L_RESUMINGDLD), EDT_WARNING);
			return TRUE;

		case AER_STOP:

			RaiseEvent (LS (L_ALREXISTS), EDT_RESPONSE_E);
			RaiseEvent (DE_EXTERROR, DMEE_USERSTOP);
			return -1;
			
		default:
			ASSERT (FALSE);
			return FALSE;
	}
}

void vmsTpDownloadMgr::RenameFile(BOOL bFormat1)
{
	int i = 1;
	DWORD dwResult;
	CHAR szFileWE [MY_MAX_PATH]; 
	CString strFile;

	

	strcpy (szFileWE, m_info.strOutputPath + m_info.strFileName);

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

	
	
	do
	{
		if (pszExt)
			strFile.Format ("%s(%d).%s", szFileWE, i++, pszExt+1);
		else
			strFile.Format ("%s(%d)", szFileWE, i++);

		dwResult = GetFileAttributes (strFile);
	}
	while (dwResult != DWORD (-1));

	char* szFileNameNew;
	fsnew (szFileNameNew, CHAR, strFile.GetLength () + 1);
	strcpy (szFileNameNew, strFile);
	
	HANDLE hFile = CreateFile (szFileNameNew, GENERIC_WRITE, 0, NULL, 
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	
	CHAR szFileName [MY_MAX_PATH];
	fsGetFileName (strFile, szFileName);
	CString strEv;
	if (bFormat1)
		strEv.Format ("%s \"%s\"", LS (L_FILEALREXISTSRENAMING), szFileName);
	else
		strEv.Format ("%s %s", LS (L_RENAMINGTO), szFileName);

	m_info.strFileName = szFileName;
	
	setDirty();

	RaiseEvent (strEv, EDT_WARNING);
	RaiseEvent (DE_EXTERROR, DMEE_FILEUPDATED);
}

BOOL vmsTpDownloadMgr::CheckDstFileExists()
{
	if (DWORD (-1) != GetFileAttributes (m_info.strOutputPath + m_info.strFileName)) 
	{
		fsAlreadyExistReaction enAER = m_enAER;

		BOOL bRet = ApplyAER (enAER);

		if (bRet == FALSE)
		{
			RaiseEvent (DE_EXTERROR, DMEE_FATALERROR);
			return FALSE;
		}
		else if (bRet == BOOL (-1))
			return FALSE;
		else if (bRet == BOOL (2))
			SetToRestartState ();

		RaiseEvent (LS (L_OPENINGFILE));
		m_dldr->InitTpStream(m_info.strTorrentUrl, m_info.strOutputPath + m_info.strFileName, GetStreamingSpeed ());
		RaiseEvent (LS (L_SUCCESS), EDT_RESPONSE_S);
	}

	return TRUE;
}