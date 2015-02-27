/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "IwResultPropertyPage.h"

#include "IwProgressPropertyPage.h"

IMPLEMENT_DYNAMIC(CIwResultPropertyPage, CPropertyPage)

CIwResultPropertyPage::CIwResultPropertyPage()
	: CPropertyPage(CIwResultPropertyPage::IDD),
	  m_pImportManager(0)
{

}

CIwResultPropertyPage::CIwResultPropertyPage(LPCTSTR pszCaption)
	: CPropertyPage(CIwResultPropertyPage::IDD),
	  m_pImportManager(0)
{
	m_strTitle = pszCaption;
	m_psp.pszTitle = m_strTitle;
	m_psp.dwFlags |= PSP_USETITLE;
}

CIwResultPropertyPage::~CIwResultPropertyPage()
{
}

void CIwResultPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIwResultPropertyPage, CPropertyPage)
END_MESSAGE_MAP()

BOOL CIwResultPropertyPage::OnSetActive()
{
	CPropertySheet* parent = (CPropertySheet*)GetParent();
	parent->SetWizardButtons(PSWIZB_FINISH);

	return CPropertyPage::OnSetActive();
}

void CIwResultPropertyPage::InitManagerResult(int nManagerIndex, bool bChecked, const CString & sSupplierName, const TImportResult& tImportResult)
{
	ASSERT(nManagerIndex >= 0 && nManagerIndex <= sizeof(g_arrIwManagerControls)/sizeof(TIwManagerControls) - 1);
	const TIwManagerControls& tIwManagerControls = g_arrIwManagerControls[nManagerIndex];

	CWnd* pwndMgr = GetDlgItem(tIwManagerControls.nResPageMgrId);
	CWnd* pwndSuccessful = GetDlgItem(tIwManagerControls.nResPageSucessfulId);
	CWnd* pwndFailed = GetDlgItem(tIwManagerControls.nResPageFailedId);
	CWnd* pwndUnprocessed = GetDlgItem(tIwManagerControls.nResPageUnprocessedId);
	CWnd* pwndTotal = GetDlgItem(tIwManagerControls.nResPageTotalId);

	ASSERT(pwndMgr != 0);
	ASSERT(pwndSuccessful != 0);
	ASSERT(pwndFailed != 0);
	ASSERT(pwndUnprocessed != 0);
	ASSERT(pwndTotal != 0);

	pwndMgr->SetWindowText(sSupplierName);

	if (!bChecked) {
		pwndMgr->EnableWindow(0);
		pwndSuccessful->EnableWindow(0);
		pwndFailed->EnableWindow(0);
		pwndUnprocessed->EnableWindow(0);
		pwndTotal->EnableWindow(0);
	} else {

		CString sStatistics;
		CString sTmp;

		pwndSuccessful->GetWindowText(sStatistics);
		sStatistics += " ";
		if (tImportResult.nSuccess == -1) {
			sStatistics += LS (L_UNDEFINED_IMPORT_RESULT);
		} else {
			sTmp.Format("%d", tImportResult.nSuccess);
			sStatistics += sTmp;
		}
		pwndSuccessful->SetWindowText(sStatistics);

		pwndFailed->GetWindowText(sStatistics);
		sStatistics += " ";
		if (tImportResult.nFailure == -1) {
			sStatistics += LS (L_UNDEFINED_IMPORT_RESULT);
		} else {
			sTmp.Format("%d", tImportResult.nFailure);
			sStatistics += sTmp;
		}
		pwndFailed->SetWindowText(sStatistics);

		pwndUnprocessed->GetWindowText(sStatistics);
		sStatistics += " ";
		if (tImportResult.nUnprocessed == -1) {
			sStatistics += LS (L_UNDEFINED_IMPORT_RESULT);
		} else {
			sTmp.Format("%d", tImportResult.nUnprocessed);
			sStatistics += sTmp;
		}
		pwndUnprocessed->SetWindowText(sStatistics);

		pwndTotal->GetWindowText(sStatistics);
		sStatistics += " ";
		if (tImportResult.nTotal == -1) {
			sStatistics += LS (L_UNDEFINED_IMPORT_RESULT);
		} else {
			sTmp.Format("%d", tImportResult.nTotal);
			sStatistics += sTmp;
		}
		pwndTotal->SetWindowText(sStatistics);
	}
}

void CIwResultPropertyPage::Init(CImportManager* pImportManager)
{
	m_pImportManager = pImportManager;
}

BOOL CIwResultPropertyPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	
	int nCount  = sizeof(g_arrIwManagerControls)/sizeof(TIwManagerControls);
	int i = 0;
	for (i = 0; i <= nCount - 1; i++) {
		const TIwManagerControls& tIwManagerControls = g_arrIwManagerControls[i];
		CWnd* pwndSuccessful = GetDlgItem(tIwManagerControls.nResPageSucessfulId);
		CWnd* pwndFailed = GetDlgItem(tIwManagerControls.nResPageFailedId);
		CWnd* pwndUnprocessed = GetDlgItem(tIwManagerControls.nResPageUnprocessedId);
		CWnd* pwndTotal = GetDlgItem(tIwManagerControls.nResPageTotalId);

		ASSERT(pwndSuccessful != 0);
		ASSERT(pwndFailed != 0);
		ASSERT(pwndUnprocessed != 0);
		ASSERT(pwndTotal != 0);

		CString sSuccessfulLabel = LS (L_SUCCESSFUL_LABEL);
		CString sFailedLabel = LS (L_FAILED_LABEL);
		CString sUnprocessedLabel = LS (L_UNPROCESSED_LABEL);
		CString sTotalLabel = LS (L_TOTAL_LABEL);

		pwndSuccessful->SetWindowText(sSuccessfulLabel);
		pwndFailed->SetWindowText(sFailedLabel);
		pwndUnprocessed->SetWindowText(sUnprocessedLabel);
		pwndTotal->SetWindowText(sTotalLabel);
	}

	
	ASSERT(m_pImportManager != 0);
	m_pImportManager->InitResultPage();

	return TRUE;
}
