/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Wnd_DownloadProgress.h"
#include "fsDownloadsMgr.h"
#include "list.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CWnd_DownloadProgress::CWnd_DownloadProgress()
{
	m_hevShutdown = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_hevDraw = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_nCVPcurr = 0;
	
	DWORD dw;
	m_hthDraw = CreateThread (NULL, 0, _threadDraw, this, 0, &dw);

	m_iLastProgress = -1;
}

CWnd_DownloadProgress::~CWnd_DownloadProgress()
{
	SetEvent (m_hevShutdown);
	WaitForSingleObject (m_hthDraw, INFINITE);
	CloseHandle (m_hthDraw);
	CloseHandle (m_hevDraw);
	CloseHandle (m_hevShutdown);
}

BEGIN_MESSAGE_MAP(CWnd_DownloadProgress, CWnd)
	//{{AFX_MSG_MAP(CWnd_DownloadProgress)
	ON_WM_PAINT()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWnd_DownloadProgress::Create(CWnd *pwndParent)
{
	CWnd::CreateEx (_theme.IsThemeActive () ? 0 : WS_EX_STATICEDGE,
			AfxRegisterWndClass (0, NULL, NULL, NULL), 
			"", WS_CHILD|WS_VISIBLE,
			CRect (0, 0, 0, 0), pwndParent, 0);
}

void CWnd_DownloadProgress::OnPaint() 
{
	CPaintDC dc(this); 
	if (m_dld != NULL)
		SetEvent (m_hevDraw);
}

DWORD WINAPI CWnd_DownloadProgress::_threadDraw(LPVOID lp)
{
	CWnd_DownloadProgress *pthis = (CWnd_DownloadProgress*) lp;
	
	SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_IDLE);
	
	HANDLE phEvs [] = {pthis->m_hevDraw, pthis->m_hevShutdown};
	
	while (WAIT_OBJECT_0 == WaitForMultipleObjects (2, phEvs, FALSE, INFINITE))
	{
		ResetEvent (pthis->m_hevDraw);

		CDC *dc = pthis->GetDC ();
		if (!dc)
			continue;

		CDC dcDraw;
		dcDraw.CreateCompatibleDC (dc);
		CBitmap *pbmdOld;

		if (pthis->m_iLastProgress != (int)(pthis->m_dld->pMgr->GetPercentDone () * 10) || pthis->m_bmpProgress.m_hObject == NULL)
		{
			CRect rc; pthis->GetClientRect (&rc);
			static int nCVPWidth = rc.Width () / 4;
			static int nCVPStep = nCVPWidth / 2;

			if (pthis->m_bmpProgress.m_hObject)
				pthis->m_bmpProgress.DeleteObject ();

			pthis->m_bmpProgress.CreateCompatibleBitmap (dc, rc.Width (), rc.Height ());
			pbmdOld = dcDraw.SelectObject (&pthis->m_bmpProgress);	
		
			UINT64 uSize = pthis->m_dld->pMgr->GetLDFileSize ();
			COLORREF clr = GetSysColor (COLOR_HIGHLIGHT);
		
			HTHEME hTheme = NULL;
			int nSepW = 0; 
			if (_theme.IsThemeActive ())
			{
				hTheme = _theme.OpenThemeData (pthis->m_hWnd, L"PROGRESS");
				if (hTheme)			
					nSepW = 3;
			}
		
			if (hTheme)
				_theme.DrawThemeBackground (hTheme, dcDraw.GetSafeHdc (), 1 , 0, &rc, NULL);
			else
				dcDraw.FillSolidRect (&rc, GetSysColor (COLOR_3DFACE));
		
			fs::list <CSize> vParts;	
		
			rc.top += nSepW;
			rc.bottom -= nSepW;
			rc.left += nSepW + (nSepW ? 1 : 0);
			rc.right -= nSepW;
		
			
			std::vector <vmsSectionInfo> v;
			pthis->m_dld->pMgr->GetSplittedSectionsList (v);
		
			size_t i = 0;
			for (i = 0; i < v.size (); i++)
			{
				vmsSectionInfo &sect = v [i];
			
				CSize part;
				if (-1 == pthis->m_dld->pMgr->GetPercentDone ())
				{
					part.cy = rc.left + pthis->m_nCVPcurr + nCVPWidth;
					part.cx = rc.left + pthis->m_nCVPcurr;
					pthis->m_nCVPcurr += nCVPStep;
					if (pthis->m_nCVPcurr > rc.Width ()) pthis->m_nCVPcurr = 0;
				}
				else
				{
					part.cy = rc.left + (int)((double)(INT64)sect.uDCurrent / (INT64)uSize * rc.Width ());
					part.cx = rc.left + (int)((double)(INT64)sect.uDStart / (INT64)uSize * rc.Width ());
				}
			
				if (part.cy == part.cx)
				{
					if (pthis->m_dld->pMgr->IsBittorrent ())
						continue;
					part.cy++; 
				}
			
				vParts.add (part);
			}
		
			
			for (i = 0; i < (size_t)vParts.size (); i++)
			{
				CSize& part = vParts [i];
			
				for (size_t j = i + 1; j < (size_t)vParts.size (); j++)
				{
					if (part.cy == vParts [j].cx)
					{
						part.cy = vParts [j].cy;
						vParts.del (j);
						i--;
						break;
					}
				
					if (part.cx == vParts [j].cy)
					{
						part.cx = vParts [j].cx;
						vParts.del (j);
						i--;
						break;
					}
				}
			}
		
			
		
			for (i = 0; i < (size_t)vParts.size (); i++)
			{
				CRect rc2 = rc;
			
				rc2.left = vParts [i].cx;
				rc2.right = vParts [i].cy;
			
				if (hTheme)
					_theme.DrawThemeBackground (hTheme, dcDraw.GetSafeHdc (), 3 , 0, &rc2, NULL);
				else
					dcDraw.FillSolidRect (&rc2, clr);
			}
		
			if (hTheme)
				_theme.CloseThemeData (hTheme);

			if (-1 != pthis->m_dld->pMgr->GetPercentDone ())
				pthis->m_iLastProgress = (int)(pthis->m_dld->pMgr->GetPercentDone () * 10);
		}
		else
		{
			pbmdOld = dcDraw.SelectObject (&pthis->m_bmpProgress);
		}

		if (IsWindow (pthis->m_hWnd))
		{
			CRect rc; pthis->GetClientRect (&rc);
			dc->BitBlt (0, 0, rc.Width (), rc.Height (), &dcDraw, 0, 0, SRCCOPY);
		}

		dcDraw.SelectObject (pbmdOld);
		dcDraw.DeleteDC ();
		
		pthis->ReleaseDC (dc);
	}
	
	return 0;
}

void CWnd_DownloadProgress::OnDestroy() 
{
	CWnd::OnDestroy();
	
	SetEvent (m_hevShutdown);
	WaitForSingleObject (m_hthDraw, INFINITE);
}

void CWnd_DownloadProgress::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	
	m_iLastProgress = -1;
	Invalidate (TRUE);
}
