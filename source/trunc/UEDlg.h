/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UEDLG_H__F4079676_7D6F_4DE9_95B9_9B53265504D4__INCLUDED_)
#define AFX_UEDLG_H__F4079676_7D6F_4DE9_95B9_9B53265504D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CUEDlg : public CDialog
{

public:
	CUEDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CUEDlg)
	enum { IDD = IDD_UNHEXC };
	CStatic	m_wndIcon;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CUEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	CFont m_fntBold;

	
	//{{AFX_MSG(CUEDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
