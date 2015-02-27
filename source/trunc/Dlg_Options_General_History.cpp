/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_General_History.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_General_History::CDlg_Options_General_History(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_General_History::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_General_History)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_General_History::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_General_History)
	DDX_Control(pDX, IDC_DAYSSPIN2, m_wndSpin3);
	DDX_Control(pDX, IDC_MAXNUMBERSPIN, m_wndSpin2);
	DDX_Control(pDX, IDC_DAYSSPIN, m_wndSpin1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_General_History, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_General_History)
	ON_BN_CLICKED(IDC_USEHIST, OnUsehist)
	ON_BN_CLICKED(IDC_CLEARHISTORY, OnClearhistory)
	ON_BN_CLICKED(IDC_USE2, OnUse2)
	ON_BN_CLICKED(IDC_CLEARHISTORY2, OnClearhistory2)
	ON_BN_CLICKED(IDC_DELRECTHATEXISTS, OnDelrecthatexists)
	ON_BN_CLICKED(IDC_MAXNUMBER, OnMaxnumber)
	ON_BN_CLICKED(IDC_DELRECTHATEXISTS2, OnDelrecthatexists2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_General_History::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
	CheckDlgButton (IDC_USEHIST, _App.History_Use () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_FOLDERSONLY, _App.History_FoldersOnly () ? BST_CHECKED : BST_UNCHECKED);
	
	m_wndSpin1.SetRange (1, 99);
	m_wndSpin2.SetRange (1, 99);
	
	if (_App.History_KeepDays () != INT_MAX)
	{
		CheckDlgButton (IDC_DELRECTHATEXISTS, BST_CHECKED);
		SetDlgItemInt (IDC_DAYS, _App.History_KeepDays ());
	}
	else
		SetDlgItemInt (IDC_DAYS, 15);
	
	if (_App.History_MaxRecords () != INT_MAX)
	{
		CheckDlgButton (IDC_MAXNUMBER, BST_CHECKED);
		SetDlgItemInt (IDC_MAXNUMBERVAL, _App.History_MaxRecords ());
	}
	else
		SetDlgItemInt (IDC_MAXNUMBERVAL, 30);

	m_wndSpin3.SetRange (1, 99);
	
	CheckDlgButton (IDC_USE2, _App.History_Downloads_Use () ? BST_CHECKED : BST_UNCHECKED);
	if (_App.History_Downloads_KeepDays () != UINT_MAX)
	{
		CheckDlgButton (IDC_DELRECTHATEXISTS2, BST_CHECKED);
		SetDlgItemInt (IDC_DAYS2, _App.History_Downloads_KeepDays ());
	}
	else
		SetDlgItemInt (IDC_DAYS2, 15);
	
	CheckDlgButton (IDC_COMPONLY2, _App.History_Downloads_CompletedOnly () ? BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_LISTRECENTDLDS, _App.RecentDownloadsHistorySize () ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();
	UpdateEnabled ();
	
	
	
	return TRUE;  
	              
}

CString CDlg_Options_General_History::get_PageTitle()
{
	return LS (L_HISTORY);
}

CString CDlg_Options_General_History::get_PageShortTitle()
{
	return LS (L_HISTORY);
}

BOOL CDlg_Options_General_History::Apply()
{
	if (IsDlgButtonChecked (IDC_USEHIST) == BST_UNCHECKED)
	{
		_App.History_Use (FALSE);
	}
	else
	{
		int cMaxDays = INT_MAX;
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
				return FALSE;
			}
		}
		
		int cMaxRecs = INT_MAX;
		if (IsDlgButtonChecked (IDC_MAXNUMBER) == BST_CHECKED)
		{
			cMaxRecs = GetDlgItemInt (IDC_MAXNUMBERVAL);
			if (cMaxRecs == 0)
			{
				CString str;
				str.Format (LS (L_ENTERGREATER), 0);
				MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
				CEdit *pE = (CEdit*) GetDlgItem (IDC_MAXNUMBERVAL);
				pE->SetSel (0, -1);
				pE->SetFocus ();
				return FALSE;
			}
		}
		
		_App.History_FoldersOnly (
			IsDlgButtonChecked (IDC_FOLDERSONLY) == BST_CHECKED);
		
		_App.History_KeepDays (cMaxDays);
		_App.History_MaxRecords (cMaxRecs);
		_App.History_Use (TRUE);
	}
	
	_HsMgr.ReadSettings ();

	if (IsDlgButtonChecked (IDC_USE2) == BST_UNCHECKED)
	{
		_App.History_Downloads_Use (FALSE);
	}
	else
	{
		UINT cMaxDays = UINT_MAX;
		if (IsDlgButtonChecked (IDC_DELRECTHATEXISTS2) == BST_CHECKED)
		{
			cMaxDays = GetDlgItemInt (IDC_DAYS2);
			if (cMaxDays == 0)
			{
				CString str;
				str.Format (LS (L_ENTERGREATER), 0);
				MessageBox (str, LS (L_INPERR), MB_ICONEXCLAMATION);
				CEdit *pE = (CEdit*) GetDlgItem (IDC_DAYS2);
				pE->SetSel (0, -1);
				pE->SetFocus ();
				return FALSE;
			}
		}
		
		_App.History_Downloads_CompletedOnly (
			IsDlgButtonChecked (IDC_COMPONLY2) == BST_CHECKED);
		
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
		vmsLogger::WriteLog("CDlg_Options_General_History::Apply " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDlg_Options_General_History::Apply unknown exception");
	}

	if (_pwndDownloads->Get_DWWN () == DWWN_HISTORY)
		_pwndDownloads->m_wndHistory.ShowWindow (SW_SHOW);

	if (IsDlgButtonChecked (IDC_LISTRECENTDLDS) == BST_CHECKED)
	{
		_App.RecentDownloadsHistorySize (10);
		_DldsMgr.get_LastFilesDownloaded ()->setMaxSize (10);
	}
	else
	{
		_App.RecentDownloadsHistorySize (0);
		_DldsMgr.get_LastFilesDownloaded ()->Clear ();
		_DldsMgr.get_LastFilesDownloaded ()->setMaxSize (0);
	}

	return TRUE;
}

void CDlg_Options_General_History::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USEHIST, L_SAVEHISTOFLINKSANDFOLDERS),
		fsDlgLngInfo (IDC_FOLDERSONLY, L_SAVEFOLDERSHISTONLY),
		fsDlgLngInfo (IDC_DELRECTHATEXISTS, L_DELRECTHATEXISTS),
		fsDlgLngInfo (IDC__DAYS, L_DAYS),
		fsDlgLngInfo (IDC_MAXNUMBER, L_MAXRECORDS),
		fsDlgLngInfo (IDC_CLEARHISTORY, L_CLEARHISTORY),

		fsDlgLngInfo (IDC_USE2, L_SAVEDLDSHIST),
		fsDlgLngInfo (IDC_DELRECTHATEXISTS2, L_DELRECTHATEXISTS),
		fsDlgLngInfo (IDC__DAYS2, L_DAYS),
		fsDlgLngInfo (IDC_COMPONLY2, L_DLHISTCOMPONLY),
		fsDlgLngInfo (IDC_CLEARHISTORY2, L_CLEARHISTORY2),

		fsDlgLngInfo (IDC_LISTRECENTDLDS, L_LISTRECENTDLDS),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_General_History::OnUsehist() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_History::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USEHIST) == BST_CHECKED;
	GetDlgItem (IDC_FOLDERSONLY)->EnableWindow (b);
	GetDlgItem (IDC_DELRECTHATEXISTS)->EnableWindow (b);
	
	BOOL b2 = IsDlgButtonChecked (IDC_DELRECTHATEXISTS) == BST_CHECKED;
	GetDlgItem (IDC_DAYS)->EnableWindow (b && b2);
	GetDlgItem (IDC_DAYSSPIN)->EnableWindow (b && b2);
	GetDlgItem (IDC__DAYS)->EnableWindow (b && b2);
	
	GetDlgItem (IDC_MAXNUMBER)->EnableWindow (b);
	b2 = IsDlgButtonChecked (IDC_MAXNUMBER) == BST_CHECKED;
	GetDlgItem (IDC_MAXNUMBERVAL)->EnableWindow (b && b2);
	GetDlgItem (IDC_MAXNUMBERSPIN)->EnableWindow (b && b2);
	
	BOOL bEnClear = b;
	if (bEnClear)
	{
		bEnClear = _LastUrlFiles.GetRecordCount () != 0 ||
			_LastUrlPaths.GetRecordCount () != 0 || 
			_LastBatchUrls.GetRecordCount () != 0 || 
			_LastFolders.GetRecordCount () != 0 ||
			_LastFlashVideoUrls.GetRecordCount () != 0;
	}
	GetDlgItem (IDC_CLEARHISTORY)->EnableWindow (bEnClear);

	b = IsDlgButtonChecked (IDC_USE2) == BST_CHECKED;
	GetDlgItem (IDC_DELRECTHATEXISTS2)->EnableWindow (b);
	GetDlgItem (IDC_COMPONLY2)->EnableWindow (b);
	GetDlgItem (IDC_CLEARHISTORY2)->EnableWindow (b && _DldsMgr.m_histmgr.GetRecordCount () != 0);
	b = b && IsDlgButtonChecked (IDC_DELRECTHATEXISTS2) == BST_CHECKED;
	GetDlgItem (IDC_DAYS2)->EnableWindow (b);
	GetDlgItem (IDC_DAYSSPIN2)->EnableWindow (b);
	GetDlgItem (IDC__DAYS2)->EnableWindow (b);
}

void CDlg_Options_General_History::OnClearhistory() 
{
	if (IDNO == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO))
		return;
	
	_HsMgr.ClearAll ();
	GetDlgItem (IDC_CLEARHISTORY)->EnableWindow (FALSE);	
}

void CDlg_Options_General_History::OnUse2() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_History::OnClearhistory2() 
{
	if (IDYES == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO | MB_ICONQUESTION))
	{
		_DldsMgr.m_histmgr.ClearHistory ();
		GetDlgItem (IDC_CLEARHISTORY2)->EnableWindow (FALSE);
	}	
}

void CDlg_Options_General_History::OnDelrecthatexists() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_History::OnMaxnumber() 
{
	UpdateEnabled ();	
}

void CDlg_Options_General_History::OnDelrecthatexists2() 
{
	UpdateEnabled ();	
}
