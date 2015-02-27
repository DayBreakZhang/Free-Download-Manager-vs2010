/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "BtDld_Seeding.h"
#include "QueryStoringServiceInfoGuard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CBtDld_Seeding, CPropertyPage)

CBtDld_Seeding::CBtDld_Seeding() : CPropertyPage(CBtDld_Seeding::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_SEEDING);
}

CBtDld_Seeding::~CBtDld_Seeding()
{
}

void CBtDld_Seeding::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBtDld_Seeding)
	DDX_Control(pDX, IDC_RATIO_LIST, m_wndRatio);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBtDld_Seeding, CPropertyPage)
	//{{AFX_MSG_MAP(CBtDld_Seeding)
	ON_BN_CLICKED(IDC_ENABLE_SEEDING, OnEnableSeeding)
	ON_BN_CLICKED(IDC_UNLIMITED_SEEDING, OnUnlimitedSeeding)
	ON_BN_CLICKED(IDC_LIMIT_BY_RATIO, OnLimitByRatio)
	ON_CBN_SELCHANGE(IDC_RATIO_LIST, OnSelchangeRatioList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CBtDld_Seeding::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	int iEnableSeeding = m_pvDlds->at (0)->pMgr->GetBtDownloadMgr ()->isSeedingEnabled () ? 1 : 0;
	float fReqRatio = m_pvDlds->at (0)->pMgr->GetBtDownloadMgr ()->getRequiredRatio ();
	for (size_t i = 1; i < m_pvDlds->size (); i++)
	{
		int iEnableSeeding2 = m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->isSeedingEnabled () ? 1 : 0;
		float fReqRatio2 = m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->getRequiredRatio ();
		if (iEnableSeeding != iEnableSeeding2)
			iEnableSeeding = 2;
		if (fReqRatio2 != fReqRatio)
			fReqRatio2 = -1;
		if (iEnableSeeding == 2 && fReqRatio2 == -1)
			break;
	}

	if (iEnableSeeding == 2)
		CheckDlgButton (IDC_ENABLE_SEEDING, BST_INDETERMINATE);
	else
		CheckDlgButton (IDC_ENABLE_SEEDING, iEnableSeeding ? BST_CHECKED : BST_UNCHECKED);

	m_wndRatio.AddString ("100 %"); m_wndRatio.SetItemData (m_wndRatio.GetCount () - 1, 100);
	m_wndRatio.AddString ("150 %"); m_wndRatio.SetItemData (m_wndRatio.GetCount () - 1, 150);
	m_wndRatio.AddString ("200 %"); m_wndRatio.SetItemData (m_wndRatio.GetCount () - 1, 200);
	m_wndRatio.AddString ("300 %"); m_wndRatio.SetItemData (m_wndRatio.GetCount () - 1, 300);
	m_wndRatio.AddString ("500 %"); m_wndRatio.SetItemData (m_wndRatio.GetCount () - 1, 500);
	m_wndRatio.AddString ("1000 %"); m_wndRatio.SetItemData (m_wndRatio.GetCount () - 1, 1000);

	m_wndRatio.SetCurSel (1);

	if (fReqRatio != -1)
	{
		CheckRadioButton (IDC_UNLIMITED_SEEDING, IDC_LIMIT_BY_RATIO, 
			fReqRatio ? IDC_LIMIT_BY_RATIO : IDC_UNLIMITED_SEEDING);
	}

	if (fReqRatio)
	{
		m_wndRatio.SetCurSel (-1);
		for (int i = 0; i < m_wndRatio.GetCount (); i++)
		{
			if (m_wndRatio.GetItemData (i) == UINT (fReqRatio * 100))
			{
				m_wndRatio.SetCurSel (i);
				break;
			}
		}
	}
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CBtDld_Seeding::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_ENABLE_SEEDING, L_ENABLE_SEEDING_HR),
		fsDlgLngInfo (IDC_UNLIMITED_SEEDING, L_UNLIMITED_SEEDING),
		fsDlgLngInfo (IDC_LIMIT_BY_RATIO, L_LIMIT_BY_RATIO),
		fsDlgLngInfo (IDC_STATIC0, L_SEED_UNTIL_RATIO_WILL_BE),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CBtDld_Seeding::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_ENABLE_SEEDING) != BST_UNCHECKED;

	GetDlgItem (IDC_UNLIMITED_SEEDING)->EnableWindow (b);
	GetDlgItem (IDC_LIMIT_BY_RATIO)->EnableWindow (b);

	BOOL b2 = IsDlgButtonChecked (IDC_LIMIT_BY_RATIO) == BST_CHECKED;
	GetDlgItem (IDC_STATIC0)->EnableWindow (b && b2);
	GetDlgItem (IDC_RATIO_LIST)->EnableWindow (b && b2);
}

void CBtDld_Seeding::OnEnableSeeding() 
{
	if (IsDlgButtonChecked (IDC_ENABLE_SEEDING) == BST_INDETERMINATE)
		CheckDlgButton (IDC_ENABLE_SEEDING, BST_UNCHECKED);
	SetModified ();
	UpdateEnabled ();
}

void CBtDld_Seeding::OnUnlimitedSeeding() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CBtDld_Seeding::OnLimitByRatio() 
{
	SetModified ();
	UpdateEnabled ();	
}

BOOL CBtDld_Seeding::OnApply() 
{
	if (IsDlgButtonChecked (IDC_ENABLE_SEEDING) != BST_INDETERMINATE)
	{
		BOOL b = IsDlgButtonChecked (IDC_ENABLE_SEEDING) == BST_CHECKED;
		for (size_t i = 0; i < m_pvDlds->size (); i++)
			m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->EnableSeeding (b);
	}

	if (IsDlgButtonChecked (IDC_UNLIMITED_SEEDING) == BST_CHECKED)
	{
		for (size_t i = 0; i < m_pvDlds->size (); i++)
			m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->setRequiredRatio (0);
	}
	else if (IsDlgButtonChecked (IDC_LIMIT_BY_RATIO) == BST_CHECKED)
	{
		int nCur = m_wndRatio.GetCurSel ();
		if (nCur != CB_ERR)
		{
			float fReqRatio = (float)m_wndRatio.GetItemData (nCur) / 100.0f;
			for (size_t i = 0; i < m_pvDlds->size (); i++)
				m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->setRequiredRatio (fReqRatio);
		}
	}
	
	return CPropertyPage::OnApply();
}

void CBtDld_Seeding::OnSelchangeRatioList() 
{
	SetModified ();	
}
