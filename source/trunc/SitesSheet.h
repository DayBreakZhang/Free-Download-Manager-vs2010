/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITESSHEET_H__AECD880A_4310_474A_92CB_C45DD8BE99A0__INCLUDED_)
#define AFX_SITESSHEET_H__AECD880A_4310_474A_92CB_C45DD8BE99A0__INCLUDED_

#include "Sites_GeneralPage.h"	
#include "Sites_AdvancedPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CSitesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSitesSheet)

public:
	CSitesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSitesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CSitesSheet)
	//}}AFX_VIRTUAL

public:
	CSites_AdvancedPage m_advanced;	
	CSites_GeneralPage m_general;	
	
	
	
	void Init (fsSiteInfo* pSite);
	void SetMode(bool bIsAddingSite);
	virtual ~CSitesSheet();

	
protected:
	//{{AFX_MSG(CSitesSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
