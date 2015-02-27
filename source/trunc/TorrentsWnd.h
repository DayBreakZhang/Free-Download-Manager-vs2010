/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TORRENTSWND_H__8D6AC2AB_0E8A_4F76_8BF0_435F8676094C__INCLUDED_)
#define AFX_TORRENTSWND_H__8D6AC2AB_0E8A_4F76_8BF0_435F8676094C__INCLUDED_

#include "WndSplitter.h"	
#include "Torrents_Tasks.h"	
#include "Downloads_Bittorrent.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

extern class CTorrentsWnd *_pwndTorrents;

class CTorrentsWnd : public CWnd
{

public:
	CTorrentsWnd();

public:

public:
	
	static void Plugin_SetLanguage (wgLanguage, HMENU hMenuMain, HMENU);
	static void Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort);
	static void Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *cItems);
	static void Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages);
	static void Plugin_GetToolBarInfo (wgTButtonInfo **ppButtons, int *pcButtons);
	static HWND Plugin_CreateMainWindow (HWND hWndParent);
	static HMENU Plugin_GetViewMenu();
	static HMENU Plugin_GetMainMenu();
	

	
	//{{AFX_VIRTUAL(CTorrentsWnd)
	//}}AFX_VIRTUAL

public:
	CDownloads_Bittorrent m_wndBtTab;
	void SetActiveDownload(vmsDownloadSmartPtr dld);
	void AddDownload (vmsDownloadSmartPtr dld, BOOL bPlaceToTop);
	void SaveAll(DWORD dwWhat);
	BOOL Create(CWnd *pwndParent);
	CTorrents_Tasks m_wndTasks;

	virtual ~CTorrentsWnd();

	
protected:
	afx_msg void OnDLListShowCol(UINT nCmd);
	void ApplyLanguageToMenuView(CMenu *menu);
	afx_msg LRESULT OnUpdateToolBar (WPARAM, LPARAM);
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM);
	afx_msg LRESULT OnUpdateMenu (WPARAM, LPARAM);
	afx_msg LRESULT OnAppQueryExit (WPARAM, LPARAM);
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	afx_msg LRESULT OnInsert (WPARAM, LPARAM);
	CWndSplitter m_wndSplitter;
	//{{AFX_MSG(CTorrentsWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBtdldAddfromfile();
	afx_msg void OnBtdldAddfromurl();
	afx_msg void OnBtdldAutostart();
	afx_msg void OnBtdldCreatenewtorrent();
	afx_msg void OnBtdldDelete();
	afx_msg void OnBtdldLaunch();
	afx_msg void OnBtdldOpenfolder();
	afx_msg void OnBtdldPasstodlds();
	afx_msg void OnBtdldProperties();
	afx_msg void OnBtdldStart();
	afx_msg void OnBtdldStop();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

//{{AFX_INSERT_LOCATION}}

#endif 
