/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBrowserSpecialInfo.h"

vmsBrowserSpecialInfo::vmsBrowserSpecialInfo()
{
	m_vUrls.reserve (100);
}

vmsBrowserSpecialInfo::~vmsBrowserSpecialInfo()
{

}

vmsBrowserSpecialInfo& vmsBrowserSpecialInfo::o()
{
	static vmsBrowserSpecialInfo _obj;
	return _obj;
}

void vmsBrowserSpecialInfo::AddUrl(const UrlInfo &url)
{
	vmsCriticalSectionAutoLock csal (&m_csUrls);
	m_vUrls.push_back (url);
}

void vmsBrowserSpecialInfo::Lock()
{
	EnterCriticalSection (&m_csUrls);
}

void vmsBrowserSpecialInfo::Unlock()
{
	LeaveCriticalSection (&m_csUrls);
}

int vmsBrowserSpecialInfo::findUrlIndex(LPCSTR pszUrl) const
{
	for (size_t i = 0; i < m_vUrls.size (); i++)
	{
		if (m_vUrls [i].strUrl == pszUrl)
			return i;
	}

	return -1;
}

vmsBrowserSpecialInfo::UrlInfo* vmsBrowserSpecialInfo::getUrlInfo(int nIndex)
{
	assert (nIndex >= 0 && nIndex < m_vUrls.size ());
	if (nIndex < 0 || nIndex >= m_vUrls.size ())
		return NULL;
	return &m_vUrls [nIndex];
}

void vmsBrowserSpecialInfo::RemoveUrlInfo(int nIndex)
{
	vmsCriticalSectionAutoLock csal (&m_csUrls);
	assert (nIndex >= 0 && nIndex < m_vUrls.size ());
	if (nIndex < 0 || nIndex >= m_vUrls.size ())
		return;
	m_vUrls.erase (m_vUrls.begin () + nIndex);
}
