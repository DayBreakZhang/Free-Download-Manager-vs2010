/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsFirefoxExtensionUpdateMgr
{
public:
	vmsFirefoxExtensionUpdateMgr(bool currentBuildFirstRun);
	virtual ~vmsFirefoxExtensionUpdateMgr(void);
	LPCTSTR getExtensionPath(void);
	bool isExtensionPathChanged () const {return m_bExtensionPathChanged;}

protected:
	tstring m_tstrExtensionPath;
	vmsAppVersion m_extensionVersion;
	void LoadState(bool currentBuildFirstRun);
	void LocateFirefoxExtension(void);
	static void GetExtensionsInstallationPath(tstring& tstrResult);
	tstring m_tstrExtensionNewVerURL;
	vmsAppVersion m_extensionNewVer;
	bool m_bExtensionPathChanged;
public:
	bool CheckForUpdates(void);
	bool isNewVersionAvailable () const {return !m_tstrExtensionNewVerURL.empty ();}
	bool PerformUpdate(void);
};

