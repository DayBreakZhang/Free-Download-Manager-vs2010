/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DIALDLG_H__5FD947D4_2E26_4DFD_BF2E_0E8A3F551C47__INCLUDED_)
#define AFX_DIALDLG_H__5FD947D4_2E26_4DFD_BF2E_0E8A3F551C47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <ras.h>
#include <raserror.h>

class CDialDlg : public CDialog
{

public:
	static HRASCONN m_hConn;		
	
	void Init (struct fsDialInfo *dial);
	CDialDlg(CWnd* pParent);

	//{{AFX_DATA(CDialDlg)
	enum { IDD = IDD_DIAL };
	CComboBox	m_wndEntries;
	CListCtrl	m_wndLog;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDialDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void Cancel();
	void ApplyLanguage();
	
	
	
	afx_msg LRESULT OnNeedEndDialog (WPARAM wp, LPARAM);
	
	
	UINT m_cAgains;	
	static BOOL m_bNeedStop;	
	
	void StartConnect();
	UINT m_cAttempts;		
	
	void SleepInterval();
	
	void Log (LPCSTR pszRecord);
	RASDIALPARAMS m_rp;	
	
	
	static CDialDlg* m_pThis;
	
	
	static int m_pThisRefs;
	
	static VOID WINAPI _RasDialFunc (UINT, RASCONNSTATE state, DWORD dwError);
	static BOOL m_bInRasFunc;	
	fsDialInfo* m_dial;	

	
	//{{AFX_MSG(CDialDlg)
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	
	afx_msg void OnConnect();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	
	afx_msg void OnAuto();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
	
	static void Release_pThis();
};

//{{AFX_INSERT_LOCATION}}

#endif 
