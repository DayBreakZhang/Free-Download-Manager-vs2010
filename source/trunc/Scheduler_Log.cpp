/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Scheduler_Log.h"
#include "ShedulerWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CShedulerWnd *_pwndScheduler;

CScheduler_Log::CScheduler_Log()
{
	m_bAutoScroll = TRUE;
}

CScheduler_Log::~CScheduler_Log()
{
}

BEGIN_MESSAGE_MAP(CScheduler_Log, CWndLog)
	//{{AFX_MSG_MAP(CScheduler_Log)
	ON_COMMAND (ID_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CScheduler_Log::OnClear() 
{
	CWndLog::OnClear ();
	_pwndScheduler->m_evMgr.clear ();
}

BOOL CScheduler_Log::Create(CWnd *pParent)
{
	if (!CWndLog::Create (pParent))
		return FALSE;

	ReadState ("SchedulerLog");

	return TRUE;
}

