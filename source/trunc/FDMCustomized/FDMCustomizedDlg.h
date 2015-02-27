/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMCUSTOMIZEDDLG_H__85BCBDE7_D0DB_403E_99E2_A19CF5DE79B6__INCLUDED_)
#define AFX_FDMCUSTOMIZEDDLG_H__85BCBDE7_D0DB_403E_99E2_A19CF5DE79B6__INCLUDED_

#include "vmsFDMCustomized.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CFDMCustomizedDlg : public CDialog
{

public:
	CFDMCustomizedDlg(CWnd* pParent = NULL);	

	//{{AFX_DATA(CFDMCustomizedDlg)
	enum { IDD = IDD_FDMCUSTOMIZED_DIALOG };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CFDMCustomizedDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	
	//}}AFX_VIRTUAL

protected:
	void FromDialog();
	void UpdateEnabled();
	vmsFDMCustomized m_FDMCustomized;
	HICON m_hIcon;

	
	//{{AFX_MSG(CFDMCustomizedDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGenerate();
	afx_msg void OnBanners();
	afx_msg void OnAddbanners();
	afx_msg void OnAddbutton();
	afx_msg void OnCustomizebutton();
	afx_msg void OnCustomizerMore();
	afx_msg void OnAddbuttonIe();
	afx_msg void OnBrowseieico();
	afx_msg void OnSetuplist();
	afx_msg void OnAdddownloads();
	afx_msg void OnLaunch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
