/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsDownloader.h"
#include "..\fsDownloadRegSaver.h"

#define DNP_COPY(a,b) SAFE_DELETE_ARRAY (m_dldr.GetDNP ()->a);\
	m_dldr.GetDNP ()->a = new char [lstrlen (b) + 1];\
	lstrcpy (m_dldr.GetDNP ()->a, b);

vmsDownloader::vmsDownloader() : 
	m_dldr (NULL),
	m_irLastError(IR_SUCCESS)
{
	m_dldr.SetEventFunc (_DownloadMgrEvents, this);
	m_dldr.SetEventDescFunc (NULL, 0);
	m_enState = D_S_STOPPED;
}

vmsDownloader::~vmsDownloader()
{

}

DWORD vmsDownloader::_DownloadMgrEvents(fsDownloadMgr *pMgr, fsDownloaderEvent ev, UINT uInfo, LPVOID lp)
{
	vmsDownloader* pthis = (vmsDownloader*) lp;

	switch (ev)
	{
	case DE_STARTINGDOWNLOAD:
	case DE_STARTINGDOWNLOAD_CONNECTING:
	case DE_CONNECTING:
		pthis->m_enState = D_S_CONNECTING;
		break;

	case DE_SECTIONSTARTED:
	case DE_SECTDOWNLOADING:
		if (pMgr->GetDownloader ()->GetRunningSectionCount ())
			pthis->m_enState = D_S_DOWNLOADING;
		break;

	case DE_EXTERROR:
		if (uInfo == DMEE_STOPPEDORDONE)
		{
			if (pMgr->IsDone ()) {
				pthis->m_enState = D_S_DONE;
			} else {
				pthis->m_enState = D_S_FAILED;
				pthis->m_irLastError = pMgr->GetLastError();
			}
		}
		break;

	case DE_STARTINGDOWNLOAD_FAILEDTOCONNECT:
	case DE_FAILCONNECT:
	case DE_ERROROCCURED:
	case DE_WRITEERROR:
	case DE_ERRFROMSERVER:
		pthis->m_enState = D_S_ERROR_NOW;
		break;
	}

	return TRUE;
}

fsInternetResult vmsDownloader::Initialize(LPCSTR pszURL, LPCSTR pszOutFile)
{
	fsInternetResult ir = m_dldr.CreateByUrl (pszURL, TRUE);
	if (ir != IR_SUCCESS) {
		m_irLastError = ir;
		return ir;
	}

	fsDownload_Properties *dp = m_dldr.GetDP ();

	SAFE_DELETE_ARRAY (dp->pszFileName);

	dp->pszFileName = new char [lstrlen (pszOutFile) + 1];
	lstrcpy (dp->pszFileName, pszOutFile);
	dp->uMaxSections = 1;
	dp->uMaxAttempts = UINT_MAX;
	dp->enAER = AER_REWRITE;
	*dp->pszAdditionalExt = 0;

	return IR_SUCCESS;
}

void vmsDownloader::StartDownloading()
{
	if (m_dldr.IsRunning ())
		return;
	m_enState = D_S_CONNECTING;
	m_dldr.StartDownloading ();
}

void vmsDownloader::StopDownloading()
{
	m_dldr.StopDownloading ();
}

vmsDownloader_State vmsDownloader::get_State()
{
	return m_enState;
}

fsInternetResult vmsDownloader::get_LastError()
{
	return m_irLastError;
}

tstring vmsDownloader::get_LastErrorMessage()
{
	tstring sMsg;

	if (m_irLastError == IR_S_FALSE && m_dldr.IsFailedToCreateDestinationFile()) {
		TCHAR szMsg[1024] = {0,};
		_stprintf_s(szMsg, 1024, _T("Cannot create the destionation file (Path: '%s'). There might be another downloader uses a file with an identical path. In this case, in order to retry downloading please exit the wizard and launch it again after other one finishes working."), m_dldr.GetDP()->pszFileName ? m_dldr.GetDP()->pszFileName : _T(""));
		return tstring(szMsg);
	}

	fsIRToStr(m_irLastError, sMsg);
	return sMsg;
}

int vmsDownloader::get_Progress()
{
	return (int)m_dldr.GetDownloader ()->GetPercentDone ();
}

UINT vmsDownloader::get_Speed()
{
	return m_dldr.GetDownloader ()->GetSpeed ();
}

UINT64 vmsDownloader::get_FileSize()
{
	return m_dldr.GetDownloader ()->GetSSFileSize ();
}

UINT64 vmsDownloader::get_DownloadedByteCount()
{
	return m_dldr.GetDownloader ()->GetDownloadedBytesCount ();
}

void vmsDownloader::set_MaxRetryCount(int nMax)
{
	m_dldr.GetDP ()->uMaxAttempts = nMax;
}

void vmsDownloader::set_RetriesTime(int nTime)
{
	m_dldr.GetDP ()->uRetriesTime = nTime;
}

void vmsDownloader::set_Timeout(UINT u)
{
	m_dldr.GetDP ()->uTimeout = u;
}

void vmsDownloader::set_Proxy(LPCSTR pszProxy, LPCSTR pszUserName, LPCSTR pszPassword)
{
	if (pszProxy == NULL)
	{
		m_dldr.GetDNP ()->enAccType = IATE_NOPROXY;
		return;
	}

	if (pszUserName == NULL)
		pszUserName = "";
	if (pszPassword == NULL)
		pszPassword = "";

	DNP_COPY (pszProxyName, pszProxy);
	DNP_COPY (pszProxyUserName, pszUserName);
	DNP_COPY (pszProxyPassword, pszPassword);

	m_dldr.GetDNP ()->enAccType = IATE_MANUALPROXY;
}

void vmsDownloader::set_DisableCookies(BOOL bDisable)
{
	m_dldr.GetDNP ()->bUseCookie = !bDisable;
}

void vmsDownloader::set_UserAgent(LPCSTR pszAgent)
{
	DNP_COPY (pszAgent, pszAgent);
}

void vmsDownloader::set_MaxSections(UINT uiMaxSections)
{
	m_dldr.GetDP()->uMaxSections = uiMaxSections;
}

void vmsDownloader::set_MinSectionSize (UINT uiMinSectionSize)
{
	m_dldr.GetDP()->uSectionMinSize = uiMinSectionSize;
}

LPCTSTR vmsDownloader::getDstFilePathName(void)
{
	return m_dldr.GetDP ()->pszFileName;
}

LPCSTR vmsDownloader::getContentType(void)
{
	return m_dldr.GetDownloader ()->GetContentType ();
}

void vmsDownloader::fsIRToStr (fsInternetResult ir, tstring& sMsg)
{
	switch (ir)
	{
		case IR_WININETUNKERROR:
		case IR_ERROR:
			sMsg = "Unknown network error";
			break;

		case IR_LOGINFAILURE:
			sMsg = "Access denied. Invalid user name or password";
			break;

		case IR_INVALIDPASSWORD:
			sMsg = "Access denied. Invalid password";
			break;

		case IR_SUCCESS:
			sMsg = "Succeeded";
			break;

		case IR_CANTCONNECT:
			sMsg = "Can't connect to the server";
			break;

		case IR_FILENOTFOUND:
			sMsg = "File not found on the server";
			break;

		case IR_LOSTCONNECTION:
			sMsg = "Connection with the server was lost";
			break;

		case IR_TIMEOUT:
			sMsg = "Server does not respond";
			break;

		case IR_NAMENOTRESOLVED:
			sMsg = "Unable to resolve the server name";
			break;

		case IR_RANGESNOTAVAIL:
			sMsg = "Server does not support download resuming. Don't stop this download; otherwise you'll have to start it from the beginning";
			break;

		case IR_DOUBTFUL_RANGESRESPONSE:
			sMsg = "Server can not guarantee its resuming capabilities. Response is invalid.";
			break;

		case IR_PROXYAUTHREQ:
			sMsg = "Proxy user name and password are required";
			break;

		case IR_EXTERROR:
			sMsg = "Extended error";
			break;

		case IR_SERVERBADREQUEST:
			sMsg = "Bad request. Possibly this is a bad URL";
			break;

		case IR_SERVERUNKERROR:
			sMsg = "Unknown server error";
			break;

		case IR_CONNECTIONABORTED:
			sMsg = "Connection aborted";
			break;

		case IR_BADURL:
			sMsg = "Bad URL";
			break;

		case IR_NOINTERNETCONNECTION:
			sMsg = "No Internet connection";
			break;

		case IR_HTTPVERNOTSUP:
			sMsg = "Selected HTTP version is not supported by this server";
			break;

		default:
			sMsg = "Unknown error";
	}
}

void vmsDownloader::DumpDownload(LPBYTE pbBuffer, LPDWORD pdwSize)
{
	if (!pdwSize)
		return;

	m_dldr.SaveState(pbBuffer, pdwSize);

}

bool vmsDownloader::RestoreDownload(LPBYTE pbBuffer, LPDWORD pdwSize, DWORD dwVer)
{
	return m_dldr.LoadState(pbBuffer, pdwSize, dwVer) ? true : false;
}

void vmsDownloader::SetResumeMode()
{
	fsDownload_Properties *dp = m_dldr.GetDP ();
	dp->enAER = AER_RESUME;
}

bool vmsDownloader::IsDone()
{
	return m_dldr.IsDone();
}

std::string vmsDownloader::get_DestinationFile()
{
	fsDownload_Properties *dp = m_dldr.GetDP ();
	std::string sDestinationFile = dp->pszFileName ? dp->pszFileName : _T("");
	return sDestinationFile;
}
