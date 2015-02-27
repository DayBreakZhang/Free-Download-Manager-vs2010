/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <exdisp.h>
#include "vmsIeTabsHookFitter.h"
#include "assert.h"

vmsIeTabsHookFitter::vmsIeTabsHookFitter()
{
	InitializeCriticalSection (&m_csTabs);
}

vmsIeTabsHookFitter::~vmsIeTabsHookFitter()
{
	DeleteCriticalSection (&m_csTabs);
}

void vmsIeTabsHookFitter::SetTabHook(IWebBrowser2 *pwb)
{
	vmsTab* tab = new vmsTab;
	tab->pwb = pwb;
	tab->hwndTab = NULL;
	
	tab->hevShutdown = CreateEvent (NULL, TRUE, FALSE, NULL);
	tab->dwTabThreadId = 0;
	EnterCriticalSection (&m_csTabs);
	m_vTabs.push_back (tab);
	LeaveCriticalSection (&m_csTabs);
	DWORD dw;
	tab->hThreadFitter = CreateThread (NULL, 0, _threadHookFitter, tab, 0, &dw);
}

void vmsIeTabsHookFitter::RemoveTabHook(IWebBrowser2 *pwb)
{
	vmsTab *tab = NULL;

	EnterCriticalSection (&m_csTabs);

	for (size_t i = 0; i < m_vTabs.size (); i++)
	{
		if (m_vTabs [i]->pwb == pwb)
		{
			tab = m_vTabs [i];
			m_vTabs.erase (m_vTabs.begin () + i);
			break;
		}
	}

	LeaveCriticalSection (&m_csTabs);

	if (tab == NULL)
		return;

	SetEvent (tab->hevShutdown);
	WaitForSingleObject (tab->hThreadFitter, INFINITE);
	CloseHandle (tab->hThreadFitter);
	CloseHandle (tab->hevShutdown);
}

DWORD WINAPI vmsIeTabsHookFitter::_threadHookFitter(LPVOID pv)
{
	vmsTab* tab = (vmsTab*)pv;

	Sleep (1000);
	extern HWND find_ie_server (HWND hwnd);
	HWND hwnd = find_ie_server (tab->hwndTab);
	if (hwnd == NULL)
		return 0;

	tab->dwTabThreadId = GetWindowThreadProcessId (hwnd, NULL);
	tab->hHook = SetWindowsHookEx (WH_CALLWNDPROC, _hookProc, NULL, tab->dwTabThreadId);

	WaitForSingleObject (tab->hevShutdown, INFINITE);
	UnhookWindowsHookEx (tab->hHook);

	return 0;
}

vmsIeTabsHookFitter& vmsIeTabsHookFitter::o()
{
	static vmsIeTabsHookFitter o;
	return o;
}

LRESULT CALLBACK vmsIeTabsHookFitter::_hookProc(int nCode, WPARAM wp, LPARAM lp)
{
	CWPSTRUCT *p = (CWPSTRUCT*)lp;
	if (p == NULL)
		return 0;

	DWORD dwWndThreadId = GetWindowThreadProcessId (p->hwnd, NULL);
	vmsTab *tab = vmsIeTabsHookFitter::o ().findTabByThreadId (dwWndThreadId);
	assert (tab != NULL);
	if (tab == NULL)
		return 0;

	if (nCode >= 0)
	{
		extern LRESULT CALLBACK _IeServerWndProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
		_IeServerWndProc (p->hwnd, p->message, p->wParam, p->lParam);
	}
	
	return CallNextHookEx (tab->hHook, nCode, wp, lp);
}

vmsIeTabsHookFitter::vmsTab* vmsIeTabsHookFitter::findTabByThreadId(DWORD dwId)
{
	vmsTab *tab = NULL;

	EnterCriticalSection (&m_csTabs);

	for (size_t i = 0; i < m_vTabs.size (); i++)
	{
		if (m_vTabs [i]->dwTabThreadId == dwId)
		{
			tab = m_vTabs [i];
			break;
		}
	}

	LeaveCriticalSection (&m_csTabs);

	return tab;
}
