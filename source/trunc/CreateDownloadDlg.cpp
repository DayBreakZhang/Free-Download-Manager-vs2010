/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CreateDownloadDlg.h"
#include "DownloadsWnd.h"
#include "inetutil.h"
#include "fsDownloadMgr.h"
#include "GroupDlg.h"
#include "DownloadPropertiesSheet.h"
#include "FolderBrowser.h"
#include "ScheduleSheet.h"
#include "system.h"
#include "fsSitesMgr.h"
#include "DownloadsWnd.h"
#include "WaitForConfirmationDlg.h"
#include "DownloadAlrExistsDlg.h"
#include "Dlg_SavePassword.h"
#include "vmsMaliciousDownloadChecker.h"
#include "MyMessageBox.h"
#include "Dlg_Opinions.h"
#include "MyMessageBox.h"
#include "mfchelp.h"
#include "FdmUiWindow.h"
#include "vmsLogger.h"

extern CDownloadsWnd *_pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CCreateDownloadDlg::CCreateDownloadDlg(vmsDownloadSmartPtr dld, CWnd* pParent )
	: CDialog(CCreateDownloadDlg::IDD, pParent), m_dld (dld)
{
	//{{AFX_DATA_INIT(CCreateDownloadDlg)
	//}}AFX_DATA_INIT
	
	
	m_bScheduled = FALSE;
	m_strUrl = dld->pMgr->get_URL ();
	if (!dld->strComment.IsEmpty ())
		m_strComment = dld->strComment;
	m_iAutostart = 0;
	m_bThread = FALSE;
	m_bNeedExit = FALSE;
	m_bSetFocusToOKBtn = false;
	m_bPlaceAtTop = false;
	m_pszCookies = m_pszPostData = NULL;
	m_pUiWindow = NULL;
}

void CCreateDownloadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDownloadDlg)
	DDX_Control(pDX, IDC_OUTFOLDER_SETDEFAULT, m_btnOutFolderSetDefault);
	DDX_Control(pDX, IDC_DLDTYPE, m_wndDldType);
	DDX_Control(pDX, IDC_SETTIME, m_btnSetTime);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	DDX_Control (pDX, IDC_GROUPS, m_wndGroups);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateDownloadDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateDownloadDlg)
	ON_EN_CHANGE(IDC_SAVEAS, OnChangeSaveas)
	ON_BN_CLICKED(IDC_USELOGIN, OnAuthorization)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_STARTNOW, OnStartnow)
	ON_BN_CLICKED(IDC_STARTMANUAL, OnStartmanual)
	ON_BN_CLICKED(IDC_STARTSCHEDULE, OnStartschedule)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_SETTIME, OnSettime)
	ON_CBN_EDITCHANGE(IDC_URL, OnEditchangeUrl)
	ON_CBN_SELCHANGE(IDC_URL, OnSelchangeUrl)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_EN_CHANGE(IDC_USER, OnChangeUser)
	ON_EN_CHANGE(IDC_PASSWORD, OnChangePassword)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_QSIZE, OnQsize)
	ON_BN_CLICKED(IDC_FILEAUTO, OnFileauto)
	ON_BN_CLICKED(IDC_MIRRORS, OnMirrors)
	ON_CBN_SELCHANGE(IDC_DLDTYPE, OnSelchangeDldtype)
	ON_BN_CLICKED(IDC_MALICIOUS, OnMalicious)
	ON_BN_CLICKED(IDC_OUTFOLDER_SETDEFAULT, OnOutfolderSetdefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CCreateDownloadDlg::OnOK() 
{
	

	if (FALSE == ReadDNP ())
		return;

	CString strOutFolder, strFileName;

	int nDldType = m_wndDldType.GetCurSel ();

	if (nDldType == 1)	
	{
		char sz [MY_MAX_PATH];
		GetTempPath (sizeof (sz), sz);
		strOutFolder = sz;
	}
	else
	{
		if (FALSE == _CheckFolderName (this, IDC_OUTFOLDER))
			return;
		GetDlgItemText (IDC_OUTFOLDER, strOutFolder);
	
		if (IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED)
		{
			GetDlgItemText (IDC_SAVEAS, strFileName);
			if (FALSE == _CheckFileName (this, IDC_SAVEAS))
				return;
			_App.NewDL_GenerateNameAutomatically (FALSE);
		}
		else
			_App.NewDL_GenerateNameAutomatically (TRUE);
	}

	fsPathToGoodPath ((LPSTR)(LPCSTR)strOutFolder);
	fsPathToGoodPath ((LPSTR)(LPCSTR)strFileName);

	if (strOutFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	if (nDldType != 1)
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

	CString strFile = strOutFolder + strFileName;
	fsnew (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, CHAR, strFile.GetLength () + 1);
	lstrcpy (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, strFile);
	
	if (_App.CheckIfDownloadWithSameUrlExists ())
	{
		int ret = _CheckDownloadAlrExists (m_dld, 0, 1, this);
		if (ret)
		{
			SAFE_DELETE_ARRAY (m_dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName);
			if (ret == 1)
				EndDialog (ID_DLNOTADDED);
			return;
		}
	}

	m_dld->pGroup = m_wndGroups.GetSelectedGroup ();

	GetDlgItemText (IDC_COMMENT, m_dld->strComment);

	BOOL bUseZipPreview = _App.NewDL_UseZIPPreview ();
	_App.UseZipPreview (bUseZipPreview);

	if (bUseZipPreview)
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_USEZIPPREVIEW;
	else
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags &= ~DPF_USEZIPPREVIEW;

	if (nDldType == 1)
	{
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_STARTWHENDONE;
		m_dld->dwFlags |= DLD_DELETEWHENDONE | DLD_DELETEFILEATRESTART;
	}
	else if (nDldType == 2)
		m_dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_STARTWHENDONE;

	m_wndGroups.RememberSelectedGroup ();
	_App.Last_Autostart (m_iAutostart);

	if (m_bThread)
	{
		m_bNeedExit = TRUE;
		m_dld->pMgr->GetDownloadMgr ()->StopQuering ();
		while (m_bThread);
	}

	_SavePassword (m_dld);

	_App.OnDlHasBeenCreatedByUser ();

	m_bPlaceAtTop = IsDlgButtonChecked (IDC_PLACEATTOP) == BST_CHECKED;

	CDialog::OnOK();
}

BOOL CCreateDownloadDlg::OnInitDialog() 
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

	
	ASSERT (m_strUrl.IsEmpty () == FALSE);

	SetDlgItemText (IDC_COMMENT, m_strComment);

	CString strUser = _App.UserName ();
	m_bAuthorization = strUser.GetLength () != 0;
	SetDlgItemText (IDC_USER, strUser);
	SetDlgItemText (IDC_PASSWORD, _App.UserPassword ());

	CheckDlgButton (IDC_USELOGIN, m_bAuthorization ? BST_CHECKED : BST_UNCHECKED);

	m_wndGroups.Fill ();

	CComboBox *pUrls = (CComboBox*) GetDlgItem (IDC_URL);
	int i = 0;
	for (i = 0; i < _LastUrlFiles.GetRecordCount (); i++)
		pUrls->AddString (_LastUrlFiles.GetRecord (i));

	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_OUTFOLDER);
	for (i = 0; i < _LastFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFolders.GetRecord (i));

	CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTNOW);
	m_dld->bAutoStart = TRUE;  

	

	

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

	Update_User_Password ();

	SetDlgItemText (IDC_URL, m_strUrl == "http://url/" ? "http://" : m_strUrl);
	((CEdit*) GetDlgItem (IDC_URL))->SetSel (0, -1);

	GetDlgItem (IDC_URL)->SetFocus ();
	UrlChanged ();

	if (m_bReqTopMostDialog)
	{
		fsSetForegroundWindow (m_hWnd);
        mfcSetTopmostWindow (this);
	}

	ReadAutostart ();

	ApplyLanguage ();

	m_bGroupChanged = FALSE;

	if (m_pGroup == NULL)
		m_pGroup = _DldsGrps.FindGroup (_App.NewDL_GroupId ());

	if (m_pGroup != NULL && m_wndGroups.SelectGroup (m_pGroup))
	{
		m_bGroupChanged = TRUE;
		OnChangeGroups ();
	}

	_DldsMgr.Apply_MirrParameters (m_dld);

	m_wndDldType.AddString (LS (L_SAVEFILE));
	m_wndDldType.AddString (LS (L_OPENFILE));
	m_wndDldType.AddString (LS (L_SAVEFILEANDOPENIT));
	m_wndDldType.SetCurSel (0);

	CheckDlgButton (IDC_FILEAUTO, _App.NewDL_GenerateNameAutomatically () ? BST_CHECKED : BST_UNCHECKED);
	OnFileauto ();

	UpdateEnabled ();

	if (m_bSetFocusToOKBtn)
	{
		GetDlgItem (IDOK)->SetFocus ();
		return FALSE;
	}

	return TRUE;
}

void CCreateDownloadDlg::OnChangeSaveas() 
{
	
}

void CCreateDownloadDlg::UpdateEnabled()
{
	GetDlgItem (IDC__USER)->EnableWindow (m_bAuthorization);
	GetDlgItem (IDC_USER)->EnableWindow (m_bAuthorization);
	GetDlgItem (IDC__PASSWORD)->EnableWindow (m_bAuthorization);
	GetDlgItem (IDC_PASSWORD)->EnableWindow (m_bAuthorization);

	int nSel = m_wndDldType.GetCurSel ();
	GetDlgItem (IDC__SAVETO)->EnableWindow (nSel != 1);
	GetDlgItem (IDC_OUTFOLDER)->EnableWindow (nSel != 1);
	GetDlgItem (IDC_CHOOSEFOLDER)->EnableWindow (nSel != 1);
	GetDlgItem (IDC_FILEAUTO)->EnableWindow (nSel != 1);

	BOOL b = nSel != 1 && IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED;
	GetDlgItem (IDC__SAVEAS)->EnableWindow (b);
	GetDlgItem (IDC_SAVEAS)->EnableWindow (b);
}

void CCreateDownloadDlg::OnAuthorization() 
{
	m_bAuthorization = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;
	UpdateEnabled ();
}

void CCreateDownloadDlg::OnSelchangeGroups() 
{
	OnChangeGroups ();
	m_bGroupChanged = TRUE;
}

void CCreateDownloadDlg::OnStartnow() 
{
	m_dld->bAutoStart = TRUE;
	m_bScheduled = FALSE;
	m_iAutostart = 0;
}

void CCreateDownloadDlg::OnStartmanual() 
{
	m_bScheduled = FALSE;
	m_dld->bAutoStart = FALSE;
	m_iAutostart = 1;
}

void CCreateDownloadDlg::OnStartschedule() 
{
	m_bScheduled = TRUE;
	m_dld->bAutoStart = FALSE;
	m_iAutostart = 2;
}

void CCreateDownloadDlg::WrongURL()
{
	MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
	GetDlgItem (IDC_URL)->SetFocus ();
}

void CCreateDownloadDlg::WrongUserName()
{
	MessageBox (LS (L_ENTERUSER), LS (L_INPERR), MB_ICONEXCLAMATION);
	GetDlgItem (IDC_USER)->SetFocus ();
}

void CCreateDownloadDlg::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
	{
		OnChangeGroups ();
	}
}

void CCreateDownloadDlg::OnAdvanced() 
{
	DLDS_LIST v;
	v.push_back (m_dld);

	GetDlgItemText (IDC_URL, m_strUrl);
	fsURL url;
	if (url.Crack (m_strUrl) != IR_SUCCESS || *url.GetHostName () == 0 || *url.GetPath () == 0)
	{
		WrongURL ();
		return;
	}

	if (FALSE == ReadDNP ())
		return;

	

	m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol = fsSchemeToNP (url.GetInternetScheme ());

	CDownloadPropertiesSheet sheet (LS (L_ADVANCED), this);
	sheet.Init (&v, DPS_SHP_NOGENERALNOMIRR);
    _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);
}

BOOL CCreateDownloadDlg::ReadDNP()
{
	fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();

	if (m_bUrlChanged)
	{
		
		
		m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->DeleteAllSections ();
		GetDlgItemText (IDC_URL, m_strUrl);

		fsURL url;
		if (IR_SUCCESS != url.Crack (m_strUrl))
		{
			WrongURL ();
			return FALSE;
		}

		if (fsDNP_ApplyUrl (dnp, m_strUrl) != IR_SUCCESS)
		{
			WrongURL ();
			return FALSE;
		}
	}

	m_bAuthorization = IsDlgButtonChecked (IDC_USELOGIN) == BST_CHECKED;

	if (m_bAuthorization)
	{
		CString strUser, strPassword;
	
		GetDlgItemText (IDC_USER, strUser);
		GetDlgItemText (IDC_PASSWORD, strPassword);

		if (strUser.GetLength () == 0)
		{
			WrongUserName ();
			return FALSE;
		}

		fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();
		
		SAFE_DELETE_ARRAY (dnp->pszUserName);
		SAFE_DELETE_ARRAY (dnp->pszPassword);

		fsnew (dnp->pszUserName, CHAR, strUser.GetLength ()+1);
		fsnew (dnp->pszPassword, CHAR, strPassword.GetLength ()+1);
		strcpy (dnp->pszUserName, strUser);
		strcpy (dnp->pszPassword, strPassword);
	}

	m_bUrlChanged = FALSE;
	return TRUE;
}

void CCreateDownloadDlg::OnChoosefolder() 
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

void CCreateDownloadDlg::OnSettime() 
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

void CCreateDownloadDlg::Update_User_Password()
{
	BOOL b = m_bAuthChanged;

	fsDownload_NetworkProperties *dnp = m_dld->pMgr->GetDownloadMgr ()->GetDNP ();

	ASSERT (dnp != NULL);
	if (!dnp)
		return;

	ASSERT (dnp->pszUserName != NULL);
	if (!dnp->pszUserName)
		return;

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

void CCreateDownloadDlg::OnEditchangeUrl() 
{
	GetDlgItemText (IDC_URL, m_strUrl);	
	UrlChanged ();
}

void CCreateDownloadDlg::OnSelchangeUrl() 
{
	CComboBox *pUrl = (CComboBox*) GetDlgItem (IDC_URL);
	pUrl->GetLBText (pUrl->GetCurSel (), m_strUrl);
	UrlChanged ();
}

void CCreateDownloadDlg::UrlChanged()
{
	

	CHAR szFile [10000];
	*szFile = 0;
	fsURL url;

	m_bUrlChanged = TRUE;

	if (m_dld->dwFlags & (DLD_MALICIOUS_NO | DLD_MALICIOUS_YES))
	{
		GetDlgItem (IDC_MALICIOUS)->EnableWindow (TRUE);
		m_dld->dwFlags &= ~ (DLD_MALICIOUS_NO | DLD_MALICIOUS_YES);
	}

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
	}

	fsSiteInfo *site = _SitesMgr.FindSite (url.GetHostName (), fsNPToSiteValidFor (fsSchemeToNP (url.GetInternetScheme ())));
	if (site)
	{
		if (site->strUser != NULL && m_bAuthChanged == FALSE && *url.GetUserName () == 0)
		{
			CheckDlgButton (IDC_USELOGIN, BST_CHECKED);
			SetDlgItemText (IDC_USER, site->strUser);
			if (site->strPassword)
				SetDlgItemText (IDC_PASSWORD, site->strPassword);
			m_bAuthorization = TRUE;
			UpdateEnabled ();
		}

		if (site->pGroup && m_bGroupChanged == FALSE)
		{
			m_wndGroups.SelectGroup (site->pGroup);
			OnChangeGroups();
		}
	}
}

void CCreateDownloadDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CCreateDownloadDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CCreateDownloadDlg::OnChangeUser() 
{
	m_bAuthChanged = TRUE;
}

void CCreateDownloadDlg::OnChangePassword() 
{
	m_bAuthChanged = TRUE;
}

void CCreateDownloadDlg::OnChangeGroups()
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);
}

void CCreateDownloadDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USELOGIN, L_AUTHORIZATION),
		fsDlgLngInfo (IDC__USER, L_USER),
		fsDlgLngInfo (IDC__PASSWORD, L_PASSWORD),
		fsDlgLngInfo (IDC__SAVETO, L_SAVETO),
		fsDlgLngInfo (IDC__SAVEAS, L_SAVEAS),
		fsDlgLngInfo (IDC__START, L_START),
		fsDlgLngInfo (IDC_STARTNOW, L_AUTOMATICALLY),
		fsDlgLngInfo (IDC_STARTMANUAL, L_MANUALLY),
		fsDlgLngInfo (IDC_STARTSCHEDULE, L_SCHEDULE),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC_QSIZE, L_QUERYSIZE),
		fsDlgLngInfo (IDC_FILEAUTO, L_FILEAUTO),
		fsDlgLngInfo (IDC_MIRRORS, L_MIRRORS),
		
		fsDlgLngInfo (IDC__DLDTYPE, L_DLDTYPE),
		fsDlgLngInfo (IDC_MALICIOUS, L_IS_MALICIOUS),
		fsDlgLngInfo (IDC_PLACEATTOP, L_PLACEDLDATTOP),
	};

	CString str = LS (L_COMMENT); str += ':';
	SetDlgItemText (IDC__COMMENT, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_NEWDLD);
}

void CCreateDownloadDlg::ReadAutostart()
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

BOOL CCreateDownloadDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CCreateDownloadDlg::PrepareCHMgr(CPoint point)
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
		fsCtrlContextHelp (IDC__SAVEAS, LS (L_SAVEASHERE)),
		fsCtrlContextHelp (IDC_SAVEAS, LS (L_SAVEASHERE)),
		fsCtrlContextHelp (IDC__COMMENT, LS (L_DLDSHORTDESC)),
		fsCtrlContextHelp (IDC_COMMENT, LS (L_DLDSHORTDESC)),
		fsCtrlContextHelp (IDC_STARTNOW, LS (L_STARTNOWHERE)),
		fsCtrlContextHelp (IDC_STARTMANUAL, LS (L_MANUALLYSTARTHERE)),
		fsCtrlContextHelp (IDC_STARTSCHEDULE, LS (L_SCHEDULESTARTHERE)),
		fsCtrlContextHelp (IDC_SETTIME, LS (L_SETTIMEHERE)),
		fsCtrlContextHelp (IDC_ADVANCED, LS (L_ADVANCEDHERE)),
		fsCtrlContextHelp (IDOK, LS (L_ACCEPTCHANGES)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTACCEPTCHANGES)),
		fsCtrlContextHelp (IDC_QSIZE, LS (L_QUERYSIZEHERE)),
		fsCtrlContextHelp (IDC_FILEAUTO, LS (L_FILEAUTOHERE)),
		fsCtrlContextHelp (IDC_MIRRORS, LS (L_MIRRORSHERE)),
		fsCtrlContextHelp (IDC_MALICIOUS, LS (L_IS_MALICIOUS_HERE)),
		fsCtrlContextHelp (IDC_PLACEATTOP, LS (L_PLACEDLDATTOPHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));		
}

void CCreateDownloadDlg::OnQsize() 
{
	if (FALSE == ReadDNP ())
		return;

	m_bUrlChanged = FALSE;

	m_bThread = TRUE;
	DWORD dw;
	CloseHandle (CreateThread (NULL, 0, _threadQSize, this, 0, &dw));
	SetDlgItemText (IDC_QSIZE, LS (L_QUERINGSIZE));
	GetDlgItem (IDC_QSIZE)->EnableWindow (FALSE);
}

DWORD WINAPI CCreateDownloadDlg::_threadQSize(LPVOID lp)
{
	CCreateDownloadDlg *pThis = (CCreateDownloadDlg*) lp;

	try
	{
		if (pThis->m_pszCookies)
		{
			SAFE_DELETE_ARRAY (pThis->m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies);
			pThis->m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies = new char [lstrlen (pThis->m_pszCookies) + 1];
			lstrcpy (pThis->m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies, pThis->m_pszCookies);
		}

		if (pThis->m_pszPostData)
		{
			SAFE_DELETE_ARRAY (pThis->m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPostData);
			pThis->m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPostData = new char [lstrlen (pThis->m_pszPostData) + 1];
			lstrcpy (pThis->m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPostData, pThis->m_pszPostData);
		}

		fsInternetResult ir = pThis->m_dld->pMgr->GetDownloadMgr ()->QuerySize ();
	
		if (ir != IR_SUCCESS)
		{
			char szMsg [1000];
			fsIRToStr (ir, szMsg, sizeof (szMsg));
			if (pThis->m_bNeedExit == FALSE)
			{
				pThis->MessageBox (szMsg, LS (L_ERR), MB_ICONERROR);
				pThis->SetDlgItemText (IDC_QSIZE, LS (L_QUERYSIZE));
				pThis->GetDlgItem (IDC_QSIZE)->EnableWindow (TRUE);
			}
			pThis->m_bThread = FALSE;
			return 0;
		}

		CString strSize;
		UINT64 uSize = pThis->m_dld->pMgr->GetDownloadMgr ()->GetDownloader ()->GetSSFileSize ();

		if (pThis->m_bNeedExit == FALSE)
		{
			if (uSize == _UI64_MAX)
				strSize = LS (L_UNKNOWN);
			else
			{
				if (_pwndDownloads->IsSizesInBytes () == FALSE)
				{
					char szDim [50];
					float fSize;
					BytesToXBytes (uSize, &fSize, szDim);
					strSize.Format ("%.*g %s", fSize > 999 ? 4 : 3, fSize, szDim);
				}
				else
					strSize = fsBytesToStr (uSize); 
			}

			
			pThis->SetDlgItemText (IDC_QSIZE, strSize);
			pThis->GetDlgItem (IDC_QSIZE)->EnableWindow (TRUE);
		}

		pThis->m_bThread = FALSE;
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CCreateDownloadDlg::_threadQSize " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CCreateDownloadDlg::_threadQSize unknown exception");
	}

	return 0;
}

void CCreateDownloadDlg::OnCancel() 
{
	
	if (m_bThread)
	{
		m_bNeedExit = TRUE;
		m_dld->pMgr->GetDownloadMgr ()->StopQuering ();
		while (m_bThread);	
	}
	
	CDialog::OnCancel();
}

void CCreateDownloadDlg::OnFileauto() 
{
	CString str;
	GetDlgItemText (IDC_SAVEAS, str);
	if (str == "" && IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED)
	{
		fsURL url;
		CString strURL;
		GetDlgItemText (IDC_URL, strURL);
		url.Crack (strURL);
		char szFile [MY_MAX_PATH];
		fsFileNameFromUrlPath (url.GetPath (), url.GetInternetScheme () == INTERNET_SCHEME_FTP,
			TRUE, szFile, sizeof (szFile));
		SetDlgItemText (IDC_SAVEAS, szFile);
	}

	UpdateEnabled ();
}

int CCreateDownloadDlg::_CheckDownloadAlrExists(
	vmsDownloadSmartPtr dld, BOOL bNeedTopMost, BOOL bShowUI, CCreateDownloadDlg* const cddlg)
{
	fsURL url1, url2;

	if (dld->pMgr->GetDownloadMgr () == NULL)
		return 0;

	vmsDownloadSmartPtr dldSame;

	fsDownload_NetworkProperties* dnp0 = dld->pMgr->GetDownloadMgr ()->GetDNP ();

	_DldsMgr.LockList (true);

	size_t nCount = _DldsMgr.GetCount ();

	for (size_t i = 0; i < nCount; i++)
	{
		vmsDownloadSmartPtr d = _DldsMgr.GetDownload (i);
		if (d->pMgr->GetDownloadMgr () == NULL)
			continue;
		fsDownload_NetworkProperties* dnp = d->pMgr->GetDownloadMgr ()->GetDNP ();

		if (dnp0->enProtocol == dnp->enProtocol && 
			dnp0->uServerPort == dnp->uServerPort &&
			fsIsServersEqual (dnp0->pszServerName, dnp->pszServerName, FALSE) && 
			lstrcmp (dnp0->pszPathName, dnp->pszPathName) == 0 &&
			lstrcmp (dnp0->pszUserName, dnp->pszUserName) == 0)
		{
			dldSame = d;
			break;
		}
	}

	_DldsMgr.UnlockList (true);

	if (dldSame != NULL)
	{
		UINT nRet = IDCANCEL;

		if (bShowUI)
		{
			CDownloadAlrExistsDlg dlg;

			dlg.m_dld = dldSame;
			dlg.m_bNeedTopMost = bNeedTopMost;

			_DlgMgr.OnDoModal (&dlg);
			nRet = dlg.DoModal ();
			_DlgMgr.OnEndDialog (&dlg);
		}

		switch (nRet)
		{
		case IDC_RESUME:
			if (dldSame->pMgr->GetDownloadMgr ()->IsRunning () == FALSE)
			{
				DLDS_LIST v;
				v.push_back (dldSame);
				_DldsMgr.StartDownloads (v, TRUE);
			}
			break;

		case IDC_RESTART:
			{
				if (cddlg != NULL)
				{
					
					fsDownload_NetworkProperties* props = dldSame->pMgr->GetDownloadMgr()->GetDNP();
					
					if (cddlg->m_pszCookies != NULL)
					{
						props->pszCookies = new char[strlen(cddlg->m_pszCookies)+1];
						strcpy(props->pszCookies, cddlg->m_pszCookies);
					}
					
					if (cddlg->m_pszPostData != NULL)
					{
						props->pszPostData = new char[strlen(cddlg->m_pszPostData)+1];
						strcpy(props->pszPostData, cddlg->m_pszPostData);
					}
				}

				_pwndDownloads->RestartDownload (dldSame, TRUE);
				break;
			}
		case IDC_LAUNCH:
			if (dldSame->pMgr->GetDownloadMgr ()->IsDone ())
				ShellExecute (::GetDesktopWindow (), "open", dldSame->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, 
				NULL, NULL, SW_SHOW);
			break;

		case IDCANCEL:
			return 2;
		}

		return 1;
	}

	return 0;
}

void CCreateDownloadDlg::OnMirrors() 
{
	DLDS_LIST v;
	v.push_back (m_dld);

	GetDlgItemText (IDC_URL, m_strUrl);
	fsURL url;
	if (url.Crack (m_strUrl) != IR_SUCCESS || *url.GetHostName () == 0 || *url.GetPath () == 0)
	{
		WrongURL ();
		return;
	}

	if (FALSE == ReadDNP ())
		return;

	m_dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol = fsSchemeToNP (url.GetInternetScheme ());

	CDownloadPropertiesSheet sheet (LS (L_MIRRORS), this);
	sheet.Init (&v, DPS_SHP_MIRRORS);
    _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);	
}

fsSiteInfo* CCreateDownloadDlg::_SavePassword(LPCSTR pszServer, fsNetworkProtocol np, LPCSTR pszUser, LPCSTR pszPwd)
{
	if (pszUser == NULL || *pszUser == 0)
		return NULL;

	if (_App.SM_KeepPasswords () && _App.SM_PwdsManualAddition () == FALSE)
	{
		fsSiteInfo *site = _SitesMgr.FindSite (pszServer, fsNPToSiteValidFor (np));

		if (site == NULL || site->strUser != pszUser || site->strPassword != pszPwd)
		{
			CDlg_SavePassword dlg;
			if (IDOK == _DlgMgr.DoModal (&dlg))
			{
				if (site)
				{
					site->strUser = pszUser;  
					site->strPassword = pszPwd;
					site->bTemp = FALSE;
					_SitesMgr.SiteUpdated (site);
					_SitesMgr.setDirty();
				}
				else
				{
					fsSiteInfoPtr site; site.CreateInstance ();
					site->strName = pszServer;
					site->pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
					site->dwFtpFlags = FTP_USEPASSIVEMODE;
					site->cConnsNow = 0;
					site->cMaxConns = UINT_MAX;
					site->dwValidFor = fsNPToSiteValidFor (np) | SITE_VALIDFOR_SUBDOMAINS;
					site->strUser = pszUser;
					site->strPassword = pszPwd;
					site->bTemp = FALSE;
					_SitesMgr.AddSite (site);
					return site;
				}
			}
		}
	}

	return NULL;
}

void CCreateDownloadDlg::OnSelchangeDldtype() 
{
	UpdateEnabled ();	
}

fsSiteInfo* CCreateDownloadDlg::_SavePassword(vmsDownloadSmartPtr dld)
{
	fsDownload_NetworkProperties *dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();
	fsSiteInfo* site = _SavePassword (dnp->pszServerName, dnp->enProtocol, 
		dnp->pszUserName, dnp->pszPassword);
	if (site) 
	{
		site->dwFtpFlags = dnp->dwFtpFlags;
		site->pGroup = dld->pGroup;
		_SitesMgr.SiteUpdated (site);
		_SitesMgr.setDirty();
	}

	return site;
}

void CCreateDownloadDlg::OnMalicious() 
{
	GetDlgItemText (IDC_URL, m_strUrl);

	vmsMaliciousDownloadChecker mdc;
	fsInternetResult ir = mdc.Check (m_strUrl);
	if (ir != IR_SUCCESS)
	{
		char sz [1000];
		fsIRToStr (ir, sz, sizeof (sz));
		MessageBox (sz, LS (L_ERR), MB_ICONERROR);
		return;
	}

	GetDlgItem (IDC_MALICIOUS)->EnableWindow (FALSE);

	int nPerc = MulDiv (mdc.get_MaliciousOpinionCount (), 100, mdc.get_OpinionTotalCount ());
	if (nPerc < _App.Community_MalReportsMinPerc ())
	{
		m_dld->dwFlags |= DLD_MALICIOUS_NO;

		if (_App.View_DontShowMalOpinionOKReport () == FALSE)
		{
			UINT nRet = MyMessageBox (this, LS (L_NO_USERS_MAL_REPS), LS (L_DONE),
				LS (L_DONTSHOWTHISWINDOWAGAIN), IDI_INFORMATION); 
			if (nRet & 0x00010000)
				_App.View_DontShowMalOpinionOKReport (TRUE);
		}
		
		return;
	}

	m_dld->dwFlags |= DLD_MALICIOUS_YES;

	CString str;
	str.Format (LS (L_THEREAREMALOPINIONS), mdc.get_MaliciousOpinionCount (),
		mdc.get_OpinionTotalCount (), 2, mdc.get_AverageRating ());
	if (IDC_BTN2 == MyMessageBox (this, str, LS (L_WARNING), NULL, IDI_WARNING, LS (L_YES), LS (L_NO)))
		return;

	CDlg_Opinions dlg;
	dlg.m_pszUrl = m_strUrl;
	if (IDC_ABORT == _DlgMgr.DoModal (&dlg))
		EndDialog (IDCANCEL);
}

void CCreateDownloadDlg::OnOutfolderSetdefault() 
{
	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	_SetDownloadOutputFolderAsDefault (this, strOutFolder, m_wndGroups.GetSelectedGroup ());
}

BOOL CCreateDownloadDlg::_SetDownloadOutputFolderAsDefault(CWnd *pwndParent, LPCSTR pszFolder, vmsDownloadsGroupSmartPtr pGroup)
{
	CMyMessageBox dlg (pwndParent);
	dlg.m_hIcon = LoadIcon (NULL, IDI_QUESTION);
	dlg.m_strBtn1Text = LS (L_YES);
	dlg.m_strBtn2Text = LS (L_NO);
	dlg.m_strCheckBoxText = LS (L_SETASDEFFORALLGROUPS);

	dlg.m_strText.Format (LS (L_OKTOSETFOLDERASDEFFORGRP), pGroup->strName);

	dlg.m_strTitle = LS (L_CONFIRMATION);

	dlg.m_bChecked = FALSE != _App.View_SetOutputFolderAsDefForAllGrpsChecked ();

	if (IDC_BTN1 != _DlgMgr.DoModal (&dlg))
		return FALSE;

	_App.View_SetOutputFolderAsDefForAllGrpsChecked (dlg.m_bChecked);

	CString strFolder;
	if (pszFolder [lstrlen (pszFolder) - 1] != '\\' &&
			pszFolder [lstrlen (pszFolder) - 1] != '/')
	{
		strFolder = pszFolder;
		strFolder += '\\';
		pszFolder = strFolder;
	}

	if (dlg.m_bChecked)
	{
		for (size_t i = 0; i < _DldsGrps.GetTotalCount (); i++) {
			_DldsGrps.GetGroup (i)->strOutFolder = pszFolder;
			_DldsGrps.GetGroup (i)->setDirty();
			
		}

		
		
		
		
	}
	else
	{
		pGroup->strOutFolder = pszFolder;
		pGroup->setDirty();
		
		
		
	}

	return TRUE;
}

BOOL CCreateDownloadDlg::_CheckFileName(CDialog *pdlg, UINT nIdCtrl)
{
	CString str;
	pdlg->GetDlgItemText (nIdCtrl, str);
	LPCSTR pszInvChars = "\\/:*?\"<>|";
	if (str.FindOneOf (pszInvChars) != -1)
	{
		pdlg->MessageBox (LS (L_INVFILENAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		pdlg->GetDlgItem (nIdCtrl)->SetFocus ();
		return FALSE;
	}

	return TRUE;
}

BOOL CCreateDownloadDlg::_CheckFolderName(CDialog *pdlg, UINT nIdCtrl)
{
	CString str;
	pdlg->GetDlgItemText (nIdCtrl, str);
	LPCSTR pszInvChars = ":*?\"<>|";
	if (str.GetLength () > 2 && str [1] == ':')
		str.Delete (1);	
	if (str.FindOneOf (pszInvChars) != -1)
	{
		pdlg->MessageBox (LS (L_INVFOLDERNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		pdlg->GetDlgItem (nIdCtrl)->SetFocus ();
		return FALSE;
	}

	return TRUE;
}
