/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "iefdmdm.h"
#include "vmsUrlWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUrlWnd::vmsUrlWnd()
{
	m_hwnd = NULL;
	m_hTextFont = NULL;
}

vmsUrlWnd::~vmsUrlWnd()
{
	if (m_hTextFont)
		DeleteObject (m_hTextFont);
}

void vmsUrlWnd::Create(HWND hwndParent, RECT &rcPos, LPCTSTR ptszTitle, LPCTSTR ptszUrl)
{
	if (m_hwnd && IsWindow (m_hwnd))
		return;

	RegisterWndClass ();

	m_hwnd = CreateWindow (_T ("767D3A70-2F26-41f1-94EB-C1D7522CD7D5"), ptszTitle, 
		WS_CHILD | WS_VISIBLE, rcPos.left, rcPos.top, rcPos.right-rcPos.left, rcPos.bottom-rcPos.top, 
		hwndParent, NULL, _Module.GetModuleInstance (), this);

	SetWindowLongPtr (m_hwnd, GWL_USERDATA, (LONG_PTR)this);

	HFONT hFont = (HFONT)SendMessage (hwndParent, WM_GETFONT, 0, 0);
	LOGFONT lf; 
	GetObject (hFont, sizeof (LOGFONT), &lf);
	lf.lfUnderline = TRUE;
	m_hTextFont = CreateFontIndirect (&lf);

	m_tstrUrl = ptszUrl;
}

void vmsUrlWnd::RegisterWndClass()
{
	static bool _bRegistered = false;
	if (_bRegistered)
		return;

	_bRegistered = true;
	
	WNDCLASSEX wc;
	ZeroMemory (&wc, sizeof (wc));
	wc.cbSize = sizeof (wc);
	wc.lpfnWndProc = _WndProc;
	wc.hInstance = _Module.GetModuleInstance ();
	wc.lpszClassName = _T ("767D3A70-2F26-41f1-94EB-C1D7522CD7D5");
	RegisterClassEx (&wc);
}

LRESULT CALLBACK vmsUrlWnd::_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_PAINT)
	{
		PAINTSTRUCT ps = {0};
		HDC hdc = BeginPaint (hwnd, &ps);
		vmsUrlWnd *pthis = getThis (hwnd);
		if (pthis)
			pthis->Draw (hdc);
		EndPaint (hwnd, &ps);
		return 0;
	}

	else if (msg == WM_SETCURSOR)
	{
		vmsUrlWnd *pthis = getThis (hwnd);
		if (pthis && pthis->isCursorOverText ())
			SetCursor (LoadCursor (NULL, IDC_HAND));
		else
			SetCursor (LoadCursor (NULL, IDC_ARROW));
		return 0;
	}

	else if (msg == WM_LBUTTONUP)
	{
		vmsUrlWnd *pthis = getThis (hwnd);
		if (pthis)
			pthis->OnClick ();
		return 0;
	}

	return DefWindowProc (hwnd, msg, wp, lp);
}

vmsUrlWnd* vmsUrlWnd::getThis(HWND hwnd)
{
	return (vmsUrlWnd*) GetWindowLongPtr (hwnd, GWL_USERDATA);
}

void vmsUrlWnd::Draw(HDC hdc)
{
	TCHAR tsz [300] = _T ("");
	GetWindowText (m_hwnd, tsz, 300);
	RECT rc;
	GetClientRect (m_hwnd, &rc);
	SetTextColor (hdc, GetSysColor (COLOR_HOTLIGHT));
	SetBkMode (hdc, TRANSPARENT);
	SelectObject (hdc, m_hTextFont);
	DrawText (hdc, tsz, -1, &rc, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	m_rcText = rc;
	DrawText (hdc, tsz, -1, &m_rcText, DT_SINGLELINE | DT_LEFT | DT_VCENTER | DT_CALCRECT);
}

void vmsUrlWnd::OnClick()
{
	if (!isCursorOverText ())
		return;
	UINT nCmd = _ttoi (m_tstrUrl.c_str ());
	if (nCmd)
		PostMessage (GetParent (m_hwnd), WM_COMMAND, nCmd, 0);
}

bool vmsUrlWnd::isCursorOverText()
{
	POINT pt;
	GetCursorPos (&pt);
	ScreenToClient (m_hwnd, &pt);
	return PtInRect (&m_rcText, pt) != FALSE;
}
