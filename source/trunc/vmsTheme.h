/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTHEME_H__099DAAAB_05C7_4633_A4D8_0F6ACA94284F__INCLUDED_)
#define AFX_VMSTHEME_H__099DAAAB_05C7_4633_A4D8_0F6ACA94284F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#ifndef HTHEME
typedef HANDLE HTHEME;
#endif

typedef HTHEME (WINAPI *fntOpenThemeData)(HWND hwnd,LPCWSTR pszClassList);
typedef HRESULT (WINAPI *fntDrawThemeBackground)(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
typedef HRESULT (WINAPI *fntCloseThemeData)(HTHEME hTheme);
typedef BOOL (WINAPI* fntIsThemeActive)();
typedef HRESULT (WINAPI *fntSetWindowTheme)(HWND, LPCWSTR, LPCWSTR);

#define TBMF_PAD                0x00000001
#define TBMF_BARPAD             0x00000002
#define TBMF_BUTTONSPACING      0x00000004

#define TB_GETMETRICS           (WM_USER + 101)
#define TB_SETMETRICS           (WM_USER + 102)

class vmsTheme  
{
public:
	HRESULT SetWindowTheme (HWND hwnd, LPCWSTR pszSubAppName, LPCWSTR pszSubIdList);
	BOOL IsThemeActive();
	HRESULT CloseThemeData(HTHEME hTheme);
	HRESULT DrawThemeBackground (HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect);
	HTHEME OpenThemeData (HWND hwnd, LPCWSTR pszClassList);
	vmsTheme();
	virtual ~vmsTheme();

protected:
	HMODULE m_hThemeDLL;
	fntOpenThemeData m_pfnOpenThemeData;
	fntDrawThemeBackground m_pfnDrawThemeBackground;
	fntCloseThemeData m_pfnCloseThemeData;
	fntIsThemeActive m_pfnIsThemeActive;
	fntSetWindowTheme m_pfnSetWindowTheme;
};

#endif 
