/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsTrayIconMgr.h"
#include "system.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsTrayIconMgr::fsTrayIconMgr()
{
	m_pIcons = NULL;
	m_iCurIconIndex = 0;

	m_cbNIDSize = GetShell32Version () >= 5 ? sizeof (NOTIFYICONDATA) : NOTIFYICONDATA_V1_SIZE;
}

fsTrayIconMgr::~fsTrayIconMgr()
{

}

BOOL fsTrayIconMgr::Create(HWND hWnd, UINT *pIcons, UINT cIcons, LPCSTR pszTooltip, UINT uCallbackMsg)
{
	LoadIcons (pIcons, cIcons);
	m_hWnd = hWnd;
	m_uCallbackMsg = uCallbackMsg;
	m_strTip = pszTooltip;
	
	return InitializeTrayIcon ();
}

void fsTrayIconMgr::LoadIcons(UINT *pIcons, UINT cIcons)
{
	if (m_pIcons)
		delete [] m_pIcons;

	m_pIcons = new HICON [cIcons];
	m_cIcons = cIcons;

	for (UINT i = 0; i < cIcons; i++)
		m_pIcons [i] = LoadIcon (AfxGetInstanceHandle (), MAKEINTRESOURCE (pIcons [i]));
}

void fsTrayIconMgr::Remove()
{
	NOTIFYICONDATA data;

	data.cbSize = m_cbNIDSize;
	data.hWnd = m_hWnd;
	data.uID = m_nID;

	Shell_NotifyIcon (NIM_DELETE, &data);
}

BOOL fsTrayIconMgr::ShowIcon(int iIndex)
{
	NOTIFYICONDATA data;

	if (m_pIcons == NULL)
		return FALSE;

	data.cbSize = m_cbNIDSize;
	data.hIcon = m_pIcons [m_iCurIconIndex = iIndex];
	data.hWnd = m_hWnd;
	data.uFlags = NIF_ICON;
	data.uID = m_nID;

	return Shell_NotifyIcon (NIM_MODIFY, &data);
}

BOOL fsTrayIconMgr::InitializeTrayIcon()
{
	NOTIFYICONDATA data;

	data.cbSize = m_cbNIDSize;
	data.hIcon = m_pIcons [0];
	data.hWnd = m_hWnd;
	strcpy (data.szTip, m_strTip);
	data.uCallbackMessage = m_uCallbackMsg;
	data.uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
	data.uID = m_nID = 0;

	return Shell_NotifyIcon (NIM_ADD, &data);
}

void fsTrayIconMgr::TestIcon()
{
	if (FALSE == ShowIcon (m_iCurIconIndex))
	{
		InitializeTrayIcon ();
		ShowIcon (m_iCurIconIndex);
	}
}

BOOL fsTrayIconMgr::ShowBalloon(LPCSTR pszInfo, LPCSTR pszInfoTitle, DWORD dwNiifIcon)
{
	if (GetShell32Version () < 5)
		return FALSE;
		
	NOTIFYICONDATA data;

	data.cbSize = m_cbNIDSize;
	data.hWnd = m_hWnd;
	data.uID = m_nID;
	data.uFlags = NIF_INFO;
	
	if (strlen (pszInfo) > 255)
	{
		strncpy (data.szInfo, pszInfo, 255);
		data.szInfo [255] = 0;
	}
	else
		strcpy (data.szInfo, pszInfo);

	if (strlen (pszInfoTitle) > 63)
	{
		strncpy (data.szInfoTitle, pszInfoTitle, 63);
		data.szInfoTitle [63] = 0;
	}
	else
		strcpy (data.szInfoTitle, pszInfoTitle);

	data.dwInfoFlags = dwNiifIcon;
	data.uTimeout = UINT_MAX;

	return Shell_NotifyIcon (NIM_MODIFY, &data);
}
