/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSWINSOCKHTTPTRAFFICCOLLECTOR_H__1E4D3EA1_5BF1_4BA3_9F7D_4DEBD43EC486__INCLUDED_)
#define AFX_VMSWINSOCKHTTPTRAFFICCOLLECTOR_H__1E4D3EA1_5BF1_4BA3_9F7D_4DEBD43EC486__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"

class vmsWinSockHttpTrafficCollector 
{
public:
	void OnBeforeCloseSocket (SOCKET s);
	void OnDataRcvd (SOCKET s, const char *pData, int nLen);
	void OnDataSent (SOCKET s, const char *pData, int nLen);

public:
	vmsWinSockHttpTrafficCollector(vmsHttpTrafficCollector *pHttpTraffic);
	virtual ~vmsWinSockHttpTrafficCollector();

protected:
	vmsHttpTrafficCollector *m_pHttpTraffic;
};

#endif 
