/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUploadsWnd.h"
#include "vmsDllCaller.h"
#include "UploadsWnd.h"
#include "resource.h"
#include "UploaderPropsSheet.h"
#include "dll.h"
#include <comdef.h>
#include "../UploadContextMenu/UploadShellExt/UploadShellExt.h"
#include <atlbase.h>

_COM_SMARTPTR_TYPEDEF(IFdmUplShellExts, __uuidof(IFdmUplShellExts));

#pragma data_seg("shdata")
HWND hwndIntegrationSettings = NULL;
#pragma data_seg()

#pragma comment(linker, "/section:shdata,rws")

void _SetDllCaller (vmsDllCaller *p)
{
	_pDllCaller = p;
}

vmsUploadsWnd* _CreateUploadsWindow (CWnd *pwndParent)
{
	ASSERT (_pDllCaller != NULL);
	if (_pDllCaller == NULL)
		return NULL;

	CUploadsWnd *pwndUploads = new CUploadsWnd;
	if (FALSE == pwndUploads->Create (pwndParent))
	{
		delete pwndUploads;
		return NULL;
	}

	return pwndUploads;
}

void _ShowIntegrationSettings (CWnd *pwndParent)
{
	if (IsWindow (hwndIntegrationSettings))
	{
		SetForegroundWindow (hwndIntegrationSettings);
		return;
	}

	AFX_MANAGE_STATE (AfxGetStaticModuleState ());

	HRESULT hr = CoInitialize (NULL);

	CUploaderPropsSheet sheet (LS (L_FUM_INTEGRATION_SETTINGS), pwndParent, true);

	sheet.m_phwndSheet = &hwndIntegrationSettings;

	_DlgMgr.DoModal (&sheet);

	hwndIntegrationSettings = NULL;

	if (SUCCEEDED (hr))
		CoUninitialize ();
}

void _EnableIntegration (BOOL bEnable, DWORD dwReserved)
{
	HRESULT hr = CoInitialize (NULL);
	char sz [MAX_PATH];

	if (bEnable)
	{
		IFdmUplShellExtsPtr spExts;
		spExts.CreateInstance (__uuidof (FdmUplShellExts));
		
		if (spExts == NULL)
		{
			_pDllCaller->GetCommonFilesFolder (sz);
			lstrcat (sz, "fumshext.dll");
			HMODULE hDll = LoadLibrary (sz);
			if (hDll != NULL)
			{
				typedef HRESULT (_stdcall *FNDRUS)(void);
				FNDRUS pfn;
				pfn = (FNDRUS)GetProcAddress (hDll, "DllRegisterServer");
				if (pfn)
					pfn ();
				FreeLibrary (hDll);
			}
			spExts.CreateInstance (__uuidof (FdmUplShellExts));
		}
		
		if (spExts != NULL)
		{
			spExts->put_ShowInExplorerContextMenu (bEnable);
			spExts->put_ShowInSendToContextMenu (bEnable);
			spExts = NULL;
		}
	}
	else
	{
		_pDllCaller->GetCommonFilesFolder (sz);
		lstrcat (sz, "fumshext.dll");
		HMODULE hDll = LoadLibrary (sz);
		if (hDll != NULL)
		{
			typedef HRESULT (_stdcall *FNDRUS)(void);
			FNDRUS pfn;
			pfn = (FNDRUS)GetProcAddress (hDll, "DllUnregisterServer");
			if (pfn)
				pfn ();
			FreeLibrary (hDll);
		}
	}

	CRegKey key;
	key.Open (HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run");

	if (bEnable)
	{
		char sz [MAX_PATH];
		#ifdef _DEBUG
		lstrcpy (sz, "E:\\VCW\\FDM\\FDM\\Uploader\\UploadContextMenu\\UploadOeMenu\\InjApp\\Debug\\fumoei.exe");
		#else
		_pDllCaller->GetCommonFilesFolder (sz);
		lstrcat (sz, "fumoei.exe");
		#endif

		ASSERT (GetFileAttributes (sz) != DWORD (-1));
		if (key.m_hKey) 
			key.SetValue (sz, "Free Uploader Oe Integration");
		ShellExecute (0, "open", sz, 0, 0, SW_SHOW);
	}
	else
	{
		HANDLE h = CreateEvent (NULL, TRUE, FALSE, "fum - oe - injapp");
		SetEvent (h);
		CloseHandle (h);
		if (key.m_hKey)
			key.DeleteValue ("Free Uploader Oe Integration");
	}

	
	_pDllCaller->GetCommonFilesFolder (sz);
	lstrcat (sz, "fumiebtn.dll");
	HMODULE hDll = LoadLibrary (sz);
	if (hDll != NULL)
	{
		typedef HRESULT (_stdcall *FNDRUS)(void);
		FNDRUS pfn;
		pfn = (FNDRUS)GetProcAddress (hDll, bEnable ? "DllRegisterServer" : "DllUnregisterServer");
		if (pfn)
			pfn ();
		FreeLibrary (hDll);
		CoFreeUnusedLibraries ();
	}
	

	if (SUCCEEDED (hr))
		CoUninitialize ();
}

void _GetVersion (DWORD *pdwDllInterfaceVersion, DWORD *pdwDllBuildNumber)
{
	if (pdwDllInterfaceVersion)
		*pdwDllInterfaceVersion = vmsUploadsDll::DLL_INTERFACE_VERSION;

	if (pdwDllBuildNumber)
		*pdwDllBuildNumber = vmsUploadsDll::DLL_BUILD_NUMBER;
}
