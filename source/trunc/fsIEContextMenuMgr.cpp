/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsIEContextMenuMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsIEContextMenuMgr::fsIEContextMenuMgr()
{

}

fsIEContextMenuMgr::~fsIEContextMenuMgr()
{

}

BOOL fsIEContextMenuMgr::AddContextMenu(LPCSTR pszMenuName, LPCSTR pszMenuUrl, DWORD dwContext)
{
	CRegKey key;

	CString strKey = "Software\\Microsoft\\Internet Explorer\\MenuExt\\";
	strKey += pszMenuName;

	if (ERROR_SUCCESS != key.Create (HKEY_CURRENT_USER, strKey))
		return FALSE;

	if (ERROR_SUCCESS != key.SetValue (pszMenuUrl))
		return FALSE;

	if (dwContext)
	{
		if (ERROR_SUCCESS != key.SetValue (dwContext, "Contexts"))
			return FALSE;
	}

	
	
	key.SetValue (1, "Free Download Manager");

	return TRUE;
}

BOOL fsIEContextMenuMgr::IsContextMenuPresent(LPCSTR pszMenuName)
{
	CRegKey key;

	CString strKey = "Software\\Microsoft\\Internet Explorer\\MenuExt\\";
	strKey += pszMenuName;

	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, strKey))
		return FALSE;

	return TRUE;
}

void fsIEContextMenuMgr::ReadState()
{
	m_bDLThisMenu = IsContextMenuPresent (LS (L_DLTHISIEMENU));
	m_bDLPageMenu = IsContextMenuPresent (LS (L_DLPAGEIEMENU));
	m_bDLAllMenu  = IsContextMenuPresent (LS (L_DLALLIEMENU));
	m_bDLSelectedMenu  = IsContextMenuPresent (LS (L_DLSELECTEDIEMENU));
	m_bDLFlashVideoMenu = IsContextMenuPresent (LS (L_DLFLASHVIDEOIEMENU));
}

BOOL fsIEContextMenuMgr::IsDLPageMenuPresent()
{
	return m_bDLPageMenu;
}

BOOL fsIEContextMenuMgr::IsDLThisMenuPresent()
{
	return m_bDLThisMenu;
}

BOOL fsIEContextMenuMgr::AddIEMenus()
{
	if (_App.Monitor_IEMenu_Enable () == FALSE)
		return TRUE;

	BOOL bOk = TRUE;
	CString strUrl = "file://";
	
	
	CString strPath = ((CFdmApp*)AfxGetApp ())->m_strAppPath;
	if (strPath == "")
		return FALSE;
	if (strPath [strPath.GetLength () - 1] != '/' && strPath [strPath.GetLength () - 1] != '\\')
		strPath += '\\';
	strUrl += strPath;

	if (m_bDLThisMenu == FALSE && _App.Monitor_IEMenu_DLThis ())
	{
		CString str = strUrl + "dllink.htm";
		bOk = bOk && AddContextMenu (LS (L_DLTHISIEMENU), str, IEMENU_CONTEXT_LINK | IEMENU_CONTEXT_IMAGE);
		if (bOk)
			m_bDLThisMenu = TRUE;
	}

	if (m_bDLPageMenu == FALSE && _App.Monitor_IEMenu_DLPage ())
	{
		CString str = strUrl + "dlpage.htm";
		if (AddContextMenu (LS (L_DLPAGEIEMENU), str, IEMENU_CONTEXT_DEFAULT|IEMENU_CONTEXT_SELECTEDTEXT))
			m_bDLPageMenu = TRUE;
		else
			bOk = FALSE;
	}

	if (m_bDLAllMenu == FALSE && _App.Monitor_IEMenu_DLAll ())
	{
		CString str = strUrl + "dlall.htm";
		if (AddContextMenu (LS (L_DLALLIEMENU), str, IEMENU_CONTEXT_DEFAULT|IEMENU_CONTEXT_SELECTEDTEXT|IEMENU_CONTEXT_LINK|IEMENU_CONTEXT_IMAGE))
			m_bDLAllMenu = TRUE;
		else
			bOk = FALSE;
	}

	if (m_bDLSelectedMenu == FALSE && _App.Monitor_IEMenu_DLSelected ())
	{
		CString str = strUrl + "dlselected.htm";
		if (AddContextMenu (LS (L_DLSELECTEDIEMENU), str, IEMENU_CONTEXT_DEFAULT|IEMENU_CONTEXT_SELECTEDTEXT|IEMENU_CONTEXT_LINK|IEMENU_CONTEXT_IMAGE))
			m_bDLSelectedMenu = TRUE;
		else
			bOk = FALSE;
	}

	if (m_bDLFlashVideoMenu == FALSE && _App.Monitor_IEMenu_DLFlashVideo ())
	{
		CString str = strUrl + "dlfvideo.htm";
		if (AddContextMenu (LS (L_DLFLASHVIDEOIEMENU), str, IEMENU_CONTEXT_DEFAULT|IEMENU_CONTEXT_SELECTEDTEXT|IEMENU_CONTEXT_LINK|IEMENU_CONTEXT_IMAGE))
			m_bDLFlashVideoMenu = TRUE;
		else
			bOk = FALSE;
		_App.WriteTranslatedStringToRegistry ("dlfvideoiemenu", LS (L_DLFLASHVIDEOIEMENU));
	}

	return bOk;
}

BOOL fsIEContextMenuMgr::IsIEMenusPresent()
{
	return m_bDLThisMenu || m_bDLPageMenu || m_bDLAllMenu || m_bDLSelectedMenu ||
		m_bDLFlashVideoMenu;
}

BOOL fsIEContextMenuMgr::DeleteIEMenus()
{
	BOOL bOk = TRUE;

	if (m_bDLThisMenu)
	{
		bOk = bOk && DeleteContextMenu (LS (L_DLTHISIEMENU));
		m_bDLThisMenu = FALSE;
	}

	if (m_bDLPageMenu)
	{
		bOk = bOk && DeleteContextMenu (LS (L_DLPAGEIEMENU));
		m_bDLPageMenu = FALSE;
	}

	if (m_bDLAllMenu)
	{
		bOk = bOk && DeleteContextMenu (LS (L_DLALLIEMENU));
		m_bDLAllMenu = FALSE;
	}

	if (m_bDLSelectedMenu)
	{
		bOk = bOk && DeleteContextMenu (LS (L_DLSELECTEDIEMENU));
		m_bDLSelectedMenu = FALSE;
	}

	if (m_bDLFlashVideoMenu)
	{
		bOk = bOk && DeleteContextMenu (LS (L_DLFLASHVIDEOIEMENU));
		m_bDLFlashVideoMenu = FALSE;
	}

	
	DeleteContextMenu ("Download all by Free Download Manager");
	DeleteContextMenu ("Download by Free Download Manager");
	DeleteContextMenu ("Download selected by Free Download Manager");
	DeleteContextMenu ("Download web site by Free Download Manager");
	

	return bOk;
}

BOOL fsIEContextMenuMgr::DeleteContextMenu(LPCSTR pszMenuName)
{
	CRegKey key;

	CString strKey = "Software\\Microsoft\\Internet Explorer\\MenuExt";

	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, strKey))
		return FALSE;

	if (ERROR_SUCCESS != key.DeleteSubKey (pszMenuName))
		return FALSE;

	return TRUE;
}

BOOL fsIEContextMenuMgr::IsDLAllMenuPresent()
{
	return m_bDLAllMenu;
}

BOOL fsIEContextMenuMgr::IsDLSelectedMenuPresent()
{
	return m_bDLSelectedMenu;
}

void fsIEContextMenuMgr::DeleteAllFDMsIEMenus()
{
	CRegKey key;

	CString strKey = "Software\\Microsoft\\Internet Explorer\\MenuExt";

	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, strKey))
		return;

	char szSubKey [1000]; DWORD dwszSubKey = sizeof (szSubKey);
	FILETIME ft;

	fs::list <fsString> vSubKeys;
	DWORD dwIndex = 0;

	while (ERROR_SUCCESS == RegEnumKeyEx (key, dwIndex++, szSubKey, &dwszSubKey, 
		NULL, NULL, NULL, &ft))
	{
		dwszSubKey = sizeof (szSubKey);

		CRegKey key2;
		if (ERROR_SUCCESS != key2.Open (key, szSubKey))
			continue;

		DWORD dwFDM = FALSE;
		key2.QueryValue (dwFDM, "Free Download Manager");

		if (dwFDM)
			vSubKeys.add (szSubKey);
	}

	for (int i = 0; i < vSubKeys.size (); i++)
		key.DeleteSubKey (vSubKeys [i]);
}

BOOL fsIEContextMenuMgr::IsDLFlashVideoMenuPresent()
{
	return m_bDLFlashVideoMenu;
}
