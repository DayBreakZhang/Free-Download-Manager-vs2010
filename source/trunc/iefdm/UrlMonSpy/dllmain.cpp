/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"

#include "vmsUrlMonDefaultApphSpy.h"
#include "vmsUrlMonRequestImpl.h"

DWORD WINAPI _threadInit (LPVOID)
{
	CoInitialize (NULL);
	vmsUrlMonDefaultApphSpy::Initialize ();
	CoUninitialize ();
	return 0;
}

HMODULE _hModule = NULL;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		_hModule = hModule;
		DWORD dw;
		CloseHandle (
			CreateThread (NULL, 0, _threadInit, NULL, 0, &dw));
		break;

	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

vmsUrlMonRequest* WINAPI fdmumspy_findRequest (LPCWSTR pwszUrl, LPBYTE pbPostData, DWORD dwPostDataSize, bool bInProgressOnly)
{
	assert (pwszUrl != NULL && *pwszUrl != 0);
	assert (dwPostDataSize == 0 || pbPostData != NULL);
	if (!pwszUrl)
		return NULL;
	if (dwPostDataSize != 0 && pbPostData == NULL)
		return NULL;
	vmsUrlMonRequestImplPtr spRequest;
	vmsUrlMonDefaultApphSpy::_Requests.Lock (true); 
	for (int i = 0; i < vmsUrlMonDefaultApphSpy::_Requests.getRequestCount (); i++)
	{
		vmsUrlMonRequestCollector::Request *req = vmsUrlMonDefaultApphSpy::_Requests.getRequest (i);
		if (bInProgressOnly && req->dwTicksCompleted != 0)
			continue;
		bool bRedirected = false;
		if (wcscmp (req->wstrUrl.c_str (), pwszUrl))
		{
			if (wcscmp (req->wstrRedirectedUrl.c_str (), pwszUrl))
				continue;
			bRedirected = true;
		}
		if (!bRedirected)
		{
			if (req->vbPostData.size () != dwPostDataSize)
				continue;
			if (dwPostDataSize && memcmp (&req->vbPostData [0], pbPostData, dwPostDataSize))
				continue;
		}
		spRequest.CreateInstance ();
		spRequest->m_spReq = req;
		spRequest->AddRef ();
		break;
	}
	vmsUrlMonDefaultApphSpy::_Requests.Lock (false); 

	return spRequest;
}