/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "Iefdm.h"
#include "WgBHO.h"
#include "comdef.h"

_COM_SMARTPTR_TYPEDEF(IHTMLInputElement, __uuidof(IHTMLInputElement));

STDMETHODIMP CWgBHO::GetSite(REFIID riid, void **ppvSite)
{
	if (m_spWebBrowser2 == NULL || ppvSite == NULL)
		return E_INVALIDARG;
	
	*ppvSite = NULL;
	return m_spWebBrowser2.QueryInterface ((IWebBrowser2**) ppvSite);
}

STDMETHODIMP CWgBHO::SetSite(IUnknown *pSite)
{
	m_spWebBrowser2 = pSite;
	if (m_spWebBrowser2 == NULL)
		return S_OK;

	m_spCPC = m_spWebBrowser2;
	if (m_spCPC == NULL)
		return E_POINTER;

	return Connect ();
}

STDMETHODIMP CWgBHO::Connect()
{
	HRESULT hr;
	CComQIPtr <IConnectionPoint> spCP;

	hr = m_spCPC->FindConnectionPoint (DIID_DWebBrowserEvents2, &spCP);
	if (FAILED (hr))
		return hr;

	IWgBHO *pThis = (IWgBHO*) this;

	hr = spCP->Advise (pThis, &m_dwCookie);

	return S_OK;
}

STDMETHODIMP CWgBHO::BeforeNavigate2(IDispatch *, VARIANT *url, VARIANT *flags, VARIANT *tfn, VARIANT *pd, VARIANT *headers, VARIANT_BOOL *bCancel)
{
	USES_CONVERSION;

	if (fsIsMonitoringTurnedOn () == FALSE)
		return S_OK;
	
	_bstr_t bstrUrl = url->bstrVal;

	LPCSTR pszUrl = W2A (bstrUrl);

	if (fsIsOKUrl (pszUrl) == FALSE)
		return S_OK;

	*bCancel = VARIANT_FALSE;

	

	if (FALSE == fsOnNavigateUrl (pszUrl))
		return S_OK;

	fsString strCookies, strPostData, strReferer;
	IDispatchPtr spdDoc;
	m_spWebBrowser2->get_Document (&spdDoc);
	IHTMLDocument2Ptr spDoc;
	if (spdDoc)
		spDoc = spdDoc;
	if (spDoc)
	{		
		BSTR bstr = NULL;
		spDoc->get_cookie (&bstr);
		if (bstr)
		{
			strCookies = W2A (bstr);
			SysFreeString (bstr);
		}

		bstr = NULL;
		spDoc->get_URL (&bstr);
		if (bstr)
		{
			strReferer = W2A (bstr);
			SysFreeString (bstr);
		}

		IHTMLElementCollectionPtr spForms;
		spDoc->get_forms (&spForms);

		long cForms = 0;
		if (spForms)
			spForms->get_length (&cForms);

		bool bFound = false;

		for (long i = 0; bFound == false && i < cForms; i++)
		{
			IDispatchPtr spd;
			spForms->item (CComVariant (i), CComVariant (i), &spd);

			IHTMLFormElementPtr spForm (spd);
			if (spForm == NULL)
				continue;

			BSTR bstr = NULL;
			spForm->get_action (&bstr);
			bFound = bstr != NULL && wcscmp (url->bstrVal, bstr) == 0;
			SysFreeString (bstr);
			if (bFound == false)
				continue;

			bstr = NULL;
			spForm->get_method (&bstr);
			if (bstr == NULL || wcsicmp (bstr, L"post"))
				break;
			SysFreeString (bstr);

			IHTMLElementPtr spFormElem (spForm);
			if (spFormElem == NULL)
			{
				bFound = false;
				continue;
			}

			WalkThroughForm (spFormElem, strPostData);

			if (strPostData != "" && 
					strPostData [strPostData.GetLength ()-1] == '&')
				strPostData [strPostData.GetLength ()-1] = 0;
		}

	}

	if (fsUrlToFdm (pszUrl, strReferer, strCookies != "" ? strCookies : NULL,
			strPostData != "" ? strPostData : NULL, FALSE))
		*bCancel = VARIANT_TRUE;

	return S_OK;
}

BOOL fsIsOKUrl (LPCSTR pszURL)
{
	return _strnicmp (pszURL, "http://", 7) == 0 ||
		_strnicmp (pszURL, "ftp://", 6) == 0 ||
		_strnicmp (pszURL, "https://", 8) == 0;
}

void CWgBHO::WalkThroughForm(IHTMLElement *pElement, fsString &str)
{
	USES_CONVERSION;

	IDispatchPtr spd;
	pElement->get_children (&spd);
	IHTMLElementCollectionPtr spels (spd);

	long cElements = 0;
	if (spels != NULL)
		spels->get_length (&cElements);

	for (int j = 0; j < cElements; j++)
	{
		spd = NULL;
		spels->item (CComVariant (j), CComVariant (j), &spd);

		IHTMLInputElementPtr spInp (spd);
		if (spInp != NULL)
		{
			BSTR bstr = NULL, bstr2 = NULL;
			spInp->get_name (&bstr);				
			spInp->get_value (&bstr2);
			if (bstr)
			{
				str += W2A (bstr);
				str += "=";
				SysFreeString (bstr);
			}
			if (bstr2)
			{
				str += W2A (bstr2);
				SysFreeString (bstr2);
			}

			if (bstr || bstr2)
				str += "&";
		}
		
		IHTMLElementPtr spel (spd);
		if (spel != NULL)
			WalkThroughForm (spel, str);
	}
}
