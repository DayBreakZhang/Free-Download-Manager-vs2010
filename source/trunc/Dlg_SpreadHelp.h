/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SPREADHELP_H__32DAF8FA_FD2D_4CB9_A227_FF4BAEB8CE95__INCLUDED_)
#define AFX_DLG_SPREADHELP_H__32DAF8FA_FD2D_4CB9_A227_FF4BAEB8CE95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_SpreadHelp : public CDialog
{

public:
	CDlg_SpreadHelp(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_SpreadHelp)
	enum { IDD = IDD_SPREADHELP };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_SpreadHelp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_SpreadHelp)
	afx_msg void OnViewlinkcode();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
