/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_GENERAL_HISTORY_H__E193A3A5_C20D_4686_AC8A_9C2670F15FFB__INCLUDED_)
#define AFX_DLG_OPTIONS_GENERAL_HISTORY_H__E193A3A5_C20D_4686_AC8A_9C2670F15FFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_General_History : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_General_History(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_General_History)
	enum { IDD = IDD_OPTIONS_GENERAL_HISTORY };
	CSpinButtonCtrl	m_wndSpin3;
	CSpinButtonCtrl	m_wndSpin2;
	CSpinButtonCtrl	m_wndSpin1;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_General_History)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_General_History)
	virtual BOOL OnInitDialog();
	afx_msg void OnUsehist();
	afx_msg void OnClearhistory();
	afx_msg void OnUse2();
	afx_msg void OnClearhistory2();
	afx_msg void OnDelrecthatexists();
	afx_msg void OnMaxnumber();
	afx_msg void OnDelrecthatexists2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
