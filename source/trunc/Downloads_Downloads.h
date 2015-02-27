/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_DOWNLOADS_H__F244E7D7_0CEB_4876_8891_33D66656BC10__INCLUDED_)
#define AFX_DOWNLOADS_DOWNLOADS_H__F244E7D7_0CEB_4876_8891_33D66656BC10__INCLUDED_

#include "WndSplitter.h"	
#include "Downloads_Tasks.h"	
#include "Downloads_Info.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDownloads_Downloads : public CWnd
{
	friend class CDownloadsWnd;
	friend class CDownloads_Groups;
	friend class CDownloaderProperties_ListPage;
	friend class CDlg_Options_Downloads;
	friend class CDlgExportDownloads;
	friend class CMainFrame;

public:
	CDownloads_Downloads();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Downloads)
	protected:
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

public:
	CDownloads_Info m_info;		
	void ApplyLanguage();
	
	void SaveState();
	
	BOOL m_bShowDLInfo;
	void ShowDLInfo (BOOL bShow);
	BOOL Create (CWnd *pParent);
	virtual ~CDownloads_Downloads();

	
protected:
	CDownloads_Tasks m_tasks;	
	CWndSplitter m_splitter;	
	//{{AFX_MSG(CDownloads_Downloads)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
