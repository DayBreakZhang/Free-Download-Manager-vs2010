/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETURLFILEDOWNLOADER_H__2BB778E5_7CEF_48DC_93FA_6AC802EA0222__INCLUDED_)
#define AFX_FSINTERNETURLFILEDOWNLOADER_H__2BB778E5_7CEF_48DC_93FA_6AC802EA0222__INCLUDED_

#include "fsInternetURLFile.h"	
#include "fsinet.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

enum fsInternetURLFileDownloaderEvent
{
	UFDE_CONNECTING,
	UFDE_DOWNLOADING,
	UFDE_DONE
};

typedef void (*fntInternetURLFileDownloaderEvents)(fsInternetURLFileDownloaderEvent ev, LPVOID lp);

class fsInternetURLFileDownloader  
{
public:
	UINT Get_FileSize();
	void SetEventFunc (fntInternetURLFileDownloaderEvents pfn, LPVOID lpParam);
	void Free_FileBuffer();
	LPBYTE Get_FileBuffer();
        
	
	fsInternetURLFile* Get_File();
	void Abort();
	fsInternetResult Initialize(fsInternetSession *pSession);
	fsInternetResult Download (LPCSTR pszUrl);
	fsInternetURLFileDownloader();
	virtual ~fsInternetURLFileDownloader();

protected:
	void Event (fsInternetURLFileDownloaderEvent ev);
	LPBYTE m_pBuffer;
	UINT m_uFileSize;
	BOOL m_bAbort;
	fsInternetURLFile m_file;

	fntInternetURLFileDownloaderEvents m_pfnEvents;
	LPVOID m_lpEvParam;
};

#endif 
