/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsDownloadMgrEx.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsDownloadMgrEx::vmsDownloadMgrEx()
{
	m_pMgr = NULL;
	m_pTpMgr = NULL;
}

vmsDownloadMgrEx::~vmsDownloadMgrEx()
{
	DetachDownloadMgr ();
}

void vmsDownloadMgrEx::DetachDownloadMgr ()
{
	vmsPersistObject *pObj = NULL;
	if (m_pMgr)
		pObj = m_pMgr;
	else if (m_spBtMgr)
		pObj = m_spBtMgr;
	else if (m_pTpMgr)
		pObj = m_pTpMgr;
	getPersistObjectChildren ()->removePersistObject (pObj);
	SAFE_DELETE (m_pMgr);
	m_spBtMgr = NULL;
	SAFE_DELETE (m_pTpMgr);
}

void vmsDownloadMgrEx::Attach(fsDownloadMgr *pMgr)
{
	DetachDownloadMgr ();
	m_pMgr = pMgr;
	getPersistObjectChildren ()->addPersistObject (m_pMgr);
}

void vmsDownloadMgrEx::Attach(vmsBtDownloadManager *pBtMgr)
{
	DetachDownloadMgr ();
	m_spBtMgr = pBtMgr;
	getPersistObjectChildren ()->addPersistObject (m_spBtMgr);
}

void vmsDownloadMgrEx::Attach(vmsTpDownloadMgr *pTpMgr)
{
	DetachDownloadMgr ();
	m_pTpMgr = pTpMgr;
	getPersistObjectChildren ()->addPersistObject (m_pTpMgr);
}

fsDownloadMgr* vmsDownloadMgrEx::GetDownloadMgr()
{
	return m_pMgr;
}

vmsBtDownloadManager* vmsDownloadMgrEx::GetBtDownloadMgr()
{
	return m_spBtMgr;
}

vmsTpDownloadMgr* vmsDownloadMgrEx::GetTpDownloadMgr()
{
	return m_pTpMgr;
}

fsString vmsDownloadMgrEx::get_OutputFilePathName()
{
	if (m_pMgr)
		return m_pMgr->GetDP ()->pszFileName;
	else if (m_spBtMgr)
		return m_spBtMgr->get_OutputFilePathName ();
	else if (m_pTpMgr)
		return m_pTpMgr->get_OutputFilePathName ();
}

float vmsDownloadMgrEx::GetPercentDone()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetPercentDone ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetPercentDone ();
	else
		return m_pTpMgr->GetPercentDone ();
}

BOOL vmsDownloadMgrEx::IsLaunchWhenDone()
{
	if (m_pMgr)
		return m_pMgr->GetDP ()->dwFlags & DPF_STARTWHENDONE;
	else if (m_spBtMgr)
		return m_spBtMgr->get_Flags () & BTDF_LAUNCH_WHEN_DONE;
	else if (m_pTpMgr)
		return m_pTpMgr->get_Flags () & BTDF_LAUNCH_WHEN_DONE;
}

fsResumeSupportType vmsDownloadMgrEx::IsResumeSupported()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->IsResumeSupported ();
	
	return RST_PRESENT; 
}

BOOL vmsDownloadMgrEx::IsDone()
{
	if (m_pMgr)
		return m_pMgr->IsDone ();
	else if (m_spBtMgr)
		return m_spBtMgr->IsDone ();
	else if (m_pTpMgr)
		m_pTpMgr->IsDone();
}

BOOL vmsDownloadMgrEx::IsRunning()
{
	if (m_pMgr)
		return m_pMgr->IsRunning ();
	else if (m_spBtMgr)
		return m_spBtMgr->IsRunning ();
	else if (m_pTpMgr)
		return m_pTpMgr->IsRunning ();
}

BOOL vmsDownloadMgrEx::IsFileInitializedOnDisk()
{
	if (m_pMgr)
		return m_pMgr->IsFileInit ();
	else
		return TRUE;
}

void vmsDownloadMgrEx::set_LaunchWhenDone(BOOL b)
{
	if (m_pMgr) {
		if (b)
			m_pMgr->GetDP ()->dwFlags |= DPF_STARTWHENDONE;
		else
			m_pMgr->GetDP ()->dwFlags &= ~DPF_STARTWHENDONE;

		m_pMgr->setDirty();

	} else if (m_spBtMgr) {
		if (b)
			m_spBtMgr->enable_Flags (BTDF_LAUNCH_WHEN_DONE);
		else
			m_spBtMgr->disable_Flags (BTDF_LAUNCH_WHEN_DONE);
	} else if (m_pTpMgr) {
		if (b)
			m_pTpMgr->enable_Flags (BTDF_LAUNCH_WHEN_DONE);
		else
			m_pTpMgr->disable_Flags (BTDF_LAUNCH_WHEN_DONE);
	}

}

fsString vmsDownloadMgrEx::get_URL(BOOL bInclAuth)
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->get_URL (bInclAuth);
	else if (m_spBtMgr)
		return m_spBtMgr->get_URL ();
	else if (m_pTpMgr)
		return m_pTpMgr->get_URL ();
}

int vmsDownloadMgrEx::GetNumberOfSections()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetNumberOfSections ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetNumberOfSections ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetNumberOfSections ();
}

UINT64 vmsDownloadMgrEx::GetLDFileSize()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetLDFileSize ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetTotalFilesSize ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetTotalFilesSize ();
}

UINT64 vmsDownloadMgrEx::GetDownloadedBytesCount()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetDownloadedBytesCount ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetDownloadedBytesCount ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetDownloadedBytesCount ();
}

BOOL vmsDownloadMgrEx::IsDownloading()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->IsDownloading ();
	else if (m_spBtMgr)
		return m_spBtMgr->IsDownloading ();
	else if (m_pTpMgr)
		return m_pTpMgr->IsDownloading ();
}

UINT64 vmsDownloadMgrEx::GetSSFileSize()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetSSFileSize ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetTotalFilesSize ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetTotalFilesSize ();
}

void vmsDownloadMgrEx::GetSectionInfo(int nIndex, vmsSectionInfo *sect, BOOL bNoCacheAccounting)
{
	if (m_pMgr)
	{
		fsSection s;
		m_pMgr->GetDownloader ()->GetSectionInfo (nIndex, &s, bNoCacheAccounting);
		sect->uDStart = s.uDStart;
		sect->uDCurrent = s.uDCurrent;
		sect->uDEnd = s.uDEnd;
	}
	else if (m_spBtMgr)
	{
		m_spBtMgr->GetSectionInfo (nIndex, sect);
	}
	else if(m_pTpMgr)
	{
		m_pTpMgr->GetSectionInfo (nIndex, sect);
	}
}

int vmsDownloadMgrEx::GetDownloadingSectionCount()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetDownloadingSectionCount ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetDownloadingSectionCount ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetDownloadingSectionCount ();
}

void vmsDownloadMgrEx::CreateOneMoreSection()
{
	if (m_pMgr)
		m_pMgr->CreateOneMoreSection ();

	ASSERT (GetBtDownloadMgr () == NULL);
}

void vmsDownloadMgrEx::StopSection()
{
	if (m_pMgr)
		m_pMgr->StopSection ();

	ASSERT (GetBtDownloadMgr () == NULL);
}

UINT64 vmsDownloadMgrEx::GetBytesLeft()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetBytesLeft ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetTotalFilesSize () - m_spBtMgr->GetDownloadedBytesCount ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetTotalFilesSize () - m_pTpMgr->GetDownloadedBytesCount ();
}

UINT vmsDownloadMgrEx::GetSpeed()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetSpeed ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetSpeed ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetSpeed ();
}

BOOL vmsDownloadMgrEx::MoveToFolder(LPCSTR pszPath)
{
	if (m_pMgr)
		return m_pMgr->MoveToFolder (pszPath);
	else if (m_spBtMgr)
		return m_spBtMgr->MoveToFolder (pszPath);
	else if (m_pTpMgr)
		return m_pTpMgr->MoveToFolder (pszPath);
}

BOOL vmsDownloadMgrEx::IsStoppedByUser()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->IsStoppedByUser ();
	else if (m_spBtMgr)
		return m_spBtMgr->IsStoppedByUser ();
}

BOOL vmsDownloadMgrEx::IsCantStart()
{
	if (m_pMgr)
		return m_pMgr->IsCantStart ();
	else if (m_spBtMgr)
		return m_spBtMgr->IsCantStart ();
	else if (m_pTpMgr)
		return m_pTpMgr->IsCantStart ();
}

fsInternetResult vmsDownloadMgrEx::RestartDownloading()
{
	if (m_pMgr)
		return m_pMgr->RestartDownloading ();
	else if (m_spBtMgr)
		return m_spBtMgr->RestartDownloading ();
	else if (m_pTpMgr)
		return m_pTpMgr->RestartDownloading ();
}

BOOL vmsDownloadMgrEx::IsDescriptionFileShouldBeGenerated()
{
	if (m_pMgr)
		return m_pMgr->GetDP ()->dwFlags & DPF_GENERATEDESCFILE;
	else if (m_spBtMgr)
		return m_spBtMgr->get_Flags () & BTDF_GENERATE_DESC_FILE;
}

BOOL vmsDownloadMgrEx::IsHtmlSpiderDownload()
{
	if (m_pMgr)
		return m_pMgr->GetDP ()->dwFlags & DLD_USEDBYHTMLSPIDER;
	else
		return FALSE;	
}

fsInternetResult vmsDownloadMgrEx::StartDownloading()
{
	if (m_pMgr)
		return m_pMgr->StartDownloading ();
	else if (m_spBtMgr)
		return m_spBtMgr->StartDownloading ();
	else if (m_pTpMgr)
		return m_pTpMgr->StartDownloading ();
}

void vmsDownloadMgrEx::StopDownloading()
{
	if (m_pMgr)
		m_pMgr->StopDownloading ();
	else if (m_spBtMgr)
		m_spBtMgr->StopDownloading ();
	else if (m_pTpMgr)
		return m_pTpMgr->StopDownloading ();
}

void vmsDownloadMgrEx::LimitTraffic(UINT uLimit)
{
	if (m_pMgr)
		m_pMgr->GetDownloader ()->LimitTraffic (uLimit);
	else if (m_spBtMgr)
		m_spBtMgr->LimitTraffic (uLimit);
}

UINT vmsDownloadMgrEx::GetTrafficLimit()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetTrafficLimit ();
	else if (m_spBtMgr)
		return m_spBtMgr->GetTrafficLimit ();
}

void vmsDownloadMgrEx::UseDetailedLog(BOOL b)
{
	if (m_pMgr)
		m_pMgr->GetDownloader ()->UseDetailedLog (b);
	else
		m_spBtMgr->UseDetailedLog (b);
}

BOOL vmsDownloadMgrEx::DeleteFile()
{
	if (m_pMgr)
		return m_pMgr->DeleteFile ();
	else if (m_spBtMgr)
		return m_spBtMgr->DeleteFile ();
	else if (m_pTpMgr)
		return m_pTpMgr->DeleteFile ();
}

BOOL vmsDownloadMgrEx::IsDontConfirmLaunchWhenDone()
{
	if (m_pMgr)
		return m_pMgr->GetDP ()->dwFlags & DPF_STARTWHENDONE_NOCONF;
	else if (m_spBtMgr)
		return m_spBtMgr->get_Flags () & BTDF_LAUNCH_WHEN_DONE_NO_CONFIRM;
	else if (m_pTpMgr)
		return m_pTpMgr->get_Flags () & BTDF_LAUNCH_WHEN_DONE_NO_CONFIRM;
}

fsInternetResult vmsDownloadMgrEx::SetToRestartState()
{
	if (m_pMgr)
		return m_pMgr->SetToRestartState ();
	else if (m_spBtMgr)
		return m_spBtMgr->SetToRestartState ();
	else if (m_pTpMgr)
		return m_pTpMgr->SetToRestartState ();
}

int vmsDownloadMgrEx::GetConnectionCount()
{
	if (m_pMgr)
		return m_pMgr->GetDownloader ()->GetRunningSectionCount ();
	else if (m_spBtMgr)
		return m_spBtMgr->get_ConnectionCount ();
	else
		return m_pTpMgr->get_ConnectionCount ();
}

BOOL vmsDownloadMgrEx::LoadState(LPBYTE lpBuffer, LPDWORD lpdwSize, WORD wVer)
{
#define CHECK_BOUNDS(need) if (need < 0 || need > int(*lpdwSize) - (pB - LPBYTE (lpBuffer))) return FALSE;
	LPBYTE pB = LPBYTE (lpBuffer);

	BYTE bBitTorrent = FALSE, bTransportProtocol = FALSE;
	DWORD dwMgrStateSize = *lpdwSize;
	DWORD dwConsumed = 0;
	
	BOOL bOk;
	if (wVer > 9)	
	{
		CHECK_BOUNDS (sizeof (BYTE));
		const int nMgr = *lpBuffer++;
		bBitTorrent = (nMgr == 1);
		if (wVer > 13) bTransportProtocol = (nMgr == 2);
		dwConsumed++;
		dwMgrStateSize--;
	}

	if (bTransportProtocol)
	{
		Attach (new vmsTpDownloadMgr);
		bOk = m_pTpMgr->LoadState (lpBuffer, &dwMgrStateSize, wVer);
	}
	else if (bBitTorrent)
	{
		vmsBtDownloadManagerPtr spMgr; spMgr.CreateInstance ();
		Attach (spMgr);
		bOk = m_spBtMgr->LoadState (lpBuffer, &dwMgrStateSize, wVer);
	}
	else
	{
		Attach (new fsDownloadMgr);	
		bOk = m_pMgr->LoadState (lpBuffer, &dwMgrStateSize, wVer);
	}

	if (bOk == FALSE)
		return FALSE;

	dwConsumed += dwMgrStateSize;
	*lpdwSize = dwConsumed;

	return TRUE;
}

BOOL vmsDownloadMgrEx::IsBittorrent()
{
	return m_spBtMgr != NULL;
}

BOOL vmsDownloadMgrEx::IsTp()
{
	return m_pTpMgr != NULL;
}

void vmsDownloadMgrEx::GetSplittedSectionsList(std::vector <vmsSectionInfo> &v)
{
	try
	{
		std::vector <vmsSectionInfo> vBtSects;
		if (m_spBtMgr)
			m_spBtMgr->GetSectionsInfo (vBtSects);
		
		v.clear ();
		size_t num = GetNumberOfSections ();
		vmsSectionInfo *sectLast = NULL;
		
		for (size_t i = 0; i < num; i++)
		{
			vmsSectionInfo sect;
			if (m_spBtMgr)
				sect = vBtSects [i];
			else
				GetSectionInfo (i, &sect);
			if (sectLast != NULL && 
				(sectLast->uDCurrent == sect.uDStart || sectLast->uDCurrent+1 == sect.uDStart))
			{
				sectLast->uDEnd = sect.uDEnd;
				sectLast->uDCurrent = sect.uDCurrent;
			}
			else
			{
				v.push_back (sect);
				
				
				std::vector <vmsSectionInfo>::iterator itLastSect = v.end () - 1;
				sectLast = &(*itLastSect);
				
			}
		}
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsDownloadMgrEx::GetSplittedSectionsList " + tstring(ex.what()));
		v.clear ();
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("vmsDownloadMgrEx::GetSplittedSectionsList unknown exception");
		v.clear ();
	}
}

BOOL vmsDownloadMgrEx::IsReservingDiskSpace()
{
	if (m_pMgr)
		return (m_pMgr->get_State () & DS_RESERVINGSPACE) != 0;
	else if (m_spBtMgr)
		return m_spBtMgr->get_State () == BTDSE_ALLOCATING;
	else if (m_pTpMgr)
		return FALSE;
}

int vmsDownloadMgrEx::get_ReservingDiskSpaceProgress()
{
	if (m_pMgr)
		return m_pMgr->get_ReservingDiskSpaceProgress ();
	else if (m_spBtMgr)
		return m_spBtMgr->get_CurrentTaskProgress ();
	else if (m_pTpMgr)
		return m_pTpMgr->GetPercentDone ();
}

void vmsDownloadMgrEx::Do_OpenFolder()
{
	if (m_pMgr && m_pMgr->IsFileInit () == FALSE)
	{
		ShellExecute (NULL, "explore", get_OutputFilePathName (), NULL, NULL, SW_SHOW);
	}
	else
	{
		CString strFileName = get_OutputFilePathName ();

		if (m_spBtMgr && m_spBtMgr->get_FileCount () > 1)
			strFileName += m_spBtMgr->get_RootFolderName ();

		if (GetFileAttributes (strFileName) == DWORD (-1))
		{
			char szPath [MY_MAX_PATH];
			
			fsGetPath (strFileName, szPath);
			ShellExecute (NULL, "explore", szPath, NULL, NULL, SW_SHOW);
		}
		else
		{
			CString strCmd;
			strCmd.Format ("/select,\"%s\"", strFileName);
				ShellExecute (NULL, "open", "explorer.exe", strCmd, NULL, SW_SHOW);
		}
	}
}

UINT64 vmsDownloadMgrEx::getSpeed(bool bOfDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->getSpeed (bOfDownload) : 0;
}

void vmsDownloadMgrEx::setSpeedLimit(bool bOfDownload, UINT64 uLimit)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	if (pObj)
		pObj->setSpeedLimit (bOfDownload, uLimit);
}

vmsDownloaderWithNetworkUsageAdjustment* vmsDownloadMgrEx::getDownloaderWithNetworkUsageAdjustmentObject(void)
{
	if (m_pMgr)
		return m_pMgr;
	if (m_spBtMgr)
		return m_spBtMgr;
	return NULL;
}

UINT64 vmsDownloadMgrEx::getSpeedLimit(bool bOfDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->getSpeedLimit (bOfDownload) : UINT64_MAX;
}

bool vmsDownloadMgrEx::isResumeSupported(bool bOfDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->isResumeSupported (bOfDownload) : true;
}

bool vmsDownloadMgrEx::isIgnoreAllSpeedLimits(bool bOfDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->isIgnoreAllSpeedLimits (bOfDownload) : false;
}

UINT64 vmsDownloadMgrEx::getInternalSpeedLimit(bool bOfDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->getInternalSpeedLimit (bOfDownload) : _UI64_MAX;
}

bool vmsDownloadMgrEx::isRequiresTraffic(bool bForDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->isRequiresTraffic (bForDownload) : false;
}

bool vmsDownloadMgrEx::isSpeedCanBeLimitedBySomeInternalReasons (bool bForDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->isSpeedCanBeLimitedBySomeInternalReasons (bForDownload) : false;
}

bool vmsDownloadMgrEx::isInternetTraffic (bool bForDownload)
{
	vmsDownloaderWithNetworkUsageAdjustment *pObj = getDownloaderWithNetworkUsageAdjustmentObject ();
	return pObj ? pObj->isInternetTraffic (bForDownload) : true;
}
