/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFE_ListLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CHFE_ListLog::CHFE_ListLog()
{
}

CHFE_ListLog::~CHFE_ListLog()
{
}

BEGIN_MESSAGE_MAP(CHFE_ListLog, CWnd)
	//{{AFX_MSG_MAP(CHFE_ListLog)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CHFE_ListLog::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x209121))
		return FALSE;

	return TRUE;
}

int CHFE_ListLog::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bShowLog = _App.View_HFELog ();
	
	if (!m_wndFileList.Create (this))
		return -1;

	if (!m_wndLog.Create (this))
		return -1;

	if (!m_wndSplitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL))
		return -1;

	m_wndSplitter.SetWnd1 (m_wndFileList);
	m_wndSplitter.SetWnd2 (m_wndLog);
	m_wndSplitter.SetRatio (_App.View_SplitterRatio ("HFE_FL_L"));

	ShowLog (m_bShowLog);
	
	return 0;
}

void CHFE_ListLog::OnSize(UINT , int cx, int cy) 
{
	if (m_bShowLog)
		m_wndSplitter.ApplyRatio ();
	else
		m_wndFileList.MoveWindow (0, 0, cx, cy);
}

void CHFE_ListLog::ShowLog(BOOL bShow)
{
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;
	m_wndLog.ShowWindow (nShow);
	::ShowWindow (m_wndSplitter.m_wndSplitter, nShow);

	m_bShowLog = bShow;
	_App.View_HFELog (bShow);

	RECT rc;
	GetClientRect (&rc);
	OnSize (0, rc.right, rc.bottom);
}

void CHFE_ListLog::SaveState()
{
	_App.View_SplitterRatio ("HFE_FL_L", m_wndSplitter.GetRatio ());
	m_wndFileList.SaveState ("HFEFileList");
	m_wndLog.SaveState ("HFELog");
}

void CHFE_ListLog::ApplyLanguage()
{
	m_wndFileList.ApplyLanguage ();
	m_wndLog.ApplyLanguage ();
}
