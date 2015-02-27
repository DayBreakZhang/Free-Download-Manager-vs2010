/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_MiscPage.h"
#include "ShedulerWnd.h"

extern CShedulerWnd *_pwndScheduler;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPrg_MiscPage, CPropertyPage)

CPrg_MiscPage::CPrg_MiscPage() : CPropertyPage(CPrg_MiscPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_MISC);

	m_bHangupToutChanged = m_bExitToutChanged = m_bShutdownToutChanged = false;
	m_bDTAEChanged = false;
}

CPrg_MiscPage::~CPrg_MiscPage()
{
}

void CPrg_MiscPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_MiscPage)
	DDX_Control(pDX, IDC_SHUTDOWN_TOUT, m_wndShutdownTout);
	DDX_Control(pDX, IDC_LAUNCHDLD_TOUT, m_wndLaunchDldTout);
	DDX_Control(pDX, IDC_HANGUP_TOUT, m_wndHangupTout);
	DDX_Control(pDX, IDC_EXIT_TOUT, m_wndExitTout);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_MiscPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrg_MiscPage)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_ASKFORST, OnAskforst)
	ON_CBN_SELCHANGE(IDC_EXIT_TOUT, OnSelchangeExitTout)
	ON_CBN_SELCHANGE(IDC_HANGUP_TOUT, OnSelchangeHangupTout)
	ON_CBN_SELCHANGE(IDC_LAUNCHDLD_TOUT, OnSelchangeLaunchdldTout)
	ON_CBN_SELCHANGE(IDC_SHUTDOWN_TOUT, OnSelchangeShutdownTout)
	ON_BN_CLICKED(IDC_DISABLEWDTASKAFTEREXEC, OnDisablewdtaskafterexec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_MiscPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

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
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CPrg_MiscPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

void CPrg_MiscPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TOUTSFORCONFS, L_TOUTSFORCONFS),
		fsDlgLngInfo (IDC__HANGUP, L_HANGUP),
		fsDlgLngInfo (IDC__EXIT, L_EXIT),
		fsDlgLngInfo (IDC__SHUTDOWN, L_SHUTDOWN),
		fsDlgLngInfo (IDC__LAUNCHDLD, L_LAUNCHDLD),
		fsDlgLngInfo (IDC_ASKFORST, L_ASKFORST),
		fsDlgLngInfo (IDC_DISABLEWDTASKAFTEREXEC, L_DISABLEWHENDONEAFTEREXEC),

	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CPrg_MiscPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CPrg_MiscPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__HANGUP, LS (L_HANGUP_TOUT_HERE)),
		fsCtrlContextHelp (IDC_HANGUP_TOUT, LS (L_HANGUP_TOUT_HERE)),
		fsCtrlContextHelp (IDC__EXIT, LS (L_EXIT_TOUT_HERE)),
		fsCtrlContextHelp (IDC_EXIT_TOUT, LS (L_EXIT_TOUT_HERE)),
		fsCtrlContextHelp (IDC__SHUTDOWN, LS (L_SHUTDOWN_TOUT_HERE)),
		fsCtrlContextHelp (IDC_SHUTDOWN_TOUT, LS (L_SHUTDOWN_TOUT_HERE)),
		fsCtrlContextHelp (IDC__LAUNCHDLD, LS (L_LAUNCHDLD_HERE)),
		fsCtrlContextHelp (IDC_LAUNCHDLD_TOUT, LS (L_LAUNCHDLD_HERE)),
		fsCtrlContextHelp (IDC_ASKFORST, LS (L_ASKFORST_HERE)),
		fsCtrlContextHelp (IDC_DISABLEWDTASKAFTEREXEC, LS (L_DISABLEWHENDONEAFTEREXEC_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CPrg_MiscPage::OnApply() 
{
	_App.WD_LastShutdownType_DontAsk (IsDlgButtonChecked (IDC_ASKFORST) == BST_UNCHECKED);

	_App.ConfTimeout_Hangup (GetTimeoutForToutItem (&m_wndHangupTout));
	_App.ConfTimeout_Exit (GetTimeoutForToutItem (&m_wndExitTout));
	_App.ConfTimeout_Shutdown (GetTimeoutForToutItem (&m_wndShutdownTout));
	_App.ConfTimeout_LaunchDld (GetTimeoutForToutItem (&m_wndLaunchDldTout));

	int pos;
	if (m_bHangupToutChanged && _pwndScheduler->HangupWhenDone (&pos))
	{
		m_bHangupToutChanged = false;
		_pwndScheduler->GetMgr ()->GetTask (pos)->uWaitForConfirmation = _App.ConfTimeout_Hangup ();
		_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
	}

	if (m_bExitToutChanged && _pwndScheduler->ExitWhenDone (&pos))
	{
		m_bExitToutChanged = false;
		_pwndScheduler->GetMgr ()->GetTask (pos)->uWaitForConfirmation = _App.ConfTimeout_Exit ();
		_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
	}

	fsShutdownType enType = (fsShutdownType) _App.WD_LastShutdownType ();
	if (m_bShutdownToutChanged && _pwndScheduler->TurnoffWhenDone (enType, &pos))
	{
		m_bShutdownToutChanged = false;
		_pwndScheduler->GetMgr ()->GetTask (pos)->uWaitForConfirmation = _App.ConfTimeout_Shutdown ();
		_pwndScheduler->GetMgr ()->setDirtyFlagForTask(pos);
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
	
	return CPropertyPage::OnApply();
}

void CPrg_MiscPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CPrg_MiscPage::SelectToutItem(CComboBox *pbox, UINT uTimeout)
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

void CPrg_MiscPage::OnAskforst() 
{
	SetModified ();	
}

void CPrg_MiscPage::OnSelchangeExitTout() 
{
	m_bExitToutChanged = true;
	SetModified ();	
}

void CPrg_MiscPage::OnSelchangeHangupTout() 
{
	m_bHangupToutChanged = true;
	SetModified ();	
}

void CPrg_MiscPage::OnSelchangeLaunchdldTout() 
{
	SetModified ();	
}

void CPrg_MiscPage::OnSelchangeShutdownTout() 
{
	m_bShutdownToutChanged = true;
	SetModified ();	
}

UINT CPrg_MiscPage::GetTimeoutForToutItem(CComboBox *pbox)
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

void CPrg_MiscPage::OnDisablewdtaskafterexec() 
{
	m_bDTAEChanged = true;
	SetModified ();
}
