/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

//{{AFX_INCLUDES()
#include "webbrowser2.h"
#include "DlgPI2_WbCustomization.h"	
//}}AFX_INCLUDES
#if !defined(AFX_DLGPI2_H__75A6D135_611E_4248_97CF_B590843F743D__INCLUDED_)
#define AFX_DLGPI2_H__75A6D135_611E_4248_97CF_B590843F743D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgPI2 : public CDialog
{

public:
	bool m_bCancelledByUser;
	CDlgPI2(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgPI2)
	enum { IDD = IDD_PI2 };
	CWebBrowser2	m_wb;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgPI2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void getHtml (std::string &str);
	CString m_strHtmlFile;
	CDlgPI2_WbCustomization m_wbCust;

	
	//{{AFX_MSG(CDlgPI2)
	virtual BOOL OnInitDialog();
	afx_msg void OnCancel2();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	//}}AFX_MSG
	afx_msg void OnShowWhatIsFavSites();
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
