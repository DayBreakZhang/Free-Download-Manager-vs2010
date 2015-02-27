/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class vmsRegisteredAppPath
{
public:
	bool Query (LPCTSTR ptszFileName)
	{
		m_tstrPath = _T ("");
		m_tstrFilePathName = _T ("");

		CRegKey key;
		tstring tstrKey = _T ("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
		tstrKey += ptszFileName;
		if (ERROR_SUCCESS != key.Open (HKEY_LOCAL_MACHINE, tstrKey.c_str (), KEY_READ))
			return false;

		TCHAR tsz [MAX_PATH] = _T ("");
		ULONG nChars = _countof (tsz);

		if (ERROR_SUCCESS == key.QueryStringValue (_T ("Path"), tsz, &nChars))
			m_tstrPath = tsz;

		nChars = _countof (tsz);
		if (ERROR_SUCCESS == key.QueryStringValue (NULL, tsz, &nChars))
			m_tstrFilePathName = tsz;

		return true;
	}

	LPCTSTR getPath () const {return m_tstrPath.c_str ();}
	LPCTSTR getFilePathName () const {return m_tstrFilePathName.c_str ();}

protected:
	tstring m_tstrPath;
	tstring m_tstrFilePathName;
};