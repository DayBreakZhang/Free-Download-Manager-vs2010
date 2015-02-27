/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#ifndef tstring

#include <string>

#if defined (UNICODE) || defined (_UNICODE)
#define tstring std::wstring
#else
#define tstring std::string
#endif

#endif 

#ifndef tstringstream

#include <sstream>

#if defined (UNICODE) || defined (_UNICODE)
#define tstringstream std::wstringstream
#else
#define tstringstream std::stringstream
#endif

inline std::string _t2utf8 (LPCTSTR ptsz)
{
	std::string strResult;
#if defined (UNICODE) || defined (_UNICODE)
	int iLen = WideCharToMultiByte (CP_UTF8, 0, ptsz, -1, NULL, 0, NULL, NULL);
	if (!iLen)
		return strResult;
	strResult.resize (iLen);
	WideCharToMultiByte (CP_UTF8, 0, ptsz, -1, &strResult [0], strResult.size (), NULL, NULL);
#else
	int iLen = MultiByteToWideChar (CP_ACP, 0, ptsz, -1, NULL, 0);
	if (!iLen)
		return strResult;
	std::wstring wstr;
	wstr.resize (iLen);
	MultiByteToWideChar (CP_ACP, 0, ptsz, -1, &wstr [0], wstr.size ());
	iLen = WideCharToMultiByte (CP_UTF8, 0, wstr.c_str (), -1, NULL, 0, NULL, NULL);
	if (!iLen)
		return strResult;
	strResult.resize (iLen);
	WideCharToMultiByte (CP_UTF8, 0, wstr.c_str (), -1, &strResult [0], strResult.size (), NULL, NULL);
#endif
	return strResult;
}

#endif 
