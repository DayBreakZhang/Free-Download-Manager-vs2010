/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSOPNETINTEGRATIONMGR_H__FAFB09B6_9FCC_4D7F_BE4C_95E6CD22AAA0__INCLUDED_)
#define AFX_FSOPNETINTEGRATIONMGR_H__FAFB09B6_9FCC_4D7F_BE4C_95E6CD22AAA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsKnownBrowsers.h"
#include "vmsBrowserPluginFileDeleter.h"

class vmsNpPluginInstaller
{
public:
	virtual void Initialize () {}
	
	
	
	bool IsPluginInstalled (bool bQueryPluginDirIfUnknown = false);
	bool InstallPlugin ();
	bool DeinstallPlugin ();
	const tstring& getPluginsDirPath () const {return m_tstrPluginsPath;}
	tstring getPluginPath () const {return m_tstrPluginsPath.empty () ? _T ("") : m_tstrPluginsPath + _T ("npfdm.dll");}

public:
	vmsNpPluginInstaller () {}
	virtual ~vmsNpPluginInstaller() {}
protected:
	virtual void onInstallStateChanged () {}
	virtual LPCTSTR getCantFindPluginsDirMsg () {return _T ("Can't find plugins directory. Would you like to specify it?");}
	tstring m_tstrPluginsPath; 
	void QueryPluginsPathFromRegistry (CRegKey key);
	void QueryPluginsPathFromShellOpenCommandKey (CRegKey key);
};

class vmsNpPluginInstallerForOpera : public vmsNpPluginInstaller
{
public:
	void Initialize ();
protected:
	virtual void onInstallStateChanged ();
	virtual LPCTSTR getCantFindPluginsDirMsg ();
};

class vmsNpPluginInstallerForNetscape : public vmsNpPluginInstaller
{
public:
	void Initialize ();
protected:
	virtual void onInstallStateChanged ();
	virtual LPCTSTR getCantFindPluginsDirMsg ();
};

class vmsNpPluginInstallerForFirefox : public vmsNpPluginInstaller
{
public:
	void Initialize ();
protected:
	virtual void onInstallStateChanged ();
	virtual LPCTSTR getCantFindPluginsDirMsg ();
};

class vmsNpPluginInstallerForMozillaSuite : public vmsNpPluginInstaller
{
public:
	void Initialize ();
protected:
	virtual void onInstallStateChanged ();
};

class vmsNpPluginInstallerForSafari : public vmsNpPluginInstaller
{
public:
	void Initialize ();
protected:
	virtual void onInstallStateChanged ();
	virtual LPCTSTR getCantFindPluginsDirMsg ();
};

class vmsNpPluginInstallerForChrome : public vmsNpPluginInstaller
{
public:
	void Initialize ();
protected:
	virtual void onInstallStateChanged ();
	virtual LPCTSTR getCantFindPluginsDirMsg ();
};

class fsOpNetIntegrationMgr  
{
public:
	vmsNpPluginInstaller& getPluginInstaller (vmsKnownBrowsers::Browser enBrowser)
	{
		std::vector <PluginInstaller>::iterator it = findInstaller (enBrowser);
		if (it == m_vInstallers.end ())
			throw std::invalid_argument ("");
		return *(it->spInstaller);
	}
public:
	
	void Initialize()
	{
		for (std::vector <PluginInstaller>::iterator it = m_vInstallers.begin (); it != m_vInstallers.end (); it++)
			it->spInstaller->Initialize ();
	}

public:
	
	
	
	
	void DeinstallPlugins (const std::vector <vmsKnownBrowsers::Browser> &vBrowsers, std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> >& vapNotDeletedPlugins);
	void DeinstallAllPlugins (std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> >& vapNotDeletedPlugins);
	
	fsOpNetIntegrationMgr() 
	{
		m_vInstallers.push_back (PluginInstaller (vmsKnownBrowsers::Opera, std::auto_ptr <vmsNpPluginInstaller> (new vmsNpPluginInstallerForOpera)));
		m_vInstallers.push_back (PluginInstaller (vmsKnownBrowsers::Netscape, std::auto_ptr <vmsNpPluginInstaller> (new vmsNpPluginInstallerForNetscape)));
		m_vInstallers.push_back (PluginInstaller (vmsKnownBrowsers::MozillaSuite, std::auto_ptr <vmsNpPluginInstaller> (new vmsNpPluginInstallerForMozillaSuite)));
		m_vInstallers.push_back (PluginInstaller (vmsKnownBrowsers::Chrome, std::auto_ptr <vmsNpPluginInstaller> (new vmsNpPluginInstallerForChrome)));
		m_vInstallers.push_back (PluginInstaller (vmsKnownBrowsers::Safari, std::auto_ptr <vmsNpPluginInstaller> (new vmsNpPluginInstallerForSafari)));
	}

	virtual ~fsOpNetIntegrationMgr() {}

protected:
	struct PluginInstaller
	{
		vmsKnownBrowsers::Browser enBrowser;
		std::auto_ptr <vmsNpPluginInstaller> spInstaller;
		PluginInstaller (vmsKnownBrowsers::Browser a_enBrowser, std::auto_ptr <vmsNpPluginInstaller> a_spInstaller) : 
			enBrowser (a_enBrowser), spInstaller (a_spInstaller) {}
	};
	std::vector <PluginInstaller> m_vInstallers;
	std::vector <PluginInstaller>::iterator findInstaller (vmsKnownBrowsers::Browser enBrowser)
	{
		for (std::vector <PluginInstaller>::iterator it = m_vInstallers.begin (); it != m_vInstallers.end (); it++)
		{
			if (it->enBrowser == enBrowser)
				return it;
		}
		return m_vInstallers.end ();
	}
};

#endif 
