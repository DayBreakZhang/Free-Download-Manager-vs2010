/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_LOGINDLG_H__E7A2BE26_4411_4496_A75B_DA425618CEEB__INCLUDED_)
#define AFX_LOGINDLG_H__E7A2BE26_4411_4496_A75B_DA425618CEEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CLoginDlg : public CDialog
{

public:
	
	
	CString m_strServer;
	CLoginDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CLoginDlg)
	enum { IDD = IDD_REQLOGIN };
	CString	m_strUser;		
	CString	m_strPassword;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CLoginDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
