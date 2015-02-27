/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "WndDlDoneNotification.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int CWndDlDoneNotification::m_acWnds [4] = {0, 0, 0, 0};
vmsCriticalSectionEx CWndDlDoneNotification::m_csWnds;

CWndDlDoneNotification::CWndDlDoneNotification()
{
	m_bWasDeletedByAutoDel = false;
}

CWndDlDoneNotification::~CWndDlDoneNotification()
{
}

BEGIN_MESSAGE_MAP(CWndDlDoneNotification, CFrameWnd)
	//{{AFX_MSG_MAP(CWndDlDoneNotification)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWndDlDoneNotification::Create(fsDownload *dld)
{
	ASSERT (dld != NULL);
	m_dld = dld;

	#ifndef WS_EX_NOACTIVATE
		#define WS_EX_NOACTIVATE 0x08000000L
	#endif

	CRect rc;
	GetNextWindowPosition (&rc);

	DWORD dwLStyle = fsSysGetOsMajorVersion () < 5 ? 0 : WS_EX_LAYERED | WS_EX_NOACTIVATE;
	
	VERIFY (CFrameWnd::CreateEx (WS_EX_TOPMOST | WS_EX_TOOLWINDOW | dwLStyle, 
		AfxRegisterWndClass (
			CS_DBLCLKS, LoadCursor (NULL, IDC_ARROW), 
			(HBRUSH)(COLOR_WINDOW+1), NULL),
		NULL, WS_POPUP, rc, NULL, 0));

	VERIFY (SetWindowPos (NULL, 0, 0, 0, 0, 
		SWP_NOZORDER | SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW | SWP_NOACTIVATE));

	
	SetBlend (255);

	int n = _App.Notif_OnDoneWnds_Timeout ();
	if (n)
		SetTimer (1, n * 1000, NULL);

	SetTimer (2, 500, NULL);
}

void CWndDlDoneNotification::GetNextWindowPosition(CRect *prc)
{
	m_csWnds.Lock ();

	int cm = INT_MAX, cim = 0;
	for (int i = 0; i < 4; i++)
	{
		if (cm > m_acWnds [i])
		{
			cm = m_acWnds [i];
			cim = i;
		}
	}

	m_acWnds [m_nPos = cim]++;

	m_csWnds.Unlock ();

	GetWindowPosition (m_nPos, prc);	
}

void CWndDlDoneNotification::GetWindowPosition(int iPos, CRect *prc)
{
	int WIDTH = 150;
	int HEIGHT = 70;

	CDC *pdc = AfxGetApp ()->m_pMainWnd->GetDC ();
	pdc->SelectObject (GetStockObject (DEFAULT_GUI_FONT));
	CString str = LS (L_DLDCOMPLETED); str += ':';
	CSize s = pdc->GetTextExtent (str);
	AfxGetApp ()->m_pMainWnd->ReleaseDC (pdc);
	WIDTH = max (WIDTH, 5+32+5+s.cx+5+16+5+GetSystemMetrics (SM_CXBORDER)*2+5);
	HEIGHT = max (HEIGHT, (s.cy + 2) * 4 + 5 + 5);

	
	RECT rcWA;
	SystemParametersInfo (SPI_GETWORKAREA, 0, &rcWA, FALSE);
	
	
	
	HWND shellWindow = ::FindWindow ("Shell_TrayWnd", NULL);
	
	APPBARDATA appBarData;
	appBarData.hWnd = shellWindow;
	appBarData.cbSize = sizeof (appBarData);
    if (FALSE == SHAppBarMessage (ABM_GETTASKBARPOS, &appBarData))
	{
		int cx = GetSystemMetrics (SM_CXSCREEN);
		int cy = GetSystemMetrics (SM_CYSCREEN);
		prc->SetRect (cx/2-WIDTH/2, cy/2-HEIGHT/2, cx/2+WIDTH/2, cy/2+HEIGHT/2);
		return;
	}
	
	bool bToTop = false, bToLeft = false;
	
	switch (appBarData.uEdge)
	{
	case ABE_LEFT:
		bToTop = false;
		bToLeft = true;
		break;
		
	case ABE_RIGHT: 
		bToTop = false;
		bToLeft = false;
		break;
		
	case ABE_TOP: 
		bToTop = true;
		bToLeft = false;
		break;
		
	case ABE_BOTTOM:
		bToTop = false;
		bToLeft = false;
		break;
	}
	
	int X_OFF = (iPos == 2 || iPos == 3) ? WIDTH + 1 : 0;
	int Y_OFF = (iPos == 1 || iPos == 3) ? HEIGHT + 1 : 0;
	
	prc->left = bToLeft ? rcWA.left + X_OFF : rcWA.right - WIDTH - X_OFF;
	prc->right = prc->left + WIDTH;
	prc->top = bToTop ? rcWA.top + Y_OFF : rcWA.bottom - HEIGHT - Y_OFF;
	prc->bottom = prc->top + HEIGHT;
}

void CWndDlDoneNotification::OnDestroy() 
{
	CFrameWnd::OnDestroy();

	m_csWnds.Lock ();
	m_acWnds [m_nPos]--;
	m_csWnds.Unlock ();
	
	delete this;	
}

void CWndDlDoneNotification::SetBlend(BYTE val)
{
	if (fsSysGetOsMajorVersion () >= 5)
		fsSetLayeredWindowAttributes (m_hWnd, 0, val, LWA_ALPHA);
}

void CWndDlDoneNotification::OnPaint() 
{
	CPaintDC dc (this);

	CRect rc; GetClientRect (&rc);
	dc.Rectangle (0, 0, rc.Width (), rc.Height ());

	SHFILEINFO fi;
	SHGetFileInfo (m_dld->pMgr->get_OutputFilePathName (), 0, &fi, sizeof (fi), 
		SHGFI_ICON | SHGFI_SHELLICONSIZE);
	dc.DrawIcon (5, 5, fi.hIcon);
	DestroyIcon (fi.hIcon);

	dc.SelectObject (GetStockObject (DEFAULT_GUI_FONT));

	CSize s = dc.GetTextExtent ("A");

	CRect rc2 (5+32+5, 5, rc.right - 5 - 16 - 5, rc.bottom - s.cy - 5 - 2 - 2);

	CString str = LS (L_DLDCOMPLETED); str += ':';
	CRect rc3 = rc2; rc3.bottom = rc3.top;
	dc.DrawText (str, &rc3, DT_WORDBREAK | DT_CALCRECT);
	dc.DrawText (str, &rc3, DT_WORDBREAK);

	HICON hIco = LoadIcon (AfxGetResourceHandle (), MAKEINTRESOURCE (IDI_CLOSEBTN));
	DrawIconEx (dc, rc.right-5-16, 5, hIco, 16, 16, 0, NULL, DI_NORMAL);
	DestroyIcon (hIco);

	rc2.right = rc.right - 5;

	rc2.top += rc3.Height () + 2;	
	rc2.top = max (rc2.top, 5+16+1);
	char sz [MY_MAX_PATH] = "";
	if (m_dld->pMgr->IsBittorrent () && m_dld->pMgr->GetBtDownloadMgr ()->get_FileCount () > 1)
		lstrcpy (sz, m_dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ());
	else
		fsGetFileName (m_dld->pMgr->get_OutputFilePathName (), sz);
	m_rcName = rc2;
	dc.DrawText (sz, &m_rcName, DT_WORDBREAK | DT_EDITCONTROL | DT_CALCRECT);
	dc.DrawText (sz, &m_rcName, DT_WORDBREAK | DT_EDITCONTROL);

	LOGFONT lf; dc.GetCurrentFont ()->GetLogFont (&lf);
	lf.lfUnderline = TRUE;
	CFont fnt; fnt.CreateFontIndirect (&lf);
	CFont *pfntOld = dc.SelectObject (&fnt);
	dc.SetTextColor (GetSysColor (26));

	CSize sLaunch = dc.GetTextExtent (LS (L_LAUNCH));
	CSize sOpenF = dc.GetTextExtent (LS (L_OPENFOLDER));
	sLaunch.cy = max (sLaunch.cy, sOpenF.cy);
	sOpenF.cy = sLaunch.cy;

	m_rcLaunch.SetRect (rc.right - 5 - 16 - 1 - sOpenF.cx - 5 - sLaunch.cx, rc.bottom - 5 - sLaunch.cy, 0, 0);
	m_rcLaunch.right = m_rcLaunch.left + sLaunch.cx;
	m_rcLaunch.bottom = m_rcLaunch.top + sLaunch.cy;
	dc.DrawText (LS (L_LAUNCH), &m_rcLaunch, DT_LEFT);

	m_rcOpenFolder.SetRect (rc.right - 5 - 16 - 1 - sOpenF.cx, rc.bottom - 5 - sOpenF.cy, 0, 0);
	m_rcOpenFolder.right = m_rcOpenFolder.left + sOpenF.cx;
	m_rcOpenFolder.bottom = m_rcOpenFolder.top + sOpenF.cy;
	dc.DrawText (LS (L_OPENFOLDER), &m_rcOpenFolder, DT_LEFT);

	dc.SelectObject (pfntOld);
}

void CWndDlDoneNotification::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CFrameWnd::OnLButtonDown(nFlags, point);
	if (PtInRect (&m_rcLaunch, point))
		_DldsMgr.LaunchDownload (m_dld);
	else if (PtInRect (&m_rcOpenFolder, point))
		m_dld->pMgr->Do_OpenFolder ();
	PostMessage (WM_CLOSE);	
}

BOOL CWndDlDoneNotification::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	CPoint pt; GetCursorPos (&pt);
	ScreenToClient (&pt);
	if (PtInRect (&m_rcLaunch, pt) || PtInRect (&m_rcOpenFolder, pt))
	{
		SetCursor (LoadCursor (AfxGetResourceHandle (), MAKEINTRESOURCE (IDC_HAND_)));
		return TRUE;
	}
	
	return CFrameWnd::OnSetCursor(pWnd, nHitTest, message);
}

BOOL CWndDlDoneNotification::PreCreateWindow(CREATESTRUCT& cs) 
{
	BOOL b = CFrameWnd::PreCreateWindow(cs);
	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	return b;
}

void CWndDlDoneNotification::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		KillTimer (1);
		PostMessage (WM_CLOSE);
	}

	if (nIDEvent == 2)
	{
		if (m_dld->getState () & DLDS_FILE_WAS_LAUNCHED_AT_LEAST_ONCE)
			PostMessage (WM_CLOSE);

		else if (m_dld->dwFlags & DLD_WAS_DELETED)
		{
			if (_DldsMgr.isAutoDelCompletedDownloads ())
				m_bWasDeletedByAutoDel = true;
			if (!m_bWasDeletedByAutoDel)
				PostMessage (WM_CLOSE);
		}
	}
	
	CFrameWnd::OnTimer(nIDEvent);
}
