/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFlvSniffDllLoader.h"
#include "vmsIeHKCU.h"

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
	vmsIeHKCU hkcu;

	if (ERROR_SUCCESS != hkcu.Open (
			_T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\FlvMonitoring"), 
			KEY_READ))
		return true;

	DWORD dw = TRUE;

	hkcu.getKey ().QueryValue (dw, _T ("Enable"));

	if (!dw)
		return false;

	dw = m_dwBrowser;
	hkcu.getKey ().QueryValue (dw, "ProcessList");

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
		GetModuleFileName (_Module.GetModuleInstance (), tsz, MAX_PATH);
		LPTSTR ptsz = _tcsrchr (tsz, '\\');
		if (ptsz)
		{
			_tcscpy (ptsz + 1, _T ("flvsniff.dll"));
			m_hDll = LoadLibrary (tsz);
		}
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

