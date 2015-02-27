/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include <memory>
#include "vmsbtsession.h"
#include "vmsBtDownloadImpl.h"
#include <libtorrent/alert_types.hpp>
#include "../../vmsPersistObject.h"

class vmsBtSessionImpl : public vmsBtSession, vmsBtPersistObject,
	protected vmsPersistObject
{
public:
	vmsBtSessionImpl();
	virtual ~vmsBtSessionImpl();
	static vmsBtSessionImpl* Instance ();

	void SetMaxConnections (int limit);
	void setWriteCacheSize (DWORD cache_size);
	void setMultiTracker (bool announce_to_all_trackers, bool announce_to_all_tiers);
	void SetMaxHalfOpenConnections (int limit);
	void RestoreDownloadHandle (vmsBtDownloadImpl* dld);
	void ListenOn (int portFrom, int portTo);
	BOOL IsListening ();
	USHORT get_ListenPort ();
	vmsBtDownload* CreateDownload (vmsBtFile *torrent, LPCSTR pwszOutputPath, LPBYTE pbFastResumeData, DWORD dwFRDataSize, vmsBtStorageMode enStorageMode, DWORD dwFlags);
	void SetDownloadLimit (int limit);
	void SetUploadLimit (int limit);
	void SetMaxUploads (int limit);
	void DeleteDownload (vmsBtDownload*);
	void DHT_start (LPBYTE pbState, DWORD dwStateSize);
	void DHT_stop ();
	void LocalPeers_start ();
	void LocalPeers_stop ();	
	void UPNP_start ();
	void UPNP_stop ();	
	void NATPMP_start ();
	void NATPMP_stop ();	
	BOOL DHT_getState (LPBYTE pbBuffer, DWORD dwBufferSize, LPDWORD pdwDataSize);
	BOOL DHT_isStarted ();
	void set_EventsHandler (fntBtSessionEventsHandler pfn, LPVOID pData);
	void SetProxySettings (LPCSTR pszIp, int nPort, LPCSTR pszUser, LPCSTR pszPwd);
	int get_TotalDownloadConnectionCount ();
	int get_DownloadCount ();
	vmsBtDownload* get_Download (int nIndex);
	int get_TotalDownloadSpeed ();
	int get_TotalUploadSpeed ();
	UINT64 get_TotalDownloadedByteCount ();
	UINT64 get_TotalUploadedByteCount ();
	void SetUserAgent (LPCSTR pszUA);
	
	void DisableOsCash();
	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	void getPersistObject (vmsBtPersistObject **ppObj) {*ppObj = this;}
	virtual bool isDirty () {return vmsPersistObject::isDirty ();}
	virtual void getStateBuffer (LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage) {
		vmsPersistObject::getStateBuffer (pb, pdwSize, bSaveToStorage);
	}
	void addDHTRouter( std::pair<std::string, int> const& node );
	
public:
	libtorrent::session m_session;

protected:
	void CheckIfDhtStateChanged ();
	static DWORD WINAPI _threadSession (LPVOID lp);
	bool m_bThreadRunning, m_bNeedStop;
	fntBtSessionEventsHandler m_pfnEvHandler;
	LPVOID m_pEvData;
	int FindDownloadIndex (const libtorrent::torrent_handle &h);
	
	std::vector <vmsBtDownloadImpl*> m_vDownloads;
	vmsCriticalSection m_csRestoreTorrentHandle, m_csDownloads, m_csObject;
	std::auto_ptr<BYTE> m_apbtSessionState;
	DWORD m_dwSessionStateSize;

private:
	
	static void handleAlertProcessingError (boost::system::error_code& exc, libtorrent::torrent_handle& hDownload, 
			vmsBtSessionEvent& ev, std::string& pszMsg, libtorrent::torrent_handle& hAlertDownload, vmsBtSessionEventType enSessionEventType);
	static void vmsBtSessionImpl::handleUnknownAlertProcessingError (libtorrent::torrent_handle& hDownload, vmsBtSessionEvent& ev, 
			libtorrent::torrent_handle& hAlertDownload, vmsBtSessionEventType enSessionEventType); 
	
	static void vmsBtSessionImpl::processPeerErrorAlert(libtorrent::peer_error_alert* pPeerErrorAlert, libtorrent::torrent_handle& hDownload, 
		vmsBtSessionEvent& ev, std::string& pszMsg);
	static void vmsBtSessionImpl::processBanErrorAlert(libtorrent::peer_ban_alert* pPeerBanAlert, libtorrent::torrent_handle& hDownload, 
			vmsBtSessionEvent& ev, std::string& pszMsg);
};
