/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"

#include "vmsFile.h"

vmsFile::vmsFile()
{
	m_file = NULL;
}

vmsFile::~vmsFile()
{
	close ();
}

bool vmsFile::open(LPCSTR pszName, LPCSTR pszMode)
{
	close ();

	m_file = fopen (pszName, pszMode);

	return m_file != NULL;
}

void vmsFile::close()
{
	if (m_file)
	{
		fclose (m_file);
		m_file = NULL;
	}
}

bool vmsFile::read(std::string& str)
{
	char sz [1000] = "";
	str = "";

	for (;;)
	{
		LPCSTR psz = fgets (sz, sizeof (sz) - 1, m_file);

		if (psz == NULL && !feof (m_file))
		{
			str = "";
			return false;
		}

		if (psz == NULL)
			return false;

		str += sz;
		if (lstrlen (sz) < sizeof (sz) - 1 ||
				str [str.length () - 1] == '\n')
			break;
	};

	if (str [str.length () - 1] == '\n')
		str.erase (str.begin () + str.length () - 1);

	return true;
}
