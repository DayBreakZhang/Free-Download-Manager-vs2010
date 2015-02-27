/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsBtDownload.h"
#include "vmsBtDownloadPeerInfoListImpl.h"
#include "vmsBtFileImpl.h"

class vmsBtDownloadImpl : public vmsBtDownload
{
	libtorrent::torrent_handle m_handle; 
	
	
	
	vmsBtFileImplPtr m_spTorrent;
	std::string m_strOutputPath;
public:
	vmsBtDownloadImpl(
		const libtorrent::torrent_handle& handle, vmsBtFileImplPtr spTorrent, const std::string& strOutputPath);

	libtorrent::torrent_handle& GetHandle();
	vmsBtFileImplPtr GetTorrentImpl();
	std::string GetOutputPath();

	void check_handle_is_valid (); 
	vmsBtDownloadState GetState ();
	BOOL IsPaused ();
	void Pause ();
	void Resume ();
	vmsBtFile* get_Torrent ();
	void get_SavePath (LPSTR pszRes);
	float get_PercentDone ();
	int get_PiecesProgressMap (bool* pbPieces, int *pnCompletedPieces);
	bool is_PieceCompleted (int nIndex);
	int get_DownloadConnectionCount ();
	UINT64 get_TotalDownloadedBytesCount ();
	UINT GetDownloadSpeed ();
	UINT GetUploadSpeed ();
	void SetDownloadLimit (int limit);
	int  GetDownloadLimit ();
	void SetUploadLimit (int limit);
	int  GetUploadLimit ();
	int get_ConnectionCount ();
	void set_ConnectionLimit (int limit);
	BOOL get_FastResumeData (LPBYTE pbRes, DWORD dwSize, DWORD *pdwDataSize);
	void set_TrackerLogin (LPCSTR pszUser, LPCSTR pszPassword);
	BOOL MoveToFolder (LPCSTR pszNewFolder);
	
	int get_NextAnnounceInterval ();
	void get_CurrentTracker (LPSTR pszRes);
	UINT64 get_TotalUploadedByteCount ();
	void get_PeersStat (int *pnPeersConnected, int *pnSeedsTotal, int *pnLeechersTotal, int *pnSeedsConnected);
	UINT64 get_WastedByteCount ();
	double get_ShareRating ();
	vmsBtDownloadPeerInfoList* get_PeerInfoList ();
	void get_FileProgress (float *p);
	BOOL is_HandleValid ();
	int get_CurrentTaskProgress ();
	void PrioritizeFiles (int* piPriorities);
	void get_CurrentTracker2 (LPSTR pszRes, DWORD dwBuffSize);
	int get_NextAnnounceInterval (LPCSTR pszTrackerUrl);
	UINT GetDownloadSpeedIncludingServiceTraffic ();
	UINT GetUploadSpeedIncludingServiceTraffic ();
	BOOL SetMagnetMetadata(vmsBtFile* torrentFile);

	void AddRef () {InterlockedIncrement (&m_cRefs);}
	void Release () {if (0 == InterlockedDecrement (&m_cRefs)) delete this;}

protected:
	virtual ~vmsBtDownloadImpl(void);

protected:
	int m_iDownloadSpeedLimit, m_iUploadSpeedLimit;
	
	vmsBtDownloadPeerInfoListImpl m_peerList;
	long m_cRefs;
	libtorrent::torrent_status& status ();
	libtorrent::torrent_status m_status; DWORD m_dwDob_status;

	vmsCriticalSection m_csStatusGuard;
};
