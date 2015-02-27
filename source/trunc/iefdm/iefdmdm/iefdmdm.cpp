/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "iefdmdm.h"

#include "iefdmdm_i.c"
#include "IEWGDM.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_IEWGDM, CIEWGDM)
END_OBJECT_MAP()

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID )
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
		setlocale (LC_NUMERIC, ".ACP");
        _Module.Init(ObjectMap, hInstance, &LIBID_IEFDMDMLib);
        DisableThreadLibraryCalls(hInstance);
    }
    else if (dwReason == DLL_PROCESS_DETACH)
	{
        _Module.Term();
	}
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
    
    return _Module.RegisterServer(TRUE);
}

STDAPI DllUnregisterServer(void)
{
    CRegKey key;

	key.Open (HKEY_CURRENT_USER, _T ("Software\\Microsoft\\Internet Explorer"));
	key.DeleteValue (_T ("DownloadUI"));

	return _Module.UnregisterServer(TRUE);
}

STDAPI vmsInstaller (bool bInstall, bool bCurrentUserOnly)
{
	if (bCurrentUserOnly)
		AtlSetPerUserRegistration (true);

	HRESULT hrRes = bInstall ? DllRegisterServer () : DllUnregisterServer ();

	if (bCurrentUserOnly)
		AtlSetPerUserRegistration (false);

	return hrRes;
}

