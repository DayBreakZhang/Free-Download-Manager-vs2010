/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "UploaderPropsSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CUploaderPropsSheet, CPropertySheet)

CUploaderPropsSheet::CUploaderPropsSheet(UINT nIDCaption, CWnd* pParentWnd, bool bIntegrationPageOnly, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	m_phwndSheet = NULL;
	Init (bIntegrationPageOnly);
}

CUploaderPropsSheet::CUploaderPropsSheet(LPCTSTR pszCaption, CWnd* pParentWnd, bool bIntegrationPageOnly, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_phwndSheet = NULL;
	Init (bIntegrationPageOnly);
}

CUploaderPropsSheet::~CUploaderPropsSheet()
{
}

BEGIN_MESSAGE_MAP(CUploaderPropsSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CUploaderPropsSheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CUploaderPropsSheet::Init(bool bIntegrationPageOnly)
{
	AddPage (&m_integration);
	if (bIntegrationPageOnly)
		return;
	
}

BOOL CUploaderPropsSheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	if (m_phwndSheet)
		*m_phwndSheet = m_hWnd;
	
	return TRUE;  
	              
}
