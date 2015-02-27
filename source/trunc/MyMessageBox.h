/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_MYMESSAGEBOX_H__611389DA_FD32_41A3_A149_12BDFFA82B97__INCLUDED_)
#define AFX_MYMESSAGEBOX_H__611389DA_FD32_41A3_A149_12BDFFA82B97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CMyMessageBox : public CDialog
{

public:
	CMyMessageBox(CWnd* pParent = NULL);   

	//{{AFX_DATA(CMyMessageBox)
	enum { IDD = IDD_MYMESSAGEBOX };
	CButton	m_wndCheckbox;
	CButton	m_wndBtn3;
	CButton	m_wndBtn2;
	CButton	m_wndBtn1;
	CStatic	m_wndMsg;
	CStatic	m_wndIcon;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CMyMessageBox)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

public:
	bool m_bTopMost;
	CString m_strCheckBoxText;	
	bool m_bChecked;			
	CString m_strText;			
	CString m_strTitle;			
	CString m_strBtn1Text, 
		m_strBtn2Text, m_strBtn3Text; 
	HICON m_hIcon;				

protected:
	
	
	//{{AFX_MSG(CMyMessageBox)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtn1();
	afx_msg void OnBtn2();
	afx_msg void OnBtn3();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

inline UINT MyMessageBox (CWnd* pwndParent, LPCSTR pszText, LPCSTR pszTitle,
	LPCSTR pszCheckbox, LPCSTR pszSysIcon = NULL, LPCSTR pszBtn1Text = "OK", LPCSTR pszBtn2Text = NULL, 
	LPCSTR pszBtn3Text = NULL, bool bTopMost = false)
{
	CMyMessageBox mb (pwndParent);

	if (pszSysIcon)
		mb.m_hIcon = LoadIcon (NULL, pszSysIcon);

	mb.m_strBtn1Text = pszBtn1Text;

	if (pszBtn2Text)
	{
		mb.m_strBtn2Text = pszBtn2Text;
		if (pszBtn3Text)
			mb.m_strBtn3Text = pszBtn3Text;
	}

	if (pszCheckbox)
		mb.m_strCheckBoxText = pszCheckbox;

	mb.m_strText = pszText;
	mb.m_strTitle = pszTitle;

	mb.m_bTopMost = bTopMost;

	UINT nRet = _DlgMgr.DoModal (&mb);

	if (mb.m_bChecked)
		nRet |= 0x00010000;

	return nRet;
}

//{{AFX_INSERT_LOCATION}}

#endif 
