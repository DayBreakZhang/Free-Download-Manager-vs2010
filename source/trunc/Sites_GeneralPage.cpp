/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Sites_GeneralPage.h"
#include "GroupDlg.h"
#include "DownloadsWnd.h"
#include "inetutil.h"
#include "fsSitesMgr.h"

extern CDownloadsWnd *_pwndDownloads;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSites_GeneralPage, CPropertyPage)

CSites_GeneralPage::CSites_GeneralPage() : CPropertyPage(CSites_GeneralPage::IDD),
	m_bIsAddingSite(false)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

CSites_GeneralPage::~CSites_GeneralPage()
{
}

void CSites_GeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSites_GeneralPage)
	DDX_Control(pDX, IDC_MAXCONNSSPIN, m_wndMaxConnsSpin);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_SITE, m_wndSite);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSites_GeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSites_GeneralPage)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_BN_CLICKED(IDC_USEMAXCONNS, OnUsemaxconns)
	ON_BN_CLICKED(IDC_USEDEFGROUP, OnUsedefgroup)
	ON_BN_CLICKED(IDC_USEFTPPASSIVE, OnUseftppassive)
	ON_CBN_EDITCHANGE(IDC_SITE, OnEditchangeSite)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_EN_CHANGE(IDC_MAXCONNS, OnChangeMaxconns)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_CBN_SELCHANGE(IDC_SITE, OnSelchangeSite)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_DONTSENDLIST2, OnDontsendlist2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSites_GeneralPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));

	
	for (int i = 0; i < _LastUrlPaths.GetRecordCount (); i++)
		m_wndSite.AddString (_LastUrlPaths.GetRecord (i));

	m_wndGroups.Fill ();

	m_wndMaxConnsSpin.SetRange (1, UD_MAXVAL);

	if (m_pSite->strName != NULL)
		SetDlgItemText (IDC_SITE, m_pSite->strName);

	if (m_pSite->strUser)
	{
		CheckDlgButton (IDC_USELOGIN, BST_CHECKED);
		SetDlgItemText (IDC_USER, m_pSite->strUser);
		if (m_pSite->strPassword)
			SetDlgItemText (IDC_PASSWORD, m_pSite->strPassword);
	}

	if (m_pSite->cMaxConns != UINT_MAX)
	{
		CheckDlgButton (IDC_USEMAXCONNS, BST_CHECKED);
		SetDlgItemInt (IDC_MAXCONNS, m_pSite->cMaxConns);
	}
	else
		SetDlgItemInt (IDC_MAXCONNS, 1);

	if (m_pSite->pGroup == NULL)
	{
		m_wndGroups.SelectGroupById (_App.CreateDld_IdOfLastGrpSelected ());
	}
	else
	{
		CheckDlgButton (IDC_USEDEFGROUP, BST_CHECKED);
		m_wndGroups.SelectGroup (m_pSite->pGroup);
	}

	CheckDlgButton (IDC_USEFTPPASSIVE, m_pSite->dwFtpFlags & FTP_USEPASSIVEMODE ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DONTSENDLIST2, m_pSite->dwFtpFlags & FTP_DONTSENDLIST ? BST_CHECKED : BST_UNCHECKED);
	
	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CSites_GeneralPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;
	GetDlgItem (IDC__USER)->EnableWindow (b);
	GetDlgItem (IDC_USER)->EnableWindow (b);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (b);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_USEMAXCONNS);
	GetDlgItem (IDC_MAXCONNS)->EnableWindow (b);
	GetDlgItem (IDC_MAXCONNSSPIN)->EnableWindow (b);

	b = IsDlgButtonChecked (IDC_USEDEFGROUP);
	GetDlgItem (IDC_GROUPS)->EnableWindow (b);
	GetDlgItem (IDC_CREATEGROUP)->EnableWindow (b);
}

void CSites_GeneralPage::OnUselogin() 
{
	SetModified ();
	UpdateEnabled ();
}

void CSites_GeneralPage::OnUsemaxconns() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CSites_GeneralPage::OnUsedefgroup() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CSites_GeneralPage::OnUseftppassive() 
{
	SetModified ();	
}

void CSites_GeneralPage::OnEditchangeSite() 
{
	SetModified ();	
}

void CSites_GeneralPage::OnChangeUser() 
{
	SetModified ();	
}

void CSites_GeneralPage::OnChangePassword() 
{
	SetModified ();	
}

void CSites_GeneralPage::OnChangeMaxconns() 
{
	SetModified ();	
}

void CSites_GeneralPage::OnSelchangeGroups() 
{
	SetModified ();	
}

void CSites_GeneralPage::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
		OnSelchangeGroups ();
}

void CSites_GeneralPage::OnSelchangeSite() 
{
	SetModified ();	
}

BOOL CSites_GeneralPage::OnApply() 
{
	CString strSite, strUser, strPassword;
	UINT cMaxConns;
	vmsDownloadsGroupSmartPtr pGroup;

	GetDlgItemText (IDC_SITE, strSite);

	if (strSite.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERSITE), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_SITE)->SetFocus ();
		return FALSE;
	}

	fsURL url;
	if (IR_SUCCESS == url.Crack (strSite))
	{
		strSite = url.GetHostName ();
		SetDlgItemText (IDC_SITE, strSite);
		if (*url.GetUserName ())
		{
			CheckDlgButton (IDC_USELOGIN, BST_CHECKED);
			SetDlgItemText (IDC_USER, url.GetUserName ());
			if (url.GetPassword ())
				SetDlgItemText (IDC_PASSWORD, url.GetPassword ());
		}

		
		if (m_advanced->IsUserChangedProtocols () == FALSE)
		{
			
			m_pSite->dwValidFor &= ~ (SITE_VALIDFOR_HTTP|SITE_VALIDFOR_HTTPS|SITE_VALIDFOR_FTP);
			m_pSite->dwValidFor |= fsNPToSiteValidFor (fsSchemeToNP (url.GetInternetScheme ()));
			if (!m_bIsAddingSite)
				_SitesMgr.setDirty();
			m_advanced->ToDialog ();	
		}

		UpdateEnabled ();
	}

	
	m_advanced->FromDialog ();

	DWORD dwVF = m_pSite->dwValidFor;
	dwVF &= ~ SITE_VALIDFOR_SUBDOMAINS; 
	fsSiteInfo *pNewSite = _SitesMgr.FindSite (strSite, dwVF, FALSE);

	
	if (pNewSite != NULL && pNewSite != m_pSite)
	{
		MessageBox (LS (L_SITEALREXISTS), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_SITE)->SetFocus ();
		return FALSE;
	}

	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED)
	{
		GetDlgItemText (IDC_USER, strUser);
		GetDlgItemText (IDC_PASSWORD, strPassword);

		if (strUser.GetLength () == 0)
		{
			MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
			GetDlgItem (IDC_USER)->SetFocus ();
			return FALSE;
		}
	}

	if (IsDlgButtonChecked (IDC_USEMAXCONNS) == BST_CHECKED)
	{
		cMaxConns = GetDlgItemInt (IDC_MAXCONNS);
		if (cMaxConns == 0)
		{
			MessageBox (LS (L_MAXCONNSMUST), LS (L_INPERR), MB_ICONEXCLAMATION);
			GetDlgItem (IDC_MAXCONNS)->SetFocus ();
			return FALSE;
		}
	}
	else
		cMaxConns = UINT_MAX;

	if (IsDlgButtonChecked (IDC_USEDEFGROUP) == BST_CHECKED)
	{
		pGroup = m_wndGroups.GetSelectedGroup ();
	}

	m_pSite->dwFtpFlags = 0;

	if (IsDlgButtonChecked (IDC_USEFTPPASSIVE) == BST_CHECKED)
		m_pSite->dwFtpFlags |= FTP_USEPASSIVEMODE;
	if (IsDlgButtonChecked (IDC_DONTSENDLIST2) == BST_CHECKED)
		m_pSite->dwFtpFlags |= FTP_DONTSENDLIST;

	m_pSite->strName = strSite;
	m_pSite->cMaxConns = cMaxConns;
	m_pSite->pGroup = pGroup;
	if (strUser.GetLength ()) 
		m_pSite->strUser = strUser; 
	else 
		m_pSite->strUser = NULL;
	if (strPassword.GetLength ()) 
		m_pSite->strPassword = strPassword; 
	else 
		m_pSite->strPassword = NULL;

	if (!m_bIsAddingSite)
		_SitesMgr.setDirty();

	return CPropertyPage::OnApply();
}

void CSites_GeneralPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSites_GeneralPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CSites_GeneralPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USELOGIN, L_LOGINREQ),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_USEMAXCONNS, L_MAXSITECONNS),
		fsDlgLngInfo (IDC_USEDEFGROUP, L_USEDEFGRP),
		fsDlgLngInfo (IDC_USEFTPPASSIVE, L_USESITEFTPPASSIVE),
		fsDlgLngInfo (IDC_DONTSENDLIST2, L_DONTRETRFILEDATEFROMSERV),
	};

	CString str; str = LS (L_SITENAME); str += ':';
	SetDlgItemText (IDC__SITE, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CSites_GeneralPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__SITE, LS (L_SITEHERE)),
		fsCtrlContextHelp (IDC_SITE, LS (L_SITEHERE)),
		fsCtrlContextHelp (IDC_USELOGIN,LS (L_LOGINHERE)),
		fsCtrlContextHelp (IDC__USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC_USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC__PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_USEMAXCONNS, LS (L_MAXCONNSHERE2)),
		fsCtrlContextHelp (IDC_USEDEFGROUP, LS (L_USEDEFGRPHERE)),
		fsCtrlContextHelp (IDC_CREATEGROUP, LS (L_CREATEGRP)),
		fsCtrlContextHelp (IDC_USEFTPPASSIVE, LS (L_USEPASSIVEMODEHERE)),
		fsCtrlContextHelp (IDC_DONTSENDLIST2, LS (L_DONTRETRFILEDATEFROMSERV_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CSites_GeneralPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CSites_GeneralPage::OnDontsendlist2() 
{
	SetModified ();	
}

void  CSites_GeneralPage::SetMode(bool bIsAddingSite)
{
	m_bIsAddingSite = bIsAddingSite;
}
