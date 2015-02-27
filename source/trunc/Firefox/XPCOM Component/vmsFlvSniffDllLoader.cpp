/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <atlbase.h>
#include "vmsFlvSniffDllLoader.h"
#include <assert.h>

vmsFlvSniffDllLoader::vmsFlvSniffDllLoader(DWORD dwBrowser)
{
	m_dwBrowser = dwBrowser;
	m_hDll = NULL;
	m_htMonitorSettings = NULL;
	m_hevDestroyObj = NULL;
}

vmsFlvSniffDllLoader::~vmsFlvSniffDllLoader()
{
	if (m_htMonitorSettings)
	{
		SetEvent (m_hevDestroyObj);
		WaitForSingleObject (m_htMonitorSettings, INFINITE);
		CloseHandle (m_hevDestroyObj);
		CloseHandle (m_htMonitorSettings);
	}
}

bool vmsFlvSniffDllLoader::isDllEnabled() const
{
	CRegKey key;

	if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
			_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"), 
			KEY_READ))
		return true;

	DWORD dw = TRUE;

	key.QueryValue (dw, _T ("Enable"));

	if (!dw)
		return false;

	dw = m_dwBrowser;
	key.QueryValue (dw, "ProcessList");

	return (dw & m_dwBrowser) != 0;
}

void vmsFlvSniffDllLoader::MakeSureDllLoaded()
{
	if (m_hDll)
		return;
	if (GetModuleHandle ("flvsniff.dll"))
		return;
	if (!isDllEnabled ())
		return;
	if (!m_hDll)
	{
		TCHAR tsz [MAX_PATH] = _T ("");
		extern HMODULE _hModule;
		assert (_hModule != NULL);
		GetModuleFileName (_hModule, tsz, MAX_PATH);
		LPTSTR ptsz = _tcsrchr (tsz, '\\');
		if (ptsz)
		{
			_tcscpy (ptsz + 1, _T ("..\\..\\..\\flvsniff.dll"));
			m_hDll = LoadLibrary (tsz);
		}
	}
	if (!m_hDll)
	{
		CRegKey key; 
		if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, 
				_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager"), KEY_READ))
			return;
		TCHAR tszPath [MAX_PATH] = _T ("");
		DWORD dw = MAX_PATH;
		key.QueryValue (tszPath, _T ("Path"), &dw);
		_tcscat (tszPath, _T ("\\flvsniff.dll"));
		m_hDll = LoadLibrary (tszPath);
	}
	if (m_hDll)
	{
		if (!m_hevDestroyObj)
			m_hevDestroyObj = CreateEvent (NULL, TRUE, FALSE, NULL);
		DWORD dw;
		m_htMonitorSettings = CreateThread (NULL, 0, _threadMonitorSettings, this, 0, &dw);
	}
}

DWORD WINAPI vmsFlvSniffDllLoader::_threadMonitorSettings(LPVOID lp)
{
	vmsFlvSniffDllLoader *pthis = (vmsFlvSniffDllLoader*)lp;
	
	while (pthis->m_hDll)
	{
		if (WaitForSingleObject (pthis->m_hevDestroyObj, 60*1000) == WAIT_OBJECT_0)
			break;
		if (!pthis->isDllEnabled ())
		{
			HMODULE h = pthis->m_hDll;
			pthis->m_hDll = NULL;
			FreeLibrary (h);
			break;
		}
	}

	return 0;
}

