/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFdmOpNetIntegrationMgr.h"
#include "vmsFdmFilesDeleter.h"
#include "VistaFx/VistaFx.h"
#include "vmsElevatedFdm.h"
#include "DlgElevateRequired.h"

vmsFdmOpNetIntegrationMgr::vmsFdmOpNetIntegrationMgr(void)
{
}

vmsFdmOpNetIntegrationMgr::~vmsFdmOpNetIntegrationMgr(void)
{
}

bool vmsFdmOpNetIntegrationMgr::DeinstallPluginsEx(const std::vector <vmsKnownBrowsers::Browser>& vBrowsers)
{
	std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> > vapNotDeletedPlugins;
	DeinstallPlugins (vBrowsers, vapNotDeletedPlugins);
	if (vapNotDeletedPlugins.empty ())
		return true;
	return vmsFdmFilesDeleter::DeleteBrowserPluginFiles (vapNotDeletedPlugins);
}

bool vmsFdmOpNetIntegrationMgr::InstallPluginsEx(const std::vector <vmsKnownBrowsers::Browser>& vBrowsers)
{
	bool bOK = true;

	std::vector <vmsKnownBrowsers::Browser> vToBeInstalledElevated;

	for (size_t i = 0; i < vBrowsers.size (); i++)
	{
		vmsNpPluginInstaller& pluginInstaller = getPluginInstaller (vBrowsers [i]);
		if (pluginInstaller.InstallPlugin ())
			continue;
		if (GetLastError () == ERROR_ACCESS_DENIED && VistaFx::IsVistaOrHigher () && !IsUserAnAdmin ())
			vToBeInstalledElevated.push_back (vBrowsers [i]);
		else
			bOK = false;
	}

	if (!vToBeInstalledElevated.empty ())
	{
		if (!vmsElevatedFdm::o ().InstallIntegration (vToBeInstalledElevated, true, true))
			bOK = false;
	}

	return bOK;
}

void vmsFdmOpNetIntegrationMgr::InstallDeinstallPluginsExWithErrMsg(HWND hwnd, const std::vector <vmsKnownBrowsers::Browser>& vBrowsersToInstall, const std::vector <vmsKnownBrowsers::Browser>& vBrowsersToDeinstall, bool &bBrowsersRestartReq)
{
	bBrowsersRestartReq = false;

	bool bOkInstall = true, bOkDeinstall = true;

	if (!vBrowsersToInstall.empty ())
		bOkInstall = InstallPluginsEx (vBrowsersToInstall);

	if (!vBrowsersToDeinstall.empty ())
		bOkDeinstall = DeinstallPluginsEx (vBrowsersToDeinstall);

	if (!bOkInstall || !bOkDeinstall)
	{
		CString strMsg = LS (L_FAILED_ENDIS_MONITORING);
		CString strBrList;
		std::vector <std::pair <vmsKnownBrowsers::Browser, bool> > vCheck;
		if (!bOkInstall)
		{
			for (size_t i = 0; i < vBrowsersToInstall.size (); i++)
				vCheck.push_back (std::make_pair (vBrowsersToInstall [i], true));
		}
		if (!bOkDeinstall)
		{
			for (size_t i = 0; i < vBrowsersToDeinstall.size (); i++)
				vCheck.push_back (std::make_pair (vBrowsersToDeinstall [i], false));
		}
		for (size_t i = 0; i < vCheck.size (); i++)
		{
			if (getPluginInstaller (vCheck [i].first).IsPluginInstalled () != vCheck [i].second)
			{
				if (!strBrList.IsEmpty ())
					strBrList += _T (", ");
				strBrList += vmsKnownBrowsers::getBrowserUiName (vCheck [i].first);
			}
			else
			{
				bBrowsersRestartReq = true;
			}
		}
		if (!strBrList.IsEmpty ())
		{
			strMsg += _T ("\n(");
			strMsg += strBrList;
			strMsg += _T (")");
		}
		MessageBox (hwnd, strMsg, NULL, MB_ICONERROR);
	}
	else
	{
		bBrowsersRestartReq = false;
	}
}