/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SCHEDULE_HTSPAGE_H__A30848B1_53AA_483B_B1AA_E976C166C892__INCLUDED_)
#define AFX_SCHEDULE_HTSPAGE_H__A30848B1_53AA_483B_B1AA_E976C166C892__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class CSchedule_HTSPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSchedule_HTSPage)

public:
	
	
	BOOL m_bNeedRecalcStartTime;
	struct fsSchedule* m_task;	
	CSchedule_HTSPage();
	~CSchedule_HTSPage();

	//{{AFX_DATA(CSchedule_HTSPage)
	enum { IDD = IDD_SCHEDULE_WHENTOSTART };
	CDateTimeCtrl	m_wndDate;
	CComboBox	m_wndEvent;
	CComboBox	m_wndEveryDim;
	//}}AFX_DATA
	CDateTimeCtrl	m_wndTime;	

	
	//{{AFX_VIRTUAL(CSchedule_HTSPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	
	void DataToDialog();
	void UpdateEnabled();
	
	//{{AFX_MSG(CSchedule_HTSPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnOnce();
	afx_msg void OnDaily();
	afx_msg void OnOnevery();
	afx_msg void OnOnevent();
	afx_msg void OnDatetimechangeTime(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDatetimechangeDate(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSun();
	afx_msg void OnWed();
	afx_msg void OnSat();
	afx_msg void OnMon();
	afx_msg void OnThu();
	afx_msg void OnTue();
	afx_msg void OnFri();
	afx_msg void OnChangeEvery();
	afx_msg void OnSelchangeEverydim();
	afx_msg void OnSelchangeEvent();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
