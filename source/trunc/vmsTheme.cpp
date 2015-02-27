/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsTheme.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsTheme::vmsTheme()
{
	m_hThemeDLL = LoadLibrary ("UxTheme.dll");
	
	if (m_hThemeDLL)
	{
		m_pfnOpenThemeData = (fntOpenThemeData)GetProcAddress (m_hThemeDLL, "OpenThemeData");
		m_pfnDrawThemeBackground = (fntDrawThemeBackground)GetProcAddress (m_hThemeDLL, "DrawThemeBackground");
		m_pfnCloseThemeData = (fntCloseThemeData)GetProcAddress (m_hThemeDLL, "CloseThemeData");
		m_pfnIsThemeActive = (fntIsThemeActive)GetProcAddress (m_hThemeDLL, "IsThemeActive");
		m_pfnSetWindowTheme = (fntSetWindowTheme)GetProcAddress (m_hThemeDLL, "SetWindowTheme");
	}
	else
	{
		m_pfnOpenThemeData = NULL;
		m_pfnDrawThemeBackground = NULL;
		m_pfnCloseThemeData = NULL;
		m_pfnIsThemeActive = NULL;
		m_pfnSetWindowTheme = NULL;
	}
}

vmsTheme::~vmsTheme()
{
	if (m_hThemeDLL)
		FreeLibrary (m_hThemeDLL);
}

HTHEME vmsTheme::OpenThemeData(HWND hwnd, LPCWSTR pszClassList)
{
	if (m_pfnOpenThemeData)
		return m_pfnOpenThemeData (hwnd, pszClassList);
	else
		return NULL;
}

HRESULT vmsTheme::DrawThemeBackground(HTHEME hTheme, HDC hdc, int iPartId, int iStateId, const RECT *pRect, const RECT *pClipRect)
{
	if (m_pfnDrawThemeBackground)
		return m_pfnDrawThemeBackground (hTheme, hdc, iPartId, iStateId, pRect, pClipRect);
	else
		return E_NOTIMPL;
}

HRESULT vmsTheme::CloseThemeData(HTHEME hTheme)
{
	if (m_pfnCloseThemeData)
		return m_pfnCloseThemeData (hTheme);
	else
		return E_NOTIMPL;
}

BOOL vmsTheme::IsThemeActive()
{
	return m_pfnIsThemeActive ? m_pfnIsThemeActive () : FALSE;
}

HRESULT vmsTheme::SetWindowTheme(HWND hwnd, LPCWSTR pszSubAppName, LPCWSTR pszSubIdList)
{
	if (m_pfnCloseThemeData)
		return m_pfnSetWindowTheme (hwnd, pszSubAppName, pszSubIdList);
	else
		return E_NOTIMPL;
}
