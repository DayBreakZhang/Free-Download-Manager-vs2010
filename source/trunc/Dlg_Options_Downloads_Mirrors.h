/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_OPTIONS_DOWNLOADS_MIRRORS_H__102C2D12_DA22_451A_8150_EA2A49310A50__INCLUDED_)
#define AFX_DLG_OPTIONS_DOWNLOADS_MIRRORS_H__102C2D12_DA22_451A_8150_EA2A49310A50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Dlg_Options_Page.h"
#include "resource.h"

class CDlg_Options_Downloads_Mirrors : public CDlg_Options_Page
{

public:
	BOOL Apply();
	CString get_PageShortTitle();
	CString get_PageTitle();
	CDlg_Options_Downloads_Mirrors(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_Options_Downloads_Mirrors)
	enum { IDD = IDD_OPTIONS_DOWNLOADS_MIRRORS };
	CComboBox	m_wndMinSizeDim;
	CComboBox	m_wndMirrServers;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_Options_Downloads_Mirrors)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlg_Options_Downloads_Mirrors)
	virtual BOOL OnInitDialog();
	afx_msg void OnAuto();
	afx_msg void OnMaxmirrors();
	afx_msg void OnCalcspeed();
	afx_msg void OnRecalcspeed();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
