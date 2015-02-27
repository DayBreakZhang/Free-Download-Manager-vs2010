/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBtSessionImpl.h"
#include "vmsBtFileImpl.h"
#include <libtorrent/alert_types.hpp>
#include <libtorrent/extensions/ut_pex.hpp>
#include <atlbase.h>
#include <magnet_uri.hpp>

bool _bWasShutdown = false;

vmsBtSession* WINAPI vmsBt_getSession ()
{
	return _bWasShutdown ? NULL : vmsBtSessionImpl::Instance ();
}

void WINAPI vmsBt_Shutdown ()
{
	_bWasShutdown = true;
	delete vmsBtSessionImpl::Instance ();
}

vmsBtSessionImpl::vmsBtSessionImpl(void)
{
	m_session.set_severity_level (libtorrent::alert::info);
	m_session.add_extension (libtorrent::create_ut_pex_plugin);
	m_session.set_max_half_open_connections (7);
	if ( m_session.is_dht_running() == TRUE ){
		m_session.stop_dht();
		m_session.add_dht_router(std::make_pair(std::string("router.bittorrent.com"), 6881));
		m_session.add_dht_router(std::make_pair(std::string("router.utorrent.com"), 6881));
		m_session.add_dht_router(std::make_pair(std::string("dht.transmissionbt.com"), 6881));
		m_session.add_dht_router(std::make_pair(std::string("dht.aelitis.com"), 6881)); 
	}

	libtorrent::session_settings ss = m_session.settings ();
	ss.active_downloads = ss.active_seeds = ss.active_limit = 100000;
	m_session.set_settings (ss);	

	setMultiTracker(true, true);
	m_bThreadRunning = true;
	m_bNeedStop = false;
	m_pfnEvHandler = NULL;
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadSession, this, 0, &dw));
	m_dwSessionStateSize = 0;
}

vmsBtSessionImpl::~vmsBtSessionImpl(void)
{
	m_bNeedStop = true;
	while (m_bThreadRunning)
		Sleep (10);
}

time_t FILETIMEToUnixTime (FILETIME filetime)
{
	long long int t = filetime.dwHighDateTime;
    t <<= 32;
    t += (unsigned long)filetime.dwLowDateTime;
    t -= 116444736000000000LL;

	return t / 10000000;
}

vmsBtDownload* vmsBtSessionImpl::CreateDownload (vmsBtFile *torrent, LPCSTR pszOutputPath, LPBYTE pbFastResumeData, DWORD dwFRDataSize, vmsBtStorageMode enStorageMode, DWORD dwFlags)
{
	char szPath [10000];
	strcpy (szPath, pszOutputPath);
	LPSTR psz = szPath;
	while (*psz)
	{
		if (*psz == '\\')
			*psz = '/';
		psz++;
	}
	if (strlen (szPath) == 2 && szPath [1] == ':')
		strcat (szPath, "/");

	try 
	{
		libtorrent::torrent_handle th;
		vmsBtFileImpl *torrentimpl = (vmsBtFileImpl*) torrent;

		libtorrent::entry entryFastResume = pbFastResumeData ? libtorrent::bdecode (pbFastResumeData, pbFastResumeData + dwFRDataSize) : libtorrent::entry ();

		try {
			if (entryFastResume.type () != libtorrent::entry::undefined_t)
				entryFastResume ["paused"] = 0;
		}catch (...) {}

		if (dwFlags & BTSCDF_FORCE_IGNORE_TIMESTAMPS)
		{		
			
			
			try {
			if (entryFastResume.type () != libtorrent::entry::undefined_t)
			{
				wchar_t wszPath [MAX_PATH] = L"";
				MultiByteToWideChar (CP_UTF8, 0, pszOutputPath, -1, wszPath, MAX_PATH-1);
				if (wszPath [wcslen (wszPath) - 1] != '\\')
					wcscat (wszPath, L"\\");

				libtorrent::entry::list_type &fl = entryFastResume ["file sizes"].list();
				
				libtorrent::entry::list_type::iterator eFRi = fl.begin ();
				
				libtorrent::torrent_info::file_iterator tiFi = torrentimpl->m_torrent->begin_files ();

				wchar_t wszFile [MAX_PATH];
				wcscpy (wszFile, wszPath);
				int nPathLen = wcslen (wszPath);

				for (; tiFi != torrentimpl->m_torrent->end_files (); tiFi++, eFRi++)
				{
					wszFile [nPathLen] = 0; 
					MultiByteToWideChar (CP_UTF8, 0, tiFi->path.string ().c_str (), -1, wszFile + nPathLen, MAX_PATH - nPathLen);
					WIN32_FILE_ATTRIBUTE_DATA wfad;
					if (GetFileAttributesExW (wszFile, GetFileExInfoStandard, &wfad))
						eFRi->list ().back ().integer () = FILETIMEToUnixTime (wfad.ftLastWriteTime);
				}
			}
			}catch (...){}
		}

		libtorrent::storage_mode_t sm;
		if (enStorageMode == BTSM_SPARSE)
			sm = libtorrent::storage_mode_sparse;
		else if (enStorageMode == BTSM_ALLOCATE)
			sm = libtorrent::storage_mode_allocate;
		else
			sm = libtorrent::storage_mode_compact;

		vmsAUTOLOCKSECTION (m_csDownloads);

		USES_CONVERSION;
		LPCWSTR pwszOutputPath = A2CW (pszOutputPath);
		std::string utf8;
		libtorrent::wchar_utf8 (pwszOutputPath, utf8);
		
		if (torrentimpl->IsMagnetLink())
		{
			boost::system::error_code err;

			libtorrent::add_torrent_params p;
			p.save_path = utf8;
			p.storage_mode = (libtorrent::storage_mode_t)libtorrent::storage_mode_allocate;
			p.paused = true;
			p.duplicate_is_error = false;
			p.auto_managed = true;

			th = libtorrent::add_magnet_uri(m_session, torrentimpl->GetMagnetLink(), p, err);
		}
		else
		{
			th = m_session.add_torrent (*torrentimpl->m_torrent, utf8, entryFastResume, sm);
		}

		th.set_ratio (1);

		vmsBtDownloadImpl *pDld = new vmsBtDownloadImpl(th, torrentimpl, utf8);
		pDld->AddRef ();
		
		m_vDownloads.push_back (pDld);
		return pDld;
	}
	catch (std::exception&) 
	{
		return NULL;
	}
}

void vmsBtSessionImpl::DeleteDownload (vmsBtDownload* pDld)
{
	vmsAUTOLOCKSECTION (m_csDownloads);

	vmsBtDownloadImpl *downloadImpl = dynamic_cast <vmsBtDownloadImpl*>(pDld);
	if (downloadImpl)
	{
		int nIndex = FindDownloadIndex (downloadImpl->GetHandle());
		if (nIndex != -1)
		{
			m_vDownloads.erase (m_vDownloads.begin () + nIndex);
		}
		try 
		{
			m_session.remove_torrent (downloadImpl->GetHandle());
		}
		catch (...) {}
		downloadImpl->Release ();
	}
}

vmsBtSessionImpl* vmsBtSessionImpl::Instance ()
{
	static vmsBtSessionImpl* _p = NULL;
	if (_p == NULL)
	{
		try {
			_p = new vmsBtSessionImpl;
		}
		catch (...) {
			_p = NULL;
		}
	}
	return _p;
}

void vmsBtSessionImpl::SetDownloadLimit (int limit)
{
	m_session.set_download_rate_limit (limit);
}

void vmsBtSessionImpl::SetUploadLimit (int limit)
{
	m_session.set_upload_rate_limit (limit);
}

void vmsBtSessionImpl::ListenOn (int portFrom, int portTo)
{
	m_session.listen_on (std::make_pair (portFrom, portTo));
}

BOOL vmsBtSessionImpl::IsListening ()
{
	return m_session.is_listening ();
}

USHORT vmsBtSessionImpl::get_ListenPort ()
{
	return m_session.listen_port ();
}

void vmsBtSessionImpl::SetMaxUploads (int limit)
{
	m_session.set_max_uploads (limit);
}

void vmsBtSessionImpl::DHT_start (LPBYTE pbState, DWORD dwStateSize)
{
	if (DHT_isStarted ())
		return;
	try {
		m_session.start_dht (pbState ? libtorrent::bdecode (pbState, pbState + dwStateSize) : libtorrent::entry ());
	}catch (...){}
}

void vmsBtSessionImpl::DHT_stop ()
{
	if (DHT_isStarted () == FALSE)
		return;
	try {
		m_session.stop_dht ();
	}catch (...){}
}

void vmsBtSessionImpl::LocalPeers_start ()
{
	try {
		m_session.start_lsd();
	}catch (...){}
}

void vmsBtSessionImpl::LocalPeers_stop ()
{
	try {
		m_session.stop_lsd();
	}catch (...){}
}

void vmsBtSessionImpl::UPNP_start ()
{
	try {
		m_session.start_upnp();
	}catch (...){}
}

void vmsBtSessionImpl::UPNP_stop ()
{
	try {
		m_session.stop_upnp();
	}catch (...){}
}

void vmsBtSessionImpl::NATPMP_start ()
{
	try {
		m_session.start_natpmp();
	}catch (...){}
}

void vmsBtSessionImpl::NATPMP_stop ()
{
	try {
		m_session.stop_natpmp();
	}catch (...){}
}

void vmsBtSessionImpl::addDHTRouter( std::pair<std::string, int> const& node ){
	try {
		m_session.add_dht_router( node );
	}catch (...){}
}

BOOL vmsBtSessionImpl::DHT_getState (LPBYTE pbBuffer, DWORD dwBufferSize, LPDWORD pdwDataSize)
{
	assert (pdwDataSize);
	if (!pdwDataSize)
		return FALSE;

	std::vector <char> v;
	libtorrent::bencode (std::back_inserter (v), m_session.dht_state ());
	
	*pdwDataSize = v.size ();

	if (pbBuffer == NULL)
		return TRUE;

	if (dwBufferSize < v.size ())	
		return FALSE;
	
	for (size_t i = 0; i < v.size (); i++)
		*pbBuffer++ = v [i];

	return TRUE;
}

BOOL vmsBtSessionImpl::DHT_isStarted ()
{
	return m_session.is_dht_running ();
}

void vmsBtSessionImpl::handleAlertProcessingError(boost::system::error_code& exc, libtorrent::torrent_handle& hDownload, 
		vmsBtSessionEvent& ev, std::string& pszMsg, libtorrent::torrent_handle& hAlertDownload, vmsBtSessionEventType enSessionEventType)
{
	hDownload = hAlertDownload;
	ev.enType = enSessionEventType;

	if (exc.value() != 10022) {
		pszMsg = exc.message();
		ev.pszMsg = pszMsg.c_str();
	} else {
		
		
		ev.pszMsg = 0;
	}
}

void vmsBtSessionImpl::processPeerErrorAlert(libtorrent::peer_error_alert* pPeerErrorAlert, libtorrent::torrent_handle& hDownload, 
		vmsBtSessionEvent& ev, std::string& pszMsg)
{
	assert(pPeerErrorAlert != 0);

	try {
		std::string strIp;
		ev.enType = BTSET_PEER_ERROR;
		strIp = pPeerErrorAlert->ip.address ().to_string ().c_str ();
		ev.pszIp = strIp.c_str ();
	} catch (boost::system::error_code& exc) {
		handleAlertProcessingError(exc, hDownload, ev, pszMsg, pPeerErrorAlert->handle, BTSET_CANNOT_PROC_PEER_MSG);
	} catch (...) {
		handleUnknownAlertProcessingError(hDownload, ev, pPeerErrorAlert->handle, BTSET_CANNOT_PROC_PEER_MSG);
	}
}

void vmsBtSessionImpl::processBanErrorAlert(libtorrent::peer_ban_alert* pPeerBanAlert, libtorrent::torrent_handle& hDownload, 
		vmsBtSessionEvent& ev, std::string& pszMsg)
{
	assert(pPeerBanAlert != 0);

	try {
		std::string strIp;
		ev.enType = BTSET_PEER_BAN;
		hDownload = pPeerBanAlert->handle;
		strIp = pPeerBanAlert->ip.address ().to_string ().c_str ();
		ev.pszIp = strIp.c_str ();

	} catch (boost::system::error_code& exc) {
		handleAlertProcessingError(exc, hDownload, ev, pszMsg, pPeerBanAlert->handle, BTSET_CANNOT_PROC_PEER_MSG);
	} catch (...) {
		handleUnknownAlertProcessingError(hDownload, ev, pPeerBanAlert->handle, BTSET_CANNOT_PROC_PEER_MSG);
	}
}

void vmsBtSessionImpl::handleUnknownAlertProcessingError(libtorrent::torrent_handle& hDownload, vmsBtSessionEvent& ev, 
		libtorrent::torrent_handle& hAlertDownload, vmsBtSessionEventType enSessionEventType)
{
	hDownload = hAlertDownload;
	ev.enType = enSessionEventType;
	ev.pszMsg = 0;
}

void vmsBtSessionImpl::CheckIfDhtStateChanged ()
{
	if (!DHT_isStarted())
		return;

	DWORD dwNewSize = 0;
	if (!DHT_getState(NULL, 0, &dwNewSize))
		return;

	if (m_dwSessionStateSize != dwNewSize) {
		std::auto_ptr<BYTE> apbtNewStateBuffer( new BYTE[dwNewSize] );
		LPBYTE pbtNewStateBuffer = apbtNewStateBuffer.get();
		if (pbtNewStateBuffer > 0) {
			if (DHT_getState(pbtNewStateBuffer, dwNewSize, &dwNewSize)) {
				m_apbtSessionState = apbtNewStateBuffer;
				m_dwSessionStateSize = dwNewSize;
				setDirty();
			}
		}
	} else {
		if (m_dwSessionStateSize > 0) {
			std::auto_ptr<BYTE> apbtNewStateBuffer( new BYTE[dwNewSize] );
			LPBYTE pbtNewStateBuffer = apbtNewStateBuffer.get();
			if (pbtNewStateBuffer > 0) {
				if (DHT_getState(pbtNewStateBuffer, dwNewSize, &dwNewSize)) {
					LPBYTE pbtStateBuffer = m_apbtSessionState.get();
					if (memcmp(pbtStateBuffer, pbtNewStateBuffer, m_dwSessionStateSize) != 0) {
						m_apbtSessionState = apbtNewStateBuffer;
						m_dwSessionStateSize = dwNewSize;
						setDirty();
					}
				}
			}
		}
	}
}

DWORD vmsBtSessionImpl::_threadSession (LPVOID lp)
{
	vmsBtSessionImpl* pthis = (vmsBtSessionImpl*)lp;

	pthis->m_apbtSessionState.reset(0);

	while (pthis->m_bNeedStop == false)
	{
		Sleep (100);

		pthis->CheckIfDhtStateChanged();

		
		std::auto_ptr <libtorrent::alert> alert = pthis->m_session.pop_alert ();
		if (alert.get () == NULL)
			continue;	

		if (pthis->m_pfnEvHandler == NULL)
			continue; 

		vmsBtSessionEvent ev;
		std::string pszMsg = alert->message ();
		ev.pszMsg = pszMsg.c_str();
		
		
		
		
		libtorrent::torrent_handle hDownload;
		std::string strIp; 

		

		libtorrent::listen_failed_alert *lfa = dynamic_cast <libtorrent::listen_failed_alert*> (alert.get ());
		if (lfa != NULL)
		{
			ev.enType = BTSET_LISTEN_FAILED;
			goto _lRaiseEvent;
		}

		libtorrent::file_error_alert *fea = dynamic_cast <libtorrent::file_error_alert*> (alert.get ());
		if (fea != NULL)
		{
			ev.enType = BTSET_FILE_ERROR;
			hDownload = fea->handle;
			goto _lRaiseEvent;
		}

		libtorrent::tracker_announce_alert *taa = dynamic_cast <libtorrent::tracker_announce_alert*> (alert.get ());
		if (taa != NULL)
		{
			ev.enType = BTSET_TRACKER_ANNOUNCE;
			hDownload = taa->handle;
			ev.tracker.pszUrl = taa->url.c_str (); 
			ev.tracker.announce.nType = taa->event;
			goto _lRaiseEvent;
		}

		libtorrent::tracker_error_alert *tea = dynamic_cast <libtorrent::tracker_error_alert*> (alert.get ());
		if (tea != NULL)
		{
			ev.enType = BTSET_TRACKER_ERROR;
			hDownload = tea->handle;
			ev.tracker.pszUrl = tea->url.c_str (); 
			ev.tracker.err.nHttpStatusCode = tea->status_code;
			goto _lRaiseEvent;
		}

		libtorrent::tracker_reply_alert *tra = dynamic_cast <libtorrent::tracker_reply_alert*> (alert.get ());
		if (tra != NULL)
		{
			ev.enType = BTSET_TRACKER_REPLY;
			hDownload = tra->handle;
			ev.tracker.pszUrl = tra->url.c_str (); 
			ev.tracker.reply.cPeersRcvd = tra->num_peers;
			goto _lRaiseEvent;
		}

		libtorrent::tracker_warning_alert *twa = dynamic_cast <libtorrent::tracker_warning_alert*> (alert.get ());
		if (twa != NULL)
		{
			ev.enType = BTSET_TRACKER_WARNING;
			hDownload = twa->handle;
			ev.tracker.pszUrl = twa->url.c_str ();
			ev.tracker.warn.pszWarningMsg = twa->msg.c_str ();
			goto _lRaiseEvent;
		}

		libtorrent::url_seed_alert *usa = dynamic_cast <libtorrent::url_seed_alert*> (alert.get ());
		if (usa != NULL)
		{
			ev.enType = BTSET_URL_SEED;
			ev.pszUrl = usa->url.c_str ();
			goto _lRaiseEvent;
		}

		libtorrent::hash_failed_alert *hfa = dynamic_cast <libtorrent::hash_failed_alert*> (alert.get ());
		if (hfa != NULL)
		{
			ev.enType = BTSET_HASH_FAILED;
			hDownload = hfa->handle;
			ev.piece_index = hfa->piece_index;
			goto _lRaiseEvent;
		}

		libtorrent::peer_ban_alert *pba = dynamic_cast <libtorrent::peer_ban_alert*> (alert.get ());
		if (pba != NULL)
		{
			processBanErrorAlert(pba, hDownload, ev, pszMsg);
			goto _lRaiseEvent;
		}

		libtorrent::peer_error_alert *pea = dynamic_cast <libtorrent::peer_error_alert*> (alert.get ());
		if (pea != NULL)
		{
			processPeerErrorAlert(pea, hDownload, ev, pszMsg);
			goto _lRaiseEvent;
		}

		libtorrent::torrent_finished_alert *tfa = dynamic_cast <libtorrent::torrent_finished_alert*> (alert.get ());
		if (tfa != NULL)
		{
			ev.enType = BTSET_TORRENT_FINISHED;
			goto _lRaiseEvent;
		}

		continue;	

_lRaiseEvent:

		vmsBtDownloadImpl *pDld = NULL;
		if (hDownload.is_valid ())
		{
			EnterCriticalSection (&pthis->m_csDownloads);
			int i = pthis->FindDownloadIndex (hDownload);
			if (i != -1)
			{
				pDld = pthis->m_vDownloads [i];
				pDld->AddRef ();
			}
			LeaveCriticalSection (&pthis->m_csDownloads);
		}
		ev.pDownload = pDld;

		EnterCriticalSection (&pthis->m_csObject);
		if (pthis->m_pfnEvHandler)
			pthis->m_pfnEvHandler (pthis, &ev, pthis->m_pEvData);
		LeaveCriticalSection (&pthis->m_csObject);

		

		if (pDld)
			pDld->Release ();
	}

	pthis->CheckIfDhtStateChanged();

	pthis->m_bThreadRunning = false;
	return 0;
}

void vmsBtSessionImpl::set_EventsHandler (fntBtSessionEventsHandler pfn, LPVOID pData)
{
	vmsAUTOLOCKSECTION (m_csObject);
	m_pfnEvHandler = pfn;
	m_pEvData = pData;
}

int vmsBtSessionImpl::FindDownloadIndex (const libtorrent::torrent_handle &h)
{
	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		vmsBtDownloadImpl* dwnld = m_vDownloads.at(i);
		if (dwnld != NULL && dwnld->GetHandle() == h)
			return i;
	}

	return -1;
}

void vmsBtSessionImpl::SetProxySettings (LPCSTR pszIp, int nPort, LPCSTR pszUser, LPCSTR pszPwd)
{
	libtorrent::proxy_settings ps;

	if (pszIp && *pszIp)
	{
		ps.hostname = pszIp;
		ps.port = nPort;
		ps.username = pszUser;
		ps.password = pszPwd;
		ps.type = pszUser && *pszUser ? libtorrent::proxy_settings::http_pw : libtorrent::proxy_settings::http;
	}
	else
	{
		ps.type = libtorrent::proxy_settings::none;
	}

	m_session.set_peer_proxy (ps);
	m_session.set_web_seed_proxy (ps);
	m_session.set_tracker_proxy (ps);
	m_session.set_dht_proxy (ps);
}

void vmsBtSessionImpl::RestoreDownloadHandle (vmsBtDownloadImpl* dld)
{
	vmsAUTOLOCKSECTION (m_csRestoreTorrentHandle);

	if (dld == NULL || dld->GetHandle().is_valid ())
		return;

	try 
	{
		vmsBtFileImplPtr dldImpl = dld->GetTorrentImpl();
		if (dldImpl == NULL || dldImpl->m_torrent == NULL)
		{
			return;
		}
		libtorrent::torrent_handle& handleLink = dld->GetHandle();
		handleLink = m_session.add_torrent(*dldImpl->m_torrent, dld->GetOutputPath());
		dld->GetHandle().pause();
	}
	catch (...) 
	{
		return;
	}

	vmsAUTOLOCKSECTION_UNLOCK (m_csRestoreTorrentHandle);

	if (m_pfnEvHandler)
	{
		vmsBtSessionEvent ev;
		ev.enType = BTSET_BTDLD_WAS_RESET;
		ev.pDownload = dld;
		ev.pszMsg = NULL;
		m_pfnEvHandler (this, &ev, m_pEvData);
	}
}

int vmsBtSessionImpl::get_TotalDownloadConnectionCount ()
{
	vmsAUTOLOCKSECTION (m_csDownloads);
	int n = 0;
	for (size_t i = 0; i < m_vDownloads.size (); i++)
		n += m_vDownloads [i]->get_DownloadConnectionCount ();
	return n;
}

int vmsBtSessionImpl::get_DownloadCount ()
{
	vmsAUTOLOCKSECTION (m_csDownloads);
	return m_vDownloads.size ();
}

vmsBtDownload* vmsBtSessionImpl::get_Download (int nIndex)
{
	vmsAUTOLOCKSECTION (m_csDownloads);
	return m_vDownloads [nIndex];
}

int vmsBtSessionImpl::get_TotalDownloadSpeed ()
{
	return (int)m_session.status ().payload_download_rate;
}

int vmsBtSessionImpl::get_TotalUploadSpeed ()
{
	return (int)m_session.status ().payload_upload_rate;
}

UINT64 vmsBtSessionImpl::get_TotalDownloadedByteCount ()
{
	return m_session.status ().total_payload_download;
}

UINT64 vmsBtSessionImpl::get_TotalUploadedByteCount ()
{
	return m_session.status ().total_payload_upload;
}

void vmsBtSessionImpl::DisableOsCash ()
{
	libtorrent::session_settings s = m_session.settings ();

	
	
	
	

	m_session.set_settings (s);
}

void vmsBtSessionImpl::SetUserAgent (LPCSTR pszUA)
{
	libtorrent::session_settings s = m_session.settings ();

	if (stricmp (pszUA, "FDM 3.x") == 0 || stricmp (pszUA, "FDM 2.x") == 0)
		pszUA = "FDM/3.0(848)";
	s.user_agent = pszUA;
	m_session.set_settings (s);
}

void vmsBtSessionImpl::SetMaxHalfOpenConnections (int limit)
{
	if (limit > 0 && limit < 200)
		m_session.set_max_half_open_connections (limit);
}

void vmsBtSessionImpl::SetMaxConnections (int limit)
{
	if (limit < 0 && limit != -1)
		limit = -1; 
	m_session.set_max_connections (limit);
}

void vmsBtSessionImpl::setWriteCacheSize (DWORD cache_size)
{
	if (cache_size) 
	{
		libtorrent::session_settings settings = m_session.settings();
		const int cache_size_16KiB = (cache_size) ? cache_size / 16384 : 0; 
		if (settings.cache_size != cache_size_16KiB) 
		{
			settings.cache_size = cache_size_16KiB;
			m_session.set_settings(settings);
		}
	}
}

void vmsBtSessionImpl::setMultiTracker (bool announce_to_all_trackers, bool announce_to_all_tiers)
{
	libtorrent::session_settings settings = m_session.settings();
	settings.announce_to_all_trackers = announce_to_all_trackers;
	settings.announce_to_all_tiers = announce_to_all_tiers;
	m_session.set_settings(settings);
}

void vmsBtSessionImpl::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	
	if (!DHT_getState (NULL, 0, &dwRequiredSize))
		return;

	if (pbtBuffer == NULL) {
		if (pdwSize) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	if (*pdwSize < dwRequiredSize)
		return;

	if (!DHT_getState (pbtBuffer, *pdwSize, &dwRequiredSize))
		return;

	*pdwSize = dwRequiredSize;
}

bool vmsBtSessionImpl::loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer)
{
	return false;
}
