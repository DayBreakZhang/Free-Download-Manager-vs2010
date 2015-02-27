/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <assert.h>
#include "vmsOeWindows.h"

#include "vmsNewMailWnd.h"
#include "fsLangMgr.h"
#include <vector>

vmsOeWindows _OeW;

#include <stdlib.h>
#include <atlbase.h>

HANDLE _hModule = NULL;

DWORD WINAPI _threadMonitorForNewWindows (LPVOID)
{
	HANDLE hevAppShutdown = CreateEvent (NULL, TRUE, FALSE, "fum - oe - injapp");
	std::vector <HWND> v;

	do
	{
		HWND hwnd = FindWindow ("ATH_Note", 0);
		if (hwnd)
		{
			if (vmsNewMailWnd::AttachToWindow (hwnd))
				v.push_back (hwnd);
		}
	}
	while (WaitForSingleObject (hevAppShutdown, 500) == WAIT_TIMEOUT);

	CloseHandle (hevAppShutdown);

	for (size_t i = 0; i < v.size (); i++)
		vmsNewMailWnd::DetachFromWindow (v [i]);

	FreeLibraryAndExitThread ((HMODULE)_hModule, 0);
	return 0;
}

BOOL InitializeLanguage ()
{
	CRegKey key;
	char sz [MAX_PATH] = ""; DWORD dw = sizeof (sz);

	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Upload Manager", KEY_READ))
	{

		key.QueryValue (sz, "lngsroot", &dw);
		if (*sz == 0)
			key.QueryValue (sz, "Path", &dw);
	}

	if (*sz == 0)
	{
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", KEY_READ))
				key.QueryValue (sz, "Path", &dw);
	}

	if (*sz == 0)
		return FALSE;

	lstrcat (sz, "\\Language");
	
	if (FALSE == _LngMgr.Initialize (sz))
		return FALSE;

	*sz = 0;

	CRegKey key2;
	if (ERROR_SUCCESS == key2.Open (key, "Settings\\View", KEY_READ))
	{
		dw = sizeof (sz);
		key2.QueryValue (sz, "Language", &dw);
	}

	if (*sz == 0)
		GetLocaleInfo (LOCALE_USER_DEFAULT, LOCALE_SENGLANGUAGE, sz, sizeof (sz));

	BOOL bLoaded = FALSE;

	for (int i = 0; i < _LngMgr.GetLngCount (); i++)
	{
		LPCSTR pszFile = _LngMgr.GetLngFilePathName (i);
		pszFile += lstrlen (pszFile);
		while (*pszFile != '\\' && *pszFile != '/')
			pszFile--;
		pszFile++;

		if (lstrcmpi (_LngMgr.GetLngName (i), sz) == 0 || lstrcmpi (pszFile, sz) == 0)
		{
			bLoaded = _LngMgr.LoadLng (i);
			break;
		}
	}

	if (bLoaded == FALSE)
		bLoaded = _LngMgr.LoadLng (_LngMgr.FindLngByName ("English"));

	return bLoaded;
}

BOOL InitializeDll ()
{
	if (FALSE == InitializeLanguage ())
		return FALSE;

	_OeW.Initialize ();

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadMonitorForNewWindows, 0, 0, &dw));

	return TRUE;
}

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		_hModule = hModule;
		if (FALSE == InitializeDll ())
			return FALSE;
	}

    return TRUE;
}

