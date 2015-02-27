/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsDownloadsMgr.h"
#include "inetutil.h"
#include "mfchelp.h"
#include "vmsRegisteredApp.h"

#ifndef FDM_DLDR__RAWCODEONLY
#include "DDRDlg.h"
#include "WaitDlg.h"
#include "ZipPreviewDlg.h"
#include "WaitForConfirmationDlg.h"
#include "WaitForConfirmationDlg.h"
#include "DownloadsWnd.h"
#include "UIThread.h"
#endif

#include "fsSitesMgr.h"
#include "misc.h"
#include "system.h"
#include "vmsFilesToDelete.h"
#include "Hash\vmsHash.h"
#include "Dlg_CheckFileIntegrity_Result.h"
#include "vmsMetalinkFile.h"
#include "Dlg_Download.h"
#include "MyMessageBox.h"
#include "vmsVideoSiteHtmlCodeParser.h"
#include "FlashVideoDownloadsWnd.h"
#include "TorrentsWnd.h"
#include <Iphlpapi.h>
#include "Utils.h"
#include "QueryStoringServiceInfoGuard.h"
#include "vmsLogger.h"

#ifndef FDM_DLDR__RAWCODEONLY
extern CDownloadsWnd* _pwndDownloads;
#endif

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

using namespace fsArchive;

const double DLD_HP_START_COEFF = 3.0;

fsDownloadsMgr::fsDownloadsMgr()
{
	m_errorTimeouts[vmsBtDownloadErrorState::BTDES_BAD_REQUEST_400] = 0;
	m_errorTimeouts[vmsBtDownloadErrorState::BTDES_SERVER_INTERNAL_ERROR_500] = 10 * 1000;

	m_bShuttingDown = FALSE;

	m_ticksNeedStartProcessDownloads.m_dwTicks = m_ticksNeedStartApplyTrafficLimit.m_dwTicks = 
		m_ticksNeedCheckNoActiveDownloads.m_dwTicks = 0;

	m_hevShuttingDown = CreateEvent (NULL, TRUE, FALSE, NULL);

	m_pfnEvents = NULL;
	m_cThreadsRunning = 0;

	m_bSkip1Cicle = FALSE;
	
	

	m_bAllowStart = TRUE;
	m_bDisablePD = FALSE;
	
	m_bDeletingNow = m_bDeletingDeletedNow = m_bRestoringNow = FALSE;

#ifndef FDM_DLDR__RAWCODEONLY
	m_histmgr.SetEventFunc (_HistoryMgrEvents, this);
#endif

	fsInternetSession::InitializeWinInet ();

	m_bIsDownloadListChanged = false;
	m_bIsDeletedDownloadListChanged = false;
	
	m_hevNeedDispatchEvents = CreateEvent (NULL, FALSE, FALSE, NULL);
	DWORD dw;
	m_htEventsDispatcher = CreateThread (NULL, 0, _threadEventsDispatcher, this, 0, &dw);
}

fsDownloadsMgr::~fsDownloadsMgr()
{
	vmsAUTOLOCKSECTION (m_csShuttingDown);
	m_bShuttingDown = TRUE;
	vmsAUTOLOCKSECTION_UNLOCK (m_csShuttingDown);

	SetEvent (m_hevShuttingDown);
	WaitForSingleObject (m_htEventsDispatcher, INFINITE);

	while (m_cThreadsRunning)
		Sleep (10);
}

UINT fsDownloadsMgr::Add(vmsDownloadSmartPtr dld, BOOL bKeepIDAsIs, bool bPlaceToTop)
{
	
	if (dld->pMgr->GetDownloadMgr () != NULL)
	{
		dld->pMgr->GetDownloadMgr ()->SetEventFunc (_DownloadMgrEvents, this);
		dld->pMgr->GetDownloadMgr ()->SetEventDescFunc (_DownloadMgrEventDesc, this);
		dld->pMgr->GetDownloadMgr ()->set_Download (dld);
	}
	else if (dld->pMgr->GetBtDownloadMgr () != NULL)
	{
		dld->pMgr->GetBtDownloadMgr ()->SetEventsHandler (_BtDownloadManagerEventHandler, this);
	}
	else if (dld->pMgr->GetTpDownloadMgr () != NULL)
	{
		dld->pMgr->GetTpDownloadMgr ()->SetEventsHandler (_TpDownloadManagerEventHandler, this);
		dld->pMgr->GetTpDownloadMgr ()->SetEventDescFunc (_TpDownloadManagerEventDesc, this);
	}

	dld->pMgr->UseDetailedLog (m_bDetLog);
	
	if (bKeepIDAsIs == FALSE) 
	{
		
		
		dld->nID = m_siStateInfo.IncIdSafely(); 
		
		
	}

	if (dld->pMgr->GetDownloadMgr () != NULL)
		Apply_MirrParameters (dld);

	SYSTEMTIME time;
	GetLocalTime (&time);
	SystemTimeToFileTime (&time, &dld->dateAdded);

	
	if (dld->pMgr->GetDownloadMgr () != NULL)
	{
		fsSiteInfo *site = _SitesMgr.FindSite (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszServerName, 
			fsNPToSiteValidFor (dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol));
		if (site)
			dld->pMgr->GetDownloadMgr ()->GetDNP ()->dwFtpFlags = site->dwFtpFlags;
	}

	if (bPlaceToTop == false)
		DownloadsList_Add (dld);
	else
		DownloadsList_Insert (0, dld);

	m_bSkip1Cicle = TRUE;

	dld->dwFlags &= ~DLD_WAS_DELETED;
	dld->setDirty();

	return dld->nID;
}

void fsDownloadsMgr::_DownloadMgrEventDesc(fsDownloadMgr *pMgr, fsDownloadMgr_EventDescType enType, LPCSTR pszEvent, LPVOID lp)
{
	try 
	{
		fsDownloadsMgr* pThis = (fsDownloadsMgr*) lp;
		vmsDownloadSmartPtr dld = pThis->GetDownloadByDownloadMgr (pMgr);
		if (dld == NULL)
			return;

		pThis->OnDownloadDescEventRcvd (dld, enType, pszEvent);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_DownloadMgrEventDesc " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_DownloadMgrEventDesc unknown exception");
	}
}

vmsDownloadSmartPtr fsDownloadsMgr::GetDownloadByDownloadMgr(fsDownloadMgr *pMgr)
{
	assert (pMgr != NULL);

	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
		{
			if (m_vDownloads [i]->pMgr->GetDownloadMgr () == pMgr)
				return m_vDownloads [i];
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByDownloadMgr " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByDownloadMgr unknown exception");
	}

	return NULL;
}

DWORD fsDownloadsMgr::_DownloadMgrEvents(fsDownloadMgr *pMgr, fsDownloaderEvent enEvent, UINT uInfo, LPVOID lp)
{
	fsDownloadsMgr* pThis = (fsDownloadsMgr*) lp;

	ASSERT (pMgr != NULL);
	vmsDownloadSmartPtr dld = pThis->GetDownloadByDownloadMgr (pMgr);

	if (dld == NULL)
		return TRUE;

	try 
	{
		switch (enEvent)
		{
			case DE_SECTIONDONE:
				pThis->Event (dld, DME_DOWNLOADEREVENTRECEIVED);
				pThis->OnSectionStop (dld);
			break;

			case DE_SECTDOWNLOADING:
				pThis->RegisterDownloadInTum (dld); 
				pThis->Event (dld, DME_SECTIONDOWNLOADING);
			break;

			case DE_SECTIONSTOPPED:
				pThis->OnSectionStop (dld);
			break;

			case DE_EXTERROR:	
				switch (uInfo)
				{
					case DMEE_FILEWASDELETED:	
						dld->bAutoStart = FALSE; 
						dld->setDirty();
						break;

					case DMEE_STOPPEDORDONE: 
						pThis->UnregisterDownloadInTum (dld);
						if (FALSE == pThis->OnDownloadStoppedOrDone (dld))
							return TRUE;
						dld = NULL;	
						break;

					case DMEE_FATALERROR:
					case DMEE_USERSTOP:
						pThis->UnregisterDownloadInTum (dld);
						dld->bAutoStart = FALSE;
						dld->setDirty();
						break;

					case DMEE_FILEUPDATED:
						pThis->Event (dld, DME_FILEUPDATED);
						dld = NULL;	
						break;

					case DMEE_STARTING:
						pThis->RegisterDownloadInTum (dld);
						if (FALSE == pThis->Event (dld, DME_DLMGRTHREADSTARTING))
							return FALSE;
						pThis->Event (dld, DME_CREATEDLDDIALOG);
						break;
				}
			break;

			case DE_QUERYNEWSECTION:	
				pThis->RebuildServerList ();	
				return pThis->OnQueryNewSection (dld, uInfo);

			case DE_SECTIONSTARTED:
				pThis->setNeedApplyTrafficLimit ();
				pThis->RebuildServerList ();
				pThis->Event (dld, DME_SECTIONSTARTED);
			break;

			case DE_ALLSTOPPEDORDONE:
			break;

			case DE_WRITEERROR:
				dld->bAutoStart = FALSE;
				dld->setDirty();
			break;

			case DE_REDIRECTINGOKCONTINUEOPENING:
				pThis->Event (dld, DME_REDIRECTED);
				pThis->Event (dld, DME_UPDATEDLDDIALOG);
				break;

			case DE_NOMIRRFOUND:
				dld->dwFlags |= DLD_DONTUSEMIRRORS; 
				dld->setDirty();
				pMgr->GetDownloader ()->Set_SearchForMirrors (FALSE);
				break;

			case DE_FILESIZETOOBIG:
				dld->bAutoStart = FALSE;
				dld->setDirty();
				break;

			case DE_NEEDFILE:
				return pThis->OnBeforeDownload (dld);

			case DE_CONFIRMARCHIVEDETECTION:
			{
	#ifndef FDM_DLDR__RAWCODEONLY
				UINT nRes;
				UIThread *thr = (UIThread*) RUNTIME_CLASS (UIThread)->CreateObject ();
				thr->set_Thread (_threadConfirmZIP, &nRes);
				thr->CreateThread ();
				WaitForSingleObject (thr->m_hThread, INFINITE);
				return nRes;
	#else
				return 0;
	#endif
			}

			case DE_ARCHIVEDETECTED:
				return pThis->OnArchiveDetected (dld, (fsArchiveRebuilder*) uInfo);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_DownloadMgrEvents " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_DownloadMgrEvents unknown exception");
	}

	if (dld) 
		pThis->Event (dld, DME_DOWNLOADEREVENTRECEIVED);

	return TRUE;
}

void fsDownloadsMgr::ProcessDownloads()
{	
	if (m_dwPDTimeLimit && isAllowedToPDCurrently () == false)
		return;

	
	DLDS_LIST vDldsToStop, vDldsToStart;
	vmsDownloadSmartPtr dldBogus;

	if (m_bAllowStart == FALSE || m_bDisablePD)
		return;

	fsTicksMgr ticksNow; ticksNow.Now ();

	try {

	RebuildServerList (FALSE);

	UINT cConns = _TumMgr.getSettings ().download.uMaxConns;
	UINT cDlds = _TumMgr.getSettings ().download.uMaxTasks;
	UINT cMaxCPS = _TumMgr.getSettings ().download.uMaxConnsPS;

	cDlds = min (cDlds, 20);

	
	
	size_t i = 0;
	_SitesMgr.LockList (true);
	for (i = 0; i < (size_t)_SitesMgr.GetSiteCount (); i++) {
		_SitesMgr.GetSite (i)->cConnsNow = min (_SitesMgr.GetSite (i)->cMaxConns, cMaxCPS); 
		_SitesMgr.setDirty();
	}
	_SitesMgr.LockList (false);

	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	for (i = 0; i < m_vDownloads.size (); i++)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];

		if (dld->pMgr->IsDone ())
			continue;

		if (dld->pMgr->IsBittorrent () && 
			dld->pMgr->GetBtDownloadMgr ()->get_State () == BTDSE_QUEUED)
			continue;

		if (dld->pMgr->IsBittorrent () && IsDownloadSuspended(dld))
			continue;

		BOOL bAccept = FALSE, bAcceptAdditionalConnections = FALSE, bNeedCloseSomeConnections = FALSE;	
		
		fsDownloadMgr *pMgr = dld->pMgr->GetDownloadMgr (); 
		LPCSTR pszSiteName = pMgr ? pMgr->GetDNP ()->pszServerName : NULL;
		fsNetworkProtocol enNP = pMgr ? pMgr->GetDNP ()->enProtocol : (fsNetworkProtocol)-1;

		if (cDlds && cConns)	
		{	
			fsSiteInfo* site = pMgr? _SitesMgr.FindSite (pszSiteName, fsNPToSiteValidFor (enNP)) : NULL;
			if (site == NULL || site->cConnsNow)	
			{
				UINT cDldConns = 0;	

				if (dld->pMgr->IsRunning ())
				{
					cDldConns = dld->pMgr->IsBittorrent () ? 0 : dld->pMgr->GetConnectionCount ();

					if (pMgr)
					{
						cDldConns += pMgr->GetDownloader ()->GetCreatingNowSectionCount (UINT_MAX);

						
						for (int i = 0; i < pMgr->GetDownloader ()->GetMirrorURLCount (); i++)
						{
							UINT cMirrConns = pMgr->GetDownloader ()->GetCreatingNowSectionCount (i);
							fsDownload_NetworkProperties* mirrDNP = pMgr->GetDownloader ()->MirrorDNP (i);

							fsSiteInfo* mirrSite = _SitesMgr.FindSite (mirrDNP->pszServerName, fsNPToSiteValidFor (mirrDNP->enProtocol));
							assert (mirrSite != NULL);

							if (mirrSite)
							{
								if (mirrSite->cConnsNow > cMirrConns)
									mirrSite->cConnsNow -= cMirrConns;
								else
									mirrSite->cConnsNow = 0; 
								_SitesMgr.setDirty();
							}
						}

					}

					bAccept = TRUE;
				}
				else
				{
					if (dld->bAutoStart)
					{
						cDldConns = min (cConns, cMaxCPS);
						if (pMgr)
						{
							cDldConns = min (cDldConns, site->cConnsNow);
							cDldConns = min (cDldConns, pMgr->GetDP ()->uMaxSections);
						}
						else
						{
							cDldConns = min (cDldConns, 2);
							
						}
						if (pMgr && cDldConns > 1)
						{
							UINT64 size = pMgr->GetDownloader ()->GetSSFileSize ();
							if (size == _UI64_MAX)
							{
								cDldConns = 1;
							}
							else if (size)
							{
								cDldConns = min (cDldConns, 
									UINT (pMgr->GetDownloader ()->GetBytesLeft () / pMgr->GetDP ()->uSectionMinSize));
								if (!cDldConns)
									cDldConns = 1;
							}
						}
						if (cDldConns)
							bAccept = TRUE;
					}
				}

				
				if (bAccept && (ticksNow - dld->ticksLastStopByProcessDownloadsFn) < 500 &&
						dld->pMgr->IsRunning () == FALSE)
				{
					bAccept = FALSE; 
					if (dldBogus == NULL)
						dldBogus = dld;
				}

				if (bAccept)
				{
					
					if (site)
					{
						if(site->cConnsNow >= cDldConns)
						{
							site->cConnsNow -= cDldConns;
						}
						else
						{
							site->cConnsNow = 0;
							bNeedCloseSomeConnections = TRUE;
						}
					}

					if (cConns >= cDldConns)
					{
						cConns -= cDldConns;
					}
					else
					{
						cConns = 0;
						bNeedCloseSomeConnections = TRUE;
					}

					if (pMgr)
					{
						if (cConns)
						{
							if (pMgr->GetDP ()->uMaxSections > (UINT)pMgr->GetDownloader ()->GetRunningSectionCount () &&
									(pMgr->GetDownloader ()->GetBytesLeft () / pMgr->GetDP ()->uSectionMinSize / 2) != 0)
							{
								bAcceptAdditionalConnections = site == NULL || site->cConnsNow;
								if (site && site->cConnsNow)
									site->cConnsNow--;
								cConns--;
							}
						}
					}

					cDlds--;
				}
			}
		}

		if (bAccept)
		{
			if (!dld->pMgr->IsRunning ())
			{
				vDldsToStart.push_back (dld);	
			}
			else if (bAcceptAdditionalConnections)
			{
				dld->pMgr->CreateOneMoreSection ();
			}
		}
		else if (dld->pMgr->IsRunning ())
		{
			
			if (pMgr == NULL || dld->pMgr->GetNumberOfSections () == 0 || 
					(dld->pMgr->GetSSFileSize () != _UI64_MAX && dld->pMgr->IsResumeSupported () == RST_PRESENT))
			{
				vDldsToStop.push_back (dld); 
				dld->ticksLastStopByProcessDownloadsFn.Now ();
			}
		}
	}

	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	if (cConns == _TumMgr.getSettings ().download.uMaxConns  && 
			dldBogus != NULL)
	{
		ASSERT (vDldsToStart.empty ());
		if (vDldsToStart.empty ())
			vDldsToStart.push_back (dldBogus);
	}

	RebuildServerList (TRUE);

	} 
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::ProcessDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::ProcessDownloads unknown exception");
	}

	StopDownloads (vDldsToStop);
	StartDownloads (vDldsToStart);
}

void fsDownloadsMgr::StartDownloads(DLDS_LIST &vpDlds, BOOL )
{
	try 
	{
		UINT cRunning = GetRunningDownloadCount (false);

		for (size_t i = 0; i < vpDlds.size (); i++)
		{
			vmsDownloadSmartPtr dld = vpDlds [i];

			if (cRunning < _TumMgr.getSettings ().download.uMaxConns && cRunning < _TumMgr.getSettings ().download.uMaxTasks && cRunning < 20)	
			{
				if (dld->pMgr->IsDone () == FALSE)
				{
					dld->pMgr->StartDownloading ();
					cRunning ++;
				}
			}
			else
			{
				dld->bAutoStart = TRUE;
				dld->setDirty();
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StartDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StartDownloads unknown exception");
	}

	setNeedApplyTrafficLimit ();

	Event (NULL, NULL, DME_DLDSAUTOSTARTMDFD);
}

void fsDownloadsMgr::StopDownloads(DLDS_LIST &vDlds, BOOL bByUser)
{
	try 
	{
		
		if (bByUser)
		{
			for (size_t i = 0; i < vDlds.size (); i++) {
				vDlds [i]->bAutoStart = FALSE;
				vDlds [i]->setDirty();
			}
		}

		for (size_t i = 0; i < vDlds.size (); i++)
			vDlds [i]->pMgr->StopDownloading ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StopDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StopDownloads unknown exception");
	}

	setNeedApplyTrafficLimit ();

	if (bByUser)
		Event (NULL, NULL, DME_DLDSAUTOSTARTMDFD);
}

void fsDownloadsMgr::SetEventsFunc(fntDownloadsMgrEventFunc pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lpParam;
}

DWORD fsDownloadsMgr::Event(fsDownload* dld, fsDLHistoryRecord *phst, fsDownloadsMgrEvent ev)
{
	DWORD dwRet = TRUE; 

	if (dld && dld->pfnDownloadEventsFunc)
		dwRet = dld->pfnDownloadEventsFunc (dld, phst, ev, dld->lpEventsParam);

	if (m_pfnEvents)
		dwRet = m_pfnEvents (dld, phst, ev, m_lpEventsParam);

	return dwRet;
}

vmsDownloadSmartPtr fsDownloadsMgr::GetDownload(size_t iIndex)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	try 
	{
		if (iIndex >= m_vDownloads.size ())
			return NULL;

		return m_vDownloads [iIndex];
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownload " + tstring(ex.what()));
		return NULL;
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownload unknown exception");
		return NULL;
	}
}

BOOL fsDownloadsMgr::LoadDownloads()
{
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);
	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	if (!m_saver.Load (m_vDownloads, "downloads", FALSE))
		return FALSE;

	m_vDownloads.resetDirty();

	BOOL bFailIfLarge = _App.CheckRecycleBinSize ();
	for (int j = 0; j < 2; j++)
	{
		fsDLLoadResult res = m_saver.Load (m_vDeletedDownloads, "downloads.del", j == 0 && bFailIfLarge);
		m_vDeletedDownloads.resetDirty();
		if (res == DLLR_TOOLARGESIZE)
		{
			CWaitForConfirmationDlg dlg;
			dlg.Init (LS (L_RBTOOLARGE), UINT_MAX, TRUE, FALSE, LS (L_DONTCHECKAGAIN));
			dlg.m_pszIcon = IDI_WARNING;
			UINT nRet = dlg.DoModal ();
			if (dlg.m_bDontAsk)
				_App.CheckRecycleBinSize (FALSE);
			if (nRet == IDOK)
				break;
		}
		else 
			break;
	}

	_App.NonUtf8NameFixed (1);

#ifndef FDM_DLDR__RAWCODEONLY
	m_histmgr.LoadHistory ();
#endif

	
	
	m_siStateInfo.SetId(0);

	size_t i = 0;
	for (i = 0; i < m_vDownloads.size (); i++)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];

		dld->pdlg = NULL;

		dld->pfnDownloadEventsFunc = NULL;

		if (dld->pMgr->GetDownloadMgr ())
		{
			dld->pMgr->GetDownloadMgr ()->SetEventFunc (_DownloadMgrEvents, this);
			dld->pMgr->GetDownloadMgr ()->SetEventDescFunc (_DownloadMgrEventDesc, this);			
			dld->pMgr->GetDownloadMgr ()->set_Download (dld);
		}
		else if (dld->pMgr->GetBtDownloadMgr ())
		{
			dld->pMgr->GetBtDownloadMgr ()->SetEventsHandler (_BtDownloadManagerEventHandler, this);
		}
		else if (dld->pMgr->GetTpDownloadMgr ())
		{
			dld->pMgr->GetTpDownloadMgr ()->SetEventsHandler (_TpDownloadManagerEventHandler, this);
			dld->pMgr->GetTpDownloadMgr ()->SetEventDescFunc (_TpDownloadManagerEventDesc, this);
		}

		dld->pMgr->UseDetailedLog (m_bDetLog);

		
		
		LONG lId = max (m_siStateInfo.GetId(), (LONG)dld->nID);
		m_siStateInfo.SetId(lId);

		dld->pGroup->cDownloads++;
	}

	for (i = 0; i < m_vDeletedDownloads.size (); i++)
	{
		LONG id = (LONG)m_vDeletedDownloads [i]->nID;
		
		
		LONG lId = max (m_siStateInfo.GetId(), id);
		m_siStateInfo.SetId(lId);
	}

	
	
	m_siStateInfo.IncId();

	LoadStateInformation ();

	Apply_MirrParameters ();

	if (_BT.is_Initialized ())
	{
		InterlockedIncrement (&m_cThreadsRunning);
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadStartSeeding, this, 0, &dw));
	}

	return TRUE;
}

BOOL fsDownloadsMgr::Save()
{
	vmsAUTOLOCKSECTION (m_csShuttingDown);
	if (m_bShuttingDown)
		return FALSE;

	BOOL b = FALSE;

	try 
	{
		
		vmsAUTOLOCKRW_READ (m_rwlDownloads);
		if (FALSE == m_saver.Save (m_vDownloads, "downloads"))
			b = FALSE;
		vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

		
		vmsAUTOLOCKSECTION (m_csDeletedDownloads);
		if (FALSE == m_saver.Save (m_vDeletedDownloads, "downloads.del"))
			b = FALSE;
		vmsAUTOLOCKSECTION_UNLOCK (m_csDeletedDownloads);

		
		if (FALSE == m_histmgr.SaveHistory ())
			b = FALSE;

		
		if (FALSE == SaveStateInformation ())
			b = FALSE;

		if (FALSE == _BT.SaveState ())
			b = FALSE;

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::Save " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::Save unknown exception");
	}

	return b;
}

int fsDownloadsMgr::GetDownloadIndex(vmsDownloadSmartPtr dld, int nFindStartPos)
{
	ASSERT (nFindStartPos >= 0);

	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	for (size_t i = nFindStartPos; i < m_vDownloads.size (); i++)
	{
		if (m_vDownloads [i] == dld)
			return i;
	}

	return -1;
}

int fsDownloadsMgr::DeleteDownloads(DLDS_LIST &vDlds, BOOL bByUser, BOOL bDontConfirmFileDeleting, BOOL bDontDeleteFiles)
{
	size_t cMaxDlds = 40;

	try 
	{
		if (vDlds [0]->pfnDownloadEventsFunc)
			cMaxDlds = 20;
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::DeleteDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::DeleteDownloads unknown exception");
	}

	
	
	if (vDlds.size () < cMaxDlds)
		return DeleteDownloads2 (&vDlds, bByUser, bDontConfirmFileDeleting, bDontDeleteFiles);

	

	int iDeleted = 0;
	
	CWaitDlg dlg;
	dlg.StartWaiting (LS (L_DELETINGDLDS), _threadWaitDelDlds, TRUE, &vDlds, &bByUser, 
		&bDontConfirmFileDeleting, &bDontDeleteFiles, &iDeleted, this);

	return iDeleted;
}

DWORD WINAPI fsDownloadsMgr::_threadDeleteDownloads(LPVOID lp)
{
	threadDeleteDownloadsParams *pParams = (threadDeleteDownloadsParams*)lp;

	try 
	{
		
		size_t i = 0;
		for (i = 0; i < pParams->vDlds.size (); i++)
		{
			vmsDownloadMgrSmartPtr mgr = pParams->vDlds [i]->pMgr;

			if (mgr->GetDownloadMgr ())
			{
				mgr->GetDownloadMgr ()->SetEventFunc (NULL, 0);
				mgr->GetDownloadMgr ()->SetEventDescFunc (NULL, 0);
			}
			else if (mgr->GetBtDownloadMgr ())
			{
				mgr->GetBtDownloadMgr ()->SetEventsHandler (NULL, 0);
			}
			else if (mgr->GetTpDownloadMgr ())
			{
				mgr->GetTpDownloadMgr ()->SetEventsHandler (NULL, 0);
				mgr->GetTpDownloadMgr ()->SetEventDescFunc (NULL, 0);
			}

			mgr->StopDownloading ();
		}

		
		for (i = 0; i < pParams->vDlds.size (); i++)
		{
			vmsDownloadSmartPtr dld = pParams->vDlds [i];
			while (dld->pMgr->IsRunning ())
			{
	#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
				MSG msg;
				while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
					DispatchMessage (&msg);
	#endif

				Sleep (10);
			}
		}

	#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
		MSG msg;
		while (PeekMessage (&msg, 0, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);
	#endif

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_threadDeleteDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_threadDeleteDownloads unknown exception");
	}

	pParams->pthis->ApplyDDRs (pParams->vDlds, pParams->vDldsDDRs, FALSE);

	try 
	{
		delete pParams;	
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_threadDeleteDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_threadDeleteDownloads unknown exception");
	}

	return 0;
}

void fsDownloadsMgr::StopGroup(vmsDownloadsGroupSmartPtr pGroup)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	DLDS_LIST vDlds;

	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];

		if (dld->pGroup->nId == pGroup->nId)
			vDlds.push_back (dld);
	}

	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	StopDownloads (vDlds, TRUE);
}

void fsDownloadsMgr::StartGroup(vmsDownloadsGroupSmartPtr pGroup)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	DLDS_LIST vDlds;

	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];

		if (dld->pGroup->nId == pGroup->nId && 
			  dld->pMgr->IsRunning () == FALSE)
			vDlds.push_back (dld);
	}

	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	StartDownloads (vDlds, TRUE);
}

DWORD WINAPI fsDownloadsMgr::_threadDownloadsMgr(LPVOID lp)
{
	fsDownloadsMgr *pThis = (fsDownloadsMgr*) lp;
	fsTicksMgr ticksNow;
	fsTicksMgr lastSpeedMeasure;	

	ticksNow.Now ();
	lastSpeedMeasure.Now ();

	pThis->m_vSummSpeed.clear ();

	fsTicksMgr lastDldsProc;
	while (pThis->m_bShuttingDown == FALSE)
	{
		if (ticksNow - lastSpeedMeasure >= 5000)	
		{
			

			lastSpeedMeasure.Now ();

			
			if (pThis->m_vSummSpeed.size () == MAX_SUMMS)
				pThis->m_vSummSpeed.clear ();

			UINT summ = 0;
			UINT cBtDownloads = 0;

			pThis->m_rwlDownloads.AcquireReaderLock ();

			
			try 
			{
				for (int i = pThis->m_vDownloads.size () - 1; i >= 0; i--) {
					summ += pThis->m_vDownloads [i]->pMgr->GetSpeed ();
					if (pThis->m_vDownloads [i]->pMgr->IsBittorrent () && pThis->m_vDownloads [i]->pMgr->IsRunning ())
						cBtDownloads++;
				}
			}
			catch (const std::exception& ex)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("fsDownloadsMgr::_threadDownloadsMgr " + tstring(ex.what()));
			}
			catch (...)
			{
				ASSERT (FALSE);
				vmsLogger::WriteLog("fsDownloadsMgr::_threadDownloadsMgr unknown exception");
			}

			pThis->m_rwlDownloads.ReleaseReaderLock ();

			
			
			if (summ == 0 && pThis->IsRunning () == FALSE)
				pThis->m_vSummSpeed.clear ();
			else {
				pThis->m_vSummSpeed.add (summ);
				if (cBtDownloads &&_BT.is_Initialized ()) {
					_BT.get_Session ()->setWriteCacheSize (cBtDownloads * _App.FileWriteCacheSize ());
				}
			}
		}

		if (pThis->m_bSkip1Cicle == FALSE)
		{
			pThis->ManageTraffic ();
		}
		else
			pThis->m_bSkip1Cicle = FALSE;

		if (pThis->m_dwPDTimeLimit)
			pThis->ManagePD ();

		pThis->m_totalProgess.clear ();

		pThis->m_rwlDownloads.AcquireReaderLock ();

		try
		{
			for (int i = pThis->m_vDownloads.size () - 1; i >= 0; i--)
			{
				fsDownload *pDld = pThis->m_vDownloads [i];
				vmsDownloadMgrEx *pDldMgr = pDld->pMgr;
				if (pDldMgr->IsRunning () || pDld->bAutoStart)
				{
					pThis->m_totalProgess.uDownloaded += pDldMgr->GetDownloadedBytesCount ();
					pThis->m_totalProgess.uTotalSize += pDldMgr->GetLDFileSize ();
					pThis->m_totalProgess.uSpeed += pDldMgr->GetSpeed ();
				}
			}
		}
		catch (const std::exception& ex)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("fsDownloadsMgr::_threadDownloadsMgr " + tstring(ex.what()));
		}
		catch (...)
		{
			ASSERT (FALSE);
			vmsLogger::WriteLog("fsDownloadsMgr::_threadDownloadsMgr unknown exception");
		}

		pThis->m_rwlDownloads.ReleaseReaderLock ();

		fsTicksMgr ticks1; ticks1 += 1000;

		while (ticksNow < ticks1)
		{
			bool bNeedPD = false, bNeedAL = false, bNeedCNAD = false;

			EnterCriticalSection (&pThis->m_csNeedStartXXXX);
			if (pThis->m_ticksNeedStartProcessDownloads.m_dwTicks && pThis->m_ticksNeedStartProcessDownloads <= ticksNow)
			{
				bNeedPD = true;
				pThis->m_ticksNeedStartProcessDownloads.m_dwTicks = 0;
				lastDldsProc.Now();
			}
			if (pThis->m_ticksNeedStartApplyTrafficLimit.m_dwTicks && pThis->m_ticksNeedStartApplyTrafficLimit <= ticksNow)
			{
				bNeedAL = true;
				pThis->m_ticksNeedStartApplyTrafficLimit.m_dwTicks = 0;
			}
			if (pThis->m_ticksNeedCheckNoActiveDownloads.m_dwTicks && pThis->m_ticksNeedCheckNoActiveDownloads <= ticksNow)
			{
				bNeedCNAD = true;
				pThis->m_ticksNeedCheckNoActiveDownloads.m_dwTicks = 0;
			}
			if (!pThis->m_dldErrorsMap.empty())
			{
				DWORD now = GetTickCount();
				if (now - lastDldsProc.m_dwTicks > 10 * 10000)
				{
					bNeedPD = true;
					pThis->m_ticksNeedStartProcessDownloads.m_dwTicks = 0;
					lastDldsProc.Now();
				}
			}
			LeaveCriticalSection (&pThis->m_csNeedStartXXXX);

			if (bNeedPD)
				pThis->ProcessDownloads ();
			if (bNeedAL)
				pThis->ApplyTrafficLimit ();
			if (bNeedCNAD)
				pThis->CheckNoActiveDownloads ();

			Sleep (100);

			ticksNow.Now ();
		}
	}

	InterlockedDecrement (&pThis->m_cThreadsRunning);

	return 0;
}

void fsDownloadsMgr::RebuildServerList(BOOL bUpdateSiteList)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	vmsCriticalSectionAutoLock csalSites;
	_SitesMgr.LockList (csalSites);

	try 
	{

	int i = 0;
	for (i = 0; i < _SitesMgr.GetSiteCount (); i++) {
		_SitesMgr.GetSite (i)->cConnsNow = 0;	
		_SitesMgr.setDirty();
	}

	
	for (i = m_vDownloads.size () - 1; i >= 0; i--)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];

		if (dld->pMgr->GetDownloadMgr () == NULL)
			continue;

		fsDownloadMgr *pMgr = dld->pMgr->GetDownloadMgr ();

		int cSects = pMgr->GetDownloader ()->GetNumberOfSections ();
		fs::list <UINT> vMirrsCalculated;

		

		
		for (int j = -1; j < cSects || (cSects == 0 && j == 0); j++)
		{
			fsSection sect;
			bool bSect = j != -1 && cSects != 0;

			if (bSect)
				pMgr->GetDownloader ()->GetSectionInfo (j, &sect);

			int cConns = bSect && (sect.state == SS_DOWNLOADING) ? 1 : 0;

			UINT uSect = UINT_MAX;
			if (bSect)
				uSect = j;

			fsDownload_NetworkProperties *dnp = pMgr->GetDownloader ()->DNP (uSect);

			LPCSTR pszServer = dnp->pszServerName;
			fsNetworkProtocol np = dnp->enProtocol;
			
			fsSiteInfo *site = _SitesMgr.FindSite (pszServer, fsNPToSiteValidFor (np));

			
			int k = 0;
			for (k = 0; k < vMirrsCalculated.size (); k++)
			{
				if (vMirrsCalculated [k] == sect.nMirrorURL)
					break;
			}

			if (k != vMirrsCalculated.size ())
			{
				cConns += pMgr->GetDownloader ()->GetCreatingNowSectionCount (sect.nMirrorURL);
				vMirrsCalculated.add (sect.nMirrorURL);
			}

			
			if (site == NULL)
			{
				
				fsSiteInfoPtr site; site.CreateInstance ();
				site->strName = pszServer;
				site->cConnsNow = cConns;
				site->dwFtpFlags = dnp->dwFtpFlags;
				site->bTemp = TRUE;
				site->cMaxConns = UINT_MAX;
				site->pGroup = dld->pGroup;
				if (_App.SM_KeepPasswords ())
				{
					site->strUser = *dnp->pszUserName ? dnp->pszUserName : NULL;
					site->strPassword = *dnp->pszPassword ? dnp->pszPassword : NULL;
				}
				site->dwValidFor = fsNPToSiteValidFor (np) | SITE_VALIDFOR_SUBDOMAINS;
				_SitesMgr.AddSite (site);
			}
			else
			{
				
				site->cConnsNow += cConns;
				_SitesMgr.setDirty();
			}
		}
	}

	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::RebuildServerList " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::RebuildServerList unknown exception");
	}

	try 
	{
		
		if (bUpdateSiteList)
		{
			for (int i = 0; i < _SitesMgr.GetSiteCount (); i++)
				_SitesMgr.SiteUpdated (_SitesMgr.GetSite (i));
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::RebuildServerList " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::RebuildServerList unknown exception");
	}
}
BOOL fsDownloadsMgr::OnQueryNewSection(vmsDownloadSmartPtr dld, UINT nUsingMirror)
{
	ASSERT (dld->pMgr->GetDownloadMgr () != NULL);
	
	
	if (dld->pMgr->GetDownloadMgr ()->GetDP ()->bIgnoreRestrictions)
		return TRUE;

	EnterCriticalSection (&m_csQSection);
	BOOL b = TRUE; 

	fsDownload_NetworkProperties *dnp;
	if (nUsingMirror != UINT_MAX)
		dnp = dld->pMgr->GetDownloadMgr ()->GetDownloader ()->MirrorDNP (nUsingMirror);
	else
		dnp = dld->pMgr->GetDownloadMgr ()->GetDNP ();

	
	if (IsServerFilled (dnp->pszServerName, fsNPToSiteValidFor (dnp->enProtocol)))
	{
		Event (dld, LS (L_LIMITREACHED), EDT_WARNING);
		b = FALSE;
	}
	else if (IsMaxConnsReached ()) 
	{
		Event (dld, LS (L_TOTALLIMITREACHED), EDT_WARNING);
		b = FALSE;
	}
	
	
	
	
	if (b == FALSE && dld->bAutoStart == FALSE && dld->pMgr->IsDownloading () == FALSE) {
		dld->bAutoStart = TRUE;
		dld->setDirty();
	}

	LeaveCriticalSection (&m_csQSection);
	return b;
}

void fsDownloadsMgr::Event(vmsDownloadSmartPtr dld, LPCSTR pszEvent, fsDownloadMgr_EventDescType enType)
{
	OnDownloadDescEventRcvd (dld, enType, pszEvent);
}

UINT fsDownloadsMgr::GetAmountConnections()
{
	UINT nConns = 0;

	vmsCriticalSectionAutoLock csal;
	_SitesMgr.LockList (csal);

	try 
	{
		for (int i = _SitesMgr.GetSiteCount () - 1; i >= 0; i--)
			nConns += _SitesMgr.GetSite (i)->cConnsNow;
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetAmountConnections " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetAmountConnections unknown exception");
	}

	return nConns;
}

void fsDownloadsMgr::OnSectionStop(vmsDownloadSmartPtr dld)
{
	

	ASSERT (dld->pMgr->GetDownloadMgr () != NULL);

	fsSiteInfo* site = _SitesMgr.FindSite (dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszServerName, 
		fsNPToSiteValidFor (dld->pMgr->GetDownloadMgr ()->GetDNP ()->enProtocol));

	if (site)
	{
		site->cConnsNow --;	
		_SitesMgr.SiteUpdated (site);
	}

	setNeedApplyTrafficLimit ();
}

void fsDownloadsMgr::ManageTraffic()
{
	
	
	
	
	
	
	
	
	
	setNeedApplyTrafficLimit ();
}

void fsDownloadsMgr::ApplyTrafficLimit()
{
	if (_BT.is_Initialized ())
	{
		
		
		_BT.get_Session ()->SetUploadLimit (_TumMgr.getRestrainAll () ? 1 :
			_App.Bittorrent_UploadTrafficLimit (_TumMgr.GetTUM ()));
		_BT.get_Session ()->SetMaxUploads (
			_App.Bittorrent_UploadConnectionLimit (_TumMgr.GetTUM ()));
		_BT.get_Session ()->SetMaxHalfOpenConnections (
			_App.Bittorrent_MaxHalfConnections (_TumMgr.GetTUM ()));
		_BT.get_Session ()->SetMaxConnections (
			_App.Bittorrent_MaxConnections (_TumMgr.GetTUM ()));
	}
}

void fsDownloadsMgr::StartAllDownloads(BOOL bByUser)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	DLDS_LIST vDlds;

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
		{
			if (m_vDownloads [i]->pMgr->IsDone () == FALSE)
				vDlds.push_back (m_vDownloads [i]);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StartAllDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StartAllDownloads unknown exception");
	}

	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	StartDownloads (vDlds, bByUser);

}

void fsDownloadsMgr::StopAllDownloads(BOOL bByUser)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	DLDS_LIST vDlds;

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
			vDlds.push_back (m_vDownloads [i]);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StopAllDownloads " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::StopAllDownloads unknown exception");
	}
	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	StopDownloads (vDlds, bByUser);
}

BOOL fsDownloadsMgr::IsSummarySpeedWasLessThan(UINT uSpeed, UINT uTimeInterval)
{
	UINT uSize = m_vSummSpeed.size ();	
	UINT uNeed = uTimeInterval / 5;	

	if (uSize == 0)
		return FALSE;

	if (uSize < uNeed)
		return FALSE;

	for (UINT i = uSize - 1; i > uSize - uNeed; i--)
	{
		
		
		if (m_vSummSpeed [i] >= uSpeed)
				return FALSE;
	}

	return TRUE;
}

BOOL fsDownloadsMgr::IsRunning()
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	try 
	{
		for (int i = m_vDownloads.size () - 1; i >= 0; i--)
			if (m_vDownloads [i]->pMgr->IsRunning ())
				return TRUE;
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::IsRunning " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::IsRunning unknown exception");
	}

	return FALSE;
}

void fsDownloadsMgr::CheckNoActiveDownloads()
{
	if (IsRunning () == FALSE)
		Event ((fsDownload*)NULL, DME_NOACTIVEDOWNLOADS);
}

vmsDownloadSmartPtr fsDownloadsMgr::GetDownloadByID(UINT nID)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	try
	{
		for (int i = m_vDownloads.size () - 1; i >= 0; i--)
		{
			vmsDownloadSmartPtr dld = m_vDownloads [i];
			if (dld->nID == nID)
				return dld;
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByID " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByID unknown exception");
	}

	return NULL;
}

void fsDownloadsMgr::AllowStartNewDownloads(BOOL bAllow)
{
	m_bAllowStart = bAllow;
}

void fsDownloadsMgr::LockList(bool bForRead)
{
	if (bForRead)
		m_rwlDownloads.AcquireReaderLock ();
	else
		m_rwlDownloads.AcquireWriterLock ();
}

void fsDownloadsMgr::UnlockList(bool bForRead)
{
	if (bForRead)
		m_rwlDownloads.ReleaseReaderLock ();
	else
		m_rwlDownloads.ReleaseWriterLock ();
}

void fsDownloadsMgr::SaveSettings()
{
	_App.DDR (m_enDDR);
	_App.AutoDelCompleted (m_bAutoDelCompleted);
	_App.DetLog (m_bDetLog);

	_App.Avir_Perform (m_bVirCheck);
	_App.Avir_Name (m_strVirName);
	_App.Avir_Args (m_strVirArgs);
	_App.Avir_Exts (m_strVirExts);
	_App.DldsMgrPDTimeLimit (m_dwPDTimeLimit);
}

BOOL fsDownloadsMgr::IsServerFilled(LPCSTR pszServer, DWORD dwReqProtocols)
{
	fsSiteInfo *site = _SitesMgr.FindSite (pszServer, dwReqProtocols);

	if (site == NULL)
		return FALSE;

	if (site->cConnsNow >= _TumMgr.getSettings ().download.uMaxConnsPS || site->cConnsNow >= site->cMaxConns)
		return TRUE;

	return FALSE;
}

BOOL fsDownloadsMgr::IsMaxConnsReached()
{
	if (GetAmountConnections () >= _TumMgr.getSettings ().download.uMaxConns)
		return TRUE;

	return FALSE;
}

void fsDownloadsMgr::ReadSettings()
{
	m_enDDR = _App.DDR ();
	m_bAutoDelCompleted = _App.AutoDelCompleted ();
	m_bDetLog = _App.DetLog ();

	m_bVirCheck = _App.Avir_Perform ();
	m_strVirName = _App.Avir_Name ();
	m_strVirArgs = _App.Avir_Args ();
	m_strVirExts = _App.Avir_Exts ();

	ReadMirrParameters ();
	ReadDeletedSettings ();

	m_histmgr.ReadSettings ();

	m_dwPDTimeLimit = _App.DldsMgrPDTimeLimit ();
}

int fsDownloadsMgr::GetRunningDownloadCount(bool bIncludeBtSeeds)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	int cRunning = 0;

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
		{
			if (m_vDownloads [i]->pMgr->IsRunning ())
			{
				cRunning ++;
				if (false == bIncludeBtSeeds && m_vDownloads [i]->pMgr->IsBittorrent () &&
						m_vDownloads [i]->pMgr->IsDone ())
					cRunning--;
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetRunningDownloadCount " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetRunningDownloadCount unknown exception");
	}

	return cRunning;
}

BOOL fsDownloadsMgr::IsDeletingNow()
{
	return m_bDeletingNow;
}

void fsDownloadsMgr::UseDetailedLog(BOOL b)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);
	m_bDetLog = b;
	for (int i = m_vDownloads.size () - 1; i >= 0; i--)
		m_vDownloads [i]->pMgr->UseDetailedLog (b);
}

int fsDownloadsMgr::DeleteDownloads2(DLDS_LIST *vDlds, BOOL bByUser, BOOL bDontConfirmFileDeleting, BOOL bDontDeleteFiles, BOOL* pbNeedStop, int* piProgress)
{
	UINT i = 0;

	
	BOOL bBypassBin = m_bBypassBinForDownloads || bByUser == FALSE || bDontConfirmFileDeleting;

	std::vector <fsDeleteDownloadReaction> vDldsDDRs;

	
	if (bDontConfirmFileDeleting && m_enDDR == DDR_ASK)
	{
		vDldsDDRs.assign (vDlds->size (), DDR_WITHFILE);	
	}
	else if (bBypassBin)
	{
		GetDDRs (*vDlds, bDontConfirmFileDeleting, FALSE, vDldsDDRs);
		if (vDldsDDRs.size () != vDlds->size ())
			return 0; 
	}
	else
	{
		vDldsDDRs.assign (vDlds->size (), DDR_FROMLISTONLY);
	}

	threadDeleteDownloadsParams *pThreadParams = new threadDeleteDownloadsParams;
	pThreadParams->pthis = this;

	vmsDownloadSmartPtr dldFake;
	Download_CreateInstance (dldFake);
	dldFake->pMgr->GetDownloadMgr ()->CreateByUrl ("http://localhost/", TRUE);

	_pwndDownloads->set_DontUpdateTIPO (TRUE);

	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);

	m_bDeletingNow = TRUE;
	m_bDisablePD = TRUE;

	DeletedDownloads_UseTmpList (TRUE);

	try 
	{
		std::vector <int> vIndexes;
		findDownloadsIndexes (*vDlds, m_vDownloads, vIndexes);

		for (i = 0; i < (UINT)vDlds->size (); i++)
		{
			
			
			if (pbNeedStop && *pbNeedStop)
				break;

			vmsDownloadSmartPtr dld = vDlds->at (i);

			int iIndex = vIndexes [i];
			if (iIndex == -1) 
				continue;

			if (dld->pdlg)
				Event (dld, DME_CLOSEDLDDIALOG);

			if (piProgress)
				*piProgress = (int) ((double)i / vDlds->size () * 100);

			if (dld->pMgr->GetDownloadMgr ())
			{
				dld->pMgr->GetDownloadMgr ()->SetEventDescFunc (NULL, 0);
				dld->pMgr->GetDownloadMgr ()->SetEventFunc (NULL, 0);
			}
			else if (dld->pMgr->GetBtDownloadMgr ())
			{
				dld->pMgr->GetBtDownloadMgr ()->SetEventsHandler (NULL, 0);
			}
			else if (dld->pMgr->GetTpDownloadMgr ())
			{
				dld->pMgr->GetTpDownloadMgr ()->SetEventsHandler (NULL, 0);
				dld->pMgr->GetTpDownloadMgr ()->SetEventDescFunc (NULL, 0);
			}

			Event (dld, DME_DOWNLOADWILLBEDELETED);
			
			m_vDownloads [iIndex] = dldFake;
			dld->pGroup->cDownloads--;

			dld->dwFlags |= DLD_WAS_DELETED;
			Event (dld, DME_DOWNLOADWASDELETEDFROMLIST);
			dld->pfnDownloadEventsFunc = NULL;

			UnregisterDownloadInTum (dld);

			fsDeleteDownloadReaction enDDR;

			BOOL bDone = dld->pMgr->IsDone ();

			if (FALSE == bBypassBin && 
				(m_bBypassBinForCompletedDownloads == FALSE || bDone == FALSE))
			{
				
				dld = PutDownloadToDeleted (dld);
				enDDR = m_enDDR; 
			}
			else
			{
				
				Event (dld, DME_DLDWILLBEFULLYDELETED);
				if ((dld->dwFlags & DLD_DONTPUTTOHISTORY) == 0 && bDone == FALSE)
					m_histmgr.AddToHistory (dld);
				enDDR = vDldsDDRs [i];
			}
		
			if (dld)
			{
				pThreadParams->vDlds.push_back (dld);
				pThreadParams->vDldsDDRs.push_back (enDDR);
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::DeleteDownloads2 " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::DeleteDownloads2 unknown exception");
	}

	int cDeleted = i;

	DeletedDownloads_UseTmpList (FALSE);

	

	DLDS_LIST v; v.reserve (m_vDownloads.size ());
	for (i = 0; i < m_vDownloads.size (); i++)
	{
		if (m_vDownloads [i] != dldFake)
			v.push_back (m_vDownloads [i]);
	}
	m_vDownloads = v;	

	m_bDeletingNow = FALSE;
	m_bDisablePD = FALSE;

	vmsAUTOLOCKRW_WRITE_UNLOCK (m_rwlDownloads);

	_pwndDownloads->set_DontUpdateTIPO (FALSE);

	_pwndDownloads->UpdateTrayIconPlusOthers ();
	_pwndDownloads->UpdateNumbersOfDownloadsInGroups ();

	if (!pThreadParams->vDlds.empty ())
	{
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadDeleteDownloads, pThreadParams, 0, &dw));
	}
	else
	{
		delete pThreadParams;
	}

	setNeedProcessDownloads ();

	return cDeleted;	
}

void fsDownloadsMgr::findDownloadsIndexes (DLDS_LIST_REF vDldsWhat, DLDS_LIST_REF vDldsWhere, std::vector <int> &vResult)
{
	vResult.assign (vDldsWhat.size (), -1);

	size_t nStart = 0;	

	
	for (size_t i = 0; i < vDldsWhere.size (); i++)
	{
		vmsDownloadSmartPtr dld = vDldsWhere [i];

		
		for (size_t j = nStart; j < vDldsWhat.size (); j++)
		{
			if (dld == vDldsWhat [j])
			{				
				vResult [j] = (int)i;

				
				size_t k = j;
				while (k > nStart && vResult [k - 1] != -1)
					k--; 
				if (k == nStart)
					nStart = j + 1;	
				break;
			}
		}
	}
}

void fsDownloadsMgr::findDownloadsIndexes (DLDS_LIST_REF vDldsWhat, vmsDownloadList& vDldsWhere, std::vector <int> &vResult)
{
	vResult.assign (vDldsWhat.size (), -1);

	size_t nStart = 0;	

	
	for (size_t i = 0; i < vDldsWhere.size (); i++)
	{
		vmsDownloadSmartPtr dld = vDldsWhere [i];

		
		for (size_t j = nStart; j < vDldsWhat.size (); j++)
		{
			if (dld == vDldsWhat [j])
			{				
				vResult [j] = (int)i;

				
				size_t k = j;
				while (k > nStart && vResult [k - 1] != -1)
					k--; 
				if (k == nStart)
					nStart = j + 1;	
				break;
			}
		}
	}
}

DWORD WINAPI fsDownloadsMgr::_threadWaitDelDlds(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	DLDS_LIST *vDlds =  (DLDS_LIST*) info->lpParam1;
	BOOL bByUser = *((BOOL*) info->lpParam2);
	BOOL bDontConfirmFileDeleting = *((BOOL*) info->lpParam3);
	BOOL bDontDeleteFiles = *((BOOL*) info->lpParam4);
	int *pcDlds = (int*) info->lpParam5;
	fsDownloadsMgr* pThis = (fsDownloadsMgr*) info->lpParam6;

	pThis->Event (NULL, NULL, DME_BEGINDELETEMANYDOWNLOADS);
	*pcDlds = pThis->DeleteDownloads2 (vDlds, bByUser, bDontConfirmFileDeleting, bDontDeleteFiles, 
		&info->bNeedStop, &info->iProgress);
	pThis->Event (NULL, NULL, DME_ENDDELETEMANYDOWNLOADS);

	info->bWaitDone = TRUE;

	return 0;
}

void fsDownloadsMgr::Download_CloneSettings(vmsDownloadSmartPtr dst, vmsDownloadSmartPtr src)
{
	dst->bAutoStart = src->bAutoStart;
	dst->dwFlags = src->dwFlags;
	dst->dwReserved = src->dwReserved;
	dst->strComment = src->strComment;
	dst->pGroup = src->pGroup;
	if (dst->pMgr && src->pMgr)
	{
		ASSERT (dst->pMgr->GetDownloadMgr () != NULL && src->pMgr->GetDownloadMgr () != NULL);
		dst->pMgr->GetDownloadMgr ()->CloneSettings (src->pMgr->GetDownloadMgr ());
	}
	dst->setDirty();
}

BOOL fsDownloadsMgr::PerformVirusCheck(vmsDownloadSmartPtr dld, BOOL bCheckExtReqs, BOOL bWaitDone)
{
	if (m_strVirName == "")
		return TRUE;

	bool bMultiTorrent = dld->pMgr->GetBtDownloadMgr () != NULL && 
		dld->pMgr->GetBtDownloadMgr ()->get_FileCount () != 1;

	bool bMultiTorrentCheck = bMultiTorrent && bCheckExtReqs;

	int nFiles = bMultiTorrentCheck ? dld->pMgr->GetBtDownloadMgr ()->get_FileCount () : 1;

	fsString strFile;

	int i = 0;
	for (i = 0; i < nFiles; i++)
	{
		char szFile [MY_MAX_PATH];
		
		if (bMultiTorrentCheck)
			strFile = dld->pMgr->GetBtDownloadMgr ()->get_OutputFilePathName (i);
		else
			strFile = dld->pMgr->get_OutputFilePathName ();

		fsGetFileName (strFile, szFile);

		if (bCheckExtReqs)
		{
			char *pszExt = strrchr (strFile, '.');

			
			if (pszExt && IsExtInExtsStr (m_strVirExts, pszExt+1))
				break;	
		}
		else
			break;
	}
	if (i == nFiles)
		return TRUE; 

	Event (dld, LS (L_LAUNCHAVIR), EDT_INQUIRY);
	
	CString strArgs = m_strVirArgs;
	CString str = '"'; str += strFile; str += '"';
	strArgs.Replace ("%file%", str);

	if (bWaitDone == FALSE)
	{
		DWORD dwErr = (DWORD) ShellExecute (HWND_DESKTOP, "open", m_strVirName, strArgs, NULL, SW_SHOW);
		if (dwErr <= 32)
		{
			SetLastError (dwErr);
			goto _lErr;
		}	
	}
	else
	{
		STARTUPINFO si;
		PROCESS_INFORMATION pi;

		ZeroMemory (&si, sizeof (si));
		si.cb = sizeof (si);
		ZeroMemory (&pi, sizeof (pi));

		fsString str = m_strVirName;
		if (strchr (str, '\\') == NULL && strchr (str, '/') == NULL)
			str = vmsRegisteredApp::GetFullPath (str);

		CString strCmdLine; 
		strCmdLine.Format ("\"%s\" %s", (LPCSTR)str, (LPCSTR)strArgs);

		if (FALSE == CreateProcess (NULL, (LPSTR)(LPCSTR)strCmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
			goto _lErr;

		WaitForSingleObject (pi.hProcess, INFINITE);
	}

	Event (dld, LS (L_SUCCESS), EDT_RESPONSE_S);
	return TRUE;

_lErr:
	CHAR szErr [1000]; DWORD dwErr = GetLastError ();
	fsErrorToStr (szErr, sizeof (szErr), &dwErr);
	Event (dld, szErr, EDT_RESPONSE_E);
	return FALSE;
}

void fsDownloadsMgr::Apply_MirrParameters()
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];
		if (dld->pMgr->GetDownloadMgr () != NULL)
			Apply_MirrParameters (dld);
	}
}

void fsDownloadsMgr::ReadMirrParameters()
{
	m_bMirrAutoSearch = _App.Mirr_AutoSearch ();
	m_uMirrFileMinSize = _App.Mirr_FileMinSize ();
	m_bMirrCalcSpeed = _App.Mirr_CalcSpeed ();
	m_cMaxMirrs = _App.Mirr_MaxCount ();
	m_uMirrRecalcSpeedTime = _App.Mirr_RecalcSpeedTime ();
	m_bMirrDontSearchIfSizeUnk = _App.Mirr_DontSearchIfSizeUnk ();
}

void fsDownloadsMgr::Apply_MirrParameters(vmsDownloadSmartPtr dld)
{
	ASSERT (dld->pMgr->GetDownloadMgr () != NULL);

	fsInternetDownloader *dldr = dld->pMgr->GetDownloadMgr ()->GetDownloader ();

	if ((dld->dwFlags & DLD_DONTUSEMIRRORS) == 0)
	{
		dldr->Set_SearchForMirrors (m_bMirrAutoSearch);
		dldr->Set_MirrDontSearchIfSizeUnk (m_bMirrDontSearchIfSizeUnk);
		dldr->Set_MirrFileMinSize (m_uMirrFileMinSize);
	}
	else
		dldr->Set_SearchForMirrors (FALSE);

	dldr->Set_MirrCalcSpeed (m_bMirrCalcSpeed);
	dldr->Set_MirrMaxCount (m_cMaxMirrs);
	dld->pMgr->GetDownloadMgr ()->Set_MirrRecalcSpeedTime (m_uMirrRecalcSpeedTime);
}

DWORD fsDownloadsMgr::OnBeforeDownload(vmsDownloadSmartPtr dld)
{
	BOOL bOK = TRUE;
	BOOL bDontDeleteFiles = FALSE;

	fsDownloadMgr *pMgr = dld->pMgr->GetDownloadMgr ();
	ASSERT (pMgr != NULL);
	if (!pMgr)
		return FALSE;

	if (dld->pMgr->GetNumberOfSections () == 0 && _App.CheckIfDownloadIsMirror ())
	{
		if (CheckIfDownloadIsMirror (dld))
		{
			bOK = FALSE;
			bDontDeleteFiles = TRUE;
		}
	}

	if (bOK && (dld->dwFlags & DLD_CTREQ_HTML))
	{
		LPCSTR pszType = pMgr->GetDownloader ()->GetContentType ();

		if(strstr (pszType, "html") == NULL)
			bOK = FALSE;
	}

	if (bOK && dld->pfnDownloadEventsFunc && (dld->dwFlags & DLD_NOTIFYBEFOREDOWNLOAD))
		bOK = dld->pfnDownloadEventsFunc (dld, NULL, DME_BEFOREDOWNLOADING, dld->lpEventsParam);

	if (bOK == FALSE)
	{
		DLDS_LIST vpDlds;
		vpDlds.push_back (dld);
		DeleteDownloads (vpDlds, FALSE, TRUE, bDontDeleteFiles);
	}

	return bOK;
}

int fsDownloadsMgr::Get_DeletedDownloadCount()
{
	vmsAUTOLOCKSECTION (m_csDeletedDownloads);
	return m_vDeletedDownloads.size () ? 
		m_vDeletedDownloads.size () : m_vDeletedDownloads_tmp.size ();
}

vmsDownloadSmartPtr fsDownloadsMgr::Get_DeletedDownload(int iIndex)
{
	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	if (m_vDeletedDownloads.size ()) 
	{
		return m_vDeletedDownloads [iIndex];
	}
	else
	{
		std::list <vmsDownloadSmartPtr>::iterator iter = m_vDeletedDownloads_tmp.begin ();
		while (iIndex--)
			iter++;
		return *iter;
	}
}

void fsDownloadsMgr::ReadDeletedSettings()
{
	ASSERT (m_vDeletedDownloads_tmp.size () == 0);

	m_bBypassBinForDownloads = _App.Deleted_Bypass ();
	m_cMaxDeleted = _App.Deleted_MaxCount ();
	m_bBypassBinForCompletedDownloads = _App.Deleted_BypassCompleted ();

	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	DLDS_LIST v;

	if (m_bBypassBinForDownloads)
	{
		
		
		m_vDeletedDownloads.Copy(v);
	}
	else if (UINT (m_vDeletedDownloads.size ()) > m_cMaxDeleted)
	{
		for (size_t i = m_cMaxDeleted; i < m_vDeletedDownloads.size (); i++)
			v.push_back (m_vDeletedDownloads [i]);
	}

	vmsAUTOLOCKSECTION_UNLOCK (m_csDeletedDownloads);

	if (v.size ())
		DeleteDeletedDownloads (v, TRUE);
}

vmsDownloadSmartPtr fsDownloadsMgr::PutDownloadToDeleted(vmsDownloadSmartPtr dld)
{
	ASSERT (m_vDeletedDownloads.size () == 0);

	dld->pMgr->StopDownloading ();
	m_vDeletedDownloads_tmp.insert (m_vDeletedDownloads_tmp.begin (), dld);
	Event (dld, DME_DLDADDEDTODELETED);

	vmsDownloadSmartPtr ret;

	UINT sz = m_vDeletedDownloads_tmp.size ();
	if (sz > m_cMaxDeleted)
	{
		std::list <vmsDownloadSmartPtr>::iterator it = m_vDeletedDownloads_tmp.end ();
		it--;
		ret = *it;
		m_vDeletedDownloads_tmp.erase (it);
		Event (ret, DME_DLDREMOVEDFROMDELETED);
		Event (ret, DME_DLDWILLBEFULLYDELETED);
		if ((ret->dwFlags & DLD_DONTPUTTOHISTORY) == 0 &&
				ret->pMgr->IsDone () == FALSE)
			m_histmgr.AddToHistory (ret);
	}

	return ret;
}

BOOL fsDownloadsMgr::DeleteDownloadFile(vmsDownloadSmartPtr dld)
{
	if (dld->pMgr->GetDownloadMgr ())
		dld->pMgr->GetDownloadMgr ()->CloseFile ();
			
	Event (dld, DME_DOWNLOADFILEWILLBEDELETED);

	return dld->pMgr->DeleteFile ();
}

BOOL fsDownloadsMgr::AskToDeleteDownloadFile (vmsDownloadSmartPtr dld, BOOL bNoCancel, fsDeleteDownloadReaction &enDDRResult, bool &bApplyForAll)
{
	CDDRDlg dlg;

	dlg.m_bNoCancel = bNoCancel;
	if (dld->pMgr->GetDownloadMgr ())
		dlg.m_strUrl = dld->pMgr->get_URL ();
	else if (dld->pMgr->GetBtDownloadMgr ())
		dlg.m_strUrl = dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ();

	if (IDCANCEL == dlg.DoModal ())
		return FALSE;

	enDDRResult = dlg.m_enDDR;

	bApplyForAll = dlg.m_bDontAskAgain || dlg.m_bForAll;

	if (dlg.m_bDontAskAgain) 
		m_enDDR = enDDRResult;

	return TRUE;
}

void fsDownloadsMgr::GetDDRs (DLDS_LIST_REF vDlds, BOOL bDeleteCompletedFilesAlso, BOOL bNoCancel, std::vector <fsDeleteDownloadReaction> &vResult)
{
	vResult.clear ();

	if (vDlds.empty ())
		return;

	fsDeleteDownloadReaction enDefaultDDR = m_enDDR;

	for (size_t i = 0; i < vDlds.size (); i++)
	{
		fsDownload *dld = vDlds [i];

		fsDeleteDownloadReaction enDDR = enDefaultDDR;

		if (dld->dwFlags & DLD_DELETEFILEALWAYS)
			enDDR = DDR_WITHFILE;

		else if (dld->pMgr->IsDone () && !bDeleteCompletedFilesAlso)
			enDDR = DDR_FROMLISTONLY;

		else if (enDDR == DDR_ASK && dld->pMgr->IsFileInitializedOnDisk ())
		{
			bool bApplyForAll = false;
			if (FALSE == AskToDeleteDownloadFile (dld, bNoCancel, enDDR, bApplyForAll))
				return;
			if (bApplyForAll)
				enDefaultDDR = enDDR;
		}

		vResult.push_back (enDDR);
	}
}

void fsDownloadsMgr::ApplyDDRs (DLDS_LIST_REF vDlds, std::vector <fsDeleteDownloadReaction> &vDDRs, BOOL bNoCancel)
{
	fsDeleteDownloadReaction enDDRforDDR_ASK = DDR_ASK;

	for (size_t i = 0; i < vDlds.size (); i++)
	{
		fsDownload *dld = vDlds [i];

		fsDeleteDownloadReaction enDDR = vDDRs [i];
		if (enDDR == DDR_ASK)
			enDDR = enDDRforDDR_ASK;
		if (enDDR == DDR_ASK)
		{
			bool bApplyForAll = false;
			AskToDeleteDownloadFile (dld, bNoCancel, enDDR, bApplyForAll);
			if (bApplyForAll)
				enDDRforDDR_ASK = enDDR;
		}

		if (enDDR == DDR_WITHFILE)
		{
			
			DeleteDownloadFile (dld);
		}
	}
}

void fsDownloadsMgr::ClearDeleted()
{
	ASSERT (m_vDeletedDownloads_tmp.size () == 0);

	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	if (m_vDeletedDownloads.size () == 0)
		return;

	DLDS_LIST v;

	
	
	m_vDeletedDownloads.Copy(v);

	vmsAUTOLOCKSECTION_UNLOCK (m_csDeletedDownloads);

	DeleteDeletedDownloads (v, FALSE);
}

int fsDownloadsMgr::DeleteDeletedDownloads(DLDS_LIST &vDlds, BOOL bNoCancel)
{
	size_t cMaxDlds = 40;

	
	
	if (vDlds.size () < cMaxDlds)
		return DeleteDeletedDownloads2 (&vDlds, bNoCancel, NULL, NULL);

	

	int iDeleted = 0;
	
	CWaitDlg dlg;
	dlg.StartWaiting (LS (L_DELETINGDLDS), _threadWaitDelDeletingsDlds, TRUE, 
		&vDlds, &bNoCancel, &iDeleted, this);

	return iDeleted;
}

int fsDownloadsMgr::DeleteDeletedDownloads2(DLDS_LIST *vDlds, BOOL bNoCancel, BOOL* pbNeedStop, int* piProgress)
{
	UINT i = 0;

	std::vector <fsDeleteDownloadReaction> vDldsDDRs;

	GetDDRs (*vDlds, FALSE, FALSE, vDldsDDRs);
	if (vDldsDDRs.size () != vDlds->size ())
		return 0; 

	threadDeleteDownloadsParams *pThreadParams = new threadDeleteDownloadsParams;
	pThreadParams->pthis = this;
	
	vmsDownloadSmartPtr dldFake;
	Download_CreateInstance (dldFake);
	dldFake->pMgr->GetDownloadMgr ()->CreateByUrl ("http://localhost/", TRUE);

	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	m_bDeletingDeletedNow = TRUE;

	try 
	{
		ASSERT (m_vDeletedDownloads.size () != 0);

		std::vector <int> vIndexes;
		findDownloadsIndexes (*vDlds, m_vDeletedDownloads, vIndexes);

		for (i = 0; i < (UINT)vDlds->size (); i++)
		{
			
			
			if (pbNeedStop && *pbNeedStop)
				break;

			vmsDownloadSmartPtr dld = vDlds->at (i);

			int iIndex = vIndexes [i];
			if (iIndex == -1)
				continue;

			if (piProgress)
				*piProgress = (int) ((double)i / vDlds->size () * 100);

			Event (dld, DME_DLDWILLBEFULLYDELETED);
			if ((dld->dwFlags & DLD_DONTPUTTOHISTORY) == 0 &&
					dld->pMgr->IsDone () == FALSE)
				m_histmgr.AddToHistory (dld);

			m_vDeletedDownloads [iIndex] = dldFake;

			Event (dld, DME_DLDREMOVEDFROMDELETED);
			
			pThreadParams->vDlds.push_back (dld);
			pThreadParams->vDldsDDRs.push_back (vDldsDDRs [i]);
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::DeleteDeletedDownloads2 " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::DeleteDeletedDownloads2 unknown exception");
	}

	int cDeleted = i;

	DLDS_LIST v; v.reserve (m_vDeletedDownloads.size ());
	for (i = 0; i < m_vDeletedDownloads.size (); i++)
	{
		if (m_vDeletedDownloads [i] != dldFake)
			v.push_back (m_vDeletedDownloads [i]);
	}
	m_vDeletedDownloads = v;	

	m_bDeletingDeletedNow = FALSE;

	vmsAUTOLOCKSECTION_UNLOCK (m_csDeletedDownloads);

	
	

	Event (NULL, NULL, DME_RECYCLEBINCONTENTCHANGED);

	if (!pThreadParams->vDlds.empty ())
	{
		DWORD dw;
		CloseHandle (CreateThread (NULL, 0, _threadDeleteDownloads, pThreadParams, 0, &dw));
	}
	else
	{
		delete pThreadParams;
	}

	return cDeleted;
}

BOOL fsDownloadsMgr::IsDeletingDeletedNow()
{
	return m_bDeletingDeletedNow;
}

int fsDownloadsMgr::GetDeletedDownloadIndex(vmsDownloadSmartPtr dld)
{
	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	for (size_t i = 0; i < m_vDeletedDownloads.size (); i++)
	{
		if (m_vDeletedDownloads [i] == dld)
			return i;
	}

	return -1;
}

DWORD WINAPI fsDownloadsMgr::_threadWaitDelDeletingsDlds(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	DLDS_LIST *vDlds =  (DLDS_LIST*) info->lpParam1;
	BOOL bNoCancel = *(BOOL*) info->lpParam2;
	int *pcDlds = (int*) info->lpParam3;
	fsDownloadsMgr* pThis = (fsDownloadsMgr*) info->lpParam4;

	*pcDlds = pThis->DeleteDeletedDownloads2 (vDlds, bNoCancel, &info->bNeedStop, &info->iProgress);

	info->bWaitDone = TRUE;

	return 0;
}

int fsDownloadsMgr::RestoreDownloads(DLDS_LIST &vDlds)
{
	size_t cMaxDlds = 40;

	if (vDlds.size () < cMaxDlds)
		return RestoreDownloads2 (&vDlds, NULL, NULL);

	

	int iRestored = 0;
	
	CWaitDlg dlg;
	dlg.StartWaiting (LS (L_RESTORINGDLDS), _threadWaitRestoringDlds, TRUE, 
		&vDlds, &iRestored, this);

	return iRestored;
}

int fsDownloadsMgr::RestoreDownloads2(DLDS_LIST* vDlds, BOOL *pbNeedStop, int *piProgress)
{
	UINT i = 0;

	
	while (IsRestoringNow ())
	{
		if (pbNeedStop && *pbNeedStop)
			break;

		
#ifdef ADDITIONAL_MSG_LOOPS_REQUIRED
		MSG msg;
		while (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
			DispatchMessage (&msg);
#endif

		Sleep (50);
	}

	if (pbNeedStop && *pbNeedStop)
		return 0;

	vmsDownloadSmartPtr dldFake;
	Download_CreateInstance (dldFake);
	dldFake->pMgr->GetDownloadMgr ()->CreateByUrl ("http://localhost/", TRUE);

	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	m_bRestoringNow = TRUE;

	try {

		ASSERT (m_vDeletedDownloads.size () != 0);

		std::vector <int> vIndexes;
		findDownloadsIndexes (*vDlds, m_vDeletedDownloads, vIndexes);

		for (i = 0; i < (UINT)vDlds->size (); i++)
		{
			
			
			if (pbNeedStop && *pbNeedStop)
				break;

			vmsDownloadSmartPtr dld = vDlds->at (i);

			int iIndex = vIndexes [i];
			if (iIndex == -1)
				continue;

			if (dld->pGroup->bAboutToBeDeleted)
				dld->pGroup = _DldsGrps.FindGroup (GRP_OTHER_ID);

			m_vDeletedDownloads [iIndex] = dldFake;
			Event (dld, DME_DLDREMOVEDFROMDELETED);

			Add (dld, TRUE);
			if (dld->dwFlags & DLD_FLASH_VIDEO)
				_pwndFVDownloads->AddDownload (dld, FALSE);
			if (_pwndTorrents && dld->isTorrent ())
				_pwndTorrents->AddDownload (dld, FALSE);

			Event (dld, DME_DLDRESTORED);

			if (piProgress)
				*piProgress = (int) ((double)i / vDlds->size () * 100);
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::RestoreDownloads2 " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::RestoreDownloads2 unknown exception");
	}

	int cRestored = i;

	DLDS_LIST v;
	for (i = 0; i < m_vDeletedDownloads.size (); i++)
	{
		if (m_vDeletedDownloads [i] != dldFake)
			v.push_back (m_vDeletedDownloads [i]);
	}
	m_vDeletedDownloads = v;	

	m_bRestoringNow = FALSE;

	vmsAUTOLOCKSECTION_UNLOCK (m_csDeletedDownloads);
	
	

	Event (NULL, NULL, DME_RECYCLEBINCONTENTCHANGED);

	if (cRestored)
		setNeedProcessDownloads ();

	return cRestored;	
}

BOOL fsDownloadsMgr::IsRestoringNow()
{
	return m_bRestoringNow;
}

DWORD WINAPI fsDownloadsMgr::_threadWaitRestoringDlds(LPVOID lp)
{
	ProcWaitInfo *info = (ProcWaitInfo*) lp;
	DLDS_LIST *vDlds =  (DLDS_LIST*) info->lpParam1;
	int *pcDlds = (int*) info->lpParam2;
	fsDownloadsMgr* pThis = (fsDownloadsMgr*) info->lpParam3;

	*pcDlds = pThis->RestoreDownloads2 (vDlds, &info->bNeedStop, &info->iProgress);

	info->bWaitDone = TRUE;

	return 0;
}

void fsDownloadsMgr::_HistoryMgrEvents(fsDownloadsHistoryMgrEvent ev, fsDLHistoryRecord *rec, LPVOID lp)
{
	fsDownloadsMgr* pThis = (fsDownloadsMgr*) lp;

	switch (ev)
	{
		case DHME_RECORDADDED:
			pThis->Event (rec, DME_RECADDEDTOHISTORY);
			break;

		case DHME_RECORDDELETED:
			pThis->Event (rec, DME_RECDELETEDFROMHISTORY);
			break;

		case DHME_HISTORYCLEARED:
			pThis->Event (rec, DME_HISTORYCLEARED);
			break;
	}
}

void fsDownloadsMgr::Event(fsDLHistoryRecord *rec, fsDownloadsMgrEvent ev)
{
	if (m_pfnEvents)
		m_pfnEvents (NULL, rec, ev, m_lpEventsParam);
}

DWORD fsDownloadsMgr::Event(fsDownload *dld, fsDownloadsMgrEvent ev)
{
	return Event (dld, NULL, ev);
}

struct _threadArchiveDetectedInfo
{
	fsArchiveRebuilder *ar;
	BOOL* pbRes;
};

DWORD fsDownloadsMgr::OnArchiveDetected(vmsDownloadSmartPtr dld, fsArchiveRebuilder *ar)
{
	BOOL b;
	UIThread *thr = (UIThread*) RUNTIME_CLASS (UIThread)->CreateObject ();
	_threadArchiveDetectedInfo inf;
	inf.ar = ar; inf.pbRes = &b;
	thr->set_Thread (_threadArchiveDetected, &inf);
	thr->CreateThread ();
	WaitForSingleObject (thr->m_hThread, INFINITE);

	if (b == FALSE) {
		dld->bAutoStart = FALSE;
		dld->setDirty();
	}

	return b;
}

void fsDownloadsMgr::MoveDownloadToEndOfList(vmsDownloadSmartPtr dld)
{
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);
	int iIndex = GetDownloadIndex (dld);
	if (iIndex != -1)
	{
		DownloadsList_Del (iIndex);
		DownloadsList_Add (dld);
	}
}

DWORD WINAPI fsDownloadsMgr::_threadConfirmZIP(LPVOID lp)
{
	CWaitForConfirmationDlg dlg;
	UINT* pnRes = (UINT*) lp;

	dlg.Init (LS (L_ZIPDETECTED), 30, TRUE, TRUE, LS (L_DONTPREVIEWINFUTURE), LS (L_YOUTURNEDOFFPREVIEW));

	*pnRes = _DlgMgr.DoModal (&dlg) == IDOK;

	if (dlg.m_bDontAsk)
		_App.NewDL_UseZIPPreview (FALSE);

	return 0;
}

DWORD WINAPI fsDownloadsMgr::_threadArchiveDetected(LPVOID lp)
{
	CZipPreviewDlg dlg;
	_threadArchiveDetectedInfo* inf = (_threadArchiveDetectedInfo*) lp;

	dlg.m_ar = inf->ar;
	*inf->pbRes = _DlgMgr.DoModal (&dlg) == IDOK;

	return 0;
}

void fsDownloadsMgr::Initialize()
{
	ReadSettings ();

	InterlockedIncrement (&m_cThreadsRunning);
	
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadDownloadsMgr, this, 0, &dw));
}

void fsDownloadsMgr::LaunchDownload(vmsDownloadSmartPtr dld, UINT nWaitForConfirmation)
{
	if (nWaitForConfirmation != 0)
	{
		CWaitForConfirmationDlg dlg;
		char szFile [MY_MAX_PATH];
		if (dld->pMgr->GetDownloadMgr ())
			fsGetFileName (dld->pMgr->get_OutputFilePathName (), szFile);
		else if (dld->pMgr->GetBtDownloadMgr ())
			lstrcpy (szFile, dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ());
		CString strMsg = "\""; strMsg += szFile; strMsg += "\" ";
		if (dld->strComment != "") {
			strMsg += '('; strMsg += dld->strComment; strMsg += ") ";
		}
		strMsg += LS (L_WASSCHEDULEDTOLAUNCH); strMsg += "\n";
		strMsg += LS (L_DOYOUWANTTOLAUNCHIT);
		dlg.Init (strMsg, nWaitForConfirmation);
		if (IDCANCEL == dlg.DoModal ())
			return;
	}

	dld->setStateFlags (DLDS_FILE_WAS_LAUNCHED_AT_LEAST_ONCE);
	dld->setDirty();

	CString strFileName = dld->pMgr->get_OutputFilePathName ();
	if (dld->pMgr->IsBittorrent ())
		strFileName += dld->pMgr->GetBtDownloadMgr ()->get_RootFolderName ();

	ShellExecute (::GetDesktopWindow (), "open", strFileName, NULL, NULL, SW_SHOW);
}

void fsDownloadsMgr::Shutdown()
{
	vmsAUTOLOCKSECTION (m_csShuttingDown);
	m_bShuttingDown = TRUE;
	vmsAUTOLOCKSECTION_UNLOCK (m_csShuttingDown);
	
	while (m_cThreadsRunning)
		Sleep (10);

	if (_BT.is_Initialized ())
		_BT.get_Session ()->set_EventsHandler (NULL, NULL);

	for (size_t i = 0; i < m_vDownloads.size (); i++)
		UnregisterDownloadInTum (m_vDownloads [i]);
	
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);
	m_vDownloads.DeleteAll();
	vmsAUTOLOCKRW_WRITE_UNLOCK (m_rwlDownloads);

	vmsAUTOLOCKSECTION (m_csBtDownloadManagerEvents);
	m_vBtDownloadManagerEvents.clear ();

	vmsAUTOLOCKSECTION (m_csDeletedDownloads);
	
	
	m_vDeletedDownloads.DeleteAll();
}

void fsDownloadsMgr::ApplyAER(fsAlreadyExistReaction enAER)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	for (int i = m_vDownloads.size () - 1; i >= 0; i--)
	{
		if (m_vDownloads [i]->pMgr->GetDownloadMgr () != NULL) {
			m_vDownloads [i]->pMgr->GetDownloadMgr ()->GetDP ()->enAER = enAER;
			m_vDownloads [i]->pMgr->GetDownloadMgr ()->setDirty();
		}
	}
}

BOOL fsDownloadsMgr::GenerateDescriptionFile(vmsDownloadSmartPtr dld)
{
	if (dld->strComment.GetLength () == 0)
		return FALSE;

	CString str = dld->strComment;
	str.Replace ("\r", "");

	str += "\n\n"; str += LS (L_THISFILEWASDLDEDFROM); str += ":\n";
	if (dld->pMgr->GetDownloadMgr ())
	{
		str += dld->pMgr->get_URL ();
	}
	else if (dld->pMgr->GetBtDownloadMgr ())
	{
		str += dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ();
		str += " (";
		str += dld->pMgr->get_URL ();
		str += ")";
	}

	str += "\n\n"; str += LS (L_DATE); str += ": ";
	
	FILETIME time;
	SYSTEMTIME systime;
	GetLocalTime (&systime);
	SystemTimeToFileTime (&systime, &time);

	char szDate [1000], szTime [1000];
	FileTimeToStr (&time, szDate, szTime, FALSE);
	str += szDate; str += ", "; str += szTime;

	CStdioFile file;
	CString strName = dld->pMgr->get_OutputFilePathName ();
	if (dld->pMgr->GetBtDownloadMgr () != NULL && 
			dld->pMgr->GetBtDownloadMgr ()->get_FileCount () != 1)
	{
		strName += "\\"; 
		strName += dld->pMgr->GetBtDownloadMgr ()->get_TorrentName ();
	}
	strName += ".dsc.txt";

	file.Open (strName, CFile::typeText | CFile::modeCreate | CFile::modeWrite);
	file.WriteString (str);
	file.Close ();

	return TRUE;
}

BOOL fsDownloadsMgr::LoadStateInformation()
{
	CString strFileName = fsGetDataFilePath ("dlmgrsi.sav");

	if (GetFileAttributes (strFileName) == DWORD (-1))
		return TRUE;

	HANDLE hFile  = CreateFile (strFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING,
		0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dw;
	DWORD dwRequiredSize = ::GetFileSize(hFile, NULL);

	fsStateInfoFileHdr hdr;

	if (dwRequiredSize < sizeof (hdr))
		return FALSE;

	if (FALSE == ReadFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	dwRequiredSize -= sizeof(hdr);

	BOOL bOldFormat = FALSE;

	if (strncmp (hdr.szSig, DLMGRFILE_SIG, sizeof (DLMGRFILE_SIG)))
	{
		
		
		bOldFormat = TRUE;
		SetFilePointer (hFile, 0, NULL, FILE_BEGIN);
	}

	if (bOldFormat) {

		UINT u;
		if (FALSE == ReadFile (hFile, &u, sizeof (u), &dw, NULL))
		{
			CloseHandle (hFile);
			return false;
		}

		
		
		m_siStateInfo.SetId(u);

	
		vmsStringRecentList vFilePathes;
		if (FALSE == vFilePathes.Load (hFile))
		{
			CloseHandle (hFile);
			return false;
		}

		for (int i = 0; i < vFilePathes.get_Count (); i++)
		{
			char sz [MY_MAX_PATH] = "";
			fsGetFileName (vFilePathes.get_String (i), sz);
			
			
			m_siStateInfo.GetFileRecentList().Add (sz, vFilePathes.get_String (i), true);
		}
	} else {
		if (dwRequiredSize > 0) {
			std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
			LPBYTE pbtBuffer = apbtBufferGuard.get();
			if (!pbtBuffer)
				return false;
			memset(pbtBuffer, 0, dwRequiredSize);

			if (FALSE == ReadFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize) {
				CloseHandle (hFile);
				return false;
			}

			m_siStateInfo.loadFromStateBuffer(pbtBuffer, &dwRequiredSize, hdr.wVer);
		}
	}

	CloseHandle (hFile);
	return true;
}

BOOL fsDownloadsMgr::SaveStateInformation()
{
	if (!m_siStateInfo.isDirty())
		return TRUE;

	CString strFileName = fsGetDataFilePath ("dlmgrsi.sav");

	HANDLE hFile = CreateFile (strFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_HIDDEN, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dw;

	fsStateInfoFileHdr hdr;
	if (FALSE == WriteFile (hFile, &hdr, sizeof (hdr), &dw, NULL))
	{
		CloseHandle (hFile);
		return FALSE;
	}

	DWORD dwRequiredSize = 0;
	m_siStateInfo.getStateBuffer(0, &dwRequiredSize, false);

	std::auto_ptr<BYTE> apbtBufferGuard( new BYTE[dwRequiredSize] );
	LPBYTE pbtBuffer = apbtBufferGuard.get();
	if (!pbtBuffer)
		return FALSE;

	m_siStateInfo.getStateBuffer(pbtBuffer, &dwRequiredSize, true);

	if (!WriteFile (hFile, pbtBuffer, dwRequiredSize, &dw, NULL) || dw != dwRequiredSize){
		CloseHandle (hFile);
		return FALSE;
	}

	CloseHandle (hFile);

	m_siStateInfo.onStateSavedSuccessfully();

	return TRUE;

	
	
	
	
	
	
	
	
	
	
	
	
	
}

UINT fsDownloadsMgr::GetNextDownloadID()
{
	
	
	return m_siStateInfo.GetId();
}

vmsFileRecentList* fsDownloadsMgr::get_LastFilesDownloaded()
{
	
	
	return &m_siStateInfo.GetFileRecentList();
}

void fsDownloadsMgr::LastFilesDownloaded_Clear()
{
	
	
	m_siStateInfo.GetFileRecentList().Clear ();
}

void fsDownloadsMgr::MoveDownloads(DLDS_LIST_REF vDlds, vmsDownloadSmartPtr pDldPosition, bool bUp)
{
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);

	size_t nIndexPos = GetDownloadIndex (pDldPosition);

	size_t i = 0;
	for (i = 0; i < vDlds.size (); i++)
	{
		size_t nIndex = GetDownloadIndex (vDlds [i]);
		if (nIndex == -1) 
		{
			vDlds.erase (vDlds.begin () + i--);
			continue;
		}
		DownloadsList_Del (nIndex);
	}

	size_t n = GetDownloadIndex (pDldPosition);
	if (n != -1)
		nIndexPos = n;
	if (bUp == false)
		nIndexPos++;
	if (nIndexPos > m_vDownloads.size ())
		nIndexPos = m_vDownloads.size ();

	for (i = 0; i < vDlds.size (); i++)
		DownloadsList_Insert (nIndexPos++, vDlds [i]);
}

void fsDownloadsMgr::ReorderDownloads(DLDS_LIST_REF vDlds, DLDS_LIST_REF vReqOrder, bool bDldsSorted)
{
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);

	if (vDlds.size () != vReqOrder.size ())
		return;	

	
	std::vector <int> vIndxs;
	
	
	size_t nPrevIndx = (size_t)-1; 
	size_t i = 0;
	for (i = 0; i < vDlds.size (); i++) 
	{
		if (m_vDownloads [nPrevIndx + 1] == vDlds [i]) {
			vIndxs.push_back (++nPrevIndx);	
		}
		else {
			
			
			
			vIndxs.push_back (nPrevIndx = GetDownloadIndex (vDlds [i], bDldsSorted ? nPrevIndx + 1 : 0));
			if (nPrevIndx == m_vDownloads.size () - 1)
				nPrevIndx = (size_t)-1;
		}
	}

	

	for (i = 0; i < vReqOrder.size (); i++)
	{
		size_t nNewIndx = vIndxs [i];	
		if (nNewIndx == (size_t)-1)
			continue;

		size_t nOldIndx;	

		

		vmsDownloadSmartPtr dld = vReqOrder [i];
		size_t j = 0;
		for (j = 0; j < vDlds.size (); j++){
			if (dld == vDlds [j])
				break;
		}
		if (j == vDlds.size ())
			continue;	
		nOldIndx = vIndxs [j];
		if (nOldIndx == (size_t)-1)
			continue;

		

		vIndxs [i] = (size_t)-1;	
		vIndxs [j] = (size_t)-1;	

		if (nNewIndx != nOldIndx)
		{
			

			vmsDownloadSmartPtr dldTmp = m_vDownloads [nNewIndx];
			m_vDownloads [nNewIndx] = dld;
			m_vDownloads [nOldIndx] = dldTmp;
		}
	}

	m_vDownloads.setDirty ();
}

DWORD WINAPI fsDownloadsMgr::_threadIntegrityCheckAndVirCheckAndLaunch(LPVOID lp)
{
	vmsDownloadSmartPtr dld = (fsDownload*) lp;
	dld->Release (); 

	bool bNeedLaunchDld = (dld->dwFlags & DLD_NOAUTOLAUNCH) == 0 && 
		dld->pMgr->IsLaunchWhenDone ();
	bool bNeedIntegrityCheck = dld->pMgr->GetDownloadMgr () != NULL && 
		dld->pMgr->GetDownloadMgr ()->GetDP ()->bCheckIntegrityWhenDone && 
		*dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum;

	if (bNeedIntegrityCheck)
	{
		_DldsMgr.Event (dld, LS (L_PERFORMINGINTEGRITYCHECK), EDT_INQUIRY);

		fsDownload_Properties *dp = dld->pMgr->GetDownloadMgr ()->GetDP ();

		vmsHash hash;
		hash.set_SHA2Strength ((vmsHash_SHA2Strength) HIWORD (dp->dwIntegrityCheckAlgorithm));
		fsString strHashResult = hash.Hash (dp->pszFileName, (vmsHashAlgorithm) LOWORD (dp->dwIntegrityCheckAlgorithm)).c_str ();
		if (strHashResult == (LPCTSTR)dp->pszCheckSum)
		{
			
			_DldsMgr.Event (dld, LS (L_INTEGRITYCHECKSUCCEEDED), EDT_RESPONSE_S);
		}
		else
		{
			
			_DldsMgr.Event (dld, LS (L_INTEGRITYCHECKFAILED), EDT_RESPONSE_E);

			switch (dp->enICFR)
			{
			case ICFR_ASKUSER:
			{
				CDlg_CheckFileIntegrity_Result dlg;
				dlg.m_bResultOK = FALSE;
				char sz [MY_MAX_PATH];
				fsGetFileName (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, sz);
				dlg.m_strFileName = sz;
				dlg.m_strUrl = dld->pMgr->get_URL ();
				dlg.m_strValidHash = dp->pszCheckSum;
				dlg.m_strResultHash = strHashResult;
				if (IDC_RESTARTDOWNLOAD == _DlgMgr.DoModal (&dlg))
				{
					_pwndDownloads->RestartDownload (dld, TRUE);
					return 0;
				}
			}
			break;

			case ICFR_RESTART:
				_pwndDownloads->RestartDownload (dld, TRUE);
			return 0;

			case ICFR_IGNORE:
			break;

			default:
				ASSERT (FALSE);
			}
		}
	}

	if (_DldsMgr.m_bVirCheck)
	{
		BOOL bOk = _DldsMgr.PerformVirusCheck (dld, TRUE, bNeedLaunchDld);

		if (bOk == FALSE && bNeedLaunchDld)
		{
			CWaitForConfirmationDlg dlg;
			dlg.Init (LS (L_VIRCHECKFAILEDLAUNCHDLDANYWAY), 60, FALSE, TRUE);
			dlg.m_pszIcon = IDI_WARNING;

			if (IDOK != _DlgMgr.DoModal (&dlg))
				bNeedLaunchDld = false;
		}
	}

	if (dld->dwFlags & DLD_FLASH_VIDEO)
		_pwndFVDownloads->OnDownloadDone (dld);

	if (bNeedLaunchDld)
	{
		dld->AddRef (); 
		_pwndDownloads->PostMessage (WM_DLD_LAUNCH, 
			dld->pMgr->IsDontConfirmLaunchWhenDone () ? 0 : _App.ConfTimeout_LaunchDld (),
			(LPARAM)(fsDownload*)dld);
	}

	_DldsMgr.OnDldDoneCheckIfNeedDel (dld);

	InterlockedDecrement (&_DldsMgr.m_cThreadsRunning);

	return 0;
}

void fsDownloadsMgr::OnDldDoneCheckIfNeedDel(vmsDownloadSmartPtr dld)
{
	if (m_bAutoDelCompleted || (dld->dwFlags & DLD_DELETEWHENDONE) != 0)
	{
		DLDS_LIST vDlds;
		vDlds.push_back (dld);
		DeleteDownloads (vDlds, FALSE, (dld->dwFlags & DLD_DELETEFILEALWAYS) != FALSE);
		Event ((fsDownload*)NULL, DME_DLDAUTODELETED);
	}
}

BOOL fsDownloadsMgr::OnDldDone_CheckDownloadIsMetaLink(vmsDownloadSmartPtr dld)
{
	if (dld->pMgr->GetDownloadMgr () == NULL)
		return FALSE;

	fsString strFile = dld->pMgr->get_OutputFilePathName ();
	if (lstrlen (strFile) > 10 && lstrcmpi (strFile + lstrlen (strFile) - 9, ".metalink") != 0)
		return FALSE; 

	vmsMetalinkFile mf;
	if (FALSE == mf.Parse (strFile))
		return FALSE;

	if (mf.get_FileCount () == 0)
		return FALSE;

	std::vector <int> viFiles;

	int iFile = 0;
	for (iFile = 0; iFile < mf.get_FileCount (); iFile++)
	{
		vmsMetalinkFile_File *file = mf.get_File (iFile);

		
		if (file->strOS.GetLength () && strstr (file->strOS, "Windows") == NULL)
			continue;

		viFiles.push_back (iFile);
	}

	if (viFiles.size () == 0)
		viFiles.push_back (0);

	for (iFile = 0; iFile < (int)viFiles.size (); iFile++)
	{
		vmsMetalinkFile_File *file = mf.get_File (viFiles [iFile]);
	
		if (file->vMirrors.size () == 0)
		{
			if (iFile == 0)
				return FALSE;
			else
				continue;
		}

		if (iFile)
		{
			vmsDownloadSmartPtr dld2;
			Download_CreateInstance (dld2);
			_DldsMgr.Download_CloneSettings (dld2, dld);
			dld = dld2;
		}

		
		fsString strBtUrl;
		
		BOOL bRecreated = FALSE;

		int i = 0;
		for (i = 0; i < file->vMirrors.size (); i++)
		{
			vmsMetalinkFile_File_Url *url = &file->vMirrors [i];

			if (strcmpi (url->strProtocol, "http") && strcmpi (url->strProtocol, "https") &&
					strcmpi (url->strProtocol, "ftp"))
			{
				if (strcmpi (url->strProtocol, "bittorrent") == 0)
					strBtUrl = url->strUrl;
				continue;
			}

			if (bRecreated == FALSE)
			{
				if (IR_SUCCESS != dld->pMgr->GetDownloadMgr ()->CreateByUrl (url->strUrl, TRUE))
					continue;
				if (iFile == 0) {
					dld->pMgr->GetDownloadMgr ()->Reset ();
				}
				bRecreated = TRUE;
			}
			else
			{
				dld->pMgr->GetDownloadMgr ()->GetDownloader ()->AddMirrorURL (url->strUrl);
			}
		}

		if (bRecreated == FALSE)
		{
			if (strBtUrl.IsEmpty ())
				return FALSE;
			
			
			if (IR_SUCCESS != dld->pMgr->GetDownloadMgr ()->CreateByUrl (strBtUrl, TRUE))
			{
				if (iFile == 0)
					return FALSE;
				continue;
			}
			if (iFile == 0) {
				dld->pMgr->GetDownloadMgr ()->Reset ();
			}
			bRecreated = TRUE;
		}
		
		if (iFile == 0)
			Event (dld, LS (L_METALINK_DETECTED), EDT_INQUIRY);

		for (i = 0; i < file->vHashes.size (); i++)
		{
			vmsMetalinkFile_File_Hash *hash = &file->vHashes [i];
			DWORD dwAlg;
			if (hash->strChecksum.GetLength () == 0)
				continue;
		
			if (lstrcmpi (hash->strAlgorithm, "md5") == 0)
				dwAlg = HA_MD5;

			else if (lstrcmpi (hash->strAlgorithm, "sha1") == 0 || 
					lstrcmpi (hash->strAlgorithm, "sha-1") == 0)
				dwAlg = HA_SHA1;

			else
				continue;

			
			dld->pMgr->GetDownloadMgr ()->GetDP ()->dwIntegrityCheckAlgorithm = dwAlg;
			SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum);
			dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum = new char [hash->strChecksum.GetLength () + 1];
			lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum, hash->strChecksum);
			dld->pMgr->GetDownloadMgr ()->setDirty();
		}
		
		if (iFile == 0)
			DeleteFile (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName);
		LPSTR psz = strrchr (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, '\\');
		if (psz == NULL)
			psz = strrchr (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, '/');
		if (psz)
			*psz = 0;

		fsString strNewFile;
		strNewFile = dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName;
		strNewFile += "\\";
		if (file->strName.pszString != NULL && strstr (file->strName, "..\\") == NULL &&
				strstr (file->strName, "../") == NULL)
			strNewFile += file->strName;
		SAFE_DELETE_ARRAY (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName);
		dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName = new char [strNewFile.Length () + 1];
		lstrcpy (dld->pMgr->GetDownloadMgr ()->GetDP ()->pszFileName, strNewFile);

		dld->pMgr->GetDownloadMgr ()->setDirty();

		if (dld->strComment.GetLength () != 0)
			dld->strComment += "\r\n";
		dld->strComment += mf.get_Description ();
		dld->setDirty();

		if (iFile == 0)
			dld->pMgr->StartDownloading ();
		else
			_pwndDownloads->CreateDownload (dld, NULL, FALSE, false);
	}

	return TRUE;
}

void fsDownloadsMgr::DownloadsList_Add(vmsDownloadSmartPtr dld)
{
	
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);	
	m_vDownloads.Add(dld);
	dld->pGroup->cDownloads++;
}

void fsDownloadsMgr::DownloadsList_Del(size_t nIndex)
{
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);
	m_vDownloads [nIndex]->pGroup->cDownloads--;
	m_vDownloads.Delete(nIndex);
}

void fsDownloadsMgr::DownloadsList_Insert(size_t nIndexBefore, vmsDownloadSmartPtr dld)
{
	vmsAUTOLOCKRW_WRITE (m_rwlDownloads);
	m_vDownloads.Insert(dld, nIndexBefore);
	dld->pGroup->cDownloads++;
}

void fsDownloadsMgr::DeletedDownloads_UseTmpList(BOOL bUse)
{
	vmsAUTOLOCKSECTION (m_csDeletedDownloads);

	if (bUse)
	{
		ASSERT (m_vDeletedDownloads_tmp.size () == 0);
		std::list <vmsDownloadSmartPtr> v;
		for (size_t i = 0; i < m_vDeletedDownloads.size (); i++)
			v.push_back (m_vDeletedDownloads [i]);
		m_vDeletedDownloads_tmp = v;
		
		
		
		m_vDeletedDownloads.DeleteAll();
	}
	else
	{
		ASSERT (m_vDeletedDownloads.size () == 0);
		DLDS_LIST v;
		std::list <vmsDownloadSmartPtr>::iterator iter;
		for (iter = m_vDeletedDownloads_tmp.begin (); iter != m_vDeletedDownloads_tmp.end (); iter++)
			v.push_back (*iter);
		m_vDeletedDownloads = v;
		
		
		m_vDeletedDownloads_tmp.clear ();		
	}
}

BOOL fsDownloadsMgr::DeleteGroupsDownloads(vmsDownloadsGroupSmartPtr pGroup, BOOL bInclSubgroups)
{
	std::vector <vmsDownloadsGroupSmartPtr> v;
	if (bInclSubgroups)
		_DldsGrps.GetGroupWithSubgroups (pGroup, v);
	else
		v.push_back (pGroup);

	DLDS_LIST vDlds;

	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	for (int i = m_vDownloads.size () - 1; i >= 0; i--)
	{
		vmsDownloadSmartPtr dld = m_vDownloads [i];
		
		for (size_t j = 0; j < v.size (); j++)
		{
			if (v [j] == dld->pGroup)
			{
				
				vDlds.push_back (dld);
				break;
			}
		}
	}

	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);

	if (vDlds.size () == 0)
		return TRUE;

	size_t cToDelete = vDlds.size ();
	size_t cDeleted = DeleteDownloads (vDlds, TRUE, FALSE);
	if (cDeleted != cToDelete)
		return FALSE;

	return TRUE;
}

void fsDownloadsMgr::GetEventColors(fsDownloadMgr_EventDescType enType, COLORREF &clrText, COLORREF &clrBg, int &iImage)
{
	clrText = RGB (0, 0, 0);

	
	
	switch (enType)
	{
		case EDT_INQUIRY:
			clrBg = CLR_INQUIRY;
			iImage = 0;
			break;

		case EDT_INQUIRY2:
			clrBg = CLR_INQUIRY2;
			iImage = 0;
			break;

		case EDT_DONE:
			clrBg = CLR_DONE;
			iImage = 1;
			break;

		case EDT_RESPONSE_S:
			clrBg = CLR_RESPONSE_S;
			iImage = 2;
			break;

		case EDT_RESPONSE_S2:
			clrBg = CLR_RESPONSE_S2;
			iImage = 2;
			break;

		case EDT_RESPONSE_E:
			clrBg = CLR_RESPONSE_E;
			iImage = 3;
			break;

		case EDT_WARNING:
			clrBg = CLR_WARNING;
			iImage = 5;
			break;

		default:
			ASSERT (4!=4);
			return;
	}
}

BOOL fsDownloadsMgr::OnDldDone_CheckDownloadIsBittorrent(vmsDownloadSmartPtr dld)
{
	if (Is9xME)
		return FALSE;

	if (dld->pMgr->GetDownloadMgr () == NULL)
		return FALSE;

	fsString strFile = dld->pMgr->get_OutputFilePathName ();

	if ((dld->dwFlags & DLD_TORRENT_DOWNLOAD) == 0)
	{
		if (lstrlen (strFile) > 10 && lstrcmpi (strFile + lstrlen (strFile) - 8, ".torrent") != 0)
			return FALSE; 
	}

	if (_App.Bittorrent_Enable () == FALSE)
	{
		if (_App.View_DontAskEnableBittorrent () == FALSE)
		{
			CMyMessageBox dlg (_pwndDownloads);
			dlg.m_hIcon = LoadIcon (NULL, IDI_QUESTION);
			dlg.m_strBtn1Text = LS (L_YES);
			dlg.m_strBtn2Text = LS (L_NO);
			dlg.m_strCheckBoxText = LS (L_DONTASKAGAIN);
			dlg.m_strText = LS (L_ENABLEBTISREQ);
			dlg.m_strTitle = LS (L_CONFIRMATION);
			dlg.m_bChecked = FALSE;
			if (IDC_BTN1 != _DlgMgr.DoModal (&dlg))
			{
				if (dlg.m_bChecked)
					_App.View_DontAskEnableBittorrent (TRUE);
				return FALSE;
			}
			_App.Bittorrent_Enable (TRUE);
		}
		else 
		{
			return FALSE;
		}
	}

	if (_AppMgr.IsBtInstalled () == FALSE)
	{
		_AppMgr.ShowInstallBtMessage ();
		_App.Bittorrent_Enable (FALSE);
		return FALSE;
	}

	dld->pMgr->GetDownloadMgr ()->CloseFile ();

	
	
	if (dld->pGroup->nId == GRP_OTHER_ID)
	{
		vmsBtFile *pBtFile = _BT.CreateTorrentFileObject ();
		if (pBtFile && pBtFile->LoadFromFile (strFile) && pBtFile->get_FileCount () == 1)
		{
			char sz [MY_MAX_PATH] = "";
			pBtFile->get_FileName2 (0, sz, sizeof (sz));
			LPCSTR psz = strrchr (sz, '.');
			if (psz)
			{
				vmsDownloadsGroupSmartPtr pGrp = _DldsGrps.FindGroupByExt (psz + 1);
				if (pGrp != NULL)
				{
					ChangeDownloadGroup (dld, pGrp);
					strFile = dld->pMgr->get_OutputFilePathName ();
				}
			}
		}
		if (pBtFile)
			pBtFile->Release ();
	}

	char szPath [MY_MAX_PATH];
	fsGetPath (strFile, szPath);

	vmsBtDownloadManagerPtr pBtMgr; 
	pBtMgr.CreateInstance ();

	if (dld->pMgr->GetDownloadMgr ()->GetDP ()->bReserveDiskSpace)
		pBtMgr->enable_Flags (BTDF_RESERVE_DISK_SPACE);
	else
		pBtMgr->disable_Flags (BTDF_RESERVE_DISK_SPACE);

	if (dld->pMgr->IsLaunchWhenDone ())
		pBtMgr->enable_Flags (BTDF_LAUNCH_WHEN_DONE);
	else
		pBtMgr->disable_Flags (BTDF_LAUNCH_WHEN_DONE);

	if (dld->pMgr->IsDescriptionFileShouldBeGenerated ())
		pBtMgr->enable_Flags (BTDF_GENERATE_DESC_FILE);
	else
		pBtMgr->disable_Flags (BTDF_GENERATE_DESC_FILE);

	if (dld->pMgr->GetDownloadMgr ()->GetDP ()->bIgnoreRestrictions)
		pBtMgr->enable_Flags (BTDF_IGNORE_ALL_RESTRICTIONS);
	else
		pBtMgr->disable_Flags (BTDF_IGNORE_ALL_RESTRICTIONS);

	if (FALSE == pBtMgr->CreateByTorrentFile (strFile, szPath, dld->pMgr->get_URL ()))
		return FALSE;

	
	
	

	if (NULL != findBtDownloadByHash (pBtMgr))
	{
		EventEx (dld, LS (L_SUCHTORRENTEXISTSALREADY), EDT_WARNING, 70);
		return FALSE;
	}

	fsString strComment = pBtMgr->get_TorrentComment ();
	if (strComment.IsEmpty () == FALSE)
	{
		if (dld->strComment.IsEmpty () == FALSE)
			dld->strComment += "\r\n";
		dld->strComment += strComment;
		dld->setDirty(); 
	}

	vmsDownloadMgrEx *pNewMgr = new vmsDownloadMgrEx;
	pNewMgr->Attach (pBtMgr);

	vmsDownloadMgrEx *pMgr = dld->pMgr;
	pMgr->AddRef ();
	

	dld->setDownloadMgr (pNewMgr);
	dld->pMgr->GetBtDownloadMgr ()->SetEventsHandler (_BtDownloadManagerEventHandler, this);

	Event (dld, DME_DLD_CHANGED_TO_BT_TYPE);
	Event (dld, LS (L_BITTORRENT_DETECTED), EDT_INQUIRY);
	Event (dld, DME_BTDLD_STAT_CHANGED);

	if ((dld->dwFlags & DLD_TORRENT_DOWNLOAD) == 0)
	{
		dld->dwFlags |= DLD_TORRENT_DOWNLOAD;
		dld->setDirty();
		if (_pwndTorrents)
			_pwndTorrents->AddDownload (dld, FALSE);
	}

	dld->pMgr->StartDownloading ();

	DWORD dw;	
	CloseHandle (
		CreateThread (NULL, 0, _threadDeleteDownloadMgrEx, pMgr, 0, &dw));

	return TRUE;
}

DWORD WINAPI fsDownloadsMgr::_threadDeleteDownloadMgrEx(LPVOID lp)
{
	vmsDownloadMgrEx *pMgr = (vmsDownloadMgrEx*) lp;
	pMgr->Release ();
	return 0;
}

void fsDownloadsMgr::_BtSessionEventsHandler(vmsBtSession *, vmsBtSessionEvent *ev, LPVOID lp)
{
	fsDownloadsMgr *pthis = (fsDownloadsMgr*)lp;

	vmsDownloadSmartPtr dld;
	if (ev->pDownload)
		dld = pthis->FindDownloadByBtDownload (ev->pDownload);
	if (dld == NULL)
		return;

	std::string strTmp;

	if (ev->enType != BTSET_TRACKER_ERROR)
	{
		std::map<vmsDownloadSmartPtr, vmsDldErrorStamp>::iterator iter = 
			pthis->m_dldErrorsMap.find(dld);
		if (iter != pthis->m_dldErrorsMap.end())
		{
			vmsDownloadMgrSmartPtr ptr = iter->first->pMgr;
			pthis->m_dldErrorsMap.erase(iter);
			if (ptr != NULL)
			{
				ptr->GetBtDownloadMgr()->SetStateError(BTDES_NO_ERROR);
			}
		}
	}

	switch (ev->enType)
	{
	case BTSET_FILE_ERROR:
    case BTSET_BTDLD_WAS_RESET:
		dld->bAutoStart = FALSE;
		dld->pMgr->GetBtDownloadMgr ()->setStoppedByUser (false);
		dld->pMgr->GetBtDownloadMgr ()->DeleteBtDownload ();
		dld->setDirty();
		if (ev->enType == BTSET_FILE_ERROR)
			pthis->Event (dld, LS (L_BT_FILE_ERROR), EDT_RESPONSE_E);
		break;

	case BTSET_TRACKER_ANNOUNCE:
		if (dld->pMgr->IsRunning () == FALSE && dld->pMgr->GetBtDownloadMgr ()->isSeeding () == FALSE)
			return;
		strTmp = LS (L_BT_TRACKER_ANNOUNCE); strTmp += " ("; strTmp += ev->tracker.pszUrl; strTmp += ")";
		pthis->Event (dld, strTmp.c_str (), EDT_INQUIRY);
		dld->pMgr->GetBtDownloadMgr ()->setLastTracker (ev->tracker.pszUrl);
		dld->pMgr->GetBtDownloadMgr ()->setLastTrackerStatus (LS (L_CONNECTING));
		break;

	case BTSET_TRACKER_ERROR:
		{
			if (dld->pMgr->IsRunning () == FALSE && dld->pMgr->GetBtDownloadMgr ()->isSeeding () == FALSE)
				return;
			strTmp = LS (L_BT_TRACKER_ERROR); strTmp += " ("; strTmp += ev->tracker.pszUrl; strTmp += ")";
			pthis->Event (dld, strTmp.c_str (), EDT_RESPONSE_E);
			if (ev->pszMsg)
			{
				LPCSTR pszMsg = strchr (ev->pszMsg, '"');
				if (pszMsg)
					pszMsg = strchr (pszMsg+1, '"');
				if (pszMsg)
					pszMsg += 2;
				if (pszMsg == NULL)
					pszMsg = ev->pszMsg;
				pthis->EventEx (dld, pszMsg, EDT_RESPONSE_E, 70);
				dld->pMgr->GetBtDownloadMgr ()->setLastTracker (ev->tracker.pszUrl);
				strTmp = LS (L_FAILED);
				strTmp += ": "; strTmp += pszMsg;
				dld->pMgr->GetBtDownloadMgr ()->setLastTrackerStatus (strTmp.c_str ());
			}
			char sz [1000];
			int nNext; nNext = dld->pMgr->GetBtDownloadMgr ()->get_NextAnnounceInterval (ev->tracker.pszUrl);
			if (nNext)
			{
				sprintf (sz, LS (L_NEXT_CONNECT_WITH_TRACKER_IN), nNext);
				
				
			}
			switch (ev->tracker.err.nHttpStatusCode)
			{
			case 500:
				{
					vmsBtDownloadManager* btMgr = dld->pMgr->GetBtDownloadMgr();
					if (btMgr)
					{
						btMgr->SetStateError(BTDES_SERVER_INTERNAL_ERROR_500);
					}
					vmsDldErrorStamp stamp(BTDES_SERVER_INTERNAL_ERROR_500);
					pthis->m_dldErrorsMap[dld] = stamp;
				}
				break;
			case 400:
				{
					vmsBtDownloadManager* btMgr = dld->pMgr->GetBtDownloadMgr();
					if (btMgr)
					{
						btMgr->SetStateError(BTDES_BAD_REQUEST_400);
					}
					vmsDldErrorStamp stamp(BTDES_BAD_REQUEST_400);
					pthis->m_dldErrorsMap[dld] = stamp;
				}
				break;
			default:
				break;
			}
			break;
		}
	case BTSET_TRACKER_REPLY:
		if (dld->pMgr->IsRunning () == FALSE && dld->pMgr->GetBtDownloadMgr ()->isSeeding () == FALSE)
			return;
		dld->pMgr->GetBtDownloadMgr ()->setLastTracker (ev->tracker.pszUrl);
		dld->pMgr->GetBtDownloadMgr ()->setLastTrackerStatus ("OK"); 
		strTmp = LS (L_BT_TRACKER_OK_RESPONSE); strTmp += " ("; strTmp += ev->tracker.pszUrl; strTmp += ")";
		pthis->Event (dld, strTmp.c_str (), EDT_RESPONSE_S);
		TCHAR tsz [200];
		_stprintf_s (tsz, _countof (tsz)-1, LS (L_N_PEERS_RECEIVED), ev->tracker.reply.cPeersRcvd);
		pthis->Event (dld, tsz, EDT_RESPONSE_S);
		break;

	case BTSET_HASH_FAILED:
		if (dld->pMgr->IsRunning () == FALSE && dld->pMgr->GetBtDownloadMgr ()->isSeeding () == FALSE)
			return;
		pthis->Event (dld, LS (L_BT_HASH_FAILED), EDT_WARNING);
		break;
	case BTSET_CANNOT_PROC_PEER_MSG:
		CString sMsg = LS (L_CANNOT_PROCESS_PEER_ALERT);
		CString sDiagnostics = ev->pszMsg;
		appendDiagnostics(sMsg, sDiagnostics);

		pthis->Event (dld, sMsg, EDT_RESPONSE_E);
		break;
	}

	pthis->Event (dld, DME_DOWNLOAD_STATE_CHANGED);
	pthis->Event (dld, DME_BTDLD_STAT_CHANGED);
}

void fsDownloadsMgr::AttachToBtSession()
{
	_BT.get_Session ()->set_EventsHandler (_BtSessionEventsHandler, this);
}

vmsDownloadSmartPtr fsDownloadsMgr::GetDownloadByBtDownloadMgr(vmsBtDownloadManager *pMgr)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	ASSERT (pMgr != NULL);

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
		{
			if (m_vDownloads [i]->pMgr->GetBtDownloadMgr () == pMgr)
				return m_vDownloads [i];
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByBtDownloadMgr " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByBtDownloadMgr unknown exception");
	}

	return NULL;
}

vmsDownloadSmartPtr fsDownloadsMgr::GetDownloadByTpDownloadMgr(vmsTpDownloadMgr *pMgr)
{
	ASSERT (pMgr != NULL);

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
		{
			if (m_vDownloads [i]->pMgr->GetTpDownloadMgr () == pMgr)
				return m_vDownloads [i];
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByTpDownloadMgr " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::GetDownloadByTpDownloadMgr unknown exception");
	}

	return NULL;
}

vmsDownloadSmartPtr fsDownloadsMgr::FindDownloadByBtDownload(vmsBtDownload *pDld)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	ASSERT (pDld != NULL);

	try 
	{
		for (size_t i = 0; i < m_vDownloads.size (); i++)
		{
			if (m_vDownloads [i]->pMgr->GetBtDownloadMgr () != NULL &&
					m_vDownloads [i]->pMgr->GetBtDownloadMgr ()->get_BtDownload () == pDld)
				return m_vDownloads [i];
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::FindDownloadByBtDownload " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::FindDownloadByBtDownload unknown exception");
	}

	return NULL;
}

DWORD fsDownloadsMgr::_BtDownloadManagerEventHandler(vmsBtDownloadManager *pMgr, vmsBtDownloadManagerEvent ev, DWORD dwInfo, LPVOID lp)
{
	fsDownloadsMgr* pthis = (fsDownloadsMgr*) lp;

	BtDownloadManagerEvent btev;
	assert (pMgr != NULL);
	btev.spMgr = pMgr;
	btev.ev = ev;
	btev.dwInfo = dwInfo;

	EnterCriticalSection (&pthis->m_csBtDownloadManagerEvents);
	pthis->m_vBtDownloadManagerEvents.push_back (btev);
	SetEvent (pthis->m_hevNeedDispatchEvents);
	LeaveCriticalSection (&pthis->m_csBtDownloadManagerEvents);

	return 0;
}

void fsDownloadsMgr::onBtDownloadManagerEvent (vmsBtDownloadManager *pMgr, vmsBtDownloadManagerEvent ev, DWORD dwInfo)
{
	vmsDownloadSmartPtr dld;
	dld = GetDownloadByBtDownloadMgr  (pMgr);

	if (dld != NULL)
	{
		switch (ev)
		{
		case BTDME_CHECKING_FILES:
		case BTDME_ALLOCATING:
			Event (dld, LS (L_PREP_FILES_ONDISK), EDT_INQUIRY);
			break;

		case BTDME_ALLOCATION_FAILED:
			CHAR szErr [1000];
			fsErrorToStr (szErr, sizeof (szErr), &dwInfo);
			dld->bAutoStart = FALSE;
			dld->setDirty();
			Event (dld, szErr, EDT_RESPONSE_E);
			break;

		case BTDME_DOWNLOAD_STARTED:
			RegisterDownloadInTum (dld);
			Event (dld, DME_DLMGRTHREADSTARTING);
			Event (dld, DME_CREATEDLDDIALOG);
			Event (dld, LS (L_STARTING), EDT_RESPONSE_S);
			break;

		case BTDME_DOWNLOAD_STOPPED_OR_DONE:
			UnregisterDownloadInTum (dld);
			Event (dld, dld->pMgr->IsDone () ? LS (L_DONE) : LS (L_STOPPED), EDT_RESPONSE_S);
			OnDownloadStoppedOrDone (dld);
			return;

		case BTDME_DOWNLOADING:
			RegisterDownloadInTum (dld); 
			Event (dld, LS (L_DOWNLOADING), EDT_RESPONSE_S);
			break;

		case BTDME_SEEDING:
			RegisterDownloadInTum (dld);
			setNeedProcessDownloads ();
			break;

		case BTDME_FATAL_ERROR:
			UnregisterDownloadInTum (dld);
			dld->bAutoStart = FALSE;
			dld->setDirty();
			break;

		case BTDME_STOP_SEEDING:
			UnregisterDownloadInTum (dld);
			break;
		}

		Event (dld, DME_DOWNLOAD_STATE_CHANGED);
	}
}

DWORD fsDownloadsMgr::_TpDownloadManagerEventHandler(vmsTpDownloadMgr *pMgr, fsDownloaderEvent enEvent, UINT uInfo, LPVOID lp)
{
	fsDownloadsMgr* pThis = (fsDownloadsMgr*) lp;

	ASSERT (pMgr != NULL);
	vmsDownloadSmartPtr dld = pThis->GetDownloadByTpDownloadMgr (pMgr);

	if (dld == NULL)
		return TRUE;

	try 
	{
		switch (enEvent)
		{
			case DE_EXTERROR:	
				switch (uInfo)
				{
					case DMEE_STARTING:
						if (FALSE == pThis->Event (dld, DME_DLMGRTHREADSTARTING))
							return FALSE;
						pThis->Event (dld, DME_CREATEDLDDIALOG);
						pThis->Event (dld, LS (L_STARTING), EDT_RESPONSE_S);
						break;

					case DMEE_STOPPEDORDONE: 
						pThis->Event (dld, dld->pMgr->IsDone () ? LS (L_DONE) : LS (L_STOPPED), EDT_RESPONSE_S);
						if (FALSE == pThis->OnDownloadStoppedOrDone (dld))
							return TRUE;
						dld = NULL;	
						break;
					
					case DMEE_FATALERROR:
					case DMEE_USERSTOP:
						dld->bAutoStart = FALSE;
						dld->setDirty();
						pThis->Event (dld, LS (L_STOPPED), EDT_RESPONSE_S);
						if (FALSE == pThis->OnDownloadStoppedOrDone (dld))
							return TRUE;
						break;
				}
			break;

			case DE_NEEDFILE:
				if (FALSE == pThis->Event (dld, DME_CREATEDLDDIALOG))
					return FALSE;
				return pMgr->CheckDstFileExists ();
		}

	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_TpDownloadManagerEventHandler " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_TpDownloadManagerEventHandler unknown exception");
	}

	if (dld) 
		pThis->Event (dld, DME_DOWNLOADEREVENTRECEIVED);

	return TRUE;
}

void fsDownloadsMgr::_TpDownloadManagerEventDesc(vmsTpDownloadMgr *pMgr, fsDownloadMgr_EventDescType enType, LPCSTR pszEvent, LPVOID lp)
{
	try 
	{
		fsDownloadsMgr* pThis = (fsDownloadsMgr*) lp;
		vmsDownloadSmartPtr dld = pThis->GetDownloadByTpDownloadMgr (pMgr);
		if (dld == NULL)
			return;

		pThis->OnDownloadDescEventRcvd (dld, enType, pszEvent);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_TpDownloadManagerEventDesc " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::_TpDownloadManagerEventDesc unknown exception");
	}
}

BOOL fsDownloadsMgr::OnDownloadStoppedOrDone(vmsDownloadSmartPtr dld)
{
	BOOL bDone = dld->pMgr->IsDone ();

	if (bDone)
	{
		SYSTEMTIME time;
		GetLocalTime (&time);
		SystemTimeToFileTime (&time, &dld->dateCompleted);
		dld->setDirty();
	}

	Event (dld, DME_DOWNLOADEREVENTRECEIVED);

	if (!bDone)
	{
		Event (dld, DME_DOWNLOADSTOPPEDORDONE);
		Event (dld, DME_UPDATEDLDDIALOG);
	}

	if (bDone)	
	{
		if (OnDldDone_CheckDownloadIsMetaLink (dld))
		{
			Event (dld, DME_UPDATEDLDDIALOG);
			return FALSE;
		}

		if (OnDldDone_CheckDownloadIsBittorrent (dld))
		{
			Event (dld, DME_UPDATEDLDDIALOG);
			return FALSE;
		}

		

		if (m_dldHighestPriority == dld)
			set_HighestPriorityDownload (NULL);

		Event (dld, DME_DOWNLOADSTOPPEDORDONE);
		Event (dld, DME_UPDATEDLDDIALOG);

		#ifndef FDM_DLDR__RAWCODEONLY
		if ((dld->dwFlags & DLD_DONTPUTTOHISTORY) == 0)
			m_histmgr.AddToHistory (dld);
		#endif

		if (dld->pMgr->IsDescriptionFileShouldBeGenerated ())
			GenerateDescriptionFile (dld);

		if (FALSE == dld->pMgr->IsHtmlSpiderDownload ())
		{
			if (dld->pMgr->GetBtDownloadMgr () && dld->pMgr->GetBtDownloadMgr ()->get_FileCount () > 1)
			{
				
				
				
				m_siStateInfo.GetFileRecentList().Add (dld->pMgr->GetBtDownloadMgr ()->get_TorrentName (), 
					dld->pMgr->get_OutputFilePathName ());
			}
			else
			{
				fsString strPath = dld->pMgr->get_OutputFilePathName ();
				char sz [MY_MAX_PATH] = "";
				fsGetFileName (strPath, sz);
				
				
				m_siStateInfo.GetFileRecentList().Add (sz, strPath);
			}
		}

		if (dld->dwFlags & DLD_DELETEFILEATRESTART)
		{
			if (dld->pMgr->GetBtDownloadMgr () && dld->pMgr->GetBtDownloadMgr ()->get_FileCount () > 1)
			{
				for (int i = 0; i < dld->pMgr->GetBtDownloadMgr ()->get_FileCount (); i++)
					vmsDeleteFileAtWinBoot  (dld->pMgr->GetBtDownloadMgr ()->get_OutputFilePathName (i));
			}
			else
			{			
				vmsDeleteFileAtWinBoot  (dld->pMgr->get_OutputFilePathName ());
			}
		}

		dld->bAutoStart = FALSE;
		dld->setDirty();

		bool bNeedLaunchDld = (dld->dwFlags & DLD_NOAUTOLAUNCH) == 0 && 
			dld->pMgr->IsLaunchWhenDone ();
		bool bNeedIntegrityCheck = dld->pMgr->GetDownloadMgr () != NULL &&
			dld->pMgr->GetDownloadMgr ()->GetDP ()->bCheckIntegrityWhenDone && 
			*dld->pMgr->GetDownloadMgr ()->GetDP ()->pszCheckSum;
		bool bNeedThread = m_bVirCheck || bNeedLaunchDld || bNeedIntegrityCheck ||
			(dld->dwFlags & DLD_FLASH_VIDEO);

		if (bNeedThread)
		{
			dld->AddRef (); 
			InterlockedIncrement (&m_cThreadsRunning);
			DWORD dw;
			CloseHandle (
				CreateThread (NULL, 0, _threadIntegrityCheckAndVirCheckAndLaunch, dld, 0, &dw));
		}
		else
		{
			OnDldDoneCheckIfNeedDel (dld);
		}

		if (dld->dwFlags & DLD_MF_AUTO_CONVERT)
		{
			dld->AddRef ();
			_pwndDownloads->PostMessage (WM_DLD_CONVERT_MEDIA, MCM_OS_SEARCH_IN_MGR, 
				(LPARAM)(fsDownload*)dld);
		}
	}
	
	if (m_dldHighestPriority == dld)
		set_HighestPriorityDownload (NULL);

	setNeedProcessDownloads ();	
	setNeedCheckNoActiveDownloads (); 

	return TRUE;
}

void fsDownloadsMgr::OnDownloadDescEventRcvd(vmsDownloadSmartPtr dld, fsDownloadMgr_EventDescType enType, LPCSTR pszEvent)
{
	try 
	{
		COLORREF clrBg, clrText;
		int iImage;

		GetEventColors (enType, clrText, clrBg, iImage);

		fsDownloadEvents event;
		SYSTEMTIME time;
		GetLocalTime (&time);

		event.clrBg = clrBg;
		event.clrText = clrText;
		event.strEvent = pszEvent;
		event.iImage = iImage;
		SystemTimeToFileTime (&time, &event.timeEvent);

		dld->vEvents.add (event);	

		if (enType ==  EDT_RESPONSE_E)
			dld->tstrLastErrMsg = pszEvent;

		if (IsStoringLogTurnedOn())
			dld->setDirty();

		
		Event (dld, DME_EVENTDESCRIPRIONRECEIVED);
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::OnDownloadDescEventRcvd " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsDownloadsMgr::OnDownloadDescEventRcvd unknown exception");
	}
}

void fsDownloadsMgr::GetRunningDownloads(DLDS_LIST &v)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		if (m_vDownloads [i]->pMgr->IsRunning ())
			v.push_back (m_vDownloads [i]);
	}
}

void fsDownloadsMgr::set_HighestPriorityDownload(vmsDownloadSmartPtr dld)
{
	if (m_dldHighestPriority == dld)
		return;

	if (m_dldHighestPriority != NULL)
		m_dldHighestPriority->pMgr->setPriority (0);
		
	m_dldHighestPriority = dld;

	if (dld)
		dld->pMgr->setPriority (BYTE_MAX);
}

int fsDownloadsMgr::IsSuchUrlExistsAlready(vmsDownloadSmartPtr dld)
{
	fsURL url1, url2;

	if (dld->pMgr->GetDownloadMgr () == NULL)
		return 0;

	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	fsDownload_NetworkProperties* dnp0 = dld->pMgr->GetDownloadMgr ()->GetDNP ();

	size_t nCount = GetCount ();
	for (size_t i = 0; i < nCount; i++)
	{
		vmsDownloadSmartPtr d = GetDownload (i);
		if (d->pMgr->GetDownloadMgr () == NULL)
			continue;
		fsDownload_NetworkProperties* dnp = d->pMgr->GetDownloadMgr ()->GetDNP ();

		if (dnp0->enProtocol == dnp->enProtocol && 
			dnp0->uServerPort == dnp->uServerPort &&
			fsIsServersEqual (dnp0->pszServerName, dnp->pszServerName, FALSE) && 
			lstrcmp (dnp0->pszPathName, dnp->pszPathName) == 0 &&
			lstrcmp (dnp0->pszUserName, dnp->pszUserName) == 0)
		{
			return i;
		}
	}

	return -1;
}

void fsDownloadsMgr::DownloadStateChanged(vmsDownloadSmartPtr dld)
{
	Event (dld, DME_DOWNLOAD_STATE_CHANGED);
}

void fsDownloadsMgr::AddEvent(vmsDownloadSmartPtr dld, LPCSTR pszEvent, fsDownloadMgr_EventDescType enType)
{
	Event (dld, pszEvent, enType);
}

void fsDownloadsMgr::EventEx(vmsDownloadSmartPtr dld, LPCSTR pszEvent, fsDownloadMgr_EventDescType enType, int nMaxCharsPerLine)
{
	fsString strEvent;
	int n = 0;

	while (*pszEvent)
	{
		if (*pszEvent == ' ' && n >= nMaxCharsPerLine)
		{
			Event (dld, strEvent, enType);
			strEvent = "";
			n = 0;
			pszEvent++;
		}
		else
		{
			strEvent += *pszEvent++;
			if (*pszEvent == '\n' || *pszEvent == '\r')
			{
				n = nMaxCharsPerLine;
				while (*pszEvent == '\n' || *pszEvent == '\r')
					pszEvent++;
				continue;
			}
			else
			{
				n++;

			}
		}
	}

	if (strEvent.IsEmpty () == FALSE)
		Event (dld, strEvent, enType);
}

vmsDownloadSmartPtr fsDownloadsMgr::get_HighestPriorityDownload()
{
	return m_dldHighestPriority;
}

DWORD WINAPI fsDownloadsMgr::_threadStartSeeding(LPVOID lp)
{
	fsDownloadsMgr *pthis = (fsDownloadsMgr*) lp;

	for (int k = 0; k < 2; k++)
	{
		
		int i = 0;
		for (i = 0; i < k == 0 ? 15 : 300; i++)
		{
			Sleep (1000);
			if (pthis->m_bShuttingDown)
				break;
		}

		if (pthis->m_bShuttingDown)
			break;

		vmsBtSession *pS = (vmsBtSession*) _BT.get_Session ();
		for (i = 0; i < pS->get_DownloadCount (); i++)
		{
			vmsBtDownload *dld = pS->get_Download (i);
			if (dld->GetState () == BTDS_SEEDING && dld->IsPaused ())
				dld->Resume ();
		}
	}

	InterlockedDecrement (&pthis->m_cThreadsRunning);
	return 0;
}

BOOL fsDownloadsMgr::AllowStartNewDownloads()
{
	return m_bAllowStart;
}

void fsDownloadsMgr::ManagePD()
{
	if (m_dwPDTimeLimit == 0)
		return;

	bool bTimeAllow = isAllowedToPDCurrently ();

	static bool _bStarted = false;
	
	if (bTimeAllow)
	{
		if (_bStarted == false)
		{
			_bStarted = true;
			setNeedProcessDownloads ();
		}
	}
	else
	{
		if (_bStarted)
		{
			_bStarted = false;
			StopAllDownloads (FALSE);
		}
	}
}

bool fsDownloadsMgr::isAllowedToPDCurrently() const
{
	if (m_dwPDTimeLimit == 0)
		return true;
	
	int t1 = LOWORD (m_dwPDTimeLimit);
	int t2 = HIWORD (m_dwPDTimeLimit);
	
	SYSTEMTIME st; GetLocalTime (&st);
	
	bool bNeedInvert = false;
	bool bTimeAllow;
	
	if (t1 > t2)
	{
		bNeedInvert = true;
		t2 += t1;
		t1 = t2 - t1;
		t2 = t2 - t1;
	}
	
	bTimeAllow = st.wHour >= t1 && st.wHour < t2;
	if (bNeedInvert)
		bTimeAllow = !bTimeAllow;

	return bTimeAllow;
}

void fsDownloadsMgr::ChangeDownloadGroup(fsDownload *dld, vmsDownloadsGroupSmartPtr spGrp, bool bMoveFiles)
{
	if (dld->pGroup->nId != spGrp->nId)
	{
		dld->pGroup->cDownloads--;
		dld->pGroup = spGrp;
		dld->setDirty();
		dld->pGroup->cDownloads++;
		if (bMoveFiles)
			dld->pMgr->GetDownloadMgr ()->MoveToFolder (spGrp->strOutFolder);
	}
}

BOOL fsDownloadsMgr::CheckIfDownloadIsMirror(fsDownload *dld)
{
	ASSERT (dld->pMgr->GetDownloadMgr () != NULL);
	fsString strFile = dld->pMgr->GetDownloadMgr ()->getFileName ();
	if (strFile.IsEmpty ())
		return FALSE;
	UINT64 uFileSize = dld->pMgr->GetSSFileSize ();

	vmsDownloadSmartPtr dldBase;
	
	vmsAUTOLOCKRW_READ (m_rwlDownloads);
	
	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		if (m_vDownloads [i] == dld)
			continue;
		fsDownloadMgr *pMgr = m_vDownloads [i]->pMgr->GetDownloadMgr ();
		if (pMgr == NULL)
			continue;
		if (stricmp (strFile, pMgr->getFileName ()) == 0)
		{
			if (pMgr->GetDownloader ()->GetSSFileSize () == uFileSize)
			{
				dldBase = m_vDownloads [i];				
				break;
			}
			else if (dldBase == NULL && pMgr->GetDownloader ()->GetNumberOfSections () == 0)
			{
				dldBase = m_vDownloads [i];
				if (uFileSize == UINT_MAX)
					break;
			}
		}
	}
	
	vmsAUTOLOCKRW_READ_UNLOCK (m_rwlDownloads);
	
	if (dldBase != NULL)
	{
		dldBase->pMgr->GetDownloadMgr ()->GetDownloader ()->AddMirrorURL (
			dld->pMgr->GetDownloadMgr ()->get_URL (), 
			dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszUserName, 
			dld->pMgr->GetDownloadMgr ()->GetDNP ()->pszPassword);
	}

	return dldBase != NULL;
}

const fsDownloadsMgr::TotalProgress& fsDownloadsMgr::getTotalProgress() const
{
	return m_totalProgess;
}

bool fsDownloadsMgr::IsStoringLogTurnedOn()
{
	return m_saver.IsStoringLogTurnedOn();
}

vmsDownloadSmartPtr fsDownloadsMgr::findBtDownloadByHash (LPBYTE pbHash, DWORD dwHashSize)
{
	vmsAUTOLOCKRW_READ (m_rwlDownloads);

	BYTE abHash [100];
	DWORD dwSize = sizeof (abHash);

	for (size_t i = 0; i < m_vDownloads.size (); i++)
	{
		vmsBtDownloadManager *pMgr = m_vDownloads [i]->pMgr->GetBtDownloadMgr ();
		if (!pMgr)
			continue;
		if (!pMgr->getInfoHash2 (abHash, &dwSize))
			continue;
		if (dwSize == dwHashSize && 0 == memcmp (pbHash, abHash, dwSize))
			return m_vDownloads [i];
	}

	return NULL;
}

vmsDownloadSmartPtr fsDownloadsMgr::findBtDownloadByHash (vmsBtDownloadManager *pMgr)
{
	BYTE abHash [100];
	DWORD dwSize = sizeof (abHash);
	if (!pMgr->getInfoHash2 (abHash, &dwSize))
		return NULL;
	return findBtDownloadByHash (abHash, dwSize);
}

DWORD WINAPI fsDownloadsMgr::_threadEventsDispatcher (LPVOID lp)
{
	fsDownloadsMgr *pthis = (fsDownloadsMgr*)lp;

	HANDLE ahEvents [] = {pthis->m_hevNeedDispatchEvents, pthis->m_hevShuttingDown};

	while (WAIT_OBJECT_0 == WaitForMultipleObjects (2, ahEvents, FALSE, INFINITE))
	{
		BtDownloadManagerEvent btev;
		bool bHas;

		do 
		{
			EnterCriticalSection (&pthis->m_csBtDownloadManagerEvents);
			bHas = !pthis->m_vBtDownloadManagerEvents.empty ();
			if (bHas)
			{
				btev = pthis->m_vBtDownloadManagerEvents [0];
				pthis->m_vBtDownloadManagerEvents.erase (pthis->m_vBtDownloadManagerEvents.begin ());
			}
			LeaveCriticalSection (&pthis->m_csBtDownloadManagerEvents);

			if (bHas)
				pthis->onBtDownloadManagerEvent (btev.spMgr, btev.ev, btev.dwInfo);
		}
		while (bHas);
	}

	return 0;
}

void fsDownloadsMgr::onCurrentTrafficUsageModeChanged(void)
{
	setNeedProcessDownloads ();
	setNeedApplyTrafficLimit ();
}

void fsDownloadsMgr::RegisterDownloadInTum(fsDownload* dld)
{
	if (dld->getState () & DLDS_REGISTERED_IN_TRAFFICUSGMGR)
		return;
	vmsAUTOLOCKSECTION (m_csRegisterDldInTum);
	dld->setStateFlags (DLDS_REGISTERED_IN_TRAFFICUSGMGR);
	_TumMgr.addManageForSpeedItem (dld->pMgr);
}

void fsDownloadsMgr::UnregisterDownloadInTum(fsDownload* dld)
{
	if (!(dld->getState () & DLDS_REGISTERED_IN_TRAFFICUSGMGR))
		return;
	vmsAUTOLOCKSECTION (m_csRegisterDldInTum);
	dld->removeStateFlags (DLDS_REGISTERED_IN_TRAFFICUSGMGR);
	_TumMgr.removeManageForSpeedItem (dld->pMgr);
}

bool fsDownloadsMgr::IsDownloadSuspended(vmsDownloadSmartPtr dld)
{
	std::map<vmsDownloadSmartPtr, vmsDldErrorStamp>::iterator iter = m_dldErrorsMap.find(dld);
	if (iter != m_dldErrorsMap.end())
	{
		vmsDldErrorStamp stamp = iter->second;
		if (m_errorTimeouts.find(stamp.Error) == m_errorTimeouts.end())
		{
			return false;
		}
		int timeout = m_errorTimeouts[stamp.Error];
		if (timeout == 0)
		{
			
			return true;
		}

		DWORD now = GetTickCount();
		if (now - stamp.TimeStamp < timeout)
		{
			return true;
		}
	}
	return false;
}
