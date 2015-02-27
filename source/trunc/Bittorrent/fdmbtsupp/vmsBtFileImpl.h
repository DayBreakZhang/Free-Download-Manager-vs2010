/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsbtfile.h"
#include <libtorrent/create_torrent.hpp>

class vmsBtFileImpl : public vmsBtFile
{
	std::string m_magnetLink;
	BOOL m_isMagnet;
	std::string m_strMagnetDisplayName;
public:
	vmsBtFileImpl();
	virtual ~vmsBtFileImpl();

	virtual BOOL LoadFromFile (LPCSTR pszTorrentFile);
	virtual BOOL LoadFromBuffer (LPBYTE pbTorrent, DWORD dwTorrentSize);
	virtual BOOL LoadFromMagnetLink (LPCSTR pszMagnetLink);
	virtual BOOL LoadFromMagnetMetadata (vmsBtFile* torrentFile);

	int get_FileCount ();
	void get_FileName (int nIndex, LPSTR pszRes);
	UINT64 get_FileSize (int nIndex);
	UINT64 get_TotalFilesSize ();
	void get_TorrentName (LPSTR pszRes);
	BOOL get_TorrentBuffer (LPBYTE pbRes, DWORD dwSize, DWORD *pdwTorrentSize);
	void get_InfoHash (LPSTR pszRes);
	BOOL getInfoHash2 (LPBYTE pb, LPDWORD pdwBufSize);
	void get_TrackerUrl (LPSTR pszRes, int nIndex);
	int get_TrackerCount ();
	void get_TorrentComment (LPSTR pszRes);
	int get_PieceCount ();
	int get_PieceSize ();
	
	virtual void Release ();
	void AddRef ();

	BOOL CreateNewTorrent (LPCSTR pszSrcPath, LPCSTR pszTrackers, LPCSTR pszUrlSeeds, 
		LPCSTR pszCreator, LPCSTR pszComment, int iPieceSize, int *pnCreateProgress, BOOL *pbNeedCancel);
	BOOL GenerateFastResumeDataForSeed (LPCSTR pszSrcFolderOrFile, LPBYTE pbData, DWORD dwSize, LPDWORD pdwSize);

	void get_FileName2 (int nIndex, LPSTR pszRes, DWORD dwBuffSize);
	void get_TorrentName2 (LPSTR pszRes, DWORD dwBuffSize);
	void get_TrackerUrl2 (LPSTR pszRes, int nIndex, DWORD dwBuffSize);
	void get_TorrentComment2 (LPSTR pszRes, DWORD dwBuffSize);
	virtual BOOL CreateNewTorrent2 (LPCWSTR pszSrcPath, LPCSTR pszTrackers, LPCSTR pszUrlSeeds, 
		LPCSTR pszCreator, LPCSTR pszComment, int iPieceSize, int *pnCreateProgress, BOOL *pbNeedCancel);
	BOOL IsMagnetLink();
	LPCSTR GetMagnetLink();
	BOOL IsValid();

public:
	libtorrent::torrent_info *m_torrent;
	libtorrent::create_torrent *m_pCreate_torrent;

protected:
	long m_cRefs;
};

typedef vmsObjectSmartPtr <vmsBtFileImpl> vmsBtFileImplPtr;