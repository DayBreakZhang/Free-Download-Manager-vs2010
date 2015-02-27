/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsIETmpCookies.h"
#include <inetfile/inetfile.h>
#include "vmsCookie.h"

vmsIETmpCookies::vmsIETmpCookies()
{
	m_mxFile = CreateMutex (NULL, FALSE, "vmsMX::fdmietmpcookiesfileops");
}

vmsIETmpCookies::~vmsIETmpCookies()
{
	CloseHandle (m_mxFile);
}

int vmsIETmpCookies::Find(LPCSTR pszUrl)
{
	fsURL url;
	if (IR_SUCCESS != url.Crack (pszUrl))
		return -1;

	char szCookie [50000] = "";
	DWORD dw = sizeof (szCookie);
	InternetGetCookie (pszUrl, NULL, szCookie, &dw);
	vmsCookie cookie; cookie.Set (szCookie);

	GetListOfKnownCookies ();

	
	fs::list <int> vFit;

	for (int i = 0; i < m_vBeforeNavUrls.size (); i++)
	{
		if (m_vBeforeNavUrls [i] == pszUrl)
		{
			
			
			vFit.add (i);
			break;
		}
	}

	for (int bEx = 0; bEx < 2 && vFit.size () == 0; bEx++)
	{
		

		for (int i = 0; i < m_vUrls.size (); i++)
		{
			fsURL url2;
			if (IR_SUCCESS != url2.Crack (m_vUrls [i].c_str ()))
				continue;

			if (fsIsServersEqual (url.GetHostName (), url2.GetHostName (), bEx))
				vFit.add (i);
		}
	}

	if (vFit.size () == 0)
	{
		

		string str1 = GetLevel2DomainName (url.GetHostName ());

		for (int i = 0; i < m_vUrls.size (); i++)
		{
			fsURL url2;
			if (IR_SUCCESS != url2.Crack (m_vUrls [i].c_str ()))
				continue;

			string str2 = GetLevel2DomainName (url2.GetHostName ());

			if (str1 == str2)
				vFit.add (i);
		}
	}

	int nIndex = -1;
	int cCI = -1;
	int len = 0;
	
	
	for (i = 0; i < vFit.size (); i++)
	{
		int n = vFit [i];	
		vmsCookie c; c.Set (get_Cookies (n));
		int cCI2 = cookie.GetCommonItemCount (&c);
		if (cCI2 > cCI || (cCI2 == cCI && len < c.get_ItemCount ()))
		{
			nIndex = n;
			cCI = cCI2;
			len = c.get_ItemCount ();
		}
	}

	if (nIndex != -1)
	{
		vmsCookie c; c.Set (get_Cookies (nIndex));
		cookie.Add (&c);
		m_vCookies [nIndex] = cookie.toString ();
	}

	return nIndex;
}

void vmsIETmpCookies::GetListOfKnownCookies()
{
	m_vUrls.clear ();
	m_vCookies.clear ();

	WaitForSingleObject (m_mxFile, INFINITE);

	
	char szTmpPath [MAX_PATH];
	GetTempPath (MAX_PATH, szTmpPath);
	lstrcat (szTmpPath, "Free Download Manager\\");
	char sz [MAX_PATH];
	lstrcpy (sz, szTmpPath);
	lstrcat (sz, "tic*.tmp");

	WIN32_FIND_DATA wfd;

	HANDLE hFind = FindFirstFile (sz, &wfd);
	
	if (hFind) do
	{
		lstrcpy (sz, szTmpPath);
		lstrcat (sz, wfd.cFileName);
		ProcessFile (sz);
	}
	while (FindNextFile (hFind, &wfd));

	if (hFind)
		FindClose (hFind);

	ReleaseMutex (m_mxFile);
}

void vmsIETmpCookies::ProcessFile(LPCSTR pszFile)
{
	static BOOL _bIsWin9x = GetVersion () & 0x80000000;

	DWORD dwShareMode = FILE_SHARE_READ|FILE_SHARE_WRITE;
	if (_bIsWin9x == FALSE)
		dwShareMode |= FILE_SHARE_DELETE;

	HANDLE hFile = CreateFile (pszFile, GENERIC_READ, 
			dwShareMode, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return;

	DWORD dwLen = GetFileSize (hFile, NULL), dw = 0;
	LPSTR psz = new char [dwLen + 1];
	ReadFile (hFile, psz, dwLen, &dw, NULL);
	psz [dw] = 0;

	string strUrl, strCookies, strPostData, strBeforeNavUrl;

	

	LPCSTR psz2 = psz;
	while (*psz2 && *psz2 != '\r')
		strUrl += *psz2++;

	if (*psz2 != '\r')
		return;
	psz2 += 2;
	while (*psz2 && *psz2 != '\r')
		strCookies += *psz2++;

	if (*psz2 != '\r')
		return;
	psz2 += 2;
	while (*psz2 && *psz2 != '\r')
		strPostData += *psz2++;

	if (*psz2 != '\r')
		return;
	psz2 += 2;
	strBeforeNavUrl = psz2;
		
	delete [] psz;

	m_vUrls.push_back (strUrl);
	m_vCookies.push_back (strCookies);
	m_vPostDatas.push_back (strPostData);
	m_vBeforeNavUrls.push_back (strBeforeNavUrl);

	CloseHandle (hFile);
}

LPCSTR vmsIETmpCookies::get_Cookies(int nIndex)
{
	return m_vCookies [nIndex].c_str ();
}

LPCSTR vmsIETmpCookies::get_Referer(int nIndex)
{
	return m_vUrls [nIndex].c_str ();
}

LPCSTR vmsIETmpCookies::get_PostData(int nIndex)
{
	return m_vPostDatas [nIndex].c_str ();
}

string vmsIETmpCookies::GetLevel2DomainName(LPCSTR pszHostName)
{
	LPCSTR psz2 = strrchr (pszHostName, '.');
	if (psz2 == NULL)
		psz2 = pszHostName;
	else
		psz2--;
	LPCSTR psz3 = psz2;
	while (pszHostName != psz2 && *psz2 != '.')
		psz2--;
	if (*psz2 == '.')
		psz2++;
	string str = psz2;
	str [psz3 - psz2 + 1] = 0;
	return str;
}
