/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "NOWDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CNOWDlg::CNOWDlg(CWnd* pParent )
	: CDialog(CNOWDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNOWDlg)
		
	//}}AFX_DATA_INIT
}

void CNOWDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNOWDlg)
	DDX_Control(pDX, IDC_CT, m_wndCT);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNOWDlg, CDialog)
	//{{AFX_MSG_MAP(CNOWDlg)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CNOWDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_wndCT.AddString ("14.4K Modem");
	m_wndCT.AddString ("28.8K Modem");
	m_wndCT.AddString ("33.6K Modem");
	m_wndCT.AddString ("56K Modem/ISDN");
	m_wndCT.AddString ("112K Dual ISDN");
	m_wndCT.AddString ("256K DSL/Cable");
	m_wndCT.AddString ("512K DSL/Cable");
	m_wndCT.AddString ("768K DSL/Cable");
	m_wndCT.AddString ("1M DSL/Cable");
	m_wndCT.AddString ("1.5M DSL/Cable");
	m_wndCT.AddString ("2M DSL/Cable");
	m_wndCT.AddString ("10/100M LAN");

	m_wndCT.SetCurSel (_App.NOW ());

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CNOWDlg::OnOK() 
{
	m_enCT = (fsConnectionType) m_wndCT.GetCurSel ();

	_App.NOW (m_enCT);
	
	CDialog::OnOK();
}

void CNOWDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CNOWDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CNOWDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__WELCOMETONOW, L_WELCOMETONOW),
		fsDlgLngInfo (IDC__MASTERDESC, L_NOWDESC),
		fsDlgLngInfo (IDC__CONNTYPE, L_SELECTCONNTYPE),
		fsDlgLngInfo (IDOK, L_FINISH),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_NOW);
}

BOOL CNOWDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CNOWDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_CT, LS (L_CONNTYPEHERE)),
		fsCtrlContextHelp (IDOK, LS (L_ADJUSTFDM)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTACCEPTCHANGES)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}
