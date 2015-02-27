/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "MyBalloon.h"
#include "TrayIconPosition.h"
#include "vmsWindowsStatusBar.h"
#include "MyBalloon_Content.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CMyBalloon::CMyBalloon(CMyBalloon_Content* p) : m_pContent (p)
{
	m_ptAnchor = CPoint (0,0);
	m_pwndParent = NULL;
}

CMyBalloon::~CMyBalloon()
{
	vmsWindowsStatusBar::o ().RestoreBarStateIfRequired ();
}

BEGIN_MESSAGE_MAP(CMyBalloon, CWnd)
	//{{AFX_MSG_MAP(CMyBalloon)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_KILLFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL vmsSetLayeredWindowAttributes (HWND hWnd, COLORREF clrKey, BYTE bAlpha, DWORD dwFlags)
{
	typedef BOOL (WINAPI*fntSetLayeredWndAttr) (HWND, COLORREF, BYTE, DWORD);
	static fntSetLayeredWndAttr _pfnSetLWA = NULL;

	if (_pfnSetLWA == NULL)
	{
		
		
		HMODULE hDll = LoadLibrary (_T ("User32.Dll"));
		
		if (hDll)
			_pfnSetLWA = (fntSetLayeredWndAttr) GetProcAddress (hDll, _T ("SetLayeredWindowAttributes"));
		
		if (_pfnSetLWA == NULL)
			return FALSE;
	}
	
	return _pfnSetLWA (hWnd, clrKey, bAlpha, dwFlags);
}

void CMyBalloon::Create(CWnd *pwndParent, bool bTrayBalloon, BYTE byteTrancparency)
{
	m_pwndParent = pwndParent;	
	m_bTrayBalloon = bTrayBalloon;

	if (bTrayBalloon)
		_TrayMgr.TestIcon ();

	if (bTrayBalloon)
	{
		CWnd *pwndTray = pwndParent;
		pwndParent = FindWindow (_T ("Shell_TrayWnd"), NULL);
		if (pwndParent)
		{
			m_bTrayBalloon = true;

			vmsWindowsStatusBar::o ().MakeSureBarIsVisible ();
			
			CTrayIconPosition ip; 
			ip.InitializePositionTracking (pwndTray->m_hWnd, 0);
			CPoint pt;
			ip.GetTrayIconPosition (pt);
			pt.x += 6; pt.y += 3;
			setAnchorPoint (pt);
		}
		else
		{
			pwndParent = pwndTray; 
		}
	}

	if (byteTrancparency != 255)
	{
		CRect rc (0,0,0,0);
		CWnd::CreateEx (0x80000, AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), NULL, NULL), 
			NULL, WS_POPUP, rc, pwndParent, 0);
		vmsSetLayeredWindowAttributes (m_hWnd, 0, byteTrancparency, 2);
	}
	else
	{	
		CRect rc (0,0,0,0);
		CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), NULL, NULL), 
			"", WS_POPUP, rc, pwndParent, 0);
	}

	CRect rc;
	m_pContent->Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), NULL, NULL), NULL,
		WS_CHILD | WS_VISIBLE, rc, this, 0);

	SetupWindowRgn ();

	SetWindowPos (NULL, 0, 0, 0, 0, 
		SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW | SWP_NOACTIVATE);
}

void CMyBalloon::SetupWindowRgn()
{
	CRect rcWnd (0,0,0,0);
	
	CSize sizeReq = m_pContent->getRequiredSize ();
	
	rcWnd.right = sizeReq.cx;
	rcWnd.bottom = sizeReq.cy;

	rcWnd.InflateRect (3, 3);

	rcWnd.left += 3; rcWnd.right += 3;
	rcWnd.top  += 3; rcWnd.bottom += 3;

	int cxScreen = GetSystemMetrics (SM_CXSCREEN);
	int cyScreen = GetSystemMetrics (SM_CYSCREEN);
	
	m_bLeaderAtRight = false; m_bLeaderAtTop = false;
	if (m_ptAnchor.x + rcWnd.Width () > cxScreen)
		m_bLeaderAtRight = true;
	if (m_ptAnchor.y - rcWnd.Height () - CY_LEADER < 0)
		m_bLeaderAtTop = true;

	if (m_bLeaderAtTop)
	{
		rcWnd.top += CY_LEADER;
		rcWnd.bottom += CY_LEADER;
	}

	CPoint ptLeader [3];

	ptLeader[0].x = m_bLeaderAtRight ? rcWnd.Width () - CX_ROUNDED - CX_LEADER_MARGIN : 
	CX_ROUNDED + CX_LEADER_MARGIN;
	ptLeader[0].y = m_bLeaderAtTop ? rcWnd.top + CY_ROUNDED : rcWnd.Height() - CY_ROUNDED;
	
	ptLeader[1].x = ptLeader[0].x;
	ptLeader[1].y = m_bLeaderAtTop ? ptLeader[0].y - CY_ROUNDED - CY_LEADER : ptLeader[0].y + CY_ROUNDED + CY_LEADER;
	
	ptLeader[2].x = m_bLeaderAtRight ? ptLeader[0].x - CX_ROUNDED - CX_LEADER - CX_LEADER_MARGIN - 10 : 
		ptLeader[0].x + CX_ROUNDED + CX_LEADER + CX_LEADER_MARGIN + 10;
	ptLeader[2].y = m_bLeaderAtTop ? rcWnd.top + CY_ROUNDED + CY_LEADER : rcWnd.Height() - CY_ROUNDED - CY_LEADER;

	CRgn rgnLeader, rgnContent;

	rgnContent.CreateRoundRectRgn (rcWnd.left, rcWnd.top, rcWnd.right, rcWnd.bottom, CX_ROUNDED, CY_ROUNDED);
	rgnLeader.CreatePolygonRgn (ptLeader, 3, ALTERNATE);
	CRgn rgn; rgn.CreateRectRgn (0, 0, rcWnd.Width (), rcWnd.Height () + CY_LEADER);
	rgn.CombineRgn (&rgnContent, &rgnLeader, RGN_OR);

	SetWindowPos (CWnd::FromHandle (HWND_TOPMOST), 
		(m_bLeaderAtRight ? m_ptAnchor.x - rcWnd.Width () + CX_ROUNDED + CX_LEADER_MARGIN : m_ptAnchor.x - CX_ROUNDED - CX_LEADER_MARGIN),
		(m_bLeaderAtTop ? m_ptAnchor.y : m_ptAnchor.y - rcWnd.Height () - CY_LEADER), 
		rcWnd.Width (), rcWnd.Height () + CY_LEADER, 0);

	SetWindowRgn (rgn, FALSE);
}

void CMyBalloon::OnPaint() 
{
	CPaintDC dc(this); 

	CRgn rgn; 
	rgn.CreateRectRgn (0,0,0,0);
	GetWindowRgn (rgn);
	
	CBrush brWnd; brWnd.CreateSolidBrush (m_pContent->getBkColor ());
	CBrush br1; br1.CreateSolidBrush (m_pContent->getTextColor ());
	dc.FillRgn (&rgn, &brWnd);
	dc.FrameRgn (&rgn, &br1, 1, 1);
}

void CMyBalloon::setAnchorPoint(CPoint pt)
{
	m_ptAnchor = pt;
	if (m_hWnd)
		SetupWindowRgn ();
}

void CMyBalloon::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CloseBalloon (true);
	
	CWnd::OnLButtonDown(nFlags, point);
}

void CMyBalloon::CloseBalloon(bool bByUser)
{
	DestroyWindow ();

	if (m_bTrayBalloon)
	{
		vmsWindowsStatusBar::o ().RestoreBarStateIfRequired ();
		m_bTrayBalloon = false;
	}
}

void CMyBalloon::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);

	if (m_pContent->m_hWnd)
	{
		

		m_pContent->MoveWindow (2, m_bLeaderAtTop ? CY_LEADER+2 : 2,
			cx - 4, m_pContent->getRequiredSize ().cy);
	}
}

void CMyBalloon::OnDestroy() 
{
	m_pwndParent->PostMessage (WM_MYBALLOON_CLOSED, 0, (LPARAM)this);
	CWnd::OnDestroy();
}

void CMyBalloon::OnKillFocus(CWnd* pNewWnd) 
{
	CWnd::OnKillFocus(pNewWnd);
	
	if (false == m_bTrayBalloon)
		CloseBalloon (false);	
}
