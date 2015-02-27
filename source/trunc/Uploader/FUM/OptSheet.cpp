/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fum.h"
#include "OptSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(COptSheet, CPropertySheet)

COptSheet::COptSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage (&m_general);
	AddPage (&m_proxy);
}

COptSheet::~COptSheet()
{
}

BEGIN_MESSAGE_MAP(COptSheet, CPropertySheet)
	//{{AFX_MSG_MAP(COptSheet)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

