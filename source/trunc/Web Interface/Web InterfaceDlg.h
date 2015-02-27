/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WEBINTERFACEDLG_H__179132A9_F658_4881_8F70_2820D92AF9EB__INCLUDED_)
#define AFX_WEBINTERFACEDLG_H__179132A9_F658_4881_8F70_2820D92AF9EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpServer.h"	
#include "vmsFdmWebInterfaceServer.h"	

class CWebInterfaceDlg : public CDialog
{

public:
	CWebInterfaceDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CWebInterfaceDlg)
	enum { IDD = IDD_WEBINTERFACE_DIALOG };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWebInterfaceDlg)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	UINT m_nShutdownMsg;
	void UpdateAddress();
	void ShowTrayMenu();
	afx_msg LRESULT OnTrayMsg (WPARAM, LPARAM);
	vmsFdmWebInterfaceServer m_fdmServer;
	vmsHttpServer m_http;
	HICON m_hIcon;

	
	//{{AFX_MSG(CWebInterfaceDlg)
	virtual BOOL OnInitDialog();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnConfigure();
	afx_msg void OnShutdown();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnOpenInBrowser();
	afx_msg void OnUsepwd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
