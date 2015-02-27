/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_H__0A6E437E_A9EF_45E0_8AA0_C6F77EB042DB__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_H__0A6E437E_A9EF_45E0_8AA0_C6F77EB042DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Downloads : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Downloads(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads)
	enum { IDD = IDD_OPTIONS_DOWNLOADS };
	CComboBox	m_wndVirName;
	CComboBox	m_wndWhenDel;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	BOOL DlgToVir();
	void AvirToDlg();
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_Downloads)
	virtual BOOL OnInitDialog();
	afx_msg void OnVircheck();
	afx_msg void OnChoosevir();
	afx_msg void OnUsewc();
	afx_msg void OnSelchangeVirname();
	afx_msg void OnCheckifmal2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
