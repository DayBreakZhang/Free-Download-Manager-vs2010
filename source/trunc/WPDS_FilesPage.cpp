/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WPDS_FilesPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CWPDS_FilesPage, CPropertyPage)

CWPDS_FilesPage::CWPDS_FilesPage() : CPropertyPage(CWPDS_FilesPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_FILES);
}

CWPDS_FilesPage::~CWPDS_FilesPage()
{
}

void CWPDS_FilesPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWPDS_FilesPage)
		
	//}}AFX_DATA_MAP

	BOOL bDLAll = !m_wpds->bNotAllFiles;
	BOOL bEl = m_wpds->enExtsType != WPDET_OFF;
	BOOL bElDL = m_wpds->enExtsType != WPDET_NOTDOWNLOAD;
	BOOL bElNDL = !bElDL;
	CString strExts = m_wpds->strExts;
	
	DDX_Text (pDX, IDC_EXTS, strExts);

	DDX_Check (pDX, IDC_DLFILESFROMOTHERSITES, bDLAll);
	DDX_Check (pDX, IDC_ELON, bEl);
	DDX_Check (pDX, IDC_ELDL, bElDL);
	DDX_Check (pDX, IDC_ELDONTDL, bElNDL);

	if (strExts == "" && bEl)
	{
		MessageBox (LS (L_ENTEREXTS), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_EXTS)->SetFocus ();
		pDX->Fail ();
		return;
	}

	DDX_Check (pDX, IDC_DLFILES, m_wpds->bDownloadFiles);

	m_wpds->bNotAllFiles = !bDLAll;
	if (bEl)
	{
		if (bElDL)
			m_wpds->enExtsType = WPDET_DOWNLOAD;
		else
			m_wpds->enExtsType = WPDET_NOTDOWNLOAD;
	}
	else
		m_wpds->enExtsType = WPDET_OFF;
	m_wpds->strExts = strExts;

	if (m_wpds->m_ppoOwner)
		m_wpds->m_ppoOwner->setDirty();
}

BEGIN_MESSAGE_MAP(CWPDS_FilesPage, CPropertyPage)
	//{{AFX_MSG_MAP(CWPDS_FilesPage)
	ON_BN_CLICKED(IDC_DLFILES, OnDlfiles)
	ON_BN_CLICKED(IDC_ELON, OnElon)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_DLFILESFROMOTHERSITES, OnDlfilesfromothersites)
	ON_BN_CLICKED(IDC_ELDL, OnEldl)
	ON_BN_CLICKED(IDC_ELDONTDL, OnEldontdl)
	ON_EN_CHANGE(IDC_EXTS, OnChangeExts)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWPDS_FilesPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CWPDS_FilesPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_DLFILES) == BST_CHECKED;

	GetDlgItem (IDC_DLFILESFROMOTHERSITES)->EnableWindow (b);
	GetDlgItem (IDC_ELON)->EnableWindow (b);
	GetDlgItem (IDC__ELIMINATION)->EnableWindow (b);

	b = b && IsDlgButtonChecked (IDC_ELON) == BST_CHECKED;
	UINT nIDs [] = {
		IDC_ELDL, IDC_ELDONTDL, IDC__EXTS, IDC_EXTS
	};
	for (int i = 0; i < sizeof (nIDs) / sizeof (UINT); i++)
		GetDlgItem (nIDs [i])->EnableWindow (b);
}

void CWPDS_FilesPage::OnDlfiles() 
{
	UpdateEnabled ();
	SetModified ();
}

void CWPDS_FilesPage::OnElon() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CWPDS_FilesPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DLFILES, L_DLFILES),
		fsDlgLngInfo (IDC_DLFILESFROMOTHERSITES, L_DLFILESFROMOTHERSITES),
		fsDlgLngInfo (IDC__ELIMINATION, L_ELIMINATION),
		fsDlgLngInfo (IDC_ELON, L_TURNON),
		fsDlgLngInfo (IDC_ELDL, L_TODONWLOAD),
		fsDlgLngInfo (IDC_ELDONTDL, L_DONTDOWNLOAD),
		fsDlgLngInfo (IDC__EXTS, L_FILESTHISEXTS),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CWPDS_FilesPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CWPDS_FilesPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CWPDS_FilesPage::OnDlfilesfromothersites() 
{
	SetModified ();	
}

void CWPDS_FilesPage::OnEldl() 
{
	SetModified ();
}

void CWPDS_FilesPage::OnEldontdl() 
{
	SetModified ();	
}

void CWPDS_FilesPage::OnChangeExts() 
{
	SetModified ();	
}

void CWPDS_FilesPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_DLFILES, LS (L_DLFILESHERE)),
		fsCtrlContextHelp (IDC_DLFILESFROMOTHERSITES, LS (L_DLFILESFROMHERE)),
		fsCtrlContextHelp (IDC_ELON, LS (L_ELONHERE)),
		fsCtrlContextHelp (IDC_ELDL, LS (L_ELDLHERE)),
		fsCtrlContextHelp (IDC_ELDONTDL, LS (L_ELDONTDLHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CWPDS_FilesPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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
