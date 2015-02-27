/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_General_Misc.h"
#include "ShedulerWnd.h"
#include "MainFrm.h"

extern CShedulerWnd *_pwndScheduler;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_General_Misc::CDlg_Options_General_Misc(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_General_Misc::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_General_Misc)
		
	//}}AFX_DATA_INIT

	m_bHangupToutChanged = m_bExitToutChanged = m_bShutdownToutChanged = false;
	m_bDTAEChanged = false;
}

void CDlg_Options_General_Misc::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_General_Misc)
	DDX_Control(pDX, IDC_TRANCPARENCY2, m_wndBlend2);
	DDX_Control(pDX, IDC_TRANCPARENCY1, m_wndBlend1);
	DDX_Control(pDX, IDC_SHUTDOWN_TOUT, m_wndShutdownTout);
	DDX_Control(pDX, IDC_LAUNCHDLD_TOUT, m_wndLaunchDldTout);
	DDX_Control(pDX, IDC_HANGUP_TOUT, m_wndHangupTout);
	DDX_Control(pDX, IDC_EXIT_TOUT, m_wndExitTout);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_General_Misc, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_General_Misc)
	ON_CBN_SELCHANGE(IDC_HANGUP_TOUT, OnSelchangeHangupTout)
	ON_CBN_SELCHANGE(IDC_EXIT_TOUT, OnSelchangeExitTout)
	ON_CBN_SELCHANGE(IDC_SHUTDOWN_TOUT, OnSelchangeShutdownTout)
	ON_CBN_SELCHANGE(IDC_LAUNCHDLD_TOUT, OnSelchangeLaunchdldTout)
	ON_BN_CLICKED(IDC_DISABLEWDTASKAFTEREXEC, OnDisablewdtaskafterexec)
	ON_BN_CLICKED(IDC_DROPBOX, OnDropbox)
	ON_BN_CLICKED(IDC_DLINFO, OnDlinfo)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TRANCPARENCY1, OnCustomdrawTrancparency1)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_TRANCPARENCY2, OnCustomdrawTrancparency2)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_General_Misc::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	CComboBox* pboxes [] = {
		&m_wndHangupTout, &m_wndExitTout, &m_wndShutdownTout, &m_wndLaunchDldTout
	};
	
	for (int i = 0; i < sizeof (pboxes) / sizeof (CComboBox*); i++)
	{
		pboxes [i]->AddString (LS (L_DONTASKFORCONF));
		
		UINT aSecs [] = { 
			5, 15, 30, 60
		};
		for (int j = 0; j < sizeof (aSecs) / sizeof (UINT); j++)
		{
			CString str; 
			str.Format (LS (L_N_SECONDS), aSecs [j]);
			pboxes [i]->AddString (str);
		}
		
		pboxes [i]->AddString (LS (L_DISABLECONFTIMEOUT));
		
		UINT uTimeout;
		switch (i) {
		case 0: uTimeout = _App.ConfTimeout_Hangup (); break;
		case 1: uTimeout = _App.ConfTimeout_Exit (); break;
		case 2: uTimeout = _App.ConfTimeout_Shutdown (); break;
		case 3: uTimeout = _App.ConfTimeout_LaunchDld (); break;
		default: ASSERT (FALSE); uTimeout = 0; break;
		}
		
		SelectToutItem (pboxes [i], uTimeout);
	}
	
	CheckDlgButton (IDC_ASKFORST, _App.WD_LastShutdownType_DontAsk () ? BST_UNCHECKED : BST_CHECKED);
	CheckDlgButton (IDC_DISABLEWDTASKAFTEREXEC, _App.WD_DisableAfterExec () ? BST_CHECKED : BST_UNCHECKED);

	m_wndBlend1.SetRange (0, 255);
	m_wndBlend2.SetRange (0, 255);
	
	m_blend1 = _App.DropBoxWndBlend ();
	m_blend2 = _App.DownloadsInfoWndBlend ();
	
	m_wndBlend1.SetPos (255 - m_blend1);
	m_wndBlend2.SetPos (255 - m_blend2);
	UpdateBlendsVals ();
	
	CheckDlgButton (IDC_DROPBOX, _App.View_FloatingWindow () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DLINFO, _App.View_FloatingInfoWindow () ? BST_CHECKED : BST_UNCHECKED);	
	CheckDlgButton (IDC_HIDEFWWFS, _App.FloatingWndsHideInFSMode () ? BST_CHECKED : BST_UNCHECKED);
	
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_General_Misc::get_PageTitle()
{
	return LS (L_ESSENTIAL);
}

CString CDlg_Options_General_Misc::get_PageShortTitle()
{
	return LS (L_ESSENTIAL);
}

BOOL CDlg_Options_General_Misc::Apply()
{
	_App.WD_LastShutdownType_DontAsk (IsDlgButtonChecked (IDC_ASKFORST) == BST_UNCHECKED);
	
	_App.ConfTimeout_Hangup (GetTimeoutForToutItem (&m_wndHangupTout));
	_App.ConfTimeout_Exit (GetTimeoutForToutItem (&m_wndExitTout));
	_App.ConfTimeout_Shutdown (GetTimeoutForToutItem (&m_wndShutdownTout));
	_App.ConfTimeout_LaunchDld (GetTimeoutForToutItem (&m_wndLaunchDldTout));
	
	int pos = -1;
	if (m_bHangupToutChanged)
	{
		pos = -1;
		_pwndScheduler->HangupWhenDone (&pos);
		if (pos != -1)
		{
			m_bHangupToutChanged = false;
			_pwndScheduler->GetMgr ()->GetTask (pos)->uWaitForConfirmation = _App.ConfTimeout_Hangup ();
			_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
		}
	}
	
	if (m_bExitToutChanged)
	{
		pos = -1;
		_pwndScheduler->ExitWhenDone (&pos);
		if (pos != -1)
		{
			m_bExitToutChanged = false;
			_pwndScheduler->GetMgr ()->GetTask (pos)->uWaitForConfirmation = _App.ConfTimeout_Exit ();
			_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
		}
	}
	
	fsShutdownType enType = (fsShutdownType) _App.WD_LastShutdownType ();
	if (m_bShutdownToutChanged)
	{
		pos = -1;
		_pwndScheduler->TurnoffWhenDone (enType, &pos);
		if (pos != -1)
		{
			m_bShutdownToutChanged = false;
			_pwndScheduler->GetMgr ()->GetTask (pos)->uWaitForConfirmation = _App.ConfTimeout_Shutdown ();
			_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
		}
	}
	
	if (m_bDTAEChanged)
	{
		m_bDTAEChanged = false;
		BOOL bDis = IsDlgButtonChecked (IDC_DISABLEWDTASKAFTEREXEC) == BST_CHECKED;
		
		_App.WD_DisableAfterExec (bDis);
		
		_pwndScheduler->HangupWhenDone (&pos);
		if (pos != -1) {
			if (bDis)
				_pwndScheduler->GetMgr ()->GetTask (pos)->dwFlags |= SCHEDULE_AUTODIS;
			else
				_pwndScheduler->GetMgr ()->GetTask (pos)->dwFlags &= ~SCHEDULE_AUTODIS;
			_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
		}
		
		_pwndScheduler->ExitWhenDone (&pos);
		if (pos != -1) {
			if (bDis)
				_pwndScheduler->GetMgr ()->GetTask (pos)->dwFlags |= SCHEDULE_AUTODIS;
			else
				_pwndScheduler->GetMgr ()->GetTask (pos)->dwFlags &= ~SCHEDULE_AUTODIS;
			_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
		}
		
		_pwndScheduler->TurnoffWhenDone (enType, &pos);
		if (pos != -1) {
			if (bDis)
				_pwndScheduler->GetMgr ()->GetTask (pos)->dwFlags |= SCHEDULE_AUTODIS;
			else
				_pwndScheduler->GetMgr ()->GetTask (pos)->dwFlags &= ~SCHEDULE_AUTODIS;
			_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
		}
	}

	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;

	_App.FloatingWndsHideInFSMode (IsDlgButtonChecked (IDC_HIDEFWWFS) == BST_CHECKED);
	pFrame->m_pFloatWndsThread->m_wndFloating.UpdateTimer ();

	_App.View_FloatingWindow (IsDlgButtonChecked (IDC_DROPBOX) == BST_CHECKED);
	_App.View_FloatingInfoWindow (IsDlgButtonChecked (IDC_DLINFO) == BST_CHECKED);
	
	if (IsDlgButtonChecked (IDC_DROPBOX) == BST_CHECKED)
		_App.DropBoxWndBlend (m_blend1 = (BYTE) (255 - m_wndBlend1.GetPos ()));
	if (IsDlgButtonChecked (IDC_DLINFO) == BST_CHECKED)
		_App.DownloadsInfoWndBlend (m_blend2 = (BYTE) (255 - m_wndBlend2.GetPos ()));

	pFrame->m_pFloatWndsThread->m_wndFloating.Show (IsDlgButtonChecked (IDC_DROPBOX) == BST_CHECKED);
	if (IsDlgButtonChecked (IDC_DLINFO) == BST_CHECKED)
	{
		_App.View_FloatingInfoWindow (TRUE);
		_pwndDownloads->UpdateTrayIconPlusOthers ();
	}
	else
	{
		pFrame->m_pFloatWndsThread->m_wndFloatingInfo.TurnOffWindow ();
	}

	return TRUE;
}

void CDlg_Options_General_Misc::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TOUTSFORCONFS, L_TOUTSFORCONFS),
		fsDlgLngInfo (IDC__HANGUP, L_HANGUP),
		fsDlgLngInfo (IDC__EXIT, L_EXIT),
		fsDlgLngInfo (IDC__SHUTDOWN, L_SHUTDOWN),
		fsDlgLngInfo (IDC__LAUNCHDLD, L_LAUNCHDLD),
		fsDlgLngInfo (IDC_ASKFORST, L_ASKFORST),
		fsDlgLngInfo (IDC_DISABLEWDTASKAFTEREXEC, L_DISABLEWHENDONEAFTEREXEC),

		fsDlgLngInfo (IDC__FLOATING_WINDOWS, L_FLOATING_WINDOWS),
		fsDlgLngInfo (IDC_HIDEFWWFS, L_FLTWNDSHIDEINFSMODE),
		fsDlgLngInfo (IDC_DROPBOX, L_DROPBOX),
		fsDlgLngInfo (IDC_DLINFO, L_SHOWDLDSINFOWHILEDOWNLOADING),
		fsDlgLngInfo (IDC__TRANCPARENCY1, L_TRANCPARENCY, TRUE),
		fsDlgLngInfo (IDC__TRANCPARENCY2, L_TRANCPARENCY, TRUE),
			
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_General_Misc::SelectToutItem(CComboBox *pbox, UINT uTimeout)
{
	switch (uTimeout) {
	case 0: pbox->SetCurSel (0); break;
	case 5: pbox->SetCurSel (1); break;
	case 15: pbox->SetCurSel (2); break;
	default:
	case 30: pbox->SetCurSel (3); break;
	case 60: pbox->SetCurSel (4); break;
	case UINT_MAX: pbox->SetCurSel (5); break;
	}
}

UINT CDlg_Options_General_Misc::GetTimeoutForToutItem(CComboBox *pbox)
{
	switch (pbox->GetCurSel ()){
	case 0:	return 0; 
	case 1: return 5;
	case 2: return 15;
	case CB_ERR:
	default:
	case 3: return 30;
	case 4: return 60;
	case 5: return UINT_MAX;
	}
}

void CDlg_Options_General_Misc::OnSelchangeHangupTout() 
{
	m_bHangupToutChanged = true;
}

void CDlg_Options_General_Misc::OnSelchangeExitTout() 
{
	m_bExitToutChanged = true;	
}

void CDlg_Options_General_Misc::OnSelchangeShutdownTout() 
{
	m_bShutdownToutChanged = true;	
}

void CDlg_Options_General_Misc::OnSelchangeLaunchdldTout() 
{
	
	
}

void CDlg_Options_General_Misc::OnDisablewdtaskafterexec() 
{
	m_bDTAEChanged = true;	
}

void CDlg_Options_General_Misc::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_DROPBOX) == BST_CHECKED;
	if (b)
		b = fsSysGetOsMajorVersion () >= 5;
	GetDlgItem (IDC__TRANCPARENCY1)->EnableWindow (b);
	GetDlgItem (IDC_TRANCPARENCY1)->EnableWindow (b);
	GetDlgItem (IDC__TRANCPARENCY1_VAL)->EnableWindow (b);
	
	BOOL b1 = IsDlgButtonChecked (IDC_DLINFO) == BST_CHECKED;
	if (b1)
		b1 = fsSysGetOsMajorVersion () >= 5;
	GetDlgItem (IDC__TRANCPARENCY2)->EnableWindow (b1);
	GetDlgItem (IDC_TRANCPARENCY2)->EnableWindow (b1);
	GetDlgItem (IDC__TRANCPARENCY2_VAL)->EnableWindow (b1);
	
	GetDlgItem (IDC_HIDEFWWFS)->EnableWindow (b || b1);
}

void CDlg_Options_General_Misc::OnDropbox() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_Misc::OnDlinfo() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_Misc::UpdateBlendsVals()
{
	CString str; str.Format ("%d%%", m_wndBlend1.GetPos () * 100 / 255);
	CString str2; GetDlgItemText (IDC__TRANCPARENCY1_VAL, str2);
	if (str != str2)
		SetDlgItemText (IDC__TRANCPARENCY1_VAL, str);
	
	str.Format ("%d%%", m_wndBlend2.GetPos () * 100 / 255);
	GetDlgItemText (IDC__TRANCPARENCY2_VAL, str2);
	if (str != str2)
		SetDlgItemText (IDC__TRANCPARENCY2_VAL, str);
}

void CDlg_Options_General_Misc::OnCustomdrawTrancparency1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateBlendsVals ();

	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloating.SetBlend ((BYTE)(255 - m_wndBlend1.GetPos ()));

	*pResult = 0;
}

void CDlg_Options_General_Misc::OnCustomdrawTrancparency2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	UpdateBlendsVals ();	

	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloatingInfo.SetBlend ((BYTE)(255 - m_wndBlend2.GetPos ()));

	*pResult = 0;
}

void CDlg_Options_General_Misc::OnDestroy() 
{
	CDlg_Options_Page::OnDestroy();
	
	CMainFrame *pFrame = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
	pFrame->m_pFloatWndsThread->m_wndFloating.SetBlend (m_blend1);
	pFrame->m_pFloatWndsThread->m_wndFloatingInfo.SetBlend (m_blend2);	
}
