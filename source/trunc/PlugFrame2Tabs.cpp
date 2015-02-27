/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "PlugFrame2Tabs.h"
#include "PluginFrame2.h"
#include "DownloadsWnd.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CPlugFrame2Tabs::CPlugFrame2Tabs()
{
}

CPlugFrame2Tabs::~CPlugFrame2Tabs()
{
}

BEGIN_MESSAGE_MAP(CPlugFrame2Tabs, CTabCtrl)
	//{{AFX_MSG_MAP(CPlugFrame2Tabs)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, OnSelchange)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPlugFrame2Tabs::Create(CWnd *pParent)
{
	CRect rc (50, 50, 275, 70);

	if (FALSE == CTabCtrl::Create (TCS_SINGLELINE|TCS_RIGHTJUSTIFY|TCS_FOCUSNEVER,
			rc, pParent, 0x5113))
		return FALSE;

	m_parent = (CPluginFrame2*) pParent;

	

	LOGFONT lf;
	NONCLIENTMETRICS nm;

	ZeroMemory (&nm, sizeof (nm));
	nm.cbSize = sizeof (nm);
	SystemParametersInfo (SPI_GETNONCLIENTMETRICS, nm.cbSize, &nm, 0);
	lf = nm.lfMenuFont;
	lf.lfCharSet = DEFAULT_CHARSET;

	m_itemsFont.CreateFontIndirect (&lf);

	SetFont (&m_itemsFont, FALSE);

	ShowWindow (SW_SHOW);

	return TRUE;
}

void CPlugFrame2Tabs::OnSelchange(NMHDR* , LRESULT* pResult) 
{
	m_parent->SetActivePlugin (GetCurSel ());	
	*pResult = 0;
}

BOOL CPlugFrame2Tabs::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (_pwndDownloads->m_wndDownloads.m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		_pwndDownloads->m_wndDownloads.m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CTabCtrl::OnEraseBkgnd(pDC);
}
