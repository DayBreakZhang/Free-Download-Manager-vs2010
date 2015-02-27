/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "../fdm.h"
#include <stdio.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}

vmsFdmApi *_pFdmApi = NULL;

DWORD WINAPI _threadJob (LPVOID);

BOOL FdmApiPluginInitialize (vmsFdmApi* pFdmApi, DWORD* pdwSdkVersionPluginUse)
{
	*pdwSdkVersionPluginUse = (FDMSDK_MAJOR_VERSION << 32) | FDMSDK_MINOR_VERSION;
	if (pFdmApi)
	{
		_pFdmApi = pFdmApi;
		DWORD dw;
		CreateThread (NULL, 0, _threadJob, NULL, 0, &dw);
	}

	return TRUE;
}

void FdmApiPluginShutdown ()
{
	
}

void FdmApiPluginGetDescription (LPSTR pszPluginShortName, LPSTR pszPluginLongName, LPSTR pszPluginVersion, LPSTR pszPluginDescription)
{
	strcpy (pszPluginShortName, "FDMExPlug");
	strcpy (pszPluginLongName, "FDM example plugin");
	strcpy (pszPluginVersion, "1.0");
	strcpy (pszPluginDescription, "This plugin helps others understand how to write a plugin for FDM.");
}

DWORD WINAPI _threadJob (LPVOID)
{
	UINT n = _pFdmApi->getFdmBuildNumber ();
	char sz [100];
	sprintf (sz, "FDM's build number is %d", n);
	MessageBox (_pFdmApi->getFdmWindowHandle (), sz, "FdmPluginExample", 0);

	vmsFdmApiCreateDownloadParameters p;
	p.pszUrl = "http://freedownloadmanager.org/";
	UINT nDownloadId = _pFdmApi->getDownloadsMgr ()->CreateDownload (&p);

	vmsFdmApiDownload *dld = _pFdmApi->getDownloadsMgr ()->getDownloadById (nDownloadId);

	while (dld->getState () != FADS_FINISHED)
		Sleep (100);

	MessageBox (_pFdmApi->getFdmWindowHandle (), "Download was completed, click OK to delete", "plugin", 0);

	dld->DeleteFileOnDisk ();
	dld->DeleteDownload (FALSE);
	
	return 0;
}

