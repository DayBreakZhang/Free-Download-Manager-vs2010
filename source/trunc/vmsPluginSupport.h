/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSPLUGINSUPPORT_H__2F7F7B11_C77D_4C90_B8F2_251FDCEAD92B__INCLUDED_)
#define AFX_VMSPLUGINSUPPORT_H__2F7F7B11_C77D_4C90_B8F2_251FDCEAD92B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

enum vmsPluginType
{
	FDMPT_WINDOWED,		
	FDMPT_WINDOWLESS,
};

struct vmsPluginInfo
{
	fsString strShortName;
	fsString strLongName;
	fsString strVersion;
	fsString strDescription;
	fsString strDllFileName;
	vmsPluginType enType;
	bool bRunning;
	DWORD dwSdkVersion;
};

class vmsPluginSupport  
{
public:
	static vmsPluginSupport& o();
	void Initialize();
	void Shutdown();

	vmsPluginSupport();
	virtual ~vmsPluginSupport();

protected:
	struct vmsLoadedPlugin : public vmsPluginInfo
	{
		HMODULE hDll;
		FARPROC pfnFdmApiPluginInitialize;
		FARPROC pfnFdmApiPluginShutdown;
	};
	static BOOL LoadPlugin (vmsLoadedPlugin& plug);
	std::vector <vmsLoadedPlugin> m_vPlugins;
};

#endif 
