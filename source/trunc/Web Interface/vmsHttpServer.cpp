/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpServer.h"
#include "vmsHttpConnection.h"
#include "vmsHttpResourceContainer.h"

vmsHttpServer::vmsHttpServer(vmsHttpResourceContainer* pResources)
{
	m_sServer = INVALID_SOCKET;
	m_hStopEvent = CreateEvent (NULL, TRUE, FALSE, NULL);
	m_nPort = 80;
	m_pResources = pResources;
	m_bServerRunning = FALSE;
}

vmsHttpServer::~vmsHttpServer()
{
	Shutdown ();
	CloseHandle (m_hStopEvent);
}

BOOL vmsHttpServer::Start()
{
	if (m_bServerRunning)
		return FALSE;

	
	m_sServer = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (m_sServer == INVALID_SOCKET)
		return FALSE;

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl (INADDR_ANY);
	addr.sin_port = htons (m_nPort);

	BOOL so_opt_val = TRUE;
	setsockopt (m_sServer, SOL_SOCKET, SO_REUSEADDR, (char*)&so_opt_val, sizeof (so_opt_val));

	if (bind (m_sServer, (sockaddr*) &addr, sizeof (addr)))
		return FALSE;

	m_bServerRunning = TRUE;

	
	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadServer, this, 0, &dw));

	return TRUE;
}

DWORD WINAPI vmsHttpServer::_threadServer(LPVOID lp)
{
	vmsHttpServer *pthis = (vmsHttpServer*) lp;

	ULONG ul = 1;
	ioctlsocket (pthis->m_sServer, FIONBIO, &ul);

	while (WaitForSingleObject (pthis->m_hStopEvent, 10) == WAIT_TIMEOUT)
	{
		

		if (listen (pthis->m_sServer, SOMAXCONN))
			continue;	

		SOCKET sConnection = accept (pthis->m_sServer, NULL, 0);
		if (sConnection == INVALID_SOCKET)
			continue;

		
		vmsHttpConnection *connection = new vmsHttpConnection (pthis);
		connection->Attach (sConnection);
		pthis->m_vConnections.push_back (connection);
	}

	

	for (int i = 0; i < pthis->m_vConnections.size (); i++)
		delete pthis->m_vConnections [i];
	pthis->m_vConnections.clear ();

	ul = 0;
	ioctlsocket (pthis->m_sServer, FIONBIO, &ul);

	shutdown (pthis->m_sServer, 2);
	closesocket (pthis->m_sServer);
	pthis->m_sServer = INVALID_SOCKET;

	pthis->m_bServerRunning = FALSE;
	return 0;
}

vmsHttpResourceContainer* vmsHttpServer::get_ResourceContainer()
{
	return m_pResources;
}

void vmsHttpServer::Shutdown()
{
	if (m_bServerRunning == FALSE)
		return;

	SetEvent (m_hStopEvent);
	while (m_bServerRunning)
		Sleep (10);
	ResetEvent (m_hStopEvent);
}

unsigned short vmsHttpServer::get_Port()
{
	return m_nPort;
}

void vmsHttpServer::set_Port(unsigned short nPort)
{
	m_nPort = nPort;
}
