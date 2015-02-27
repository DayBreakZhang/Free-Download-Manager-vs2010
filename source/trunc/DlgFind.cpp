/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DlgFind.h"
#include "DlgFindAdvanced.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlgFind::CDlgFind(CWnd* pParent )
	: CDialog(CDlgFind::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFind)
		
	//}}AFX_DATA_INIT
}

void CDlgFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFind)
	DDX_Control(pDX, IDC_FINDWHAT, m_wndWhat);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgFind, CDialog)
	//{{AFX_MSG_MAP(CDlgFind)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_CBN_EDITCHANGE(IDC_FINDWHAT, OnEditchangeFindwhat)
	ON_CBN_SELCHANGE(IDC_FINDWHAT, OnSelchangeFindwhat)
	ON_BN_CLICKED(IDC_FILENAME, OnFilename)
	ON_BN_CLICKED(IDC_URL, OnUrl)
	ON_BN_CLICKED(IDC_COMMENT, OnComment)
	ON_BN_CLICKED(IDC_LOCALNAME, OnLocalname)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlgFind::OnInitDialog() 
{
	CDialog::OnInitDialog();

	for (int i = 0; i < _LastFind.GetRecordCount (); i++)
		m_wndWhat.AddString (_LastFind.GetRecord (i));
	m_wndWhat.SetCurSel (0);

	DWORD dwFlags = _App.Find_Flags ();

	CheckDlgButton (IDC_FILENAME, dwFlags & SEARCHIN_FILENAME ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_COMMENT, dwFlags & SEARCHIN_COMMENT ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_URL, dwFlags & SEARCHIN_URL ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_LOCALNAME, dwFlags & SEARCHIN_LOCFILENAME ? BST_CHECKED : BST_UNCHECKED);
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CDlgFind::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CDlgFind::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDlgFind::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDlgFind::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__FINDWHAT, L_FINDWHAT),
		fsDlgLngInfo (IDC__SEARCHIN, L_SEARCHIN),
		fsDlgLngInfo (IDC_FILENAME, L_FILENAME),
		fsDlgLngInfo (IDC_COMMENT, L_COMMENT),
		fsDlgLngInfo (IDC_LOCALNAME, L_LOCFILENAME),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDOK, L_FIND),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_FIND);
}

void CDlgFind::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__FINDWHAT, LS (L_FINDWHATHERE)),
		fsCtrlContextHelp (IDC_FINDWHAT, LS (L_FINDWHATHERE)),
		fsCtrlContextHelp (IDC_FILENAME, LS (L_SEARCHIN_FILENAMEHERE)),
		fsCtrlContextHelp (IDC_URL, LS (L_SEARCHIN_URLHERE)),
		fsCtrlContextHelp (IDC_COMMENT, LS (L_SEARCHIN_COMMENTHERE)),
		fsCtrlContextHelp (IDC_LOCALNAME, LS (L_SEARCHIN_LOCALFILENAMEHERE)),
		fsCtrlContextHelp (IDC_ADVANCED, LS (L_SEARCHADVANCEDHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDlgFind::OnAdvanced() 
{
	CDlgFindAdvanced dlg;
	_DlgMgr.DoModal (&dlg);	
}

void CDlgFind::OnOK() 
{
	CString str; 
	GetDlgItemText (IDC_FINDWHAT, str);

	BOOL bFile = IsDlgButtonChecked (IDC_FILENAME) == BST_CHECKED;
	BOOL bComment = IsDlgButtonChecked (IDC_COMMENT) == BST_CHECKED;
	BOOL bURL = IsDlgButtonChecked (IDC_URL) == BST_CHECKED;
	BOOL bLoc = IsDlgButtonChecked (IDC_LOCALNAME) == BST_CHECKED;

	DWORD dwFlags = _App.Find_Flags ();

	dwFlags &= ~(SEARCHIN_FILENAME|SEARCHIN_COMMENT|SEARCHIN_URL|SEARCHIN_LOCFILENAME);

	if (bFile)
		dwFlags |= SEARCHIN_FILENAME;

	if (bComment)
		dwFlags |= SEARCHIN_COMMENT;

	if (bURL)
		dwFlags |= SEARCHIN_URL;

	if (bLoc)
		dwFlags |= SEARCHIN_LOCFILENAME;

	_App.Find_Flags (dwFlags);
	_App.Find_What (str);

	_LastFind.AddRecord (str);

	CDialog::OnOK();
}

void CDlgFind::UpdateEnabled()
{
	CString str; 
	GetDlgItemText (IDC_FINDWHAT, str);
	if (str.GetLength ())
	{
		BOOL bFile = IsDlgButtonChecked (IDC_FILENAME) == BST_CHECKED;
		BOOL bComment = IsDlgButtonChecked (IDC_COMMENT) == BST_CHECKED;
		BOOL bURL = IsDlgButtonChecked (IDC_URL) == BST_CHECKED;
		BOOL bLoc = IsDlgButtonChecked (IDC_LOCALNAME) == BST_CHECKED;

		if (bFile == FALSE && bComment == FALSE && bURL == FALSE && bLoc == FALSE)
			GetDlgItem (IDOK)->EnableWindow (FALSE);
		else
			GetDlgItem (IDOK)->EnableWindow (TRUE);
	}
	else
		GetDlgItem (IDOK)->EnableWindow (FALSE);
}

void CDlgFind::OnEditchangeFindwhat() 
{
	UpdateEnabled ();
}

void CDlgFind::OnSelchangeFindwhat() 
{
	UpdateEnabled ();	
}

void CDlgFind::OnFilename() 
{
	UpdateEnabled ();
}

void CDlgFind::OnUrl() 
{
	UpdateEnabled ();
}

void CDlgFind::OnComment() 
{
	UpdateEnabled ();
}

void CDlgFind::OnLocalname() 
{
	UpdateEnabled ();
}
