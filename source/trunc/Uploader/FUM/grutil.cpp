/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "grutil.h"

void fsFillSolidRect (CDC* pDC, RECT* prc, COLORREF clr)
{
	CBrush br (clr);
	pDC->FillRect (prc, &br);
}

void fsDrawFrame (CDC* dc, RECT* prc, int w)
{
	CPen LightPen (PS_SOLID, 1, GetSysColor (COLOR_3DLIGHT));
	CPen DarkPen (PS_SOLID, 1, GetSysColor (COLOR_3DDKSHADOW));
	CPen HilightPen (PS_SOLID, 1, GetSysColor (COLOR_3DHILIGHT));
	CPen ShadowPen (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));

	CPen* oldpen = dc->SelectObject (&HilightPen);
	dc->MoveTo (prc->left, prc->bottom);
	dc->LineTo (prc->left, prc->top);
	dc->LineTo (prc->right, prc->top);

	if (w == 2)
	{
		dc->SelectObject (&LightPen);
		dc->MoveTo (prc->left+1, prc->bottom-1);
		dc->LineTo (prc->left+1, prc->top+1);
		dc->LineTo (prc->right-1, prc->top+1);
	}

	dc->SelectObject (w == 2 ? &DarkPen : &ShadowPen);
	dc->MoveTo (prc->left + 1, prc->bottom);
	dc->LineTo (prc->right, prc->bottom);
	dc->LineTo (prc->right, prc->top);

	if (w == 2)
	{
		dc->SelectObject (&ShadowPen);
		dc->MoveTo (prc->left + 2, prc->bottom - 1);
		dc->LineTo (prc->right - 1, prc->bottom - 1);
		dc->LineTo (prc->right - 1, prc->top + 1);
	}
	
	dc->SelectObject (oldpen);
}

void fsDrawPressedFrame (CDC* dc, RECT* prc, int w)
{
	CPen LightPen (PS_SOLID, 1, GetSysColor (COLOR_3DLIGHT));
	CPen DarkPen (PS_SOLID, 1, GetSysColor (COLOR_3DDKSHADOW));
	CPen HilightPen (PS_SOLID, 1, GetSysColor (COLOR_3DHILIGHT));
	CPen ShadowPen (PS_SOLID, 1, GetSysColor (COLOR_3DSHADOW));

	CPen* oldpen = dc->SelectObject (w == 2 ? &DarkPen : &ShadowPen);
	dc->MoveTo (prc->left, prc->bottom);
	dc->LineTo (prc->left, prc->top);
	dc->LineTo (prc->right, prc->top);

	if (w == 2)
	{
		dc->SelectObject (&ShadowPen);
		dc->MoveTo (prc->left+1, prc->bottom-1);
		dc->LineTo (prc->left+1, prc->top+1);
		dc->LineTo (prc->right-1, prc->top+1);
	}

	dc->SelectObject (&HilightPen);
	dc->MoveTo (prc->left + 1, prc->bottom);
	dc->LineTo (prc->right, prc->bottom);
	dc->LineTo (prc->right, prc->top);

	if (w == 2)
	{
		dc->SelectObject (&LightPen);
		dc->MoveTo (prc->left + 2, prc->bottom - 1);
		dc->LineTo (prc->right - 1, prc->bottom - 1);
		dc->LineTo (prc->right - 1, prc->top + 1);
	}
	
	dc->SelectObject (oldpen);
}