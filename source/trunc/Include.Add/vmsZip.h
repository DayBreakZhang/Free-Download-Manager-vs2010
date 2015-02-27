/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSZIP_H__59620159_BC04_4875_BB68_8157CD79FCF7__INCLUDED_)
#define AFX_VMSZIP_H__59620159_BC04_4875_BB68_8157CD79FCF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "zip.h"

class vmsZip  
{
public:
	BOOL AddFile (LPCTSTR ptszFileName, LPCTSTR ptszName);
	BOOL AddBuffer (LPCVOID pData, DWORD dwDataSize, LPCTSTR ptszName);
	void CloseZipFile();
	BOOL CreateNewZipFile (LPCTSTR ptszFileName);
	vmsZip();
	virtual ~vmsZip();

protected:
	zipFile m_zip;

};

#endif 
