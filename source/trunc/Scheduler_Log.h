/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SCHEDULER_LOG_H__E6B6D3C4_EFED_41F6_8C91_0CB7C3FAFB19__INCLUDED_)
#define AFX_SCHEDULER_LOG_H__E6B6D3C4_EFED_41F6_8C91_0CB7C3FAFB19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "WndLog.h"

class CScheduler_Log : public CWndLog
{

public:
	CScheduler_Log();

public:

public:

	
	//{{AFX_VIRTUAL(CScheduler_Log)
	//}}AFX_VIRTUAL

public:
	BOOL Create (CWnd *pParent);
	virtual ~CScheduler_Log();

	
protected:
	CPoint m_rbPt;
	BOOL m_bAutoScroll;	
	CImageList m_images;
	//{{AFX_MSG(CScheduler_Log)
	afx_msg void OnClear();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
