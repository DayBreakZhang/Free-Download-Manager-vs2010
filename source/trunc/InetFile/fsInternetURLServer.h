/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETURLSERVER_H__8100FC18_F1BF_4F7F_B866_0CB57B83B9DD__INCLUDED_)
#define AFX_FSINTERNETURLSERVER_H__8100FC18_F1BF_4F7F_B866_0CB57B83B9DD__INCLUDED_

#include "fsinet.h"	
#include "fsURL.h"	
#include "fsFtpConnection.h"	
#include "fsHttpConnection.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class fsInternetURLServer  
{
public:
	
	fsInternetResult Connect (LPCSTR pszUrl, LPCSTR pszUser, LPCSTR pszPassword, INTERNET_PORT nPort);
	void CloseHandle();
	INTERNET_PORT GetServerPort();
	LPCSTR GetServerName();
	HINTERNET GetHandle();
	fsInternetResult Initialize (fsInternetSession* pSession);

	
	void UseFtpPassiveMode (BOOL bUse);
	
	INTERNET_SCHEME GetScheme();
	
	BOOL IsHttpsServer();
	
	BOOL IsFtpServer();
	
	BOOL IsHttpServer();
	
	fsFtpConnection* GetFtpServer();
	
	fsHttpConnection* GetHttpServer();
	
	fsInternetURLServer();
	virtual ~fsInternetURLServer();

protected:
	INTERNET_SCHEME m_scheme;					
	fsInternetServerConnection* m_pServer;		
	fsHttpConnection m_httpServer;
	fsFtpConnection m_ftpServer;
};

#endif 
