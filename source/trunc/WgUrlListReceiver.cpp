/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "WgUrlListReceiver.h"
#include "CreateDownloadListDlg.h"
#include "DownloadsWnd.h"
#include <Mshtml.h>
#include "MainFrm.h"
#include "UIThread.h"

extern CDownloadsWnd *_pwndDownloads;

STDMETHODIMP CWgUrlListReceiver::get_Url(BSTR *pVal)
{
	*pVal = SysAllocString (m_bstrUrl);
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::put_Url(BSTR newVal)
{
	m_bstrUrl = newVal;
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::get_Comment(BSTR *pVal)
{
	*pVal = SysAllocString (m_bstrComment);
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::put_Comment(BSTR newVal)
{
	m_bstrComment = newVal;
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::get_Referer(BSTR *pVal)
{
	*pVal = SysAllocString (m_bstrReferer);
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::put_Referer(BSTR newVal)
{
	m_bstrReferer = newVal;
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::ShowAddUrlListDialog()
{
	if (m_vUrls.size () == 0)
		return S_FALSE;

	UIThread *thr = (UIThread*) RUNTIME_CLASS (UIThread)->CreateObject ();

	threadAddUrlListDialogParam *param = new threadAddUrlListDialogParam;
	param->pthis = this;
	AddRef ();
	CComObject <CFdmUiWindow> *pUiWindow = NULL;
	CComObject <CFdmUiWindow>::CreateInstance (&pUiWindow);
	param->pUiWindow = pUiWindow;
	if (pUiWindow)
		pUiWindow->AddRef ();
	vmsAUTOLOCKSECTION (m_csLastUiWindow);
	m_spLastUiWindow = pUiWindow;
	vmsAUTOLOCKSECTION_UNLOCK (m_csLastUiWindow);
	thr->set_Thread (_threadAddUrlListDialog, param);
	thr->CreateThread ();

	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::AddUrlToList()
{
	USES_CONVERSION;

	LPCSTR pszUrl = W2A (m_bstrUrl);

	if (pszUrl == NULL)
		return E_INVALIDARG;

	for (int i = 0; i < m_vUrls.size (); i++)
		if (stricmp (pszUrl, m_vUrls [i]) == 0)
			return S_FALSE;

	m_vUrls.add (pszUrl);
	m_vReferers.add (W2A (m_bstrReferer));
	m_vComments.add (W2A (m_bstrComment));
	m_vCookies.add (W2A (m_bstrCookies));

	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::GetUrlListFromDocumentSelection(IDispatch *pDispatch)
{
	USES_CONVERSION;
	
	CComQIPtr<IHTMLDocument2> doc =  pDispatch;

	if (doc == NULL)
		return E_FAIL;

	BSTR bstr = NULL;
	doc->get_cookie (&bstr);
	if (bstr)
	{
		put_Cookies (bstr);
		SysFreeString (bstr);
	}
	else
		put_Cookies (L"");

	CComQIPtr <IHTMLSelectionObject> sel;

	if (FAILED (doc->get_selection (&sel)))
		return E_FAIL;

	CComBSTR str;

	sel->get_type (&str);

	if (stricmp (W2A (str), "none") == 0)
		return S_FALSE;

	IDispatch *pDisp = NULL;

	if (FAILED (sel->createRange (&pDisp)))
		return E_FAIL;

	CComQIPtr <IHTMLTxtRange> text = pDisp;

	if (text == NULL)
		return E_FAIL;

	CComBSTR htmlText;

	if (FAILED (text->get_htmlText (&htmlText)))
		return E_FAIL;

	fsHTMLParser parser;

	parser.SetKillDupes (TRUE);
	parser.ParseHTML ((LPSTR) W2A (htmlText));

	m_bstrComment = m_bstrReferer = L"";

	CComBSTR bstrRootURL;

	if (FAILED (doc->get_URL (&bstrRootURL)))
		return E_FAIL;

	LPCSTR pszRootURL = W2A (bstrRootURL);

	for (int i = 0; i < parser.GetUrlCount (); i ++)
	{
		LPCSTR pszUrl = parser.GetUrl (i);

		
		if (*pszUrl == '#')
			continue;	

		LPSTR pszFullUrl;
		
		fsUrlToFullUrl (pszRootURL, pszUrl, &pszFullUrl);
		if (pszFullUrl == NULL)
			continue;

		fsURL url;
		if (IR_SUCCESS != url.Crack (pszFullUrl, TRUE))
		{
			delete [] pszFullUrl;
			continue;
		}

		if (*url.GetHostName () == 0)
		{
			delete [] pszFullUrl;
			continue;
		}

		put_Url (A2W (pszFullUrl));
		AddUrlToList ();

		delete [] pszFullUrl;
	}

	return S_OK;
}

DWORD WINAPI CWgUrlListReceiver::_threadAddUrlListDialog(LPVOID lp)
{
	threadAddUrlListDialogParam* param = (threadAddUrlListDialogParam*) lp;

	CCreateDownloadListDlg dlg;

	while (((CFdmApp*)AfxGetApp ())->Is_Starting ())
		Sleep (100);

	dlg.m_pvUrls = &param->pthis->m_vUrls;
	dlg.m_pvReferers = &param->pthis->m_vReferers;
	dlg.m_pvComments = &param->pthis->m_vComments;
	dlg.m_pvCookies = &param->pthis->m_vCookies;
	dlg.m_pUiWindow = param->pUiWindow;

	_DlgMgr.OnDoModal (&dlg);
	dlg.DoModal ();
	_DlgMgr.OnEndDialog (&dlg);

	param->pthis->Release ();
	if (param->pUiWindow)
		param->pUiWindow->Release ();
	delete param;

	return 0;
}

STDMETHODIMP CWgUrlListReceiver::get_Cookies(BSTR *pVal)
{
	*pVal = SysAllocString (m_bstrCookies);
	return S_OK;
}

STDMETHODIMP CWgUrlListReceiver::put_Cookies(BSTR newVal)
{
	m_bstrCookies = newVal;
	return S_OK;
}

