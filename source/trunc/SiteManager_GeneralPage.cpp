/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SiteManager_GeneralPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSiteManager_GeneralPage, CPropertyPage)

CSiteManager_GeneralPage::CSiteManager_GeneralPage() : CPropertyPage(CSiteManager_GeneralPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

CSiteManager_GeneralPage::~CSiteManager_GeneralPage()
{
}

void CSiteManager_GeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSiteManager_GeneralPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSiteManager_GeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSiteManager_GeneralPage)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

