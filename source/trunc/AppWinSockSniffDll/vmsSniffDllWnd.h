/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSNIFFDLLWND_H__DC3299D1_9992_41EA_9389_7D3076E6AF41__INCLUDED_)
#define AFX_VMSSNIFFDLLWND_H__DC3299D1_9992_41EA_9389_7D3076E6AF41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSniffDllWnd  
{
public:
	static LRESULT WINAPI _WndProc (HWND, UINT, WPARAM, LPARAM);
	void Create ();
	vmsSniffDllWnd();
	virtual ~vmsSniffDllWnd();

protected:
	static DWORD WINAPI _threadTransferDldsToFdm (LPVOID lp);
	static LRESULT OnProcessWebPageUrl (LPARAM lp);
	HWND m_hWnd;
};

#endif 
