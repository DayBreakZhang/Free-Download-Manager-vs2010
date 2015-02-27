/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_CUSTOMIZER_H__EC05A25A_AE53_4C7F_A4AA_E100B1B5EC0A__INCLUDED_)
#define AFX_DLG_CUSTOMIZER_H__EC05A25A_AE53_4C7F_A4AA_E100B1B5EC0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Customizer : public CDialog
{

public:
	CDlg_Customizer(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Customizer)
	enum { IDD = IDD_CUSTOMIZER };
	CString	m_strURL;
	CString	m_strIcon;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Customizer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlg_Customizer)
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
