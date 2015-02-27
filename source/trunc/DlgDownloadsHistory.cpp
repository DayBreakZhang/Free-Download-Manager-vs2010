/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgDownloadsHistory.h"
#include "DownloadsWnd.h"
#include "vmsLogger.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgDownloadsHistory::CDlgDownloadsHistory(CWnd* pParent )
	: CDialog(CDlgDownloadsHistory::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDownloadsHistory)
		
	//}}AFX_DATA_INIT
}

void CDlgDownloadsHistory::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDownloadsHistory)
	DDX_Control(pDX, IDC_DAYSSPIN, m_wndSpin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgDownloadsHistory, CDialog)
	//{{AFX_MSG_MAP(CDlgDownloadsHistory)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_USE, OnUse)
	ON_BN_CLICKED(IDC_DELRECTHATEXISTS, OnDelrecthatexists)
	ON_BN_CLICKED(IDC_CLEARHISTORY, OnClearhistory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgDownloadsHistory::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndSpin.SetRange (1, 99);

	CheckDlgButton (IDC_USE, _App.History_Downloads_Use () ? BST_CHECKED : BST_UNCHECKED);
	if (_App.History_Downloads_KeepDays () != UINT_MAX)
	{
		CheckDlgButton (IDC_DELRECTHATEXISTS, BST_CHECKED);
		SetDlgItemInt (IDC_DAYS, _App.History_Downloads_KeepDays ());
	}
	else
		SetDlgItemInt (IDC_DAYS, 15);

	CheckDlgButton (IDC_COMPONLY, _App.History_Downloads_CompletedOnly () ? BST_CHECKED : BST_UNCHECKED);
		
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CDlgDownloadsHistory::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDlgDownloadsHistory::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDlgDownloadsHistory::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDlgDownloadsHistory::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USE) == BST_CHECKED;
	GetDlgItem (IDC_DELRECTHATEXISTS)->EnableWindow (b);
	GetDlgItem (IDC_COMPONLY)->EnableWindow (b);
	GetDlgItem (IDC_CLEARHISTORY)->EnableWindow (b && _DldsMgr.m_histmgr.GetRecordCount () != 0);
	b = b && IsDlgButtonChecked (IDC_DELRECTHATEXISTS) == BST_CHECKED;
	GetDlgItem (IDC_DAYS)->EnableWindow (b);
	GetDlgItem (IDC_DAYSSPIN)->EnableWindow (b);
	GetDlgItem (IDC__DAYS)->EnableWindow (b);
}

void CDlgDownloadsHistory::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USE, L_SAVEDLHIST),
		fsDlgLngInfo (IDC_DELRECTHATEXISTS, L_DELRECTHATEXISTS),
		fsDlgLngInfo (IDC__DAYS, L_DAYS),
		fsDlgLngInfo (IDC_COMPONLY, L_DLHISTCOMPONLY),
		fsDlgLngInfo (IDC_CLEARHISTORY, L_CLEARHISTORY2),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_DLHISTSETTINGS);
}

void CDlgDownloadsHistory::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_USE, LS (L_USEDLHISTHERE)),
		fsCtrlContextHelp (IDC_DELRECTHATEXISTS, LS (L_DELRECTHATEXISTSHERE)),
		fsCtrlContextHelp (IDC_DAYS, LS (L_DELRECTHATEXISTSHERE)),
		fsCtrlContextHelp (IDC_COMPONLY, LS (L_DLHISTCOMPONLYHERE)),
		fsCtrlContextHelp (IDC_CLEARHISTORY, LS (L_CLEARHISTORYHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDlgDownloadsHistory::OnUse() 
{
	UpdateEnabled ();
}

void CDlgDownloadsHistory::OnDelrecthatexists() 
{
	UpdateEnabled ();	
}

void CDlgDownloadsHistory::OnClearhistory() 
{
	if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO | MB_ICONQUESTION))
	{
		_DldsMgr.m_histmgr.ClearHistory ();
		GetDlgItem (IDC_CLEARHISTORY)->EnableWindow (FALSE);
	}
}

void CDlgDownloadsHistory::OnOK() 
{
	if (IsDlgButtonChecked (IDC_USE) == BST_UNCHECKED)
	{
		_App.History_Downloads_Use (FALSE);
	}
	else
	{
		UINT cMaxDays = UINT_MAX;
		if (IsDlgButtonChecked (IDC_DELRECTHATEXISTS) == BST_CHECKED)
		{
			cMaxDays = GetDlgItemInt (IDC_DAYS);
			if (cMaxDays == 0)
			{
				CString str;
				str.Format (LS (L_ENTERGREATER), 0);
				MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
				CEdit *pE = (CEdit*) GetDlgItem (IDC_DAYS);
				pE->SetSel (0, -1);
				pE->SetFocus ();
				return;
			}
		}

		_App.History_Downloads_CompletedOnly (
			IsDlgButtonChecked (IDC_COMPONLY) == BST_CHECKED);

		_App.History_Downloads_KeepDays (cMaxDays);
		_App.History_Downloads_Use (TRUE);
	}

	if (_pwndDownloads->Get_DWWN () == DWWN_HISTORY)
		_pwndDownloads->m_wndHistory.ShowWindow (SW_HIDE);
	
	try 
	{
		_DldsMgr.m_histmgr.ReadSettings ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlgDownloadsHistory::OnOK " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlgDownloadsHistory::OnOK unknown exception");
	}

	if (_pwndDownloads->Get_DWWN () == DWWN_HISTORY)
		_pwndDownloads->m_wndHistory.ShowWindow (SW_SHOW);
	
	CDialog::OnOK();
}
