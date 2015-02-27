/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsIeHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsIeHelper::vmsIeHelper()
{

}

vmsIeHelper::~vmsIeHelper()
{

}

bool vmsIeHelper::RegisterExeAsSafeToRun(LPCTSTR ptszAppGuid)
{
	CString strKey = _T ("Software\\Microsoft\\Internet Explorer\\Low Rights\\ElevationPolicy\\");
	strKey += ptszAppGuid;
	CRegKey key;
	bool bOK = ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strKey, KEY_ALL_ACCESS);
	if (!bOK)
		bOK = ERROR_SUCCESS == key.Create (HKEY_LOCAL_MACHINE, strKey, NULL, 0, KEY_ALL_ACCESS, NULL, NULL);
	if (!bOK)
		bOK = ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, strKey, KEY_ALL_ACCESS);
	if (!bOK)
		bOK = ERROR_SUCCESS == key.Create (HKEY_CURRENT_USER, strKey, NULL, 0, KEY_ALL_ACCESS, NULL, NULL);
	if (!bOK)
		return false;
	
	TCHAR tsz [MY_MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MY_MAX_PATH);

	LPTSTR ptsz = strrchr (tsz, '\\');
	if (!ptsz)
		return false;

	CString strName = ptsz+1;
	*ptsz = 0;

	bOK = ERROR_SUCCESS == key.SetValue (strName, _T ("AppName"));
	bOK = ERROR_SUCCESS == key.SetValue (tsz, _T ("AppPath")) && bOK;
	bOK = ERROR_SUCCESS == key.SetValue (3, _T ("Policy")) && bOK;

	return bOK;
}

bool vmsIeHelper::RegisterExeAsSafeToDragDrop(LPCTSTR ptszAppGuid)
{
	CString strKey = _T ("Software\\Microsoft\\Internet Explorer\\Low Rights\\DragDrop\\");
	strKey += ptszAppGuid;
	CRegKey key;
	bool bOK = ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strKey, KEY_ALL_ACCESS);
	if (!bOK)
		bOK = ERROR_SUCCESS == key.Create (HKEY_LOCAL_MACHINE, strKey, NULL, 0, KEY_ALL_ACCESS, NULL, NULL);
	if (!bOK)
		bOK = ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, strKey, KEY_ALL_ACCESS);
	if (!bOK)
		bOK = ERROR_SUCCESS == key.Create (HKEY_CURRENT_USER, strKey, NULL, 0, KEY_ALL_ACCESS, NULL, NULL);
	if (!bOK)
		return false;
	
	
	TCHAR tsz [MY_MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MY_MAX_PATH);
	
	LPTSTR ptsz = strrchr (tsz, '\\');
	if (!ptsz)
		return false;
	
	CString strName = ptsz+1;
	*ptsz = 0;
	
	bOK = ERROR_SUCCESS == key.SetValue (strName, _T ("AppName"));
	bOK = ERROR_SUCCESS == key.SetValue (tsz, _T ("AppPath")) && bOK;
	bOK = ERROR_SUCCESS == key.SetValue (3, _T ("Policy")) && bOK;
	
	return bOK;
}
