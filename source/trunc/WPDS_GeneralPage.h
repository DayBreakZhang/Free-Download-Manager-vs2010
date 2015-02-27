/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WPDS_GENERALPAGE_H__D70C8C98_CD96_4924_9B27_2D8DD5D1CE50__INCLUDED_)
#define AFX_WPDS_GENERALPAGE_H__D70C8C98_CD96_4924_9B27_2D8DD5D1CE50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"

class CWPDS_GeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CWPDS_GeneralPage)

public:
	void ApplyLanguage();
	fsWebPageDownloaderPtr m_wpd;
	fsWPDSettings* m_wpds;
	CWPDS_GeneralPage();
	~CWPDS_GeneralPage();

	//{{AFX_DATA(CWPDS_GeneralPage)
	enum { IDD = IDD_WPDS_GENERAL };
	CDownloadsGroupsComboBox	m_wndGroups;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWPDS_GeneralPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	BOOL WriteAuthorization();
	void ReadAuthorization();
	void UpdateEnabled ();
	
	//{{AFX_MSG(CWPDS_GeneralPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnUselogin();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
