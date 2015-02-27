/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "fsInternetFileListMgr.h"
#include "inetutil.h"
#include "LoginDlg.h"
#include "fsSitesMgr.h"
#include "vmsLogger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsInternetFileListMgr::fsInternetFileListMgr()
{
	m_bThread = FALSE;
	m_pfnEvents = NULL;
	m_files = NULL;
	m_bConnected = FALSE;
	m_bAbort = FALSE;
	ReadSettings ();
}

fsInternetFileListMgr::~fsInternetFileListMgr()
{
	Free ();
}

fsInternetResult fsInternetFileListMgr::GetList(LPCSTR pszUrl, LPCSTR pszUser, LPCSTR pszPassword)
{
	if (IsRunning ())
		return IR_S_FALSE;

	if (pszUser)
	{
		
		if (m_strUser != pszUser || m_strPassword != pszPassword)
		{
			
			Free ();
			m_bConnected = FALSE;	
		}
	}

	
	if (m_bConnected == FALSE && m_server.IsFtpServer ())
		Free ();	

	
	int iIndex = FindFiles (pszUrl);
	if (iIndex == -1)
	{
		
		m_bAbort = FALSE;
		_strUrl = pszUrl;
		_strUser = pszUser;
		_strPassword = pszPassword;
		Start ();
	}
	else
	{
		m_files = m_vFiles [iIndex];
		m_bCurPathIsRoot = strcmp (GetCurrentPath (), "/") == 0 || strcmp (GetCurrentPath (), "\\") == 0;
		m_lastError = IR_SUCCESS;
		m_bConnected = TRUE;
		Event (FLME_DONE_FROM_CACHE);
	}

	return IR_SUCCESS;
}

void fsInternetFileListMgr::Stop(BOOL bWaitStop)
{
	m_bAbort = TRUE;

	try 
	{
		if (m_files)
			m_files->Abort ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetFileListMgr::Stop " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetFileListMgr::Stop unknown exception");
	}

	try 
	{
		m_server.CloseHandle ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetFileListMgr::Stop " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetFileListMgr::Stop unknown exception");
	}

	try 
	{
		m_session.CloseHandle ();
	}
	catch (const std::exception& ex)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetFileListMgr::Stop " + tstring(ex.what()));
	}
	catch (...)
	{
		ASSERT (FALSE);
		vmsLogger::WriteLog("fsInternetFileListMgr::Stop unknown exception");
	}

	m_bConnected = FALSE;

	while (m_bThread && bWaitStop)
		Sleep (5);
}

void fsInternetFileListMgr::Start()
{
	DWORD dw;
	m_bThread = TRUE;
	CloseHandle (CreateThread (NULL, 0, _threadGetList, this, 0, &dw));
}

DWORD WINAPI fsInternetFileListMgr::_threadGetList(LPVOID lp)
{
	fsInternetFileListMgr* pThis = (fsInternetFileListMgr*) lp;

	CString strProxy, strPUser, strPPassword;
	fsURL url;

	if (url.Crack (pThis->_strUrl) != IR_SUCCESS)
	{
		pThis->m_lastError = IR_BADURL;
		goto _lExit;
	}

	if (*url.GetHostName () == 0 || *url.GetPath () == 0)
	{
		pThis->m_lastError = IR_BADURL;
		goto _lExit;
	}

	if (*url.GetUserName ())
	{
		if (pThis->m_strUser != url.GetUserName ())
		{
			pThis->m_strUser = url.GetUserName ();
			pThis->m_strPassword = url.GetPassword ();
			pThis->Free (FALSE);
			pThis->m_bConnected = FALSE;
		}
	}
	else
	{
		if (pThis->m_strUser != pThis->_strUser)
		{
			if (pThis->_strUser != NULL || fsIsServersEqual (url.GetHostName (), pThis->m_server.GetServerName ()) == FALSE)
			{
				pThis->m_strUser = pThis->_strUser;
				pThis->m_strPassword = pThis->_strPassword;
				pThis->m_bConnected = FALSE;
			}
		}
	}

	pThis->m_bCurPathIsRoot = strcmp (url.GetPath (), "/") == 0 || strcmp (url.GetPath (), "\\") == 0;

_lConnect:

	
	
	if (pThis->m_bConnected == FALSE || 
		 FALSE == fsIsServersEqual (pThis->m_server.GetServerName (), url.GetHostName ()) || 
		 pThis->m_server.GetScheme () != url.GetInternetScheme () )
	{
		pThis->Free (FALSE);

		

		fsGetProxy (fsSchemeToNP (url.GetInternetScheme ()), strProxy, strPUser, strPPassword);

		pThis->m_session.Create (_App.Agent (), _App.InternetAccessType (), strProxy, 
			fsSchemeToNP (url.GetInternetScheme ()));
		pThis->m_session.SetProxyAuth (strPUser, strPPassword);
		pThis->m_session.SetTimeout (_App.Timeout ());
		pThis->m_server.Initialize (&pThis->m_session);
		pThis->m_server.UseFtpPassiveMode (pThis->m_bFtpPassiveMode);

		UINT cAttempts = _App.MaxAttempts ();

		do
		{
			pThis->Event (FLME_CONNECTING);

			
			
			pThis->m_lastError = pThis->m_server.Connect (pThis->_strUrl, pThis->m_strUser, pThis->m_strPassword, url.GetPort ());
			if (pThis->m_lastError != IR_SUCCESS)
			{
				if (pThis->m_lastError != IR_S_FALSE)
					pThis->Event (FLME_ERROR);
			}
			else
			{
				
				if (pThis->m_server.IsFtpServer ())
					pThis->Event (FLME_CONNECTED);
			}

			if (pThis->m_lastError != IR_SUCCESS)
			{
				if (pThis->m_lastError == IR_LOGINFAILURE || pThis->m_lastError == IR_INVALIDUSERNAME || 
					 pThis->m_lastError == IR_INVALIDPASSWORD)
				{
					

					fsSiteInfo *site = _SitesMgr.FindSite (url.GetHostName (), fsNPToSiteValidFor (fsSchemeToNP (url.GetInternetScheme ())));
					if (site && site->strUser)
					{
						CString strPass = site->strPassword ? site->strPassword : "";
						if (site->strUser != pThis->m_strUser || strPass != pThis->m_strPassword)
						{
							

							pThis->Event (FLME_TRYINGTOUSESITEMGRLOGIN);
							pThis->m_strUser = site->strUser;
							pThis->m_strPassword = strPass;
							continue;
						}
					}

					

					if (pThis->AskForLogin (url.GetHostName ()))
						continue;
					else
						break;
				}

				pThis->SleepInterval ();
			}

			cAttempts--;

			if (cAttempts == 0)
				break;
		}
		while (pThis->m_lastError != IR_SUCCESS && pThis->m_bAbort == FALSE);

		if (pThis->m_lastError == IR_SUCCESS && pThis->m_bAbort == FALSE)
		{
			if (pThis->m_server.IsFtpServer ())
			{
				pThis->m_bConnected = TRUE;
			}
		}
		else
		{
			pThis->Event (FLME_STOPPED);
			goto _lExit2;
		}
	}
	else if (pThis->m_server.IsFtpServer () == FALSE)
		pThis->Event (FLME_CONNECTING);

	UINT cAttempts;
	cAttempts = _App.MaxAttempts ();

	do
	{
		
		if (pThis->m_server.IsFtpServer ())
			pThis->Event (FLME_GETTINGLIST);

		fsnew1 (pThis->m_files, fsInternetURLFiles);
		pThis->m_files->SetHttpEventFunc (_HttpEvents, pThis);
		pThis->m_files->RetreiveInfoWhileGettingList (pThis->m_bRetreiveInfoWhileGettingList);
		
		pThis->m_lastError = pThis->m_files->GetList (&pThis->m_server, url.GetPath ());

		if (pThis->m_lastError == IR_S_REDIRECTED)
			pThis->m_lastError = IR_SUCCESS;
	
		if (pThis->m_lastError != IR_SUCCESS && pThis->m_lastError != IR_S_REDIRECTED)
		{
			fsInternetURLFiles *files = pThis->m_files;
			pThis->m_files = NULL;
			delete files;

			if (pThis->m_lastError != IR_S_FALSE)
				pThis->Event (FLME_ERROR);

			if (pThis->m_bAbort)
				break;

			switch (pThis->m_lastError)
			{
				case IR_CONNECTIONABORTED:
				case IR_LOSTCONNECTION:
					pThis->Event (FLME_CONNECTIONWASLOST_RESTORE);
					pThis->m_bConnected = FALSE;
					goto _lConnect;
				break;

				case IR_LOGINFAILURE:
				case IR_INVALIDUSERNAME:
				case IR_INVALIDPASSWORD:
					if (pThis->AskForLogin (url.GetHostName ()))
						goto _lConnect;
					else
					{
						pThis->Event (FLME_STOPPED);
						goto _lExit2;
					}
				break;
			}

			cAttempts--;

			if (cAttempts == 0 || pThis->m_bAbort)
				break;

			pThis->SleepInterval ();

			if (pThis->m_bAbort == FALSE)
				pThis->Event (FLME_CONNECTING);
		}
	}
	while (pThis->m_lastError != IR_SUCCESS && pThis->m_bAbort == FALSE);

	pThis->_strUrl = NULL;

	if (pThis->m_lastError == IR_SUCCESS)
		pThis->m_vFiles.add (pThis->m_files);
	else
	{
		pThis->Event (FLME_STOPPED);
		goto _lExit2;
	}

_lExit:

	if (pThis->m_lastError != IR_SUCCESS)
	{
		if (pThis->m_lastError != IR_S_FALSE)
			pThis->Event (FLME_ERROR);
	}
	else
		pThis->Event (FLME_DONE);

_lExit2:
	
	pThis->m_bThread = FALSE;

	return 0;
}

BOOL fsInternetFileListMgr::IsRunning()
{
	return m_bThread;
}

void fsInternetFileListMgr::SetEventsFunc(fsFileListMgrFunc pfn, LPVOID lpParam)
{
	m_pfnEvents = pfn;
	m_lpEventsParam = lpParam;
}

void fsInternetFileListMgr::Event(fsInternetFileListMgrEvent ev)
{
	if (m_pfnEvents)
		m_pfnEvents (this, ev, m_lpEventsParam);
}

fsInternetResult fsInternetFileListMgr::GetLastError()
{
	return m_lastError;
}

UINT fsInternetFileListMgr::GetFileCount()
{
	return m_files ? m_files->GetFileCount () : 0;
}

fsFileInfo* fsInternetFileListMgr::GetFileInfo(UINT uIndex)
{
	return m_files ? m_files->GetFileInfo (uIndex) : NULL;
}

BOOL fsInternetFileListMgr::IsCurrentPathRoot()
{
	return m_bCurPathIsRoot;
}

LPCSTR fsInternetFileListMgr::GetLastErrorDesc()
{
	return m_files ? m_files->GetLastError () : NULL;
}

int fsInternetFileListMgr::FindFiles(LPCSTR pszFilesUrl)
{
	fsURL url;

	if (m_vFiles.size () == 0)
		return -1;

	if (IR_SUCCESS != url.Crack (pszFilesUrl))
		return -1;

	if (stricmp (url.GetHostName (), m_server.GetServerName ()) || url.GetPort () != m_server.GetServerPort () ||
		 url.GetInternetScheme () != m_server.GetScheme ()  )
		return -1;

	if (m_strUser.Length ())
	{
		if (strcmp (url.GetUserName (), m_strUser) || strcmp (url.GetPassword (), m_strPassword))
			return -1;
	}

	for (int i = m_vFiles.size () - 1; i >= 0; i--)
	{
		if (strcmp (url.GetPath (), m_vFiles [i]->GetCurrentPath ()) == 0)
			return i;
	}

	return -1;
}

void fsInternetFileListMgr::Free(BOOL bStopBeforeFree)
{
	if (bStopBeforeFree)
		Stop ();

	m_files = NULL;

	for (int i = m_vFiles.size () - 1; i >= 0; i--)
		delete m_vFiles [i];
	m_vFiles.clear ();
}

LPCSTR fsInternetFileListMgr::GetCurrentPath()
{
	return m_files ? m_files->GetCurrentPath () : NULL;
}

fsInternetResult fsInternetFileListMgr::Refresh()
{
	if (m_files == NULL || IsRunning ())
		return IR_S_FALSE;

	fsString strUrl;

	GetCurrentUrl (strUrl);

	Free ();

	return GetList (strUrl, NULL, NULL);
}

fsInternetResult fsInternetFileListMgr::GoParentFolder()
{
	if (IsCurrentPathRoot () || m_files == NULL)
		return IR_S_FALSE;

	if (IsRunning ())
		return IR_S_FALSE;

	fsString strUrl;
	GetParentFolderUrl (strUrl);

	return GetList (strUrl, NULL, NULL);
}

fsInternetResult fsInternetFileListMgr::GoFolder(LPCSTR pszFolder)
{
	if (m_files == NULL)
		return IR_S_FALSE;

	if (IsRunning ())
		return IR_S_FALSE;

	fsString strUrl;
	FolderToUrl (pszFolder, strUrl);

	return GetList (strUrl, NULL, NULL);
}

fsInternetResult fsInternetFileListMgr::GetFullUrl(LPCSTR pszRelOrNotUrl, fsString &strUrl)
{
	fsURL url;

	if (m_files == NULL)
		return IR_S_FALSE;

	fsString strUrlCurrent;
	GetCurrentUrl (strUrlCurrent);

	char* pszRes;

	fsUrlToFullUrl (strUrlCurrent, pszRelOrNotUrl, &pszRes);

	strUrl = pszRes;
	delete [] pszRes;

	return IR_SUCCESS;
}

void fsInternetFileListMgr::GetCurrentUrl(fsString &strUrl, BOOL bIncludeUser, BOOL bIncludePassword)
{
	strUrl = "";

	if (m_files != NULL)
	{
		char szUrl [10000] = ""; DWORD dwLen = sizeof (szUrl);
		fsURL url;
		if (IR_SUCCESS == url.Create (m_server.GetScheme (), m_server.GetServerName (), m_server.GetServerPort (),
				bIncludeUser ? m_strUser : NULL, bIncludePassword ? m_strPassword : NULL, m_files->GetCurrentPath (), szUrl, &dwLen))
			strUrl = szUrl;
	}
}

void fsInternetFileListMgr::SleepInterval()
{
	if (m_bAbort)
		return;

	int uInterval = _App.RetriesTime ();

	Event (FLME_PAUSE);

	while (uInterval > 0 && m_bAbort == FALSE)
	{
		Sleep (100);
		uInterval -= 100;
	}
}

void fsInternetFileListMgr::_HttpEvents(fsHttpFiles* , fsHttpFilesEvent enEvent, LPVOID lpParam)
{
	fsInternetFileListMgr *pThis = (fsInternetFileListMgr*) lpParam;

	switch (enEvent)
	{
		case HFE_CONNECTED:
			pThis->m_bConnected = TRUE;
			pThis->Event (FLME_CONNECTED);
			pThis->Event (FLME_GETTINGLIST);
			break;

		case HFE_FILELISTREAD:
			pThis->Event (FLME_HTTP_LISTREAD);
			break;

		case HFE_STARTBUILDLIST:
			pThis->Event (FLME_HTTP_STARTBUILDLIST);
			break;

		case HFE_FINISHBUILDLIST:
			pThis->Event (FLME_HTTP_FINISHBUILDLIST);
			break;
	}
}

BOOL fsInternetFileListMgr::AskForLogin(LPCSTR pszHostName)
{
	CLoginDlg dlg;

	dlg.m_strServer = pszHostName;
	dlg.m_strUser = m_strUser;
	dlg.m_strPassword = m_strPassword;

	if (IDCANCEL == dlg.DoModal ())
		return FALSE;

	m_strUser = dlg.m_strUser;
	m_strPassword = dlg.m_strPassword;

	return TRUE;
}

BOOL fsInternetFileListMgr::IsConnected()
{
	return m_bConnected;
}

void fsInternetFileListMgr::RetreiveInfoWhileGettingList(BOOL b)
{
	m_bRetreiveInfoWhileGettingList = b;
}

BOOL fsInternetFileListMgr::RetreiveInfoWhileGettingList()
{
	return m_bRetreiveInfoWhileGettingList;
}

void fsInternetFileListMgr::FtpPassiveMode(BOOL b)
{
	m_bFtpPassiveMode = b;
}

void fsInternetFileListMgr::Disconnect()
{
	m_bConnected = FALSE;
	m_server.CloseHandle ();
	Free (FALSE);
}

void fsInternetFileListMgr::ReadSettings()
{
	m_bRetreiveInfoWhileGettingList = _App.RetreiveInfoWhileGettingList ();
	m_bFtpPassiveMode = _App.HFE_FtpPassiveMode ();
}

void fsInternetFileListMgr::FolderToUrl(LPCSTR pszFolder, fsString &strUrl)
{
	strUrl = "";

	char* pszRes;

	GetCurrentUrl (strUrl);
	fsUrlToFullUrl (strUrl, pszFolder, &pszRes);

	strUrl = pszRes;
	delete [] pszRes;

	int len = strUrl.Length ();
	if (len > 0 && strUrl [len - 1] != '\\' && strUrl [len - 1] != '/')
		strUrl += '/';
}

void fsInternetFileListMgr::GetParentFolderUrl(fsString &strUrl)
{
	GetCurrentUrl (strUrl);

	if (strUrl.IsEmpty ())
		return;

	

	int pos = strUrl.Length () - 2;

	while (pos > 0 && strUrl [pos] != '\\' && strUrl [pos] != '/')
		pos--;

	strUrl [pos+1] = 0;
}
