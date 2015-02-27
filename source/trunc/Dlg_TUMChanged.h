/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_TUMCHANGED_H__E8589D0F_8361_4762_A894_4844D6CE4357__INCLUDED_)
#define AFX_DLG_TUMCHANGED_H__E8589D0F_8361_4762_A894_4844D6CE4357__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_TUMChanged : public CDialog
{

public:
	CDlg_TUMChanged(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_TUMChanged)
	enum { IDD = IDD_TUM_CHANGED };
	CStatic	m_wndIMedium;
	CStatic	m_wndILight;
	CStatic	m_wndIHeavy;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_TUMChanged)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	CFont m_fntBold;

	
	//{{AFX_MSG(CDlg_TUMChanged)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
