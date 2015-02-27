/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsHttpRedirectList.h"

vmsHttpRedirectList::vmsHttpRedirectList(void)
{
	m_vRedirects.reserve (100);
}

vmsHttpRedirectList::~vmsHttpRedirectList(void)
{
}

void vmsHttpRedirectList::addRedirect(const Redirect& obj)
{
	vmsAUTOLOCKSECTION (m_csRedirects);
	RemoveTooOldItems ();
	m_vRedirects.push_back (obj);
}

void vmsHttpRedirectList::RemoveTooOldItems(void)
{
	vmsAUTOLOCKSECTION (m_csRedirects);
	size_t cRemove;
	DWORD dwTicksNow = GetTickCount ();
	for (cRemove = 0; cRemove < m_vRedirects.size (); cRemove++)
	{
		if (dwTicksNow - m_vRedirects [cRemove].dwTicksRegistered < 3*60*1000)
			break;
	}
	if (cRemove)
		m_vRedirects.erase (m_vRedirects.begin (), m_vRedirects.begin () + cRemove);
}

int vmsHttpRedirectList::findRedirectIndex(LPCWSTR pwszUrl)
{
	vmsAUTOLOCKSECTION (m_csRedirects);
	for (size_t i = 0; i < m_vRedirects.size (); i++)
	{
		if (m_vRedirects [i].wstrUrl == pwszUrl)
			return (int)i;
	}
	return -1;
}

const vmsHttpRedirectList::Redirect* vmsHttpRedirectList::getRedirect(int nIndex)
{
	assert (nIndex >= 0 && nIndex < (int)m_vRedirects.size ());
	vmsAUTOLOCKSECTION (m_csRedirects);
	if (nIndex < 0 || nIndex >= (int)m_vRedirects.size ())
		return NULL;
	return &m_vRedirects [nIndex];
}

void vmsHttpRedirectList::Lock(bool bLock)
{
	if (bLock)
		EnterCriticalSection (&m_csRedirects);
	else
		LeaveCriticalSection (&m_csRedirects);
}

vmsHttpRedirectList& vmsHttpRedirectList::o(void)
{
	static vmsHttpRedirectList _obj;
	return _obj;
}
