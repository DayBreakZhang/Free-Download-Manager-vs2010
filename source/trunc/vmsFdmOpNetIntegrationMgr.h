/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "fsopnetintegrationmgr.h"
class vmsFdmOpNetIntegrationMgr :
	public fsOpNetIntegrationMgr
{
public:
	vmsFdmOpNetIntegrationMgr(void);
	~vmsFdmOpNetIntegrationMgr(void);
	bool DeinstallPluginsEx(const std::vector <vmsKnownBrowsers::Browser>& vBrowsers);
	bool InstallPluginsEx(const std::vector <vmsKnownBrowsers::Browser>& vBrowsers);
	void InstallDeinstallPluginsExWithErrMsg(HWND hwnd, const std::vector <vmsKnownBrowsers::Browser>& vBrowsersToInstall, const std::vector <vmsKnownBrowsers::Browser>& vBrowsersToDeinstall, bool &bBrowsersRestartReq);
};

