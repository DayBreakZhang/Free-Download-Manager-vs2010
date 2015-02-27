/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGUPDATE_H__078D5F43_656F_4097_AA77_A85AB4D2E94A__INCLUDED_)
#define AFX_DLGUPDATE_H__078D5F43_656F_4097_AA77_A85AB4D2E94A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgUpdate : public CDialog
{

public:
	static BOOL StartUpdater (LPCSTR pszFile);
	CDlgUpdate(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgUpdate)
	enum { IDD = IDD_UPDATE };
	CProgressCtrl	m_wndProgress;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgUpdate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void ApplyLanguage();
	int m_iProgress;
	static DWORD WINAPI _threadDownload (LPVOID lp);
	CString m_strUpdateFile;

	
	//{{AFX_MSG(CDlgUpdate)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
