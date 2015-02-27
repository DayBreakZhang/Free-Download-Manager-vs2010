/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "fsInternetURLServer.h"

fsInternetURLServer::fsInternetURLServer()
{
	m_pServer = NULL;
	m_scheme = INTERNET_SCHEME_UNKNOWN;
}

fsInternetURLServer::~fsInternetURLServer()
{

}

fsInternetResult fsInternetURLServer::Connect(LPCSTR pszUrl, LPCSTR pszUser, LPCSTR pszPassword, INTERNET_PORT nPort)
{
	fsInternetResult ir;

	m_httpServer.CloseHandle ();
	m_ftpServer.CloseHandle ();

	fsURL url;

	
	ir = url.Crack (pszUrl);
	if (ir != IR_SUCCESS)
		return ir;

	m_scheme = url.GetInternetScheme (); 
	switch (m_scheme)
	{
		case INTERNET_SCHEME_HTTP:
		case INTERNET_SCHEME_HTTPS:
			m_pServer = &m_httpServer;	
			break;

		case INTERNET_SCHEME_FTP:
			m_pServer = &m_ftpServer;	
			break;

		default:
			return IR_BADURL;
	}

	return m_pServer->Connect (url.GetHostName (), pszUser ? pszUser : url.GetUserName (),
		pszPassword ? pszPassword : url.GetPassword (), nPort);
}

HINTERNET fsInternetURLServer::GetHandle()
{
	return m_pServer->GetHandle ();
}

BOOL fsInternetURLServer::IsHttpServer()
{
	return m_scheme == INTERNET_SCHEME_HTTP;
}

BOOL fsInternetURLServer::IsFtpServer()
{
	return m_scheme == INTERNET_SCHEME_FTP;
}

fsHttpConnection* fsInternetURLServer::GetHttpServer()
{
	return &m_httpServer;
}

fsFtpConnection* fsInternetURLServer::GetFtpServer()
{
	return &m_ftpServer;
}

BOOL fsInternetURLServer::IsHttpsServer()
{
	return m_scheme == INTERNET_SCHEME_HTTPS;
}

INTERNET_SCHEME fsInternetURLServer::GetScheme()
{
	return m_scheme;
}

LPCSTR fsInternetURLServer::GetServerName()
{
	return m_pServer ? m_pServer->GetServerName () : NULL;
}

INTERNET_PORT fsInternetURLServer::GetServerPort()
{
	return m_pServer ? m_pServer->GetServerPort () : (INTERNET_PORT) 0;
}

fsInternetResult fsInternetURLServer::Initialize(fsInternetSession *pSession)
{
	m_httpServer.Initialize (pSession);
	m_ftpServer.Initialize (pSession);

	return IR_SUCCESS;
}

void fsInternetURLServer::CloseHandle()
{
	m_ftpServer.CloseHandle ();
	m_httpServer.CloseHandle ();
}

void fsInternetURLServer::UseFtpPassiveMode(BOOL bUse)
{
	m_ftpServer.UsePassiveMode (bUse);
}
