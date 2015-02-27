/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsHttpRequest.h"
#include "base64.c"

vmsHttpRequest::vmsHttpRequest()
{

}

vmsHttpRequest::~vmsHttpRequest()
{

}

BOOL vmsHttpRequest::Receive(SOCKET sConnection)
{
	std::string strRequest;

	do 
	{
		char sz [100];

		int n = recv (sConnection, sz, sizeof (sz) - 1, 0);

		if (n == 0)
			return FALSE;	
		if (n == SOCKET_ERROR)
			return FALSE;	

		sz [n] = 0;
		strRequest += sz;
	}
	
	while (lstrcmp (strRequest.c_str () + strRequest.length () - 4, "\r\n\r\n"));

	return ParseRequest (strRequest.c_str ());
}

BOOL vmsHttpRequest::ParseRequest(LPCSTR pszReq)
{
	

	m_strRequestType = ExtractString (pszReq);
	if (m_strRequestType == "")
		return FALSE;
	m_strResourcePath = ExtractString (pszReq);
	if (m_strResourcePath == "")
		return FALSE;
	m_strHttpVersion = ExtractString (pszReq);
	if (m_strHttpVersion == "")
		return FALSE;

	m_strAuth = "";

	LPCSTR psz = strstr (pszReq, "Authorization: ");
	if (psz)
	{
		psz += lstrlen ("Authorization: ");
		if (strnicmp (psz, "Basic ", 6) == 0)
		{
			psz += 6;
			char* psz2 = new char [strlen (psz)*3+1];
			ZeroMemory (psz2, strlen (psz)*3+1);
			base64_decode (psz, psz2);
			m_strAuth = psz2;
			delete [] psz2;
		}
	}
	
	return TRUE;
}

BOOL vmsHttpRequest::IsBlank(char c)
{
	return c == ' ' || c == '\t';
}

BOOL vmsHttpRequest::IsCLRF(LPCSTR psz)
{
	return *psz == '\r' || *psz == '\n';
}

std::string vmsHttpRequest::ExtractString(LPCSTR &psz)
{
	std::string str;

	while (*psz && FALSE == IsBlank (*psz) && FALSE == IsCLRF (psz))
		str += *psz++;

	while (IsBlank (*++psz));

	return str;
}

LPCSTR vmsHttpRequest::get_ResourcePath()
{
	return m_strResourcePath.c_str ();
}

LPCSTR vmsHttpRequest::get_RequestType()
{
	return m_strRequestType.c_str ();
}

LPCSTR vmsHttpRequest::get_Auth()
{
	return m_strAuth.c_str ();
}
