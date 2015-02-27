/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSGETITBUTTON_H__A26B4169_6D5A_421F_AD64_34AA3AD12F8D__INCLUDED_)
#define AFX_VMSGETITBUTTON_H__A26B4169_6D5A_421F_AD64_34AA3AD12F8D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <commctrl.h>
#include <string>
#include "vmsFlvSniffDll.h"	

class vmsGetItButton  
{
public:
	bool Clicked () const;
	void Close();
	static BOOL Settings_ShowButton ();
	static void Settings_ShowButton (BOOL bShow);
	bool isShowingMenu () const;
	const vmsFlvSniffDll* getSniffDll () const;
	HWND getHWND () const;
	std::string m_strHtmlPageUrl;
	std::string m_strFrameUrl;
	std::string m_strSwfUrl;
	std::string m_strFlashVars;
	std::string m_strOtherSwfUrls;
	std::string m_strOtherFlashVars;
	void Create (HWND hwndParent, const RECT* prcFlash);
	vmsGetItButton();
	virtual ~vmsGetItButton();

protected:
	bool m_bWasClick;
	static DWORD WINAPI _threadOnDownloadItBtnClicked (LPVOID lp);
	HANDLE m_hEvCloseDlg;
	bool m_bShowingMenu;
	vmsFlvSniffDll m_sniffDll;
	void onClick ();
	static HIMAGELIST m_hImgs;
	HWND m_hWnd, m_hwndTB;
	static LRESULT CALLBACK _TBParentWndProc (HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
	static void Initialize ();
};

#endif 
