/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class vmsChromeExtensionInstaller
{
public:
	static bool IsInstalled();
	static bool Enabled(bool& isEnabled);
	static BOOL Install();
	static void Enable();
	static BOOL Uninstall();

private:
	vmsChromeExtensionInstaller();
	vmsChromeExtensionInstaller(const vmsChromeExtensionInstaller&);
	~vmsChromeExtensionInstaller();

	static BOOL RunChrome(const TCHAR* parameters);

};
