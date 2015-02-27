/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FDMCustIEBtn.h"
#include "FDMCustButton.h"
#include <shlguid.h>

STDMETHODIMP CFDMCustButton::QueryStatus(const GUID *pCmdGroup, ULONG cCmds, OLECMD prgCmds[], OLECMDTEXT *pCmdText)
{
	prgCmds[0].cmdf = OLECMDF_ENABLED;
	return S_OK;
}

STDMETHODIMP CFDMCustButton::Exec(const GUID *pCmdGroup, DWORD nCmdID, DWORD nCmdExecOpt, VARIANTARG *pvaIn, VARIANTARG *pvaOut)
{
	HKEY key;
	DWORD dwSize;
	char szURL [10000];
	if (ERROR_SUCCESS != RegOpenKey (HKEY_CURRENT_USER, "Software\\FreeDownloadManager.ORG\\Free Download Manager", &key))
		return E_FAIL;
	dwSize = 10000;
	if (ERROR_SUCCESS != RegQueryValueEx (key, "CustSite", NULL, NULL, (LPBYTE) szURL, &dwSize))
		return E_FAIL;
	szURL [dwSize] = 0;

	CComBSTR bstr = szURL;
	return m_spBrowser->Navigate (bstr, NULL, NULL, NULL, NULL);
}

STDMETHODIMP CFDMCustButton::SetSite(IUnknown *pUnkSite)
{
	if (pUnkSite == NULL)
	{
		if (m_spBrowser != NULL)
			m_spBrowser = NULL;

		return S_OK;
	}

	CComQIPtr <IServiceProvider> spServProv (pUnkSite);

	return spServProv->QueryService (SID_SWebBrowserApp, IID_IWebBrowser2,
			(void**)&m_spBrowser);
}

STDMETHODIMP CFDMCustButton::GetSite(REFIID riid, void **ppvSite)
{
	return m_spBrowser->QueryInterface (riid, ppvSite);
}
