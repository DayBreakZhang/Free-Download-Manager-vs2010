/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_HFESHEET_H__A5E19192_AFB6_481B_9310_CC14D61D8A7E__INCLUDED_)
#define AFX_HFESHEET_H__A5E19192_AFB6_481B_9310_CC14D61D8A7E__INCLUDED_

#include "HFE_ProtocolPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class CHFESheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CHFESheet)

public:
	CHFESheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CHFESheet)
	//}}AFX_VIRTUAL

public:
	virtual ~CHFESheet();

	
protected:
	CHFE_ProtocolPage m_protocol;	
	//{{AFX_MSG(CHFESheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
