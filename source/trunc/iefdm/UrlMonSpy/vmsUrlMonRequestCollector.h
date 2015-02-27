/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsObject.h"

class vmsUrlMonRequestCollector
{
public:
	struct Request;
	typedef vmsObjectSmartPtr <Request> RequestPtr;
	struct Request : public vmsObject
	{
		enum State
		{
			
			GotResponse			= 1,
		};
		wstring wstrUrl, wstrRedirectedUrl;
		wstring wstrSrcTabUrl;
		IUriPtr spUri;
		IInternetProtocolPtr spProt;
		IInternetProtocolSinkPtr spSink;
		IHttpNegotiatePtr spHttpNegotiate;
		IInternetBindInfoPtr spBindInfo;
		DWORD grfPI;
		
		
		
		DWORD dwthridStart, dwthridContinue;
		string strRequestHeaders;
		string strResponseHeaders;
		vector <BYTE> vbPostData;
		DWORD dwTicksStarted, dwTicksCompleted;
		DWORD dwState;

		Request () 
		{
			
			dwthridStart = dwthridContinue = 0; 
			dwTicksStarted = dwTicksCompleted = 0;
			dwState = 0;
		}
	};
public:
	vmsUrlMonRequestCollector(void);
	~vmsUrlMonRequestCollector(void);

protected:
public:
	vector <RequestPtr> m_vReq;
	vmsCriticalSection m_csReq;
	static PROTOCOLDATA _protocolData;
	static LPCSTR _protocolData_pData;
public:
	void onInternetProtocolRoot_Start(IInternetProtocolRoot *pProt, LPCWSTR pwszUrl, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI);
	void onInternetProtocolEx_StartEx(IInternetProtocolEx *pProt, IUri *pUri, IInternetProtocolSink *pSink, IInternetBindInfo *pInfo, DWORD grfPI);
	void onInternetProtocolRoot_Abort(IInternetProtocolRoot *pProt, HRESULT hrReason, DWORD dwOptions);
	void onInternetProtocolRoot_Terminate(IInternetProtocolRoot *pProt, DWORD dwOptions);
	bool onInternetProtocolRoot_Continue(IInternetProtocolRoot* pProt, PROTOCOLDATA* pProtocolData);
	int findRequestIndexByProtocol(IUnknown* pProtocol) const;
	int findRequestIndexByHttpNegotiate(IUnknown* pHN) const;
	int findRequestIndexBySink(IUnknown* pSink) const;
	Request* getRequest(int nIndex);
	void onHttpNegotiate_BeginningTransaction(IHttpNegotiate* pHN, LPCWSTR szURL, LPCWSTR szHeaders, LPWSTR * pszAdditionalHeaders);
	void onHttpNegotiate_OnResponse(IHttpNegotiate* pHN, DWORD dwResponseCode, LPCWSTR szResponseHeaders, LPCWSTR szRequestHeaders, LPWSTR* pszAdditionalRequestHeaders);
protected:
	void onNewRequest(Request *request);
public:
	void onInternetProtocolSink_ReportResult(IInternetProtocolSink *pSink, HRESULT hrResult, DWORD dwError, LPCWSTR szResult);
	void onInternetProtocolSink_ReportProgress(IInternetProtocolSink* pSink, ULONG ulStatusCode, LPCWSTR szStatusText);
	void onInternetProtocolSink_ReportData(IInternetProtocolSink* pSink, DWORD grfBSCF, ULONG ulProgress, ULONG ulProgressMax);
protected:
	void CloseRequest(Request* request);
public:
	void Lock(bool bLock);
	int getRequestCount(void) const;
protected:
	void RemoveTooOldRequests(void);
	static DWORD WINAPI _threadJob(LPVOID lp);
	HANDLE m_htJob;
	HANDLE m_hevShutdown;
	void CloseTimedoutRequests(void);
};

