/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "VideoWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CVideoWindow::CVideoWindow()
{
}

CVideoWindow::~CVideoWindow()
{
}

BEGIN_MESSAGE_MAP(CVideoWindow, CWnd)
	//{{AFX_MSG_MAP(CVideoWindow)
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_MESSAGE (WM_VIDEONOTIFY, OnGraphMessage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CVideoWindow::Create(CWnd *pWndParent)
{
	CRect rc (2, 2, 150, 150);

	LPCSTR pszClass = AfxRegisterWndClass (CS_HREDRAW|CS_VREDRAW, LoadCursor (NULL, IDC_ARROW), (HBRUSH) (GetStockObject (BLACK_BRUSH)), NULL);

	if (FALSE == CWnd::CreateEx (WS_EX_CLIENTEDGE, pszClass, NULL,
			WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, rc, pWndParent, 0))
		return FALSE;

	return TRUE;
}

void CVideoWindow::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);

	if (cx && cy)
		m_player.AutoSize ();
}

int CVideoWindow::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_player.Initialize (m_hWnd);
	
	return 0;
}

LRESULT CVideoWindow::WindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	m_player.NotifyOwnerMessage (m_hWnd, message, wParam, lParam);
	return CWnd::WindowProc(message, wParam, lParam);
}

LRESULT CVideoWindow::OnGraphMessage(WPARAM, LPARAM)
{
	GetParent ()->SendMessage (WM_VIDEONOTIFY);
	return 0;
}
