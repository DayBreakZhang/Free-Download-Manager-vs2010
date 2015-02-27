/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vms7zipFormatDLL.h"
#include <archive\IArchive.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vms7zipFormatDLL::vms7zipFormatDLL(LPCSTR pszDll)
{
	m_hDll = NULL;
	m_pfnCreateObject = NULL;
	m_pfnGetHandlerProperty = NULL;

	if (pszDll)
		Load (pszDll);
}

vms7zipFormatDLL::~vms7zipFormatDLL()
{
	Free ();
}

bool vms7zipFormatDLL::Load(LPCSTR pszDll)
{
	Free ();
	m_hDll = LoadLibrary (pszDll);
	if (m_hDll == NULL)
		return false;
	m_pfnCreateObject = (FNCreateObject)GetProcAddress (m_hDll, "CreateObject");
	m_pfnGetHandlerProperty = (FNGetHandlerProperty)GetProcAddress (m_hDll, "GetHandlerProperty");;
	return m_pfnCreateObject != NULL && m_pfnGetHandlerProperty != NULL;
}

void vms7zipFormatDLL::Free()
{
	if (m_hDll) 
	{
		FreeLibrary (m_hDll);
		m_hDll = NULL;
		m_pfnCreateObject = NULL;
		m_pfnGetHandlerProperty = NULL;
	}
}

HRESULT vms7zipFormatDLL::CreateObject(const GUID *classID, const GUID *interfaceID, void **outObject)
{
	if (m_pfnCreateObject == NULL)
		return E_NOTIMPL;

	return m_pfnCreateObject (classID, interfaceID, outObject);
}

HRESULT vms7zipFormatDLL::GetHandlerProperty(PROPID propID, PROPVARIANT *value)
{
	if (m_pfnGetHandlerProperty == NULL)
		return E_NOTIMPL;

	return m_pfnGetHandlerProperty (propID, value);
}

bool vms7zipFormatDLL::IsSupportedArchive(LPCSTR pszArchive)
{
	LPCSTR pszExt;
	pszExt = strrchr (pszArchive, '.');
	if (pszExt == NULL)
		return false;
	pszExt++;

	PROPVARIANT vt;
	PropVariantInit (&vt);
	if (FAILED (GetHandlerProperty (NArchive::kExtension, &vt)))
		return false;

	CString str = vt.bstrVal;
	SysFreeString (vt.bstrVal);

	if (FALSE == IsExtInExtsStr (str, pszExt))
		return false;

	return true;
}

HRESULT vms7zipFormatDLL::get_GUID(GUID *guid)
{
	PROPVARIANT vt;
	HRESULT hr;
	hr = GetHandlerProperty (NArchive::kClassID, &vt);
	if (FAILED (hr))
		return hr;

	CopyMemory (guid, vt.bstrVal, sizeof (GUID));
	SysFreeString (vt.bstrVal);

	return S_OK;
}
