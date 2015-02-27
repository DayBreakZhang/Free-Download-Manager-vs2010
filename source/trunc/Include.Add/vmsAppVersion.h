/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

struct vmsAppVersionPart
{
	DWORD dwVal;
	int cPreZeros; 

	vmsAppVersionPart (LPCTSTR ptsz) 
	{
		fromString (ptsz);
	}

	void fromString (LPCTSTR ptsz)
	{
		if (ptsz)
		{
			dwVal = _ttoi (ptsz);
			cPreZeros = 0;
			if (dwVal)
			{
				while (*ptsz++ == '0')
					cPreZeros++;
			}
		}
		else
		{
			dwVal = 0; 
			cPreZeros = 0;
		}
	}

	tstring toString () const 
	{
		tstring tstr;
		for (int i = 0; i < cPreZeros; i++)
			tstr += '0';
		TCHAR tsz [100] = _T ("");
		tstr += _itot (dwVal, tsz, 10);
		return tstr;
	}

	vmsAppVersionPart (DWORD dw) 
	{
		dwVal = dw;
		cPreZeros = 0;
	}

	BOOL operator < (const vmsAppVersionPart &o) const {
		return cPreZeros != o.cPreZeros && dwVal != 0 && o.dwVal != 0 ? 
			cPreZeros > o.cPreZeros : dwVal < o.dwVal;
	}

	BOOL operator == (const vmsAppVersionPart &o) const {
		return dwVal == o.dwVal && cPreZeros == o.cPreZeros;
	}

	BOOL operator != (const vmsAppVersionPart &o) const {return !operator == (o);}

	BOOL operator != (DWORD dw) const { return dwVal != dw || cPreZeros != 0;}
};

enum vmsAppVersionReleaseType
{
	RT_RELEASE,
	RT_ALPHA,
	RT_BETA,
	RC_RC,
	RC_UNKNOWN,
};

class vmsAppVersion : public std::vector <vmsAppVersionPart>
{
public:
	void clear()
	{
		std::vector<vmsAppVersionPart>::clear ();
		m_tstrReleaseType = _T ("");
	}

	tstring ToString() const
	{
		tstring tstrVer;
		for (size_t i = 0; i < size (); i++)
		{
			if (!tstrVer.empty ())
				tstrVer += _T (".");
			tstrVer += at (i).toString ();
		}
		tstrVer += m_tstrReleaseType;
		return tstrVer;
	}

	BOOL FromString (LPCTSTR ptszVersion)
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
			tstring tstrVer;
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
			m_tstrReleaseType = ptszVersion;
		}

		return size () != 0;
	}

	tstring m_tstrReleaseType; 

	vmsAppVersion() {}
	virtual ~vmsAppVersion() {}
};

