/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_URLWITHLOGINDLG_H__E283B8C6_8EC6_4167_A07F_5C8D8D0A223B__INCLUDED_)
#define AFX_URLWITHLOGINDLG_H__E283B8C6_8EC6_4167_A07F_5C8D8D0A223B__INCLUDED_

#include "fsDownloadsMgr.h"	
#include "DownloadProperties.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CUrlWithLoginDlg : public CDialog
{

public:
	fsDownload_NetworkProperties m_dnp;	
	int m_CaptionLngID;	
	CString m_strUrl;	
	CString m_strUser;	
	CString m_strPassword;	

	CUrlWithLoginDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CUrlWithLoginDlg)
	enum { IDD = IDD_URLWITHLOGIN };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CUrlWithLoginDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void WrongURL();
	BOOL UpdateDNP();
	vmsDownloadSmartPtr m_dld;
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CUrlWithLoginDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnUselogin();
	afx_msg void OnAdvanced();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
