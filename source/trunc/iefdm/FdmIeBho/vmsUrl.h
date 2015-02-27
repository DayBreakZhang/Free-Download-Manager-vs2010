/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSURL_H__CABECE07_A6B4_4F1F_8774_7749376481B7__INCLUDED_)
#define AFX_VMSURL_H__CABECE07_A6B4_4F1F_8774_7749376481B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsUrl  
{
public:
	static LPCSTR GetFileNamePartStart (LPCSTR pszUrl);
	static void GetScheme (LPCSTR pszUrl, string &strResult);
	static void GetAbsoluteUrlFromRelative (LPCSTR pszUrlPath, LPCSTR pszRelUrl, string &strResult);
	static void GetAbsoluteUrlFromRelative2 (LPCSTR pszWebPageUrl, LPCSTR pszRelUrl, string &strResult);
	static LPCSTR GetFilePathStart (LPCSTR pszUrl);
	static bool isAbsolute (LPCSTR pszUrl);
	vmsUrl();
	virtual ~vmsUrl();

};

#endif 
