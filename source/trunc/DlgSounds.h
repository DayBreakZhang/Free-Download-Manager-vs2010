/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGSOUNDS_H__DE9D62DA_141D_4890_A4E6_0A36C0D52154__INCLUDED_)
#define AFX_DLGSOUNDS_H__DE9D62DA_141D_4890_A4E6_0A36C0D52154__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgSounds : public CDialog
{

public:
	CDlgSounds(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgSounds)
	enum { IDD = IDD_SOUNDS };
	CListCtrl	m_wndSnds;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgSounds)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	
	int GetCurSelSnd();
	
	CString GetSndFile (int iItem);
	void UpdateEnabled();
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();

	
	//{{AFX_MSG(CDlgSounds)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnClickSounds(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkSounds(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetsound();
	afx_msg void OnRemove();
	afx_msg void OnTest();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString SndFile (CString strSndFile);
};

//{{AFX_INSERT_LOCATION}}

#endif 
