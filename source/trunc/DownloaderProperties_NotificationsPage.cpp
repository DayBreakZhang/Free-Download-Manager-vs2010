/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_NotificationsPage.h"
#include "DlgSounds.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloaderProperties_NotificationsPage, CPropertyPage)

CDownloaderProperties_NotificationsPage::CDownloaderProperties_NotificationsPage() : CPropertyPage(CDownloaderProperties_NotificationsPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_NOTIFICATIONS);
}

CDownloaderProperties_NotificationsPage::~CDownloaderProperties_NotificationsPage()
{
}

void CDownloaderProperties_NotificationsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_NotificationsPage)
	DDX_Control(pDX, IDC_TIMEOUTSPIN, m_wndTSpin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_NotificationsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_NotificationsPage)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_EN_CHANGE(IDC_TIMEOUT, OnChangeTimeout)
	ON_BN_CLICKED(IDC_USEBALLOON, OnUseballoon)
	ON_BN_CLICKED(IDC_USESOUNDS, OnUsesounds)
	ON_BN_CLICKED(IDC_CUSTOMIZE, OnCustomize)
	ON_BN_CLICKED(IDC_DISABLEFORBATCHDLDS, OnDisableforbatchdlds)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_NotificationsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_wndTSpin.SetRange (1, UD_MAXVAL);

	CheckDlgButton (IDC_USEBALLOON, _App.Notif_UseBalloon () ? BST_CHECKED : BST_UNCHECKED);
	SetDlgItemInt (IDC_TIMEOUT, _App.Notif_BalloonTimeout ());

	CheckDlgButton (IDC_USESOUNDS, _App.Snd_Use () ? BST_CHECKED : BST_UNCHECKED);
	
	CheckDlgButton (IDC_DISABLEFORBATCHDLDS, _App.Notif_DisableForBatchDownloads () ? BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CDownloaderProperties_NotificationsPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USEBALLOON, L_USEBALLOONS),
		fsDlgLngInfo (IDC__TIMEOUT, L_TIMEOUT),
		fsDlgLngInfo (IDC__SEC, L_SECS),
		fsDlgLngInfo (IDC_USESOUNDS, L_USESOUNDS),
		fsDlgLngInfo (IDC_CUSTOMIZE, L_CUSTOMIZE),
		fsDlgLngInfo (IDC_DISABLEFORBATCHDLDS, L_DISABLENOTIFICATIONSFORBATCHDLDS),
	};

	_LngMgr.ApplyLanguage (	this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloaderProperties_NotificationsPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDownloaderProperties_NotificationsPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_NotificationsPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_NotificationsPage::PrepareCHMgr(CPoint point)
{
	static CString _strDisableForBatchDlds;
	_strDisableForBatchDlds.Format (LS (L_DISABLENOTIFICATIONSFORBATCHDLDS_HERE),
		LS (L_CREATEBATCHDLD));
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_USEBALLOON, LS (L_USEBALLOONSHERE)),
		fsCtrlContextHelp (IDC__TIMEOUT, LS (L_BALLOONTIMEOUTHERE)),
		fsCtrlContextHelp (IDC_TIMEOUT, LS (L_BALLOONTIMEOUTHERE)),
		fsCtrlContextHelp (IDC_USESOUNDS, LS (L_USESOUNDSHERE)),
		fsCtrlContextHelp (IDC_CUSTOMIZE, LS (L_CUSTOMIZESOUNDSHERE)),
		fsCtrlContextHelp (IDC_DISABLEFORBATCHDLDS, _strDisableForBatchDlds),
	};

	static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CDownloaderProperties_NotificationsPage::OnChangeTimeout() 
{
	SetModified ();
}

void CDownloaderProperties_NotificationsPage::OnUseballoon() 
{
	if (GetShell32Version () < 5)
	{
		MessageBox (LS (L_AVAILON2000), LS (L_ERR), MB_ICONEXCLAMATION);
		CheckDlgButton (IDC_USEBALLOON, BST_UNCHECKED);
		return;
	}
	
	SetModified ();
	UpdateEnabled ();
}

void CDownloaderProperties_NotificationsPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USEBALLOON) == BST_CHECKED;

	GetDlgItem (IDC__TIMEOUT)->EnableWindow (b);
	GetDlgItem (IDC_TIMEOUT)->EnableWindow (b);
	GetDlgItem (IDC_TIMEOUTSPIN)->EnableWindow (b);
	GetDlgItem (IDC__SEC)->EnableWindow (b);

	GetDlgItem (IDC_CUSTOMIZE)->EnableWindow (
		IsDlgButtonChecked (IDC_USESOUNDS) == BST_CHECKED);
}

BOOL CDownloaderProperties_NotificationsPage::OnApply() 
{
	_App.Notif_UseBalloon (IsDlgButtonChecked (IDC_USEBALLOON) == BST_CHECKED);
	_App.Notif_BalloonTimeout (GetDlgItemInt (IDC_TIMEOUT));
	
	_App.Snd_Use (IsDlgButtonChecked (IDC_USESOUNDS) == BST_CHECKED);
	_Snds.ReadSettings ();

	_App.Notif_DisableForBatchDownloads (IsDlgButtonChecked (IDC_DISABLEFORBATCHDLDS) == BST_CHECKED);
	
	return CPropertyPage::OnApply();
}

void CDownloaderProperties_NotificationsPage::OnUsesounds() 
{
	SetModified ();
	UpdateEnabled ();
}

void CDownloaderProperties_NotificationsPage::OnCustomize() 
{
	CDlgSounds dlg;
	_DlgMgr.DoModal (&dlg);
}

void CDownloaderProperties_NotificationsPage::OnDisableforbatchdlds() 
{
	SetModified ();
}
