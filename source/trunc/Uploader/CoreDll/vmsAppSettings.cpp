/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "CoreDll.h"
#include "vmsAppSettings.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsAppSettings::vmsAppSettings()
{

}

vmsAppSettings::~vmsAppSettings()
{

}

float vmsAppSettings::View_SplitterRatio(LPCSTR pszName)
{
	LPBYTE pf;
	UINT nSize;
	float f = 0.5f;

	if (GetProfileBinary (_T ("Settings\\View\\Splitters"), pszName, &pf, &nSize))
	{
		if (pf [0] == 0 && pf [1] == 0 && pf [2] == 192 && pf [3] == 255)
			f = 0.1f;
		else
			CopyMemory (&f, pf, sizeof (f));
		
		delete [] pf;

		if (f < 0 || f > 1)
			f = 0.5;
	}

	return f;
}

void vmsAppSettings::View_SplitterRatio(LPCSTR pszName, float f)
{
	WriteProfileBinary (_T ("Settings\\View\\Splitters"), pszName, (LPBYTE)&f, sizeof (f));
}

void vmsAppSettings::WriteProfileBinary(LPCSTR pszSection, LPCSTR pszName, LPVOID pvData, UINT nDataSize)
{
	_pDllCaller->GetPersist ()->WriteProfileBinary (pszSection, pszName, pvData, nDataSize);
}

BOOL vmsAppSettings::GetProfileBinary(LPCSTR pszSection, LPCSTR pszName, LPBYTE *ppData, UINT *pnDataSize)
{
	LPBYTE pb; UINT n;
	if (FALSE == _pDllCaller->GetPersist ()->GetProfileBinary (pszSection, pszName, &pb, &n))
		return FALSE;
	*ppData = new BYTE [n];
	CopyMemory (*ppData, pb, n);
	*pnDataSize = n;
	_pDllCaller->GetPersist ()->FreeBuffer (pb);
	return TRUE;
}

BOOL vmsAppSettings::View_UploadDoneDlg()
{
	return _pDllCaller->GetPersist ()->GetProfileInt ("Settings\\View", "UploadDoneDlg", TRUE);
}

void vmsAppSettings::View_UploadDoneDlg(BOOL b)
{
	_pDllCaller->GetPersist ()->WriteProfileInt ("Settings\\View", "UploadDoneDlg", b);
}
