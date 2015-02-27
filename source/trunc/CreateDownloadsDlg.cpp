/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "CreateDownloadsDlg.h"
#include "CreateDownloadDlg.h"
#include "HFE_FileList.h"
#include "DownloadsWnd.h"
#include "GroupDlg.h"
#include "FolderBrowser.h"
#include "ScheduleSheet.h"
#include "inetutil.h"
#include "DownloadPropertiesSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDownloadsWnd* _pwndDownloads;

CCreateDownloadsDlg::CCreateDownloadsDlg(CWnd* pParent )
	: CDialog(CCreateDownloadsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateDownloadsDlg)
	//}}AFX_DATA_INIT
	m_bSort = TRUE;
	m_pGroup = NULL;
}

void CCreateDownloadsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateDownloadsDlg)
	DDX_Control(pDX, IDC_OUTFOLDER_SETDEFAULT, m_btnOutFolderSetDefault);
	DDX_Control(pDX, IDC_GROUPS, m_wndGroups);
	DDX_Control(pDX, IDC_SETTIME, m_btnSetTime);
	DDX_Control(pDX, IDC_CHOOSEFOLDER, m_btnChooseFolder);
	DDX_Control(pDX, IDC_CREATEGROUP, m_btnCreateGroup);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_FILES, m_wndFiles);
}

BEGIN_MESSAGE_MAP(CCreateDownloadsDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateDownloadsDlg)
	ON_CBN_SELCHANGE(IDC_GROUPS, OnSelchangeGroups)
	ON_BN_CLICKED(IDC_CREATEGROUP, OnCreategroup)
	ON_BN_CLICKED(IDC_CHOOSEFOLDER, OnChoosefolder)
	ON_BN_CLICKED(IDC_SETTIME, OnSettime)
	ON_BN_CLICKED(IDC_ADVANCED, OnAdvanced)
	ON_BN_CLICKED(IDC_STARTNOW, OnStartnow)
	ON_BN_CLICKED(IDC_STARTMANUAL, OnStartmanual)
	ON_BN_CLICKED(IDC_STARTSCHEDULE, OnStartschedule)
	ON_NOTIFY(TVN_SELCHANGED, IDC_FILES, OnSelchangedFiles)
	ON_BN_CLICKED(IDC_SELECTFOLDER, OnSelectfolder)
	ON_BN_CLICKED(IDC_UNSELECTFOLDER, OnUnselectfolder)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_WHATISTHIS, OnWhatisthis)
	ON_WM_HELPINFO()
	ON_BN_CLICKED(IDC_OUTFOLDER_SETDEFAULT, OnOutfolderSetdefault)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CCreateDownloadsDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

	

	m_btnChooseFolder.SetIcon (SICO (IDI_CHOOSEFOLDER));
	m_btnCreateGroup.SetIcon (SICO (IDI_CREATEGROUP));
	m_btnSetTime.SetIcon (SICO (IDI_SETTIME));
	m_btnOutFolderSetDefault.SetIcon (SICO (IDI_SETFOLDERDEFAULT));

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

	CBitmap bmp; bmp.Attach (SBMP (IDB_CHECKS));
	BITMAP bm; bmp.GetBitmap (&bm);
	m_checks.Create (15, bm.bmHeight, ILC_COLOR24|ILC_MASK, 3, 1);
	m_checks.Add (&bmp, RGB (255, 0, 255));
	m_wndFiles.SetImageList (&m_checks, TVSIL_STATE);

	
	AddToList (m_pFileList, TVI_ROOT);
	
	BuildDownloads (m_pFileList, m_strRootUrl);

	if (m_bSort)
	{
		TVSORTCB sort;
		sort.hParent = TVI_ROOT;
		sort.lParam = 0;
		sort.lpfnCompare = CHFE_FileList::_SortFunc;
		m_wndFiles.SortChildrenCB (&sort);
	}

	m_wndGroups.SelectGroupById (_App.NewDL_GroupId ());

	OnSelchangeGroups ();

	ReadAutostart ();
	UpdateEnabled ();
	ApplyLanguage ();
	
	return TRUE;
}

void CCreateDownloadsDlg::AddToList(fs::tree <fsFileInfo*>* pTree, HTREEITEM hWhere)
{
	fs::tree <fsFileInfo*> *pCur = pTree;
	
	while (pCur)
	{
		fsFileInfo *file = pCur->Data ();
		HTREEITEM hItem = m_wndFiles.InsertItem (TVIF_TEXT|TVIF_PARAM, file->strName, 
			0, 0, 0, 0, (LPARAM) file, hWhere, TVI_LAST);
		m_wndFiles.SetCheck (hItem);	

		if (pCur->Right ())	
			AddToList (pCur->Right (), hItem);	

		pCur = pCur->Left ();
	}
}

void CCreateDownloadsDlg::OnSelchangeGroups() 
{
	SetDlgItemText (IDC_OUTFOLDER, m_wndGroups.GetSelectedGroup ()->strOutFolder);
}

void CCreateDownloadsDlg::OnCreategroup() 
{
	if (m_wndGroups.CreateNewGroup (m_wndGroups.GetSelectedGroup ()))
		OnSelchangeGroups ();
}

void CCreateDownloadsDlg::OnChoosefolder() 
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

void CCreateDownloadsDlg::OnSettime() 
{
	CScheduleSheet sheet (LS (L_SCHEDULEDLDS), this);

	sheet.Init (&m_schScheduleParam.schTask, FALSE);
	
	_DlgMgr.OnDoModal (&sheet);

	if (IDOK == sheet.DoModal ())
	{
		CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
	}

    _DlgMgr.OnEndDialog (&sheet);
	GetDlgItem (IDC_STARTSCHEDULE)->SetFocus ();
}

void CCreateDownloadsDlg::OnAdvanced() 
{
	CDownloadPropertiesSheet sheet (LS (L_ADVANCED), this);
	sheet.Init (&m_vpDlds, DPS_SHP_NOGENERALNOMIRR);
    _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);
}

void CCreateDownloadsDlg::BuildDownloads(fs::tree <fsFileInfo*>* pTree, LPCSTR pszRootUrl)
{
	fs::tree <fsFileInfo*> *pCur = pTree;
	
	while (pCur)
	{
		fsFileInfo *file = pCur->Data ();

		CString strUrl;	

		char* pszRes;

		fsUrlToFullUrl (pszRootUrl, file->strName, &pszRes);

		strUrl = pszRes;
		delete [] pszRes;
		
		if (pCur->Right ())	
		{
			if (strUrl [strUrl.GetLength () - 1] != '/')	
				strUrl += '/';				
			BuildDownloads (pCur->Right (), strUrl);	
		}
		else if (file->bFolder == FALSE)	
		{
			
			vmsDownloadSmartPtr dld;
			Download_CreateInstance (dld);
			
			dld->pMgr->GetDownloadMgr ()->CreateByUrl (strUrl);
			m_vpDlds.push_back (dld);
		}

		pCur = pCur->Left ();	
	}
}

CCreateDownloadsDlg::~CCreateDownloadsDlg()
{
	
}

void CCreateDownloadsDlg::UpdateEnabled()
{
	HTREEITEM hItem = m_wndFiles.GetSelectedItem ();
	BOOL b = hItem && m_wndFiles.ItemHasChildren (hItem);
	GetDlgItem (IDC_SELECTFOLDER)->EnableWindow (b);
	GetDlgItem (IDC_UNSELECTFOLDER)->EnableWindow (b);
}

void CCreateDownloadsDlg::OnStartnow() 
{
	UpdateEnabled ();
	m_iAutostart = 0;
}

void CCreateDownloadsDlg::OnStartmanual() 
{
	UpdateEnabled ();	
	m_iAutostart = 1;
}

void CCreateDownloadsDlg::OnStartschedule() 
{
	UpdateEnabled ();	
	m_iAutostart = 2;
}

void CCreateDownloadsDlg::OnOK() 
{
	

	CString strFolder;
	GetDlgItemText (IDC_OUTFOLDER, strFolder);
	if (strFolder == "")
	{
		MessageBox (LS (L_ENTERFLRNAME), LS (L_INPERR), MB_ICONEXCLAMATION);
		GetDlgItem (IDC_OUTFOLDER)->SetFocus ();
		return;
	}

	if (FALSE == CCreateDownloadDlg::_CheckFolderName (this, IDC_OUTFOLDER))
		return;

	fsPathToGoodPath ((LPSTR)(LPCSTR)strFolder);

	_LastFolders.AddRecord (strFolder);
	if (strFolder [strFolder.GetLength () - 1] != '\\' && 
		strFolder [strFolder.GetLength () - 1] != '/')
		strFolder += '\\';

	m_wndGroups.RememberSelectedGroup ();
	m_bAutoStart = IsDlgButtonChecked (IDC_STARTNOW) == BST_CHECKED;

	m_pGroup = m_wndGroups.GetSelectedGroup ();

	
	CreateDownloads (TVI_ROOT, strFolder, TRUE);

	BOOL bScheduled = IsDlgButtonChecked (IDC_STARTSCHEDULE) == BST_CHECKED;

	
	_pwndDownloads->CreateDownloads (m_vpDldsToStart, bScheduled ? &m_schScheduleParam.schTask : NULL);

	BOOL bUseZipPreview = _App.NewDL_UseZIPPreview ();

	for (size_t i = 0; i < m_vpDldsToStart.size (); i++)
	{
		if (bUseZipPreview)
			m_vpDldsToStart [i]->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_USEZIPPREVIEW;
		else
			m_vpDldsToStart [i]->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags &= ~DPF_USEZIPPREVIEW;
		m_vpDldsToStart [i]->pMgr->GetDownloadMgr ()->setDirty();
	}

	_App.Last_Autostart (m_iAutostart);
	_App.UseZipPreview (bUseZipPreview);
	
	CDialog::OnOK();
}

void CCreateDownloadsDlg::CreateDownloads(HTREEITEM hTree, LPCSTR pszRootDir, BOOL bCreate)
{
	static int nDld;	

	if (hTree == NULL)
		return;
	
	if (hTree == TVI_ROOT)	
		nDld = 0;	

	

	HTREEITEM hCur = m_wndFiles.GetChildItem (hTree);

	while (hCur)
	{
		fsFileInfo* file = (fsFileInfo*) m_wndFiles.GetItemData (hCur);

		CString strDir;	

		strDir = pszRootDir;
		
		if (m_wndFiles.ItemHasChildren (hCur))	
		{
			strDir += file->strName;

			if (strDir [strDir.GetLength () - 1] != '\\' || strDir [strDir.GetLength () - 1] != '/')
				strDir += '\\'; 
			BOOL b = m_wndFiles.IsChecked (hCur);	
			CreateDownloads (hCur, strDir, b && bCreate);	
		}
		else if (file->bFolder == FALSE) 
		{	
			if (m_wndFiles.IsChecked (hCur) && bCreate)	
			{
				vmsDownloadSmartPtr dld = m_vpDlds [nDld];
				dld->pGroup = m_pGroup;
				dld->bAutoStart = m_bAutoStart;
				fsDownload_Properties *dp = dld->pMgr->GetDownloadMgr ()->GetDP ();
				fsnew (dp->pszFileName, char, strDir.GetLength () + 1);
				strcpy (dp->pszFileName, strDir);

				m_vpDldsToStart.push_back (dld);
			}

			nDld++;
		}

		hCur = m_wndFiles.GetNextItem (hCur, TVGN_NEXT);
	}
}

void CCreateDownloadsDlg::OnSelchangedFiles(NMHDR* , LRESULT* pResult) 
{
	
	UpdateEnabled ();	
	*pResult = 0;
}

void CCreateDownloadsDlg::OnSelectfolder() 
{
	
	

	HTREEITEM hItem = m_wndFiles.GetSelectedItem ();
	hItem = m_wndFiles.GetChildItem (hItem);
	while (hItem)
	{
		m_wndFiles.SetCheck (hItem, TRUE);
		hItem = m_wndFiles.GetNextItem (hItem, TVGN_NEXT);
	}
}

void CCreateDownloadsDlg::OnUnselectfolder() 
{
	
	

	HTREEITEM hItem = m_wndFiles.GetSelectedItem ();
	hItem = m_wndFiles.GetChildItem (hItem);
	while (hItem)
	{
		m_wndFiles.SetCheck (hItem, FALSE);
		hItem = m_wndFiles.GetNextItem (hItem, TVGN_NEXT);
	}
}

void CCreateDownloadsDlg::OnContextMenu(CWnd* , CPoint point) 
{
	PrepareCHMgr (point);
	_CHMgr.ShowMenu ();
}

void CCreateDownloadsDlg::OnWhatisthis() 
{
	_CHMgr.OnWT ();	
}

void CCreateDownloadsDlg::ApplyLanguage()
{
	fsDlgLngInfo lnginfo [] =  {
		fsDlgLngInfo (IDC__SAVETO, L_SAVETO),
		fsDlgLngInfo (IDC__START, L_START),
		fsDlgLngInfo (IDC_STARTNOW, L_AUTOMATICALLY),
		fsDlgLngInfo (IDC_STARTMANUAL, L_MANUALLY),
		fsDlgLngInfo (IDC_STARTSCHEDULE, L_SCHEDULE),
		fsDlgLngInfo (IDC__GROUP, L_GROUP),
		fsDlgLngInfo (IDC_ADVANCED, L_ADVANCED),
		fsDlgLngInfo (IDCANCEL, L_CANCEL),
		fsDlgLngInfo (IDC__LIST, L_LISTOFDLDS),
		fsDlgLngInfo (IDC_SELECTFOLDER, L_SELECTCONTENT),
		fsDlgLngInfo (IDC_UNSELECTFOLDER, L_UNSELECTCONTENT),
	};

	_LngMgr.ApplyLanguage (this, lnginfo, sizeof (lnginfo) / sizeof (fsDlgLngInfo), L_CREATEDLDS);
}

void CCreateDownloadsDlg::ReadAutostart()
{
	m_iAutostart = _App.Last_Autostart ();

	switch (m_iAutostart)
	{
		case 0:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTNOW);
			break;

		case 1:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTMANUAL);
			break;

		case 2:
			CheckRadioButton (IDC_STARTNOW, IDC_STARTSCHEDULE, IDC_STARTSCHEDULE);
			break;
	}
}

BOOL CCreateDownloadsDlg::OnHelpInfo(HELPINFO* pHelpInfo) 
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

void CCreateDownloadsDlg::PrepareCHMgr(CPoint point)
{
	fsCtrlContextHelp aCH1 [] = {
		fsCtrlContextHelp (IDC__GROUP, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC_GROUPS, LS (L_GROUPHERE)),
		fsCtrlContextHelp (IDC_CREATEGROUP, LS (L_CREATEGRP)),
		fsCtrlContextHelp (IDC__SAVETO, LS (L_DLDFOLDERHERE)),
		fsCtrlContextHelp (IDC_CHOOSEFOLDER, LS (L_BROWSEFOR)),
		fsCtrlContextHelp (IDC_STARTNOW, LS (L_STARTNOWHERE)),
		fsCtrlContextHelp (IDC_STARTMANUAL, LS (L_MANUALLYSTARTHERE)),
		fsCtrlContextHelp (IDC_STARTSCHEDULE, LS (L_SCHEDULESTARTHERE)),
		fsCtrlContextHelp (IDC_SETTIME, LS (L_SETTIMEHERE)),
		fsCtrlContextHelp (IDC_ADVANCED, LS (L_ADVANCEDHERE)),
		fsCtrlContextHelp (IDOK, LS (L_ACCEPTCHANGES)),
		fsCtrlContextHelp (IDCANCEL, LS (L_DONTACCEPTCHANGES)),
		fsCtrlContextHelp (IDC__LIST, LS (L_LISTOFDLDSHERE)),
		fsCtrlContextHelp (IDC_FILES, LS (L_LISTOFDLDSHERE)),
		fsCtrlContextHelp (IDC_SELECTFOLDER, LS (L_SELFOLDERHERE)),
		fsCtrlContextHelp (IDC_UNSELECTFOLDER, LS (L_UNSELFOLDERHERE)),
	};

    static fsCtrlContextHelp aCH [sizeof (aCH1) / sizeof (fsCtrlContextHelp)];
	CopyMemory (aCH, aCH1, sizeof (aCH));

	_CHMgr.PrepareContextMenu (this, point, aCH, sizeof (aCH) / sizeof (fsCtrlContextHelp));	
}

void CCreateDownloadsDlg::OnOutfolderSetdefault() 
{
	CString strOutFolder;
	GetDlgItemText (IDC_OUTFOLDER, strOutFolder);

	CCreateDownloadDlg::_SetDownloadOutputFolderAsDefault (this, strOutFolder, 
		m_wndGroups.GetSelectedGroup ());	
}
