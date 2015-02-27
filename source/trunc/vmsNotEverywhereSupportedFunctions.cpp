/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsNotEverywhereSupportedFunctions.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsNotEverywhereSupportedFunctions::vmsNotEverywhereSupportedFunctions()
{
	
}

vmsNotEverywhereSupportedFunctions::~vmsNotEverywhereSupportedFunctions()
{

}

LONG vmsNotEverywhereSupportedFunctions::RegOverridePredefKey(HKEY hkey1, HKEY hkey2)
{
	HMODULE h = LoadLibrary ("advapi32.dll");
	if (!h)
		return ERROR_BAD_ENVIRONMENT;
	typedef LONG (WINAPI *FNROPK)(HKEY,HKEY);
	FNROPK pfn = (FNROPK)GetProcAddress (h, "RegOverridePredefKey");
	if (!pfn)
	{
		FreeLibrary (h);
		return ERROR_BAD_ENVIRONMENT;
	}
	LONG lRes = pfn (hkey1, hkey2);
	FreeLibrary (h);
	return lRes;
}
