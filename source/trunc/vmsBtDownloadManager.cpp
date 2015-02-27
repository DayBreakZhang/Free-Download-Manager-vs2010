/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

﻿

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsBtDownloadManager.h"
#include "TorrentMoveErrorDlg.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

std::vector <vmsBtDownloadManager*>* vmsBtDownloadManager::m_pvpDlds = NULL;
vmsCriticalSection* vmsBtDownloadManager::m_pcsvpDlds = NULL;
HANDLE vmsBtDownloadManager::m_htDlds = NULL;
HANDLE vmsBtDownloadManager::m_hevStopDldsThread = NULL;
LONG vmsBtDownloadManager::m_cStatDataRefs = 0;
HANDLE vmsBtDownloadManager::m_hmxStaticObj = CreateMutex (NULL, FALSE, NULL);

vmsBtDownloadManager::vmsBtDownloadManager()
	: m_errorState(BTDES_NO_ERROR)	
	, m_downloadMagnetMetadata(false)
{
	WaitForSingleObject (m_hmxStaticObj, INFINITE);
	if (InterlockedIncrement (&m_cStatDataRefs) == 1)
	{
		if (!m_pcsvpDlds)
			m_pcsvpDlds = new vmsCriticalSection;

		if (!m_pvpDlds)
			m_pvpDlds = new std::vector <vmsBtDownloadManager*>;		

		if (!m_hevStopDldsThread)
			m_hevStopDldsThread = CreateEvent (NULL, TRUE, FALSE, NULL);
		if (!m_htDlds)
		{
			DWORD dw;
			m_htDlds = CreateThread (NULL, 0, _threadDlds, NULL, 0, &dw);
		}
	}
	ReleaseMutex (m_hmxStaticObj);

	m_pDownload = NULL;
	m_pTorrent = NULL;
	m_info.pbFastResumeData = NULL;
	m_info.dwFastResumeDataSize = 0;
	m_pfnEvHandler = NULL;
	m_info.dwFlags = 0;
	m_info.pfProgress = NULL;
	m_info.timeLastDataStatAccess.Now ();
	m_bStoppedByUser = FALSE;
	m_bDlThreadRunning = m_bDlThreadDoJob = m_bDlThreadNeedStop = false;
	m_info.nUploadedBytes = 0;
	m_info.fShareRating = 0;
	m_info.nWastedBytes = 0;
	m_info.fPercentDone = 0;
	m_info.bDone = FALSE;
	m_info.nDownloadedBytes = 0;
	m_nUsingBtDownload = 0;

	m_uTrafficLimit = UINT_MAX;
	m_uLowSpeedMaxTime = UINT_MAX;

	if (_App.Bittorrent_DisableSeedingByDef ())
		enable_Flags (BTDF_DISABLE_SEEDING);

	m_cache.nDownloadingSectionCount = 0;

	m_bNeedRaiseFatalError = false;

	m_cache.nDownloadedBytes_time.m_dwTicks = 0;
	m_cache.nDownloadingSectionCount_time.m_dwTicks = 0;
	m_cache.nPartial_time.m_dwTicks = 0;

	m_fRequiredRatio = 0;
}

vmsBtDownloadManager::~vmsBtDownloadManager()
{
	StopThread ();
	DeleteFromDldsList ();
	DeleteBtDownload ();
    SAFE_RELEASE (m_pTorrent);
	SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
	SAFE_DELETE_ARRAY (m_info.pfProgress);
	WaitForSingleObject (m_hmxStaticObj, INFINITE);
	if (0 == InterlockedDecrement (&m_cStatDataRefs))
	{
		Shutdown ();
		SAFE_DELETE (m_pvpDlds);
		SAFE_DELETE (m_pcsvpDlds);
	}
	ReleaseMutex (m_hmxStaticObj);
}

BOOL vmsBtDownloadManager::CreateByTorrentFile(LPCSTR pszTorrentFile, LPCSTR pszOutputPath, LPCSTR pszTorrentUrl, BOOL bSeedOnly)
{
	assert (pszTorrentFile != NULL);
	if (!pszTorrentFile)
		return FALSE;

	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (!LoadTorrent(pszTorrentFile))
		return FALSE;

	if (bSeedOnly)
	{
		if (m_pTorrent->GenerateFastResumeDataForSeed (pszOutputPath, NULL, 0, 
				&m_info.dwFastResumeDataSize))
		{
			m_info.pbFastResumeData = new BYTE [m_info.dwFastResumeDataSize];
			m_pTorrent->GenerateFastResumeDataForSeed (pszOutputPath, m_info.pbFastResumeData, 
				m_info.dwFastResumeDataSize, &m_info.dwFastResumeDataSize);
			m_info.bDone = TRUE;
			m_info.fPercentDone = 100;
			m_info.nDownloadedBytes = GetTotalFilesSize ();
			setDirty();
		}

		enable_Flags (BTDF_NEVER_DELETE_FILES_ON_DISK);
	}

	m_info.pfProgress = new float [get_FileCount () * sizeof (float)];
	for (int i = get_FileCount () - 1; i >= 0; i--)
		m_info.pfProgress [i] = bSeedOnly ? 1.0f : 0;

	SetTorrentInfo(pszTorrentFile, pszOutputPath);

	vmsAUTOLOCKSECTION_UNLOCK (m_csTorrentFile);

	PostCreateTorrentObject ();

	m_fRequiredRatio = _App.Bittorrent_RequiredRatio ();
	setDirty();

	return TRUE;
}

BOOL vmsBtDownloadManager::CreateByMagnetLink (LPCTSTR pszMagnetLink, LPCTSTR pszOutputPath)
{
	assert (pszMagnetLink != NULL);
	if (!pszMagnetLink)
		return FALSE;

	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (!LoadTorrent(pszMagnetLink, TRUE))
		return FALSE;

	SetTorrentInfo(pszMagnetLink, pszOutputPath);
	m_fRequiredRatio = _App.Bittorrent_RequiredRatio();

	vmsAUTOLOCKSECTION_UNLOCK (m_csTorrentFile);
	return TRUE;
}

BOOL vmsBtDownloadManager::CreateByMagnetMetadata (vmsBtFile* vmsFile, LPCTSTR pszOutputPath)
{
	assert (vmsFile != NULL);
	if (!vmsFile)
	{
		return FALSE;
	}
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (!LoadTorrent(NULL, TRUE, vmsFile))
		return FALSE;

	LPCTSTR magnetLink;
#ifdef UNICODE
	std::wstring wtemp = (LPCWSTR)vmsFile->GetMagnetLink();
	m_magnetLink.assign(wtemp.begin(), wtemp.end());
#else
	magnetLink = (LPCSTR)vmsFile->GetMagnetLink();
#endif

	SetTorrentInfo(magnetLink, pszOutputPath);
	m_fRequiredRatio = _App.Bittorrent_RequiredRatio();

	vmsAUTOLOCKSECTION_UNLOCK (m_csTorrentFile);
	return TRUE;
}

void vmsBtDownloadManager::SetTorrentInfo(LPCTSTR pszTorrentFile, LPCTSTR pszOutputPath)
{
	m_info.strTorrentUrl = pszTorrentFile;
	m_info.strOutputPath = pszOutputPath;
	if (m_info.strOutputPath [m_info.strOutputPath.GetLength () - 1] != '\\')
		m_info.strOutputPath += '\\';

	setDirty();
}

BOOL vmsBtDownloadManager::CreateBtDownload()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_pDownload)
		return TRUE;

	vmsBtSession *pSession = _BT.get_Session ();
	if (pSession == NULL)
		return FALSE;

	CString strOutputPath = m_info.strOutputPath;
	ProcessFilePathMacroses (strOutputPath);
	m_info.strOutputPath = strOutputPath;
	setDirty();

	m_pDownload = pSession->CreateDownload (m_pTorrent, strOutputPath, 
		m_info.pbFastResumeData, m_info.dwFastResumeDataSize, 
		m_info.dwFlags & BTDF_RESERVE_DISK_SPACE ? BTSM_SPARSE : BTSM_COMPACT,
		m_info.bDone ? 0 : BTSCDF_FORCE_IGNORE_TIMESTAMPS);

	if (m_pDownload == NULL)
		return FALSE;

	if (m_info.vFilesPriorities.size () && _BT.getBtDllVersion () >= 778)
	{
		int *pi = new int [m_info.vFilesPriorities.size ()];
		for (size_t i = 0; i < m_info.vFilesPriorities.size (); i++)
			pi [i] = m_info.vFilesPriorities [i];
		m_pDownload->PrioritizeFiles (pi);
		delete [] pi;
	}

	return TRUE;
}

void vmsBtDownloadManager::ProcessFilePathMacroses(CString &str)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return;

	if (str.Find ('%', 0) == -1)
		return;	

	if (str.Find ("%sdrive%") != -1)
	{
		str.Replace ("%sdrive%", CString (vmsGetExeDriveLetter ()) + ":");
		m_info.dwFlags |= BTDF_USE_PORTABLE_DRIVE;
		setDirty();
	}

	char szTracker [10000];
	m_pTorrent->get_TrackerUrl2 (szTracker, 0, sizeof (szTracker));
	fsURL url;
	url.Crack (szTracker);

	str.Replace ("%server%", url.GetHostName ());
	str.Replace ("%path_on_server%", url.GetPath ());

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
}

void vmsBtDownloadManager::DeleteBtDownload()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_pDownload)
	{
		DeleteFromDldsList ();
		vmsBtDownload *p = m_pDownload;
		while (m_nUsingBtDownload)
			Sleep (5);
		m_pDownload = NULL;
		vmsBtSession *pSession = _BT.get_Session ();
		if (pSession)
		{
			m_info.nUploadedBytes += p->get_TotalUploadedByteCount ();
			m_info.nWastedBytes += p->get_WastedByteCount ();
			while (m_nUsingBtDownload)
				Sleep (5);
			pSession->DeleteDownload (p);
		}

		setDirty();
	}
}

vmsBtDownloadStateEx vmsBtDownloadManager::get_State()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_errorState != BTDES_NO_ERROR)
	{
		return (vmsBtDownloadStateEx)m_errorState;
	}
	vmsBtDownloadStateEx enState = m_pDownload ?
		(vmsBtDownloadStateEx) m_pDownload->GetState () : BTDSE_STOPPED;
	return enState;
}

fsString vmsBtDownloadManager::get_TorrentName()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return "";
	char sz [10000] = "";
	m_pTorrent->get_TorrentName2 (sz, sizeof (sz));
	vmsUtf8ToAscii (sz);
	return sz;
}

UINT vmsBtDownloadManager::GetUploadSpeed()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_pDownload ? m_pDownload->GetUploadSpeed () : 0;
}

int vmsBtDownloadManager::get_FileCount()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	assert (m_pTorrent != NULL);
	if (!m_pTorrent)
		return 0;
	return m_pTorrent->get_FileCount ();
}

fsString vmsBtDownloadManager::get_OutputFilePathName(int nIndex)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);	
	std::string str = get_OutputPath ();
	assert (!str.empty ());
	if (str.empty ())
		return "";
	if (str [str.length () - 1] != '\\')
		str += '\\';
	str += get_FileName (nIndex);
	return str.c_str ();
}

LPCSTR vmsBtDownloadManager::get_OutputPath()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	return m_info.strOutputPath;
}

void vmsBtDownloadManager::SetEventsHandler(fntBtDownloadManagerEventHandler pfn, LPVOID pData)
{
	m_pfnEvHandler = pfn;
	m_lpEvParam = pData;

	if (pfn && m_bNeedRaiseFatalError)
	{
		RaiseEvent (BTDME_FATAL_ERROR);
		m_bNeedRaiseFatalError = false;
	}
}

fsString vmsBtDownloadManager::get_InfoHash()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return "";
	char sz [1000] = "";
	m_pTorrent->get_InfoHash (sz);
	return sz;
}

BOOL vmsBtDownloadManager::getInfoHash2(LPBYTE pb, LPDWORD pdwBufSize)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return false;
	return m_pTorrent->getInfoHash2 (pb, pdwBufSize);
}

LPCSTR vmsBtDownloadManager::get_TorrentUrl()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	return m_info.strTorrentUrl.IsEmpty () ? "" : m_info.strTorrentUrl;
}

void vmsBtDownloadManager::get_TrackerLogin(fsString &strUser, fsString &strPassword)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	strUser = m_info.strTrackerUser;
	strPassword = m_info.strTrackerPassword;
}

fsString vmsBtDownloadManager::get_URL()
{
	return get_TorrentUrl ();
}

DWORD vmsBtDownloadManager::get_Flags()
{
	return m_info.dwFlags;
}

void vmsBtDownloadManager::enable_Flags(DWORD dw)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_info.dwFlags |= dw;
	setDirty();
}

void vmsBtDownloadManager::disable_Flags(DWORD dw)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_info.dwFlags &= ~dw;
	setDirty();
}

void vmsBtDownloadManager::set_TrackerLogin(LPCSTR pszUser, LPCSTR pszPassword)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_info.strTrackerUser = pszUser;
	m_info.strTrackerPassword = pszPassword;
	if (m_pDownload)
		m_pDownload->set_TrackerLogin (pszUser, pszPassword);
	setDirty();
}

fsString vmsBtDownloadManager::get_TorrentComment()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return "";
	char sz [3000] = "";
	m_pTorrent->get_TorrentComment2 (sz, sizeof (sz));
	vmsUtf8ToAscii (sz);
	return sz;
}

fsString vmsBtDownloadManager::get_FileName(int nIndex)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return "";
	char sz [MY_MAX_PATH] = "";
	m_pTorrent->get_FileName2 (nIndex, sz, sizeof (sz));
	vmsUtf8ToAscii (sz);
	LPSTR psz = sz;
	while (*psz)
	{
		if (*psz == '/')
			*psz = '\\';
		psz++;
	}
	return sz;
}

UINT64 vmsBtDownloadManager::get_FileSize(int nIndex)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return 0;
	return m_pTorrent->get_FileSize (nIndex);
}

int vmsBtDownloadManager::get_FilePercentDone(int nIndex)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	fsTicksMgr time; time.Now ();

	if (time - m_info.timeLastDataStatAccess > 1000 || m_info.pfProgress == NULL)
	{
		if (get_State () != BTDSE_CHECKING_FILES && get_State () != BTDSE_CHECKING_RESUME_DATA &&
				get_State () != BTDSE_QUEUED)
			SaveBtDownloadState_FileProgress ();
	}

	return m_info.pfProgress ? (int) (m_info.pfProgress [nIndex] * 100) : 0;
}

int vmsBtDownloadManager::get_PieceCount()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return 0;
	return m_pTorrent->get_PieceCount ();
}

int vmsBtDownloadManager::get_PieceSize()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return 0;
	return m_pTorrent->get_PieceSize ();
}

fsString vmsBtDownloadManager::get_LastTracker()
{
	vmsAUTOLOCKSECTION (m_csMisc);
	return m_info.strLastTracker;
}

UINT64 vmsBtDownloadManager::get_TotalUploadedByteCount()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	UINT64 u = m_info.nUploadedBytes; 
	if (IsDownloadStatCanBeRead ())
	{
		assert (m_pDownload != NULL);
		if (m_pDownload)
			u += m_pDownload->get_TotalUploadedByteCount ();
	}
	return u;
}

double vmsBtDownloadManager::getRatio()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	UINT64 u = (__int64)GetDownloadedBytesCount (true);
	if (!u)
		return 0;
	return (double)(__int64)get_TotalUploadedByteCount () / (__int64)u;
	
}

UINT64 vmsBtDownloadManager::get_WastedByteCount()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_pDownload && IsDownloadStatCanBeRead ())
		return m_pDownload->get_WastedByteCount ();
	return m_info.nWastedBytes;
}

void vmsBtDownloadManager::get_PeersStat(int *pnPeersConnected, int *pnSeedsTotal, int *pnLeechersTotal, int *pnSeedsConnected)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_pDownload) 
	{
		m_pDownload->get_PeersStat(pnPeersConnected, pnSeedsTotal, pnLeechersTotal, pnSeedsConnected);
	}
	else
	{
		if (pnPeersConnected)
			*pnPeersConnected = 0;
		if (pnSeedsTotal)
			*pnSeedsTotal = 0;
		if (pnLeechersTotal)
			*pnLeechersTotal = 0;
		if (pnSeedsConnected)
			*pnSeedsConnected = 0;
	}
}

vmsBtDownloadPeerInfoList* vmsBtDownloadManager::get_PeerInfoList()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (!m_pDownload)
		return NULL;
	return m_pDownload->get_PeerInfoList ();
}

int vmsBtDownloadManager::get_NextAnnounceInterval(LPCSTR pszTrackerUrl)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (!m_pDownload)
		return -1;
	return m_pDownload->get_NextAnnounceInterval (pszTrackerUrl);
}

vmsBtDownload* vmsBtDownloadManager::get_BtDownload()
{
	return m_pDownload;
}

fsString vmsBtDownloadManager::get_OutputFilePathName()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return "";
	if (m_pTorrent->get_FileCount () == 1)
		return get_OutputFilePathName (0);
	else
		return get_OutputPath ();
}

float vmsBtDownloadManager::GetPercentDone()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_pDownload && IsDownloadStatCanBeRead ())
		return m_pDownload->get_PercentDone ();
	return m_info.fPercentDone;
}

BOOL vmsBtDownloadManager::IsDone()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (!IsDownloadStatCanBeRead ())
		return m_info.bDone;

	if (isSeeding ())
		return TRUE;

	if (get_State () != BTDSE_DOWNLOADING)
		return GetPercentDone () == 100.0f;

	return FALSE;
}

BOOL vmsBtDownloadManager::IsRunning()
{
	return m_bDlThreadDoJob || IsBtDownloadRunning ();
}

int vmsBtDownloadManager::GetNumberOfSections()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	assert (m_pTorrent != NULL);
	if (!m_pTorrent)
		return 0;
	return m_pTorrent->get_PieceCount ();
}

UINT64 vmsBtDownloadManager::GetTotalFilesSize()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	assert (m_pTorrent != NULL);
	if (!m_pTorrent)
		return 0;
	return m_pTorrent->get_TotalFilesSize ();
}

UINT64 vmsBtDownloadManager::GetDownloadedBytesCount(bool bFromCache)
{
	if (!bFromCache)
	{	
		vmsAUTOLOCKSECTION (m_csDownload);
		if (m_pDownload != NULL && IsDownloadStatCanBeRead ())
		{
			m_info.nDownloadedBytes = m_pDownload->get_TotalDownloadedBytesCount ();
			m_cache.nDownloadedBytes_time.Now ();

			setDirty();
		}
	}
	return m_info.nDownloadedBytes;
}

BOOL vmsBtDownloadManager::IsDownloading()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_pDownload == NULL)
		return FALSE;
	BOOL b = GetSpeed () != 0;
	if (!b)
		b = get_State () == BTDSE_DOWNLOADING && m_pDownload->IsPaused () == FALSE;
	return b;
}

void vmsBtDownloadManager::GetSectionInfo(int nIndex, vmsSectionInfo *sect)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	
	UINT64 uTotal = GetTotalFilesSize ();
	int ns = GetNumberOfSections ();
	UINT64 uPerPiece = uTotal / ns;
	
	sect->uDStart = nIndex * uPerPiece;
	sect->uDEnd = nIndex == ns-1 ? uTotal : sect->uDStart + uPerPiece - 1;
	bool bPC = false; 
	if (m_pDownload && IsDownloadStatCanBeRead () && get_State () == BTDSE_DOWNLOADING)
		bPC = m_pDownload->is_PieceCompleted (nIndex);
	else if (!m_info.vPieces.empty ())
		bPC = m_info.vPieces [nIndex];
	sect->uDCurrent = bPC ? sect->uDEnd : sect->uDStart;
}

int vmsBtDownloadManager::GetDownloadingSectionCount(bool bFromCache)
{
	if (bFromCache)
		return m_cache.nDownloadingSectionCount;

	vmsAUTOLOCKSECTION (m_csDownload);
	m_cache.nDownloadingSectionCount = m_pDownload ? m_pDownload->get_DownloadConnectionCount () : 0;
	m_cache.nDownloadingSectionCount_time.Now ();
	return m_cache.nDownloadingSectionCount;
}

UINT vmsBtDownloadManager::GetSpeed()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_pDownload ? m_pDownload->GetDownloadSpeed () : 0;
}

BOOL vmsBtDownloadManager::MoveToFolder(LPCSTR pszPath)
{
	InterlockedIncrement (&m_nUsingBtDownload);

	if (m_pDownload == NULL)
	{
		InterlockedDecrement (&m_nUsingBtDownload);

		USES_CONVERSION;

		
		std::wstring wstrSrcPath = A2W (m_info.strOutputPath);
		if (wstrSrcPath [wstrSrcPath.length () - 1] != '\\')
			wstrSrcPath += '\\';
		
		std::wstring wstrDstPath = A2W (pszPath);
		if (wstrDstPath [wstrDstPath.length () - 1] != '\\')
			wstrDstPath += '\\';

		
		int i = 0;
		for (i = 0; i < get_FileCount (); i++)
		{
			std::wstring wstrSrc = wstrSrcPath; wstrSrc += get_FileNameW (i);
			std::wstring wstrDst = wstrDstPath; wstrDst += get_FileNameW (i);
			fsBuildPathToFileW (wstrDst.c_str ());
			if (FALSE == MoveFileW (wstrSrc.c_str (), wstrDst.c_str ()) && 
					GetFileAttributesW (wstrSrc.c_str ()) != DWORD (-1))
				break;
		}

		if (i != get_FileCount ())
		{
			
			while (--i >= 0)
			{
				std::wstring wstrSrc = wstrSrcPath; wstrSrc += get_FileNameW (i);
				std::wstring wstrDst = wstrDstPath; wstrDst += get_FileNameW (i);
				MoveFileW (wstrDst.c_str (), wstrSrc.c_str ());
			}
			
			return FALSE;
		}

		RemoveBtDownloadDirectory ();

		
		vmsAUTOLOCKSECTION (m_csTorrentFile);
		m_info.strOutputPath = W2A (wstrDstPath.c_str ());

		setDirty();

		return TRUE;
	}

	CString str = pszPath;
	if (str [str.GetLength () - 1] != '\\')
			str += '\\';
	ProcessFilePathMacroses (str);
	if (FALSE == m_pDownload->MoveToFolder (str))
	{
		InterlockedDecrement (&m_nUsingBtDownload);
		return FALSE;
	}

	RemoveBtDownloadDirectory ();

	vmsAUTOLOCKSECTION (m_csTorrentFile);
	m_info.strOutputPath = str;

	setDirty();

	InterlockedDecrement (&m_nUsingBtDownload);

	return TRUE;
}

BOOL vmsBtDownloadManager::IsCantStart()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_pDownload == NULL)
		return FALSE;

	return IsBtDownloadRunning () && get_State () != BTDSE_DOWNLOADING &&
		get_State () != BTDSE_CHECKING_FILES;
}

BOOL vmsBtDownloadManager::IsBtDownloadRunning(bool *pbReason)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (!m_pDownload)
		return FALSE;

	vmsBtDownloadState enState = m_pDownload->GetState ();

	bool bPaused = enState == BTDSE_QUEUED || m_pDownload->IsPaused ();

	if (pbReason)
		*pbReason = bPaused;

	if (bPaused)
		return FALSE;

	return enState != BTDSE_SEEDING && enState != BTDSE_FINISHED;
}

fsInternetResult vmsBtDownloadManager::RestartDownloading()
{
	fsInternetResult ir = SetToRestartState ();

	if (ir != IR_SUCCESS)
		return ir;

	return StartDownloading ();
}

fsInternetResult vmsBtDownloadManager::SetToRestartState()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (m_pDownload)
		DeleteBtDownload ();

	SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
	m_info.dwFastResumeDataSize = 0;

	SAFE_DELETE_ARRAY (m_info.pfProgress);
		
	m_info.nUploadedBytes = 0;
	m_info.fShareRating = 0;
	m_info.nWastedBytes = 0;
	m_info.fPercentDone = 0;
	m_info.bDone = FALSE;
	m_info.nDownloadedBytes = 0;

	setDirty();

	if (FALSE == DeleteFile ())
		return IR_ERROR;

	return IR_SUCCESS;
}

BOOL vmsBtDownloadManager::DeleteFile()
{
	if (m_info.dwFlags & BTDF_NEVER_DELETE_FILES_ON_DISK)
		return TRUE;

	bool bMaySleep = false;

	if (m_pDownload)
	{
		if (IsRunning ())
		{
			StopDownloading ();
			while (m_bDlThreadRunning)
				Sleep (10);
		}
		else
		{
			SaveBtDownloadState ();
			DeleteBtDownload ();
		}

		bMaySleep = true;
	}

	

	USES_CONVERSION;

	
	std::wstring wstrSrcPath = A2W (m_info.strOutputPath);
	if (wstrSrcPath [wstrSrcPath.length () - 1] != '\\')
		wstrSrcPath += '\\';

	
	bool bAllDeletedOk = true;

	for (int i = 0; i < get_FileCount (); i++)
	{
		std::wstring wstr = wstrSrcPath; wstr += get_FileNameW (i);
		if (FALSE == ::DeleteFileW (wstr.c_str ()) && GetFileAttributesW (wstr.c_str ()) != DWORD (-1))
		{
			if (bMaySleep)
			{
				bMaySleep = false;
				Sleep (300);
				i--;
				continue;
			}
			bAllDeletedOk = false;
		}
	}

	RemoveBtDownloadDirectory ();

	return bAllDeletedOk;
}

fsInternetResult vmsBtDownloadManager::StartDownloading()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_downloadMagnetMetadata && m_pDownload != NULL && m_pDownload->is_HandleValid())
	{
		return IR_SUCCESS;
	}

	
	m_bStoppedByUser = TRUE;

	
	
	if (m_info.bDone || m_bDlThreadRunning && (m_pTorrent != NULL && m_pTorrent->IsValid() == TRUE))
		return IR_S_FALSE;

	if (m_pDownload == NULL && FALSE == CreateBtDownload ())
		return IR_ERROR;

	if (m_bDlThreadRunning == false)
	{
		ATLTRACE ("Creating thread BtDownloadManager\n");
		m_bDlThreadRunning = m_bDlThreadDoJob = true;
		m_bDlThreadNeedStop = false;
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadBtDownloadManager, this, 0, &dw));
	}

	return IR_SUCCESS;
}

void vmsBtDownloadManager::StopDownloading()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_bDlThreadNeedStop = true;
	if (isSeeding ())
		StopSeeding ();
	else if (m_pDownload && IsDone ())
		DeleteBtDownload ();
}

void vmsBtDownloadManager::LimitTraffic(UINT uLimit)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_pDownload)
		m_pDownload->SetDownloadLimit ((int)uLimit);
}

UINT vmsBtDownloadManager::GetTrafficLimit()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_pDownload ? (UINT)m_pDownload->GetDownloadLimit () : UINT_MAX;
}

void vmsBtDownloadManager::UseDetailedLog(BOOL bUse)
{
	
}

int vmsBtDownloadManager::get_ConnectionCount()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_pDownload ? m_pDownload->get_ConnectionCount () : 0;
}

std::wstring _tmpfix_convert_to_wstring(std::string & s)
{
	
	std::wstring ret;

	const char* end = &s[0] + s.size();
	for (const char* i = &s[0]; i < end;)
	{
		wchar_t c = '.';
		int result = std::mbtowc(&c, i, end - i);
		if (result > 0) i += result;
		else ++i;
		ret += c;
	}
	return ret;
}

void vmsBtDownloadManager::FixDir (fsString outputPath, vmsBtFile *pTorrent)
{
	
	std::string strOutPath = outputPath;
	std::wstring wstrOutPathBroken = _tmpfix_convert_to_wstring (strOutPath);

	USES_CONVERSION;
	const std::wstring wstrOutPath = A2CW(outputPath);
	
	if (!wcscmp (wstrOutPathBroken.c_str(), wstrOutPath.c_str()))
		return;

	
	if (GetFileAttributesW (wstrOutPathBroken.c_str()) != DWORD (-1))
	{
		static UINT _nRet = IDC_ABORT;
		std::vector <std::wstring> vFilePathBroken, vFilePath, vDirBroken;

		std::wstring wstrFileNameBroken;
		for (int i = 0; i < pTorrent->get_FileCount (); i++)
		{
			char szFile [MAX_PATH];
			
			pTorrent->get_FileName2 (i, szFile, MAX_PATH);
			std::string fileName = szFile;
			
			
			int n;
			while ((n = fileName.find ("/")) != -1)
			{
				fileName.replace(n, 1, "\\");
			}

			
			wchar_t wszFile [MAX_PATH];
			MultiByteToWideChar (CP_UTF8, 0, fileName.c_str(), -1, wszFile, MAX_PATH);

			
			wstrFileNameBroken = _tmpfix_convert_to_wstring (fileName);
			std::wstring wstrFilePathBroken = wstrOutPathBroken; wstrFilePathBroken += wstrFileNameBroken;

			
			const wchar_t *pdest = wstrFileNameBroken.c_str();
			while (pdest = wcschr (pdest, '\\')) 
			{
				std::wstring wstrDirBroken = wstrOutPathBroken;
				int ndest = (int)(pdest - wstrFileNameBroken.c_str() + 1);
				for (int i = 0; i < ndest; i++)
					wstrDirBroken += wstrFileNameBroken [i];
				
				if (GetFileAttributesW (wstrDirBroken.c_str()) != DWORD (-1) &&
					vDirBroken.end() == std::find(vDirBroken.begin(), vDirBroken.end(), wstrDirBroken))
					vDirBroken.push_back (wstrDirBroken);
				pdest++;
			}
				
			
			if (GetFileAttributesW (wstrFilePathBroken.c_str()) != DWORD (-1))
			{
				std::wstring wstrFilePath = wstrOutPath; wstrFilePath += wszFile;
				fsBuildPathToFileW (wstrFilePath.c_str());
				
				do
				{
					if (MoveFileW (wstrFilePathBroken.c_str (), wstrFilePath.c_str ()))
					{
						vFilePathBroken.push_back (wstrFilePathBroken);
						vFilePath.push_back (wstrFilePath);
					}
					else
					{
						if (ERROR_SHARING_VIOLATION == GetLastError () && _nRet != IDC_ABORTALL)
						{
							CHAR szErr [1000], szMsg [10000];
							fsErrorToStr (szErr, 1000);
							sprintf (szMsg, LS (L_TRIEDTODMOVE), W2A(wstrFilePathBroken.c_str()), W2A(wstrFilePath.c_str()), LS(L_ERR), szErr);
							
							CTorrentMoveErrorDlg dlg;
							dlg.m_strMsg = szMsg;
							_DlgMgr.OnDoModal (&dlg);
							_nRet = dlg.DoModal ();
							_DlgMgr.OnEndDialog (&dlg);
						
							if (IDC_RETRY == _nRet) continue;
						}

						
						
						for (int i = 0; i < vFilePathBroken.size (); i++)
							MoveFileW (vFilePath[i].c_str (), vFilePathBroken[i].c_str ());
						vFilePathBroken.clear(); vFilePath.clear();

						
						m_info.fPercentDone = 0;
						SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
						m_info.dwFastResumeDataSize = 0;
						RaiseEvent (BTDME_FATAL_ERROR);
						return;
					}
					break;
				} while (true);
			}
		}

		
		std::vector<std::wstring>::reverse_iterator it;
		for (it = vDirBroken.rbegin() ; it != vDirBroken.rend(); it++ )
			RemoveDirectoryW (it->c_str());

		
		RemoveDirectoryW (wstrOutPathBroken.c_str());
	}
}

BOOL vmsBtDownloadManager::LoadState(LPBYTE lpBuffer, LPDWORD pdwSize, WORD wVer)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	ASSERT (wVer >= 10);

	LPBYTE pbStart = lpBuffer;

	int i;
	char sz [10000];

	if (wVer > 10)
	{
		CopyMemory (&i, lpBuffer, sizeof (int));
		lpBuffer += sizeof (int);
		CopyMemory (sz, lpBuffer, i);
		sz [i] = 0;
		lpBuffer += i;
		m_info.strTorrentUrl = sz;
	}
	else
	{
		m_info.strTorrentUrl = "";
	}

	CopyMemory (&i, lpBuffer, sizeof (int));
	lpBuffer += sizeof (int);
	CopyMemory (sz, lpBuffer, i);
	sz [i] = 0;
	m_info.strOutputPath = sz;
	lpBuffer += i;

	CopyMemory (&i, lpBuffer, sizeof (int));
	lpBuffer += sizeof (int);
	CopyMemory (sz, lpBuffer, i);
	sz [i] = 0;
	lpBuffer += i;
	m_info.strTrackerUser = sz;

	CopyMemory (&i, lpBuffer, sizeof (int));
	lpBuffer += sizeof (int);
	CopyMemory (sz, lpBuffer, i);
	sz [i] = 0;
	lpBuffer += i;
	m_info.strTrackerPassword = sz;

	DWORD dwTorrentSize = *((LPDWORD)lpBuffer);
	LPBYTE pbTorrent = lpBuffer + sizeof (DWORD);
	lpBuffer += sizeof (DWORD) + dwTorrentSize;

	m_pTorrent = _BT.CreateTorrentFileObject ();
	if (m_pTorrent == NULL)
		return FALSE;
	if (FALSE == m_pTorrent->LoadFromBuffer (pbTorrent, dwTorrentSize))
		return FALSE;

	m_info.dwFastResumeDataSize = *((LPDWORD)lpBuffer);
	lpBuffer += sizeof (DWORD);
	SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
	if (m_info.dwFastResumeDataSize)
	{
		m_info.pbFastResumeData = new BYTE [m_info.dwFastResumeDataSize];
		CopyMemory (m_info.pbFastResumeData, lpBuffer, m_info.dwFastResumeDataSize);
		lpBuffer += m_info.dwFastResumeDataSize;
	}

	if (wVer > 11)
	{
		m_info.pfProgress = new float [get_FileCount () * sizeof (float)];
		CopyMemory (m_info.pfProgress, lpBuffer, get_FileCount () * sizeof (float));
		lpBuffer += get_FileCount () * sizeof (float);

		CopyMemory (&i, lpBuffer, sizeof (int));
		lpBuffer += sizeof (int);
		CopyMemory (sz, lpBuffer, i);
		sz [i] = 0;
		lpBuffer += i;
		m_info.strLastTracker = sz;

		CopyMemory (&m_info.nUploadedBytes, lpBuffer, sizeof (m_info.nUploadedBytes));
		lpBuffer += sizeof (m_info.nUploadedBytes);

		CopyMemory (&m_info.fShareRating, lpBuffer, sizeof (m_info.fShareRating));
		lpBuffer += sizeof (m_info.fShareRating);

		CopyMemory (&m_info.nWastedBytes, lpBuffer, sizeof (m_info.nWastedBytes));
		lpBuffer += sizeof (m_info.nWastedBytes);

		CopyMemory (&m_info.fPercentDone, lpBuffer, sizeof (m_info.fPercentDone));
		lpBuffer += sizeof (m_info.fPercentDone);

		CopyMemory (&m_info.bDone, lpBuffer, sizeof (m_info.bDone));
		lpBuffer += sizeof (m_info.bDone);

		CopyMemory (&i, lpBuffer, sizeof (int));
		lpBuffer += sizeof (int);
		m_info.vPieces.clear ();
		while (i--)
			m_info.vPieces.push_back ((*lpBuffer++) != 0);
		
		CopyMemory (&m_info.nDownloadedBytes, lpBuffer, sizeof (m_info.nDownloadedBytes));
		lpBuffer += sizeof (m_info.nDownloadedBytes);

		if (wVer > 12)
		{
			CopyMemory (&i, lpBuffer, sizeof (int));
			lpBuffer += sizeof (int);
			m_info.vFilesPriorities.clear ();
			while (i--)
				m_info.vFilesPriorities.push_back (*lpBuffer++);

			if (wVer > 13)
			{
				m_fRequiredRatio = *((float*)lpBuffer);
				lpBuffer += sizeof (float);	
			}
		}
	}
	else
	{
		m_info.pfProgress = new float [get_FileCount () * sizeof (float)];
		for (int i = get_FileCount () - 1; i >= 0; i--)
			m_info.pfProgress [i] = 0;

		PostCreateTorrentObject ();
	}

	m_info.dwFlags = *((LPDWORD)lpBuffer);
	lpBuffer += sizeof (DWORD);

	if (m_info.dwFlags & BTDF_USE_PORTABLE_DRIVE)
		m_info.strOutputPath [0] = vmsGetExeDriveLetter ();

	m_uLowSpeedMaxTime = *((LPUINT)lpBuffer);
	lpBuffer += sizeof (UINT);

	m_uTrafficLimit = *((LPUINT)lpBuffer);
	lpBuffer += sizeof (UINT);

	*pdwSize = lpBuffer - pbStart;

	

	if (!_App.NonUtf8NameFixed ())
		FixDir (m_info.strOutputPath, m_pTorrent);

	if ((m_info.dwFlags & BTDF_DISABLE_SEEDING) == 0 && m_info.bDone)
		EnableSeeding (TRUE);

	return TRUE;
}

void vmsBtDownloadManager::onSeedingFilesChangedUnexpectively ()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
	m_info.dwFastResumeDataSize = 0;
	for (int i = get_FileCount () - 1; i >= 0; i--)
		m_info.pfProgress [i] = 0;
	m_info.fPercentDone = 0;
	m_info.bDone = FALSE;
	m_cache.nDownloadingSectionCount = 0;
	m_info.nDownloadedBytes = 0;
	setDirty();

	DeleteFromDldsList ();
	if (get_State () == BTDSE_DOWNLOADING)
		SaveBtDownloadState ();
	DeleteBtDownload ();

	if (m_pfnEvHandler)
		RaiseEvent (BTDME_FATAL_ERROR);
	else
		m_bNeedRaiseFatalError = true;
}

BOOL vmsBtDownloadManager::IsStoppedByUser()
{
	return m_bStoppedByUser;
}

void vmsBtDownloadManager::setStoppedByUser (bool b)
{
	m_bStoppedByUser = b;
}

DWORD WINAPI vmsBtDownloadManager::_threadBtDownloadManager(LPVOID lp)
{
	vmsBtDownloadManager *pthis = (vmsBtDownloadManager*)lp;
	vmsBtDownloadStateEx enPrevState = BTDSE_QUEUED;

	pthis->m_cache.nDownloadingSectionCount = 0;
	pthis->m_cache.nDownloadingSectionCount_time.Now ();

	vmsBtDownload* downLoad = pthis->get_BtDownload();
	if (downLoad->get_Torrent()->IsMagnetLink() && downLoad->is_HandleValid() == false)
	{
		pthis->RaiseEvent (BTDME_DOWNLOADING_METADATA);

		while (downLoad->is_HandleValid() == false && pthis->m_bDlThreadNeedStop == false)
		{
			Sleep(200);
		}
		pthis->checkMagnetMetadata();
		pthis->PostCreateTorrentObject();

		if (pthis->m_downloadMagnetMetadata)
		{
			pthis->m_bDlThreadDoJob = false;
			pthis->m_bDlThreadRunning = false;
			return 0;
		}
	}
	else 
	{
		pthis->checkMagnetMetadata();
	}

	pthis->RaiseEvent (BTDME_DOWNLOAD_STARTED);

	while (pthis->get_State () == BTDSE_QUEUED && pthis->m_bDlThreadNeedStop == false)
		Sleep (100);

	bool bDownloading = false;
	bool bMayFilesEvent = true;
	
	fsTicksMgr timeStart;

	while (!pthis->m_bDlThreadNeedStop)
	{
		bool bReasonPaused = false;
		if (pthis->IsBtDownloadRunning (&bReasonPaused) == false)
		{
			if (bReasonPaused)
			{
				
				
				fsTicksMgr timeNow; 
				if (timeNow - timeStart > 7000)
					break;
			}
			else
			{
				break;
			}			
		}

		vmsBtDownloadStateEx enCurrState = pthis->get_State ();
		if (enCurrState != enPrevState)
		{
			switch (enCurrState)
			{
			case BTDSE_CHECKING_FILES:
				if (bMayFilesEvent)
					pthis->RaiseEvent (BTDME_CHECKING_FILES);
				bMayFilesEvent = false;
				break;

			case BTDSE_ALLOCATING:
				if (bMayFilesEvent)
					pthis->RaiseEvent (BTDME_ALLOCATING);
				bMayFilesEvent = false;
				break;

			case BTDSE_DOWNLOADING:
				pthis->GetDownloadingSectionCount (false);
				pthis->GetDownloadedBytesCount (false);
				
				
				_DldsMgr.setNeedProcessDownloads ();
				break;
			}

			enPrevState = enCurrState;
		}

		Sleep (100);
		if (bDownloading == false)
		{
			if (pthis->GetSpeed ())
			{
				bDownloading = true;
				pthis->RaiseEvent (BTDME_DOWNLOADING);
			}
		}
		else
		{
			fsTicksMgr time;
			if (time - pthis->m_cache.nDownloadingSectionCount_time > 3000)
			{
				pthis->GetDownloadingSectionCount (false);
				pthis->GetDownloadedBytesCount (false);
			}
		}
	}

	
	pthis->m_cache.nDownloadingSectionCount = 0;

	pthis->GetDownloadedBytesCount (false);

	if (pthis->m_pDownload != NULL &&
			(pthis->m_bDlThreadNeedStop || !pthis->isSeeding () ||
				(pthis->m_info.dwFlags & BTDF_DISABLE_SEEDING) != 0 || 
				_DldsMgr.AllowStartNewDownloads () == FALSE))
	{
		EnterCriticalSection (&pthis->m_csDownload);
		if (pthis->m_pDownload)
			pthis->m_pDownload->Pause ();
		pthis->SaveBtDownloadState ();
		pthis->DeleteBtDownload ();
		LeaveCriticalSection (&pthis->m_csDownload);
	}
	else
	{
		pthis->SaveBtDownloadState ();
	}

	pthis->m_bDlThreadDoJob = false;

	try
	{
		pthis->RaiseEvent (BTDME_DOWNLOAD_STOPPED_OR_DONE);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsBtDownloadManager::_threadBtDownloadManager " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsBtDownloadManager::_threadBtDownloadManager unknown exception");
	}

	if (pthis->isSeeding ())
	{
		pthis->AddToDldsList ();
		pthis->RaiseEvent (BTDME_SEEDING);
	}

	pthis->m_bDlThreadRunning = false;

	return 0;
}

void vmsBtDownloadManager::StopThread()
{
	if (m_bDlThreadRunning)
	{
		StopDownloading ();
		while (m_bDlThreadRunning)
			Sleep (10);
	}
}

void vmsBtDownloadManager::SaveBtDownloadState(bool bDontQueryStoringDownloadList)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_pDownload == NULL || m_pDownload->is_HandleValid () == FALSE)
		return;
	
	vmsBtDownloadStateEx enState = get_State ();
	if (enState == BTDSE_QUEUED || enState == BTDSE_CHECKING_RESUME_DATA || enState == BTDSE_CHECKING_FILES)
		return;

	LPBYTE pbFRD = NULL; DWORD dwFRDSize = 0;

	if (m_pDownload->get_FastResumeData (NULL, 0, &dwFRDSize) && dwFRDSize != 0)
	{
		pbFRD = new BYTE [dwFRDSize * 2];
		if (FALSE == m_pDownload->get_FastResumeData (pbFRD, dwFRDSize * 2, &dwFRDSize))
		{
			SAFE_DELETE_ARRAY (pbFRD);
			dwFRDSize = 0;
		}
	}

	assert (dwFRDSize != 0 || m_info.dwFastResumeDataSize == 0);
	if (!dwFRDSize && m_info.dwFastResumeDataSize)
		return; 

	if (pbFRD && dwFRDSize)
	{
		SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
		m_info.pbFastResumeData = pbFRD;
		m_info.dwFastResumeDataSize = dwFRDSize;
	}

	SaveBtDownloadState_FileProgress ();
	m_info.fShareRating = getRatio ();
	m_info.fPercentDone = GetPercentDone ();
	SaveBtDownloadState_Pieces ();
	m_info.nDownloadedBytes = GetDownloadedBytesCount (false);
	m_info.bDone = IsDone ();

	if (!bDontQueryStoringDownloadList)
		setDirty();
}

void vmsBtDownloadManager::SaveBtDownloadState_FileProgress()
{
	if (m_info.pfProgress == NULL)
	{
		const int nFiles = get_FileCount();
		if (m_pDownload == NULL || nFiles == 0)
		{
			return;
		}
		m_info.pfProgress = new float[nFiles];
		setDirty();
	}
		
	if (m_pDownload)
	{
		m_pDownload->get_FileProgress (m_info.pfProgress);

		setDirty();

		m_info.timeLastDataStatAccess.Now ();
	}
}

DWORD vmsBtDownloadManager::RaiseEvent(vmsBtDownloadManagerEvent ev, DWORD dw)
{
	if (m_pfnEvHandler == NULL)
		return 0;

	return m_pfnEvHandler (this, ev, dw, m_lpEvParam);
}

void vmsBtDownloadManager::PostCreateTorrentObject()
{
	for (int i = 0; i < get_PieceCount (); i++)
		m_info.vPieces.push_back (false);

	if (get_PieceCount () > 0) {
		setDirty();
	}
}

BOOL vmsBtDownloadManager::IsDownloadStatCanBeRead()
{
	
	
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_pDownload && 
		(get_State () == BTDSE_CONNECTING_TRACKER || get_State () == BTDSE_DOWNLOADING || 
		get_State () == BTDSE_FINISHED || get_State () == BTDSE_SEEDING);
}

void vmsBtDownloadManager::EnableSeeding(BOOL bEnable)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (bEnable)
	{
		disable_Flags (BTDF_DISABLE_SEEDING);
		if (m_pDownload == NULL && m_info.bDone && m_bDlThreadRunning == false)
		{
			if (getRequiredRatio () && getRatio () >= getRequiredRatio ())
				return; 

			m_bDlThreadRunning = true;
			m_bDlThreadNeedStop = false;
			DWORD dw;
			CloseHandle (
				CreateThread (NULL, 0, _threadCheckStartSeeding, this, 0, &dw));
		}
	}
	else
	{
		enable_Flags (BTDF_DISABLE_SEEDING);
		StopSeeding ();
	}
}

void vmsBtDownloadManager::RecursiveRemoveDirectory(LPCWSTR pwszPath)
{
	std::wstring wstrPath = pwszPath;
	if (wstrPath [wstrPath.length () - 1] != '\\')
		wstrPath += '\\';
	std::wstring wstrMask = wstrPath; wstrMask += L"*.*";

	fs::list <std::wstring> vFolders;

	WIN32_FIND_DATAW wfd;
	HANDLE hFind = FindFirstFileW (wstrMask.c_str (), &wfd);
	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::wstring wstr = wstrPath; wstr += wfd.cFileName;
			DWORD dw = GetFileAttributesW (wstr.c_str ());
			if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY) != 0 && 
					wcscmp (wfd.cFileName, L".") && wcscmp (wfd.cFileName, L".."))
			{
				vFolders.add (wstr);
			}
		}
		while (FindNextFileW (hFind, &wfd));

		FindClose (hFind);

		for (int i = 0; i < vFolders.size (); i++)
			RecursiveRemoveDirectory (vFolders [i].c_str ());

		RemoveDirectoryW (pwszPath);
	}
}

void vmsBtDownloadManager::RemoveBtDownloadDirectory()
{
	USES_CONVERSION;
	std::wstring wstr = get_FileNameW (0);
	if (wcschr (wstr.c_str (), '\\'))
	{
		std::wstring wstr2 = A2W (m_info.strOutputPath);
		for (int i = 0; wstr [i] != '\\'; i++)
			wstr2 += wstr [i];	
		RecursiveRemoveDirectory (wstr2.c_str ());
	}
}

DWORD WINAPI vmsBtDownloadManager::_threadCheckStartSeeding(LPVOID lp)
{
	vmsBtDownloadManager *pthis = (vmsBtDownloadManager*)lp;

	pthis->CreateBtDownload ();

	bool bNeedSaveFRD = false;
	
	
	while (pthis->m_bDlThreadNeedStop == false && pthis->m_pDownload != NULL)
	{
		vmsBtDownloadStateEx s = pthis->get_State ();

		if (s == BTDSE_CHECKING_FILES)
		{
			pthis->onSeedingFilesChangedUnexpectively ();
			break;
		}

		

		
		if (s != BTDSE_QUEUED && s != BTDSE_CHECKING_FILES && s != BTDSE_CONNECTING_TRACKER && s != BTDSE_CHECKING_RESUME_DATA)
			break;

		if (s == BTDSE_CONNECTING_TRACKER && 
				(pthis->m_info.bDone == FALSE && pthis->GetPercentDone () != 100.0f))
			break;

		Sleep (10);
	}

	if (bNeedSaveFRD)
		pthis->SaveBtDownloadState ();

	if (pthis->m_bDlThreadNeedStop == false && pthis->m_pDownload != NULL)
	{
		if (!pthis->isSeeding () || (pthis->m_info.dwFlags & BTDF_DISABLE_SEEDING) != 0)
		{
			pthis->DeleteBtDownload ();
		}
		else
		{
			pthis->AddToDldsList ();
			pthis->RaiseEvent (BTDME_SEEDING);
		}
	}

	pthis->m_bDlThreadRunning = false;

	return 0;
}

void vmsBtDownloadManager::StopSeeding()
{
	if (isSeeding ())
	{
		vmsAUTOLOCKSECTION (m_csDownload);
		DeleteFromDldsList ();
		SaveBtDownloadState ();
		DeleteBtDownload ();
		vmsAUTOLOCKSECTION_UNLOCK (m_csDownload);
		RaiseEvent (BTDME_STOP_SEEDING);
	}
}

std::wstring vmsBtDownloadManager::get_FileNameW(int nIndex)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	ASSERT (m_pTorrent != NULL);
	if (!m_pTorrent)
		return L"";
	char sz [MY_MAX_PATH] = "";
	m_pTorrent->get_FileName2 (nIndex, sz, MY_MAX_PATH);
	std::wstring wstr = vmsUtf8Unicode (sz);
	LPWSTR pwsz = (LPWSTR)wstr.c_str ();
	while (*pwsz)
	{
		if (*pwsz == '/')
			*pwsz = '\\';
		pwsz++;
	}
	return wstr;
}

int vmsBtDownloadManager::get_CurrentTaskProgress()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_pDownload == NULL)
		return -1;
	return m_pDownload->get_CurrentTaskProgress ();
}

void vmsBtDownloadManager::SaveBtDownloadState_Pieces()
{
	assert (m_pTorrent != NULL);
	if (!m_pTorrent)
		return;
	int ns = m_pTorrent->get_PieceCount ();
	bool *pbPieces = (bool*)_alloca (get_PieceCount () * sizeof (bool));
	int nCompleted = 0;
	int nRetSize = m_pDownload->get_PiecesProgressMap (pbPieces, &nCompleted);
	vmsBtDownloadStateEx s= get_State ();
	if (s != BTDSE_DOWNLOADING)
		s = s;
	if (nRetSize == ns)
	{
		m_info.vPieces.resize (ns);
		for (int i = 0; i < ns; i++)
			m_info.vPieces [i] = pbPieces [i];

		setDirty();
	}
	else if (ns == nCompleted)
	{
		
		
		m_info.vPieces.assign (ns, true);
		setDirty();
	}
}

void vmsBtDownloadManager::GetSectionsInfo(std::vector <vmsSectionInfo> &v)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	
	if (m_pDownload && IsDownloadStatCanBeRead () && get_State () == BTDSE_DOWNLOADING)
		SaveBtDownloadState_Pieces ();

	assert (!m_info.vPieces.empty ());

	v.clear ();

	vmsSectionInfo sect;

	UINT64 uTotal = GetTotalFilesSize ();
	int ns = GetNumberOfSections ();
	if (ns == 0)
	{
		return;
	}
	UINT64 uPerPiece = uTotal / ns;

	for (int i = 0; i < ns; i++)
	{
		sect.uDStart = i * uPerPiece;
		sect.uDEnd = i == ns-1 ? uTotal : sect.uDStart + uPerPiece - 1;
		bool bPC = false;
		if (!m_info.vPieces.empty ())
			bPC = m_info.vPieces [i];
		sect.uDCurrent = bPC ? sect.uDEnd : sect.uDStart;
		v.push_back (sect);
	}
}

UINT64 vmsBtDownloadManager::get_SplittedByteCountAtBeginningOfFile()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	
	UINT64 uTotal = GetTotalFilesSize ();
	int ns = GetNumberOfSections ();
	UINT64 uPerPiece = uTotal / ns;
	
	UINT64 uRes = 0;
	bool bIDSCBR = m_pDownload && IsDownloadStatCanBeRead ();

	for (int i = 0; i < ns; i++)
	{
		if (false == (bIDSCBR ? m_pDownload->is_PieceCompleted (i) : m_info.vPieces [i]))
			break;

		uRes += uPerPiece;
	}

	return uRes;
}

fsString vmsBtDownloadManager::get_RootFolderName()
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (get_FileCount () == 1)
		return "";

	int nOffset = 0;
	
	for (int i = 0; i < get_FileCount (); i++)
	{
		fsString str = get_FileName (i);
		if (nOffset == 0)
		{
			LPCSTR psz = strchr (str, '\\');
			if (psz)
				nOffset = psz - str + 1;
			else
				break;
		}
		else
		{
			LPCSTR psz = strchr (str, '\\');
			int nOffset2 = 0;
			if (psz)
				nOffset2 = psz - str + 1;
			if (nOffset2 != nOffset || strnicmp (str, get_FileName (i-1), nOffset))
			{
				nOffset = 0;
				break;
			}
		}
	}

	if (nOffset == 0)
		return "";

	char sz [MY_MAX_PATH];
	lstrcpyn (sz, get_FileName (0), nOffset);
	return sz;	
}

BOOL vmsBtDownloadManager::isSeeding()
{
	vmsBtDownloadStateEx enState = get_State ();
	return enState == BTDSE_SEEDING || enState == BTDSE_FINISHED;
}

void vmsBtDownloadManager::GetFilesTree(fs::ListTree <vmsFile> *tree)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	int cFiles = get_FileCount ();

	if (cFiles == 0)
	{
		
		return;
	}

	for (int i = 0; i < cFiles; i++)
	{
		fsString strFile = get_FileName (i);
		addFileToTree (tree, strFile, i);
	}

	tree->GetData ().nIndex = -1;
	calculateFoldersSizesInTree (tree);
}

void vmsBtDownloadManager::addFileToTree(fs::ListTree <vmsFile> *pTree, LPCSTR pszFile, int nFileIndex)
{
	fsString strFilePart;
	while (*pszFile && *pszFile != '\\' && *pszFile != '/')
		strFilePart += *pszFile++;
	if (*pszFile)
		pszFile++;

	fs::ListTree <vmsFile> *ptLeaf = pTree;

	for (int i = 0; i < pTree->GetLeafCount (); i++)
	{
		if (lstrcmpi (pTree->GetLeaf (i)->GetData ().strName, strFilePart) == 0)
		{
			ptLeaf = pTree->GetLeaf (i);
			break;
		}
	}

	if (*pszFile)
	{
		if (ptLeaf == pTree)
		{
			vmsFile file; 
			file.strName = strFilePart;
			file.nIndex = -1;
			file.nFileSize = _UI64_MAX;
			ptLeaf = pTree->AddLeaf (file);
		}

		addFileToTree (ptLeaf, pszFile, nFileIndex);
	}
	else
	{
		vmsFile file; 
		file.strName = strFilePart;
		file.nIndex = nFileIndex;
		file.nFileSize = get_FileSize (nFileIndex);
		file.iPriority = m_info.vFilesPriorities.size () ? m_info.vFilesPriorities [nFileIndex] : 1;
		ptLeaf->AddLeaf (file);
	}
}

void vmsBtDownloadManager::calculateFoldersSizesInTree(fs::ListTree <vmsFile> *pTree)
{
	ASSERT (pTree->GetData ().nIndex == -1);
	if (pTree->GetData ().nIndex != -1)
		return;
	
	pTree->GetData ().nFileSize = 0;

	for (int i = 0; i < pTree->GetLeafCount (); i++)
	{
		if (pTree->GetLeaf (i)->GetData ().nFileSize == _UI64_MAX)
			calculateFoldersSizesInTree (pTree->GetLeaf (i));
		pTree->GetData ().nFileSize += pTree->GetLeaf (i)->GetData ().nFileSize;
	}
}

BOOL vmsBtDownloadManager::LoadTorrent(LPCSTR pszFile, BOOL isMagnet, vmsBtFile* tempTorrent)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (m_pTorrent)
		return TRUE;
	
	m_pTorrent = _BT.CreateTorrentFileObject ();
	if (m_pTorrent == NULL)
		return FALSE;

	BOOL result = FALSE;
	if (isMagnet)
	{
		if (tempTorrent == NULL)
		{
			result = m_pTorrent->LoadFromMagnetLink(pszFile);
		}
		else
		{
			result = m_pTorrent->LoadFromMagnetMetadata(tempTorrent);
		}
	}
	else
	{
		result = m_pTorrent->LoadFromFile(pszFile);
	}
	
	if (FALSE == result)
	{
		m_pTorrent->Release ();
		m_pTorrent = NULL;
		return FALSE;
	}

	setDirty();
	return TRUE;
}

void vmsBtDownloadManager::PrioritizeFiles(int *piPriorities)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	int cFiles = get_FileCount ();
	bool bWasEmpty = m_info.vFilesPriorities.size () == 0;

	for (int i = 0; i < cFiles; i++)
	{
		if (bWasEmpty)
			m_info.vFilesPriorities.push_back ((BYTE)piPriorities [i]);
		else
			m_info.vFilesPriorities [i] = (BYTE)piPriorities [i];
	}

	setDirty();

	ApplyNewFilesPriorities ();
}

void vmsBtDownloadManager::CalculateFilesPieces()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	if (m_vFilesPieces.size ())
		return;
	int cFiles = get_FileCount ();
	UINT64 pos = 0;
	UINT64 piece_size = get_PieceSize ();
	for (int i = 0; i < cFiles; i++)
	{
		UINT64 file_size = get_FileSize (i);
		m_vFilesPieces.push_back (_inc_FilePieces (
			(int)(pos / piece_size), (int)((pos+file_size-1) / piece_size)));
		pos += file_size;
	}
}

void vmsBtDownloadManager::getPartialDownloadProgress(UINT64 *pnBytesToDownload, UINT64 *pnBytesDownloaded)
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_info.vFilesPriorities.size () == 0)
	{
		*pnBytesDownloaded = GetDownloadedBytesCount ();
		*pnBytesToDownload = GetTotalFilesSize ();
		return;
	}

	fsTicksMgr now;
	if (now - m_cache.nPartial_time < 1000)
	{
		*pnBytesDownloaded = m_cache.nPartial_BytesDownloaded;
		*pnBytesToDownload = m_cache.nPartial_BytesToDownload;
		return;
	}

	*pnBytesDownloaded = *pnBytesToDownload = 0;

	CalculateFilesPieces ();

	bool *pbPieces = (bool*)_alloca (get_PieceCount () * sizeof (bool));
	int piece_size = get_PieceSize ();

	int cPieces = 0;
	if (m_pDownload && IsDownloadStatCanBeRead ())
		cPieces = m_pDownload->get_PiecesProgressMap (pbPieces, NULL);
	if (!cPieces)
	{
		cPieces = get_PieceCount ();
		assert (cPieces != 0);
		for (size_t i = 0; i < m_info.vPieces.size (); i++)
			pbPieces [i] = m_info.vPieces [i];
	}

	int last_piece = -1;
	for (size_t i = 0; i < m_info.vFilesPriorities.size (); i++)
	{
		if (m_info.vFilesPriorities [i] == 0)
			continue;

		_inc_FilePieces &fp = m_vFilesPieces [i];
		
		for (int j = fp.nStartPiece; j <= fp.nEndPiece; j++)
		{
			if (j == last_piece)
				continue;
			if (j == cPieces - 1)
				piece_size = (int) (GetTotalFilesSize () % piece_size);
			*pnBytesToDownload += piece_size;
			if (pbPieces [j])
				*pnBytesDownloaded += piece_size;
			last_piece = j;
		}
	}

	m_cache.nPartial_BytesDownloaded = *pnBytesDownloaded;
	m_cache.nPartial_BytesToDownload = *pnBytesToDownload;
	m_cache.nPartial_time.Now ();
}

int vmsBtDownloadManager::getFilePriority(int nFileIndex)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_info.vFilesPriorities.empty () ? 1 : m_info.vFilesPriorities [nFileIndex];
}

void vmsBtDownloadManager::setFilePriority(int nFileIndex, int iPriority, bool bApply)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	if (m_info.vFilesPriorities.empty ())
	{
		if (iPriority == 1)
			return;
		for (int i = get_FileCount () - 1; i >= 0; i--)
			m_info.vFilesPriorities.push_back (1);
	}

	ASSERT (iPriority >= 0 && iPriority <= 7);

	m_info.vFilesPriorities [nFileIndex] = (BYTE)iPriority;

	setDirty();

	if (bApply)
		ApplyNewFilesPriorities ();
}

void vmsBtDownloadManager::ApplyNewFilesPriorities()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	if (m_info.bDone && m_info.fPercentDone == 100.0f)
		return; 

	if (isSeeding ())
	{
		StopSeeding ();
		m_info.bDone = FALSE;
		setDirty();
		StartDownloading ();
	}
	else if (m_pDownload)
	{
		int *pi = new int [m_info.vFilesPriorities.size ()];
		for (size_t i = 0; i < m_info.vFilesPriorities.size (); i++)
			pi [i] = m_info.vFilesPriorities [i];
		m_pDownload->PrioritizeFiles (pi);
		delete [] pi;
	}
	if (m_info.bDone)
	{
		m_info.bDone = FALSE;
		setDirty();
		StartDownloading ();		
	}
	
	
	if (!m_info.strOutputPath.IsEmpty ())
	{
		USES_CONVERSION;
		std::wstring wstrSrcPath = A2W (m_info.strOutputPath);
		if (wstrSrcPath [wstrSrcPath.length () - 1] != '\\')
			wstrSrcPath += '\\';
		
		for (int i = 0; i < (int)m_info.vFilesPriorities.size (); i++)
		{
			std::wstring wstr = wstrSrcPath; wstr += get_FileNameW (i);
			DWORD dw = GetFileAttributesW (wstr.c_str ());
			if (dw != DWORD (-1))
			{
				if (m_info.vFilesPriorities [i] == 0 && (dw & FILE_ATTRIBUTE_HIDDEN) == 0)
					SetFileAttributesW (wstr.c_str (), dw | FILE_ATTRIBUTE_HIDDEN);
				else if (m_info.vFilesPriorities [i] != 0 && (dw & FILE_ATTRIBUTE_HIDDEN) != 0)
					SetFileAttributesW (wstr.c_str (), dw & (~FILE_ATTRIBUTE_HIDDEN));
			}
		}
	}
}

bool vmsBtDownloadManager::isSeedingEnabled() const
{
	return (m_info.dwFlags & BTDF_DISABLE_SEEDING) == 0;
}

void vmsBtDownloadManager::setRequiredRatio(float f)
{
	m_fRequiredRatio = f;
	setDirty();
}

float vmsBtDownloadManager::getRequiredRatio()
{
	return m_fRequiredRatio;
}

void vmsBtDownloadManager::Shutdown()
{
	WaitForSingleObject (m_hmxStaticObj, INFINITE);
	if (m_htDlds)
	{
		if (!m_hevStopDldsThread)
		{
			ReleaseMutex (m_hmxStaticObj);
			return;
		}
		SetEvent (m_hevStopDldsThread);
		WaitForSingleObject (m_htDlds, INFINITE);
		ResetEvent (m_hevStopDldsThread);
		CloseHandle (m_htDlds);
		m_htDlds = NULL;
	}
	ReleaseMutex (m_hmxStaticObj);
	vmsAUTOLOCKSECTION_PTR (m_pcsvpDlds);
	if (m_pvpDlds)
	{
		while (!m_pvpDlds->empty ())
		{
			vmsBtDownloadManager *pDld = m_pvpDlds->at (0);
			m_pvpDlds->erase (m_pvpDlds->begin ());
			pDld->DeleteBtDownload ();
		}
	}
}

DWORD WINAPI vmsBtDownloadManager::_threadDlds(LPVOID)
{
	while (WaitForSingleObject (m_hevStopDldsThread, 30*1000) == WAIT_TIMEOUT)
	{
		EnterCriticalSection (m_pcsvpDlds);

		for (size_t i = 0; i < m_pvpDlds->size (); i++)
		{
			if (m_pvpDlds->at (i)->isSeeding () &&
					m_pvpDlds->at (i)->getRequiredRatio () && 
					m_pvpDlds->at (i)->getRatio () >= m_pvpDlds->at (i)->getRequiredRatio ())
			{
				vmsBtDownloadManager *dld = m_pvpDlds->at (i);
				dld->StopSeeding ();
			}
		}

		LeaveCriticalSection (m_pcsvpDlds);
	}

	return 0;
}

void vmsBtDownloadManager::DeleteFromDldsList()
{
	vmsAUTOLOCKSECTION_PTR (m_pcsvpDlds);

	for (size_t i = 0; i < m_pvpDlds->size (); i++)
	{
		if (m_pvpDlds->at (i) == this)
		{
			m_pvpDlds->erase (m_pvpDlds->begin () + i);
			break;
		}
	}
}

void vmsBtDownloadManager::AddToDldsList()
{
	vmsAUTOLOCKSECTION_PTR (m_pcsvpDlds);

	for (size_t i = 0; i < m_pvpDlds->size (); i++)
	{
		if (m_pvpDlds->at (i) == this)
			return;
	}

	m_pvpDlds->push_back (this);
}

void vmsBtDownloadManager::setLastTracker(LPCSTR pszUrl)
{
	vmsAUTOLOCKSECTION (m_csMisc);
	m_info.strLastTracker = pszUrl;
	setDirty();
}

void vmsBtDownloadManager::setLastTrackerStatus(LPCSTR pszStatus)
{
	vmsAUTOLOCKSECTION (m_csMisc);
	m_strLastTrackerStatus = pszStatus;
}

std::string vmsBtDownloadManager::getLastTrackerStatus(void)
{
	vmsAUTOLOCKSECTION (m_csMisc);
	return m_strLastTrackerStatus;
}

void vmsBtDownloadManager::getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	vmsAUTOLOCKSECTION (m_csMisc);

	if (m_pDownload && pb == NULL)
		SaveBtDownloadState (false);

	#define CHECK_SIZE(need) {if (pb != NULL && *pdwSize < (UINT)(pb + need - pbOld)) goto _lSizeErr;}

	LPBYTE pbOld = pb;

	DWORD dwNeedSize = 0;

	dwNeedSize += sizeof (DWORD); 
	dwNeedSize += sizeof (int) + m_info.strOutputPath.GetLength ();
	dwNeedSize += sizeof (int) + m_info.strTorrentUrl.GetLength ();
	dwNeedSize += sizeof (int) + m_info.strTrackerUser.GetLength ();
	dwNeedSize += sizeof (int) + m_info.strTrackerPassword.GetLength ();

	DWORD dwTorrentSize = 0;
	if (FALSE == m_pTorrent->get_TorrentBuffer (NULL, 0, &dwTorrentSize))
		return;
	dwNeedSize += dwTorrentSize + sizeof (DWORD);

	if (dwTorrentSize)
	{
		dwNeedSize += sizeof (float) * get_FileCount (); 
		dwNeedSize += sizeof (int) + m_info.strLastTracker.GetLength ();
		dwNeedSize += sizeof (m_info.nUploadedBytes);
		dwNeedSize += sizeof (m_info.fShareRating);
		dwNeedSize += sizeof (m_info.nWastedBytes);
		dwNeedSize += sizeof (m_info.fPercentDone);
		dwNeedSize += sizeof (m_info.bDone);
		dwNeedSize += sizeof (int) + sizeof (BYTE) * m_info.vPieces.size ();
		dwNeedSize += sizeof (m_info.nDownloadedBytes);
		dwNeedSize += sizeof (int) + sizeof (BYTE) * m_info.vFilesPriorities.size ();
		dwNeedSize += m_info.dwFastResumeDataSize + sizeof (DWORD);
	}
	
	dwNeedSize += sizeof (m_fRequiredRatio);
	dwNeedSize += sizeof (m_uLowSpeedMaxTime) + sizeof (m_uTrafficLimit);
	
	if (pb == NULL)
	{
		*pdwSize = dwNeedSize;
		return;
	}

	int i;

	
	i = m_info.strTorrentUrl.GetLength ();
	CHECK_SIZE (sizeof (int));
	CopyMemory (pb, &i, sizeof (int));
	pb += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (pb, m_info.strTorrentUrl, i);
	pb += i;

	
	i = m_info.strOutputPath.GetLength ();
	CHECK_SIZE (sizeof (int));
	CopyMemory (pb, &i, sizeof (int));
	pb += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (pb, m_info.strOutputPath, i);
	pb += i;

	
	i = m_info.strTrackerUser.GetLength ();
	CHECK_SIZE (sizeof (int));
	CopyMemory (pb, &i, sizeof (int));
	pb += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (pb, m_info.strTrackerUser, i);
	pb += i;

	i = m_info.strTrackerPassword.GetLength ();
	CHECK_SIZE (sizeof (int));
	CopyMemory (pb, &i, sizeof (int));
	pb += sizeof (int);
	CHECK_SIZE (i);
	CopyMemory (pb, m_info.strTrackerPassword, i);
	pb += i;

	
	CHECK_SIZE (sizeof (DWORD));
	DWORD dw = *pdwSize - (pb - pbOld - sizeof (DWORD));
	if (dw < dwTorrentSize)
		goto _lSizeErr;
	if (dwTorrentSize)
	{
		if (FALSE == m_pTorrent->get_TorrentBuffer (pb + sizeof (DWORD), dw, &dw))
			goto _lSizeErr;
		*((LPDWORD)pb) = dw;
		pb += sizeof (DWORD) + dw;
	}
	else
	{
		*((LPDWORD)pb) = 0;
		pb += sizeof (DWORD);
	}

	if (dwTorrentSize)
	{
		
		CHECK_SIZE (sizeof (DWORD));
		*((LPDWORD)pb) = m_info.dwFastResumeDataSize;
		pb += sizeof (DWORD);
		if (m_info.dwFastResumeDataSize != 0)
		{
			CHECK_SIZE (m_info.dwFastResumeDataSize);
			CopyMemory (pb, m_info.pbFastResumeData, m_info.dwFastResumeDataSize);
			pb += m_info.dwFastResumeDataSize;
		}

		
		CHECK_SIZE (get_FileCount () * sizeof (float));
		ASSERT (m_info.pfProgress != NULL);
		CopyMemory (pb, m_info.pfProgress, get_FileCount () * sizeof (float));
		pb += get_FileCount () * sizeof (float);

		i = m_info.strLastTracker.GetLength ();
		CHECK_SIZE (sizeof (int));
		CopyMemory (pb, &i, sizeof (int));
		pb += sizeof (int);
		CHECK_SIZE (i);
		CopyMemory (pb, m_info.strLastTracker, i);
		pb += i;

		UINT64 nUploadedBytes; nUploadedBytes = get_TotalUploadedByteCount ();
		CHECK_SIZE (sizeof (nUploadedBytes));
		CopyMemory (pb, &nUploadedBytes, sizeof (nUploadedBytes));
		pb += sizeof (nUploadedBytes);

		CHECK_SIZE (sizeof (m_info.fShareRating));
		CopyMemory (pb, &m_info.fShareRating, sizeof (m_info.fShareRating));
		pb += sizeof (m_info.fShareRating);

		UINT64 nWastedBytes; nWastedBytes = get_WastedByteCount ();
		CHECK_SIZE (sizeof (nWastedBytes));
		CopyMemory (pb, &nWastedBytes, sizeof (nWastedBytes));
		pb += sizeof (nWastedBytes);

		CHECK_SIZE (sizeof (m_info.fPercentDone));
		CopyMemory (pb, &m_info.fPercentDone, sizeof (m_info.fPercentDone));
		pb += sizeof (m_info.fPercentDone);

		CHECK_SIZE (sizeof (m_info.bDone));
		CopyMemory (pb, &m_info.bDone, sizeof (m_info.bDone));
		pb += sizeof (m_info.bDone);

		i = m_info.vPieces.size ();
		CHECK_SIZE (sizeof (int));
		CopyMemory (pb, &i, sizeof (int));
		pb += sizeof (int);
		CHECK_SIZE (i);
		int j;
		for (j = 0; j < i; j++)
			*pb++ = m_info.vPieces [j];

		CHECK_SIZE (sizeof (m_info.nDownloadedBytes));
		CopyMemory (pb, &m_info.nDownloadedBytes, sizeof (m_info.nDownloadedBytes));
		pb += sizeof (m_info.nDownloadedBytes);

		i = m_info.vFilesPriorities.size ();
		CHECK_SIZE (sizeof (int));
		CopyMemory (pb, &i, sizeof (int));
		pb += sizeof (int);
		CHECK_SIZE (i);
		for (j = 0; j < i; j++)
			*pb++ = m_info.vFilesPriorities [j];
	}

	

	CHECK_SIZE (sizeof (m_fRequiredRatio));
	*((float*)pb) = m_fRequiredRatio;
	pb += sizeof (m_fRequiredRatio);
	
	CHECK_SIZE (sizeof (m_info.dwFlags));
	*((LPDWORD)pb) = m_info.dwFlags;
	pb += sizeof (m_info.dwFlags);

	CHECK_SIZE (sizeof (m_uLowSpeedMaxTime));
	*((LPDWORD)pb) = m_uLowSpeedMaxTime;
	pb += sizeof (m_uLowSpeedMaxTime);

	CHECK_SIZE (sizeof (m_uTrafficLimit));
	*((LPDWORD)pb) = m_uTrafficLimit;
	pb += sizeof (m_uTrafficLimit);

	*pdwSize = pb - pbOld;

	return;

_lSizeErr:
	assert ("not enough buffer" == 0);
	getObjectItselfStateBuffer (NULL, pdwSize, false);
	return;
}

void vmsBtDownloadManager::setOutputPath (LPCTSTR ptszPath)
{
	assert (ptszPath != NULL);
	assert (m_pDownload == NULL);
	if (m_pDownload)
		return;
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	m_info.strOutputPath = ptszPath;
	setDirty();
}

bool vmsBtDownloadManager::isHashEqual (const vmsBtDownloadManager *pMgr2)
{
	BYTE abHash1 [100]; BYTE abHash2 [100];
	DWORD dwSize = sizeof (abHash1);

	if (!getInfoHash2 (abHash1, &dwSize))
		return false;

	if (!getInfoHash2 (abHash2, &dwSize))
		return false;

	return 0 == memcmp (abHash1, abHash2, dwSize);
}

bool vmsBtDownloadManager::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	vmsAUTOLOCKSECTION (m_csTorrentFile);

	ASSERT (dwVer >= 16);

	LPBYTE pB = pb;

	int i;
	char sz [10000];

	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	pB += i;
	m_info.strTorrentUrl = sz;
	
	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	m_info.strOutputPath = sz;
	pB += i;

	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	pB += i;
	m_info.strTrackerUser = sz;

	CopyMemory (&i, pB, sizeof (int));
	pB += sizeof (int);
	CopyMemory (sz, pB, i);
	sz [i] = 0;
	pB += i;
	m_info.strTrackerPassword = sz;

	m_pTorrent = _BT.CreateTorrentFileObject ();
	if (m_pTorrent == NULL)
		return false;

	DWORD dwTorrentSize = *((LPDWORD)pB);

	if (!dwTorrentSize)
	{
		if (_tcsstr (m_info.strTorrentUrl, _T("magnet:")) == m_info.strTorrentUrl) {
			m_pTorrent->LoadFromMagnetLink(m_info.strTorrentUrl);
		}
		else {
			assert (!"invalid torrent type");
			return false;
		}
	}
	else
	{
		LPBYTE pbTorrent = pB + sizeof (DWORD);
		if (FALSE == m_pTorrent->LoadFromBuffer (pbTorrent, dwTorrentSize))
			return false;
	}

	pB += sizeof (DWORD) + dwTorrentSize;

	if (dwTorrentSize)
	{
		m_info.dwFastResumeDataSize = *((LPDWORD)pB);
		pB += sizeof (DWORD);
		SAFE_DELETE_ARRAY (m_info.pbFastResumeData);
		if (m_info.dwFastResumeDataSize)
		{
			m_info.pbFastResumeData = new BYTE [m_info.dwFastResumeDataSize];
			CopyMemory (m_info.pbFastResumeData, pB, m_info.dwFastResumeDataSize);
			pB += m_info.dwFastResumeDataSize;
		}

		m_info.pfProgress = new float [get_FileCount () * sizeof (float)];
		CopyMemory (m_info.pfProgress, pB, get_FileCount () * sizeof (float));
		pB += get_FileCount () * sizeof (float);

		CopyMemory (&i, pB, sizeof (int));
		pB += sizeof (int);
		CopyMemory (sz, pB, i);
		sz [i] = 0;
		pB += i;
		m_info.strLastTracker = sz;

		CopyMemory (&m_info.nUploadedBytes, pB, sizeof (m_info.nUploadedBytes));
		pB += sizeof (m_info.nUploadedBytes);

		CopyMemory (&m_info.fShareRating, pB, sizeof (m_info.fShareRating));
		pB += sizeof (m_info.fShareRating);

		CopyMemory (&m_info.nWastedBytes, pB, sizeof (m_info.nWastedBytes));
		pB += sizeof (m_info.nWastedBytes);

		CopyMemory (&m_info.fPercentDone, pB, sizeof (m_info.fPercentDone));
		pB += sizeof (m_info.fPercentDone);

		CopyMemory (&m_info.bDone, pB, sizeof (m_info.bDone));
		pB += sizeof (m_info.bDone);

		CopyMemory (&i, pB, sizeof (int));
		pB += sizeof (int);
		m_info.vPieces.clear ();
		while (i--)
			m_info.vPieces.push_back ((*pB++) != 0);

		CopyMemory (&m_info.nDownloadedBytes, pB, sizeof (m_info.nDownloadedBytes));
		pB += sizeof (m_info.nDownloadedBytes);

		CopyMemory (&i, pB, sizeof (int));
		pB += sizeof (int);
		m_info.vFilesPriorities.clear ();
		while (i--)
			m_info.vFilesPriorities.push_back (*pB++);
	}

	m_fRequiredRatio = *((float*)pB);
	pB += sizeof (float);	

	m_info.dwFlags = *((LPDWORD)pB);
	pB += sizeof (DWORD);

	if (m_info.dwFlags & BTDF_USE_PORTABLE_DRIVE)
		m_info.strOutputPath [0] = vmsGetExeDriveLetter ();

	m_uLowSpeedMaxTime = *((LPUINT)pB);
	pB += sizeof (UINT);

	m_uTrafficLimit = *((LPUINT)pB);
	pB += sizeof (UINT);

	*pdwSize = pB - pb;

	if (!_App.NonUtf8NameFixed ())
		FixDir (m_info.strOutputPath, m_pTorrent);

	if ((m_info.dwFlags & BTDF_DISABLE_SEEDING) == 0 && m_info.bDone)
		EnableSeeding (TRUE);

	return true;
}

UINT64 vmsBtDownloadManager::getSpeed(bool bOfDownload)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (!m_pDownload)
		return 0;
	return bOfDownload ? m_pDownload->GetDownloadSpeedIncludingServiceTraffic () : 
		m_pDownload->GetDownloadSpeedIncludingServiceTraffic ();
}

void vmsBtDownloadManager::setSpeedLimit(bool bOfDownload, UINT64 uLimit)
{
	int iLimit = uLimit == UINT64_MAX ? -1 : (int)uLimit;
	vmsAUTOLOCKSECTION (m_csDownload);
	if (m_pDownload)
	{
		if (bOfDownload)
			m_pDownload->SetDownloadLimit ((int)iLimit);
		else
			m_pDownload->SetUploadLimit ((int)iLimit);
	}
}

UINT64 vmsBtDownloadManager::getSpeedLimit(bool bOfDownload)
{
	vmsAUTOLOCKSECTION (m_csDownload);
	if (!m_pDownload)
		return UINT64_MAX;
	int iLimit = bOfDownload ? m_pDownload->GetDownloadLimit () : m_pDownload->GetUploadLimit ();
	return iLimit == -1 ? UINT64_MAX : (UINT64)iLimit;
}

bool vmsBtDownloadManager::isRequiresTraffic(bool bForDownload)
{
	return bForDownload ? !IsDone () : true;
}

vmsBtFile* vmsBtDownloadManager::GetTorrentFile()
{
	return m_pTorrent;
}

BOOL vmsBtDownloadManager::DownloadMagnetMetadata(LPCTSTR pszMagnetLink, LPCTSTR pszOutputPath)
{
	if (pszMagnetLink != _T("") || pszOutputPath != _T(""))
	{
		BOOL createResult = CreateByMagnetLink(pszMagnetLink, pszOutputPath);
		if (createResult == FALSE)
		{
			return FALSE;
		}
	}
	m_downloadMagnetMetadata = true;
	return (StartDownloading() == IR_SUCCESS);
}

BOOL vmsBtDownloadManager::checkMagnetMetadata()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	vmsAUTOLOCKSECTION (m_csTorrentFile);
	if (m_pDownload->is_HandleValid() && m_pTorrent->IsValid() == FALSE)
	{
		if (m_pDownload->SetMagnetMetadata(m_pTorrent))
		{
			const int nFiles = get_FileCount();
			m_info.pfProgress = new float [nFiles * sizeof (float)];
			for (int i = nFiles - 1; i >= 0; i--)
				m_info.pfProgress [i] = 0;

			return TRUE;
		}
		return FALSE;
	}
	else if (m_pTorrent->IsValid())
	{
		return TRUE;
	}
	return FALSE;
}
void vmsBtDownloadManager::SetStateError(vmsBtDownloadErrorState err)
{
	if (err != BTDES_NO_ERROR)
	{
		StopDownloading();
	}
	m_errorState = err;
}