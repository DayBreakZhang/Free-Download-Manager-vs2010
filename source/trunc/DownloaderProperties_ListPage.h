/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIES_LISTPAGE_H__95A06FC6_024D_4DBA_9F0A_29774E53FBEF__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIES_LISTPAGE_H__95A06FC6_024D_4DBA_9F0A_29774E53FBEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsDownloadsMgr.h"

class CDownloaderProperties_ListPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CDownloaderProperties_ListPage)

public:
	CDownloaderProperties_ListPage();
	~CDownloaderProperties_ListPage();

	//{{AFX_DATA(CDownloaderProperties_ListPage)
	enum { IDD = IDD_DLDR_LIST };
	CComboBox	m_wndVirName;
	CComboBox	m_wndWhenDel;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloaderProperties_ListPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	BOOL DlgToVir();
	
	void AvirToDlg();
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CDownloaderProperties_ListPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeWhendel();
	afx_msg void OnAutodel();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDetailedlog();
	afx_msg void OnSizeinbytes();
	afx_msg void OnVircheck();
	afx_msg void OnSelchangeVirname();
	afx_msg void OnEditchangeVirname();
	afx_msg void OnChangeArgs();
	afx_msg void OnChangeVirexts();
	afx_msg void OnChoosevir();
	afx_msg void OnShowdlddlg();
	afx_msg void OnDontsavelogs();
	afx_msg void OnUsewc();
	afx_msg void OnChangeWcSize();
	afx_msg void OnPreventStandby();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
