/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__26AF3072_0185_4726_A622_751AE316A367__INCLUDED_)
#define AFX_STDAFX_H__26AF3072_0185_4726_A622_751AE316A367__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0501
#endif
#define _ATL_APARTMENT_THREADED

#define ISOLATION_AWARE_ENABLED 1

#define _CRT_SECURE_NO_DEPRECATE 1
#define _CRT_INSECURE_NO_DEPRECATE

#define MY_MAX_PATH		10000

#include <atlbase.h>

extern CComModule _Module;
#include <atlcom.h>
#include <atlwin.h>

#include <string>
#include <vector>
using namespace std;

#define assert ATLASSERT
#define LOGFN(a)

#if defined (UNICODE) || defined (_UNICODE)
	#define tstring wstring
#else
	#define tstring string
#endif

//{{AFX_INSERT_LOCATION}}

#endif 
