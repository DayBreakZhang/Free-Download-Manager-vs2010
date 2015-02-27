/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsAutorunMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsAutorunMgr::fsAutorunMgr()
{
	m_hAutoStart = NULL;
}

fsAutorunMgr::~fsAutorunMgr()
{

}

BOOL fsAutorunMgr::SetAutoStart(BOOL bSet)
{
	if (FALSE == OpenAutoStartKey ())
		return FALSE;

	TCHAR szModule [MAX_PATH + 50];
	*szModule = 0;
	BOOL bRet;

	
	GetModuleFileName (NULL, szModule, MAX_PATH);

	if (bSet)
	{
		
		_tcscat (szModule, _T (" -autorun"));
		bRet = ERROR_SUCCESS == RegSetValueEx (m_hAutoStart, _T ("Free Upload Manager"), 0, REG_SZ, (CONST BYTE*) szModule, _tcslen (szModule) + 1);
	}
	else
	{
		bRet = ERROR_SUCCESS == RegDeleteValue (m_hAutoStart, _T ("Free Upload Manager"));
	}

	CloseAutoStartKey ();

	return bRet;
}

BOOL fsAutorunMgr::OpenAutoStartKey()
{
	
	if (ERROR_SUCCESS != RegOpenKey (HKEY_CURRENT_USER, 
			_T ("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &m_hAutoStart))
		return FALSE;

	return TRUE;
}

void fsAutorunMgr::CloseAutoStartKey()
{
	RegCloseKey (m_hAutoStart);
}

BOOL fsAutorunMgr::IsAutoStart()
{
	if (FALSE == OpenAutoStartKey ())
		return FALSE;

	DWORD dwType;

	return ERROR_SUCCESS == RegQueryValueEx (m_hAutoStart, _T ("Free Upload Manager"), NULL,
		&dwType, NULL, NULL);
}
