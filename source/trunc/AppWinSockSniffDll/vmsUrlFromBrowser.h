/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSURLFROMBROWSER_H__5D4D49E1_EDC1_4FF6_822A_104FDD8BB70D__INCLUDED_)
#define AFX_VMSURLFROMBROWSER_H__5D4D49E1_EDC1_4FF6_822A_104FDD8BB70D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsUrlFromBrowser  
{
public:
	enum CompareMethod
	{
		CM_JUST_COMPARE			= 1,
		CM_WO_ANCHOR			= 1 << 1,
		CM_DECODED				= 1 << 2,
		CM_DECODED_WO_ANCHOR	= 1 << 3,	
		CM_ALL					= 0xffffffff
	};
	struct FindEqualUrlData
	{
		LPCSTR pszUrlFromBrowser;
		string strUrlFromBrowserWoAnchor;

		FindEqualUrlData () {
			pszUrlFromBrowser = NULL;
		}
	};
public:
	static bool FindEqualUrl_isEqual (LPCSTR pszUrl, DWORD enCompareMethod, const FindEqualUrlData &data);
	static void FindEqualUrl_start (LPCSTR pszUrlFromBrowser, FindEqualUrlData &data);
	static bool isEqual (LPCSTR pszUrlFromBrowser, LPCSTR pszNetworkUrl, DWORD enCompareMethod = CM_ALL);
	vmsUrlFromBrowser();
	virtual ~vmsUrlFromBrowser();

};

#endif 
