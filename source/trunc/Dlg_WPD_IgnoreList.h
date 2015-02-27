/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_WPD_IGNORELIST_H__D2B83B5C_569F_4FB9_95BE_C4F0FFAB5484__INCLUDED_)
#define AFX_DLG_WPD_IGNORELIST_H__D2B83B5C_569F_4FB9_95BE_C4F0FFAB5484__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlg_WPD_IgnoreList : public CDialog
{

public:
	CDlg_WPD_IgnoreList(struct fsWPDSettings* wpds, CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_WPD_IgnoreList)
	enum { IDD = IDD_WPD_IGNORELIST };
	CListCtrl	m_wndList;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_WPD_IgnoreList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	void UpdateEnabled();
	fsWPDSettings* m_wpds;

	
	//{{AFX_MSG(CDlg_WPD_IgnoreList)
	afx_msg void OnAdd();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnRemove();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
