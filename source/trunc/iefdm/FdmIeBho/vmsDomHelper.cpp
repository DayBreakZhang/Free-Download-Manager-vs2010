/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsDomHelper.h"

_COM_SMARTPTR_TYPEDEF(IHTMLElement2, __uuidof(IHTMLElement2));

vmsDomHelper::vmsDomHelper()
{

}

vmsDomHelper::~vmsDomHelper()
{

}

void vmsDomHelper::GetElementParam(IHTMLElement *pElem, LPCWSTR pwszName, wstring &wstrResult)
{
	getElementAttribute (pElem, pwszName, wstrResult);
	if (!wstrResult.empty ())
		return;

	IDispatchPtr spDisp;
	pElem->get_children (&spDisp);

	IHTMLElementCollectionPtr spElems (spDisp);

	if (spElems != NULL)
	{
		long cElems = 0;
		spElems->get_length (&cElems);

		for (long i = 0; i < cElems; i++)
		{
			IDispatchPtr spDisp;
			spElems->item (CComVariant (i), CComVariant (i), &spDisp);
			IHTMLElementPtr spChildElem (spDisp);
			if (spChildElem == NULL)
				continue;
			wstring wstrName;
			getElementAttribute (spChildElem, L"name", wstrName);
			if (wcsicmp (wstrName.c_str (), pwszName) == 0)
			{
				getElementAttribute (spChildElem, L"value", wstrResult);
				break;
			}
		}
	}

	if (!wstrResult.empty ())
		return;

	IHTMLElementPtr spParentElem;
	pElem->get_parentElement (&spParentElem);

	if (spParentElem != NULL)
		GetElementParam (spParentElem, pwszName, wstrResult);
}

void vmsDomHelper::getElementAttribute(IHTMLElement *pElement, LPCWSTR pwszName, wstring &wstrResult)
{
	CComVariant vaRes;
	CComBSTR bstrName = pwszName;
	pElement->getAttribute (bstrName, 0, &vaRes);
	wstrResult = L"";
	if (vaRes.vt == VT_BSTR && vaRes.bstrVal)
		wstrResult = vaRes.bstrVal;
}

HRESULT vmsDomHelper::ExecJScript(IHTMLDocument *pDoc, BSTR bstrFuncName, const vector <CComVariant>& vArgs, CComVariant &vaResult)
{
	ATLASSERT (pDoc != NULL);
	if (!pDoc)
		return E_INVALIDARG;

	IDispatchPtr spScript;
	HRESULT hr = pDoc->get_Script (&spScript);
	if (spScript == NULL)
		return hr;

	DISPID did = NULL;
	hr = spScript->GetIDsOfNames (IID_NULL, &bstrFuncName, 1, LOCALE_SYSTEM_DEFAULT, &did);
	if (FAILED (hr))
		return hr;

	DISPPARAMS dparams;
	ZeroMemory (&dparams, sizeof (dparams));
	dparams.cArgs = vArgs.size ();
	if (dparams.cArgs)
		dparams.rgvarg = new VARIANT [dparams.cArgs];

	for (int i = 0; i < vArgs.size (); i++)
	{
		CComVariant vaTmp; vaTmp.Copy (&vArgs [vArgs.size () - i - 1]);
		VariantInit (&dparams.rgvarg [i]);
		vaTmp.Detach (&dparams.rgvarg [i]);
	}

	EXCEPINFO ei;
	ZeroMemory (&ei, sizeof (ei));
	UINT nArgErr = (UINT)-1;

	hr = spScript->Invoke (did, IID_NULL, 0, DISPATCH_METHOD, &dparams, &vaResult, &ei, &nArgErr);

	if (dparams.rgvarg)
	{
		for (int i = 0; i < dparams.cArgs; i++)
			VariantClear (&dparams.rgvarg [i]);
		delete [] dparams.rgvarg;
	}

	return hr;
}

HRESULT vmsDomHelper::InjectJSCode(IHTMLDocument2 *pDoc, BSTR bsCode)
{
	IHTMLElementPtr spBody;
	HRESULT hr = pDoc->get_body (&spBody);
	if (spBody == NULL)
		return hr;

	IHTMLElementPtr spScript;
	hr = pDoc->createElement (CComBSTR (L"script"), &spScript);
	if (spScript == NULL)
		return hr;

	spScript->setAttribute (CComBSTR (L"type"), CComVariant (L"text/javascript"));
	IHTMLScriptElementPtr spScriptEl (spScript);
	ATLASSERT (spScriptEl != NULL);
	spScriptEl->put_text (bsCode);

	IHTMLElement2Ptr spBodyEl (spBody);
	IHTMLElementPtr spTmp1;
	
	return spBodyEl->insertAdjacentElement (L"beforeEnd", spScript, &spTmp1);
}

bool vmsDomHelper::IsJSFunctionKnown(IHTMLDocument *pDoc, BSTR bsFuncName)
{
	ATLASSERT (pDoc != NULL);
	if (!pDoc)
		return false;
	
	IDispatchPtr spScript;
	HRESULT hr = pDoc->get_Script (&spScript);
	if (spScript == NULL)
		return false;
	
	DISPID did = NULL;
	hr = spScript->GetIDsOfNames (IID_NULL, &bsFuncName, 1, LOCALE_SYSTEM_DEFAULT, &did);

	return SUCCEEDED (hr);
}

HRESULT vmsDomHelper::GetParentDocument(IHTMLDocument2 *pDoc, IHTMLDocument2 **ppParentDoc)
{
	*ppParentDoc = NULL;

	ATLASSERT (pDoc != NULL);
	if (!pDoc)
		return E_INVALIDARG;

	IHTMLWindow2Ptr spWnd;
	HRESULT hr = pDoc->get_parentWindow (&spWnd);
	if (FAILED (hr))
		return hr;

	IHTMLWindow2Ptr spWndParent;
	hr = spWnd->get_parent (&spWndParent);
	if (FAILED (hr))
		return hr;

	hr = spWndParent->get_document (ppParentDoc);
	if (hr == E_ACCESSDENIED)
	{
		IWebBrowser2Ptr spWB;
		hr = GetWebBrowser (spWndParent, &spWB);
		if (FAILED (hr))
			return E_ACCESSDENIED;
		IDispatchPtr spdDoc;
		hr = spWB->get_Document (&spdDoc);
		if (FAILED (hr))
			return hr;
		hr = spdDoc->QueryInterface (IID_IHTMLDocument2, (void**)ppParentDoc);
	}
	if (FAILED (hr))
		return hr;

	IUnknownPtr spUnk1 (pDoc);
	IUnknownPtr spUnk2 (*ppParentDoc);
	if (pDoc == *ppParentDoc || spUnk1 == spUnk2)
	{
		(*ppParentDoc)->Release ();
		*ppParentDoc = NULL;
	}

	return S_OK;
}

HRESULT vmsDomHelper::GetWebBrowser(IHTMLWindow2 *pWnd, IWebBrowser2 **ppWebBrowser)
{
	*ppWebBrowser = NULL;

	ATLASSERT (pWnd != NULL);
	if (!pWnd)
		return E_INVALIDARG;

	IServiceProviderPtr spSP (pWnd);

	if (spSP == NULL)
		return E_INVALIDARG;

	return spSP->QueryService (IID_IWebBrowserApp, IID_IWebBrowser2, (void**)ppWebBrowser);
}

HRESULT vmsDomHelper::GetWindowDocument(IHTMLWindow2* pWnd, IHTMLDocument2** ppDoc)
{
	assert (pWnd != NULL && ppDoc != NULL);
	if (!ppDoc)
		return E_INVALIDARG;
	*ppDoc = NULL;
	if (!pWnd)
		return E_INVALIDARG;

	HRESULT hr = pWnd->get_document (ppDoc);

	if (*ppDoc)
		return hr;

	IWebBrowser2Ptr spWB;
	GetWebBrowser (pWnd, &spWB);

	if (spWB != NULL)
	{
		IDispatchPtr spdDoc;
		spWB->get_Document (&spdDoc);
		if (spdDoc != NULL)
		{
			spdDoc->QueryInterface (IID_IHTMLDocument2, (void**)ppDoc);
			if (*ppDoc)
				hr = S_OK;
		}
	}
	
	return hr;
}
