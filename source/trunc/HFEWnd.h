/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFEWND_H__1BCAA1E5_6ACC_458E_B378_DACBA9BDE111__INCLUDED_)
#define AFX_HFEWND_H__1BCAA1E5_6ACC_458E_B378_DACBA9BDE111__INCLUDED_

#include "HFE_ListLog.h"	
#include "HFE_Address.h"	
#include "fsInternetFileListMgr.h"	
#include "fsEventsMgr.h"	
#include "plugins.h"
#if _MSC_VER > 1000
#pragma once
#endif 

class CHFEWnd : public CWnd
{
	friend class CHFE_Log;
	friend class CHFE_FileList;

public:
	CHFEWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CHFEWnd)
	//}}AFX_VIRTUAL

public:
	static HMENU Plugin_GetViewMenu();
	static HMENU Plugin_GetMainMenu();
	
	void LogFailedMessage (LPCSTR pszMsg);
	void ClearHistory();
	
	static void Plugin_SetLanguage (wgLanguage, HMENU hMenuMain, HMENU);
	static void Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort);
	static void Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *cItems);
	static void Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages);
	static void Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons);
	static HWND Plugin_CreateMainWindow (HWND hParent);
	afx_msg LRESULT OnAppQueryExit (WPARAM, LPARAM);
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	
	
	void OnGo();
	
	void SaveAll(DWORD dwWhat);
	fsInternetFileListMgr* GetMgr();
	BOOL Create (CWnd* pParent);
	virtual ~CHFEWnd();

	
protected:
	
	afx_msg void OnLogShowCol (UINT uCmd);
	afx_msg void OnFilesListShowCol (UINT uCmd);
	void UpdateLogColMenu (CMenu* menu);
	void UpdateFilesListColMenu (CMenu* menu);
	

	
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM lp);
	void ApplyLanguageToMenuView(CMenu *menu);
	
	afx_msg void OnShowLog ();
	afx_msg LRESULT OnUpdateToolBar (WPARAM wp, LPARAM);
	
	static DWORD WINAPI _threadGoUrl (LPVOID lp);
	afx_msg LRESULT OnUpdateMenu (WPARAM, LPARAM lp);
	fsEventsMgr m_evMgr;	
	
	static void _EventsFunc (class fsInternetFileListMgr*, fsInternetFileListMgrEvent ev, LPVOID lp);
	fsInternetFileListMgr m_mgr;
	CHFE_ListLog m_wndListLog;	
	CHFE_Address m_wndUrl;		
	CString m_strLastGoUrl;
	vmsCriticalSection m_csLastGoUrl, m_csGo;
	//{{AFX_MSG(CHFEWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	afx_msg void OnHfeRefresh();
	
	afx_msg void OnHfeSettings();
	
	afx_msg void OnHfeStop();
	
	afx_msg void OnHfeDownload();
	
	afx_msg void OnHfeOpenfolder();
	
	afx_msg void OnHfeParentfolder();
	
	afx_msg void OnHfeDisconnect();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
