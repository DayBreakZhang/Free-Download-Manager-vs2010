/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FloatingWnd.h"
#include "MainFrm.h"
#include "system.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFloatingWnd::CFloatingWnd()
{
	m_bTimerSet = FALSE;
	m_bShown = FALSE;
	m_bHideAlways = FALSE;
}

CFloatingWnd::~CFloatingWnd()
{
}

BEGIN_MESSAGE_MAP(CFloatingWnd, CFrameWnd)
	//{{AFX_MSG_MAP(CFloatingWnd)
	ON_WM_NCHITTEST()
	ON_WM_PAINT()
	ON_WM_NCRBUTTONUP()
	ON_WM_CREATE()
	ON_WM_NCLBUTTONDBLCLK()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_WM_MOVING()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CFloatingWnd::Create()
{
	m_pMainFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	
	RECT rcWA;
	SystemParametersInfo (SPI_GETWORKAREA, 0, &rcWA, FALSE);
	RECT rc = {rcWA.right - 1 - 40, rcWA.bottom - 1 - 40, rcWA.right - 1, rcWA.bottom - 1};

	DWORD dwLStyle = fsSysGetOsMajorVersion () < 5 ? 0 : WS_EX_LAYERED;

	if (FALSE == CFrameWnd::CreateEx (WS_EX_TOPMOST|WS_EX_TOOLWINDOW|dwLStyle, 
			AfxRegisterWndClass (CS_DBLCLKS, LoadCursor (NULL, IDC_ARROW),	(HBRUSH)(COLOR_WINDOW+1), NULL), 
			NULL, 
			WS_POPUP|WS_VISIBLE|WS_CLIPSIBLINGS|WS_OVERLAPPED, 
			rc, NULL, 0))
		return FALSE;

	m_hLogoIcon = SICOEX (IDI_LOGO2, 32, 32);

	SetBlend (_App.DropBoxWndBlend ());
	
	_App.View_ReadWndPlacement (this, "FloatingWnd", 
		_App.View_FloatingWindow () == FALSE ? fsAppSettings::RWPA_FORCE_SWHIDE : fsAppSettings::RWPA_NONE);

	SetWindowPos (NULL, 0, 0, 40, 40, SWP_NOMOVE | SWP_NOZORDER);

	Show (_App.View_FloatingWindow (), FALSE);
	UpdateTimer ();
	
	return TRUE;
}

LRESULT CFloatingWnd::OnNcHitTest(CPoint ) 
{
	return HTCAPTION;
}

void CFloatingWnd::OnPaint() 
{
	CFrameWnd::OnPaint();
	CDC* pdc = GetWindowDC ();
	CBrush br (GetSysColor (COLOR_WINDOW));
	CBrush *oldbr = pdc->SelectObject (&br);
	pdc->Rectangle (0, 0, 40, 40);
	pdc->SelectObject (oldbr);
	
	::DrawIconEx (pdc->m_hDC, 4, 4, m_hLogoIcon, 32, 32, 0, NULL, DI_NORMAL);
	ReleaseDC (pdc);
}

void CFloatingWnd::SaveState()
{
	_App.View_SaveWndPlacement (this, "FloatingWnd");
	
}

void CFloatingWnd::OnNcRButtonUp(UINT nHitTest, CPoint point) 
{
	m_pMainFrame->SendMessage (WM_SHOWTRAYMENU);
	CFrameWnd::OnNcRButtonUp(nHitTest, point);
}

int CFloatingWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_drop.Register (this);

	return 0;
}

void CFloatingWnd::OnNcLButtonDblClk(UINT nHitTest, CPoint point) 
{
	if (m_pMainFrame->IsIconic ())
		m_pMainFrame->OnShowmainwindow ();
	else
		m_pMainFrame->ShowWindow (SW_MINIMIZE);

	CFrameWnd::OnNcLButtonDblClk(nHitTest, point);
}

void CFloatingWnd::OnClose() 
{
	ShowWindow (SW_HIDE);
	_App.View_FloatingWindow (FALSE);
	if (::IsWindow (m_wndTip)) {
		m_wndTip.Hide ();
		m_wndTip.DestroyWindow ();
	}
}

void CFloatingWnd::OnTimer(UINT nIDEvent) 
{
	if (m_bTimerSet == FALSE)
		return;

	static BOOL _bDropBoxIntro = _App.View_DropBoxIntro () &&
		IS_PORTABLE_MODE == FALSE;
	if (_bDropBoxIntro)
	{
		_bDropBoxIntro = FALSE;
		ShowTip ();
		_App.View_DropBoxIntro (FALSE);
	}

	BOOL bFS = fsIsSystemInFullScreenMode ();	

	

	if (bFS && m_bShown)
		Show (FALSE, FALSE);
	else if (bFS == FALSE && m_bShown == FALSE)
		Show (TRUE, FALSE);
	
	CFrameWnd::OnTimer(nIDEvent);
}

void CFloatingWnd::Show(BOOL bShow, BOOL bByUser)
{
	if (bByUser == FALSE && !m_bShown == !bShow)
		return;

	if (bShow == FALSE && ::IsWindow (m_wndTip)) {
		m_wndTip.Hide ();
		m_wndTip.DestroyWindow ();
	}

	if (bByUser)
	{
		_App.View_FloatingWindow (bShow);
		UpdateTimer ();
	}

	ShowWindow (bShow && m_bHideAlways == FALSE ? SW_SHOW : SW_HIDE);
	m_bShown = bShow && m_bHideAlways == FALSE;
}

void CFloatingWnd::UpdateTimer()
{
	BOOL bNeedSet = _App.View_FloatingWindow () && _App.FloatingWndsHideInFSMode ();
	if (bNeedSet && m_bTimerSet == FALSE)
		SetTimer (1, 1000, NULL);
	else if (bNeedSet == FALSE && m_bTimerSet)
		KillTimer (1);
	m_bTimerSet = bNeedSet;

	if (m_bTimerSet == FALSE && _App.View_FloatingWindow () && m_bShown == FALSE && m_bHideAlways == FALSE)
		ShowWindow (SW_SHOW);
}

void CFloatingWnd::ShowTip()
{
	m_wndTip.Create (this);
	m_wndTip.SetIcon (LoadIcon (NULL, IDI_INFORMATION));
	m_wndTip.SetShowDelay (0);
	m_wndTip.SetAutohideDelay (10000);
		
	CRect rc;
	GetWindowRect (&rc);
	CPoint pt (rc.left + rc.Width () / 2, rc.top + rc.Height () / 2);
	CString sTipMessage = LS (L_DROPBOXINTRO);
	sTipMessage.Replace("&", "&&");
	m_wndTip.Show (LS (L_FDMDROPBOX), sTipMessage, TRUE, &pt);
}

void CFloatingWnd::OnMoving(UINT fwSide, LPRECT pRect) 
{
	CFrameWnd::OnMoving(fwSide, pRect);
	
	if (::IsWindow (m_wndTip)) {
		m_wndTip.Hide ();
		m_wndTip.DestroyWindow ();
	}
}

void CFloatingWnd::SetBlend (BYTE val)
{
	m_blend = val;
	if (fsSysGetOsMajorVersion () >= 5)
		fsSetLayeredWindowAttributes (m_hWnd, 0, m_blend, LWA_ALPHA);
}

void CFloatingWnd::HideAlways()
{
	m_bHideAlways = TRUE;
	Show (FALSE, FALSE);
}
