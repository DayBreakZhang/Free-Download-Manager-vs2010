/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDOWNLOADER_H__EA106F59_B464_4AC4_A569_542D928740B4__INCLUDED_)
#define AFX_VMSDOWNLOADER_H__EA106F59_B464_4AC4_A569_542D928740B4__INCLUDED_

#include "..\fsDownloadMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

enum vmsDownloader_State
{
	D_S_CONNECTING,
	D_S_DOWNLOADING,
	D_S_STOPPED,
	D_S_DONE,
	D_S_FAILED,	
	D_S_ERROR_NOW,
};

class vmsDownloader  
{
public:
	void set_UserAgent (LPCSTR pszAgent);
	void set_DisableCookies (BOOL bDisable);
	void set_MaxSections(UINT uiMaxSections);
	
	
	void set_Proxy (LPCSTR pszProxy, LPCSTR pszUserName, LPCSTR pszPassword);
	void set_Timeout (UINT u);
	void set_RetriesTime (int nTime);
	void set_MaxRetryCount (int nMax);
	void set_MinSectionSize (UINT uiMinSectionSize);
	UINT64 get_DownloadedByteCount ();
	UINT64 get_FileSize();
	UINT get_Speed ();
	int get_Progress();
	vmsDownloader_State get_State();
	fsInternetResult get_LastError();
	tstring get_LastErrorMessage();
	void StopDownloading();
	void StartDownloading();
	fsInternetResult Initialize (LPCSTR pszURL, LPCSTR pszOutFile);
	void DumpDownload(LPBYTE pbBuffer, LPDWORD pdwSize);
	bool RestoreDownload(LPBYTE pbBuffer, LPDWORD pdwSize, DWORD dwVer);
	void SetResumeMode();
	bool IsDone();
	std::string get_DestinationFile();
	vmsDownloader();
	virtual ~vmsDownloader();

protected:
	static DWORD _DownloadMgrEvents(fsDownloadMgr* pMgr, fsDownloaderEvent ev, UINT uInfo, LPVOID lp);
	void vmsDownloader::fsIRToStr (fsInternetResult ir, tstring& sMsg);

	fsDownloadMgr m_dldr;
	vmsDownloader_State m_enState;
	fsInternetResult m_irLastError;
public:
	LPCTSTR getDstFilePathName(void);
	LPCSTR getContentType(void);
};

#endif 
