/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFileExtension.h"

vmsFileExtension::vmsFileExtension()
{

}

vmsFileExtension::~vmsFileExtension()
{

}

LPCTSTR vmsFileExtension::getExtensionPart(LPCTSTR ptszFileName)
{
	if (!ptszFileName)
		return NULL;
	LPCTSTR ptsz = _tcsrchr (ptszFileName, '.');
	if (!ptsz)
		return NULL;
	return ptsz+1;
}

tstring vmsFileExtension::GetExtensionId(LPCTSTR ptszExt)
{
	assert (ptszExt != NULL);
	if (ptszExt == NULL)
		return _T ("");
	CRegKey key;
	tstring tstr = _T ("."); tstr += ptszExt;
	if (ERROR_SUCCESS != key.Open (HKEY_CLASSES_ROOT, tstr.c_str (), KEY_READ))
		return _T ("");
	TCHAR tsz [1000] = _T (""); DWORD dw = 1000;
	key.QueryValue (tsz, NULL, &dw);
	return tsz;
}

tstring vmsFileExtension::GetExtensionName(LPCTSTR ptszExt)
{
	tstring tstrId = GetExtensionId (ptszExt);
	if (tstrId.empty ())
		return _T ("");
	CRegKey key;
	if (ERROR_SUCCESS != key.Open (HKEY_CLASSES_ROOT, tstrId.c_str (), KEY_READ))
		return _T ("");
	TCHAR tsz [1000] = _T (""); DWORD dw = 1000;
	key.QueryValue (tsz, NULL, &dw);
	return tsz;
}
