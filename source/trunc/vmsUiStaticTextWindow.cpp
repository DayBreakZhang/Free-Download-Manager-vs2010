/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUiStaticTextWindow.h"
#include "vmsUiFonts.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsUiStaticTextWindow::vmsUiStaticTextWindow()
{
	m_pFont = NULL;
	m_uDrawTextFlags = 0;
}

vmsUiStaticTextWindow::~vmsUiStaticTextWindow()
{

}

void vmsUiStaticTextWindow::Draw(CDC *pdc)
{
	CFont *pfntOld = pdc->SelectObject (m_pFont ? m_pFont : vmsUiFonts::Tahoma_11 ());
	COLORREF clrOld = pdc->SetTextColor (m_clrText);
	pdc->SetBkMode (TRANSPARENT);
	CRect rc; getAbsolutePos (&rc);
	pdc->DrawText (m_tstrText.c_str (), &rc, m_uDrawTextFlags);
	pdc->SetTextColor (clrOld);
	pdc->SelectObject (pfntOld);
	
	vmsUiWindow::Draw (pdc);
}

void vmsUiStaticTextWindow::setText(LPCTSTR ptszText, CFont *pFont, COLORREF clrText, UINT uDrawTextFlags)
{
	m_tstrText = ptszText;
	m_pFont = pFont;
	m_clrText = clrText;
	m_uDrawTextFlags = uDrawTextFlags;
}

CSize vmsUiStaticTextWindow::getRequiredSize()
{
	CDC *pdc = getDC ();
	if (pdc)
	{
		CRect rc = m_rcPos;
		pdc->SelectObject (m_pFont);
		pdc->DrawText (m_tstrText.c_str (), &rc, DT_CALCRECT | m_uDrawTextFlags);
		releaseDC (pdc);
		return CSize (rc.Width (), rc.Height ());
	}

	return CSize (0,0);
}
