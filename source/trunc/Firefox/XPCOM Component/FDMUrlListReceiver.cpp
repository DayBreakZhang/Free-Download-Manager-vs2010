/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMUrlListReceiver.h"
#include "common.h"
#include <nsMemory.h>
#include "xrfix.h"

XRFIX_NS_IMPL_ISUPPORTS1(CFDMUrlListReceiver, IFDMUrlListReceiver, IFDMURLLISTRECEIVER_IID)

CFDMUrlListReceiver::CFDMUrlListReceiver()
{
	CoInitialize (NULL);
}

CFDMUrlListReceiver::~CFDMUrlListReceiver()
{
	m_spUrlListRcvr = NULL;
	CoUninitialize ();
}

NS_IMETHODIMP CFDMUrlListReceiver::AddUrl(IFDMUrl *url)
{
    if (m_spUrlListRcvr == NULL)
		m_spUrlListRcvr.CreateInstance (__uuidof (WGUrlListReceiver));

	assert (m_spUrlListRcvr != NULL);
    if (m_spUrlListRcvr == NULL)
		return NS_ERROR_FAILURE;

	wchar_t_IDL *wsz;
	_bstr_t bstr;

	url->GetUrl (&wsz);
	bstr = pwchar_t_IDL_to_pwchar_t (wsz);
	CC (m_spUrlListRcvr->put_Url (bstr));
	nsMemory::Free (wsz);

	url->GetReferer (&wsz);
	bstr = pwchar_t_IDL_to_pwchar_t (wsz);
	CC (m_spUrlListRcvr->put_Referer (bstr));
	nsMemory::Free (wsz);

	url->GetComment (&wsz);
	bstr = pwchar_t_IDL_to_pwchar_t (wsz);
	CC (m_spUrlListRcvr->put_Comment (bstr));
	nsMemory::Free (wsz);

	url->GetCookies (&wsz);
	bstr = pwchar_t_IDL_to_pwchar_t (wsz);
	CC (m_spUrlListRcvr->put_Cookies (bstr));
	nsMemory::Free (wsz);

	CC (m_spUrlListRcvr->AddUrlToList ());

	return NS_OK;
}

NS_IMETHODIMP CFDMUrlListReceiver::ShowAddUrlListDialog()
{
    assert (m_spUrlListRcvr != NULL);
	if (m_spUrlListRcvr == NULL)
		return NS_ERROR_FAILURE;

	CC (m_spUrlListRcvr->ShowAddUrlListDialog ());

	m_spUrlListRcvr = NULL;

    return NS_OK;
}
