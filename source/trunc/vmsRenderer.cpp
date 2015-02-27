/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsRenderer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsRenderer::vmsRenderer()
{

}

vmsRenderer::~vmsRenderer()
{

}

CDC* vmsRenderer::Start(CDC *dc, RECT *rc)
{
	m_dcDst = dc;
	m_rcDraw = *rc;
	m_dcDraw.CreateCompatibleDC (dc);
	m_bmDraw.CreateCompatibleBitmap (dc, m_rcDraw.right, m_rcDraw.bottom);
	m_hbmOld = SelectObject (m_dcDraw, m_bmDraw);
	return &m_dcDraw;
}

void vmsRenderer::End()
{
	m_dcDst->BitBlt (m_rcDraw.left, m_rcDraw.top, 
		m_rcDraw.Width (), m_rcDraw.Height (), 
		&m_dcDraw, m_rcDraw.left, m_rcDraw.top, SRCCOPY);

	SelectObject (m_dcDraw, m_hbmOld);
	m_bmDraw.DeleteObject ();
	m_dcDraw.DeleteDC ();
}
