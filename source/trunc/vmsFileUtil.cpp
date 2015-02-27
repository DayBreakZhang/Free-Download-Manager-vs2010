/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFileUtil.h"
#include <shlobj.h>
#include "vmsLogger.h"

void vmsFileUtil::WriteString(vmsFile &file, LPCSTR psz)
{
	int l = lstrlen (psz);
	file.Write (&l, sizeof (l));
	file.Write (psz, l);
}

void vmsFileUtil::ReadString(vmsFile &file, fsString &str)
{
	int l = 0;
	file.Read (&l, sizeof (l));

	if (l > 100 * 1024 * 1024)	
		throw ERROR_BAD_FORMAT;

	char* psz = new char [l+1];
	try 
	{
		file.Read (psz, l);
		psz [l] = 0;
	} 
	catch (DWORD dw) 
	{
		vmsLogger::WriteLog("vmsFileUtil::ReadString exception");

		delete [] psz;
		throw dw;
	}

	str = psz;
	delete [] psz;
}

void vmsFileUtil::WriteHeader(vmsFile& file, LPCSTR pszDesc, WORD wVersion)
{
	WriteString (file, pszDesc);
	file.Write (&wVersion, sizeof (WORD));
}

void vmsFileUtil::ReadHeader(vmsFile& file, fsString& strDesc, WORD &wVersion)
{
	ReadString (file, strDesc);
	file.Read (&wVersion, sizeof (WORD));
}

void vmsFileUtil::MakePathOK(LPSTR szPath, bool bNeedBackslashAtEnd)
{
	LPSTR psz = szPath;
	while (*psz)
	{
		if (*psz == '/')
			*psz = '\\';
		psz++;
	}

	if (bNeedBackslashAtEnd && psz [-1] != '\\')
	{
		psz [0] = '\\';
		psz [1] = 0;
	}
}

void vmsFileUtil::GetAppDataPath(LPCSTR pszAppName, LPSTR szPath)
{
	LPITEMIDLIST pidl = NULL;
	SHGetSpecialFolderLocation (NULL, CSIDL_APPDATA, &pidl);
	SHGetPathFromIDList (pidl, szPath);

	vmsFileUtil::MakePathOK (szPath);
	lstrcat (szPath, pszAppName);
	lstrcat (szPath, "\\");
}

void vmsFileUtil::BuildPathToFile(LPCSTR pszPathName)
{
	BuildPath (GetPathFromPathName (pszPathName));
}

fsString vmsFileUtil::GetPathFromPathName(LPCSTR pszPathName)
{
	char szPath [MY_MAX_PATH];
	lstrcpy (szPath, pszPathName);
	MakePathOK (szPath, false);
	LPSTR psz = strrchr (szPath, '\\');
	if (psz == NULL)
		return "";
	*psz = 0;
	return szPath;
}

void vmsFileUtil::BuildPath(LPCSTR pszPath)
{
	char szPath [MY_MAX_PATH];
	lstrcpy (szPath, pszPath);
	MakePathOK (szPath, true);
	LPSTR psz = szPath;
	if (psz [1] == ':')
		psz += 3;

	while (*psz)
	{
		char szPathNow [MY_MAX_PATH];
		psz = strchr (psz, '\\') + 1;
		lstrcpyn (szPathNow, szPath, psz - szPath);
		if (FALSE == CreateDirectory (szPathNow, NULL) && 
				ERROR_ALREADY_EXISTS != GetLastError ())
			throw GetLastError ();
	}
}

BOOL vmsFileUtil::DirectoryExists(const char* dirName)
{
	DWORD attribs = ::GetFileAttributesA(dirName);
	if (attribs == INVALID_FILE_ATTRIBUTES)
		return false;

	return (attribs & FILE_ATTRIBUTE_DIRECTORY);
}