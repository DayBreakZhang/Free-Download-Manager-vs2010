/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUrl.h"

vmsUrl::vmsUrl()
{

}

vmsUrl::~vmsUrl()
{

}

bool vmsUrl::isAbsolute(LPCSTR pszUrl)
{
	string str; 
	GetScheme (pszUrl, str);
	return !str.empty ();
}

LPCSTR vmsUrl::GetFilePathStart(LPCSTR pszUrl)
{
	pszUrl = strstr (pszUrl, "://");
	if (!pszUrl)
		return NULL;
	return strchr (pszUrl+3, '/');
}

void vmsUrl::GetAbsoluteUrlFromRelative(LPCSTR pszUrlPath, LPCSTR pszRelUrl, string &strResult)
{
	strResult = "";
	assert (pszUrlPath != NULL && pszRelUrl != NULL);
	if (!pszUrlPath || !pszRelUrl)
		return;
	assert (!isAbsolute (pszRelUrl));

	LPCSTR pszFilePathStart = GetFilePathStart (pszUrlPath);
	assert (pszFilePathStart != pszUrlPath);
	if (pszFilePathStart == NULL || pszFilePathStart == pszUrlPath)
		return;
	int nServPartLen = pszFilePathStart - pszUrlPath;

	if (*pszRelUrl == '/')
	{
		if (pszRelUrl [1] == '/')
		{
			
			string strScheme; GetScheme (pszUrlPath, strScheme);
			assert (!strScheme.empty ());
			if (strScheme.empty ())
				return;
			strResult = strScheme;
			strResult += ':';
			strResult += pszRelUrl;
			return;
		}
		strResult.assign (pszUrlPath, nServPartLen);
		assert (strResult [strResult.length () - 1] != '/');
		strResult += pszRelUrl;
		return;
	}
	
	strResult = pszUrlPath;
	if (strResult [strResult.length ()-1] != '/')
		strResult += '/';

	LPCSTR pszFilePathEnd = strchr (pszRelUrl, '?');
	if (!pszFilePathEnd)
		pszFilePathEnd = pszRelUrl + strlen (pszRelUrl);

	while (pszRelUrl < pszFilePathEnd && *pszRelUrl)
	{
		LPCSTR psz = strchr (pszRelUrl, '/');
		if (!psz)
			psz = pszFilePathEnd;
		string strFolder; 
		strFolder.assign (pszRelUrl, psz - pszRelUrl);
		if (*psz)
			pszRelUrl = psz + 1;
		else
			pszRelUrl = psz;
		if (strFolder == ".")
			continue;
		if (strFolder == "..")
		{
			if (strResult.length () == nServPartLen + 1)
				continue; 
			int cDel = 1;
			while (strResult [strResult.length () - cDel - 1] != '/')
			{
				cDel++;
				assert (cDel < strResult.length ());
				if (cDel == strResult.length ())
				{
					strResult = "";
					return; 
				}
			}
			strResult.erase (strResult.end () - cDel, strResult.end ());
		}
		else
		{
			strResult += strFolder;
			if (psz < pszFilePathEnd)
				strResult += '/';
		}
	}
	if (*pszRelUrl)
		strResult += pszRelUrl;
}

void vmsUrl::GetAbsoluteUrlFromRelative2 (LPCSTR pszWebPageUrl, LPCSTR pszRelUrl, string &strResult)
{
	strResult = "";
	LPCSTR psz = vmsUrl::GetFileNamePartStart (pszWebPageUrl);
	if (psz)
	{
		string strUrlPath; 
		strUrlPath.assign (pszWebPageUrl, psz - pszWebPageUrl);
		string strAbsUrl;
		GetAbsoluteUrlFromRelative (strUrlPath.c_str (), pszRelUrl, strResult);
	}
}

void vmsUrl::GetScheme(LPCSTR pszUrl, string &strResult)
{
	strResult = "";
	assert (pszUrl != NULL);
	if (!pszUrl)
		return;
	while (isalpha ((BYTE)*pszUrl))
		strResult += *pszUrl++;
	if (pszUrl [0] != ':' || pszUrl [1] != '/' || pszUrl [2] != '/')
	{
		strResult = "";
		return; 
	}
}

LPCSTR vmsUrl::GetFileNamePartStart(LPCSTR pszUrl)
{
	LPCSTR pszQ = strchr (pszUrl, '?');
	LPCSTR pszRes = NULL;
	if (!pszQ)
	{
		pszRes = strrchr (pszUrl, '/');
		return pszRes ? pszRes + 1 : NULL;
	}
	while (true) 
	{
		LPCSTR pszS = strchr (pszUrl, '/');
		if (!pszS || pszS > pszQ)
			return pszRes;
		pszRes = pszUrl = pszS + 1;
	}
}