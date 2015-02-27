/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_CommunityPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloaderProperties_CommunityPage, CPropertyPage)

CDownloaderProperties_CommunityPage::CDownloaderProperties_CommunityPage() : CPropertyPage(CDownloaderProperties_CommunityPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_FDMCOMMUNITY);
}

CDownloaderProperties_CommunityPage::~CDownloaderProperties_CommunityPage()
{
}

void CDownloaderProperties_CommunityPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_CommunityPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_CommunityPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_CommunityPage)
	ON_BN_CLICKED(IDC_SWITCHTOOPINIONS, OnSwitchtoopinions)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_CHECKIFMAL, OnCheckifmal)
	ON_BN_CLICKED(IDC_DISPLAYOPINIONS, OnDisplayopinions)
	ON_EN_CHANGE(IDC_MALREPSMINIMUM, OnChangeMalrepsminimum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_CommunityPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	CheckDlgButton (IDC_SWITCHTOOPINIONS, _App.Community_SwitchToOpinions () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_CHECKIFMAL, _App.Community_CheckIfMalBeforeDlding () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DISPLAYOPINIONS, _App.Community_DisplayOpinionsAtDlding () ? BST_CHECKED : BST_UNCHECKED);

	SetDlgItemInt (IDC_MALREPSMINIMUM, _App.Community_MalReportsMinPerc ());

	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

BOOL CDownloaderProperties_CommunityPage::OnApply() 
{
	_App.Community_SwitchToOpinions (IsDlgButtonChecked (IDC_SWITCHTOOPINIONS) == BST_CHECKED);
	_App.Community_DisplayOpinionsAtDlding (IsDlgButtonChecked (IDC_DISPLAYOPINIONS) == BST_CHECKED);
	BOOL b = IsDlgButtonChecked (IDC_CHECKIFMAL) == BST_CHECKED;
	_App.Community_CheckIfMalBeforeDlding (b);
	if (b)
		_App.Community_MalReportsMinPerc (GetDlgItemInt (IDC_MALREPSMINIMUM));
	
	return CPropertyPage::OnApply();
}

void CDownloaderProperties_CommunityPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_SWITCHTOOPINIONS, L_SWITCHTOOPINIONS),
		fsDlgLngInfo (IDC_CHECKIFMAL, L_CHECKNEWDLDIFITISMALICIOUS),
		fsDlgLngInfo (IDC_DISPLAYOPINIONS, L_DISPLAYOPINIONSWHENDOWNLOADING),
		fsDlgLngInfo (IDC__S0, L_CONSIDER_DLD_AS_MAL_IF_MIN_0),
		fsDlgLngInfo (IDC__S1, L_CONSIDER_DLD_AS_MAL_IF_MIN_1),
	};

	_LngMgr.ApplyLanguage (	this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloaderProperties_CommunityPage::OnSwitchtoopinions() 
{
	SetModified ();	
}

void CDownloaderProperties_CommunityPage::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDownloaderProperties_CommunityPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_CommunityPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_CommunityPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_SWITCHTOOPINIONS, LS (L_SWITCHTOOPINIONS_HERE)),
		fsCtrlContextHelp (IDC_CHECKIFMAL, LS (L_CHECKNEWDLDIFITISMALICIOUS_HERE)),
		fsCtrlContextHelp (IDC_DISPLAYOPINIONS, LS (L_DISPLAYOPINIONSWHENDOWNLOADING_HERE)),
	};

	static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDownloaderProperties_CommunityPage::OnCheckifmal() 
{
	SetModified ();	
	UpdateEnabled ();
}

void CDownloaderProperties_CommunityPage::OnDisplayopinions() 
{
	SetModified ();	
}

void CDownloaderProperties_CommunityPage::OnChangeMalrepsminimum() 
{
	SetModified ();
}

void CDownloaderProperties_CommunityPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_CHECKIFMAL) == BST_CHECKED;
	GetDlgItem (IDC__S0)->EnableWindow (b);
	GetDlgItem (IDC__S1)->EnableWindow (b);
	GetDlgItem (IDC_MALREPSMINIMUM)->EnableWindow (b);
}
