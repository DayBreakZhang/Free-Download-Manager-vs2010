/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CDownloaderPropertiesSheet, CPropertySheet)

CDownloaderPropertiesSheet::CDownloaderPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CDownloaderPropertiesSheet::CDownloaderPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	EnableStackedTabs (FALSE);
}

CDownloaderPropertiesSheet::~CDownloaderPropertiesSheet()
{
}

BEGIN_MESSAGE_MAP(CDownloaderPropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CDownloaderPropertiesSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDownloaderPropertiesSheet::Init()
{
	AddPage (&m_newdld);
	AddPage (&m_list);
	if (Is9xME == FALSE && _AppMgr.IsBtInstalled ())
		AddPage (&m_bt);
	AddPage (&m_mirrors);
	AddPage (&m_monitor);
	AddPage (&m_notifications);
	AddPage (&m_community);
}

BOOL CDownloaderPropertiesSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;  
	              
}
