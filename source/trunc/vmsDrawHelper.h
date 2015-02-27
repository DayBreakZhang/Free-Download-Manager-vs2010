/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDRAWHELPER_H__E52C3B1E_702B_4CCD_929E_19742E247A79__INCLUDED_)
#define AFX_VMSDRAWHELPER_H__E52C3B1E_702B_4CCD_929E_19742E247A79__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsDrawHelper  
{
public:
	static void DrawTransparentBitmap (CDC *pdc, CBitmap *pbmp, int x, int y, COLORREF clrBg);
	static void DrawBitmap (CDC *pdc, CBitmap *bmp, int x, int y);
	vmsDrawHelper();
	virtual ~vmsDrawHelper();

};

#endif 
