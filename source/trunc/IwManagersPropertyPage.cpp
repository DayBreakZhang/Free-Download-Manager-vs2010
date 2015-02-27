/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "IwManagersPropertyPage.h"
#include "IwProgressPropertyPage.h"

IMPLEMENT_DYNAMIC(CIwManagersPropertyPage, CPropertyPage)

CIwManagersPropertyPage::CIwManagersPropertyPage()
	: CPropertyPage(CIwManagersPropertyPage::IDD)
{

}

CIwManagersPropertyPage::CIwManagersPropertyPage(LPCTSTR pszCaption)
	: CPropertyPage(CIwManagersPropertyPage::IDD),
	  m_pImportManager(0)
{
	m_strTitle = pszCaption;
	m_psp.pszTitle = m_strTitle;
	m_psp.dwFlags |= PSP_USETITLE;

}

CIwManagersPropertyPage::~CIwManagersPropertyPage()
{
}

void CIwManagersPropertyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIwManagersPropertyPage, CPropertyPage)
	ON_BN_CLICKED(IDC_ORBIT_MANAGER, &CIwManagersPropertyPage::OnBnClickedOrbitManager)
	ON_BN_CLICKED(IDC_MTORRENET_MANAGER, &CIwManagersPropertyPage::OnBnClickedMtorrenetManager)
END_MESSAGE_MAP()

BOOL CIwManagersPropertyPage::OnSetActive()
{
	CPropertySheet* parent = (CPropertySheet*)GetParent();
	ASSERT(parent != 0);
	

	
	CWnd* pwndBackBut = parent->GetDlgItem(ID_WIZBACK);
	ASSERT(pwndBackBut != 0);
	pwndBackBut->EnableWindow(0);

	CWnd* pwndNextBut = parent->GetDlgItem(ID_WIZNEXT);
	ASSERT(pwndNextBut != 0);
	pwndNextBut->EnableWindow(0);

	return CPropertyPage::OnSetActive();
}

LRESULT CIwManagersPropertyPage::OnWizardNext()
{
	ASSERT(m_pImportManager != 0);

	int i = 0;
	for (i = 0; i <= sizeof(g_arrIwManagerControls)/sizeof(TIwManagerControls) - 1; i++) {
		const TIwManagerControls& tIwManagerControls = g_arrIwManagerControls[i];
		CButton* pctlManager = (CButton*)GetDlgItem(g_arrIwManagerControls[i].nMgrsPageMgrId);
		ASSERT(pctlManager != 0);
		m_pImportManager->CheckSupplier(i, (pctlManager->GetCheck() == BST_CHECKED));
	}

	return CPropertyPage::OnWizardNext();
}

void CIwManagersPropertyPage::InitManager(int nManagerIndex, bool bIsEnabled, const CString& sManagerName)
{
	ASSERT(nManagerIndex >= 0 && nManagerIndex <= sizeof(g_arrIwManagerControls)/sizeof(TIwManagerControls) - 1);
	int nId = g_arrIwManagerControls[nManagerIndex].nMgrsPageMgrId;

	CWnd* pWnd = GetDlgItem(nId);
	if (!pWnd)
		return;

	pWnd->EnableWindow(bIsEnabled);
	pWnd->SetWindowText(sManagerName);
}

BOOL CIwManagersPropertyPage::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	CWnd* pwndChooseManagers = GetDlgItem(IDC_STATIC_CHOOSE_MANAGERS);
	ASSERT(pwndChooseManagers != 0);
	CString sChooseManagersHeader = LS (L_IMPORT_WIZARD_CHOOSE_MANAGERS_HEADER);
	pwndChooseManagers->SetWindowText(sChooseManagersHeader);

	ASSERT(m_pImportManager != 0);
	m_pImportManager->InitWizard();

	return TRUE;
}

void CIwManagersPropertyPage::Init(CImportManager* pImportManager)
{
	m_pImportManager = pImportManager;
}

void CIwManagersPropertyPage::UpdateButtons()
{
	bool bIsNextButtonEnabled = false;
	int i = 0;
	for (i = 0; i <= sizeof(g_arrIwManagerControls)/sizeof(TIwManagerControls) - 1; i++) {
		const TIwManagerControls& tIwManagerControls = g_arrIwManagerControls[i];
		CButton* pctlManager = (CButton*)GetDlgItem(tIwManagerControls.nMgrsPageMgrId);
		ASSERT(pctlManager != 0);

		if (pctlManager->GetCheck() == BST_CHECKED)
			bIsNextButtonEnabled = true;
	}

	CPropertySheet* parent = (CPropertySheet*)GetParent();
	ASSERT(parent != 0);

	CWnd* pwndNextBut = parent->GetDlgItem(ID_WIZNEXT);
	ASSERT(pwndNextBut != 0);

	pwndNextBut->EnableWindow(bIsNextButtonEnabled);
}

void CIwManagersPropertyPage::OnBnClickedOrbitManager()
{
	UpdateButtons();
}

void CIwManagersPropertyPage::OnBnClickedMtorrenetManager()
{
	UpdateButtons();
}
