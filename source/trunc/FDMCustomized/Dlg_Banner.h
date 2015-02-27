/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_BANNER_H__C9A6F3E1_BD30_44CA_9762_1BE45940E770__INCLUDED_)
#define AFX_DLG_BANNER_H__C9A6F3E1_BD30_44CA_9762_1BE45940E770__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Banner : public CDialog
{

public:
	CDlg_Banner(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Banner)
	enum { IDD = IDD_BANNER_ADD };
	CString	m_strFile;
	CString	m_strURL;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Banner)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlg_Banner)
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
