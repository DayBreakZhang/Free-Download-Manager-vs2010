/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_)
#define AFX_STDAFX_H__A9DB83DB_A9FD_11D0_BFD1_444553540000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define WIN32_LEAN_AND_MEAN		

#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
using namespace std;

#if !defined (UNICODE) && !defined (_UNICODE)
#define tstring string
#else 
#define tstring wstring
#endif

//{{AFX_INSERT_LOCATION}}

#endif 
