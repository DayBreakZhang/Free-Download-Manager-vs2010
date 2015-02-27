/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPDATEDLG_H__6107B08B_7B97_4773_956E_31EADCF6C993__INCLUDED_)
#define AFX_UPDATEDLG_H__6107B08B_7B97_4773_956E_31EADCF6C993__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CUpdateDlg : public CDialog
{

public:
	
	bool m_bCheckingByUser;
	CUpdateDlg(CWnd* pParent = NULL);   

	//{{AFX_DATA(CUpdateDlg)
	enum { IDD = IDD_UPDATE };
	CStatic	m_wndSpeed;
	CStatic	m_wndSize;
	CStatic	m_wndTimeLeft;
	CProgressCtrl	m_wndProgress;
	CStatic	m_wndMsg;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CUpdateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	void OnUpdateDone();
	
	void ShowGroup (BOOL bFirstGroup);
	
	static void _UpdateMgrDescEvents (LPCSTR pszEvent, LPVOID lp);
	static void _UpdateMgrEvents (fsUpdateMgrEvent ev, LPVOID lp);
	
	void ShowUpdateInfo ();
	
	void CheckForUpdate();
	
	
	//{{AFX_MSG(CUpdateDlg)
	virtual BOOL OnInitDialog();
	
	afx_msg void OnDesc();
	afx_msg void OnUpdate();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg void OnHelp();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
