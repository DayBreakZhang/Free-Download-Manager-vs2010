/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsVistaFx.h"

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

BOOL _IsProcessElevated ()
{
	return vmsVistaFx::IsElevated ();
}

BOOL _RunNonElevatedProcess (LPCSTR pszPath, LPCSTR pszParameters, LPCSTR pszDirectory)
{
	return vmsVistaFx::RunNonElevated (pszPath, pszParameters, pszDirectory);
}