/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fum.h"
#include "fsUpdateMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsUpdateMgr::fsUpdateMgr(LPCSTR in_updateURL)
{
	m_strUpdateUrl = in_updateURL;
	m_newBuild = 0;
}

fsUpdateMgr::~fsUpdateMgr()
{

}

UPDATE_RESULT fsUpdateMgr::CheckForUpdates()
{
	char szTmpDir [MAX_PATH];
	GetTempPath (MAX_PATH, szTmpDir);
	char szTmpFile [MAX_PATH];
	GetTempFileName (szTmpDir, "wut", 0, szTmpFile);
  
	UPDATE_RESULT ur = UR_CONNECTION_ERROR;
	
	if (UrlDownloadToFile (m_strUpdateUrl, szTmpFile))
	{
		ur = UR_NO_FRESH_VERSION;

		HANDLE hFile = CreateFile (szTmpFile, GENERIC_READ, 0, NULL, OPEN_EXISTING,
			0, NULL);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			DWORD dw = GetFileSize (hFile, NULL);
			LPSTR pszFile = new char [dw + 1];
			ReadFile (hFile, pszFile, dw, &dw, NULL);
			pszFile [dw] = 0;
			CloseHandle (hFile);

			LPSTR psz = pszFile;

			char szVer [100];
			char szUrl [10000];

			m_newBuild = atoi (psz);
			while (*psz && *psz != '|')
				psz++;
			if (*psz)
				psz++;

			int i = 0;
			while (*psz && *psz != '|')
				szVer [i++] = *psz++;
			if (*psz)
				psz++;
			szVer [i] = 0;

			i = 0;
			while (*psz && *psz != '|')
				szUrl [i++] = *psz++;
			szUrl [i] = 0;

			if (m_newBuild > PRG_BUILD_NUMBER && m_strDistribUrl != "")
			{
				ur = UR_UPDATE_AVAILABLE;
				m_strDistribUrl = szUrl;
				m_strNewVer = szVer;
			}
			
			delete [] pszFile;
		}
	}

	DeleteFile (szTmpFile);

	return ur;
}

int fsUpdateMgr::GetNewBuildNumber()
{
	return m_newBuild;
}

BOOL fsUpdateMgr::DownloadUpdate(LPCSTR pszFile, int *piProgress)
{
	return UrlDownloadToFile (m_strDistribUrl, pszFile, piProgress);
}

LPCSTR fsUpdateMgr::GetNewVersion()
{
	return m_strNewVer;
}

BOOL fsUpdateMgr::UrlDownloadToFile(LPCSTR pszUrl, LPCSTR pszFile, int *piProgress)
{
	m_bNeedStop = FALSE;

	if (piProgress)
		*piProgress = 0;

	m_hInet = InternetOpen (PRG_AGENT_NAME, INTERNET_OPEN_TYPE_PRECONFIG,
		NULL, NULL, 0);
	if (m_hInet == NULL)
		return FALSE;

	HINTERNET m_hFile = InternetOpenUrl (m_hInet, pszUrl, NULL, 0, 
		INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_NO_UI | 
		INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_RELOAD, 0);
	if (m_hFile == NULL)
	{
		InternetCloseHandle (m_hInet);
		return FALSE;
	}

	if (m_bNeedStop)
		return FALSE;

	HANDLE hLocalFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hLocalFile == INVALID_HANDLE_VALUE)
	{
		InternetCloseHandle (m_hFile);
		InternetCloseHandle (m_hInet);
		return FALSE;
	}

	UINT nLen = UINT_MAX, nDownloaded = 0; DWORD dw = sizeof (nLen);
	HttpQueryInfo (m_hFile, HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER, 
		&nLen, &dw, NULL);

	BYTE ab [1000]; DWORD dwRead = 1;
	while (InternetReadFile (m_hFile, ab, sizeof (ab), &dwRead) && dwRead != 0)
	{
		if (m_bNeedStop)
			break;

		WriteFile (hLocalFile, ab, dwRead, &dwRead, NULL);
		nDownloaded += dwRead;
		if (piProgress)
			*piProgress = MulDiv (nDownloaded, 100, nLen);
	}

	CloseHandle (hLocalFile);
	InternetCloseHandle (m_hFile);
	InternetCloseHandle (m_hInet);

	if (dwRead != 0 || m_bNeedStop)
	{
		DeleteFile (pszFile);
		return FALSE;
	}

	return TRUE;
}

void fsUpdateMgr::Abort()
{
	m_bNeedStop = TRUE;
	InternetCloseHandle (m_hFile);
	InternetCloseHandle (m_hInet);
}
