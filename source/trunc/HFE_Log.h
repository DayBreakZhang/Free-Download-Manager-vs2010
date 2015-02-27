/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFE_LOG_H__7ABE1BB5_930B_400F_8E4B_28CE0A4B36D3__INCLUDED_)
#define AFX_HFE_LOG_H__7ABE1BB5_930B_400F_8E4B_28CE0A4B36D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "WndLog.h"

class CHFE_Log : public CWndLog
{

public:
	CHFE_Log();

public:

public:

	
	//{{AFX_VIRTUAL(CHFE_Log)
	//}}AFX_VIRTUAL

public:
	BOOL Create (CWnd *pParent);
	virtual ~CHFE_Log();

	
protected:
	//{{AFX_MSG(CHFE_Log)
		afx_msg void OnClear();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
