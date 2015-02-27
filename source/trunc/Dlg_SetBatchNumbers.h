/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_SETBATCHNUMBERS_H__0B532F73_29A2_4673_A538_A173472F4305__INCLUDED_)
#define AFX_DLG_SETBATCHNUMBERS_H__0B532F73_29A2_4673_A538_A173472F4305__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_SetBatchNumbers : public CDialog
{

public:
	
	CString m_strNumbers;

	CDlg_SetBatchNumbers(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_SetBatchNumbers)
	enum { IDD = IDD_SETUPBATCHNUMBERS };
	CListBox	m_wndSets;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_SetBatchNumbers)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	bool CheckSetOfNumbersParameters (int from, int to, int step, int wc);
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	void UpdateEnabled();

	
	//{{AFX_MSG(CDlg_SetBatchNumbers)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetofnumbers();
	afx_msg void OnSinglenumber();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnAdd();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
