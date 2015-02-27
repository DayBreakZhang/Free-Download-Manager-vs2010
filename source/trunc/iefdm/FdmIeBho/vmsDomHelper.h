/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSDOMHELPER_H__A44F5175_D31F_4064_ABDC_F9DB00D75842__INCLUDED_)
#define AFX_VMSDOMHELPER_H__A44F5175_D31F_4064_ABDC_F9DB00D75842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsDomHelper  
{
public:
	static HRESULT GetWebBrowser (IHTMLWindow2 *pWnd, IWebBrowser2 **ppWebBrowser);
	static HRESULT GetParentDocument (IHTMLDocument2 *pDoc, IHTMLDocument2 **ppParentDoc);
	static bool IsJSFunctionKnown (IHTMLDocument *pDoc, BSTR bsFuncName);
	static HRESULT InjectJSCode (IHTMLDocument2 *pDoc, BSTR bsCode);
	static HRESULT ExecJScript (IHTMLDocument *pDoc, BSTR bstrFuncName, const vector <CComVariant>& vArgs, CComVariant &vaResult);
	static void getElementAttribute (IHTMLElement *pElement, LPCWSTR pwszName, wstring &wstrResult);
	static void GetElementParam (IHTMLElement *pElem, LPCWSTR pwszName, wstring &wstrResult);
	vmsDomHelper();
	virtual ~vmsDomHelper();

	static HRESULT GetWindowDocument(IHTMLWindow2* pWnd, IHTMLDocument2** ppDoc);
};

#endif 
