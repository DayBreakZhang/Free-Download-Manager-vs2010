/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_SITEMGR_H__EA7E9260_C24B_4F6F_8857_FC709E17721C__INCLUDED_)
#define AFX_DLG_OPTIONS_SITEMGR_H__EA7E9260_C24B_4F6F_8857_FC709E17721C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_SiteMgr : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_SiteMgr(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_SiteMgr)
	enum { IDD = IDD_OPTIONS_SITEMGR };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_SiteMgr)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateEnabled();

	
	//{{AFX_MSG(CDlg_Options_SiteMgr)
	virtual BOOL OnInitDialog();
	afx_msg void OnDelall();
	afx_msg void OnUse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
