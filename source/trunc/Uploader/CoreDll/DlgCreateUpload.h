/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGCREATEUPLOAD_H__4E40394E_13C9_47C9_8032_4E40778BE0F8__INCLUDED_)
#define AFX_DLGCREATEUPLOAD_H__4E40394E_13C9_47C9_8032_4E40778BE0F8__INCLUDED_

#include "vmsUploadPackageImpl.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "urlwnd.h"

class CDlgCreateUpload : public CDialog
{

public:
	vmsUploadPackageImpl m_pkg;
	CDlgCreateUpload(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgCreateUpload)
	enum { IDD = IDD_CREATE_UPLOAD };
	CComboBox	m_wndCompress;
	CComboBox	m_wndNumberOfDlds;
	CComboBox	m_wndDaysToKeep;
	CListCtrl	m_wndFiles;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgCreateUpload)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

protected:
	CFont m_fntUnderline;
	CUrlWnd m_wndTerms;
	void InitializeTerms();
	void ApplyLanguage();
	void UpdateEnabled ();
	CImageList m_imgsFiles;
	CToolBar m_tbFiles;

	
	//{{AFX_MSG(CDlgCreateUpload)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSetpwd();
	afx_msg void OnAdvancedinfo();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	afx_msg void OnAddfiles();
	afx_msg void OnAddfolder();
};

//{{AFX_INSERT_LOCATION}}

#endif 
