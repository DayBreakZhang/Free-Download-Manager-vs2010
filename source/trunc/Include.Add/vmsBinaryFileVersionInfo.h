/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsAppVersion.h"

#pragma comment (lib, "version")

class vmsBinaryFileVersionInfo
{
public:
	BOOL Retrieve (LPCTSTR pszFile)
	{
		m_tstrProductName = _T ("");
		m_tstrProductVersion = _T ("");
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

	vmsBinaryFileVersionInfo(LPCTSTR ptszFile = NULL)
	{
		if (ptszFile)
			Retrieve (ptszFile);
	}

	virtual ~vmsBinaryFileVersionInfo() {}

	tstring m_tstrCompanyName;
	tstring m_tstrFileDescription;
	tstring m_tstrFileVersion;
	tstring m_tstrInternalName;
	tstring m_tstrLegalCopyright;
	tstring m_tstrOriginalFileName;
	tstring m_tstrProductName;
	tstring m_tstrProductVersion;

	
	vmsAppVersion m_appVersion, m_fileVersion;

protected:
	BOOL ExtractVersionInfo (LPVOID pvVer, DWORD dwSize)
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
			while (m_appVersion.size () > 2 && m_appVersion [m_appVersion.size () - 1].dwVal == 0)
				m_appVersion.erase (m_appVersion.end () - 1);

			m_fileVersion.push_back (pFileInfo->dwFileVersionMS >> 16);
			m_fileVersion.push_back (pFileInfo->dwFileVersionMS & 0xffff);
			m_fileVersion.push_back (pFileInfo->dwFileVersionLS >> 16);
			m_fileVersion.push_back (pFileInfo->dwFileVersionLS & 0xffff);
			while (m_fileVersion.size () > 2 && m_fileVersion [m_fileVersion.size () - 1].dwVal == 0)
				m_fileVersion.erase (m_fileVersion.end () - 1);

			bOK = TRUE;
		}

		struct LANGANDCODEPAGE
		{
			WORD wLanguage;
			WORD wCodePage;
		} *pTranslate;

		UINT uLen;

		tstring tstrLng;

		if (FALSE == VerQueryValue (pvVer, _T ("\\VarFileInfo\\Translation"), (LPVOID*) &pTranslate, &uLen))
		{
			LPBYTE pb;
			if (FALSE == VerQueryValue (pvVer, _T ("\\"), (LPVOID*)&pb, &uLen))
				return bOK;
			VS_FIXEDFILEINFO *p = (VS_FIXEDFILEINFO*)pb;
			pb += uLen;
			while (DWORD (pb - (LPBYTE)pvVer) < dwSize - wcslen (L"StringFileInfo") && wcsncmp ((LPWSTR)pb, L"StringFileInfo", wcslen (L"StringFileInfo")))
				pb++;
			if (DWORD (pb - (LPBYTE)pvVer) >= dwSize - wcslen (L"StringFileInfo"))
				return bOK;
			pb += (wcslen (L"StringFileInfo") + 1) * 2;
			pb += 3*sizeof (WORD);
			do {
				while (DWORD (pb - (LPBYTE)pvVer) < dwSize - 8*2 && 
					(wcslen ((LPWSTR)pb) < 8) )
					pb++;
				LPWSTR pwsz = (LPWSTR)pb;
				while (*pwsz && (isdigit (*pwsz) || isalpha (*pwsz)))
					pwsz++;
				if (*pwsz == 0)
				{
					USES_CONVERSION;
					tstrLng = W2T ((LPWSTR)pb);
					break;
				}
			}
			while (DWORD (pb - (LPBYTE)pvVer) < dwSize - 8*2);
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

		m_tstrCompanyName = _T ("");
		m_tstrFileDescription = _T ("");
		m_tstrFileVersion = _T ("");
		m_tstrInternalName = _T ("");
		m_tstrLegalCopyright = _T ("");
		m_tstrOriginalFileName = _T ("");
		m_tstrProductName = _T ("");
		m_tstrProductVersion = _T ("");

		tstring* atstrValues [] = {
			&m_tstrProductVersion, &m_tstrProductName, &m_tstrFileDescription, &m_tstrCompanyName,
			&m_tstrFileVersion, &m_tstrInternalName, &m_tstrLegalCopyright,
			&m_tstrOriginalFileName
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

		if (m_tstrProductVersion.empty ())
			m_tstrProductVersion = m_appVersion.ToString ();
		else
		{
			for (size_t i = 0; i < m_tstrProductVersion.length (); i++)
			{
				if (m_tstrProductVersion [i] == ',')
					m_tstrProductVersion [i] = '.';

				if (m_tstrProductVersion [i] == '.')
				{
					while (i+1 < m_tstrProductVersion.length () && m_tstrProductVersion [i+1] == ' ')
						m_tstrProductVersion.erase (m_tstrProductVersion.begin () + i + 1);
				}
			}
		}

		return TRUE;
	}
};

