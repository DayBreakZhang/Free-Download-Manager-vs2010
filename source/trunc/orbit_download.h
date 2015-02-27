/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef ORBIT_DOWNLOAD_INCLUDED_FILE
#define ORBIT_DOWNLOAD_INCLUDED_FILE

struct TOrbitDownload
{
	TOrbitDownload();

	CString sPath;
	CString sFile;
	CString sUrl;
	bool bIsComplete;
	UINT64 uCompletedSize;
	UINT64 uFileSize;
};

typedef CArray<TOrbitDownload, TOrbitDownload&> OrbitDownloadsArray;

void parseOrbitDownloadsList(const CString& sDldList, OrbitDownloadsArray& arrDownloads);

#endif
