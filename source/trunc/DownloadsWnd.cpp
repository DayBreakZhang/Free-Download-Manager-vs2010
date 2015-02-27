/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "DownloadsWnd.h"
#include "CreateDownloadDlg.h"
#include "CreateTPDownloadDlg.h"
#include "fsDownloadMgr.h"
#include "plugins.h"
#include "DownloadPropertiesSheet.h"
#include "DownloaderPropertiesSheet.h"
#include "NOWDlg.h"
#include "ShedulerWnd.h"
#include "plugincmds.h"
#include "system.h"
#include "WaitDlg.h"
#include "MainFrm.h"
#include "fsUrlsToDownloadRegKeyMgr.h"
#include "inetutil.h"
#include "SpiderWnd.h"
#include "Dlg_Opinions.h"
#include "vmsSimpleFileDownloader.h"
#include "fsDownloadsMgr.h"
#include "Dlg_Download.h"
#include "vmsDownloadsGroupsMgr.h"
#include "BtDldSheet.h"
#include "CreateDownloadFromTorrentFileDlg.h"
#include "FlashVideoDownloadsWnd.h"
#include "vmsMaliciousDownloadChecker.h"
#include "TorrentsWnd.h"
#include "Dlg_CreateNewTorrent.h"
#include "WndDlDoneNotification.h"
#include "FdmUiWindow.h"
#include "TpDldSheet.h"
#include "vmsLogger.h"

extern CSpiderWnd* _pwndSpider;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CDownloadsWnd* _pwndDownloads;

extern CShedulerWnd *_pwndScheduler;

CDownloadsWnd::CDownloadsWnd()
{
	m_wndGroups.m_pWndDownloads = this;
	m_wndDownloads.m_tasks.m_pDownloadsWnd = this;
	_DldsMgr.SetEventsFunc (_Events, this);
	m_bExiting = FALSE;
	m_bDontUpdateTIPO = FALSE;

	_TumMgr.AttachToIECatchMgr (&_IECatchMgr);

	m_uTotalSpeed = 0;

	m_cCheckDldHasOpinionsThreads = 0;

	m_bDeletingManyDownloads = false;

	m_bCreatingLotOfDownloads = false;
}

CDownloadsWnd::~CDownloadsWnd()
{
	_DldsMgr.SetEventsFunc (NULL, NULL);
}

BEGIN_MESSAGE_MAP(CDownloadsWnd, CWnd)
	//{{AFX_MSG_MAP(CDownloadsWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_COMMAND(ID_DLDDELETE, OnDlddelete)
	ON_COMMAND(ID_DLDLAUNCH, OnDldlaunch)
	ON_COMMAND(ID_DLDOPENFOLDER, OnDldopenfolder)
	ON_COMMAND(ID_DLDPROPERTIES, OnDldproperties)
	ON_COMMAND(ID_DLDSTART, OnDldstart)
	ON_COMMAND(ID_DLDSTOP, OnDldstop)
	ON_COMMAND(ID_DLDSCHEDULE, OnDldschedule)
	ON_COMMAND(ID_DLDAUTOSTART, OnDldautostart)
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_DLDADDSECTION, OnDldaddsection)
	ON_COMMAND(ID_DLDDELSECTION, OnDlddelsection)
	ON_COMMAND(ID_DLDRESTART, OnDldrestart)
	ON_COMMAND(ID_DLDQSIZE, OnDldqsize)
	ON_COMMAND(ID_DLDCREATEBATCH, OnDldcreatebatch)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_DLDCHECKVIR, OnDldcheckvir)
	ON_COMMAND(ID_DLDFIND, OnDldfind)
	ON_COMMAND(ID_DLDFINDNEXT, OnDldfindnext)
	ON_COMMAND(ID_DLDUNPACK, OnDldunpack)
	ON_COMMAND(ID_DLDMOVEDOWN, OnDldmovedown)
	ON_COMMAND(ID_DLDMOVEUP, OnDldmoveup)
	ON_COMMAND(ID_DLDCHECKINTEGRITY, OnDldcheckintegrity)
	ON_COMMAND(ID_DLDMOVETOFOLDER, OnDldmovetofolder)
	ON_COMMAND(ID_DLDMOVEBOTTOM, OnDldmovebottom)
	ON_COMMAND(ID_DLDMOVETOP, OnDldmovetop)
	ON_COMMAND(ID_DLDSCHEDULESTOP, OnDldschedulestop)
	ON_COMMAND(ID_DLDGRANTBANDWIDTHFORDLD, OnDldgrantbandwidthfordld)
	ON_COMMAND(ID_DLDSHOWPROGRESSDLG, OnDldshowprogressdlg)
	ON_COMMAND(ID_DLDCONVERT, OnDldconvert)
	ON_COMMAND(ID_DLDCREATE, OnDownloadCreate)
	ON_COMMAND(ID_DLDENABLESEEDING, OnDldenableseeding)
	ON_COMMAND(ID_DLD_TP, OnTpDownloadCreate)
	//}}AFX_MSG_MAP

	
	ON_MESSAGE (WM_WGP_SHUTDOWN, OnAppExit)
	ON_MESSAGE (WM_WGP_READYTOSHUTDOWN, OnAppQueryExit)
	ON_MESSAGE (WM_WGP_UPDATE_MENUMAIN, OnUpdateMenu)
	ON_MESSAGE (WM_WGP_UPDATE_MENUVIEW, OnUpdateMenuView)
	ON_MESSAGE (WM_WGP_UPDATE_CMDITEM, OnUpdateToolBar)
	ON_MESSAGE (WM_WGP_INSERT, OnInsert)
	
	ON_COMMAND(WGP_MENU_VIEWSMPLITEM_CMDSTART+0, OnShowAllGroups)
	ON_COMMAND(WGP_MENU_VIEWSMPLITEM_CMDSTART+1, OnShowDownloadingInfo)

	ON_COMMAND_RANGE(ID_DLLIST_1, ID_DLLIST_8, OnDLListShowCol)
	ON_COMMAND_RANGE(ID_DLOG_1, ID_DLOG_3, OnDLLogShowCol)
	
	

	ON_MESSAGE (WM_DW_CREATEDLDDIALOG, OnDWCreateDldDialog)
	ON_MESSAGE (WM_DW_CLOSEDLDDIALOG, OnDWCloseDldDialog)
	ON_MESSAGE (WM_DW_UPDATEDLDDIALOG, OnDWUpdateDldDialog)
	ON_MESSAGE (WM_DLD_SHOWOPINIONS, OnDldShowOpinions)
	ON_MESSAGE (WM_DLD_CONVERT_MEDIA, OnDldConvertMedia)
	ON_MESSAGE (WM_DLD_LAUNCH, OnWmDldLaunch)
	ON_MESSAGE (WM_DLD_SHOW_ON_DONE_NOTIFICATION, OnShowOnDlDoneNotification)
	ON_MESSAGE (WM_DW_DLDSMGR_EVENT, OnDwDldsMgrEvent)
	ON_MESSAGE (WM_DW_ONDLDSADDED, OnWmDwDldsAdded)
	ON_MESSAGE (WM_DW_ONSUCHTORRENTEXISTSALREADY, OnDwSuchTorrentExistsAlready)

END_MESSAGE_MAP()

BOOL CDownloadsWnd::Create(CWnd *pParent)
{
	CRect rc (0, 0, 50, 50);

	_TumMgr.ReadSettings ();
	_DldsMgr.Initialize ();

	if (FALSE == CWnd::Create (AfxRegisterWndClass (0, NULL,
		NULL, NULL), NULL, WS_CHILD | WS_VISIBLE, rc, pParent, 0x121))
		return FALSE;

	return TRUE;
}

int CDownloadsWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_bShowGroups = _App.View_AllGroups ();

	m_enDWWN = DWWN_LISTOFDOWNLOADS; 

	if (!_DldsGrps.LoadFromDisk ())
		MessageBox (LS (L_ERRLOADGRPS), LS (L_ERR), MB_ICONERROR);
	
	if (FALSE == m_wndDownloads.Create (this))
		return -1;

	if (FALSE == m_wndHistory.Create (this))
		return -1;

	if (FALSE == m_wndDeleted.Create (this))
		return -1;

	if (FALSE == m_wndGroups.Create (this))
		return -1;

	if (m_splitter.Create (AfxGetInstanceHandle (), m_hWnd) == FALSE)
		return -1;

	m_splitter.SetWnd1 (m_wndGroups.m_hWnd);

	m_wndDownloads.m_tasks.m_bSizesInBytes = _App.View_SizesInBytes ();

	do
	{
		if (FALSE == LoadDownloads ())
		{
			
				break;
		}
		else
			break;
	}
	while (TRUE);

	ApplyDWWN ();

	SetTimer (1, 1000, NULL);

	
	_App.View_ReadWndSize (&m_wndGroups, "DownloadsGroups");

	ShowAllGroups (m_bShowGroups);
	UpdateNumbersOfDownloadsInGroups ();

	
	PostMessage (WM_DW_DLDSMGR_EVENT);

	return 0;
}

void CDownloadsWnd::OnSize(UINT, int cx, int cy) 
{
	if (cx && cy)
	{
		
		if (m_bShowGroups)
		{
			
			m_splitter.RecalRatio (TRUE);
			m_splitter.ApplyRatio ();
		}
		else
		{
			
			m_wndDownloads.MoveWindow (0, 0, cx, cy);
			m_wndHistory.MoveWindow (0, 0, cx, cy);
			m_wndDeleted.MoveWindow (0, 0, cx, cy);
		}
	}
}

void CDownloadsWnd::OnDownloadCreate() 
{
	CreateDownload ((LPCSTR)NULL);
}

void CDownloadsWnd::OnTpDownloadCreate()
{
	LPCSTR pszStartUrl = _ClipbrdMgr.Text ();
	if (pszStartUrl)
	{
		if (_tcsstr (pszStartUrl, "rtsp://") == 0 &&
			_tcsstr (pszStartUrl, "mmsh://") == 0 &&
			_tcsstr (pszStartUrl, "mmst://") == 0 &&
			_tcsstr (pszStartUrl, "mms://") == 0)
			pszStartUrl = "";
	}

	vmsDownloadSmartPtr dld;
	Download_CreateInstance (dld, false, true);

	dld->dwFlags |= DLD_TP_DOWNLOAD;

	if (_App.ReserveDiskSpace ())
		dld->pMgr->GetTpDownloadMgr ()->enable_Flags (BTDF_RESERVE_DISK_SPACE);
	if (_App.DownloadFlags () & DPF_GENERATEDESCFILE)
		dld->pMgr->GetTpDownloadMgr ()->enable_Flags (BTDF_GENERATE_DESC_FILE);
	if (_App.DownloadFlags () & DPF_STARTWHENDONE)
		dld->pMgr->GetTpDownloadMgr ()->enable_Flags (BTDF_LAUNCH_WHEN_DONE);

	UINT res = IDOK;
	BOOL bPlaceToTop = FALSE;
	BOOL bScheduled = FALSE;
	
	fsScheduleEx schScheduleParam;
	fsSchedule& task = schScheduleParam.schTask;

	vmsDownloadsGroupSmartPtr pGroup = _DldsGrps.FindGroup (_App.NewDL_GroupId ());
	if (pGroup == NULL)
		pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);

	dld->pGroup = pGroup;

	dld->bAutoStart = _App.NewDL_AutoStart ();
	

	

	CCreateTPDownloadDlg dlg (dld, this);
	dlg.m_strUrl = pszStartUrl;
	
	res = _DlgMgr.DoModal (&dlg);

	if (res != IDOK)
		return;

	bPlaceToTop = dlg.m_bPlaceAtTop;
	
	
	task.hts.enType = HTS_ONCE;
	task.hts.last.dwHighDateTime = task.hts.last.dwLowDateTime = UINT_MAX;
	task.dwFlags = SCHEDULE_ENABLED;
	task.uWaitForConfirmation = 0;
	
	CString strUrl = dlg.m_strUrl;
	CString strOutFolder = dlg.m_strOutFolder;
	CString strFileName = dlg.m_strFileName;
	int nStreamingSpped = dlg.m_nStreamingSpeed;

	vmsTpDownloadMgr *pMgr = dld->pMgr->GetTpDownloadMgr ();
	if (pMgr == NULL) return;
	if (pMgr->CreateTPDownload (strUrl, strOutFolder, strFileName, nStreamingSpped))
		CreateDownload (dld, NULL, FALSE, bPlaceToTop);
}

void CDownloadsWnd::OnTimer(UINT ) 
{
	if (m_bExiting)
		return;

	
	

	_DldsMgr.LockList (true);

	int cDownloads = _DldsMgr.GetCount ();
	UINT uTotalSpeed = 0;
	DLDS_LIST v;
	BOOL bHasRunning = FALSE;

	try 
	{
		for (int i = 0; i < cDownloads; i++)
		{
			vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);

			if (dld == m_wndDownloads.m_info.Get_ActiveDownload ())
			{
				m_wndDownloads.m_info.UpdateActiveDownload ();
				m_wndDownloads.m_info.m_video.m_vidman.Update ();
				m_wndDownloads.m_info.m_bt.m_general.UpdateUploadStat ();
				m_wndDownloads.m_info.m_bt.UpdatePeersStat ();
				m_wndDownloads.m_info.m_bt.m_general.UpdateWastedStat ();
				if (dld->pMgr->IsDownloading ())
					m_wndDownloads.m_info.m_bt.m_files.UpdateProgress ();
			}

			if (_pwndTorrents && dld == _pwndTorrents->m_wndBtTab.getActiveDownload ())
			{
				_pwndTorrents->m_wndBtTab.m_general.UpdateUploadStat ();
				_pwndTorrents->m_wndBtTab.UpdatePeersStat ();
				_pwndTorrents->m_wndBtTab.m_general.UpdateWastedStat ();
				if (dld->pMgr->IsDownloading ())
					_pwndTorrents->m_wndBtTab.m_files.UpdateProgress ();
			}

			if (dld->pMgr->IsDownloading ()) 
			{
				uTotalSpeed += dld->pMgr->GetSpeed ();
				m_wndDownloads.m_tasks.UpdateDownload (dld);
				if (dld->dwFlags & DLD_FLASH_VIDEO)
					_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
				if (_pwndTorrents && dld->isTorrent ())
					_pwndTorrents->m_wndTasks.UpdateDownload (dld);
			}
			else if (dld->pMgr->IsReservingDiskSpace ())
			{
				m_wndDownloads.m_tasks.UpdateDownload (dld);
				if (dld->dwFlags & DLD_FLASH_VIDEO)
					_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
				if (_pwndTorrents && dld->isTorrent ())
					_pwndTorrents->m_wndTasks.UpdateDownload (dld);
			}

			if (dld->pMgr->IsBittorrent () && 
					dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed ())
			{
				v.push_back (dld);
				if (dld->pMgr->IsDownloading () == FALSE)
				{
					m_wndDownloads.m_tasks.UpdateDownload (dld);
					if (dld->dwFlags & DLD_FLASH_VIDEO)
						_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
					if (_pwndTorrents)
						_pwndTorrents->m_wndTasks.UpdateDownload (dld);
				}
			}

			if (dld->pMgr->IsRunning ())
				bHasRunning = TRUE;
		}
		m_uTotalSpeed = uTotalSpeed;
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::OnTimer " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::OnTimer unknown exception");
	}

	_DldsMgr.UnlockList (true);

	if (bHasRunning && _App.PreventStandbyWhileDownloading ())
		SetThreadExecutionState (ES_SYSTEM_REQUIRED);

	if (v != m_vUploadDownloads)
	{
		m_vUploadDownloads = v;
		((CMainFrame*)AfxGetApp ()->m_pMainWnd)->RebuidDownloadsList ();
	}
}

void CDownloadsWnd::SetActiveDownload(vmsDownloadSmartPtr dld)
{
	try 
	{
		m_wndDownloads.m_info.Set_ActiveDownload (dld);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::SetActiveDownload " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::SetActiveDownload unknown exception");
	}
}

void CDownloadsWnd::OnDownloadProperties(DLDS_LIST &vDlds, CWnd* pwndParent)
{
	ASSERT (vDlds [0]->pMgr->GetDownloadMgr () != NULL);

	CDownloadPropertiesSheet sheet (LS (L_DLDPROP), pwndParent ? pwndParent : this);

	sheet.Init (&vDlds, DPS_SHP_ALL);

    _DlgMgr.OnDoModal (&sheet);

	if (sheet.DoModal () == IDOK)
	{
		
		if (sheet.IsNeedUpdateTasks ())
			OnDownloadsGroupChanged ();

		if (sheet.IsNeedProcessDownloads ())
			_DldsMgr.setNeedProcessDownloads ();
	}

    _DlgMgr.OnEndDialog (&sheet);
}

BOOL CDownloadsWnd::LoadDownloads()
{
	BOOL retVal = FALSE;
	try
	{
		retVal = _DldsMgr.LoadDownloads ();
	}
	catch (...)
	{
		vmsLogger::WriteLog("CDownloadsWnd::LoadDownloads unknown exception");
		retVal = FALSE;
	}
	if (retVal == FALSE)
	{
		if (IDCANCEL == MessageBox (LS (L_ERROR_LOADING_DOWNLOADS__CANCEL_TO_EXIT), NULL, MB_ICONERROR | MB_OKCANCEL | MB_SYSTEMMODAL))
			TerminateProcess (GetCurrentProcess (), 1);
		return FALSE;
	}

	_MediaConvertMgr.LoadState ();

	for (int i = _DldsMgr.Get_DeletedDownloadCount ()-1; i >= 0; i--)
		m_wndDeleted.AddDownload (_DldsMgr.Get_DeletedDownload (i));

	m_wndGroups.UpdateDeletedIcon ();

	return TRUE;
}

LRESULT CDownloadsWnd::OnAppExit(WPARAM, LPARAM)
{
	m_bExiting = TRUE;

	KillTimer (1);

	_DldsMgr.AllowStartNewDownloads (FALSE);
	_pwndSpider->m_mgr.StopAll ();

	for (int k = 0; k < 3*60*1000 && _pwndSpider->m_mgr.IsDownloadsMgrRequired (); k += 50)
	{
#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
		MSG msg;
		while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message != WM_TIMER)
				DispatchMessage (&msg);
		}
#endif
		Sleep (50);
	}

	_DldsMgr.LockList (true);

	size_t cDownloads = _DldsMgr.GetCount ();
	size_t i;

	for (i = 0; i < cDownloads; i++)
	{
		vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);

		if (dld->pdlg)
		{
			dld->pdlg->ShowWindow (SW_HIDE);
			dld->AddRef (); 
			PostMessage (WM_DW_CLOSEDLDDIALOG, 0, (LPARAM)(fsDownload*) dld);
		}

		if (dld->pMgr->GetDownloadMgr ())
		{
			dld->pMgr->GetDownloadMgr ()->SetEventFunc (NULL, 0);
			dld->pMgr->GetDownloadMgr ()->SetEventDescFunc (NULL, 0);
		}
		else if (dld->pMgr->GetBtDownloadMgr ())
		{
			dld->pMgr->GetBtDownloadMgr ()->SetEventsHandler (NULL, 0);
			dld->pMgr->GetBtDownloadMgr ()->StopSeeding ();
		}
		else if (dld->pMgr->GetTpDownloadMgr ())
		{
			dld->pMgr->GetTpDownloadMgr ()->SetEventsHandler (NULL, 0);
			dld->pMgr->GetTpDownloadMgr ()->SetEventDescFunc (NULL, 0);
		}

		dld->pMgr->StopDownloading ();
	}

	_DldsMgr.UnlockList (true);

	DWORD dwTicks = GetTickCount ();

	while (_DldsMgr.IsRunning ())
	{
#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
		MSG msg;
		while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message != WM_TIMER)
				DispatchMessage (&msg);
		}
#endif
		Sleep (10);
		if (GetTickCount () - dwTicks > 10000)
		{
			_DldsMgr.StopAllDownloads (FALSE); 
			dwTicks = GetTickCount ();
		}
	}

#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
	
	
	
	while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE)) 
	{
		if (msg.message != WM_TIMER)
			DispatchMessage (&msg);
	}
#endif

	while (m_cCheckDldHasOpinionsThreads)
		Sleep (10);

	SaveAll (0xffffffff);

	_IECatchMgr.Detach ();

	m_wndDownloads.m_tasks.DeleteAllItems ();
	SetActiveDownload (NULL);
	
	return 0;
}

BOOL CDownloadsWnd::DeleteGroup(vmsDownloadsGroupSmartPtr pGroup)
{
	if (pGroup->nId == GRP_OTHER_ID)
		return FALSE;

	CString str = LS (L_AREYOUSURE); str += '\n'; str += LS (L_THISDELGRPDLDS);
	if (IDNO == MessageBox (str, LS (L_CONFIRMATION), MB_ICONQUESTION|MB_YESNO))
		return FALSE;

	std::vector <vmsDownloadsGroupSmartPtr> v;
	_DldsGrps.GetGroupWithSubgroups (pGroup, v);
	for (size_t i = 0; i < v.size (); i++)
		v [i]->bAboutToBeDeleted = true;

	
	if (FALSE == _DldsMgr.DeleteGroupsDownloads (pGroup, TRUE))
	{
		for (size_t i = 0; i < v.size (); i++)
			v [i]->bAboutToBeDeleted = false;
		return FALSE;
	}

	_DldsGrps.DeleteGroup (pGroup);
	
	_SitesMgr.CheckGroups ();

	return TRUE;
}

DWORD CDownloadsWnd::_Events(fsDownload* dld, fsDLHistoryRecord *rec, fsDownloadsMgrEvent ev, LPVOID lp)
{
	assert (_pwndDownloads != NULL);
	if (!_pwndDownloads)
		return 0;

	CDownloadsWnd* pthis = (CDownloadsWnd*) lp;

	

	

	DwDldsMgrEventParam p;
	p.dld = dld;
	p.rec = rec;
	p.ev = ev;

	if (ev == DME_EVENTDESCRIPRIONRECEIVED)
	{
		assert (dld != NULL);
		assert (dld->vEvents.size () != 0);
		p.iDldLogEntry = p.dld->vEvents.size () - 1;
	}

	EnterCriticalSection (&pthis->m_csDldsMgrEvents);
	pthis->m_vDldsMgrEvents.push_back (p);
	if (pthis->m_vDldsMgrEvents.size () == 1 && pthis->m_hWnd != NULL)		
		pthis->PostMessage (WM_DW_DLDSMGR_EVENT);
	LeaveCriticalSection (&pthis->m_csDldsMgrEvents);

	return TRUE;
}

void CDownloadsWnd::OnDownloadDefProperties()
{
	CDownloadPropertiesSheet sheet (LS (L_DLDDEFOPT), this);
	DLDS_LIST vDlds;

	
	
	vmsDownloadSmartPtr http, ftp, https;

	http.CreateInstance ();
	http->pMgr->Attach (new fsDownloadMgr);
	https.CreateInstance ();
	https->pMgr->Attach (new fsDownloadMgr);
	ftp.CreateInstance ();
	ftp->pMgr->Attach (new fsDownloadMgr);

	http->pMgr->GetDownloadMgr ()->CreateByUrl ("http://");
	https->pMgr->GetDownloadMgr ()->CreateByUrl ("https://");
	ftp->pMgr->GetDownloadMgr ()->CreateByUrl ("ftp://");

	vDlds.push_back (http);
	vDlds.push_back (https);
	vDlds.push_back (ftp);

	sheet.Init (&vDlds, DPS_SHP_NOGENERALNOMIRR);

    _DlgMgr.OnDoModal (&sheet);

	if (sheet.DoModal () == IDOK)
	{
		fsDownload_Properties *dp = http->pMgr->GetDownloadMgr ()->GetDP ();
		fsDownload_NetworkProperties *dnp = http->pMgr->GetDownloadMgr ()->GetDNP ();

		
		_App.AccDeniedReaction (dp->aEP [DFE_ACCDENIED]);
		_App.AdditionalExtension (dp->pszAdditionalExt);
		_App.Download_CreateExt (dp->pszCreateExt);
		_App.Agent (dnp->pszAgent);
		_App.AlreadyExistReaction (dp->enAER);
		_App.FtpTransferType (dnp->enFtpTransferType);
		_App.ASCIIExts (dnp->pszASCIIExts);
		_App.DownloadFlags (dp->dwFlags);
		_App.IgnoreRestrictions (dp->bIgnoreRestrictions);
		_App.InternetAccessType (dnp->enAccType);
		_App.MaxAttempts (dp->uMaxAttempts);
		_App.MaxSections (dp->uMaxSections);
		_App.NotFoundReaction (dp->aEP [DFE_NOTFOUND]);
		_App.FtpFlags (dnp->dwFtpFlags);
		_App.Referer (dnp->pszReferer);
		_App.ReserveDiskSpace (dp->bReserveDiskSpace);
		_App.RestartSpeedLow (dp->bRestartSpeedLow);
		_App.RetriesTime (dp->uRetriesTime);
		_App.SectionMinSize (dp->uSectionMinSize);
		_App.SizeChangeReaction (dp->enSCR);
		_App.Timeout (dp->uTimeout);
		_App.TrafficRestriction (dp->uTrafficRestriction);
		_App.UseCookie (dnp->bUseCookie);
		_App.UseHttp11 (dnp->bUseHttp11);
		_App.UserName (dnp->pszUserName);
		_App.UserPassword (dnp->pszPassword);
		_App.RollBackSize (dnp->wRollBackSize);
		_App.DNPFlags (dnp->dwFlags);
		_App.LowSpeed_Duration (dnp->wLowSpeed_Duration);
		_App.LowSpeed_Factor (dnp->wLowSpeed_Factor);
		_App.Download_CheckIntegrityWhenDone (dp->bCheckIntegrityWhenDone);
		_App.Download_IntegrityCheckFailedReaction (dp->enICFR);

		
		
		_App.HttpProxy_Name (dnp->pszProxyName);
		_App.HttpProxy_Password (dnp->pszProxyPassword);
		_App.HttpProxy_UserName (dnp->pszProxyUserName);
		
		_App.HttpsProxy_Name (https->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyName);
		_App.HttpsProxy_Password (https->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyPassword);
		_App.HttpsProxy_UserName (https->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyUserName);
		
		_App.FtpProxy_Name (ftp->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyName);
		_App.FtpProxy_Password (ftp->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyPassword);
		_App.FtpProxy_UserName (ftp->pMgr->GetDownloadMgr ()->GetDNP ()->pszProxyUserName);
	}

    _DlgMgr.OnEndDialog (&sheet);
}

void CDownloadsWnd::OnDownloaderProperties()
{
	CDownloaderPropertiesSheet sheet (LS (L_DLDR_OPTIONS), this);

	sheet.Init ();
     _DlgMgr.OnDoModal (&sheet);
	sheet.DoModal ();
    _DlgMgr.OnEndDialog (&sheet);
	_TumMgr.SaveSettings ();
	_DldsMgr.SaveSettings ();
	_DldsMgr.setNeedProcessDownloads ();
}

void CDownloadsWnd::OnOptimizationWizard()
{
	CNOWDlg dlg;

    _DlgMgr.OnDoModal (&dlg);
	
	if (IDOK != dlg.DoModal ())
	{
	   _DlgMgr.OnEndDialog (&dlg);
		return;
	}

     _DlgMgr.OnEndDialog (&dlg);

	
}

void CDownloadsWnd::OnDestroy() 
{
	CWnd::OnDestroy();
	
	SAFE_DELETE (_pwndDownloads);	
}

LRESULT CDownloadsWnd::OnAppQueryExit(WPARAM, LPARAM)
{
	
	return 0; 
}

LRESULT CDownloadsWnd::OnUpdateMenu(WPARAM, LPARAM lp)
{
	HMENU *hMenu = (HMENU*) lp;

	m_wndDownloads.m_tasks.UpdateMenu (CMenu::FromHandle (*hMenu));

	return 0;
}

void CDownloadsWnd::OnDlddelete() 
{
	m_wndDownloads.m_tasks.OnDlddelete ();
}

void CDownloadsWnd::OnDldlaunch() 
{
	m_wndDownloads.m_tasks.OnDldlaunch ();	
}

void CDownloadsWnd::OnDldopenfolder() 
{
	m_wndDownloads.m_tasks.OnDldopenfolder ();	
}

void CDownloadsWnd::OnDldproperties() 
{
	m_wndDownloads.m_tasks.OnDldproperties ();	
}

void CDownloadsWnd::OnDldstart() 
{
	m_wndDownloads.m_tasks.OnDldstart ();	
}

void CDownloadsWnd::OnDldstop() 
{
	m_wndDownloads.m_tasks.OnDldstop ();	
}

UINT CDownloadsWnd::CreateDownload(LPCSTR pszStartUrl, BOOL bReqTopMostDialog, LPCSTR pszComment, LPCSTR pszReferer, 
	BOOL bSilent, DWORD dwForceAutoLaunch, BOOL *pbAutoStart, vmsDWCD_AdditionalParameters* pParams, UINT* pRes)
{
	std::string strUrlTmp;
	if (pszStartUrl == NULL || *pszStartUrl == NULL)
	{
		pszStartUrl = "http://";

		if (!bSilent)
		{
			LPCSTR psz = _ClipbrdMgr.Text ();
			if (psz)
			{
				strUrlTmp = psz;
			}
			
			if (strUrlTmp.find("magnet:") == 0)
			{
				pszStartUrl = strUrlTmp.c_str();
			}
			else if (!strUrlTmp.empty ())
			{
				fsURL url;
				if (url.Crack (strUrlTmp.c_str ()) == IR_SUCCESS && *url.GetHostName ())
					pszStartUrl = strUrlTmp.c_str ();
			}
		}
	}

	
	if (!_tcsnicmp (pszStartUrl, _T ("magnet:"), 7))
	{
		UINT nDownloadId = 0;
		if (!CreateBtDownload (pszStartUrl, _T(""), bSilent, FALSE, NULL, NULL, NULL, NULL, NULL, &nDownloadId))
		{
			if (pRes)
				*pRes = IDCANCEL;
			return UINT_MAX;
		}
		if (pRes)
			*pRes = IDOK;
		return nDownloadId;
	}

	vmsDownloadSmartPtr dld;
	Download_CreateInstance (dld, false);

	UINT res = IDOK;
	bool bPlaceToTop = false;
	BOOL bScheduled = FALSE;
	
	fsScheduleEx schScheduleParam;
	fsSchedule& task = schScheduleParam.schTask;

	if (FALSE == CreateDownloadWithDefSettings (dld, pszStartUrl))
		return UINT_MAX;

	if (pszReferer)
	{
		SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer);
		dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer = new char [strlen (pszReferer) + 1];
		strcpy (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszReferer, pszReferer);
	}

	if (pszComment)
		dld->strComment = pszComment;

	OnDownloadPreCreate (dld, pParams);

	if (bSilent == FALSE)
	{
		CCreateDownloadDlg dlg (dld, this);
		dlg.m_bReqTopMostDialog = bReqTopMostDialog;
		if (pParams)
			dlg.m_pUiWindow = pParams->pUiWindow;
		
		if (pParams)
		{
			if ((pParams->dwMask & DWCDAP_FLAGS) && (pParams->dwFlags & DWDCDAP_F_SETFOCUSTOOKBTN))
				dlg.m_bSetFocusToOKBtn = true;
			if (pParams->dwMask & DWCDAP_COOKIES)
				dlg.m_pszCookies  = pParams->strCookies;
			if (pParams->dwMask & DWCDAP_POSTDATA)
				dlg.m_pszPostData = pParams->strPostData;
			if (pParams->dwMask & DWCDAP_GROUP)
				dlg.m_pGroup = pParams->pGroup;
		}
		
		res = _DlgMgr.DoModal (&dlg);

		if (res == IDOK && !dlg.m_strUrl.Find (_T ("magnet:")))
		{
			
			
			assert (dlg.m_strUrl != pszStartUrl); 
			if (dlg.m_strUrl != pszStartUrl)
				return CreateDownload (dlg.m_strUrl, bReqTopMostDialog, pszComment, pszReferer, bSilent, dwForceAutoLaunch, pbAutoStart, pParams, pRes);
		}
		
		bPlaceToTop = dlg.m_bPlaceAtTop;
		bScheduled = dlg.m_bScheduled;
		task = dlg.m_schScheduleParam.schTask;
	}
	else
	{
		if (dld->pMgr->GetDownloadMgr () != NULL)
		{
			fsDownload_NetworkProperties *dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();
			if (!dnp->pszUserName || !*dnp->pszUserName)
			{
				fsSiteInfo *site = _SitesMgr.FindSite (dnp->pszServerName, fsNPToSiteValidFor (dnp->enProtocol));
				if (site != NULL && !site->strUser.IsEmpty ())
				{
					SAFE_DELETE_ARRAY (dnp->pszUserName);
					SAFE_DELETE_ARRAY (dnp->pszPassword);
					fsnew (dnp->pszUserName, CHAR, site->strUser.GetLength ()+1);
					fsnew (dnp->pszPassword, CHAR, site->strPassword.GetLength ()+1);
					strcpy (dnp->pszUserName, site->strUser);
					strcpy (dnp->pszPassword, site->strPassword);
				}
			}
		}

		ASSERT (pParams == NULL || pParams->pUiWindow == NULL);
		if (pParams && pParams->pUiWindow)
			pParams->pUiWindow->setWindow (NULL);

		if (pbAutoStart)
			dld->bAutoStart = *pbAutoStart;

		if (dwForceAutoLaunch != DWCD_NOFORCEAUTOLAUNCH)
		{
			dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_STARTWHENDONE;
			if (dwForceAutoLaunch == DWCD_FORCEAUTOLAUNCH_NOCONF)
				dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_STARTWHENDONE_NOCONF;
		}

		BOOL bShowUI = TRUE;
		if (pParams && (pParams->dwMask & DWCDAP_FLAGS) &&
				0 != (pParams->dwFlags & DWDCDAP_F_NO_UI))
			bShowUI = FALSE;

		if (pParams && (pParams->dwMask & DWCDAP_FLAGS) && 
				(pParams->dwFlags & DWDCDAP_F_DONTCHECKURLALREADYEXISTS))
		{
			if (_DldsMgr.IsSuchUrlExistsAlready (dld) != -1)
			{
				if (dld->pMgr->GetDownloadMgr ())
				{
					dld->pMgr->GetDownloadMgr ()->GetDP ()->enAER = AER_RENAME;
				}
			}
		}
		else
		{
			if (_App.CheckIfDownloadWithSameUrlExists ())
			{
				int ret = CCreateDownloadDlg::_CheckDownloadAlrExists (dld, TRUE, bShowUI);
				if (ret)
				{
					if (ret == 1)
						res = ID_DLNOTADDED;
					else
						res = IDCANCEL;
				}
			}
		}
	}

	if (res != IDOK)
	{
		if (pRes)
			*pRes = res;

		return UINT_MAX;
	}

	if (pParams)
	{
		CString strDstFolder = pParams->strDstFolder;

		if (pParams->dwMask & DWCDAP_GROUP)
		{
			dld->pGroup = pParams->pGroup;
			if (strDstFolder.IsEmpty ())
				strDstFolder = dld->pGroup->strOutFolder;
		}

		if (strDstFolder.IsEmpty () == FALSE)
		{
			LPCSTR pszFolder = strDstFolder;
			delete [] dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
			dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName = new char [lstrlen (pszFolder) + 2];
			lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, pszFolder);
			if (pszFolder [lstrlen (pszFolder) - 1] != '\\')
				lstrcat (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, "\\");
		}

		if (pParams->dwMask & DWCDAP_FILENAME)
		{
			fsDownload_Properties *dp = dld->pMgr->GetDownloadMgr ()->GetDP ();
			if (dp->pszFileName [lstrlen (dp->pszFileName) - 1] == '\\' ||
					dp->pszFileName [lstrlen (dp->pszFileName) - 1] == '/')
			{
				LPSTR psz = new char [lstrlen (dp->pszFileName) + pParams->strFileName.GetLength () + 1];
				lstrcpy (psz, dp->pszFileName);
				lstrcat (psz, pParams->strFileName);
				delete [] dp->pszFileName;
				dp->pszFileName = psz;
			}
		}

		if (pParams->dwMask & DWCDAP_FLAGS)
		{
			if (pParams->dwFlags & DWDCDAP_F_SAVETODESKTOP)
			{
				char szDesktop [MY_MAX_PATH];
				LPITEMIDLIST pidl = NULL;
				SHGetSpecialFolderLocation (NULL, CSIDL_DESKTOP, &pidl);
				SHGetPathFromIDList (pidl, szDesktop);
				if (szDesktop [lstrlen (szDesktop) - 1] != '\\')
					lstrcat (szDesktop, "\\");
				delete [] dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
				dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName = new char [lstrlen (szDesktop) + 1];
				lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, szDesktop);
			}
			else if (pParams->dwFlags & DWDCDAP_F_SAVETOTEMPFLDR)
			{
				char szTmpFolder [MY_MAX_PATH];
				GetTempPath (MY_MAX_PATH, szTmpFolder);
				if (szTmpFolder [lstrlen (szTmpFolder) - 1] != '\\')
					lstrcat (szTmpFolder, "\\");
				delete [] dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
				dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName = new char [lstrlen (szTmpFolder) + 1];
				lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, szTmpFolder);
			}

			if (pParams->dwFlags & DWDCDAP_F_DELWHENDONE)
				dld->dwFlags |= DLD_DELETEWHENDONE | DLD_DELETEFILEATRESTART;

			if (pParams->dwFlags & DWDCDAP_F_IGNOREALLRESTRICTS)
				dld->pMgr->GetDownloadMgr ()->GetDP ()->bIgnoreRestrictions = TRUE;

			if (pParams->dwFlags & DWDCDAP_F_PLACETOTOP)
				bPlaceToTop = true;

			if (pParams->dwFlags & DWDCDAP_F_NOGRPAUTOCHANGE)
				dld->dwFlags |= DLD_NOAUTOCHANGECURGRPFILTER;

			if (pParams->dwFlags & DWDCDAP_F_FORCEAUTOSTART)
				dld->bAutoStart = TRUE;

			if (pParams->dwFlags & DWDCDAP_F_DISABLEMALICIOUSCHECK)
				dld->dwFlags |= DLD_MALICIOUS_DISABLE_CHECK;

			if (pParams->dwFlags & DWDCDAP_F_FLASHVIDEODOWNLOAD)
				dld->dwFlags |= DLD_FLASH_VIDEO;

			if (pParams->dwFlags & DWDCDAP_F_TORRENTDOWNLOAD)
				dld->dwFlags |= DLD_TORRENT_DOWNLOAD;
		}

		if (pParams->dwMask & DWCDAP_COOKIES)
		{
			SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies);
			dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies = new char [pParams->strCookies.GetLength () + 1];
			lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszCookies, pParams->strCookies);
		}

		if (pParams->dwMask & DWCDAP_POSTDATA)
		{
			SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPostData);
			dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPostData = new char [pParams->strPostData.GetLength () + 1];
			lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPostData, pParams->strPostData);
		}

		if (pParams->dwMask & DWCDAP_MEDIA_CONVERT_SETTINGS)
		{
			dld->dwFlags |= DLD_MF_AUTO_CONVERT;
			_MediaConvertMgr.AddTask (dld, pParams->stgsMediaConvert);
		}
	}

	OnDownloadPostCreate (dld);

	CreateDownload (dld, bScheduled ? &task : NULL, FALSE, bPlaceToTop);

	if (dld->dwFlags & DLD_FLASH_VIDEO)
		_pwndFVDownloads->AddDownload (dld, bPlaceToTop);

	if (_pwndTorrents && (dld->dwFlags & DLD_TORRENT_DOWNLOAD))
		_pwndTorrents->AddDownload (dld, bPlaceToTop);

	return dld->nID;
}

void CDownloadsWnd::StartDownloadsInList()
{
	CDownloads_Tasks *tasks = &m_wndDownloads.m_tasks;
	int cDlds = tasks->GetItemCount ();
	DLDS_LIST vDlds;

	for (int i = 0; i < cDlds; i++)
	{
		vmsDownloadSmartPtr dld = (fsDownload*) tasks->GetItemData (i);
		vDlds.push_back (dld);
	}

	_DldsMgr.StartDownloads (vDlds, TRUE);
}

void CDownloadsWnd::StopDownloadsInList()
{
	CDownloads_Tasks *tasks = &m_wndDownloads.m_tasks;
	int cDlds = tasks->GetItemCount ();
	DLDS_LIST vDlds;

	int i = 0;
	for (i = 0; i < cDlds; i++)
	{
		vmsDownloadSmartPtr dld = (fsDownload*) tasks->GetItemData (i);
		vDlds.push_back (dld);
	}

	_DldsMgr.StopDownloads (vDlds, TRUE);

	for (i = 0; i < cDlds; i++)
		tasks->UpdateDownload (vDlds [i]);
}

void CDownloadsWnd::DeleteDownloadsInList()
{
	CDownloads_Tasks *tasks = &m_wndDownloads.m_tasks;
	int cDlds = tasks->GetItemCount ();

	if (cDlds == 0)
		return;

	if (_App.Deleted_ConfirmDeletion ())
	if (IDNO == MessageBox (LS (L_AREYOUSURE), LS (L_CONFIRMATION), MB_ICONQUESTION|MB_YESNO))
		return;

	cDlds = tasks->GetItemCount ();

	DLDS_LIST vDlds;

	for (int i = 0; i < cDlds; i++)
		vDlds.push_back ((fsDownload*) tasks->GetItemData (i));

	tasks->ShowWindow (SW_HIDE);
	if (m_bShowGroups)
		m_wndGroups.ShowWindow (SW_HIDE);
	
	DeleteDownloads (vDlds, TRUE, FALSE);

	tasks->ShowWindow (SW_SHOW);
	if (m_bShowGroups)
		m_wndGroups.ShowWindow (SW_SHOW);
}

void CDownloadsWnd::DeleteCompletedDownloadsInList()
{
	CDownloads_Tasks *tasks = &m_wndDownloads.m_tasks;
	int cDlds = tasks->GetItemCount ();

	DLDS_LIST vDlds;

	for (int i = 0; i < cDlds; i++)
	{
		vmsDownloadSmartPtr dld = (fsDownload*) tasks->GetItemData (i);
		if (dld->pMgr->IsDone ())
			vDlds.push_back (dld);
	}

	if (vDlds.size () == 0)
		return;

	DeleteDownloads (vDlds, TRUE, FALSE);
}

void CDownloadsWnd::OnDldschedule() 
{
	m_wndDownloads.m_tasks.OnDldschedule ();		
}

void CDownloadsWnd::UpdateAllDownloads()
{
	m_wndDownloads.m_tasks.UpdateAllDownloads ();
}

void CDownloadsWnd::OnDldautostart() 
{
	m_wndDownloads.m_tasks.OnDldautostart ();	
}

void CDownloadsWnd::CreateDownloads(DLDS_LIST &vDlds, fsSchedule *task, BOOL bDontUseSounds, bool bPlaceToTop)
{	
	if (vDlds.size () == 0)
		return;

	if (task)
	{
		task->wts.enType = WTS_STARTDOWNLOAD;
		fsnew1 (task->wts.dlds.pvIDs, fs::list <UINT>);
		task->wts.dlds.dwFlags = 0;
	}

	int sz = vDlds.size ();

	_DldsMgr.LockList (false);

	for (int i = 0; i < sz; i++)
	{
		UINT uID = _DldsMgr.Add (vDlds [i], FALSE, bPlaceToTop);

		
		if (task)
			task->wts.dlds.pvIDs->add (uID);
	}

	_DldsMgr.UnlockList (false);

	if (task)
		_pwndScheduler->AddTask (task);

	vmsAUTOLOCKSECTION (m_csDownloadsHasBeenAdded);

	if (m_bCreatingLotOfDownloads == false)
	{
		vmsAUTOLOCKSECTION_UNLOCK (m_csDownloadsHasBeenAdded);
		onDownloadsHasBeenAdded (vDlds, bPlaceToTop, bDontUseSounds);
	}
	else
	{
		for (size_t i = 0; i < vDlds.size (); i++)
		{
			if (bPlaceToTop)
				m_vDownloadsHasBeenAdded.insert (m_vDownloadsHasBeenAdded.begin ()+i, vDlds [i]);
			else
				m_vDownloadsHasBeenAdded.push_back (vDlds [i]);
		}
		m_bDownloadsHasBeenAddedToTop = bPlaceToTop;
		m_bDontUseSoundsForDownloadsHasBeenJustAdded = bDontUseSounds;
	}
}

void CDownloadsWnd::SaveAll(DWORD dwWhat)
{
	try
	{
		if (dwWhat & 1)
		{
			_DldsGrps.SaveToDisk ();
			_DldsMgr.Save ();
			_TumMgr.SaveSettings ();
			_DldsMgr.SaveSettings ();
			_MediaConvertMgr.SaveState ();
		}

		if (dwWhat & 2)
		{
			ASSERT (::IsWindow (m_hWnd));

			_App.View_SaveWndSize (&m_wndGroups, "DownloadsGroups");
			m_wndDownloads.SaveState ();
			m_wndHistory.SaveState ("DownloadsHistory");
			m_wndDeleted.SaveState ("DownloadsDeleted");
			_App.View_SizesInBytes (m_wndDownloads.m_tasks.m_bSizesInBytes);
			_App.View_DWWN (m_enDWWN);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::SaveAll " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::SaveAll unknown exception");
	}
}

LRESULT CDownloadsWnd::OnUpdateToolBar(WPARAM wp, LPARAM)
{
	return m_wndDownloads.m_tasks.OnUpdateToolBar (wp);	
}

void CDownloadsWnd::UpdateTrayIconPlusOthers()
{
	if (m_bDontUpdateTIPO)
		return;

	try 
	{
		BOOL bRun = FALSE;	
		BOOL bRunOk = FALSE;	
		BOOL bWaitRunOk = FALSE;	
		BOOL bUploading = FALSE;

		_DldsMgr.LockList (true);

		size_t nCount = _DldsMgr.GetCount ();

		for (size_t i = 0; i < nCount; i++)
		{
			vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);
			vmsDownloadMgrSmartPtr pMgr = dld->pMgr;

			if (pMgr->IsRunning () && pMgr->IsDone () == FALSE)
			{
				bRun = TRUE;	

				if (pMgr->GetDownloadingSectionCount () || pMgr->GetSpeed ())
					bRunOk = TRUE;	

				if (pMgr->IsCantStart () == FALSE)
					bWaitRunOk = TRUE;	
			}

			if (bUploading == FALSE && dld->pMgr->IsBittorrent () && 
					dld->pMgr->GetBtDownloadMgr ()->GetUploadSpeed ())
				bUploading = TRUE;

			if (bRunOk)
				break; 
			
		}

		_DldsMgr.UnlockList (true);

		if (_App.View_FloatingInfoWindow ())
		{
			CMainFrame* pFrm = (CMainFrame*) AfxGetApp ()->m_pMainWnd;
			if (bRun || bUploading)
			{
				if (pFrm->IsFloatingInfoWindowVisible () == FALSE)
					pFrm->ShowFloatingInfoWindow (TRUE);
			}
			else
			{
				if (pFrm->IsFloatingInfoWindowVisible ())
					pFrm->ShowFloatingInfoWindow (FALSE);
			}
		}

		if (bRunOk)
		{
			_TrayMgr.ShowIcon (TRAY_ICON_DOWNLOADING);
		}
		else if (bRun)
		{
			if (bWaitRunOk)
				_TrayMgr.ShowIcon (TRAY_ICON_UNKNOWN);
			else
				_TrayMgr.ShowIcon (TRAY_ICON_ERRORS);
		}
		else
		{
			_TrayMgr.ShowIcon (TRAY_ICON_NORMAL);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::UpdateTrayIconPlusOthers " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::UpdateTrayIconPlusOthers unknown exception");
	}
}

void CDownloadsWnd::OnShowAllGroups()
{
	ShowAllGroups (m_bShowGroups == FALSE);
}

void CDownloadsWnd::ShowAllGroups(BOOL bShow)
{
	UINT nShow = bShow ? SW_SHOW : SW_HIDE;
	m_wndGroups.ShowWindow (nShow);
	::ShowWindow (m_splitter.m_wndSplitter, nShow);

	m_bShowGroups = bShow;
	_App.View_AllGroups (m_bShowGroups);

	RECT rc;
	GetClientRect (&rc);
	OnSize (0, rc.right, rc.bottom);

	if (bShow == FALSE)
		m_wndGroups.SelectItem (m_wndGroups.m_hAllGroups);
}

void CDownloadsWnd::OnShowDownloadingInfo()
{
	m_wndDownloads.ShowDLInfo (m_wndDownloads.m_bShowDLInfo == FALSE);
}

void CDownloadsWnd::CreateDownload(vmsDownloadSmartPtr dld, fsSchedule *task, BOOL bDontUseSounds, bool bPlaceToTop)
{
	DLDS_LIST vDlds;
	vDlds.push_back (dld);
	CreateDownloads (vDlds, task, bDontUseSounds, bPlaceToTop);
}

void CDownloadsWnd::OnNewGroupCreated (vmsDownloadsGroupSmartPtr pGroup)
{
	m_wndGroups.OnNewGroupCreated (pGroup);
}

void CDownloadsWnd::UpdateDownload(vmsDownloadSmartPtr dld, BOOL )
{
	m_wndDownloads.m_tasks.UpdateDownload (dld);
}

void CDownloadsWnd::OnDownloadsGroupChanged()
{
	if (GetCurrentFilter () && GetCurrentFilter ()->GetType () == DFT_GROUP)
		ApplyCurrentFilter ();
}

void CDownloadsWnd::DeleteDownload(vmsDownloadSmartPtr dld, BOOL bByUser, BOOL bDontConfirmFileDeleting)
{
	DLDS_LIST vpDlds;
	vpDlds.push_back (dld);
	DeleteDownloads (vpDlds, bByUser, bDontConfirmFileDeleting);
}

void CDownloadsWnd::OnSetFocus(CWnd* pOldWnd) 
{
	CWnd::OnSetFocus(pOldWnd);
	m_wndDownloads.m_tasks.SetFocus ();	
}

void CDownloadsWnd::OnDldaddsection() 
{
	m_wndDownloads.m_tasks.OnDldaddsection ();	
}

void CDownloadsWnd::OnDlddelsection() 
{
	m_wndDownloads.m_tasks.OnDlddelsection ();	
}

void CDownloadsWnd::OnDldrestart() 
{
	m_wndDownloads.m_tasks.OnDldrestart ();	
}

void CDownloadsWnd::OnDldqsize() 
{
	m_wndDownloads.m_tasks.OnDldqsize ();	
}

HWND CDownloadsWnd::Plugin_CreateMainWindow(HWND hParent)
{
	fsnew1 (_pwndDownloads, CDownloadsWnd);

	if (!_pwndDownloads->Create (CWnd::FromHandle (hParent)))
		return NULL;

	return _pwndDownloads->m_hWnd;
}

void CDownloadsWnd::Plugin_GetMenuImages(fsSetImage **ppImages, int *pcImages)
{
	static fsSetImage images [] = 
	{
		fsSetImage (ID_DLDCREATE, 0),
		fsSetImage (ID_DLDSTART, 1),
		fsSetImage (ID_DLDSTOP, 2),
		
		fsSetImage (ID_DLDMOVEUP, 4),
     	fsSetImage (ID_DLDMOVEDOWN, 5),
		fsSetImage (ID_DLDPROPERTIES, 6),
		fsSetImage (ID_DLDDELETE, 7),
		fsSetImage (ID_DLDUNPACK, 8),
	};

	*ppImages = images;
	*pcImages = sizeof (images) / sizeof (fsSetImage);
}

void CDownloadsWnd::Plugin_GetMenuViewItems(wgMenuViewItem **ppItems, int *cItems)
{
	static wgMenuViewItem aItems [] = {
		wgMenuViewItem ("", &_pwndDownloads->m_bShowGroups),
		wgMenuViewItem ("", &_pwndDownloads->m_wndDownloads.m_bShowDLInfo),
	};

	aItems [0].pszName = LS (L_DLGROUPS);
	aItems [1].pszName = LS (L_DLINFO);

	*ppItems = aItems;
	*cItems = sizeof (aItems) / sizeof (wgMenuViewItem);
}

void CDownloadsWnd::Plugin_GetPluginNames(LPCSTR *ppszLong, LPCSTR *ppszShort)
{
	static CString strName;
	strName = LSNP (L_DOWNLOADS);
	*ppszLong = *ppszShort = strName;
}

void CDownloadsWnd::Plugin_GetToolBarInfo(wgTButtonInfo **ppButtons, int *pcButtons)
{
	static wgTButtonInfo btns [] = 
	{
		wgTButtonInfo (ID_DLDCREATE, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_DLDSTART, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_DLDSTOP, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_DLDSCHEDULE, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (0, TBSTYLE_SEP, ""),
		wgTButtonInfo (ID_DLDMOVEUP, TBSTYLE_BUTTON, ""),
		wgTButtonInfo (ID_DLDMOVEDOWN, TBSTYLE_BUTTON, ""),
	};

	btns [0].pszToolTip = LS (L_NEWDLD);
	btns [1].pszToolTip = LS (L_STARTDLDS);
	btns [2].pszToolTip = LS (L_STOPDLDS);
	btns [3].pszToolTip = LS (L_SCHEDULEDLDS);
	btns [5].pszToolTip = LS (L_MOVEDLDUP);
	btns [6].pszToolTip = LS (L_MOVEDLDDOWN);

	*ppButtons = btns;
	*pcButtons = sizeof (btns) / sizeof (wgTButtonInfo);
}

void CDownloadsWnd::Plugin_SetLanguage(wgLanguage, HMENU hMenuMain, HMENU hMenuView)
{
	CMenu *menu = CMenu::FromHandle (hMenuMain);
	_pwndDownloads->m_wndDownloads.m_tasks.ApplyLanguageToMenu (menu);
	_pwndDownloads->m_wndGroups.ApplyLanguage ();
	_pwndDownloads->m_wndDownloads.ApplyLanguage ();
	_pwndDownloads->m_wndHistory.ApplyLanguage ();
	_pwndDownloads->m_wndDeleted.ApplyLanguage ();
	_pwndDownloads->ApplyLanguageToMenuView (CMenu::FromHandle (hMenuView));
}

void CDownloadsWnd::ApplyLanguageToMenuView(CMenu *menu)
{
	menu->ModifyMenu (0, MF_BYPOSITION | MF_STRING, 0, LS (L_LISTOFDLDS));
	menu->ModifyMenu (1, MF_BYPOSITION | MF_STRING, 0, LS (L_LOG));

	UINT aCmds [] = {ID_DLLIST_1, ID_DLLIST_2, ID_DLLIST_3, ID_DLLIST_4, ID_DLLIST_5, 
		ID_DLLIST_6, ID_DLLIST_7, ID_DLLIST_8, ID_DLOG_1, ID_DLOG_2, ID_DLOG_3 };
	LPCSTR apszCmds [] = {LS (L_FILENAME), LS (L_SIZE), LS (L_DOWNLOADED),
		LS (L_TIMELEFT), LS (L_SECTIONS), LS (L_SPEED), LS (L_COMMENT), LS (L_ADDED),
		LS (L_TIME), LS (L_DATE), LS (L_INFORMATION)};
	
	for (int i = 0; i < sizeof (aCmds) / sizeof (UINT); i++)
		menu->ModifyMenu (aCmds [i], MF_BYCOMMAND|MF_STRING, aCmds [i], apszCmds [i]);
}

LRESULT CDownloadsWnd::OnUpdateMenuView(WPARAM, LPARAM lp)
{
	HMENU* pMenus = (HMENU*) lp;
	UpdateDLListColMenu (CMenu::FromHandle (pMenus [0]));
	UpdateDLLogColMenu (CMenu::FromHandle (pMenus [1]));
	return 0;
}

void CDownloadsWnd::UpdateDLListColMenu(CMenu *menu)
{
	BOOL bEn = m_wndDownloads.m_tasks.GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 8; i++)
	{
		if (m_wndDownloads.m_tasks.IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_DLLIST_1+i, MF_CHECKED);
			if (bEn == FALSE)
				menu->EnableMenuItem (ID_DLLIST_1+i, MF_GRAYED);
		}
	}
}

void CDownloadsWnd::UpdateDLLogColMenu(CMenu *menu)
{
	
	BOOL bEn = m_wndDownloads.m_info.Get_LogWindow ()->GetHeaderCtrl ()->GetItemCount () > 1;
	for (int i = 0; i < 3; i++)
	{
		if (m_wndDownloads.m_info.Get_LogWindow ()->IsColumnShown (i))
		{
			menu->CheckMenuItem (ID_DLOG_1+i, MF_CHECKED);
			if (bEn == FALSE)
				
				menu->EnableMenuItem (ID_DLOG_1+i, MF_GRAYED);
		}
	}
}

void CDownloadsWnd::OnDLListShowCol(UINT uCmd)
{
	int iCol = uCmd - ID_DLLIST_1;
	m_wndDownloads.m_tasks.ChangeColumnVisibility (iCol);
}

void CDownloadsWnd::OnDLLogShowCol(UINT nCmd)
{
	int iCol = nCmd - ID_DLOG_1;
	m_wndDownloads.m_info.Get_LogWindow ()->ChangeColumnVisibility (iCol);
}

void CDownloadsWnd::FilterDownloads(fsDldFilter *filter)
{
	if (filter == NULL)
	{
		m_wndDownloads.m_tasks.DeleteAllItems ();
		return;
	}

	FilterDownloads2 (filter);
}

void CDownloadsWnd::ApplyCurrentFilter()
{
	FilterDownloads (m_wndGroups.GetCurrentFilter ());
}

fsDldFilter* CDownloadsWnd::GetCurrentFilter()
{
	return m_wndGroups.GetCurrentFilter ();
}

void CDownloadsWnd::FilterDownloads2(fsDldFilter *filter, int *pProgress)
{
	CDownloads_Tasks *pList = &m_wndDownloads.m_tasks;

	if (filter == NULL)
		return;

	while (_DldsMgr.IsDeletingNow ())
	{
#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
		MSG msg;
		while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);
#endif

		Sleep (50);
	}

	
	

	pList->LockList ();
	
	try 
	{
		pList->DeleteAllItems ();

		pList->BeginAddDownloads ();

		_DldsMgr.LockList (true);

		vmsDownloadSmartPtr dldSel;

		size_t nCount = _DldsMgr.GetCount ();

		for (size_t i = 0; i < nCount; i++)
		{
			vmsDownloadSmartPtr dld = _DldsMgr.GetDownload (i);
			if (filter->IsSatisfies (dld)) {
				pList->AddDownloadToList (dld, FALSE);
				if (dldSel == NULL)
					dldSel = dld;
			}
			if (pProgress)
				*pProgress = (int) ((double) i / (double) _DldsMgr.GetCount () * 100);
		}

		_DldsMgr.UnlockList (true);

		if (dldSel != NULL)
			pList->SelectDownload (dldSel);

	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::FilterDownloads2 " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::FilterDownloads2 unknown exception");
	}

	pList->EndAddDownloads ();
	pList->UnlockList ();
}

DWORD WINAPI CDownloadsWnd::_threadFilterDownloads(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	CDownloadsWnd* pThis = (CDownloadsWnd*) info->lpParam1;
	fsDldFilter *filter = (fsDldFilter*) info->lpParam2;
	pThis->FilterDownloads2 (filter, &info->iProgress);
	info->bWaitDone = TRUE;
	return 0;
}

void CDownloadsWnd::OnDldcreatebatch() 
{
	m_wndDownloads.m_tasks.OnDldcreatebatch ();
}

LRESULT CDownloadsWnd::OnInsert(WPARAM, LPARAM)
{
	m_wndDownloads.m_tasks.OnDldcreate ();
	return 0;
}

BOOL CDownloadsWnd::IsSizesInBytes()
{
	return m_wndDownloads.m_tasks.m_bSizesInBytes;
}

BOOL CDownloadsWnd::CreateDownloadWithDefSettings(vmsDownloadSmartPtr dld, LPCSTR pszUrl)
{
	if (dld->pMgr == NULL)
		dld->setDownloadMgr (new vmsDownloadMgrEx);

	if (dld->pMgr->GetDownloadMgr () == NULL)
	{
		ASSERT (dld->pMgr->GetBtDownloadMgr () == NULL);
		dld->pMgr->Attach (new fsDownloadMgr (dld));
	}

	if (IR_SUCCESS != dld->pMgr->GetDownloadMgr ()->CreateByUrl (pszUrl, TRUE))
		return FALSE;

	fsDownload_NetworkProperties* dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();

	fsSiteInfo *site = _SitesMgr.FindSite (dnp->pszServerName, fsNPToSiteValidFor (dnp->enProtocol));
	if (site && site->strUser != NULL && *dnp->pszUserName == 0)
		fsDNP_SetAuth (dnp, site->strUser, site->strPassword);

	CString strFolder;

	vmsDownloadsGroupSmartPtr pGroup = _DldsGrps.FindGroup (_App.NewDL_GroupId ());
	
	if (pGroup == NULL)
	{
		if (site && site->pGroup != NULL)
		{
			pGroup = site->pGroup;
		}
		else
		{
			CHAR szFile [10000];
			*szFile = 0;

			
			bool isMagnet = false;
			const char* magnetStart = _tcsstr (pszUrl, _T("magnet:"));
			if (magnetStart != 0 && pszUrl == magnetStart)
			{
				isMagnet = true;
				strcpy(szFile, pszUrl);
			}
			else
			{
				fsFileNameFromUrlPath(
					dnp->pszPathName, dnp->enProtocol == NP_FTP, TRUE, szFile, sizeof (szFile));
			}

			int len = strlen (szFile);

			if (len && isMagnet == false)
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
					pGroup = _DldsGrps.FindGroupByExt (szExt);
				}
			}
		}
	}

	if (pGroup == NULL)
		pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);

	dld->pGroup = pGroup;

	dld->bAutoStart = _App.NewDL_AutoStart ();
	if (_App.NewDL_UseZIPPreview ())
		dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags |= DPF_USEZIPPREVIEW;
	else
		dld->pMgr->GetDownloadMgr ()->GetDP ()->dwFlags &= ~DPF_USEZIPPREVIEW;

	if (strFolder.GetLength () == 0)
		strFolder = pGroup->strOutFolder;
	if (strFolder.Right (1) != '\\' && strFolder.Right (1) != '/')
		strFolder += '\\';

	SAFE_DELETE (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName);
	dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName = new char [strFolder.GetLength () + 1];
	strcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, strFolder);

	return TRUE;
}

fsDLsWndWhatIsNow CDownloadsWnd::Get_DWWN()
{
	return m_enDWWN;
}

void CDownloadsWnd::ApplyDWWN(BOOL bRecalcSize)
{
	switch (m_enDWWN)
	{
		case DWWN_LISTOFDOWNLOADS:
			m_splitter.SetWnd2 (m_wndDownloads.m_hWnd);
			break;

		case DWWN_HISTORY:
			m_splitter.SetWnd2 (m_wndHistory.m_hWnd);
			break;

		case DWWN_DELETED:
			m_splitter.SetWnd2 (m_wndDeleted.m_hWnd);
			break;

		default:
			m_enDWWN = DWWN_LISTOFDOWNLOADS;
			ApplyDWWN (bRecalcSize);
			return;
	}

	if (bRecalcSize)
		m_splitter.ApplyRatio ();

	switch (m_enDWWN)
	{
		case DWWN_LISTOFDOWNLOADS:
			m_wndHistory.ShowWindow (SW_HIDE);
			m_wndDeleted.ShowWindow (SW_HIDE);
            m_wndDownloads.ShowWindow (SW_SHOW);
			break;

		case DWWN_HISTORY:
			m_wndDownloads.ShowWindow (SW_HIDE);
			m_wndDeleted.ShowWindow (SW_HIDE);
            m_wndHistory.ShowWindow (SW_SHOW);
			break;

		case DWWN_DELETED:
			m_wndDownloads.ShowWindow (SW_HIDE);
			m_wndHistory.ShowWindow (SW_HIDE);
            m_wndDeleted.ShowWindow (SW_SHOW);
			break;
	}
}

void CDownloadsWnd::Set_DWWN(fsDLsWndWhatIsNow en)
{
	if (en != m_enDWWN)
	{
		m_enDWWN = en;
		ApplyDWWN (TRUE);
	}
}

void CDownloadsWnd::ApplyHistoryCurrentFilter()
{
	m_wndHistory.ApplyFilter (m_wndGroups.GetHistoryCurrentFilter ());
}

void CDownloadsWnd::ShowAllDownloads()
{
	m_wndGroups.SetFilter_AllDownloads ();
}

void CDownloadsWnd::SelectDownload(vmsDownloadSmartPtr dld)
{
	fsDldFilter *filter = m_wndGroups.GetCurrentFilter ();

	if (filter == NULL || filter->IsSatisfies (dld) == FALSE)
		m_wndGroups.SetGroupFilter (dld->pGroup);

	m_wndDownloads.m_tasks.SelectDownload (dld);
}

void CDownloadsWnd::FindDownloads_Start()
{
	m_finder.PrepareFind ();
	if (FALSE == m_finder.FindNext ())
		MessageBox (LS (L_THEREISNOITEMS), LS (L_FINDDONE), MB_ICONEXCLAMATION);
}

void CDownloadsWnd::FindDownloads_FindNext()
{
	if (FALSE == m_finder.FindNext ())
		MessageBox (LS (L_THEREISNOMOREITEMS), LS (L_FINDDONE), MB_ICONEXCLAMATION);
}

void CDownloadsWnd::ShowAllHistory()
{
	m_wndGroups.SetFilter_AllHistory ();
}

void CDownloadsWnd::SelectHistRecord(fsDLHistoryRecord *rec)
{
	m_wndHistory.SelectRecord (rec);
}

void CDownloadsWnd::ShowDeletedDownloads()
{
	m_wndGroups.SetFilter_DeletedDownloads ();
}

void CDownloadsWnd::SelectDeletedDownload(vmsDownloadSmartPtr dld)
{
	m_wndDeleted.SelectDownload (dld);
}

BOOL CDownloadsWnd::IsFindNextAvail()
{
	return m_finder.IsFindNextAvail ();
}

BOOL CDownloadsWnd::OnEraseBkgnd(CDC* pDC) 
{
	
	
	
	
	if (_pwndDownloads->m_wndDownloads.m_info.m_video.m_wndVideo.m_player.Get_State () != VFPS_CLOSED)
	{
    		CRect rc;

		
		_pwndDownloads->m_wndDownloads.m_info.m_video.GetWindowRect(&rc);
		ScreenToClient(&rc);

		
		pDC->ExcludeClipRect(&rc);
	}

	return CWnd::OnEraseBkgnd(pDC);
}

void CDownloadsWnd::OnDldcheckvir() 
{
	m_wndDownloads.m_tasks.OnDldcheckvir ();	
}

void CDownloadsWnd::OnDldfind() 
{
	m_wndDownloads.m_tasks.OnDldfind ();	
}

void CDownloadsWnd::OnDldfindnext() 
{
	m_wndDownloads.m_tasks.OnDldfindnext ();	
}

void CDownloadsWnd::RestartDownload(vmsDownloadSmartPtr dld, BOOL bSelThisDld)
{
	if (dld->pMgr->IsRunning () == FALSE)
	{
		dld->removeStateFlags (DLDS_FILE_WAS_LAUNCHED_AT_LEAST_ONCE);
		dld->pMgr->RestartDownloading ();

		SYSTEMTIME time;
		GetLocalTime (&time);
		SystemTimeToFileTime (&time, &dld->dateAdded);
		ZeroMemory (&dld->dateCompleted, sizeof (dld->dateCompleted));

		dld->setDirty();
		
		_DldsMgr.MoveDownloadToEndOfList (dld);

		if (-1 != m_wndDownloads.m_tasks.FindItem (dld))
		{
			
			m_wndDownloads.m_tasks.DeleteDownload (dld);
			m_wndDownloads.m_tasks.AddDownload (dld, FALSE);
		}

		if (bSelThisDld)
			SelectDownload (dld);
	}
}

void CDownloadsWnd::set_DontUpdateTIPO(BOOL b)
{
	m_bDontUpdateTIPO = b;
}

LRESULT CDownloadsWnd::OnDWCreateDldDialog(WPARAM wp, LPARAM lp)
{
	vmsDownloadSmartPtr dld = (fsDownload*) lp;

	vmsBtDownloadManager* btMgr = dld->pMgr->GetBtDownloadMgr();
	if (btMgr && btMgr->get_State() == BTDS_SERVER_INTERNAL_ERROR_500)
	{
		return 2;
	}

	dld->Release (); 

	if (_App.DownloadDialog_Use () == FALSE)
		return 2;

	if (dld->pdlg)
	{
		dld->pdlg->NeedUpdate ();
		return 1;
	}

	if (wp == 0)
	if (dld->dwFlags & (DLD_DONTSHOWDIALOG | DLD_USEDBYHTMLSPIDER | DLD_BATCH))
		return 1;

	dld->pdlg = new CDlg_Download;
	dld->pdlg->Create (dld);
	dld->pdlg->ShowWindow (SW_SHOW);

	return 0;
}

LRESULT CDownloadsWnd::OnDWCloseDldDialog(WPARAM, LPARAM lp)
{
	vmsDownloadSmartPtr dld = (fsDownload*) lp;
	dld->Release (); 
	if (dld->pdlg)
	{
		dld->pdlg->DestroyWindow ();
		SAFE_DELETE (dld->pdlg);
	}
	return 0;
}

LRESULT  CDownloadsWnd::OnDWUpdateDldDialog(WPARAM, LPARAM lp)
{
	vmsDownloadSmartPtr dld = (fsDownload*) lp;
	dld->Release (); 
	if (dld->pdlg)
	{
		if (dld->pMgr->IsRunning () == FALSE && dld->pdlg->IsDlgButtonChecked (IDC_AUTOCLOSE) == BST_CHECKED)
		{
			dld->AddRef (); 
			return OnDWCloseDldDialog (0, lp);
		}
		dld->pdlg->NeedUpdate ();
	}
	return 0;
}

void CDownloadsWnd::OnDldunpack() 
{
	m_wndDownloads.m_tasks.OnDldunpack ();	
}

UINT CDownloadsWnd::getTotalDownloadingSpeed()
{
	return m_uTotalSpeed;
}

UINT CDownloadsWnd::getTotalUploadingSpeed()
{
	vmsBtSession *pS = _BT.is_Initialized () ? _BT.get_Session () : NULL;
	return pS ? pS->get_TotalUploadSpeed () : 0;
}

void CDownloadsWnd::OnDldmovedown() 
{
	m_wndDownloads.m_tasks.OnDldmovedown ();	
}

void CDownloadsWnd::OnDldmoveup() 
{
	m_wndDownloads.m_tasks.OnDldmoveup ();	
}

void CDownloadsWnd::OnDldcheckintegrity() 
{
	m_wndDownloads.m_tasks.OnDldcheckintegrity ();	
}

LRESULT CDownloadsWnd::OnDldShowOpinions(WPARAM, LPARAM lp)
{
	CDlg_Opinions dlg;
	vmsDownloadSmartPtr dld = (fsDownload*)lp;
	dld->Release (); 
	CString strUrl;
	if (dld->pMgr->IsBittorrent ())
		strUrl = dld->pMgr->GetBtDownloadMgr ()->get_InfoHash ();
	else
		strUrl = vmsMaliciousDownloadChecker::EncodeUrl (dld->pMgr->get_URL ());
	dlg.m_pszUrl = strUrl;
	return IDC_ABORT != _DlgMgr.DoModal (&dlg);
}

DWORD WINAPI CDownloadsWnd::_threadCheckDldHasOpinions(LPVOID lp)
{
	CDownloadsWnd* pthis = (CDownloadsWnd*)lp;
	vmsDownloadSmartPtr dld = pthis->m_wndDownloads.m_info.Get_ActiveDownload ();
	vmsSimpleFileDownloader dldr;
	CString strUrl;

	if (dld == NULL)
		goto _lExit;

	strUrl.Format ("http://fdm.freedownloadmanager.org/fromfdm/checkurl.php?url=%s",
		vmsMaliciousDownloadChecker::EncodeUrl (dld->pMgr->get_URL ()));

	char szTmpPath [MY_MAX_PATH];
	char szTmpFile [MY_MAX_PATH];

	GetTempPath (sizeof (szTmpPath), szTmpPath);
	GetTempFileName (szTmpPath, "fdm", 0, szTmpFile);

	dldr.Download (strUrl, szTmpFile);
	while (pthis->m_bExiting == FALSE && dldr.IsRunning ())
		Sleep (50);

    DeleteFile (szTmpFile);

	if (pthis->m_bExiting)
		goto _lExit;

	bool bHasOpinions;
	bHasOpinions = dldr.GetLastError () == IR_SUCCESS;

	dld->dwFlags &= ~ (DLD_HASOPINIONS_YES | DLD_HASOPINIONS_NO);

	if (bHasOpinions)
		dld->dwFlags |= DLD_HASOPINIONS_YES;
	else
		dld->dwFlags |= DLD_HASOPINIONS_NO;

	dld->setDirty();

	pthis->OnDldHasOpinions (dld);	

_lExit:
	InterlockedDecrement (&pthis->m_cCheckDldHasOpinionsThreads);
	return 0;
}

void CDownloadsWnd::OnDldHasOpinions(vmsDownloadSmartPtr dld)
{
	ASSERT (dld->dwFlags & (DLD_HASOPINIONS_YES | DLD_HASOPINIONS_NO));

	if (m_wndDownloads.m_info.Get_ActiveDownload () != dld)
		return;

	if (dld->dwFlags & DLD_HASOPINIONS_YES)
		m_wndDownloads.m_info.m_opinions.UpdateContent (true);
		
}

void CDownloadsWnd::CheckDldHasOpinions(vmsDownloadSmartPtr dld)
{
	InterlockedIncrement (&m_cCheckDldHasOpinionsThreads);
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadCheckDldHasOpinions, this, 0, &dw));
}

void CDownloadsWnd::OnDldmovetofolder() 
{
	m_wndDownloads.m_tasks.OnDldmovetofolder ();	
}

void CDownloadsWnd::OnDldmovebottom() 
{
	m_wndDownloads.m_tasks.OnDldmovebottom ();	
}

void CDownloadsWnd::OnDldmovetop() 
{
	m_wndDownloads.m_tasks.OnDldmovetop ();	
}

void CDownloadsWnd::OnDldschedulestop() 
{
	m_wndDownloads.m_tasks.OnDldschedulestop ();	
}

void CDownloadsWnd::OnGroupNameChanged(vmsDownloadsGroupSmartPtr pGroup)
{
	m_wndGroups.OnGroupNameChanged (pGroup);
}

void CDownloadsWnd::DeleteDeadDownloadsInList()
{
	CDownloads_Tasks *tasks = &m_wndDownloads.m_tasks;
	int cDlds = tasks->GetItemCount ();

	DLDS_LIST vDlds;

	for (int i = 0; i < cDlds; i++)
	{
		vmsDownloadSmartPtr dld = (fsDownload*) tasks->GetItemData (i);
		if (dld->pMgr->IsDone ())
		{
			fsString strFile;
			if (dld->pMgr->GetDownloadMgr ())
				strFile = dld->pMgr->get_OutputFilePathName ();
			else 
				strFile = dld->pMgr->GetBtDownloadMgr ()->get_OutputFilePathName (0);

			if (GetFileAttributes (strFile) == DWORD (-1))
				vDlds.push_back (dld);
		}
	}

	if (vDlds.size () == 0)
		return;

	tasks->ShowWindow (SW_HIDE);
	try 
	{
		_DldsMgr.DeleteDownloads (vDlds, TRUE, FALSE);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::DeleteDeadDownloadsInList " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::DeleteDeadDownloadsInList unknown exception");
	}

	tasks->ShowWindow (SW_SHOW);
}

void CDownloadsWnd::UpdateNumbersOfDownloadsInGroups()
{
	m_wndGroups.UpdateNumbersOfDownloadsInGroups ();
}

void CDownloadsWnd::OnBtDownloadProperties(DLDS_LIST &vDlds, CWnd *pwndParent)
{
	CBtDldSheet sheet (LS (L_DLDPROP), pwndParent ? pwndParent : this);

	sheet.Init (&vDlds);
  
	if (_DlgMgr.DoModal (&sheet) == IDOK)
	{
		
		if (sheet.IsNeedUpdateTasks ())
			OnDownloadsGroupChanged ();

		
	}

    _DlgMgr.OnEndDialog (&sheet);
}

void CDownloadsWnd::OnTpDownloadProperties(DLDS_LIST &vDlds, CWnd *pwndParent)
{
	
	CTpDldSheet sheet (LS (L_DLDPROP), pwndParent ? pwndParent : this);

	sheet.Init (&vDlds);

    _DlgMgr.OnDoModal (&sheet);

	if (sheet.DoModal () == IDOK)
	{
		
		if (sheet.IsNeedUpdateTasks ())
			OnDownloadsGroupChanged ();
	}

    _DlgMgr.OnEndDialog (&sheet);
}

BOOL CDownloadsWnd::CreateBtDownload(
	LPCTSTR pszFile, 
	LPCTSTR pszTorrentUrl, 
	BOOL bSilent, 
	BOOL bSeedOnly, 
	LPCTSTR pszOutputOrSrcForSeedFolder, 
	LPCTSTR ptszUserName, 
	LPCTSTR ptszPassword, 
	int* pnProirities,
	vmsBtFile* tempTorrent,
	UINT *pnDownloadId)
{
	if (bSeedOnly)
	{
		ASSERT (bSilent);
		bSilent = TRUE;
	}

	ASSERT (pszOutputOrSrcForSeedFolder == NULL || bSilent != FALSE);

	vmsDownloadSmartPtr dld;
	Download_CreateInstance (dld, true);
	dld->dwFlags |= DLD_TORRENT_DOWNLOAD;

	if (_App.ReserveDiskSpace ())
		dld->pMgr->GetBtDownloadMgr ()->enable_Flags (BTDF_RESERVE_DISK_SPACE);
	if (_App.DownloadFlags () & DPF_GENERATEDESCFILE)
		dld->pMgr->GetBtDownloadMgr ()->enable_Flags (BTDF_GENERATE_DESC_FILE);
	if (_App.DownloadFlags () & DPF_STARTWHENDONE)
		dld->pMgr->GetBtDownloadMgr ()->enable_Flags (BTDF_LAUNCH_WHEN_DONE);

	BOOL bPlaceToTop = FALSE;

	if (_App.NewDL_GroupId () != -1)
		dld->pGroup = _DldsGrps.FindGroup (_App.NewDL_GroupId ());
	if (dld->pGroup == NULL)
		dld->pGroup = _DldsGrps.FindGroupByExt ("torrent");
	if (dld->pGroup == NULL)
		dld->pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);
	dld->bAutoStart = _App.NewDL_AutoStart ();

	vmsBtDownloadManager *pMgr = dld->pMgr->GetBtDownloadMgr ();

	BOOL isMagnet = FALSE;
	const char* magnetStart = _tcsstr (pszFile, _T("magnet:"));
	if (magnetStart != 0 && pszFile == magnetStart)
	{
		isMagnet = TRUE;
	}

	LPCTSTR outputPath = pszOutputOrSrcForSeedFolder ? pszOutputOrSrcForSeedFolder : dld->pGroup->strOutFolder;

	BOOL result = FALSE;
	if (isMagnet == FALSE)
	{
		CString tstrTorrentUrl;
		if (isMagnet == FALSE && (pszTorrentUrl == NULL || *pszTorrentUrl == 0))
		{
			tstrTorrentUrl = _T ("file://");
			tstrTorrentUrl += pszFile;
			pszTorrentUrl = tstrTorrentUrl;
		}

		result = pMgr->CreateByTorrentFile (pszFile, outputPath, pszTorrentUrl, bSeedOnly);
	}
	else
	{
		if (tempTorrent != NULL && tempTorrent->IsMagnetLink())
		{
			result = pMgr->CreateByMagnetMetadata(tempTorrent, outputPath);
		}
		else
		{
			result = pMgr->CreateByMagnetLink(pszFile, outputPath);
		}
	}
	if (result == FALSE)
	{
		return FALSE;
	}

	if (NULL != _DldsMgr.findBtDownloadByHash (pMgr))
	{
		onBtDownloadWithSameInfoHashExistsAlready ();
		return FALSE;
	}

	fsString strComment = pMgr->get_TorrentComment ();
	if (strComment.IsEmpty () == FALSE)
	{
		if (dld->strComment.IsEmpty () == FALSE)
			dld->strComment += "\r\n";
		dld->strComment += strComment;
	}

	if (!bSilent)
	{
		CCreateDownloadFromTorrentFileDlg dlg;
		dlg.m_ptszTorrentFile = pszFile;

		dlg.m_dld = dld;
		if (IDOK != _DlgMgr.DoModal (&dlg))
			return FALSE;

		
		if (NULL != _DldsMgr.findBtDownloadByHash (pMgr))
		{
			onBtDownloadWithSameInfoHashExistsAlready ();
			return FALSE;
		}

		bPlaceToTop = dlg.m_bPlaceToTop;

		CreateDownload (dld, dlg.m_bScheduled ? &dlg.m_schScheduleParam.schTask : NULL, FALSE, dlg.m_bPlaceToTop != 0);
	}
	else
	{
		CreateDownload (dld, NULL, FALSE, false);
	}

	if (_pwndTorrents)
		_pwndTorrents->AddDownload (dld, bPlaceToTop);
	
	if (bSeedOnly)
		dld->pMgr->GetBtDownloadMgr ()->EnableSeeding (TRUE);

	if (pnDownloadId)
		*pnDownloadId = dld->nID;
	
	return TRUE;
}

void CDownloadsWnd::OnDldgrantbandwidthfordld() 
{
	m_wndDownloads.m_tasks.OnDldgrantbandwidthfordld ();	
}

void CDownloadsWnd::OnDldshowprogressdlg() 
{
	m_wndDownloads.m_tasks.OnDldshowprogressdlg ();	
}

void CDownloadsWnd::ShowDownloads(DLDS_LIST_REF vDlds)
{
	m_wndDownloads.m_tasks.LockList ();

	try
	{
		fsDldFilter *filter = m_wndGroups.GetCurrentFilter ();
		
		
		BOOL bNeedAdd = filter != NULL && filter->IsSatisfies (vDlds [0]);

		if (bNeedAdd == FALSE)
		{
			m_wndDownloads.m_tasks.UnlockList ();
			m_wndGroups.SetGroupFilter (vDlds [0]->pGroup);
			m_wndDownloads.m_tasks.LockList ();
		}
		m_wndDownloads.m_tasks.SelectDownload (vDlds [0]);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::ShowDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::ShowDownloads unknown exception");
	}

	m_wndDownloads.m_tasks.UnlockList ();
}

int CDownloadsWnd::DeleteDownloads(DLDS_LIST_REF v, BOOL bByUser, BOOL bDontConfirmFileDeleting)
{
	int nRes = 0;
	m_wndDownloads.m_tasks.ShowWindow (SW_HIDE);
	try 
	{
		nRes = _DldsMgr.DeleteDownloads (v, bByUser, bDontConfirmFileDeleting);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::DeleteDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::DeleteDownloads unknown exception");
	}

	UpdateTrayIconPlusOthers ();
	m_wndDownloads.m_tasks.UpdateActiveDownload (0);
	m_wndDownloads.m_tasks.ShowWindow (SW_SHOW);
	return nRes;
}

LRESULT CDownloadsWnd::OnDldConvertMedia(WPARAM wp, LPARAM lp)
{
	vmsDownloadSmartPtr dld = (fsDownload*) lp;
	dld->Release ();

	_MediaConvertMgr.ConvertMediaFile (dld, (vmsMediaConvertMgr_OptionsSource)wp);

	return 0;
}

void CDownloadsWnd::OnDldconvert() 
{
	m_wndDownloads.m_tasks.OnDldconvert ();
}

BOOL CDownloadsWnd::IsMediaDownload(vmsDownloadSmartPtr dld)
{
	fsString strFile = dld->pMgr->get_OutputFilePathName ();
	LPCSTR pszExt = strrchr (strFile, '.');
	if (pszExt++ == NULL)
		return FALSE;
	return IsExtInExtsStr (vmsDownloadsGroupsMgr::GetVideoExts (), pszExt) ||
		IsExtInExtsStr (vmsDownloadsGroupsMgr::GetAudioExts (), pszExt);
}

HMENU CDownloadsWnd::Plugin_GetMainMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_DOWNLOADS));
}

HMENU CDownloadsWnd::Plugin_GetViewMenu()
{
	return LoadMenu (AfxGetInstanceHandle (), MAKEINTRESOURCE (IDM_DL_VIEW));
}

void CDownloadsWnd::OnDldenableseeding() 
{
	m_wndDownloads.m_tasks.OnDldenableseeding ();	
}

BOOL CDownloadsWnd::CreateNewTorrent()
{
	if (vmsBtSupport::getBtDllVersion () < 778)
		return FALSE;
	CDlg_CreateNewTorrent dlg; 
	_DlgMgr.DoModal (&dlg);
	return TRUE;
}

LRESULT CDownloadsWnd::OnWmDldLaunch(WPARAM wp, LPARAM lp)
{
	fsDownload *dld = (fsDownload*)lp;
	_DldsMgr.LaunchDownload (dld, wp);
	dld->Release ();
	return 0;
}

void CDownloadsWnd::OnBtDownloadDefProperties()
{
	CBtDldSheet sheet (LS (L_ADVANCED), this);
	DLDS_LIST v;
	vmsDownloadSmartPtr dld;
	Download_CreateInstance (dld, true);
	dld->pMgr->GetBtDownloadMgr ()->setRequiredRatio (_App.Bittorrent_RequiredRatio ());
	
	v.push_back (dld);
	sheet.Init (&v, BTDS_SEEDING_PAGE);
	if (IDCANCEL == _DlgMgr.DoModal (&sheet))
		return;

	_App.Bittorrent_RequiredRatio (dld->pMgr->GetBtDownloadMgr ()->getRequiredRatio ());
	_App.Bittorrent_DisableSeedingByDef (
		dld->pMgr->GetBtDownloadMgr ()->get_Flags () & BTDF_DISABLE_SEEDING);
}

void CDownloadsWnd::BeginCreateDownloads()
{
	vmsAUTOLOCKSECTION (m_csDownloadsHasBeenAdded);
	m_bCreatingLotOfDownloads = true;
}

void CDownloadsWnd::EndCreateDownloads()
{
	vmsAUTOLOCKSECTION (m_csDownloadsHasBeenAdded);

	m_bCreatingLotOfDownloads = false;

	if (m_vDownloadsHasBeenAdded.empty ())
		return;

	DLDS_LIST v = m_vDownloadsHasBeenAdded;
	bool bPlaceToTop = m_bDownloadsHasBeenAddedToTop;
	BOOL bDontUseSounds = m_bDontUseSoundsForDownloadsHasBeenJustAdded;
	m_vDownloadsHasBeenAdded.clear ();

	vmsAUTOLOCKSECTION_UNLOCK (m_csDownloadsHasBeenAdded);

	onDownloadsHasBeenAdded (v, bPlaceToTop, bDontUseSounds);
}

LRESULT CDownloadsWnd::OnWmDwDldsAdded (WPARAM wp, LPARAM lp)
{
	WmDwDldsAdded *p = (WmDwDldsAdded*)lp;
	onDownloadsHasBeenAdded_imp (p->vDlds, p->bPlaceToTop, p->bDontUseSounds);
	delete p;
	return 0;
}

void CDownloadsWnd::onDownloadsHasBeenAdded_imp(DLDS_LIST &vDlds, bool bPlaceToTop, BOOL bDontUseSounds)
{
	if (vDlds.empty ())
		return;

	m_wndDownloads.m_tasks.LockList ();

	fsDldFilter *filter = m_wndGroups.GetCurrentFilter ();
	
	
	BOOL bNeedAdd = filter != NULL && filter->IsSatisfies (vDlds [0]);
	
	BOOL bNeedShow = (vDlds [0]->dwFlags & (DLD_USEDBYHTMLSPIDER | DLD_NOAUTOCHANGECURGRPFILTER)) == 0;

	if (bNeedAdd == FALSE)
	{
		if (bNeedShow)
		{			
			m_wndDownloads.m_tasks.UnlockList ();
			m_wndGroups.SetGroupFilter (vDlds [0]->pGroup);
			m_wndDownloads.m_tasks.LockList ();
			m_wndDownloads.m_tasks.SelectDownload (vDlds [0]);
		}
	}
	else
	{
		m_wndDownloads.m_tasks.BeginAddDownloads ();

		for (size_t i = 0; i < vDlds.size (); i++)
			m_wndDownloads.m_tasks.AddDownloadToList (vDlds [i], FALSE, bPlaceToTop);	

		m_wndDownloads.m_tasks.EndAddDownloads ();

		if (bNeedShow)
			m_wndDownloads.m_tasks.SelectDownload (bPlaceToTop ? vDlds [0] : vDlds [vDlds.size () - 1]);
	}

	m_wndDownloads.m_tasks.UnlockList ();

    if (bDontUseSounds == FALSE)
      	_Snds.Event (SME_DOWNLOADADDED);

	_DldsMgr.setNeedProcessDownloads ();

	UpdateNumbersOfDownloadsInGroups ();
}

void CDownloadsWnd::onDownloadsHasBeenAdded(DLDS_LIST &vDlds, bool bPlaceToTop, BOOL bDontUseSounds)
{
	WmDwDldsAdded *p = new WmDwDldsAdded;
	p->vDlds = vDlds;
	p->bPlaceToTop = bPlaceToTop;
	p->bDontUseSounds = bDontUseSounds != FALSE;
	PostMessage (WM_DW_ONDLDSADDED, 0, (LPARAM)p);
}

LRESULT CDownloadsWnd::OnShowOnDlDoneNotification(WPARAM wp, LPARAM lp)
{
	vmsDownloadSmartPtr dld = (fsDownload*) lp;
	dld->Release (); 

	CWndDlDoneNotification *pwnd = new CWndDlDoneNotification;
	pwnd->Create (dld);

	return (LRESULT)0;
}

UINT CDownloadsWnd::CreateDownload(vmsNewDownloadInfo *pDld, BOOL bReqTopMostDialog)
{
	return CreateDownload (pDld->strUrl, bReqTopMostDialog, 
		pDld->strComment.IsEmpty () ? NULL : (LPCSTR)pDld->strComment, 
		pDld->strReferer.IsEmpty () ? NULL : (LPCSTR)pDld->strReferer,
		pDld->bAddSilent, pDld->dwForceAutoLaunch, 
		pDld->dwWhatIsValid & NDIV_AUTOSTART ? &pDld->bAutoStart : NULL,
		pDld->dwWhatIsValid & NDIV_AP ? &pDld->ap : NULL, pDld->pnCreateNewDownloadResult);
}

void CDownloadsWnd::onEvents(fsDownload* dld, fsDLHistoryRecord *rec, fsDownloadsMgrEvent ev, int iDldLogEntry)
{
	if (m_bExiting)
		return;

	BOOL bUpdateTIPO = TRUE;
	bool bApplyNotGroupFilterForDownload = dld != NULL;

	try 
	{
		switch (ev)
		{
		case DME_DOWNLOADEREVENTRECEIVED:
		case DME_DOWNLOAD_STATE_CHANGED:
			ASSERT (dld != NULL);
			
			m_wndDownloads.m_tasks.UpdateDownload (dld);
			m_wndDownloads.m_info.m_video.m_vidman.Update ();
			if (dld->dwFlags & DLD_FLASH_VIDEO)
			{
				_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
				_pwndFVDownloads->m_wndPreview.m_vidman.Update ();
			}
			if (_pwndTorrents && dld->isTorrent ())
				_pwndTorrents->m_wndTasks.UpdateDownload (dld);
			break;

		case DME_EVENTDESCRIPRIONRECEIVED:
			ASSERT (dld != NULL);
			
			if (dld == m_wndDownloads.m_tasks.GetActiveDownload ())
				
				m_wndDownloads.m_info.AddDownloadEvent (&dld->vEvents [iDldLogEntry]);

			
			m_wndDownloads.m_tasks.UpdateDownload (dld);
			if (dld->dwFlags & DLD_FLASH_VIDEO)
				_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
			if (_pwndTorrents && dld->isTorrent ())
				_pwndTorrents->m_wndTasks.UpdateDownload (dld);
			break;

		case DME_DOWNLOADWILLBEDELETED:
			ASSERT (dld != NULL);

			if (m_bDeletingManyDownloads == false)
			{
				m_wndDownloads.m_tasks.WillBeDeleted (dld);
				if (dld->dwFlags & DLD_FLASH_VIDEO)
					_pwndFVDownloads->m_wndTasks.WillBeDeleted (dld);
				if (_pwndTorrents && dld->isTorrent ())
					_pwndTorrents->m_wndTasks.WillBeDeleted (dld);
			}

			bApplyNotGroupFilterForDownload = false;
			bUpdateTIPO = FALSE;
			break;

		case DME_DLDAUTODELETED:
			m_wndDownloads.m_tasks.UpdateActiveDownload (0);
			break;

		case DME_DOWNLOADFILEWILLBEDELETED:
			m_wndDownloads.m_info.m_video.Stop ();
			bUpdateTIPO = FALSE;
			bApplyNotGroupFilterForDownload = false;
			break;

		case DME_NOACTIVEDOWNLOADS:
			if (m_bExiting == FALSE)
			{
				
				_pwndScheduler->GetMgr ()->ExciteEvent (EV_NODOWNLOADS);
				
				_Snds.Event (SME_NOACTIVEDOWNLOADS);
			}
			break;

		case DME_FILEUPDATED:
			ASSERT (dld != NULL);
			m_wndDownloads.m_tasks.UpdateDownload (dld);
			if (dld->dwFlags & DLD_FLASH_VIDEO)
				_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
			if (_pwndTorrents && dld->isTorrent ())
				_pwndTorrents->m_wndTasks.UpdateDownload (dld);
			m_wndDownloads.m_info.m_video.m_vidman.Update ();
			((CMainFrame*)AfxGetApp ()->m_pMainWnd)->RebuidDownloadsList ();
			bUpdateTIPO = FALSE;
			break;

		case DME_CREATEDLDDIALOG:
			ASSERT (dld != NULL);
			dld->AddRef (); 
			PostMessage (WM_DW_CREATEDLDDIALOG, 0, (LPARAM)dld);
			bUpdateTIPO = FALSE;
			break;

		case DME_UPDATEDLDDIALOG:
			ASSERT (dld != NULL);
			dld->AddRef (); 
			PostMessage (WM_DW_UPDATEDLDDIALOG, 0, (LPARAM)dld);
			bUpdateTIPO = FALSE;
			break;

		case DME_CLOSEDLDDIALOG:
			ASSERT (dld != NULL);
			dld->AddRef (); 
			PostMessage (WM_DW_CLOSEDLDDIALOG, 0, (LPARAM)dld);
			bUpdateTIPO = FALSE;
			break;

		case DME_REDIRECTED:
			ASSERT (dld != NULL);
			m_wndDownloads.m_tasks.UpdateDownload (dld);
			if (dld->dwFlags & DLD_FLASH_VIDEO)
				_pwndFVDownloads->m_wndTasks.UpdateDownload (dld);
			if (_pwndTorrents && dld->isTorrent ())
				_pwndTorrents->m_wndTasks.UpdateDownload (dld);
			m_wndDownloads.m_info.m_video.m_vidman.Update ();
			((CMainFrame*)AfxGetApp ()->m_pMainWnd)->RebuidDownloadsList ();
			bUpdateTIPO = FALSE;
			break;

		case DME_DLDSAUTOSTARTMDFD:
			m_wndDownloads.m_tasks.Invalidate (FALSE);
			if (_pwndFVDownloads)
				_pwndFVDownloads->m_wndTasks.Invalidate (FALSE);
			if (_pwndTorrents)
				_pwndTorrents->m_wndTasks.Invalidate (FALSE);
			break;

		case DME_DOWNLOADSTOPPEDORDONE:
			{
				ASSERT (dld != NULL);

				((CMainFrame*)AfxGetApp ()->m_pMainWnd)->RebuidDownloadsList ();
				BOOL bNoBalloon = FALSE;

				char szFile [MY_MAX_PATH];
				CDownloads_Tasks::GetFileName (dld, szFile);

				tstring tstrMsg;
				bool bOnDoneBalloon = false;

				if (dld->pMgr->IsDone ())
				{
					bOnDoneBalloon = true;
					tstrMsg = LS (L_DONE);

					bool bNotif = true; 

					if (dld->dwFlags & DLD_NOTIFICATIONS_LL)
						bNotif = false;
					else if ((dld->dwFlags & DLD_BATCH) && _App.Notif_DisableForBatchDownloads ())
						bNotif = false;

					if (bNotif)
						_Snds.Event (SME_DOWNLOADCOMPLETE);
					else
						bNoBalloon = TRUE;

					if (m_wndDownloads.m_info.Get_ActiveDownload () == dld)
					{
						BOOL bDontSwitchToMedia = FALSE;

						if (m_wndDownloads.m_info.get_CurTab () == DIT_OPINIONS)
							m_wndDownloads.m_info.m_opinions.UpdateContent ();
						else if (_App.Community_SwitchToOpinions ())
						{
							m_wndDownloads.m_info.m_opinions.UpdateContent (true);
							bDontSwitchToMedia = TRUE;
						}

						if (bDontSwitchToMedia == FALSE && _App.View_AutoSwitchToMediaPreview ())
						{
							if (IsMediaDownload (dld))
								m_wndDownloads.m_info.set_CurTab (DIT_MEDIAPREVIEW);
						}
					}
				}
				else if (dld->pMgr->IsStoppedByUser ())
				{
					
					
					break;
				}
				else
				{
					if (dld->bAutoStart == FALSE)
					{
						tstrMsg = LS (L_STOPPED);
						if (!dld->tstrLastErrMsg.empty ()) {
							tstrMsg += _T ("\n");
							tstrMsg += dld->tstrLastErrMsg;
						}
						_Snds.Event (SME_DOWNLOADFAILED);
					}
					else
					{
						tstrMsg = LS (L_WAITING);
						if (dld->dwFlags & DLD_NOTIFICATIONS_LL)
							bNoBalloon = TRUE;
						else if ((dld->dwFlags & DLD_BATCH) && _App.Notif_DisableForBatchDownloads ())
							bNoBalloon = TRUE;
					}
				}

				if (bNoBalloon == FALSE)
				{
					bool bShowUsualBalloon = true;

					if (bOnDoneBalloon)
					{
						if (_App.Notif_UseOnDoneWnds ())
						{
							dld->AddRef (); 
							PostMessage (WM_DLD_SHOW_ON_DONE_NOTIFICATION, 0, (LPARAM)(fsDownload*)dld);
							bShowUsualBalloon = false;
							
						}
					}

					if (bShowUsualBalloon)
					{
						CString str;
						str.Format ("%s - %s", szFile, tstrMsg.c_str ());
						CMainFrame::ShowTimeoutBalloon (str, vmsFdmAppMgr::getAppName ());
					}
				}
			}
			break;

		case DME_SECTIONDOWNLOADING:
			ASSERT (dld != NULL);
			if (dld == m_wndDownloads.m_info.Get_ActiveDownload () &&
				dld->pMgr->GetDownloadingSectionCount () == 1)
			{
				if (_App.Community_DisplayOpinionsAtDlding ())
				{
					if (dld->dwFlags & DLD_HASOPINIONS_YES)
						OnDldHasOpinions (dld);
					else if ((dld->dwFlags & DLD_HASOPINIONS_NO) == 0)
						CheckDldHasOpinions (dld);
				}

				if (_App.View_AutoSwitchToMediaPreview ())
				{
					if (IsMediaDownload (dld))
						m_wndDownloads.m_info.set_CurTab (DIT_MEDIAPREVIEW);
				}
			}
			break;

		case DME_DOWNLOADWASDELETEDFROMLIST:
			bApplyNotGroupFilterForDownload = false;
			
		case DME_SECTIONSTARTED:
		case DME_DLMGRTHREADSTARTING:
			if (m_bDeletingManyDownloads == false)
				((CMainFrame*)AfxGetApp ()->m_pMainWnd)->RebuidDownloadsList ();
			
			
			break;

		case DME_DLDADDEDTODELETED:
			ASSERT (dld != NULL);
			m_wndDeleted.AddDownload (dld);
			m_wndGroups.UpdateDeletedIcon ();
			bApplyNotGroupFilterForDownload = false;
			bUpdateTIPO = FALSE;
			break;

		case DME_RECYCLEBINCONTENTCHANGED:
			m_wndGroups.UpdateDeletedIcon ();
			bUpdateTIPO = FALSE;
			break;

		case DME_DLDREMOVEDFROMDELETED:
			ASSERT (dld != NULL);
			m_wndDeleted.RemoveDownload (dld);
			bApplyNotGroupFilterForDownload = false;
			bUpdateTIPO = FALSE;
			break;

		case DME_DLDRESTORED:
			ASSERT (dld != NULL);
			fsDldFilter *filter;
			filter = m_wndGroups.GetCurrentFilter ();

			if (filter)
			{
				if (filter->IsSatisfies (dld))	
					m_wndDownloads.m_tasks.AddDownloadToList (dld, FALSE);	
			}

			_pwndSpider->GetMgr ()->OnDownloadRestored (dld);
			bUpdateTIPO = FALSE;
			break;

		case DME_RECADDEDTOHISTORY:
			fsDldHistRecFilter* f;
			f = m_wndGroups.GetHistoryCurrentFilter ();
			if (f && f->IsSatisfies (rec))
				m_wndHistory.AddRecord (rec);
			bUpdateTIPO = FALSE;
			break;

		case DME_RECDELETEDFROMHISTORY:
			m_wndHistory.DeleteRecord (rec);
			bUpdateTIPO = FALSE;
			break;

		case DME_HISTORYCLEARED:
			m_wndHistory.DeleteAllRecords ();
			bUpdateTIPO = FALSE;
			break;

		case DME_DLDWILLBEFULLYDELETED:
			bApplyNotGroupFilterForDownload = false;
			bUpdateTIPO = FALSE;
			break;

		case DME_BEGINDELETEMANYDOWNLOADS:
			m_bDeletingManyDownloads = true;
			bUpdateTIPO = FALSE;
			break;

		case DME_ENDDELETEMANYDOWNLOADS:
			m_bDeletingManyDownloads = false;
			ApplyCurrentFilter ();
			((CMainFrame*)AfxGetApp ()->m_pMainWnd)->RebuidDownloadsList ();
			bUpdateTIPO = FALSE;
			break;

		case DME_BTDLD_STAT_CHANGED:
			ASSERT (dld != NULL);
			if (dld == m_wndDownloads.m_info.Get_ActiveDownload ())
				m_wndDownloads.m_info.UpdateBtStat ();
			if (_pwndTorrents && dld == _pwndTorrents->m_wndBtTab.getActiveDownload ())
				_pwndTorrents->m_wndBtTab.UpdateStat ();
			break;

		case DME_DLD_CHANGED_TO_BT_TYPE:
			ASSERT (dld != NULL);
			if (_pwndTorrents && dld == _pwndTorrents->m_wndTasks.getActiveDownload  ())
				_pwndTorrents->SetActiveDownload (dld);
			break;
		}

		if (bApplyNotGroupFilterForDownload)
			m_wndGroups.ApplyNotGroupFilterForDownload (dld);

		if (bUpdateTIPO)
			UpdateTrayIconPlusOthers ();

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::onEvents " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("CDownloadsWnd::onEvents unknown exception");
	}
}

LRESULT CDownloadsWnd::OnDwDldsMgrEvent(WPARAM wp, LPARAM lp)
{
	size_t nEvent = 0;

	for (;;)
	{
		vmsAUTOLOCKSECTION (m_csDldsMgrEvents);
		if (m_vDldsMgrEvents.size () <= nEvent)
		{
			m_vDldsMgrEvents.clear ();
			return 0;
		}
		DwDldsMgrEventParam param = m_vDldsMgrEvents [nEvent++];
		vmsAUTOLOCKSECTION_UNLOCK (m_csDldsMgrEvents);
		onEvents (param.dld, param.rec, param.ev, param.iDldLogEntry);
	}
}

void CDownloadsWnd::OnDownloadPreCreate(fsDownload* dld, vmsDWCD_AdditionalParameters* pParams)
{
	OnDownloadPreCreate_AdjustFileSharingSiteSupport (dld, pParams);
}

void CDownloadsWnd::OnDownloadPreCreate_AdjustFileSharingSiteSupport(fsDownload* dld, vmsDWCD_AdditionalParameters* pParams)
{
	

	if (!dld->pMgr->GetDownloadMgr ())
		return;

	LPCSTR pszKnownSite = isKnownFileSharingSite (dld);
	if (!pszKnownSite)
		return;

	fsDownloadMgr *pMgr = dld->pMgr->GetDownloadMgr ();

	
	pMgr->GetDNP ()->dwFlags |= DNPF_IMMEDIATELY_SEND_AUTH_AS_BASIC;
	pMgr->setDirty();

	if (!strcmp (pszKnownSite, "filesonic.com"))
	{
		if (pParams)
		{
			if (!pParams->strOriginalUrl.IsEmpty ())
				fsDNP_ApplyUrl (pMgr->GetDNP (), pParams->strOriginalUrl);
			if (!pParams->strUserAgent.IsEmpty ())
			{
				SAFE_DELETE_ARRAY (pMgr->GetDNP ()->pszAgent);
				pMgr->GetDNP ()->pszAgent = new char [pParams->strUserAgent.GetLength () + 1];
				strcpy (pMgr->GetDNP ()->pszAgent, pParams->strUserAgent);
			}
		}
		pMgr->GetDNP ()->dwFlags |= DNPF_DONT_UPDATE_ORIGINAL_URL_AFTER_REDIRECT;
		pMgr->setDirty();
	}
}

LPCSTR CDownloadsWnd::isKnownFileSharingSite(fsDownload* dld)
{
	static LPCSTR apszKnownSites [] = {
		"rapidshare.com", "filesonic.com"
	};

	LPCSTR pszHost = dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszServerName;
	int nHostNameLen = strlen (pszHost);

	for (int i = 0; i < _countof (apszKnownSites); i++)
	{
		LPCSTR pszKnownSite = apszKnownSites [i];
		int nKnownSiteNameLen = strlen (pszKnownSite);

		if (strcmp (pszKnownSite, pszHost) == 0)
			return apszKnownSites [i];
		
		if (nHostNameLen > nKnownSiteNameLen+1 && 
				pszHost [nHostNameLen - nKnownSiteNameLen - 1] == '.' &&
				strcmp (pszHost + nHostNameLen - nKnownSiteNameLen, pszKnownSite) == 0)
			return apszKnownSites [i];
	}

	return NULL;
}

void CDownloadsWnd::OnDownloadPostCreate(fsDownload* dld)
{
	
}

void CDownloadsWnd::onBtDownloadWithSameInfoHashExistsAlready ()
{
	PostMessage (WM_DW_ONSUCHTORRENTEXISTSALREADY);
}

LRESULT CDownloadsWnd::OnDwSuchTorrentExistsAlready (WPARAM, LPARAM)
{
	MessageBox (LS (L_SUCHTORRENTEXISTSALREADY), NULL, MB_ICONEXCLAMATION);
	return 0;
}