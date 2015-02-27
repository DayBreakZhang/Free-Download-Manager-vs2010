/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsDrawHelper.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDrawHelper::vmsDrawHelper()
{

}

vmsDrawHelper::~vmsDrawHelper()
{

}

void vmsDrawHelper::DrawBitmap(CDC *pdc, CBitmap *bmp, int x, int y)
{
	BITMAP bm; bmp->GetBitmap (&bm);
	CDC dcMem; dcMem.CreateCompatibleDC (pdc);
	CBitmap *pbmpOld = dcMem.SelectObject (bmp);
	pdc->BitBlt (x, y, bm.bmWidth, bm.bmHeight, &dcMem, 0, 0, SRCCOPY);
	dcMem.SelectObject (pbmpOld);
}

void vmsDrawHelper::DrawTransparentBitmap(CDC *pdc, CBitmap *pbmp, int x, int y, COLORREF clrBg)
{
	BITMAP bm; pbmp->GetBitmap (&bm);
	CDC dcMem; dcMem.CreateCompatibleDC (pdc);
	dcMem.SelectObject (pbmp);
	TransparentBlt (pdc->GetSafeHdc (), x, y, bm.bmWidth, bm.bmHeight, 
		dcMem.GetSafeHdc (), 0, 0, bm.bmWidth, bm.bmHeight, clrBg);
}
