/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "PrgSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CPrgSheet, CPropertySheet)

CPrgSheet::CPrgSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CPrgSheet::CPrgSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CPrgSheet::~CPrgSheet()
{
}

BEGIN_MESSAGE_MAP(CPrgSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CPrgSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CPrgSheet::Init()
{
	AddPage (&m_general);
	AddPage (&m_data);
	AddPage (&m_history);
	AddPage (&m_skins);
	AddPage (&m_update);
	AddPage (&m_misc);
}

BOOL CPrgSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;
}
