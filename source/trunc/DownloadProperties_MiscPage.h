/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_MISCPAGE_H__04ACEE9B_D798_466C_943F_AE1DB910DB9A__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_MISCPAGE_H__04ACEE9B_D798_466C_943F_AE1DB910DB9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

class CDownloadProperties_MiscPage : public CPropertyPage
{
	friend class CDownloadPropertiesSheet;

	DECLARE_DYNCREATE(CDownloadProperties_MiscPage)

public:
	CDownloadProperties_MiscPage();
	~CDownloadProperties_MiscPage();

	//{{AFX_DATA(CDownloadProperties_MiscPage)
	enum { IDD = IDD_DOWNLOAD_MISC };
	CComboBox	m_wndSCR;
	CComboBox	m_wndAER;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_MiscPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	BOOL m_bCreateExtModified;
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	BOOL m_bMayRename;		
	BOOL m_bExtModified;	
	void UpdateEnabled();
	DLDS_LIST *m_pvDlds;
	
	//{{AFX_MSG(CDownloadProperties_MiscPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeAer();
	afx_msg void OnSelchangeScr();
	afx_msg void OnReservespace();
	afx_msg void OnUseext();
	afx_msg void OnChangeExt();
	afx_msg void OnDontrestartifnoresume();
	afx_msg void OnFilenotfound();
	afx_msg void OnAccdenied();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnUsecreateext();
	afx_msg void OnChangeCreateext();
	afx_msg void OnUsehiddenflag();
	afx_msg void OnAppendcomment();
	afx_msg void OnLaunchwhendone();
	afx_msg void OnRetrfiledate();
	afx_msg void OnGenerateinfofile();
	afx_msg void OnRenameatrestart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
