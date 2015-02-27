/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsTrafficUsageModeMgr.h"
#include <Iphlpapi.h>
#include "vmsTickCount.h"
#include "vmsIpHelper.h"

#pragma warning (disable : 4244)

vmsTrafficUsageModeMgr _TumMgr;

vmsTrafficUsageModeMgr::vmsTrafficUsageModeMgr(void) : 
	m_dwState (0)
{
	m_bRestrainAll = false;
	m_enTUMManage = TM_OFF;
	m_enUserTUM = TUM_HEAVY;
	m_hevShuttingDown = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_cSecondsNoSpeedMeasure = 0;

	DWORD dw;
	m_htManage = CreateThread (NULL, 0, _threadManage, this, 0, &dw);	
}

vmsTrafficUsageModeMgr::~vmsTrafficUsageModeMgr(void)
{
	SetEvent (m_hevShuttingDown);
	WaitForSingleObject (m_htManage, INFINITE);
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
		delete m_vpManageForSpeed [i];
}

vmsTrafficUsageModeRawSettings& vmsTrafficUsageModeMgr::GetTumRawSettings (fsTUM enTUM)
{
	return m_aTUM [enTUM];
}

void vmsTrafficUsageModeMgr::SetTumRawSettings (fsTUM enTUM, vmsTrafficUsageModeRawSettings& stgs)
{
	if (memcmp (&m_aTUM [enTUM], &stgs, sizeof (stgs)))
	{
		m_aTUM [enTUM] = stgs;
		if (enTUM == m_enCurrentTUM)
			BuildCurrentSettings ();
	}
}

void vmsTrafficUsageModeMgr::SetTumRawSettingsPerDirection (fsTUM enTUM, vmsTrafficUsageModeRawSettings::PerDirection& stgs, bool bForDownload)
{
	if (memcmp (&m_aTUM [enTUM].getSettings (bForDownload), &stgs, sizeof (stgs)))
	{
		m_aTUM [enTUM].refgetSettings (bForDownload) = stgs;
		if (enTUM == m_enCurrentTUM)
			BuildCurrentSettings ();
	}
}

const vmsTrafficUsageModeSettings& vmsTrafficUsageModeMgr::getSettings(void)
{
	return m_currentStgs;
}

void vmsTrafficUsageModeMgr::InitTUM (bool bForDownload)
{
	m_aTUM [0].refgetSettings (bForDownload).u8TrafficLimitPerc = 15;
	m_aTUM [1].refgetSettings (bForDownload).u8TrafficLimitPerc = 50;
	m_aTUM [2].refgetSettings (bForDownload).u8TrafficLimitPerc = 100;

	m_aTUM [0].refgetSettings (bForDownload).uMaxConns = 0;
	m_aTUM [1].refgetSettings (bForDownload).uMaxConns = 0;
	m_aTUM [2].refgetSettings (bForDownload).uMaxConns = 0;

	m_aTUM [0].refgetSettings (bForDownload).uMaxConnsPS = 0;
	m_aTUM [1].refgetSettings (bForDownload).uMaxConnsPS = 0;
	m_aTUM [2].refgetSettings (bForDownload).uMaxConnsPS = 0;

	m_aTUM [0].refgetSettings (bForDownload).uMaxTasks = 0;
	m_aTUM [1].refgetSettings (bForDownload).uMaxTasks = 0;
	m_aTUM [2].refgetSettings (bForDownload).uMaxTasks = 0;
}

void vmsTrafficUsageModeMgr::InitTUM (void)
{
	InitTUM (true);
	InitTUM (false);
}

void vmsTrafficUsageModeMgr::ReadSettings(void)
{
	if (FALSE == _App.Get_TUM (m_aTUM))
		InitTUM ();

	
	ASSERT (m_aTUM [TUM_HEAVY].download.u8TrafficLimitPerc == 100);
	ASSERT (m_aTUM [TUM_HEAVY].upload.u8TrafficLimitPerc == 100);
	m_aTUM [TUM_HEAVY].download.u8TrafficLimitPerc = 100;
	m_aTUM [TUM_HEAVY].upload.u8TrafficLimitPerc = 100;

	m_enCurrentTUM = m_enUserTUM = _App.CurrentTUM ();
	m_enTUMManage = _App.TUMManage ();

	refgetNetworkStat (true).uConnectionBandwidthByUser = _App.ConnectionBandwidth (true);
	refgetNetworkStat (false).uConnectionBandwidthByUser = _App.ConnectionBandwidth (false);

	BuildCurrentSettings ();
}

void vmsTrafficUsageModeMgr::SaveSettings(void)
{
	_App.TUMManage (m_enTUMManage);
	_App.CurrentTUM (m_enUserTUM);
	
	ASSERT (m_aTUM [TUM_HEAVY].download.u8TrafficLimitPerc == 100);
	ASSERT (m_aTUM [TUM_HEAVY].upload.u8TrafficLimitPerc == 100);
	m_aTUM [TUM_HEAVY].download.u8TrafficLimitPerc = 100;
	m_aTUM [TUM_HEAVY].upload.u8TrafficLimitPerc = 100;
	_App.Set_TUM (m_aTUM);
	_App.ConnectionBandwidth (true, refgetNetworkStat (true).uConnectionBandwidthByUser);
	_App.ConnectionBandwidth (false, refgetNetworkStat (false).uConnectionBandwidthByUser);
}

void vmsTrafficUsageModeMgr::setConnectionBandwidthSpecifiedByUser (bool bForDownload, UINT64 uValue)
{
	refgetNetworkStat (bForDownload).uConnectionBandwidthByUser = uValue;
}

UINT64 vmsTrafficUsageModeMgr::getConnectionBandwidthSpecifiedByUser (bool bForDownload)
{
	return refgetNetworkStat (bForDownload).uConnectionBandwidthByUser;
}

void vmsTrafficUsageModeMgr::SetTUM(fsTUM tum)
{
	setTUM (tum, true);
}

fsTUM vmsTrafficUsageModeMgr::GetTUM()
{
	return m_enCurrentTUM;
}

void vmsTrafficUsageModeMgr::_IECatchMgrEvents(fsIECatchMgrEvent ev, LPVOID lp)
{
	vmsTrafficUsageModeMgr *pThis = (vmsTrafficUsageModeMgr*) lp;

	vmsCriticalSectionAutoLock csal (&pThis->m_csTUMManage);

	switch (ev)
	{
	case ICME_DLSTARTED:
		switch (pThis->m_enTUMManage)
		{
		case TM_OFF:
			return;

		case TM_DECREASEBYONELEVEL:
			switch (pThis->GetTUM ())
			{
			case TUM_HEAVY:
				pThis->setTUM (TUM_MEDIUM, false);
				break;

			case TUM_MEDIUM:
				pThis->setTUM (TUM_LIGHT, false);
				break;
			}
			break;

		case TM_SETTOLIGHT:
			pThis->setTUM (TUM_LIGHT, false);
			break;
		}
		break;

	case ICME_DLCOMPLETED:
		if (pThis->GetTUM () != pThis->m_enUserTUM)
			pThis->setTUM (pThis->m_enUserTUM, false);
		break;
	}
}

void vmsTrafficUsageModeMgr::AttachToIECatchMgr(fsIECatchMgr *mgr)
{
	mgr->SetEventsFunc (_IECatchMgrEvents, this);
}

void vmsTrafficUsageModeMgr::SetTUMManage(fsTUMManage enManage)
{
	vmsAUTOLOCKSECTION (m_csTUMManage);
	m_enTUMManage = enManage;
	if (enManage == TM_OFF) 
	{
		if (GetTUM () != m_enUserTUM)
			SetTUM (m_enUserTUM); 
	}
}

fsTUMManage vmsTrafficUsageModeMgr::GetTUMManage()
{
	return m_enTUMManage;
}

void vmsTrafficUsageModeMgr::SetToDownloadOneByOne(void)
{
	m_aTUM [0].download.uMaxTasks = m_aTUM [1].download.uMaxTasks = m_aTUM [2].download.uMaxTasks = 1;
	BuildCurrentSettings ();
}

void vmsTrafficUsageModeMgr::onSettingsWasChanged ()
{
	_DldsMgr.onCurrentTrafficUsageModeChanged ();
}

void vmsTrafficUsageModeMgr::ApplySpeedLimit(bool bForDownload, UINT64 uLimit)
{
	vmsAUTOLOCKSECTION (m_csManageForSpeed);

	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		for (size_t j = 0; j < m_vpManageForSpeed [i]->vItems.size (); j++)
		{
			if ((m_vpManageForSpeed [i]->vItems [j].state & ManageForSpeedItem::MSIS_PRIORITY_CHANGED) ||
					(m_vpManageForSpeed [i]->vItems [j].getData (bForDownload).state & ManageForSpeedItem::ManageForSpeedItemData::MSIDS_SPEED_CAN_BE_LIMITED_CHANGED))
				m_vpManageForSpeed [i]->vItems [j].getData (bForDownload).vSpeed.clear ();				
		}
	}

	NetworkStat &ns = refgetNetworkStat (bForDownload);

	bool bIsHighestPriorityItems = true;
	for (int i = m_vpManageForSpeed.size () - 1; i >= 0; i--, bIsHighestPriorityItems = false)
	{
		ApplySpeedLimitForItems (bForDownload, m_vpManageForSpeed [i], 
			ns.currentBandwidthExploreInLimitedMode.isExploring () ? UINT64_MAX : uLimit, bIsHighestPriorityItems, &uLimit);
	}
}

void vmsTrafficUsageModeMgr::ApplySpeedLimitForItems(bool bForDownload, ManageForSpeedItemsList *pItems, UINT64 uLimit, bool bIsHighestPriorityItems, UINT64* puUnusedLimit)
{
	LOGFN ("vmsTrafficUsageModeMgr::ApplySpeedLimitForItems");

	assert (puUnusedLimit != NULL);

	pItems->state &= ~ManageForSpeedItemsList::MSILS_USES_ALL_BANDWIDTH_PROVIDED;

	if (pItems->vItems.empty ())
	{
		*puUnusedLimit = uLimit;
		return;
	}

	size_t cProcessed = 0; 
	std::vector <bool> vProcessed; 
	vProcessed.assign (pItems->vItems.size (), false);
	std::vector <UINT64> vLimits; 
	vLimits.assign (pItems->vItems.size (), 0);

	UINT64 uEatenTotal = 0;

	
	
	bool bMaxLimitPerOneMustBeRecalculated = true;

	while (bMaxLimitPerOneMustBeRecalculated) 
	{
		UINT64 uMaxLimitPerOne = uLimit == UINT64_MAX ? UINT64_MAX : (uLimit - uEatenTotal) / (vProcessed.size () - cProcessed);
		bMaxLimitPerOneMustBeRecalculated = false;		

		for (size_t i = 0; i < pItems->vItems.size (); i++) 
		{
			if (vProcessed [i])
				continue;

			ManageForSpeedItem *pItem = &pItems->vItems [i];

			if (!pItem->pDldr->isRequiresTraffic (bForDownload))
			{
				vProcessed [i] = true;
				
				
				
				vLimits [i] = uMaxLimitPerOne;
				uEatenTotal += min (pItem->pDldr->getSpeed (bForDownload), uMaxLimitPerOne);
				
				cProcessed++;
				bMaxLimitPerOneMustBeRecalculated = cProcessed != vProcessed.size ();
				continue;
			}

			UINT64 uMaxLimitForThis = uMaxLimitPerOne;
			if (!uMaxLimitForThis)
				uMaxLimitForThis = 1;
			if (pItem->pDldr->getInternalSpeedLimit (bForDownload) < uMaxLimitForThis)
				uMaxLimitForThis = pItem->pDldr->getInternalSpeedLimit (bForDownload);
			if (pItem->pDldr->isIgnoreAllSpeedLimits (bForDownload))
				uMaxLimitForThis = UINT64_MAX;
			if (uMaxLimitForThis < 100 && !pItem->pDldr->isResumeSupported (bForDownload))
				uMaxLimitForThis = 100;

			UINT64 uCurrentLimit = pItem->pDldr->getSpeedLimit (bForDownload);
			UINT64 uCurrentMaximumSpeed = pItem->getData (bForDownload).vSpeed.getCurrentMaximumValue ();

			
			if (uCurrentLimit <= uMaxLimitForThis && 
				uCurrentMaximumSpeed < uCurrentLimit / 1.1)
			{
				
				
				
				vLimits [i] = uMaxLimitForThis;
				uEatenTotal += uCurrentMaximumSpeed; 
				if (uEatenTotal > uLimit)
					uEatenTotal = uLimit; 
				vProcessed [i] = true;
				cProcessed++;
				bMaxLimitPerOneMustBeRecalculated = cProcessed != vProcessed.size ();
				continue;
			}

			if (!bMaxLimitPerOneMustBeRecalculated)
				vLimits [i] = uMaxLimitForThis;
		}
	}

	

	if (cProcessed != vProcessed.size ())
	{
		for (size_t i = 0; i < pItems->vItems.size (); i++)
		{
			if (vProcessed [i])
				continue;
			if (vLimits [i] == UINT64_MAX)
			{
				uEatenTotal = UINT64_MAX;
				break;
			}
			uEatenTotal += vLimits [i]; 
		}
	}

	if (uEatenTotal > uLimit)
		uEatenTotal = uLimit; 

	

	for (size_t i = 0; i < pItems->vItems.size (); i++)
	{
		LOG ("set limit of %I64d for %i item", vLimits [i], i);
		pItems->vItems [i].pDldr->setSpeedLimit (bForDownload, vLimits [i]);
	}

	

	NetworkStat& ns = refgetNetworkStat (bForDownload);

	
	UINT64 uLimit2 = uLimit;

	if (bIsHighestPriorityItems)
	{
		
		if (ns.uCurrentBandwidth < uLimit2)
		{
			uLimit2 = ns.uCurrentBandwidth;
			if (uEatenTotal != UINT64_MAX && uEatenTotal > uLimit2)
				uEatenTotal = uLimit2;
		}
	}

	if (uEatenTotal != UINT64_MAX)
	{
		
		uEatenTotal *= 1.05;
		if (uEatenTotal > uLimit2)
			uEatenTotal = uLimit2;

		if (uLimit2 != UINT64_MAX)
		{
			if (uEatenTotal != uLimit2)
			{
				
				if (uLimit2 / delta (uLimit2, uEatenTotal) >= 10)
					uEatenTotal = uLimit2; 
			}
		}
	}

	if (pItems->totalSpeedExplorer.isExploring ())
	{
		if (uEatenTotal != UINT64_MAX)
		{
			
			uEatenTotal += pItems->totalSpeedExplorer.getAdjustingValue ();
			if (uEatenTotal > uLimit2)
				uEatenTotal = uLimit2;
		}
	}

	*puUnusedLimit = uLimit2 > uEatenTotal ? uLimit2 - uEatenTotal : 0;

	if (*puUnusedLimit == 0)
		pItems->state |= ManageForSpeedItemsList::MSILS_USES_ALL_BANDWIDTH_PROVIDED;

	if (ns.currentBandwidthExplorer.isExploring ())
	{
		*puUnusedLimit += ns.currentBandwidthExplorer.getAdjustingValue ();
		if (*puUnusedLimit > uLimit)
		{
			assert (uEatenTotal <= uLimit);
			*puUnusedLimit = uLimit - uEatenTotal;
		}
	}
}

DWORD WINAPI vmsTrafficUsageModeMgr::_threadManage(LPVOID lp)
{
	LOGFN ("vmsTrafficUsageModeMgr::_threadManage");

	vmsTrafficUsageModeMgr *pthis = (vmsTrafficUsageModeMgr*)lp;

	while (WaitForSingleObject (pthis->m_hevShuttingDown, 1000) == WAIT_TIMEOUT)
	{
		pthis->CheckIfBestInterfaceChanged ();
		pthis->CheckNeedResetAllSpeedsInfo ();

		bool bDontUpdateSpeeds = pthis->m_cSecondsNoSpeedMeasure != 0;
		if (bDontUpdateSpeeds)
		{
			vmsCriticalSectionAutoLock csal (&pthis->m_csMisc);
			pthis->m_cSecondsNoSpeedMeasure--;			
		}
		if (pthis->m_bRestrainAll)
			bDontUpdateSpeeds = true;
		vmsCriticalSectionAutoLock csal (&pthis->m_csManageForSpeed);
		pthis->CheckItemsPriorityChanges ();
		UINT64 uConnectionDownloadBandwidth = pthis->refgetNetworkStat (true).uConnectionBandwidth;
		UINT64 uConnectionUploadBandwidth = pthis->refgetNetworkStat (false).uConnectionBandwidth;
		pthis->ProcessManageForSpeedItems (true, bDontUpdateSpeeds);
		

		
		for (size_t i = 0; i < pthis->m_vpManageForSpeed.size (); i++)
		{
			for (size_t j = 0; j < pthis->m_vpManageForSpeed [i]->vItems.size (); j++)
				pthis->m_vpManageForSpeed [i]->vItems [j].state &= ~ManageForSpeedItem::MSIS_PRIORITY_CHANGED;
		}

		if (uConnectionDownloadBandwidth != pthis->refgetNetworkStat (true).uConnectionBandwidth ||
				uConnectionUploadBandwidth != pthis->refgetNetworkStat (false).uConnectionBandwidth)
			pthis->BuildCurrentSettings ();
		else if (uConnectionDownloadBandwidth == UINT64_MAX )
			pthis->BuildCurrentSettings ();
	}

	return 0;
}

void vmsTrafficUsageModeMgr::CheckItemsPriorityChanges ()
{
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

		for (size_t j = 0; j < pList->vItems.size (); j++)
		{
			ManageForSpeedItem& item = pList->vItems [j];

			if (item.pDldr->getPriority () != pList->i8Priority)
			{
				int iPriorityIndex = GetPriorityListIndex (item.pDldr->getPriority ());
				item.state |= item.MSIS_PRIORITY_CHANGED;
				m_vpManageForSpeed [iPriorityIndex]->vItems.push_back (item);
				pList->vItems.erase (pList->vItems.begin () + j--);
			}
		}
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_checkStateChanges (bool bForDownload)
{
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

		for (size_t j = 0; j < pList->vItems.size (); j++)
		{
			ManageForSpeedItem& item = pList->vItems [j];
			ManageForSpeedItem::ManageForSpeedItemData &data = item.getData (bForDownload);

			if (!(data.state & data.MSIDS_SPEED_CAN_BE_LIMITED) != !item.pDldr->isSpeedCanBeLimitedBySomeInternalReasons (bForDownload))
			{
				data.state ^= data.MSIDS_SPEED_CAN_BE_LIMITED;
				data.state |= data.MSIDS_SPEED_CAN_BE_LIMITED_CHANGED;
			}
		}
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidthInLimitedMode (bool bForDownload)
{
	NetworkStat& ns = refgetNetworkStat (bForDownload);

	if (ns.currentBandwidthExploreInLimitedMode.isExploring ())
	{
		ns.currentBandwidthExploreInLimitedMode.CheckNeedStopExplore ();
	}
	else
	{
		if (m_enCurrentTUM == TUM_HEAVY || m_bRestrainAll || ns.uConnectionBandwidthByUser != UINT64_MAX)
			return; 
		if (ns.tcHeavyModeWorkedEnoughUntil && vmsTickCount::GetTickCount64 () - ns.tcHeavyModeWorkedEnoughUntil < 5*60*1000)
			return; 
		ns.currentBandwidthExploreInLimitedMode.CheckNeedStartExplore ();
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidth (bool bForDownload)
{
	NetworkStat& ns = refgetNetworkStat (bForDownload);

	UINT64 nCurrentMaxTotalSpeed = ns.vTotalSpeed.getCurrentMaximumValue ();
	if (nCurrentMaxTotalSpeed == UINT64_MAX)
		return;

	if (ns.uCurrentBandwidth == UINT64_MAX ||
			ns.uCurrentBandwidth < nCurrentMaxTotalSpeed ||
			nCurrentMaxTotalSpeed < ns.uCurrentBandwidth * 0.9)
		ns.uCurrentBandwidth = nCurrentMaxTotalSpeed;

	if (ns.currentBandwidthExplorer.isExploring ())
	{
		ns.currentBandwidthExplorer.CheckNeedStopExplore ();
	}
	else
	{
		UINT64 uCurrentLimit = getSettings ().getSettings (bForDownload).uTrafficLimit;
		if (uCurrentLimit == UINT64_MAX || uCurrentLimit == UINT_MAX)
			uCurrentLimit = ns.uConnectionBandwidth;
		bool bNeedExplore = ns.uCurrentBandwidth < uCurrentLimit * 0.9;
		if (bNeedExplore)
			ns.currentBandwidthExplorer.CheckNeedStartExplore ();
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_manageReMeasures_ExtraBandwidthForHigherPriorityItems (bool bForDownload)
{
	int nIndex = findIndexOfItemsListExploringTotalSpeed ();

	if (nIndex != -1)
	{
		m_vpManageForSpeed [nIndex]->totalSpeedExplorer.CheckNeedStopExplore ();
	}
	else
	{
		for (int i = m_vpManageForSpeed.size () - 1; i >= 0; i--)
		{
			ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

			if (pList->state & ManageForSpeedItemsList::MSILS_USES_ALL_BANDWIDTH_PROVIDED)
				continue; 
			if (pList->vTotalSpeed.getCurrentMaximumValue () == UINT64_MAX)
				continue;
			pList->totalSpeedExplorer.CheckNeedStartExplore ();
			if (pList->totalSpeedExplorer.isExploring ())
				return;
		}
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_manageReMeasures (bool bForDownload)
{
	NetworkStat& ns = refgetNetworkStat (bForDownload);

	if (ns.currentBandwidthExploreInLimitedMode.isExploring ())
	{
		ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidthInLimitedMode (bForDownload);
	}

	else if (ns.currentBandwidthExplorer.isExploring ())
	{
		ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidth (bForDownload);
	}

	else if (findIndexOfItemsListExploringTotalSpeed () != -1)
	{
		ProcessManageForSpeedItems_manageReMeasures_ExtraBandwidthForHigherPriorityItems (bForDownload);
	}

	else
	{
		if (m_bRestrainAll)
			return; 

		ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidthInLimitedMode (bForDownload);

		if (!ns.currentBandwidthExploreInLimitedMode.isExploring ())
		{
			ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidth (bForDownload);

			if (!ns.currentBandwidthExplorer.isExploring ())
				ProcessManageForSpeedItems_manageReMeasures_ExtraBandwidthForHigherPriorityItems (bForDownload);
		}
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems(bool bForDownload, bool bDontUpdateSpeeds)
{
	vmsAUTOLOCKSECTION (m_csManageForSpeed);

	ProcessManageForSpeedItems_checkStateChanges (bForDownload);

	if (!bDontUpdateSpeeds)
		ProcessManageForSpeedItems_updateSpeeds (bForDownload);

	ProcessManageForSpeedItems_manageReMeasures (bForDownload);

	UINT64 uLimit = getSettings ().getSettings (bForDownload).uTrafficLimit;
	if (m_bRestrainAll)
		uLimit = 0;
	ApplySpeedLimit (bForDownload, uLimit);

	
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		for (size_t j = 0; j < m_vpManageForSpeed [i]->vItems.size (); j++)
			m_vpManageForSpeed [i]->vItems [j].getData (bForDownload).state &= ~ManageForSpeedItem::ManageForSpeedItemData::MSIDS_SPEED_CAN_BE_LIMITED_CHANGED;
	}
}

int vmsTrafficUsageModeMgr::GetPriorityListIndex (BYTE i8Priority)
{
	size_t i = 0;
	while (i < m_vpManageForSpeed.size () && m_vpManageForSpeed [i]->i8Priority <= i8Priority)
		i++;
	if (i == m_vpManageForSpeed.size ())
	{
		ManageForSpeedItemsList *pList = new ManageForSpeedItemsList;
		pList->i8Priority = i8Priority;
		m_vpManageForSpeed.push_back (pList);
	}
	else
	{
		if (m_vpManageForSpeed [i]->i8Priority != i8Priority)
		{
			ManageForSpeedItemsList *pList = new ManageForSpeedItemsList;
			pList->i8Priority = i8Priority;
			m_vpManageForSpeed.insert (m_vpManageForSpeed.begin () + i, pList);
		}
	}
	return i;
}

void vmsTrafficUsageModeMgr::addManageForSpeedItem(vmsDownloaderWithNetworkUsageAdjustment* pItem)
{
	assert (pItem);
	if (!pItem)
		return;
	vmsAUTOLOCKSECTION (m_csManageForSpeed);
	int iPriorityIndex = -1;
	if (findManageForSpeedItemIndex (pItem, &iPriorityIndex) == -1)
	{
		if (iPriorityIndex == -1)
			iPriorityIndex = GetPriorityListIndex (pItem->getPriority ());
		m_vpManageForSpeed [iPriorityIndex]->vItems.push_back (pItem);
	}
}

void vmsTrafficUsageModeMgr::removeManageForSpeedItem(vmsDownloaderWithNetworkUsageAdjustment* pItem)
{
	assert (pItem);
	if (!pItem)
		return;
	vmsAUTOLOCKSECTION (m_csManageForSpeed);
	int nPriorityIndex, nIndex = findManageForSpeedItemIndex (pItem, &nPriorityIndex);
	if (nIndex != -1)
		m_vpManageForSpeed [nPriorityIndex]->vItems.erase (m_vpManageForSpeed [nPriorityIndex]->vItems.begin () + nIndex);
}

int vmsTrafficUsageModeMgr::findPriorityIndex (BYTE i8Priority) const
{
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		if (m_vpManageForSpeed [i]->i8Priority == i8Priority)
			return i;
		if (m_vpManageForSpeed [i]->i8Priority > i8Priority)
			return -1; 
	}
	return -1;
}

int vmsTrafficUsageModeMgr::findManageForSpeedItemIndex(vmsDownloaderWithNetworkUsageAdjustment* pItem, int *piPriorityIndex) const
{
	assert (piPriorityIndex != NULL);
	if (!piPriorityIndex)
		return -1;
	*piPriorityIndex = findPriorityIndex (pItem->getPriority ());
	if (*piPriorityIndex != -1)
	{
		int i = m_vpManageForSpeed [*piPriorityIndex]->findItemIndexByDownloader (pItem);
		if (i != -1)
			return i;
	}
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		if (int (i) == *piPriorityIndex)
			continue;
		int i2 = m_vpManageForSpeed [i]->findItemIndexByDownloader (pItem);
		if (i2 != -1)
		{
			*piPriorityIndex = i;
			return i2;
		}
	}
	return -1;
}

void vmsTrafficUsageModeMgr::setTUM(fsTUM tum, bool bByUser)
{
	if (GetTUM () != tum)
	{
		vmsAUTOLOCKSECTION (m_csMisc);
		m_cSecondsNoSpeedMeasure = 7;
		vmsAUTOLOCKSECTION_UNLOCK (m_csMisc);
		if (bByUser)
			m_enUserTUM = tum;
		m_enCurrentTUM = tum;
		BuildCurrentSettings ();
	}
}

void vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_updateSpeeds(bool bForDownload)
{
	LOGFN ("vmsTrafficUsageModeMgr::ProcessManageForSpeedItems_updateSpeeds");

	UINT64 uTotalInternetSpeed = 0;
	bool bAtLeast1UsesInternet = false;

	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

		UINT64 uListTotalInternetSpeed = 0;

		for (size_t j = 0; j < pList->vItems.size (); j++)
		{
			ManageForSpeedItem *pItem = &pList->vItems [j];
			if (pItem->pDldr->isRequiresTraffic (bForDownload))
			{
				UINT64 uSpeed = pItem->pDldr->getSpeed (bForDownload);
				pItem->getData (bForDownload).vSpeed.AddValue (uSpeed);

				if (pItem->pDldr->isInternetTraffic (bForDownload))
				{
					bAtLeast1UsesInternet = true;
					uListTotalInternetSpeed += uSpeed;
				}				
			}
			else
			{
				if (!pItem->getData (bForDownload).vSpeed.empty ())
					pItem->getData (bForDownload).vSpeed.clear ();				
			}
		}

		pList->vTotalSpeed.AddValue (uListTotalInternetSpeed);
		uTotalInternetSpeed += uListTotalInternetSpeed;
	}

	NetworkStat& ns = refgetNetworkStat (bForDownload);

	if (m_enCurrentTUM != TUM_HEAVY)
	{
		ns.tcTrafficGoesInHeavyModeFrom = 0;
	}
	else
	{
		if (!uTotalInternetSpeed)
		{
			ns.tcTrafficGoesInHeavyModeFrom = 0;
		}
		else
		{
			UINT64 tcNow = vmsTickCount::GetTickCount64 ();
			if (!ns.tcTrafficGoesInHeavyModeFrom)
				ns.tcTrafficGoesInHeavyModeFrom = tcNow;
			if (tcNow - ns.tcTrafficGoesInHeavyModeFrom > 3*60*1000)
				ns.tcHeavyModeWorkedEnoughUntil = tcNow;
		}
	}

	vmsAUTOLOCKSECTION (m_csMisc);
	if (bAtLeast1UsesInternet)
		ns.vTotalSpeed.AddValue (uTotalInternetSpeed);

	UINT64 uTotalMaxSpeed = ns.vTotalSpeed.getMaximumValue ();

	if (uTotalMaxSpeed != UINT64_MAX)
	{
		if (ns.uConnectionBandwidth == UINT64_MAX)
		{
			if (uTotalMaxSpeed > ns.bandwidthMeasureStart.uMaxValue)
			{
				if (uTotalMaxSpeed > UINT64 (ns.bandwidthMeasureStart.uMaxValue*1.1))
					ns.bandwidthMeasureStart.cNonZeroTotalSpeeds = 0; 
				ns.bandwidthMeasureStart.uMaxValue = uTotalMaxSpeed;
			}
			if (uTotalMaxSpeed)
				ns.bandwidthMeasureStart.cNonZeroTotalSpeeds++;
			if (ns.bandwidthMeasureStart.cNonZeroTotalSpeeds >= 10)
				ns.uConnectionBandwidth = ns.bandwidthMeasureStart.uMaxValue;
		}
		else if (ns.uConnectionBandwidth < uTotalMaxSpeed)
		{
			ns.uConnectionBandwidth = uTotalMaxSpeed;
		}
	}
}

void vmsTrafficUsageModeMgr::setRestrainAll(bool bSet)
{
	if (m_bRestrainAll != bSet)
	{
		if (!bSet)
		{
			vmsAUTOLOCKSECTION (m_csMisc);
			m_cSecondsNoSpeedMeasure = 7;
		}
		m_bRestrainAll = bSet;
		_DldsMgr.setNeedApplyTrafficLimit ();
	}
}

bool vmsTrafficUsageModeMgr::getRestrainAll(void)
{
	return m_bRestrainAll;
}

void vmsTrafficUsageModeMgr::CheckIfBestInterfaceChanged ()
{
	vmsIpHelper iph;
	if (!iph.GetAdaptersInfo ())
		return;

	DWORD dwIfIndex;
	if (NO_ERROR != GetBestInterface (inet_addr ("8.8.8.8"), &dwIfIndex))
		return;

	PIP_ADAPTER_INFO pAdapter = iph.FindAdapterByIfIndex (dwIfIndex);
	if (!pAdapter)
		return;

	if (pAdapter->IpAddressList.IpAddress.String == m_strCurrentIP)
		return;

	if (!(m_dwState & TUMM_SPEEDS_INFO_CAN_BE_INCORRECT))
		SaveCurrentAdapterInfo ();

	std::string strAdapterAddress;
	for (UINT i = 0; i < pAdapter->AddressLength; i++)
	{
		char sz [10];
		itoa (pAdapter->Address [i], sz, 16);
		if (sz [1] == 0)
			strAdapterAddress += '0';
		strAdapterAddress += sz;
	}

	m_strCurrentAdapterAddress = strAdapterAddress;
	m_strCurrentIP = pAdapter->IpAddressList.IpAddress.String;

	vmsAUTOLOCKSECTION (m_csMisc);
	m_dwState |= TUMM_SPEEDS_INFO_CAN_BE_INCORRECT;
	vmsAUTOLOCKSECTION_UNLOCK (m_csMisc);

	vmsAUTOLOCKSECTION (m_csManageForSpeed);
	
	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

		for (size_t j = 0; j < pList->vItems.size (); j++)
			pList->vItems [j].state |= ManageForSpeedItem::MSIS_MAY_USE_NOT_CURRENT_ADAPTER;
	}
	vmsAUTOLOCKSECTION_UNLOCK (m_csManageForSpeed);

	ResetAllSpeedsInfo ();
}

void vmsTrafficUsageModeMgr::ResetAllSpeedsInfo(void)
{
	ResetAllSpeedsInfo (true);
	ResetAllSpeedsInfo (false);
}

void vmsTrafficUsageModeMgr::ResetAllSpeedsInfo(bool bForDownload)
{
	vmsAUTOLOCKSECTION (m_csManageForSpeed);

	NetworkStat &ns = refgetNetworkStat (bForDownload);
	ns.bandwidthMeasureStart.Reset ();
	ns.uConnectionBandwidth = ns.uCurrentBandwidth = UINT64_MAX;
	ns.vTotalSpeed.clear ();
	ns.currentBandwidthExplorer.Reset ();
	ns.currentBandwidthExploreInLimitedMode.Reset ();

	for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
	{
		ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

		pList->vTotalSpeed.clear ();
		pList->totalSpeedExplorer.Reset ();

		for (size_t j = 0; j < pList->vItems.size (); j++)
		{
			ManageForSpeedItem *pItem = &pList->vItems [j];
			pItem->getData (bForDownload).vSpeed.clear ();
		}
	}
}

void vmsTrafficUsageModeMgr::ReadCurrentAdapterInfo(void)
{
	ReadCurrentAdapterInfo (true);
	ReadCurrentAdapterInfo (false);
}

void vmsTrafficUsageModeMgr::ReadCurrentAdapterInfo(bool bForUpload)
{
}

void vmsTrafficUsageModeMgr::CheckNeedResetAllSpeedsInfo(void)
{
	if (!(m_dwState & TUMM_SPEEDS_INFO_CAN_BE_INCORRECT))
		return;

	bool bAllUsesCurrentAdapter = true;

	vmsAUTOLOCKSECTION (m_csManageForSpeed);

	for (size_t i = 0; bAllUsesCurrentAdapter && i < m_vpManageForSpeed.size (); i++)
	{
		ManageForSpeedItemsList *pList = m_vpManageForSpeed [i];

		for (size_t j = 0; bAllUsesCurrentAdapter && j < pList->vItems.size (); j++)
		{
			if (pList->vItems [j].state & ManageForSpeedItem::MSIS_MAY_USE_NOT_CURRENT_ADAPTER)
				bAllUsesCurrentAdapter = false;
		}
	}

	vmsAUTOLOCKSECTION_UNLOCK (m_csManageForSpeed);

	if (!bAllUsesCurrentAdapter)
		return;

	vmsAUTOLOCKSECTION (m_csMisc);
	m_dwState &= ~TUMM_SPEEDS_INFO_CAN_BE_INCORRECT;
	vmsAUTOLOCKSECTION_UNLOCK (m_csMisc);

	ResetAllSpeedsInfo ();
	ReadCurrentAdapterInfo ();
}

void vmsTrafficUsageModeMgr::SaveCurrentAdapterInfo(void)
{
	if (m_dwState & TUMM_SPEEDS_INFO_CAN_BE_INCORRECT)
		return;
	SaveCurrentAdapterInfo (true);
	SaveCurrentAdapterInfo (false);
}

void vmsTrafficUsageModeMgr::SaveCurrentAdapterInfo(bool bForDownload)
{
	if (m_dwState & TUMM_SPEEDS_INFO_CAN_BE_INCORRECT)
		return;
}

void vmsTrafficUsageModeMgr::BuildCurrentSettings_PerDirection (vmsTrafficUsageModeSettings &stgs, bool bForDownload)
{
	vmsTrafficUsageModeSettings::PerDirection &s = stgs.refgetSettings (bForDownload);

	assert (UINT (UINT64_MAX) == UINT_MAX); 

	const vmsTrafficUsageModeRawSettings::PerDirection &rs = m_aTUM [m_enCurrentTUM].getSettings (bForDownload);

	UINT64 uConnectionSpeed = refgetNetworkStat (bForDownload).uConnectionBandwidthByUser;
	if (uConnectionSpeed == UINT64_MAX)
		uConnectionSpeed = refgetNetworkStat (bForDownload).uConnectionBandwidth;

	float fK = float (rs.u8TrafficLimitPerc) / 100.0f;

	if (m_enCurrentTUM == TUM_HEAVY)
	{
		s.uTrafficLimit = UINT64_MAX;
	}
	else
	{
		if (uConnectionSpeed == UINT64_MAX)
			s.uTrafficLimit = UINT64_MAX;
		else if (rs.u8TrafficLimitPerc == 100)
			s.uTrafficLimit = UINT64_MAX;
		else	
			s.uTrafficLimit = (UINT64) (uConnectionSpeed * fK);
	}

	
	
	UINT nMaxConnsPerTask, nMaxTasks;

	if (uConnectionSpeed == UINT64_MAX)
	{
		nMaxTasks = 2;
		UINT64 uMaxSpeed = refgetNetworkStat (bForDownload).vTotalSpeed.getMaximumValue (false);
		if (uMaxSpeed == UINT64_MAX)
			nMaxConnsPerTask = 6;
		else if (uMaxSpeed >= 16*1024*1024/8)
			nMaxConnsPerTask = 30;
		else if (uMaxSpeed >= 8*1024*1024/8)
			nMaxConnsPerTask = 20;
		else if (uMaxSpeed >= 3*1024*1024/8)
			nMaxConnsPerTask = 15;
		else if (uMaxSpeed >= 128*1024/8)
			nMaxConnsPerTask = 10;
		else
			nMaxConnsPerTask = 6;
	}
	else if (uConnectionSpeed >= 30*1024*1024/8)
	{
		nMaxTasks = 7;
		nMaxConnsPerTask = 30;
	}
	else if (uConnectionSpeed >= 20*1024*1024/8)
	{
		nMaxTasks = 5;
		nMaxConnsPerTask = 25;
	}
	else if (uConnectionSpeed >= 10*1024*1024/8)
	{
		nMaxTasks = 4;
		nMaxConnsPerTask = 20;
	}
	else if (uConnectionSpeed >= 6*1024*1024/8)
	{
		nMaxTasks = 3;
		nMaxConnsPerTask = 15;
	}
	else if (uConnectionSpeed >= 2*1024*1024/8)
	{
		nMaxTasks = 2;
		nMaxConnsPerTask = 10;			
	}
	else if (uConnectionSpeed >= 128*1024/8)
	{
		nMaxTasks = 2;
		nMaxConnsPerTask = 10;
	}
	else
	{
		nMaxTasks = 2;
		nMaxConnsPerTask = 4;
	}
	

	s.uMaxTasks = rs.uMaxTasks ? rs.uMaxTasks : (float (nMaxTasks) * fK + 0.5f);
	s.uMaxConns = rs.uMaxConns ? rs.uMaxConns : (float (nMaxConnsPerTask * nMaxTasks) * fK + 0.5f);
	s.uMaxConnsPS = rs.uMaxConnsPS ? rs.uMaxConnsPS : (float (nMaxConnsPerTask) * fK + 0.5f);

	if (!s.uTrafficLimit)
		s.uTrafficLimit = 1;
	if (!s.uMaxTasks)
		s.uMaxTasks = 1;
	if (!s.uMaxConns)
		s.uMaxConns = 1;
	if (!s.uMaxConnsPS)
		s.uMaxConnsPS = 1;
}

void vmsTrafficUsageModeMgr::BuildCurrentSettings ()
{
	vmsTrafficUsageModeSettings stgs;

	BuildCurrentSettings_PerDirection (stgs, true);
	BuildCurrentSettings_PerDirection (stgs, false);

	if (memcmp (&m_currentStgs, &stgs, sizeof (stgs)))
	{
		m_currentStgs = stgs;
		onSettingsWasChanged ();
	}
}

void vmsTrafficUsageModeMgr::Shutdown(void)
{
	SetEvent (m_hevShuttingDown);
}
