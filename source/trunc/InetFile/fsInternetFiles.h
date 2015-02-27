/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETFILES_H__0E0074EB_2AD0_438E_A57C_4EFA0D8855E7__INCLUDED_)
#define AFX_FSINTERNETFILES_H__0E0074EB_2AD0_438E_A57C_4EFA0D8855E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include "../list.h"
#include <fsString.h>
#include "fsinet.h"	
#include "fsInternetSession.h"

struct fsFileInfo
{
	fsString strName;		
	UINT64 uSize;			
	FILETIME date;			
	BOOL bAvailable;		
	BOOL bFolder;			

	fsFileInfo ()
	{
		bFolder = FALSE;
		bAvailable = TRUE;
	}
};

class fsInternetFiles  
{
public:
	
	
	
	
	virtual fsInternetResult GetList (LPCSTR pszPath) = NULL;
	
	virtual void Abort () = NULL;
	
	UINT GetFileCount();
	
	
	LPCSTR GetCurrentPath();
	
	fsFileInfo* GetFileInfo (UINT uIndex);
	virtual LPCSTR GetLastError () = NULL;
	fsInternetFiles();
	virtual ~fsInternetFiles();

protected:
	fsString m_strPath;					
	fs::list <fsFileInfo> m_vFiles;		
};

#endif 
