/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_NEWDLD_H__F4BB3446_ECEB_44C6_9FBA_CBBA5CC96E42__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_NEWDLD_H__F4BB3446_ECEB_44C6_9FBA_CBBA5CC96E42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"
#include "DownloadsGroupsComboBox.h"

class CDlg_Options_Downloads_NewDld : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Downloads_NewDld(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_NewDld)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_NEWDLD };
	CButton	m_btnCreateGroup2;
	CDownloadsGroupsComboBox m_wndGroups2;
	CDownloadsGroupsComboBox m_wndGroups;
	CButton	m_btnCreateGroup;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_NewDld)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_Downloads_NewDld)
	virtual BOOL OnInitDialog();
	afx_msg void OnCreategroup();
	afx_msg void OnCreategroup2();
	afx_msg void OnSetgrpsfldr();
	afx_msg void OnNewgrp0();
	afx_msg void OnNewgrp1();
	afx_msg void OnNewgrp2();
	afx_msg void OnAdvanced();
	afx_msg void OnHtmlspiderDefdldstgs();
	afx_msg void OnBtDefdldstgs();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
