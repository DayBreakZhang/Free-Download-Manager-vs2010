/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "system.h"
#include <windows.h>
#include <shellapi.h>
#include <shlwapi.h>

DWORD _dwOsMajorVersion = 0;

typedef BOOL (WINAPI*fntSetLayeredWndAttr) (HWND, COLORREF, BYTE, DWORD);
fntSetLayeredWndAttr _pfnSetLWA = NULL;

BOOL fsSetLayeredWindowAttributes (HWND hWnd, COLORREF clrKey, BYTE bAlpha, DWORD dwFlags)
{
	if (fsSysGetOsMajorVersion () < 5)
		return FALSE;

	if (_pfnSetLWA == NULL)
	{
		

		HMODULE hDll = LoadLibrary (_T ("User32.Dll"));

		if (hDll)
			_pfnSetLWA = (fntSetLayeredWndAttr) GetProcAddress (hDll, _T ("SetLayeredWindowAttributes"));
																											
		if (_pfnSetLWA == NULL)
			return FALSE;
	}

	return _pfnSetLWA (hWnd, clrKey, bAlpha, dwFlags);
}

DWORD fsSysGetOsMajorVersion ()
{
	if (_dwOsMajorVersion == 0)
	{
		OSVERSIONINFO ver;
		ver.dwOSVersionInfoSize = sizeof (ver);
		GetVersionEx (&ver);
		_dwOsMajorVersion = ver.dwMajorVersion;
	}

	return _dwOsMajorVersion;
}

void fsSetForegroundWindow (HWND hWnd)
{
	HWND hFor = GetForegroundWindow ();
	int iMyTID = GetCurrentThreadId ();
	int iCurrTID = GetWindowThreadProcessId (hFor, NULL);

	AttachThreadInput (iMyTID, iCurrTID, TRUE);

	SetForegroundWindow (hWnd);

	AttachThreadInput (iMyTID, iCurrTID, FALSE);
}

void fsOpenUrlInBrowser (LPCSTR pszUrl)
{
	char szReg [100];
	char szBrowser [MAX_PATH];
	DWORD dwBrowserLen = MAX_PATH;

	

	if (strnicmp (pszUrl, "http", 4) == 0)
		strcpy (szReg, "http");
	else if (strnicmp (pszUrl, "https", 5) == 0)
		strcpy (szReg, "https");
	else
		strcpy (szReg, "ftp");

	strcat (szReg, "\\shell\\open\\command");

	HKEY hReg;

	if (ERROR_SUCCESS != RegOpenKeyEx (HKEY_CLASSES_ROOT, szReg, 0, KEY_QUERY_VALUE, &hReg))
		goto _lErr;

	if (ERROR_SUCCESS != RegQueryValueEx (hReg, NULL, NULL, NULL, (LPBYTE) szBrowser, &dwBrowserLen))
	{
		RegCloseKey (hReg);
		goto _lErr;
	}

	RegCloseKey (hReg);

	strlwr (szBrowser);
	LPSTR pszExe;
	pszExe = strstr (szBrowser, ".exe");

	if (pszExe == NULL)
		goto _lErr;

	pszExe [4] = 0;

	if (32 >= (int)ShellExecute (HWND_DESKTOP, "open", szBrowser [0] == '"' ? szBrowser+1 : szBrowser, pszUrl, NULL, SW_SHOW))
		goto _lErr;

	return;

_lErr:
	if (32 >= (int) ShellExecute (HWND_DESKTOP, "open", pszUrl, NULL, NULL, SW_SHOW))
		MessageBox (NULL, pszUrl, LS (L_ERROPENURL), MB_ICONERROR);
}

int fsStrCmpNC (LPCSTR psz1, LPCSTR psz2)
{
	int ret = CompareString (LOCALE_USER_DEFAULT, NORM_IGNORECASE, psz1, -1, psz2, -1);
	switch (ret)
	{
		case CSTR_LESS_THAN:
			return -1;

		case CSTR_EQUAL:
			return 0;

		default:
			return 1;
	}
}

int fsStrNCmpNC (LPCSTR psz1, LPCSTR psz2, int nCount)
{
	int ret = CompareString (LOCALE_USER_DEFAULT, NORM_IGNORECASE, psz1, nCount, psz2, nCount);
	switch (ret)
	{
		case CSTR_LESS_THAN:
			return -1;

		case CSTR_EQUAL:
			return 0;

		default:
			return 1;
	}
}

BOOL GetIEVersion(DWORD *pMajor, DWORD *pMinor, DWORD *pBuild, DWORD *pSubBuild)
{
#ifndef FDM_DLDR__RAWCODEONLY
    CRegKey rk;
    LONG lRet = rk.Open(HKEY_LOCAL_MACHINE, _T("Software\\Microsoft\\Internet Explorer"), KEY_READ);
    if(lRet == 0)
    {
        TCHAR szBuff[256];
        DWORD dwCount = sizeof(szBuff);
        lRet = rk.QueryValue(szBuff, _T("Version"), &dwCount);
        if(lRet == 0)
        {
            sscanf(szBuff, "%u.%u.%u.%u", pMajor, pMinor, pBuild, pSubBuild);
            return TRUE;
        }
    }
#endif

    return FALSE;
}

typedef HRESULT  (CALLBACK *fntDllGetVersion) (DLLVERSIONINFO*);

DWORD GetShell32Version ()
{
	static DWORD dwVer = 0;

	if (dwVer == 0)
	{
		HMODULE hLib = LoadLibrary ("shell32.dll");
		if (hLib == NULL)
			return 0;

		fntDllGetVersion pfn = (fntDllGetVersion) GetProcAddress (hLib, "DllGetVersion");

		if (pfn == NULL)
		{
			FreeLibrary (hLib);
			return 0;
		}

		DLLVERSIONINFO info;
		info.cbSize = sizeof (info);
		pfn (&info);

		FreeLibrary (hLib);

		return dwVer = info.dwMajorVersion;
	}

	return dwVer;
}

BOOL fsSetFilePointer (HANDLE hFile, UINT64 uPosition, DWORD dwMethod)
{
	LONG lOffsetHi = 0;
	UINT64 uOffset = uPosition;
	
	while (uOffset > DWORD (-1))
	{
		SetFilePointer (hFile, -1, &lOffsetHi, dwMethod);
		if (GetLastError ())
			return FALSE;
		uOffset -= DWORD (-1);
		dwMethod = FILE_CURRENT;
		lOffsetHi = 0;
	}
	SetFilePointer (hFile, DWORD (uOffset), &lOffsetHi, dwMethod);
	return TRUE;
}

UINT64 fsGetFileSize (HANDLE hFile)
{
	DWORD dw1, dw2;
	dw1 = GetFileSize (hFile, &dw2);

	return dw1 | UINT64 (dw2) << 32;
}

int fsGetFTimeDaysDelta (FILETIME t1, FILETIME t2)
{
	UINT64 u1, u2;

	u1 = UINT64 (t1.dwHighDateTime) << 32 | t1.dwLowDateTime; 
	u2 = UINT64 (t2.dwHighDateTime) << 32 | t2.dwLowDateTime;
	
	return int ((u1 - u2) / 10000000 / 60 / 60 / 24);
}

BOOL fsIsSystemInFullScreenMode ()
{
#ifndef FDM_DLDR__RAWCODEONLY

	CWnd* pwnd = CWnd::FromHandle (GetForegroundWindow ());
	if (pwnd != NULL && pwnd->m_hWnd != GetDesktopWindow ())
	{
		CRect rc; pwnd->GetWindowRect (&rc);
		if (rc.Width () == GetSystemMetrics (SM_CXSCREEN) &&
				rc.Height () == GetSystemMetrics (SM_CYSCREEN))
		{
			CString str;
			pwnd->GetWindowText (str);
			char sz [1000];
			GetClassName (pwnd->m_hWnd, sz, 1000);
			str = sz;
			if (str.CompareNoCase ("progman"))
				return TRUE;
		}	
	}

#endif

	return FALSE;
}

BOOL vmsSetSuspendState (BOOL bHibernate, BOOL bForce, BOOL bDisableWakeEvent)
{
	typedef BOOLEAN (WINAPI *fntSetSuspendState)(BOOL, BOOL, BOOL);
	static fntSetSuspendState _pfnSSS = NULL;

	if (_pfnSSS == NULL)
	{
		HMODULE hDll = LoadLibrary ("powrprof.dll");
		if (hDll)
			_pfnSSS = (fntSetSuspendState) GetProcAddress (hDll, "SetSuspendState");
	}

	if (_pfnSSS == NULL)
		return FALSE;

	return _pfnSSS (bHibernate, bForce, bDisableWakeEvent);
}

LONG fsCopyKey(HKEY hSrcParent, HKEY hTargParent, LPCTSTR szSrcKey, LPCTSTR szTargKey)
{
    LONG nRes = ERROR_SUCCESS;
    TCHAR *szSubKeyName = NULL;
    TCHAR *szValueName = NULL;
    BYTE *pData = NULL;
    HKEY hSrcKey = NULL, hTargKey = NULL;
    
    __try
    {
        nRes = RegCreateKey(hTargParent, szTargKey, &hTargKey);
        if(nRes != ERROR_SUCCESS)
            __leave;

        nRes = RegOpenKeyEx(hSrcParent, szSrcKey, 0, KEY_ENUMERATE_SUB_KEYS | KEY_READ, &hSrcKey);
        if(nRes != ERROR_SUCCESS)
            __leave;

        DWORD nMaxKeyNameLen, nMaxValueNameLen, nMaxValueLen;
        RegQueryInfoKey(
            hSrcKey, NULL, NULL, NULL, NULL,
            &nMaxKeyNameLen, NULL, NULL,
            &nMaxValueNameLen, &nMaxValueLen, NULL, NULL);

        nMaxKeyNameLen++;
        nMaxValueNameLen++;

        szSubKeyName = new TCHAR[nMaxKeyNameLen];
        DWORD nIndex = 0, nSize = nMaxKeyNameLen;
        FILETIME tTime;

        while(RegEnumKeyEx(
            hSrcKey, nIndex++, szSubKeyName, &nSize, 0, NULL, NULL, &tTime) == ERROR_SUCCESS)
        {
            LONG nRes = fsCopyKey(hSrcKey, hTargKey, szSubKeyName, szSubKeyName);
            if(nRes != ERROR_SUCCESS)
                __leave;

            nSize = nMaxKeyNameLen;
        }

        szValueName = new TCHAR[nMaxValueNameLen];
        pData = new BYTE[nMaxValueLen];
        DWORD nType, nDataSize;

        nIndex = 0;
        nSize = nMaxValueNameLen;
        nDataSize = nMaxValueLen;

        while(RegEnumValue(
            hSrcKey, nIndex++, szValueName, &nSize,
            NULL, NULL, pData, &nDataSize) == ERROR_SUCCESS)
        {
            nRes = RegQueryValueEx(hSrcKey, szValueName, NULL, &nType, pData, &nDataSize);
            if(nRes != ERROR_SUCCESS)
                __leave;

            nRes = RegSetValueEx(hTargKey, szValueName, NULL, nType, pData, nDataSize);
            if(nRes != ERROR_SUCCESS)
                __leave;

            nSize = nMaxValueNameLen;
            nDataSize = nMaxValueLen;
        }

        nRes = ERROR_SUCCESS;
    }
    __finally
    {
        if(szSubKeyName != NULL)
            delete [] szSubKeyName;

        if(szValueName != NULL)
            delete [] szValueName;

        if(pData != NULL)
            delete [] pData;

        if(hSrcKey != NULL)
            RegCloseKey(hSrcKey);

        if(hTargKey != NULL)
            RegCloseKey(hTargKey);

        return nRes;
    }
}

DWORD vmsSHCopyKey (HKEY hkeySrc, LPCSTR pszSubKey, HKEY hkeyDst)
{
	typedef DWORD (WINAPI *fntSHCopyKey)(HKEY, LPCSTR, HKEY, DWORD);
	static fntSHCopyKey _pfnCK = NULL;

	if (_pfnCK == NULL)
	{
		HMODULE hDll = LoadLibrary ("shlwapi.dll");
		if (hDll)
			_pfnCK = (fntSHCopyKey) GetProcAddress (hDll, "SHCopyKeyA");
	}

	if (_pfnCK == NULL)
		return FALSE;

	return _pfnCK (hkeySrc, pszSubKey, hkeyDst, NULL);
}

BOOL vmsMoveFileAtWinBoot (LPCSTR pszSrc, LPCSTR pszDst)
{
	if ((GetVersion () & 0x80000000) == 0) 
		return MoveFileEx (pszSrc, pszDst, MOVEFILE_DELAY_UNTIL_REBOOT);

	char szWinInit [MAX_PATH] = "";
	GetWindowsDirectory (szWinInit, MAX_PATH);
	if (szWinInit [3] != 0)
		lstrcat (szWinInit, "\\");
	lstrcat (szWinInit, "wininit.ini");

	char sz [32000] = "";
	DWORD dwLen = GetPrivateProfileSection ("rename", sz, sizeof (sz), szWinInit);
	LPSTR psz = sz + dwLen;
	lstrcpy (psz, pszDst ? pszDst : "NUL");
	lstrcat (psz, "=");
	lstrcat (psz, pszSrc);
	psz [lstrlen (psz) + 1] = 0;
	return WritePrivateProfileSection ("rename", sz, szWinInit);
}

BOOL vmsDeleteFileAtWinBoot (LPCSTR pszFile)
{
	return vmsMoveFileAtWinBoot (pszFile, NULL);
}

