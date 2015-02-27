/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Dlg_WPD_IL_Add.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_WPD_IL_Add::CDlg_WPD_IL_Add(CWnd* pParent )
	: CDialog(CDlg_WPD_IL_Add::IDD, pParent)
{
	m_strURL = "";
	m_bSubfoldersAlso = TRUE;
	m_bThisOnly = FALSE;
}

void CDlg_WPD_IL_Add::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_WPD_IL_Add)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_WPD_IL_Add, CDialog)
	//{{AFX_MSG_MAP(CDlg_WPD_IL_Add)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_WPD_IL_Add::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (m_strURL.GetLength () == 0)
	{
		LPCSTR pszURL = _ClipbrdMgr.Text ();
		fsURL url;
		if (pszURL && url.Crack (pszURL) == IR_SUCCESS)
			m_strURL = pszURL;
	}

	SetDlgItemText (IDC_URL, m_strURL);

	if (m_bSubfoldersAlso)
		CheckDlgButton (IDC_SUBFOLDERS, BST_CHECKED);

	CheckRadioButton (IDC_IGNORE, IDC_THISONLY, m_bThisOnly ? IDC_THISONLY : IDC_IGNORE);
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CDlg_WPD_IL_Add::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_SUBFOLDERS, L_INCLUDINGSUBFOLDERS),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC_IGNORE, L_DONTDLDTHISPATH),
		fsDlgLngInfo (IDC_THISONLY, L_DLDTHISPATHONLY),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ADD);
}

void CDlg_WPD_IL_Add::OnOK() 
{
	GetDlgItemText (IDC_URL, m_strURL);

	fsURL url;
	if (url.Crack (m_strURL) != IR_SUCCESS)
	{
		MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_URL)->SetFocus ();
		return;
	}

	m_bSubfoldersAlso = IsDlgButtonChecked (IDC_SUBFOLDERS) == BST_CHECKED;
	m_bThisOnly = IsDlgButtonChecked (IDC_THISONLY) == BST_CHECKED;
	
	CDialog::OnOK();
}

BOOL CDlg_WPD_IL_Add::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDlg_WPD_IL_Add::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

void CDlg_WPD_IL_Add::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDlg_WPD_IL_Add::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__URL, LS (L_FOLDERURL_HERE)),
		fsCtrlContextHelp (IDC_URL, LS (L_FOLDERURL_HERE)),
		fsCtrlContextHelp (IDC_IGNORE, LS (L_IGNOREPATH_HERE)),
		fsCtrlContextHelp (IDC_THISONLY, LS (L_THISPATHONLY_HERE)),
		fsCtrlContextHelp (IDC_SUBFOLDERS, LS (L_INCLUDINGSUBFOLDERS_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}
