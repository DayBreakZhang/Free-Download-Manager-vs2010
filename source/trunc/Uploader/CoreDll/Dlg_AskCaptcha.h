/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLG_ASKCAPTCHA_H__B4D0BEB1_B0A2_46E1_B2E6_BC031806F679__INCLUDED_)
#define AFX_DLG_ASKCAPTCHA_H__B4D0BEB1_B0A2_46E1_B2E6_BC031806F679__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsImage_CtxFree.h"

class CDlg_AskCaptcha : public CDialog
{

public:
	vmsImage_CtxFree m_img;
	CString m_strValue;
	CDlg_AskCaptcha(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlg_AskCaptcha)
	enum { IDD = IDD_ASK_CAPTCHA };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlg_AskCaptcha)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	CRect m_rcImage;

	
	//{{AFX_MSG(CDlg_AskCaptcha)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
