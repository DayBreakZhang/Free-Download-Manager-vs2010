/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "FDMUrl.h"
#include <windows.h>
#include <nsmemory.h>
#include "xrfix.h"
#include "vmsHttpRedirectList.h"

XRFIX_NS_IMPL_ISUPPORTS1(CFDMUrl, IFDMUrl, IFDMURL_IID)

CFDMUrl::CFDMUrl()
{

}

CFDMUrl::~CFDMUrl()
{
  
}

NS_IMETHODIMP CFDMUrl::GetUrl(PRUnicharIDL * *aUrl)
{
    *aUrl = (PRUnicharIDL*) nsMemory::Clone (m_wstrUrl.c_str (), (m_wstrUrl.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}
NS_IMETHODIMP CFDMUrl::SetUrl(const PRUnicharIDL * aUrl)
{
	if (!aUrl)
		return NS_ERROR_INVALID_ARG;

	m_wstrUrl = pwchar_t_IDL_to_pwchar_t (aUrl);

	vmsHttpRedirectList::o ().Lock (true);
	int nIndex = vmsHttpRedirectList::o ().findRedirectIndex (pwchar_t_IDL_to_pwchar_t (aUrl));
	if (nIndex != -1)
		m_wstrOriginalUrl = vmsHttpRedirectList::o ().getRedirect (nIndex)->wstrOriginalUrl;
	vmsHttpRedirectList::o ().Lock (false);

	return NS_OK;
}

NS_IMETHODIMP CFDMUrl::GetReferer(PRUnicharIDL * *aReferer)
{
    *aReferer = (PRUnicharIDL*) nsMemory::Clone (m_wstrReferer.c_str (), (m_wstrReferer.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}
NS_IMETHODIMP CFDMUrl::SetReferer(const PRUnicharIDL * aReferer)
{
	m_wstrReferer = L"";

	if (!aReferer)
		return NS_OK;

	if (_wcsicmp (pwchar_t_IDL_to_pwchar_t (aReferer), L"about:blank"))
		m_wstrReferer = pwchar_t_IDL_to_pwchar_t (aReferer);

	return NS_OK;
}

NS_IMETHODIMP CFDMUrl::GetComment(PRUnicharIDL * *aComment)
{
    *aComment = (PRUnicharIDL*) nsMemory::Clone (m_wstrComment.c_str (), (m_wstrComment.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}
NS_IMETHODIMP CFDMUrl::SetComment(const PRUnicharIDL * aComment)
{
	m_wstrComment = aComment ? pwchar_t_IDL_to_pwchar_t (aComment) : L"";
    return NS_OK;
}

NS_IMETHODIMP CFDMUrl::GetCookies(PRUnicharIDL * *aCookies)
{
    *aCookies = (PRUnicharIDL*) nsMemory::Clone (m_wstrCookies.c_str (), (m_wstrCookies.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}
NS_IMETHODIMP CFDMUrl::SetCookies(const PRUnicharIDL * aCookies)
{
    m_wstrCookies = aCookies ? pwchar_t_IDL_to_pwchar_t (aCookies) : L"";
	return NS_OK;
}

NS_IMETHODIMP CFDMUrl::GetPostData(PRUnicharIDL * *aPostData)
{
	*aPostData = (PRUnicharIDL*) nsMemory::Clone (m_wstrPostData.c_str (), (m_wstrPostData.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}

NS_IMETHODIMP CFDMUrl::SetPostData(const PRUnicharIDL * aPostData)
{
	if (aPostData)
		m_wstrPostData = pwchar_t_IDL_to_pwchar_t (aPostData);
	else
		m_wstrPostData = L"";

    return NS_OK;
}

NS_IMETHODIMP CFDMUrl::GetOriginalUrl(PRUnicharIDL * *aUrl)
{
	*aUrl = (PRUnicharIDL*) nsMemory::Clone (m_wstrOriginalUrl.c_str (), 
		(m_wstrOriginalUrl.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}
NS_IMETHODIMP CFDMUrl::SetOriginalUrl(const PRUnicharIDL * aUrl)
{
	m_wstrOriginalUrl = aUrl ? pwchar_t_IDL_to_pwchar_t (aUrl) : L"";
	return NS_OK;
}

NS_IMETHODIMP CFDMUrl::GetUserAgent(PRUnicharIDL * *aUrl)
{
	*aUrl = (PRUnicharIDL*) nsMemory::Clone (m_wstrUserAgent.c_str (), 
		(m_wstrUserAgent.length ()+1) * sizeof (wchar_t));
	return NS_OK;
}
NS_IMETHODIMP CFDMUrl::SetUserAgent(const PRUnicharIDL * aUrl)
{
	m_wstrUserAgent = aUrl ? pwchar_t_IDL_to_pwchar_t (aUrl) : L"";
	return NS_OK;
}