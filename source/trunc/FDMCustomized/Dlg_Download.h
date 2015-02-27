/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_DOWNLOAD_H__B8B4135D_A89C_4A28_91E8_F1D25C6F3AB5__INCLUDED_)
#define AFX_DLG_DOWNLOAD_H__B8B4135D_A89C_4A28_91E8_F1D25C6F3AB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Download : public CDialog
{

public:
	CDlg_Download(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Download)
	enum { IDD = IDD_DOWNLOAD };
	CString	m_strURL;
	CString	m_strReferer;
	CString	m_strComment;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Download)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlg_Download)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
