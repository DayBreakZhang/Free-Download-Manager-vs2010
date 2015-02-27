/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Iefdm.h"
#include "IEWGMonitor.h"

#include <objbase.h>
#include <comdef.h>

STDMETHODIMP CIEWGMonitor::Abort(HRESULT, DWORD)
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::Continue(PROTOCOLDATA *)
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::Resume()
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::Start(LPCWSTR pszwUrl, IInternetProtocolSink *, IInternetBindInfo *, DWORD, DWORD)
{
	USES_CONVERSION;

	LPCSTR pszUrl = W2A (pszwUrl);

	if (fsIsOKUrl (pszUrl) == FALSE)
		return S_OK;

	if (fsOnNavigateUrl (pszUrl) == FALSE)
		return INET_E_USE_DEFAULT_PROTOCOLHANDLER;
	else
	{
		if (FALSE == fsUrlToFdm (pszUrl, NULL, NULL, NULL, FALSE))
			return INET_E_USE_DEFAULT_PROTOCOLHANDLER;

		return INET_E_DATA_NOT_AVAILABLE;
	}
}

STDMETHODIMP CIEWGMonitor::Suspend()
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::Terminate(DWORD)
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::LockRequest(DWORD)
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::Read(LPVOID, ULONG, ULONG *)
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::Seek(LARGE_INTEGER, DWORD, ULARGE_INTEGER*)
{
	return E_NOTIMPL;
}

STDMETHODIMP CIEWGMonitor::UnlockRequest()
{
	return E_NOTIMPL;
}

