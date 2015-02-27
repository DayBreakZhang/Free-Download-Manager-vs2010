/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_LISTOFDOWNLOADS_H__23748B24_D386_4C96_9E76_AAF62F274630__INCLUDED_)
#define AFX_DLG_LISTOFDOWNLOADS_H__23748B24_D386_4C96_9E76_AAF62F274630__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsFDMCustomized.h"

class CDlg_ListOfDownloads : public CDialog
{

public:
	vmsFDMCustomized* m_pCust;
	CDlg_ListOfDownloads(vmsFDMCustomized* pCust, CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_ListOfDownloads)
	enum { IDD = IDD_DOWNLOADS };
	CListCtrl	m_wndDownloads;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_ListOfDownloads)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();

	
	//{{AFX_MSG(CDlg_ListOfDownloads)
	virtual BOOL OnInitDialog();
	afx_msg void OnClickDownloads(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkDownloads(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownDownloads(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnAdd();
	afx_msg void OnRemove();
	afx_msg void OnModify();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
