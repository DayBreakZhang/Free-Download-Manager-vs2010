/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsClipboardCatchMgr.h"
#include "fsIECatchMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

fsClipboardCatchMgr::fsClipboardCatchMgr()
{
	m_bEnabled  = FALSE;
}

fsClipboardCatchMgr::~fsClipboardCatchMgr()
{
}

BEGIN_MESSAGE_MAP(fsClipboardCatchMgr, CWnd)
	//{{AFX_MSG_MAP(fsClipboardCatchMgr)
	ON_WM_DRAWCLIPBOARD()
	ON_WM_CHANGECBCHAIN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL fsClipboardCatchMgr::Create(CWnd *pParent)
{
	CRect rc (0, 0, 0, 0);
	if (FALSE == CWnd::Create (NULL, NULL, WS_CHILD, rc, pParent, 0x129978))
		return FALSE;

	ShowWindow (SW_HIDE);

	return TRUE;
}

void fsClipboardCatchMgr::Enable(BOOL bEnable)
{
	

	if (bEnable)
	{
		if (m_bEnabled == FALSE)
		{
			m_hNextViewer = SetClipboardViewer ();
			m_bEnabled = TRUE;
		}
	}
	else
	{
		if (m_bEnabled)
		{
			ChangeClipboardChain (m_hNextViewer);
			m_bEnabled = FALSE;
		}
	}
}

void fsClipboardCatchMgr::OnDrawClipboard() 
{
	LPCSTR pszUrl = _ClipbrdMgr.Text ();

	if (pszUrl)
	{
		
		if (lstrlen (pszUrl) > 3 && pszUrl [1] != ':' && pszUrl [2] != ':')
		if (m_strLastUrl != pszUrl)
		{
			m_strLastUrl = pszUrl;
			if (m_pIEMgr->OnBeforeNavigate (pszUrl, FALSE) == FALSE)
				return;
		}
	}

	if (IsWindow (m_hNextViewer))
		::PostMessage (m_hNextViewer, WM_DRAWCLIPBOARD, 0, 0);
}

void fsClipboardCatchMgr::OnChangeCbChain(HWND hWndRemove, HWND hWndAfter) 
{
	if (m_hNextViewer == hWndRemove)
		m_hNextViewer = hWndAfter;
	else if (IsWindow (m_hNextViewer))
		::PostMessage (m_hNextViewer, WM_CHANGECBCHAIN, WPARAM (hWndRemove), LPARAM (hWndAfter));
}

BOOL fsClipboardCatchMgr::IsEnabled()
{
	return m_bEnabled;
}

void fsClipboardCatchMgr::Initialize(fsIECatchMgr *iemgr)
{
	m_pIEMgr = iemgr;
}
