/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#define WINVER 0x501
#define _WIN32_IE 0x501
#define _WIN32_WINNT 0x501

#include "fsDShowFilterDetector.h"
#include "../system.h"
#include <stdio.h>

fsDShowFilterDetector::fsDShowFilterDetector()
{
	ZeroMemory(&m_mt, sizeof (m_mt));
    m_mt.lSampleSize = 1;
    m_mt.bFixedSizeSamples = TRUE;
	m_mt.majortype = MEDIATYPE_Stream;
	m_uFileOkLen = 0;
}

fsDShowFilterDetector::~fsDShowFilterDetector()
{

}

const AM_MEDIA_TYPE* fsDShowFilterDetector::DetectMediaType(HANDLE hFile, UINT64 uFileOkLen)
{
	HKEY key;
	if (ERROR_SUCCESS != RegOpenKeyEx (HKEY_CLASSES_ROOT, 
			"Media Type\\{e436eb83-524f-11ce-9f53-0020af0ba770}", 0, KEY_READ, &key))
		return NULL;

	m_uFileOkLen = uFileOkLen;
	if (m_uFileOkLen == _UI64_MAX)
	{
		DWORD dw1, dw2;
		dw1 = GetFileSize (hFile, &dw2);
		m_uFileOkLen = UINT64 (dw1) | UINT64 (dw2) << 32;
	}

	const AM_MEDIA_TYPE* mt = DetectMediaType (hFile, key);
	
	RegCloseKey (key);

	return mt;
}

const AM_MEDIA_TYPE* fsDShowFilterDetector::Get_MediaType()
{
	return &m_mt;
}

const AM_MEDIA_TYPE* fsDShowFilterDetector::DetectMediaType(HANDLE hFile, HKEY hkFilters)
{
	DWORD dwRes = ERROR_SUCCESS;
	char szKey [1000];

 	for (DWORD i = 0; dwRes == ERROR_SUCCESS; i++)
	{
		dwRes = RegEnumKey (hkFilters, i, szKey, sizeof (szKey));
		
		
		if (szKey [strlen (szKey)-1] != '}')
			strcat (szKey, "}");

		if (dwRes == ERROR_SUCCESS)
		{
			HKEY hKey;
			if (ERROR_SUCCESS != RegOpenKeyEx (hkFilters, szKey, 0, KEY_READ, &hKey))
				continue;

			if (IsFilterMeets (hFile, hKey))
			{
				RegCloseKey (hKey);
				break;
			}

			RegCloseKey (hKey);
		}
	}

	if (dwRes != ERROR_SUCCESS)
		return NULL;	
	
	GUID  guid;
	wchar_t szFilterGUID [1000];
	ZeroMemory (szFilterGUID, sizeof (szFilterGUID));
	MultiByteToWideChar (CP_ACP, 0, szKey, -1, szFilterGUID, 1000);
	if (FAILED (CLSIDFromString (szFilterGUID, &guid)))
		return NULL;

	m_mt.subtype = guid;

	return &m_mt;
}

BOOL fsDShowFilterDetector::IsFilterMeets(HANDLE hFile, HKEY hkFilter)
{
	DWORD dwRes = ERROR_SUCCESS;
	for (DWORD i = 0; dwRes == ERROR_SUCCESS; i++)
	{
		char szValue [1000], szData [1000];
		DWORD dwValLen = sizeof (szValue), 
			dwDataLen = sizeof (szData);
		DWORD dwType;

		dwRes = RegEnumValue (hkFilter, i, szValue, &dwValLen, NULL,
			&dwType, (LPBYTE)szData, &dwDataLen);

		if (dwRes == ERROR_SUCCESS && dwType == REG_SZ)
		{
			if (stricmp (szValue, "Source Filter") == 0)
				continue;

			if (IsFilterMeets (hFile, szData))
				return TRUE;
		}
	}

	return FALSE;
}

BOOL fsDShowFilterDetector::IsFilterMeets(HANDLE hFile, LPCSTR pszCheckBytes)
{
	while (*pszCheckBytes)
	{
		char szOffset [100], szCb [100], szMask [10000], szVal [10000];
		int pos = 0;

		
		while (*pszCheckBytes && *pszCheckBytes == ' ')
			pszCheckBytes++;

		
		while (*pszCheckBytes && *pszCheckBytes != ',')
			szOffset [pos++] = *pszCheckBytes++;
		szOffset [pos] = 0;
		pos = 0;
		if (*pszCheckBytes)	pszCheckBytes++;
		while (*pszCheckBytes && *pszCheckBytes == ' ')
			pszCheckBytes++;

		
		while (*pszCheckBytes && *pszCheckBytes != ',')
			szCb [pos++] = *pszCheckBytes++;
		szCb [pos] = 0;
		pos = 0;
		if (*pszCheckBytes)	pszCheckBytes++;
		while (*pszCheckBytes && *pszCheckBytes == ' ')
			pszCheckBytes++;

		
		while (*pszCheckBytes && *pszCheckBytes != ',')
			szMask [pos++] = *pszCheckBytes++;
		szMask [pos] = 0;
		pos = 0;
		if (*pszCheckBytes)	pszCheckBytes++;
		while (*pszCheckBytes && *pszCheckBytes == ' ')
			pszCheckBytes++;

		
		while (*pszCheckBytes && *pszCheckBytes != ',')
			szVal [pos++] = *pszCheckBytes++;
		szVal [pos] = 0;
		pos = 0;
		if (*pszCheckBytes)	pszCheckBytes++;
		while (*pszCheckBytes && *pszCheckBytes == ' ')
			pszCheckBytes++;

		if (*szOffset == 0 || *szCb == 0 || *szVal == 0)
			return FALSE;

		if (*szMask == 0)
		{
			UINT i = 0;
			for (i = 0; i < strlen (szVal); i++)
				szMask [i] = 'F';
			szMask [i] = 0;
		}

		if (FALSE == IsFilterMeets (hFile, szOffset, szCb, szMask, szVal))
			return FALSE;
	}

	return TRUE;
}

BOOL fsDShowFilterDetector::IsFilterMeets(HANDLE hFile, LPCSTR pszOffset, LPCSTR pszCb, LPCSTR pszMask, LPCSTR pszVal)
{
	INT64 offset =  _atoi64 (pszOffset);
	int cb = atoi (pszCb);
	DWORD dw;

	if (offset < 0)
	{
		DWORD dw1, dw2;
		dw1 = GetFileSize (hFile, &dw2);
		INT64 iSize = UINT64 (dw1) | UINT64 (dw2) << 32;
		offset += iSize;
	}

	if (UINT64 (offset + cb) > m_uFileOkLen)
		return FALSE;

	fsSetFilePointer (hFile, offset, FILE_BEGIN);

	LPBYTE buf = new BYTE [cb];

	if (FALSE == ReadFile (hFile, buf, cb, &dw, NULL))
		return FALSE;

	for (int i = 0; i < cb; i++)
	{
		char szHexMaskByte [3];
		szHexMaskByte [0] = pszMask [i*2];
		szHexMaskByte [1] = pszMask [i*2+1];
		szHexMaskByte [2] = 0;

		char szHexValByte [3];
		szHexValByte [0] = pszVal [i*2];
		szHexValByte [1] = pszVal [i*2+1];
		szHexValByte [2] = 0;

		int x;

		sscanf (szHexMaskByte, "%x", &x);
		BYTE bMask = (BYTE) x;

		sscanf (szHexValByte, "%x", &x);
		BYTE bVal = (BYTE) x;

		if ((buf [i] & bMask) != bVal)
			return FALSE;
	}

	return TRUE;
}
