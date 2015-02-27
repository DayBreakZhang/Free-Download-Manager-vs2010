/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADS_OPINIONS_H__D5CD8A8E_5101_465C_BC7D_CDE7B97F9BAE__INCLUDED_)
#define AFX_DOWNLOADS_OPINIONS_H__D5CD8A8E_5101_465C_BC7D_CDE7B97F9BAE__INCLUDED_

#include "webbrowser2.h"	
#include "Downloads_Opinions_WBEvents.h"	
#include "vmsWebBrowserEvents.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

enum CDownloads_Opinions_CurrentlyShowing
{
	DOCS_UNKNOWN,	
	DOCS_BLANK,		
	DOCS_OPINION,	
	DOCS_OPINIONS,	
};

class CDownloads_Opinions : public CWnd
{
	friend class CDownloads_Opinions_WBEvents;

public:
	CDownloads_Opinions();

public:

public:

	
	//{{AFX_VIRTUAL(CDownloads_Opinions)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

public:
	
	
	
	
	
	void UpdateContent(bool bSetAsCurrentTabAfterLoadComplete = false);
	bool Create (CWnd* pwndParent);
	void Set_ActiveDownload (vmsDownloadSmartPtr dld);
	virtual ~CDownloads_Opinions();

	
protected:
	
	long m_cSetAsCurrentTabAfterLoadComplete;
	
	CDownloads_Opinions_CurrentlyShowing m_enCS;
	
	afx_msg LRESULT OnUpdateContent (WPARAM, LPARAM);
	CDownloads_Opinions_WBEvents m_wbEventRcvr;
	
	vmsDownloadSmartPtr m_dld;
	
	CWebBrowser2 m_wb;
	//{{AFX_MSG(CDownloads_Opinions)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
