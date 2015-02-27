/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPINIONS_H__343C22CF_7661_4030_90E9_D26E433CCE3A__INCLUDED_)
#define AFX_DLG_OPINIONS_H__343C22CF_7661_4030_90E9_D26E433CCE3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

//{{AFX_INCLUDES()
#include "webbrowser2.h"
#include "vmsWebBrowserEvents.h"	
#include "vmsDocHostUIHandler.h"	
//}}AFX_INCLUDES

class CDlg_Opinions : public CDialog
{

public:
	CDlg_Opinions(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Opinions)
	enum { IDD = IDD_OPINIONS };
	CWebBrowser2	m_wndWB;
	//}}AFX_DATA

	
	LPCSTR m_pszUrl;

	
	//{{AFX_VIRTUAL(CDlg_Opinions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	vmsDocHostUIHandler m_UIHandler;
	vmsWebBrowserEvents m_wbEvents;

	
	//{{AFX_MSG(CDlg_Opinions)
	virtual BOOL OnInitDialog();
	afx_msg void OnAbort();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
