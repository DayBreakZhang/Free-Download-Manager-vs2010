/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMS7ZIPFORMATDLL_H__088B0073_2E34_4ABB_B1B2_76A6276ED383__INCLUDED_)
#define AFX_VMS7ZIPFORMATDLL_H__088B0073_2E34_4ABB_B1B2_76A6276ED383__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vms7zipFormatDLL  
{
public:
	
	HRESULT get_GUID (GUID* guid);
	
	
	bool IsSupportedArchive(LPCSTR pszArchive);
	
	HRESULT GetHandlerProperty(PROPID propID, PROPVARIANT *value);
	
	HRESULT CreateObject(const GUID *classID, const GUID *interfaceID, void **outObject);
	
	void Free();
	
	bool Load (LPCSTR pszDll);

	vms7zipFormatDLL(LPCSTR pszDll = NULL);
	virtual ~vms7zipFormatDLL();

protected:
	typedef HRESULT (STDAPICALLTYPE *FNCreateObject)(const GUID *classID, const GUID *interfaceID, void **outObject);
	typedef HRESULT (STDAPICALLTYPE *FNGetHandlerProperty)(PROPID propID, PROPVARIANT *value);
	FNCreateObject m_pfnCreateObject;
	FNGetHandlerProperty m_pfnGetHandlerProperty;
	HMODULE m_hDll;
};

#endif 
