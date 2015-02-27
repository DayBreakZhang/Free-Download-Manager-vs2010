/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_GeneralPage.h"
#include "MainFrm.h"
#include "Prg_GeneralPage_FWDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPrg_GeneralPage, CPropertyPage)

CPrg_GeneralPage::CPrg_GeneralPage() : CPropertyPage(CPrg_GeneralPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

CPrg_GeneralPage::~CPrg_GeneralPage()
{
}

void CPrg_GeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_GeneralPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_GeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrg_GeneralPage)
	ON_BN_CLICKED(IDC_AUTOSTART, OnAutostart)
	ON_BN_CLICKED(IDC_STARTMINIMIZED, OnStartminimized)
	ON_BN_CLICKED(IDC_MINTOTRAY, OnMintotray)
	ON_BN_CLICKED(IDC_CLOSEASMINIMIZE, OnCloseasminimize)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_MODIFYIEUSERAGENT, OnModifyieuseragent)
	ON_BN_CLICKED(IDC_ADJUST_FW, OnAdjustFw)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_GeneralPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	
	CheckDlgButton (IDC_AUTOSTART, _AutorunMgr.IsAutoStart () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_STARTMINIMIZED, _App.Prg_StartMinimized () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_MINTOTRAY, pFrame->m_bMinToTray ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_CLOSEASMINIMIZE, pFrame->m_bCloseAsMinimize ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_MODIFYIEUSERAGENT, _App.ModifyIEUserAgent () ? BST_CHECKED : BST_UNCHECKED);

	m_dlgFW.m_bDropBox = _App.View_FloatingWindow ();
	m_dlgFW.m_bInfoWnd = _App.View_FloatingInfoWindow ();
	m_dlgFW.m_bHideInFs = _App.FloatingWndsHideInFSMode ();
	m_dlgFW.m_DropBoxTrancparency = _App.DropBoxWndBlend ();
	m_dlgFW.m_InfoWndTrancparency = _App.DownloadsInfoWndBlend ();

	m_bAutostartChanged = FALSE;

	ApplyLanguage ();
	
	return TRUE;
}

void CPrg_GeneralPage::OnAutostart() 
{
	SetModified ();
	m_bAutostartChanged = TRUE;
}

void CPrg_GeneralPage::OnStartminimized() 
{
	SetModified ();	
}

void CPrg_GeneralPage::OnMintotray() 
{
	SetModified ();	
}

void CPrg_GeneralPage::OnCloseasminimize() 
{
	SetModified ();	
}

BOOL CPrg_GeneralPage::OnApply() 
{
	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	BOOL b = IsDlgButtonChecked (IDC_AUTOSTART) == BST_CHECKED;
	if (m_bAutostartChanged && FALSE == _AutorunMgr.SetAutoStart (b))
	{
		CheckDlgButton (IDC_AUTOSTART, !b ? BST_CHECKED : BST_UNCHECKED);
		m_bAutostartChanged = FALSE;
	}
    
	_App.Prg_StartMinimized (IsDlgButtonChecked (IDC_STARTMINIMIZED) == BST_CHECKED);

	pFrame->m_pFloatWndsThread->m_wndFloating.Show (m_dlgFW.m_bDropBox);
	if (m_dlgFW.m_bInfoWnd)
	{
		_App.View_FloatingInfoWindow (TRUE);
		_pwndDownloads->UpdateTrayIconPlusOthers ();
	}
	else
	{
		pFrame->m_pFloatWndsThread->m_wndFloatingInfo.TurnOffWindow ();
	}

	_App.DropBoxWndBlend (m_dlgFW.m_DropBoxTrancparency);
	pFrame->m_pFloatWndsThread->m_wndFloating.SetBlend (m_dlgFW.m_DropBoxTrancparency);

	_App.DownloadsInfoWndBlend (m_dlgFW.m_InfoWndTrancparency);
	pFrame->m_pFloatWndsThread->m_wndFloatingInfo.SetBlend (m_dlgFW.m_InfoWndTrancparency);

	_App.FloatingWndsHideInFSMode (m_dlgFW.m_bHideInFs);
	pFrame->m_pFloatWndsThread->m_wndFloating.UpdateTimer ();	

	pFrame->m_bCloseAsMinimize = IsDlgButtonChecked (IDC_CLOSEASMINIMIZE) == BST_CHECKED;
	pFrame->m_bMinToTray = IsDlgButtonChecked (IDC_MINTOTRAY) == BST_CHECKED;
	
	return CPropertyPage::OnApply();
}

void CPrg_GeneralPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CPrg_GeneralPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CPrg_GeneralPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__STARTUP, L_STARTUP),
		fsDlgLngInfo (IDC_AUTOSTART, L_AUTOSTART),
		fsDlgLngInfo (IDC_STARTMINIMIZED, L_STARTMINIMIZED),
		fsDlgLngInfo (IDC__SYSTEM, L_SYSTEM),
		fsDlgLngInfo (IDC_MINTOTRAY, L_MINTOTRAY),
		fsDlgLngInfo (IDC_CLOSEASMINIMIZE, L_CLOSEASMINIMIZE),
		fsDlgLngInfo (IDC_ADJUST_FW, L_ADJUST_FW),
		fsDlgLngInfo (IDC_MODIFYIEUSERAGENT, L_MODIFYIEUSERAGENT),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CPrg_GeneralPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_AUTOSTART, LS (L_AUTOSTARTHERE)),
		fsCtrlContextHelp (IDC_STARTMINIMIZED, LS (L_STARTMINIMIZEDHERE)),
		fsCtrlContextHelp (IDC_MINTOTRAY, LS (L_MINTOTRAYHERE)),
		fsCtrlContextHelp (IDC_CLOSEASMINIMIZE, LS (L_CLOSEASMINHERE)),
		fsCtrlContextHelp (IDC_MODIFYIEUSERAGENT, LS (L_MODIFYIEUSERAGENT_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CPrg_GeneralPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CPrg_GeneralPage::OnModifyieuseragent() 
{
	SetModified ();	
}

void CPrg_GeneralPage::OnAdjustFw() 
{
	if (IDOK == _DlgMgr.DoModal (&m_dlgFW))
		SetModified ();
}

void CPrg_GeneralPage::OnCancel() 
{
	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloating.SetBlend (_App.DropBoxWndBlend ());
	pFrame->m_pFloatWndsThread->m_wndFloatingInfo.SetBlend (_App.DownloadsInfoWndBlend ());
	
	CPropertyPage::OnCancel();
}
