/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_InfoFrame.h"
#include "DownloadsWnd.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_InfoFrame::CDownloads_InfoFrame()
{
	m_pChild = NULL;
}

CDownloads_InfoFrame::~CDownloads_InfoFrame()
{
}

BEGIN_MESSAGE_MAP(CDownloads_InfoFrame, CWnd)
	//{{AFX_MSG_MAP(CDownloads_InfoFrame)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_InfoFrame::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW),
			(HBRUSH)(COLOR_3DFACE+1), NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x121f))
		return FALSE;

	return TRUE;
}

void CDownloads_InfoFrame::OnPaint() 
{
	CPaintDC dc(this); 

	
	
	CRect rc;
	GetClientRect (&rc);

	CPen penLight (PS_SOLID, 1, GetSysColor (COLOR_3DHILIGHT));
	CPen penShadow (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));

	CPen *oldPen = dc.SelectObject (&penLight);

	

	dc.SelectObject (oldPen);
}

void CDownloads_InfoFrame::SetChildWnd(CWnd *pWnd)
{
	m_pChild = pWnd;

	CRect rc;
	GetClientRect (&rc);
	ResizeChild (rc.right, rc.bottom);
}

void CDownloads_InfoFrame::OnSize(UINT, int cx, int cy) 
{
	if (m_pChild)
		ResizeChild (cx, cy);
}

void CDownloads_InfoFrame::ResizeChild(int cx, int cy)
{
	if (cx > 5 && cy > 4)
		m_pChild->MoveWindow (3, 3, cx - 5, cy - 4);
}

BOOL CDownloads_InfoFrame::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (_pwndDownloads->m_wndDownloads.m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		_pwndDownloads->m_wndDownloads.m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CWnd::OnEraseBkgnd(pDC);
}
