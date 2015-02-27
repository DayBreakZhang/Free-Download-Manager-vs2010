/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsBtDownload.h"
#include "vmsBtFile.h"
#include "vmsBtPersistObject.h"

enum vmsBtSessionEventType
{
	
	
	BTSET_LISTEN_FAILED,
	
	
	BTSET_FILE_ERROR,
	
	
	BTSET_TRACKER_ANNOUNCE,
	
	
	BTSET_TRACKER_ERROR,
	
	
	BTSET_TRACKER_REPLY,
	
	
	
	
	BTSET_TRACKER_WARNING,
	
	BTSET_URL_SEED,
	
	
	
	BTSET_HASH_FAILED,
	
	
	BTSET_PEER_BAN,
	
	
	
	BTSET_PEER_ERROR,
	
	
	BTSET_TORRENT_FINISHED,
	
	
	BTSET_BTDLD_WAS_RESET,
	
	BTSET_CANNOT_PROC_PEER_MSG
};

struct vmsBtSessionEvent_Tracker_Announce
{
	int nType;
};

struct vmsBtSessionEvent_Tracker_Reply
{
	int cPeersRcvd;
};

struct vmsBtSessionEvent_Tracker_Error
{
	int nHttpStatusCode;
};

struct vmsBtSessionEvent_Tracker_Warning
{
	LPCSTR pszWarningMsg;
};

struct vmsBtSessionEvent_Tracker
{
	LPCSTR pszUrl;
	union {
		vmsBtSessionEvent_Tracker_Announce announce;
		vmsBtSessionEvent_Tracker_Reply reply;
		vmsBtSessionEvent_Tracker_Error err;
		vmsBtSessionEvent_Tracker_Warning warn;
	};
};

struct vmsBtSessionEvent
{
	vmsBtSessionEventType enType;
	LPCSTR pszMsg;
	vmsBtDownload *pDownload;

	union {
	vmsBtSessionEvent_Tracker tracker;

	
	LPCSTR pszUrl;

	
	int piece_index;

	
	LPCSTR pszIp;
	};
};

enum vmsBtStorageMode
{
	
	
	
	BTSM_ALLOCATE	= 0,
	
	
	
	BTSM_COMPACT	= 1,
	
	
	BTSM_SPARSE		= 2,
};

typedef void (*fntBtSessionEventsHandler)(class vmsBtSession*, vmsBtSessionEvent*, LPVOID);

#define BTSCDF_FORCE_IGNORE_TIMESTAMPS			1

class vmsBtSession
{
public:
	
	
	virtual void ListenOn (int portFrom, int portTo) = NULL;
	
	virtual BOOL IsListening () = NULL;
	
	virtual USHORT get_ListenPort () = NULL;
	
	virtual vmsBtDownload* CreateDownload (vmsBtFile *torrent, LPCSTR pszOutputPath, LPBYTE pbFastResumeData, DWORD dwFRDataSize, vmsBtStorageMode enStorageMode, DWORD dwFlags) = NULL;
	
	virtual void SetDownloadLimit (int limit) = NULL;
	virtual void SetUploadLimit (int limit) = NULL;
	
	virtual void SetMaxUploads (int limit) = NULL;
	
	virtual void DeleteDownload (vmsBtDownload*) = NULL;
	
	virtual void DHT_start (LPBYTE pbState, DWORD dwStateSize) = NULL;
	virtual void DHT_stop () = NULL;
	virtual BOOL DHT_getState (LPBYTE pbBuffer, DWORD dwBufferSize, LPDWORD pdwDataSize) = NULL;
	virtual BOOL DHT_isStarted () = NULL;
	virtual void LocalPeers_start () = NULL;
	virtual void LocalPeers_stop () = NULL;	
	virtual void UPNP_start () = NULL;
	virtual void UPNP_stop () = NULL;	
	virtual void NATPMP_start () = NULL;
	virtual void NATPMP_stop () = NULL;	
	
	
	virtual void set_EventsHandler (fntBtSessionEventsHandler pfn, LPVOID pData) = NULL;
	virtual void SetProxySettings (LPCSTR pszIp, int nPort, LPCSTR pszUser, LPCSTR pszPwd) = NULL;
	virtual int get_TotalDownloadConnectionCount () = NULL;
	virtual int get_DownloadCount () = NULL;
	virtual vmsBtDownload* get_Download (int nIndex) = NULL;
	virtual int get_TotalDownloadSpeed () = NULL;
	virtual int get_TotalUploadSpeed () = NULL;
	virtual UINT64 get_TotalDownloadedByteCount () = NULL;
	virtual UINT64 get_TotalUploadedByteCount () = NULL;
	virtual void SetUserAgent (LPCSTR pszUA) = NULL;
	virtual void SetMaxHalfOpenConnections (int limit) = NULL;
	virtual void SetMaxConnections (int limit) = NULL;
	virtual void setWriteCacheSize (DWORD cache_size) = NULL;
	virtual void setMultiTracker (bool announce_to_all_trackers, bool announce_to_all_tiers) = NULL;
	
	virtual void DisableOsCash() = NULL;
	virtual void getPersistObject (vmsBtPersistObject **ppObj) = NULL;
	virtual void addDHTRouter( std::pair<std::string, int> const& node ) = NULL;
};
