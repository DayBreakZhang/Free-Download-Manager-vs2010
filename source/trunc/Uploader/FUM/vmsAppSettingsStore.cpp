/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsAppSettingsStore.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsAppSettingsStore::vmsAppSettingsStore()
{
	m_app = AfxGetApp ();
	m_bUseRegistry = true;
}

vmsAppSettingsStore::~vmsAppSettingsStore()
{

}

UINT vmsAppSettingsStore::GetProfileInt(LPCSTR pszSection, LPCSTR pszEntry, INT nDefault)
{
	if (m_bUseRegistry)
		return m_app->GetProfileInt (pszSection, pszEntry, nDefault);
		
	int iValue = nDefault;
	m_file.get_Value (pszSection, pszEntry, iValue);
	return iValue;
}

BOOL vmsAppSettingsStore::WriteProfileInt(LPCSTR pszSection, LPCSTR pszEntry, int nValue)
{
	if (m_bUseRegistry)
		return m_app->WriteProfileInt (pszSection, pszEntry, nValue);

	m_file.set_Value (pszSection, pszEntry, nValue);
	return TRUE;
}

CString vmsAppSettingsStore::GetProfileString(LPCSTR pszSection, LPCSTR pszEntry, LPCSTR pszDefault)
{
	if (m_bUseRegistry)
		return m_app->GetProfileString (pszSection, pszEntry, pszDefault);

	LPCSTR pszValue = pszDefault;
	m_file.get_Value (pszSection, pszEntry, pszValue);
	return pszValue;
}

BOOL vmsAppSettingsStore::WriteProfileString(LPCSTR pszSection, LPCSTR pszEntry, LPCSTR pszValue)
{
	if (m_bUseRegistry)
		return m_app->WriteProfileString (pszSection, pszEntry, pszValue);

	m_file.set_Value (pszSection, pszEntry, pszValue);
	return TRUE;
}

BOOL vmsAppSettingsStore::GetProfileBinary(LPCSTR pszSection, LPCSTR pszEntry, LPBYTE *ppData, UINT *pBytes)
{
	if (m_bUseRegistry)
		return m_app->GetProfileBinary (pszSection, pszEntry, ppData, pBytes);

	LPBYTE pbValue = NULL;
	UINT nValueSize = 0;

	m_file.get_Value (pszSection, pszEntry, pbValue, nValueSize);

	if (pbValue == NULL)
		return FALSE;

	*ppData = new BYTE [nValueSize];
	CopyMemory (*ppData, pbValue, nValueSize);
	*pBytes = nValueSize;

	return TRUE;
}

BOOL vmsAppSettingsStore::WriteProfileBinary(LPCSTR pszSection, LPCSTR pszEntry, LPBYTE pbData, UINT nBytes)
{
	if (m_bUseRegistry)
		return m_app->WriteProfileBinary (pszSection, pszEntry, pbData, nBytes);

	m_file.set_Value (pszSection, pszEntry, pbData, nBytes);
	return TRUE;
}

void vmsAppSettingsStore::LoadSettingsFromFile(LPCSTR pszFile)
{
	m_bUseRegistry = false;

	HANDLE hFile = CreateFile (pszFile, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	try {
		m_file.LoadFromFile (hFile);
	}catch (...){}

	CloseHandle (hFile);
}

void vmsAppSettingsStore::SaveSettingsToFile(LPCSTR pszFile)
{
	HANDLE hFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	try {
		m_file.SaveToFile (hFile);
	}catch (...){}

	CloseHandle (hFile);
}
