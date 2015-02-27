/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WPDS_WebPagesPage.h"
#include "Dlg_WPD_IgnoreList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CWPDS_WebPagesPage, CPropertyPage)

CWPDS_WebPagesPage::CWPDS_WebPagesPage() : CPropertyPage(CWPDS_WebPagesPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_WEBPAGES);
	m_bUsedAsSetDefaults = false;
}

CWPDS_WebPagesPage::~CWPDS_WebPagesPage()
{
}

void CWPDS_WebPagesPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);

	CString strHTMLExts = m_wpds->strHTMLExts;
	BOOL bDLAll = !m_wpds->bNotAllPages;
	BOOL bHTM = m_wpds->bSavePagesUnderHTM;
	int iDepth = m_wpds->iDepth;

	//{{AFX_DATA_MAP(CWPDS_WebPagesPage)
	DDX_Control(pDX, IDC_DEPTHSPIN, m_wndDepthSpin);
	//}}AFX_DATA_MAP

	DDX_Text (pDX, IDC_HTMLEXTS, strHTMLExts);

	if (strHTMLExts == "")
	{
		MessageBox (LS (L_ENTEREXTS), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_HTMLEXTS)->SetFocus ();
		pDX->Fail ();
		return;
	}

	DDX_Text (pDX, IDC_DEPTH, iDepth);

	DDX_Check (pDX, IDC_DLSTYLES, m_wpds->bDownloadStyles);
	DDX_Check (pDX, IDC_DLWPFROMOTHERSITES, bDLAll);
	DDX_Check (pDX, IDC_USEHTM, bHTM);

	m_wpds->strHTMLExts = strHTMLExts;
	m_wpds->iDepth = iDepth;
	m_wpds->bNotAllPages = !bDLAll;
	m_wpds->bSavePagesUnderHTM = bHTM;

	if (m_wpds->m_ppoOwner)
		m_wpds->m_ppoOwner->setDirty();
}

BEGIN_MESSAGE_MAP(CWPDS_WebPagesPage, CPropertyPage)
	//{{AFX_MSG_MAP(CWPDS_WebPagesPage)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_EN_CHANGE(IDC_HTMLEXTS, OnChangeHtmlexts)
	ON_BN_CLICKED(IDC_DLSTYLES, OnDlstyles)
	ON_BN_CLICKED(IDC_DLWPFROMOTHERSITES, OnDlwpfromothersites)
	ON_EN_CHANGE(IDC_DEPTH, OnChangeDepth)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_USEHTM, OnUsehtm)
	ON_BN_CLICKED(IDC_IGNORELIST, OnIgnorelist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CWPDS_WebPagesPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_wndDepthSpin.SetRange (0, UD_MAXVAL);

	if (m_bUsedAsSetDefaults)
		GetDlgItem (IDC_IGNORELIST)->EnableWindow (FALSE);

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CWPDS_WebPagesPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__PAGES, L_PAGES),
		fsDlgLngInfo (IDC__HTMLEXTS, L_HTMLEXTS),
		fsDlgLngInfo (IDC_DLSTYLES, L_DLWPSTYLES),
		fsDlgLngInfo (IDC_DLWPFROMOTHERSITES, L_DLWPFROMOTHERSITES),
		fsDlgLngInfo (IDC__DEPTH, L_DLDEPTH),
		fsDlgLngInfo (IDC_USEHTM, L_SAVEUNDERHTM),
		fsDlgLngInfo (IDC_IGNORELIST, L_IGNORELIST),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CWPDS_WebPagesPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CWPDS_WebPagesPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CWPDS_WebPagesPage::OnChangeHtmlexts() 
{
	SetModified ();
}

void CWPDS_WebPagesPage::OnDlstyles() 
{
	SetModified ();	
}

void CWPDS_WebPagesPage::OnDlwpfromothersites() 
{
	SetModified ();
}

void CWPDS_WebPagesPage::OnChangeDepth() 
{
	SetModified ();	
}

void CWPDS_WebPagesPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__HTMLEXTS, LS (L_HTMLEXTSHERE)),
		fsCtrlContextHelp (IDC_HTMLEXTS, LS (L_HTMLEXTSHERE)),
		fsCtrlContextHelp (IDC_DLSTYLES, LS (L_DLSTYLESHERE)),
		fsCtrlContextHelp (IDC_DLWPFROMOTHERSITES, LS (L_DLWPFROMHERE)),
		fsCtrlContextHelp (IDC__DEPTH, LS (L_DLDEPTHHERE)),
		fsCtrlContextHelp (IDC_DEPTH, LS (L_DLDEPTHHERE)),
		fsCtrlContextHelp (IDC_USEHTM, LS (L_USEHTMHERE)),
		fsCtrlContextHelp (IDC_IGNORELIST, LS (L_IGNORELISTHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CWPDS_WebPagesPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CWPDS_WebPagesPage::OnUsehtm() 
{
	SetModified ();	
}

void CWPDS_WebPagesPage::OnIgnorelist() 
{
	CDlg_WPD_IgnoreList dlg (m_wpds, this);
	if (IDOK == _DlgMgr.DoModal (&dlg))
		SetModified ();
}
