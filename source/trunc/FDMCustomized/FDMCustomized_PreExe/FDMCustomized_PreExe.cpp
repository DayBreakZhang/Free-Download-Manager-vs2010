/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <stdio.h>
#include <objbase.h>
#include <shlobj.h>

char _szInstName [MAX_PATH];
char _szPostVersion [1000];
DWORD _dwFlags;

HKEY _hFDMKey;
char _szFDMPath [MAX_PATH];
char _szCustSite [10000];

char LABEL [100];

void BuildLABEL ()
{
	strcpy (LABEL, "###");
	strcat (LABEL, "FDMDATA");
	strcat (LABEL, "###");
}

void fsGetPath (LPCSTR pszFile, LPSTR pszPath)
{
	strcpy (pszPath, pszFile);
	
	int len = lstrlen (pszPath) - 1;

	while (len >= 0 && pszPath [len] != '\\' && pszPath [len] != '/')
		len--;

	pszPath [len+1] = 0;
}

BOOL fsBuildPathToFile (LPCSTR pszFileName)
{
	CHAR szPath [MAX_PATH];
	
	fsGetPath (pszFileName, szPath);

	int len = lstrlen (szPath);
	int start = 0;

	if (szPath [1] == ':')
		start = 3;

	for (int i = start; i < len; i++)
	{
		if (szPath [i] == '\\' || szPath [i] == '/')
		{
			CHAR szPath2 [MAX_PATH];

			CopyMemory (szPath2, szPath, i);
			szPath2 [i] = 0;

			if (FALSE == CreateDirectory (szPath2, NULL))
			{
				if (GetLastError () != ERROR_ALREADY_EXISTS)
					return FALSE;
			}
		}
	}

	return TRUE;
}

LPCSTR bufbuf (LPCSTR where, LPCSTR what, int maxpos)
{
	int len = lstrlen (what);
	while (memcmp (where, what, len))
	{
		where ++;
		if (--maxpos == 0)
			break;
	}

	return maxpos == 0 ? NULL : where;
}

BOOL CreateInstaller (LPCSTR pszFile, LPCSTR pszStart, DWORD dwSize)
{
	if (FALSE == fsBuildPathToFile (pszFile))
		return FALSE;

	HANDLE hFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dwWritten = 0;

	if (FALSE == WriteFile (hFile, pszStart, dwSize, &dwWritten, NULL) ||
		dwWritten != dwSize)
	{
		CloseHandle (hFile);
		return FALSE;
	}

	CloseHandle (hFile);

	return TRUE;
}

BOOL AddURLToDownload (LPCSTR pszUrl, LPCSTR pszReferer, LPCSTR pszComment, BOOL bAutoStart)
{
	DWORD dwErr;
	HKEY key;
	static int _iKey = 0;

	char szKey [1000];
	wsprintf (szKey, "URLsToDownload\\FdmSetupInstaller_%d", _iKey++);

	dwErr = RegCreateKey (_hFDMKey, szKey, &key);

	if (dwErr != ERROR_SUCCESS && dwErr)
		return FALSE;

	RegSetValueEx (key, "URL", NULL, REG_SZ, LPBYTE (pszUrl), lstrlen (pszUrl));
	RegSetValueEx (key, "Referer", NULL, REG_SZ, LPBYTE (pszReferer), lstrlen (pszReferer));
	RegSetValueEx (key, "Comment", NULL, REG_SZ, LPBYTE (pszComment), lstrlen (pszComment));
	DWORD dw = TRUE;
	RegSetValueEx (key, "Silent", NULL, REG_DWORD, (LPBYTE)&dw, sizeof (dw));
	RegSetValueEx (key, "zlr", 0, REG_DWORD, (LPBYTE)&dw, sizeof (dw));
	
	if (bAutoStart)
		dw = TRUE;
	else
		dw = FALSE;

	RegSetValueEx (key, "AutoStart", NULL, REG_DWORD, (LPBYTE)&dw, sizeof (dw));
	
	RegCloseKey (key);

	return TRUE;
}

HANDLE StartProcess (LPCSTR pszName)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	ZeroMemory (&pi, sizeof (pi));

	if (FALSE == CreateProcess (pszName, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		return NULL;

	return pi.hProcess;
}

DWORD LaunchInstaller (LPCSTR pszFile)
{
	HANDLE hInstaller = StartProcess (pszFile);
	if (hInstaller == NULL)
		return 0xffffffff;	

	WaitForSingleObject (hInstaller, INFINITE);

	DWORD dwCode;
	
	GetExitCodeProcess (hInstaller, &dwCode);
	CloseHandle (hInstaller);

	return dwCode;
}

LPCSTR DoJob_Step1 (LPCSTR psz)
{
	char szTmpPath [MAX_PATH];
	if (0 == GetTempPath (sizeof (szTmpPath), szTmpPath))
		GetCurrentDirectory (sizeof (szTmpPath), szTmpPath);
	GetTempFileName (szTmpPath, "fdm", 0, _szInstName);

	DWORD dwSize = *(LPDWORD(psz));
	psz += sizeof (DWORD);

	if (FALSE == CreateInstaller (_szInstName, psz, dwSize))
	{
		DeleteFile (_szInstName);
		return NULL;
	}

	return psz + dwSize;
}

#define FC_MODIFYHOMEPAGE		1L
#define FC_ADDLINKTOFAVOR		(1L << 1)
#define FC_ADDLINKTOSTARTMENU	(1L << 2)
#define FC_ADDBUTTONTOIE		(1L << 3)
#define FC_ADDDOWNLOADS			(1L << 4)
#define FC_ADDBANNERS			(1L << 5)

#define FC_MHP_CHECKEDBYDEF		(1L << 6)

#define FC_FAV_OPTIONAL			(1L << 7)
#define FC_FAV_CHECKEDBYDEF		(1L << 8)

#define FC_SM_OPTIONAL			(1L << 9)
#define FC_SM_CHECKEDBYDEF		(1L << 10)

#define FC_IEBTN_OPTIONAL		(1L << 11)
#define FC_IEBTN_CHECKEDBYDEF	(1L << 12)

LPCSTR DoJob_Step2 (LPCSTR psz)
{
	DWORD dwSize = *(LPDWORD(psz));
	psz += sizeof (DWORD);

	CopyMemory (_szPostVersion, psz, dwSize);
	_szPostVersion [dwSize] = 0;
	psz += dwSize;

	DWORD dwErr;
	dwErr = RegCreateKey (HKEY_CURRENT_USER, 
				"Software\\FreeDownloadManager.ORG\\Free Download Manager", 
				&_hFDMKey);

	if (dwErr == ERROR_SUCCESS)
		RegSetValueEx (_hFDMKey, "PostVersion", NULL, REG_SZ, LPBYTE (_szPostVersion), lstrlen (_szPostVersion));

	char szCustomizer [1000];

	dwSize = *((LPDWORD) psz);
	psz += sizeof (DWORD);
	CopyMemory (szCustomizer, psz, dwSize);
	szCustomizer [dwSize] = 0;
	psz += dwSize;

	dwSize = *((LPDWORD) psz);
	psz += sizeof (DWORD);
	CopyMemory (_szCustSite, psz, dwSize);
	_szCustSite [dwSize] = 0;
	psz += dwSize;

	RegSetValueEx (_hFDMKey, "Customizer", NULL, REG_SZ, LPBYTE (szCustomizer), lstrlen (szCustomizer));
	RegSetValueEx (_hFDMKey, "CustSite", NULL, REG_SZ, LPBYTE (_szCustSite), lstrlen (_szCustSite));

	_dwFlags = *((LPDWORD) psz);
	psz += sizeof (DWORD);

	DWORD dw = 1;

	if (_dwFlags & (FC_ADDLINKTOFAVOR | FC_ADDLINKTOSTARTMENU))
	{
		if (_dwFlags & FC_ADDLINKTOFAVOR)
		{
			if (_dwFlags & FC_FAV_OPTIONAL)
			{
				dw = 2;
				if (_dwFlags & FC_FAV_CHECKEDBYDEF)
					dw = 3;
			}
			RegSetValueEx (_hFDMKey, "CreateLFM", 0, REG_DWORD, (LPBYTE)&dw, 4);
			dw = 1;
		}

		if (_dwFlags & FC_ADDLINKTOSTARTMENU)
		{
			if (_dwFlags & FC_SM_OPTIONAL)
			{
				dw = 2;
				if (_dwFlags & FC_SM_CHECKEDBYDEF)
					dw = 3;
			}
			RegSetValueEx (_hFDMKey, "CreateLSM", 0, REG_DWORD, (LPBYTE)&dw, 4);
			dw = 1;
		}
	}

	if (_dwFlags & FC_MODIFYHOMEPAGE)
	{
		dw = 2;
		if (_dwFlags & FC_MHP_CHECKEDBYDEF)
			dw = 3;
		RegSetValueEx (_hFDMKey, "UseHPage", 0, REG_DWORD, (LPBYTE)&dw, sizeof (dw));
		RegSetValueEx (_hFDMKey, "HPageTo", 0, REG_SZ, (LPBYTE)_szCustSite, lstrlen (_szCustSite));
		dw = 1;
	}
	
	if (_dwFlags & FC_ADDBUTTONTOIE)
	{
		if (_dwFlags & FC_IEBTN_OPTIONAL)
		{
			dw = 2;
			if (_dwFlags & FC_IEBTN_CHECKEDBYDEF)
				dw = 3;
		}
		RegSetValueEx (_hFDMKey, "IEBtn", 0, REG_DWORD, (LPBYTE)&dw, sizeof (dw));
		dw = 1;
	}

	return psz;
}

LPCSTR ExtractFile (LPCSTR psz, LPCSTR pszFile, BOOL bDontCreateIfSize0 = FALSE)
{
	DWORD dwSize = *((LPDWORD) psz);
	psz += sizeof (DWORD);
	if (dwSize == 0 && bDontCreateIfSize0) {
		return psz;
	}

	HANDLE hFile;
	do {
		hFile = CreateFile (pszFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
			FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE) {
			if (GetLastError () == ERROR_SHARING_VIOLATION) {
				Sleep (100);
				continue;
			}
			return psz;	
		}
	} while (hFile == INVALID_HANDLE_VALUE);

	WriteFile (hFile, psz, dwSize, &dwSize, NULL);

	psz += dwSize;
	CloseHandle (hFile);

	return psz;
}

LPCSTR DoJob_Step3 (LPCSTR psz)
{
	char szIco [MAX_PATH];
	strcpy (szIco, _szFDMPath);
	strcat (szIco, "fdmcs.ico");
	psz = ExtractFile (psz, szIco, TRUE);

	if (_dwFlags & (FC_ADDLINKTOFAVOR | FC_ADDLINKTOSTARTMENU))
	{
		
	}

	if (_dwFlags & FC_MODIFYHOMEPAGE)
	{
		DWORD dw = 0;
		DWORD dwSize = sizeof (dw);
		RegQueryValueEx (_hFDMKey, "HPageDo", NULL, NULL, (LPBYTE)&dw, &dwSize);
		if (dw == 0)
			_dwFlags &= ~FC_MODIFYHOMEPAGE;
	}

	if (_dwFlags & FC_MODIFYHOMEPAGE)
	{
		HKEY hKey;
		RegOpenKey (HKEY_CURRENT_USER, "Software\\Microsoft\\Internet Explorer\\Main", &hKey);

		char sz [10000] = "about:blank";
		DWORD dw = sizeof (sz);

		
		if (ERROR_SUCCESS != RegQueryValueEx (
				_hFDMKey, "CIEOP", NULL, NULL, (LPBYTE)sz, &dw))
		{
			RegQueryValueEx (hKey, "Start Page", NULL, NULL, (LPBYTE)sz, &dw);
			RegSetValueEx (_hFDMKey, "CIEOP", 0, REG_SZ, (LPBYTE)sz, lstrlen (sz));
		}

		RegSetValueEx (hKey, "Start Page", 0, REG_SZ, (LPBYTE)_szCustSite, lstrlen (_szCustSite));
		RegCloseKey (hKey);
	}

	return psz;
}

BOOL RegisterDLL (LPCSTR pszDLL)
{
	typedef HRESULT (_stdcall *fntDllRegUnregServer)(void);
	HMODULE hLib = LoadLibrary (pszDLL);
	if (hLib == NULL)
		return FALSE;

	fntDllRegUnregServer pfnDll;
	pfnDll = (fntDllRegUnregServer) GetProcAddress (hLib, "DllRegisterServer");

	if (pfnDll)
		pfnDll ();

	FreeLibrary (hLib);
	return TRUE;
}

LPCSTR DoJob_Step4 (LPCSTR psz)
{
	if (_dwFlags & FC_ADDBUTTONTOIE)
	{
		char szFile [MAX_PATH];

		

		strcpy (szFile, _szFDMPath);
		strcat (szFile, "fdmcsiebtn.ico");
		psz = ExtractFile (psz, szFile);
	}

	if (_dwFlags & FC_ADDDOWNLOADS)
	{
		DWORD dwDLCount = *((LPDWORD) psz);
		psz += sizeof (DWORD);

		while (dwDLCount--)
		{
			char szURL [10000], szReferer [10000], szComment [10000];
			DWORD dwSize;

			dwSize = *((LPDWORD) psz);
			psz += sizeof (DWORD);
			CopyMemory (szURL, psz, dwSize);
			szURL [dwSize] = 0;
			psz += dwSize;

			dwSize = *((LPDWORD) psz);
			psz += sizeof (DWORD);
			CopyMemory (szReferer, psz, dwSize);
			szReferer [dwSize] = 0;
			psz += dwSize;

			dwSize = *((LPDWORD) psz);
			psz += sizeof (DWORD);
			CopyMemory (szComment, psz, dwSize);
			szComment [dwSize] = 0;
			psz += dwSize;

			BOOL bAutoStart = *((LPBOOL) psz);
			psz += sizeof (BOOL);

			AddURLToDownload (szURL, szReferer, szComment, bAutoStart);
		}
	}

	return psz;
}

LPCSTR DoJob_Step5 (LPCSTR psz)
{
	char szFile [MAX_PATH];
	strcpy (szFile, _szFDMPath);
	strcat (szFile, "fdmcs.dat");
	psz = ExtractFile (psz, szFile);
	return psz;
}

BOOL DoJob (LPCSTR psz, int iBufSize)
{
	LPCSTR pszStart;

	BuildLABEL ();

	SetLastError (ERROR_BAD_ENVIRONMENT);	

	pszStart = bufbuf (psz, LABEL, iBufSize);
	if (pszStart == NULL)
		return FALSE;
	pszStart += lstrlen (LABEL);

	pszStart = DoJob_Step1 (pszStart);
	if (NULL == pszStart)
		return FALSE;

	pszStart = DoJob_Step2 (pszStart);
	if (NULL == pszStart)
		return FALSE;

	DWORD dwRet = LaunchInstaller (_szInstName);
	DeleteFile (_szInstName);
	RegDeleteValue (_hFDMKey, "PostVersion");
	RegDeleteValue (_hFDMKey, "CreateLFM");
	RegDeleteValue (_hFDMKey, "CreateLSM");
	RegDeleteValue (_hFDMKey, "UseHPage");
	RegDeleteValue (_hFDMKey, "HPageTo");
	RegDeleteValue (_hFDMKey, "IEBtn");

	if (dwRet == 0xffffffff)
		return FALSE;
	if (dwRet != 0)
		return TRUE;

	DWORD dwSize = MAX_PATH;
	RegQueryValueEx (_hFDMKey, "Path", NULL, NULL, (LPBYTE)_szFDMPath, &dwSize);
	_szFDMPath [dwSize] = 0;
	if (_szFDMPath [dwSize-1] != '\\')
		strcat (_szFDMPath, "\\");

	pszStart = DoJob_Step3 (pszStart);
	if (NULL == pszStart)
		return FALSE;

	pszStart = DoJob_Step4 (pszStart);
	if (NULL == pszStart)
		return FALSE;

	pszStart = DoJob_Step5 (pszStart);
	if (NULL == pszStart)
		return FALSE;

	return TRUE;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	char szMyFileName [10000];
	HANDLE hFile = INVALID_HANDLE_VALUE;

	CoInitialize (NULL);

	if (0 == GetModuleFileName (GetModuleHandle (NULL), szMyFileName, sizeof (szMyFileName)))
		goto _lErr;

	hFile = CreateFile (szMyFileName, GENERIC_READ, FILE_SHARE_READ, 
		NULL, OPEN_EXISTING, 0, NULL);

	if (hFile == INVALID_HANDLE_VALUE)
		goto _lErr;

	char *psz;
	DWORD dwFileLen;

	dwFileLen = GetFileSize (hFile, NULL);
	psz = new char [dwFileLen+1];

	if (FALSE == ReadFile (hFile, psz, dwFileLen, &dwFileLen, NULL))
		goto _lErr;

	psz [dwFileLen] = 0; 

	CreateMutex (NULL, FALSE, "_mx_FDM_Lock_Start_");

	if (FALSE == DoJob (psz, dwFileLen))
		goto _lErr;

	delete [] psz;
	CloseHandle (hFile);

	CoUninitialize ();
	return 0;

_lErr:
	CoUninitialize ();

	char szError [10000];

	if (hFile != INVALID_HANDLE_VALUE)
		CloseHandle (hFile);

	sprintf (szError, "Failed to start FDM installer!\nError code is %d", 
		GetLastError ());

	MessageBox (NULL, szError, "Error", MB_ICONERROR);

	return GetLastError ();
}

