/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WAITFORCONFIRMATIONDLG_H__F6E1B9F6_A68E_4939_9F4B_CAD4C5616BD6__INCLUDED_)
#define AFX_WAITFORCONFIRMATIONDLG_H__F6E1B9F6_A68E_4939_9F4B_CAD4C5616BD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CWaitForConfirmationDlg : public CDialog
{

public:
	BOOL m_bDontAsk;
	LPCSTR m_pszIcon;
	
	
	
	void Init (LPCSTR pszMsg, UINT uWait = UINT_MAX, BOOL bShowDontAsk = FALSE, BOOL bNoIsDefault = FALSE, LPCSTR pszDontAskAgainText = NULL, LPCSTR pszMsgIfDontAskAgain = NULL);
	CWaitForConfirmationDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CWaitForConfirmationDlg)
	enum { IDD = IDD_WAITFORCONFIRMATION };
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWaitForConfirmationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void DoPostDlg();
	
	void ApplyLanguage();
	
	void SetTimerText();
	CString m_msg, m_strDontAskAgainText;
	CString m_strMsgIfDontAskAfain;
	BOOL m_bShowDontAsk;
	BOOL m_bNoIsDefault;
	UINT m_wait;

	
	//{{AFX_MSG(CWaitForConfirmationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnDontask();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
