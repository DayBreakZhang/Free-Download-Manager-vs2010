/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsRegisteredApp.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsRegisteredApp::vmsRegisteredApp()
{

}

vmsRegisteredApp::~vmsRegisteredApp()
{

}

CString vmsRegisteredApp::GetFullPath(LPCSTR pszExeName)
{
	CRegKey key;
	CString str = "Software\\Microsoft\\Windows\\CurrentVersion\\App Paths\\";
	str += pszExeName;
	if (ERROR_SUCCESS == key.Open (HKEY_LOCAL_MACHINE, str, KEY_READ))
	{
		char szPath [MY_MAX_PATH];
		DWORD dw = sizeof (szPath);

		if (ERROR_SUCCESS == key.QueryValue (szPath, "Path", &dw))
		{
			str = szPath;
			if (str [str.GetLength () - 1] != '\\' && str [str.GetLength () - 1] != '/')
				str += '\\';
			str += pszExeName;
			return str;
		}

		if (ERROR_SUCCESS == key.QueryValue (szPath, NULL, &dw))
		{
			str = szPath;
			if (str != "" && str [0] == '"')
			{
				str.Delete (0);
				str.Delete (str.GetLength () - 1);
			}
			return str;
		}
	}

	return "";
}
