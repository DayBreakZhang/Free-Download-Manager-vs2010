/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_BANNERS_H__A8098E34_1D37_4954_B9E3_A0991E30479B__INCLUDED_)
#define AFX_DLG_BANNERS_H__A8098E34_1D37_4954_B9E3_A0991E30479B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsFDMCustomized.h"

class CDlg_Banners : public CDialog
{

public:
	CDlg_Banners(vmsFDMCustomized* pCust, CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Banners)
	enum { IDD = IDD_BANNERS };
	CListCtrl	m_wndBanners;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Banners)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	vmsFDMCustomized* m_pCust;

	
	//{{AFX_MSG(CDlg_Banners)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickBanners(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkBanners(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownBanners(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnRemove();
	afx_msg void OnModify();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
