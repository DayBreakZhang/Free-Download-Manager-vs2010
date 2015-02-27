/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_HistoryPage.h"
#include "DlgDownloadsHistory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPrg_HistoryPage, CPropertyPage)

CPrg_HistoryPage::CPrg_HistoryPage() : CPropertyPage(CPrg_HistoryPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_HISTORY);
}

CPrg_HistoryPage::~CPrg_HistoryPage()
{
}

void CPrg_HistoryPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_HistoryPage)
	DDX_Control(pDX, IDC_DAYSSPIN, m_wndSpin2);
	DDX_Control(pDX, IDC_MAXNUMBERSPIN, m_wndSpin1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_HistoryPage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrg_HistoryPage)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_USEHIST, OnUsehist)
	ON_BN_CLICKED(IDC_FOLDERSONLY, OnFoldersonly)
	ON_BN_CLICKED(IDC_DELRECTHATEXISTS, OnDelrecthatexists)
	ON_BN_CLICKED(IDC_MAXNUMBER, OnMaxnumber)
	ON_BN_CLICKED(IDC_CLEARHISTORY, OnClearhistory)
	ON_EN_CHANGE(IDC_DAYS, OnChangeDays)
	ON_EN_CHANGE(IDC_MAXNUMBERVAL, OnChangeMaxnumberval)
	ON_BN_CLICKED(IDC_SWITCHDLHIST, OnSwitchdlhist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_HistoryPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

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
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;
}

void CPrg_HistoryPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CPrg_HistoryPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CPrg_HistoryPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CPrg_HistoryPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_USEHIST, LS (L_USEHISTHERE)),
		fsCtrlContextHelp (IDC_FOLDERSONLY, LS (L_FOLDERSONLYHERE)),
		fsCtrlContextHelp (IDC_DELRECTHATEXISTS, LS (L_DELRECTHATEXISTSHERE)),
		fsCtrlContextHelp (IDC_DAYS, LS (L_DELRECTHATEXISTSHERE)),
		fsCtrlContextHelp (IDC_MAXNUMBER, LS (L_HISTMAXNUMBERHERE)),
		fsCtrlContextHelp (IDC_MAXNUMBERVAL, LS (L_HISTMAXNUMBERHERE)),
		fsCtrlContextHelp (IDC_CLEARHISTORY, LS (L_CLEARHISTORYHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CPrg_HistoryPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USEHIST, L_SAVEHISTOFLINKSANDFOLDERS),
		fsDlgLngInfo (IDC_FOLDERSONLY, L_SAVEFOLDERSHISTONLY),
		fsDlgLngInfo (IDC_DELRECTHATEXISTS, L_DELRECTHATEXISTS),
		fsDlgLngInfo (IDC__DAYS, L_DAYS),
		fsDlgLngInfo (IDC_MAXNUMBER, L_MAXRECORDS),
		fsDlgLngInfo (IDC_CLEARHISTORY, L_CLEARHISTORY),
		fsDlgLngInfo (IDC_SWITCHDLHIST, L_DLHISTSETTINGS),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CPrg_HistoryPage::OnUsehist() 
{
	SetModified ();
	UpdateEnabled ();
}

void CPrg_HistoryPage::OnFoldersonly() 
{
	SetModified ();
}

void CPrg_HistoryPage::OnDelrecthatexists() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CPrg_HistoryPage::OnMaxnumber() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CPrg_HistoryPage::OnClearhistory() 
{
	if (IDNO == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO))
		return;

	_HsMgr.ClearAll ();
	GetDlgItem (IDC_CLEARHISTORY)->EnableWindow (FALSE);
}

BOOL CPrg_HistoryPage::OnApply() 
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
	
	return CPropertyPage::OnApply();
}

void CPrg_HistoryPage::UpdateEnabled()
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
					_LastFolders.GetRecordCount () != 0;
	}
	GetDlgItem (IDC_CLEARHISTORY)->EnableWindow (bEnClear);
}

void CPrg_HistoryPage::OnChangeDays() 
{
	SetModified ();	
}

void CPrg_HistoryPage::OnChangeMaxnumberval() 
{
	SetModified ();
}

void CPrg_HistoryPage::OnSwitchdlhist() 
{
	CDlgDownloadsHistory dlg (this);
	_DlgMgr.DoModal (&dlg);
}
