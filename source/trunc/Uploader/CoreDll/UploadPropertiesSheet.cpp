/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "UploadPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CUploadPropertiesSheet, CPropertySheet)

CUploadPropertiesSheet::CUploadPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CUploadPropertiesSheet::~CUploadPropertiesSheet()
{
}

BEGIN_MESSAGE_MAP(CUploadPropertiesSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CUploadPropertiesSheet)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CUploadPropertiesSheet::set_Upload(vmsUploadSmartPtr upl)
{
	m_general.m_upl = upl;

	AddPage (&m_general);
}
