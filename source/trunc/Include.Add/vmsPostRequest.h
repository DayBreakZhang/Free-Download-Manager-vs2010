/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSPOSTREQUEST_H__025232FA_DD3A_4CD2_B152_C539CEDDC6FA__INCLUDED_)
#define AFX_VMSPOSTREQUEST_H__025232FA_DD3A_4CD2_B152_C539CEDDC6FA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <WinInet.h>

class vmsPostRequest  
{
public:
	struct ProxyInfo
	{
		tstring tstrAddr;
		tstring tstrUserName;
		tstring tstrPassword;
	};
public:
	void Close();
	static BOOL MyInternetWriteFile (HINTERNET hFile, LPCVOID lpBuffer, DWORD dwToWrite);
	BOOL ReadResponse (LPVOID pData, DWORD dwToRead, LPDWORD pdwRead);
	BOOL Send (LPCTSTR ptszServer, LPCTSTR ptszFilePath, std::string *pstrResponse);
	BOOL SendMultipart (LPCTSTR ptszServer, LPCTSTR ptszFilePath, std::string *pstrResponse = NULL);
	
	void AddPart (LPCSTR ptszName, LPCSTR ptszFileName, LPCVOID pData, DWORD dwSize, bool bFreeData = false);
	void RemoveAllParts();
	BOOL Send (LPCTSTR ptszServer, LPCTSTR ptszFilePath, LPCVOID pvData, DWORD dwDataSize, LPCTSTR ptszContentType, std::string *pstrResponse);

	static std::string HttpEncode (LPCSTR psz);

	void setProxyInfo (ProxyInfo *pProxyInfo) {m_pProxyInfo = pProxyInfo;}

	vmsPostRequest(LPCTSTR ptszUserAgent = NULL, ProxyInfo *pProxyInfo = NULL);
	virtual ~vmsPostRequest();

protected:
	static void PostInitWinInetHandle (HINTERNET hInet);

protected:
	ProxyInfo *m_pProxyInfo;
	tstring m_tstrUserAgent;
	void ApplyProxyAuth (HINTERNET hInet);
	HINTERNET m_hInet, m_hConnect, m_hRequest;
	struct _inc_mpart_item {
		std::string strName;
		std::string strFileName;
		LPCVOID pData;
		DWORD dwSize;
		bool bFreeData;
	};
	std::vector <_inc_mpart_item> m_vParts;
public:
	HINTERNET getResponseHandle(void) const;
};

#endif 
