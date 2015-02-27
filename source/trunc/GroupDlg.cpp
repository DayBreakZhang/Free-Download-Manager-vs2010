/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "GroupDlg.h"
#include "DownloadsWnd.h"
#include "FolderBrowser.h"
#include "system.h"
#include "CreateDownloadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ID_FOLDER_MACROS_0		20000

CGroupDlg::CGroupDlg(vmsDownloadsGroupSmartPtr pGroup, vmsDownloadsGroupSmartPtr pParentGroup, CWnd* pParent )
	: CDialog(CGroupDlg::IDD, pParent), m_pGroup (pGroup), m_pParentGroup (pParentGroup)
{
	//{{AFX_DATA_INIT(CGroupDlg)
	//}}AFX_DATA_INIT
	m_wndGroups.m_bHasAllGroupsItem = true;
}

void CGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGroupDlg)
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGroupDlg, CDialog)
	//{{AFX_MSG_MAP(CGroupDlg)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_EN_CHANGE(IDC_GRPNAME, OnChangeGrpname)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_MACROSES, OnMacroses)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_CBN_SELCHANGE(IDC_GRPFOLDER, OnSelchangeGrpfolder)
	ON_CBN_EDITCHANGE(IDC_GRPFOLDER, OnEditchangeGrpfolder)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_FOLDER_MACROS_0, ID_FOLDER_MACROS_0 + 50, OnInsertMacros)
END_MESSAGE_MAP()

BOOL CGroupDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));

	m_wndGroups.Fill ();
	
	if (m_pGroup)
	{
		PDLDS_GROUPS_TREE p = _DldsGrps.FindGroupInTree (m_pGroup)->GetRoot ();
		if (p == _DldsGrps.GetGroupsTree ())
			m_pParentGroup = NULL;
		else
			m_pParentGroup = p->GetData ();
		m_wndGroups.EnableWindow (FALSE);
	}

	m_wndGroups.SelectGroup (m_pParentGroup);

	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_GRPFOLDER);
	for (int i = 0; i < _LastFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFolders.GetRecord (i));

	
	if (m_pGroup == NULL)
	{
		m_strBaseFolder = m_pParentGroup == NULL ? 
			_DldsGrps.GetGroupsRootOutFolder () : m_pParentGroup->strOutFolder;
		SetDlgItemText (IDC_GRPFOLDER, m_strBaseFolder);
		m_bPathChanged = FALSE;
	}
	else
	{	
		m_bPathChanged = TRUE;

		if (m_pGroup->strName.GetLength () < m_pGroup->strOutFolder.GetLength ())
		{
			if (lstrcmp (m_pGroup->strOutFolder + m_pGroup->strOutFolder.GetLength () - 
					m_pGroup->strName.GetLength (), m_pGroup->strName) == 0)
			{
				m_strBaseFolder = m_pGroup->strOutFolder;
				m_strBaseFolder.Delete (m_pGroup->strOutFolder.GetLength () - 
					m_pGroup->strName.GetLength (), m_pGroup->strName.GetLength ());
				m_bPathChanged = FALSE;
			}
		}

		SetDlgItemText (IDC_GRPFOLDER, m_pGroup->strOutFolder);
		SetDlgItemText (IDC_GRPEXTS, m_pGroup->strExts);

		if (m_pGroup->nId == GRP_OTHER_ID)
		{
			
			((CEdit*) GetDlgItem (IDC_GRPNAME))->SetReadOnly ();
			GetDlgItem (IDC_GRPFOLDER)->SetFocus ();
			SetDlgItemText (IDC_GRPNAME, LS (L_OTHER));
		}
		else
		{
			SetDlgItemText (IDC_GRPNAME, m_pGroup->strName);
			GetDlgItem (IDC_GRPNAME)->SetFocus ();
		}
	}

	SetWindowText (m_pGroup == NULL ? LS (L_CREATEGRP) : LS (L_GRPPROP));

	ApplyLanguage ();
	
	return FALSE;  
	              
}

void CGroupDlg::OnOK() 
{
	CString strName, strFolder, strExts;
	GetDlgItemText (IDC_GRPNAME, strName);
	GetDlgItemText (IDC_GRPFOLDER, strFolder);
	GetDlgItemText (IDC_GRPEXTS, strExts);
	if (strName.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERGRPNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_GRPNAME)->SetFocus ();
		return;
	}

	if (-1 != strName.FindOneOf ("/\\"))
	{
		MessageBox (LS (L_INVALIDGROUPNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_GRPNAME)->SetFocus ();
		return;
	}

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_GRPFOLDER))
		return;

	if (strFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_GRPFOLDER)->SetFocus ();
		return;
	}

	bool bNewGroup = m_pGroup == NULL;

	if (bNewGroup)
	{
		m_pGroup.CreateInstance ();
		m_pParentGroup = m_wndGroups.GetSelectedGroup ();
		_DldsGrps.Add (m_pGroup, m_pParentGroup);
	}

	m_pGroup->strName = strName;
	m_pGroup->strOutFolder = strFolder;
	m_pGroup->strExts = strExts;

	if (m_pGroup->strOutFolder [m_pGroup->strOutFolder.GetLength () - 1] != '\\' &&
			m_pGroup->strOutFolder [m_pGroup->strOutFolder.GetLength () - 1] != '/')
	{
		m_pGroup->strOutFolder += '\\';
	}

	fsPathToGoodPath (m_pGroup->strOutFolder);

	_LastFolders.AddRecord (m_pGroup->strOutFolder);

	if (bNewGroup)
		_pwndDownloads->OnNewGroupCreated (m_pGroup);
	else
		_pwndDownloads->OnGroupNameChanged (m_pGroup);

	m_pGroup->setDirty();
	
	
	
	_DldsGrps.SaveToDisk ();
	
	CDialog::OnOK();
}

void CGroupDlg::OnChoosefolder() 
{
	CString str = "";
	GetDlgItemText (IDC_GRPFOLDER, str);

	if (str.GetLength () > 3 && (str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
		str.GetBuffer (0) [str.GetLength () - 1] = 0;

	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEGRPFLDR), str, NULL, this);
	if (fb == NULL)
		return;

	SetDlgItemText (IDC_GRPFOLDER, fb->GetPath ());	
	m_bPathChanged = TRUE;
}

void CGroupDlg::OnChangeGrpname() 
{
	if (m_bPathChanged)
		return;

	CString strName;
	GetDlgItemText (IDC_GRPNAME, strName);
	
	SetDlgItemText (IDC_GRPFOLDER, m_strBaseFolder + strName);
}

void CGroupDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CGroupDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CGroupDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__GROUP, L_GRPNAME),
		fsDlgLngInfo (IDC__PARENTGROUP, L_PARENT_GROUP, TRUE),
		fsDlgLngInfo (IDC__FOLDER, L_GRPFOLDER),
		fsDlgLngInfo (IDC__EXTS, L_GRPEXTS),
		fsDlgLngInfo (IDC__DEFPRIOR, L_GRPDEFPRIOR),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC_MACROSES, L_MACROSES),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), 0);
}

BOOL CGroupDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CGroupDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__GROUP, LS (L_ENTERGRPNAMEHERE)),
		fsCtrlContextHelp (IDC_GRPNAME, LS (L_ENTERGRPNAMEHERE)),
		fsCtrlContextHelp (IDC__FOLDER, LS (L_FOLDERINWHICH)),
		fsCtrlContextHelp (IDC_GRPFOLDER, LS (L_FOLDERINWHICH)),
		fsCtrlContextHelp (IDC_CHOOSEFOLDER, LS (L_BROWSEFOR)),
		fsCtrlContextHelp (IDC__EXTS, LS (L_GRPFILESEXTS)),
		fsCtrlContextHelp (IDC_GRPEXTS, LS (L_GRPFILESEXTS)),
		fsCtrlContextHelp (IDOK, LS (L_ACCEPTCHANGES)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTACCEPTCHANGES)),
	};

     static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CGroupDlg::OnMacroses() 
{
	CMenu menu;
	menu.CreatePopupMenu ();

	CString str;
	str.Format ("%%server%%  - %s", LS (L_SERVER_MACROS_DESC));
	menu.InsertMenu (0, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0, str);

	str.Format ("%%path_on_server%%  - %s", LS (L_PATHONSERVER_MACROS_DESC));
	menu.InsertMenu (1, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 1, str);

	str.Format ("%%year%%  - %s", LS (L_YEAR_MACROS_DESC));
	menu.InsertMenu (2, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 2, str);

	str.Format ("%%month%%  - %s", LS (L_MONTH_MACROS_DESC));
	menu.InsertMenu (3, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 3, str);

	str.Format ("%%day%%  - %s", LS (L_DAY_MACROS_DESC));
	menu.InsertMenu (4, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 4, str);

	str.Format ("%%date%%  - %s", LS (L_DATE_MACROS_DESC));
	menu.InsertMenu (5, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 5, str);

	str.Format ("%%sdrive%% - %s", LS (L_STARTDRIVELETTER));
	menu.InsertMenu (6, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 6, str);

	str.Format ("%%userprofile%% - %s", LS (L_PATHTOPROFILE));
	menu.InsertMenu (7, MF_BYPOSITION | MF_STRING, ID_FOLDER_MACROS_0 + 7, str);

	CPoint pt;
	GetCursorPos (&pt);
	menu.TrackPopupMenu (TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_RIGHTALIGN, pt.x, pt.y, this);
}

void CGroupDlg::OnInsertMacros(UINT nIDMacrosCmd)
{
	LPCSTR ppsz [] = {
		"%server%", "%path_on_server%", "%year%", "%month%",
		"%day%", "%date%", "%sdrive%", "%userprofile%"
	};

	LPCSTR pszMacros = ppsz [nIDMacrosCmd - ID_FOLDER_MACROS_0];

	CString str;
	GetDlgItemText (IDC_GRPFOLDER, str);

	if (str.IsEmpty () == FALSE && str [str.GetLength () - 1] != '\\')
		str += '\\';

	str += pszMacros;

	str += '\\';

	SetDlgItemText (IDC_GRPFOLDER, str);
}

void CGroupDlg::OnSelchangeGroups() 
{
	vmsDownloadsGroupSmartPtr pGroup = m_wndGroups.GetSelectedGroup ();
	if (pGroup == NULL)
		pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
	m_strBaseFolder = pGroup->strOutFolder;
	CString str;
	GetDlgItemText (IDC_GRPNAME, str);
	SetDlgItemText (IDC_GRPFOLDER, m_strBaseFolder + str);
	m_bPathChanged = FALSE;
}

void CGroupDlg::OnSelchangeGrpfolder() 
{
	m_bPathChanged = TRUE;	
}

void CGroupDlg::OnEditchangeGrpfolder() 
{
	m_bPathChanged = TRUE;	
}
