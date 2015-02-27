/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "Prg_UpdatePage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPrg_UpdatePage, CPropertyPage)

CPrg_UpdatePage::CPrg_UpdatePage() : CPropertyPage(CPrg_UpdatePage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_UPDATE);
}

CPrg_UpdatePage::~CPrg_UpdatePage()
{
}

void CPrg_UpdatePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrg_UpdatePage)
		
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPrg_UpdatePage, CPropertyPage)
	//{{AFX_MSG_MAP(CPrg_UpdatePage)
	ON_EN_CHANGE(IDC_UPDATEURL, OnChangeUpdateurl)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_AUTOUPDATES_INSTALL, OnAutoupdatesInstall)
	ON_BN_CLICKED(IDC_AUTOUPDATES_NOTIFYONLY, OnAutoupdatesNotifyonly)
	ON_BN_CLICKED(IDC_AUTOUPDATES_TURNOFF, OnAutoupdatesTurnoff)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPrg_UpdatePage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	SetDlgItemText (IDC_UPDATEURL, _UpdateMgr.m_strUpdateUrl);
	CheckRadioButton (IDC_AUTOUPDATES_INSTALL, IDC_AUTOUPDATES_TURNOFF,
		IDC_AUTOUPDATES_INSTALL + _UpdateMgr.m_enAUT);

	ApplyLanguage ();

	UpdateEnabled ();
	
	return TRUE;  
	              
}

void CPrg_UpdatePage::OnChangeUpdateurl() 
{
	SetModified ();
}

BOOL CPrg_UpdatePage::OnApply() 
{
	CString str;

	GetDlgItemText (IDC_UPDATEURL, str);

	
	if (str [str.GetLength () - 1] != '\\' && str [str.GetLength () - 1] != '/')
		str += '/';

	fsURL url;
	if (url.Crack (str) != IR_SUCCESS || *url.GetHostName () == 0)
	{
		MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
		CEdit *pE = (CEdit*) GetDlgItem (IDC_UPDATEURL);
		pE->SetSel (0, -1);
		pE->SetFocus ();
		return FALSE;
	}

	_UpdateMgr.m_strUpdateUrl = _UpdateMgr.m_strDlFullInstallPath = _UpdateMgr.m_strDlUpgradesPath = str;

	if (IsDlgButtonChecked (IDC_AUTOUPDATES_INSTALL) == BST_CHECKED)
		_UpdateMgr.m_enAUT = AUT_DLANDINST;
	else if (IsDlgButtonChecked (IDC_AUTOUPDATES_NOTIFYONLY) == BST_CHECKED)
		_UpdateMgr.m_enAUT = AUT_NOTIFYONLY;
	else
		_UpdateMgr.m_enAUT = AUT_TURNOFF;
	
	return CPropertyPage::OnApply();
}

void CPrg_UpdatePage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CPrg_UpdatePage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CPrg_UpdatePage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_AUTOUPDATES_INSTALL, L_AUTOUPDATE_DLANDINST),
		fsDlgLngInfo (IDC_AUTOUPDATES_NOTIFYONLY, L_AUTOUPDATE_NOTIFYONLY),
		fsDlgLngInfo (IDC_AUTOUPDATES_TURNOFF, L_AUTOUPDATE_TURNOFF),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CPrg_UpdatePage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__URL, LS (L_UPDSERVURLHERE)),
		fsCtrlContextHelp (IDC_UPDATEURL, LS (L_UPDSERVURLHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CPrg_UpdatePage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CPrg_UpdatePage::OnAutoupdatesInstall() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CPrg_UpdatePage::OnAutoupdatesNotifyonly() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CPrg_UpdatePage::OnAutoupdatesTurnoff() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CPrg_UpdatePage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_AUTOUPDATES_TURNOFF) != BST_CHECKED;
	GetDlgItem (IDC__URL)->EnableWindow (b);
	GetDlgItem (IDC_UPDATEURL)->EnableWindow (b);
}
