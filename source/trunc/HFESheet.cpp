/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFESheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CHFESheet, CPropertySheet)

CHFESheet::CHFESheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage (&m_protocol);
}

CHFESheet::~CHFESheet()
{
}

BEGIN_MESSAGE_MAP(CHFESheet, CPropertySheet)
	//{{AFX_MSG_MAP(CHFESheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CHFESheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;  
	              
}
