/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsBinaryFileVersionInfo.h"
#include <shlobj.h>

class vmsInternetExplorerVersion : public vmsBinaryFileVersionInfo
{
public:
	vmsInternetExplorerVersion () 
	{
		
		

		Retrieve ();
	}

protected:
	bool Retrieve ()
	{
		TCHAR  tszPath [MAX_PATH] = _T ("");
		if (!SHGetSpecialFolderPath (NULL, tszPath, CSIDL_PROGRAM_FILES, FALSE))
			return false;
		if (!*tszPath)
			return false;

		_tcscat (tszPath, _T ("\\Internet Explorer\\iexplore.exe"));

		return vmsBinaryFileVersionInfo::Retrieve (tszPath);
	}
};

