/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsAppSettingsStore.h"
#include "vmsLogger.h"

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

	bool bIsChanged = false;
	int iValue = 0;
	if (!m_file.get_Value (pszSection, pszEntry, iValue) || nValue != iValue) {
		bIsChanged = true;
	}

	m_file.set_Value (pszSection, pszEntry, nValue);
	
	if (bIsChanged)
		setDirty();
	return TRUE;
}

UINT64 vmsAppSettingsStore::GetProfileUint64(LPCSTR pszSection, LPCSTR pszEntry, UINT64 nDefault)
{
	LPBYTE pData; UINT uSize;
	if (!GetProfileBinary (pszSection, pszEntry, &pData, &uSize))
		return nDefault;
	UINT64 uRes = uSize == sizeof (UINT64) ? *((UINT64*)pData) : nDefault;
	delete [] pData;
	return uRes;
}

BOOL vmsAppSettingsStore::WriteProfileUint64(LPCSTR pszSection, LPCSTR pszEntry, UINT64 nValue)
{
	return WriteProfileBinary (pszSection, pszEntry, (LPBYTE)&nValue, sizeof (nValue));
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

	bool bIsChanged = false;
	LPCSTR pszOldValue = 0;
	if (!m_file.get_Value (pszSection, pszEntry, pszOldValue)) {
		bIsChanged = true;
	}
	if ((pszOldValue == NULL && pszValue != NULL) || (pszOldValue != NULL && pszValue == NULL)) {
		bIsChanged = true;
	} else if (pszValue != NULL && pszOldValue != NULL) {
		bIsChanged = (_tcscmp(pszValue, pszOldValue) != 0);
	}

	m_file.set_Value (pszSection, pszEntry, pszValue);
	if (bIsChanged)
		setDirty();
	return TRUE;
}

BOOL vmsAppSettingsStore::GetProfileBinary(LPCSTR pszSection, LPCSTR pszEntry, LPBYTE *ppData, UINT *pBytes)
{
	if (m_bUseRegistry)
		return m_app->GetProfileBinary (pszSection, pszEntry, ppData, pBytes);

	LPBYTE pbValue = NULL;
	UINT nValueSize = 0;

	m_file.get_Value (pszSection, pszEntry, pbValue, nValueSize);

	if (pbValue == NULL || nValueSize == 0)
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

	UINT nOldBytes = 0;
	LPBYTE pbOldData = 0;
	bool bIsChanged = false;
	if (!m_file.get_Value (pszSection, pszEntry, pbOldData, nOldBytes)) {
		bIsChanged = true;
	} else {
		if (nOldBytes != nBytes) {
			bIsChanged = true;
		} else {
			if (nBytes != 0) {
				bIsChanged = (memcmp(pbData, pbOldData, nBytes) != 0);
			}
		}
	}

	m_file.set_Value (pszSection, pszEntry, pbData, nBytes);
	if (bIsChanged)
		setDirty();
	return TRUE;
}

void vmsAppSettingsStore::LoadSettingsFromFile(LPCSTR pszFile)
{
	m_bUseRegistry = false;

	HANDLE hFile = CreateFile (pszFile, GENERIC_READ, FILE_SHARE_READ, NULL,
		OPEN_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	try 
	{
		DWORD dwRequiredSize = ::GetFileSize(hFile, NULL);
		DWORD dw = 0;
		if (dwRequiredSize <= 0) {
			CloseHandle (hFile);
			return;
		}

		std::auto_ptr<BYTE> pbtBufferGuard( new BYTE[dwRequiredSize] );
		LPBYTE pbtBuffer = pbtBufferGuard.get();
		if (pbtBuffer == 0) {
			CloseHandle (hFile);
			return;
		}
		memset(pbtBuffer, 0, dwRequiredSize);

		if (!ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
			CloseHandle (hFile);
			return;
		}

		if (!loadFromStateBuffer(pbtBuffer, &dwRequiredSize, 0)) {
			CloseHandle (hFile);
			return;
		}

		CloseHandle (hFile);
		resetDirty();
	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsAppSettingsStore::LoadSettingsFromFile " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsAppSettingsStore::LoadSettingsFromFile unknown exception");
	}
}

void vmsAppSettingsStore::SaveSettingsToFile(LPCSTR pszFile)
{
	if (!isDirty())
		return;

	HANDLE hFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return;

	try 
	{
		DWORD dwRequiredSize = 0;
		DWORD dw = 0;

		getStateBuffer(0, &dwRequiredSize, false);

		if (dwRequiredSize == 0)
			return;

		std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
		LPBYTE pbtBuffer = apbtBufferGuard.get();
		if (pbtBuffer == 0)
			return;
		memset(pbtBuffer, 0, dwRequiredSize);

		getStateBuffer(pbtBuffer, &dwRequiredSize, true);

		if (FALSE == WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
			CloseHandle (hFile);
			return;
		}
		CloseHandle (hFile);
		onStateSavedSuccessfully();
	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsAppSettingsStore::SaveSettingsToFile " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsAppSettingsStore::SaveSettingsToFile unknown exception");
	}
}

void vmsAppSettingsStore::getObjectItselfStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, bool bSaveToStorage)
{
	DWORD dwRequiredSize = 0;
	LPBYTE pbtCurrentPos = pbtBuffer;

	m_file.SaveToBuffer(pbtCurrentPos, 0, 0, &dwRequiredSize);

	if (pbtBuffer == NULL) 
	{
		if (pdwSize != 0) {
			*pdwSize = dwRequiredSize;
		}
		return;
	}

	m_file.SaveToBuffer(pbtCurrentPos, pbtBuffer, *pdwSize, &dwRequiredSize);

	*pdwSize = pbtCurrentPos - pbtBuffer;
}

bool vmsAppSettingsStore::loadObjectItselfFromStateBuffer(LPBYTE pbtBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	LPBYTE pbtCurrentPos = pbtBuffer;
	m_file.LoadFromBuffer(pbtCurrentPos, pbtBuffer, *pdwSize);
	*pdwSize = pbtCurrentPos - pbtBuffer;
	return true;
}
