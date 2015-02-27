/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "downloadproperties.h"
#include "misc.h"

void DecodeURLPath (LPSTR pszPath)
{
	
	char szURL [10000];
	strcpy (szURL, "ftp://f.c");
	if (*pszPath != '/' && *pszPath != '\\')
		strcat (szURL, "/");
	strcat (szURL, pszPath);

	

	fsURL url;
	if (IR_SUCCESS == url.Crack (szURL))
	{
		if (*pszPath != '/' && *pszPath != '\\')		
			strcpy (pszPath, url.GetPath ()+1);
		else
			strcpy (pszPath, url.GetPath ());
	}
}

BOOL fsFilePathFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize)
{
	*pszBuf = 0;

	if (*pszUrl == 0)
		return TRUE;

	
	int end = bUsingFTP ? strlen (pszUrl)-1 : strcspn (pszUrl, "?=#") - 1;

	if (end >= (int)uSize)
		return FALSE;

	

	CopyMemory (pszBuf, pszUrl, end+1);
	pszBuf [end+1] = 0;

	if (bUsingFTP == FALSE && bDecode)
		DecodeURLPath (pszBuf);

	return TRUE;
}

BOOL fsPathFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize)
{
	*pszBuf = 0;

	if (*pszUrl == 0)
		return TRUE;

	int end = bUsingFTP ? strlen (pszUrl)-1 : strcspn (pszUrl, "?#") - 1;

	if (end >= (int)uSize)
		return FALSE;

	CopyMemory (pszBuf, pszUrl, end+1);
	pszBuf [end+1] = 0;

	

	LPSTR pszEnd = max (strrchr (pszBuf, '/'), strrchr (pszBuf, '\\'));

	if (pszEnd == NULL)
		pszEnd = pszBuf;

	*pszEnd = 0;

	if (bUsingFTP == FALSE && bDecode)
		DecodeURLPath (pszBuf);

	return TRUE;
}

BOOL fsIsAnchorInUrl (LPCSTR pszFullUrl, LPSTR* ppszWithoutAnchor, LPCSTR* ppszAnchor = NULL)
{
	fsURL url;
	if (url.Crack (pszFullUrl) != IR_SUCCESS)
		return FALSE;

	if (url.GetInternetScheme () != INTERNET_SCHEME_HTTP && 
			url.GetInternetScheme () != INTERNET_SCHEME_FTP)
		return FALSE;

	LPCSTR pszPath = url.GetPath ();
	LPCSTR pszA = strchr (pszPath, '#');

	if (pszA == NULL)
		return FALSE;

	
	int len = pszA - pszPath;

	char szUrl [10000]; DWORD dw = sizeof (szUrl);
	fsURL url2;
	url2.Create (url.GetInternetScheme (), url.GetHostName (), url.GetPort (),
		url.GetUserName (), url.GetPassword (), url.GetPath (), szUrl, &dw);

	if (ppszWithoutAnchor)
	{
		int oldlen = strlen (szUrl);
		int oldpathlen = strlen (pszPath);
		fsnew (*ppszWithoutAnchor, char, oldlen - oldpathlen + len + 1);
		CopyMemory (*ppszWithoutAnchor, szUrl, oldlen - oldpathlen + len);
		(*ppszWithoutAnchor) [oldlen - oldpathlen + len] = 0; 

		if (ppszAnchor)
			*ppszAnchor = szUrl + oldlen - oldpathlen + len;
	}

	return TRUE;
}

BOOL fsFileNameFromUrlPath (LPCSTR pszUrl, BOOL bUsingFTP, BOOL bDecode, LPSTR pszBuf, UINT uSize)
{
	*pszBuf = 0;

	int len = strlen (pszUrl);
	int pos;

	if (len == 0)
		return TRUE;

	int end = bUsingFTP ? strlen (pszUrl)-1 : strcspn (pszUrl, "?#") - 1;
	
	if (end < 0)
		return FALSE; 
	
	if (end >= len)
		end = len - 1; 

	pos = end; 

	
	while (pos && pszUrl [pos] != '/' && pszUrl [pos] != '\\')
		pos--;

	if (pszUrl [pos] != '/' && pszUrl [pos] != '\\')
		return FALSE; 

	if (UINT(len - pos) > uSize)
		return FALSE; 

	strcpy (pszBuf, pszUrl + pos + 1);

	pszBuf [end - pos] = 0; 

	if (bUsingFTP == FALSE && bDecode)
		DecodeURLPath (pszBuf);

	if (strchr (pszBuf, '\\') || strchr (pszBuf, '/'))
	{
		
		char sz [1000] = "";
		fsGetFileName (pszBuf, sz);
		lstrcpy (pszBuf, sz);
	}

	return TRUE;
}

BOOL fsIRToStr (fsInternetResult ir, LPSTR pszStr, UINT uMaxSize)
{
	LPCSTR pszDesc;

	switch (ir)
	{
		case IR_WININETUNKERROR:
		case IR_ERROR:
			pszDesc = LS (L_UNKNETERR);
			break;

		case IR_LOGINFAILURE:
			pszDesc = LS (L_INVLOGIN);
			break;

		case IR_INVALIDPASSWORD:
			pszDesc = LS (L_INVPWD);
			break;

		case IR_SUCCESS:
			pszDesc = LS (L_SUCCESS);
			break;

		case IR_CANTCONNECT:
			pszDesc = LS (L_CANTCONNECT);
			break;

		case IR_FILENOTFOUND:
			pszDesc = LS (L_NOTFOUND);
			break;

		case IR_LOSTCONNECTION:
			pszDesc = LS (L_CONNWASLOST);
			break;

		case IR_TIMEOUT:
			pszDesc = LS (L_NOTRESPONSE);
			break;

		case IR_NAMENOTRESOLVED:
			pszDesc = LS (L_NOTRESOLVED);
			break;

		case IR_RANGESNOTAVAIL:
			pszDesc = LS (L_NORESUME);
			break;

		case IR_DOUBTFUL_RANGESRESPONSE:
			pszDesc = LS (L_DOUBTFULRANGESRESPONSE);
			break;

		case IR_PROXYAUTHREQ:
			pszDesc = LS (L_PROXYLOGINREQ);
			break;

		case IR_EXTERROR:
			pszDesc = LS (L_EXTERR);
			break;

		case IR_SERVERBADREQUEST:
			pszDesc = LS (L_BADREQ);
			break;

		case IR_SERVERUNKERROR:
			pszDesc = LS (L_UNKSERVERR);
			break;

		case IR_CONNECTIONABORTED:
			pszDesc = LS (L_CONNABORTED);
			break;

		case IR_BADURL:
			pszDesc = LS (L_BADURL);
			break;

		case IR_NOINTERNETCONNECTION:
			pszDesc = LS (L_NOINETCONN);
			break;

		case IR_HTTPVERNOTSUP:
			pszDesc = LS (L_HTTPNOTSUPP);
			break;

		default:
			pszDesc = LS (L_UNKERR);
	}

	if (strlen (pszDesc) >= uMaxSize)
		return FALSE;

	strcpy (pszStr, pszDesc);

	return TRUE;
}

#ifndef FDM_DLDR__RAWCODEONLY
DWORD fsNPToSiteValidFor (fsNetworkProtocol np)
{
	switch (np)
	{
		case NP_HTTP:
			return SITE_VALIDFOR_HTTP;

		case NP_HTTPS:
			return SITE_VALIDFOR_HTTPS;

		case NP_FTP:
			return SITE_VALIDFOR_FTP;

		default:
			return 0;
	}
}
#endif

ULONG fsGetSiteIp (LPCSTR pszSite)
{
	hostent* he = gethostbyname (pszSite);

	if (he == NULL)
		return 0;

	return *((ULONG*) he->h_addr_list [0]);

	
}

void vmsMakeWinInetProxy (LPCSTR pszProxy, fsNetworkProtocol npConnection, fsNetworkProtocol npProxy, LPSTR pszWProxy)
{
	switch (npConnection)
	{
		case NP_FTP:
			lstrcpy (pszWProxy, "ftp=");
			break;

		case NP_HTTP:
		case NP_FILE:
			lstrcpy (pszWProxy, "http=");
			break;

		case NP_HTTPS:
			lstrcpy (pszWProxy, "https=");
			break;

		default:
			ASSERT (FALSE);
			return;
	}

	switch (npProxy)
	{
		case NP_FTP:
			lstrcat (pszWProxy, "ftp://");
			break;

		case NP_HTTP:
		case NP_FILE:
			lstrcat (pszWProxy, "http://");
			break;

		case NP_HTTPS:
			lstrcat (pszWProxy, "https://");
			break;

		default:
			ASSERT (FALSE);
			return;
	}

	lstrcat (pszWProxy, pszProxy);
}

void fsDecodeHtmlText (fsString &str)
{
	CString str2 = str;
	str2.Replace ("&amp;", "&");
	str2.Replace ("&lt;", "<");
	str2.Replace ("&gt;", ">");
	str2.Replace ("&quot;", "\"");
	str2.Replace ("&nbsp;", " ");
	str = str2;
}

void fsDecodeHtmlUrl (fsString &str)
{
	CString str2;
	int len = str.GetLength ();
	for (int i = 0; i < len; )
	{
		if (str [i] == '\\' && str [i+1] == 'u' && str.GetLength () - i >= 6)
		{
			
			char sz [5];
			sz [0] = str [i+2];
			sz [1] = str [i+3];
			sz [2] = str [i+4];
			sz [3] = str [i+5];
			sz [4] = 0;
			int c;
			sscanf (sz, "%x", &c);
			if (c < 127)
				str2 += (char)c; 
			i += 6;
		}
		else if (str [i] == '%' && str [i+1] != '%' && str.GetLength () - i >= 3)
		{
			
			char sz [3];
			sz [0] = str [i+1];
			sz [1] = str [i+2];
			sz [2] = 0;
			int c;
			sscanf (sz, "%x", &c);
			str2 += (char)c;
			i += 3;
		}
		else if (str [i] == '&' && str [i+1] == '#')
		{
			CString strC;
			int j = i+2;
			while (isdigit (str [j]))
				strC += str [j++];
			if (str [j] == ';')
			{
				
				int c = atoi (strC);
				str2 += (char)c;
				i = j + 1;
			}
			else
			{
				str2 += str [i++];
			}
		}
		else
		{
			str2 += str [i++];
		}
	}

	str = str2;

	fsDecodeHtmlText (str);
}
