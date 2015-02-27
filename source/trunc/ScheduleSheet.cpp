/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ScheduleSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CScheduleSheet, CPropertySheet)

CScheduleSheet::CScheduleSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CScheduleSheet::CScheduleSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CScheduleSheet::~CScheduleSheet()
{
}

BEGIN_MESSAGE_MAP(CScheduleSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CScheduleSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CScheduleSheet::Init(fsSchedule *task, BOOL bWTSPage)
{
	m_wts.m_task = m_hts.m_task = task = m_advanced.m_task = task;

	if (bWTSPage)
		AddPage (&m_wts);

	AddPage (&m_hts);
	AddPage (&m_advanced);
}

BOOL CScheduleSheet::IsNeedRecalculateStartTime()
{
	return m_hts.m_bNeedRecalcStartTime;
}

BOOL CScheduleSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;  
	              
}
