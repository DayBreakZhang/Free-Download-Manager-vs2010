/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUiWindowsHoster.h"
#include "vmsRenderer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

vmsUiWindowsHoster::vmsUiWindowsHoster()
{
	m_pUiWindow = NULL;
}

vmsUiWindowsHoster::~vmsUiWindowsHoster()
{
}

BEGIN_MESSAGE_MAP(vmsUiWindowsHoster, CWnd)
	//{{AFX_MSG_MAP(vmsUiWindowsHoster)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SIZE()
	ON_WM_KILLFOCUS()
	ON_WM_TIMER()
	ON_WM_CREATE()
	ON_WM_ENTERIDLE()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void vmsUiWindowsHoster::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CWnd::OnLButtonDown(nFlags, point);

	if (m_pUiWindow)
	{
		CPoint pt = point;
		pt.x -= m_pUiWindow->getPos ()->left;
		pt.y -= m_pUiWindow->getPos ()->top;
		m_pUiWindow->OnLButtonDown (pt);
	}
}

void vmsUiWindowsHoster::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CWnd::OnLButtonUp(nFlags, point);

	if (m_pUiWindow)
	{
		CPoint pt = point;
		pt.x -= m_pUiWindow->getPos ()->left;
		pt.y -= m_pUiWindow->getPos ()->top;
		m_pUiWindow->OnLButtonUp (pt);
	}
}

void vmsUiWindowsHoster::OnMouseMove(UINT nFlags, CPoint point) 
{
	CWnd::OnMouseMove(nFlags, point);

	if (m_pUiWindow)
	{
		CPoint pt = point;
		pt.x -= m_pUiWindow->getPos ()->left;
		pt.y -= m_pUiWindow->getPos ()->top;
		m_pUiWindow->OnMouseMove (pt);
	}
}

BOOL vmsUiWindowsHoster::PreCreateWindow(CREATESTRUCT& cs) 
{
	cs.style |= WS_CLIPCHILDREN;
	return CWnd::PreCreateWindow(cs);
}

void vmsUiWindowsHoster::AttachUiWindow(vmsUiWindow *pUiWindow)
{
	ASSERT (m_pUiWindow == NULL);
	ASSERT (IsWindow (m_hWnd));
	if (m_pUiWindow)
		return;
	m_pUiWindow = pUiWindow;
	m_pUiWindow->setHosterWindow (this);
}

void vmsUiWindowsHoster::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	if (m_pUiWindow)
		m_pUiWindow->setPos (0, 0, cx, cy);	
}

void vmsUiWindowsHoster::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);
	
	if (m_pUiWindow)
		m_pUiWindow->OnKillHosterWindowFocus ();
}

void vmsUiWindowsHoster::OnTimer(UINT nIDEvent) 
{
	CWnd::OnTimer(nIDEvent);

	if (m_pUiWindow)
		m_pUiWindow->OnIdle ();
}

int vmsUiWindowsHoster::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	SetTimer (0x1000, 100, NULL);
	
	return 0;
}

void vmsUiWindowsHoster::OnEnterIdle(UINT nWhy, CWnd* pWho) 
{
	CWnd::OnEnterIdle(nWhy, pWho);
	
	
	
}

void vmsUiWindowsHoster::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CWnd::OnRButtonDown(nFlags, point);

	if (m_pUiWindow)
	{
		CPoint pt = point;
		pt.x -= m_pUiWindow->getPos ()->left;
		pt.y -= m_pUiWindow->getPos ()->top;
		m_pUiWindow->OnRButtonDown (pt);
	}
}

void vmsUiWindowsHoster::OnPaint() 
{
	CPaintDC dc(this); 
	
	vmsRenderer r;
	CRect rc; GetClientRect (&rc);
	CDC *pdcDraw = r.Start (&dc, &rc);
	ASSERT (m_pUiWindow != NULL);
	m_pUiWindow->Draw (pdcDraw);
	r.End ();
}
