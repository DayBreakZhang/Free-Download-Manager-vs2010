/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsWinSockHttpTrafficCollector.h"
#include "vmsSniffDllWnd.h"
#include "vmsBrowserCachedFlvTrafficCollector.h"
#include "vmsHttpFlvTrafficAnalyzer2.h"
#include "vmsHttpFlvTrafficAnalyzer3.h"
#include "vmsHttpFlvTrafficAnalyzer4.h"
#include "vmsDownloadForTrafficCollector.h"
#include "vmsHttpFlvTrafficAnalyzer5.h"
#include "vmsTransferFlvDownloadsToFdm.h"
#include "vmsWinInetHttpTrafficCollector.h"
#include "vmsExternalHttpTrafficCollector.h"
#include "vmsFindFlvDownloadsResultsCache.h"
#include <WinInet.h>
#include <shellapi.h>
#include "vmsBrowserSpecialInfo.h"
#include "vmsUrlMonSpyDll.h"
#include <dbghelp.h>
#include "vmsOverlappedWinsockCalls.h"
#include "../Include.Add/vmsAsyncTaskMgr.h"
#include "vmsFindFlvDownloadsResultsCacheAsyncRequest.h"

HMODULE _hModule = NULL;

vmsHttpTrafficCollector _HttpTraffic;
vmsWinSockHttpTrafficCollector _WinSockTrafficCollector (&_HttpTraffic);
vmsWinInetHttpTrafficCollector _WinInetTrafficCollector (&_HttpTraffic);
vmsExternalHttpTrafficCollector _ExternalTrafficCollector (&_HttpTraffic);
vmsFindFlvDownloadsResultsCache _FlvResCache (&_HttpTraffic, &vmsWinSockHttpDlgTree::o ());
vmsOverlappedWinsockCalls _WinsockAsyncCalls;
vmsAsyncTaskMgr _AsyncTasks;

LPCSTR strstrn (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc)
{
	assert (lenSrc > 0);
	assert (pszSrch && *pszSrch != 0);
	if (pszSrch == NULL || *pszSrch == 0 || lenSrc == 0)
		return NULL;
	int lSrch = strlen (pszSrch);
	lenSrc -= lSrch;
	while (lenSrc >= 0)
	{
		if (strncmp (pszSrc, pszSrch, lSrch) == 0)
			return pszSrc;
		pszSrc++;
		lenSrc--;
	}
	return NULL;
}

LPCSTR strstrni (LPCSTR pszSrc, LPCSTR pszSrch, int lenSrc)
{
	assert (lenSrc > 0);
	assert (pszSrch && *pszSrch != 0);
	if (pszSrch == NULL || *pszSrch == 0 || lenSrc == 0)
		return NULL;
	int lSrch = strlen (pszSrch);
	lenSrc -= lSrch;
	while (lenSrc >= 0)
	{
		if (strnicmp (pszSrc, pszSrch, lSrch) == 0)
			return pszSrc;
		pszSrc++;
		lenSrc--;
	}
	return NULL;
}

HMODULE WINAPI Detoured ()
{
	
	return GetModuleHandle ("detoured.dll");
}

int (WINAPI *Real_WSASend)(SOCKET a0, LPWSABUF a1, DWORD a2, LPDWORD a3, DWORD a4, LPWSAOVERLAPPED a5, LPWSAOVERLAPPED_COMPLETION_ROUTINE a6) = WSASend;
int (WINAPI *Real_send)(SOCKET a0, CONST char* a1, int a2, int a3) = send;

int (WINAPI *Real_WSARecv)(SOCKET a0, LPWSABUF a1, DWORD a2, LPDWORD a3, LPDWORD a4, LPWSAOVERLAPPED a5, LPWSAOVERLAPPED_COMPLETION_ROUTINE a6) = WSARecv;
int (WINAPI *Real_recv)(SOCKET a0, char* a1, int a2, int a3) = recv;

int (WINAPI * Real_closesocket)(SOCKET a0) = closesocket;

BOOL (WINAPI *Real_HttpSendRequestA)(HINTERNET, LPCSTR, DWORD, LPVOID, DWORD) = HttpSendRequestA;
BOOL (WINAPI *Real_HttpSendRequestW)(HINTERNET, LPCWSTR, DWORD, LPVOID, DWORD) = HttpSendRequestW;
BOOL (WINAPI *Real_InternetReadFile)(HINTERNET, LPVOID, DWORD, LPDWORD) = InternetReadFile;
BOOL (WINAPI *Real_InternetCloseHandle)(HINTERNET) = InternetCloseHandle;

BOOL (WSAAPI *Real_WSAGetOverlappedResult)(SOCKET, LPWSAOVERLAPPED, LPDWORD, BOOL, LPDWORD) = WSAGetOverlappedResult;

int WINAPI my_send (SOCKET s, const char FAR* buf, int len, int flags)
{
	int rv = SOCKET_ERROR;
	try {
		rv = Real_send (s, buf, len, flags);
	}
	catch (...) {}

	if (rv != SOCKET_ERROR)
		_WinSockTrafficCollector.OnDataSent (s, buf, rv);

	return rv;
}

void CALLBACK my_WinsockCompletionRoutine (DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags)
{
	_WinsockAsyncCalls.LockList (true);
	int iCall = _WinsockAsyncCalls.FindCallIndex (INVALID_SOCKET, lpOverlapped);
	const vmsOverlappedWinsockCalls::Call *pCall = NULL;
	if (iCall != -1)
		pCall = _WinsockAsyncCalls.getCall (iCall);
	assert (pCall != NULL);
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine = NULL;
	if (pCall)
	{
		assert (pCall->lpCompletionRoutine);
		lpCompletionRoutine = pCall->lpCompletionRoutine;

		if (dwError == 0)
		{
			DWORD dwBytesTransferred = cbTransferred;
			for (size_t i = 0; i < pCall->vBuffers.size () && dwBytesTransferred != 0; i++)
			{
				DWORD dwL = min (dwBytesTransferred, pCall->vBuffers [i].len);
				if (pCall->bSend)
					_WinSockTrafficCollector.OnDataSent (pCall->s, pCall->vBuffers [i].buf, dwL);
				else
					_WinSockTrafficCollector.OnDataRcvd (pCall->s, pCall->vBuffers [i].buf, dwL);
				dwBytesTransferred -= dwL;
			}
		}

		_WinsockAsyncCalls.RemoveCall (iCall);
	}

	_WinsockAsyncCalls.LockList (false);

	lpCompletionRoutine (dwError, cbTransferred, lpOverlapped, dwFlags);
}

BOOL WSAAPI my_WSAGetOverlappedResult (SOCKET s, LPWSAOVERLAPPED lpOverlapped, LPDWORD lpcbTransfer, BOOL fWait, LPDWORD lpdwFlags)
{
	BOOL bResult = FALSE;
	try{
		bResult = Real_WSAGetOverlappedResult (s, lpOverlapped, lpcbTransfer, fWait, lpdwFlags);
	}
	catch (...) {assert (false); return FALSE;}

	if (bResult)
	{
		_WinsockAsyncCalls.LockList (true);
		int iCall = _WinsockAsyncCalls.FindCallIndex (s, lpOverlapped);
		const vmsOverlappedWinsockCalls::Call *pCall = NULL;
		if (iCall != -1)
			pCall = _WinsockAsyncCalls.getCall (iCall);
		if (pCall)
		{
			assert (lpcbTransfer != NULL);
			DWORD dwBytesTransferred = lpcbTransfer ? *lpcbTransfer : 0;
			for (size_t i = 0; i < pCall->vBuffers.size () && dwBytesTransferred != 0; i++)
			{
				DWORD dwL = min (dwBytesTransferred, pCall->vBuffers [i].len);
				if (pCall->bSend)
					_WinSockTrafficCollector.OnDataSent (s, pCall->vBuffers [i].buf, dwL);
				else
					_WinSockTrafficCollector.OnDataRcvd (s, pCall->vBuffers [i].buf, dwL);
				dwBytesTransferred -= dwL;
			}
			_WinsockAsyncCalls.RemoveCall (iCall);
		}
		_WinsockAsyncCalls.LockList (false);
	}
	else if (WSAGetLastError () != WSA_IO_INCOMPLETE)
	{
		_WinsockAsyncCalls.LockList (true);
		int iCall = _WinsockAsyncCalls.FindCallIndex (s, lpOverlapped);
		if (iCall != -1)
			_WinsockAsyncCalls.RemoveCall (iCall);
		_WinsockAsyncCalls.LockList (false);
	}

	return bResult;
}

int WINAPI my_WSASend (SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, 
					   LPDWORD lpNumberOfBytesSent, DWORD dwFlags, 
					   LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
{
	int rv = SOCKET_ERROR;
	try {
		rv = Real_WSASend (s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpCompletionRoutine);
	}
	catch (...) {return SOCKET_ERROR;}

	if (rv == SOCKET_ERROR)
	{
		if (WSAGetLastError () == WSA_IO_PENDING)
			_WinsockAsyncCalls.AddCall (s, lpBuffers, dwBufferCount, lpOverlapped, lpCompletionRoutine, true);
	}
	else
	{
		if (lpNumberOfBytesSent)
		{
			DWORD dwBytesSent = *lpNumberOfBytesSent;
			for (int i = 0; i < dwBufferCount && dwBytesSent != 0; i++)
			{
				DWORD dwL = min (dwBytesSent, lpBuffers [i].len);
				_WinSockTrafficCollector.OnDataSent (s, lpBuffers [i].buf, dwL);
				dwBytesSent -= dwL;
			}
		}
	}

	return rv;
}

int WINAPI my_recv (SOCKET s, char* buf, int len, int flags)
{
	int rv = SOCKET_ERROR;
	try {
		rv = Real_recv (s, buf, len, flags);
	}
	catch (...) {}

	if (rv != SOCKET_ERROR)
		_WinSockTrafficCollector.OnDataRcvd (s, buf, rv);

	return rv;
}

int WINAPI my_WSARecv (SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd,
                        LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine)
{
	int rv = SOCKET_ERROR;
	try {
		rv = Real_WSARecv (s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpOverlapped, lpCompletionRoutine);
	}
	catch (...) {return SOCKET_ERROR;}

	assert (rv == 0 || rv == SOCKET_ERROR);

	if (rv == SOCKET_ERROR)
	{
		if (WSAGetLastError () == WSA_IO_PENDING)
			_WinsockAsyncCalls.AddCall (s, lpBuffers, dwBufferCount, lpOverlapped, lpCompletionRoutine, false);
	}
	else
	{
		if (lpNumberOfBytesRecvd)
		{
			DWORD dwBytesRecvd = *lpNumberOfBytesRecvd;

			for (int i = 0; i < dwBufferCount && dwBytesRecvd != 0; i++)
			{
				DWORD dwL = min (dwBytesRecvd, lpBuffers [i].len);
				if (dwL)
					_WinSockTrafficCollector.OnDataRcvd (s, lpBuffers [i].buf, dwL);
				dwBytesRecvd -= dwL;
			}
		}
	}
	
	return rv;
}

int WINAPI my_closesocket (SOCKET s)
{
	_WinSockTrafficCollector.OnBeforeCloseSocket (s);
	return Real_closesocket (s);
}

BOOL WINAPI my_InternetReadFile (HINTERNET hFile, LPVOID lpBuffer, DWORD dwToRead, LPDWORD pdwRead)
{
	assert (pdwRead != NULL);
	assert (dwToRead != 0);
	BOOL bResult = Real_InternetReadFile (hFile, lpBuffer, dwToRead, pdwRead);
	if (bResult && dwToRead && pdwRead)
		_WinInetTrafficCollector.OnInternetReadFile (hFile, lpBuffer, *pdwRead);
	return bResult;
}

BOOL WINAPI my_InternetCloseHandle (HINTERNET hInternet)
{
	_WinInetTrafficCollector.OnInternetCloseHandle (hInternet);
	return Real_InternetCloseHandle (hInternet);
}

BOOL WINAPI my_HttpSendRequestA (HINTERNET hRequest, LPCSTR pszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength)
{
	if (dwOptionalLength)
		_WinInetTrafficCollector.OnSendPostData (hRequest, lpOptional, dwOptionalLength);
	return Real_HttpSendRequestA (hRequest, pszHeaders, dwHeadersLength, lpOptional, dwOptionalLength);
}

BOOL WINAPI my_HttpSendRequestW (HINTERNET hRequest, LPCWSTR pwszHeaders, DWORD dwHeadersLength, LPVOID lpOptional, DWORD dwOptionalLength)
{
	if (dwOptionalLength)
		_WinInetTrafficCollector.OnSendPostData (hRequest, lpOptional, dwOptionalLength);
	return Real_HttpSendRequestW (hRequest, pwszHeaders, dwHeadersLength, lpOptional, dwOptionalLength);
}

void DetourAPIs (bool bDetour)
{
	LONG (WINAPI *DetourFN)(PVOID*, PVOID) = bDetour ? DetourAttach : DetourDetach;
	
	DetourTransactionBegin ();
	DetourUpdateThread (GetCurrentThread ());
	DetourFN ((PVOID*)&Real_send, my_send);
	DetourFN ((PVOID*)&Real_WSASend, my_WSASend);
	DetourFN ((PVOID*)&Real_recv, my_recv);
	DetourFN ((PVOID*)&Real_WSARecv, my_WSARecv);
	DetourFN ((PVOID*)&Real_HttpSendRequestA, my_HttpSendRequestA);
	DetourFN ((PVOID*)&Real_HttpSendRequestW, my_HttpSendRequestW);
	DetourFN ((PVOID*)&Real_InternetReadFile, my_InternetReadFile);
	DetourFN ((PVOID*)&Real_InternetCloseHandle, my_InternetCloseHandle);
	DetourFN ((PVOID*)&Real_WSAGetOverlappedResult, my_WSAGetOverlappedResult);
	DetourFN ((PVOID*)&Real_closesocket, my_closesocket);
	DetourTransactionCommit ();	
}

DWORD WINAPI _threadFlvSniffDllWnd (LPVOID)
{
	Sleep (3000);
	vmsSniffDllWnd wnd;
	wnd.Create ();
	MSG msg;
	while (GetMessage (&msg, NULL, 0, 0))
		DispatchMessage (&msg);
	return 0;
}

void CreateFlvSniffDllWnd ()
{
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadFlvSniffDllWnd, NULL, 0, &dw));
}

HANDLE _hevShuttingDown = CreateEvent (NULL, TRUE, FALSE, NULL);
HANDLE _htTrafficCollectorCleanuper = NULL;

DWORD WINAPI _threadTrafficCollectorCleanuper (LPVOID)
{
	
	const int RECHECK_INTERVAL = 10;
	const int HTTPTRAFF_KEEPDLGSTIME = 10;
	const int DLGTREE_KEEPDLGSTIME = 15;
	const int DLGTREE_KEEPWEBPAGESANDFLVSTIME = 2*60;

	while (WaitForSingleObject (_hevShuttingDown, RECHECK_INTERVAL * 60 * 1000) == WAIT_TIMEOUT)
	{
		_HttpTraffic.RemoveAllDialogsOlderWhen (HTTPTRAFF_KEEPDLGSTIME * 60);
		vmsWinSockHttpDlgTree::o ().RemoveAllDialogsOlderWhen (DLGTREE_KEEPDLGSTIME * 60, DLGTREE_KEEPWEBPAGESANDFLVSTIME * 60);
	}
	
	return 0;
}

#ifdef LOG_WEBFILES_TREE
void log_webfiles_init ()
{
	TCHAR tszPath [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszPath);
	_tcscat (tszPath, _T ("\\fdmflvsniff"));

	SHFILEOPSTRUCT sfos = {0};
	sfos.wFunc = FO_DELETE;
	sfos.pFrom = tszPath;
	sfos.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;
	SHFileOperation (&sfos);
}
void log_webfiles_init2 ()
{
	TCHAR tszPath [MAX_PATH] = _T ("");
	GetTempPath (MAX_PATH, tszPath);
	_tcscat (tszPath, _T ("\\fdmflvsniff"));
		
	CreateDirectory (tszPath, NULL);
	
	_tcscat (tszPath, _T ("\\webfiles"));
	CreateDirectory (tszPath, NULL);
}
#endif

LPTOP_LEVEL_EXCEPTION_FILTER _pfnOriginalUEF = NULL;
LONG WINAPI _UEF (_EXCEPTION_POINTERS* info)
{
	HMODULE hDll = LoadLibrary (_T ("dbghelp.dll"));
	if (hDll)
	{
		typedef BOOL (WINAPI *FNMDWD)(HANDLE, DWORD, HANDLE, MINIDUMP_TYPE, 
			PMINIDUMP_EXCEPTION_INFORMATION, PMINIDUMP_USER_STREAM_INFORMATION, PMINIDUMP_CALLBACK_INFORMATION);
		FNMDWD pfnMiniDumpWriteDump = (FNMDWD) GetProcAddress (hDll, "MiniDumpWriteDump");
		if (pfnMiniDumpWriteDump)
		{
			MINIDUMP_EXCEPTION_INFORMATION eInfo;
			eInfo.ThreadId = GetCurrentThreadId();
			eInfo.ExceptionPointers = info;
			eInfo.ClientPointers = FALSE;
			
			TCHAR tszFile [MAX_PATH]; TCHAR tszName [100];
			_tcscpy (tszName, _T ("fdmflvsniff.dmp"));
			GetTempPath (MAX_PATH, tszFile);
			_tcscat (tszFile, tszName);
			HANDLE hFile = CreateFile (tszFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
			
			
			pfnMiniDumpWriteDump(
				GetCurrentProcess(),
				GetCurrentProcessId(),
				hFile,
				MiniDumpNormal,
				&eInfo,
				NULL,
				NULL);
			
			CloseHandle (hFile);

			MessageBox (NULL, _T ("Crashed. Dump has been written to %tmp%\\fdmflvsniff.dmp"), NULL, MB_ICONEXCLAMATION);
		}
	}
	return  _pfnOriginalUEF ? _pfnOriginalUEF (info) : EXCEPTION_EXECUTE_HANDLER;
}

#include <atlbase.h>

DWORD WINAPI _threadInitialize (LPVOID)
{
	#ifdef LOG_WEBFILES_TREE
		log_webfiles_init ();
	#endif

	DWORD dwOverrideUEF = FALSE;
	try {
		CRegKey key;
		if (ERROR_SUCCESS == key.Open (HKEY_CURRENT_USER, _T ("Software\\FreeDownloadManager.ORG\\Free Download Manager\\Debug"), KEY_READ))
			key.QueryDWORDValue (_T ("FlvSniffOverrideUEF"), dwOverrideUEF);
	}
	catch (...) {}
	if (dwOverrideUEF)
		SetUnhandledExceptionFilter (_UEF);

	vmsUrlMonSpyDll::MakeSureDllLoaded ();
	return 0;
}

BOOL APIENTRY DllMain( HANDLE hModule, 
					  DWORD  ul_reason_for_call, 
					  LPVOID lpReserved
					  )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		_hModule = (HMODULE)hModule;

		DWORD dw;
		CloseHandle  (
			CreateThread (NULL, 0, _threadInitialize, NULL, 0, &dw));
	
		DetourAPIs (true);
		CreateFlvSniffDllWnd ();

		_htTrafficCollectorCleanuper = CreateThread (NULL, 0, _threadTrafficCollectorCleanuper, NULL, 0, &dw);
	}
	
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		SetEvent (_hevShuttingDown);
		DetourAPIs (false);
		WaitForSingleObject (_htTrafficCollectorCleanuper, INFINITE);
	}
	
    return TRUE;
}

#if defined (LOG_WEBFILES_TREE) || defined (SCL_ENABLE)
LONG _cInOnGetItBtnClicked = 0;
#endif

HRESULT WINAPI onGetItBtnClicked3 (LPCSTR pszUrl, LPCSTR pszFrameUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars, LPCSTR pszOtherSwfUrls, LPCSTR pszOtherFlashVars)
{
	LOGFN ("onGetItBtnClicked3");

#ifdef LOG_WEBFILES_TREE
	InterlockedIncrement (&_cInOnGetItBtnClicked);
#endif

	vmsFindFlvDownloadsResultsCache::ResultPtr result;
	HRESULT hr = _FlvResCache.FindFlvDownloads (pszUrl, pszFrameUrl, pszSwfUrl, pszFlashVars, pszOtherSwfUrls, 
		pszOtherFlashVars, result);

#ifdef LOG_WEBFILES_TREE
	InterlockedDecrement (&_cInOnGetItBtnClicked);
#endif

	if (hr != S_OK)
		return hr;

	assert (result->pTa->get_FlvDownloadCount () != 0);
	if (!result->pTa->get_FlvDownloadCount ())
		return S_FALSE;
	
	return vmsTransferFlvDownloadsToFdm::Do (pszUrl, result->pTa->getFlvDownloads ());
}

HRESULT WINAPI onGetItBtnClicked2 (LPCSTR pszUrl, LPCSTR pszSwfUrl, LPCSTR pszFlashVars)
{
	return onGetItBtnClicked3 (pszUrl, NULL, pszSwfUrl, pszFlashVars, NULL, NULL);
}

HRESULT WINAPI onGetItBtnClicked (LPCSTR pszUrl)
{
	return onGetItBtnClicked2 (pszUrl, NULL, NULL);
}

BOOL WINAPI isVideoFlash (LPCSTR pszWebPageUrl, LPCSTR pszFrameUrl, 
						  LPCSTR pszSwfUrl, LPCSTR pszFlashVars,
						  LPCSTR pszOtherSwfUrls, LPCSTR pszOtherFlashVars)
{
	LOGFN ("isVideoFlash");
	LOG (" Page URL: %s", pszWebPageUrl);
	LOG (" Frame URL: %s", pszFrameUrl);
	LOG (" Swf URL: %s", pszSwfUrl);
	LOG (" Flash Vars: %s", pszFlashVars);
	LOG (" Other Swf URLs: %s", pszOtherSwfUrls);
	LOG (" OtherFlashVars: %s", pszOtherFlashVars);
	
	vmsFindFlvDownloadsResultsCache::ResultPtr result;

	_FlvResCache.CheckNeedCacheReset ();
	result = _FlvResCache.FindResult (pszWebPageUrl, pszFrameUrl, pszSwfUrl, pszFlashVars);

	if (result)
		return result->pTa->get_FlvDownloadCount () != 0;

	vmsFindFlvDownloadsResultsCacheAsyncRequest *pRequest = new vmsFindFlvDownloadsResultsCacheAsyncRequest;
	pRequest->m_strWebPageUrl = pszWebPageUrl;
	pRequest->m_strFrameUrl = pszFrameUrl;
	pRequest->m_strSwfUrl = pszSwfUrl;
	pRequest->m_strFlashVars = pszFlashVars;
	pRequest->m_strOtherSwfUrls = pszOtherSwfUrls;
	pRequest->m_strOtherFlashVars = pszOtherFlashVars;
	if (_AsyncTasks.HasEqualTask (pRequest, NULL))
		return FALSE;

	HANDLE hevDone = CreateEvent (NULL, TRUE, FALSE, NULL);
	pRequest->setOnDoneEvent (hevDone);
	pRequest->setFlags (vmsAsyncTask::RemoveWhenDone);

	tsp_vmsAsyncTask spTask (pRequest);
	_AsyncTasks.AddTask (spTask);

	if (WAIT_TIMEOUT == WaitForSingleObject (hevDone, 300))
		return FALSE;

	result = pRequest->m_result;
	
	return result != NULL && result->pTa->get_FlvDownloadCount () != 0;
}

UINT WINAPI onNewHttpDialog (LPCSTR pszUrl, LPCSTR pszRequestHdrs, LPCSTR pszRespHdrs)
{
	assert (pszUrl != NULL && pszRequestHdrs != NULL && pszRespHdrs != NULL);
	if (!pszUrl || !pszRequestHdrs || !pszRespHdrs)
		return (UINT)-1;
	return _ExternalTrafficCollector.OnNewHttpDialog (pszUrl, pszRequestHdrs, pszRespHdrs);
}

void WINAPI onHttpDialogDataReceived (UINT nUID, LPBYTE pbData, UINT nSize)
{
	assert (nUID != (UINT)-1);
	if (nUID == (UINT)-1)
		return;
	_ExternalTrafficCollector.OnHttpDialogDataReceived (nUID, pbData, nSize);
}

void WINAPI onHttpDialogClosed (UINT nUID)
{
	assert (nUID != (UINT)-1);
	if (nUID == (UINT)-1)
		return;
	_ExternalTrafficCollector.OnHttpDialogClosed (nUID);
}

void WINAPI onNewHttpRequest (LPCSTR pszUrl, LPCSTR pszSrcTabUrl)
{
	assert (pszUrl != NULL && pszSrcTabUrl != NULL);
	if (!pszUrl || !pszSrcTabUrl)
		return;
	LOGsnl ("onNewHttpRequest:");
	LOG (" url: %s", pszUrl);
	LOG (" srcTab: %s", pszSrcTabUrl);
	vmsBrowserSpecialInfo::UrlInfo url;
	url.strUrl = pszUrl;
	url.strSrcTabUrl = pszSrcTabUrl;
	vmsBrowserSpecialInfo::o ().AddUrl (url);
}