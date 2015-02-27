/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSAPPVERSION_H__8781CDB7_59E5_4455_9470_B79536FD43D7__INCLUDED_)
#define AFX_VMSAPPVERSION_H__8781CDB7_59E5_4455_9470_B79536FD43D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

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

	std::string toString () const 
	{
		std::string tstr;
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
	void clear();
	std::string ToString() const;
	BOOL FromString (LPCTSTR ptszVersion);

	std::string m_strReleaseType; 

	vmsAppVersion();
	virtual ~vmsAppVersion();
};

#endif 
