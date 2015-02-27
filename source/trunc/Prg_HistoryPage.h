/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_HISTORYPAGE_H__5A80A274_AC6F_442D_B994_E4F687D25E51__INCLUDED_)
#define AFX_PRG_HISTORYPAGE_H__5A80A274_AC6F_442D_B994_E4F687D25E51__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_HistoryPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPrg_HistoryPage)

public:
	CPrg_HistoryPage();
	~CPrg_HistoryPage();

	//{{AFX_DATA(CPrg_HistoryPage)
	enum { IDD = IDD_PRG_HISTORY };
	CSpinButtonCtrl	m_wndSpin2;
	CSpinButtonCtrl	m_wndSpin1;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_HistoryPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void UpdateEnabled();
	void ApplyLanguage();
	void PrepareCHMgr(CPoint point);
	
	//{{AFX_MSG(CPrg_HistoryPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnUsehist();
	afx_msg void OnFoldersonly();
	afx_msg void OnDelrecthatexists();
	afx_msg void OnMaxnumber();
	afx_msg void OnClearhistory();
	afx_msg void OnChangeDays();
	afx_msg void OnChangeMaxnumberval();
	afx_msg void OnSwitchdlhist();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
