/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "resource.h"

class CDlgUnhExc2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgUnhExc2)

public:
	CDlgUnhExc2(CWnd* pParent = NULL);   
	virtual ~CDlgUnhExc2();

	enum { IDD = IDD_UNHEXC2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    

	DECLARE_MESSAGE_MAP()
public:
	bool m_bRestartApp;
	CStatic m_wndIcon;
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

protected:
	CFont m_fntBold;
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_strDescription;
};
