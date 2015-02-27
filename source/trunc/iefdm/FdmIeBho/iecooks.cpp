/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "iecooks.h"

#include "iecooks_i.c"
#include "FDMIECookiesBHO.h"
#include "FDMIEStat.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_FDMIEBHO, CFDMIEBHO)
OBJECT_ENTRY(CLSID_FDMIEStat, CFDMIEStat)
END_OBJECT_MAP()

BOOL _bIsWin9x = FALSE;

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID )
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
		_bIsWin9x = GetVersion () & 0x80000000;

        _Module.Init(ObjectMap, hInstance, &LIBID_IEFDMBHOLib);
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
    
    return _Module.RegisterServer(TRUE);
}

STDAPI DllUnregisterServer(void)
{
    return _Module.UnregisterServer(TRUE);
}

BSTR WINAPI fdmbho_getTabUrl (DWORD dwThreadId)
{
	vmsCriticalSectionAutoLock csal (&CFDMIEBHO::_csInstances);
	int nIndex = CFDMIEBHO::findInstanceIndexByThreadId (dwThreadId);
	if (nIndex == -1)
		return NULL;
	CFDMIEBHO *bho = CFDMIEBHO::_vInstances [nIndex].pBHO;
	vmsCriticalSectionAutoLock csal2 (&bho->m_cswstrPageUrl);
	return SysAllocString (bho->m_wstrPageUrl.c_str ());
}