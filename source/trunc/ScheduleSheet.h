/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SCHEDULESHEET_H__95158EF1_1653_4F5E_94C4_36C7F7EAD5CF__INCLUDED_)
#define AFX_SCHEDULESHEET_H__95158EF1_1653_4F5E_94C4_36C7F7EAD5CF__INCLUDED_

#include "Schedule_WTSPage.h"	
#include "Schedule_HTSPage.h"	
#include "Schedule_AdvancedPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CScheduleSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CScheduleSheet)

public:
	CScheduleSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CScheduleSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CScheduleSheet)
	//}}AFX_VIRTUAL

public:
	BOOL IsNeedRecalculateStartTime();
	void Init (fsSchedule *task, BOOL bWTSPage = TRUE);
	virtual ~CScheduleSheet();

	
protected:
	CSchedule_AdvancedPage m_advanced;	
	CSchedule_HTSPage m_hts;	
	CSchedule_WTSPage m_wts;	
	//{{AFX_MSG(CScheduleSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
