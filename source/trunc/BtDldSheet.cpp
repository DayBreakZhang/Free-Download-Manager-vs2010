/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "BtDldSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CBtDldSheet, CPropertySheet)

CBtDldSheet::CBtDldSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{

}

CBtDldSheet::CBtDldSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CBtDldSheet::~CBtDldSheet()
{
}

BEGIN_MESSAGE_MAP(CBtDldSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CBtDldSheet)
		
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CBtDldSheet::Init(DLDS_LIST *pvDlds, DWORD dwPages)
{
	m_general.m_pvDlds = m_files.m_pvDlds = m_seeding.m_pvDlds = m_misc.m_pvDlds = pvDlds;

	if (dwPages & BTDS_GENERAL_PAGE)
		AddPage (&m_general);

	if ((dwPages & BTDS_FILES_PAGE) && vmsBtSupport::getBtDllVersion () >= 778)
	{
		if (pvDlds->size () == 1 && pvDlds->at (0)->pMgr->GetBtDownloadMgr ()->get_FileCount () > 1)
			AddPage (&m_files);
	}

	if (dwPages & BTDS_SEEDING_PAGE)
		AddPage (&m_seeding);

	if (dwPages & BTDS_MISC_PAGE)
		AddPage (&m_misc);
}

BOOL CBtDldSheet::IsNeedUpdateTasks()
{
	return m_general.m_bNeedUpdateTasks;
}
