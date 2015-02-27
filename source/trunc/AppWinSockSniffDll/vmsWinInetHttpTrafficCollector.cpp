/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWinInetHttpTrafficCollector.h"

vmsWinInetHttpTrafficCollector::vmsWinInetHttpTrafficCollector(vmsHttpTrafficCollector *pHttpTraffic)
{
	assert (pHttpTraffic != NULL);
	m_pHttpTraffic = pHttpTraffic;
}

vmsWinInetHttpTrafficCollector::~vmsWinInetHttpTrafficCollector()
{

}

void vmsWinInetHttpTrafficCollector::OnInternetReadFile(HINTERNET hFile, LPVOID lpBuffer, DWORD dwRead)
{
	EnterCriticalSection (&m_cs_vNonCacheHandles);
	bool bIgnore = findNonCacheHandleIndex (hFile) != -1;
	LeaveCriticalSection (&m_cs_vNonCacheHandles);
	if (bIgnore)
		return;

	m_pHttpTraffic->LockDialogsLists (true);

	vmsHttpTrafficCollector::HttpDialogPtr spDlg;
	
	int nIndex = m_pHttpTraffic->FindDialogIndexByWInetFile (hFile);
	if (nIndex == -1 && m_pHttpTraffic->FindDialogIndexByWInetFile (hFile, true) != -1)
	{
		m_pHttpTraffic->LockDialogsLists (false);
		return;
	}

	if (nIndex == -1)
	{
		INTERNET_DIAGNOSTIC_SOCKET_INFO sockInfo = {0}; DWORD dw = sizeof (sockInfo);
		sockInfo.Socket = INVALID_SOCKET;
		InternetQueryOption (hFile, INTERNET_OPTION_DIAGNOSTIC_SOCKET_INFO, &sockInfo, &dw);
		if (sockInfo.Socket != INVALID_SOCKET && 
				(m_pHttpTraffic->FindDialogIndexBySocket (sockInfo.Socket, false) != -1 ||
					m_pHttpTraffic->FindDialogIndexBySocket (sockInfo.Socket, true) != -1))
		{
			EnterCriticalSection (&m_cs_vNonCacheHandles);
			m_vNonCacheHandles.push_back (hFile);
			LeaveCriticalSection (&m_cs_vNonCacheHandles);
			m_pHttpTraffic->LockDialogsLists (false);
			return;
		}

		spDlg = m_pHttpTraffic->CreateHttpDialogStore ();
#ifdef _DEBUG
		spDlg->enProvider = vmsHttpTrafficCollector::HttpDialog::Provider::PROV_WININET;
#endif
		spDlg->s = sockInfo.Socket;
		spDlg->hWInetFile = hFile;
		spDlg->dwFlags |= vmsHttpTrafficCollector::HttpDialog::BODY_DECOMPRESSED;
		m_pHttpTraffic->ExtractRequestUrlFromWInetFile (spDlg);

		if (m_pHttpTraffic->FindDialogByRequestUrl (spDlg->strRequestUrl.c_str (), vmsHttpTrafficCollector::HttpDialog::ALL, false))
		{
			EnterCriticalSection (&m_cs_vNonCacheHandles);
			m_vNonCacheHandles.push_back (hFile);
			LeaveCriticalSection (&m_cs_vNonCacheHandles);
			m_pHttpTraffic->LockDialogsLists (false);
			return;
		}

		m_pHttpTraffic->ExtractHttpHeadersFromWInetFile (spDlg);
		EnterCriticalSection (&m_cs_vPostData);
		int nPdIndex = findPostDataIndex (hFile);
		if (nPdIndex != -1)
			spDlg->vbRequestBody = m_vPostData [nPdIndex].vbData;
		LeaveCriticalSection (&m_cs_vPostData);
		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RESPONSE_HEADERS_RCVD;
		m_pHttpTraffic->m_vDialogsInProgress.push_back (spDlg);

		if (!m_pHttpTraffic->isNeedBody (spDlg))
		{
			m_pHttpTraffic->MoveDialogToCompleted (spDlg);
			m_pHttpTraffic->LockDialogsLists (false);
			return;
		}

		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_BODY;
	}
	else
	{
		spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];
	}
	
	m_pHttpTraffic->LockDialogsLists (false);

	assert (lpBuffer != NULL);

	if (lpBuffer && dwRead)
	{
		assert (m_pHttpTraffic->isNeedBody (spDlg));
		int l; l = spDlg->vbResponseBody.size ();
		spDlg->vbResponseBody.resize (l + dwRead);
		CopyMemory (&spDlg->vbResponseBody [l], (LPBYTE)lpBuffer, dwRead);
		m_pHttpTraffic->onDataReceived (spDlg);
	}

	if (!dwRead)
	{
		
		
		
		CloseDialog (hFile);
	}
}

void vmsWinInetHttpTrafficCollector::OnInternetCloseHandle(HINTERNET hInternet)
{
	if (!hInternet)
		return;

	m_pHttpTraffic->LockDialogsLists (true);

	CloseDialog (hInternet);
	
	for (size_t i = 0; i < m_pHttpTraffic->m_vCompletedDialogs.size (); i++)
	{
		if (m_pHttpTraffic->m_vCompletedDialogs [i]->hWInetFile == hInternet)
			m_pHttpTraffic->m_vCompletedDialogs [i]->hWInetFile = NULL;
	}

	m_pHttpTraffic->LockDialogsLists (false);

	EnterCriticalSection (&m_cs_vPostData);
	int nIndex = findPostDataIndex (hInternet);
	if (nIndex != -1)
		m_vPostData.erase (m_vPostData.begin () + nIndex);
	LeaveCriticalSection (&m_cs_vPostData);

	EnterCriticalSection (&m_cs_vNonCacheHandles);
	nIndex = findNonCacheHandleIndex (hInternet);
	if (nIndex != -1)
		m_vNonCacheHandles.erase (m_vNonCacheHandles.begin () + nIndex);
	LeaveCriticalSection (&m_cs_vNonCacheHandles);
}

void vmsWinInetHttpTrafficCollector::OnSendPostData(HINTERNET hInet, LPVOID pData, DWORD dwSize)
{
	assert (hInet != NULL);
	assert (pData != NULL);
	assert (dwSize != 0);
	if (!hInet || !pData || !dwSize)
		return;
	if (dwSize > vmsHttpTrafficCollector::RequestBodyMaxSize)
		return;
	vmsCriticalSectionAutoLock al (&m_cs_vPostData);
#ifdef _DEBUG
	int nIndex = findPostDataIndex (hInet);
	assert (nIndex == -1);
#endif
	PostData pd; 
	pd.hRequest = hInet;
	pd.vbData.assign ((LPBYTE)pData, (LPBYTE)pData + dwSize);
	m_vPostData.push_back (pd);
}

int vmsWinInetHttpTrafficCollector::findPostDataIndex(HINTERNET hInet) const
{
	for (size_t i = 0; i < m_vPostData.size (); i++)
	{
		if (m_vPostData [i].hRequest == hInet)
			return i;
	}

	return -1;
}

int vmsWinInetHttpTrafficCollector::findNonCacheHandleIndex(HINTERNET hInet) const
{
	for (size_t i = 0; i < m_vNonCacheHandles.size (); i++)
	{
		if (m_vNonCacheHandles [i] == hInet)
			return i;
	}

	return -1;
}

void vmsWinInetHttpTrafficCollector::CloseDialog(HINTERNET hInet)
{
	m_pHttpTraffic->LockDialogsLists (true);
	
	int nIndex = m_pHttpTraffic->FindDialogIndexByWInetFile (hInet);

	if (nIndex != -1)
	{
		vmsHttpTrafficCollector::HttpDialogPtr spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];
		assert (spDlg != NULL);
		m_pHttpTraffic->CloseDialog (spDlg);
	}
	
	m_pHttpTraffic->LockDialogsLists (false);
}
