/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__E337E97A_1D0F_4F8B_A2A7_FE9D6D5F1447__INCLUDED_)
#define AFX_STDAFX_H__E337E97A_1D0F_4F8B_A2A7_FE9D6D5F1447__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define WIN32_LEAN_AND_MEAN		

#include <windows.h>
#include <winsock2.h>
#include <wininet.h>
#include <tchar.h>
#include "detours.h"
#include <string>
#include <vector>
#include <process.h>
using namespace std;
#include <assert.h>

#if defined (UNICODE) || defined (_UNICODE)
 #define tstring wstring
#else
 #define tstring string
#endif

#include "common.h"

#ifdef _DEBUG
#define SCL_ENABLE
#define LOG_WEBFILES_TREE

#endif

#include "../Include.Add/vmsCriticalSection.h"
#include "../Include.Add/vmsSourceCodeLogger.h"
#include "vmsLogHelper.h"

//{{AFX_INSERT_LOCATION}}

#endif 
