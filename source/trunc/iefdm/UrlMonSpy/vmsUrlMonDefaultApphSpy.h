/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsInterfaceHook.h"
#include "vmsUrlMonRequestCollector.h"

class vmsUrlMonDefaultApphSpy
{
public:
	vmsUrlMonDefaultApphSpy(void);
	virtual ~vmsUrlMonDefaultApphSpy(void);
	static bool Initialize(void);

public:
	static vmsUrlMonRequestCollector _Requests;

protected:
	static STDMETHODIMP InternetProtocolRoot_Start(IInternetProtocolRoot *pthis, LPCWSTR pwszUrl, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI, DWORD dwReserved);
	static vmsInterfaceHook _Hooks;
	static STDMETHODIMP InternetProtocolRoot_Terminate(IInternetProtocolRoot *pthis, DWORD dwOptions);
	static STDMETHODIMP InternetProtocolRoot_Abort(IInternetProtocolRoot *pthis, HRESULT hrReason, DWORD dwOptions);
	static STDMETHODIMP InternetProtocolEx_StartEx(IInternetProtocolEx *pthis, IUri *pUri, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI, DWORD dwReserved);
	static STDMETHODIMP InternetProtocolRoot_Continue(IInternetProtocolRoot* pProt, PROTOCOLDATA* pProtocolData);
	static STDMETHODIMP HttpNegotiate_BeginningTransaction(IHttpNegotiate* pthis, LPCWSTR szURL, LPCWSTR szHeaders, DWORD dwReserved, LPWSTR * pszAdditionalHeaders);
	static STDMETHODIMP HttpNegotiate_OnResponse(IHttpNegotiate* pthis, DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR* pszAdditionalRequestHeaders);
	static STDMETHODIMP InternetProtocolSink_ReportResult(IInternetProtocolSink *pthis, HRESULT hrResult, DWORD dwError, LPCWSTR szResult);
	static STDMETHODIMP InternetProtocolSink_ReportProgress(IInternetProtocolSink* pthis, ULONG ulStatusCode, LPCWSTR szStatusText);
	static STDMETHODIMP InternetProtocolSink_ReportData(IInternetProtocolSink* pthis, DWORD grfBSCF, ULONG ulProgress, ULONG ulProgressMax);
};

