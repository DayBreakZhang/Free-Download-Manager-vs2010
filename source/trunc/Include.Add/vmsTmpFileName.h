/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include <shellapi.h>

class vmsTmpFileName
{
public:
	vmsTmpFileName (LPCTSTR ptszPrefix = _T ("tmp"), LPCTSTR ptszExt = NULL)
	{
		TCHAR tsz [MAX_PATH] = _T ("");
		GetTempPath (_countof (tsz), tsz);
		TCHAR tsz1 [MAX_PATH] = _T ("");
		GetTempFileName (tsz, ptszPrefix, 0, tsz1);
		m_tstrTmpFileName1 = tsz1;
		if (ptszExt && _tcsicmp (ptszExt, _T ("tmp")))
		{
			_tcscpy (tsz1 + _tcslen (tsz1) - 3, ptszExt);
			m_tstrTmpFileName2 = tsz1;
			assert (GetFileAttributes (tsz1) == DWORD (-1));
		}
	}

	~vmsTmpFileName ()
	{
		if (!m_tstrTmpFileName2.empty ())
			DeleteFile (m_tstrTmpFileName2.c_str ());
		if (!m_tstrTmpFileName1.empty ())
			DeleteFile (m_tstrTmpFileName1.c_str ());
	}

	operator LPCTSTR () const {return m_tstrTmpFileName2.empty () ? m_tstrTmpFileName1.c_str () : m_tstrTmpFileName2.c_str ();}

protected:
	tstring m_tstrTmpFileName1, m_tstrTmpFileName2;
};

class vmsTmpDirName
{
public:
	vmsTmpDirName (bool bDeleteDirWithContents = true) : 
	  m_bDeleteDirWithContents (bDeleteDirWithContents)
	{
		WCHAR wsz [MAX_PATH] = L"";
		GetTempPathW (_countof (wsz), wsz);
		GUID guid;
		if (FAILED (CoCreateGuid (&guid)))
			return;
		wchar_t wszGuid [100] = L"";
		StringFromGUID2 (guid, wszGuid, _countof (wszGuid));
		wcscat (wsz, L"\\");
		wcscat (wsz, wszGuid);
		CreateDirectoryW (wsz, NULL);
		USES_CONVERSION;
		m_tstrTmpDirName = W2CT (wsz);
	}

	~vmsTmpDirName ()
	{
		if (!m_tstrTmpDirName.empty ())
		{
			if (!RemoveDirectory (m_tstrTmpDirName.c_str ()))
			{
				if (m_bDeleteDirWithContents)
				{
					SHFILEOPSTRUCT sh;
					ZeroMemory (&sh, sizeof (sh));
					sh.wFunc  = FO_DELETE;
					sh.fFlags = FOF_NOCONFIRMATION | FOF_SILENT | FOF_NOERRORUI;

					std::vector <TCHAR> vtchFrom;
					vtchFrom.resize (m_tstrTmpDirName.length () + 1);
					CopyMemory (&vtchFrom [0], m_tstrTmpDirName.c_str (), (m_tstrTmpDirName.length () + 1) * sizeof (TCHAR));
					vtchFrom.push_back (0);
					sh.pFrom  = &vtchFrom [0];

					SHFileOperation (&sh);
				}
			}
		}
	}

	operator LPCTSTR () const {return m_tstrTmpDirName.c_str ();}

protected:
	tstring m_tstrTmpDirName;
	bool m_bDeleteDirWithContents;
};

