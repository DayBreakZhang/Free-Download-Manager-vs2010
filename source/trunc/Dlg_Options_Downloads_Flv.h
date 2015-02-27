/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_FLV_H__A179B91A_92BF_42E4_BF6D_7F642A4AD542__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_FLV_H__A179B91A_92BF_42E4_BF6D_7F642A4AD542__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Downloads_Flv : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageTitle();
	CString get_PageShortTitle();
	CDlg_Options_Downloads_Flv(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_Flv)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_FLV };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_Flv)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	DWORD m_dwOldFSDI, m_dwInitialFSDI;
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_Downloads_Flv)
	virtual BOOL OnInitDialog();
	afx_msg void OnEnableMonitoring();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
