/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "coredll.h"
#include "Upload_GeneralPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CUpload_GeneralPage, CPropertyPage)

CUpload_GeneralPage::CUpload_GeneralPage() : CPropertyPage(CUpload_GeneralPage::IDD)
{
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
}

CUpload_GeneralPage::~CUpload_GeneralPage()
{
}

void CUpload_GeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUpload_GeneralPage)
	DDX_Control(pDX, IDC_COMPRESS, m_wndCompress);
	DDX_Control(pDX, IDC_FILES, m_wndFiles);
	DDX_Control(pDX, IDC_DAYSTOKEEP, m_wndDaysToKeep);
	DDX_Control(pDX, IDC_NUMBEROFDLDS, m_wndNumberOfDlds);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CUpload_GeneralPage, CPropertyPage)
	//{{AFX_MSG_MAP(CUpload_GeneralPage)
	ON_BN_CLICKED(IDC_SETPWD, OnSetpwd)
	ON_BN_CLICKED(IDC_ADVANCEDINFO, OnAdvancedinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CUpload_GeneralPage::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_SETPWD) == BST_CHECKED;
	GetDlgItem (IDC_PWD)->EnableWindow (b);
	GetDlgItem (IDC_PWD_R)->EnableWindow (b);	

	b = IsDlgButtonChecked (IDC_ADVANCEDINFO) == BST_CHECKED;
	GetDlgItem (IDC__SNDRNAME)->EnableWindow (b);
	GetDlgItem (IDC_SNDRNAME)->EnableWindow (b);
	GetDlgItem (IDC__SNDREMAIL)->EnableWindow (b);
	GetDlgItem (IDC_SNDREMAIL)->EnableWindow (b);
	GetDlgItem (IDC__RCVREMAIL)->EnableWindow (b);
	GetDlgItem (IDC_RCVREMAIL)->EnableWindow (b);
	GetDlgItem (IDC__DESC)->EnableWindow (b);
	GetDlgItem (IDC_DESC)->EnableWindow (b);
	GetDlgItem (IDC__TAGS)->EnableWindow (b);
	GetDlgItem (IDC_TAGS)->EnableWindow (b);
}

BOOL CUpload_GeneralPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	SetDlgItemText (IDC_PKGNAME, m_upl->pMgr->get_PackageName ());

	vmsUploadPackageImpl *pkg = m_upl->pMgr->get_Package ();

	m_wndNumberOfDlds.AddString ("less than 10");
	m_wndNumberOfDlds.AddString ("from 10 to 100");
	m_wndNumberOfDlds.AddString ("more than 100");
	switch (pkg->m_nSupposedNumberOfDlds)
	{
	case 9: m_wndNumberOfDlds.SetCurSel (0); break;
	case 100: m_wndNumberOfDlds.SetCurSel (1); break;
	case 0: m_wndNumberOfDlds.SetCurSel (2); break;
	}

	m_wndDaysToKeep.AddString ("2 days");
	m_wndDaysToKeep.AddString ("7 days");
	m_wndDaysToKeep.AddString ("1 month");
	switch (pkg->m_nNumberOfDaysToKeepThisUpload)
	{
	case 2: m_wndDaysToKeep.SetCurSel (0); break;
	case 7: m_wndDaysToKeep.SetCurSel (1); break;
	case 31: m_wndDaysToKeep.SetCurSel (2); break;
	}

	m_wndCompress.AddString (LS (L_NONE));
	m_wndCompress.AddString (LS (L_FAST));
	m_wndCompress.AddString (LS (L_AVERAGE2));
	m_wndCompress.AddString (LS (L_BEST));
	m_wndCompress.SetItemData (0, 0);
	m_wndCompress.SetItemData (1, 2);
	m_wndCompress.SetItemData (2, 6);
	m_wndCompress.SetItemData (3, 9);
	size_t i = 0;
	for (i = 0; i < (size_t) m_wndCompress.GetCount (); i++)
	{
		if (m_wndCompress.GetItemData (i) == (DWORD)pkg->m_iZipCompressMethod)
			m_wndCompress.SetCurSel (i);
	}

	m_wndFiles.InsertColumn (0, "");
	for (i = 0; i < pkg->m_vPathes.size (); i++)
		m_wndFiles.InsertItem (i, pkg->m_vPathes [i]);
	m_wndFiles.SetColumnWidth (0, LVSCW_AUTOSIZE);

	if (pkg->m_strPassword.IsEmpty () == FALSE)
	{
		CheckDlgButton (IDC_SETPWD, BST_CHECKED);
		SetDlgItemText (IDC_PWD, pkg->m_strPassword);
	}

	if (pkg->m_bAddLinkToUploadInCatalogue)
		CheckDlgButton (IDC_PLACETOCAT, BST_CHECKED);

	BOOL bAdvInfo = FALSE;

	SetDlgItemText (IDC_DESC, pkg->m_strDescription);
	bAdvInfo = bAdvInfo || pkg->m_strDescription.IsEmpty () == FALSE;

	SetDlgItemText (IDC_TAGS, pkg->m_strTags);
	bAdvInfo = bAdvInfo || pkg->m_strTags.IsEmpty () == FALSE;

	SetDlgItemText (IDC_SNDRNAME, pkg->m_strOwnerName);
	bAdvInfo = bAdvInfo || pkg->m_strOwnerName.IsEmpty () == FALSE;

	SetDlgItemText (IDC_SNDREMAIL, pkg->m_strOwnerEmail);
	bAdvInfo = bAdvInfo || pkg->m_strOwnerEmail.IsEmpty () == FALSE;

	SetDlgItemText (IDC_RCVREMAIL, pkg->m_strRecipientEmail);
	bAdvInfo = bAdvInfo || pkg->m_strRecipientEmail.IsEmpty () == FALSE;

	if (bAdvInfo)
		CheckDlgButton (IDC_ADVANCEDINFO, BST_CHECKED);
	
	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CUpload_GeneralPage::OnSetpwd() 
{
	UpdateEnabled ();	
}

void CUpload_GeneralPage::OnAdvancedinfo() 
{
	UpdateEnabled ();	
}

void CUpload_GeneralPage::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__FILESTOUPLOAD, L_FILESTOUPLOAD, TRUE),
		fsDlgLngInfo (IDC__PKGNAME, L_PKGNAME, TRUE),
		fsDlgLngInfo (IDC__COMPRESS, L_COMPRESS, TRUE),
		fsDlgLngInfo (IDC_SETPWD, L_SETPWDFORTHISDLD),
		fsDlgLngInfo (IDC__PWD, L_PASSWORD),
		fsDlgLngInfo (IDC__PWD_R, L_RETYPE, TRUE),
		fsDlgLngInfo (IDC__KEEPTHESEFILES, L_KEEPTHESEFILES, TRUE),
		fsDlgLngInfo (IDC__SUPPOSEDNUMBEROFDLDS, L_SUPPOSEDNUMBEROFDLDS, TRUE),
		fsDlgLngInfo (IDC_PLACETOCAT, L_ADDLINKINOURCAT),
		fsDlgLngInfo (IDC_ADVANCEDINFO, L_INCADVINFO),
		fsDlgLngInfo (IDC__DESC, L_DESCRIPTION, TRUE),
		fsDlgLngInfo (IDC__TAGS, L_TAGS, TRUE),
		fsDlgLngInfo (IDC__SNDRNAME, L_YOURNAME, TRUE),
		fsDlgLngInfo (IDC__SNDREMAIL, L_YOUREMAIL, TRUE),
		fsDlgLngInfo (IDC__RCVREMAIL, L_RCVREMAIL, TRUE),
	};

	vmsMfcLngHelper::ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}
