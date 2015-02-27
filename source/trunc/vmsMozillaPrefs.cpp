/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsMozillaPrefs.h"

vmsMozillaPrefs::vmsMozillaPrefs()
{

}

vmsMozillaPrefs::~vmsMozillaPrefs()
{

}

bool vmsMozillaPrefs::LoadPrefs(LPCSTR pszFile)
{
	Free ();

	

	HANDLE hFile = CreateFile (pszFile, GENERIC_READ, FILE_SHARE_READ, NULL, 
		OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return false;
	
	int n = GetFileSize (hFile, NULL);
	m_strPrefs.pszString = new char [n+1];

	DWORD dw;
	ReadFile (hFile, m_strPrefs.pszString, n, &dw, NULL);
	m_strPrefs.pszString [n] = 0;

	CloseHandle (hFile);

	return true;
}

void vmsMozillaPrefs::Free()
{
	if (m_strPrefs.pszString) {
		delete [] m_strPrefs.pszString;
		m_strPrefs.pszString = 0;
	}
}

fsString vmsMozillaPrefs::get_Value(LPCSTR pszPrefName) const
{
	LPCSTR pszPrefs = m_strPrefs.pszString;

	fsString strPrefName; 
	strPrefName = "\""; 
	strPrefName += pszPrefName;
	strPrefName += "\""; 

	

	while (*pszPrefs && strnicmp (pszPrefs, strPrefName, strPrefName.Length ()))
		pszPrefs++;

	if (*pszPrefs == 0)
		return MOZILLAPREFS_VALUE_NOT_FOUND;

	pszPrefs += strPrefName.Length ();
	
	
	while (*pszPrefs && *pszPrefs != ',')
		pszPrefs++;

	if (*pszPrefs == 0)
		return MOZILLAPREFS_UNEXPECTED_ERROR;

	
	pszPrefs++;
	while (*pszPrefs == ' ' || *pszPrefs == '\t')
		pszPrefs++;

	bool bInQ = false; 
	if (*pszPrefs == '"') {
		pszPrefs++;
		bInQ = true;
	}

	fsString strValue;

	
	
	if (bInQ)
	{
		while (*pszPrefs && *pszPrefs != '"')
		{
			char c = *pszPrefs++;

			
			if (c == '\\')
			{
				switch (*pszPrefs)
				{
				case 'n': c = '\n'; break;
				case 't': c = '\t'; break;
				case 'r': c = '\r'; break;
				default: c = *pszPrefs; break;
				}

				pszPrefs++;
			}

			strValue += c;
		}
	}
	else
	{
		while (IsCharAlphaNumeric (*pszPrefs))
			strValue += *pszPrefs++;
	}

	return strValue;
}
