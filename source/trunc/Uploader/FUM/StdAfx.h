/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__1480F00C_7FAF_4FA2_A7CC_F59AFB48D5DB__INCLUDED_)
#define AFX_STDAFX_H__1480F00C_7FAF_4FA2_A7CC_F59AFB48D5DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

const int PRG_BUILD_NUMBER = 115;

const char* const PRG_NAME		= "Free Upload Manager";
const char* const PRG_FULL_NAME = "Free Upload Manager 1.0";

const char* const PRG_VERSION	= "1.0";

const char* const PRG_AGENT_NAME = "FUM 1.x";

#define VC_EXTRALEAN		

#include <afxwin.h>         
#include <afxext.h>         
#include <afxdisp.h>        
#include <afxdtctl.h>		
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			
#endif 

#include "../../lngphrases.h"
#include "fsMFCLangMgr.h"
#include "fsAppSettings.h"
#include "fsDialogsMgr.h"
#include "fsTrayIconMgr.h"
extern fsMFCLangMgr _LngMgr;
extern fsAppSettings _App;
extern fsDialogsMgr _DlgMgr;
extern fsTrayIconMgr _Tray;

#define _ATL_APARTMENT_THREADED
#include <atlbase.h>

class CFUMModule : public CComModule
{
public:
	LONG Unlock();
	LONG Lock();
	LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2);
	DWORD dwThreadID;
};
extern CFUMModule _Module;
#include <atlcom.h>

//{{AFX_INSERT_LOCATION}}

#endif 
