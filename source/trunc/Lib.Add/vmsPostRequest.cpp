/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifdef DEBUG_SHOW_SERVER_REQUESTS
	static int _c = 0;
#endif

#define vmsPostRequest_USE_NO_HTTPSENDREQUESTEX

vmsPostRequest::vmsPostRequest(LPCTSTR ptszUserAgent, ProxyInfo *pProxyInfo) : 
	m_pProxyInfo (pProxyInfo)
{
	m_hInet = m_hConnect = m_hRequest = NULL;
	if (ptszUserAgent)
		m_tstrUserAgent = ptszUserAgent;
}

vmsPostRequest::~vmsPostRequest()
{
	Close ();
	RemoveAllParts ();
}

BOOL vmsPostRequest::Send(LPCTSTR ptszServer, LPCTSTR ptszFilePath, LPCVOID pvData, DWORD dwDataSize, LPCTSTR ptszContentType, std::string *pstrResponse)
{
	Close ();

	DWORD dwAccessType = INTERNET_OPEN_TYPE_PRECONFIG;
	if (m_pProxyInfo)
		dwAccessType = m_pProxyInfo->tstrAddr.empty () ? INTERNET_OPEN_TYPE_DIRECT : INTERNET_OPEN_TYPE_PROXY;
	m_hInet = InternetOpen (m_tstrUserAgent.c_str (), dwAccessType,
		dwAccessType == INTERNET_OPEN_TYPE_PROXY ? m_pProxyInfo->tstrAddr.c_str () : NULL, NULL, 0);
	if (m_hInet == NULL)
		return FALSE;

	PostInitWinInetHandle (m_hInet);

	m_hConnect = InternetConnect (m_hInet, ptszServer, INTERNET_DEFAULT_HTTP_PORT, 
		NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL);
	if (m_hConnect == NULL)
		return FALSE;

#ifdef DEBUG_SHOW_SERVER_REQUESTS
	TCHAR tszTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, tszTmpPath);
	TCHAR tszTmpFile [MAX_PATH];
	_stprintf (tszTmpFile, _T ("%s\\si_serv_req_%d.txt"), tszTmpPath, _c++);
	HANDLE hLog = CreateFile (tszTmpFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	DWORD dwLogWritten;
	#define LOG_REQ(s) WriteFile (hLog, s, strlen (s), &dwLogWritten, NULL)
	#define LOG_REQ_OPEN	CloseHandle (hLog); ShellExecute (NULL, "open", tszTmpFile, NULL, NULL, SW_SHOW);
	char szTmp [10000] = ""; DWORD dwTmp = 10000;
	#define LOG_REQ_HTTP_HDRS *szTmp = 0; HttpQueryInfo (m_hRequest, HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS, szTmp, &dwTmp, 0); LOG_REQ (szTmp);
	#define LOG_REQ_ALL LOG_REQ_HTTP_HDRS; LOG_REQ ((LPCSTR)pvData);
	#define LOG_RESP_HTTP_HDRS *szTmp = 0; HttpQueryInfo (m_hRequest, HTTP_QUERY_RAW_HEADERS_CRLF, szTmp, &dwTmp, 0); LOG_REQ (szTmp);
	DWORD dwErr;
#else
	#define LOG_REQ(s) 
	#define LOG_REQ_OPEN
	#define LOG_REQ_HTTP_HDRS
	#define LOG_RESP_HTTP_HDRS
	#define LOG_REQ_ALL
#endif

	m_hRequest = HttpOpenRequest (m_hConnect, _T ("POST"), ptszFilePath, NULL, NULL, NULL,
		INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_UI | 
		INTERNET_FLAG_PRAGMA_NOCACHE, 0);
	if (m_hRequest == NULL)
	{
		DWORD dwErr = GetLastError ();
		LOG_REQ ("SERVER FAILURE\r\n");
		LOG_REQ_OPEN;
		SetLastError (dwErr);
		return FALSE;
	}

	ApplyProxyAuth (m_hRequest);

	if (ptszContentType)
	{
		tstring tstr = _T ("Content-Type: ");
		tstr += ptszContentType;
		tstr += _T ("\r\n");
		HttpAddRequestHeaders (m_hRequest, tstr.c_str (), tstr.length (), HTTP_ADDREQ_FLAG_ADD|HTTP_ADDREQ_FLAG_REPLACE);
	}

#ifdef vmsPostRequest_USE_NO_HTTPSENDREQUESTEX
	if (FALSE == HttpSendRequest (m_hRequest, NULL, 0, (LPVOID)pvData, dwDataSize))
		return FALSE;
#else
	INTERNET_BUFFERS buffs;
	ZeroMemory (&buffs, sizeof (buffs));
	buffs.dwStructSize = sizeof (buffs);
	buffs.dwBufferTotal = dwDataSize;

	if (FALSE == HttpSendRequestEx (m_hRequest, &buffs, NULL, 0, 0))
	{
		PUL (" >>> HttpSendRequestEx failed.");
		LOG_REQ ("SERVER FAILURE\r\n");
		LOG_REQ_OPEN;
		return FALSE;
	}

	if (FALSE == MyInternetWriteFile (m_hRequest, pvData, dwDataSize))
	{
		PUL (" >>> MyInternetWriteFile failed.");
		LOG_REQ ("SERVER FAILURE\r\n");
		LOG_REQ_OPEN;
		return FALSE;
	}

	if (FALSE == HttpEndRequest (m_hRequest, NULL, 0, 0))
	{
		PUL (" >>> HttpEndRequest failed.");
		LOG_REQ_ALL;
		LOG_REQ ("\r\n\r\n");
		LOG_RESP_HTTP_HDRS;
		LOG_REQ ("SERVER FAILURE\r\n");
		LOG_REQ_OPEN;
		return FALSE;
	}
#endif

	LOG_REQ_ALL;
	LOG_REQ ("\r\n\r\n");
	LOG_RESP_HTTP_HDRS;

	if (pstrResponse)
	{
		*pstrResponse = "";
		char sz [1025];
		DWORD dw;		
		while (InternetReadFile (m_hRequest, sz, sizeof (sz) - 1, &dw) && dw != 0)
		{
			sz [dw] = 0;
			(*pstrResponse) += sz;
		}
	}

	LOG_REQ_OPEN;
	return TRUE;
}

void vmsPostRequest::RemoveAllParts()
{
	for (size_t i = 0; i < m_vParts.size (); i++)
	{
		if (m_vParts [i].bFreeData)
			delete [] (LPVOID)m_vParts [i].pData;
	}

	m_vParts.clear ();
}

void vmsPostRequest::AddPart(LPCSTR pszName, LPCSTR pszFileName, LPCVOID pData, DWORD dwSize, bool bFreeData)
{
	assert (pszName != NULL);
	assert (pData != NULL);

	_inc_mpart_item item;
	item.strName = pszName;
	if (pszFileName)
		item.strFileName = pszFileName;
	item.pData = pData;
	item.dwSize = dwSize;
	item.bFreeData = bFreeData;
	m_vParts.push_back (item);
}

BOOL vmsPostRequest::SendMultipart(LPCTSTR ptszServer, LPCTSTR ptszFilePath, std::string *pstrResponse)
{
	Close ();

	USES_CONVERSION;

#ifdef DEBUG_SHOW_SERVER_REQUESTS
	TCHAR tszTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, tszTmpPath);
	TCHAR tszTmpFile [MAX_PATH];
	_stprintf (tszTmpFile, _T ("%s\\si_serv_req_%d.txt"), tszTmpPath, _c++);
	HANDLE hLog = CreateFile (tszTmpFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, 0, NULL);
	DWORD dwLogWritten;
	#define LOG_REQ_BUFFER(buf, size) WriteFile (hLog, buf, size, &dwLogWritten, NULL)
	#define LOG_REQ(s) LOG_REQ_BUFFER (s, strlen (s))
	#define LOG_REQ_OPEN	CloseHandle (hLog); ShellExecute (NULL, "open", tszTmpFile, NULL, NULL, SW_SHOW);
	char szTmp [10000] = ""; DWORD dwTmp = 10000;
	#define LOG_REQ_HTTP_HDRS *szTmp = 0; HttpQueryInfo (m_hRequest, HTTP_QUERY_RAW_HEADERS_CRLF | HTTP_QUERY_FLAG_REQUEST_HEADERS, szTmp, &dwTmp, 0); LOG_REQ (szTmp);
	#define LOG_REQ_DATA_BUFFER LOG_REQ_BUFFER (pbSendData, pbSendDataPos-pbSendData)
	#define LOG_REQ_ALL LOG_REQ_HTTP_HDRS; LOG_REQ_DATA_BUFFER;
	#define LOG_RESP_HTTP_HDRS *szTmp = 0; HttpQueryInfo (m_hRequest, HTTP_QUERY_RAW_HEADERS_CRLF, szTmp, &dwTmp, 0); LOG_REQ (szTmp);
#else
	#define LOG_REQ(s) 
	#define LOG_REQ_OPEN
	#define LOG_REQ_DATA_BUFFER
	#define LOG_REQ_HTTP_HDRS
	#define LOG_RESP_HTTP_HDRS
	#define LOG_REQ_ALL
#endif

	LPBYTE pbSendData = NULL; LPBYTE pbSendDataPos = NULL;
	#define ADD_DATA_TO_SEND(data,len) {memcpy (pbSendDataPos, data, len); pbSendDataPos += len;}
	#define ADD_STRING_TO_SEND(s) ADD_DATA_TO_SEND (s, strlen (s));

	if (m_vParts.size () == 0)
		return FALSE;

	DWORD dwAccessType = INTERNET_OPEN_TYPE_PRECONFIG;
	if (m_pProxyInfo)
		dwAccessType = m_pProxyInfo->tstrAddr.empty () ? INTERNET_OPEN_TYPE_DIRECT : INTERNET_OPEN_TYPE_PROXY;
	m_hInet = InternetOpen (m_tstrUserAgent.c_str (), dwAccessType,
		dwAccessType == INTERNET_OPEN_TYPE_PROXY ? m_pProxyInfo->tstrAddr.c_str () : NULL, NULL, 0);
	if (m_hInet == NULL)
		return FALSE;

	PostInitWinInetHandle (m_hInet);
	
	m_hConnect = InternetConnect (m_hInet, ptszServer, INTERNET_DEFAULT_HTTP_PORT, 
		NULL, NULL, INTERNET_SERVICE_HTTP, 0, NULL);
	if (m_hConnect == NULL)
	{
		LOG_REQ ("SERVER CONNECT FAILURE\r\n");
		LOG_REQ_OPEN;
		return FALSE;
	}
	
	m_hRequest = HttpOpenRequest (m_hConnect, _T ("POST"), ptszFilePath, NULL, NULL, NULL,
		INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_KEEP_CONNECTION | INTERNET_FLAG_NO_UI | 
		INTERNET_FLAG_PRAGMA_NOCACHE, 0);
	if (m_hRequest == NULL)
	{
		LOG_REQ ("SERVER OPEN REQUEST FAILURE\r\n");
		LOG_REQ_OPEN;
		return FALSE;
	}

	ApplyProxyAuth (m_hRequest);

	std::string strLabel = "---------------------------284583012225az7";

	TCHAR tszHdr [10000] = _T ("Content-Type: multipart/form-data; boundary=");
	_tcscat (tszHdr, A2CT (strLabel.c_str ()));

	

	INTERNET_BUFFERS buffs;
	ZeroMemory (&buffs, sizeof (buffs));
	buffs.dwStructSize = sizeof (buffs);
	buffs.lpcszHeader = tszHdr;
	buffs.dwHeadersLength = buffs.dwHeadersTotal = _tcslen (tszHdr);
	buffs.dwBufferTotal = strLabel.length () + 4; 

	for (int step = 0; step < 2; step++)
	for (size_t i = 0; i < m_vParts.size (); i++)
	{
		_inc_mpart_item &item = m_vParts [i];

		CHAR sz [10000];
		if (item.strFileName.empty () == false)
		{
			sprintf (sz, "\
--%s\r\n\
Content-Disposition: form-data; name=\"%s\"; filename=\"%s\"\r\n\
Content-Type: application/octet-stream\r\n\r\n",
				strLabel.c_str (), item.strName.c_str (), item.strFileName.c_str ());
		}
		else
		{
			sprintf (sz, "--%s\r\nContent-Disposition: form-data; name=\"%s\"\r\n\r\n",
				strLabel.c_str (), item.strName.c_str ());
		}

		if (step == 0)
		{
			buffs.dwBufferTotal += strlen (sz) + m_vParts [i].dwSize + 2 ;
			continue;
		}
		else if (i == 0)
		{
	#ifndef vmsPostRequest_USE_NO_HTTPSENDREQUESTEX
			if (!HttpSendRequestEx (m_hRequest, &buffs, NULL, HSR_INITIATE, 0))
			{
				PUL (" >>> HttpSendRequestEx failed.");
				#ifdef DEBUG_SHOW_SERVER_REQUESTS
					LOG_REQ ("SERVER FAILURE\r\nData buffer state:\r\n");
					LOG_REQ_DATA_BUFFER;
					LOG_REQ_OPEN;
				#endif
				return FALSE;
			}
	#endif

			pbSendData = new BYTE [buffs.dwBufferTotal+1];
			pbSendDataPos = pbSendData;
		}

		ADD_STRING_TO_SEND (sz);

		ADD_DATA_TO_SEND (item.pData, item.dwSize);

		ADD_STRING_TO_SEND ("\r\n");
	}

	ADD_STRING_TO_SEND (strLabel.c_str ());

	ADD_STRING_TO_SEND ("--\r\n");

#ifdef vmsPostRequest_USE_NO_HTTPSENDREQUESTEX
	assert (pbSendDataPos-pbSendData == buffs.dwBufferTotal);
	if (FALSE == HttpSendRequest (m_hRequest, buffs.lpcszHeader, buffs.dwHeadersLength, pbSendData, pbSendDataPos-pbSendData))
		return FALSE;
#else
	if (FALSE == MyInternetWriteFile (m_hRequest, pbSendData, pbSendDataPos-pbSendData))
	{
		PUL (" >>> MyInternetWriteFile_5 failed.");
		LOG_REQ ("SERVER FAILURE\r\nData buffer state:\r\n");
		LOG_REQ_DATA_BUFFER;
		LOG_REQ_OPEN;
		delete [] pbSendData;
		return FALSE;
	}

	if (FALSE == HttpEndRequest (m_hRequest, NULL, 0, 0))
	{
		PUL (" >>> HttpEndRequest failed.");
		LOG_REQ_ALL;
		LOG_REQ ("\r\n\r\n");
		LOG_RESP_HTTP_HDRS;
		LOG_REQ ("SERVER FAILURE\r\n");
		LOG_REQ_OPEN;
		delete [] pbSendData;
		return FALSE;
	}
#endif

	LOG_REQ_ALL;
	LOG_REQ ("\r\n\r\n");
	LOG_RESP_HTTP_HDRS;

	delete [] pbSendData;

	if (pstrResponse)
	{
		*pstrResponse = "";
		char sz [1025];
		DWORD dw;		
		while (InternetReadFile (m_hRequest, sz, sizeof (sz) - 1, &dw) && dw != 0)
		{
			sz [dw] = 0;
			(*pstrResponse) += sz;
		}
	}

	LOG_REQ_OPEN;

	return TRUE;
}

BOOL vmsPostRequest::Send(LPCTSTR ptszServer, LPCTSTR ptszFilePath, std::string *pstrResponse)
{
	std::string str;
	for (size_t i = 0; i < m_vParts.size (); i++)
	{
		if (i)
			str += "&";
		str += HttpEncode (m_vParts [i].strName.c_str ());
		str += "=";
		str += HttpEncode ((LPCSTR)m_vParts [i].pData);
	}
	return Send (ptszServer, ptszFilePath, str.c_str (), str.length (), _T ("application/x-www-form-urlencoded"), pstrResponse);
}

std::string vmsPostRequest::HttpEncode(LPCSTR psz)
{
	if (psz == NULL || *psz == 0)
		return "";
		
	std::string str;
		
	while (*psz)
	{
		if (isdigit (*psz) || isalpha (*psz) || 
			*psz == '$' || *psz == '-' || *psz == '_' ||
			*psz == '.' || *psz == '+' || *psz == '!' || 
			*psz == '*' || *psz == '\'' || *psz == '(' ||
			*psz == ')' || *psz == ',')
		{
			str += *psz;
		}
		else
		{
			char sz [4];
			sprintf (sz, "%%%02X", (int)(unsigned char)*psz);
			str += sz;
		}
			
		psz++;
	}
		
	return str;
}

BOOL vmsPostRequest::ReadResponse(LPVOID pData, DWORD dwToRead, LPDWORD pdwRead)
{
	if (m_hRequest == NULL)
		return FALSE;
	return InternetReadFile (m_hRequest, pData, dwToRead, pdwRead);
}

void vmsPostRequest::PostInitWinInetHandle(HINTERNET hInet)
{
	
	BOOL bDisable = TRUE;
	InternetSetOption (hInet, INTERNET_OPTION_DISABLE_AUTODIAL, &bDisable, sizeof (bDisable));

	UINT uTimeout = 2*60*1000;
	InternetSetOption (hInet, INTERNET_OPTION_RECEIVE_TIMEOUT, &uTimeout, sizeof (uTimeout));
	InternetSetOption (hInet, INTERNET_OPTION_SEND_TIMEOUT, &uTimeout, sizeof (uTimeout));
	InternetSetOption (hInet, INTERNET_OPTION_CONNECT_TIMEOUT, &uTimeout, sizeof (uTimeout));
}

BOOL vmsPostRequest::MyInternetWriteFile(HINTERNET hFile, LPCVOID lpBuffer, DWORD dwToWrite)
{
	DWORD dw;
	while (dwToWrite)
	{
		dw = min (dwToWrite, 1024);
		if (FALSE == InternetWriteFile (hFile, lpBuffer, dw, &dw) || dw == 0)
			return FALSE;
		dwToWrite -= dw;
		lpBuffer = (LPCVOID)((DWORD)lpBuffer + dw);
	}
	return TRUE;
}

void vmsPostRequest::ApplyProxyAuth(HINTERNET hInet)
{
	if (!m_pProxyInfo || m_pProxyInfo->tstrUserName.empty ())
		return;
	
	InternetSetOption (hInet, INTERNET_OPTION_PROXY_USERNAME, 
		(LPVOID) m_pProxyInfo->tstrUserName.c_str (), 
		m_pProxyInfo->tstrUserName.length ()+1);
	
	InternetSetOption (hInet, INTERNET_OPTION_PROXY_PASSWORD, 
		(LPVOID) m_pProxyInfo->tstrPassword.c_str (), 
		m_pProxyInfo->tstrPassword.length ()+1);
}

void vmsPostRequest::Close()
{
	if (m_hRequest)
		InternetCloseHandle (m_hRequest);
	if (m_hConnect)
		InternetCloseHandle (m_hConnect);
	if (m_hInet)
		InternetCloseHandle (m_hInet);
	m_hRequest = m_hConnect = m_hInet = NULL;
}

HINTERNET vmsPostRequest::getResponseHandle(void) const
{
	return m_hRequest;
}
