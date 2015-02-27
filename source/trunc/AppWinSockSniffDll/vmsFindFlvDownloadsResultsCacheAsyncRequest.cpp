/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFindFlvDownloadsResultsCacheAsyncRequest.h"
#include "vmsAsyncTasksTypes.h"

vmsFindFlvDownloadsResultsCacheAsyncRequest::vmsFindFlvDownloadsResultsCacheAsyncRequest(void)
{
	m_nType = vmsAsyncTasksTypes::FindFlvDownloads;
}

vmsFindFlvDownloadsResultsCacheAsyncRequest::~vmsFindFlvDownloadsResultsCacheAsyncRequest(void)
{
}

void vmsFindFlvDownloadsResultsCacheAsyncRequest::Perform ()
{
	extern vmsFindFlvDownloadsResultsCache _FlvResCache;
	_FlvResCache.FindFlvDownloads (m_strWebPageUrl.c_str (), m_strFrameUrl.c_str (), m_strSwfUrl.c_str (), 
		m_strFlashVars.c_str (), m_strOtherSwfUrls.c_str (), m_strOtherFlashVars.c_str (), m_result);
}

bool vmsFindFlvDownloadsResultsCacheAsyncRequest::isEqual (vmsAsyncTask *pTask)
{
	assert (pTask->getType () == getType ());
	vmsFindFlvDownloadsResultsCacheAsyncRequest *p = (vmsFindFlvDownloadsResultsCacheAsyncRequest*)pTask;
	return m_strWebPageUrl == p->m_strWebPageUrl && m_strFrameUrl == p->m_strFrameUrl && 
		m_strSwfUrl == p->m_strSwfUrl && m_strFlashVars == p->m_strFlashVars;
}