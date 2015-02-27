/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADSWND_H__10043ADB_1AF4_4035_8F21_703313BD9458__INCLUDED_)
#define AFX_UPLOADSWND_H__10043ADB_1AF4_4035_8F21_703313BD9458__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

extern class CUploadsWnd *_pwndUploads;

#include "Uploader\CoreDll\dll.h"
#include "vmsUploadsDllCaller.h"	

class CUploadsWnd : public CWnd
{

public:
	CUploadsWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CUploadsWnd)
	//}}AFX_VIRTUAL

public:
	static BOOL LoadFumCoreDll(bool bShowUI = false);
	static HMENU Plugin_GetViewMenu();
	static HMENU Plugin_GetMainMenu();
	
	
	vmsUploadsDll::vmsUploadsWnd *m_pwndUploads;
	void SaveAll();
	void ApplyLanguageToMenu(CMenu* menu);
	static void Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView);
	static void Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort);
	static void Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int* );
	static void Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages);
	static void Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons);
	static HWND Plugin_CreateMainWindow(HWND hWndParent);
	BOOL Create(CWnd *pWndParent);
	virtual ~CUploadsWnd();

	
protected:
	afx_msg void OnUploadsCmd (UINT nCmd);
	
	static HMODULE m_hUploadsDll;
	
	vmsUploadsDllCaller m_udc;
	afx_msg void OnLogShowCol (UINT nID);
	afx_msg void OnListShowCol (UINT nID);
	void UpdateListColMenu(CMenu *menu);
	void ApplyLanguageToMenuView(CMenu *menu);
	void UpdateLogColMenu (CMenu *menu);
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM lp);
	afx_msg LRESULT OnInsert (WPARAM, LPARAM);
	int UpdateToolBar(UINT nID);
	afx_msg LRESULT OnUpdateToolBar (WPARAM wp, LPARAM);
	void UpdateMenu (CMenu *menu);
	afx_msg LRESULT OnUpdateMenu (WPARAM, LPARAM lp);
	afx_msg LRESULT OnAppQueryExit (WPARAM, LPARAM);
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	//{{AFX_MSG(CUploadsWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

//{{AFX_INSERT_LOCATION}}

#endif 
