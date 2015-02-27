/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SCHEDULE_ADVANCEDPAGE_H__2385770E_F598_49A9_9002_6B1F93C9FC62__INCLUDED_)
#define AFX_SCHEDULE_ADVANCEDPAGE_H__2385770E_F598_49A9_9002_6B1F93C9FC62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsScheduleMgr.h"

class CSchedule_AdvancedPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSchedule_AdvancedPage)

public:
	fsSchedule* m_task;	
	CSchedule_AdvancedPage();
	~CSchedule_AdvancedPage();

	//{{AFX_DATA(CSchedule_AdvancedPage)
	enum { IDD = IDD_SCHEDULE_ADVANCED };
		
		
	//}}AFX_DATA

	
	//{{AFX_VIRTUAL(CSchedule_AdvancedPage)
	public:
	virtual BOOL OnApply();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    
	//}}AFX_VIRTUAL

protected:
	void PrepareCHMgr(CPoint point);
	void ApplyLanguage();
	void UpdateEnabled();
	
	//{{AFX_MSG(CSchedule_AdvancedPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnUseconfirmation();
	afx_msg void OnUsewait();
	afx_msg void OnChangeDuring();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnWhatisthis();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnDisable();
	afx_msg void OnDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}

#endif 
