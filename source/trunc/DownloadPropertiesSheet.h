/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_DOWNLOADPROPERTYSHEET_H__62605145_E319_476F_B224_92B1E5315E79__INCLUDED_)
#define AFX_DOWNLOADPROPERTYSHEET_H__62605145_E319_476F_B224_92B1E5315E79__INCLUDED_

#include "DownloadProperties_ProxyPage.h"	
#include "DownloadProperties_ProtocolPage.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "DownloadProperties_ConnectionPage.h"	
#include "DownloadProperties_GeneralPage.h"	
#include "DownloadProperties_MiscPage.h"	
#include "DownloadProperties_MirrorsPage.h"	
#include "DownloadProperties_IntegrityPage.h"	

#define DPS_SHP_GENERAL			1
#define DPS_SHP_MIRRORS			2
#define DPS_SHP_CONNECTION		4
#define DPS_SHP_PROTOCOL		8
#define DPS_SHP_PROXY			16
#define DPS_SHP_MISC			32
#define DPS_SHP_INTEGRITY		64

#define DPS_SHP_NETWORKPAGES	(DPS_SHP_PROTOCOL|DPS_SHP_PROXY|DPS_SHP_CONNECTION)
#define DPS_SHP_NOGENERALNOMIRR	(DPS_SHP_NETWORKPAGES|DPS_SHP_MISC|DPS_SHP_INTEGRITY)
#define DPS_SHP_NOGENERAL		(DPS_SHP_MIRRORS|DPS_SHP_NOGENERALNOMIRR|DPS_SHP_INTEGRITY)
#define DPS_SHP_ALL				(DPS_SHP_GENERAL|DPS_SHP_NOGENERAL)

class CDownloadPropertiesSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CDownloadPropertiesSheet)

public:
	CDownloadPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CDownloadPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

public:

public:

	
	//{{AFX_VIRTUAL(CDownloadPropertySheet)
	//}}AFX_VIRTUAL

public:
	
	
	BOOL IsNeedProcessDownloads ();
	
	BOOL IsNeedUpdateTasks();
	
	
	
	
	void Init (DLDS_LIST *pvDlds, DWORD dwPages);
	virtual ~CDownloadPropertiesSheet();

	
protected:
	CDownloadProperties_IntegrityPage m_integrity;
	CDownloadProperties_MirrorsPage m_mirrors;
	
	RECT m_rctPage;
	CFont m_fntPage;
	void BuildPropPageArray();
	

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();

	
	CDownloadProperties_MiscPage m_misc;		
	CDownloadProperties_GeneralPage m_general;	
	CDownloadProperties_ConnectionPage m_connection;	
	CDownloadProperties_ProtocolPage m_protocol;	
	CDownloadProperties_ProxyPage m_proxy;		
	

	//{{AFX_MSG(CDownloadPropertySheet)
		
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}

#endif 
