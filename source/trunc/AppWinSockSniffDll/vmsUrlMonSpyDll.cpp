/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUrlMonSpyDll.h"

HMODULE vmsUrlMonSpyDll::m_hDll = NULL;

vmsUrlMonSpyDll::vmsUrlMonSpyDll()
{

}

vmsUrlMonSpyDll::~vmsUrlMonSpyDll()
{

}

vmsUrlMonRequestPtr vmsUrlMonSpyDll::FindRequest(LPCWSTR pwszUrl, LPBYTE pbPostData, DWORD dwPostDataSize, bool bInProgressOnly)
{
	if (!m_hDll)
		return false;

	typedef vmsUrlMonRequest* (WINAPI *FNfdmumspy_findRequest) (LPCWSTR pwszUrl, LPBYTE pbPostData, DWORD dwPostDataSize, bool bInProgressOnly);
	static FNfdmumspy_findRequest _pfnFind = NULL;
	if (!_pfnFind)
		_pfnFind = (FNfdmumspy_findRequest) GetProcAddress (m_hDll, "fdmumspy_findRequest");
	if (!_pfnFind)
		return NULL;

	vmsUrlMonRequestPtr spReq = _pfnFind (pwszUrl, pbPostData, dwPostDataSize, bInProgressOnly);
	if (spReq)
		spReq->Release (); 

	return spReq;
}

void vmsUrlMonSpyDll::MakeSureDllLoaded()
{
	if (m_hDll)
		return;

	m_hDll = GetModuleHandle (_T ("fdmumsp.dll"));

	if (!m_hDll)
	{
		extern HMODULE _hModule;
		TCHAR tsz [MAX_PATH] = _T ("");
		GetModuleFileName (_hModule, tsz, MAX_PATH);
		LPTSTR ptsz = _tcsrchr (tsz, '\\');
		if (ptsz)
		{
			_tcscpy (ptsz + 1, _T ("fdmumsp.dll"));
			m_hDll = LoadLibrary (tsz);
		}
	}
}

void vmsUrlMonSpyDll::CheckDllLoaded()
{
	if (m_hDll)
		return;
	
	m_hDll = GetModuleHandle (_T ("fdmumsp.dll"));
}
