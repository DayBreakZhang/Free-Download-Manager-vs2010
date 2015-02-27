/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>
#include "UploadShellExt.h"

#include "UploadShellExt_i.c"
#include "FdmUplShlExt.h"
#include "FdmUplSendToShlExt.h"
#include "FdmUplShellExts.h"

CComModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
OBJECT_ENTRY(CLSID_FdmUplShlExt, CFdmUplShlExt)
OBJECT_ENTRY(CLSID_FdmUplSendToShlExt, CFdmUplSendToShlExt)
OBJECT_ENTRY(CLSID_FdmUplShellExts, CFdmUplShellExts)
END_OBJECT_MAP()

extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID )
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        _Module.Init(ObjectMap, hInstance, &LIBID_UPLOADSHELLEXTLib);
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

#include "FdmUplShellExts.h"
