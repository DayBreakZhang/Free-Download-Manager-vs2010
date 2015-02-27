/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADPROPERTIESSHEET_H__91059A4C_291D_4579_9630_EA21549AE318__INCLUDED_)
#define AFX_UPLOADPROPERTIESSHEET_H__91059A4C_291D_4579_9630_EA21549AE318__INCLUDED_

#include "Upload_GeneralPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CUploadPropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CUploadPropertiesSheet)

public:
	CUploadPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CUploadPropertiesSheet)
	//}}AFX_VIRTUAL

public:
	void set_Upload (vmsUploadSmartPtr upl);
	CUpload_GeneralPage m_general;
	virtual ~CUploadPropertiesSheet();

	
protected:
	//{{AFX_MSG(CUploadPropertiesSheet)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
