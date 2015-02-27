/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSVISTAFX_H__59A7830E_FDB1_455B_BC8C_63DD07A81E0E__INCLUDED_)
#define AFX_VMSVISTAFX_H__59A7830E_FDB1_455B_BC8C_63DD07A81E0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsVistaFx  
{
public:
	static BOOL IsWow64();
	static BOOL RunNonElevated (LPCSTR pszPath, LPCSTR pszParameters, LPCSTR pszDirectory);
	static BOOL IsElevated();
	vmsVistaFx();
	virtual ~vmsVistaFx();

protected:
	static LRESULT CALLBACK _HookProc (int code, WPARAM wp, LPARAM lp);
};

#endif 
