/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIELOCK_H__D943D89A_D41F_4B36_981D_AFDE73AAF9FD__INCLUDED_)
#define AFX_VMSIELOCK_H__D943D89A_D41F_4B36_981D_AFDE73AAF9FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsIeLock  
{
public:
	static void Unlock();
	static void Lock();

protected:
	static void UnsubclassIeWindow(HWND hwnd);
	static void UnsubclassIeWindows ();
	static void SubclassIeWindow (HWND hwnd);
	static void SubclassIeWindows();
	static LRESULT WINAPI _IeWndProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static bool isIe();
	static DWORD WINAPI _threadFindIeLockWindow (LPVOID);
	static DWORD WINAPI _threadCloseIeLockWindow (LPVOID);
	
	static void CloseIeLockWindow();
	
	
	static void OpenIeLockWindow();
	static LONG _cLocks;
	static HWND _hwndIeLock;
	static WNDPROC _pfnIeWndOrigProc;
	static int _cTabsInLastClosingWindow;
};

#endif 
