/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpHelper.h"

vmsHttpHelper::vmsHttpHelper()
{

}

vmsHttpHelper::~vmsHttpHelper()
{

}

void vmsHttpHelper::ExtractUrlValues(LPCSTR pszUrl, vector <string> *pvValNames, vector <string> *pvValues)
{
	if (pvValNames)
		pvValNames->clear ();
	if (pvValues)
		pvValues->clear ();

	LPCSTR psz = strstr (pszUrl, "://");
	if (!psz)
		return;

	psz = strchr (psz+3, '/');
	if (!psz)
		return;

	psz = strchr (psz+1, '?');
	if (!psz)
		return;

	psz++;

	while (*psz)
	{
		string strValName;
		string strValue;

		while (*psz && *psz != '=')
			strValName += *psz++;
		if (*psz++ == 0)
			return;

		while (*psz && *psz != '&')
			strValue += *psz++;

		if (*psz)
			psz++;

		if (!strValName.empty ())
		{
			if (pvValNames)
				pvValNames->push_back (strValName);
			if (pvValues)
				pvValues->push_back (strValue);
		}
	}
}

string vmsHttpHelper::ExtractFileName(LPCSTR pszUrl)
{
	string strPath = ExtractPath (pszUrl);
	LPCSTR psz = strrchr (strPath.c_str (), '/');
	assert (psz != NULL);
	if (!psz)
		return "";
	return psz+1;
}

string vmsHttpHelper::ExtractPathWithoutFileName(LPCSTR pszUrl)
{
	string strPath = ExtractPath (pszUrl);
	LPSTR psz = const_cast<LPSTR>(strrchr (strPath.c_str (), '/'));
	assert (psz != NULL);
	if (!psz)
		return "";
	strPath [psz-strPath.c_str ()] = 0;	
	return strPath;
}

string vmsHttpHelper::ExtractPath(LPCSTR pszUrl)
{
	pszUrl = strstr (pszUrl, "://");
	if (!pszUrl)
	{
		assert (false);
		return "";
	}

	pszUrl += 3;
	pszUrl = strchr (pszUrl, '/');

	assert (pszUrl != NULL);
	if (!pszUrl)
		return "";

	LPCSTR psz1 = strchr (pszUrl, '?');
	LPCSTR psz2 = strchr (pszUrl, '#');

	LPCSTR pszEnd = pszUrl + strlen (pszUrl);
	if (psz1)
		pszEnd = psz1;
	if (psz2 && pszEnd > psz2)
		pszEnd = psz2;

	string strPath;
	strPath.assign (pszUrl, pszEnd-pszUrl);
	return strPath;
}

void vmsHttpHelper::DecodeUrl(LPCSTR pszUrl, string &strRes)
{
	strRes = "";
	
	assert (pszUrl != NULL);
	if (pszUrl == NULL)
		return;
	
	while (*pszUrl)
	{
		if (*pszUrl != '%')
		{
			strRes += *pszUrl++;
		}
		else
		{
			char sz [3];
			sz [0] = *++pszUrl;
			assert (sz [0] != 0);
			if (sz [0] == 0)
				return;
			sz [1] = *++pszUrl;
			pszUrl++;
			assert (sz [1] != 0);
			if (sz [1] == 0)
				return;
			sz [2] = 0;
			int i = 0;
			sscanf (sz, "%x", &i);
			assert (i != 0);
			if (i == 0)
				return;
			strRes += (char)i;
		}
	}
}

void vmsHttpHelper::ExtractHostName(LPCSTR pszUrl, string &strHost)
{
	strHost = "";
	LPCSTR psz = strstr (pszUrl, "://");
	if (!psz)
		psz = strstr (pszUrl, ":\\\\");
	if (!psz)
		return;
	psz += 3;
	while (*psz && *psz != '/' && *psz != '\\')
		strHost += *psz++;
}
