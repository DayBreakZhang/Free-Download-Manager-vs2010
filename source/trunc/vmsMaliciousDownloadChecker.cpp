/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsMaliciousDownloadChecker.h"
#include "vmsSimpleFileDownloader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsMaliciousDownloadChecker::vmsMaliciousDownloadChecker()
{
	m_dldr = NULL;
	m_bNeedStop = false;
}

vmsMaliciousDownloadChecker::~vmsMaliciousDownloadChecker()
{

}

fsInternetResult vmsMaliciousDownloadChecker::Check(LPCSTR pszUrl)
{
	char szTmpPath [MY_MAX_PATH];
	char szTmpFile [MY_MAX_PATH];

	m_bNeedStop = false;

	GetTempPath (sizeof (szTmpPath), szTmpPath);
	GetTempFileName (szTmpPath, "fdm", 0, szTmpFile);

	
	CString strUrl;
	strUrl.Format ("http://fdm.freedownloadmanager.org/fromfdm/url.php?url=%s", EncodeUrl (pszUrl));

	
	vmsSimpleFileDownloader dldr;
	m_dldr = &dldr;
	if (m_bNeedStop) {
		DeleteFile (szTmpFile);
		return IR_S_FALSE;
	}
	dldr.Download (strUrl, szTmpFile);
	while (dldr.IsRunning ())
		Sleep (50);
	m_dldr = NULL;
	if (dldr.GetLastError () != IR_SUCCESS) {
		DeleteFile (szTmpFile);
		return dldr.GetLastError ();
	}
	if (m_bNeedStop) {
		DeleteFile (szTmpFile);
		return IR_S_FALSE;
	}

	
	HANDLE hFile = CreateFile (szTmpFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 
		FILE_FLAG_DELETE_ON_CLOSE, NULL);
	ASSERT (hFile != INVALID_HANDLE_VALUE);
	if (hFile == INVALID_HANDLE_VALUE) {
		DeleteFile (szTmpFile);
		return IR_ERROR;
	}

	char szBuf [1000];
	DWORD dwSize = 0;
	ReadFile (hFile, szBuf, sizeof (szBuf), &dwSize, NULL);
	CloseHandle (hFile);

	if (dwSize == 0)
	{
		
		
		m_cOpinions = 0;
		m_cMalOpinions = 0;
		m_fRating = 0;
		m_strVirusCheckResult = "";
	}
	else
	{
		
		

		szBuf [dwSize] = 0;

		char szVCR [10000];
		sscanf (szBuf, "%d %f %d %s", &m_cOpinions, &m_fRating, &m_cMalOpinions, szVCR);
		m_strVirusCheckResult = szVCR;
	}

	return IR_SUCCESS;
}

CString vmsMaliciousDownloadChecker::EncodeUrl(LPCSTR pszUrl)
{
	CString str;

	while (*pszUrl)
	{
		char c = *pszUrl++;
		if ((c >= 'a' && c <= 'z') ||
				(c >= 'A' && c <='Z') ||
				(c >= '0' && c <= '9'))
		{
			str += c;
		}
		else
		{
			
			
			char szHex [10];
			sprintf (szHex, "%%%x", (int)(BYTE)c);
			str += szHex;
		}
	}

	return str;
}

int vmsMaliciousDownloadChecker::get_OpinionTotalCount()
{
	return m_cOpinions;
}

int vmsMaliciousDownloadChecker::get_MaliciousOpinionCount()
{
	return m_cMalOpinions;
}

float vmsMaliciousDownloadChecker::get_AverageRating()
{
	return m_fRating;
}

LPCSTR vmsMaliciousDownloadChecker::get_VirusCheckResult()
{
	return m_strVirusCheckResult;
}

void vmsMaliciousDownloadChecker::Stop()
{
	m_bNeedStop = true;
	if (m_dldr)
		m_dldr->Stop ();
}
