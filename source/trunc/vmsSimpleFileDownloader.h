/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSIMPLEFILEDOWNLOADER_H__539BE448_3975_4D2A_858C_84EFAD3E3300__INCLUDED_)
#define AFX_VMSSIMPLEFILEDOWNLOADER_H__539BE448_3975_4D2A_858C_84EFAD3E3300__INCLUDED_

#include "fsDownloadMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSimpleFileDownloader  
{
public:
	fsInternetResult Download (LPCSTR pszUrl, LPCSTR pszFileName);
	
	void Stop();
	
	fsInternetResult GetLastError();
	bool IsRunning();
	
	vmsSimpleFileDownloader();
	virtual ~vmsSimpleFileDownloader();

protected:
	void CreateDownloader();
	static DWORD _DownloadMgrEvents(fsDownloadMgr* pMgr, fsDownloaderEvent ev, UINT uInfo, LPVOID lp);
	static void _DownloadMgrDescEvents(fsDownloadMgr* , fsDownloadMgr_EventDescType , LPCSTR pszDesc, LPVOID lp);
	fsDownloadMgr *m_dldr;
};

#endif 
