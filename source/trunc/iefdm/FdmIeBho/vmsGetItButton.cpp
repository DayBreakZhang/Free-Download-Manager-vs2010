/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsGetItButton.h"
#include <commctrl.h>
#include "resource.h"
#include "vmsFdmTranslations.h"
#include "vmsIeHKCU.h"
#include "WaitDlg.h"

#define ID_DOWNLOAD_IT			100

HIMAGELIST vmsGetItButton::m_hImgs = NULL;

vmsGetItButton::vmsGetItButton()
{
	m_hWnd = m_hwndTB = NULL;
	m_bShowingMenu = false;
	Initialize ();
	m_hEvCloseDlg = NULL;
	m_bWasClick = false;
}

vmsGetItButton::~vmsGetItButton()
{
	if (m_hWnd)
		DestroyWindow (m_hWnd);
}

void vmsGetItButton::Initialize()
{
	static bool _bInitialized = false;

	if (_bInitialized)
		return;

	_bInitialized = true;

	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof (wc);
	wc.lpfnWndProc = _TBParentWndProc;
	wc.hInstance = _Module.GetModuleInstance ();
	wc.lpszClassName = _T ("{E93F4E35-5841-41e7-AFF6-F456BBAE488B}");

	RegisterClassEx (&wc);

	m_hImgs = ImageList_Create (16, 16, ILC_COLOR24 | ILC_MASK, 1, 1);
	HICON hIco = LoadIcon (_Module.GetModuleInstance (), MAKEINTRESOURCE (IDI_FDM));
	ImageList_AddIcon (m_hImgs, hIco);
}

LRESULT CALLBACK vmsGetItButton::_TBParentWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (msg == WM_COMMAND)
	{
		vmsGetItButton *pthis = (vmsGetItButton*)GetWindowLong (hwnd, GWL_USERDATA);

		if (wp == ID_SHOW)
		{
			Settings_ShowButton (FALSE);
			PostMessage (hwnd, WM_CLOSE, 0, 0);
		}
		else if (wp == ID_DOWNLOAD_IT)
		{	
			PostMessage (hwnd, WM_CLOSE, 0, 0);
			pthis->onClick ();
		}
	}

	else if (msg == WM_NOTIFY)
	{
		NMHDR* hdr = (NMHDR*)lp;
		if (hdr->code == TBN_DROPDOWN)
		{
			LPNMTOOLBAR nmtb = (LPNMTOOLBAR)lp;
			vmsGetItButton *pthis = (vmsGetItButton*)GetWindowLong (hwnd, GWL_USERDATA);
			RECT rc;
			SendMessage (pthis->m_hwndTB, TB_GETITEMRECT, 0, (LPARAM)&rc);
			ClientToScreen (pthis->m_hwndTB, (LPPOINT)&rc);
			ClientToScreen (pthis->m_hwndTB, (LPPOINT)&rc + 1);
			POINT pt; GetCursorPos (&pt);
			if (abs (pt.x - rc.right) > 50 || abs (pt.y - rc.bottom) > 50)
			{
				rc.left = pt.x;
				rc.bottom = pt.y;
			}

			HMENU menu = LoadMenu (_Module.GetResourceInstance (), MAKEINTRESOURCE (IDM_DOWNLOAD_IT));
			HMENU menu2 = GetSubMenu (menu, 0);

			ModifyMenu (menu2, ID_SHOW, MF_BYCOMMAND|MF_STRING, ID_SHOW, 
				vmsFdmTranslations::o ().GetString (L_SHOW_THIS_BUTTON));
			CheckMenuItem (menu2, ID_SHOW, MF_CHECKED);

			pthis->m_bShowingMenu = true;

			TrackPopupMenu (menu2, TPM_RIGHTBUTTON | TPM_LEFTALIGN | TPM_TOPALIGN, 
				rc.left, rc.bottom+1, 0, hwnd, NULL);

			pthis->m_bShowingMenu = false;
		}
	}

	return DefWindowProc (hwnd, msg, wp, lp);	
}

void vmsGetItButton::Create(HWND hwndParent, const RECT* prcFlash)
{
	if (m_hWnd)
		return;

	m_hWnd = CreateWindowEx (0, _T ("{E93F4E35-5841-41e7-AFF6-F456BBAE488B}"), NULL, 
		WS_CHILD | WS_VISIBLE, 0, 0, 0, 0, hwndParent, NULL, 
		_Module.GetModuleInstance (), NULL);

	m_hwndTB = CreateWindow (TOOLBARCLASSNAME, 
		NULL, WS_CHILD | WS_VISIBLE | TBSTYLE_FLAT |
		TBSTYLE_TRANSPARENT | TBSTYLE_LIST | 
		CCS_NODIVIDER | CCS_NORESIZE | CCS_NOPARENTALIGN, 0, 0, 16+70, 16+7, 
		m_hWnd, NULL, _Module.GetModuleInstance (), NULL);
	SendMessage (m_hwndTB, TB_SETEXTENDEDSTYLE, 0, TBSTYLE_EX_DRAWDDARROWS);

	SetWindowLongPtr (m_hwndTB, GWL_USERDATA, (LONG_PTR)this);
	SetWindowLongPtr (m_hWnd, GWL_USERDATA, (LONG_PTR)this);

	SendMessage (m_hwndTB, TB_BUTTONSTRUCTSIZE, sizeof (TBBUTTON), 0);

	std::string str = vmsFdmTranslations::o ().GetString (L_DLBYFDM);
	if (str.empty ())
		str = "Download with FDM";
	USES_CONVERSION;
	SendMessage (m_hwndTB, TB_ADDSTRING, 0, (LPARAM)A2CT (str.c_str ()));

	SendMessage (m_hwndTB, TB_SETBITMAPSIZE, 0, MAKELONG (16, 16));
	SendMessage (m_hwndTB, TB_SETIMAGELIST, 0, (LPARAM)m_hImgs);
	
	TBBUTTON btn = {0};
	btn.iBitmap = 0;
	btn.idCommand = ID_DOWNLOAD_IT;
	btn.fsState = TBSTATE_ENABLED;
	btn.fsStyle = TBSTYLE_BUTTON | TBSTYLE_DROPDOWN;
	btn.dwData = 0;
	btn.iString = 0;
	SendMessage (m_hwndTB, TB_ADDBUTTONS, 1, (LPARAM)&btn);

	RECT rc;
	SendMessage (m_hwndTB, TB_GETRECT, btn.idCommand, (LPARAM)&rc);

	int x, y;

	int cx = rc.right - rc.left;
	int cy = rc.bottom - rc.top;

	if (prcFlash == NULL)
	{
		POINT pt; GetCursorPos (&pt);
		ScreenToClient (hwndParent, &pt);
		x = pt.x += 10, y = pt.y -= 50;
		RECT rc0; GetClientRect (hwndParent, &rc0);
		if (x + cx >= rc0.right)
			x = rc0.right - cx - 1;
		if (x < 0)
			x = 0;
		if (y < 0)
			y = 0;
	}
	else
	{
		RECT rc;
		GetWindowRect (hwndParent, &rc);
		POINT pt;
		if (prcFlash->top - rc.top >= cy)
			pt.y = prcFlash->top - cy;
		else
			pt.y = prcFlash->bottom;
		if (prcFlash->left >= rc.left)
			pt.x = prcFlash->left;
		else
			pt.x = rc.left;
		ScreenToClient (hwndParent, &pt);
		x = pt.x; y = pt.y;
	}

	SetWindowPos (m_hWnd, NULL, x, y, cx, cy, SWP_NOZORDER);
	SetWindowPos (m_hwndTB, NULL, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOZORDER);

	HRGN hRgn = CreateRoundRectRgn (0, 0, cx + 1, cy + 1, 3, 3);
	SetWindowRgn (m_hWnd, hRgn, TRUE);
}

void vmsGetItButton::onClick()
{
	m_bWasClick = true;

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadOnDownloadItBtnClicked, this, 0, &dw));

	CWaitDlg dlg;
	dlg.m_strMsg = vmsFdmTranslations::o ().GetString (L_SEARCHING_FLVS);
	dlg.m_hEvCloseDlg = m_hEvCloseDlg = CreateEvent (NULL, TRUE, FALSE, NULL);
	if (dlg.m_strMsg.empty ())
		dlg.m_strMsg = _T ("Searching flash videos...");
	dlg.Create (GetFocus ());

	while (IsWindow (dlg))
	{
		MSG msg;
		while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);
		Sleep (10);
	}
	
	CloseHandle (m_hEvCloseDlg);
	m_hEvCloseDlg = NULL;
}

HWND vmsGetItButton::getHWND() const
{
	return m_hWnd;
}

const vmsFlvSniffDll* vmsGetItButton::getSniffDll() const
{
	return &m_sniffDll;
}

bool vmsGetItButton::isShowingMenu() const
{
	return m_bShowingMenu;
}

void vmsGetItButton::Settings_ShowButton(BOOL bShow)
{
	vmsIeHKCU hkcu;

	if (ERROR_SUCCESS != hkcu.Open (_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"),
			KEY_ALL_ACCESS))
	{
		if (ERROR_SUCCESS != hkcu.Create (_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"),
				KEY_ALL_ACCESS))
			return;
	}

	hkcu.getKey ().SetValue (bShow, _T ("ShowDownloadItBtn"));
}

BOOL vmsGetItButton::Settings_ShowButton()
{
	DWORD dwRes = TRUE;

	vmsIeHKCU hkcu;
	
	if (ERROR_SUCCESS == hkcu.Open (_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"),
			KEY_READ))
	{
		hkcu.getKey ().QueryValue (dwRes, _T ("ShowDownloadItBtn"));
	}

	return dwRes;
}

DWORD WINAPI vmsGetItButton::_threadOnDownloadItBtnClicked(LPVOID lp)
{
	HRESULT hr = CoInitialize (NULL);
	vmsGetItButton *pthis = (vmsGetItButton*)lp;
	pthis->m_sniffDll.OnDownloadItBtnClicked (pthis->m_strHtmlPageUrl.c_str (),
		pthis->m_strFrameUrl.c_str (), pthis->m_strSwfUrl.c_str (), pthis->m_strFlashVars.c_str (),
		pthis->m_strOtherSwfUrls.c_str (), pthis->m_strOtherFlashVars.c_str ());
	SetEvent (pthis->m_hEvCloseDlg);
	if (SUCCEEDED (hr))
		CoUninitialize ();
	return 0;
}

void vmsGetItButton::Close()
{
	PostMessage (m_hWnd, WM_CLOSE, 0, 0);
}

bool vmsGetItButton::Clicked() const
{
	return m_bWasClick;
}
