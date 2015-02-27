/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "FdmBalloon_OnDownloadDone.h"
#include "FdmBalloon.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFdmBalloon_OnDownloadDone::CFdmBalloon_OnDownloadDone()
{
	CFont *pFont = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));
	LOGFONT lf;
	pFont->GetLogFont (&lf);
	lf.lfUnderline = TRUE;
	m_fntUnderline.CreateFontIndirect (&lf);
}

CFdmBalloon_OnDownloadDone::~CFdmBalloon_OnDownloadDone()
{
}

BEGIN_MESSAGE_MAP(CFdmBalloon_OnDownloadDone, CFdmBalloonContent)
	//{{AFX_MSG_MAP(CFdmBalloon_OnDownloadDone)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CFdmBalloon_OnDownloadDone::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFdmBalloonContent::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	
	return 0;
}

CSize CFdmBalloon_OnDownloadDone::getRequiredSize()
{
	CDC *pdc = GetDC ();

	CFont *pFont = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));
	pdc->SelectObject (pFont);

	CString strDone; strDone.Format (" - %s", LS (L_DONE));
	CSize sDone = pdc->GetTextExtent (strDone);

	pdc->SelectObject (&m_fntUnderline);

	CSize s (0, 0);

	for (size_t i = 0; i < m_vItems.size (); i++)
	{
		CSize s2 = pdc->GetTextExtent (m_vItems [i].strName);
		s.cy += s2.cy + 3;
		s.cx = max (s.cx, s2.cx);
	}

	ReleaseDC (pdc);

	m_cxDone = sDone.cx;
	s.cx += 3 + m_cxDone + 3;
	s.cy += 8;

	return s;
}

void CFdmBalloon_OnDownloadDone::OnPaint() 
{
	CPaintDC dc(this); 

	dc.SetBkMode (TRANSPARENT);

	CFont *pFont = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));

	int y = 7;

	CString strDone; strDone.Format (" - %s", LS (L_DONE));

	for (size_t i = 0; i < m_vItems.size (); i++)
	{
		const DownloadedItem &item = m_vItems [i];

		dc.SelectObject (&m_fntUnderline);

		CSize s = dc.GetTextExtent (item.strName);

		CRect rc (3, y, 10+s.cx, y+s.cy);

		if (m_vLinksPos.size () < m_vItems.size ())
		{
			m_vLinksPos.push_back (rc);
			m_vWasLaunched.push_back (false);
		}

		dc.SetTextColor (GetSysColor (26));
		dc.DrawText (item.strName, &rc, DT_LEFT);

		dc.SelectObject (pFont);
		dc.SetTextColor (GetSysColor (COLOR_WINDOWTEXT));
		rc.left += s.cx + 3; rc.right = rc.left + m_cxDone;
		dc.DrawText (strDone, &rc, DT_LEFT);

		y += s.cy + 3;
	}
}

BOOL CFdmBalloon_OnDownloadDone::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	int nIndex = FindLinkIndexUnderCursor ();
	
	if (nIndex != -1)
	{
		
		SetCursor (LoadCursor (AfxGetResourceHandle (), MAKEINTRESOURCE (IDC_HAND_)));
		return TRUE;
	}
	
	return CFdmBalloonContent::OnSetCursor(pWnd, nHitTest, message);
}

void CFdmBalloon_OnDownloadDone::OnLButtonDown(UINT nFlags, CPoint point) 
{
	int nIndex = FindLinkIndexUnderCursor ();
	if (nIndex != -1)
	{
		ShellExecute (NULL, "open", m_vItems [nIndex].strFile, NULL, NULL, SW_SHOW);
		m_vWasLaunched [nIndex] = true;
	}
	bool bClose = nIndex == -1;
	if (bClose == false)
	{
		bClose = true;
		for (size_t i = 0; i < m_vWasLaunched.size (); i++)
		{
			if (m_vWasLaunched [i] == false)
			{
				bClose = false;
				break;
			}
		}
	}
	if (bClose)
		((CFdmBalloon*)GetParent ()->GetParent ())->CloseBalloon (true);
	
}

int CFdmBalloon_OnDownloadDone::FindLinkIndexUnderCursor()
{
	CPoint pt; GetCursorPos (&pt);
	ScreenToClient (&pt);
	
	for (size_t i = 0; i < m_vLinksPos.size (); i++)
	{
		if (PtInRect (&m_vLinksPos [i], pt))
			return i;
	}

	return -1;
}
