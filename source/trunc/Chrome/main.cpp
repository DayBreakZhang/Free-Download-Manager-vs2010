/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#define _CRT_SECURE_NO_WARNINGS
#include <string>

#define WIN32_LEAN_AND_MEAN		
#include <windows.h>
#include <objbase.h>
#include <comdef.h>

#include "Fdm.h"

#include "picojson.h"

_COM_SMARTPTR_TYPEDEF(IFdmUiWindow, __uuidof(IFdmUiWindow));

DWORD _bMonitor = 0;
DWORD _dwSkipSmaller = 0;
DWORD _bAllowDownload = 1;
DWORD _bALTShouldBePressed = 0;
DWORD _bContextMenuDLAll = 1; 
DWORD _bContextMenuDLFlashVideo = 1; 
DWORD _bContextMenuDLPage = 0;
DWORD _bContextMenuDLSelected = 1; 
DWORD _bContextMenuDLThis = 1; 

void ReadConfig()
{
	DWORD cbData;
	HKEY hMonitor = NULL;
	if(RegOpenKeyEx(
			HKEY_CURRENT_USER,
			"Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor",
			0,
			KEY_READ,
			&hMonitor) == ERROR_SUCCESS)
	{
		cbData = sizeof(DWORD);
		RegQueryValueEx(hMonitor, "AllowDownload", NULL, NULL, (LPBYTE)&_bAllowDownload, &cbData);

		cbData = sizeof(DWORD);
		RegQueryValueEx(hMonitor, "ALTShouldPressed", NULL, NULL, (LPBYTE)&_bALTShouldBePressed, &cbData);

		cbData = sizeof(DWORD);
		RegQueryValueEx(hMonitor, "Chrome", NULL, NULL, (LPBYTE)&_bMonitor, &cbData);

		cbData = sizeof(DWORD);
		RegQueryValueEx(hMonitor, "SkipSmaller", NULL, NULL, (LPBYTE)&_dwSkipSmaller, &cbData);

		HKEY hMenu = NULL;
		if(RegOpenKeyEx(
				HKEY_CURRENT_USER,
				"Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor\\IEMenu",
				0,
				KEY_READ,
				&hMenu) == ERROR_SUCCESS)
		{
			DWORD bContextMenu = 0;
			cbData = sizeof(DWORD);
			RegQueryValueEx(hMenu, "Enable", NULL, NULL, (LPBYTE)&bContextMenu, &cbData);

			if(bContextMenu)
			{
				cbData = sizeof(DWORD);
				RegQueryValueEx(hMenu, "DLAll", NULL, NULL, (LPBYTE)&_bContextMenuDLAll, &cbData);

				cbData = sizeof(DWORD);
				RegQueryValueEx(hMenu, "DLFlashVideo", NULL, NULL, (LPBYTE)&_bContextMenuDLFlashVideo, &cbData);

				cbData = sizeof(DWORD);
				RegQueryValueEx(hMenu, "DLPage", NULL, NULL, (LPBYTE)&_bContextMenuDLPage, &cbData);

				cbData = sizeof(DWORD);
				RegQueryValueEx(hMenu, "DLSelected", NULL, NULL, (LPBYTE)&_bContextMenuDLSelected, &cbData);

				cbData = sizeof(DWORD);
				RegQueryValueEx(hMenu, "DLThis", NULL, NULL, (LPBYTE)&_bContextMenuDLThis, &cbData);
			}
		}
	}
}

std::string ReadSkipServers()
{
	std::string res;
	HKEY hMonitor = NULL;
	if(RegOpenKeyEx(
			HKEY_CURRENT_USER,
			"Software\\FreeDownloadManager.ORG\\Free Download Manager\\Settings\\Monitor",
			0,
			KEY_READ,
			&hMonitor) == ERROR_SUCCESS)
	{
		DWORD cbData = 0;
		if(RegQueryValueEx(hMonitor, "SkipServers", NULL, NULL, NULL, &cbData) == ERROR_SUCCESS && cbData != 0)
		{
			res.resize(cbData);
			RegQueryValueEx(hMonitor, "SkipServers", NULL, NULL, (LPBYTE)res.c_str(), &cbData);
		}
	}
	return res;
}

LPCSTR strcmp_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	if (*pszWhere == 0)
		return *pszWhat == 0 ? pszWhere : NULL;

	if (*pszWhat == 0)
		return NULL;

	if (*pszWhat == '*')
	{
		if (pszWhat [1] == 0)
			return pszWhere;
		
		
		
		LPCSTR psz = strcmp_m (pszWhere, pszWhat+1);
		if (psz)
			return psz;

		
		return strcmp_m (pszWhere+1, pszWhat);
	}

	if (*pszWhat != '?')
	{
		if (*pszWhere != *pszWhat)
			return NULL;
	}

	return strcmp_m (pszWhere+1, pszWhat+1) ? pszWhere : NULL;
}

LPCSTR strcmpi_m (LPCSTR pszWhere, LPCSTR pszWhat)
{
	char *psz1 = new char [lstrlen (pszWhere) + 1];
	char *psz2 = new char [lstrlen (pszWhat) + 1];

	lstrcpy (psz1, pszWhere);
	lstrcpy (psz2, pszWhat);

	CharLower (psz1);
	CharLower (psz2);

	LPCSTR psz = strcmp_m (psz1, psz2);
	LPCSTR pszRet = NULL;
	if (psz)
		pszRet = pszWhere + (psz - psz1);

	delete [] psz1;
	delete [] psz2;

	return pszRet;
}

BOOL IsExtStrEq (LPCSTR pszMasked, LPCSTR psz2)
{
	return strcmpi_m (psz2, pszMasked) != NULL;
}

BOOL IsExtInExtsStr (LPCSTR pszExts, LPCSTR pszExt)
{
	if (pszExt == NULL)
		return FALSE;

	int len = lstrlen (pszExts);
	int i = 0;
	CHAR szExt [10000];

	do
	{
		int j = 0;

		while (i < len && pszExts [i] != ' ')
			szExt [j++] = pszExts [i++];

		szExt [j] = 0;
		i++;

		if (IsExtStrEq (szExt, pszExt))
			return TRUE;

	} while (i < len);

	return FALSE;
}

BOOL IsServerInServersStr (LPCSTR pszServers, LPCSTR pszServer)
{
	if(*pszServers == 0)
		return FALSE;
	if (pszServer == NULL)
		return FALSE;

	int len = lstrlen (pszServers);
	int i = 0;
	CHAR szServer [10000];

	do
	{
		int j = 0;

		while (i < len && pszServers [i] != ' ')
			szServer [j++] = pszServers [i++];

		szServer [j] = 0;
		i++;

		if (IsExtStrEq (szServer, pszServer))
			return TRUE;

		std::string str;
		str = "*."; str += szServer;
		if (IsExtStrEq (str.c_str(), pszServer))
			return TRUE;

	} while (i < len);

	return FALSE;
}

std::string DomainFromUrl(LPCSTR pszUrl)
{
	LPCSTR pszS = strstr (pszUrl, "://");
	if (pszS == NULL)
		pszS = strstr (pszUrl, ":\\\\");
	if (pszS == NULL)
		pszS = pszUrl;
	else
		pszS += 3;
	LPCSTR pszE = pszS;
	while (*pszE && *pszE != '\\' && *pszE != '/')
		pszE++;

	char sz [1000];
	if (pszE - pszS > sizeof (sz))
		return "";

	lstrcpyn (sz, pszS, pszE - pszS + 1);
	return sz;
}

bool UrlToFdm (LPCSTR pszUrl, LPCSTR pszOrigUrl, LPCSTR pszCookies, LPCSTR pszReferrer, bool page, LPCSTR post, LPCSTR pszUserAgent)
{
	if(IsServerInServersStr(ReadSkipServers().c_str(), DomainFromUrl(pszUrl).c_str()))
		return false;

	IWGUrlReceiver* wg;
	HRESULT hr;
	if (FAILED (hr=CoCreateInstance (CLSID_WGUrlReceiver, NULL, CLSCTX_ALL, IID_IWGUrlReceiver, (void**) &wg)))
	{
		char szMsg [1000];
		lstrcpy (szMsg, "Free Download Manager is not properly installed! Please reinstall Free Download Manager\n\nIf you want to download with your browser please disable FDM extension in it.\n\nError code: ");
		char sz [100];
		_itoa_s (hr, sz, 100, 16);
		lstrcat (szMsg, sz);
		MessageBox (NULL, szMsg, "Error", MB_ICONERROR);
		return false;
	}

	wg->put_Url (_bstr_t(pszUrl));
	wg->put_OriginalURL(_bstr_t(pszOrigUrl));
	wg->put_Cookies (_bstr_t(pszCookies));
	wg->put_Referer (_bstr_t(pszReferrer));
	wg->put_UserAgent(_bstr_t(pszUserAgent));
	if(strlen(post) > 0)
		wg->put_PostData(_bstr_t(post));
	if(page)
	{
		HRESULT res = wg->ShowAddPageDownloadDialog();
		wg->Release();
		return !FAILED(res);
	} else
	{
		if(wg->AddDownload () == E_NOTIMPL)
		{
			wg->Release();
			return false;
		}

		IServiceProviderPtr spSP (wg);
		IFdmUiWindowPtr spUiWindow;
		if (spSP)
			spSP->QueryService (__uuidof (IFdmUiWindow), __uuidof (IFdmUiWindow), (void**)&spUiWindow);
		if (spUiWindow)
		{
			spUiWindow->WaitForWindowCreation (5000);
			ULONG u = 0;
			spUiWindow->get_Handle (&u);
			if (u)
			{
				SetForegroundWindow ((HWND)u);
				BringWindowToTop ((HWND)u);
			}
		}

		
		BSTR state = NULL;
		_bstr_t in_progress(L"in_progress");
		do
		{
			SysFreeString(state);
			Sleep(5);
			wg->get_UIState(&state);
		} while(in_progress == _bstr_t(state, true));
	
		_bstr_t st(state, false);
		wg->Release ();
		return (st == _bstr_t(L"added"));
	}
}

bool UrlListToFdm(LPCSTR pszUrlList, LPCSTR pszCookies, LPCSTR pszReferrer)
{
	IWGUrlListReceiver* wg;
	HRESULT hr;
	if(FAILED (hr=CoCreateInstance (CLSID_WGUrlListReceiver, NULL, CLSCTX_ALL, IID_IWGUrlListReceiver, (void**) &wg)))
	{
		char szMsg [1000];
		lstrcpy (szMsg, "Free Download Manager is not properly installed! Please reinstall Free Download Manager\n\nIf you want to download with your browser please disable FDM extension in it.\n\nError code: ");
		char sz [100];
		_itoa_s (hr, sz, 100, 16);
		lstrcat (szMsg, sz);
		MessageBox (NULL, szMsg, "Error", MB_ICONERROR);
		return false;
	}

	
	size_t len = strlen(pszUrlList);
	char* urls = new char[len+1];
	strcpy(urls, pszUrlList);
	for(size_t i = 0; i < len; i++)
		if(urls[i] == '\n')
			urls[i] = 0;

	size_t i = 0;
	do
	{
		wg->put_Url(_bstr_t(&urls[i]));
		wg->put_Cookies(_bstr_t(pszCookies));
		wg->put_Referer(_bstr_t(pszReferrer));
		wg->AddUrlToList();
		i += (strlen(&urls[i])+1);
	} while (i < len);

	wg->ShowAddUrlListDialog();
	wg->Release();
	delete[] urls;
	return true;
}

bool PassRequestToFdm(const std::string pszUrl, const std::string pszOrigUrl, const std::string pszCookies,
		const std::string pszReferrer, bool list, bool page, std::string post, std::string useragent)
{
	if(pszUrl.length() == 0)
		return false;

	if(list)
		return UrlListToFdm(pszUrl.c_str(), pszCookies.c_str(), pszReferrer.c_str());
	else
		return UrlToFdm(pszUrl.c_str(), pszOrigUrl.c_str(), pszCookies.c_str(), pszReferrer.c_str(), page, post.c_str(), useragent.c_str());
}

void ReplyToExtension(const std::string id, const std::string msg)
{
	const char* format = "{\"id\": %s, \"result\": %s}";
	size_t len = strlen(format)+id.length()+msg.length()+1;
	char* message = new char[len];
	_snprintf(message, len, format, id.c_str(), msg.c_str());
	len = strlen(message);
	
	printf("%c%c%c%c", (char) (len & 0xff),
					(char) ((len>>8) & 0xFF),
					(char) ((len>>16) & 0xFF),
					(char) ((len>>24) & 0xFF));
	
	printf("%s", message);
	fflush(stdout);
	delete[] message;
}

void PassConfigToExtension()
{
	const char* format = "{ \"monitor\": %d, \"skip_smaller\": %d, \"allow_download\": %d, \"alt_pressed\": %d,\
\"menu\": { \"all\": %d, \"flash_video\": %d, \"page\": %d, \"selected\": %d, \"_this\": %d } }";
	size_t len = strlen(format) + 9*10 + 1;
	char* msg = new char[len];
	_snprintf(msg, len, format, _bMonitor, _dwSkipSmaller, _bAllowDownload, _bALTShouldBePressed,
_bContextMenuDLAll, _bContextMenuDLFlashVideo, _bContextMenuDLPage, _bContextMenuDLSelected, _bContextMenuDLThis);
	
	ReplyToExtension("-2", msg);
	delete[] msg;
}

bool ParseRequest(std::string& id, std::string& url, std::string& origUrl,
	std::string& cookies, std::string& referrer, bool& list, bool& page, std::string& post, std::string& useragent)
{
	
	size_t length = 0;
	for (int i = 0; i < 4; i++)
	{
		int ch = getchar();
		if(ch == EOF)
			return false;
		length += (ch << (8*i));
	}

	
	char* msg = new char[length+1];
	memset(msg, 0, length+1);
	for(size_t i = 0; i < length; i++)
			msg[i] = getchar();
	
	
	picojson::value v;
	std::string err;
	picojson::parse(v, msg, msg + length, &err);
	if (!err.empty())
	{
		delete[] msg;
		return false;
	}
	
	id   = v.get( "id").to_str();
	url  = v.get("url").to_str();
	origUrl = v.contains("origUrl") ? v.get("origUrl").to_str() : url;
	cookies  = v.get( "cookies").to_str();
	referrer = v.get("referrer").to_str();
	list = v.get("list").get<bool>();
	page = v.get("page").get<bool>();
	post = v.get("post").to_str();
	useragent = v.get("useragent").to_str();

	delete[] msg;
	return true;
}

int main()
{
	CoInitialize (NULL);

	ReadConfig();
	PassConfigToExtension();

	while(true)
	{
		std::string id, url, origUrl, cookies, referrer, post, useragent;
		bool list, page;
		if(!ParseRequest(id, url, origUrl, cookies, referrer, list, page, post, useragent))
			break;
		if(PassRequestToFdm(url, origUrl, cookies, referrer, list, page, post, useragent))
			ReplyToExtension(id, "true");
		else
			ReplyToExtension(id, "false");
	}

	CoUninitialize ();
	return EXIT_SUCCESS;
}
