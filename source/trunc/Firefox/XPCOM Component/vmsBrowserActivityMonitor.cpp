/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsBrowserActivityMonitor.h"

vmsBrowserActivityMonitor::vmsBrowserActivityMonitor(void)
{
	m_hevShutdown = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_htJob = CreateThread (NULL, 0, _threadJob, this, 0, NULL);
}

vmsBrowserActivityMonitor::~vmsBrowserActivityMonitor(void)
{
	SetEvent (m_hevShutdown);
	WaitForSingleObject (m_htJob, INFINITE);
}

DWORD WINAPI vmsBrowserActivityMonitor::_threadJob(LPVOID lp)
{
	vmsBrowserActivityMonitor *pthis = (vmsBrowserActivityMonitor*) lp;

	while (WAIT_TIMEOUT == WaitForSingleObject (pthis->m_hevShutdown, 5*1000))
		pthis->RemoveTimedoutItems ();

	return 0;
}

size_t vmsBrowserActivityMonitor::FindItemByUrl(LPCWSTR pwszUrl)
{
	for (size_t i = 0; i < m_vList.size (); i++)
	{
		if (m_vList [i].wstrUrl == pwszUrl)
			return i;
	}

	return size_t (-1);
}

void vmsBrowserActivityMonitor::onActivity(LPCWSTR pwszUrl)
{
	vmsAUTOLOCKSECTION (m_csList);
	int nIndex = FindItemByUrl (pwszUrl);
	if (nIndex != -1)
	{
		m_vList [nIndex].dwTimeLastActivity = GetTickCount ();
		return;
	}
	CreateNewItem (pwszUrl);
}

void vmsBrowserActivityMonitor::CreateNewItem(LPCWSTR pwszUrl)
{
	m_bsd.ModifyActiveDownloadsCount (1);
	ActivityInfo ai;
	ai.wstrUrl = pwszUrl;
	ai.dwTimeLastActivity = GetTickCount ();
	vmsAUTOLOCKSECTION (m_csList);
	m_vList.push_back (ai);
}

void vmsBrowserActivityMonitor::onDownloadBegin(LPCWSTR pwszUrl)
{
	m_bsd.ModifyActiveDownloadsCount (1);
}

void vmsBrowserActivityMonitor::onDownloadEnd(LPCWSTR pwszUrl)
{
	m_bsd.ModifyActiveDownloadsCount (-1);
}

void vmsBrowserActivityMonitor::RemoveTimedoutItems(void)
{
	DWORD dwNow = GetTickCount ();

	vmsAUTOLOCKSECTION (m_csList);

	for (size_t i = 0; i < m_vList.size (); i++)
	{
		if (dwNow - m_vList [i].dwTimeLastActivity >= 10*1000)
			RemoveItem (i--); 
	}
}

void vmsBrowserActivityMonitor::RemoveItem(size_t nIndex)
{
	assert (nIndex < m_vList.size ());
	m_bsd.ModifyActiveDownloadsCount (-1);
	vmsAUTOLOCKSECTION (m_csList);
	m_vList.erase (m_vList.begin () + nIndex);
}

vmsBrowserActivityMonitor& vmsBrowserActivityMonitor::o(void)
{
	static vmsBrowserActivityMonitor _o;
	return _o;
}
