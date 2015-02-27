/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsImage_CtxFree.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsImage_CtxFree::vmsImage_CtxFree()
{

}

vmsImage_CtxFree::~vmsImage_CtxFree()
{
	Free ();
}

HRESULT vmsImage_CtxFree::Load(LPCSTR pszFile)
{	
	Free ();
		
	HRESULT hr = m_Image.Load (pszFile);
	if (FAILED (hr))
		return hr;

	CreateImagesBitmaps ();

	m_Image.Free ();
	return S_OK;
}

void vmsImage_CtxFree::CreateImagesBitmaps()
{
	COLORREF clrBk = GetSysColor (COLOR_3DFACE);
	
	m_vBitmaps.clear ();

	int cFrames = m_Image.get_FrameCount ();
	m_cFrames = cFrames;
	m_iCurrentFrame = 0;
	if (cFrames == 0)
		cFrames = 1;
	else
		m_Image.set_CurrentFrame (0);

	int i = 0;
	for (i = 0; i < cFrames; i++)
	{
		if (i)
			m_Image.set_CurrentFrame (i);

		HDC hdc = CreateDC ("DISPLAY", NULL, NULL, NULL);
		HDC hmem = CreateCompatibleDC (hdc);
		SIZE size = m_Image.get_Size ();
		HBITMAP hbm = CreateCompatibleBitmap (hdc, size.cx, size.cy);
		HBITMAP holdbm = (HBITMAP)SelectObject (hmem, hbm);
		RECT rc = {0, 0, size.cx, size.cy};

		if (i == 0 )
		{
			
			HBRUSH br = CreateSolidBrush (clrBk);
			FillRect (hmem, &rc, br);
			DeleteObject (br);
		}
		else
		{
			
			POINT pt = {0,0};
			DrawBitmap (hmem, i-1, pt);
		}

		m_Image.Draw (hmem, rc);

		SelectObject (hmem, holdbm);
		m_vBitmaps.push_back (hbm);
		m_vSizes.push_back (size);
	}

	for (i = 0; i < m_Image.get_FrameCount (); i++)
		m_vFrameDelays.push_back (m_Image.get_FrameDelay (i));
}

void vmsImage_CtxFree::set_CurrentFrame(int iIndex)
{
	m_iCurrentFrame = iIndex;
}

SIZE vmsImage_CtxFree::get_Size()
{
	return m_vSizes [m_iCurrentFrame];
}

int vmsImage_CtxFree::get_FrameCount()
{
	return m_cFrames;
}

void vmsImage_CtxFree::Draw(HDC dc, RECT &rc)
{
	if (m_vBitmaps.size () == 0)
		return;

	POINT pt = {rc.left, rc.top};
	DrawBitmap (dc, m_iCurrentFrame, pt);
}

int vmsImage_CtxFree::get_FrameDelay(int iIndex)
{
	return m_vFrameDelays [iIndex];
}

BOOL vmsImage_CtxFree::is_Loaded()
{
	return m_vBitmaps.size () != 0;
}

void vmsImage_CtxFree::Free()
{
	for (size_t i = 0; i < m_vBitmaps.size (); i++)
		DeleteObject (m_vBitmaps [i]);
	m_vBitmaps.clear ();
	m_vFrameDelays.clear ();
	m_vSizes.clear ();
	m_Image.Free ();
}

void vmsImage_CtxFree::DrawBitmap(HDC dc, int iBitmap, POINT pt)
{
	HBITMAP hbm = m_vBitmaps [iBitmap];
	SIZE size = m_vSizes [iBitmap];
	HDC hmem = CreateCompatibleDC (dc);
	HBITMAP hbmold = (HBITMAP)SelectObject (hmem, hbm);
	
	BitBlt (dc, pt.x, pt.y, size.cx, size.cy, 
		hmem, 0, 0, SRCCOPY);

	SelectObject (hmem, hbmold);
	DeleteDC (hmem);
}
