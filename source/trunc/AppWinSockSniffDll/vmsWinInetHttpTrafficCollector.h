/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWININETHTTPTRAFFICCOLLECTOR_H__ED2D8CDA_0BAB_4171_9E57_8CFF985788C7__INCLUDED_)
#define AFX_VMSWININETHTTPTRAFFICCOLLECTOR_H__ED2D8CDA_0BAB_4171_9E57_8CFF985788C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"

class vmsWinInetHttpTrafficCollector  
{
public:
	void OnSendPostData (HINTERNET hInet, LPVOID pData, DWORD dwSize);
	void OnInternetReadFile (HINTERNET hFile, LPVOID lpBuffer, DWORD dwRead);
	void OnInternetCloseHandle (HINTERNET hInternet);
	vmsWinInetHttpTrafficCollector(vmsHttpTrafficCollector *pHttpTraffic);
	virtual ~vmsWinInetHttpTrafficCollector();

protected:
	void CloseDialog (HINTERNET hInet);
	int findNonCacheHandleIndex (HINTERNET hInet) const;
	vmsCriticalSection m_cs_vPostData, m_cs_vNonCacheHandles;
	int findPostDataIndex (HINTERNET hInet) const;
	struct PostData {
		HINTERNET hRequest;
		vector <BYTE> vbData;
	};
	vector <PostData> m_vPostData;
	vector <HINTERNET> m_vNonCacheHandles;
	vmsHttpTrafficCollector *m_pHttpTraffic;
};

#endif 
