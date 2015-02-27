/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMUrlReceiver.h"
#include "common.h"
#include <nsMemory.h>
#include "xrfix.h"

XRFIX_NS_IMPL_ISUPPORTS1(CFDMUrlReceiver, IFDMUrlReceiver, IFDMURLRECEIVER_IID)

CFDMUrlReceiver::CFDMUrlReceiver()
{
	CoInitialize (NULL);
}

CFDMUrlReceiver::~CFDMUrlReceiver()
{
	m_spUrlRcvr = NULL;
	CoUninitialize ();
}

NS_IMETHODIMP CFDMUrlReceiver::SetUrl(IFDMUrl *url)
{
	if (!url)
		return NS_ERROR_INVALID_ARG;
	
	if (m_spUrlRcvr == NULL)
		m_spUrlRcvr.CreateInstance (__uuidof (WGUrlReceiver));

	assert (m_spUrlRcvr != NULL);
    if (m_spUrlRcvr == NULL)
		return NS_ERROR_FAILURE;

	CC (ApplyUrlToReceiver (m_spUrlRcvr, url));

	return NS_OK;
}

NS_IMETHODIMP CFDMUrlReceiver::ShowAddDownloadDialog()
{
	assert (m_spUrlRcvr != NULL);
	if (m_spUrlRcvr == NULL)
		return NS_ERROR_FAILURE;

	CC (m_spUrlRcvr->ShowAddDownloadDialog ());

	m_spUrlRcvr = NULL;

    return NS_OK;
}

nsresult CFDMUrlReceiver::ApplyUrlToReceiver(IWGUrlReceiver *pUrlRcvr, IFDMUrl *url)
{
	if (!url || !pUrlRcvr)
		return NS_ERROR_INVALID_POINTER;

	wchar_t_IDL *pwsz = NULL;
	_bstr_t bstr;

	url->GetUrl (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_Url (bstr));
	nsMemory::Free (pwsz);

	url->GetOriginalUrl (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_OriginalURL (bstr));
	nsMemory::Free (pwsz);

	url->GetUserAgent (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_UserAgent (bstr));
	nsMemory::Free (pwsz);

	url->GetReferer (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_Referer (bstr));
	nsMemory::Free (pwsz);

	url->GetComment (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_Comment (bstr));
	nsMemory::Free (pwsz);

	url->GetCookies (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_Cookies (bstr));
	nsMemory::Free (pwsz);

	url->GetPostData (&pwsz);
	bstr = pwchar_t_IDL_to_pwchar_t (pwsz);
	CC (pUrlRcvr->put_PostData (bstr));
	nsMemory::Free (pwsz);

	return NS_OK;
}
