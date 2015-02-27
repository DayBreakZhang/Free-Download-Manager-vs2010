/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "BtDld_General.h"
#include "FolderBrowser.h"
#include "QueryStoringServiceInfoGuard.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CBtDld_General, CPropertyPage)

CBtDld_General::CBtDld_General() : CPropertyPage(CBtDld_General::IDD)
{
	//{{AFX_DATA_INIT(CBtDld_General)
		
	//}}AFX_DATA_INIT
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
	m_bNeedUpdateTasks = FALSE;
	m_bCommentModified = FALSE;
}

CBtDld_General::~CBtDld_General()
{
}

void CBtDld_General::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBtDld_General)
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBtDld_General, CPropertyPage)
	//{{AFX_MSG_MAP(CBtDld_General)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_EN_CHANGE(IDC_COMMENT, OnChangeComment)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CBtDld_General::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	
	if (m_pvDlds->size () == 1)
	{
		SetDlgItemText (IDC_URL, m_pvDlds->at (0)->pMgr->GetBtDownloadMgr ()->get_TorrentUrl ());
	}
	else
	{
		GetDlgItem (IDC_URL)->EnableWindow (FALSE);
		GetDlgItem (IDC__GENERAL)->EnableWindow (FALSE);
		GetDlgItem (IDC__TORRENTURL)->EnableWindow (FALSE);
	}

	m_wndGroups.Fill ();

	vmsDownloadSmartPtr dld0 = m_pvDlds->at (0);

	size_t i = 1;
	for (i = 1; i < m_pvDlds->size (); i++)
	{
		if (dld0->pGroup->nId != m_pvDlds->at (i)->pGroup->nId)
			break;
	}

	if (i == m_pvDlds->size ())	
		m_wndGroups.SelectGroup (dld0->pGroup);
	else
		m_wndGroups.SelectGroup (NULL);

	for (i = 1; i < m_pvDlds->size (); i++)
	{
		if (dld0->strComment != m_pvDlds->at (i)->strComment)
			break;
	}

	if (i == m_pvDlds->size ())
		SetDlgItemText (IDC_COMMENT, dld0->strComment);

	fsString strUser0, strPwd0;
	dld0->pMgr->GetBtDownloadMgr ()->get_TrackerLogin (strUser0, strPwd0);
	for (i = 1; i < m_pvDlds->size (); i++)
	{
		fsString strU, strP;
		m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->get_TrackerLogin (strU, strP);
		if (strUser0 != strU || strPwd0 != strP)
			break;
	}
	if (i == m_pvDlds->size ())
	{
		CheckDlgButton (IDC_USELOGIN, strUser0.IsEmpty () ? BST_UNCHECKED : BST_CHECKED);
		SetDlgItemText (IDC_USER, strUser0);
		SetDlgItemText (IDC_PASSWORD, strPwd0);
	}
	else
	{
		CheckDlgButton (IDC_USELOGIN, BST_INDETERMINATE);
	}

	ReadSavedIn ();

	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CBtDld_General::UpdateEnabled()
{
	BOOL bE = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;

	GetDlgItem (IDC_USER)->EnableWindow (bE);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (bE);
	GetDlgItem (IDC__USER)->EnableWindow (bE);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (bE);
}

void CBtDld_General::OnUselogin() 
{
	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_INDETERMINATE)
		CheckDlgButton (IDC_USELOGIN, BST_UNCHECKED);

	UpdateEnabled ();	
}

BOOL CBtDld_General::OnApply() 
{
	vmsDownloadsGroupSmartPtr pGroup = m_wndGroups.GetSelectedGroup ();
	if (pGroup != NULL)
	{
		for (size_t i = 0; i < m_pvDlds->size (); i++)
		{
			if (m_pvDlds->at (i)->pGroup->nId != pGroup->nId)
			{
				m_pvDlds->at (i)->pGroup->cDownloads--;
				m_pvDlds->at (i)->pGroup = pGroup;
				pGroup->cDownloads++;
				m_pvDlds->at (i)->pMgr->MoveToFolder (pGroup->strOutFolder);
				
				m_pvDlds->at (i)->setDirty();
			}
		}

		m_bNeedUpdateTasks = TRUE;
		_pwndDownloads->UpdateNumbersOfDownloadsInGroups ();
	}
	else
		m_bNeedUpdateTasks = FALSE;

	if (m_bCommentModified)
	{
		CString strComment;
		GetDlgItemText (IDC_COMMENT, strComment);

		for (size_t i = 0; i < m_pvDlds->size (); i++)
		{
			m_pvDlds->at (i)->strComment = strComment;
			
			m_pvDlds->at (i)->setDirty();
			_pwndDownloads->UpdateDownload (m_pvDlds->at (i));
		}

		m_bNeedUpdateTasks = TRUE;
	}

	UINT u = IsDlgButtonChecked (IDC_USELOGIN);
	if (u != BST_INDETERMINATE)
	{
		CString strU, strP;
		if (u == BST_CHECKED)
		{
			GetDlgItemText (IDC_USER, strU);
			GetDlgItemText (IDC_PASSWORD, strP);
		}
		for (size_t i = 0; i < m_pvDlds->size (); i++) {
			m_pvDlds->at (i)->pMgr->GetBtDownloadMgr ()->set_TrackerLogin (strU, strP);
		}
	}
	
	return CPropertyPage::OnApply();
}

void CBtDld_General::OnChangeComment() 
{
	m_bCommentModified = TRUE;
}

void CBtDld_General::OnChoosefolder() 
{
	CString str = "";
	GetDlgItemText (IDC_SAVEIN, str);

	if ((GetFileAttributes (str) & FILE_ATTRIBUTE_DIRECTORY) == 0)
	{
		char sz [MY_MAX_PATH];
		fsGetPath (str, sz);
		str = sz;
	}

	if (str.GetLength () > 3 && 
			(str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
	{
		str.GetBuffer (0) [str.GetLength () - 1] = 0;
		str.ReleaseBuffer ();
	}
	
	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), str, NULL, this);
	if (fb == NULL)
		return;

	for (size_t i = 0; i < m_pvDlds->size (); i++)
		m_pvDlds->at (i)->pMgr->MoveToFolder (fb->GetPath ());

	ReadSavedIn ();
}

void CBtDld_General::ReadSavedIn()
{
	vmsDownloadSmartPtr dld0 = m_pvDlds->at (0);

	CString str0 = dld0->pMgr->get_OutputFilePathName ();

	size_t i = 1;
	for (i = 1; i < m_pvDlds->size (); i++)
	{
		if (str0 != m_pvDlds->at (i)->pMgr->get_OutputFilePathName ())
			break;
	}

	if (i == m_pvDlds->size ())	
		SetDlgItemText (IDC_SAVEIN, str0);
}

void CBtDld_General::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TORRENTURL, L_TORRENTFILEURL, TRUE),
		fsDlgLngInfo (IDC__GENERAL, L_GENERALINFO),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_USELOGIN, L_LOGINREQ),
		fsDlgLngInfo (IDC__SAVEDIN, L_SAVEDAS),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDC__COMMENT, L_COMMENT, TRUE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}
