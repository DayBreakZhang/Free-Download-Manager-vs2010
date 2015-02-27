/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBtDownloadImpl.h"
#include "vmsBtSessionImpl.h"
#include "vmsBtDownloadPeerInfoListImpl.h"
#include "vmsBtDownloadPeerInfoImpl.h"

#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

vmsBtDownloadImpl::vmsBtDownloadImpl(
	const libtorrent::torrent_handle& handle, 
	vmsBtFileImplPtr spTorrent, 
	const std::string& strOutputPath)
	: m_handle(handle)
	, m_spTorrent(spTorrent)
	, m_strOutputPath(strOutputPath)
{
	m_iDownloadSpeedLimit = -1;
	m_iUploadSpeedLimit = -1;
	m_peerList.m_dld = this;
	m_cRefs = 0;
	m_dwDob_status = 0;
	
}

vmsBtDownloadImpl::~vmsBtDownloadImpl(void)
{
}

libtorrent::torrent_handle& vmsBtDownloadImpl::GetHandle()
{
	return m_handle;
}

std::string vmsBtDownloadImpl::GetOutputPath()
{
	return m_strOutputPath;
}

vmsBtFileImplPtr vmsBtDownloadImpl::GetTorrentImpl()
{
	return m_spTorrent;
}

vmsBtDownloadState vmsBtDownloadImpl::GetState ()
{
	if (m_handle.is_valid () == false)
		return BTDS_QUEUED;

	switch (m_handle.status ().state)
	{
	case libtorrent::torrent_status::queued_for_checking:
		return BTDS_QUEUED;

	case libtorrent::torrent_status::checking_files:
		return BTDS_CHECKING_FILES;

	case libtorrent::torrent_status::checking_resume_data:
		return BTDS_CHECKING_RESUME_DATA;

	case libtorrent::torrent_status::downloading:
		return BTDS_DOWNLOADING;

	case libtorrent::torrent_status::finished:
		return BTDS_FINISHED;

	case libtorrent::torrent_status::seeding:
		return BTDS_SEEDING;

	case libtorrent::torrent_status::allocating:
		return BTDS_ALLOCATING;

	case libtorrent::torrent_status::downloading_metadata:
		return BTDS_DOWNLOADING_METADATA;

	default:
		assert (FALSE);
		return BTDS_LT_UNKNOWN_STATE;
	}
}

BOOL vmsBtDownloadImpl::IsPaused ()
{
	if (m_handle.is_valid () == false)
		return FALSE;
	return m_handle.status ().paused;
}

void vmsBtDownloadImpl::get_SavePath (LPSTR pszRes)
{
	if (m_handle.is_valid () == false) 
	{
		*pszRes = 0;
		return;
	}
	strcpy (pszRes, m_handle.save_path ().string ().c_str ());
}

float vmsBtDownloadImpl::get_PercentDone ()
{
	if (m_handle.is_valid () == false)
		return 0;

	return (float)
		((double)get_TotalDownloadedBytesCount () / m_spTorrent->get_TotalFilesSize () * 100.0);
}

int vmsBtDownloadImpl::get_PiecesProgressMap (bool* pbPieces, int *pnCompletedPieces)
{
	if (m_handle.is_valid () == false) {
		if (pnCompletedPieces != NULL)
			*pnCompletedPieces = 0;
		return 0;
	}

	if (pnCompletedPieces != NULL)
		*pnCompletedPieces = status ().num_pieces;

	libtorrent::bitfield pieces = status ().pieces;
	
	if (pbPieces && !pieces.empty())
	{
		assert (pieces.size () == m_spTorrent->get_PieceCount ());
		for (int i = 0; i < pieces.size (); i++)
			pbPieces [i] = pieces[i];
	}

	return pieces.empty() ? 0 : pieces.size ();
}

int vmsBtDownloadImpl::get_DownloadConnectionCount ()
{
	if (m_handle.is_valid () == false)
		return 0;

	std::vector <libtorrent::peer_info> v;
	m_handle.get_peer_info (v);

	int n = 0;

	for (size_t i = 0; i < v.size (); i++)
	{
		if ((v [i].flags & libtorrent::peer_info::interesting) != 0 && 
				(v [i].flags & libtorrent::peer_info::queued) == 0)
			n++;
	}

	return n; 
}

UINT64 vmsBtDownloadImpl::get_TotalDownloadedBytesCount ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return status ().total_done;
}

UINT vmsBtDownloadImpl::GetDownloadSpeed ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return (UINT)status ().download_payload_rate;
}

UINT vmsBtDownloadImpl::GetUploadSpeed ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return (UINT)status ().upload_payload_rate;
}

UINT vmsBtDownloadImpl::GetDownloadSpeedIncludingServiceTraffic ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return (UINT)status ().download_rate;
}

UINT vmsBtDownloadImpl::GetUploadSpeedIncludingServiceTraffic ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return (UINT)status ().upload_rate;
}

void vmsBtDownloadImpl::Pause ()
{
	if (m_handle.is_valid () == false)
		return;
	m_handle.pause ();
}

void vmsBtDownloadImpl::Resume ()
{
	if (m_handle.is_valid () == false)
		return;
	m_handle.resume ();
}

void vmsBtDownloadImpl::SetDownloadLimit (int limit)
{
	if (!limit)
		limit = 1; 
	if (m_handle.is_valid () == false)
		return;
	m_handle.set_download_limit (m_iDownloadSpeedLimit = limit);
}

int  vmsBtDownloadImpl::GetDownloadLimit ()
{
	return m_iDownloadSpeedLimit;
}

void vmsBtDownloadImpl::SetUploadLimit (int limit)
{
	if (!limit)
		limit = 1; 
	if (m_handle.is_valid () == false)
		return;
	m_handle.set_upload_limit (m_iUploadSpeedLimit = limit);
}

int  vmsBtDownloadImpl::GetUploadLimit ()
{
	return m_iUploadSpeedLimit;
}

vmsBtFile* vmsBtDownloadImpl::get_Torrent ()
{
	return m_spTorrent;
}

int vmsBtDownloadImpl::get_ConnectionCount ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return status ().num_peers;
}

void vmsBtDownloadImpl::set_ConnectionLimit (int limit)
{
	if (m_handle.is_valid () == false)
		return;
	m_handle.set_max_connections (limit);
}

BOOL vmsBtDownloadImpl::get_FastResumeData (LPBYTE pbRes, DWORD dwSize, DWORD *pdwDataSize)
{
	if (m_handle.is_valid () == false)
		return FALSE;

try{

	libtorrent::entry e = m_handle.write_resume_data ();

	std::vector <char> v;
	libtorrent::bencode (std::back_inserter (v), e);

	*pdwDataSize = v.size ();

	if (pbRes == NULL)
		return TRUE;

	if (dwSize < v.size ())
		return FALSE;

	if (!v.empty ())
		CopyMemory (pbRes, &v[0], v.size ());

	return TRUE;

}catch (...) {*pdwDataSize = 0; return FALSE;}
}

void vmsBtDownloadImpl::set_TrackerLogin (LPCSTR pszUser, LPCSTR pszPassword)
{
	if (m_handle.is_valid () == false)
		return;
	m_handle.set_tracker_login (pszUser, pszPassword);
}

BOOL vmsBtDownloadImpl::MoveToFolder (LPCSTR pszNewFolder)
{
	assert (pszNewFolder);
	if (!pszNewFolder || *pszNewFolder == 0)
		return FALSE;

	if (m_handle.is_valid () == false)
		return FALSE;

	char sz [MAX_PATH] = "";
	strcpy (sz, pszNewFolder);
	LPSTR psz = sz;
	while (*++psz) if (*psz == '\\') *psz = '/';
	m_handle.move_storage (sz);

	return TRUE;
}

void vmsBtDownloadImpl::check_handle_is_valid ()
{
	if (m_handle.is_valid () == false)
		vmsBtSessionImpl::Instance ()->RestoreDownloadHandle (this);
	assert (m_handle.is_valid ());
}

int vmsBtDownloadImpl::get_NextAnnounceInterval ()
{
	if (m_handle.is_valid () == false)
		return -1;
	return m_handle.status ().next_announce.total_seconds ();
}

int vmsBtDownloadImpl::get_NextAnnounceInterval (LPCSTR pszTracker)
{
	if (!pszTracker)
		return get_NextAnnounceInterval ();
	if (m_handle.is_valid () == false)
		return -1;
	const std::vector <libtorrent::announce_entry> &v = m_handle.trackers ();
	for (size_t i = 0; i < v.size (); i++)
	{
		if (v [i].url == pszTracker)
			return v [i].next_announce_in ();
	}
	return -1;
}

bool vmsBtDownloadImpl::is_PieceCompleted (int nIndex)
{
	if (m_handle.is_valid ())
		return status().pieces.empty() ? false : m_status.pieces[nIndex];
	return false;
}

void vmsBtDownloadImpl::get_CurrentTracker (LPSTR pszRes)
{
	if (m_handle.is_valid () == false) {
		*pszRes = 0;
		return;
	}
	libtorrent::torrent_status s = m_handle.status ();
	LPCSTR pszT = s.current_tracker.c_str ();
	if ((pszT == NULL || *pszT == 0) && m_handle.get_torrent_info ().trackers ().size ())
		pszT = m_handle.get_torrent_info ().trackers () [0].url.c_str ();
	if (pszT)
		strcpy (pszRes, pszT);
	else
		*pszRes = 0;
}

UINT64 vmsBtDownloadImpl::get_TotalUploadedByteCount ()
{
	if (m_handle.is_valid () == false)
		return 0;
	return status ().total_payload_upload;
}

void vmsBtDownloadImpl::get_PeersStat (int *pnPeersConnected, int *pnSeedsTotal, int *pnLeechersTotal, int *pnSeedsConnected)
{
	if (m_handle.is_valid () == false) {
		*pnPeersConnected = 0;
		*pnSeedsTotal = 0;
		*pnLeechersTotal = 0;
		*pnSeedsConnected = 0;
		return;
	}
	libtorrent::torrent_status s = m_handle.status ();
	*pnPeersConnected = s.num_peers;
	*pnSeedsTotal = s.num_complete;
	*pnLeechersTotal = s.num_incomplete;
	*pnSeedsConnected = s.num_seeds;
}

UINT64 vmsBtDownloadImpl::get_WastedByteCount ()
{
	if (m_handle.is_valid () == false)
		return 0;
	libtorrent::torrent_status s = status ();
	return s.total_failed_bytes + s.total_redundant_bytes;
}

double vmsBtDownloadImpl::get_ShareRating ()
{
	if (m_handle.is_valid () == false)
		return 0;
	libtorrent::torrent_status s = status ();
	if (s.total_payload_download == 0)
		return 0;
	return (double)s.total_payload_upload / s.total_payload_download;
}

vmsBtDownloadPeerInfoList* vmsBtDownloadImpl::get_PeerInfoList ()
{
	if (m_handle.is_valid () == false)
		return NULL;
	return &m_peerList;
}

void vmsBtDownloadImpl::get_FileProgress (float *p)
{
	if (m_handle.is_valid () == false)
		return;

	std::vector<float> v;
	m_handle.file_progress (v);
	for (size_t i = 0; i < v.size (); i++)
		p [i] = v [i];
}

BOOL vmsBtDownloadImpl::is_HandleValid ()
{
	if (m_spTorrent->IsMagnetLink() && m_handle.is_valid ())
	{
		return m_handle.has_metadata();
	}
	return m_handle.is_valid ();
}

int vmsBtDownloadImpl::get_CurrentTaskProgress ()
{
	return (int)(m_handle.status ().progress * 100);
}

void vmsBtDownloadImpl::PrioritizeFiles (int* piPriorities)
{
	std::vector <int> v;
	int n = m_spTorrent->get_FileCount ();
	if (n)
	{
		v.resize (n);
		CopyMemory (&v[0], piPriorities, n * sizeof (int));
	}
	m_handle.prioritize_files (v);
}

libtorrent::torrent_status& vmsBtDownloadImpl::status ()
{
	if (GetTickCount () - m_dwDob_status)
	{
		vmsAUTOLOCKSECTION (m_csStatusGuard);
		m_status = m_handle.status ();
		m_dwDob_status = GetTickCount ();
	}

	return m_status;
}

void vmsBtDownloadImpl::get_CurrentTracker2 (LPSTR pszRes, DWORD dwBuffSize)
{
	if (m_handle.is_valid () == false) {
		*pszRes = 0;
		return;
	}
	
	libtorrent::torrent_status s = m_handle.status ();
	LPCSTR pszT = s.current_tracker.c_str ();
	if ((pszT == NULL || *pszT == 0) && m_handle.get_torrent_info ().trackers ().size ())
		pszT = m_handle.get_torrent_info ().trackers () [0].url.c_str ();
	if (pszT)
	{
		strncpy (pszRes, pszT, dwBuffSize - 1);
		pszRes [dwBuffSize - 1] = 0;
	}
	else
	{
		*pszRes = 0;
	}
}

BOOL vmsBtDownloadImpl::SetMagnetMetadata(vmsBtFile* torrentFile)
{
	if (m_spTorrent->IsMagnetLink() == FALSE || m_handle.has_metadata() == false)
	{
		return FALSE;
	}
	vmsBtFileImpl* torrentImpl = static_cast<vmsBtFileImpl*>(torrentFile);
	torrentImpl->m_torrent = new libtorrent::torrent_info(m_handle.get_torrent_info());
	return TRUE;
}
