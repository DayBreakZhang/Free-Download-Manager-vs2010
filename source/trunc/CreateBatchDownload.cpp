/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CreateBatchDownload.h"
#include "DownloadsWnd.h"
#include "inetutil.h"
#include "GroupDlg.h"
#include "FolderBrowser.h"
#include "ScheduleSheet.h"
#include "DownloadPropertiesSheet.h"
#include "CBD_SeeResultsDlg.h"
#include "WaitDlg.h"
#include "CreateDownloadDlg.h"
#include "Dlg_SetBatchNumbers.h"
#include "vmsDownloadsGroupsMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd *_pwndDownloads;

CCreateBatchDownload::CCreateBatchDownload(CWnd* pParent )
	: CDialog(CCreateBatchDownload::IDD, pParent)
{
	Download_CreateInstance (m_dld);
	m_iAlphaFrom = 0;
	m_iAlphaTo = 25;
	m_bBLParametersChanged = true;
	m_pvDownloads = NULL;
}

void CCreateBatchDownload::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateBatchDownload)
	DDX_Control(pDX, IDC_OUTFOLDER_SETDEFAULT, m_btnOutFolderSetDefault);
	DDX_Control(pDX, IDC_Z, m_wndZ);
	DDX_Control(pDX, IDC_A, m_wndA);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_SETTIME, m_btnSetTime);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateBatchDownload, CDialog)
	//{{AFX_MSG_MAP(CCreateBatchDownload)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_CBN_EDITCHANGE(IDC_URL, OnEditchangeUrl)
	ON_CBN_SELCHANGE(IDC_URL, OnSelchangeUrl)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_BN_CLICKED(IDC_STARTNOW, OnStartnow)
	ON_BN_CLICKED(IDC_STARTMANUAL, OnStartmanual)
	ON_BN_CLICKED(IDC_STARTSCHEDULE, OnStartschedule)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_SETTIME, OnSettime)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_BN_CLICKED(IDC_RESULTS, OnResults)
	ON_BN_CLICKED(IDC_QUERYSIZE, OnQuerysize)
	ON_CBN_SELCHANGE(IDC_A, OnSelchangeA)
	ON_CBN_SELCHANGE(IDC_Z, OnSelchangeZ)
	ON_EN_CHANGE(IDC_NUMBERS, OnChangeNumbers)
	ON_BN_CLICKED(IDC_SETNUMBERS, OnSetnumbers)
	ON_BN_CLICKED(IDC_FILEAUTO, OnFileauto)
	ON_BN_CLICKED(IDC_OUTFOLDER_SETDEFAULT, OnOutfolderSetdefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CCreateBatchDownload::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));
	m_btnSetTime.SetIcon (SICO (IDI_SETTIME));
	m_btnOutFolderSetDefault.SetIcon (SICO (IDI_SETFOLDERDEFAULT));

	
	m_schScheduleParam.schTask.hts.enType = HTS_ONCE;
	m_schScheduleParam.schTask.hts.last.dwHighDateTime = m_schScheduleParam.schTask.hts.last.dwLowDateTime = UINT_MAX;
	SYSTEMTIME time;
	GetLocalTime (&time);
	if (++time.wHour > 23)
		time.wHour = 0;
	time.wMinute = 0;
	SystemTimeToFileTime (&time, &m_schScheduleParam.schTask.hts.next);
	m_schScheduleParam.schTask.uWaitForConfirmation = 0;

	
	LPCSTR pszUrl = _ClipbrdMgr.Text ();
	if (pszUrl && *pszUrl)
	{
		fsURL url;
		if (url.Crack (pszUrl) == IR_SUCCESS)
			m_strUrl = pszUrl;	
	}
	
	if (m_strUrl == "")
		m_strUrl = "http://";	

	CString strUser = _App.UserName ();	
	m_bAuthorization = strUser.GetLength () != 0;
	SetDlgItemText (IDC_USER, strUser);
	SetDlgItemText (IDC_PASSWORD, _App.UserPassword ());

	CheckDlgButton (IDC_USELOGIN, m_bAuthorization ? BST_CHECKED : BST_UNCHECKED);

	
	m_wndGroups.Fill ();

	
	CComboBox *pUrls = (CComboBox*) GetDlgItem (IDC_URL);
	int i = 0;
	for (i = 0; i < _LastBatchUrls.GetRecordCount (); i++)
		pUrls->AddString (_LastBatchUrls.GetRecord (i));

	
	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_OUTFOLDER);
	for (i = 0; i < _LastFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFolders.GetRecord (i));

	CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTNOW);
	m_dld->bAutoStart = TRUE;  

	GetDlgItem (IDC_URL)->SetFocus ();

	if (IR_SUCCESS != m_dld->pMgr->GetDownloadMgr ()->CreateByUrl (m_strUrl, TRUE) && m_strUrl != "http://")
		m_dld->pMgr->GetDownloadMgr ()->CreateByUrl ("http://", TRUE);

	m_bGroupChanged = m_bAuthChanged = FALSE;

	fsURL url;
	if (IR_SUCCESS == url.Crack (m_strUrl) && *url.GetHostName ())
	{
		fsURL u;
		char szUrl [10000];
		DWORD dwLen = 10000;
		u.Create (url.GetInternetScheme (), url.GetHostName (), url.GetPort (), NULL, NULL, url.GetPath (), szUrl, &dwLen);
		m_strUrl = szUrl;	

		if (*url.GetUserName ())
			m_bAuthChanged = TRUE;
	}

	UpdateEnabled ();

	
	Update_User_Password ();

	SetDlgItemText (IDC_URL, m_strUrl == "http://url/" ? "http://" : m_strUrl);
	((CEdit*) GetDlgItem (IDC_URL))->SetSel (0, -1);

	UrlChanged ();

	DWORD dwAtoZ = _App.CreateBD_LastAtoZ ();
	int az1 = LOWORD (dwAtoZ);
	int az2 = HIWORD (dwAtoZ);

	if ((az1 < 0 || az2 >= 'Z' - 'A') ||
			(az2 < 0 || az2 > 'Z' - 'A' - 1)) 
	{
		az1 = 0; az2 = 'Z' - 'A' - 1;
	}

	for (i = 0; i < 'Z' - 'A'; i++)
	{
		CString str = (char)('A' + i);
		m_wndA.AddString (str);
	}
	m_wndA.SetCurSel (az1);
	FillZ ();
	m_wndZ.SetCurSel (az2);

	ReadAutostart ();
	ApplyLanguage ();

	if (m_wndGroups.SelectGroupById (_App.NewDL_GroupId ()))
		m_bGroupChanged = TRUE;

	OnChangeGroups ();

	SetDlgItemText (IDC_NUMBERS, _App.CreateBD_LastNumbers ());

	CString strSaveAs = _App.CreateBD_SaveAs_Template ();
	SetDlgItemText (IDC_SAVEAS, strSaveAs);
	if (strSaveAs == "") {
		CheckDlgButton (IDC_FILEAUTO, BST_CHECKED);
		UpdateEnabled ();
	}

	m_dld->dwFlags |= DLD_BATCH;

	return TRUE;  
	              
}

void CCreateBatchDownload::OnChangeGroups()
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);
}

void CCreateBatchDownload::OnSelchangeGroups() 
{
	OnChangeGroups ();	
	m_bGroupChanged = TRUE;
}

void CCreateBatchDownload::UpdateEnabled()
{
	GetDlgItem (IDC__USER)->EnableWindow (m_bAuthorization);
	GetDlgItem (IDC_USER)->EnableWindow (m_bAuthorization);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (m_bAuthorization);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (m_bAuthorization);

	BOOL b = IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED;
	GetDlgItem (IDC__SAVEAS)->EnableWindow (b);
	GetDlgItem (IDC_SAVEAS)->EnableWindow (b);
}

void CCreateBatchDownload::Update_User_Password()
{
	BOOL b = m_bAuthChanged;

	fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();
	if (*dnp->pszUserName)
	{
		CheckDlgButton (IDC_USELOGIN, BST_CHECKED);
		m_bAuthorization = TRUE;
	}
	else
	{
		CheckDlgButton (IDC_USELOGIN, BST_UNCHECKED);
		m_bAuthorization = FALSE;
	}

	SetDlgItemText (IDC_USER, dnp->pszUserName);
	SetDlgItemText (IDC_PASSWORD, dnp->pszPassword);

	UpdateEnabled ();

	m_bAuthChanged = b;
}

void CCreateBatchDownload::UrlChanged()
{
	CHAR szFile [10000];
	*szFile = 0;
	fsURL url;

	m_bBLParametersChanged = true;

	if (IR_SUCCESS != url.Crack (m_strUrl))
		return;

	
	
	if (m_bGroupChanged == FALSE)
	{
		fsFileNameFromUrlPath (url.GetPath (), url.GetInternetScheme () == INTERNET_SCHEME_FTP, 
			TRUE, szFile, sizeof (szFile));

		int len = strlen (szFile);
		vmsDownloadsGroupSmartPtr grp;

		if (len)
		{
			int i;
			for (i = len-1; i > 0; i--)
				if (szFile [i] == '.')	
					break;

			if (i && i < len-1)
			{
				i++;
				CHAR szExt [1000];
				strcpy (szExt, szFile + i);
				grp = _DldsGrps.FindGroupByExt (szExt);
			}
		}

		if (grp == NULL)
			grp = _DldsGrps.FindGroup (GRP_OTHER_ID);

		if (grp != NULL)
		{		
			if (m_wndGroups.SelectGroup (grp))
				OnChangeGroups();
		}

		m_bGroupChanged = FALSE;
	}

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
		m_bAuthorization = !strNewUser.IsEmpty ();
		CheckDlgButton (IDC_USELOGIN, m_bAuthorization ? BST_CHECKED : BST_UNCHECKED);
		SetDlgItemText (IDC_USER, strNewUser);
		SetDlgItemText (IDC_PASSWORD, strNewPassword);
		m_bAuthChanged = FALSE;
		UpdateEnabled ();
	}
}

void CCreateBatchDownload::ReadAutostart()
{
	m_iAutostart = _App.Last_Autostart ();

	switch (m_iAutostart)
	{
		case 0:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTNOW);
			m_dld->bAutoStart = TRUE;
			m_bScheduled = FALSE;
			break;

		case 1:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTMANUAL);
			m_dld->bAutoStart = FALSE; 
			m_bScheduled = FALSE;
			break;

		case 2:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
			m_dld->bAutoStart = FALSE;
			m_bScheduled = TRUE;
			break;
	}
}

void CCreateBatchDownload::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USELOGIN, L_AUTHORIZATION),
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
		fsDlgLngInfo (IDC__FROM2, L_DLGFROM),
		fsDlgLngInfo (IDC__TO2, L_DLGTO),
		fsDlgLngInfo (IDC_RESULTS, L_SEERESULTS),
		fsDlgLngInfo (IDC__SAMPLE, L_DLGSAMPLE),
		fsDlgLngInfo (IDC_QUERYSIZE, L_QUERYSIZE),
		fsDlgLngInfo (IDC__SETOFNUMBERS, L_SETOFNUMBERS, TRUE),
		fsDlgLngInfo (IDC_SETNUMBERS, L_ASSIGN),
		fsDlgLngInfo (IDC_FILEAUTO, L_FILEAUTO),
		fsDlgLngInfo (IDC__SAVEAS, L_DLG_SAVE_AS_TEMPLATE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATEBATCHDLD);
}

void CCreateBatchDownload::OnEditchangeUrl() 
{
	GetDlgItemText (IDC_URL, m_strUrl);	
	UrlChanged ();
}

void CCreateBatchDownload::OnSelchangeUrl() 
{
	CComboBox *pUrl = (CComboBox*) GetDlgItem (IDC_URL);
	pUrl->GetLBText (pUrl->GetCurSel (), m_strUrl);
	UrlChanged ();
}

void CCreateBatchDownload::OnUselogin() 
{
	m_bAuthorization = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;
	UpdateEnabled ();	
}

void CCreateBatchDownload::OnChangeUser() 
{
	m_bAuthChanged = TRUE;
}

void CCreateBatchDownload::OnChangePassword() 
{
	m_bAuthChanged = TRUE;
}

void CCreateBatchDownload::OnStartnow() 
{
	m_dld->bAutoStart = TRUE;
	m_bScheduled = FALSE;
	m_iAutostart = 0;	
}

void CCreateBatchDownload::OnStartmanual() 
{
	m_bScheduled = FALSE;
	m_dld->bAutoStart = FALSE;
	m_iAutostart = 1;	
}

void CCreateBatchDownload::OnStartschedule() 
{
	m_bScheduled = TRUE;
	m_dld->bAutoStart = FALSE;
	m_iAutostart = 2;	
}

void CCreateBatchDownload::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
		OnChangeGroups ();
}

void CCreateBatchDownload::OnChoosefolder() 
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

void CCreateBatchDownload::OnSettime() 
{
	CScheduleSheet sheet (LS (L_SCHEDULEDLDS), this);

	sheet.Init (&m_schScheduleParam.schTask, FALSE);
	
	_DlgMgr.OnDoModal (&sheet);

	if (IDOK == sheet.DoModal ())
	{
		CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
                m_bScheduled = TRUE;
		m_dld->bAutoStart = FALSE;
		m_iAutostart = 2;
	}

    _DlgMgr.OnEndDialog (&sheet);
	GetDlgItem (IDC_STARTSCHEDULE)->SetFocus ();	
}

void CCreateBatchDownload::OnAdvanced() 
{
	DLDS_LIST v;
	v.push_back (m_dld);

	GetDlgItemText (IDC_URL, m_strUrl);
	fsURL url;
	
	if (url.Crack (m_strUrl) != IR_SUCCESS)
	{
		WrongUrl ();
		return;
	}

	m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol = fsSchemeToNP (url.GetInternetScheme ());

	CDownloadPropertiesSheet sheet (LS (L_ADVANCED), this);
	sheet.Init (&v, DPS_SHP_NOGENERALNOMIRR);
    _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);	
}

void CCreateBatchDownload::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();	
}

BOOL CCreateBatchDownload::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CCreateBatchDownload::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CCreateBatchDownload::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__URL, LS (L_ADDROFFILE)),
		fsCtrlContextHelp (IDC_URL, LS (L_ADDROFFILE)),
		fsCtrlContextHelp (IDC__USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC_USER, LS (L_USERHERE)),
		fsCtrlContextHelp (IDC__PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_PASSWORD, LS (L_PWDHERE)),
		fsCtrlContextHelp (IDC_USELOGIN, LS (L_LOGINHERE)),
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
		fsCtrlContextHelp (IDC_RESULTS, LS (L_SEERESULTSHERE)),
		fsCtrlContextHelp (IDC_QUERYSIZE, LS (L_QUERYBATCHSIZEHERE)),
		fsCtrlContextHelp (IDC__SETOFNUMBERS, LS (L_SETOFNUMBERS_HERE)),
		fsCtrlContextHelp (IDC_NUMBERS, LS (L_SETOFNUMBERS_HERE)),
		fsCtrlContextHelp (IDC_SETNUMBERS, LS (L_ASSIGNSETOFNUMBERS_HERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CCreateBatchDownload::OnResults() 
{
	if (FALSE == BuildBatchList ())
		return;

	CCBD_SeeResultsDlg dlg;
	dlg.m_bl = &m_bl;

	_DlgMgr.DoModal (&dlg);
}

BOOL CCreateBatchDownload::BuildBatchList()
{
	if (m_bBLParametersChanged == false)
		return TRUE;

	GetDlgItemText (IDC_URL, m_strUrl);
	if (FALSE == CheckUrl ())
		return FALSE;

	m_iAlphaFrom = m_wndA.GetCurSel ();
	m_iAlphaTo   = m_iAlphaFrom + m_wndZ.GetCurSel () + 1;
	CString strNumbers;
	GetDlgItemText (IDC_NUMBERS, strNumbers);
	if (false == m_bl.Create (m_strUrl, strNumbers, (char)('A' + m_iAlphaFrom), 
			(char)('A' + m_iAlphaTo))) {
		MessageBox (LS (L_SYNTAXERROR), LS (L_INPERR), MB_ICONERROR);
		GetDlgItem (IDC_NUMBERS)->SetFocus ();
		return FALSE;
	}

	FreeDownloads ();
	m_bBLParametersChanged = false;
	
	return TRUE;
}

void CCreateBatchDownload::WrongUrl()
{
	MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
	GetDlgItem (IDC_URL)->SetFocus ();
}

BOOL CCreateBatchDownload::CheckUrl()
{
	fsURL url;
	GetDlgItemText (IDC_URL, m_strUrl);
	if (url.Crack (m_strUrl) != IR_SUCCESS || *url.GetHostName () == 0 || *url.GetPath () == 0)
	{
		WrongUrl ();
		return FALSE;
	}

	
	if (m_strUrl.Find ("(*)") == -1 &&
			m_strUrl.Find ("(*A)") == -1 &&
			m_strUrl.Find ("(*a)") == -1)
	{
		MessageBox (LS (L_USEBDS2), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_URL)->SetFocus ();
		return FALSE;
	}

	return TRUE;
}

void CCreateBatchDownload::OnOK() 
{
	if (FALSE == ReadAuth ())
		return;

	if (FALSE == BuildBatchList ())
		return;

	CString strSaveAs;
	if (IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED)
	{
		GetDlgItemText (IDC_SAVEAS, strSaveAs);
	}

	if (strSaveAs != "")
	{
		CString strNumbers;
		GetDlgItemText (IDC_NUMBERS, strNumbers);

		m_blSaveAs.Create (strSaveAs, strNumbers, (char)('A' + m_iAlphaFrom), 
			(char)('A' + m_iAlphaTo));

		if (m_bl.get_ResultCount () != m_blSaveAs.get_ResultCount ())
		{
			MessageBox (LS (L_INVALID_SAVE_AS_TEMPLATE), LS (L_INPERR), MB_ICONERROR);
			GetDlgItem (IDC_SAVEAS)->SetFocus ();
			return;
		}

		if (strcspn (m_blSaveAs.get_Result (0), "\\/:*?\"<>|") != strlen (m_blSaveAs.get_Result (0)))
		{
			MessageBox (LS (L_INVFILENAME), LS (L_INPERR), MB_ICONEXCLAMATION);
			GetDlgItem (IDC_SAVEAS)->SetFocus ();
			return;
		}
	}
	else {
		m_blSaveAs.Clear ();
	}

	BOOL bUseZipPreview = _App.NewDL_UseZIPPreview ();

	if (bUseZipPreview)
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_USEZIPPREVIEW;
	else
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags &= ~DPF_USEZIPPREVIEW;

	CString strOutFolder;

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_OUTFOLDER))
		return;

	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	fsPathToGoodPath ((LPSTR)(LPCSTR)strOutFolder);

	if (strOutFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	_LastFolders.AddRecord (strOutFolder);
	_LastBatchUrls.AddRecord (m_strUrl);

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

	fsnew (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, CHAR, strOutFolder.GetLength () + 1);
	strcpy (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, strOutFolder);

	m_dld->pGroup = m_wndGroups.GetSelectedGroup ();

	m_wndGroups.RememberSelectedGroup ();
	
	_App.Last_Autostart (m_iAutostart);

	GenerateAndAddDownloads ();	

	
	_App.CreateBD_LastAtoZ (MAKELPARAM (m_wndA.GetCurSel (), m_wndZ.GetCurSel ()));
	CString str;
	GetDlgItemText (IDC_NUMBERS, str);
	_App.CreateBD_LastNumbers (str);
	_App.CreateBD_SaveAs_Template (strSaveAs);

	if (m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszUserName && *m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszUserName)
	{
		fsURL url;
		url.Crack (m_strUrl);
		LPCSTR pszServer = url.GetHostName ();
		if (strstr (pszServer, "(*)") == NULL &&
			strstr (pszServer, "(*a)") == NULL &&
			strstr (pszServer, "(*A)") == NULL)
		{
			CCreateDownloadDlg::_SavePassword (pszServer, fsSchemeToNP (url.GetInternetScheme ()),
				m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszUserName, m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPassword);
		}
	}

	_App.OnDlHasBeenCreatedByUser ();

	CDialog::OnOK();
}

BOOL CCreateBatchDownload::ReadAuth()
{
	CString strUser, strPassword;

	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED)
	{
		GetDlgItemText (IDC_USER, strUser);
		GetDlgItemText (IDC_PASSWORD, strPassword);

		if (strUser.GetLength () == 0)
		{
			MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
			GetDlgItem (IDC_USER)->SetFocus ();
			return FALSE;
		}
	}
	else
	{
		fsURL url;
		url.Crack (m_strUrl);
		strUser = url.GetUserName ();
		strPassword = url.GetPassword ();
	}

	if (strUser != "")
	{
		fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
		SAFE_DELETE_ARRAY (dnp->pszUserName);
		SAFE_DELETE_ARRAY (dnp->pszPassword);

		fsnew (dnp->pszUserName, CHAR, strUser.GetLength ()+1);
		fsnew (dnp->pszPassword, CHAR, strPassword.GetLength ()+1);
		strcpy (dnp->pszUserName, strUser);
		strcpy (dnp->pszPassword, strPassword);
	}

	return TRUE;
}

void CCreateBatchDownload::GenerateAndAddDownloads()
{
	
	if (m_pvDownloads == NULL)
		m_pvDownloads = GenerateDownloads ();

	
	ASSERT (m_blSaveAs.get_ResultCount () == 0 || m_blSaveAs.get_ResultCount () == (int)m_pvDownloads->size ());
	LPCSTR psz = m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
	int len = lstrlen (psz);
	size_t i = 0;
	for (i = 0; i < (size_t)m_blSaveAs.get_ResultCount (); i++)
	{
		fsDownload_Properties* dp = m_pvDownloads->at (i)->pMgr->GetDownloadMgr ()->GetDP ();
		LPCSTR pszAs = m_blSaveAs.get_Result (i);

		if (dp->pszFileName)
			delete [] dp->pszFileName;

		dp->pszFileName = new char [len + lstrlen (pszAs) + 1];
		lstrcpy (dp->pszFileName, psz);
		lstrcat (dp->pszFileName, pszAs);
	}

	
	for (i = 0; i < m_pvDownloads->size (); i++)
		fsDownloadsMgr::Download_CloneSettings (m_pvDownloads->at (i), m_dld);

	
	_pwndDownloads->CreateDownloads (*m_pvDownloads, m_bScheduled ? &m_schScheduleParam.schTask : NULL);

	FreeDownloads ();
}

DLDS_LIST* CCreateBatchDownload::GenerateDownloads()
{
	DLDS_LIST *vpDlds = new DLDS_LIST;

	for (int i = 0; i < m_bl.get_ResultCount (); i++)
	{
		vmsDownloadSmartPtr dld;
		Download_CreateInstance (dld);

		dld->pMgr->GetDownloadMgr ()->CreateByUrl (m_bl.get_Result (i), TRUE);
		vpDlds->push_back (dld);
	}

	return vpDlds;
}

void CCreateBatchDownload::OnQuerysize() 
{
	if (FALSE == CheckUrl ())
		return;

	if (FALSE == ReadAuth ())
		return;

	
	if (m_bBLParametersChanged)
	{
		if (FALSE == BuildBatchList ())
			return;

		m_pvDownloads = GenerateDownloads ();
	}

	CWaitDlg dlg;	
	dlg.StartWaiting (LS (L_QUERINGSIZE), _threadCalcSize, TRUE, this, &dlg);
}

DWORD WINAPI CCreateBatchDownload::_threadCalcSize(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CCreateBatchDownload* pThis = (CCreateBatchDownload*) info->lpParam1;
	
	
	DWORD dw;
	CloseHandle (CreateThread (NULL, 0, _threadCalculateSize, lp, 0, &dw));

	
	while (info->bWaitDone == FALSE)
	{
		if (info->bNeedStop)
		{
			for (size_t i = 0; i < pThis->m_pvDownloads->size (); i++)
				pThis->m_pvDownloads->at (i)->pMgr->GetDownloadMgr ()->StopQuering ();

			break;
		}

		Sleep (500);
	}
	
	return 0;
}

DWORD WINAPI CCreateBatchDownload::_threadCalculateSize(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CWaitDlg* dlg = (CWaitDlg*) info->lpParam2;
	CCreateBatchDownload* pThis = (CCreateBatchDownload*) info->lpParam1;

	int iFailed = 0;	
	UINT64 uSummSize = 0;	

	
	for (size_t i = 0; i < pThis->m_pvDownloads->size () && info->bNeedStop == FALSE; i++)
	{
		vmsDownloadSmartPtr dld = pThis->m_pvDownloads->at (i);
		if (IR_SUCCESS != dld->pMgr->GetDownloadMgr ()->QuerySize ())	
			iFailed ++;	

		UINT64 uSize = dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetSSFileSize ();

		
		if (uSize == _UI64_MAX)
		{
			uSummSize = _UI64_MAX;	
			break;
		}

		uSummSize += uSize;

		CString str;
		str.Format ("%s (%d - %s, %d - %s)", LS (L_QUERINGSIZE), i+1, LS (L_DONE), iFailed, LS (L_ERR));
		dlg->SetDlgItemText (IDC_MESSAGE, str);	

		info->iProgress = (int) ((double) i / pThis->m_pvDownloads->size () * 100);
	}

	if (info->bNeedStop == FALSE)
	{
		CString strSize;

		if (uSummSize == _UI64_MAX)
			strSize = LS (L_UNKNOWN);
		else
		{
			if (_pwndDownloads->IsSizesInBytes () == FALSE)
			{
				char szDim [50];
				float fSize;
				BytesToXBytes (uSummSize, &fSize, szDim);
				strSize.Format ("%.*g %s", fSize > 999 ? 4 : 3, fSize, szDim);
			}
			else
				strSize = fsBytesToStr (uSummSize);
		}

		
		pThis->SetDlgItemText (IDC_QUERYSIZE, strSize);
	}
	else
		pThis->SetDlgItemText (IDC_QUERYSIZE, LS (L_QUERYSIZE));

	info->bWaitDone = TRUE;

	return 0;
}

void CCreateBatchDownload::OnCancel() 
{
	FreeDownloads ();
	CDialog::OnCancel();
}

void CCreateBatchDownload::FreeDownloads()
{
	if (m_pvDownloads)
	{
		delete m_pvDownloads;
		m_pvDownloads = NULL;
	}
}

void CCreateBatchDownload::FillZ()
{
	CString str;
	if (m_wndZ.GetCurSel () != LB_ERR)
		m_wndZ.GetLBText (m_wndZ.GetCurSel (), str);

	m_wndZ.ResetContent ();
	for (int i = m_wndA.GetCurSel () + 1; i <= 'Z' - 'A'; i++)
	{
		CString str = (char)('A' + i);
		m_wndZ.AddString (str);
	}

	if (str != "")
		m_wndZ.SelectString (-1, str);
	if (m_wndZ.GetCurSel () == LB_ERR)
		m_wndZ.SetCurSel (m_wndZ.GetCount ()-1);
}

void CCreateBatchDownload::OnSelchangeA() 
{
	FillZ ();
	m_bBLParametersChanged = true;
}

void CCreateBatchDownload::OnSelchangeZ() 
{
	m_bBLParametersChanged = true;	
}

void CCreateBatchDownload::OnChangeNumbers() 
{
	m_bBLParametersChanged = true;
}

void CCreateBatchDownload::OnSetnumbers() 
{
	CDlg_SetBatchNumbers dlg;
	if (IDOK == _DlgMgr.DoModal (&dlg))
		SetDlgItemText (IDC_NUMBERS, dlg.m_strNumbers);
}

void CCreateBatchDownload::OnFileauto() 
{
	UpdateEnabled ();	
}

void CCreateBatchDownload::OnOutfolderSetdefault() 
{
	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	CCreateDownloadDlg::_SetDownloadOutputFolderAsDefault (this, strOutFolder,
		m_wndGroups.GetSelectedGroup ());
}
