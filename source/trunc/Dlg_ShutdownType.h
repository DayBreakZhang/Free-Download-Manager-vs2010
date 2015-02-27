/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SHUTDOWNTYPE_H__E2EA0620_9AD5_49EF_920D_D624E087829C__INCLUDED_)
#define AFX_DLG_SHUTDOWNTYPE_H__E2EA0620_9AD5_49EF_920D_D624E087829C__INCLUDED_

#include "fsScheduleMgr.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_ShutdownType : public CDialog
{

public:
	
	BOOL m_bRemember;
	
	fsShutdownType m_enType;

	CDlg_ShutdownType(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_ShutdownType)
	enum { IDD = IDD_SHUTDOWN_TYPE };
	CComboBox	m_wndShutdownType;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_ShutdownType)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlg_ShutdownType)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
