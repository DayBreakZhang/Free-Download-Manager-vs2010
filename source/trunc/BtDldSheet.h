/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_BTDLDSHEET_H__758A8CA6_C725_4BC9_A4FB_C945B13AF7DD__INCLUDED_)
#define AFX_BTDLDSHEET_H__758A8CA6_C725_4BC9_A4FB_C945B13AF7DD__INCLUDED_

#include "BtDld_General.h"	
#include "BtDld_Misc.h"	
#include "BtDld_Files.h"	
#include "BtDld_Seeding.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#define BTDS_GENERAL_PAGE		1
#define BTDS_FILES_PAGE			(1 << 1)
#define BTDS_SEEDING_PAGE		(1 << 2)
#define BTDS_MISC_PAGE			(1 << 3)
#define BTDS_ALL				(0xffffffff)

class CBtDldSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CBtDldSheet)

public:
	CBtDldSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CBtDldSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CBtDldSheet)
	//}}AFX_VIRTUAL

public:
	CBtDld_Seeding m_seeding;
	CBtDld_Files m_files;
	CBtDld_Misc m_misc;
	BOOL IsNeedUpdateTasks();
	void Init (DLDS_LIST* pvDlds, DWORD dwPages = BTDS_ALL);
	CBtDld_General m_general;
	virtual ~CBtDldSheet();

	
protected:
	//{{AFX_MSG(CBtDldSheet)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
