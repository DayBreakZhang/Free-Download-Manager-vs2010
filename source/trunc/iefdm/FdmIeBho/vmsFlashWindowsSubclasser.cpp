/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFlashWindowsSubclasser.h"

vmsFlashWindowsSubclasser::vmsFlashWindowsSubclasser()
{

}

vmsFlashWindowsSubclasser::~vmsFlashWindowsSubclasser()
{

}

int vmsFlashWindowsSubclasser::FindWindow(HWND hwnd) const
{
	for (size_t i = 0; i < m_vWnds.size (); i++)
	{
		if (m_vWnds [i].hwnd == hwnd)
			return i;
	}
	return -1;
}

bool vmsFlashWindowsSubclasser::Subclass(HWND hwnd, WNDPROC pfn, LPVOID pvData)
{
	if (FindWindow (hwnd) != -1)
		return false;

	FlashWindow wnd;
	wnd.hwnd = hwnd;
	wnd.pfnOldProc = (WNDPROC) GetWindowLongPtr (hwnd, GWL_WNDPROC);

	if (wnd.pfnOldProc == pfn)
		return false;

	wnd.pvData = pvData;
	m_vWnds.push_back (wnd);

	SetWindowLongPtr (hwnd, GWL_WNDPROC, (LONG_PTR)pfn);

	return true;
}

vmsFlashWindowsSubclasser::FlashWindow* vmsFlashWindowsSubclasser::getWindow(int nIndex)
{
	return &m_vWnds [nIndex];
}

vmsFlashWindowsSubclasser& vmsFlashWindowsSubclasser::o()
{
	static vmsFlashWindowsSubclasser o;
	return o;
}
