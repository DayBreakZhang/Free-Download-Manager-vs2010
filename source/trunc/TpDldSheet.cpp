/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "TpDldSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CTpDldSheet, CPropertySheet)

CTpDldSheet::CTpDldSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CTpDldSheet::CTpDldSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CTpDldSheet::~CTpDldSheet()
{
}

BEGIN_MESSAGE_MAP(CTpDldSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CTpDldSheet)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CTpDldSheet::Init(DLDS_LIST *pvDlds, DWORD dwPages)
{
	m_general.m_pvDlds =  pvDlds;

	if (dwPages & BTDS_GENERAL_PAGE)
		AddPage (&m_general);

	
}

BOOL CTpDldSheet::IsNeedUpdateTasks()
{
	return m_general.m_bNeedUpdateTasks;
}
