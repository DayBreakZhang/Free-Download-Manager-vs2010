/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "HFE_ProtocolPage.h"
#include "HFEWnd.h"

extern CHFEWnd* _pwndHFE;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CHFE_ProtocolPage, CPropertyPage)

CHFE_ProtocolPage::CHFE_ProtocolPage() : CPropertyPage(CHFE_ProtocolPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_PROTOCOL);
}

CHFE_ProtocolPage::~CHFE_ProtocolPage()
{
}

void CHFE_ProtocolPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHFE_ProtocolPage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHFE_ProtocolPage, CPropertyPage)
	//{{AFX_MSG_MAP(CHFE_ProtocolPage)
	ON_BN_CLICKED(IDC_RETREIVEADDINFO, OnRetreiveaddinfo)
	ON_BN_CLICKED(IDC_PASSIVEMODE, OnPassivemode)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CHFE_ProtocolPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	CheckDlgButton (IDC_RETREIVEADDINFO, _App.RetreiveInfoWhileGettingList ());
	CheckDlgButton (IDC_PASSIVEMODE, _App.HFE_FtpPassiveMode ());

	ApplyLanguage ();
	
	return TRUE;  
	              
}

BOOL CHFE_ProtocolPage::OnApply() 
{
	fsInternetFileListMgr *mgr = _pwndHFE->GetMgr ();

	BOOL b = IsDlgButtonChecked (IDC_RETREIVEADDINFO) == BST_CHECKED;
	_App.RetreiveInfoWhileGettingList (b);
	mgr->RetreiveInfoWhileGettingList (b);

	b = IsDlgButtonChecked (IDC_PASSIVEMODE) == BST_CHECKED;
	_App.HFE_FtpPassiveMode (b);
	mgr->FtpPassiveMode (b);
	
	return CPropertyPage::OnApply();
}

void CHFE_ProtocolPage::OnRetreiveaddinfo() 
{
	SetModified ();	
}

void CHFE_ProtocolPage::OnPassivemode() 
{
	SetModified ();	
}

void CHFE_ProtocolPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CHFE_ProtocolPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CHFE_ProtocolPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_RETREIVEADDINFO, L_RETRADDINFO),
		fsDlgLngInfo (IDC__USINGMAY, L_USINGMAYDECREASE),
		fsDlgLngInfo (IDC_PASSIVEMODE, L_USEPASSIVEMODE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CHFE_ProtocolPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CHFE_ProtocolPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_RETREIVEADDINFO, LS (L_RETRADDINFOHERE)),
		fsCtrlContextHelp (IDC_PASSIVEMODE, LS (L_USEPASSIVEMODEHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}
