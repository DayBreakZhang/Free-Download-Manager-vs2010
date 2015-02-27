/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SCRDlg.h"
#include "downloadproperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CSCRDlg::CSCRDlg(CWnd* pParent )
	: CDialog(CSCRDlg::IDD, pParent)
{
	m_enSCR = SCR_RESTART;	
	//{{AFX_DATA_INIT(CSCRDlg)
		
	//}}AFX_DATA_INIT
}

void CSCRDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSCRDlg)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSCRDlg, CDialog)
	//{{AFX_MSG_MAP(CSCRDlg)
	ON_BN_CLICKED(IDC_RESTART, OnRestart)
	ON_BN_CLICKED(IDC_ADJUST, OnAdjust)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_CLOSE()
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSCRDlg::OnRestart() 
{
	m_enSCR = SCR_RESTART;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);
}

void CSCRDlg::OnAdjust() 
{
	m_enSCR = SCR_ADJUSTFORNEWSIZE;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);
}

void CSCRDlg::OnStop() 
{
	m_enSCR = SCR_STOP;
	m_bDontAskAgain = IsDlgButtonChecked (IDC_DONTASKAGAIN) == BST_CHECKED;
	EndDialog (IDOK);	
}

BOOL CSCRDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	((CStatic*) GetDlgItem (IDC_DLGICON))->SetIcon (LoadIcon (NULL, IDI_QUESTION));

	CString str;
	char szUrl [10000];
	DWORD dwLen = 10000;
	fsURL url;

	url.Create (fsNPToScheme (m_dnp->enProtocol), m_dnp->pszServerName, m_dnp->uServerPort,
		NULL, NULL, m_dnp->pszPathName, szUrl, &dwLen);

	str.Format (LS (L_SIZECHANGEDWTD), szUrl);
	SetDlgItemText (IDC_MESSAGE, str);

	ApplyLanguage ();
	
	return TRUE;
}

void CSCRDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSCRDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CSCRDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DONTASKAGAIN, L_DONTASKAGAIN),
		fsDlgLngInfo (IDC_RESTART, L_RESTART),
		fsDlgLngInfo (IDC_ADJUST, L_ADJUST),
		fsDlgLngInfo (IDC_STOP, L_STOP),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ASKUSER);
}

void CSCRDlg::OnClose() 
{
	
}

void CSCRDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_DONTASKAGAIN, LS (L_DONTASKAGAINHERE)),
		fsCtrlContextHelp (IDC_RESTART, LS (L_RESTARTHERE)),
		fsCtrlContextHelp (IDC_ADJUST, LS (L_ADJUSTHERE)),
		fsCtrlContextHelp (IDC_STOP, LS (L_STOPHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

BOOL CSCRDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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
