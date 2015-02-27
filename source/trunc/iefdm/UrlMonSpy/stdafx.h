/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#define WIN32_LEAN_AND_MEAN             

#define _WIN32_IE _WIN32_IE_IE70

#include <windows.h>
#include <UrlMon.h>
#include <ObjBase.h>
#include <comdef.h>
#include <atlbase.h>
#include <assert.h>

_COM_SMARTPTR_TYPEDEF(IInternetProtocolEx, __uuidof(IInternetProtocolEx));
_COM_SMARTPTR_TYPEDEF(IUri, __uuidof(IUri));

#include <vector>
#include <string>
using namespace std;

#if defined (_UNICODE) || defined (UNICODE)
#define tstring std::wstring
#else 
#define tstring std::string
#endif

#include "vmsCriticalSection.h"

#ifdef _DEBUG
#define SCL_ENABLE
#endif

#include "../../Include.Add/vmsSourceCodeLogger.h"

