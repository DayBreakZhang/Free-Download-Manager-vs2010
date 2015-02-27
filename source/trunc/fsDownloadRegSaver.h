/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSDOWNLOADREGSAVER_H__C91EBD46_B85B_4D4B_A864_1648A483A8F0__INCLUDED_)
#define AFX_FSDOWNLOADREGSAVER_H__C91EBD46_B85B_4D4B_A864_1648A483A8F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "fsDownload.h"
#include "vmsPersistableListOfDownloads.h"

typedef DLDS_LIST t_downloads;

#define DLFILE_CURRENT_VERSION	(18)

#define DLFILE_SIG "FDM Downloads  "

struct fsDLFileHdr
{
	char szSig [sizeof (DLFILE_SIG) + 1];
	WORD wVer;

	fsDLFileHdr ()
	{
		strcpy (szSig, DLFILE_SIG);
		wVer = DLFILE_CURRENT_VERSION;
	}
};

enum fsDLLoadFromType
{
	DLLFT_SAV,			
	DLLFT_BAK			
};

enum fsDLLoadResult
{
	DLLR_FAILED,
	DLLR_SUCCEEDED,
	DLLR_TOOLARGESIZE,
};

class fsDownloadRegSaver
{
public:
	
	
	
	fsDLLoadResult Load (t_downloads* vDownloads, LPCSTR pszFileName, BOOL bDontLoadIfTooLarge, fsDLLoadFromType lt = DLLFT_SAV, BOOL bErrIfNotExists = FALSE);
	
	fsDLLoadResult Load (vmsDownloadList& vDownloads, LPCSTR pszFileName, BOOL bDontLoadIfTooLarge, fsDLLoadFromType lt = DLLFT_SAV, BOOL bErrIfNotExists = FALSE);
	
	BOOL Save(vmsDownloadList& vDownloads, LPCSTR pszFileName);
	bool IsStoringLogTurnedOn();

	fsDownloadRegSaver();
	virtual ~fsDownloadRegSaver();
protected:
	BOOL m_bDontSaveLogs;
	
	
	
	
	
	BOOL LoadDownload (vmsDownloadSmartPtr dld, LPVOID lpBuffer, LPDWORD lpdwSize, WORD wVer);

	
	
	BOOL OLD_LoadDownload (vmsDownloadSmartPtr dld, LPVOID lpBuffer, LPDWORD lpdwSize);
};

#endif 
