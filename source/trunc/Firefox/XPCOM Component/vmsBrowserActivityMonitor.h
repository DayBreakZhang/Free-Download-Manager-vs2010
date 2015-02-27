/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include <windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <assert.h>
#include <vmsCriticalSection.h>
#include "../../include.add/vmsBrowsersSharedData.h"

class vmsBrowserActivityMonitor
{
public:
	vmsBrowserActivityMonitor(void);
	~vmsBrowserActivityMonitor(void);

protected:
	struct ActivityInfo
	{
		std::wstring wstrUrl;
		DWORD dwTimeLastActivity; 
	};
	std::vector <ActivityInfo> m_vList;
	vmsCriticalSection m_csList;
	HANDLE m_hevShutdown;
	HANDLE m_htJob;
	static DWORD WINAPI _threadJob(LPVOID lp);
	size_t FindItemByUrl(LPCWSTR pwszUrl);
public:
	
	void onDownloadBegin(LPCWSTR pwszUrl);
	void onDownloadEnd(LPCWSTR pwszUrl);
	
	void onActivity(LPCWSTR pwszUrl);
protected:
	vmsBrowsersSharedData m_bsd;
	void CreateNewItem(LPCWSTR pwszUrl);
	void RemoveTimedoutItems(void);
	void RemoveItem(size_t nIndex);
public:
	static vmsBrowserActivityMonitor& o(void);
};

