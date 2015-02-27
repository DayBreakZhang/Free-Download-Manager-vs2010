/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsBtDownloadPeerInfoList.h"
#include "vmsBtFile.h"

enum vmsBtDownloadState
{
	
	
	BTDS_QUEUED,
	
	
	BTDS_CHECKING_FILES,
	
	BTDS_CONNECTING_TRACKER,
	
	
	
	BTDS_DOWNLOADING,
	
	
	BTDS_FINISHED,
	
	BTDS_SEEDING,
	
	
	BTDS_ALLOCATING,
	
	BTDS_LT_UNKNOWN_STATE,
	
	
	
	BTDS_CHECKING_RESUME_DATA,
	
	BTDS_DOWNLOADING_METADATA,
	
	BTDS_SERVER_INTERNAL_ERROR_500,
	BTDS_BAD_REQUEST_400,
};

class vmsBtDownload
{
public:
	
	virtual vmsBtDownloadState GetState () = NULL;
	virtual BOOL IsPaused () = NULL;
	virtual void Pause () = NULL;
	virtual void Resume () = NULL;
	virtual vmsBtFile* get_Torrent () = NULL;
	
	virtual void get_SavePath (LPSTR pszRes) = NULL;
	
	virtual float get_PercentDone () = NULL;
	
	
	
	
	
	virtual int get_PiecesProgressMap (bool* pbPieces, int *pnCompletedPieces) = NULL;
	virtual bool is_PieceCompleted (int nIndex) = NULL;
	
	virtual int get_DownloadConnectionCount () = NULL;
	
	virtual UINT64 get_TotalDownloadedBytesCount () = NULL;
	virtual UINT GetDownloadSpeed () = NULL;
	virtual UINT GetUploadSpeed () = NULL;
	
	virtual void SetDownloadLimit (int limit) = NULL;
	virtual int  GetDownloadLimit () = NULL;
	
	virtual int get_ConnectionCount () = NULL;
	
	virtual void set_ConnectionLimit (int limit) = NULL;
	
	virtual BOOL get_FastResumeData (LPBYTE pbRes, DWORD dwSize, DWORD *pdwDataSize) = NULL;
	
	virtual void set_TrackerLogin (LPCSTR pszUser, LPCSTR pszPassword) = NULL;
	
	virtual BOOL MoveToFolder (LPCSTR pszNewFolder) = NULL;
	virtual int get_NextAnnounceInterval () = NULL;
	virtual void get_CurrentTracker (LPSTR pszRes) = NULL;
	virtual UINT64 get_TotalUploadedByteCount () = NULL;
	virtual void get_PeersStat (int *pnPeersConnected, int *pnSeedsTotal, int *pnLeechersTotal, int *pnSeedsConnected) = NULL;
	virtual UINT64 get_WastedByteCount () = NULL;
	virtual double get_ShareRating () = NULL;
	virtual vmsBtDownloadPeerInfoList* get_PeerInfoList () = NULL;
	
	
	virtual void get_FileProgress (float *p) = NULL;
	virtual BOOL is_HandleValid () = NULL;
	virtual int get_CurrentTaskProgress () = NULL;
	
	
	
	
	virtual void PrioritizeFiles (int* piPriorities) = NULL;
	virtual void get_CurrentTracker2 (LPSTR pszRes, DWORD dwBuffSize) = NULL;
	virtual int get_NextAnnounceInterval (LPCSTR pszTrackerUrl) = NULL;
	
	virtual void SetUploadLimit (int limit) = NULL;
	virtual int  GetUploadLimit () = NULL;
	virtual UINT GetDownloadSpeedIncludingServiceTraffic () = NULL;
	virtual UINT GetUploadSpeedIncludingServiceTraffic () = NULL;
	virtual BOOL SetMagnetMetadata(vmsBtFile* torrentFile) = NULL;
};