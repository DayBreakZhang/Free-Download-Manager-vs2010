/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <windows.h>
#include "vmsFirefoxExtensionInstaller.h"
#include "vmsFirefoxUtil.h"
#include "vmsFile.h"

vmsFirefoxExtensionInstaller::vmsFirefoxExtensionInstaller()
{

}

vmsFirefoxExtensionInstaller::~vmsFirefoxExtensionInstaller()
{

}

bool vmsFirefoxExtensionInstaller::IsInstalled(LPCSTR pszCID, bool bInDefaultProfileOnly)
{
	FEI_STRINGLIST v;
	int nDefaultProfile;
	get_ProfilesPathes (v, nDefaultProfile);

	if (v.size () == 0)
		return false;

	for (int i = 0; i < v.size (); i++)
	{
		if (bInDefaultProfileOnly && i != nDefaultProfile)
			continue;

		char sz [MAX_PATH];
		lstrcpy (sz, v [i]);
		lstrcat (sz, "\\extensions\\");
		lstrcat (sz, pszCID);
		if (GetFileAttributes (sz) != DWORD (-1))
			return true;
	}

	return false;
}

bool vmsFirefoxExtensionInstaller::get_ProfilesPathes(FEI_STRINGLIST &v, int& nDefaultProfile)
{
try {
	char szPath [MAX_PATH];
	vmsFirefoxUtil::GetDataPath (szPath);

	char szProfilesIni [MAX_PATH];
	lstrcpy (szProfilesIni, szPath);
	lstrcat (szProfilesIni, "profiles.ini");

	if (GetFileAttributes (szProfilesIni) != DWORD (-1))
	{
		nDefaultProfile = -1;

		for (int i = 0;; i++)
		{
			char sz [100], szPP [MAX_PATH] = "";
			sprintf (sz, "Profile%d", i);
			GetPrivateProfileString (sz, "Path", "", szPP, sizeof (szPP), szProfilesIni);
			if (*szPP == 0)
				break;
			LPSTR psz = szPP;
			while (*psz) {
				if (*psz == '/')
					*psz = '\\';
				psz++;
			}
			if (szPP [1] == ':')
			{
				v.add (szPP);
			}
			else
			{
				
				char sz [MAX_PATH];
				lstrcpy (sz, szPath);
				lstrcat (sz, szPP);
				v.add (sz);
			}

			if (nDefaultProfile == -1 &&
					GetPrivateProfileInt (sz, "Default", 0, szProfilesIni))
				nDefaultProfile = i;
		}
	}

	if (v.size () == 0)
	{
		char szProfiles [MAX_PATH];
		vmsFirefoxUtil::GetProfilesPath (szProfiles);
		lstrcat (szProfiles, "*");

		WIN32_FIND_DATA wfd;
		HANDLE hFind = FindFirstFile (szProfiles, &wfd);
		if (hFind == INVALID_HANDLE_VALUE)
			return false;

		do
		{
			if (0 == lstrcmp (wfd.cFileName, ".") || 0 == lstrcmp (wfd.cFileName, ".."))
				continue;

			char sz [MAX_PATH];
			lstrcpy (sz, szPath);
			lstrcat (sz, wfd.cFileName);

			DWORD dw = GetFileAttributes (sz);
			if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY))
			{
				char sz2 [MAX_PATH];
				lstrcpy (sz2, sz);
				lstrcat (sz2, "\\extensions\\");
				DWORD dw = GetFileAttributes (sz2);
				if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY))
					v.add (sz);
			}
		}
		while (FindNextFile (hFind, &wfd));

		FindClose (hFind);
	}

	return true;

}catch (...) {return false;}
}
