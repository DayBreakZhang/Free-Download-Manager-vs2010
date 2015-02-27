/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_GENERAL_H__E0C160A4_E3D5_41B5_8864_5510A8F2361E__INCLUDED_)
#define AFX_DLG_OPTIONS_GENERAL_H__E0C160A4_E3D5_41B5_8864_5510A8F2361E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_General : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_General(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_General)
	enum { IDD = IDD_OPTIONS_GENERAL };
	CComboBox	m_wndSkins;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_General)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_General)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
