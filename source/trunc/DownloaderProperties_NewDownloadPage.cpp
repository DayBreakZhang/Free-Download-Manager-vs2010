/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloaderProperties_NewDownloadPage.h"
#include "DownloadsWnd.h"
#include "GroupDlg.h"
#include "FolderBrowser.h"

extern CDownloadsWnd* _pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CDownloaderProperties_NewDownloadPage, CPropertyPage)

CDownloaderProperties_NewDownloadPage::CDownloaderProperties_NewDownloadPage() : CPropertyPage(CDownloaderProperties_NewDownloadPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_NEWDOWNLOAD);
}

CDownloaderProperties_NewDownloadPage::~CDownloaderProperties_NewDownloadPage()
{
}

void CDownloaderProperties_NewDownloadPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDownloaderProperties_NewDownloadPage)
	DDX_Control(pDX, IDC_CREATEGROUP2, m_btnCreateGroup2);
	DDX_Control(pDX, IDC_GROUPS2, m_wndGroups2);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDownloaderProperties_NewDownloadPage, CPropertyPage)
	//{{AFX_MSG_MAP(CDownloaderProperties_NewDownloadPage)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_AUTOSTART, OnAutostart)
	ON_BN_CLICKED(IDC_USEZIP, OnUsezip)
	ON_BN_CLICKED(IDC_NEWGRP_0, OnNewgrp0)
	ON_BN_CLICKED(IDC_NEWGRP_1, OnNewgrp1)
	ON_BN_CLICKED(IDC_NEWGRP_2, OnNewgrp2)
	ON_BN_CLICKED(IDC_CREATEGROUP2, OnCreategroup2)
	ON_BN_CLICKED(IDC_SETGRPSFLDR, OnSetgrpsfldr)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDownloaderProperties_NewDownloadPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));
	m_btnCreateGroup2.SetIcon (SICO (IDI_CREATEGROUP));

	m_wndGroups.Fill ();
	m_wndGroups2.Fill ();

	switch (_App.NewGrp_SelectWay ())
	{
	case NGSW_CHOOSE_BY_EXT:
		if (_App.NewDL_GroupId () != (UINT)-1)
			_App.NewDL_GroupId ((UINT)-1);
		CheckRadioButton (IDC_NEWGRP_0, IDC_NEWGRP_2, IDC_NEWGRP_0);
		m_wndGroups.SelectGroupById (GRP_OTHER_ID);
		m_wndGroups2.SelectGroupById (GRP_OTHER_ID);
		break;

	case NGSW_USE_ALWAYS_SAME_GROUP:
		CheckRadioButton (IDC_NEWGRP_0, IDC_NEWGRP_2, IDC_NEWGRP_1);
		m_wndGroups.SelectGroupById (_App.NewDL_GroupId ());
		m_wndGroups2.SelectGroupById (GRP_OTHER_ID);
		break;

	case NGSW_USE_ALWAYS_SAME_GROUP_WITH_OUTFOLDER_AUTO_UPDATE:
		CheckRadioButton (IDC_NEWGRP_0, IDC_NEWGRP_2, IDC_NEWGRP_2);
		m_wndGroups.SelectGroupById (GRP_OTHER_ID);
		m_wndGroups2.SelectGroupById (_App.NewDL_GroupId ());
		break;
	}

	CheckDlgButton (IDC_AUTOSTART, _App.NewDL_AutoStart () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_USEZIP, _App.NewDL_UseZIPPreview () ? BST_CHECKED : BST_UNCHECKED);

	ApplyLanguage ();

	UpdateEnabled ();
	
	return TRUE; 
}

BOOL CDownloaderProperties_NewDownloadPage::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CDownloaderProperties_NewDownloadPage::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();		
}

void CDownloaderProperties_NewDownloadPage::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CDownloaderProperties_NewDownloadPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GRPFORNEWDLD, L_GRPFORNEWDLD),
		fsDlgLngInfo (IDC_NEWGRP_0, L_GROUPBYEXT),
		fsDlgLngInfo (IDC_NEWGRP_1, L_ALWAYSUSETHISGRP),
		fsDlgLngInfo (IDC_NEWGRP_2, L_ALWAYSUSESAMEGRPANDAUTOUPDATEOUTFOLDER),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDC_AUTOSTART, L_STARTDLDAUTOMATICALLY),
		fsDlgLngInfo (IDC_USEZIP, L_USEZIPPREVIEW),
		fsDlgLngInfo (IDC_SETGRPSFLDR, L_SETDEFDLDFLDR),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDownloaderProperties_NewDownloadPage::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_NEWGRP_0, LS (L_GROUPBYEXTHERE)),
		fsCtrlContextHelp (IDC_GROUPS, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC_CREATEGROUP, LS (L_CREATEGRP)),
		fsCtrlContextHelp (IDC_ADVANCED, LS (L_ADVANCEDHERE)),
		fsCtrlContextHelp (IDC_AUTOSTART, LS (L_DLDAUTOSTARTHERE)),
		fsCtrlContextHelp (IDC_USEZIP, LS (L_USEZIPPREVIEWHERE)),
	};

	static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CDownloaderProperties_NewDownloadPage::UpdateEnabled()
{
	BOOL b1, b2;

	if (IsDlgButtonChecked (IDC_NEWGRP_0) == BST_CHECKED)
		b1 = b2 = FALSE;
	else if (IsDlgButtonChecked (IDC_NEWGRP_1) == BST_CHECKED) {
		b1 = TRUE; b2 = FALSE;
	}
	else {
		b1 = FALSE; b2 = TRUE;
	}

	GetDlgItem (IDC_GROUPS)->EnableWindow (b1);
	GetDlgItem (IDC_CREATEGROUP)->EnableWindow (b1);

	GetDlgItem (IDC_GROUPS2)->EnableWindow (b2);
	GetDlgItem (IDC_CREATEGROUP2)->EnableWindow (b2);
}

void CDownloaderProperties_NewDownloadPage::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
		SetModified ();
}

void CDownloaderProperties_NewDownloadPage::OnAdvanced() 
{
	_pwndDownloads->OnDownloadDefProperties ();	
}

void CDownloaderProperties_NewDownloadPage::OnSelchangeGroups() 
{
	SetModified ();	
}

BOOL CDownloaderProperties_NewDownloadPage::OnApply() 
{
	if (IsDlgButtonChecked (IDC_NEWGRP_0) == BST_CHECKED)
	{
		_App.NewGrp_SelectWay (NGSW_CHOOSE_BY_EXT);
		_App.NewDL_GroupId ((UINT)-1);
	}
	else if (IsDlgButtonChecked (IDC_NEWGRP_1) == BST_CHECKED)
	{
		_App.NewGrp_SelectWay (NGSW_USE_ALWAYS_SAME_GROUP);
		_App.NewDL_GroupId (m_wndGroups.GetSelectedGroup ()->nId);
	}
	else
	{
		_App.NewGrp_SelectWay (NGSW_USE_ALWAYS_SAME_GROUP_WITH_OUTFOLDER_AUTO_UPDATE);
		_App.NewDL_GroupId (m_wndGroups2.GetSelectedGroup ()->nId);
	}

	_App.NewDL_AutoStart (IsDlgButtonChecked (IDC_AUTOSTART) == BST_CHECKED);
	_App.NewDL_UseZIPPreview (IsDlgButtonChecked (IDC_USEZIP) == BST_CHECKED);
	
	return CPropertyPage::OnApply();
}

void CDownloaderProperties_NewDownloadPage::OnAutostart() 
{
	SetModified ();	
}

void CDownloaderProperties_NewDownloadPage::OnUsezip() 
{
	SetModified ();	
}

void CDownloaderProperties_NewDownloadPage::OnNewgrp0() 
{
	SetModified ();
	UpdateEnabled ();
}

void CDownloaderProperties_NewDownloadPage::OnNewgrp1() 
{
	SetModified ();
	UpdateEnabled ();
}

void CDownloaderProperties_NewDownloadPage::OnNewgrp2() 
{
	SetModified ();
	UpdateEnabled ();	
}

void CDownloaderProperties_NewDownloadPage::OnCreategroup2() 
{
	if (m_wndGroups2.CreateNewGroup (m_wndGroups2.GetSelectedGroup ()))
		SetModified ();	
}

void CDownloaderProperties_NewDownloadPage::OnSetgrpsfldr() 
{
	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), 
		_DldsGrps.FindGroup (GRP_OTHER_ID)->strOutFolder, NULL, this);
	if (fb == NULL)
		return;

	CString str = fb->GetPath ();
	if (str.Right (1) != '\\')
		str += '\\';

	if (MessageBox (LS (L_ALLGRPSFLDRSWBCHANGEDTOTHISFLDR), NULL, MB_YESNO) == IDNO)
		return;

	for (size_t i = 0; i < _DldsGrps.GetTotalCount (); i++) {
		_DldsGrps.GetGroup (i)->strOutFolder = str;
		_DldsGrps.GetGroup (i)->setDirty();
		
	}

	
	
	
	
}
