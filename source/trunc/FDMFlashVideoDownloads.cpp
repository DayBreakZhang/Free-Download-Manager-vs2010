/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "FDMFlashVideoDownloads.h"
#include "vmsVideoSiteHtmlCodeParser.h"
#include "FlashVideoDownloadsWnd.h"
#include "UIThread.h"

_COM_SMARTPTR_TYPEDEF (IWGUrlReceiver, __uuidof (IWGUrlReceiver));
_COM_SMARTPTR_TYPEDEF (IFdmFlvDownload, __uuidof (IFdmFlvDownload));

STDMETHODIMP CFDMFlashVideoDownloads::ProcessIeDocument(IDispatch *pDispatch)
{
	IHTMLDocument2Ptr spDoc (pDispatch);
	if (spDoc == NULL)
		return E_INVALIDARG;

	IPersistFilePtr spFile (pDispatch);
	if (spFile == NULL)
		return E_INVALIDARG;

	

	USES_CONVERSION;
	BSTR bstrHost = NULL;
	spDoc->get_URL (&bstrHost);
	fsURL url;
	if (url.Crack (W2A (bstrHost)) != IR_SUCCESS)
		return E_FAIL;
	SysFreeString (bstrHost);

	char szPath [MY_MAX_PATH];
	GetTempPath (sizeof (szPath), szPath);
	char szFile [MY_MAX_PATH];
	GetTempFileName (szPath, "fdm", 0, szFile);

	COleVariant vaFile (szFile);
	if (FAILED (spFile->Save (vaFile.bstrVal, FALSE)))
		return E_FAIL;

	HANDLE hFile = CreateFile (szFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return E_FAIL;

	DWORD dw = GetFileSize (hFile, NULL);

	LPSTR pszHtml = new char [dw + 1];
	ReadFile (hFile, pszHtml, dw, &dw, NULL);
	pszHtml [dw] = 0;

	CloseHandle (hFile);
	DeleteFile (szFile);

	ProcessHtml (url.GetHostName (), pszHtml);
	delete [] pszHtml;

	return S_OK;
}

STDMETHODIMP CFDMFlashVideoDownloads::ProcessHtml(BSTR bstrHost, BSTR bstrHtml)
{
	USES_CONVERSION;
	ProcessHtml (W2A (bstrHost), W2A (bstrHtml));
	return S_OK;
}

void CFDMFlashVideoDownloads::ProcessHtml(LPCSTR pszHost, LPCSTR pszHtml)
{
	vmsVideoSiteHtmlCodeParser vshcp;
	if (FALSE == vshcp.Parse (pszHost, pszHtml))
		return;

	USES_CONVERSION;

	IWGUrlReceiverPtr spRcvr;
	spRcvr.CreateInstance (__uuidof (WGUrlReceiver));
	spRcvr->put_Url (A2W (vshcp.get_VideoUrl ()));

	if (vshcp.get_IsVideoUrlDirectLink ())
	{
		CString str = vshcp.get_VideoTitle ();
		str += "."; str += vshcp.get_VideoType ();
		spRcvr->put_FileName (A2W (str));

		spRcvr->put_Comment (A2W (vshcp.get_VideoTitle ()));

		spRcvr->put_FlashVideoDownload (TRUE);
	}

	spRcvr->AddDownload ();
}

DWORD WINAPI CFDMFlashVideoDownloads::_threadCreateDownload(LPVOID lp)
{
	USES_CONVERSION;

	BSTR bstrUrl = (BSTR) lp;

	_pwndFVDownloads->CreateDownload (W2A (bstrUrl), true);

	SysFreeString (bstrUrl);

	return 0;
}

STDMETHODIMP CFDMFlashVideoDownloads::CreateFromUrl(BSTR bstrUrl)
{
	UIThread *thr = (UIThread*) RUNTIME_CLASS (UIThread)->CreateObject ();
	thr->set_Thread (_threadCreateDownload, SysAllocString (bstrUrl));
	thr->CreateThread ();

	return S_OK;
}

STDMETHODIMP CFDMFlashVideoDownloads::ShowAddDownloadDialog(BSTR bstrSrcWebPageUrl, IFdmFlvDownload *pDld)
{
	return E_NOTIMPL;
}

STDMETHODIMP CFDMFlashVideoDownloads::ShowAddDownloadsDialog(BSTR bstrSrcWebPageUrl, SAFEARRAY *psaDownloads)
{
	USES_CONVERSION;

	CComObject <CFdmUiWindow> *pUiWindow = NULL;
	CComObject <CFdmUiWindow>::CreateInstance (&pUiWindow);

	vmsAUTOLOCKSECTION (m_csLastUiWindow);
	m_spLastUiWindow = pUiWindow;
	vmsAUTOLOCKSECTION_UNLOCK (m_csLastUiWindow);

	if (psaDownloads == NULL)
		return E_INVALIDARG;

	UINT cDim = SafeArrayGetDim (psaDownloads);
	if (cDim != 1)
		return E_INVALIDARG;

	LONG lLBound = 0, lUBound = 0;
	SafeArrayGetLBound (psaDownloads, 1, &lLBound);
	SafeArrayGetUBound (psaDownloads, 1, &lUBound);

	std::vector <vmsNewDownloadInfo> *pvDlds = new std::vector <vmsNewDownloadInfo>;

	for (long i = lLBound; i <= lUBound; i++)
	{
		IDispatchPtr spDisp;
		SafeArrayGetElement (psaDownloads, &i, &spDisp);

		IFdmFlvDownloadPtr spFlvDld (spDisp);

		if (spFlvDld == NULL)
		{
			delete pvDlds;
			return E_INVALIDARG;
		}
		IWGUrlReceiverPtr spUrl;
		spFlvDld->get_Url (&spUrl);
		if (spUrl == NULL)
		{
			delete pvDlds;
			return E_INVALIDARG;
		}

		CComBSTR bstr;
		spUrl->get_Url (&bstr);

		CString strUrl = W2CT (bstr);
		bool bSkip = false;

		for (size_t j = 0; j < pvDlds->size (); j++)
		{
			if (pvDlds->at (j).strUrl == strUrl)
			{
				bSkip = true; 
				break;
			}
		}

		if (bSkip)
			continue;

		vmsNewDownloadInfo dlInfo;

		dlInfo.strUrl = W2CA (bstr);

		spUrl->get_Referer (&bstr);
		dlInfo.strReferer = W2CA (bstr);

		spUrl->get_Comment (&bstr);
		dlInfo.strComment = bstr;

		dlInfo.dwWhatIsValid = NDIV_AP;

		dlInfo.ap.dwMask = DWCDAP_FLAGS;
		dlInfo.ap.dwFlags = DWDCDAP_F_FLASHVIDEODOWNLOAD;

		spUrl->get_Cookies (&bstr);
		if (bstr.Length ())
		{
			dlInfo.ap.dwMask |= DWCDAP_COOKIES;
			dlInfo.ap.strCookies = W2CA (bstr);
		}

		spUrl->get_PostData (&bstr);
		if (bstr.Length ())
		{
			dlInfo.ap.dwMask |= DWCDAP_POSTDATA;
			dlInfo.ap.strPostData = W2CA (bstr);
		}

		spUrl->get_FileName (&bstr);
		if (bstr.Length ())
		{
			dlInfo.ap.dwMask |= DWCDAP_FILENAME;
			dlInfo.ap.strFileName = W2CA (bstr);
		}

		spUrl->get_FileSize (&bstr);
		if (bstr.Length ())
		{
			dlInfo.ap.dwMask |= DWCDAP_FILESIZE;
			dlInfo.ap.uFileSize = (UINT64)_wtoi64 (bstr);
		}

		pvDlds->push_back (dlInfo);
	}

	CFlashVideoDownloadsWnd::WmFvdwLparam *lp = new CFlashVideoDownloadsWnd::WmFvdwLparam;
	lp->strSrcWebPageUrl = W2CA(bstrSrcWebPageUrl);
	lp->pvDlds = pvDlds;
	lp->pUiWindow = pUiWindow; 
	if (pUiWindow)
		pUiWindow->AddRef ();
	_pwndFVDownloads->PostMessage (WM_FVDW_CREATEDOWNLOADS, 0, (LPARAM)lp);

	return S_OK;
}

STDMETHODIMP CFDMFlashVideoDownloads::QueryService(REFGUID guidService, REFIID riid, void** ppv)
{
	if (IsEqualIID (guidService, IID_IFdmUiWindow))
	{
		vmsAUTOLOCKSECTION (m_csLastUiWindow);
		if (m_spLastUiWindow)
			return m_spLastUiWindow->QueryInterface (riid, ppv);
	}
	return E_NOINTERFACE;
}
