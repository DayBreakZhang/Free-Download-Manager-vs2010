/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "SmallTipWnd.h"
#include "vmsAppTipsMgr.h"
#include "resource.h"
#include "vmsDrawHelper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CSmallTipWnd::CSmallTipWnd()
{
	m_rcClose.SetRectEmpty ();

	m_bmpTip.LoadBitmap (IDB_TIP);
	m_bmpTip.GetBitmap (&m_bmTip);
	m_bmpClose.LoadBitmap (IDB_CLOSE);
	m_bmpClose.GetBitmap (&m_bmClose);

	addChildWindow (&m_tip);
}

CSmallTipWnd::~CSmallTipWnd()
{
}

BEGIN_MESSAGE_MAP(CSmallTipWnd, vmsUiWindowsHoster)
	//{{AFX_MSG_MAP(CSmallTipWnd)
	ON_WM_CREATE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	ON_COMMAND(10, OnSetToDownloadOneByOne)
	ON_COMMAND(11, OnEnableSilentMonitoring)
END_MESSAGE_MAP()

int CSmallTipWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (vmsUiWindowsHoster::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	AttachUiWindow (this);

	m_tstrCurrentTip = vmsAppSmallTipsMgr::o ().getTip ();
	if (!m_tstrCurrentTip.empty ())
		m_tip.setText (m_tstrCurrentTip.c_str ());

	SetTimer (1, 3600*1000, NULL);
	
	return 0;
}

void CSmallTipWnd::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 0, 0);
	
	CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW),
		(HBRUSH)(COLOR_BTNFACE+1), NULL), NULL, WS_CHILD, rc, pwndParent, 0);
}

CSize CSmallTipWnd::getRequiredSize() const
{
	CSize s = m_tip.getRequiredSize ();
	s.cy = max (m_bmTip.bmHeight, s.cy);
	s.cy = max (m_bmClose.bmHeight, s.cy);
	s.cy += 3+4;
	s.cx = 5 + m_bmTip.bmWidth + 15 + s.cx + 80 + m_bmClose.bmWidth + 5;
	return s;
}

void CSmallTipWnd::setPos(int x, int y, int cx, int cy)
{
	vmsUiWindow::setPos (x, y, cx, cy);
	CSize s = m_tip.getRequiredSize ();
	m_tip.setPos (5+m_bmTip.bmWidth+15, (cy-s.cy)/2, s.cx, s.cy);
}

void CSmallTipWnd::Draw(CDC *pdc)
{
	
	pdc->FillSolidRect (0, 0, m_rcPos.Width (), m_rcPos.Height (), GetSysColor (COLOR_BTNFACE));

	
	CPen pen (PS_SOLID, 1, RGB (201,201,201));
	CBrush br (RGB (243,243,243));
	CPen *penOld = pdc->SelectObject (&pen);
	CBrush *pbrOld = pdc->SelectObject (&br);
	pdc->RoundRect (0, 0, m_rcPos.Width (), m_rcPos.Height (), 7, 7);
	pdc->SelectObject (penOld);
	pdc->SelectObject (pbrOld);

	vmsUiWindow::Draw (pdc);

	vmsDrawHelper::DrawBitmap (pdc, &m_bmpTip, 5, (m_rcPos.Height ()-m_bmTip.bmHeight)/2);

	m_rcClose.left = m_rcPos.Width ()-5-m_bmClose.bmWidth;
	m_rcClose.top = (m_rcPos.Height ()-m_bmClose.bmHeight)/2;
	m_rcClose.right = m_rcClose.left + m_bmClose.bmWidth;
	m_rcClose.bottom = m_rcClose.top + m_bmClose.bmHeight;
	vmsDrawHelper::DrawTransparentBitmap (pdc, &m_bmpClose, m_rcClose.left, m_rcClose.top, RGB (255,0,255));
}

void CSmallTipWnd::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (PtInRect (&m_rcClose, point))
		GetParent ()->PostMessage (WM_COMMAND, ID_SMALLTIP_CLOSE);
	else
		vmsUiWindowsHoster::OnLButtonUp(nFlags, point);
}

void CSmallTipWnd::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent == 1)
	{
		vmsAppSmallTipsMgr::o ().SetupCurrentTipIndex ();
		tstring tstrTip = vmsAppSmallTipsMgr::o ().getTip ();
		if (m_tstrCurrentTip != tstrTip)
		{
			m_tstrCurrentTip = tstrTip;
			m_tip.setText (tstrTip.c_str ());
			GetParent ()->PostMessage (WM_COMMAND, ID_SMALLTIP_CHANGED);
		}
	}
	
	vmsUiWindowsHoster::OnTimer(nIDEvent);
}

void CSmallTipWnd::OnSetToDownloadOneByOne() 
{
	_TumMgr.SetToDownloadOneByOne ();
	MessageBox (LS (L_DONE), NULL, MB_ICONINFORMATION);
}

void CSmallTipWnd::OnEnableSilentMonitoring()
{
	_App.Monitor_Silent (TRUE);
	MessageBox (LS (L_DONE), NULL, MB_ICONINFORMATION);
}
