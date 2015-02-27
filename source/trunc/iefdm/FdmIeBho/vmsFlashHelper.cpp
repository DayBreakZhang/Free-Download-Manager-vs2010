/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFlashHelper.h"
#include <mflash.h>
#include <mflash.c>
#include <mshtml.h>

_COM_SMARTPTR_TYPEDEF(IShockwaveFlash, __uuidof(IShockwaveFlash));

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFlashHelper::vmsFlashHelper()
{

}

vmsFlashHelper::~vmsFlashHelper()
{

}

void vmsFlashHelper::DisableFlashMovies(IHTMLDocument2Ptr spDoc, BOOL bIncludingFrames)
{
	FLASHLIST vf;
	GetFlashMoviesObjList (spDoc, &vf, bIncludingFrames);

	for (int i = 0; i < vf.size (); i++)
	{
		
		
		IHTMLElementPtr spElem (vf [i]);
		if (spElem)
		{
			IHTMLStylePtr spStyle;
			HRESULT hr = spElem->get_style (&spStyle);
			if (SUCCEEDED (hr) && spStyle != NULL)
			{
				spStyle->put_visibility  (L"hidden");
				spStyle->put_pixelHeight (0);
				spStyle->put_pixelWidth  (0);
			}
		}
	}
}

void vmsFlashHelper::SaveFlashMovies_noframes(IHTMLDocument2Ptr spDoc, LPCSTR pszFolder)
{
	USES_CONVERSION;

	if (spDoc == NULL)
		return;

	IHTMLElementCollectionPtr spAll;
	HRESULT hr = spDoc->get_all(&spAll);
	if (SUCCEEDED(hr) && spAll != NULL)
	{
		
		CComVariant vTagName ("OBJECT");
        IDispatchPtr spTagsDisp;
		hr = spAll->tags (vTagName, &spTagsDisp);
		if (SUCCEEDED(hr) && spTagsDisp != NULL)
		{
			IHTMLElementCollectionPtr spTags (spTagsDisp);
			if (spTags)
			{
				long nCnt;
				hr = spTags->get_length(&nCnt);
				if (SUCCEEDED(hr))
				{
					for (long i = 0; i < nCnt; i++)
					{
						CComVariant varIdx;
						V_VT(&varIdx) = VT_I4;
						V_I4(&varIdx) = i;

						IDispatchPtr spTagDisp;
						hr = spTags->item(varIdx, varIdx, &spTagDisp);
						if (SUCCEEDED(hr) && spTagDisp != NULL)
						{
							IHTMLObjectElementPtr spObject(spTagDisp);
							if (spObject != NULL)
							{
								BSTR bstrClassID = NULL;
								hr = spObject->get_classid(&bstrClassID);
								if (SUCCEEDED(hr) && bstrClassID)
								{
									fsString strClassID = W2A (bstrClassID);
									SysFreeString (bstrClassID);
									if (lstrcmpi (strClassID, "CLSID:D27CDB6E-AE6D-11CF-96B8-444553540000") == 0)
									{
										IDispatchPtr spObj;
										spObject->get_object (&spObj);
										IShockwaveFlashPtr spFlash (spObj);
										if (spFlash != NULL)
										{
											BSTR bstr;
											spFlash->get_Movie (&bstr);
											SysFreeString (bstr);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	
    CComVariant vTagName ("EMBED");
	IDispatchPtr spTagsDisp;
    hr = spAll->tags(vTagName, &spTagsDisp);
    if (SUCCEEDED(hr) && spTagsDisp != NULL)
    {
        IHTMLElementCollectionPtr spTags(spTagsDisp);
        if (spTags != NULL)
        {
            long nCnt;
            hr = spTags->get_length(&nCnt);
            if (SUCCEEDED(hr))
            {
                for (long i = 0; i < nCnt; i++)
				{
					CComVariant varIdx;
					V_VT(&varIdx) = VT_I4;
					V_I4(&varIdx) = i;

					IDispatchPtr spTagDisp;
					hr = spTags->item(varIdx, varIdx, &spTagDisp);
					if (SUCCEEDED(hr) && spTagDisp != NULL)
					{
						IHTMLEmbedElementPtr spObject(spTagDisp);
						if (spObject != NULL)
						{
							IShockwaveFlashPtr spFlash (spObject);
							if (spFlash != NULL)
							{
								BSTR bstrSrc = NULL;
								hr = spObject->get_src(&bstrSrc);
								if (SUCCEEDED(hr) && bstrSrc)
								{
									SysFreeString (bstrSrc);
								}
							}
						}
					}
				}
            }
        }
	}
}

void vmsFlashHelper::SaveFlashMovies(IHTMLDocument2Ptr spDoc, LPCSTR pszFolder, BOOL bIncludingFrames)
{
    SaveFlashMovies_noframes(spDoc, pszFolder);

	if (bIncludingFrames == FALSE)
		return;

    
    IHTMLFramesCollection2Ptr spFrames;
	spDoc->get_frames (&spFrames);
	if (spFrames == NULL)
		return;

	long lCount = 0;
	spFrames->get_length (&lCount);

	for (long i = 0; i < lCount; i++)
	{
		CComVariant va ((long)i);
		CComVariant vaR;

		spFrames->item (&va, &vaR);

		if (vaR.pdispVal != NULL)
		{
			IHTMLWindow2Ptr spWnd = vaR.pdispVal;
			if (spWnd != NULL)
			{
				IHTMLDocument2Ptr spFDoc;
				spWnd->get_document (&spFDoc);
				if (spFDoc != NULL)
					SaveFlashMovies (spFDoc, pszFolder, TRUE);
			}
		}
	}
}

void vmsFlashHelper::GetFlashMoviesList(IHTMLDocument2Ptr spDoc, std::vector <fsString> *pslURLs, std::vector <fsString> *pslHTMLs)
{
	USES_CONVERSION;

	FLASHLIST vf;
	GetFlashMoviesObjList (spDoc, &vf, TRUE);

	IHTMLLocationPtr spLoc;
	spDoc->get_location (&spLoc);
	BSTR bstrHref = NULL;
	spLoc->get_href (&bstrHref);
	fsString strParent = W2A (bstrHref);
	SysFreeString (bstrHref);

	for (int i = 0; i < vf.size (); i++)
	{
		IDispatch* pTag = vf [i];
		fsString strMovieURL;
		fsString strMovieHTML;
		
		
		IHTMLObjectElementPtr spObject (pTag);
		if (spObject != NULL)
		{
			IDispatchPtr spObj;
			spObject->get_object (&spObj);
			IShockwaveFlashPtr spFlash (spObj);
			if (spFlash != NULL)
			{
				BSTR bstr;
				spFlash->get_Movie (&bstr);
				strMovieURL = W2A (bstr);
				SysFreeString (bstr);
			}
		}
		else
		{
			
			IHTMLEmbedElementPtr spObject(pTag);
			BSTR bstrSrc = NULL;
			spObject->get_src(&bstrSrc);
			strMovieURL = W2A (bstrSrc);
			SysFreeString (bstrSrc);
		}

		
		if (pslHTMLs != NULL)
		{
			IHTMLElementPtr spElement (pTag);
			BSTR bstr = NULL;
			spElement->get_outerHTML (&bstr);
			strMovieHTML = W2A (bstr);
			SysFreeString (bstr);
		}

		pslURLs->push_back (strMovieURL);
		if (pslHTMLs)
			pslHTMLs->push_back (strMovieHTML);
	}
}

void vmsFlashHelper::GetFlashMoviesObjList(IHTMLDocument2Ptr spDoc, LPFLASHLIST pv, BOOL bIncludingFrames)
{
	
    GetFlashMoviesObjList_noframes (spDoc, pv);

	if (bIncludingFrames == FALSE)
		return;

    
    IHTMLFramesCollection2Ptr spFrames;
	spDoc->get_frames (&spFrames);
	if (spFrames == NULL)
		return;

	long lCount = 0;
	spFrames->get_length (&lCount);

	for (long i = 0; i < lCount; i++)
	{
		CComVariant va ((long)i);
		CComVariant vaR;

		spFrames->item (&va, &vaR);

		if (vaR.pdispVal != NULL)
		{
			IHTMLWindow2Ptr spWnd = vaR.pdispVal;
			if (spWnd != NULL)
			{
				IHTMLDocument2Ptr spFDoc;
				spWnd->get_document (&spFDoc);
				if (spFDoc != NULL)
					GetFlashMoviesObjList (spFDoc, pv, TRUE);
			}
		}
	}
}

void vmsFlashHelper::GetFlashMoviesObjList_noframes(IHTMLDocument2Ptr spDoc, LPFLASHLIST pv)
{
	USES_CONVERSION;

	if (spDoc == NULL)
		return;

	IHTMLElementCollectionPtr spAll;
	HRESULT hr = spDoc->get_all(&spAll);
	if (SUCCEEDED(hr) && spAll != NULL)
	{
		
		CComVariant vTagName ("OBJECT");
        IDispatchPtr spTagsDisp;
		hr = spAll->tags (vTagName, &spTagsDisp);
		if (SUCCEEDED(hr) && spTagsDisp != NULL)
		{
			IHTMLElementCollectionPtr spTags (spTagsDisp);
			if (spTags)
			{
				long nCnt;
				hr = spTags->get_length(&nCnt);
				if (SUCCEEDED(hr))
				{
					for (long i = 0; i < nCnt; i++)
					{
						CComVariant varIdx;
						V_VT(&varIdx) = VT_I4;
						V_I4(&varIdx) = i;

						IDispatchPtr spTagDisp;
						hr = spTags->item(varIdx, varIdx, &spTagDisp);
						if (SUCCEEDED(hr) && spTagDisp != NULL)
						{
							IHTMLObjectElementPtr spObject(spTagDisp);
							if (spObject != NULL)
							{
								BSTR bstrClassID = NULL;
								hr = spObject->get_classid(&bstrClassID);
								if (SUCCEEDED(hr) && bstrClassID)
								{
									fsString strClassID = W2A (bstrClassID);
									SysFreeString (bstrClassID);
									if (lstrcmpi (strClassID, "CLSID:D27CDB6E-AE6D-11CF-96B8-444553540000") == 0)
										pv->push_back (spTagDisp);
								}
							}
						}
					}
				}
			}
		}
	}

	
    CComVariant vTagName ("EMBED");
	IDispatchPtr spTagsDisp;
    hr = spAll->tags(vTagName, &spTagsDisp);
    if (SUCCEEDED(hr) && spTagsDisp != NULL)
    {
        IHTMLElementCollectionPtr spTags(spTagsDisp);
        if (spTags != NULL)
        {
            long nCnt;
            hr = spTags->get_length(&nCnt);
            if (SUCCEEDED(hr))
            {
                for (long i = 0; i < nCnt; i++)
				{
					CComVariant varIdx;
					V_VT(&varIdx) = VT_I4;
					V_I4(&varIdx) = i;

					IDispatchPtr spTagDisp;
					hr = spTags->item(varIdx, varIdx, &spTagDisp);
					if (SUCCEEDED(hr) && spTagDisp != NULL)
					{
						IHTMLEmbedElementPtr spObject(spTagDisp);
						if (spObject != NULL)
						{
							IShockwaveFlashPtr spFlash (spObject);
							if (spFlash != NULL)
								pv->push_back (spTagDisp);
						}
					}
				}
            }
        }
	}
}

BOOL vmsFlashHelper::is_FlashElement(IHTMLElementPtr spEl, IDispatchPtr& spFlashDisp, IDispatchPtr& spFlashObject)
{
	USES_CONVERSION;

	IHTMLObjectElementPtr spObject (spEl);
	if (spObject != NULL)
	{
		BSTR bstrClassID = NULL;
		HRESULT hr = spObject->get_classid(&bstrClassID);
		if (SUCCEEDED (hr) && bstrClassID)
		{
			fsString strClassID = W2A (bstrClassID);
			SysFreeString (bstrClassID);
			if (lstrcmpi (strClassID, "CLSID:D27CDB6E-AE6D-11CF-96B8-444553540000") == 0)
			{
				spFlashDisp = spObject;
				spObject->get_object (&spFlashObject);
				return TRUE;
			}
		}

		return FALSE;
	}

	IHTMLEmbedElementPtr spEmbed (spEl);
	if (spEmbed != NULL)
	{
		IShockwaveFlashPtr spFlash (spEmbed);
		if (spFlash != NULL)
		{
			spFlashDisp = spEmbed;
			spFlashObject = spEmbed;
			return TRUE;
		}

		return FALSE;
	}

	

	return FALSE;
}

void vmsFlashHelper::GetFlashInfo(IDispatchPtr spFlash, IHTMLDocument2Ptr spDoc, fsString *pstrMovieURL, fsString *pstrMovieHTML)
{
	USES_CONVERSION;

	IHTMLLocationPtr spLoc;
	spDoc->get_location (&spLoc);
	BSTR bstrHref = NULL;
	spLoc->get_href (&bstrHref);
	fsString strParent = W2A (bstrHref);
	SysFreeString (bstrHref);

	
	IHTMLObjectElementPtr spObject (spFlash);
	if (spObject != NULL)
	{
		IDispatchPtr spObj;
		spObject->get_object (&spObj);
		IShockwaveFlashPtr spFlash (spObj);
		if (spFlash != NULL)
		{
			BSTR bstr;
			spFlash->get_Movie (&bstr);
			*pstrMovieURL = W2A (bstr);
			SysFreeString (bstr);
		}
	}
	else
	{
		
		IHTMLEmbedElementPtr spObject (spFlash);
		BSTR bstrSrc = NULL;
		spObject->get_src(&bstrSrc);
		*pstrMovieURL = W2A (bstrSrc);
		SysFreeString (bstrSrc);
	}

	
	if (pstrMovieHTML != NULL)
	{
		IHTMLElementPtr spElement (spFlash);
		BSTR bstr = NULL;
		spElement->get_outerHTML (&bstr);
		*pstrMovieHTML = W2A (bstr);
		SysFreeString (bstr);
	}
}
