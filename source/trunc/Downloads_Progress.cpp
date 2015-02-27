/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Downloads_Progress.h"
#include "DownloadsWnd.h"
#include "fsDownloadMgr.h"
#include "fsInternetDownloader.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloads_Progress::CDownloads_Progress()
{
	m_pActiveDownload = NULL;

	m_hevShutdown = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_hevDraw = CreateEvent (NULL, TRUE, FALSE, NULL);
	
	DWORD dw;
	m_hthDrawProgress = CreateThread (NULL, 0, _threadDrawProgress, this, 0, &dw);

	m_iLastProgress = -1;
	m_bRepaintBitmap = false;
}

CDownloads_Progress::~CDownloads_Progress()
{
	SetEvent (m_hevShutdown);
	WaitForSingleObject (m_hthDrawProgress, INFINITE);
	CloseHandle (m_hthDrawProgress);
	CloseHandle (m_hevDraw);
	CloseHandle (m_hevShutdown);
}

BEGIN_MESSAGE_MAP(CDownloads_Progress, CWnd)
	//{{AFX_MSG_MAP(CDownloads_Progress)
	ON_WM_PAINT()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloads_Progress::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, LoadCursor (NULL, IDC_ARROW), (HBRUSH) (COLOR_WINDOW+1), NULL) ,
			NULL, WS_CHILD, rc, pParent, 0x121))
		return FALSE;

	m_brProgress.CreateSolidBrush (RGB (255, 255, 255));
	m_brDone.CreateSolidBrush (RGB (158, 208, 235));
	m_penQ.CreatePen (PS_SOLID, 1, RGB (0, 115, 170));

	return TRUE;
}

void CDownloads_Progress::OnPaint() 
{
	CPaintDC dc(this); 

	SetEvent (m_hevDraw);
}

void CDownloads_Progress::DrawProgress(CDC *dc, vmsDownloadSmartPtr dld)
{
	if (dld == NULL) 
		return;

	if (IsWindowVisible () == FALSE)
		return;

	UINT64 uFileSize = dld->pMgr->GetLDFileSize ();
	
	if (uFileSize == 0 || uFileSize == _UI64_MAX)
		return;

	CDC dcDraw;
	dcDraw.CreateCompatibleDC (dc);
	CBitmap *pbmdOld;

	if (m_iLastProgress != (int)(dld->pMgr->GetPercentDone () * 10) || m_bmpProgress.m_hObject == NULL ||
			m_bRepaintBitmap)
	{
		if (m_bmpProgress.m_hObject)
			m_bmpProgress.DeleteObject ();
		m_bRepaintBitmap = false;

		bool bDontUseAlreadyDraw = dld->pMgr->IsBittorrent () != FALSE;

		
		std::vector <vmsSectionInfo> v;
		dld->pMgr->GetSplittedSectionsList (v);

		m_bmpProgress.CreateCompatibleBitmap (dc, m_size.cx, m_size.cy);
		pbmdOld = dcDraw.SelectObject (&m_bmpProgress);

		dcDraw.FillSolidRect (0, 0, m_size.cx, m_size.cy, GetSysColor (COLOR_WINDOW));

		for (size_t i = 0; i < v.size (); i++)
			DrawSectionProgress (&dcDraw, &v[i], i, uFileSize, bDontUseAlreadyDraw);

		m_iLastProgress = (int)(dld->pMgr->GetPercentDone () * 10);
	}
	else
	{
		pbmdOld = dcDraw.SelectObject (&m_bmpProgress);		
	}

	dc->BitBlt (0, 0, m_size.cx, m_size.cy, &dcDraw, 0, 0, SRCCOPY);

	dcDraw.SelectObject (pbmdOld);
	dcDraw.DeleteDC ();
}

void CDownloads_Progress::SetActiveDownload(vmsDownloadSmartPtr dld)
{
	m_pActiveDownload = dld;
	set_FullRedraw ();
	Invalidate ();
}

void CDownloads_Progress::OnSize(UINT , int cx, int cy) 
{
	m_size.cx = cx;
	m_size.cy = cy;
	set_FullRedraw ();
	Invalidate (TRUE);
}

void CDownloads_Progress::DrawSectionProgress(CDC *dc, vmsSectionInfo *sect, int iSect, UINT64 uFileSize, bool bDontUseAlreadyDraw)
{
	const int sqDimX = 6;  
	const int sqDimY = 6;  
	const int sqDist = 1; 

	int csqx = (m_size.cx - sqDist) / (sqDimX + sqDist);	
	int csqy = (m_size.cy - sqDist) / (sqDimY + sqDist);	
	int csq = csqx * csqy;					

	double nsqs = double ((INT64)sect->uDStart) / (INT64)uFileSize * csq; 
	double nsqe = double ((INT64)sect->uDEnd) / (INT64)uFileSize * csq;  
	double nsqc = double ((INT64)sect->uDCurrent) / (INT64)uFileSize * csq;  

	int xStart = sqDist;	
	int yStart = sqDist;	

	CBrush* brold = dc->SelectObject (&m_brDone);
	CPen *penold = dc->SelectObject (&m_penQ);

	for (int i = 0; i < nsqe; i++)
	{
		if (i >= nsqs)	
		{
			if (i >= nsqc)
				dc->SelectObject (&m_brProgress);

			dc->Rectangle (xStart, yStart, xStart + sqDimX, yStart + sqDimY);
		}
		
		
		xStart += sqDimX + sqDist;
		if (xStart + sqDimX + sqDist >= m_size.cx)
		{
			
			xStart = sqDist;
			yStart += sqDimY + sqDist;
		}
	}

	dc->SelectObject (brold);
	dc->SelectObject (penold);
}

vmsDownloadSmartPtr CDownloads_Progress::GetActiveDownload()
{
	return m_pActiveDownload;
}

void CDownloads_Progress::UpdateDownload()
{
	SetEvent (m_hevDraw);
}

void CDownloads_Progress::set_FullRedraw()
{
	m_bRepaintBitmap = true;
}

DWORD WINAPI CDownloads_Progress::_threadDrawProgress(LPVOID lp)
{
	CDownloads_Progress *pthis = (CDownloads_Progress*) lp;

	SetThreadPriority (GetCurrentThread (), THREAD_PRIORITY_IDLE);

	HANDLE phEvs [] = {pthis->m_hevDraw, pthis->m_hevShutdown};

	while (WAIT_OBJECT_0 == WaitForMultipleObjects (2, phEvs, FALSE, INFINITE))
	{
		ResetEvent (pthis->m_hevDraw);
		vmsDownloadSmartPtr dld = pthis->m_pActiveDownload;
		if (dld != NULL)
		{
			CDC *dc = pthis->GetDC ();
			pthis->DrawProgress (dc, dld);
			pthis->ReleaseDC (dc);
		}
	}

	return 0;
}
