/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "ImportWizardPropertySheet.h"

IMPLEMENT_DYNAMIC(CImportWizardPropertySheet, CPropertySheet)

CImportWizardPropertySheet::CImportWizardPropertySheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	Init();
}

CImportWizardPropertySheet::CImportWizardPropertySheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage),
	m_pageManagers(pszCaption),
	m_pageProgress(pszCaption),
	m_pageResult(pszCaption)
{
	Init();
}

void CImportWizardPropertySheet::Init()
{
	AddPage(&m_pageManagers);
	AddPage(&m_pageProgress);
	AddPage(&m_pageResult);
	m_psh.dwFlags &= ~PSH_HASHELP;
	m_pageManagers.m_psp.dwFlags &= ~PSP_HASHELP;
	m_pageProgress.m_psp.dwFlags &= ~PSP_HASHELP;
	m_pageResult.m_psp.dwFlags &= ~PSP_HASHELP;
	m_pageManagers.Init(&m_imImportManager);
	m_pageProgress.Init(&m_imImportManager);
	m_pageResult.Init(&m_imImportManager);

	SetWizardMode();
}

CImportWizardPropertySheet::~CImportWizardPropertySheet()
{
	if (::IsWindow(m_hWnd)) {
		_DlgMgr.OnEndDialog(this);
		::EndDialog(m_hWnd, IDCANCEL);
	}
}

BEGIN_MESSAGE_MAP(CImportWizardPropertySheet, CPropertySheet)
END_MESSAGE_MAP()

BOOL CImportWizardPropertySheet::OnInitDialog()
{
	m_imImportManager.Init(&CImportWizardPropertySheet::UpdateProgress, &CImportWizardPropertySheet::InitManager, &CImportWizardPropertySheet::InitManagerResult,
			this, m_hWnd);

	BOOL bResult = CPropertySheet::OnInitDialog();

	return bResult;
}

void CImportWizardPropertySheet::UpdateProgress(int nTotal, int nProcessed, const CString& sSupplierName)
{
	m_pageProgress.UpdateProgress(nTotal, nProcessed, sSupplierName);
}

void CImportWizardPropertySheet::InitManager(int nManagerIndex, bool bIsEnabled, const CString& sManagerName)
{
	m_pageManagers.InitManager(nManagerIndex, bIsEnabled, sManagerName);
}

void CImportWizardPropertySheet::UpdateProgress(int nTotal, int nProcessed, const CString& sSupplierName, void* pData)
{
	ASSERT(pData != 0);

	CImportWizardPropertySheet* pSheet = (CImportWizardPropertySheet*)pData;
	pSheet->UpdateProgress(nTotal, nProcessed, sSupplierName);
}

void CImportWizardPropertySheet::InitManager(int nId, bool bIsEnabled, const CString& sManagerName, void* pData)
{
	ASSERT(pData != 0);

	CImportWizardPropertySheet* pSheet = (CImportWizardPropertySheet*)pData;
	pSheet->InitManager(nId, bIsEnabled, sManagerName);
}

void CImportWizardPropertySheet::InitManagerResult(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult)
{
	m_pageResult.InitManagerResult(nManagerIndex, bChecked, sSupplierName, tImportResult);
}

void CImportWizardPropertySheet::InitManagerResult(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult, void* pData)
{
	ASSERT(pData != 0);

	CImportWizardPropertySheet* pSheet = (CImportWizardPropertySheet*)pData;
	pSheet->InitManagerResult(nManagerIndex, bChecked, sSupplierName, tImportResult);
}
