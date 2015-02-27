/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_TIMELIMIT_H__445D0BE4_6E87_402C_9597_A2784F6A7B9C__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_TIMELIMIT_H__445D0BE4_6E87_402C_9597_A2784F6A7B9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Downloads_TimeLimit : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageTitle();
	CString get_PageShortTitle();
	CDlg_Options_Downloads_TimeLimit(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_TimeLimit)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_TIMELIMIT };
	CComboBox	m_wndTo;
	CComboBox	m_wndFrom;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_TimeLimit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateEnabled();
	void FillTimes (CComboBox* pbox);

	
	//{{AFX_MSG(CDlg_Options_Downloads_TimeLimit)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetlimit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
