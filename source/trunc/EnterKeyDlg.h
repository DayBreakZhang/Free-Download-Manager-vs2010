/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_ENTERKEYDLG_H__1EE27B98_B274_4E3A_A267_650E1738ACF6__INCLUDED_)
#define AFX_ENTERKEYDLG_H__1EE27B98_B274_4E3A_A267_650E1738ACF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CEnterKeyDlg : public CDialog
{

public:
	CEnterKeyDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CEnterKeyDlg)
	enum { IDD = IDD_ENTERKEY };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CEnterKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	BOOL RegisterKey (LPCSTR pszKey);
	void ApplyLanguage();

	
	//{{AFX_MSG(CEnterKeyDlg)
	afx_msg void OnGetkey();
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
