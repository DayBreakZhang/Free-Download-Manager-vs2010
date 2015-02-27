/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_OPTSHEET_H__BB445066_1396_4D6C_918F_F3A868BA9C9B__INCLUDED_)
#define AFX_OPTSHEET_H__BB445066_1396_4D6C_918F_F3A868BA9C9B__INCLUDED_

#include "OptsProxyPage.h"	
#include "OptsGeneralPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class COptSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(COptSheet)

public:
	COptSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(COptSheet)
	//}}AFX_VIRTUAL

public:
	COptsGeneralPage m_general;
	COptsProxyPage m_proxy;
	virtual ~COptSheet();

	
protected:
	//{{AFX_MSG(COptSheet)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
