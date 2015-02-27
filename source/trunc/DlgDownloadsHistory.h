/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DLGDOWNLOADSHISTORY_H__51A1E39F_E731_481C_B54B_B4F7786443BD__INCLUDED_)
#define AFX_DLGDOWNLOADSHISTORY_H__51A1E39F_E731_481C_B54B_B4F7786443BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CDlgDownloadsHistory : public CDialog
{

public:
	CDlgDownloadsHistory(CWnd* pParent = NULL);   

	//{{AFX_DATA(CDlgDownloadsHistory)
	enum { IDD = IDD_DOWNLOADSHISTORY_SETTINGS };
	CSpinButtonCtrl	m_wndSpin;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CDlgDownloadsHistory)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	void UpdateEnabled();

	
	//{{AFX_MSG(CDlgDownloadsHistory)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnUse();
	afx_msg void OnDelrecthatexists();
	afx_msg void OnClearhistory();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
