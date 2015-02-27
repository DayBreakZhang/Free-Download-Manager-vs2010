/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "FDMCustIEBtn.h"

#include "FDMCustIEBtn_i.c"
#include "FDMCustButton.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_FDMCustButton, CFDMCustButton)
END_OBJECT_MAP()

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID )
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_FDMCUSTIEBTNLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
        _Module.Term();
    return TRUE;    
}

STDAPI DllCanUnloadNow(void)
{
    return (_Module.GetLockCount()==0) ? S_OK : S_FALSE;
}

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _Module.GetClassObject(rclsid, riid, ppv);
}

STDAPI DllRegisterServer(void)
{
   	HKEY key;
	char szIco [MAX_PATH];
	char szCustomizer [1000];
	DWORD dwSize = MAX_PATH;

	if (ERROR_SUCCESS != RegOpenKey (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", &key))
		return E_FAIL;
	if (ERROR_SUCCESS != RegQueryValueEx (key, "Path", NULL, NULL, (LPBYTE) szIco, &dwSize))
		return E_FAIL;
	szIco [dwSize] = 0;
	if (szIco [dwSize-1] != '\\')
		lstrcat (szIco, "\\");
	lstrcat (szIco, "fdmcsiebtn.ico");

	dwSize = 1000;
	if (ERROR_SUCCESS != RegQueryValueEx (key, "Customizer", NULL, NULL, (LPBYTE) szCustomizer, &dwSize))
		return E_FAIL;
	szCustomizer [dwSize] = 0;

	RegCloseKey (key);

	
    HRESULT hr = _Module.RegisterServer(TRUE);
	if (FAILED (hr))
		return hr;

	RegOpenKey (HKEY_CURRENT_USER, "Software\\Microsoft\\Internet Explorer\\Extensions\\{DAC360AF-9FD0-432D-B2F2-ED3220F4CAD9}", &key);
	RegSetValueEx (key, "Icon", 0, REG_SZ, (LPBYTE)szIco, lstrlen (szIco));
	RegSetValueEx (key, "HotIcon", 0, REG_SZ, (LPBYTE)szIco, lstrlen (szIco));
	RegSetValueEx (key, "ButtonText", 0, REG_SZ, (LPBYTE)szCustomizer, lstrlen (szCustomizer));
	RegCloseKey (key);
	
	return hr;
}

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}

