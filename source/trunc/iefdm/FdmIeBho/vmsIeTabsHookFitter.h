/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIETABSHOOKFITTER_H__D942AC16_4045_470C_B616_7A92291E19C5__INCLUDED_)
#define AFX_VMSIETABSHOOKFITTER_H__D942AC16_4045_470C_B616_7A92291E19C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <comdef.h>
#include <vector>

class vmsIeTabsHookFitter  
{
public:
	static vmsIeTabsHookFitter& o();
	void RemoveTabHook (IWebBrowser2 *pwb);
	void SetTabHook (IWebBrowser2* pwb);
	vmsIeTabsHookFitter();
	virtual ~vmsIeTabsHookFitter();

protected:
	struct vmsTab 
	{
		HANDLE hThreadFitter;
		HHOOK hHook;
		DWORD dwTabThreadId;
		HWND hwndTab;
		IWebBrowser2 *pwb;
		HANDLE hevShutdown;
	};
	std::vector <vmsTab*> m_vTabs;

protected:
	CRITICAL_SECTION m_csTabs;
	vmsTab* findTabByThreadId (DWORD dwId);
	static LRESULT CALLBACK _hookProc (int nCode, WPARAM wp, LPARAM lp);
	static DWORD WINAPI _threadHookFitter (LPVOID pv);
};

#endif 
