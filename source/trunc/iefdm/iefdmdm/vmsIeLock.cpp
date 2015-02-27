/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsIeLock.h"
#include <comdef.h>
#include <dispex.h>
#include <hlguids.h>
#include <shlguid.h>
#include "vmsIeHelper.h"

HWND vmsIeLock::_hwndIeLock = NULL;
LONG vmsIeLock::_cLocks = 0;
WNDPROC vmsIeLock::_pfnIeWndOrigProc = NULL;
int vmsIeLock::_cTabsInLastClosingWindow = -1;

void vmsIeLock::Lock()
{
	if (1 == InterlockedIncrement (&_cLocks) && _hwndIeLock == NULL)
	{
		
	}
}

void vmsIeLock::Unlock()
{
	if (0 == InterlockedDecrement (&_cLocks))
	{
		
	}
}

void vmsIeLock::OpenIeLockWindow()
{
	IWebBrowser2 *pBrowser2 = NULL;
	
	CoCreateInstance (CLSID_InternetExplorer, NULL, CLSCTX_ALL, IID_IWebBrowser2, (void**)&pBrowser2);
	
	if (pBrowser2)
	{
		VARIANT vEmpty;
		VariantInit (&vEmpty);
		
		VARIANT vFlags;
		V_VT(&vFlags) = VT_I4;
		V_I4(&vFlags) = navOpenInNewWindow | navNoHistory | navNoWriteToCache;

		TCHAR tszHtmlFile [MAX_PATH] = _T ("");
		GetModuleFileName (_Module.GetModuleInstance (), tszHtmlFile, MAX_PATH);
		ATLASSERT (*tszHtmlFile != 0);
		LPTSTR ptsz = _tcsrchr (tszHtmlFile, '\\');
		ATLASSERT (ptsz != NULL);
		if (ptsz == NULL)
		{
			pBrowser2->Release ();
			return;
		}
		_tcscpy (ptsz+1, _T ("fdmielock.html"));
		ATLASSERT (GetFileAttributes (tszHtmlFile) != DWORD (-1));
		if (GetFileAttributes (tszHtmlFile) == DWORD (-1))
		{
			pBrowser2->Release ();
			return;
		}
		TCHAR tszUrl [MAX_PATH] = _T ("");
		_tcscpy (tszUrl, _T ("file://"));
		_tcscat (tszUrl, tszHtmlFile);
		USES_CONVERSION;
		BSTR bstrURL = SysAllocString (T2W (tszUrl));
		
		pBrowser2->Navigate (bstrURL, &vFlags, &vEmpty, &vEmpty, &vEmpty);
		
		pBrowser2->Quit ();
		
		SysFreeString (bstrURL);
		pBrowser2->Release ();
	}

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadFindIeLockWindow, NULL, 0, &dw));
	Sleep (100);
}

void vmsIeLock::CloseIeLockWindow()
{
	if (_hwndIeLock)
	{
		PostMessage (_hwndIeLock, WM_CLOSE, 0, 0);
		_hwndIeLock = NULL;
	}
}

DWORD WINAPI vmsIeLock::_threadCloseIeLockWindow(LPVOID)
{
	while (true)
	{
		Sleep (300);

		if (_cLocks != 0)
			continue;

		vector <HWND> vIeWindows;
		HWND hwnd = NULL;

		do
		{
			hwnd = FindWindowEx (NULL, hwnd, _T ("IEFrame"), NULL);
			if (hwnd)
				vIeWindows.push_back (hwnd);
		}
		while (hwnd != NULL);

		int cProcessWnds = 0;
		DWORD dwCPID = GetCurrentProcessId ();
		for (size_t i = 0; i < vIeWindows.size (); i++)
		{
			DWORD dwPID = 0;
			GetWindowThreadProcessId (vIeWindows [i], &dwPID);
			if (dwPID == dwCPID)
				cProcessWnds++;
		}

		if (cProcessWnds == 1 && _cLocks == 0)
		{
			CloseIeLockWindow ();
			break;
		}
	}
	return 0;
}

DWORD WINAPI vmsIeLock::_threadFindIeLockWindow(LPVOID)
{
	HWND hwnd = NULL;
	while (!hwnd)
	{
		do
		{
			hwnd = FindWindowEx (NULL, hwnd, _T ("IEFrame"), NULL);
			if (!hwnd)
				break;
			TCHAR tsz [1000] = _T ("");
			GetWindowText (hwnd, tsz, 1000);
			if (_tcsstr (tsz, _T ("2B65874B-9932-44c4-BB26-6860D8624536")) != NULL)
				break;
		}
		while (true);
		
		Sleep (10);
	}
	
	_hwndIeLock = hwnd;
	
	if (_hwndIeLock)
	{
		
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadCloseIeLockWindow, NULL, 0, &dw));
	}

	return 0;
}

bool vmsIeLock::isIe()
{
	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MAX_PATH);
	LPTSTR ptsz = _tcsrchr (tsz, '\\');
	if (!ptsz)
		return false;
	return _tcsicmp (ptsz+1, _T ("iexplore.exe")) == 0;
}

#define WM_IE8_CLOSETAB		(WM_USER+31945)
#define WM_IE7_CLOSETAB		(WM_USER+155)

LRESULT WINAPI vmsIeLock::_IeWndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	if (_hwndIeLock) 
		return CallWindowProc (_pfnIeWndOrigProc, hwnd, msg, wp, lp);

	if (msg == WM_CLOSE)
	{
		_cTabsInLastClosingWindow = -1;
		SubclassIeWindows (); 
		vector <HWND> v;
		vmsIeHelper::GetIeWindows (v);
		if (v.size () == 1)
			_cTabsInLastClosingWindow = vmsIeHelper::GetTabCount (v[0]);
	}

	if ((msg == WM_IE7_CLOSETAB || msg == WM_IE8_CLOSETAB) && _cTabsInLastClosingWindow != -1)
	{
		if (_cTabsInLastClosingWindow == 1)
		{
			if (_cLocks != 0)
			{
				_hwndIeLock = hwnd;
				ShowWindow (hwnd, SW_HIDE);
				return 0; 
			}
		}
		_cTabsInLastClosingWindow--;
	}
	return CallWindowProc (_pfnIeWndOrigProc, hwnd, msg, wp, lp);
}

void vmsIeLock::SubclassIeWindows()
{
	vector <HWND> v;
	vmsIeHelper::GetIeWindows (v);
	ATLASSERT (v.size () != 0);
	for (size_t i = 0; i < v.size (); i++)
		SubclassIeWindow (v [i]);
}

void vmsIeLock::SubclassIeWindow(HWND hwnd)
{
	LONG_PTR pOld = GetWindowLongPtr (hwnd, GWL_WNDPROC);
	ATLASSERT (pOld != NULL);
	if (pOld == NULL)
		return;
	if (_pfnIeWndOrigProc == NULL)
		_pfnIeWndOrigProc = (WNDPROC)pOld;
	if (pOld == (LONG_PTR)_pfnIeWndOrigProc)
		SetWindowLongPtr (hwnd, GWL_WNDPROC, (LONG_PTR)_IeWndProc);
}

void vmsIeLock::UnsubclassIeWindows()
{
	vector <HWND> v;
	vmsIeHelper::GetIeWindows (v);
	for (size_t i = 0; i < v.size (); i++)
		UnsubclassIeWindow (v [i]);
	_cTabsInLastClosingWindow = -1;
}

void vmsIeLock::UnsubclassIeWindow(HWND hwnd)
{
	LONG_PTR pOld = GetWindowLongPtr (hwnd, GWL_WNDPROC);
	ATLASSERT (pOld != NULL);
	if (pOld == NULL)
		return;
	if (pOld == (LONG_PTR)_pfnIeWndOrigProc)
		return;
	SetWindowLongPtr (hwnd, GWL_WNDPROC, (LONG_PTR)_pfnIeWndOrigProc);
}
