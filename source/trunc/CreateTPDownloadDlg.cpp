/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CreateTPDownloadDlg.h"
#include "DownloadsWnd.h"
#include "inetutil.h"
#include "GroupDlg.h"
#include "FolderBrowser.h"
#include "DownloadAlrExistsDlg.h"
#include "MyMessageBox.h"
#include "vmsLogger.h"

extern CDownloadsWnd *_pwndDownloads;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CCreateTPDownloadDlg::CCreateTPDownloadDlg(vmsDownloadSmartPtr dld, CWnd* pParent )
	: CDialog(CCreateTPDownloadDlg::IDD, pParent), m_dld (dld)
{
	//{{AFX_DATA_INIT(CCreateTPDownloadDlg)
	//}}AFX_DATA_INIT
	m_bSetSaveAs = TRUE;
	m_bPlaceAtTop = false;
	m_strUrl = dld->pMgr->get_URL ();
	m_bThread = FALSE;
	m_bNeedExit = FALSE;
}

void CCreateTPDownloadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateTPDownloadDlg)
	DDX_Control(pDX, IDC_OUTFOLDER_SETDEFAULT, m_btnOutFolderSetDefault);
	DDX_Control(pDX, IDC_DLDTYPE, m_wndDldType);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	DDX_Control (pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_STRSPEED_SPIN, m_wndSpin);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateTPDownloadDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateTPDownloadDlg)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_OUTFOLDER_SETDEFAULT, OnOutfolderSetdefault)
	ON_CBN_EDITCHANGE(IDC_URL, OnEditchangeUrl)
	ON_CBN_SELCHANGE(IDC_URL, OnSelchangeUrl)
	ON_BN_CLICKED(IDOK, OnOk)
	ON_CBN_SELCHANGE(IDC_DLDTYPE, OnSelchangeDldtype)
	ON_BN_CLICKED(IDCANCEL, OnCancel)
	ON_EN_CHANGE(IDC_SAVEAS, OnChangeSaveas)
	ON_BN_CLICKED(IDC_FILEAUTO, OnFileauto)
	ON_BN_CLICKED(IDC_QSIZE, OnQsize)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CCreateTPDownloadDlg::OnInitDialog() 
{
	

	CDialog::OnInitDialog();

	SetDlgItemText (IDC_URL, m_strUrl);
	CHAR szFile [10000];
	*szFile = 0;
	fsFileNameFromUrlPath (m_strUrl, FALSE, TRUE, szFile, sizeof (szFile));

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
	m_btnOutFolderSetDefault.SetIcon (SICO (IDI_SETFOLDERDEFAULT));

	m_wndGroups.Fill ();

	CComboBox *pUrls = (CComboBox*) GetDlgItem (IDC_URL);
	int i = 0;
	for (i = 0; i < _LastUrlFiles.GetRecordCount (); i++)
		pUrls->AddString (_LastUrlFiles.GetRecord (i));

	CComboBox *pDirs = (CComboBox*) GetDlgItem (IDC_OUTFOLDER);
	for (i = 0; i < _LastFolders.GetRecordCount (); i++)
		pDirs->AddString (_LastFolders.GetRecord (i));

	m_bGroupChanged = m_bAuthChanged = FALSE;

	SetDlgItemInt (IDC_STRSPEED, 1);
	m_wndSpin.SetRange (1, 10);
	
	GetDlgItem (IDC_URL)->SetFocus ();
	UrlChanged ();

	if (strlen(szFile) == 0)
	{
		
		CString strDateTime;
		SYSTEMTIME systime;
		GetLocalTime (&systime);
		char szDate [100], szTime [100];
		GetDateFormat (LOCALE_USER_DEFAULT, 0, &systime, "yyyy-MM-dd", szDate, 100);
		GetTimeFormat (LOCALE_USER_DEFAULT, 0, &systime, "HHmmss", szTime, 100);
		strDateTime = szDate; strDateTime += " "; strDateTime += szTime; strDateTime += ".asf";
		SetDlgItemText (IDC_SAVEAS, strDateTime);
	}
	else
	{
		if (strchr(szFile, '.') == 0)
		 strcat(szFile, ".asf");
		SetDlgItemText (IDC_SAVEAS, szFile);
	}
	

	ApplyLanguage ();

	m_bGroupChanged = FALSE;

	if (m_pGroup == NULL)
		m_pGroup = _DldsGrps.FindGroup (_App.NewDL_GroupId ());

	if (m_pGroup != NULL && m_wndGroups.SelectGroup (m_pGroup))
	{
		m_bGroupChanged = TRUE;
		OnChangeGroups ();
	}

	m_wndDldType.AddString (LS (L_SAVEFILE));
	m_wndDldType.AddString (LS (L_OPENFILE));
	m_wndDldType.AddString (LS (L_SAVEFILEANDOPENIT));
	m_wndDldType.SetCurSel (0);

	CheckDlgButton (IDC_FILEAUTO, _App.NewDL_GenerateNameAutomatically () ? BST_CHECKED : BST_UNCHECKED);
	OnFileauto ();

	UpdateEnabled ();

	return TRUE;
}

void CCreateTPDownloadDlg::OnChangeSaveas() 
{
	m_bSetSaveAs = FALSE;
}

void CCreateTPDownloadDlg::UpdateEnabled()
{
	int nSel = m_wndDldType.GetCurSel ();
	GetDlgItem (IDC__SAVETO)->EnableWindow (nSel != 1);
	GetDlgItem (IDC_OUTFOLDER)->EnableWindow (nSel != 1);
	GetDlgItem (IDC_CHOOSEFOLDER)->EnableWindow (nSel != 1);
	GetDlgItem (IDC_FILEAUTO)->EnableWindow (nSel != 1);

	BOOL b = nSel != 1 && IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED;
	GetDlgItem (IDC__SAVEAS)->EnableWindow (b);
	GetDlgItem (IDC_SAVEAS)->EnableWindow (b);
}

void CCreateTPDownloadDlg::OnSelchangeGroups() 
{
	OnChangeGroups ();
	m_bGroupChanged = TRUE;
}

void CCreateTPDownloadDlg::WrongURL()
{
	MessageBox (LS (L_CHECKURL), LS (L_INPERR), MB_ICONEXCLAMATION);
	GetDlgItem (IDC_URL)->SetFocus ();
}

void CCreateTPDownloadDlg::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
	{
		OnChangeGroups ();
	}
}

void CCreateTPDownloadDlg::OnChoosefolder() 
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

void CCreateTPDownloadDlg::UrlChanged()
{
	SetDlgItemText (IDC_QSIZE, LS (L_QUERYSIZE));
	if (m_bThread) m_bNeedExit = TRUE;
	if (IR_SUCCESS != Crack(m_strUrl))
	{
		GetDlgItem (IDC_QSIZE)->EnableWindow (FALSE);
		return;
	}

	CHAR szFile [10000];
	*szFile = 0;

	m_bUrlChanged = TRUE;

	if (m_dld->dwFlags & (DLD_MALICIOUS_NO | DLD_MALICIOUS_YES))
	{
		GetDlgItem (IDC_MALICIOUS)->EnableWindow (TRUE);
		m_dld->dwFlags &= ~ (DLD_MALICIOUS_NO | DLD_MALICIOUS_YES);
	}

	if (m_bGroupChanged == FALSE)
	{
		fsFileNameFromUrlPath (m_strUrl, FALSE, TRUE, szFile, sizeof (szFile));

		int len = strlen (szFile);
		vmsDownloadsGroupSmartPtr grp;

		if (len)
		{
			if (strchr(szFile, '.') == 0)
				strcat(szFile, ".asf");
			SetDlgItemText (IDC_SAVEAS, szFile);

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
	bool bRtsp = (m_strUrl.Find("rtsp://") != -1);
	GetDlgItem (IDC_STRSPEED)->EnableWindow(bRtsp);
	GetDlgItem (IDC_STRSPEED_SPIN)->EnableWindow(bRtsp);
	GetDlgItem (IDC_QSIZE)->EnableWindow ();
}

void CCreateTPDownloadDlg::OnChangeGroups()
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);
}

void CCreateTPDownloadDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC_USELOGIN, L_AUTHORIZATION),
		fsDlgLngInfo (IDC__SAVETO, L_SAVETO),
		fsDlgLngInfo (IDC__SAVEAS, L_SAVEAS),
		fsDlgLngInfo (IDC__START, L_START),
		fsDlgLngInfo (IDC_STARTNOW, L_AUTOMATICALLY),
		fsDlgLngInfo (IDC_STARTMANUAL, L_MANUALLY),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC_FILEAUTO, L_FILEAUTO),
		fsDlgLngInfo (IDC__DLDTYPE, L_DLDTYPE),
		fsDlgLngInfo (IDC__STRSPEED, L_SPEED),
		fsDlgLngInfo (IDC_PLACEATTOP, L_PLACEDLDATTOP),
		fsDlgLngInfo (IDC_QSIZE, L_QUERYSIZE),
	};

	CString str = LS (L_COMMENT); str += ':';
	SetDlgItemText (IDC__COMMENT, str);

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_NEWDLD);
}

void CCreateTPDownloadDlg::OnFileauto() 
{
	CString str;
	GetDlgItemText (IDC_SAVEAS, str);
	if (str == "" && IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED)
	{

	}

	UpdateEnabled ();
}

int CCreateTPDownloadDlg::_CheckDownloadAlrExists(vmsDownloadSmartPtr dld, BOOL bNeedTopMost, BOOL bShowUI)
{
	fsURL url1, url2;

	if (dld->pMgr->GetTpDownloadMgr () == NULL)
		return 0;

	for (size_t i = 0; i < _DldsMgr.GetCount (); i++)
	{
		vmsDownloadSmartPtr d = _DldsMgr.GetDownload (i);
		if (d->pMgr->GetTpDownloadMgr () == NULL)
			continue;
		
		if (m_strUrl == d->pMgr->GetTpDownloadMgr ()->get_URL())
		{
			UINT nRet = IDCANCEL;

			if (bShowUI)
			{
				CDownloadAlrExistsDlg dlg;

				dlg.m_dld = d;
				dlg.m_bNeedTopMost = bNeedTopMost;

				_DlgMgr.OnDoModal (&dlg);
				nRet = dlg.DoModal ();
				_DlgMgr.OnEndDialog (&dlg);
			}

			switch (nRet)
			{
				case IDC_RESUME:
					if (d->pMgr->GetTpDownloadMgr ()->IsRunning () == FALSE)
					{
						DLDS_LIST v;
						v.push_back (d);
						_DldsMgr.StartDownloads (v, TRUE);
					}
					break;

				case IDC_RESTART:
					_pwndDownloads->RestartDownload (d, TRUE);
					break;

				case IDC_LAUNCH:
					if (d->pMgr->GetDownloadMgr ()->IsDone ())
						ShellExecute (::GetDesktopWindow (), "open", d->pMgr->GetTpDownloadMgr ()->get_OutputFilePathName() , 
							NULL, NULL, SW_SHOW);
					break;

				case IDCANCEL:
					return 2;
			}

			return 1;
		}
			
	}

	return 0;
}

void CCreateTPDownloadDlg::OnOutfolderSetdefault() 
{
	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	_SetDownloadOutputFolderAsDefault (this, strOutFolder, m_wndGroups.GetSelectedGroup ());
}

BOOL CCreateTPDownloadDlg::_SetDownloadOutputFolderAsDefault(CWnd *pwndParent, LPCSTR pszFolder, vmsDownloadsGroupSmartPtr pGroup)
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

BOOL CCreateTPDownloadDlg::_CheckFileName(CDialog *pdlg, UINT nIdCtrl)
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

BOOL CCreateTPDownloadDlg::_CheckFolderName(CDialog *pdlg, UINT nIdCtrl)
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

void CCreateTPDownloadDlg::OnEditchangeUrl()
{
	GetDlgItemText (IDC_URL, m_strUrl);	
	UrlChanged ();
}

void CCreateTPDownloadDlg::OnSelchangeUrl()
{
	CComboBox *pUrl = (CComboBox*) GetDlgItem (IDC_URL);
	pUrl->GetLBText (pUrl->GetCurSel (), m_strUrl);
	UrlChanged ();
}

void CCreateTPDownloadDlg::OnOk()
{
	if (IR_SUCCESS != Crack(m_strUrl))
		return WrongURL ();

	GetDlgItemText (IDC_SAVEAS, m_strFileName);

	int nDldType = m_wndDldType.GetCurSel ();

	if (nDldType == 1)	
	{
		char sz [MY_MAX_PATH];
		GetTempPath (sizeof (sz), sz);
		m_strOutFolder = sz;
	}
	else
	{
		if (FALSE == _CheckFolderName (this, IDC_OUTFOLDER))
			return;
		GetDlgItemText (IDC_OUTFOLDER, m_strOutFolder);
	
		if (IsDlgButtonChecked (IDC_FILEAUTO) == BST_UNCHECKED)
		{
			if (m_strFileName == "")
			{
				MessageBox (LS (L_EMPTY), LS (L_INPERR), MB_ICONEXCLAMATION);
				GetDlgItem (IDC_SAVEAS)->SetFocus ();
				return;
			}
			if (FALSE == _CheckFileName (this, IDC_SAVEAS))
				return;
			_App.NewDL_GenerateNameAutomatically (FALSE);
		}
		else
			_App.NewDL_GenerateNameAutomatically (TRUE);
	}

	fsPathToGoodPath ((LPSTR)(LPCSTR)m_strOutFolder);
	fsPathToGoodPath ((LPSTR)(LPCSTR)m_strFileName);

	if (m_strOutFolder.GetLength () == 0)
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	if (nDldType != 1)
		_LastFolders.AddRecord (m_strOutFolder);
	_LastUrlFiles.AddRecord (m_strUrl);

	if (m_strOutFolder [m_strOutFolder.GetLength () - 1] != '\\' && 
		m_strOutFolder [m_strOutFolder.GetLength () - 1] != '/')
		m_strOutFolder += '\\';

	if (_App.NewGrp_SelectWay () == NGSW_USE_ALWAYS_SAME_GROUP_WITH_OUTFOLDER_AUTO_UPDATE)
	{
		vmsDownloadsGroupSmartPtr pGrp = _DldsGrps.FindGroup (_App.NewDL_GroupId ());
		if (pGrp != NULL) {
			pGrp->strOutFolder = m_strOutFolder;
			pGrp->setDirty();
		}
	}
	
	if (_App.CheckIfDownloadWithSameUrlExists ())
	{
		int ret = _CheckDownloadAlrExists (m_dld);
		if (ret)
		{
			if (ret == 1)
				EndDialog (ID_DLNOTADDED);
			return;
		}
	}

	m_dld->pGroup = m_wndGroups.GetSelectedGroup ();

	GetDlgItemText (IDC_COMMENT, m_dld->strComment);

	BOOL bUseZipPreview = _App.NewDL_UseZIPPreview ();
	_App.UseZipPreview (bUseZipPreview);

	if (nDldType == 1)
	{
		m_dld->dwFlags |= DLD_DELETEWHENDONE | DLD_DELETEFILEATRESTART;
	}
	else if (nDldType == 2)
		m_dld->dwFlags |= DPF_STARTWHENDONE;

	m_wndGroups.RememberSelectedGroup ();

	m_nStreamingSpeed = GetDlgItemInt (IDC_STRSPEED);

	if (m_bThread)
	{
		m_bNeedExit = TRUE;
		while (m_bThread);
	}

	_App.OnDlHasBeenCreatedByUser ();

	m_bPlaceAtTop = IsDlgButtonChecked (IDC_PLACEATTOP) == BST_CHECKED;

	CDialog::OnOK();
}

void CCreateTPDownloadDlg::OnSelchangeDldtype()
{
	UpdateEnabled ();
}

void CCreateTPDownloadDlg::OnCancel() 
{
	
	if (m_bThread)
	{
		m_bNeedExit = TRUE;
		while (m_bThread);	
	}

	CDialog::OnCancel();
}

fsInternetResult CCreateTPDownloadDlg::Crack(LPCSTR pszUrl)
{
	CHAR m_szScheme [URL_SCHEME_SIZE];	
	CHAR m_szHost [URL_HOSTNAME_SIZE];	
	CHAR m_szUser [URL_USERNAME_SIZE];	
	CHAR m_szPassword [URL_PASSWORD_SIZE];	
	CHAR m_szPath [URL_PATH_SIZE];		

	DWORD urlLen = strlen (pszUrl) * 2;
	CHAR *pszCanUrl = NULL;
	fsString strUrl;

	
	if (*pszUrl == '"' || *pszUrl == '\'')
	{
		
		
		strUrl = pszUrl + 1;
		if (strUrl [0] == 0)
			return IR_BADURL;
		strUrl [strUrl.Length () - 1] = 0;
		m_strUrl = pszUrl = strUrl;
	}

	fsnew (pszCanUrl, CHAR, urlLen);

	
	if (!InternetCanonicalizeUrl (pszUrl, pszCanUrl, &urlLen, ICU_BROWSER_MODE))
	{
		delete pszCanUrl;

		if (GetLastError () == ERROR_INSUFFICIENT_BUFFER)
		{
			fsnew (pszCanUrl, CHAR, urlLen+1);
			if (!InternetCanonicalizeUrl (pszUrl, pszCanUrl, &urlLen, ICU_BROWSER_MODE))
			{
				delete pszCanUrl;
				return fsWinInetErrorToIR ();
			}
		}
		else
		return fsWinInetErrorToIR ();
	}

	URL_COMPONENTS m_url;
	ZeroMemory (&m_url, sizeof (m_url));
	m_url.dwStructSize = sizeof (m_url);

	m_url.lpszHostName = m_szHost;
	m_url.lpszPassword = m_szPassword;
	m_url.lpszScheme = m_szScheme;
	m_url.lpszUrlPath = m_szPath;
	m_url.lpszUserName = m_szUser;

	m_url.dwHostNameLength = URL_HOSTNAME_SIZE;
	m_url.dwPasswordLength = URL_PASSWORD_SIZE;
	m_url.dwSchemeLength = URL_SCHEME_SIZE;
	m_url.dwUrlPathLength = URL_PATH_SIZE;
	m_url.dwUserNameLength = URL_USERNAME_SIZE;

	if (!InternetCrackUrl (pszCanUrl, urlLen, 0, &m_url))
	{
		delete pszCanUrl;
		return fsWinInetErrorToIR ();
	}

	delete pszCanUrl;

	if (strstr (m_url.lpszScheme, "mmsh") == NULL 
		&& strstr (m_url.lpszScheme, "mmst") == NULL
		&& strstr (m_url.lpszScheme, "mms") == NULL
		&& strstr (m_url.lpszScheme, "rtsp") == NULL
		|| m_url.dwHostNameLength == 0)
		return IR_BADURL;

	return IR_SUCCESS;
}

void CCreateTPDownloadDlg::OnQsize()
{
	GetDlgItemText (IDC_URL, m_strUrl);
	m_bNeedExit = FALSE;
	m_bThread = TRUE;
	DWORD dw;
	CloseHandle (CreateThread (NULL, 0, _threadQSize, this, 0, &dw));
	SetDlgItemText (IDC_QSIZE, LS (L_QUERINGSIZE));
	GetDlgItem (IDC_QSIZE)->EnableWindow (FALSE);
}

DWORD WINAPI CCreateTPDownloadDlg::_threadQSize(LPVOID lp)
{
	CCreateTPDownloadDlg *pThis = (CCreateTPDownloadDlg*) lp;

	try
	{
		CString strSize;
		UINT64 uSize = 0;
		vmsTpDownloadMgr* pMgr = pThis->m_dld->pMgr->GetTpDownloadMgr ();
		if (pMgr->CreateTPDownload (pThis->m_strUrl, "", "", 1))
		{
			pMgr->StartDownloading (FALSE);

			while ((uSize = pMgr->GetTotalFilesSize ()) == 0
				&& pThis->m_bNeedExit == FALSE)
			{
				Sleep (500);
			}
			pMgr->StopDownloading ();
		}

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
					if (pMgr->GetPercentDone () == -1)
						strSize.Format ("%s", LS (L_LIVESTREAMING));
					else
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
		vmsLogger::WriteLog("CCreateTPDownloadDlg::_threadQSize " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CCreateTPDownloadDlg::_threadQSize unknown exception");
	}

	return 0;
}
