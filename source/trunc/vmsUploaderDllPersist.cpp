/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsUploaderDllPersist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUploaderDllPersist::vmsUploaderDllPersist()
{

}

vmsUploaderDllPersist::~vmsUploaderDllPersist()
{

}

BOOL vmsUploaderDllPersist::GetProfileBinary(LPCSTR pszSection, LPCSTR pszName, LPBYTE *ppData, UINT *pnDataSize)
{
	return _App.get_SettingsStore ()->GetProfileBinary (pszSection, pszName, ppData, pnDataSize);
}

void vmsUploaderDllPersist::WriteProfileBinary(LPCSTR pszSection, LPCSTR pszName, LPVOID pvData, UINT nDataSize)
{
	_App.get_SettingsStore ()->WriteProfileBinary (pszSection, pszName, (LPBYTE)pvData, nDataSize);
}

void vmsUploaderDllPersist::FreeBuffer(LPBYTE pb)
{
	delete [] pb;
}

UINT vmsUploaderDllPersist::GetProfileInt(LPCSTR pszSection, LPCSTR pszName, UINT nDefValue)
{
	return _App.get_SettingsStore ()->GetProfileInt (pszSection, pszName, nDefValue);
}

void vmsUploaderDllPersist::WriteProfileInt(LPCSTR pszSection, LPCSTR pszName, UINT nValue)
{
	_App.get_SettingsStore ()->WriteProfileInt (pszSection, pszName, nValue);
}

BOOL vmsUploaderDllPersist::GetProfileString (LPCSTR pszSection, LPCSTR pszName, LPCSTR pszDefValue, LPSTR pszValue, DWORD *pdwValueSize)
{
	CString str = _App.get_SettingsStore ()->GetProfileString (pszSection, pszName, pszDefValue);
	if (*pdwValueSize <= (DWORD)str.GetLength ())
	{
		*pdwValueSize = str.GetLength () + 1;
		return FALSE;
	}
	lstrcpy (pszValue, str);
	return TRUE;
}

void vmsUploaderDllPersist::WriteProfileString (LPCSTR pszSection, LPCSTR pszName, LPCSTR pszValue)
{
	_App.get_SettingsStore ()->WriteProfileString (pszSection, pszName, pszValue);
}