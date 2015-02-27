/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsIeHKCU.h"
#include <string>

vmsIeHKCU::vmsIeHKCU()
{

}

vmsIeHKCU::~vmsIeHKCU()
{

}

LONG vmsIeHKCU::Open(LPCTSTR ptszPath, REGSAM samDesired)
{
	Close ();

	if (!IsIeInProtectedMode ())
		return m_key.Open (HKEY_CURRENT_USER, ptszPath, samDesired);
	
	std::string str = _T ("Software\\Microsoft\\Internet Explorer\\LowRegistry\\");
	str += ptszPath;
	return m_key.Open (HKEY_CURRENT_USER, str.c_str (), samDesired);
}

LONG vmsIeHKCU::Create(LPCTSTR ptszPath, REGSAM samDesired)
{
	Close ();

	if (!IsIeInProtectedMode ())
		return m_key.Create (HKEY_CURRENT_USER, ptszPath, NULL, 0, samDesired, NULL, NULL);
	
	std::string str = _T ("Software\\Microsoft\\Internet Explorer\\LowRegistry\\");
	str += ptszPath;
	return m_key.Create (HKEY_CURRENT_USER, str.c_str (), NULL, 0, samDesired, NULL, NULL);
}

void vmsIeHKCU::Close()
{
	m_key.Close ();
}

bool vmsIeHKCU::IsIeInProtectedMode()
{
	static int _iRes = 2;

	if (_iRes != 2)
		return _iRes != 0;

	HMODULE hDll = GetModuleHandle ("ieframe.dll");
	if (!hDll)
	{
		_iRes = 0;
		return false;
	}
	
	typedef HRESULT (__stdcall *FNIPMP)(BOOL*);
	FNIPMP pfn = (FNIPMP)GetProcAddress (hDll, "IEIsProtectedModeProcess");
	if (!pfn)
	{
		_iRes = 0;
		return false;
	}
	
	BOOL bResult = FALSE;
	if (SUCCEEDED (pfn (&bResult)))
		_iRes = bResult != 0;
	else 
		_iRes = 0;

	return _iRes != 0;
}

CRegKey& vmsIeHKCU::getKey()
{
	return m_key;
}
