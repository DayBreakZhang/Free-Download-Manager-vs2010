/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FLOATINGINFO_LISTCTRLWND_H__5DD5A846_F1A1_4CEA_91EC_742DDA31EEEB__INCLUDED_)
#define AFX_FLOATINGINFO_LISTCTRLWND_H__5DD5A846_F1A1_4CEA_91EC_742DDA31EEEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "ListCtrlEx.h"

class CFloatingInfo_ListCtrlWnd : public CListCtrlEx
{

public:
	CFloatingInfo_ListCtrlWnd();

public:

public:

	
	//{{AFX_VIRTUAL(CFloatingInfo_ListCtrlWnd)
	//}}AFX_VIRTUAL

public:
	virtual ~CFloatingInfo_ListCtrlWnd();

	
protected:
	//{{AFX_MSG(CFloatingInfo_ListCtrlWnd)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
