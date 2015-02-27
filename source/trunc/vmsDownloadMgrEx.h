/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDOWNLOADMGREX_H__A5D098FD_2C7B_4051_B405_8B1F25F3C3FA__INCLUDED_)
#define AFX_VMSDOWNLOADMGREX_H__A5D098FD_2C7B_4051_B405_8B1F25F3C3FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsPersistObject.h"
#include "dldscommon.h"

struct vmsSectionInfo
{
	
	
	UINT64 uDStart, uDEnd, uDCurrent;
};

class vmsDownloadMgrEx : public vmsObject, 
	public vmsDownloaderWithNetworkUsageAdjustment, 
	public vmsPersistObject 
{
public:
	void Do_OpenFolder();
	int get_ReservingDiskSpaceProgress();
	BOOL IsReservingDiskSpace();
	void GetSplittedSectionsList (std::vector <vmsSectionInfo> &v);
	
	BOOL IsBittorrent();
	BOOL IsTp();
	
	
	
	
	
	BOOL LoadState (LPBYTE pb, LPDWORD pdwSize, WORD wVer);
	int GetConnectionCount();
	fsInternetResult SetToRestartState();
	BOOL IsDontConfirmLaunchWhenDone();
	BOOL DeleteFile();
	void UseDetailedLog (BOOL b);
	UINT GetTrafficLimit();
	void LimitTraffic (UINT uLimit);
	void StopDownloading();
	fsInternetResult StartDownloading();
	BOOL IsHtmlSpiderDownload();
	BOOL IsDescriptionFileShouldBeGenerated();
	fsInternetResult RestartDownloading();
	BOOL IsCantStart();
	BOOL IsStoppedByUser();
	BOOL MoveToFolder (LPCSTR pszPath);
	UINT GetSpeed();
	UINT64 GetBytesLeft();
	void StopSection();
	void CreateOneMoreSection();
	int GetDownloadingSectionCount();
	void GetSectionInfo (int nIndex, vmsSectionInfo *sect, BOOL bNoCacheAccounting = FALSE);
	UINT64 GetSSFileSize();
	BOOL IsDownloading();
	UINT64 GetDownloadedBytesCount();
	UINT64 GetLDFileSize();
	int GetNumberOfSections();
	fsString get_URL(BOOL bInclAuth = FALSE);
	void set_LaunchWhenDone (BOOL b);
	BOOL IsFileInitializedOnDisk();
	BOOL IsRunning();
	BOOL IsDone();
	fsResumeSupportType IsResumeSupported();
	BOOL IsLaunchWhenDone();
	float GetPercentDone();
	fsString get_OutputFilePathName();
	class vmsBtDownloadManager* GetBtDownloadMgr();
	class vmsTpDownloadMgr* GetTpDownloadMgr();
	class fsDownloadMgr* GetDownloadMgr();
	
	void Attach (vmsBtDownloadManager* pBtMgr);
	void Attach (fsDownloadMgr *pMgr);
	void Attach(vmsTpDownloadMgr *pTpMgr);
	vmsDownloadMgrEx();
	virtual ~vmsDownloadMgrEx();

protected:
	void DetachDownloadMgr ();
	vmsObjectSmartPtr <class vmsBtDownloadManager> m_spBtMgr;
	fsDownloadMgr* m_pMgr;
	vmsTpDownloadMgr* m_pTpMgr;
public:
	UINT64 getSpeed(bool bOfDownload);
	void setSpeedLimit(bool bOfDownload, UINT64 uLimit);
protected:
	vmsDownloaderWithNetworkUsageAdjustment* getDownloaderWithNetworkUsageAdjustmentObject(void);
public:
	UINT64 getSpeedLimit(bool bOfDownload);
	bool isResumeSupported(bool bOfDownload);
	bool isIgnoreAllSpeedLimits(bool bOfDownload);
	UINT64 getInternalSpeedLimit(bool bOfDownload);
	bool isRequiresTraffic(bool bForDownload);
	bool isSpeedCanBeLimitedBySomeInternalReasons (bool bForDownload);
	bool isInternetTraffic (bool bForDownload);
};

typedef vmsObjectSmartPtr <vmsDownloadMgrEx> vmsDownloadMgrSmartPtr;

#endif 
