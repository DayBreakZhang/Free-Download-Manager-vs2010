/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_NOWDLG_H__0233D754_F11F_4297_BB2B_9031E69AAC15__INCLUDED_)
#define AFX_NOWDLG_H__0233D754_F11F_4297_BB2B_9031E69AAC15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CNOWDlg : public CDialog
{

public:
	enum fsConnectionType m_enCT;	
	CNOWDlg(CWnd* pParent = NULL);  

	//{{AFX_DATA(CNOWDlg)
	enum { IDD = IDD_OPTMASTER };
	CComboBox	m_wndCT;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CNOWDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CNOWDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
