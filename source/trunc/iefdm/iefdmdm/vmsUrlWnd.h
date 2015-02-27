/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSURLWND_H__FD1AC562_2E87_4CF9_90CD_CC099DC7DAD4__INCLUDED_)
#define AFX_VMSURLWND_H__FD1AC562_2E87_4CF9_90CD_CC099DC7DAD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsUrlWnd  
{
public:
	void Create (HWND hwndParent, RECT &rcPos, LPCTSTR ptszTitle, LPCTSTR ptszUrl);
	vmsUrlWnd();
	virtual ~vmsUrlWnd();

protected:
	bool isCursorOverText();
	RECT m_rcText;
	void OnClick();
	tstring m_tstrUrl;
	void Draw (HDC hdc);
	static vmsUrlWnd* getThis (HWND hwnd);
	static LRESULT CALLBACK _WndProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static void RegisterWndClass();
	HWND m_hwnd;
	HFONT m_hTextFont;
};

#endif 
