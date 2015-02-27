/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgDeletedProperties.h"
#include "DownloadsWnd.h"
#include "vmsLogger.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgDeletedProperties::CDlgDeletedProperties(CWnd* pParent )
	: CDialog(CDlgDeletedProperties::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDeletedProperties)
		
	//}}AFX_DATA_INIT
}

void CDlgDeletedProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDeletedProperties)
	DDX_Control(pDX, IDC_MAXVALSPIN, m_wndMaxValSpin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgDeletedProperties, CDialog)
	//{{AFX_MSG_MAP(CDlgDeletedProperties)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_BN_CLICKED(IDC_DONTUSE, OnDontuse)
	ON_BN_CLICKED(IDC_USEMAX, OnUsemax)
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgDeletedProperties::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_wndMaxValSpin.SetRange (1, UD_MAXVAL);

	CheckDlgButton (IDC_DONTUSE, _App.Deleted_Bypass () ? BST_CHECKED : BST_UNCHECKED);

	UINT max = _App.Deleted_MaxCount ();
	if (max != UINT_MAX)
	{
		CheckDlgButton (IDC_USEMAX, BST_CHECKED);
		SetDlgItemInt (IDC_MAXVAL, int (max));
	}
	else
		SetDlgItemInt (IDC_MAXVAL, 100);

	CheckDlgButton (IDC_BYPASSCOMPLETED, _App.Deleted_BypassCompleted () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_CONFIRMDELETION, _App.Deleted_ConfirmDeletion () ? 
		BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

BOOL CDlgDeletedProperties::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDlgDeletedProperties::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();		
}

void CDlgDeletedProperties::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DONTUSE, L_DONTUSEDELETED),
		fsDlgLngInfo (IDC_USEMAX, L_MAXDELETED),
		fsDlgLngInfo (IDC__DOWNLOADS, L_DOWNLOADS_),
		fsDlgLngInfo (IDC_BYPASSCOMPLETED, L_BYPASSCOMPLETED),
		fsDlgLngInfo (IDC_CONFIRMDELETION, L_CONFIRMDLDELETION),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_DELETEDPROPERTIES);
}

void CDlgDeletedProperties::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_DONTUSE) == BST_UNCHECKED;
	GetDlgItem (IDC_BYPASSCOMPLETED)->EnableWindow (b);
	GetDlgItem (IDC_USEMAX)->EnableWindow (b);
	b = b && IsDlgButtonChecked (IDC_USEMAX) == BST_CHECKED;
	GetDlgItem (IDC_MAXVAL)->EnableWindow (b);
	GetDlgItem (IDC_MAXVALSPIN)->EnableWindow (b);
	GetDlgItem (IDC__DOWNLOADS)->EnableWindow (b);
}

void CDlgDeletedProperties::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_DONTUSE, LS (L_DONTUSEDELETEDHERE)),
		fsCtrlContextHelp (IDC_USEMAX, LS (L_MAXDELETEDHERE)),
		fsCtrlContextHelp (IDC_MAXVAL, LS (L_MAXDELETEDVALHERE)),
		fsCtrlContextHelp (IDC_BYPASSCOMPLETED, LS (L_BYPASSCOMPLETEDHERE)),
		fsCtrlContextHelp (IDC_CONFIRMDELETION, LS (L_CONFIRMDLDDELETIONHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDlgDeletedProperties::OnDontuse() 
{
	if (IsDlgButtonChecked (IDC_DONTUSE) == BST_CHECKED)
		CheckDlgButton (IDC_CONFIRMDELETION, BST_CHECKED);
	
	UpdateEnabled ();	
}

void CDlgDeletedProperties::OnOK() 
{
	BOOL bDontUse = IsDlgButtonChecked (IDC_DONTUSE) == BST_CHECKED;
	if (bDontUse == FALSE)
	{
		if (IsDlgButtonChecked (IDC_USEMAX) == BST_CHECKED)
		{
			UINT max = GetDlgItemInt (IDC_MAXVAL);
			if (max == 0)
			{
				CString str;
				str.Format (LS (L_ENTERGREATER), 0);
				MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
				CEdit *pE = (CEdit*) GetDlgItem (IDC_MAXVAL);
				pE->SetSel (0, -1);
				pE->SetFocus ();
				return;
			}
			_App.Deleted_MaxCount (max);
		}
		else
			_App.Deleted_MaxCount (UINT_MAX);

		_App.Deleted_BypassCompleted (
			IsDlgButtonChecked (IDC_BYPASSCOMPLETED) == BST_CHECKED);
	}

	_App.Deleted_Bypass (bDontUse);
	_App.Deleted_ConfirmDeletion (IsDlgButtonChecked (IDC_CONFIRMDELETION) == BST_CHECKED);

	if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
		_pwndDownloads->m_wndDeleted.ShowWindow (SW_HIDE);
	try 
	{
		_DldsMgr.ReadDeletedSettings ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlgDeletedProperties::OnOK " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlgDeletedProperties::OnOK unknown exception");
	}

	if (_pwndDownloads->Get_DWWN () == DWWN_DELETED)
		_pwndDownloads->m_wndDeleted.ShowWindow (SW_SHOW);
	
	CDialog::OnOK();
}

void CDlgDeletedProperties::OnUsemax() 
{
	UpdateEnabled ();	
}

void CDlgDeletedProperties::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}
