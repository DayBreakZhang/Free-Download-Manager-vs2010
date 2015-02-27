/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsFdmApiDownloadImpl.h"
#include "DownloadsWnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFdmApiDownloadImpl::vmsFdmApiDownloadImpl()
{

}

vmsFdmApiDownloadImpl::~vmsFdmApiDownloadImpl()
{

}

vmsFdmApiDownloadState vmsFdmApiDownloadImpl::getState()
{
	if (m_dld->dwFlags & DLD_WAS_DELETED)
		return FADS_WAS_DELETED;

	if (m_dld->pMgr->IsRunning ())
	{
		if (m_dld->pMgr->IsDownloading ())
			return FADS_DOWNLOADING;

		if (m_dld->pMgr->IsCantStart () == FALSE)
			return FADS_STARTING;

		return FADS_HAVING_ERROR;
	}

	if (m_dld->pMgr->IsDone ())
		return FADS_FINISHED;

	return m_dld->bAutoStart ? FADS_QUEUED : FADS_STOPPED;
}

void vmsFdmApiDownloadImpl::PerformCommand(vmsFdmApiDownloadCommand enCmd)
{
	if (m_dld->dwFlags & DLD_WAS_DELETED)
		return;

	switch (enCmd)
	{
	case FADC_START:
	{
		DLDS_LIST v; v.push_back (m_dld);
		_DldsMgr.StartDownloads (v, TRUE);
		return;
	}

	case FADC_STOP:
	{
		DLDS_LIST v; v.push_back (m_dld);
		_DldsMgr.StopDownloads (v, TRUE);
		return;
	}

	case FADC_RESTART:
		_pwndDownloads->RestartDownload (m_dld, FALSE);
		return;

	case FADC_OPEN_FOLDER:
		m_dld->pMgr->Do_OpenFolder ();
		return;

	case FADC_LAUNCH_FILE:
		_DldsMgr.LaunchDownload (m_dld);
		return;
	}
}

void vmsFdmApiDownloadImpl::DeleteDownload(BOOL bAskConfirmation)
{
	_pwndDownloads->DeleteDownload (m_dld, bAskConfirmation ? TRUE : FALSE, FALSE);
}

void vmsFdmApiDownloadImpl::DeleteFileOnDisk()
{
	m_dld->pMgr->DeleteFile ();
}

void vmsFdmApiDownloadImpl::getFileName(LPSTR pszFileName)
{
	strcpy (pszFileName, m_dld->pMgr->get_OutputFilePathName ());
}

void vmsFdmApiDownloadImpl::getUrl(LPSTR pszUrl)
{
	strcpy (pszUrl, m_dld->pMgr->get_URL ());
}

float vmsFdmApiDownloadImpl::getProgress()
{
	return (float)((double)(__int64)m_dld->pMgr->GetDownloadedBytesCount () / (__int64)m_dld->pMgr->GetLDFileSize ());
}

UINT vmsFdmApiDownloadImpl::getId()
{
	return m_dld->nID;
}
