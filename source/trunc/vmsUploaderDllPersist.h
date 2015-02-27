/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUPLOADERDLLPERSIST_H__A3F75517_0BA7_4E82_8F79_BCBB3F87F7F3__INCLUDED_)
#define AFX_VMSUPLOADERDLLPERSIST_H__A3F75517_0BA7_4E82_8F79_BCBB3F87F7F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Uploader\CoreDll\dll.h"

class vmsUploaderDllPersist : public vmsUploadsDll::vmsDllPersist
{
public:
	BOOL GetProfileString (LPCSTR pszSecion, LPCSTR pszName, LPCSTR pszDefValue, LPSTR pszValue, DWORD *pdwValueSize);
	void WriteProfileString (LPCSTR pszSecion, LPCSTR pszName, LPCSTR pszValue);
	void WriteProfileInt(LPCSTR pszSection, LPCSTR pszName, UINT nValue);
	UINT GetProfileInt(LPCSTR pszSection, LPCSTR pszName, UINT nDefValue);
	void WriteProfileBinary (LPCSTR pszSection, LPCSTR pszName, LPVOID pvData, UINT nDataSize);
	BOOL GetProfileBinary (LPCSTR pszSecion, LPCSTR pszName, LPBYTE *ppData, UINT *pnDataSize);
	
	void FreeBuffer (LPBYTE pb);

	vmsUploaderDllPersist();
	virtual ~vmsUploaderDllPersist();

};

#endif 
