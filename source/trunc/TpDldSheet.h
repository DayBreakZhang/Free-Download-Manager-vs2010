/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_TPDLDSHEET_H__758A8CA6_C725_4BC9_A4FB_C945B13AF7DD__INCLUDED_)
#define AFX_TPDLDSHEET_H__758A8CA6_C725_4BC9_A4FB_C945B13AF7DD__INCLUDED_

#include "TpDld_General.h"	

#if _MSC_VER > 1000
#pragma once
#endif 

#define BTDS_GENERAL_PAGE		1
#define BTDS_FILES_PAGE			(1 << 1)
#define BTDS_SEEDING_PAGE		(1 << 2)
#define BTDS_MISC_PAGE			(1 << 3)
#define BTDS_ALL				(0xffffffff)

class CTpDldSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CTpDldSheet)

public:
	CTpDldSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CTpDldSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CTpDldSheet)
	//}}AFX_VIRTUAL

public:
	CTpDld_General m_general;
	
	
	
	BOOL IsNeedUpdateTasks();
	void Init (DLDS_LIST* pvDlds, DWORD dwPages = BTDS_ALL);

	virtual ~CTpDldSheet();

	
protected:
	//{{AFX_MSG(CTpDldSheet)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
