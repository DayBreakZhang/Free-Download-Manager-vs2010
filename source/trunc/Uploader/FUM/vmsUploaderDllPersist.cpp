/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUploaderDllPersist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUploaderDllPersist::vmsUploaderDllPersist()
{
	m_app = AfxGetApp ();
}

vmsUploaderDllPersist::~vmsUploaderDllPersist()
{

}

BOOL vmsUploaderDllPersist::GetProfileBinary(LPCSTR pszSection, LPCSTR pszName, LPBYTE *ppData, UINT *pnDataSize)
{
	return m_app->GetProfileBinary (pszSection, pszName, ppData, pnDataSize);
}

void vmsUploaderDllPersist::WriteProfileBinary(LPCSTR pszSection, LPCSTR pszName, LPVOID pvData, UINT nDataSize)
{
	m_app->WriteProfileBinary (pszSection, pszName, (LPBYTE)pvData, nDataSize);
}

void vmsUploaderDllPersist::FreeBuffer(LPBYTE pb)
{
	delete [] pb;
}

UINT vmsUploaderDllPersist::GetProfileInt(LPCSTR pszSection, LPCSTR pszName, UINT nDefValue)
{
	return m_app->GetProfileInt (pszSection, pszName, nDefValue);
}

void vmsUploaderDllPersist::WriteProfileInt(LPCSTR pszSection, LPCSTR pszName, UINT nValue)
{
	m_app->WriteProfileInt (pszSection, pszName, nValue);
}

BOOL vmsUploaderDllPersist::GetProfileString(LPCSTR pszSection, LPCSTR pszName, LPCSTR pszDefValue, LPSTR pszValue, DWORD *pdwValueSize)
{
	CString str = m_app->GetProfileString (pszSection, pszName, pszDefValue);
	if (*pdwValueSize <= (DWORD)str.GetLength ())
	{
		*pdwValueSize = str.GetLength () + 1;
		return FALSE;
	}
	lstrcpy (pszValue, str);
	return TRUE;
}

void vmsUploaderDllPersist::WriteProfileString(LPCSTR pszSection, LPCSTR pszName, LPCSTR pszValue)
{
	m_app->WriteProfileString (pszSection, pszName, pszValue);
}
