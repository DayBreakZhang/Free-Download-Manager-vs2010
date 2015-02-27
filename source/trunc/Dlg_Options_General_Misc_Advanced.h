/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_GENERAL_MISC_ADVANCED_H__DB640351_CC7B_418F_8C66_6962D2FEDEBE__INCLUDED_)
#define AFX_DLG_OPTIONS_GENERAL_MISC_ADVANCED_H__DB640351_CC7B_418F_8C66_6962D2FEDEBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_General_Misc_Advanced : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_General_Misc_Advanced(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_General_Misc_Advanced)
	enum { IDD = IDD_OPTIONS_GENERAL_MISC_ADV };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_General_Misc_Advanced)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_General_Misc_Advanced)
	virtual BOOL OnInitDialog();
	afx_msg void OnKeep1();
	afx_msg void OnKeep2();
	afx_msg void OnBrowse();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
