/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__47BAA06B_F3FC_415D_9BFF_4633F8789428__INCLUDED_)
#define AFX_STDAFX_H__47BAA06B_F3FC_415D_9BFF_4633F8789428__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define STRICT
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif
#define _ATL_APARTMENT_THREADED

#define ISOLATION_AWARE_ENABLED			1

#include <atlbase.h>

extern CComModule _Module;
#include <atlcom.h>
#include <atlwin.h>

#include <comdef.h>

#include <string>
#include <vector>
using namespace std;
#include <assert.h>

#include <Mshtml.h>
#include <exdisp.h>

#include "vmsCriticalSection.h"
#include <windows.h>

//{{AFX_INSERT_LOCATION}}

#endif 
