/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FlashVideoDownloadsWnd.h"
#include "plugincmds.h"
#include "Dlg_CreateFVDownload.h"
#include "DlgCreateFlvDownloads.h"
#include "DlgCreateFlvDownloadsByWebPageUrl.h"
#include "WaitDlg.h"
#include "vmsSharedData.h"
#include "MainFrm.h"
#include "FdmUiWindow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CFlashVideoDownloadsWnd *_pwndFVDownloads = NULL;

CFlashVideoDownloadsWnd::CFlashVideoDownloadsWnd()
{
	m_wndPreview.set_InFVDownloads (TRUE);
}

CFlashVideoDownloadsWnd::~CFlashVideoDownloadsWnd()
{
}

BEGIN_MESSAGE_MAP(CFlashVideoDownloadsWnd, CWnd)
	//{{AFX_MSG_MAP(CFlashVideoDownloadsWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_FVDLD_CREATE, OnFvdldCreate)
	ON_COMMAND(ID_FVDLD_AUTOSTART, OnFvdldAutostart)
	ON_COMMAND(ID_FVDLD_DELETE, OnFvdldDelete)
	ON_COMMAND(ID_FVDLD_LAUNCH, OnFvdldLaunch)
	ON_COMMAND(ID_FVDLD_OPENFOLDER, OnFvdldOpenfolder)
	ON_COMMAND(ID_FVDLD_PASSTODLDS, OnFvdldPasstodlds)
	ON_COMMAND(ID_FVDLD_PROPERTIES, OnFvdldProperties)
	ON_COMMAND(ID_FVDLD_START, OnFvdldStart)
	ON_COMMAND(ID_FVDLD_STOP, OnFvdldStop)
	ON_COMMAND(ID_FVDLD_CONVERT, OnFvdldConvert)
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)

	ON_COMMAND_RANGE(ID_DLLIST_1, ID_DLLIST_8, OnDLListShowCol)
	

	ON_MESSAGE (WM_FVDW_CREATEDOWNLOADS, OnFvdwCreateDownloads)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

BOOL CFlashVideoDownloadsWnd::Create(CWnd *pwndParent)
{
	CRect rc (0, 0, 50, 50);

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
			NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pwndParent, 0x1af))
		return FALSE;

	return TRUE;
}

HWND CFlashVideoDownloadsWnd::Plugin_CreateMainWindow(HWND hWndParent)
{
	fsnew1 (_pwndFVDownloads, CFlashVideoDownloadsWnd);

	_pwndFVDownloads->Create (CWnd::FromHandle (hWndParent));

	return _pwndFVDownloads->m_hWnd;
}

void CFlashVideoDownloadsWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_FVDLD_CREATE, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_FVDLD_START, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_FVDLD_STOP, TBSTYLE_BUTTON, ""),
	};

	btns [0].pszToolTip = LS (L_NEWDLD);
	btns [1].pszToolTip = LS (L_STARTDLDS);
	btns [2].pszToolTip = LS (L_STOPDLDS);

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

void CFlashVideoDownloadsWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_FVDLD_CREATE, 0),
		fsSetImage (ID_FVDLD_START, 1),
		fsSetImage (ID_FVDLD_STOP, 2),
		fsSetImage (ID_FVDLD_PROPERTIES, 6),
		fsSetImage (ID_FVDLD_DELETE, 7),
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

void CFlashVideoDownloadsWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int* )
{
	*ppItems = NULL;
}

void CFlashVideoDownloadsWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strName;
	strName = LSNP (L_FVDOWNLOADS);
	*ppszLong = *ppszShort = strName;
}

void CFlashVideoDownloadsWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndFVDownloads->m_wndTasks.ApplyLanguageToMenu (menu);
	_pwndFVDownloads->m_wndTasks.ApplyLanguage ();
	_pwndFVDownloads->m_wndPreview.ApplyLanguage ();
	_pwndFVDownloads->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
}

int CFlashVideoDownloadsWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	m_wndTasks.Create (this);
	m_wndPreview.Create (this);

	m_splitter.Create (AfxGetInstanceHandle (), m_hWnd, WST_HORIZONTAL);
	m_splitter.SetWnd1 (m_wndTasks.m_hWnd);
	m_splitter.SetWnd2 (m_wndPreview.m_hWnd);
	m_splitter.SetMinDimensions (50, 50);
	float fRatio = _App.View_SplitterRatio ("FVDownloads_DL_PREVIEW");
	if (fRatio < 0.1f)
		fRatio = 0.1f;
	m_splitter.SetRatio (fRatio);

	m_wndPreview.ShowWindow (SW_SHOW);

	DLDS_LIST v;

	_DldsMgr.LockList (true);
	size_t nCount = _DldsMgr.GetCount ();
	for (size_t i = 0; i < nCount; i++)
	{
		if (_DldsMgr.GetDownload (i)->dwFlags & DLD_FLASH_VIDEO)
			v.push_back (_DldsMgr.GetDownload (i));
	}
	_DldsMgr.UnlockList (true);

	for (size_t i = 0; i < v.size (); i++)
		m_wndTasks.AddDownload (v [i], TRUE);
	
	return 0;
}

void CFlashVideoDownloadsWnd::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);

	m_splitter.ApplyRatio ();

	
}

void CFlashVideoDownloadsWnd::AddDownload(vmsDownloadSmartPtr dld, BOOL bPlaceToTop)
{
	ASSERT (dld->dwFlags & DLD_FLASH_VIDEO);
	m_wndTasks.AddDownload (dld, bPlaceToTop);
}

void CFlashVideoDownloadsWnd::OnFvdldCreate() 
{
	m_wndTasks.OnFvdldCreate ();
}

void CFlashVideoDownloadsWnd::OnDownloadDone(vmsDownloadSmartPtr dld)
{
	
}

LRESULT CFlashVideoDownloadsWnd::OnInsert(WPARAM, LPARAM)
{
	m_wndTasks.OnFvdldCreate ();
	return 0;
}

LRESULT CFlashVideoDownloadsWnd::OnAppExit(WPARAM, LPARAM)
{
	SaveAll (0xffffffff);
	return 0;
}

LRESULT CFlashVideoDownloadsWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	return 0;
}

LRESULT CFlashVideoDownloadsWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	m_wndTasks.UpdateMenu (CMenu::FromHandle (*((HMENU*)lp)));
	return 0;
}

LRESULT CFlashVideoDownloadsWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	CMenu* menu = CMenu::FromHandle (pMenus [0]);

	BOOL bEn = m_wndTasks.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 8; i++)
	{
		if (m_wndTasks.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_DLLIST_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_DLLIST_1+i, MF_GRAYED);
		}
	}

	return 0;
}

LRESULT CFlashVideoDownloadsWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return m_wndTasks.OnUpdateToolBar (wp);	
}

void CFlashVideoDownloadsWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFDLDS));

	UINT aCmds [] = {ID_DLLIST_1, ID_DLLIST_2, ID_DLLIST_3, ID_DLLIST_4, ID_DLLIST_5, 
		ID_DLLIST_6, ID_DLLIST_7, ID_DLLIST_8 };
	LPCSTR apszCmds [] = {LS (L_FILENAME), LS (L_SIZE), LS (L_DOWNLOADED),
		LS (L_TIMELEFT), LS (L_SECTIONS), LS (L_SPEED), LS (L_COMMENT), LS (L_ADDED) };
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

void CFlashVideoDownloadsWnd::OnDLListShowCol(UINT nCmd)
{
	int iCol = nCmd - ID_DLLIST_1;
	m_wndTasks.ChangeColumnVisibility (iCol);
}

void CFlashVideoDownloadsWnd::OnFvdldAutostart() 
{
	m_wndTasks.OnFvdldAutostart ();
}

void CFlashVideoDownloadsWnd::OnFvdldDelete() 
{
	m_wndTasks.OnFvdldDelete ();	
}

void CFlashVideoDownloadsWnd::OnFvdldLaunch() 
{
	m_wndTasks.OnFvdldLaunch ();	
}

void CFlashVideoDownloadsWnd::OnFvdldOpenfolder() 
{
	m_wndTasks.OnFvdldOpenfolder ();	
}

void CFlashVideoDownloadsWnd::OnFvdldPasstodlds() 
{
	m_wndTasks.OnFvdldPasstodlds ();	
}

void CFlashVideoDownloadsWnd::OnFvdldProperties() 
{
	m_wndTasks.OnFvdldProperties ();	
}

void CFlashVideoDownloadsWnd::OnFvdldStart() 
{
	m_wndTasks.OnFvdldStart ();	
}

void CFlashVideoDownloadsWnd::OnFvdldStop() 
{
	m_wndTasks.OnFvdldStop ();	
}

void CFlashVideoDownloadsWnd::SaveAll(DWORD dwWhat)
{
	if (dwWhat & 2)
	{
		ASSERT (::IsWindow (m_hWnd));
		m_wndTasks.SaveState ();
		_App.View_SplitterRatio ("FVDownloads_DL_PREVIEW", m_splitter.GetRatio ());
	}
}

void CFlashVideoDownloadsWnd::SetActiveDownload(vmsDownloadSmartPtr dld)
{
	m_wndPreview.Set_ActiveDownload (dld);
}

void CFlashVideoDownloadsWnd::OnFvdldConvert() 
{
	m_wndTasks.OnFvdldConvert ();	
}

HMENU CFlashVideoDownloadsWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_FVDOWNLOADS));
}

HMENU CFlashVideoDownloadsWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_FVDOWNLOADS_VIEW));
}

BOOL CFlashVideoDownloadsWnd::CreateDownload(LPCSTR pszUrl, bool bTopMostErrMessages)
{
	DWORD dwMB = bTopMostErrMessages ? MB_SYSTEMMODAL : 0;

	if (_App.FlvMonitoring_Enable () == FALSE)
	{
		MessageBox (LS (L_ENABLE_FLVMONITORING_FIRST), NULL, MB_ICONEXCLAMATION | dwMB);
		return FALSE;
	}

	CString strUrl;

	if (pszUrl == NULL || *pszUrl == 0)
	{
		CDlgCreateFlvDownloadsByWebPageUrl dlg;
		if (IDOK != AfxGetApp ()->m_pMainWnd->SendMessage (WM_DOMODAL, 0, (LPARAM)&dlg))
			return FALSE;
		strUrl = dlg.m_strWebPageUrl;
	}
	else
	{
		strUrl = pszUrl;
	}

	CWaitDlg dlgWait;
	HRESULT hrRes;
	dlgWait.StartWaiting (LS (L_SEARCHING_FLVS), _threadPassWebPageUrlToFlvSniffDll, FALSE, (LPVOID)(LPCTSTR)strUrl, (LPVOID)&hrRes);

	if (hrRes != S_OK)
	{
		switch (hrRes)
		{
		case S_FALSE:
			MessageBox (LS (L_NOFLVSFOUND), NULL, MB_ICONEXCLAMATION | dwMB);
			break;

		case E_INVALIDARG:
			MessageBox (LS (L_FLVWEBPAGENOTFOUND), NULL, MB_ICONEXCLAMATION | dwMB);
			break;

		default:
			CString str;
			str.Format (LS (L_ERRGETFLVDLDS), hrRes);
			MessageBox (str, LS (L_ERROR), MB_ICONERROR | dwMB);
			break;
		}
	}

	return hrRes == S_OK;

	
}

LRESULT CFlashVideoDownloadsWnd::OnFvdwCreateDownloads(WPARAM, LPARAM lp)
{
	WmFvdwLparam *lParam = (WmFvdwLparam*)lp;
	ASSERT (lParam != NULL && lParam->pvDlds != NULL);
	if (lParam == NULL || lParam->pvDlds == NULL)
		return 1;

	std::vector <vmsNewDownloadInfo> *pvDlds = lParam->pvDlds;
	
	CDlgCreateFlvDownloads dlg (NULL, lParam->pUiWindow);

	dlg.m_strWebPageUrl = lParam->strSrcWebPageUrl;
	dlg.m_bReqTopMostDialog = true;

	size_t i = 0;
	for (i = 0; i < pvDlds->size (); i++)
	{
		vmsNewDownloadInfo &dlInfo = pvDlds->at (i);

		if (!dlInfo.ap.strFileName.IsEmpty ())
		{
			
			LPSTR psz = dlInfo.ap.strFileName.GetBuffer (0);
			char szSymbls [] = {":*?\"<>|\\/"};
			while (*psz) 
			{
				if (strchr (szSymbls, *psz))
					*psz = '_';
				psz++;
			}
			dlInfo.ap.strFileName.ReleaseBuffer ();
		}		

		CDlgCreateFlvDownloads::FlvDownload dld;

		dld.strTitle = dlInfo.ap.strFileName;
		dld.strUrl = dlInfo.strUrl;
		dld.uSize = dlInfo.ap.dwMask & DWCDAP_FILESIZE ? dlInfo.ap.uFileSize : _UI64_MAX;

		dlg.m_vDlds.push_back (dld);
	}

	UINT nRes = _DlgMgr.DoModal (&dlg);

	if (nRes != IDOK)
	{
		delete pvDlds;
		lParam->pUiWindow->Release ();
		delete lParam;
		return 2;
	}

	for (i = 0; i < pvDlds->size (); i++)
	{
		vmsNewDownloadInfo &dlInfo = pvDlds->at (i);

		if (dlg.m_vbDldSelected [i] == false)
			continue;

		dlInfo.dwWhatIsValid |= NDIV_AP;

		if ((dlInfo.ap.dwMask & DWCDAP_FLAGS) == 0)
		{
			dlInfo.ap.dwMask |= DWCDAP_FLAGS;
			dlInfo.ap.dwFlags = DWDCDAP_F_FLASHVIDEODOWNLOAD;
		}
		else
		{
			dlInfo.ap.dwFlags |= DWDCDAP_F_FLASHVIDEODOWNLOAD;
		}		

		if (dlg.m_bUseAutoConvert)
		{
			dlInfo.ap.dwMask |= DWCDAP_MEDIA_CONVERT_SETTINGS;
			dlInfo.ap.stgsMediaConvert = dlg.m_convertSettings;
		}

		dlInfo.bAddSilent = true;

		dlInfo.ap.strDstFolder = dlg.m_strDstFolder;

		if (dlInfo.ap.pGroup == NULL)
		{
			LPCSTR pszExt = NULL;
			if (dlInfo.ap.strFileName.IsEmpty () == FALSE)
			{
				pszExt = strrchr (dlInfo.ap.strFileName, '.');
				if (pszExt)
					pszExt++;
			}

			if (pszExt && *pszExt)
				dlInfo.ap.pGroup = _DldsGrps.FindGroupByExt (pszExt);
			if (dlInfo.ap.pGroup == NULL)
				dlInfo.ap.pGroup = _DldsGrps.FindGroupByExt ("flv");
			if (dlInfo.ap.pGroup == NULL)
				dlInfo.ap.pGroup = _DldsGrps.FindGroupByExt ("mp4");
			if (dlInfo.ap.pGroup == NULL)
				dlInfo.ap.pGroup = _DldsGrps.FindGroupByExt ("avi");

			if (dlInfo.ap.pGroup != NULL)
				dlInfo.ap.dwMask |= DWCDAP_GROUP;
		}

		_pwndDownloads->CreateDownload (&dlInfo);
	}

	delete pvDlds;
	lParam->pUiWindow->Release ();
	delete lParam;

	return 0;
}

DWORD WINAPI CFlashVideoDownloadsWnd::_threadPassWebPageUrlToFlvSniffDll(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	LPSTR pszUrl = (LPSTR)info->lpParam1;
	HRESULT *phrRes = (HRESULT*)info->lpParam2;

	*phrRes = S_FALSE;

	vmsSharedData sdata ("Fdm::mem::passUrlToFlvSniffDll", FALSE, strlen (pszUrl)+1);
	LPSTR psz = (LPSTR)sdata.getData ();
	ASSERT (psz != NULL);
	if (!psz)
	{
		info->bWaitDone = TRUE;
		return 0;
	}
	strcpy (psz, pszUrl);
	
	HWND hwnd = NULL;
	
	std::vector <HWND> vWnds;
	
	do 
	{
		hwnd = ::FindWindowEx (NULL, hwnd, "FdmFlvSniffDllWnd", NULL);
		if (hwnd)
			vWnds.push_back (hwnd);
	}
	while (hwnd);

	info->iProgress = 0;

	fsSetForegroundWindow (info->hwndDlg);

	for (size_t i = 0; i < vWnds.size (); i++)
	{
		HRESULT hr = ::SendMessage (vWnds [i], WM_COMMAND, 0, 0);

		if (info)
		{
			info->iProgress = 100 * (i+1) / vWnds.size ();

			if (hr == S_OK)
			{
				*phrRes = S_OK;	
				info->bWaitDone = true; 
				info = NULL;
			}
			else
			{
				if (*phrRes != S_OK)
					*phrRes = hr;
			}
		}
	}

	if (info)
		info->bWaitDone = true;

	return 0;
}

void CFlashVideoDownloadsWnd::OnDestroy()
{
	CWnd::OnDestroy();

	SAFE_DELETE (_pwndFVDownloads);
}
