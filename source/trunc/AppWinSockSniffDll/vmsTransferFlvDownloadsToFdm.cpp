/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsTransferFlvDownloadsToFdm.h"
#include "..\FDM.h"
#include <comdef.h>
#include <atlbase.h>
#include "vmsCharsets.h"

_COM_SMARTPTR_TYPEDEF(IWGUrlReceiver, __uuidof(IWGUrlReceiver));
_COM_SMARTPTR_TYPEDEF(IFdmFlvDownload, __uuidof(IFdmFlvDownload));
_COM_SMARTPTR_TYPEDEF(IFDMFlashVideoDownloads, __uuidof(IFDMFlashVideoDownloads));
_COM_SMARTPTR_TYPEDEF(IFdmUiWindow, __uuidof(IFdmUiWindow));

vmsTransferFlvDownloadsToFdm::vmsTransferFlvDownloadsToFdm()
{

}

vmsTransferFlvDownloadsToFdm::~vmsTransferFlvDownloadsToFdm()
{

}

HRESULT vmsTransferFlvDownloadsToFdm::Do(LPCSTR pszSrcWebPageUrl, const vector <vmsHttpFlvTrafficAnalyzer::FlvDownload> &v)
{
	LOGsnl ("In vmsTransferFlvDownloadsToFdm::Do");

	vector <IFdmFlvDownloadPtr> vDownloads;

	HRESULT hr;

	for (int i = 0; i < v.size (); i++)
	{
		IFdmFlvDownloadPtr spFlv;
		hr = spFlv.CreateInstance (__uuidof (FdmFlvDownload));
		if (FAILED (hr))
			break;

		IWGUrlReceiverPtr spUrlRcvr;
		hr = spUrlRcvr.CreateInstance (__uuidof (WGUrlReceiver));
		if (FAILED (hr))
			break;

		SetupWgUrlRcvr (spUrlRcvr, v [i]);

		spFlv->put_Url (spUrlRcvr);

		vDownloads.push_back (spFlv);
	}

	LOG ("cDownloads = %d", vDownloads.size ());

	if (vDownloads.empty ())
		return hr;

	
	SAFEARRAY *psaDownloads = SafeArrayCreateVector (VT_DISPATCH, 0, vDownloads.size ());
	if (!psaDownloads)
	{
		LOGsnl ("error: out of memory");
		return E_OUTOFMEMORY;
	}

	for (long j = 0; j < vDownloads.size (); j++)
	{
		IDispatchPtr spDisp;
		vDownloads [j]->QueryInterface (IID_IDispatch, (void**)&spDisp);
		SafeArrayPutElement (psaDownloads, &j, spDisp);
	}

	IFDMFlashVideoDownloadsPtr spFvDownloads;
	hr = spFvDownloads.CreateInstance (__uuidof (FDMFlashVideoDownloads));
	if (FAILED (hr))
	{
		LOG ("error: failed create flashDownloads obj, hr=0x%x", hr);
		return hr;
	}
	
	CComBSTR bstr; bstr = pszSrcWebPageUrl;
	hr = spFvDownloads->ShowAddDownloadsDialog (bstr, psaDownloads);
	LOG ("done. result = 0x%x", hr);

	if (SUCCEEDED (hr))
	{
		IServiceProviderPtr spSP (spFvDownloads);
		if (spSP != NULL)
		{
			IFdmUiWindowPtr spUiWindow;
			spSP->QueryService (__uuidof(IFdmUiWindow), __uuidof(IFdmUiWindow), (void**)&spUiWindow);
			if (spUiWindow != NULL)
			{
				spUiWindow->WaitForWindowCreation (5000);
				ULONG u = 0;
				spUiWindow->get_Handle (&u);
				if (u)
				{
					SetForegroundWindow ((HWND)u);
					BringWindowToTop ((HWND)u);
				}
			}
		}
	}

	SafeArrayDestroy (psaDownloads);

	return S_OK;
}

void vmsTransferFlvDownloadsToFdm::SetupWgUrlRcvr(IWGUrlReceiver *pRcvr, const vmsHttpFlvTrafficAnalyzer::FlvDownload &flv)
{
	CComBSTR bstr; bstr = flv.strUrl.c_str ();
	pRcvr->put_Url (bstr);
	wstring wstr = flv.wstrTitle;
	if (!wstr.empty () && !flv.strContentType.empty ())
	{
		string strExt = ExtensionFromContentType (flv.strContentType.c_str ());
		if (!strExt.empty ())
		{
			wstr += '.';
			USES_CONVERSION;
			wstr += A2W (strExt.c_str ());
		}
	}
	bstr = wstr.c_str ();
	pRcvr->put_FileName (bstr);
	bstr = flv.strContentLength.c_str ();
	pRcvr->put_FileSize (bstr);
	bstr = flv.strReferer.c_str ();
	pRcvr->put_Referer (bstr);
	bstr = flv.strCookies.c_str ();
	pRcvr->put_Cookies (bstr);
	if (flv.vbPostData.size ())
	{
		char *psz = new char [flv.vbPostData.size ()+1];
		memcpy (psz, &flv.vbPostData [0], flv.vbPostData.size ());
		psz [flv.vbPostData.size ()] = 0;
		bstr = psz;
		pRcvr->put_PostData (bstr);
		delete [] psz;
	}
}

string vmsTransferFlvDownloadsToFdm::ExtensionFromContentType(LPCSTR pszCT)
{
	LPCSTR apszCT [] = {
		"video/x-flv", "video/mp4", "video/x-m4v", "audio/mp4a-latm", 
		"video/3gpp", "video/quicktime", "audio/mp4",
	};

	LPCSTR apszExts [] = {
		"flv", "mp4", "mp4", "mp4", 
		"3gp", "mov", "mp4",
	};

	assert (sizeof (apszCT) == sizeof (apszExts));
	
	for (int i = 0; i < sizeof (apszCT) / sizeof (LPCSTR); i++)
	{
		if (strnicmp (pszCT, apszCT [i], strlen (apszCT [i])) == 0)
			return apszExts [i];
	}

	return "flv";
}
