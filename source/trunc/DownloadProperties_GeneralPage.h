/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTIES_GENERALPAGE_H__4335D862_C2F6_45AF_ADDF_DCD5B003AA39__INCLUDED_)
#define AFX_DOWNLOADPROPERTIES_GENERALPAGE_H__4335D862_C2F6_45AF_ADDF_DCD5B003AA39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "DownloadsGroupsComboBox.h"

class CDownloadProperties_GeneralPage : public CPropertyPage
{
	friend class CDownloadPropertiesSheet;

	DECLARE_DYNCREATE(CDownloadProperties_GeneralPage)

public:
	
	BOOL m_bNeedProcessDownloads;
	BOOL m_bNeedUpdateTasks;	
	CDownloadProperties_GeneralPage();
	~CDownloadProperties_GeneralPage();

	//{{AFX_DATA(CDownloadProperties_GeneralPage)
	enum { IDD = IDD_DOWNLOAD_GENERAL };
	CDownloadsGroupsComboBox	m_wndGroups;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDownloadProperties_GeneralPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	
	void WriteAuthorization();
	BOOL m_bUserChanged, m_bPasswordChanged;	
	void UpdateEnabled();
	
	void ReadAuthorization();
	void ApplyLanguage();
	CString m_strUrl;	
	BOOL m_bCommentModified;	
	DLDS_LIST *m_pvDlds;	
	
	//{{AFX_MSG(CDownloadProperties_GeneralPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeGroups();
	afx_msg void OnChangeComment();
	afx_msg void OnChangeUrl();
	afx_msg void OnChangeSaveas();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnUselogin();
	afx_msg void OnChangeUser();
	afx_msg void OnChangePassword();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
