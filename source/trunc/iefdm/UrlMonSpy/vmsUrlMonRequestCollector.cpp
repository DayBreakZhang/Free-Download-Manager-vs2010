/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "vmsUrlMonRequestCollector.h"
#include <WinInet.h>
#include "../../Include.Add/vmsBrowsersSharedData.h"
#include "../../Include.Add/vmsInternetExplorerVersion.h"

LPCSTR vmsUrlMonRequestCollector::_protocolData_pData = "PROTOCOLDATA";
PROTOCOLDATA vmsUrlMonRequestCollector::_protocolData = {PD_FORCE_SWITCH, 0, (LPVOID)_protocolData_pData, 13};

vmsBrowsersSharedData _BrowsersSharedData;
vmsInternetExplorerVersion _IEVersion;

vmsUrlMonRequestCollector::vmsUrlMonRequestCollector(void)
{
	
	m_hevShutdown = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_htJob = CreateThread (NULL, 0, _threadJob, this, 0, NULL);
}

vmsUrlMonRequestCollector::~vmsUrlMonRequestCollector(void)
{
	SetEvent (m_hevShutdown);
	WaitForSingleObject (m_htJob, INFINITE);
	CloseTimedoutRequests ();
}

void vmsUrlMonRequestCollector::onInternetProtocolRoot_Start(IInternetProtocolRoot *pProt, LPCWSTR pwszUrl, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI)
{
	RequestPtr r; r.CreateInstance ();
	r->wstrUrl = pwszUrl;
	r->spProt = pProt;
	r->spSink = pSink;
	r->spBindInfo = pInfo;
	r->grfPI = grfPI;
	onNewRequest (r);
}

void vmsUrlMonRequestCollector::onInternetProtocolRoot_Abort(IInternetProtocolRoot *pProt, HRESULT hrReason, DWORD dwOptions)
{
	vmsCriticalSectionAutoLock csal (&m_csReq);
	int nIndex = findRequestIndexByProtocol (pProt);
	ATLASSERT (nIndex != -1);
	if (nIndex == -1)
		return;
	Request *req = getRequest (nIndex);
}

void vmsUrlMonRequestCollector::onInternetProtocolRoot_Terminate(IInternetProtocolRoot *pProt, DWORD dwOptions)
{
	
}

void vmsUrlMonRequestCollector::onInternetProtocolEx_StartEx(IInternetProtocolEx *pProt, IUri *pUri, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI)
{
	RequestPtr r; r.CreateInstance ();
	r->spProt = pProt;
	r->spUri = pUri;
	r->spSink = pSink;
	r->spBindInfo = pInfo;
	r->grfPI = grfPI;
	CComBSTR bstr;
	pUri->GetAbsoluteUri (&bstr);
	r->wstrUrl = bstr;
	onNewRequest (r);
}

void vmsUrlMonRequestCollector::onNewRequest(Request *request)
{
	_BrowsersSharedData.ModifyActiveDownloadsCount (1);

	RemoveTooOldRequests ();

	request->dwTicksStarted = GetTickCount ();

	IServiceProviderPtr spSP (request->spSink);
	assert (spSP != NULL);
	if (spSP != NULL)
		spSP->QueryService (IID_IHttpNegotiate, IID_IHttpNegotiate, (void**)&request->spHttpNegotiate);

	request->dwthridStart = GetCurrentThreadId ();

	if (_IEVersion.m_appVersion.empty () || _IEVersion.m_appVersion [0] < 10)
	{
		BINDINFO bi; DWORD dwBindF;
		ZeroMemory (&bi, sizeof (bi));
		bi.cbSize = sizeof (bi);
		request->spBindInfo->GetBindInfo (&dwBindF, &bi);

		if (bi.dwBindVerb == BINDVERB_POST && bi.cbstgmedData)
		{
			
			if (bi.stgmedData.tymed == TYMED_HGLOBAL)
			{
				LPVOID pData = GlobalLock (bi.stgmedData.hGlobal);
				if (pData)
				{
					request->vbPostData.resize (bi.cbstgmedData);
					CopyMemory (&request->vbPostData [0], pData, bi.cbstgmedData);
					GlobalUnlock (bi.stgmedData.hGlobal);
				}
			}
		}
	}

	vmsCriticalSectionAutoLock csal (&m_csReq);
	m_vReq.push_back (request);

#ifdef SCL_ENABLE
	LOGsnl ("New request:");
	USES_CONVERSION;
	LOG (" URL: %s", W2CA (request->wstrUrl.c_str ()));
	LOG (" thridStart: %d", request->dwthridStart);
	LOG (" post data size: %d", request->vbPostData.size ());
#endif

	request->spSink->Switch (&_protocolData);
}

bool vmsUrlMonRequestCollector::onInternetProtocolRoot_Continue(IInternetProtocolRoot* pProt, PROTOCOLDATA* pProtocolData)
{
	if (pProtocolData == &_protocolData || 
			(pProtocolData->dwState == 0 && pProtocolData->pData == _protocolData_pData && pProtocolData->cbData == 13))
	{
		vmsCriticalSectionAutoLock csal (&m_csReq);
		int nIndex = findRequestIndexByProtocol (pProt);
		assert (nIndex != -1);
		if (nIndex == -1)
		{
			LOGsnl ("WARNING: no request found for pProt in onInternetProtocolRoot_Continue");
			return true;
		}
		Request *req = getRequest (nIndex);

		if (!req->dwthridContinue)
		{
			if (req->dwTicksCompleted)
				req->spProt = NULL;

			req->dwthridContinue = GetCurrentThreadId ();

#ifdef SCL_ENABLE
			LOGsnl ("Update for request:");
			USES_CONVERSION;
			LOG (" URL: %s", W2CA (req->wstrUrl.c_str ()));
			LOG (" thridContinue: %d", req->dwthridContinue);
#endif

			HMODULE hBhoDll = GetModuleHandle (_T ("iefdm2.dll"));
			if (hBhoDll)
			{
				typedef BSTR (WINAPI *FNfdmbho_getTabUrl) (DWORD dwThreadId);
				FNfdmbho_getTabUrl pfn = (FNfdmbho_getTabUrl)GetProcAddress (hBhoDll, "fdmbho_getTabUrl");
				if (pfn)
				{
					BSTR bstrTabUrl = pfn (req->dwthridContinue);
					if (!bstrTabUrl)
						bstrTabUrl = pfn (req->dwthridStart);
					if (bstrTabUrl)
					{
						req->wstrSrcTabUrl = bstrTabUrl;
						SysFreeString (bstrTabUrl);
					}
#ifdef SCL_ENABLE
					LOG (" SRC TAB URL: %s", req->wstrSrcTabUrl.empty () ? "<NOT_FOUND>" : W2CA (req->wstrSrcTabUrl.c_str ()));
#endif
				}
			}
		}
		return true;
	}

	return false;
}

int vmsUrlMonRequestCollector::findRequestIndexByProtocol(IUnknown* pProtocol) const
{
	assert (pProtocol != NULL);
	if (!pProtocol)
		return -1;
	for (size_t i = 0; i < m_vReq.size (); i++)
	{
		if (m_vReq [i]->spProt == pProtocol)
			return i;
	}
	return -1;
}

int vmsUrlMonRequestCollector::findRequestIndexByHttpNegotiate(IUnknown* pHN) const
{
	assert (pHN != NULL);
	if (!pHN)
		return -1;
	for (size_t i = 0; i < m_vReq.size (); i++)
	{
		if (m_vReq [i]->spHttpNegotiate == pHN)
			return i;
	}
	return -1;
}

int vmsUrlMonRequestCollector::findRequestIndexBySink(IUnknown* pSink) const
{
	assert (pSink != NULL);
	if (!pSink)
		return -1;
	for (size_t i = 0; i < m_vReq.size (); i++)
	{
		if (m_vReq [i]->spSink == pSink)
			return i;
	}
	return -1;
}

vmsUrlMonRequestCollector::Request* vmsUrlMonRequestCollector::getRequest(int nIndex)
{
	assert (nIndex >= 0 && nIndex < (int)m_vReq.size ());
	if (nIndex < 0 || nIndex >= (int)m_vReq.size ())
		return NULL;
	return m_vReq [nIndex];
}

void vmsUrlMonRequestCollector::onHttpNegotiate_BeginningTransaction(IHttpNegotiate* pHN, LPCWSTR szURL, LPCWSTR szHeaders, LPWSTR * pszAdditionalHeaders)
{
	
}

void vmsUrlMonRequestCollector::onHttpNegotiate_OnResponse(IHttpNegotiate* pHN, DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR* pszAdditionalRequestHeaders)
{
	vmsCriticalSectionAutoLock csal (&m_csReq);
	int nIndex = findRequestIndexByHttpNegotiate (pHN);
	if (nIndex == -1)
		return;
	Request *req = getRequest (nIndex);
	req->dwState |= Request::GotResponse;

	IWinInetHttpInfoPtr spWinInetHttpInfo (req->spProt);
	if (spWinInetHttpInfo != NULL)
	{
		DWORD dwSize = 0, dwFlags = 0;
		spWinInetHttpInfo->QueryInfo (HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS, 0, &dwSize, &dwFlags, 0);
		if (dwSize)
		{
			std::vector <char> vBuf (dwSize);
			LPSTR psz = &vBuf.front (); *psz = 0;
			spWinInetHttpInfo->QueryInfo (HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS, psz, &dwSize, &dwFlags, 0);
			req->strRequestHeaders = psz;
		}
		dwSize = 0; dwFlags = 0;
		spWinInetHttpInfo->QueryInfo (HTTP_QUERY_RAW_HEADERS_CRLF, 0, &dwSize, &dwFlags, 0);
		if (dwSize)
		{
			std::vector <char> vBuf (dwSize);
			LPSTR psz = &vBuf.front (); *psz = 0;
			spWinInetHttpInfo->QueryInfo (HTTP_QUERY_RAW_HEADERS_CRLF, psz, &dwSize, &dwFlags, 0);
			req->strResponseHeaders = psz;
		}
	}

	IWinInetInfoPtr spWinInetInfo (req->spProt);
	if (spWinInetInfo != NULL)
	{
		vector <char> vch; vch.resize (1000); vch [0] = 0;
		DWORD dwSize = vch.size ();
		HRESULT hr = spWinInetInfo->QueryOption (INTERNET_OPTION_URL, &vch[0], &dwSize);
		if (dwSize > vch.size ())
		{
			vch.resize (dwSize); vch [0] = 0;
			hr = spWinInetInfo->QueryOption (INTERNET_OPTION_URL, &vch[0], &dwSize);
		}
		if (SUCCEEDED (hr))
		{
			USES_CONVERSION;
			wstring wstr = A2CW (&vch[0]);
			if (wcscmp (wstr.c_str (), req->wstrUrl.c_str ()))
				req->wstrRedirectedUrl = wstr;
		}
	}
}

void vmsUrlMonRequestCollector::onInternetProtocolSink_ReportResult(IInternetProtocolSink *pSink, HRESULT hrResult, DWORD dwError, LPCWSTR szResult)
{
	vmsCriticalSectionAutoLock csal (&m_csReq);
	int nIndex = findRequestIndexBySink (pSink);
	ATLASSERT (nIndex != -1);
	if (nIndex == -1)
		return;
	Request *req = getRequest (nIndex);
	CloseRequest (req);
}

void vmsUrlMonRequestCollector::onInternetProtocolSink_ReportProgress(IInternetProtocolSink* pSink, ULONG ulStatusCode, LPCWSTR szStatusText)
{
#ifdef SCL_ENABLE
	{USES_CONVERSION;
	vmsCriticalSectionAutoLock csal (&m_csReq);
	int nIndex = findRequestIndexBySink (pSink);
	if (nIndex == -1)
		return;
	Request *req = getRequest (nIndex);
	LOGsnl ("Progress for request:");
	LOG (" URL: %s", W2CA (req->wstrUrl.c_str ()));
	LOG (" ulStatusCode: %d", ulStatusCode);
	LOG (" szStatusText: %s", W2CA (szStatusText));}
#endif

	if (ulStatusCode != BINDSTATUS_REDIRECTING)
		return;

	assert (szStatusText != NULL);
	if (!szStatusText)
		return;

	vmsCriticalSectionAutoLock csal (&m_csReq);
	int nIndex = findRequestIndexBySink (pSink);
	if (nIndex == -1)
		return;
	Request *req = getRequest (nIndex);

	req->wstrRedirectedUrl = szStatusText;

#ifdef SCL_ENABLE
	LOGsnl ("Update for request:");
	USES_CONVERSION;
	LOG (" URL: %s", W2CA (req->wstrUrl.c_str ()));
	LOG (" Redirecting to URL: %s", W2CA (szStatusText));
	LOG (" TICKCOUNT: %d", GetTickCount ());
#endif
}

void vmsUrlMonRequestCollector::onInternetProtocolSink_ReportData(IInternetProtocolSink* pSink, DWORD grfBSCF, ULONG ulProgress, ULONG ulProgressMax)
{
	vmsCriticalSectionAutoLock csal (&m_csReq);
	int nIndex = findRequestIndexBySink (pSink);
	if (nIndex == -1)
		return;
	Request *req = getRequest (nIndex);
	req->dwState |= Request::GotResponse;

#ifdef SCL_ENABLE
	USES_CONVERSION;
	LOGsnl ("Report data for request:");
	LOG (" URL: %s", W2CA (req->wstrUrl.c_str ()));
	LOG (" grfBSCF: %d", grfBSCF);
	LOG (" progress: %d", ulProgress);
	LOG (" progress max: %d", ulProgressMax);
#endif
}

void vmsUrlMonRequestCollector::CloseRequest(Request* request)
{
#ifdef SCL_ENABLE
	LOGsnl ("Close request:");
	USES_CONVERSION;
	LOG (" URL: %s", W2CA (request->wstrUrl.c_str ()));
#endif

	assert (!request->dwTicksCompleted);
	if (request->dwTicksCompleted)
		return;

	_BrowsersSharedData.ModifyActiveDownloadsCount (-1);

	request->dwTicksCompleted = GetTickCount ();
	request->spHttpNegotiate = NULL;
	request->spSink = NULL;
	request->spBindInfo = NULL;
	request->spUri = NULL;
	if (request->dwthridContinue)
		request->spProt = NULL; 
}

void vmsUrlMonRequestCollector::Lock(bool bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csReq);
	else 
		LeaveCriticalSection (&m_csReq);
}

int vmsUrlMonRequestCollector::getRequestCount(void) const
{
	return (int)m_vReq.size ();
}

void vmsUrlMonRequestCollector::RemoveTooOldRequests(void)
{
	vmsCriticalSectionAutoLock csal (&m_csReq);
	size_t cOld = 0;

	DWORD dwTicks = GetTickCount ();

	for (size_t i = 0; i < m_vReq.size (); i++, cOld++)
	{
		if (m_vReq [i]->dwTicksCompleted && 
				dwTicks - m_vReq [i]->dwTicksCompleted < 5*60*1000)
			break;
		if (dwTicks - m_vReq [i]->dwTicksStarted < 15*60*1000)
			break;
		if (!m_vReq [i]->dwTicksCompleted) 
			CloseRequest (m_vReq [i]);
	}

	if (cOld)
		m_vReq.erase (m_vReq.begin (), m_vReq.begin () + cOld);
}

DWORD WINAPI vmsUrlMonRequestCollector::_threadJob(LPVOID lp)
{
	vmsUrlMonRequestCollector *pthis = (vmsUrlMonRequestCollector*)lp;

	while (WaitForSingleObject (pthis->m_hevShutdown, 1*60*1000) == WAIT_TIMEOUT)
		pthis->CloseTimedoutRequests ();
	
	return 0;
}

void vmsUrlMonRequestCollector::CloseTimedoutRequests(void)
{
	vmsCriticalSectionAutoLock csal (&m_csReq);
	DWORD dwTicks = GetTickCount ();
	for (size_t i = 0; i < m_vReq.size (); i++)
	{
		if ((m_vReq [i]->dwState & Request::GotResponse) || m_vReq [i]->dwTicksCompleted)
			continue;
		if (dwTicks - m_vReq [i]->dwTicksStarted >= 2*60*1000)
			CloseRequest (m_vReq [i]);
	}
}
