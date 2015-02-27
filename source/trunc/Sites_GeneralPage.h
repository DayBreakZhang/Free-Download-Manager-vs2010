/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITES_GENERALPAGE_H__0C57B8D1_4411_4034_98BF_49BCB918ECC0__INCLUDED_)
#define AFX_SITES_GENERALPAGE_H__0C57B8D1_4411_4034_98BF_49BCB918ECC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsSitesMgr.h"
#include "Sites_AdvancedPage.h"
#include "DownloadsGroupsComboBox.h"

class CSites_GeneralPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSites_GeneralPage)

public:
	CSites_AdvancedPage* m_advanced;	
	int m_iSiteIndex;		
	fsSiteInfo* m_pSite;	
	void SetMode(bool bIsAddingSite);

	CSites_GeneralPage();
	~CSites_GeneralPage();

	//{{AFX_DATA(CSites_GeneralPage)
	enum { IDD = IDD_SITES_GENERAL };
	CSpinButtonCtrl	m_wndMaxConnsSpin;
	CDownloadsGroupsComboBox	m_wndGroups;
	CButton	m_btnCreateGroup;
	CComboBox	m_wndSite;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSites_GeneralPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	void UpdateEnabled();
	
	//{{AFX_MSG(CSites_GeneralPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnUselogin();
	afx_msg void OnUsemaxconns();
	afx_msg void OnUsedefgroup();
	afx_msg void OnUseftppassive();
	afx_msg void OnEditchangeSite();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg void OnChangeMaxconns();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnCreategroup();
	afx_msg void OnSelchangeSite();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDontsendlist2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	bool m_bIsAddingSite;

};

//{{AFX_INSERT_LOCATION}}

#endif 
