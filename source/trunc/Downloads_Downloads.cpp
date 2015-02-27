/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Downloads.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Downloads::CDownloads_Downloads()
{
}

CDownloads_Downloads::~CDownloads_Downloads()
{
}

BEGIN_MESSAGE_MAP(CDownloads_Downloads, CWnd)
	//{{AFX_MSG_MAP(CDownloads_Downloads)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Downloads::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW),
		(HBRUSH) (COLOR_WINDOW+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x121))
		return FALSE;

	return TRUE;
}

int CDownloads_Downloads::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bShowDLInfo = _App.View_DLInfo ();
	
	m_tasks.Create (this);
	m_info.Create (this);
	m_splitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL);
	m_splitter.SetWnd1 (m_tasks.m_hWnd);
	m_splitter.SetWnd2 (m_info.m_hWnd);
	m_splitter.SetMinDimensions (50, 50);
	float fRatio = _App.View_SplitterRatio ("Downloads_DL_LOG");
	if (fRatio < 0.1f)
		fRatio = 0.1f;
	m_splitter.SetRatio (fRatio);

	ShowDLInfo (m_bShowDLInfo);

	return 0;
}

void CDownloads_Downloads::OnSize(UINT, int cx, int cy) 
{
	if (m_bShowDLInfo)
		m_splitter.ApplyRatio ();	
	else
		m_tasks.MoveWindow (0, 0, cx, cy);
}

BOOL CDownloads_Downloads::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	

	
	
	return CWnd::OnNotify(wParam, lParam, pResult);
}

void CDownloads_Downloads::ShowDLInfo(BOOL bShow)
{
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;
	m_info.ShowWindow (nShow);
	::ShowWindow (m_splitter.m_wndSplitter, nShow);

	m_bShowDLInfo = bShow;
	_App.View_DLInfo (m_bShowDLInfo);

	RECT rc;
	GetClientRect (&rc);
	OnSize (0, rc.right, rc.bottom);
}

void CDownloads_Downloads::SaveState()
{
	_App.View_SplitterRatio ("Downloads_DL_LOG", m_splitter.GetRatio ());
	m_tasks.SaveState ("DownloadsList");
	m_info.SaveState ();
}

void CDownloads_Downloads::ApplyLanguage()
{
	m_tasks.ApplyLanguage ();
	m_info.ApplyLanguage ();
}

void CDownloads_Downloads::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	m_tasks.SetFocus ();
}

BOOL CDownloads_Downloads::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CWnd::OnEraseBkgnd(pDC);
}
