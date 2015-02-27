/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CreateDownloadListDlg.h"
#include "DownloadsWnd.h"
#include "CreateDownloadDlg.h"
#include "GroupDlg.h"
#include "FolderBrowser.h"
#include "ScheduleSheet.h"
#include "DownloadPropertiesSheet.h"
#include "WaitDlg.h"
#include "DlgExtensionsFilter.h"
#include "inetutil.h"
#include "FdmUiWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd *_pwndDownloads;

CCreateDownloadListDlg::CCreateDownloadListDlg(CWnd* pParent )
	: CDialog(CCreateDownloadListDlg::IDD, pParent),
	  m_bIsFirstHit(true),
	  m_bUsernameChanged(false),
	  m_bPasswordChanged(false)
{
	//{{AFX_DATA_INIT(CCreateDownloadListDlg)
	//}}AFX_DATA_INIT

	Download_CreateInstance (m_dld);
	m_pUiWindow = NULL;
}

void CCreateDownloadListDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDownloadListDlg)
	DDX_Control(pDX, IDC_URLLIST, m_wndUrlList);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_SETTIME, m_btnSetTime);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateDownloadListDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateDownloadListDlg)
	ON_WM_CONTEXTMENU()
	ON_WM_HELPINFO()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_NOTIFY(LVN_KEYDOWN, IDC_URLLIST, OnKeydownUrllist)
	ON_BN_CLICKED(IDC_DELSELECTED, OnDelselected)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_URLLIST, OnItemchangedUrllist)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_SETTIME, OnSettime)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_BN_CLICKED(IDC_QUERYSIZE, OnQuerysize)
	ON_BN_CLICKED(IDC_STARTNOW, OnStartnow)
	ON_BN_CLICKED(IDC_STARTMANUAL, OnStartmanual)
	ON_BN_CLICKED(IDC_STARTSCHEDULE, OnStartschedule)
	ON_BN_CLICKED(IDC_USELOGIN, OnUselogin)
	ON_BN_CLICKED(IDC_FILTER, OnFilter)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_USER, &CCreateDownloadListDlg::OnEnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, &CCreateDownloadListDlg::OnEnChangePassword)
END_MESSAGE_MAP()

BOOL CCreateDownloadListDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (m_pUiWindow)
		m_pUiWindow->setWindow (m_hWnd);
	
	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));
	m_btnSetTime.SetIcon (SICO (IDI_SETTIME));

	
	m_schScheduleParam.schTask.hts.enType = HTS_ONCE;
	m_schScheduleParam.schTask.hts.last.dwHighDateTime = m_schScheduleParam.schTask.hts.last.dwLowDateTime = UINT_MAX;
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
	m_dld->bAutoStart = TRUE;  

	m_dld->pMgr->GetDownloadMgr ()->CreateByUrl ("http://");

	m_bGroupChanged = m_bAuthChanged = FALSE;

	WriteUrlsToDialog ();

	
	UINT uiState = BST_UNCHECKED;

	tstring sUserName;
	tstring sPassword;

	bool bHaveSpecified = false;
	bool bHaveUnspecified = false;

	int cDownloads = m_wndUrlList.GetItemCount();
	int i = 0;
	for (i = 0; i <= cDownloads - 1; i++) {
		LPCSTR pszUrl = m_pvUrls->at (m_wndUrlList.GetItemData (i));
		fsURL urlDownloadUrl;
		if (IR_SUCCESS != urlDownloadUrl.Crack (pszUrl)) {
			continue;
		}

		fsSiteInfo *siDldSiteInfo = _SitesMgr.FindSite (urlDownloadUrl.GetHostName (), fsNPToSiteValidFor (fsSchemeToNP (urlDownloadUrl.GetInternetScheme ())));
		if (siDldSiteInfo && siDldSiteInfo->strUser != NULL && siDldSiteInfo->strPassword != NULL && *urlDownloadUrl.GetUserName () == 0) {
				
			if (!bHaveSpecified) {
				sUserName = (LPTSTR)siDldSiteInfo->strUser;
				sPassword = (LPTSTR)siDldSiteInfo->strPassword;
				bHaveSpecified = true;
			} else {
				tstring sCurrentUserName = (LPTSTR)siDldSiteInfo->strUser;
				tstring sCurrentPassword = (LPTSTR)siDldSiteInfo->strPassword;

				if (sUserName.compare(sCurrentUserName) != 0) {
					sUserName = _T("");
				}

				if (sPassword.compare(sCurrentPassword) != 0) {
					sPassword = _T("");
				}
			}

		} else if (*urlDownloadUrl.GetUserName () == 0 && *urlDownloadUrl.GetPassword ()) {

			if (!bHaveSpecified) {
				sUserName = urlDownloadUrl.GetUserName ();
				sPassword = urlDownloadUrl.GetPassword ();
				bHaveSpecified = true;
			} else {
				tstring sCurrentUserName = urlDownloadUrl.GetUserName ();
				tstring sCurrentPassword = urlDownloadUrl.GetPassword ();

				if (sUserName.compare(sCurrentUserName) != 0) {
					sUserName = _T("");
				}

				if (sPassword.compare(sCurrentPassword) != 0) {
					sPassword = _T("");
				}
			}

		} else {
			bHaveUnspecified = true;
		}
	}

	if (bHaveSpecified && bHaveUnspecified) {
		uiState = BST_INDETERMINATE;
	} else if (bHaveSpecified && !bHaveUnspecified) {
		uiState = BST_CHECKED;
		SetDlgItemText (IDC_USER, sUserName.c_str());
		SetDlgItemText (IDC_PASSWORD, sPassword.c_str());
	} else {
		uiState = BST_UNCHECKED;
	}
	CheckDlgButton (IDC_USELOGIN, uiState);

	ReadAutostart ();

	ApplyLanguage ();

	if (m_wndGroups.SelectGroupById (_App.NewDL_GroupId ()))
		m_bGroupChanged = TRUE;

	OnChangeGroups ();
	
	fsSetForegroundWindow (m_hWnd);

	m_bPasswordChanged = false;
	m_bUsernameChanged = false;

	UpdateEnabled ();
	return TRUE;
}

void CCreateDownloadListDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_DELSELECTED, L_DELETESELECTED),
		fsDlgLngInfo (IDC_FILTER, L_FILTER),
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
		fsDlgLngInfo (IDC_QUERYSIZE, L_QUERYSIZE),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_ADDLISTOFDOWNLOADS);
}

void CCreateDownloadListDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();		
}

BOOL CCreateDownloadListDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CCreateDownloadListDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC_URLLIST, LS (L_URLLISTHERE)),
		fsCtrlContextHelp (IDC_DELSELECTED, LS (L_DELETESELECTEDHERE)),
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
		fsCtrlContextHelp (IDC_QUERYSIZE, LS (L_QUERYBATCHSIZEHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));
}

void CCreateDownloadListDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CCreateDownloadListDlg::ReadAutostart()
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

void CCreateDownloadListDlg::OnChangeGroups()
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);
}

void CCreateDownloadListDlg::OnOK() 
{
	if (FALSE == ReadAuth ())
		return;

	CString strOutFolder;

	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	fsPathToGoodPath ((LPSTR)(LPCSTR)strOutFolder);

	if (strOutFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_OUTFOLDER))
		return;

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

	fsnew (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, CHAR, strOutFolder.GetLength () + 1);
	strcpy (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, strOutFolder);

	m_dld->pGroup = m_wndGroups.GetSelectedGroup ();

	BOOL bUseZipPreview = _App.NewDL_UseZIPPreview ();

	if (bUseZipPreview)
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_USEZIPPREVIEW;
	else
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags &= ~DPF_USEZIPPREVIEW;

	if (FALSE == AddDownloads ())
		return;

	m_wndGroups.RememberSelectedGroup ();
	_App.Last_Autostart (m_iAutostart);
	_App.UseZipPreview (bUseZipPreview);

	_App.OnDlHasBeenCreatedByUser ();

	CDialog::OnOK();
}

BOOL CCreateDownloadListDlg::ReadAuth()
{
	CString strUser, strPassword;

	

	GetDlgItemText (IDC_USER, strUser);
	GetDlgItemText (IDC_PASSWORD, strPassword);

	UINT uiState = IsDlgButtonChecked (IDC_USELOGIN);

	switch (uiState) {
		case BST_CHECKED:
			if (m_bUsernameChanged || !strUser.IsEmpty()) {
				fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				SAFE_DELETE_ARRAY (dnp->pszUserName);
				
				fsnew (dnp->pszUserName, CHAR, strUser.GetLength ()+1);
				strcpy (dnp->pszUserName, strUser);
			}

			if (m_bPasswordChanged || !strPassword.IsEmpty()) {
				fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				SAFE_DELETE_ARRAY (dnp->pszPassword);
				
				fsnew (dnp->pszPassword, CHAR, strPassword.GetLength ()+1);
				strcpy (dnp->pszPassword, strPassword);
			}
			break;

		case BST_UNCHECKED:
		case BST_INDETERMINATE:

			{
				CString sEmptyString;

				fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				SAFE_DELETE_ARRAY (dnp->pszUserName);
				SAFE_DELETE_ARRAY (dnp->pszPassword);

				fsnew (dnp->pszUserName, CHAR, sEmptyString.GetLength ()+1);
				fsnew (dnp->pszPassword, CHAR, sEmptyString.GetLength ()+1);
				strcpy (dnp->pszUserName, sEmptyString);
				strcpy (dnp->pszPassword, sEmptyString);
			}

			break;
	}

	return TRUE;
}

BOOL CCreateDownloadListDlg::AddDownloads()
{
	DLDS_LIST* pvpDlds = GenerateDownloads (_App.CheckIfDownloadWithSameUrlExists ());

	if (pvpDlds == NULL)
		return FALSE;

	
	_pwndDownloads->CreateDownloads (*pvpDlds, m_bScheduled ? &m_schScheduleParam.schTask : NULL);

	delete pvpDlds;

	return TRUE;
}

void CCreateDownloadListDlg::WriteUrlsToDialog()
{
	m_wndUrlList.InsertColumn (0, "", LVCFMT_LEFT, 200);
	

	int wmax = 0;
	BOOL b1Server = TRUE;
	BOOL b1ServerESD = TRUE;	
	CString strServer;
	DWORD dwVF = 0;

	for (int i = 0, cItems = 0; i < m_pvUrls->size (); i++)
	{
		LPCSTR pszURL = m_pvUrls->at (i);

		fsURL url;
		if (IR_SUCCESS != url.Crack (pszURL))
			continue;

		if (i == 0) {
			strServer = url.GetHostName ();
		}
		else if (b1ServerESD) {
			b1Server = fsIsServersEqual (strServer, url.GetHostName (), FALSE);
			if (b1Server == false) {
				b1ServerESD = fsIsServersEqual (strServer, url.GetHostName (), TRUE);
				if (strServer.GetLength () < lstrlen (url.GetHostName ()))
					strServer = url.GetHostName ();
			}
			if (b1ServerESD)
				dwVF |= fsNPToSiteValidFor (fsSchemeToNP (url.GetInternetScheme ()));
		}
		
		int w = m_wndUrlList.GetStringWidth (pszURL);
		if (w > wmax)
			wmax = w;

		
		m_wndUrlList.InsertItem (cItems, pszURL);
		m_wndUrlList.SetItemData (cItems, i);
		
		cItems++;
	}

	m_wndUrlList.SetColumnWidth (0, wmax+20);

	m_wndUrlList.SetExtendedStyle (LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP);

	if (b1ServerESD)
	{
		fsSiteInfo* site = _SitesMgr.FindSite (strServer, dwVF, FALSE);
		if (site && site->strUser.GetLength ())
		{
			CheckDlgButton (IDC_USELOGIN, BST_CHECKED);
			SetDlgItemText (IDC_USER, site->strUser);
			SetDlgItemText (IDC_PASSWORD, site->strPassword);
		}
	}
}

void CCreateDownloadListDlg::OnKeydownUrllist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	LV_KEYDOWN* pLVKeyDown = (LV_KEYDOWN*)pNMHDR;
	
	if (pLVKeyDown->wVKey == VK_DELETE)
		DeleteSelectedUrls ();
	
	*pResult = 0;
}

void CCreateDownloadListDlg::DeleteSelectedUrls()
{
	if (m_wndUrlList.GetSelectedCount () == 0)
		return;

	if (MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_YESNO) == IDNO)
		return;

	std::vector <int> v;

	POSITION pos = m_wndUrlList.GetFirstSelectedItemPosition ();
	while (pos)
		v.push_back (m_wndUrlList.GetNextSelectedItem (pos));

	for (int i = v.size () - 1; i >= 0; i--)
		m_wndUrlList.DeleteItem (v [i]);
}

void CCreateDownloadListDlg::OnDelselected() 
{
	DeleteSelectedUrls ();	
}

void CCreateDownloadListDlg::UpdateEnabled()
{
	BOOL b = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;
	GetDlgItem (IDC__USER)->EnableWindow (b);
	GetDlgItem (IDC_USER)->EnableWindow (b);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (b);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (b);

	GetDlgItem (IDC_DELSELECTED)->EnableWindow (m_wndUrlList.GetSelectedCount ());
}

void CCreateDownloadListDlg::OnItemchangedUrllist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	
	
	UpdateEnabled ();
	
	*pResult = 0;
}

void CCreateDownloadListDlg::OnSelchangeGroups() 
{
	OnChangeGroups ();	
	m_bGroupChanged = TRUE;	
}

void CCreateDownloadListDlg::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
		OnChangeGroups ();
}

void CCreateDownloadListDlg::OnChoosefolder() 
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

void CCreateDownloadListDlg::OnSettime() 
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

void CCreateDownloadListDlg::OnAdvanced() 
{
	DLDS_LIST v;
	v.push_back (m_dld);

	m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol = NP_HTTP;

	CDownloadPropertiesSheet sheet (LS (L_ADVANCED), this);
	sheet.Init (&v, DPS_SHP_NOGENERALNOMIRR);
    _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);	
}

void CCreateDownloadListDlg::OnQuerysize() 
{
	if (FALSE == ReadAuth ())
		return;

	DLDS_LIST* pvpDlds = GenerateDownloads (FALSE);

	CWaitDlg dlg;	
	dlg.StartWaiting (LS (L_QUERINGSIZE), _threadCalcSize, TRUE, this, &dlg, pvpDlds);	

	delete pvpDlds;
}

DWORD WINAPI CCreateDownloadListDlg::_threadCalcSize(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	
	DLDS_LIST* pvpDlds = (DLDS_LIST*) info->lpParam3;
	
	
	DWORD dw;
	CloseHandle (CreateThread (NULL, 0, _threadCalculateSize, lp, 0, &dw));

	
	while (info->bWaitDone == FALSE)
	{
		if (info->bNeedStop)
		{
			for (size_t i = 0; i < pvpDlds->size (); i++)
				pvpDlds->at (i)->pMgr->GetDownloadMgr ()->StopQuering ();

			break;
		}

		Sleep (500);
	}

	return 0;
}

DWORD WINAPI CCreateDownloadListDlg::_threadCalculateSize(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CWaitDlg* dlg = (CWaitDlg*) info->lpParam2;
	CCreateDownloadListDlg* pThis = (CCreateDownloadListDlg*) info->lpParam1;
	DLDS_LIST* pvpDlds = (DLDS_LIST*) info->lpParam3;

	int iFailed = 0;	
	UINT64 uSummSize = 0;	

	
	for (size_t i = 0; i < pvpDlds->size () && info->bNeedStop == FALSE; i++)
	{
		vmsDownloadSmartPtr dld = pvpDlds->at (i);
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

		info->iProgress = (int) ((double) i / pvpDlds->size () * 100);
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

DLDS_LIST* CCreateDownloadListDlg::GenerateDownloads(BOOL bCheckDldExistance)
{
	DLDS_LIST* pvpDlds = new DLDS_LIST;

	int cDownloads = m_wndUrlList.GetItemCount ();
	bool bNeedReferer = m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer == NULL || *m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer == 0;

	for (int i = 0; i < cDownloads; i++)
	{
		vmsDownloadSmartPtr dld;
		Download_CreateInstance (dld);

		LPCSTR pszUrl = m_pvUrls->at (m_wndUrlList.GetItemData (i));
		LPCSTR pszCookies = m_pvCookies->at (m_wndUrlList.GetItemData (i));

		if (IR_SUCCESS != dld->pMgr->GetDownloadMgr ()->CreateByUrl (pszUrl, TRUE))
			continue;

		if (bCheckDldExistance)
		{
			int ret = CCreateDownloadDlg::_CheckDownloadAlrExists (m_dld);
			if (ret)
			{
				if (ret == 1)
					continue;
				
				return NULL;
			}
		}
			
		
		fsDownloadsMgr::Download_CloneSettings (dld, m_dld);

		
		if (IsDlgButtonChecked (IDC_USELOGIN) == BST_INDETERMINATE) {

			fsURL urlDownloadUrl;
			if (IR_SUCCESS != urlDownloadUrl.Crack (pszUrl)) {
				continue;
			}
			fsSiteInfo *siDldSiteInfo = _SitesMgr.FindSite (urlDownloadUrl.GetHostName (), fsNPToSiteValidFor (fsSchemeToNP (urlDownloadUrl.GetInternetScheme ())));
			if (siDldSiteInfo && siDldSiteInfo->strUser != NULL && siDldSiteInfo->strPassword != NULL && *urlDownloadUrl.GetUserName () == 0) {

				fsDownload_NetworkProperties *dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				SAFE_DELETE_ARRAY (dnp->pszUserName);
				SAFE_DELETE_ARRAY (dnp->pszPassword);

				fsnew (dnp->pszUserName, CHAR, siDldSiteInfo->strUser.GetLength ()+1);
				fsnew (dnp->pszPassword, CHAR, siDldSiteInfo->strPassword.GetLength ()+1);
				strcpy (dnp->pszUserName, siDldSiteInfo->strUser);
				strcpy (dnp->pszPassword, siDldSiteInfo->strPassword);

			} else if (*urlDownloadUrl.GetUserName () == 0 && *urlDownloadUrl.GetPassword ()) {
				fsDownload_NetworkProperties *dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				SAFE_DELETE_ARRAY (dnp->pszUserName);
				SAFE_DELETE_ARRAY (dnp->pszPassword);

				tstring sUserName = urlDownloadUrl.GetUserName ();
				tstring sPasword = urlDownloadUrl.GetUserName ();

				fsnew (dnp->pszUserName, CHAR, sUserName.length() + 1);
				fsnew (dnp->pszPassword, CHAR, sPasword.length() + 1);
				strcpy (dnp->pszUserName, sUserName.c_str());
				strcpy (dnp->pszPassword, sPasword.c_str());
			}

		}

		if (IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED) {

			fsURL urlDownloadUrl;
			if (IR_SUCCESS != urlDownloadUrl.Crack (pszUrl)) {
				continue;
			}
			fsSiteInfo *siDldSiteInfo = _SitesMgr.FindSite (urlDownloadUrl.GetHostName (), fsNPToSiteValidFor (fsSchemeToNP (urlDownloadUrl.GetInternetScheme ())));
			if (siDldSiteInfo && siDldSiteInfo->strUser != NULL && siDldSiteInfo->strPassword != NULL && *urlDownloadUrl.GetUserName () == 0) {

				fsDownload_NetworkProperties *dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				if (!m_bUsernameChanged) {
					SAFE_DELETE_ARRAY (dnp->pszUserName);
					fsnew (dnp->pszUserName, CHAR, siDldSiteInfo->strUser.GetLength ()+1);
					strcpy (dnp->pszUserName, siDldSiteInfo->strUser);
				}
				if (!m_bPasswordChanged) {
					SAFE_DELETE_ARRAY (dnp->pszPassword);
					fsnew (dnp->pszPassword, CHAR, siDldSiteInfo->strPassword.GetLength ()+1);
					strcpy (dnp->pszPassword, siDldSiteInfo->strPassword);
				}

			} else if (*urlDownloadUrl.GetUserName () == 0 && *urlDownloadUrl.GetPassword ()) {
				fsDownload_NetworkProperties *dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
				if (!m_bUsernameChanged) {
					SAFE_DELETE_ARRAY (dnp->pszUserName);
					fsnew (dnp->pszUserName, CHAR, siDldSiteInfo->strUser.GetLength ()+1);
					strcpy (dnp->pszUserName, siDldSiteInfo->strUser);
				}
				if (!m_bPasswordChanged) {
					SAFE_DELETE_ARRAY (dnp->pszPassword);
					fsnew (dnp->pszPassword, CHAR, siDldSiteInfo->strPassword.GetLength ()+1);
					strcpy (dnp->pszPassword, siDldSiteInfo->strPassword);
				}
			}

		}

		if (bNeedReferer)
		{
			LPCSTR pszReferer = m_pvReferers->at (m_wndUrlList.GetItemData (i));
			int len = pszReferer ? lstrlen (pszReferer) : 0;
			if (len) 
			{
				SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer);
				dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer = new char [len+1];
				lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer, pszReferer);
			}
		}

		if (pszCookies && *pszCookies)
		{
			SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies);
			dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies = new char [lstrlen (pszCookies) + 1];
			lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies, pszCookies);
		}

		pvpDlds->push_back (dld);
	}

	return pvpDlds;
}

void CCreateDownloadListDlg::OnStartnow() 
{
	m_dld->bAutoStart = TRUE;
	m_bScheduled = FALSE;
	m_iAutostart = 0;		
}

void CCreateDownloadListDlg::OnStartmanual() 
{
	m_bScheduled = FALSE;
	m_dld->bAutoStart = FALSE;
	m_iAutostart = 1;	
}

void CCreateDownloadListDlg::OnStartschedule() 
{
	m_bScheduled = TRUE;
	m_dld->bAutoStart = FALSE;
	m_iAutostart = 2;	
}

void CCreateDownloadListDlg::OnUselogin() 
{
	if (IsDlgButtonChecked (IDC_USELOGIN) == BST_INDETERMINATE) {
		CheckDlgButton(IDC_USELOGIN, BST_UNCHECKED);
	}
	UpdateEnabled ();	
}

void CCreateDownloadListDlg::OnFilter() 
{
	CDlgExtensionsFilter dlg;

	dlg.m_strExts = _App.DldListDlg_Filter_LastExts ();
	dlg.m_bRemove = _App.DldListDlg_Filter_LastExtsRemove ();

	if (IDOK != _DlgMgr.DoModal (&dlg))
		return;

	_App.DldListDlg_Filter_LastExts (dlg.m_strExts);
	_App.DldListDlg_Filter_LastExtsRemove (dlg.m_bRemove);

	char szFile [10000];

	std::vector <int> v;

	int i = 0;
	for (i = 0; i < m_wndUrlList.GetItemCount (); i++)
	{
		LPCSTR pszUrl = m_pvUrls->at (m_wndUrlList.GetItemData (i));
		fsURL url;
		if (IR_SUCCESS == url.Crack (pszUrl))
		{
			fsFileNameFromUrlPath (url.GetPath (), url.GetInternetScheme () == INTERNET_SCHEME_FTP, 
				TRUE, szFile, sizeof (szFile));

			BOOL bExtPresent = FALSE;

			LPCSTR pszExt = strrchr (szFile, '.');
			if (pszExt && IsExtInExtsStr (dlg.m_strExts, pszExt+1))
				bExtPresent = TRUE;

			if ((bExtPresent && dlg.m_bRemove) ||
					(FALSE == bExtPresent && FALSE == dlg.m_bRemove))
				v.push_back (i);
		}
	}

	for (i = v.size () - 1; i >= 0; i--)
		m_wndUrlList.DeleteItem (v [i]);
}

void CCreateDownloadListDlg::OnEnChangeUser()
{
	m_bUsernameChanged = true;
}

void CCreateDownloadListDlg::OnEnChangePassword()
{
	m_bPasswordChanged = true;
}
