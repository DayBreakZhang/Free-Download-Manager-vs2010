/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGDL_H__D4E5F35D_B01D_4814_B022_CC8A7FA9FA90__INCLUDED_)
#define AFX_DLGDL_H__D4E5F35D_B01D_4814_B022_CC8A7FA9FA90__INCLUDED_

#include "fsDownloadMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgDL : public CDialog
{

public:
	bool m_bCancelled;
	bool m_bSucceeded;
	CString m_strFile;
	CString m_strUrl;
	CString m_strDlName;
	CDlgDL(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgDL)
	enum { IDD = IDD_DL };
	CProgressCtrl	m_wndProgress;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgDL)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	fsDownloadMgr m_dldr;

	
	//{{AFX_MSG(CDlgDL)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
