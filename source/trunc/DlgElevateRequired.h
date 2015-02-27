/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGELEVATEREQUIRED_H__954967F0_64BB_4C05_8083_DF9DDC30E850__INCLUDED_)
#define AFX_DLGELEVATEREQUIRED_H__954967F0_64BB_4C05_8083_DF9DDC30E850__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "resource.h"

class CDlgElevateRequired : public CDialog
{

public:
	CDlgElevateRequired(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgElevateRequired)
	enum { IDD = IDD_ELEVATE_REQ };
	CString	m_strMsg;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgElevateRequired)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlgElevateRequired)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
