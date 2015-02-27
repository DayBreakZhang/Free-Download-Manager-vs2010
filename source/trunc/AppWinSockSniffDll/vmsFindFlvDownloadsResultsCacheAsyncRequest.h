/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "../Include.Add/vmsAsyncTaskMgr.h"
#include "vmsFindFlvDownloadsResultsCache.h"
class vmsFindFlvDownloadsResultsCacheAsyncRequest : public vmsAsyncTask
{
public:
	void Perform ();
	bool isEqual (vmsAsyncTask *pTask);
	vmsFindFlvDownloadsResultsCacheAsyncRequest(void);
	~vmsFindFlvDownloadsResultsCacheAsyncRequest(void);

public:
	vmsFindFlvDownloadsResultsCache::ResultPtr m_result;
	std::string m_strWebPageUrl, m_strFrameUrl, m_strSwfUrl, m_strFlashVars, m_strOtherSwfUrls, m_strOtherFlashVars;
};

