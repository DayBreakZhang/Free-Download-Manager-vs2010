/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFirefoxUtil.h"
#include "vmsFileUtil.h"
#include "vmsLogger.h"

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

bool vmsFirefoxUtil::GetProfilesPathes(FU_STRINGLIST &v, int &nDefaultProfile)
{
	try 
	{
		char szPath [MY_MAX_PATH];
		GetDataPath (szPath);

		

		char szProfilesIni [MY_MAX_PATH];
		lstrcpy (szProfilesIni, szPath);
		lstrcat (szProfilesIni, "profiles.ini");

		if (GetFileAttributes (szProfilesIni) != DWORD (-1))
		{
			nDefaultProfile = -1;

			for (int i = 0;; i++)
			{
				char sz [100], szPP [MY_MAX_PATH] = ""; 
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
					
					char sz [MY_MAX_PATH];
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
			

			

			char szProfiles [MY_MAX_PATH];
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

				char sz [MY_MAX_PATH];
				lstrcpy (sz, szPath);
				lstrcat (sz, wfd.cFileName);

				DWORD dw = GetFileAttributes (sz);
				if (dw != DWORD (-1) && (dw & FILE_ATTRIBUTE_DIRECTORY))
				{
					char sz2 [MY_MAX_PATH];
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
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog(" " + tstring(ex.what()));
		return false;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog(" unknown exception");
		return false;
	}
}

bool vmsFirefoxUtil::GetDefaultProfilePath(LPSTR pszPath)
{
	FU_STRINGLIST v; 
	int nDefaultProfile;

	if (false == GetProfilesPathes (v, nDefaultProfile) || v.size () == 0)
		return false;

	if (nDefaultProfile == -1 || nDefaultProfile < 0 || nDefaultProfile >= v.size ())
		nDefaultProfile = 0;

	lstrcpy (pszPath, v [nDefaultProfile]);

	return  true;
}
