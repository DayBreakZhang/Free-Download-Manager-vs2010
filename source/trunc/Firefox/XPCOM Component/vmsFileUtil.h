/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFILEUTIL_H__A3E2F9DA_BF0E_43B9_AF5C_84C1AB7A72A6__INCLUDED_)
#define AFX_VMSFILEUTIL_H__A3E2F9DA_BF0E_43B9_AF5C_84C1AB7A72A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <fsString.h>

class vmsFileUtil  
{
public:
	static void BuildPath (LPCSTR pszPath);
	static fsString GetPathFromPathName (LPCSTR pszPathName);
	static void BuildPathToFile (LPCSTR pszFileName);
	static void GetAppDataPath (LPCSTR pszAppName, LPSTR szPath);
	static void MakePathOK (LPSTR szPath, bool bNeedBackslashAtEnd = true);
};

#endif 
