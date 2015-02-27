/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUrlFromBrowser.h"
#include "vmsHttpHelper.h"

vmsUrlFromBrowser::vmsUrlFromBrowser()
{

}

vmsUrlFromBrowser::~vmsUrlFromBrowser()
{

}

bool vmsUrlFromBrowser::isEqual(LPCSTR pszUrlFromBrowser, LPCSTR pszNetworkUrl, DWORD enCM)
{
	assert (pszUrlFromBrowser && pszNetworkUrl);
	if (!pszNetworkUrl || !pszUrlFromBrowser)
		return false;
	FindEqualUrlData data;
	FindEqualUrl_start (pszUrlFromBrowser, data);
	return FindEqualUrl_isEqual (pszNetworkUrl, enCM, data);
}

void vmsUrlFromBrowser::FindEqualUrl_start(LPCSTR pszUrlFromBrowser, FindEqualUrlData &data)
{
	assert (pszUrlFromBrowser);
	if (!pszUrlFromBrowser)
		return;
	data.pszUrlFromBrowser = pszUrlFromBrowser;
	LPCSTR psz = strrchr (pszUrlFromBrowser, '#');
	if (psz)
		data.strUrlFromBrowserWoAnchor.assign (pszUrlFromBrowser, psz - pszUrlFromBrowser);
}

bool vmsUrlFromBrowser::FindEqualUrl_isEqual(LPCSTR pszUrl, DWORD enCM, const FindEqualUrlData &data)
{
	assert (pszUrl && data.pszUrlFromBrowser);
	if (!pszUrl || !data.pszUrlFromBrowser)
		return false;

	if (enCM & CM_JUST_COMPARE)
	{
		if (!strcmp (data.pszUrlFromBrowser, pszUrl))
			return true;
	}

	if (enCM & CM_WO_ANCHOR)
	{
		if (data.strUrlFromBrowserWoAnchor == pszUrl)
			return true;		
	}

	if (enCM & CM_DECODED)
	{
		string strUrl;
		vmsHttpHelper::DecodeUrl (pszUrl, strUrl);
		int cch = MultiByteToWideChar (CP_UTF8, 0, strUrl.c_str (), -1, NULL, 0);
		assert (cch != 0);
		LPWSTR pwsz = new wchar_t [cch+1];
		MultiByteToWideChar (CP_UTF8, 0, strUrl.c_str (), -1, pwsz, cch+1);
		cch = WideCharToMultiByte (CP_ACP, 0, pwsz, -1, NULL, 0, NULL, NULL);
		assert (cch != 0);
		LPSTR psz = new char [cch+1];
		WideCharToMultiByte (CP_ACP, 0, pwsz, -1, psz, cch+1, NULL, NULL);
		strUrl = psz;
		delete [] pwsz;
		delete [] psz;
		if (strUrl == data.pszUrlFromBrowser)
			return true;
		if ((enCM & CM_DECODED_WO_ANCHOR) && strUrl == data.strUrlFromBrowserWoAnchor)
			return true;
	}

	return false;
}
