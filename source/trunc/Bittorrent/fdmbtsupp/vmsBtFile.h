/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class vmsBtFile
{
public:
	virtual BOOL LoadFromFile (LPCSTR pszTorrentFile) = NULL;
	virtual BOOL LoadFromBuffer (LPBYTE pbTorrent, DWORD dwTorrentSize) = NULL;
	virtual BOOL LoadFromMagnetLink (LPCSTR pszTorrentFile) = NULL;
	virtual BOOL LoadFromMagnetMetadata (vmsBtFile* torrentFile) = NULL;
	virtual LPCSTR GetMagnetLink() = NULL;

	
	virtual int get_FileCount () = NULL;
	
	virtual void get_FileName (int nIndex, LPSTR pszRes) = NULL;
	virtual UINT64 get_FileSize (int nIndex) = NULL;
	
	virtual UINT64 get_TotalFilesSize () = NULL;
	
	virtual void get_TorrentName (LPSTR pszRes) = NULL;
	
	virtual BOOL get_TorrentBuffer (LPBYTE pbRes, DWORD dwSize, DWORD *pdwTorrentSize) = NULL;
	
	virtual void get_InfoHash (LPSTR pszRes) = NULL;
	
	virtual void get_TrackerUrl (LPSTR pszRes, int nIndex) = NULL;
	
	virtual int get_TrackerCount () = NULL;
	
	virtual void get_TorrentComment (LPSTR pszRes) = NULL;
	virtual int get_PieceCount () = NULL;
	virtual int get_PieceSize () = NULL;

	virtual void Release () = NULL;

	
	
	
	
	
	virtual BOOL CreateNewTorrent (LPCSTR pszSrcPath, LPCSTR pszTrackers, LPCSTR pszUrlSeeds, 
		LPCSTR pszCreator, LPCSTR pszComment, int iPieceSize, int *pnCreateProgress, BOOL *pbNeedCancel) = NULL;

	virtual BOOL GenerateFastResumeDataForSeed (LPCSTR pszSrcFolderOrFile, LPBYTE pbData, DWORD dwSize, LPDWORD pdwSize) = NULL;

	
	virtual void get_FileName2 (int nIndex, LPSTR pszRes, DWORD dwBuffSize) = NULL;
	
	virtual void get_TorrentName2 (LPSTR pszRes, DWORD dwBuffSize) = NULL;
	
	virtual void get_TrackerUrl2 (LPSTR pszRes, int nIndex, DWORD dwBuffSize) = NULL;
	
	virtual void get_TorrentComment2 (LPSTR pszRes, DWORD dwBuffSize) = NULL;
	virtual BOOL CreateNewTorrent2 (LPCWSTR pszSrcPath, LPCSTR pszTrackers, LPCSTR pszUrlSeeds, 
		LPCSTR pszCreator, LPCSTR pszComment, int iPieceSize, int *pnCreateProgress, BOOL *pbNeedCancel) = NULL;

	virtual BOOL getInfoHash2 (LPBYTE pb, LPDWORD pdwBufSize) = NULL;

	virtual BOOL IsMagnetLink() = NULL;

	virtual BOOL IsValid() = NULL;
};
