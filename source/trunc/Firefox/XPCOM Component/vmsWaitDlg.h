/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWAITDLG_H__56854275_0940_4F32_9253_7960323D17AB__INCLUDED_)
#define AFX_VMSWAITDLG_H__56854275_0940_4F32_9253_7960323D17AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <string>

class vmsWaitDlg  
{
public:
	HICON m_hIcon;
	bool m_bPostQuitMsg;
	std::string m_strMsg;
	HANDLE m_hevCloseDlg;
	BOOL Create (HINSTANCE hInstance, LPCTSTR lpTemplate, HWND hWndParent);
	HWND m_hwnd;
	vmsWaitDlg();
	virtual ~vmsWaitDlg();

protected:
	static void setThisPtr (HWND hwnd, vmsWaitDlg *pthis);
	static vmsWaitDlg* getThisPtr (HWND hwnd);
	static INT_PTR CALLBACK _DlgProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
};

#endif 
