/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WPDS_GeneralPage.h"
#include "DownloadsWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd *_pwndDownloads;

IMPLEMENT_DYNCREATE(CWPDS_GeneralPage, CPropertyPage)

CWPDS_GeneralPage::CWPDS_GeneralPage() : CPropertyPage(CWPDS_GeneralPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

CWPDS_GeneralPage::~CWPDS_GeneralPage()
{
}

void CWPDS_GeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWPDS_GeneralPage)
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWPDS_GeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CWPDS_GeneralPage)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWPDS_GeneralPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_wndGroups.Fill ();

	m_wndGroups.SelectGroup (m_wpds->pDLGroup);

	SetDlgItemText (IDC_URL, m_wpd->GetRootPage ()->GetData ()->strURL);
	SetDlgItemText (IDC_SAVEDIN, m_wpds->strFolderSaveTo);

	ReadAuthorization ();

	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

BOOL CWPDS_GeneralPage::OnApply() 
{
	if (FALSE == WriteAuthorization ())
		return FALSE;

	vmsDownloadsGroupSmartPtr pGroup = m_wndGroups.GetSelectedGroup ();

	if (pGroup->nId != m_wpds->pDLGroup->nId)
	{
		m_wpds->pDLGroup = pGroup;
		if (m_wpds->m_ppoOwner)
			m_wpds->m_ppoOwner->setDirty();
		for (int i = 0; i < m_wpd->GetDownloadCount (); i++) {
			m_wpd->GetDownload (i)->pGroup = pGroup;
			m_wpd->GetDownload (i)->setDirty();
		}

		_pwndDownloads->OnDownloadsGroupChanged ();
	}
	
	return CPropertyPage::OnApply();
}

void CWPDS_GeneralPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GENERAL, L_GENERALINFO),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_USELOGIN, L_LOGINREQ),
		fsDlgLngInfo (IDC__SAVEDIN, L_SAVEDIN),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDC__URL, L_WEBPAGEURL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CWPDS_GeneralPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CWPDS_GeneralPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CWPDS_GeneralPage::OnSelchangeGroups() 
{
	SetModified ();	
}

void CWPDS_GeneralPage::UpdateEnabled()
{
	BOOL bE = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;

	GetDlgItem (IDC_USER)->EnableWindow (bE);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (bE);
	GetDlgItem (IDC__USER)->EnableWindow (bE);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (bE);
}

void CWPDS_GeneralPage::OnUselogin() 
{
	UpdateEnabled ();
	SetModified ();
}

void CWPDS_GeneralPage::OnChangeUser() 
{
	SetModified ();
}

void CWPDS_GeneralPage::OnChangePassword() 
{
	SetModified ();	
}

void CWPDS_GeneralPage::ReadAuthorization()
{
	if (m_wpds->strUserName.Length ())
	{
		SetDlgItemText (IDC_USER, m_wpds->strUserName);
		SetDlgItemText (IDC_PASSWORD, m_wpds->strPassword);
		CheckDlgButton (IDC_USELOGIN, BST_CHECKED);
	}
	else
	{
		CheckDlgButton (IDC_USELOGIN, BST_UNCHECKED);
	}
}

BOOL CWPDS_GeneralPage::WriteAuthorization()
{
	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED)
	{
		CString str;
		GetDlgItemText (IDC_USER, str);
		if (str == "")
		{
			MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
			CEdit *pE = (CEdit*) GetDlgItem (IDC_USER);
			pE->SetFocus ();
			pE->SetSel (0, -1);
			return FALSE;
		}

		m_wpds->strUserName = str;

		GetDlgItemText (IDC_PASSWORD, str);
		m_wpds->strPassword = str;
	}
	else
	{
		m_wpds->strUserName = "";
		m_wpds->strPassword = "";
	}

	if (m_wpds->m_ppoOwner)
		m_wpds->m_ppoOwner->setDirty();

	return TRUE;
}

void CWPDS_GeneralPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__URL, LS (L_STARTWEBPAGEURLHERE)),
		fsCtrlContextHelp (IDC_URL, LS (L_STARTWEBPAGEURLHERE)),
		fsCtrlContextHelp (IDC__USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC_USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC__PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_USELOGIN, LS (L_LOGINHERE)),
		fsCtrlContextHelp (IDC__GROUP, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC_GROUPS, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC__SAVEDIN, LS (L_SAVEDINHERE)),
		fsCtrlContextHelp (IDC_SAVEDIN, LS (L_SAVEDINHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CWPDS_GeneralPage::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	RECT rc;
	CWnd *pItem = GetDlgItem (pHelpInfo->iCtrlId);
	if (pItem == NULL)
		return TRUE;
	pItem->GetWindowRect (&rc);
	if (PtInRect (&rc, pHelpInfo->MousePos) == FALSE)
	{
		pHelpInfo->MousePos.x = rc.left + (rc.right - rc.left) / 2;
		pHelpInfo->MousePos.y = rc.top + (rc.bottom - rc.top) / 2;
	}
	PrepareCHMgr (pHelpInfo->MousePos);
	_CHMgr.OnWT ();
	return TRUE;
}
