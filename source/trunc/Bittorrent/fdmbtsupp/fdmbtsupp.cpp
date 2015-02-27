/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"

void InitializeFdmBtSuppDll ()
{
	boost::filesystem::path::default_name_check (boost::filesystem::no_check);
}

int WINAPI vmsBt_getMinimumFdmBuildRequired ()
{
	
	return 1354;
}

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
		InitializeFdmBtSuppDll ();

    return TRUE;
}

