/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __GRUTIL_H_
#define __GRUTIL_H_

extern void fsFillSolidRect (CDC* pDC, RECT *prc, COLORREF clr);

extern void fsDrawFrame (CDC* pDC, RECT* prc, int w);

extern void fsDrawPressedFrame (CDC* pDC, RECT* prc, int w);

#endif