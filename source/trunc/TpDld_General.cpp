/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "TpDld_General.h"
#include "FolderBrowser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CTpDld_General, CPropertyPage)

CTpDld_General::CTpDld_General() : CPropertyPage(CTpDld_General::IDD)
{
	//{{AFX_DATA_INIT(CTpDld_General)
		
	//}}AFX_DATA_INIT
	m_psp.dwFlags |= PSP_USETITLE;
	m_psp.pszTitle = LS (L_GENERAL);
	m_bNeedUpdateTasks = FALSE;
	m_bCommentModified = FALSE;
}

CTpDld_General::~CTpDld_General()
{
}

void CTpDld_General::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTpDld_General)
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTpDld_General, CPropertyPage)
	//{{AFX_MSG_MAP(CTpDld_General)
	
	
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CTpDld_General::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	
	if (m_pvDlds->size () == 1)
	{
		SetDlgItemText (IDC_URL, m_pvDlds->at (0)->pMgr->GetTpDownloadMgr ()->get_URL ());
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

	for (i = 1; i < m_pvDlds->size (); i++)
	{
		
			
	}

	
		

	fsString strUser0, strPwd0;
	

	ReadSavedIn ();

	UpdateEnabled ();

	ApplyLanguage ();
	
	return TRUE;  
	              
}

void CTpDld_General::UpdateEnabled()
{
	

	
}

BOOL CTpDld_General::OnApply() 
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
				m_pvDlds->at (i)->setDirty();
				pGroup->cDownloads++;
				m_pvDlds->at (i)->pMgr->MoveToFolder (pGroup->strOutFolder);
			}
		}

		m_bNeedUpdateTasks = TRUE;
		_pwndDownloads->UpdateNumbersOfDownloadsInGroups ();
	}
	else
		m_bNeedUpdateTasks = FALSE;

	

	
	
	return CPropertyPage::OnApply();
}

void CTpDld_General::OnChoosefolder() 
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

void CTpDld_General::ReadSavedIn()
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

void CTpDld_General::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__TORRENTURL, L_TORRENTFILEURL, TRUE),
		fsDlgLngInfo (IDC__GENERAL, L_GENERALINFO),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC_USELOGIN, L_LOGINREQ),
		fsDlgLngInfo (IDC__SAVEDIN, L_SAVEDAS),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}
