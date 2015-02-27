/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"			
#include "XInfoTip.h"		

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define CX_ROUNDED				12		
#define CY_ROUNDED				10		
#define CX_LEADER				25		
#define CY_LEADER				25		
#define CX_ICON_MARGIN			5		

#define DEFAULT_SHOW_DELAY		5000	

#define TIMER_HIDE				5000		

#define IDC_DSA			12000

CXInfoTip::CXInfoTip()
{
	
	m_szClass		= AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), NULL, NULL);

	m_hIcon			= NULL;

	
	m_nShowDelay	= DEFAULT_SHOW_DELAY;

	m_IconSize		= CSize(0, 0);
	m_ptOrigin		= CPoint(0, 0);

	m_bPlaced = false;

	m_bDSAChecked = FALSE;

	m_bShowDSA = FALSE;

	m_nAutohideDelay = TIMER_HIDE;
}

CXInfoTip::~CXInfoTip()
{
}

BEGIN_MESSAGE_MAP(CXInfoTip, CWnd)
	//{{AFX_MSG_MAP(CXInfoTip)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_DSA, OnDSA)
END_MESSAGE_MAP()

BOOL CXInfoTip::Create(CWnd* pParentWnd) 
{
	BOOL	bSuccess;

	
	ASSERT(pParentWnd != NULL);

	bSuccess = CreateEx(NULL, m_szClass, NULL, WS_POPUP, 0, 0, 0, 0, pParentWnd->GetSafeHwnd(), NULL, NULL);

	
	CFont* pFont = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));
	
	LOGFONT lf;
	pFont->GetLogFont (&lf);
	m_fntNormal.CreateFontIndirect (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);

	return bSuccess;
}

void CXInfoTip::Show(LPCSTR pszCaption, CString szText, BOOL bAutoHide , CPoint *pt )
{
	if (pt != NULL)
		m_ptOrigin	= *pt;
	else
		GetCursorPos(&m_ptOrigin);

	m_szText	= szText;
	m_strCaption = pszCaption;

	
	m_nTimer = SetTimer(bAutoHide ? timerShow : timerShowNAH, m_nShowDelay, NULL);
}

void CXInfoTip::OnPaint() 
{
	CPaintDC dc( this ); 

	CRect	rc;
	CBrush	WindowBrush;
	CBrush	FrameBrush;
	CBrush	InnerFrameBrush;
	HRGN	hRegion;
	CRgn	*pRegion;
	CFont	*pSysFont;

	
	GetClientRect(rc);

	
	InnerFrameBrush.CreateSolidBrush(::GetSysColor(COLOR_SCROLLBAR));
	FrameBrush.CreateSolidBrush(::GetSysColor(COLOR_WINDOWTEXT));
	WindowBrush.CreateSolidBrush(::GetSysColor(COLOR_WINDOW));

	
	GetWindowRegion(&dc, &hRegion);
	pRegion = CRgn::FromHandle(hRegion);

	
	dc.FillRgn(pRegion, &WindowBrush);
	dc.FrameRgn(pRegion, &InnerFrameBrush, 3, 3);
	dc.FrameRgn(pRegion, &FrameBrush, 1, 1);

	
	rc.DeflateRect(CX_ROUNDED, CY_ROUNDED, 0, 0);
	if (m_hIcon != NULL)
		rc.left = rc.left + m_IconSize.cx + CX_ICON_MARGIN;
	
	
	pSysFont = (CFont *)dc.SelectObject(&m_fntBold);
	
	dc.SetBkMode( TRANSPARENT );

	dc.DrawText (m_strCaption, &rc, DT_TOP | DT_LEFT);

	dc.SelectObject(&m_fntNormal);
	
	CRect rc2 = rc;
	rc2.top += m_nCaptionHeight;
	dc.DrawText(m_szText, &rc2, DT_TOP | DT_LEFT);

	if (m_bShowDSA && m_bPlaced == false)
	{
		m_bPlaced = true;
		m_btnDSA.MoveWindow (rc.left, m_yDSA, m_cxDSA + 10 + 20, 20);
	}

	
	if (m_hIcon != NULL)
		DrawIconEx(dc.m_hDC, CX_ROUNDED, CY_ROUNDED, m_hIcon, m_IconSize.cx, m_IconSize.cy, 0, NULL, DI_NORMAL);

	
	::DeleteObject(hRegion);
	dc.SelectObject(pSysFont);

}

BOOL CXInfoTip::GetWindowRegion(CDC* pDC, HRGN* hRegion, CSize *Size )
{
	CRect	rcWnd (0,0,0,0);
	POINT	ptLeader[3];
	CRgn	LeaderRegion;
	CRgn	CaptionRegion;
	CFont	*pSysFont;
	
	ASSERT(pDC != NULL);
	ASSERT(hRegion != NULL);

	
	pSysFont = (CFont *)pDC->SelectObject(&m_fntBold);

	CRect rcWnd1, rcWnd2;

	pDC->DrawText(m_strCaption + "\n", &rcWnd1, DT_CALCRECT);

	pDC->SelectObject (&m_fntNormal);

	pDC->DrawText(m_szText, &rcWnd2, DT_CALCRECT);

	m_nCaptionHeight = rcWnd1.Height ();
	rcWnd.right = max (rcWnd1.Width (), rcWnd2.Width ());
	rcWnd.bottom = m_nCaptionHeight + rcWnd2.Height ();

	if (m_bShowDSA)
	{
		
		CRect rcDSA;
		pDC->DrawText (LS (L_DONTSHOWTHISWINDOWAGAIN), &rcDSA, DT_CALCRECT);
		m_yDSA = rcWnd.bottom + rcDSA.Height ();
		rcWnd.bottom += 10 + rcDSA.Height ();
		m_cxDSA = rcDSA.Width ();
		rcWnd.right = max (rcWnd.right, m_cxDSA + 30);
	}

	pDC->SelectObject(pSysFont);

	
	rcWnd.InflateRect(CX_ROUNDED, CY_ROUNDED);

	
	if (m_hIcon != NULL)
		rcWnd.right = rcWnd.right + m_IconSize.cx + CX_ICON_MARGIN;
	if (rcWnd.Height() < m_IconSize.cy)
		rcWnd.bottom = rcWnd.top + m_IconSize.cy;

	

	ptLeader[0].x	= rcWnd.Width() - CX_ROUNDED;
	ptLeader[0].y	= rcWnd.Height() - CY_ROUNDED;

	ptLeader[1].x	= ptLeader[0].x;
	ptLeader[1].y	= ptLeader[0].y + CY_LEADER;

	ptLeader[2].x	= ptLeader[0].x - CX_LEADER;
	ptLeader[2].y	= rcWnd.Height() - CY_ROUNDED;

	
	CaptionRegion.CreateRoundRectRgn(0, 0, rcWnd.Width(), rcWnd.Height(), CX_ROUNDED, CY_ROUNDED);
	
	LeaderRegion.CreatePolygonRgn(ptLeader, 3, ALTERNATE);
	
	*hRegion =  ::CreateRectRgn(0, 0, rcWnd.Width(), rcWnd.Height() + CY_LEADER);
	
	CombineRgn(*hRegion, CaptionRegion.operator HRGN(), LeaderRegion.operator HRGN(), RGN_OR);

	
	if (Size != NULL)
	{
		Size->cx	= rcWnd.Width();
		Size->cy	= rcWnd.Height() + CY_LEADER;
	}

	return TRUE;
}

int CXInfoTip::OnCreate( LPCREATESTRUCT lpCreateStruct ) 
{
   if ( CWnd::OnCreate( lpCreateStruct ) == -1 )
      return -1;

   m_brWnd.CreateSolidBrush (GetSysColor (COLOR_WINDOW));

   CRect rc (0,0,0,0);
   m_btnDSA.Create (LS (L_DONTSHOWTHISWINDOWAGAIN), 
	   BS_AUTOCHECKBOX | BS_CHECKBOX | WS_CHILD | WS_VISIBLE, rc, this, IDC_DSA);
     
   return 0;
}

void CXInfoTip::OnTimer( UINT nIDEvent ) 
{
	HRGN	hRegion;
	CSize	WindowSize;
	CDC		*pDC;
	CPoint	ptCursor;

	switch (nIDEvent)
	{
	
	
	
	case timerShow:
		KillTimer(m_nTimer);

		pDC = GetDC();
		GetWindowRegion(pDC, &hRegion, &WindowSize);
		ReleaseDC(pDC);

		::SetWindowRgn(m_hWnd, hRegion, TRUE);

		SetWindowPos(&wndTop, m_ptOrigin.x - WindowSize.cx + CX_ROUNDED, m_ptOrigin.y - WindowSize.cy + CY_ROUNDED, WindowSize.cx, WindowSize.cy, SWP_NOACTIVATE | SWP_SHOWWINDOW);
		m_bPlaced = false;

		m_nTimer = SetTimer(timerHide, m_nAutohideDelay, NULL);
		break;
	
	
	
	case timerHide:
		GetCursorPos(&ptCursor);
		if (ptCursor != m_ptOrigin)
		{
			KillTimer(m_nTimer);
			ShowWindow(SW_HIDE);
		}

		break;

	
	
	
	case timerShowNAH:
		KillTimer(m_nTimer);

		pDC = GetDC();
		GetWindowRegion(pDC, &hRegion, &WindowSize);
		ReleaseDC(pDC);

		::SetWindowRgn(m_hWnd, hRegion, TRUE);

		SetWindowPos(&wndTop, m_ptOrigin.x - WindowSize.cx + CX_ROUNDED, m_ptOrigin.y - WindowSize.cy + CY_ROUNDED, WindowSize.cx, WindowSize.cy, SWP_NOACTIVATE | SWP_SHOWWINDOW);
		m_bPlaced = false;
		break;
	}

	CWnd::OnTimer(nIDEvent);
}

void CXInfoTip::OnDestroy() 
{
	KillTimer(m_nTimer);

	CWnd::OnDestroy();
}

void CXInfoTip::RelayEvent(LPMSG lpMsg)
{
	if (m_nTimer == timerShowNAH)
		return;

	CPoint			point;
	CWnd			*pWindow;
	CString			szTooltipText;
	TipToolInfo		Info;
		
	switch(lpMsg->message)
	{
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
	case WM_MBUTTONDOWN:
		ShowWindow(SW_HIDE);
		break;
	case WM_MOUSEMOVE:
		GetCursorPos(&point);

		if (point != m_ptOrigin)
		{
			
			pWindow = WindowFromPoint(point);
			if (pWindow != NULL)
			{
				if (m_ToolMap.Lookup(pWindow->m_hWnd, Info))
				{
					
					m_ptOrigin = point;
					SetIcon(Info.hIcon);
					Show("", Info.szText, TRUE, &point);
				}
			}
		}

		
		if (point != m_ptOrigin)
			ShowWindow(SW_HIDE);
		
		break;
	}
}

void CXInfoTip::SetIcon(HICON hIcon) 
{
	ICONINFO	IconInfo;

	m_hIcon = hIcon; 

	if (hIcon == NULL)
	{
		m_IconSize = CSize(0, 0);
		return;
	}
	
	
	ZeroMemory(&IconInfo, sizeof(ICONINFO));
	::GetIconInfo(m_hIcon, &IconInfo);

	m_IconSize.cx = (BYTE)(IconInfo.xHotspot );
	m_IconSize.cy = (BYTE)(IconInfo.yHotspot );
    
	::DeleteObject(IconInfo.hbmMask);
	::DeleteObject(IconInfo.hbmColor);

	if (IsWindow(m_hWnd))
		RedrawWindow();
}

void CXInfoTip::AddTool(CWnd *pWnd, LPCTSTR szTooltipText, HICON hIcon )
{
	ASSERT(pWnd != NULL);

	
	TipToolInfo Info;
	Info.szText = szTooltipText;
	Info.hIcon	= hIcon;

	
	m_ToolMap.SetAt(pWnd->m_hWnd, Info);
};

void CXInfoTip::RemoveTool(CWnd *pWnd)
{
	m_ToolMap.RemoveKey(pWnd->m_hWnd);
}

void CXInfoTip::OnLButtonDown(UINT, CPoint pt)
{
	Hide ();
}

HBRUSH CXInfoTip::OnCtlColor(CDC *pDC, CWnd *pWnd, UINT nCtlColor)
{
	pDC->SelectObject (&m_fntNormal);
	return m_brWnd;
}

BOOL CXInfoTip::OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message)
{
	SetCursor (LoadCursor (NULL, IDC_ARROW));
	return FALSE;
}

void CXInfoTip::OnDSA()
{
	m_bDSAChecked = 0 != (m_btnDSA.GetState () & BST_CHECKED);
}

BOOL CXInfoTip::is_DontShowChecked()
{
	return m_bDSAChecked;
}

void CXInfoTip::SetAutohideDelay(int nDelay)
{
	m_nAutohideDelay = nDelay;
}
