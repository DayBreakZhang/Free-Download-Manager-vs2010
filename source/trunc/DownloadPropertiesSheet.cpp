/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadPropertiesSheet.h"
#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CDownloadPropertiesSheet, CPropertySheet)

CDownloadPropertiesSheet::CDownloadPropertiesSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	
}

CDownloadPropertiesSheet::CDownloadPropertiesSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
}

CDownloadPropertiesSheet::~CDownloadPropertiesSheet()
{
}

BEGIN_MESSAGE_MAP(CDownloadPropertiesSheet, CPropertySheet)
	ON_WM_CREATE ()
	//{{AFX_MSG_MAP(CDownloadPropertiesSheet)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDownloadPropertiesSheet::Init(DLDS_LIST* pvDlds, DWORD dwPages)
{
	m_general.m_pvDlds = m_connection.m_pvDlds = m_protocol.m_pvDlds = m_proxy.m_pvDlds = 
		m_integrity.m_pvDlds = m_misc.m_pvDlds = pvDlds;

	if (dwPages & DPS_SHP_GENERAL)
		AddPage (&m_general);

	if ((dwPages & DPS_SHP_MIRRORS) && pvDlds->size () == 1)
	{
		m_mirrors.m_dld = pvDlds->at (0);
		AddPage (&m_mirrors);
	}

	if (dwPages & DPS_SHP_CONNECTION)
		AddPage (&m_connection);

	if (dwPages & DPS_SHP_PROTOCOL)
		AddPage (&m_protocol);

	if (dwPages & DPS_SHP_PROXY)
		AddPage (&m_proxy);

	if (dwPages & DPS_SHP_INTEGRITY)
		AddPage (&m_integrity);

	if (dwPages & DPS_SHP_MISC)
		AddPage (&m_misc);

	EnableStackedTabs (FALSE);

	
}

BOOL CDownloadPropertiesSheet::OnInitDialog()
{
	CPropertySheet::OnInitDialog ();

	DWORD dw = GetWindowLong (m_hWnd, GWL_EXSTYLE);
	dw |= WS_EX_CONTEXTHELP;
	SetWindowLong (m_hWnd, GWL_EXSTYLE, dw);

	return TRUE;
}

BOOL CDownloadPropertiesSheet::IsNeedUpdateTasks()
{
	return m_general.m_bNeedUpdateTasks;
}

BOOL CDownloadPropertiesSheet::IsNeedProcessDownloads()
{
	return m_general.m_bNeedProcessDownloads;
}

int CDownloadPropertiesSheet::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	int iRet = CPropertySheet::OnCreate (lpCreateStruct);

	return iRet;
}

void CDownloadPropertiesSheet::BuildPropPageArray()
{
	CPropertySheet::BuildPropPageArray();

	
}

