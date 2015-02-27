/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "WndSplitter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CWndSplitter::CWndSplitter()
{
	m_ratio = 0.5;
	m_dim   = 5;
	m_startDrag = -1; 
	m_dim1min = m_dim2min = 3;
	m_bDragging = FALSE;
}

CWndSplitter::~CWndSplitter()
{

}

BOOL CWndSplitter::Create(HINSTANCE hInst, HWND hWndParent, WndSplitterType enType)
{
	m_type = enType;
	m_wndParent = hWndParent;
	LPCSTR pszClassName = m_type == WST_VERTICAL ? "WndSplitter_Vertical" : "WndSplitter_Horizontal";

	WNDCLASS wc = {
		0, _wndProc, 0, 0, hInst, NULL, LoadCursor (NULL, m_type == WST_VERTICAL ? IDC_SIZEWE : IDC_SIZENS),
			(HBRUSH) (COLOR_3DFACE+1), NULL, pszClassName
	};

	RegisterClass (&wc);

	m_wndSplitter = CreateWindow (pszClassName, NULL, WS_CHILD|WS_VISIBLE, 0, 0, 5, 5, hWndParent,
		NULL, hInst, 0);

	SetWindowLong (m_wndSplitter, GWL_USERDATA, (LONG) this);

	return TRUE;
}

LRESULT CALLBACK CWndSplitter::_wndProc(HWND hWnd, UINT uMsg, WPARAM wp, LPARAM lp)
{
	CWndSplitter *pThis = (CWndSplitter*) GetWindowLong (hWnd, GWL_USERDATA);

	switch (uMsg)
	{
		case WM_PAINT:
			pThis->OnPaint ();			
			return 0;

		case WM_LBUTTONDOWN:
			pThis->OnLButtonDown ();
			break;

		case WM_MOUSEMOVE:
			if (wp & MK_LBUTTON)
				pThis->OnMouseDrag (MAKEPOINTS (lp));
			return 0;

		case WM_LBUTTONUP:
			pThis->OnLButtonUp (MAKEPOINTS (lp));
			return 0;

		case WM_CAPTURECHANGED:
			pThis->OnCaptureChanged ();
			return 0;
	}

	return DefWindowProc (hWnd, uMsg, wp, lp);
}

void CWndSplitter::SetWnd1(HWND hWnd)
{
	m_wnd1 = hWnd;
}

void CWndSplitter::SetWnd2(HWND hWnd)
{
	m_wnd2 = hWnd;
}

void CWndSplitter::ApplyRatio()
{
	RECT rcParent, rcWnd1, rcWnd2, rcSplit;

	GetClientRect (m_wndParent, &rcParent);

	rcWnd1.top = rcWnd1.left = 0;
	rcWnd2.right = rcParent.right; rcWnd2.bottom = rcParent.bottom;

	
	

	switch (m_type)
	{
		case WST_VERTICAL:
			rcWnd1.right = (LONG)(rcParent.right * m_ratio + 0.5f) - m_dim / 2;
			rcWnd1.bottom = rcParent.bottom+1;
			rcWnd2.left = rcWnd1.right + m_dim + 1;
			rcWnd2.top = 0;
			rcSplit.top = 0; rcSplit.left = rcWnd1.right;
			rcSplit.right = rcWnd2.left; rcSplit.bottom = rcParent.bottom;
			break;

		case WST_HORIZONTAL:
			rcWnd1.right = rcParent.right+1; 
			rcWnd1.bottom = (LONG)(rcParent.bottom * m_ratio + 0.5f) - m_dim / 2;
			rcWnd2.top = rcWnd1.bottom + m_dim + 1;
			rcWnd2.left = 0;
			rcSplit.top = rcWnd1.bottom; rcSplit.left = 0;
			rcSplit.right = rcParent.right; rcSplit.bottom = rcWnd2.top;
			break;

		default:
			return;
	}

	MoveWindow (m_wnd1, rcWnd1.left, rcWnd1.top, rcWnd1.right - rcWnd1.left, 
		rcWnd1.bottom - rcWnd1.top, TRUE);

	MoveWindow (m_wnd2, rcWnd2.left, rcWnd2.top, rcWnd2.right - rcWnd2.left, 
		rcWnd2.bottom - rcWnd2.top, TRUE);

	MoveWindow (m_wndSplitter, rcSplit.left, rcSplit.top, rcSplit.right - rcSplit.left, 
		rcSplit.bottom - rcSplit.top, TRUE);
}

void CWndSplitter::OnPaint()
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rc;

	GetClientRect (m_wndSplitter, &rc);

	hdc = BeginPaint (m_wndSplitter, &ps);

	if (m_type == WST_VERTICAL)
		DrawVerticalFrame (hdc, 0, rc.right-1, 0, rc.bottom);
	else
		DrawHorizontalFrame (hdc, 0, rc.bottom-1, 0, rc.right);

	EndPaint (m_wndSplitter, &ps);
}

void CWndSplitter::OnLButtonDown()
{
	

	
	SetCapture (m_wndSplitter);

	m_bDragging = TRUE;	

	RECT rc;
	GetWindowRect (m_wndSplitter, &rc);

	

	if (m_type == WST_VERTICAL)
		m_drag = rc.left + m_dim / 2;
	else
		m_drag = rc.top + m_dim / 2;

	m_startDrag = m_drag;

	
	DrawSizingFrame ();
}

void CWndSplitter::DrawSizingFrame()
{
	HDC hdc = GetDC (m_wndParent);
	RECT rc;

	GetWindowRect (m_wndSplitter, &rc);

	
	

	if (m_type == WST_VERTICAL)
	{
		rc.left = m_drag - m_dim / 2 + 2;
		rc.right = rc.left + m_dim - 2;
	}
	else
	{
		rc.top = m_drag - m_dim / 2 + 2;
		rc.bottom = m_drag + m_dim - 2;
	}

	ScreenToClient (m_wndParent, (LPPOINT) &rc);
	ScreenToClient (m_wndParent, ((LPPOINT) &rc)+1);

	

	SetROP2 (hdc, R2_NOTXORPEN);

	HPEN hPen  = CreatePen (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));
	HBRUSH hbr = CreateSolidBrush (GetSysColor (COLOR_3DSHADOW));
	HGDIOBJ hOldPen, hOldBr;

	hOldPen = SelectObject (hdc, hPen);
	hOldBr  = SelectObject (hdc, hbr);

	
	Rectangle (hdc, rc.left, rc.top, rc.right, rc.bottom);

	SelectObject (hdc, hOldPen);
	SelectObject (hdc, hOldBr);

	DeleteObject (hPen);
	DeleteObject (hbr);

	ReleaseDC (m_wndParent, hdc);
}

void CWndSplitter::OnMouseDrag(POINTS pt)
{
	if (m_startDrag == -1)
		return;

	POINT Pt;

	Pt.x = pt.x;
	Pt.y = pt.y;

	RECT rcParent;

	GetWindowRect (m_wndParent, &rcParent);
	ClientToScreen (m_wndSplitter, &Pt);

	if (m_type == WST_VERTICAL)
	{
		
		if (Pt.x < rcParent.left + m_dim1min || Pt.x > rcParent.right - m_dim2min)
			return;	

		
		DrawSizingFrame ();
		m_drag = Pt.x;
	}
	else
	{
		if (Pt.y < rcParent.top + m_dim1min || Pt.y > rcParent.bottom - m_dim2min )
			return;

		DrawSizingFrame ();
		m_drag = Pt.y;
	}

	
	DrawSizingFrame ();
}

void CWndSplitter::OnLButtonUp(POINTS )
{
	if (m_bDragging == FALSE)
		return;

	m_bDragging = FALSE;	

	DrawSizingFrame ();	

	RECT rcParent;
	GetClientRect (m_wndParent, &rcParent);

	float parentDim = m_type == WST_VERTICAL ? (FLOAT) rcParent.right : (FLOAT) rcParent.bottom;
	
	

	
	float dRatio = (m_drag - m_startDrag) / parentDim;

	m_ratio += dRatio;	

	if (m_ratio < 0)
		m_ratio = 0;
	else if (m_ratio > 1)
		m_ratio = 1;

	ApplyRatio ();	

	m_startDrag = -1;

	ReleaseCapture ();	

	InvalidateRect (m_wndSplitter, NULL, FALSE);
}

void CWndSplitter::OnCaptureChanged()
{
	if (m_startDrag != -1)
	{
		

		
		DrawSizingFrame ();
		m_startDrag = -1;	
		InvalidateRect (m_wndSplitter, NULL, FALSE);
	}
}

void CWndSplitter::SetMinDimensions(int wnd1, int wnd2)
{
	m_dim1min = wnd1;
	m_dim2min = wnd2;
}

void CWndSplitter::SetRatio(float fRatio)
{
	m_ratio = fRatio;
}

void CWndSplitter::RecalRatio(BOOL bWnd1MustNotResize)
{
	RECT rcWnd, rcParent;
	HWND hWnd = bWnd1MustNotResize ? m_wnd1 : m_wnd2;

	GetWindowRect (hWnd, &rcWnd);
	GetClientRect (m_wndParent, &rcParent);

	

	int wndDim = m_type == WST_VERTICAL ? rcWnd.right-rcWnd.left : rcWnd.bottom-rcWnd.top;
	int parentDim = m_type == WST_VERTICAL ? rcParent.right : rcParent.bottom;

	wndDim += m_dim / 2;
	
	if (bWnd1MustNotResize)
		m_ratio = (FLOAT) wndDim / parentDim;
	else
		m_ratio = 1.0f - ((FLOAT) wndDim / parentDim);
}	

float CWndSplitter::GetRatio()
{
	return m_ratio;
}
