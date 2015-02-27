/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CreateDownloadFromTorrentFileDlg.h"
#include "FolderBrowser.h"
#include "CreateDownloadDlg.h"
#include "ScheduleSheet.h"
#include "BtDldSheet.h"
#include "mfchelp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CCreateDownloadFromTorrentFileDlg::CCreateDownloadFromTorrentFileDlg(CWnd* pParent )
	: CDialog(CCreateDownloadFromTorrentFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateDownloadFromTorrentFileDlg)
	m_ptszTorrentFile = NULL;
	//}}AFX_DATA_INIT

	m_bScheduled = FALSE;
	m_bPlaceToTop = FALSE;
}

void CCreateDownloadFromTorrentFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDownloadFromTorrentFileDlg)
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_SETTIME, m_btnSetTime);
	DDX_Control(pDX, IDC_OUTFOLDER_SETDEFAULT, m_btnSetDefaultFolder);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateDownloadFromTorrentFileDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateDownloadFromTorrentFileDlg)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_OUTFOLDER_SETDEFAULT, OnOutfolderSetdefault)
	ON_BN_CLICKED(IDC_SETTIME, OnSettime)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CCreateDownloadFromTorrentFileDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	ASSERT (m_ptszTorrentFile);
	if (m_ptszTorrentFile)
		SetDlgItemText (IDC_TORRENTFILE, m_ptszTorrentFile);
	
	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));
	m_btnSetTime.SetIcon (SICO (IDI_SETTIME));
	m_btnSetDefaultFolder.SetIcon (SICO (IDI_SETFOLDERDEFAULT));

	m_schScheduleParam.schTask.hts.enType = HTS_ONCE;
	m_schScheduleParam.schTask.hts.last.dwHighDateTime = m_schScheduleParam.schTask.hts.last.dwLowDateTime = UINT_MAX;
	m_schScheduleParam.schTask.dwFlags = SCHEDULE_ENABLED;
	SYSTEMTIME time;
	GetLocalTime (&time);
	if (++time.wHour > 23)
		time.wHour = 0;
	time.wMinute = 0;
	SystemTimeToFileTime (&time, &m_schScheduleParam.schTask.hts.next);
	m_schScheduleParam.schTask.uWaitForConfirmation = 0;

	m_wndGroups.Fill ();

	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_OUTFOLDER);
	for (int i = 0; i < _LastFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFolders.GetRecord (i));

	CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTNOW);

	ASSERT (m_dld->pGroup != NULL);
	m_wndGroups.SelectGroup (m_dld->pGroup);

	pDirs->SetWindowText (m_wndGroups.GetSelectedGroup ()->strOutFolder);

	UINT nAS = _App.Last_Autostart ();
	if (nAS == 0)
		nAS = IDC_STARTNOW;
	else
		nAS = nAS == 1 ? IDC_STARTMANUAL : IDC_STARTSCHEDULE;
	CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, nAS);

	SetDlgItemText (IDC_COMMENT, m_dld->strComment);

	ApplyLanguage ();

	UpdateEnabled ();

	mfcSetForegroundWindow (this);

	return TRUE;  
	              
}

void CCreateDownloadFromTorrentFileDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USELOGIN, L_TRACKERLOGINREQ),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC__SAVETO, L_SAVETO),
		fsDlgLngInfo (IDC__START, L_START),
		fsDlgLngInfo (IDC_STARTNOW, L_AUTOMATICALLY),
		fsDlgLngInfo (IDC_STARTMANUAL, L_MANUALLY),
		fsDlgLngInfo (IDC_STARTSCHEDULE, L_SCHEDULE),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC_PLACEATTOP, L_PLACEDLDATTOP),
		fsDlgLngInfo (IDC__COMMENT, L_COMMENT, TRUE),
		fsDlgLngInfo (IDC__FILE, L_TORRENTFILE, TRUE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATENEWTORRENTDLD);
}

void CCreateDownloadFromTorrentFileDlg::OnUselogin() 
{
	UpdateEnabled ();	
}

void CCreateDownloadFromTorrentFileDlg::UpdateEnabled()
{
	BOOL bE = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;

	GetDlgItem (IDC_USER)->EnableWindow (bE);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (bE);
	GetDlgItem (IDC__USER)->EnableWindow (bE);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (bE);
}

void CCreateDownloadFromTorrentFileDlg::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
	{
		GetDlgItem (IDC_OUTFOLDER)->SetWindowText (m_wndGroups.GetSelectedGroup ()->strOutFolder);
	}	
}

void CCreateDownloadFromTorrentFileDlg::OnChoosefolder() 
{
	CString str = "";
	GetDlgItemText (IDC_OUTFOLDER, str);

	if (str.GetLength () > 3 && (str [str.GetLength () - 1] == '\\' || str [str.GetLength () - 1] == '/'))
		str.GetBuffer (0) [str.GetLength () - 1] = 0;

	CFolderBrowser *fb = CFolderBrowser::Create (LS (L_CHOOSEOUTFOLDER), str, NULL, this);
	if (fb == NULL)
		return;

	SetDlgItemText (IDC_OUTFOLDER, fb->GetPath ());
	GetDlgItem (IDC_OUTFOLDER)->SetFocus ();	
}

void CCreateDownloadFromTorrentFileDlg::OnOutfolderSetdefault() 
{
	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	CCreateDownloadDlg::_SetDownloadOutputFolderAsDefault (this, strOutFolder, m_wndGroups.GetSelectedGroup ());	
}

void CCreateDownloadFromTorrentFileDlg::OnSettime() 
{
	CScheduleSheet sheet (LS (L_SCHEDULEDLDS), this);

	sheet.Init (&m_schScheduleParam.schTask, FALSE);
	
	if (IDOK == _DlgMgr.DoModal (&sheet))
	{
		CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
	}

	GetDlgItem (IDC_STARTSCHEDULE)->SetFocus ();	
}

void CCreateDownloadFromTorrentFileDlg::OnAdvanced() 
{
	CBtDldSheet sheet (LS (L_ADVANCED), this);
	DLDS_LIST v;
	v.push_back (m_dld);
	sheet.Init (&v, BTDS_FILES_PAGE | BTDS_MISC_PAGE);
	_DlgMgr.DoModal (&sheet);
}

void CCreateDownloadFromTorrentFileDlg::OnOK() 
{
	vmsBtDownloadManager *pMgr = m_dld->pMgr->GetBtDownloadMgr ();

	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED)
	{
		CString strUser, strPwd;
		GetDlgItemText (IDC_USER, strUser);
		GetDlgItemText (IDC_PASSWORD, strPwd);
		pMgr->set_TrackerLogin (strUser, strPwd);		
	}

	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);
	fsPathToGoodPath ((LPSTR)(LPCSTR)strOutFolder);

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_OUTFOLDER))
		return;

	if (strOutFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	_LastFolders.AddRecord (strOutFolder);

	if (strOutFolder [strOutFolder.GetLength () - 1] != '\\' && 
			strOutFolder [strOutFolder.GetLength () - 1] != '/')
		strOutFolder += '\\';

    if (_App.NewGrp_SelectWay () == NGSW_USE_ALWAYS_SAME_GROUP_WITH_OUTFOLDER_AUTO_UPDATE)
	{
		vmsDownloadsGroupSmartPtr pGrp = _DldsGrps.FindGroup (_App.NewDL_GroupId ());
		if (pGrp != NULL) {
			pGrp->strOutFolder = strOutFolder;
			pGrp->setDirty();
			
			
			
		}
	}

	pMgr->setOutputPath (strOutFolder);

	m_dld->pGroup = m_wndGroups.GetSelectedGroup ();
	
	GetDlgItemText (IDC_COMMENT, m_dld->strComment);
	
	m_bScheduled = IsDlgButtonChecked (IDC_STARTSCHEDULE) == BST_CHECKED;
	m_dld->bAutoStart = IsDlgButtonChecked (IDC_STARTNOW) == BST_CHECKED;

	m_bPlaceToTop = IsDlgButtonChecked (IDC_PLACEATTOP) == BST_CHECKED;

	m_wndGroups.RememberSelectedGroup ();
	if (m_dld->bAutoStart)
		_App.Last_Autostart (0);
	else
		_App.Last_Autostart (m_bScheduled ? 2 : 1);

	CDialog::OnOK();
}

void CCreateDownloadFromTorrentFileDlg::OnSelchangeGroups() 
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);
}