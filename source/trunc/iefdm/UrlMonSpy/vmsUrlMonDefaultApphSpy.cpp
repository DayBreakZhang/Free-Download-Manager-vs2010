/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "vmsUrlMonDefaultApphSpy.h"

vmsInterfaceHook vmsUrlMonDefaultApphSpy::_Hooks;
vmsUrlMonRequestCollector vmsUrlMonDefaultApphSpy::_Requests;

vmsUrlMonDefaultApphSpy::vmsUrlMonDefaultApphSpy(void)
{
}

vmsUrlMonDefaultApphSpy::~vmsUrlMonDefaultApphSpy(void)
{
}

bool vmsUrlMonDefaultApphSpy::Initialize(void)
{
	static bool _bInitialized = false;
	if (_bInitialized)
		return true;

	const IID* apIIDProtocol [] = {&CLSID_HttpProtocol, &CLSID_HttpSProtocol};

	for (int i = 0; i < sizeof (apIIDProtocol) / sizeof (IID*); i++)
	{
		IInternetProtocolRootPtr spProtocol;
		CoCreateInstance (*apIIDProtocol[i], NULL, CLSCTX_INPROC, IID_IInternetProtocol, (void**)&spProtocol);

		if (spProtocol)
		{
			_bInitialized = true;

			_Hooks.HookMethod (spProtocol, InternetProtocolRoot_Start, 3);
			_Hooks.HookMethod (spProtocol, InternetProtocolRoot_Continue, 4);
			
			

			IInternetProtocolExPtr spProtocolEx (spProtocol);
			if (spProtocolEx)
				_Hooks.HookMethod (spProtocolEx, InternetProtocolEx_StartEx, 13);

			spProtocol = NULL;
		}
	}

	return _bInitialized;
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolRoot_Start(IInternetProtocolRoot *pthis, LPCWSTR pwszUrl, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI, DWORD dwReserved)
{
	_Requests.onInternetProtocolRoot_Start (pthis, pwszUrl, pSink, pInfo, grfPI);

	typedef HRESULT (STDMETHODCALLTYPE *FNSTART)(IInternetProtocolRoot *pthis, LPCWSTR pwszUrl, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI, DWORD dwReserved);
	int nIndex = _Hooks.findHookIndex (pthis, 3);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	HRESULT hr = ((FNSTART)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, pwszUrl, pSink, pInfo, grfPI, dwReserved);
	LOG ("ProtocolRoot_Start hr = 0x%x", hr);
	return hr;
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolRoot_Abort(IInternetProtocolRoot *pthis, HRESULT hrReason, DWORD dwOptions)
{
	_Requests.onInternetProtocolRoot_Abort (pthis, hrReason, dwOptions);

	typedef HRESULT (STDMETHODCALLTYPE *FNABORT)(IInternetProtocolRoot *pthis, HRESULT, DWORD);
	int nIndex = _Hooks.findHookIndex (pthis, 5);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	return ((FNABORT)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, hrReason, dwOptions);
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolRoot_Terminate(IInternetProtocolRoot *pthis, DWORD dwOptions)
{
	_Requests.onInternetProtocolRoot_Terminate (pthis, dwOptions);

	typedef HRESULT (STDMETHODCALLTYPE *FNABORT)(IInternetProtocolRoot *pthis, DWORD);
	int nIndex = _Hooks.findHookIndex (pthis, 6);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	return ((FNABORT)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, dwOptions);
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolEx_StartEx(IInternetProtocolEx *pthis, IUri *pUri, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI, DWORD dwReserved)
{
	IServiceProviderPtr spSP (pSink);
	assert (spSP != NULL);
	if (spSP != NULL)
	{
		IHttpNegotiatePtr spHN;
		spSP->QueryService (IID_IHttpNegotiate, IID_IHttpNegotiate, (void**)&spHN);
		assert (spHN != NULL);
		if (spHN != NULL)
		{
			_Hooks.HookMethod (spHN, HttpNegotiate_BeginningTransaction, 3); 
			_Hooks.HookMethod (spHN, HttpNegotiate_OnResponse, 4);
		}
	}
	_Hooks.HookMethod (pSink, InternetProtocolSink_ReportProgress, 4);
	_Hooks.HookMethod (pSink, InternetProtocolSink_ReportData, 5);
	_Hooks.HookMethod (pSink, InternetProtocolSink_ReportResult, 6);

	_Requests.onInternetProtocolEx_StartEx (pthis, pUri, pSink, pInfo, grfPI);

	typedef HRESULT (STDMETHODCALLTYPE *FNSTARTEX)(IInternetProtocolEx *pthis, IUri *pUri, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI, DWORD dwReserved);
	int nIndex = _Hooks.findHookIndex (pthis, 13);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	HRESULT hr = ((FNSTARTEX)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, pUri, pSink, pInfo, grfPI, dwReserved);
	LOG ("ProtocolRoot_StartEx hr = 0x%x", hr);
	LOG ("ProtocolRoot_StartEx pSink = 0x%x", (DWORD)pSink);
	LOG ("ProtocolRoot_StartEx pInfo = 0x%x", (DWORD)pInfo);
	LOG ("ProtocolRoot_StartEx pUri = 0x%x", (DWORD)pUri);
	LOG ("ProtocolRoot_StartEx grfPI = 0x%x", (DWORD)grfPI);
	return hr;
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolRoot_Continue(IInternetProtocolRoot* pthis, PROTOCOLDATA* pProtocolData)
{
	if (_Requests.onInternetProtocolRoot_Continue (pthis, pProtocolData))
		return S_OK;

	typedef HRESULT (STDMETHODCALLTYPE *FNCONT)(IInternetProtocolRoot *pthis, PROTOCOLDATA*);
	int nIndex = _Hooks.findHookIndex (pthis, 4);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	return ((FNCONT)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, pProtocolData);
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::HttpNegotiate_BeginningTransaction(IHttpNegotiate* pthis, LPCWSTR szURL, LPCWSTR szHeaders, DWORD dwReserved, LPWSTR * pszAdditionalHeaders)
{
	typedef HRESULT (STDMETHODCALLTYPE *FNBT)(IHttpNegotiate* pthis, LPCWSTR szURL, LPCWSTR szHeaders, DWORD dwReserved, LPWSTR * pszAdditionalHeaders);
	int nIndex = _Hooks.findHookIndex (pthis, 3);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	HRESULT hr = ((FNBT)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, szURL, szHeaders, dwReserved, pszAdditionalHeaders);
	
	_Requests.onHttpNegotiate_BeginningTransaction (pthis, szURL, szHeaders, pszAdditionalHeaders);

	return hr;
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::HttpNegotiate_OnResponse(IHttpNegotiate* pthis, DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR* pszAdditionalRequestHeaders)
{
	typedef HRESULT (STDMETHODCALLTYPE *FNRESP)(IHttpNegotiate* pthis, DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR* pszAdditionalRequestHeaders);
	int nIndex = _Hooks.findHookIndex (pthis, 4);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	HRESULT hr = ((FNRESP)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, dwResponseCode, szResponseHeaders, szRequestHeaders, pszAdditionalRequestHeaders);
	
	_Requests.onHttpNegotiate_OnResponse (pthis, dwResponseCode, szResponseHeaders, szRequestHeaders, pszAdditionalRequestHeaders);

	return hr;
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolSink_ReportResult(IInternetProtocolSink *pthis, HRESULT hrResult, DWORD dwError, LPCWSTR szResult)
{
	_Requests.onInternetProtocolSink_ReportResult (pthis, hrResult, dwError, szResult);

	typedef HRESULT (STDMETHODCALLTYPE *FNRR)(IInternetProtocolSink *pthis, HRESULT hrResult, DWORD dwError, LPCWSTR szResult);
	int nIndex = _Hooks.findHookIndex (pthis, 6);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	return ((FNRR)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, hrResult, dwError, szResult);
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolSink_ReportProgress(IInternetProtocolSink* pthis, ULONG ulStatusCode, LPCWSTR szStatusText)
{
	_Requests.onInternetProtocolSink_ReportProgress (pthis, ulStatusCode, szStatusText);

	typedef HRESULT (STDMETHODCALLTYPE *FNRP)(IInternetProtocolSink *pthis, ULONG ulStatusCode, LPCWSTR szStatusText);
	int nIndex = _Hooks.findHookIndex (pthis, 4);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	return ((FNRP)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, ulStatusCode, szStatusText);
}

STDMETHODIMP vmsUrlMonDefaultApphSpy::InternetProtocolSink_ReportData(IInternetProtocolSink* pthis, DWORD grfBSCF, ULONG ulProgress, ULONG ulProgressMax)
{
	_Requests.onInternetProtocolSink_ReportData (pthis, grfBSCF, ulProgress, ulProgressMax);

	typedef HRESULT (STDMETHODCALLTYPE *FNRD)(IInternetProtocolSink* pthis, DWORD grfBSCF, ULONG ulProgress, ULONG ulProgressMax);
	int nIndex = _Hooks.findHookIndex (pthis, 5);
	assert (nIndex != -1);
	if (nIndex == -1)
		return E_UNEXPECTED;
	return ((FNRD)_Hooks.getHook (nIndex)->pvOriginalFn) (pthis, grfBSCF, ulProgress, ulProgressMax);
}
