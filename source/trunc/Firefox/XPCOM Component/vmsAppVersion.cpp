/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <Windows.h>
#include <string>
#include <vector>
#include <tchar.h>
#include "vmsAppVersion.h"

vmsAppVersion::vmsAppVersion()
{

}

vmsAppVersion::~vmsAppVersion()
{

}

BOOL vmsAppVersion::FromString(LPCTSTR ptszVersion)
{
	clear ();

	while (*ptszVersion == ' ')
		ptszVersion++;

	if (*ptszVersion == 'v' || *ptszVersion == 'V')
		ptszVersion++;
	
	while (*ptszVersion)
	{
		while (*ptszVersion == ' ')
			ptszVersion++;
		std::string tstrVer;
		while (_istdigit (*ptszVersion))
			tstrVer += *ptszVersion++;
		if (tstrVer.empty ())
			break;
		while (*ptszVersion == ' ')
			ptszVersion++;
		if (*ptszVersion == '.' || *ptszVersion == ',')
			ptszVersion++;
		push_back (vmsAppVersionPart (tstrVer.c_str ()));
	}
	
	if (size () && *ptszVersion)
	{
		while (ptszVersion [-1] == ' ')
			ptszVersion--;
		m_strReleaseType = ptszVersion;
	}

	return size () != 0;
}

std::string vmsAppVersion::ToString() const
{
	std::string tstrVer;
	for (size_t i = 0; i < size (); i++)
	{
		if (!tstrVer.empty ())
			tstrVer += _T (".");
		tstrVer += at (i).toString ();
	}
	tstrVer += m_strReleaseType;
	return tstrVer;
}

void vmsAppVersion::clear()
{
	using namespace std;
	vector<vmsAppVersionPart>::clear ();
	m_strReleaseType = _T ("");
}
