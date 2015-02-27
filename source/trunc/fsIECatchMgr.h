/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSIECATCHMGR_H__02D75EC6_6354_488F_BCC9_5689F5137467__INCLUDED_)
#define AFX_FSIECATCHMGR_H__02D75EC6_6354_488F_BCC9_5689F5137467__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum fsIECatchMgrEvent
{
	ICME_DLSTARTED,		
	ICME_DLCOMPLETED,	
};

typedef void (*fntIECatchMgrEvents)(fsIECatchMgrEvent, LPVOID);

class fsIECatchMgr  
{
	friend class fsClipboardCatchMgr; 
public:
	BOOL IsMonitoringDllRegistered ();
	
	
	
	static void CleanIEPluginKey();
	
	HRESULT Initialize ();
	
	
	
	
	BOOL InstallIeIntegration (BOOL bInstall = TRUE, BOOL bCurrentUserOnly = FALSE, BOOL bOverrideHKCR = TRUE);
	BOOL IsIE2Active();
	void SetEventsFunc (fntIECatchMgrEvents pfn,  LPVOID lpParam);
	
	BOOL IsActive();
	
	void Detach();
	
	void ReadSettings();

	fsIECatchMgr();
	virtual ~fsIECatchMgr();

protected:
	
	bool m_bNeedStop;
	
	bool m_bMonitorIEActivityRunning;
	
	
	static DWORD WINAPI _threadMonitorIEActivity (LPVOID lp);
	
	void Event (fsIECatchMgrEvent ev);
	fntIECatchMgrEvents m_pfnEvents;
	LPVOID m_lpEventsParam;

	
	BOOL m_bCatchClicks;
	
	int m_cIEDLs;
	
	BOOL m_bALTShouldPressed;
	
	CString m_strSkipExts;
	
	
	
	BOOL OnBeforeNavigate (LPCSTR pszUrl, BOOL bCheckALT = TRUE);
};

#endif 
