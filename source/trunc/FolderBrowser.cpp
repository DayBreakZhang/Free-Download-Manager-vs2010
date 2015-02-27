/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FolderBrowser.h"
#include "AlsFolderBrowser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CFolderBrowser, CWinThread)

CFolderBrowser::CFolderBrowser()
{
}

CFolderBrowser::~CFolderBrowser()
{
}

BOOL CFolderBrowser::InitInstance()
{
	AfxOleInit ();

	AlsFolderBrowser fb;
	m_bResult = fb.Create (m_pszTitle, m_pszPath, m_pszRoot, m_hWndParent);

	if (m_bResult)
		m_strResPath = fb.GetPath ();
	
	return FALSE;
}

int CFolderBrowser::ExitInstance()
{
	
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CFolderBrowser, CWinThread)
	//{{AFX_MSG_MAP(CFolderBrowser)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CFolderBrowser* CFolderBrowser::Create(LPCSTR pszTitle, LPCSTR pszPath, LPCSTR pszRoot, CWnd *pWndParent)
{
	CFolderBrowser* pThis = (CFolderBrowser*) RUNTIME_CLASS (CFolderBrowser)->CreateObject ();
	pThis->m_bAutoDelete = FALSE;

	pThis->m_pszTitle = pszTitle;
	pThis->m_pszPath = pszPath;
	pThis->m_pszRoot = pszRoot;
	pThis->m_hWndParent = pWndParent ? pWndParent->m_hWnd : NULL;

	pThis->CreateThread ();
	
	HANDLE hThread;
	DuplicateHandle (GetCurrentProcess (), pThis->m_hThread, GetCurrentProcess (),
		&hThread, 0, TRUE, DUPLICATE_SAME_ACCESS);

	DWORD dw = 0;
	do 
	{
		Sleep (10);
		
		MSG msg;
		while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);

		GetExitCodeThread (hThread, &dw);
	}
	while (dw == STILL_ACTIVE);

	CloseHandle (hThread);

	if (pThis->m_bResult)
		return pThis;
	
	delete pThis;
	return NULL;
}

LPCSTR CFolderBrowser::GetPath()
{
	return m_strResPath;
}
