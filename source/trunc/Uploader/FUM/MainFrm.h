/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_MAINFRM_H__142AE40C_055D_4F78_BD40_519BBE725D19__INCLUDED_)
#define AFX_MAINFRM_H__142AE40C_055D_4F78_BD40_519BBE725D19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ChildView.h"
#include "fsODMenu.h"	
#include "fsUpdateMgr.h"	

#define ID_NEED_EXIT		41000

class CMainFrame : public CFrameWnd
{
	
public:
	CMainFrame();
protected: 
	DECLARE_DYNAMIC(CMainFrame)

public:

public:

	
	//{{AFX_VIRTUAL(CMainFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

public:
	void SaveState();
	void ShowTrayMenu();
	fsUpdateMgr m_um;
	#define LCR_NO_NEW_VER			0
	#define LCR_CHECK_FAILED		1
	#define LCR_NEW_VER_DETECTED	2
	#define LCR_RESTART_REQ			3
	int m_iOnBeforeUpload_LastCallResult; 
	BOOL OnBeforeUpload(LPSTR pszStopReason, bool* pbNeedStop);
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;
	CChildView    m_wndView;

protected:
	UINT m_nUploadsMsg1;
	UINT m_nShutdownMsg;
	fsODMenu m_odTrayMenu;
	BOOL m_bTrayMenuShowing;
	afx_msg LRESULT OnTrayMsg (WPARAM, LPARAM);
	class CDlgUpdate* m_dlgUpdate;
	static DWORD WINAPI _threadCheckNewVer (LPVOID lp);
	CString GetToolbarButtonText (UINT nID);
	void ApplyLanguage();
	afx_msg void OnUpdateLanguage (CCmdUI *pCmdUI);
	afx_msg void OnLanguage (UINT nId);
	void BuildLngMenu();
	fsODMenu m_odmenuMain;
	CImageList m_imgsTb, m_imgsTb_d;
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSetFocus(CWnd *pOldWnd);
	afx_msg void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnToolsGeneralsettings();
	afx_msg void OnHomepage();
	afx_msg void OnSupport();
	afx_msg void OnRecommend();
	afx_msg void OnClose();
	afx_msg void OnShowmainwindow();
	afx_msg void OnCreatenewupload();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg void OnNeedExit ();
	afx_msg void OnUpdate ();
};

//{{AFX_INSERT_LOCATION}}

#endif 
