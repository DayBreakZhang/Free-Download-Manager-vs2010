/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPCONNECTION_H__BFFC75EC_1905_42F5_9C8C_2E44DCAB84B9__INCLUDED_)
#define AFX_VMSHTTPCONNECTION_H__BFFC75EC_1905_42F5_9C8C_2E44DCAB84B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <winsock.h>
#include "vmsHttpRequest.h"	

class vmsHttpServer;

class vmsHttpConnection  
{
public:
	
	void Attach (SOCKET sConnection);
	
	void Shutdown();
	
	vmsHttpConnection(vmsHttpServer* pServer);
	virtual ~vmsHttpConnection();

protected:
	
	vmsHttpRequest m_request;
	
	
	static DWORD WINAPI _threadConnection (LPVOID lp);
	
	SOCKET m_sConnection;
	
	vmsHttpServer* m_pServer;
};

#endif 
