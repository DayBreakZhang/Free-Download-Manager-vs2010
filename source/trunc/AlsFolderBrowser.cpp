/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "AlsFolderBrowser.h"
#include <tchar.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

AlsFolderBrowser::AlsFolderBrowser()
{

}

AlsFolderBrowser::~AlsFolderBrowser()
{

}

LPCTSTR AlsFolderBrowser::GetPath()
{
	return m_pszFullPath;
}

INT CALLBACK AlsFolderBrowser::_BrowserCallback(HWND hWnd, UINT uMsg, LPARAM lp, LPARAM lpData)
{
	

	switch (uMsg)
	{
		case BFFM_INITIALIZED:
			if (lpData)
				SendMessage (hWnd, BFFM_SETSELECTION, TRUE, lpData);
		break;

		case BFFM_SELCHANGED:
			
		break;
	}

	return 0;
}

BOOL AlsFolderBrowser::Create(LPCTSTR pszTitle, LPCTSTR pszPath, LPCTSTR pszRoot, HWND hWndParent)
{
	LPMALLOC pMalloc;
	BOOL bResult = FALSE;

	if (SHGetMalloc (&pMalloc) != NOERROR)
		return FALSE;

	BROWSEINFO bi;
	
	ZeroMemory (&bi, sizeof (bi));
	
	bi.ulFlags = BIF_RETURNONLYFSDIRS |  BIF_EDITBOX | BIF_VALIDATE | 0x40;
	bi.hwndOwner = hWndParent;
	bi.lpszTitle = pszTitle;
	bi.lpfn = _BrowserCallback;
	bi.lParam = (LPARAM) pszPath;

	if (pszRoot != NULL)
	{
		IShellFolder *pFolder;
		if (SHGetDesktopFolder (&pFolder) == NOERROR)
		{
			LPITEMIDLIST pIdl = NULL;
			ULONG chEaten;
			ULONG dwAttributes;

			wchar_t str [MAX_PATH];
			mbtowc (str, pszRoot, _tcslen (pszRoot));

			pFolder->ParseDisplayName (NULL, NULL, str, &chEaten, &pIdl, &dwAttributes);
			pFolder->Release ();

			bi.pidlRoot = pIdl;
		}
	}

	LPITEMIDLIST pIdl = SHBrowseForFolder (&bi);

	if (pIdl != NULL)
	{
		if (SHGetPathFromIDList (pIdl, m_pszFullPath))
			bResult = TRUE;

		pMalloc->Free (pIdl);
	}

	if (bi.pidlRoot)
		pMalloc->Free ((void*)bi.pidlRoot);

	pMalloc->Release ();

	return bResult;
}
