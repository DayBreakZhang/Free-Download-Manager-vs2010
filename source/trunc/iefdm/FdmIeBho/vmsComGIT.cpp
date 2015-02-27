/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsComGIT.h"

IGlobalInterfaceTablePtr vmsComGIT::m_spGIT;

vmsComGIT::vmsComGIT()
{

}

vmsComGIT::~vmsComGIT()
{

}

HRESULT vmsComGIT::RegisterInterfaceInGlobal(IUnknown *pUnk, REFIID riid, DWORD *pdwCookie)
{
	CreateGIT ();
	if (m_spGIT == NULL)
		return E_FAIL;
	return m_spGIT->RegisterInterfaceInGlobal (pUnk, riid, pdwCookie);
}

HRESULT vmsComGIT::CreateGIT()
{
	if (m_spGIT == NULL)
	{
		return m_spGIT.CreateInstance (CLSID_StdGlobalInterfaceTable, 
			NULL, CLSCTX_INPROC_SERVER);
	}

	return S_OK;
}

HRESULT vmsComGIT::GetInterfaceFromGlobal(DWORD dwCookie, REFIID riid, void **ppv)
{
	CreateGIT ();
	if (m_spGIT == NULL)
		return E_FAIL;
	return m_spGIT->GetInterfaceFromGlobal (dwCookie, riid, ppv);
}

HRESULT vmsComGIT::RevokeInterfaceFromGlobal(DWORD dwCookie)
{
	CreateGIT ();
	if (m_spGIT == NULL)
		return E_FAIL;
	return m_spGIT->RevokeInterfaceFromGlobal (dwCookie);
}
