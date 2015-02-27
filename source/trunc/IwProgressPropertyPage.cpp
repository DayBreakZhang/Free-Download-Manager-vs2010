/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "IwProgressPropertyPage.h"

#include "resource.h"

IMPLEMENT_DYNAMIC(CIwProgressPropertyPage, CPropertyPage)

CIwProgressPropertyPage::CIwProgressPropertyPage()
	: CPropertyPage(CIwProgressPropertyPage::IDD),
	  m_pImportManager(0)
{

}

CIwProgressPropertyPage::CIwProgressPropertyPage(LPCTSTR pszCaption)
	: CPropertyPage(CIwProgressPropertyPage::IDD),
	  m_pImportManager(0)
{
	m_strTitle = pszCaption;
	m_psp.pszTitle = m_strTitle;
	m_psp.dwFlags |= PSP_USETITLE;
}

CIwProgressPropertyPage::~CIwProgressPropertyPage()
{
}

void CIwProgressPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIwProgressPropertyPage, CPropertyPage)
END_MESSAGE_MAP()

BOOL CIwProgressPropertyPage::OnSetActive()
{
	CPropertySheet* parent = (CPropertySheet*)GetParent();
	parent->SetWizardButtons(PSWIZB_DISABLEDFINISH);

	return CPropertyPage::OnSetActive();
}

BOOL CIwProgressPropertyPage::OnInitDialog()
{
	CProgressCtrl* ctlProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS);
	ctlProgress->SetRange(0, 100);
	ctlProgress->SetPos(1);

	CPropertySheet* parent = (CPropertySheet*)GetParent();
	parent->PostMessage(PSM_PRESSBUTTON, PSBTN_NEXT, 0);
	CWnd* pwndNextBut = parent->GetDlgItem(ID_WIZNEXT);
	CWnd* pwndCancelBut = parent->GetDlgItem(IDCANCEL);
	if (pwndNextBut)
		pwndNextBut->EnableWindow(0);
	if (pwndCancelBut)
		pwndCancelBut->EnableWindow(0);

	return TRUE;  
}

LRESULT CIwProgressPropertyPage::OnWizardNext()
{
	UpdateWindow();

	ASSERT(m_pImportManager != 0);
	m_pImportManager->Run();

	return CPropertyPage::OnWizardNext();
}

BOOL CIwProgressPropertyPage::OnKillActive()
{

	return CPropertyPage::OnKillActive();
}

void CIwProgressPropertyPage::UpdateProgress(int nTotal, int nProcessed, const CString& sSupplierName)
{
	CProgressCtrl* ctlProgress = (CProgressCtrl*)GetDlgItem(IDC_PROGRESS);
	ASSERT(ctlProgress != 0);
	CWnd* pWnd = GetDlgItem(IDC_STATIC_PROCESSED);
	ASSERT(pWnd != 0);
	CWnd* pManager = GetDlgItem(IDC_STATIC_MANAGER);
	ASSERT(pManager != 0);

	
	if (nTotal == -1) {
		ctlProgress->SetPos(0);
		CString sStatus = LS (L_PROCESSED_LABEL);
		pWnd->SetWindowText(sStatus);
		pManager->SetWindowText(sSupplierName);
		return;
	}

	int nPos;
	if (nProcessed == nTotal)
	{
		nPos = 100;
	}
	else
	{
		assert (nTotal != 0);
		nPos = (100 * nProcessed) / nTotal;
	}

	ctlProgress->SetPos(nPos);

	CString sManager;
	pManager->GetWindowText(sManager);
	if (sManager.Compare(sSupplierName) != 0) {
		pManager->SetWindowText(sSupplierName);
	}

	CString sStatus = LS (L_PROCESSED_LABEL);
	sStatus += " ";
	CString sTmp;
	CString sFmt = LS (L_PART_OF_TOTAL_FMT);
	sTmp.Format(sFmt, nProcessed, nTotal);
	sStatus += sTmp;
	pWnd->SetWindowText(sStatus);
}

void CIwProgressPropertyPage::Init(CImportManager* pImportManager)
{
	m_pImportManager = pImportManager;
}
