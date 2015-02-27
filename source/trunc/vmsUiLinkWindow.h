/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUILINKWINDOW_H__2D02948E_BD4E_4DA8_871D_A4981C2ABCAA__INCLUDED_)
#define AFX_VMSUILINKWINDOW_H__2D02948E_BD4E_4DA8_871D_A4981C2ABCAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsUiWindow.h"

class vmsUiLinkWindow : public vmsUiWindow  
{
public:
	void setLinkTextFont (CFont *pfnt);
	void OnLButtonDown(CPoint pt);
	void OnMouseMove(CPoint pt);
	void Draw(CDC *pdc);
	CSize getSize () const;
	
	void setLink (LPCTSTR ptszText, LPCTSTR ptszUrl, UINT uDrawTextFormat = 0);
	vmsUiLinkWindow();
	virtual ~vmsUiLinkWindow();

protected:
	CFont* m_pfntLnk;
	tstring m_tstrText, m_tstrUrl;
	UINT m_uDrawTextFormat;
};

#endif 
