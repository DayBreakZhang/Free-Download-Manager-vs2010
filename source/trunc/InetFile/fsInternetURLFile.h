/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSINTERNETURLFILE_H__F1F640DC_4992_4104_AB67_5C29AFD245D4__INCLUDED_)
#define AFX_FSINTERNETURLFILE_H__F1F640DC_4992_4104_AB67_5C29AFD245D4__INCLUDED_

#include "fsinet.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsHttpFile.h"
#include "fsFtpFile.h"
#include "fsHttpConnection.h"
#include "fsFtpConnection.h"
#include "fsLocalFile.h"
#include "fsInternetFile2.h"	
#include "fsSpeaking.h"

class fsInternetURLFile : public fsSpeaking  
{
public:
	void SetInterface (LPCSTR psz);
	void set_Charset (LPCSTR psz);
	void set_EnableAutoRedirect (BOOL b);
	fsString GetCookiesFromResponse();
	fsInternetResult OpenAnotherRequestOnServer (LPCSTR pszPath, UINT64 uStartPosition, UINT64 uUploadPartSize, UINT64 uUploadTotalSize);
	void set_UseMultipart (BOOL b);
	fsInternetResult Write (LPBYTE pBuffer, DWORD dwToWrite, DWORD *pdwWritten);
	
	fsInternetResult OpenEx (INTERNET_SCHEME scheme, LPCSTR pszHostName, LPCSTR pszUser,
		LPCSTR pszPassword, INTERNET_PORT port, LPCSTR pszPath, UINT64 uStartPosition, 
		BOOL bSendHTTPBasicAuthImmediately = FALSE, UINT64 uUploadPartSize = _UI64_MAX, 
		UINT64 uUploadTotalSize = _UI64_MAX);
	fsFtpTransferType FtpGetTransferType();
	
	void SetPostData (LPCSTR pszHdrs);
	void SetCookies (LPCSTR pszCookies);
	
	
	
	
	
	void FtpSetDontUseLIST (BOOL b);
	
	
	
	
	
	
	
	
	fsInternetResult Open (INTERNET_SCHEME scheme, LPCSTR pszHostName, LPCSTR pszUser, LPCSTR pszPassword, INTERNET_PORT port, LPCSTR pszPath, UINT64 uStartPosition, BOOL bSendHTTPBasicAuthImmediately = FALSE);
	
	fsInternetResult QuerySize (INTERNET_SCHEME scheme, LPCSTR pszHostName, LPCSTR pszUser, LPCSTR pszPassword, INTERNET_PORT port, LPCSTR pszPath, BOOL bSendHTTPBasicAuthImmediately);
	
	fsInternetResult Read (BYTE *pBuffer, DWORD dwToRead, DWORD *pdwRead);
	
	LPCSTR GetSuggestedFileName();
	fsResumeSupportType IsResumeSupported();
	BOOL GetLastModifiedDate (LPFILETIME pDate);
	BOOL GetContentType (LPSTR pszType);
	LPCSTR GetLastError();
	void FtpSetTransferType (fsFtpTransferType enType);
	void UseFtpPassiveMode (BOOL bUse);
	void UseCookie (BOOL bUse);
	void UseHttp11 (BOOL bUse);
	void SetReferer (LPCSTR pszReferer);
	UINT64 GetFileSize();
	LPCSTR GetServerName();
	fsInternetResult Initialize (class fsInternetSession *pSession, BOOL bAutoDelSession = FALSE);
	
	
	
	void CloseHandle();
	
	void Close();
	
	
	fsInternetURLFile();
	virtual ~fsInternetURLFile();

protected:
	fsString m_strInterface;
	bool isProxySpecified();
	fsString m_strRespFromServer;
	BOOL m_bCatchFromServerResponse;
	static void _InetFileDialogFunc (fsInetFileDialogDirection enDir, LPCSTR pszMsg, LPVOID lp1, LPVOID lp2);
	void FormHttpBasicAuthHdr (LPCSTR pszUser, LPCSTR pszPassword);
#ifndef NOCURL
	void SetupProxyForFile2();
#endif
	bool m_bUseFile2;
#ifndef NOCURL
	fsInternetFile2 m_ifile2;
#endif
	BOOL m_bAutoDelSession;					
	CRITICAL_SECTION m_cs;					
	LPCSTR m_pszLastError;					
	class fsInternetSession* m_pSession;	
	class fsInternetFile* m_pFile;			
	class fsInternetServerConnection *m_pServer;	
	fsFtpConnection m_ftpConnection;		
	fsHttpConnection m_httpConnection;		
	fsHttpFile m_httpFile;					
	fsFtpFile m_ftpFile;					
	fsLocalFile m_localFile;				
};

#endif 
