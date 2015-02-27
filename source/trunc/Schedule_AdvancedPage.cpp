/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Schedule_AdvancedPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CSchedule_AdvancedPage, CPropertyPage)

CSchedule_AdvancedPage::CSchedule_AdvancedPage() : CPropertyPage(CSchedule_AdvancedPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_ADVANCED);
}

CSchedule_AdvancedPage::~CSchedule_AdvancedPage()
{
}

void CSchedule_AdvancedPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSchedule_AdvancedPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSchedule_AdvancedPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSchedule_AdvancedPage)
	ON_BN_CLICKED(IDC_USECONFIRMATION, OnUseconfirmation)
	ON_BN_CLICKED(IDC_USEWAIT, OnUsewait)
	ON_EN_CHANGE(IDC_DURING, OnChangeDuring)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_DISABLE, OnDisable)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSchedule_AdvancedPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	CheckDlgButton (IDC_USECONFIRMATION, m_task->uWaitForConfirmation > 0 ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_USEWAIT, m_task->uWaitForConfirmation == UINT_MAX || m_task->uWaitForConfirmation == 0 ? BST_UNCHECKED : BST_CHECKED);

	CheckDlgButton (IDC_DELETE, m_task->dwFlags & SCHEDULE_AUTODEL ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_DISABLE, m_task->dwFlags & SCHEDULE_AUTODIS ? BST_CHECKED : BST_UNCHECKED);

	((CSpinButtonCtrl*) GetDlgItem (IDC_DURINGSPIN))->SetRange (1, UD_MAXVAL);

	if (m_task->uWaitForConfirmation == UINT_MAX || m_task->uWaitForConfirmation == 0)
		SetDlgItemInt (IDC_DURING, 30);
	else
		SetDlgItemInt (IDC_DURING, m_task->uWaitForConfirmation);

	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CSchedule_AdvancedPage::UpdateEnabled()
{
	BOOL b;

	b = IsDlgButtonChecked (IDC_USECONFIRMATION) == BST_CHECKED;
	GetDlgItem (IDC_USEWAIT)->EnableWindow (b);

	b = b && IsDlgButtonChecked (IDC_USEWAIT) == BST_CHECKED;
	GetDlgItem (IDC_DURING)->EnableWindow (b);
	GetDlgItem (IDC_DURINGSPIN)->EnableWindow (b);
	GetDlgItem (IDC__SECONDS)->EnableWindow (b);

	GetDlgItem (IDC_DISABLE)->EnableWindow (IsDlgButtonChecked (IDC_DELETE) != BST_CHECKED);
}

void CSchedule_AdvancedPage::OnUseconfirmation() 
{
	UpdateEnabled ();
	SetModified ();
}

void CSchedule_AdvancedPage::OnUsewait() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CSchedule_AdvancedPage::OnChangeDuring() 
{
	SetModified ();
}

BOOL CSchedule_AdvancedPage::OnApply() 
{
	if (IsDlgButtonChecked (IDC_USECONFIRMATION) == BST_UNCHECKED)
		m_task->uWaitForConfirmation = 0;
	else 
	{
		if (IsDlgButtonChecked (IDC_USEWAIT) == BST_UNCHECKED)
			m_task->uWaitForConfirmation = UINT_MAX;
		else
			m_task->uWaitForConfirmation = GetDlgItemInt (IDC_DURING);
	}

	if (IsDlgButtonChecked (IDC_DELETE) == BST_CHECKED)
		m_task->dwFlags |= SCHEDULE_AUTODEL;
	else
	{
		m_task->dwFlags &= ~ SCHEDULE_AUTODEL;
		if (IsDlgButtonChecked (IDC_DISABLE) == BST_CHECKED)
			m_task->dwFlags |= SCHEDULE_AUTODIS;
		else
			m_task->dwFlags &= ~ SCHEDULE_AUTODIS;
	}

	fsScheduleEx* pschScheduleParam = (fsScheduleEx*)m_task;
	if (pschScheduleParam && pschScheduleParam->m_ppoTaskWrapper)
		pschScheduleParam->m_ppoTaskWrapper->setDirty();
	
	return CPropertyPage::OnApply();
}

void CSchedule_AdvancedPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSchedule_AdvancedPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CSchedule_AdvancedPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__CONFIRMATION, L_CONFIRMATION),
		fsDlgLngInfo (IDC_USECONFIRMATION, L_CONFIRMREQ),
		fsDlgLngInfo (IDC_USEWAIT, L_WAITFORCONFIRM),
		fsDlgLngInfo (IDC__SECONDS, L_SECS),
		fsDlgLngInfo (IDC_DISABLE, L_DISAFTEREXEC),
		fsDlgLngInfo (IDC_DELETE, L_DELAFTEREXEC),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CSchedule_AdvancedPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_USECONFIRMATION, LS (L_USECONFIRMHERE)),
		fsCtrlContextHelp (IDC_USEWAIT, LS (L_WAITFORCONFIRMHERE)),
		fsCtrlContextHelp (IDC_DISABLE, LS (L_DISSCHEDHERE)),
		fsCtrlContextHelp (IDC_DELETE, LS (L_DELSCHEDHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CSchedule_AdvancedPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CSchedule_AdvancedPage::OnDisable() 
{
	SetModified ();	
}

void CSchedule_AdvancedPage::OnDelete() 
{
	SetModified ();
	UpdateEnabled ();
}
