/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsDLL.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDLL::vmsDLL(LPCSTR pszDll)
{
	m_hDLL = NULL;
	if (pszDll)
		Load (pszDll);
}

vmsDLL::~vmsDLL()
{

}

bool vmsDLL::Load(LPCSTR pszDll)
{
	Free ();
	m_hDLL = LoadLibrary (pszDll);
	if (m_hDLL == NULL)
		return false;
	return true;
}

void vmsDLL::Free()
{
	if (m_hDLL) 
	{
		FreeLibrary (m_hDLL);
		m_hDLL = NULL;
	}
}

FARPROC vmsDLL::GetProcAddress(LPCSTR pszProcName)
{
	if (m_hDLL == NULL)
		return NULL;

	return ::GetProcAddress (m_hDLL, pszProcName);
}

bool vmsDLL::is_Loaded()
{
	return m_hDLL != NULL;
}
