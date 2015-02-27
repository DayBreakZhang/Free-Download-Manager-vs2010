/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSHTTPCONNECTION_H__8E66E788_A627_4EC6_8570_B28876142D61__INCLUDED_)
#define AFX_FSHTTPCONNECTION_H__8E66E788_A627_4EC6_8570_B28876142D61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsServerConnection.h"
#include "fsinet.h"	

class fsHttpConnection : public fsInternetServerConnection  
{
public:
	
	
	
	
	fsInternetResult Connect (LPCSTR pszServer, LPCSTR pszUser, LPCSTR pszPassword, INTERNET_PORT nPort = INTERNET_DEFAULT_HTTP_PORT);
	fsHttpConnection();
	virtual ~fsHttpConnection();
};

#endif 
