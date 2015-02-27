/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Sites_AdvancedPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSites_AdvancedPage, CPropertyPage)

CSites_AdvancedPage::CSites_AdvancedPage() : CPropertyPage(CSites_AdvancedPage::IDD),
	m_bIsAddingSite(false)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_ADVANCED);
	m_bDialogWasInited = FALSE;
}

CSites_AdvancedPage::~CSites_AdvancedPage()
{
}

void CSites_AdvancedPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSites_AdvancedPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSites_AdvancedPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSites_AdvancedPage)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_VALIDHTTP, OnValidhttp)
	ON_BN_CLICKED(IDC_VALIDHTTPS, OnValidhttps)
	ON_BN_CLICKED(IDC_VALIDFTP, OnValidftp)
	ON_BN_CLICKED(IDC_VALIDSUBDOMAINS, OnValidsubdomains)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSites_AdvancedPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_bDialogWasInited = TRUE;
	ToDialog ();
	m_bUserChangedProtocols = FALSE;
	
	ApplyLanguage ();
	return TRUE;  
	              
}

BOOL CSites_AdvancedPage::OnApply() 
{
	BOOL bAtLeast1Protocol = FALSE;
	DWORD dwVF = 0;

	if (IsDlgButtonChecked (IDC_VALIDHTTP) == BST_CHECKED)
	{
		dwVF |= SITE_VALIDFOR_HTTP;
		bAtLeast1Protocol = TRUE;
	}

	if (IsDlgButtonChecked (IDC_VALIDHTTPS) == BST_CHECKED)
	{
		dwVF |= SITE_VALIDFOR_HTTPS;
		bAtLeast1Protocol = TRUE;
	}

	if (IsDlgButtonChecked (IDC_VALIDFTP) == BST_CHECKED)
	{
		dwVF |= SITE_VALIDFOR_FTP;
		bAtLeast1Protocol = TRUE;
	}

	fsSiteInfo *pNewSite = _SitesMgr.FindSite (m_pSite->strName, dwVF, FALSE);

	
	if (pNewSite != NULL && pNewSite != m_pSite)
	{
		MessageBox (LS (L_SITEALREXISTS), LS (L_INPERR), MB_ICONEXCLAMATION);
		return FALSE;
	}

	if (IsDlgButtonChecked (IDC_VALIDSUBDOMAINS) == BST_CHECKED)
		dwVF |= SITE_VALIDFOR_SUBDOMAINS;

	if (bAtLeast1Protocol == FALSE)
	{
		MessageBox (LS (L_ENTERATLEAST1PROTOCOL), LS (L_INPERR), MB_ICONEXCLAMATION);
		return FALSE;
	}

	m_pSite->dwValidFor = dwVF;
	if (!m_bIsAddingSite)
		_SitesMgr.setDirty();

	return CPropertyPage::OnApply();
}

void CSites_AdvancedPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__VALIDFOR, L_VALIDFOR),
		fsDlgLngInfo (IDC_VALIDSUBDOMAINS, L_VALIDFORSUBDOMAINS),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CSites_AdvancedPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSites_AdvancedPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CSites_AdvancedPage::OnValidhttp() 
{
	m_bUserChangedProtocols = TRUE;
	SetModified ();	
}

void CSites_AdvancedPage::OnValidhttps() 
{
	m_bUserChangedProtocols = TRUE;
	SetModified ();	
}

void CSites_AdvancedPage::OnValidftp() 
{
	m_bUserChangedProtocols = TRUE;
	SetModified ();	
}

void CSites_AdvancedPage::OnValidsubdomains() 
{
	SetModified ();	
}

BOOL CSites_AdvancedPage::IsUserChangedProtocols()
{
	return m_bUserChangedProtocols;
}

void CSites_AdvancedPage::FromDialog()
{
 	if (m_bDialogWasInited)
 		OnApply ();
}

void CSites_AdvancedPage::ToDialog()
{
	if (m_bDialogWasInited == FALSE)
		return;

	CheckDlgButton (IDC_VALIDHTTP, m_pSite->dwValidFor & SITE_VALIDFOR_HTTP);
	CheckDlgButton (IDC_VALIDHTTPS, m_pSite->dwValidFor & SITE_VALIDFOR_HTTPS);
	CheckDlgButton (IDC_VALIDFTP, m_pSite->dwValidFor & SITE_VALIDFOR_FTP);
	CheckDlgButton (IDC_VALIDSUBDOMAINS, m_pSite->dwValidFor & SITE_VALIDFOR_SUBDOMAINS);
}

void CSites_AdvancedPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_VALIDHTTP, LS (L_VALIDHTTPHERE)),
		fsCtrlContextHelp (IDC_VALIDHTTPS, LS (L_VALIDHTTPSHERE)),
		fsCtrlContextHelp (IDC_VALIDFTP, LS (L_VALIDFTPHERE)),
		fsCtrlContextHelp (IDC_VALIDSUBDOMAINS, LS (L_VALIDSUBDOMAINSHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CSites_AdvancedPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void  CSites_AdvancedPage::SetMode(bool bIsAddingSite)
{
	m_bIsAddingSite = bIsAddingSite;
}
