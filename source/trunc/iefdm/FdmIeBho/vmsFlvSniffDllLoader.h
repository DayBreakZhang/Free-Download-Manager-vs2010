/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFLVSNIFFDLLLOADER_H__C6B24525_8FCF_41B6_9311_C6099E03F453__INCLUDED_)
#define AFX_VMSFLVSNIFFDLLLOADER_H__C6B24525_8FCF_41B6_9311_C6099E03F453__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsFlvSniffDllLoader  
{
public:
	void MakeSureDllLoaded ();
	bool isDllEnabled () const;
	vmsFlvSniffDllLoader(DWORD dwBrowser);
	virtual ~vmsFlvSniffDllLoader();

protected:
	HANDLE m_hevDestroyObj;
	HANDLE m_htMonitorSettings;
	static DWORD WINAPI _threadMonitorSettings (LPVOID lp);
	HMODULE m_hDll;
	DWORD m_dwBrowser;
};

#endif 
