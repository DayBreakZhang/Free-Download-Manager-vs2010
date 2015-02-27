/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsSimpleFileDownloader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSimpleFileDownloader::vmsSimpleFileDownloader()
{
	m_dldr = NULL;
}

vmsSimpleFileDownloader::~vmsSimpleFileDownloader()
{
	SAFE_DELETE (m_dldr);
}

fsInternetResult vmsSimpleFileDownloader::Download(LPCSTR pszUrl, LPCSTR pszFileName)
{
	if (IsRunning ())
		return IR_S_FALSE;

	CreateDownloader ();

	fsInternetResult ir = m_dldr->CreateByUrl (pszUrl);
	if (ir != IR_SUCCESS)
		return ir;

	fsDownload_Properties *dp = m_dldr->GetDP ();

	SAFE_DELETE_ARRAY (dp->pszFileName);
	fsnew (dp->pszFileName, char, lstrlen (pszFileName) + 1);
	strcpy (dp->pszFileName, pszFileName);
	dp->uMaxSections = 1;
	dp->uMaxAttempts = 1;
	dp->dwFlags |= DPF_DONTRESTARTIFNORESUME;
	dp->enSCR = SCR_STOP;
	dp->enAER = AER_REWRITE;
	*dp->pszAdditionalExt = 0;

	ir = m_dldr->StartDownloading ();
	if (ir != IR_SUCCESS)
		return ir;

	return IR_SUCCESS;
}

void vmsSimpleFileDownloader::_DownloadMgrDescEvents(fsDownloadMgr *, fsDownloadMgr_EventDescType, LPCSTR pszDesc, LPVOID lp)
{

}

DWORD vmsSimpleFileDownloader::_DownloadMgrEvents(fsDownloadMgr *pMgr, fsDownloaderEvent ev, UINT uInfo, LPVOID lp)
{
	vmsSimpleFileDownloader *pthis = (vmsSimpleFileDownloader*) lp;

	switch (ev)
	{
		case DE_EXTERROR:
			if (uInfo == DMEE_STOPPEDORDONE)
			{
				if (pthis->m_dldr->IsDone () == FALSE)
					pthis->m_dldr->DeleteFile ();
			}
		break;
	}

	return TRUE;
}

void vmsSimpleFileDownloader::CreateDownloader()
{
	SAFE_DELETE (m_dldr);
	fsnew1 (m_dldr, fsDownloadMgr (NULL));
	m_dldr->SetEventFunc (_DownloadMgrEvents, this);
	m_dldr->SetEventDescFunc (_DownloadMgrDescEvents, this);
}

bool vmsSimpleFileDownloader::IsRunning()
{
	return m_dldr ? m_dldr->HasActivity () != 0 : FALSE;
}

fsInternetResult vmsSimpleFileDownloader::GetLastError()
{
	return m_dldr->GetLastError ();
}

void vmsSimpleFileDownloader::Stop()
{
	if (m_dldr)
		m_dldr->StopDownloading ();
}
