/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpConnection.h"
#include "vmsHttpResponse.h"
#include "vmsHttpResourceContainer.h"
#include "vmsHttpServer.h"

vmsHttpConnection::vmsHttpConnection(vmsHttpServer* pServer)
{
	m_pServer = pServer;
	m_sConnection = INVALID_SOCKET;
}

vmsHttpConnection::~vmsHttpConnection()
{
	Shutdown ();
}

void vmsHttpConnection::Attach(SOCKET sConnection)
{
	m_sConnection = sConnection;

	DWORD dw;
	CloseHandle (
		CreateThread (NULL, 0, _threadConnection, this, 0, &dw));
}

DWORD WINAPI vmsHttpConnection::_threadConnection(LPVOID lp)
{
	vmsHttpConnection *pthis = (vmsHttpConnection*) lp;

	

	if (FALSE == pthis->m_request.Receive (pthis->m_sConnection))
	{
		pthis->Shutdown ();
		return 1;
	}

	

	vmsHttpResponse response;

	

	response.set_HttpVersion ("HTTP/1.1");
	response.set_ResponseCode ("200 OK");
	response.set_Body (NULL, 0);

	

	pthis->m_pServer->get_ResourceContainer ()->ProcessRequest (pthis->m_request,
		response);

	

	if (FALSE == response.Send (pthis->m_sConnection))
	{
		pthis->Shutdown ();
		return 1;
	}

	pthis->Shutdown ();	
	return 0;
}

void vmsHttpConnection::Shutdown()
{
	if (m_sConnection != INVALID_SOCKET)
	{
		shutdown (m_sConnection, 2);
		closesocket (m_sConnection);
		m_sConnection = INVALID_SOCKET;
	}
}
