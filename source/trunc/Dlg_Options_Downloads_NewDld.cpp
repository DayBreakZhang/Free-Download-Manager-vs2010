/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "Dlg_Options_Downloads_NewDld.h"
#include "FolderBrowser.h"
#include "SpiderWnd.h"

extern CSpiderWnd *_pwndSpider;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDlg_Options_Downloads_NewDld::CDlg_Options_Downloads_NewDld(CWnd* pParent )
	: CDlg_Options_Page(CDlg_Options_Downloads_NewDld::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_Options_Downloads_NewDld)
		
	//}}AFX_DATA_INIT
}

void CDlg_Options_Downloads_NewDld::DoDataExchange(CDataExchange* pDX)
{
	CDlg_Options_Page::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_Options_Downloads_NewDld)
	DDX_Control(pDX, IDC_CREATEGROUP2, m_btnCreateGroup2);
	DDX_Control(pDX, IDC_GROUPS2, m_wndGroups2);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlg_Options_Downloads_NewDld, CDlg_Options_Page)
	//{{AFX_MSG_MAP(CDlg_Options_Downloads_NewDld)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CREATEGROUP2, OnCreategroup2)
	ON_BN_CLICKED(IDC_SETGRPSFLDR, OnSetgrpsfldr)
	ON_BN_CLICKED(IDC_NEWGRP_0, OnNewgrp0)
	ON_BN_CLICKED(IDC_NEWGRP_1, OnNewgrp1)
	ON_BN_CLICKED(IDC_NEWGRP_2, OnNewgrp2)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_BN_CLICKED(IDC_HTMLSPIDER_DEFDLDSTGS, OnHtmlspiderDefdldstgs)
	ON_BN_CLICKED(IDC_BT_DEFDLDSTGS, OnBtDefdldstgs)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CDlg_Options_Downloads_NewDld::OnInitDialog() 
{
	CDlg_Options_Page::OnInitDialog();
	
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
	
	CheckDlgButton (IDC_CHECKEXISTS, _App.CheckIfDownloadWithSameUrlExists () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_AUTOSTART, _App.NewDL_AutoStart () ? BST_CHECKED : BST_UNCHECKED);
	CheckDlgButton (IDC_USEZIP, _App.NewDL_UseZIPPreview () ? BST_CHECKED : BST_UNCHECKED);
	
	
	ApplyLanguage ();
	UpdateEnabled ();
	
	return TRUE;  
	              
}

CString CDlg_Options_Downloads_NewDld::get_PageTitle()
{
	return LS (L_NEWDOWNLOAD);
}

CString CDlg_Options_Downloads_NewDld::get_PageShortTitle()
{
	return LS (L_NEWDOWNLOAD);
}

BOOL CDlg_Options_Downloads_NewDld::Apply()
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
	
	_App.CheckIfDownloadWithSameUrlExists (IsDlgButtonChecked (IDC_CHECKEXISTS) == BST_CHECKED);
	_App.NewDL_AutoStart (IsDlgButtonChecked (IDC_AUTOSTART) == BST_CHECKED);
	_App.NewDL_UseZIPPreview (IsDlgButtonChecked (IDC_USEZIP) == BST_CHECKED);
	
	return TRUE;
}

void CDlg_Options_Downloads_NewDld::ApplyLanguage()
{
	CString str0;
	str0 = LS (L_STARTDLDAUTOMATICALLY);
	str0 += _T (" (");
	str0 += LS (L_AFTERSILENTCREATION);
	str0 += ')';
	SetDlgItemText (IDC_AUTOSTART, str0);

	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GRPFORNEWDLD, L_GRPFORNEWDLD),
		fsDlgLngInfo (IDC_NEWGRP_0, L_GROUPBYEXT),
		fsDlgLngInfo (IDC_NEWGRP_1, L_ALWAYSUSETHISGRP),
		fsDlgLngInfo (IDC_NEWGRP_2, L_ALWAYSUSESAMEGRPANDAUTOUPDATEOUTFOLDER),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDC_USEZIP, L_USEZIPPREVIEW),
		fsDlgLngInfo (IDC_SETGRPSFLDR, L_SETDEFDLDFLDR),
		fsDlgLngInfo (IDC_HTMLSPIDER_DEFDLDSTGS, L_SITESDLD_DEFSTGS),
		fsDlgLngInfo (IDC_CHECKEXISTS, L_CHECKDLDWITHSAMEURLEXISTS),
		fsDlgLngInfo (IDC_BT_DEFDLDSTGS, L_BTDLD_DEFSTGS),
	};
	
	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

void CDlg_Options_Downloads_NewDld::UpdateEnabled()
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

void CDlg_Options_Downloads_NewDld::OnCreategroup() 
{
	m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ());
}

void CDlg_Options_Downloads_NewDld::OnCreategroup2() 
{
	m_wndGroups2.CreateNewGroup (m_wndGroups2.GetSelectedGroup ());
}

void CDlg_Options_Downloads_NewDld::OnSetgrpsfldr() 
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

void CDlg_Options_Downloads_NewDld::OnNewgrp0() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_NewDld::OnNewgrp1() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_NewDld::OnNewgrp2() 
{
	UpdateEnabled ();	
}

void CDlg_Options_Downloads_NewDld::OnAdvanced() 
{
	_pwndDownloads->OnDownloadDefProperties ();	
}

void CDlg_Options_Downloads_NewDld::OnHtmlspiderDefdldstgs() 
{
	_pwndSpider->SetupDefSettings ();		
}

void CDlg_Options_Downloads_NewDld::OnBtDefdldstgs() 
{
	_pwndDownloads->OnBtDownloadDefProperties ();	
}
