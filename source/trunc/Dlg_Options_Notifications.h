/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_NOTIFICATIONS_H__E70A10B5_C819_4513_AD87_61363BA1867B__INCLUDED_)
#define AFX_DLG_OPTIONS_NOTIFICATIONS_H__E70A10B5_C819_4513_AD87_61363BA1867B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Notifications : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Notifications(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Notifications)
	enum { IDD = IDD_OPTIONS_NOTIFICATIONS };
	CSpinButtonCtrl	m_wndT2Spin;
	CSpinButtonCtrl	m_wndTSpin;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Notifications)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_Notifications)
	virtual BOOL OnInitDialog();
	afx_msg void OnUseballoon();
	afx_msg void OnUsesounds();
	afx_msg void OnCustomize();
	afx_msg void OnUseOndoneWnds();
	afx_msg void OnUsetimeout2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
