/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_STDAFX_H__A73A189F_8604_4566_8E09_83FF26E0900F__INCLUDED_)
#define AFX_STDAFX_H__A73A189F_8604_4566_8E09_83FF26E0900F__INCLUDED_

#define WINVER 0x501
#define _WIN32_WINNT 0x501

#if _MSC_VER > 1000
#pragma once
#endif 

#define VC_EXTRALEAN		

#include <afxwin.h>         
#include <afxext.h>         

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         
#include <afxodlgs.h>       
#include <afxdisp.h>        
#endif 

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>			
#endif 

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>			
#endif 

#include <afxdtctl.h>		
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			
#endif 

#pragma warning (push, 3)
#include <vector>
#include <list>
#include <string>
#include <xlocale>
#pragma warning (pop)

#include "vmsDllCaller.h"

extern vmsDllCaller *_pDllCaller;

#include "../../lngphrases.h"
#define LS(id) (_pDllCaller->GetTranslatedString (id))

//{{AFX_INSERT_LOCATION}}

#include "fsUploadsMgr.h"
#include "fsDialogsMgr.h"
#include "vmsAppSettings.h"
#include "vmsMfcLngHelper.h"

extern fsUploadsMgr _UplsMgr;
extern fsDialogsMgr _DlgMgr;
extern vmsAppSettings _App;

#endif 
