/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSURLMONSPYDLL_H__895BE550_571B_4ACC_A279_4CB2B962AB3B__INCLUDED_)
#define AFX_VMSURLMONSPYDLL_H__895BE550_571B_4ACC_A279_4CB2B962AB3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "../iefdm/UrlMonSpy/vmsUrlMonRequest.h"

class vmsUrlMonSpyDll  
{
public:
	static void CheckDllLoaded ();
	static void MakeSureDllLoaded();
	static vmsUrlMonRequestPtr FindRequest (LPCWSTR pwszUrl, LPBYTE pbPostData, DWORD dwPostDataSize, bool bInProgressOnly);
	vmsUrlMonSpyDll();
	virtual ~vmsUrlMonSpyDll();

protected:
	static HMODULE m_hDll;

};

#endif 
