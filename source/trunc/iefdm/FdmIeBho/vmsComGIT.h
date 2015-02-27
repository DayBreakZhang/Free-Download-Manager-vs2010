/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSCOMGIT_H__FC2E4319_BB5D_4BEE_88E6_07188D380C04__INCLUDED_)
#define AFX_VMSCOMGIT_H__FC2E4319_BB5D_4BEE_88E6_07188D380C04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <objidl.h>
#include <comdef.h>

class vmsComGIT  
{
public:
	static HRESULT RegisterInterfaceInGlobal (IUnknown *pUnk, REFIID riid, DWORD *pdwCookie);
	static HRESULT GetInterfaceFromGlobal (DWORD dwCookie, REFIID riid, void **ppv);
	static HRESULT RevokeInterfaceFromGlobal (DWORD dwCookie);	

protected:
	vmsComGIT();
	virtual ~vmsComGIT();

protected:
	static HRESULT CreateGIT();
	static IGlobalInterfaceTablePtr m_spGIT;

};

#endif 
