/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsElevatedFdm
{
public:
	vmsElevatedFdm(void);
	~vmsElevatedFdm(void);
	static bool Run(LPCTSTR ptszAdditionalArgs, bool bWaitForComplete = false);
	static vmsElevatedFdm& o(void);
protected:
	
	bool m_bInstallIeIntegrationPerformed;
public:
	bool InstallIeIntegration(bool bShowPreUacDlg);
	
	
	
	
	static bool CopyFiles(const std::vector <std::pair <tstring, tstring> >& vFiles);
	static bool InstallIntegration (const std::vector <vmsKnownBrowsers::Browser> &vBrowsers, bool bInstall, bool bShowPreUacDlg);
};

