/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSMIRRORURLSMGR_H__F477E452_F0BB_4580_AEB8_54D9454478AD__INCLUDED_)
#define AFX_FSMIRRORURLSMGR_H__F477E452_F0BB_4580_AEB8_54D9454478AD__INCLUDED_

#include "fsSitePingMgr.h"	
#include "inetfile/inetfile.h"
#if _MSC_VER > 1000
#pragma once
#endif 

enum fsMirrorURLsMgrEvent
{
	MUME_CONNECTINGSEARCHSERVER,	
	MUME_RETREIVINGSEARCHRESULTS,	
	MUME_DONE						
};

typedef void (*fntMirrorURLsMgrEvents)(fsMirrorURLsMgrEvent ev, LPVOID lp);

class fsMirrorURLsMgr  
{
public:
	
	void Abort();
	
	void Set_EventFunc (fntMirrorURLsMgrEvents pfn, LPVOID lp);
	
	fsInternetResult SearchForMirrors();
	
	LPCSTR Get_MirrorURL (int iIndex);
	
	int Get_MirrorURLCount();
	
	
	
	void Set_SearchURL (LPCSTR pszUrl);
	
	
	
	
	void Initialize (LPCSTR pszFileName, UINT64 uSize, LPCSTR pszBaseServer, fsInternetSession* pSession);
	fsMirrorURLsMgr();
	virtual ~fsMirrorURLsMgr();

protected:
	
	BOOL m_bAbort;
	
	
	virtual BOOL IsMirrorURLGood (LPCSTR pszURL);
	
	virtual fsInternetResult OnSearchScriptResultsReceived();
	
	void Event (fsMirrorURLsMgrEvent ev);
	
	static void _DldrEvents (fsInternetURLFileDownloaderEvent ev, LPVOID lp);
	fsInternetURLFileDownloader m_dldr;
	fsString m_strSearchURL;
	fsString m_strBaseServer;
	fsString m_strFile;
	UINT64 m_uSize;
	fs::list <fsString> m_vMirrorURLs;	
	fs::list <DWORD> m_vMirrorSpeeds;	

	fntMirrorURLsMgrEvents m_pfnEvents;
	LPVOID m_lpEvParam;
};

class fsMirrorURLsMgr_FileMirrorsDotCom : public fsMirrorURLsMgr  
{
public:
	void Set_SearchURL (int nURL);
	fsMirrorURLsMgr_FileMirrorsDotCom();
	virtual ~fsMirrorURLsMgr_FileMirrorsDotCom();

protected:
};

#endif 
