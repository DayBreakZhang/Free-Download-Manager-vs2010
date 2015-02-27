/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FLASHVIDEODOWNLOADSWND_H__09228685_F3CC_4075_B8A1_430FAACBC81B__INCLUDED_)
#define AFX_FLASHVIDEODOWNLOADSWND_H__09228685_F3CC_4075_B8A1_430FAACBC81B__INCLUDED_

#include "FVDownloads_Tasks.h"	
#include "WndSplitter.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

extern class CFlashVideoDownloadsWnd *_pwndFVDownloads;

#define WM_FVDW_CREATEDOWNLOADS			(WM_APP+1000)

class CFlashVideoDownloadsWnd : public CWnd
{
public:
	struct WmFvdwLparam
	{
		CString strSrcWebPageUrl;
		std::vector <vmsNewDownloadInfo> *pvDlds;
		class CFdmUiWindow *pUiWindow;
	};

public:
	CFlashVideoDownloadsWnd();

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
	

	
	//{{AFX_VIRTUAL(CFlashVideoDownloadsWnd)
	//}}AFX_VIRTUAL

public:
	BOOL CreateDownload (LPCSTR pszUrl = NULL, bool bTopMostErrMessages = false);
	void SetActiveDownload (vmsDownloadSmartPtr dld);
	void SaveAll(DWORD dwWhat);
	void OnDownloadDone (vmsDownloadSmartPtr dld);
	void AddDownload (vmsDownloadSmartPtr dld, BOOL bPlaceToTop);
	CDownloads_VideoPreview m_wndPreview;
	CFVDownloads_Tasks m_wndTasks;
	BOOL Create (CWnd *pwndParent);
	virtual ~CFlashVideoDownloadsWnd();

	
protected:
	static DWORD WINAPI _threadPassWebPageUrlToFlvSniffDll (LPVOID lp);
	afx_msg LRESULT OnFvdwCreateDownloads (WPARAM, LPARAM);
	CWndSplitter m_splitter;
	afx_msg void OnDLListShowCol (UINT nCmd);
	void ApplyLanguageToMenuView(CMenu *menu);
	afx_msg LRESULT OnUpdateToolBar (WPARAM, LPARAM);
	afx_msg LRESULT OnUpdateMenuView (WPARAM, LPARAM);
	afx_msg LRESULT OnUpdateMenu (WPARAM, LPARAM);
	afx_msg LRESULT OnAppQueryExit (WPARAM, LPARAM);
	afx_msg LRESULT OnAppExit (WPARAM, LPARAM);
	afx_msg LRESULT OnInsert (WPARAM, LPARAM);
	//{{AFX_MSG(CFlashVideoDownloadsWnd)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnFvdldCreate();
	afx_msg void OnFvdldAutostart();
	afx_msg void OnFvdldDelete();
	afx_msg void OnFvdldLaunch();
	afx_msg void OnFvdldOpenfolder();
	afx_msg void OnFvdldPasstodlds();
	afx_msg void OnFvdldProperties();
	afx_msg void OnFvdldStart();
	afx_msg void OnFvdldStop();
	afx_msg void OnFvdldConvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
};

//{{AFX_INSERT_LOCATION}}

#endif 
