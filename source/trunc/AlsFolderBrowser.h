/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __ALSFOLDERBROWSER_H_
#define __ALSFOLDERBROWSER_H_

#include <windows.h>
#include <shlobj.h>

class AlsFolderBrowser  
{
public:
	BOOL Create (LPCTSTR pszTitle, LPCTSTR pszPath, LPCTSTR pszRoot, HWND hWndParent);
	LPCTSTR GetPath ();
	AlsFolderBrowser();
	virtual ~AlsFolderBrowser();

protected:
	static INT CALLBACK _BrowserCallback (HWND hWnd, UINT uMsg, LPARAM lp, LPARAM lpData);
	TCHAR      m_pszFullPath [MAX_PATH];

};

#endif 
