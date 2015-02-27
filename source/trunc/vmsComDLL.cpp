/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsComDLL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsComDLL::vmsComDLL()
{
	CoInitialize (NULL);
	m_pfnRegServer = m_pfnUnregServer = NULL;
}

vmsComDLL::~vmsComDLL()
{
	CoUninitialize ();
}

bool vmsComDLL::Load(LPCSTR pszDll)
{
	if (false == vmsDLL::Load (pszDll))
		return false;

	m_pfnRegServer = (FNDLLRS) GetProcAddress ("DllRegisterServer");
	m_pfnUnregServer = (FNDLLRS) GetProcAddress ("DllUnregisterServer");

	return m_pfnRegServer != NULL && m_pfnUnregServer != NULL;
}

HRESULT vmsComDLL::RegisterServer(bool bRegister)
{
	FNDLLRS pfn = bRegister ? m_pfnRegServer : m_pfnUnregServer;
	if (pfn == NULL)
		return E_NOTIMPL;
	return pfn ();
}
