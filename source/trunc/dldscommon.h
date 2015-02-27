/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

class vmsDownloaderWithNetworkUsageAdjustment
{
public:
	
	virtual UINT64 getSpeed (bool bOfDownload) = NULL;
	virtual void setSpeedLimit (bool bOfDownload, UINT64 uLimit) = NULL;
	virtual UINT64 getSpeedLimit (bool bOfDownload) = NULL;
	virtual bool isResumeSupported (bool bOfDownload) {UNREFERENCED_PARAMETER (bOfDownload); return true;}
	
	virtual bool isIgnoreAllSpeedLimits (bool bOfDownload) {UNREFERENCED_PARAMETER (bOfDownload); return false;}
	
	
	virtual UINT64 getInternalSpeedLimit (bool bOfDownload) {UNREFERENCED_PARAMETER (bOfDownload); return _UI64_MAX;}
	virtual bool isRequiresTraffic (bool bForDownload) = NULL;
	virtual BYTE getPriority () {return m_i8Priority;}
	virtual void setPriority (BYTE i8Priority){m_i8Priority = i8Priority;}
	virtual bool isSpeedCanBeLimitedBySomeInternalReasons (bool bForDownload) {UNREFERENCED_PARAMETER (bForDownload); return false;}
	virtual bool isInternetTraffic (bool bForDownload) {UNREFERENCED_PARAMETER (bForDownload); return true;}

public:
	vmsDownloaderWithNetworkUsageAdjustment () : m_i8Priority (0) {}
	virtual ~vmsDownloaderWithNetworkUsageAdjustment () {}

protected:
	
	BYTE m_i8Priority;
};