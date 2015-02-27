/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsClipboardMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsClipboardMgr::fsClipboardMgr()
{

}

fsClipboardMgr::~fsClipboardMgr()
{

}

void fsClipboardMgr::Initialize(HWND hWnd)
{
	m_hWnd = hWnd;
}

LPCSTR fsClipboardMgr::Text()
{
	if (FALSE == OpenClipboard (m_hWnd))
		return NULL;

	HANDLE hMem = GetClipboardData (CF_TEXT);

	if (hMem == NULL)
	{
		CloseClipboard ();
		return FALSE;
	}

	LPCSTR pszText = (LPCSTR) GlobalLock (hMem);
	m_strText = pszText;
	GlobalUnlock (hMem);

	CloseClipboard ();

	return m_strText;
}

BOOL fsClipboardMgr::Text(LPCSTR psz)
{
	if (FALSE == OpenClipboard (m_hWnd))
		return FALSE;

	EmptyClipboard ();

	HANDLE hText = GlobalAlloc (GMEM_MOVEABLE, strlen (psz)+1);
	if (hText == NULL)
	{
		CloseClipboard ();
		return FALSE;
	}

	LPSTR pszText = (LPSTR) GlobalLock (hText);
	strcpy (pszText, psz);
	GlobalUnlock (hText);

	SetClipboardData (CF_TEXT, hText);

	CloseClipboard ();

	return TRUE;
}
