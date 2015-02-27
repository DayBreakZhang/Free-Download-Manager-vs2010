/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsOpNetIntegrationMgr.h"
#include "FolderBrowser.h"
#include "vmsCommandLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

bool vmsNpPluginInstaller::IsPluginInstalled (bool bQueryPluginDirIfUnknown)
{
	if (m_tstrPluginsPath.empty ())
	{
		Initialize ();
		if (!m_tstrPluginsPath.empty ())
			return IsPluginInstalled (bQueryPluginDirIfUnknown);

		if (!bQueryPluginDirIfUnknown)
			return false;

		if (MessageBox (NULL, getCantFindPluginsDirMsg (), vmsFdmAppMgr::getAppName (), MB_ICONEXCLAMATION|MB_YESNO) == IDNO)
			return FALSE;

		CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), NULL, NULL, NULL);
		if (fb == NULL)
			return FALSE;

		m_tstrPluginsPath = fb->GetPath ();

		if (m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '\\' || m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '/')
			m_tstrPluginsPath += '\\';

		
		
		if (_tcsnicmp (m_tstrPluginsPath.c_str () + m_tstrPluginsPath.length () - 8, "Plugins\\", 8))
		{
			if (GetFileAttributes ((m_tstrPluginsPath + _T ("program\\plugins")).c_str ()) != DWORD (-1))
				m_tstrPluginsPath += _T ("program\\plugins\\");	
			else
				m_tstrPluginsPath += _T ("Plugins\\");
		}
	}

	tstring tstr = m_tstrPluginsPath;
	tstr += "npfdm.dll";
	return GetFileAttributes (tstr.c_str ()) != DWORD (-1);
}

bool vmsNpPluginInstaller::InstallPlugin ()
{
	if (m_tstrPluginsPath.empty ())
		return false;

	tstring tstr = m_tstrPluginsPath;
	tstr += _T ("npfdm.dll");
	if (!fsBuildPathToFile (tstr.c_str ()))
		return false;

	onInstallStateChanged ();

	return CopyFile (_T ("npfdm.dll"), tstr.c_str (), FALSE) != FALSE;
}

bool vmsNpPluginInstaller::DeinstallPlugin ()
{
	if (m_tstrPluginsPath.empty ())
		return true;

	tstring tstr = getPluginPath ();

	m_tstrPluginsPath = _T ("");

	onInstallStateChanged ();

	return DeleteFile (tstr.c_str ()) != FALSE || GetLastError () == ERROR_FILE_NOT_FOUND;
}

void vmsNpPluginInstallerForOpera::onInstallStateChanged ()
{
	
	_App.Monitor_OperaPDInstalledTo (m_tstrPluginsPath.c_str ());
}

void vmsNpPluginInstallerForNetscape::onInstallStateChanged ()
{
	
	_App.Monitor_NetscapePDInstalledTo (m_tstrPluginsPath.c_str ());
}

void vmsNpPluginInstallerForFirefox::onInstallStateChanged ()
{
	
	_App.Monitor_FirefoxPDInstalledTo (m_tstrPluginsPath.c_str ());
}

void vmsNpPluginInstallerForMozillaSuite::onInstallStateChanged ()
{
	
	_App.Monitor_MozillaSuitePDInstalledTo (m_tstrPluginsPath.c_str ());
}

void vmsNpPluginInstallerForSafari::onInstallStateChanged ()
{
	
	_App.Monitor_SafariPDInstalledTo (m_tstrPluginsPath.c_str ());
}

void vmsNpPluginInstallerForChrome::onInstallStateChanged ()
{
	
	_App.Monitor_ChromePDInstalledTo (m_tstrPluginsPath.c_str ());
}

LPCTSTR vmsNpPluginInstallerForOpera::getCantFindPluginsDirMsg () 
{
	return LS (L_CANTFINDOPERADIR);
}

LPCTSTR vmsNpPluginInstallerForNetscape::getCantFindPluginsDirMsg () 
{
	return LS (L_CANTFINDNETSCAPEDIR);
}

LPCTSTR vmsNpPluginInstallerForFirefox::getCantFindPluginsDirMsg () 
{
	return LS (L_CANTFINDFIREFOXDIR);
}

LPCTSTR vmsNpPluginInstallerForSafari::getCantFindPluginsDirMsg () 
{
	return LS (L_CANTFINDSAFARIDIR);
}

LPCTSTR vmsNpPluginInstallerForChrome::getCantFindPluginsDirMsg () 
{
	return LS (L_CANTFINDCHROMEDIR);
}

void vmsNpPluginInstallerForOpera::Initialize ()
{
	CRegKey key;

	if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, "Software\\Opera Software", KEY_READ))
	{
		char szPath [MY_MAX_PATH] = "";
		DWORD dw = sizeof (szPath);
		if (ERROR_SUCCESS == key.QueryValue (szPath, "Plugin Path", &dw))
		{
			if (*szPath)
			{
				m_tstrPluginsPath = szPath;
				if (m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '\\' || m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '/')
					m_tstrPluginsPath += '\\';
			}
		}
	}

	if (m_tstrPluginsPath.empty () && ERROR_SUCCESS == key.Open (HKEY_CLASSES_ROOT, 
		"Applications\\Opera.exe\\shell\\open\\command", KEY_READ))
	{
		QueryPluginsPathFromShellOpenCommandKey (key);
	}

	if (m_tstrPluginsPath.empty () && ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, _T ("Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Opera.exe"), KEY_READ))
	{
		
		QueryPluginsPathFromRegistry (key);
	}

	if (m_tstrPluginsPath.empty ())
	{
		
		
		
		m_tstrPluginsPath = _App.Monitor_OperaPDInstalledTo ();
	}
}

void vmsNpPluginInstaller::QueryPluginsPathFromRegistry (CRegKey key)
{
	char szPath [MY_MAX_PATH] = "";
	DWORD dw = sizeof (szPath);
	key.QueryValue (szPath, "Path", &dw);
	if (*szPath)
	{
		m_tstrPluginsPath = szPath;
		if (m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '\\' || m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '/')
			m_tstrPluginsPath += '\\';
		if (GetFileAttributes ((m_tstrPluginsPath + "program\\plugins").c_str ()) != DWORD (-1))
			m_tstrPluginsPath += "program\\plugins\\";	
		else
			m_tstrPluginsPath += "Plugins\\";
	}
	key.Close ();
}

void vmsNpPluginInstaller::QueryPluginsPathFromShellOpenCommandKey (CRegKey key)
{
	char sz [MY_MAX_PATH] = "";
	DWORD dw = sizeof (sz);
	key.QueryValue (sz, NULL, &dw);
	vmsCommandLine cl;
	cl.fromString (sz, true);
	if (cl.getExe () != NULL && *cl.getExe () != 0)
	{
		*sz = 0;
		fsGetPath (cl.getExe (), sz);
		if (*sz)
		{
			m_tstrPluginsPath = sz;
			if (m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '\\' || m_tstrPluginsPath [m_tstrPluginsPath.length () - 1] != '/')
				m_tstrPluginsPath += '\\';
			if (GetFileAttributes ((m_tstrPluginsPath + "program\\plugins").c_str ()) != DWORD (-1))
				m_tstrPluginsPath += "program\\plugins\\";
			else
				m_tstrPluginsPath += "Plugins\\";
		}
	}
}

void vmsNpPluginInstallerForNetscape::Initialize()
{
	CRegKey key;

	CString strNetKey1 = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Netscp.exe";
	CString strNetKey2 = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Netscp6.exe";
	CString strNetKey3 = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Netscape.exe";
	CString strNetKey4 = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\navigator.exe";

	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strNetKey1, KEY_READ) ||
		ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strNetKey2, KEY_READ) || 
		ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strNetKey3, KEY_READ) ||
		ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strNetKey4, KEY_READ))
	{
		QueryPluginsPathFromRegistry (key);
	}
	else
	{
		m_tstrPluginsPath = _App.Monitor_NetscapePDInstalledTo ();
	}
}

void vmsNpPluginInstallerForFirefox::Initialize()
{
	CRegKey key;

	CString strFfKey = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\Firefox.exe";

	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strFfKey, KEY_READ))
	{
		QueryPluginsPathFromRegistry (key);
	}
	else
	{
		m_tstrPluginsPath = _App.Monitor_FirefoxPDInstalledTo ();
	}
}

void vmsNpPluginInstallerForMozillaSuite::Initialize()
{
	CRegKey key;

	CString strMozSKey1 = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\SeaMonkey.exe";
	CString strMozSKey2 = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\mozilla.exe";

	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strMozSKey1, KEY_READ) ||
		ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, strMozSKey2, KEY_READ))
	{
		
		QueryPluginsPathFromRegistry (key);
	}
	else
	{
		m_tstrPluginsPath = _App.Monitor_MozillaSuitePDInstalledTo ();
	}
}

void vmsNpPluginInstallerForSafari::Initialize()
{
	CRegKey key;

	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, "Software\\Clients\\StartMenuInternet\\Safari.exe\\shell\\open\\command", KEY_READ))
	{
		QueryPluginsPathFromShellOpenCommandKey (key);
	}
	else
	{
		m_tstrPluginsPath = _App.Monitor_SafariPDInstalledTo ();
	}
}

void vmsNpPluginInstallerForChrome::Initialize()
{
	CRegKey key;

	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, "Software\\Clients\\StartMenuInternet\\chrome.exe\\shell\\open\\command", KEY_READ) || 
		ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, "Software\\Clients\\StartMenuInternet\\Google Chrome\\shell\\open\\command", KEY_READ))
	{
		QueryPluginsPathFromShellOpenCommandKey (key);
	}
	else
	{
		LPITEMIDLIST pidl = NULL;
		if (SUCCEEDED (SHGetSpecialFolderLocation (NULL, CSIDL_LOCAL_APPDATA, &pidl)))
		{
			TCHAR tszPath [MY_MAX_PATH] = _T ("");
			SHGetPathFromIDList (pidl, tszPath);
			if (tszPath [_tcslen (tszPath)-1] != '\\')
				_tcscat (tszPath, _T ("\\"));
			_tcscat (tszPath, _T ("Google\\Chrome\\Application"));
			if (GetFileAttributes (tszPath) != DWORD (-1))
			{
				_tcscat (tszPath, _T ("\\Plugins\\"));
				m_tstrPluginsPath = tszPath;
			}

			IMallocPtr spMalloc;
			SHGetMalloc (&spMalloc);
			spMalloc->Free (pidl);
		}

		if (m_tstrPluginsPath.empty ())
			m_tstrPluginsPath = _App.Monitor_ChromePDInstalledTo ();
	}
}

void fsOpNetIntegrationMgr::DeinstallPlugins (const std::vector <vmsKnownBrowsers::Browser> &vBrowsers, std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> >& vapNotDeletedPlugins)
{
	for (size_t i = 0; i < vBrowsers.size (); i++)
	{
		vmsNpPluginInstaller& pi = getPluginInstaller (vBrowsers [i]);
		tstring tstrPlugin = pi.getPluginPath ();
		if (pi.DeinstallPlugin ())
			continue;
		DWORD dwError = GetLastError ();
		vapNotDeletedPlugins.push_back (std::auto_ptr <vmsBrowserPluginFileDeleter> (new vmsBrowserPluginFileDeleter (vBrowsers [i], tstrPlugin.c_str (), dwError)));
	}
}

void fsOpNetIntegrationMgr::DeinstallAllPlugins (std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> >& vapNotDeletedPlugins)
{
	std::vector <vmsKnownBrowsers::Browser> vBrowsers;
	vBrowsers.reserve (m_vInstallers.size ());
	for (size_t i = 0; i < m_vInstallers.size (); i++)
		vBrowsers.push_back (m_vInstallers [i].enBrowser);
	DeinstallPlugins (vBrowsers, vapNotDeletedPlugins);
}