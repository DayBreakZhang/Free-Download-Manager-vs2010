/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "SpiderAddPageDlg.h"
#include "DownloadsWnd.h"
#include "CreateDownloadDlg.h"
#include "GroupDlg.h"
#include "FolderBrowser.h"
#include "ScheduleSheet.h"
#include "inetutil.h"
#include "fsSitesMgr.h"
#include "WPDS_Sheet.h"
#include "system.h"
#include "mfchelp.h"
#include "FdmUiWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd *_pwndDownloads;

CSpiderAddPageDlg::CSpiderAddPageDlg(CWnd* pParent )
	: CDialog(CSpiderAddPageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSpiderAddPageDlg)
		
	//}}AFX_DATA_INIT
	m_bAuthChanged = FALSE;
	m_pUiWindow = NULL;
}

void CSpiderAddPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSpiderAddPageDlg)
	DDX_Control(pDX, IDC_OUTFOLDER_SETDEFAULT, m_btnOutFolderSetDefault);
	DDX_Control(pDX, IDC_DEPTHSPIN, m_wndDepthSpin);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_SETTIME, m_btnSetTime);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSpiderAddPageDlg, CDialog)
	//{{AFX_MSG_MAP(CSpiderAddPageDlg)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_SETTIME, OnSettime)
	ON_BN_CLICKED(IDC_STARTNOW, OnStartnow)
	ON_BN_CLICKED(IDC_STARTMANUAL, OnStartmanual)
	ON_BN_CLICKED(IDC_STARTSCHEDULE, OnStartschedule)
	ON_CBN_EDITCHANGE(IDC_URL, OnEditchangeUrl)
	ON_CBN_SELCHANGE(IDC_URL, OnSelchangeUrl)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_WM_HELPINFO()
	ON_CBN_EDITCHANGE(IDC_OUTFOLDER, OnEditchangeOutfolder)
	ON_CBN_SELCHANGE(IDC_OUTFOLDER, OnSelchangeOutfolder)
	ON_BN_CLICKED(IDC_KEEP, OnKeep)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_BN_CLICKED(IDC_OUTFOLDER_SETDEFAULT, OnOutfolderSetdefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CSpiderAddPageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (m_pUiWindow)
		m_pUiWindow->setWindow (m_hWnd);

	
	
	
	
	
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

	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));
	m_btnSetTime.SetIcon (SICO (IDI_SETTIME));
	m_btnOutFolderSetDefault.SetIcon (SICO (IDI_SETFOLDERDEFAULT));

	m_wndGroups.Fill ();
	m_wndGroups.SelectGroupById (_App.CreateDld_IdOfLastGrpSelected ());

	CheckDlgButton (IDC_KEEP, _App.Spider_Flags () & WPDF_KEEPFOLDERSTRUCTURE ? 
						BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_DONTSTOREPAGES, _App.Spider_Flags () & WPDF_DONTSTOREPAGES ? 
						BST_CHECKED : BST_UNCHECKED);

	CheckDlgButton (IDC_DELCOMPLETED, _App.Spider_Flags () & WPDF_DELCOMPLETEDDLDS ?
						BST_CHECKED : BST_UNCHECKED);

	CComboBox *pUrls = (CComboBox*) GetDlgItem (IDC_URL);
	int i = 0;
	for (i = 0; i < _LastUrlFiles.GetRecordCount (); i++)
		pUrls->AddString (_LastUrlFiles.GetRecord (i));

	if (m_strStartUrl.GetLength () == 0)
	{
		LPCSTR pszUrl = _ClipbrdMgr.Text ();
		if (pszUrl)
		{
			fsURL url;
			if (url.Crack (pszUrl) == IR_SUCCESS)
				m_strUrl = pszUrl;
		}
		
		if (m_strUrl.GetLength () == 0)
			m_strUrl = "http://";
	}
	else
		m_strUrl = m_strStartUrl;

	pUrls->SetWindowText (m_strUrl);

	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_OUTFOLDER);
	for (i = 0; i < _LastFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFolders.GetRecord (i));

	GetDlgItem (IDC_URL)->SetFocus ();

	m_bOutFolderChanged = m_bGroupChanged = FALSE;

	ReadAutostart ();
	ApplyLanguage ();

	if (m_bReqTopMost)
	{
		fsSetForegroundWindow (m_hWnd);
        mfcSetTopmostWindow (this);
	}

	m_wndDepthSpin.SetRange (0, UD_MAXVAL);
	SetDlgItemInt (IDC_DEPTH, m_wpd->GetWDPS ()->iDepth);

	if (m_wndGroups.SelectGroupById (_App.NewDL_GroupId ()))
		m_bGroupChanged = TRUE;

	OnChangeGroups ();

	BuildOutFolder ();

	UpdateEnabled ();

	return TRUE;  
	              
}

void CSpiderAddPageDlg::OnChangeGroups()
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);

	m_strBaseFolder = m_wndGroups.GetSelectedGroup ()->strOutFolder;
	BuildOutFolder ();
}

void CSpiderAddPageDlg::OnSelchangeGroups() 
{
	m_bGroupChanged = TRUE;
	OnChangeGroups ();	
}

void CSpiderAddPageDlg::OnAdvanced() 
{
	CWPDS_Sheet sheet (LS (L_ADVANCED), this);

	sheet.Init (m_wpd->GetWDPS (), FALSE, NULL);

	
	m_wpd->GetWDPS ()->iDepth = GetDlgItemInt (IDC_DEPTH);
	m_wpd->setDirty();

	_DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
	_DlgMgr.OnEndDialog (&sheet);

	SetDlgItemInt (IDC_DEPTH, m_wpd->GetWDPS ()->iDepth);
}

void CSpiderAddPageDlg::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
		OnChangeGroups ();
}

void CSpiderAddPageDlg::OnChoosefolder() 
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

void CSpiderAddPageDlg::OnSettime() 
{
	CScheduleSheet sheet (LS (L_SCHEDULEDLDS), this);

	sheet.Init (&m_schScheduleParam.schTask, FALSE);
	
	_DlgMgr.OnDoModal (&sheet);

	if (IDOK == sheet.DoModal ())
	{
		CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
		m_bScheduled = TRUE;
		m_bAutoStart = FALSE;	
		m_iAutostart = 2;
	}

    _DlgMgr.OnEndDialog (&sheet);
	GetDlgItem (IDC_STARTSCHEDULE)->SetFocus ();
}

void CSpiderAddPageDlg::OnStartnow() 
{
	m_bAutoStart = TRUE;
	m_bScheduled = FALSE;	
	m_iAutostart = 0;
}

void CSpiderAddPageDlg::OnStartmanual() 
{
	m_bScheduled = FALSE;
	m_bAutoStart = FALSE;	
	m_iAutostart = 1;
}

void CSpiderAddPageDlg::OnStartschedule() 
{
	m_bScheduled = TRUE;
	m_bAutoStart = FALSE;	
	m_iAutostart = 2;
}

void CSpiderAddPageDlg::OnUrlChanged()
{
	

	fsURL url;

	if (IR_SUCCESS != url.Crack (m_strUrl))
		return;

	CString strNewUser, strNewPassword;

	strNewUser = url.GetUserName ();
	strNewPassword = url.GetPassword ();

	fsSiteInfo *site = _SitesMgr.FindSite (url.GetHostName (), fsNPToSiteValidFor (fsSchemeToNP (url.GetInternetScheme ())));
	if (site)
	{
		if (!m_bAuthChanged && strNewUser.IsEmpty ())
		{
			if (!site->strUser.IsEmpty ())
			{
				strNewUser = site->strUser;
				if (!site->strPassword.IsEmpty ())
					strNewPassword = site->strPassword;
			}
		}

		if (site->pGroup && m_bGroupChanged == FALSE)
		{
			m_wndGroups.SelectGroup (site->pGroup);
			OnChangeGroups();
			m_bGroupChanged = FALSE;
		}
	}

	if (!m_bAuthChanged)
	{
		CheckDlgButton (IDC_USELOGIN, !strNewUser.IsEmpty () ? BST_CHECKED : BST_UNCHECKED);
		SetDlgItemText (IDC_USER, strNewUser);
		SetDlgItemText (IDC_PASSWORD, strNewPassword);
		m_bAuthChanged = FALSE;
		UpdateEnabled ();
	}

	BuildOutFolder ();
}

void CSpiderAddPageDlg::OnEditchangeUrl() 
{
	GetDlgItemText (IDC_URL, m_strUrl);
	OnUrlChanged ();	
}

void CSpiderAddPageDlg::OnSelchangeUrl() 
{
	CComboBox *pUrl = (CComboBox*) GetDlgItem (IDC_URL);
	pUrl->GetLBText (pUrl->GetCurSel (), m_strUrl);
	OnUrlChanged ();	
}

void CSpiderAddPageDlg::OnOK() 
{
	

	fsWPDSettings *wpds = m_wpd->GetWDPS ();

	GetDlgItemText (IDC_URL, m_strUrl);

	if (FALSE == WriteAuthorization ())
		return;

	BOOL bAddSlash;
	if (FALSE == IsOkUrl (m_strUrl, m_wpd->GetWDPS ()->strHTMLExts, &bAddSlash))
	{
		WrongURL ();
		return;
	}

	if (bAddSlash)
		m_strUrl += '/';

	CString strOutFolder;

	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_OUTFOLDER))
		return;

	fsPathToGoodPath ((LPSTR)(LPCSTR)strOutFolder);

	if (strOutFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	_LastFolders.AddRecord (strOutFolder);
	_LastUrlFiles.AddRecord (m_strUrl);

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

	wpds->pDLGroup = m_wndGroups.GetSelectedGroup ();

	wpds->strFolderSaveTo = strOutFolder;

	wpds->iDepth = GetDlgItemInt (IDC_DEPTH);

	wpds->dwFlags = 0;

	if (IsDlgButtonChecked (IDC_KEEP) == BST_CHECKED)
		wpds->dwFlags |= WPDF_KEEPFOLDERSTRUCTURE;

	if (IsDlgButtonChecked (IDC_DONTSTOREPAGES) == BST_CHECKED)
	{
		wpds->bDownloadStyles = FALSE;
		wpds->dwFlags |= WPDF_DONTSTOREPAGES;
	}

	if (IsDlgButtonChecked (IDC_DELCOMPLETED) == BST_CHECKED)
		wpds->dwFlags |= WPDF_DELCOMPLETEDDLDS;

	if (wpds->m_ppoOwner)
		wpds->m_ppoOwner->setDirty();

	_App.Spider_Flags (wpds->dwFlags);

	m_wndGroups.RememberSelectedGroup ();
	_App.Last_Autostart (m_iAutostart);

	if (wpds->strUserName.GetLength () != 0)
	{
		fsURL url;
		url.Crack (m_strUrl);
		fsSiteInfo* site = CCreateDownloadDlg::_SavePassword (url.GetHostName (), 
			fsSchemeToNP (url.GetInternetScheme ()), wpds->strUserName, wpds->strPassword);
		if (site) 
		{
			site->pGroup = wpds->pDLGroup;
			_SitesMgr.setDirty();
			_SitesMgr.SiteUpdated (site);
		}
	}

	_App.OnDlHasBeenCreatedByUser ();
	
	CDialog::OnOK();
}

void CSpiderAddPageDlg::WrongURL()
{
	MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
	GetDlgItem (IDC_URL)->SetFocus ();
}

void CSpiderAddPageDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__URL, L_WEBPAGEURL),
		fsDlgLngInfo (IDC_KEEP, L_KEEPFOLDERSTRUCTURE),
		fsDlgLngInfo (IDC_DONTSTOREPAGES, L_DONTSTOREPAGES),
		fsDlgLngInfo (IDC_DELCOMPLETED, L_SPIDER_DELCOMPLETED),
		fsDlgLngInfo (IDC__DEPTH, L_DLDEPTH),
		fsDlgLngInfo (IDC_USELOGIN, L_LOGINREQ),
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
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_DLWEBPAGE);
}

void CSpiderAddPageDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CSpiderAddPageDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();
}

void CSpiderAddPageDlg::ReadAutostart()
{
	m_iAutostart = _App.Last_Autostart ();

	switch (m_iAutostart)
	{
		case 0:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTNOW);
			m_bAutoStart = TRUE;  
			m_bScheduled = FALSE;
			break;

		case 1:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTMANUAL);
			m_bAutoStart = FALSE; 
			m_bScheduled = FALSE;
			break;

		case 2:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
			m_bAutoStart = FALSE;
			m_bScheduled = TRUE;
			break;
	}
}

BOOL CSpiderAddPageDlg::IsOkUrl(LPCSTR pszUrl, LPCSTR , BOOL *pbMustAddSlash)
{
	if (pbMustAddSlash)
		*pbMustAddSlash = FALSE;

	fsURL url;
	if (IR_SUCCESS != url.Crack (pszUrl) || *url.GetHostName () == 0)
		return FALSE;

	if (url.GetInternetScheme () != INTERNET_SCHEME_HTTP && url.GetInternetScheme () != INTERNET_SCHEME_HTTPS)
		return FALSE;

	if (*url.GetHostName () == 0)
		return FALSE;

	

	return TRUE;
}

void CSpiderAddPageDlg::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;
	GetDlgItem (IDC__USER)->EnableWindow (b);
	GetDlgItem (IDC_USER)->EnableWindow (b);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (b);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (b);
}

void CSpiderAddPageDlg::OnUselogin() 
{
	UpdateEnabled ();
	m_bAuthChanged = TRUE;
}

BOOL CSpiderAddPageDlg::WriteAuthorization()
{
	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED)
	{
		CString str;
		GetDlgItemText (IDC_USER, str);
		if (str == "")
		{
			MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
			CEdit *pE = (CEdit*) GetDlgItem (IDC_USER);
			pE->SetFocus ();
			pE->SetSel (0, -1);
			return FALSE;
		}

		m_wpd->GetWDPS ()->strUserName = str;

		GetDlgItemText (IDC_PASSWORD, str);
		m_wpd->GetWDPS ()->strPassword = str;
		m_wpd->setDirty();
	}

	return TRUE;

}

void CSpiderAddPageDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__URL, LS (L_WEBPAGEURLHERE)),
		fsCtrlContextHelp (IDC_URL, LS (L_WEBPAGEURLHERE)),
		fsCtrlContextHelp (IDC_KEEP, LS (L_KEEPFOLDERHERE)),
		fsCtrlContextHelp (IDC_DONTSTOREPAGES, LS (L_DONTSTOREPAGESHERE)),
		fsCtrlContextHelp (IDC_DELCOMPLETED, LS (L_SPIDER_DELCOMPLETEDHERE)),
		fsCtrlContextHelp (IDC__DEPTH, LS (L_DLDEPTHHERE)),
		fsCtrlContextHelp (IDC_DEPTH, LS (L_DLDEPTHHERE)),
		fsCtrlContextHelp (IDC_USELOGIN,LS (L_LOGINHERE)),
		fsCtrlContextHelp (IDC__USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC_USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC__PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC__GROUP, LS (L_GROUPHERE)),
        fsCtrlContextHelp (IDC_GROUPS, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC_CREATEGROUP, LS (L_CREATEGRP)),
		fsCtrlContextHelp (IDC__SAVETO, LS (L_DLDFOLDERHERE)),
		fsCtrlContextHelp (IDC_OUTFOLDER, LS (L_DLDFOLDERHERE)),
		fsCtrlContextHelp (IDC_CHOOSEFOLDER, LS (L_BROWSEFOR)),
		fsCtrlContextHelp (IDC_STARTNOW, LS (L_STARTNOWHERE)),
		fsCtrlContextHelp (IDC_STARTMANUAL, LS (L_MANUALLYSTARTHERE)),
		fsCtrlContextHelp (IDC_STARTSCHEDULE, LS (L_SCHEDULESTARTHERE)),
		fsCtrlContextHelp (IDC_SETTIME, LS (L_SETTIMEHERE)),
		fsCtrlContextHelp (IDC_ADVANCED, LS (L_ADVANCEDHERE)),
		fsCtrlContextHelp (IDOK, LS (L_ACCEPTCHANGES)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTACCEPTCHANGES)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

BOOL CSpiderAddPageDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CSpiderAddPageDlg::OnEditchangeOutfolder() 
{
	m_bOutFolderChanged = TRUE;	
}

void CSpiderAddPageDlg::OnSelchangeOutfolder() 
{
	m_bOutFolderChanged = TRUE;	
}

void CSpiderAddPageDlg::BuildOutFolder()
{
	CHAR szFile [10000];
        *szFile = 0;
	fsURL url;

	
	if (m_bOutFolderChanged)
		return;

	if (IR_SUCCESS != url.Crack (m_strUrl))
		return;

	if (*url.GetHostName () == 0)
		return;

	if (IsDlgButtonChecked (IDC_KEEP) == BST_CHECKED)
	{
		SetDlgItemText (IDC_OUTFOLDER, m_strBaseFolder);
		return;
	}
	
	fsFileNameFromUrlPath (url.GetPath (), url.GetInternetScheme () == INTERNET_SCHEME_FTP,
		TRUE, szFile, sizeof (szFile));

	CString str = m_strBaseFolder;
	str += url.GetHostName ();
	str += '\\';
	
	SetDlgItemText (IDC_OUTFOLDER, str);
}

void CSpiderAddPageDlg::OnKeep() 
{
	BuildOutFolder ();	
}

void CSpiderAddPageDlg::OnChangeUser() 
{
	m_bAuthChanged = TRUE;	
}

void CSpiderAddPageDlg::OnChangePassword() 
{
	m_bAuthChanged = TRUE;
}

void CSpiderAddPageDlg::OnOutfolderSetdefault() 
{
	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	CCreateDownloadDlg::_SetDownloadOutputFolderAsDefault (this, strOutFolder,
		m_wndGroups.GetSelectedGroup ());
}
