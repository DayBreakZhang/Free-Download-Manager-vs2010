/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CHOOSEGROUP_H__D65076BB_AFA6_40EE_AD40_AF5833D88E91__INCLUDED_)
#define AFX_DLG_CHOOSEGROUP_H__D65076BB_AFA6_40EE_AD40_AF5833D88E91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "DownloadsGroupsComboBox.h"

class CDlg_ChooseGroup : public CDialog
{

public:
	
	vmsDownloadsGroupSmartPtr m_pGroup;
	CDlg_ChooseGroup(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_ChooseGroup)
	enum { IDD = IDD_CHOOSEGRP };
	CDownloadsGroupsComboBox	m_wndGroup;
	CButton	m_btnNewGrp;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_ChooseGroup)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_ChooseGroup)
	virtual BOOL OnInitDialog();
	afx_msg void OnCreategroup();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
