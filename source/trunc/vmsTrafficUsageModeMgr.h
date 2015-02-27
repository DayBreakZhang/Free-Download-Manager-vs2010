/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsMaximumSpeedMeter.h"
#include "vmsValueLog.h"

enum fsTUM
{
	TUM_LIGHT		= 0,	
	TUM_MEDIUM		= 1,	
	TUM_HEAVY		= 2		
};

struct vmsTrafficUsageModeRawSettings
{
	struct PerDirection
	{
		UINT32 uMaxConns;
		UINT32 uMaxConnsPS;
		UINT32 uMaxTasks;
		BYTE u8TrafficLimitPerc;	
		PerDirection () {uMaxConns = 3; uMaxConnsPS = 3; uMaxTasks = 3; u8TrafficLimitPerc = 100;}
	};
	PerDirection download, upload;
	PerDirection& refgetSettings (bool bForDownload) {return bForDownload ? download : upload;}
	const PerDirection& getSettings (bool bForDownload) const {return bForDownload ? download : upload;}
};

struct vmsTrafficUsageModeSettings
{
	struct PerDirection
	{
		UINT32 uMaxConns;
		UINT32 uMaxConnsPS;
		UINT32 uMaxTasks;
		UINT64 uTrafficLimit;	
		PerDirection () {uMaxConns = 3; uMaxConnsPS = 3; uMaxTasks = 3; uTrafficLimit = UINT64_MAX;}
	};
	PerDirection download, upload;
	PerDirection& refgetSettings (bool bForDownload) {return bForDownload ? download : upload;}
	const PerDirection& getSettings (bool bForDownload) const {return bForDownload ? download : upload;}
};

enum fsTUMManage
{
	TM_OFF,						
	TM_DECREASEBYONELEVEL,		
	TM_SETTOLIGHT				
};

class vmsDownloaderWithNetworkUsageAdjustment;

class vmsTrafficUsageModeMgr
{
public:
	fsTUMManage GetTUMManage();
	void SetTUMManage (fsTUMManage enManage);
	fsTUM GetTUM();
	void SetTUM (fsTUM tum);
	
	vmsTrafficUsageModeRawSettings& GetTumRawSettings (fsTUM enTUM);
	void SetTumRawSettings (fsTUM enTUM, vmsTrafficUsageModeRawSettings& stgs);
	void SetTumRawSettingsPerDirection (fsTUM enTUM, vmsTrafficUsageModeRawSettings::PerDirection& stgs, bool bForDownload);
	
#ifndef FDM_DLDR__RAWCODEONLY
	
	void AttachToIECatchMgr (fsIECatchMgr* mgr);
#endif
public:
	vmsTrafficUsageModeMgr(void);
	virtual ~vmsTrafficUsageModeMgr(void);

protected:
	void CheckIfBestInterfaceChanged ();
	vmsTrafficUsageModeRawSettings m_aTUM [3];	
	vmsTrafficUsageModeSettings m_currentStgs;	
	void BuildCurrentSettings ();
	void BuildCurrentSettings_PerDirection (vmsTrafficUsageModeSettings &stgs, bool bForDownload);
	fsTUMManage m_enTUMManage;	
	vmsCriticalSection m_csTUMManage;
	fsTUM m_enCurrentTUM;
	fsTUM m_enUserTUM;			
#ifndef FDM_DLDR__RAWCODEONLY
	
	static void _IECatchMgrEvents (fsIECatchMgrEvent ev, LPVOID lp);
#endif
public:
	
	const vmsTrafficUsageModeSettings& getSettings(void);
	void ReadSettings(void);
	void SaveSettings (void);
	void SetToDownloadOneByOne(void);
	void setConnectionBandwidthSpecifiedByUser (bool bForDownload, UINT64 uValue);
	UINT64 getConnectionBandwidthSpecifiedByUser (bool bForDownload);

protected:
	typedef vmsValueLog <UINT64, UINT64_MAX, 15, INT_MAX, 7, 90> SpeedLog;

	struct ManageForSpeedItem
	{
		struct ManageForSpeedItemData
		{
			enum
			{
				MSIDS_SPEED_CAN_BE_LIMITED				= 1,
				MSIDS_SPEED_CAN_BE_LIMITED_CHANGED		= 1 << 1,
			};

			SpeedLog vSpeed;
			BYTE state;	

			ManageForSpeedItemData () : state (0) {}
		};

		enum
		{
			
			MSIS_PRIORITY_CHANGED							= 1,
			MSIS_MAY_USE_NOT_CURRENT_ADAPTER				= 1 << 1,
		};
		vmsDownloaderWithNetworkUsageAdjustment *pDldr;		
		ManageForSpeedItemData downloadData, uploadData;
		BYTE state; 

		ManageForSpeedItem (vmsDownloaderWithNetworkUsageAdjustment *pObj) : pDldr (pObj), state (0) {}
		ManageForSpeedItemData& getData (bool bForDownload) {return bForDownload ? downloadData : uploadData;}
	};

	struct ManageForSpeedItemsList
	{
		enum
		{
			
			
			MSILS_USES_ALL_BANDWIDTH_PROVIDED		= 1,
		};
		std::vector <ManageForSpeedItem> vItems;
		BYTE i8Priority;
		BYTE state; 
		SpeedLog vTotalSpeed;
		
		vmsMaximumPossibleValueExplorer <20, INT_MAX, 90, 3*60, 1000, SpeedLog> totalSpeedExplorer;

		ManageForSpeedItemsList () : i8Priority (0), state (0), totalSpeedExplorer (&vTotalSpeed) {}

		int findItemIndexByDownloader (vmsDownloaderWithNetworkUsageAdjustment *pDldr) const 
		{
			for (size_t i = 0; i < vItems.size (); i++)
			{
				if (vItems [i].pDldr == pDldr)
					return i;
			}
			return -1;
		}
	};

	std::vector <ManageForSpeedItemsList*> m_vpManageForSpeed;
	vmsCriticalSection m_csManageForSpeed;

	int findIndexOfItemsListExploringTotalSpeed () const
	{
		for (size_t i = 0; i < m_vpManageForSpeed.size (); i++)
		{
			if (m_vpManageForSpeed [i]->totalSpeedExplorer.isExploring ())
				return i;
		}
		return -1;
	}

	
	int m_cSecondsNoSpeedMeasure;
	vmsCriticalSection m_csMisc;

protected:
	typedef vmsValueLog <UINT64, UINT64_MAX, 15, INT_MAX, 7, 4*60> TotalSpeedLog;
	struct NetworkStat
	{
		struct BandwidthMeasureStart
		{
			UINT64 uMaxValue;
			WORD cNonZeroTotalSpeeds;
			BandwidthMeasureStart () {Reset ();}
			void Reset () {uMaxValue = 0; cNonZeroTotalSpeeds = 0;}
		} bandwidthMeasureStart;

		
		UINT64 uConnectionBandwidth; 
		UINT64 uConnectionBandwidthByUser; 
		
		
		UINT64 uCurrentBandwidth;
		
		TotalSpeedLog vTotalSpeed;
		
		vmsMaximumPossibleValueExplorer <15, 40, 3*60, 20*60, 1000, TotalSpeedLog> currentBandwidthExplorer;

		
		
		
		
		vmsMaximumPossibleValueExplorer2 <UINT64, 20, 25, 3*60, INT_MAX, TotalSpeedLog> currentBandwidthExploreInLimitedMode;

		UINT64 tcTrafficGoesInHeavyModeFrom;
		UINT64 tcHeavyModeWorkedEnoughUntil;

		NetworkStat () : uConnectionBandwidth (UINT64_MAX), uConnectionBandwidthByUser (UINT64_MAX),
			uCurrentBandwidth (UINT64_MAX), currentBandwidthExplorer (&vTotalSpeed),
			currentBandwidthExploreInLimitedMode (&uConnectionBandwidth, &vTotalSpeed, 1.5),
			tcTrafficGoesInHeavyModeFrom (0), tcHeavyModeWorkedEnoughUntil (0) {}
	};
	NetworkStat m_downloadStat, m_uploadStat;
	NetworkStat& refgetNetworkStat (bool bForDownload) {return bForDownload ? m_downloadStat : m_uploadStat;}
public:
	UINT64 getConnectionBandwidth (bool bForDownload) {return refgetNetworkStat (bForDownload).uConnectionBandwidth;}
	UINT64 getCurrentBandwidth (bool bForDownload) {return refgetNetworkStat (bForDownload).uCurrentBandwidth;}
protected:
	void ApplySpeedLimit(bool bForDownload, UINT64 uLimit);
	void ApplySpeedLimitForItems(bool bForDownload, ManageForSpeedItemsList *pItems, UINT64 uLimit, bool bIsHighestPriorityItems, UINT64* puUnusedLimit);
	static DWORD WINAPI _threadManage(LPVOID lp);
	HANDLE m_htManage;
	HANDLE m_hevShuttingDown;
	void CheckItemsPriorityChanges ();
	void ProcessManageForSpeedItems(bool bForDownload, bool bDontUpdateSpeeds);
	void ProcessManageForSpeedItems_checkStateChanges (bool bForDownload);
	void ProcessManageForSpeedItems_manageReMeasures (bool bForDownload);
	void ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidth (bool bForDownload);
	void ProcessManageForSpeedItems_manageReMeasures_ExtraBandwidthForHigherPriorityItems (bool bForDownload);
	void ProcessManageForSpeedItems_manageReMeasures_CurrentBandwidthInLimitedMode (bool bForDownload);
public:
	void addManageForSpeedItem(vmsDownloaderWithNetworkUsageAdjustment* pItem);
	void removeManageForSpeedItem(vmsDownloaderWithNetworkUsageAdjustment* pItem);
protected:
	
	int GetPriorityListIndex (BYTE i8Priority);
	int findPriorityIndex (BYTE i8Priority) const;
	int findManageForSpeedItemIndex(vmsDownloaderWithNetworkUsageAdjustment* pItem, int *piPriorityIndex) const;
	void setTUM(fsTUM tum, bool bByUser);
	void ProcessManageForSpeedItems_updateSpeeds(bool bForDownload);
	bool m_bRestrainAll;
	std::string m_strCurrentIP, m_strCurrentAdapterAddress; 
public:
	void setRestrainAll(bool bSet);
	bool getRestrainAll(void);
	void ResetAllSpeedsInfo(void);
	void ResetAllSpeedsInfo (bool bForDownload);
protected:
	void onSettingsWasChanged ();
	void ReadCurrentAdapterInfo(void);
	void ReadCurrentAdapterInfo(bool bForDownload);

	enum
	{
		TUMM_SPEEDS_INFO_CAN_BE_INCORRECT			= 1,
	};

	DWORD m_dwState;
	void CheckNeedResetAllSpeedsInfo(void);
	void SaveCurrentAdapterInfo(void);
	void SaveCurrentAdapterInfo(bool bForDownload);
	void InitTUM ();
	void InitTUM (bool bForDownload);
public:
	void Shutdown(void);
};

extern vmsTrafficUsageModeMgr _TumMgr;

