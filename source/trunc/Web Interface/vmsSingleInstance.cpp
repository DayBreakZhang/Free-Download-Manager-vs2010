/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSingleInstance.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSingleInstance::vmsSingleInstance(LPCSTR pszAppName)
{
	
	m_hmx = CreateMutex (NULL, FALSE, pszAppName);
	
	if (GetLastError () == ERROR_ALREADY_EXISTS)
	{
		
		
		CloseHandle (m_hmx);
		m_hmx = NULL;
	}
}

vmsSingleInstance::~vmsSingleInstance()
{

}

BOOL vmsSingleInstance::is_1stInstance()
{
	return m_hmx != NULL;
}

void vmsSingleInstance::set_1stInstanceHWND(HWND hwnd)
{
	
}

HWND vmsSingleInstance::get_1stInstanceHWND()
{
	return NULL;
}

void vmsSingleInstance::Shutdown1stInstance()
{
	PostMessage (get_1stInstanceHWND (), WM_APP_NEEDSHUTDOWN, 0, 0);
}

void vmsSingleInstance::FreeInstance()
{
	if (m_hmx) {
		CloseHandle (m_hmx);
		m_hmx = NULL;
	}
}
