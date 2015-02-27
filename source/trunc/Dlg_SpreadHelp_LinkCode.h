/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

//{{AFX_INCLUDES()
#include "vmsImage_CtxFree.h"	
//}}AFX_INCLUDES
#if !defined(AFX_DLG_SPREADHELP_LINKCODE_H__8664BDE2_84DD_44B1_B4A5_1A43FD923030__INCLUDED_)
#define AFX_DLG_SPREADHELP_LINKCODE_H__8664BDE2_84DD_44B1_B4A5_1A43FD923030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "UrlWnd.h"

class CDlg_SpreadHelp_LinkCode : public CDialog
{

public:
	CDlg_SpreadHelp_LinkCode(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_SpreadHelp_LinkCode)
	enum { IDD = IDD_SPREADHELP_LINKCODE };
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_SpreadHelp_LinkCode)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	volatile BOOL m_bImgLoaded;
	void ApplyLanguage();
	CString get_HTMLCode();
	CFont m_fntFDM;
	void ShutdownThread();
	DWORD m_dwThrJob;
	BOOL m_bRunning;
	static DWORD WINAPI _threadImage (LPVOID lp);
	int m_iCurrentFrame;
	vmsImage_CtxFree m_img;

	
	//{{AFX_MSG(CDlg_SpreadHelp_LinkCode)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	virtual void OnOK();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnCancel();
	afx_msg void OnCopytoclipboard();
	afx_msg void OnMoreexamples();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
