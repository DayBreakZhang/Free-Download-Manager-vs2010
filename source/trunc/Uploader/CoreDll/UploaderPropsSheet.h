/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_UPLOADERPROPSSHEET_H__B5524393_0832_4BED_9DB6_F12DB2EA013A__INCLUDED_)
#define AFX_UPLOADERPROPSSHEET_H__B5524393_0832_4BED_9DB6_F12DB2EA013A__INCLUDED_

#include "UploaderProps_Integration.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CUploaderPropsSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CUploaderPropsSheet)

public:
	CUploaderPropsSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, bool bIntegrationPageOnly = false, UINT iSelectPage = 0);
	CUploaderPropsSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, bool bIntegrationPageOnly = false, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CUploaderPropsSheet)
	//}}AFX_VIRTUAL

public:
	HWND* m_phwndSheet;
	virtual ~CUploaderPropsSheet();

	
protected:
	CUploaderProps_Integration m_integration;
	void Init(bool bIntegrationPageOnly);
	//{{AFX_MSG(CUploaderPropsSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
