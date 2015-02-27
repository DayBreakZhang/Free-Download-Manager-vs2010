/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "FdmBalloon_Content.h"
#include "FdmBalloonContent.h"
#include "FdmBalloon.h"
#include "resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFdmBalloon_Content::CFdmBalloon_Content(CFdmBalloonContent* p) : m_pContent (p)
{
	ASSERT (p != NULL);
	CFont *pFont = CFont::FromHandle((HFONT)::GetStockObject(DEFAULT_GUI_FONT));
	LOGFONT lf;
	pFont->GetLogFont (&lf);
	lf.lfWeight = FW_BOLD;
	m_fntBold.CreateFontIndirect (&lf);
	m_strCaption = vmsFdmAppMgr::getAppName ();
}

CFdmBalloon_Content::~CFdmBalloon_Content()
{

}

BEGIN_MESSAGE_MAP(CFdmBalloon_Content, CMyBalloon_Content)
	//{{AFX_MSG_MAP(CFdmBalloon_Content)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CFdmBalloon_Content::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMyBalloon_Content::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_pContent->Create (this);
	
	return 0;
}

CSize CFdmBalloon_Content::getRequiredSize()
{
	CDC *pdc = GetDC ();
	pdc->SelectObject (&m_fntBold);
	CSize s = m_sCaption = pdc->GetTextExtent (m_strCaption);
	s.cx += 10+11 + 16+5 + 5 + 
		16;
	s.cy = max (s.cy, 4+16);
	CSize s2 = m_pContent->getRequiredSize ();
	s.cx = max (s.cx, s2.cx + 10);
	s.cy += 5+s2.cy;
	ReleaseDC (pdc);
	return s;
}

void CFdmBalloon_Content::OnPaint() 
{
	CPaintDC dc(this); 

	HICON hIco = LoadIcon (NULL, IDI_INFORMATION);
	DrawIconEx (dc, 10, 4, hIco, 16, 16, 0, NULL, DI_NORMAL);
	
	dc.SelectObject (m_fntBold);
	dc.SetBkMode (TRANSPARENT);
	int y = m_sCaption.cy < 16 ? (16 - m_sCaption.cy) / 2 : 0;
	CRect rc (16+10+10, 4+y, 0, 0);
	rc.right = rc.left + m_sCaption.cx;
	rc.bottom = rc.top + m_sCaption.cy;
	dc.DrawText (m_strCaption, &rc, DT_LEFT);

	hIco = LoadIcon (AfxGetResourceHandle (), MAKEINTRESOURCE (IDI_CLOSEBTN));
	GetClientRect (&rc);
	DrawIconEx (dc, rc.right-5-16, 4, hIco, 16, 16, 0, NULL, DI_NORMAL);
	
	
}

void CFdmBalloon_Content::OnSize(UINT nType, int cx, int cy) 
{
	CMyBalloon_Content::OnSize(nType, cx, cy);
	
	ASSERT (m_pContent != NULL);
	if (m_pContent->m_hWnd)
	{
		CSize s = m_pContent->getRequiredSize ();
		m_pContent->MoveWindow (10, 16+5, s.cx, s.cy);
	}	
}

void CFdmBalloon_Content::OnLButtonDown(UINT nFlags, CPoint point) 
{
	((CFdmBalloon*)GetParent ())->CloseBalloon (true);
	
	CMyBalloon_Content::OnLButtonDown(nFlags, point);
}
