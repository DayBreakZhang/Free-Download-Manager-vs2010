/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpResponse.h"

vmsHttpResponse::vmsHttpResponse()
{
	m_pBody = NULL;
	m_dwBodySize = 0;
}

vmsHttpResponse::~vmsHttpResponse()
{
	set_Body (NULL, 0);
}

BOOL vmsHttpResponse::Send(SOCKET sConnection)
{
	std::string str;
	str = m_strHttpVersion; str += ' '; 
	str += m_strResponseCode; str += "\r\n";
	send (sConnection, str.c_str (), str.length (), 0);

	if (strncmp (m_strResponseCode.c_str (), "401 ", 4) == 0)
	{
		str = "WWW-Authenticate: Basic realm=\"FDM Remote control server\"\r\n";
		send (sConnection, str.c_str (), str.length (), 0);
	}

	str = "Content-Length: ";
	char sz [50];
	itoa (m_dwBodySize, sz, 10);
	str += sz; str += "\r\n";
	send (sConnection, str.c_str (), str.length (), 0);

	send (sConnection, "\r\n", 2, 0);

	if (m_pBody)
	{
		LPBYTE pb = (LPBYTE)m_pBody;
		DWORD dw = m_dwBodySize;
		while (dw)
		{
			int n = dw > 1000 ? 1000 : dw;
			n = send (sConnection, (LPSTR)pb, n, 0);
			if (n == 0)
				return FALSE;
			if (n == INVALID_SOCKET)
				return FALSE;
			pb += n;
			dw -= n;
		}
	}

	return TRUE;
}

void vmsHttpResponse::set_HttpVersion(LPCSTR psz)
{
	m_strHttpVersion = psz;
}

void vmsHttpResponse::set_ResponseCode(LPCSTR psz)
{
	m_strResponseCode = psz;
}

void vmsHttpResponse::set_Body(LPCVOID pv, DWORD dwSize)
{
	if (m_pBody)
		delete [] m_pBody;

	m_pBody = pv && dwSize ? new BYTE [dwSize] : NULL;
	m_dwBodySize = m_pBody ? dwSize : 0;

	if (m_pBody)
		CopyMemory (m_pBody, pv, dwSize);
}
