/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WPDS_ImagesPages.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CWPDS_ImagesPages, CPropertyPage)

CWPDS_ImagesPages::CWPDS_ImagesPages() : CPropertyPage(CWPDS_ImagesPages::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_IMAGES);
}

CWPDS_ImagesPages::~CWPDS_ImagesPages()
{
}

void CWPDS_ImagesPages::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	BOOL bDLAll = !m_wpds->bNotAllImages;
	BOOL bEl = m_wpds->enImgsExtsType != WPDET_OFF;
	BOOL bElDL = m_wpds->enImgsExtsType != WPDET_NOTDOWNLOAD;
	BOOL bElNDL = !bElDL;
	CString strExts = m_wpds->strImgsExts;
	
	DDX_Text (pDX, IDC_EXTS, strExts);

	DDX_Check (pDX, IDC_DLIMAGESFROMOTHERSITES, bDLAll);
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

	DDX_Check (pDX, IDC_DLIMAGES, m_wpds->bDownloadImages);

	m_wpds->bNotAllImages = !bDLAll;
	if (bEl)
	{
		if (bElDL)
			m_wpds->enImgsExtsType = WPDET_DOWNLOAD;
		else
			m_wpds->enImgsExtsType = WPDET_NOTDOWNLOAD;
	}
	else
		m_wpds->enImgsExtsType = WPDET_OFF;
	m_wpds->strImgsExts = strExts;

	if (m_wpds->m_ppoOwner)
		m_wpds->m_ppoOwner->setDirty();
}

BEGIN_MESSAGE_MAP(CWPDS_ImagesPages, CPropertyPage)
	//{{AFX_MSG_MAP(CWPDS_ImagesPages)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_DLIMAGES, OnDlimages)
	ON_BN_CLICKED(IDC_ELON, OnElon)
	ON_BN_CLICKED(IDC_DLIMAGESFROMOTHERSITES, OnDlimagesfromothersites)
	ON_BN_CLICKED(IDC_ELDL, OnEldl)
	ON_BN_CLICKED(IDC_ELDONTDL, OnEldontdl)
	ON_EN_CHANGE(IDC_EXTS, OnChangeExts)
	ON_WM_HELPINFO()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWPDS_ImagesPages::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DLIMAGES, L_DLIMAGES),
		fsDlgLngInfo (IDC_DLIMAGESFROMOTHERSITES, L_DLIMAGESFROMOTHERSITES),
		fsDlgLngInfo (IDC__ELIMINATION, L_IMGELIMINATION),
		fsDlgLngInfo (IDC_ELON, L_TURNON),
		fsDlgLngInfo (IDC_ELDL, L_TODONWLOAD),
		fsDlgLngInfo (IDC_ELDONTDL, L_DONTDOWNLOAD),
		fsDlgLngInfo (IDC__EXTS, L_IMGSTHISEXTS),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CWPDS_ImagesPages::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	UpdateEnabled ();
	
	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CWPDS_ImagesPages::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CWPDS_ImagesPages::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CWPDS_ImagesPages::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_DLIMAGES) == BST_CHECKED;

	GetDlgItem (IDC_DLIMAGESFROMOTHERSITES)->EnableWindow (b);
	GetDlgItem (IDC_ELON)->EnableWindow (b);
	GetDlgItem (IDC__ELIMINATION)->EnableWindow (b);

	b = b && IsDlgButtonChecked (IDC_ELON) == BST_CHECKED;
	UINT nIDs [] = {
		IDC_ELDL, IDC_ELDONTDL, IDC__EXTS, IDC_EXTS
	};
	for (int i = 0; i < sizeof (nIDs) / sizeof (UINT); i++)
		GetDlgItem (nIDs [i])->EnableWindow (b);
}

void CWPDS_ImagesPages::OnDlimages() 
{
	UpdateEnabled ();
	SetModified ();
}

void CWPDS_ImagesPages::OnElon() 
{
	UpdateEnabled ();
	SetModified ();	
}

void CWPDS_ImagesPages::OnDlimagesfromothersites() 
{
	SetModified ();	
}

void CWPDS_ImagesPages::OnEldl() 
{
	SetModified ();	
}

void CWPDS_ImagesPages::OnEldontdl() 
{
	SetModified ();	
}

void CWPDS_ImagesPages::OnChangeExts() 
{
	SetModified ();	
}

void CWPDS_ImagesPages::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_DLIMAGES, LS (L_DLIMAGESHERE)),
		fsCtrlContextHelp (IDC_DLIMAGESFROMOTHERSITES, LS (L_DLIMAGESFROMHERE)),
		fsCtrlContextHelp (IDC_ELON, LS (L_IMGELONHERE)),
		fsCtrlContextHelp (IDC_ELDL, LS (L_IMGELDLHERE)),
		fsCtrlContextHelp (IDC_ELDONTDL, LS (L_IMGELDONTDLHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CWPDS_ImagesPages::OnHelpInfo(HELPINFO* pHelpInfo) 
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
