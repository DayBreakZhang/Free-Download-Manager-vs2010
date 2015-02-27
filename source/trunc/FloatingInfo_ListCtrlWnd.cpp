/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FloatingInfo_ListCtrlWnd.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFloatingInfo_ListCtrlWnd::CFloatingInfo_ListCtrlWnd()
{
}

CFloatingInfo_ListCtrlWnd::~CFloatingInfo_ListCtrlWnd()
{
}

BEGIN_MESSAGE_MAP(CFloatingInfo_ListCtrlWnd, CListCtrlEx)
	//{{AFX_MSG_MAP(CFloatingInfo_ListCtrlWnd)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CFloatingInfo_ListCtrlWnd::OnDblclk(NMHDR* , LRESULT* pResult) 
{
	CMainFrame *pMainFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	if (pMainFrame->IsIconic ())
		pMainFrame->OnShowmainwindow ();
	else
		pMainFrame->ShowWindow (SW_MINIMIZE);

	*pResult = 0;
}

void CFloatingInfo_ListCtrlWnd::OnRclick(NMHDR* , LRESULT* pResult) 
{
	AfxGetApp ()->m_pMainWnd->SendMessage (WM_SHOWTRAYMENU);
	*pResult = 0;
}
