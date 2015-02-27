/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_SITEMANAGERSHEET_H__A78C05D3_860E_40E1_AC5F_05EB43440C73__INCLUDED_)
#define AFX_SITEMANAGERSHEET_H__A78C05D3_860E_40E1_AC5F_05EB43440C73__INCLUDED_

#include "SiteManager_GeneralPage.h"	
#include "SiteManager_PasswordsPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CSiteManagerSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSiteManagerSheet)

public:
	CSiteManagerSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CSiteManagerSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CSiteManagerSheet)
	//}}AFX_VIRTUAL

public:
	CSiteManager_PasswordsPage m_passwords;
	CSiteManager_GeneralPage m_general;
	virtual ~CSiteManagerSheet();

	
protected:
	//{{AFX_MSG(CSiteManagerSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
