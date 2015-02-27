/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUISTATICTEXTWINDOW_H__A528804F_5DA9_4354_8C1F_C0DAE427B5AE__INCLUDED_)
#define AFX_VMSUISTATICTEXTWINDOW_H__A528804F_5DA9_4354_8C1F_C0DAE427B5AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsUiWindow.h"

class vmsUiStaticTextWindow : public vmsUiWindow  
{
public:
	CSize getRequiredSize();
	void setText (LPCTSTR ptszText, CFont *pFont, COLORREF clrText, UINT uDrawTextFlags = 0);
	void Draw (CDC *pdc);
	vmsUiStaticTextWindow();
	virtual ~vmsUiStaticTextWindow();

protected:
	COLORREF m_clrText;
	CFont* m_pFont;
	tstring m_tstrText;
	UINT m_uDrawTextFlags;
};

#endif 
