/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_WPD_IL_ADD_H__017907C0_EA61_4001_A7DD_14A4393DC21A__INCLUDED_)
#define AFX_DLG_WPD_IL_ADD_H__017907C0_EA61_4001_A7DD_14A4393DC21A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_WPD_IL_Add : public CDialog
{

public:
	BOOL m_bSubfoldersAlso, m_bThisOnly;
	CString m_strURL;
	CDlg_WPD_IL_Add(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_WPD_IL_Add)
	enum { IDD = IDD_WPD_IL_ADD };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_WPD_IL_Add)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_WPD_IL_Add)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
