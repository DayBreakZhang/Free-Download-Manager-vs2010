/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWinSockHttpTrafficCollector.h"
#include "vmsHttpParser.h"
#include "vmsZlibHelper.h"
#include "vmsHttpHelper.h"
#include "vmsWinSockHttpDlgTree.h"

extern LPCSTR strstrn (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc);

vmsWinSockHttpTrafficCollector::vmsWinSockHttpTrafficCollector(vmsHttpTrafficCollector *pHttpTraffic)
{
	assert (pHttpTraffic != NULL);
	m_pHttpTraffic = pHttpTraffic;
}

vmsWinSockHttpTrafficCollector::~vmsWinSockHttpTrafficCollector()
{
	
}

void vmsWinSockHttpTrafficCollector::OnDataSent(SOCKET s, const char *pData, int nLen)
{
	LOGFN ("vmsWinSockHttpTrafficCollector::OnDataSent");

	

	EnterCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);

	int nIndex = m_pHttpTraffic->FindDialogIndexBySocket (s);
	vmsHttpTrafficCollector::HttpDialogPtr spDlg;

	if (nIndex != -1)
	{
		spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];
		if (spDlg->enState >= vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_HEADERS)
		{
			m_pHttpTraffic->CloseDialog (spDlg);
			spDlg = NULL;
			nIndex = -1;
		}
	}

	LeaveCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);

	if (nIndex == -1)
	{
		
		if (nLen < 5)
		{
			LOGsnl (" too small size");
			return; 
		}
		if (strnicmp (pData, "GET ", 4) && strnicmp (pData, "POST ", 5))
		{
			LOGsnl (" not a GET or POST request");
			char *p = new char [nLen + 1];
			memcpy (p, pData, nLen);
			p [nLen] = 0;
			LOG ("  (contains: %s)", p);
			delete [] p;
			return; 
		}
		if (strstrn (pData, "HTTP/1.", nLen) == NULL)
		{
			LOGsnl (" HTTP/1. not found");
			return; 
		}
		
		
		spDlg = m_pHttpTraffic->CreateHttpDialogStore ();
		LOGsnl (" new dialog store is created.");
#ifdef _DEBUG
		spDlg->enProvider = vmsHttpTrafficCollector::HttpDialog::Provider::PROV_WINSOCK;
#endif
		spDlg->s = s;
		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_HEADERS;
		EnterCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);
		m_pHttpTraffic->m_vDialogsInProgress.push_back (spDlg);
		LeaveCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);
	}

	switch (spDlg->enState)
	{
	case vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_HEADERS:
	{
		LPCSTR pszHdrEnd = strstrn (pData, "\r\n\r\n", nLen);
		if (pszHdrEnd == NULL)
			spDlg->strRequestHeaders.append (pData, nLen);
		else
			spDlg->strRequestHeaders.append (pData, pszHdrEnd-pData+4);
		if (pszHdrEnd != NULL)
		{
			m_pHttpTraffic->onHttpRequestHdrsAvailable (spDlg);
			m_pHttpTraffic->ExtractRequestUrlFromSocket (spDlg);

			pszHdrEnd += 4;
			spDlg->enState = vmsHttpTrafficCollector::HttpDialog::REQUEST_HEADERS_SENT;

			if (pszHdrEnd-pData < nLen)
			{
				spDlg->enState = vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_BODY;
				int l = nLen-(pszHdrEnd-pData);
				if (l <= vmsHttpTrafficCollector::RequestBodyMaxSize)
				{
					spDlg->vbRequestBody.resize (l);
					if (l)
						CopyMemory (&spDlg->vbRequestBody[0], pszHdrEnd, l);
				}
				else
				{
					m_pHttpTraffic->DeleteDialogFromListByID (spDlg->nID);
					return;
				}
			}
		}
		break;
	}

	case vmsHttpTrafficCollector::HttpDialog::REQUEST_HEADERS_SENT:
		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_BODY;
		

	case vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_BODY:
	{
		int l = spDlg->vbRequestBody.size ();
		if (l + nLen <= vmsHttpTrafficCollector::RequestBodyMaxSize)
		{
			spDlg->vbRequestBody.resize (l + nLen);
			CopyMemory (&spDlg->vbRequestBody[l], pData, nLen);
		}
		else
		{
			m_pHttpTraffic->DeleteDialogFromListByID (spDlg->nID);
			return;
		}
		break;
	}

	default:
		assert (false); 
		return;
	}
}

void vmsWinSockHttpTrafficCollector::OnDataRcvd(SOCKET s, const char *pData, int nLen)
{
	LOGFN ("vmsWinSockHttpTrafficCollector::OnDataRcvd");

	

	EnterCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);

	int nIndex = m_pHttpTraffic->FindDialogIndexBySocket (s);
	if (nIndex == -1)
	{
		LOGsnl (" no dialog found for the specified socket");
		LeaveCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);
		return;
	}

	vmsHttpTrafficCollector::HttpDialogPtr spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];

	LeaveCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);

	assert (spDlg != NULL);

	if (!nLen)
	{
		if (spDlg->enState < vmsHttpTrafficCollector::HttpDialog::RESPONSE_HEADERS_RCVD)
			return;
		if (spDlg->nContentLength != _UI64_MAX)
			return; 
		m_pHttpTraffic->MoveDialogToCompleted (spDlg);
		return;
	}

	switch (spDlg->enState)
	{
	case vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_HEADERS:
		LOGsnl (" invalid dialog state");
		assert (false); 
		return;

	case vmsHttpTrafficCollector::HttpDialog::REQUEST_HEADERS_SENT:
	case vmsHttpTrafficCollector::HttpDialog::SENDING_REQUEST_BODY:
		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_HEADERS;
		

	case vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_HEADERS:
	{
		assert (spDlg->strResponseHeaders.empty () == false || strncmp (pData, "HTTP/", 5) == 0);
		LPCSTR pszHdrEnd = strstrn (pData, "\r\n\r\n", nLen);
		if (pszHdrEnd == NULL)
			spDlg->strResponseHeaders.append (pData, nLen);
		else
			spDlg->strResponseHeaders.append (pData, pszHdrEnd-pData+4);
		if (pszHdrEnd != NULL)
		{
			pszHdrEnd += 4;
			spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RESPONSE_HEADERS_RCVD;

			m_pHttpTraffic->onHttpResponseHdrsAvailable (spDlg);

			if (!m_pHttpTraffic->isNeedBody (spDlg))
			{
				m_pHttpTraffic->MoveDialogToCompleted (spDlg);
			}
			else if (pszHdrEnd-pData < nLen)
			{
				spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_BODY;
				int l = nLen-(pszHdrEnd-pData);
				spDlg->vbResponseBody.resize (l);
				if (l)
					CopyMemory (&spDlg->vbResponseBody[0], pszHdrEnd, l);
			}
		}
		break;
	}

	case vmsHttpTrafficCollector::HttpDialog::RESPONSE_HEADERS_RCVD:
		assert (spDlg->bSaveResponseBody || (spDlg->dwFlags & vmsHttpTrafficCollector::HttpDialog::CHECK_REAL_CONTENT_TYPE) != 0);
		spDlg->enState = vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_BODY;
		
		
	case vmsHttpTrafficCollector::HttpDialog::RECEIVING_RESPONSE_BODY:
		assert (spDlg->bSaveResponseBody || (spDlg->dwFlags & vmsHttpTrafficCollector::HttpDialog::CHECK_REAL_CONTENT_TYPE) != 0);
		int l; l = spDlg->vbResponseBody.size ();
		spDlg->vbResponseBody.resize (l + nLen);
		CopyMemory (&spDlg->vbResponseBody [l], pData, nLen);
		break;

	case vmsHttpTrafficCollector::HttpDialog::DONE:
		break; 
		
	default:
		assert (false); 
		return;
	}

	m_pHttpTraffic->onDataReceived (spDlg);
}

void vmsWinSockHttpTrafficCollector::OnBeforeCloseSocket(SOCKET s)
{
	LOGFN ("vmsWinSockHttpTrafficCollector::OnBeforeCloseSocket");

	EnterCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);

	int nIndex = m_pHttpTraffic->FindDialogIndexBySocket (s);
	if (nIndex != -1)
	{
		vmsHttpTrafficCollector::HttpDialogPtr spDlg = m_pHttpTraffic->m_vDialogsInProgress [nIndex];
		assert (spDlg != NULL);
		m_pHttpTraffic->CloseDialog (spDlg);		
	}

	for (size_t i = 0; i < m_pHttpTraffic->m_vCompletedDialogs.size (); i++)
	{
		if (m_pHttpTraffic->m_vCompletedDialogs [i]->s == s)
			m_pHttpTraffic->m_vCompletedDialogs [i]->s = INVALID_SOCKET;
	}

	LeaveCriticalSection (&m_pHttpTraffic->m_csModifyDialogsVector);
}

