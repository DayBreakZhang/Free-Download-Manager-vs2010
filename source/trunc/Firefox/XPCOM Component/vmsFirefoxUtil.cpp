/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <windows.h>
#include "vmsFirefoxUtil.h"
#include "vmsFileUtil.h"

vmsFirefoxUtil::vmsFirefoxUtil()
{

}

vmsFirefoxUtil::~vmsFirefoxUtil()
{

}

void vmsFirefoxUtil::GetProfilesPath(LPSTR pszPath)
{
	vmsFirefoxUtil::GetDataPath (pszPath);
	lstrcat (pszPath, "Profiles\\");
}

void vmsFirefoxUtil::GetDataPath(LPSTR pszPath)
{
	vmsFileUtil::GetAppDataPath ("Mozilla", pszPath);
	vmsFileUtil::MakePathOK (pszPath, true);
	lstrcat (pszPath, "Firefox\\");
}
