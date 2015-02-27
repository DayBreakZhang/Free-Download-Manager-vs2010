/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGFIND_H__92D8F2C5_48F7_41FF_B5C4_3000B48EFB93__INCLUDED_)
#define AFX_DLGFIND_H__92D8F2C5_48F7_41FF_B5C4_3000B48EFB93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgFind : public CDialog
{

public:
	CDlgFind(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgFind)
	enum { IDD = IDD_FIND };
	CComboBox	m_wndWhat;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgFind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled  ();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgFind)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	
	afx_msg void OnAdvanced();
	virtual void OnOK();
	afx_msg void OnEditchangeFindwhat();
	afx_msg void OnSelchangeFindwhat();
	
	afx_msg void OnFilename();
	afx_msg void OnUrl();
	afx_msg void OnComment();
	afx_msg void OnLocalname();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
