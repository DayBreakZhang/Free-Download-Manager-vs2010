/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_DOWNLOAD_ONHIDE_H__7FF36867_2F00_429C_A7BA_C989A63F4C96__INCLUDED_)
#define AFX_DLG_DOWNLOAD_ONHIDE_H__7FF36867_2F00_429C_A7BA_C989A63F4C96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum vmsDlg_Download_OnHide_Result
{
	DDOR_SHOW,					
	DDOR_DONTSHOW,				
	DDOR_DONTSHOWFORTHISDLD,	
};

class CDlg_Download_OnHide : public CDialog
{

public:
	
	BOOL m_bDontAskAgain;
	
	vmsDlg_Download_OnHide_Result m_enResult;

	CDlg_Download_OnHide(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Download_OnHide)
	enum { IDD = IDD_DLDDIALOG_HIDE };
	CStatic	m_wndIcon;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Download_OnHide)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Download_OnHide)
	virtual void OnOK();
	afx_msg void OnShow();
	afx_msg void OnDontshow();
	afx_msg void OnDontshowForthisdld();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
