/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPRESPONSE_H__B1739215_2E5D_465A_B436_CF3F15A6775E__INCLUDED_)
#define AFX_VMSHTTPRESPONSE_H__B1739215_2E5D_465A_B436_CF3F15A6775E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <winsock.h>
#include <string>

class vmsHttpResponse  
{
public:
	
	void set_HttpVersion (LPCSTR psz);
	
	void set_ResponseCode (LPCSTR psz);
	
	
	
	void set_Body (LPCVOID pv, DWORD dwSize);
	
	BOOL Send (SOCKET sConnection);

	vmsHttpResponse();
	virtual ~vmsHttpResponse();

protected:
	std::string m_strHttpVersion;
	std::string m_strResponseCode;
	LPVOID m_pBody;
	DWORD m_dwBodySize;
};

#endif 
