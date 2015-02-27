/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsIEUserAgent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsIEUserAgent::fsIEUserAgent()
{
	OpenUAKey ();
}

fsIEUserAgent::~fsIEUserAgent()
{

}

void fsIEUserAgent::OpenUAKey()
{
	if (m_keyUA.m_hKey)
		return;

	m_keyUA.Create (HKEY_LOCAL_MACHINE, "Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings\\5.0\\User Agent\\Post Platform");
}

void fsIEUserAgent::SetPP(LPCSTR pszPP)
{
	if (m_keyUA.m_hKey)
		m_keyUA.SetValue ("", pszPP);
}

void fsIEUserAgent::RemovePP(LPCSTR pszPP)
{
	if (m_keyUA.m_hKey)
		m_keyUA.DeleteValue (pszPP);
}
