/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_NEWDOWNLOADPAGE_H__2616B7AC_D3FB_4E79_B003_89FB2025ADEE__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_NEWDOWNLOADPAGE_H__2616B7AC_D3FB_4E79_B003_89FB2025ADEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"

class CDownloaderProperties_NewDownloadPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_NewDownloadPage)

public:
	CDownloaderProperties_NewDownloadPage();
	~CDownloaderProperties_NewDownloadPage();

	//{{AFX_DATA(CDownloaderProperties_NewDownloadPage)
	enum { IDD = IDD_DLDR_NEWDLD };
	CButton	m_btnCreateGroup2;
	CDownloadsGroupsComboBox m_wndGroups2;
	CDownloadsGroupsComboBox m_wndGroups;
	CButton	m_btnCreateGroup;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_NewDownloadPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloaderProperties_NewDownloadPage)
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnCreategroup();
	afx_msg void OnAdvanced();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnAutostart();
	afx_msg void OnUsezip();
	afx_msg void OnNewgrp0();
	afx_msg void OnNewgrp1();
	afx_msg void OnNewgrp2();
	afx_msg void OnCreategroup2();
	afx_msg void OnSetgrpsfldr();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
