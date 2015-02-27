/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGCREATEFLVDOWNLOADSBYWEBPAGEURL_H__3E8E74FF_26BB_4F88_B8A8_E05ECFF076D8__INCLUDED_)
#define AFX_DLGCREATEFLVDOWNLOADSBYWEBPAGEURL_H__3E8E74FF_26BB_4F88_B8A8_E05ECFF076D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "resource.h"

class CDlgCreateFlvDownloadsByWebPageUrl : public CDialog
{

public:
	CString m_strWebPageUrl;
	CDlgCreateFlvDownloadsByWebPageUrl(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgCreateFlvDownloadsByWebPageUrl)
	enum { IDD = IDD_CREATEFLVDOWNLOADS_BY_WEBPAGE_URL };
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgCreateFlvDownloadsByWebPageUrl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgCreateFlvDownloadsByWebPageUrl)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
