/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_WAITDLG_H__C786669C_04B0_4433_9DBB_C631CAD1F94D__INCLUDED_)
#define AFX_WAITDLG_H__C786669C_04B0_4433_9DBB_C631CAD1F94D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

struct ProcWaitInfo 
{
	HWND hwndDlg;
	
	LPVOID	lpParam1, lpParam2, lpParam3, lpParam4, lpParam5, lpParam6;
	
	BOOL	bNeedStop;
	
	BOOL	bWaitDone; 
	
	int		iProgress;	
};

class CWaitDlg : public CDialog
{

public:
	
	
	
	
	
	UINT StartWaiting (LPCSTR pszMessage, LPTHREAD_START_ROUTINE procWait, BOOL bEnableCancel, 
		LPVOID lpParam1 = NULL, LPVOID lpParam2 = NULL, LPVOID lpParam3 = NULL, 
		LPVOID lpParam4 = NULL, LPVOID lpParam5 = NULL, LPVOID lpParam6 = NULL, 
		BOOL bModal = TRUE);

	CWaitDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CWaitDlg)
	enum { IDD = IDD_WAITER };
	CProgressCtrl	m_wndProgress;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CWaitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	bool m_bNeedRelease;
	BOOL m_bCancel;	
	ProcWaitInfo m_info;	
	CString m_strMsg;	
	LPTHREAD_START_ROUTINE m_pfnThread;

	
	//{{AFX_MSG(CWaitDlg)
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
