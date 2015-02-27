/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_PRG_MISCPAGE_H__F829ADE1_71F8_405B_A4DD_6200D772C33B__INCLUDED_)
#define AFX_PRG_MISCPAGE_H__F829ADE1_71F8_405B_A4DD_6200D772C33B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CPrg_MiscPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CPrg_MiscPage)

public:
	CPrg_MiscPage();
	~CPrg_MiscPage();

	//{{AFX_DATA(CPrg_MiscPage)
	enum { IDD = IDD_PRG_MISC };
	CComboBox	m_wndShutdownTout;
	CComboBox	m_wndLaunchDldTout;
	CComboBox	m_wndHangupTout;
	CComboBox	m_wndExitTout;
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CPrg_MiscPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	bool m_bDTAEChanged;
	bool m_bShutdownToutChanged;
	bool m_bExitToutChanged;
	bool m_bHangupToutChanged;
	UINT GetTimeoutForToutItem (CComboBox* pbox);
	void SelectToutItem (CComboBox* pbox, UINT uTimeout);
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	//{{AFX_MSG(CPrg_MiscPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnWhatisthis();
	afx_msg void OnAskforst();
	afx_msg void OnSelchangeExitTout();
	afx_msg void OnSelchangeHangupTout();
	afx_msg void OnSelchangeLaunchdldTout();
	afx_msg void OnSelchangeShutdownTout();
	afx_msg void OnDisablewdtaskafterexec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
