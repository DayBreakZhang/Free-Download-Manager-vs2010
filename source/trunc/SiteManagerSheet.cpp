/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SiteManagerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CSiteManagerSheet, CPropertySheet)

CSiteManagerSheet::CSiteManagerSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CSiteManagerSheet::CSiteManagerSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	
	AddPage (&m_passwords);
}

CSiteManagerSheet::~CSiteManagerSheet()
{
	
}

BEGIN_MESSAGE_MAP(CSiteManagerSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CSiteManagerSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSiteManagerSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;  
	              
}
