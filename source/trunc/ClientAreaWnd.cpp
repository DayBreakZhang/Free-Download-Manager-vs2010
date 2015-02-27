/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "ClientAreaWnd.h"
#include "DownloadsWnd.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CClientAreaWnd::CClientAreaWnd()
{
}

CClientAreaWnd::~CClientAreaWnd()
{
}

BEGIN_MESSAGE_MAP(CClientAreaWnd, CWnd)
	//{{AFX_MSG_MAP(CClientAreaWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CClientAreaWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	m_bShowSWBar = _App.View_SWBar ();
	
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (FALSE == m_plugs2.Create (this))
		return -1;

	return 0;
}

void CClientAreaWnd::OnSize(UINT, int cx, int cy)
{
	if (cx == 0 || cy == 0)
		return;
	
	m_plugs2.MoveWindow (0, 0, cx, cy);
}

BOOL CClientAreaWnd::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		(HBRUSH)(COLOR_BTNFACE+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x111))
		return FALSE;

	return TRUE;
}

void CClientAreaWnd::SaveState()
{
}

void CClientAreaWnd::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	m_plugs2.SetFocus ();
}

BOOL CClientAreaWnd::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (_pwndDownloads->m_wndDownloads.m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		_pwndDownloads->m_wndDownloads.m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CWnd::OnEraseBkgnd(pDC);
}
