/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_MONITORING_H__9A7FD4F1_02CF_4EEB_AAD6_A6C637B9F59A__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_MONITORING_H__9A7FD4F1_02CF_4EEB_AAD6_A6C637B9F59A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Downloads_Monitoring : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Downloads_Monitoring(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_Monitoring)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_MONITORING };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_Monitoring)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateElevateReq();
	BOOL m_bIEMenuWas;
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_Downloads_Monitoring)
	virtual BOOL OnInitDialog();
	afx_msg void OnCustomize();
	afx_msg void OnSkiplist();
	afx_msg void OnIe2();
	afx_msg void OnFirefox();
	afx_msg void OnDontmonsmall();
	afx_msg void OnAddtoiemenu();
	afx_msg void OnFfportver();
	afx_msg void OnOpera();
	afx_msg void OnNetscape();
	afx_msg void OnMozilla();
	afx_msg void OnSafari();
	afx_msg void OnChrome();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
