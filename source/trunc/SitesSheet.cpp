/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SitesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CSitesSheet, CPropertySheet)

CSitesSheet::CSitesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CSitesSheet::CSitesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CSitesSheet::~CSitesSheet()
{
}

BEGIN_MESSAGE_MAP(CSitesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSitesSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSitesSheet::Init(fsSiteInfo *pSite)
{
	m_general.m_pSite = m_advanced.m_pSite = pSite;
	m_general.m_advanced = &m_advanced;
	AddPage (&m_general);
	AddPage (&m_advanced);
}

BOOL CSitesSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;  
	              
}

void CSitesSheet::SetMode(bool bIsAddingSite)
{
	m_general.SetMode(bIsAddingSite);
	m_advanced.SetMode(bIsAddingSite);
}
