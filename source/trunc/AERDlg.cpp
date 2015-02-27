/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdmapp.h"
#include "AERDlg.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CAERDlg::CAERDlg(CWnd* pParent )
	: CDialog(CAERDlg::IDD, pParent)
{
	m_bDSR = FALSE;
	m_enAER = AER_RENAME;	
	//{{AFX_DATA_INIT(CAERDlg)
		
	//}}AFX_DATA_INIT
}

void CAERDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAERDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAERDlg, CDialog)
	//{{AFX_MSG_MAP(CAERDlg)
	ON_BN_CLICKED(IDC_REWRITE, OnRewrite)
	ON_BN_CLICKED(IDC_RENAME, OnRename)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_RESUME, OnResume)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_CLOSE()
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CAERDlg::OnRewrite() 
{
	m_enAER = AER_REWRITE;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);
}

void CAERDlg::OnRename() 
{
	m_enAER = AER_RENAME;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);	
}

void CAERDlg::OnStop() 
{
	m_enAER = AER_STOP;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);	
}

void CAERDlg::OnResume() 
{
	m_enAER = AER_RESUME;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);	
}

BOOL CAERDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	((CStatic*) GetDlgItem (IDC_DLGICON))->SetIcon (LoadIcon (NULL, IDI_QUESTION));

	
	CString str;
	str.Format (LS (L_FILEEXISTSWHATTODO), m_pszFile);
	SetDlgItemText (IDC__MESSAGE, str);

	if (m_bDSR)
	{
		GetDlgItem (IDC_STOP)->EnableWindow (FALSE);
		GetDlgItem (IDC_RESUME)->EnableWindow (FALSE);
	}

	GetDlgItem (IDC_RENAME)->SetFocus ();	

	ApplyLanguage ();

    mfcSetTopmostWindow (this);

	return FALSE;
}

void CAERDlg::DisableStopAndResume()
{
	m_bDSR = TRUE;
}

void CAERDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CAERDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DONTASKAGAIN, L_DONTASKAGAIN),
		fsDlgLngInfo (IDC_REWRITE, L_REWRITE),
		fsDlgLngInfo (IDC_RENAME, L_RENAME),
		fsDlgLngInfo (IDC_RESUME, L_RESUME),
		fsDlgLngInfo (IDC_STOP, L_STOP),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ASKUSER);
}

void CAERDlg::OnClose() 
{

}

void CAERDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

BOOL CAERDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CAERDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_DONTASKAGAIN, LS (L_DONTASKAGAINHERE)),
		fsCtrlContextHelp (IDC_REWRITE, LS (L_REWRITEHERE)),
		fsCtrlContextHelp (IDC_RENAME, LS (L_RENAMEHERE)),
		fsCtrlContextHelp (IDC_RESUME, LS (L_RESUMEHERE)),
		fsCtrlContextHelp (IDC_STOP, LS (L_STOPHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}
