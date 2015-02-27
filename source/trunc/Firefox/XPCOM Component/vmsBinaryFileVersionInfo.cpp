/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <Windows.h>
#include <malloc.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <tchar.h>
#include "vmsBinaryFileVersionInfo.h"
#include <atlbase.h>

#pragma comment (lib, "version")

vmsBinaryFileVersionInfo::vmsBinaryFileVersionInfo(LPCTSTR ptszFile)
{
	if (ptszFile)
		Retrieve (ptszFile);
}

vmsBinaryFileVersionInfo::~vmsBinaryFileVersionInfo()
{

}

BOOL vmsBinaryFileVersionInfo::Retrieve(LPCTSTR pszFile)
{
	m_strProductName = _T ("");
	m_strProductVersion = _T ("");
	m_appVersion.clear ();

	DWORD dw;
	DWORD dwSize = GetFileVersionInfoSize (pszFile, &dw);
	if (dwSize == 0)
		return FALSE;
	LPVOID pvVer = _alloca (dwSize);
	ZeroMemory (pvVer, dwSize);
	if (FALSE == GetFileVersionInfo (pszFile, 0, dwSize, pvVer))
		return FALSE;
	return ExtractVersionInfo (pvVer, dwSize);
}

BOOL vmsBinaryFileVersionInfo::ExtractVersionInfo(LPVOID pvVer, DWORD dwSize)
{
	VS_FIXEDFILEINFO *pFileInfo = NULL;
	UINT u;
	BOOL bOK = FALSE;
	if (VerQueryValue (pvVer, _T ("\\"), (LPVOID*)&pFileInfo, &u))
	{
		m_appVersion.push_back (pFileInfo->dwProductVersionMS >> 16);
		m_appVersion.push_back (pFileInfo->dwProductVersionMS & 0xffff);
		m_appVersion.push_back (pFileInfo->dwProductVersionLS >> 16);
		m_appVersion.push_back (pFileInfo->dwProductVersionLS & 0xffff);
		bOK = TRUE;
	}

	struct LANGANDCODEPAGE
	{
		WORD wLanguage;
		WORD wCodePage;
	} *pTranslate;

	UINT uLen;

	std::string tstrLng;

	if (FALSE == VerQueryValue (pvVer, _T ("\\VarFileInfo\\Translation"), (LPVOID*) &pTranslate, &uLen))
	{
		LPBYTE pb;
		if (FALSE == VerQueryValue (pvVer, _T ("\\"), (LPVOID*)&pb, &uLen))
			return bOK;
		VS_FIXEDFILEINFO *p = (VS_FIXEDFILEINFO*)pb;
		pb += uLen;
		while (pb - (LPBYTE)pvVer < dwSize - wcslen (L"StringFileInfo") && wcsncmp ((LPWSTR)pb, L"StringFileInfo", wcslen (L"StringFileInfo")))
			pb++;
		if (pb - (LPBYTE)pvVer >= dwSize - wcslen (L"StringFileInfo"))
			return bOK;
		pb += (wcslen (L"StringFileInfo") + 1) * 2;
		pb += 3*sizeof (WORD);
		do {
			while (pb - (LPBYTE)pvVer < dwSize - 8*2 && 
					(wcslen ((LPWSTR)pb) < 8) )
				pb++;
			LPWSTR pwsz = (LPWSTR)pb;
			while (*pwsz && (isdigit (*pwsz) || isalpha (*pwsz)))
				pwsz++;
			if (*pwsz == 0)
			{
				tstrLng = CW2TEX<128> ((LPWSTR)pb);
				break;
			}
		}
		while (pb - (LPBYTE)pvVer < dwSize - 8*2);
	}

	LPTSTR atszValueName [] = {
		_T ("ProductVersion"),
		_T ("ProductName"),
		_T ("FileDescription"),
		_T ("CompanyName"),
		_T ("FileVersion"),
		_T ("InternalName"),
		_T ("LegalCopyright"),
		_T ("OriginalFilename"),
	};

	m_strCompanyName = _T ("");
	m_strFileDescription = _T ("");
	m_strFileVersion = _T ("");
	m_strInternalName = _T ("");
	m_strLegalCopyright = _T ("");
	m_strOriginalFileName = _T ("");
	m_strProductName = _T ("");
	m_strProductVersion = _T ("");

	std::string* atstrValues [] = {
		&m_strProductVersion, &m_strProductName, &m_strFileDescription, &m_strCompanyName,
		&m_strFileVersion, &m_strInternalName, &m_strLegalCopyright,
		&m_strOriginalFileName
	};

	int nLang = 0;

	if (tstrLng.empty ())
	{
		for (int i = 0; i < (int)uLen / (int)sizeof (LANGANDCODEPAGE) ; i++)
		{
			if ((pTranslate [i].wLanguage & 0x3FF) == 9)
			{
				
				nLang = i;
				break;
			}
		}
	}

	for (int i = 0; i < sizeof (atszValueName) / sizeof (LPTSTR); i++)
	{
		TCHAR tsz [200];
		if (tstrLng.empty ())
		{
			_stprintf (tsz, _T ("\\StringFileInfo\\%04x%04x\\%s"), pTranslate [nLang].wLanguage,
				pTranslate [nLang].wCodePage, atszValueName [i]);
		}
		else
		{
			_stprintf (tsz, _T ("\\StringFileInfo\\%s\\%s"), tstrLng.c_str (), atszValueName [i]);
		}
		LPVOID pvValue;
		UINT uValLen;
		if (FALSE == VerQueryValue (pvVer, tsz, &pvValue, &uValLen))
		{
			if (tstrLng.empty () && pTranslate [nLang].wLanguage == 0)
			{
				pTranslate [nLang].wLanguage = 0x0409;
				i--;
			}
			continue;
		}

		atstrValues [i]->assign ((LPCTSTR)pvValue);
	}

	if (m_strProductVersion.empty ())
		m_strProductVersion = m_appVersion.ToString ();
	else
	{
		for (int i = 0; i < m_strProductVersion.length (); i++)
		{
			if (m_strProductVersion [i] == ',')
				m_strProductVersion [i] = '.';
			
			if (m_strProductVersion [i] == '.')
			{
				while (i+1 < m_strProductVersion.length () && m_strProductVersion [i+1] == ' ')
					m_strProductVersion.erase (m_strProductVersion.begin () + i + 1);
			}
		}
	}

	return TRUE;
}

