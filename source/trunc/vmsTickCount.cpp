/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsTickCount.h"

vmsCriticalSection* vmsTickCount::m_pcsMyGetTickCount64 = new vmsCriticalSection;

vmsTickCount::vmsTickCount(void)
{
}

vmsTickCount::~vmsTickCount(void)
{
}

UINT64 vmsTickCount::GetTickCount64(void)
{
	typedef ULONGLONG (WINAPI *FNGetTickCount64)();
	static FNGetTickCount64 _pfnGetTickCount64 = NULL;
	if (!_pfnGetTickCount64)
	{
		HMODULE hDll = GetModuleHandle ("kernel32.dll");
		if (hDll)
			_pfnGetTickCount64 = (FNGetTickCount64) GetProcAddress (hDll, "GetTickCount64");
		if (!_pfnGetTickCount64)
			_pfnGetTickCount64 = myGetTickCount64;
	}
	return _pfnGetTickCount64 ();
}

UINT64 WINAPI vmsTickCount::myGetTickCount64(void)
{
	static UINT64 _uCorrention = 0;
	static DWORD _dwPrevValue = 0;

	vmsAUTOLOCKSECTION_PTR (m_pcsMyGetTickCount64);
	
	DWORD dwResult = ::GetTickCount ();
	if (dwResult < _dwPrevValue)
		_uCorrention += DWORD_MAX;

	_dwPrevValue = dwResult;

	return _uCorrention + dwResult;
}
