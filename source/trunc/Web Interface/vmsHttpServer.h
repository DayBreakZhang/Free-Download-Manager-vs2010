/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPSERVER_H__5D9B07CF_37C4_4AC2_BD71_24BA28CCCE21__INCLUDED_)
#define AFX_VMSHTTPSERVER_H__5D9B07CF_37C4_4AC2_BD71_24BA28CCCE21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <winsock.h>
#include <vector>

class vmsHttpResourceContainer;
class vmsHttpConnection;

class vmsHttpServer  
{
public:
	
	BOOL Start ();
	
	void set_Port (unsigned short nPort);
	unsigned short get_Port();
	
	void Shutdown();
	
	vmsHttpResourceContainer* get_ResourceContainer();
	
	vmsHttpServer(vmsHttpResourceContainer* pResources);
	virtual ~vmsHttpServer();

protected:
	vmsHttpResourceContainer* m_pResources;
	
	HANDLE m_hStopEvent;
	
	BOOL m_bServerRunning;
	
	static DWORD WINAPI _threadServer (LPVOID lp);
	
	SOCKET m_sServer;
	
	unsigned short m_nPort;
	
	std::vector <vmsHttpConnection*> m_vConnections;
};

#endif 
