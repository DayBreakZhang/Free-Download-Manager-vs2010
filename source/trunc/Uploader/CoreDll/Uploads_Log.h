/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADS_LOG_H__7C368615_3319_4D79_B071_E1E368B60715__INCLUDED_)
#define AFX_UPLOADS_LOG_H__7C368615_3319_4D79_B071_E1E368B60715__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "WndLog.h"
#include "fsUpload.h"	

class CUploads_Log : public CWndLog
{

public:
	CUploads_Log();

public:

public:

	
	//{{AFX_VIRTUAL(CUploads_Log)
	//}}AFX_VIRTUAL

public:
	vmsUploadSmartPtr get_CurrentUpload();
	void set_CurrentUpload (vmsUploadSmartPtr upl);
	BOOL Create(CWnd *pParent);
	virtual ~CUploads_Log();

	
protected:
	vmsUploadSmartPtr m_pUpload;
	//{{AFX_MSG(CUploads_Log)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
