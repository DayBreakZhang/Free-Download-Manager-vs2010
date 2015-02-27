/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsPluginSupport.h"
#include "FdmApp.h"
#include "Plugins API/fdm.h"
#include "vmsFdmApiImpl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsPluginSupport::vmsPluginSupport()
{

}

vmsPluginSupport::~vmsPluginSupport()
{

}

vmsPluginSupport& vmsPluginSupport::o()
{
	static vmsPluginSupport o;
	return o;
}

void vmsPluginSupport::Initialize()
{
	CString str = ((CFdmApp*)AfxGetApp ())->m_strAppPath;
	if (str.Right (1) != "\\")
		str += '\\';
	str += "Plugins\\";

	CString strMask = str + "*.dll"; 

	WIN32_FIND_DATA wfd;
	HANDLE hFind = FindFirstFile (strMask, &wfd);
	if (hFind == INVALID_HANDLE_VALUE)
		return;

	do 
	{
		vmsLoadedPlugin plug;
		plug.bRunning = false;
		plug.enType = FDMPT_WINDOWLESS;
		plug.strDllFileName = str + wfd.cFileName;
		
		if (FALSE == LoadPlugin (plug))
			continue;

		m_vPlugins.push_back (plug);
	} 
	while (FindNextFile (hFind, &wfd));
}

BOOL vmsPluginSupport::LoadPlugin(vmsLoadedPlugin &plug)
{
	plug.hDll = LoadLibrary (plug.strDllFileName);
	if (plug.hDll == NULL)
		return FALSE;

	plug.pfnFdmApiPluginInitialize = GetProcAddress (plug.hDll, "FdmApiPluginInitialize");
	plug.pfnFdmApiPluginShutdown = GetProcAddress (plug.hDll, "FdmApiPluginShutdown");

	if (plug.pfnFdmApiPluginInitialize == NULL)
		return FALSE;

	typedef BOOL (*FdmApiPluginInitialize) (void*, DWORD*);
	BOOL bOk = ((FdmApiPluginInitialize)plug.pfnFdmApiPluginInitialize) (NULL, &plug.dwSdkVersion);
	if (bOk)
	{
		if (HIWORD (plug.dwSdkVersion) != FDMSDK_MAJOR_VERSION ||
				LOWORD (plug.dwSdkVersion) != FDMSDK_MINOR_VERSION)
			bOk = FALSE;
	}
	
	if (bOk)
		bOk = ((FdmApiPluginInitialize)plug.pfnFdmApiPluginInitialize) (&vmsFdmApiImpl::o (), &plug.dwSdkVersion);

	if (bOk == FALSE)
	{
		FreeLibrary (plug.hDll);
		return FALSE;
	}

	plug.bRunning = true;

	typedef void (*FdmApiPluginGetDescription)(LPSTR,LPSTR,LPSTR,LPSTR);
	
	FdmApiPluginGetDescription pfn = (FdmApiPluginGetDescription)
		GetProcAddress (plug.hDll, "FdmApiPluginGetDescription");
	
	if (pfn == NULL)
	{
		FreeLibrary (plug.hDll);
		return FALSE;
	}

	char sz1 [3000] = "", sz2 [3000] = "", sz3 [3000] = "", sz4 [3000] = "";
	pfn (sz1, sz2, sz3, sz4);

	plug.strShortName = sz1;
	plug.strLongName = sz2;
	plug.strVersion = sz3;
	plug.strDescription = sz4;

	return TRUE;
}

void vmsPluginSupport::Shutdown()
{
	for (size_t i = 0; i < m_vPlugins.size (); i++)
	{
		vmsLoadedPlugin &plug = m_vPlugins [i];

		typedef void (*FNPS)();

		if (plug.hDll && plug.bRunning && plug.pfnFdmApiPluginShutdown)
			((FNPS)plug.pfnFdmApiPluginShutdown)();

		if (plug.hDll)
			FreeLibrary (plug.hDll);
	}

	m_vPlugins.clear ();
}

