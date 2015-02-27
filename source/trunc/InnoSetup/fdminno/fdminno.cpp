/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <stdio.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

DWORD _stdcall GetSystemDefaultLanguageId ()
{
	char sz [10] = "";
	GetLocaleInfo (LOCALE_USER_DEFAULT, LOCALE_IDEFAULTLANGUAGE, sz, sizeof (sz));
	DWORD dw = 0;
	sscanf (sz, "%x", &dw);
	return dw;
}

