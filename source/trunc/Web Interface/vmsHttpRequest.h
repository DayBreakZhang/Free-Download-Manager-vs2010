/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPREQUEST_H__C1D057E5_A9E0_4E3E_A0E1_AD3AF1A663C8__INCLUDED_)
#define AFX_VMSHTTPREQUEST_H__C1D057E5_A9E0_4E3E_A0E1_AD3AF1A663C8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <winsock.h>
#include <string>

class vmsHttpRequest  
{
public:
	LPCSTR get_Auth ();
	
	BOOL Receive (SOCKET sConnection);
	
	LPCSTR get_RequestType ();
	
	LPCSTR get_ResourcePath();
	
	vmsHttpRequest();
	virtual ~vmsHttpRequest();

protected:
	
	std::string ExtractString (LPCSTR &psz);
	BOOL IsCLRF (LPCSTR psz);
	BOOL IsBlank (char c);
	
	std::string m_strRequestType;
	std::string m_strHttpVersion;
	std::string m_strResourcePath;
	
	std::string m_strAuth;

	BOOL ParseRequest (LPCSTR pszReq);
};

#endif 
