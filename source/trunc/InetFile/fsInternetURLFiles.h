/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETURLFILES_H__78826A95_6DE1_4BE1_AD42_A30F33A5FC9C__INCLUDED_)
#define AFX_FSINTERNETURLFILES_H__78826A95_6DE1_4BE1_AD42_A30F33A5FC9C__INCLUDED_

#include "fsHttpFiles.h"	
#include "fsFtpFiles.h"	
#include "fsinet.h"	
#include "fsInternetFiles.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsInternetUrlServer.h"
#include "fsHttpFiles.h"
#include "fsFtpFiles.h"

class fsInternetURLFiles  
{
public:
	
	fsInternetResult GetList (fsInternetURLServer *pServer, LPCSTR pszPath);
	void RetreiveInfoWhileGettingList (BOOL b);
	void SetHttpEventFunc (fntHttpFilesEventFunc pfn, LPVOID lpParam);
	LPCSTR GetCurrentPath();
	LPCSTR GetLastError();
	void Abort();
	fsFileInfo* GetFileInfo (UINT uIndex);
	UINT GetFileCount();
	fsInternetURLFiles();
	virtual ~fsInternetURLFiles();

protected:
	fsInternetFiles* m_pFiles;
	fsFtpFiles m_ftpFiles;
	fsHttpFiles m_httpFiles;
};

#endif 
