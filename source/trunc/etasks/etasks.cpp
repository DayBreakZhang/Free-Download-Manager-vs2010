/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsCommandLineParser.h"
#include "vmsTask_CopyFile.h"
#include "vmsTask_DeleteFile.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	fsCommandLineParser cl;

	vector <vmsTask*> vTasks;
	
	int i = 0;
	for (i = 0; i < cl.Get_ParameterCount (); i++)
	{
		LPCTSTR ptszArg = cl.Get_Parameter (i);

		if (!_tcsicmp (ptszArg, _T ("copy")))
		{
			if (cl.Get_ParameterCount () - i < 3)
				break;

			if (*cl.Get_ParameterValue (i+1) == 0 || *cl.Get_ParameterValue (i+2) == 0)
				break;

			vmsTask_CopyFile *p = new vmsTask_CopyFile;
			p->setSrcFile (cl.Get_ParameterValue (++i));
			p->setDstFile (cl.Get_ParameterValue (++i));

			vTasks.push_back (p);
		}

		else if (!_tcsicmp (ptszArg, _T ("del")))
		{
			if (cl.Get_ParameterCount () - i < 2)
				break;
			
			if (*cl.Get_ParameterValue (i+1) == 0)
				break;
			
			vmsTask_DeleteFile *p = new vmsTask_DeleteFile;
			p->setFile (cl.Get_ParameterValue (++i));
			
			vTasks.push_back (p);
		}
	}

	int iRes = 0;

	for (i = 0; i < vTasks.size (); i++)
	{
		if (!vTasks [i]->Do ())
			iRes = 1; 
		delete vTasks [i];
	}

	return iRes;
}

void vmsGetPath (LPCTSTR pszFile, LPTSTR pszPath)
{
	_tcscpy (pszPath, pszFile);
	
	int len = _tcslen (pszPath) - 1;
	
	while (len >= 0 && pszPath [len] != '\\' && pszPath [len] != '/')
		len--;
	
	pszPath [len+1] = 0;
}

BOOL vmsBuildPathToFile (LPCTSTR pszFileName)
{
	TCHAR szPath [MAX_PATH];
	
	vmsGetPath (pszFileName, szPath);
	
	int len = _tcslen (szPath);
	int start = 0;
	
	
	if (szPath [0] == '\\' && szPath [1] == '\\')
	{
		
		LPCTSTR psz = _tcschr (szPath + 2, '\\');
		
		if (psz)
			psz = _tcschr (psz+1, '\\');
		if (psz)
			psz++;
		if (psz == NULL)
		{
			
			SetLastError (ERROR_PATH_NOT_FOUND);
			return FALSE;
		}
		
		
		start = psz - szPath;
	}
	else
	{
		if (szPath [1] == ':')
			start = 3;
	}
	
	for (int i = start; i < len; i++)
	{
		if (szPath [i] == '\\' || szPath [i] == '/')
		{
			
			
			
			
			
			
			
			TCHAR szPath2 [MAX_PATH];
			
			CopyMemory (szPath2, szPath, i * sizeof (TCHAR));
			szPath2 [i] = 0;
			
			if (FALSE == CreateDirectory (szPath2, NULL))	
			{
				if (GetLastError () != ERROR_ALREADY_EXISTS)
					return FALSE;
			}
		}
	}
	
	return TRUE;
}
