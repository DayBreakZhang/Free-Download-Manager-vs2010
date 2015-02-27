/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TPDLD_GENERAL_H__E93D9E61_B97A_4D79_B588_53826EB058D1__INCLUDED_)
#define AFX_TPDLD_GENERAL_H__E93D9E61_B97A_4D79_B588_53826EB058D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"

class CTpDld_General : public CPropertyPage
{
	DECLARE_DYNCREATE(CTpDld_General)

public:
	
	
	BOOL m_bNeedUpdateTasks;
	
	DLDS_LIST* m_pvDlds;

	CTpDld_General();
	~CTpDld_General();

	//{{AFX_DATA(CTpDld_General)
	enum { IDD = IDD_TPDLD_GENERAL };
	CButton	m_btnChooseFolder;
	CDownloadsGroupsComboBox	m_wndGroups;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CTpDld_General)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	
	void ReadSavedIn();
	
	BOOL m_bCommentModified;
	void UpdateEnabled();
	
	//{{AFX_MSG(CTpDld_General)
	virtual BOOL OnInitDialog();
	
	
	afx_msg void OnChoosefolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
