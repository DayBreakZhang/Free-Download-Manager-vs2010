/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__8CB5129C_A0AC_477C_91B0_EB13DFAC6784__INCLUDED_)
#define AFX_STDAFX_H__8CB5129C_A0AC_477C_91B0_EB13DFAC6784__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define WIN32_LEAN_AND_MEAN		

#define WINVER 0x501
#define _WIN32_IE 0x501
#define _WIN32_WINNT 0x501

#define FDM_DLDR__RAWCODEONLY
#define ASSERT(a)
#define DEBUG_NEW new
#define MY_MAX_PATH		10000
#define MAX_EXTS_LEN	1000

#include <vector>
#include <list>
#include <assert.h>
#include <intsafe.h> 

#define LS(s) ""
#define LOG(x)
#include <windows.h>
#include <..\inetfile\inetfile.h>
#include <fsString.h>
#include "../common.h"
#include "../dldscommon.h"
#include "../system.h"
#include <stdio.h>
#include <comdef.h>
#include <..\dldscommon.h>
#include <vmsCriticalSection.h>
#include <vmsReaderWriterLock.h>
#include <vmsObject.h>

#ifdef UNICODE
#define tstring std::wstring
#else
#define tstring std::string
#endif

typedef fsString CString;

//{{AFX_INSERT_LOCATION}}

#endif 
