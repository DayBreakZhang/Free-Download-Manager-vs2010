/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_BUTTON_H__FB91C1C8_FC12_49FD_8BE7_A5C73544AD2C__INCLUDED_)
#define AFX_DLG_BUTTON_H__FB91C1C8_FC12_49FD_8BE7_A5C73544AD2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_Button : public CDialog
{

public:
	CDlg_Button(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Button)
	enum { IDD = IDD_BUTTONINFO };
	CString	m_strIco;
	CString	m_strText;
	CString	m_strURL;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Button)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:

	
	//{{AFX_MSG(CDlg_Button)
	afx_msg void OnBrowse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
