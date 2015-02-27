/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "UrlWnd.h"
#include "resource.h"
#include "misc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void fsOpenUrlInBrowser (LPCSTR pszUrl)
{
	char szReg [100];
	char szBrowser [MAX_PATH];
	DWORD dwBrowserLen = MAX_PATH;

	

	if (strnicmp (pszUrl, "http", 4) == 0)
		strcpy (szReg, "http");
	else if (strnicmp (pszUrl, "https", 5) == 0)
		strcpy (szReg, "https");
	else
		strcpy (szReg, "ftp");

	strcat (szReg, "\\shell\\open\\command");

	HKEY hReg;

	if (ERROR_SUCCESS != RegOpenKeyEx (HKEY_CLASSES_ROOT, szReg, 0, KEY_QUERY_VALUE, &hReg))
		goto _lErr;

	if (ERROR_SUCCESS != RegQueryValueEx (hReg, NULL, NULL, NULL, (LPBYTE) szBrowser, &dwBrowserLen))
	{
		RegCloseKey (hReg);
		goto _lErr;
	}

	RegCloseKey (hReg);

	strlwr (szBrowser);
	LPSTR pszExe;
	pszExe = strstr (szBrowser, ".exe");

	if (pszExe == NULL)
		goto _lErr;

	pszExe [4] = 0;

	if (32 >= (int)ShellExecute (HWND_DESKTOP, "open", szBrowser [0] == '"' ? szBrowser+1 : szBrowser, pszUrl, NULL, SW_SHOW))
		goto _lErr;

	return;

_lErr:
	if (32 >= (int) ShellExecute (HWND_DESKTOP, "open", pszUrl, NULL, NULL, SW_SHOW))
		MessageBox (NULL, pszUrl, LS (L_ERROPENURL), MB_ICONERROR);
}

CUrlWnd::CUrlWnd()
{
}

CUrlWnd::~CUrlWnd()
{
}

BEGIN_MESSAGE_MAP(CUrlWnd, CStatic)
	//{{AFX_MSG_MAP(CUrlWnd)
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CUrlWnd::Init()
{
	SetClassLong (m_hWnd, GCL_HCURSOR, (LONG)LoadCursor (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDC_HAND_)));
	GetWindowText (m_strUrl);
}

void CUrlWnd::OnLButtonDown(UINT , CPoint )
{
	if (strnicmp (m_strUrl, "mailto:", 7))
		fsOpenUrlInBrowser (m_strUrl);
	else
		ShellExecute (::GetDesktopWindow (), "open", m_strUrl, NULL, NULL, SW_SHOW);
}

void CUrlWnd::SetUrl(LPCSTR pszUrl)
{
	m_strUrl = pszUrl;
}
