/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Wnd_Banner.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IMGT_LOAD		1

#define IMGT_DRAW		2 

#define IMGT_EXIT		4

CWnd_Banner::CWnd_Banner()
{
	m_dwThrJob = 0;
	m_bRunning = FALSE;
}

CWnd_Banner::~CWnd_Banner()
{
	Shutdown ();
}

BEGIN_MESSAGE_MAP(CWnd_Banner, CWnd)
	//{{AFX_MSG_MAP(CWnd_Banner)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWnd_Banner::Create(CWnd *pWndParent, int cy)
{
	CWnd::Create (
			AfxRegisterWndClass (0, LoadCursor (AfxGetInstanceHandle (), 
					MAKEINTRESOURCE (IDC_HAND_)),
				(HBRUSH)(COLOR_3DFACE+1), NULL), 
			"", WS_CHILD|WS_VISIBLE,
			CRect (0, 0, 300, cy), pWndParent, 0);

	Initialize ();
	return TRUE;
}

void CWnd_Banner::OnPaint() 
{
	CPaintDC dc(this); 

	m_hDCNow = dc;
	m_dwThrJob |= IMGT_DRAW;
	while (m_dwThrJob & IMGT_DRAW)
		Sleep (10);
}

void CWnd_Banner::SetBanner(LPCSTR pszFile, LPCSTR pszURL)
{
	KillTimer (1);

	if (m_bRunning == FALSE)
		Initialize ();

	m_strImgFile = pszFile;
	m_strURL = pszURL;

	m_dwThrJob |= IMGT_LOAD;
	while (m_dwThrJob & IMGT_LOAD)
		Sleep (10);

	SetWindowPos (NULL, 0, 0, m_img.get_Size ().cx, m_img.get_Size ().cy, SWP_NOMOVE|SWP_NOZORDER);

	if (m_img.get_FrameCount ())
	{
		m_iCurrentFrame = 0;
		
		SetTimer (1, m_img.get_FrameDelay (0) * 10, NULL);
	}

	Invalidate ();
}

DWORD WINAPI CWnd_Banner::_threadImage(LPVOID lp)
{
	CoInitialize (NULL);
	CWnd_Banner* pThis = (CWnd_Banner*) lp;

	pThis->m_bRunning = TRUE;

	while ((pThis->m_dwThrJob & IMGT_EXIT) == 0)
	{
		
		if (pThis->m_dwThrJob & IMGT_LOAD)
		{
			pThis->m_img.Load (pThis->m_strImgFile);
			pThis->m_dwThrJob &= ~IMGT_LOAD;
		}

		
		if (pThis->m_dwThrJob & IMGT_DRAW)
		{
			if (pThis->m_img.is_Loaded ())
			{
				CRect rc;
				pThis->GetClientRect (&rc);
				CSize size = pThis->m_img.get_Size ();

				

				rc.bottom = size.cy;

				if (rc.Width () <= size.cx)
				{
					rc.right = size.cx;	
				}
				else
				{
					int w = (rc.Width () - size.cx) / 2;
					rc.left = w;
					rc.right = w + size.cx;
				}

				pThis->m_img.Draw (pThis->m_hDCNow, rc);
			}

			pThis->m_dwThrJob &= ~IMGT_DRAW;
		}

		Sleep (50);
	}

	pThis->m_img.Free ();

	pThis->m_bRunning = FALSE;
	pThis->m_dwThrJob &= ~IMGT_EXIT;

	CoUninitialize ();

	return 0;
}

void CWnd_Banner::OnLButtonDown(UINT nFlags, CPoint point) 
{
	
	CWnd::OnLButtonDown(nFlags, point);
}

void CWnd_Banner::Shutdown()
{
	if (m_bRunning)
	{
		m_dwThrJob = IMGT_EXIT;
		while (m_dwThrJob & IMGT_EXIT)
			Sleep (10);
	}
}

void CWnd_Banner::Initialize()
{
	if (m_bRunning == FALSE)
	{
		DWORD dw;
		m_bRunning = TRUE;
		CreateThread (NULL, 0, _threadImage, this, 0, &dw);
	}
}

void CWnd_Banner::OnTimer(UINT nIDEvent) 
{
	if (m_iCurrentFrame == m_img.get_FrameCount ())
		m_iCurrentFrame = 0;	

	
	KillTimer (1);
	SetTimer (1, m_img.get_FrameDelay (m_iCurrentFrame) * 10, NULL);

	m_img.set_CurrentFrame (m_iCurrentFrame++);

	CDC* dc = GetDC ();
	m_hDCNow = *dc;
	m_dwThrJob |= IMGT_DRAW;
	while (m_dwThrJob & IMGT_DRAW)
		Sleep (10);
	ReleaseDC (dc);
	
	CWnd::OnTimer(nIDEvent);
}

void CWnd_Banner::OnLButtonUp(UINT nFlags, CPoint point) 
{
	fsOpenUrlInBrowser (m_strURL);	
	CWnd::OnLButtonUp(nFlags, point);
}
