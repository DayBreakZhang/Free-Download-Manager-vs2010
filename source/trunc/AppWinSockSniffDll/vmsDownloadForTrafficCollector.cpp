/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsDownloadForTrafficCollector.h"
#include <wininet.h>
#include "vmsWinInetHttpTrafficCollector.h"

vmsDownloadForTrafficCollector::vmsDownloadForTrafficCollector()
{

}

vmsDownloadForTrafficCollector::~vmsDownloadForTrafficCollector()
{

}

BOOL vmsDownloadForTrafficCollector::MakeDownload(LPCSTR pszUrl, vmsHttpTrafficCollector::HttpDialog::ResourceContentType enCT, 
			vmsHttpTrafficCollector *pTraffic, vmsWinSockHttpDlgTree *pDlgTree)
{
	LOGFN ("vmsDownloadForTrafficCollector::MakeDownload");

	if (!MakeWasteDownload (pszUrl))
		return FALSE;

	const vmsHttpTrafficCollector::HttpDialog *pDlg = 
		pTraffic->FindDialogByRequestUrl (pszUrl, enCT);

	if (pDlg == NULL)
	{
		pDlg = pTraffic->FindDialogByRequestUrl (pszUrl, enCT, false);
		if (pDlg)
		{
			pTraffic->FinishDialog (pDlg);
			pDlg = pTraffic->FindDialogByRequestUrl (pszUrl, enCT);
		}
	}
	
	if (pDlg != NULL)
	{
		pTraffic->MoveDialogToTop (pDlg);
		pDlgTree->MoveDialogToTop (pDlg);
	}

	return TRUE;
}

BOOL vmsDownloadForTrafficCollector::MakeWasteDownload(LPCSTR pszUrl)
{
	bool bHTTPS = !strnicmp (pszUrl, "https://", 8);
	HINTERNET hInet = InternetOpen ("Mozilla/4.05 [en] (WinXP; I)", INTERNET_OPEN_TYPE_PRECONFIG,
		NULL, NULL, 0);
	if (hInet == NULL)
		return FALSE;
	HINTERNET hFile = InternetOpenUrl (hInet, pszUrl, NULL, 0, INTERNET_FLAG_IGNORE_CERT_CN_INVALID | 
		INTERNET_FLAG_IGNORE_CERT_DATE_INVALID | INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP | 
		INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_UI | INTERNET_FLAG_RELOAD, NULL);
	if (hFile == NULL)
	{
		InternetCloseHandle (hInet);
		return FALSE;
	}
	BYTE ab [1024]; DWORD dw = 0; int iMaxSize = 200*1024/sizeof(ab);
	extern vmsWinInetHttpTrafficCollector _WinInetTrafficCollector;
	while (InternetReadFile (hFile, ab, sizeof (ab), &dw) && dw != 0 && --iMaxSize > 0)
	{
		if (bHTTPS)
			_WinInetTrafficCollector.OnInternetReadFile (hFile, ab, dw);
	}
	InternetCloseHandle (hFile);
	if (bHTTPS)
		_WinInetTrafficCollector.OnInternetCloseHandle (hFile);
	InternetCloseHandle (hInet);
	return TRUE;
}
