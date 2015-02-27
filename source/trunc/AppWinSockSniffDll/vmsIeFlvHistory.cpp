/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsIeFlvHistory.h"
#include <wininet.h>
#include "vmsHttpTrafficCollector.h"

vmsIeFlvHistory::vmsIeFlvHistory()
{

}

vmsIeFlvHistory::~vmsIeFlvHistory()
{

}

void vmsIeFlvHistory::Gather()
{
	m_vItems.clear ();

	DWORD dwSize = 0; DWORD dwBufSize = 0;
	FindFirstUrlCacheEntry (NULL, NULL, &dwSize);
	if (dwSize == 0)
		return;
	
	INTERNET_CACHE_ENTRY_INFO *cei = (INTERNET_CACHE_ENTRY_INFO*) new BYTE [(dwBufSize = dwSize)+1];
	cei->dwStructSize = dwSize;
	HANDLE hFind = FindFirstUrlCacheEntry (NULL, cei, &dwSize);
	((LPBYTE)cei) [dwSize] = 0; 
	
	while (cei != NULL)
	{
		if ((cei->CacheEntryType & COOKIE_CACHE_ENTRY) == 0 &&
				cei->lpHeaderInfo != NULL && cei->dwHeaderInfoSize != 0)
		{
			LPCSTR pszUrl2 = cei->lpszSourceUrlName;
			if (strncmp (pszUrl2, "Visited: ", 9) == 0)
				pszUrl2 += 9;
			pszUrl2 = pszUrl2 + 0;

			LPCSTR pszCT = strstr (cei->lpHeaderInfo, "Content-Type:");
			if (pszCT)
			{
				pszCT += 13+1;
				string strCT;
				while (!isspace ((BYTE)*pszCT) && cei->dwHeaderInfoSize > (pszCT - cei->lpHeaderInfo))
					strCT += *pszCT++;
				if (vmsHttpTrafficCollector::isFlashVideoCT (strCT.c_str ()))
				{
					vmsBrowserFlvHistory::Item item;
					item.strUrl = pszUrl2;
					item.strHttpResponse = (LPCSTR)cei->lpHeaderInfo;
					item.strContentType = strCT;
					m_vItems.push_back (item);
				}
			}
		}
		
		dwSize = 0;
		FindNextUrlCacheEntry (hFind, NULL, &dwSize);

		if (dwSize)
		{
			if (dwBufSize < dwSize)
			{
				delete [] (LPBYTE) cei;
				cei = (INTERNET_CACHE_ENTRY_INFO*) new BYTE [(dwBufSize = dwSize)+1];
				((LPBYTE)cei) [dwBufSize] = 0;
			}

			cei->dwStructSize = dwSize;
			FindNextUrlCacheEntry (hFind, cei, &dwSize);
			((LPBYTE)cei) [dwSize] = 0; 
		}
		else
		{
			delete [] (LPBYTE) cei;
			cei = NULL;
		}
	}
	
	FindCloseUrlCache (hFind);
}
