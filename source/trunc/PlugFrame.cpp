/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "PlugFrame.h"
#include "misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CPlugFrame::CPlugFrame()
{
	m_dyCaption = 25;
	m_wndPlugin = NULL;
	m_clrBkCaption = RGB (170, 170, 170);
	m_clrCaptionText = RGB (255, 255, 255);

	m_font.CreateFont (20, 0, 0, 0, FW_BOLD, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "Arial");
}

CPlugFrame::~CPlugFrame()
{
}

BEGIN_MESSAGE_MAP(CPlugFrame, CWnd)
	//{{AFX_MSG_MAP(CPlugFrame)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPlugFrame::Create(CWnd *pParent)
{
	CRect rc (0, 0, 100, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (CS_DBLCLKS, LoadCursor (NULL, IDC_ARROW),
		(HBRUSH) (COLOR_3DFACE+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x111))
		return FALSE;

	return TRUE;
}

void CPlugFrame::OnPaint() 
{
	CPaintDC dc(this); 
	
	dc.SetTextColor (m_clrCaptionText);
	CBrush br (m_clrBkCaption);

	CBrush *oldBr = dc.SelectObject (&br);
	CFont *oldFont = dc.SelectObject (&m_font);
	CPen pen (PS_SOLID, 1, m_clrBkCaption),
		 penBorder (PS_SOLID, 2, GetSysColor (COLOR_3DDKSHADOW));

	CRect rcCaption;
	GetClientRect (&rcCaption);
	rcCaption.bottom = m_dyCaption - 3;

	CPen *oldPen = dc.SelectObject (&pen);

	
	dc.Rectangle (&rcCaption);

	dc.SetBkMode (TRANSPARENT);
	rcCaption.left = 10;

	
	dc.DrawText (m_strFrameName, &rcCaption, DT_SINGLELINE | DT_VCENTER);

	

	CPen penShadow (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));
	dc.SelectObject (&penShadow);
	dc.MoveTo (0, m_dyCaption - 1);
	dc.LineTo (rcCaption.right, m_dyCaption - 1);

	dc.SelectObject (oldBr);
	dc.SelectObject (oldFont);
	dc.SelectObject (oldPen);
	
	
}

void CPlugFrame::SetFrameName(LPCTSTR pszName)
{
	m_strFrameName = pszName;
	Invalidate (FALSE);
}

void CPlugFrame::SetPluginWindow(HWND hWnd)
{
	m_wndPlugin = hWnd;
	SetupPluginRect ();
}

void CPlugFrame::OnSize(UINT , int , int ) 
{
	if (m_wndPlugin)
		SetupPluginRect ();

	Invalidate (FALSE);
}

void CPlugFrame::SetupPluginRect()
{
	RECT rcThis;

	GetClientRect (&rcThis);

	rcThis.top += m_dyCaption;

	::MoveWindow (m_wndPlugin, rcThis.left, rcThis.top, rcThis.right - rcThis.left,
		rcThis.bottom - rcThis.top, TRUE);
}

void CPlugFrame::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	::SetFocus (m_wndPlugin);
}
