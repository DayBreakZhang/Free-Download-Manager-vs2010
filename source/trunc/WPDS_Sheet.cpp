/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WPDS_Sheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CWPDS_Sheet, CPropertySheet)

CWPDS_Sheet::CWPDS_Sheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CWPDS_Sheet::CWPDS_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CWPDS_Sheet::~CWPDS_Sheet()
{
}

BEGIN_MESSAGE_MAP(CWPDS_Sheet, CPropertySheet)
	//{{AFX_MSG_MAP(CWPDS_Sheet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWPDS_Sheet::Init(fsWPDSettings *wpds, BOOL bGeneralPage, fsWebPageDownloader* wpd, bool bUsedAsSetDefaults)
{
	if (bGeneralPage)
		AddPage (&m_general);

	m_general.m_wpds = m_webpages.m_wpds = m_files.m_wpds = m_images.m_wpds = wpds;
	m_general.m_wpd = wpd;

	m_webpages.m_bUsedAsSetDefaults = bUsedAsSetDefaults;

	AddPage (&m_webpages);
	AddPage (&m_images);
	AddPage (&m_files);
}

BOOL CWPDS_Sheet::OnInitDialog() 
{
	CPropertySheet::OnInitDialog();
	
	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);
	
	return TRUE;  
	              
}
