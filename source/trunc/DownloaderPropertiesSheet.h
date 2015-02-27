/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADERPROPERTIESSHEET_H__C070C853_0F47_4043_AC87_07BBD37417FD__INCLUDED_)
#define AFX_DOWNLOADERPROPERTIESSHEET_H__C070C853_0F47_4043_AC87_07BBD37417FD__INCLUDED_

#include "DownloaderProperties_ListPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsDownloadsMgr.h"
#include "DownloaderProperties_MonitorPage.h"	
#include "DownloaderProperties_NotificationsPage.h"	
#include "DownloaderProperties_MirrorsPage.h"	
#include "DownloaderProperties_NewDownloadPage.h"	
#include "DownloaderProperties_CommunityPage.h"	
#include "DownloaderProperties_BtPage.h"	

class CDownloaderPropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CDownloaderPropertiesSheet)

public:
	CDownloaderPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CDownloaderPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CDownloaderPropertiesSheet)
	//}}AFX_VIRTUAL

public:
	void Init ();
	virtual ~CDownloaderPropertiesSheet();

	
protected:
	CDownloaderProperties_BtPage m_bt;
	CDownloaderProperties_CommunityPage m_community;
	CDownloaderProperties_NewDownloadPage m_newdld;
	CDownloaderProperties_MirrorsPage m_mirrors;
	CDownloaderProperties_NotificationsPage m_notifications;
	CDownloaderProperties_MonitorPage m_monitor;	
	CDownloaderProperties_ListPage m_list;
	//{{AFX_MSG(CDownloaderPropertiesSheet)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
