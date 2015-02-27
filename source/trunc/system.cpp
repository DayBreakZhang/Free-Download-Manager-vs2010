/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "system.h"
#include <windows.h>
#include <shellapi.h>
#include <shlwapi.h>

DWORD _dwOsMajorVersion = 0;

typedef DWORD (WINAPI*fntRasGetStat) (HRASCONN hRasConn, RAS_STATS* pStatistics);
typedef DWORD (WINAPI*fntRasHangUp)(HRASCONN); 
typedef DWORD (WINAPI*fntRasGetErrorString)(UINT, LPTSTR, DWORD);
typedef DWORD (WINAPI*fntRasDial)(LPRASDIALEXTENSIONS, LPCTSTR, LPRASDIALPARAMS, DWORD, LPVOID, LPHRASCONN);
typedef DWORD (WINAPI*fntRasGetEntryDialParams)(LPCTSTR, LPRASDIALPARAMS, LPBOOL);
typedef DWORD (WINAPI*fntRasEnumEntries)(LPCTSTR, LPCTSTR, LPRASENTRYNAME, LPDWORD, LPDWORD);
typedef DWORD (WINAPI*fntRasEnumConnections)(LPRASCONN, LPDWORD, LPDWORD);
fntRasGetStat _pfnRasGetStat = NULL;
fntRasHangUp  _pfnRasHangUp = NULL;
fntRasGetErrorString _pfnRasGetErrorString = NULL;
fntRasDial _pfnRasDial = NULL;
fntRasGetEntryDialParams _pfnRasGetEntryDialParams = NULL;
fntRasEnumEntries _pfnRasEnumEntries = NULL;
fntRasEnumConnections _pfnRasEnumConnections = NULL;

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

void fsInitRAS ()
{
	static BOOL bRasWasInit = FALSE;

	if (bRasWasInit)
		return;
	else
		bRasWasInit = TRUE;

	HMODULE hDll = LoadLibrary (_T ("RasApi32.Dll"));

	if (hDll)
	{
		
		_pfnRasGetStat = (fntRasGetStat) GetProcAddress (hDll, _T ("RasGetConnectionStatistics"));

		
		_pfnRasHangUp  = (fntRasHangUp) GetProcAddress (hDll, _T ("RasHangUpA"));
		if (_pfnRasHangUp == NULL)
			_pfnRasHangUp  = (fntRasHangUp) GetProcAddress (hDll, _T ("RasHangUp"));

		
		_pfnRasGetErrorString = (fntRasGetErrorString) GetProcAddress (hDll, "RasGetErrorStringA");
		if (_pfnRasGetErrorString == NULL)
			_pfnRasGetErrorString = (fntRasGetErrorString) GetProcAddress (hDll, "RasGetErrorString");

		
		_pfnRasDial = (fntRasDial) GetProcAddress (hDll, "RasDialA");
		if (_pfnRasDial == NULL)
			_pfnRasDial = (fntRasDial) GetProcAddress (hDll, "RasDial");

		
		_pfnRasGetEntryDialParams = (fntRasGetEntryDialParams) GetProcAddress (hDll, "RasGetEntryDialParamsA");
		if (_pfnRasGetEntryDialParams == NULL)
			_pfnRasGetEntryDialParams = (fntRasGetEntryDialParams) GetProcAddress (hDll, "RasGetEntryDialParams");

		
		_pfnRasEnumEntries = (fntRasEnumEntries) GetProcAddress (hDll, "RasEnumEntriesA");
		if (_pfnRasEnumEntries == NULL)
			_pfnRasEnumEntries = (fntRasEnumEntries) GetProcAddress (hDll, "RasEnumEntries");

		
		_pfnRasEnumConnections = (fntRasEnumConnections) GetProcAddress (hDll, "RasEnumConnectionsA");
		if (_pfnRasEnumConnections == NULL)
			_pfnRasEnumConnections = (fntRasEnumConnections) GetProcAddress (hDll, "RasEnumConnections");

		if (_pfnRasGetStat == NULL && _pfnRasHangUp == NULL && 
			_pfnRasGetErrorString == NULL && _pfnRasDial == NULL && 
			_pfnRasGetEntryDialParams == NULL && _pfnRasEnumEntries == NULL && 
			_pfnRasEnumConnections == NULL)
		{
			FreeLibrary (hDll);
		}
	}
}

void fsSysGetConnectionStatistics (HRASCONN hRasConn, RAS_STATS* pStatistics)
{
	if (fsSysGetOsMajorVersion () < 5)
		return;

	if (_pfnRasGetStat == NULL)
	{
		fsInitRAS ();
		if (_pfnRasGetStat == NULL)
			return;
	}

	_pfnRasGetStat (hRasConn, pStatistics);
}

DWORD fsRasHangUp (HRASCONN hRasConn)
{
	if (_pfnRasHangUp == NULL)
	{
		fsInitRAS ();
		if (_pfnRasHangUp == NULL)
			return ERROR_INVALID_HANDLE;
	}

	return _pfnRasHangUp (hRasConn);
}

DWORD fsRasEnumEntries (LPCTSTR p1, LPCTSTR p2, LPRASENTRYNAME p3, LPDWORD p4, LPDWORD p5)
{
	if (_pfnRasEnumEntries == NULL)
	{
		fsInitRAS ();
		if (_pfnRasEnumEntries == NULL)
			return ERROR_INVALID_HANDLE;
	}

	return _pfnRasEnumEntries (p1, p2, p3, p4, p5);
}

DWORD fsRasEnumConnections (LPRASCONN p1, LPDWORD p2, LPDWORD p3)
{
	if (_pfnRasEnumConnections == NULL)
	{
		fsInitRAS ();
		if (_pfnRasEnumConnections == NULL)
			return ERROR_INVALID_HANDLE;
	}

	return _pfnRasEnumConnections (p1, p2, p3);
}

DWORD fsRasGetErrorString (UINT p1, LPTSTR p2, DWORD p3)
{
	if (_pfnRasGetErrorString == NULL)
	{
		fsInitRAS ();
		if (_pfnRasGetErrorString == NULL)
			return ERROR_INVALID_HANDLE;
	}

	return _pfnRasGetErrorString (p1, p2, p3);
}

DWORD fsRasDial (LPRASDIALEXTENSIONS p1, LPCTSTR p2, LPRASDIALPARAMS p3, DWORD p4, LPVOID p5, LPHRASCONN p6)
{
	if (_pfnRasDial == NULL)
	{
		fsInitRAS ();
		if (_pfnRasDial == NULL)
			return ERROR_INVALID_HANDLE;
	}

	return _pfnRasDial (p1, p2, p3, p4, p5, p6);
}

DWORD fsRasGetEntryDialParams (LPCTSTR p1, LPRASDIALPARAMS p2, LPBOOL p3)
{
	if (_pfnRasGetEntryDialParams == NULL)
	{
		fsInitRAS ();
		if (_pfnRasGetEntryDialParams == NULL)
			return ERROR_INVALID_HANDLE;
	}

	return _pfnRasGetEntryDialParams (p1, p2, p3);
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
	char szBrowser [MY_MAX_PATH];
	DWORD dwBrowserLen = MY_MAX_PATH;

	

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

void fsOnMemoryError ()
{
#ifndef FDM_DLDR__RAWCODEONLY
	if (IDCANCEL == MessageBox (NULL, "Out of memory! Please close some applications and press Retry or Cancel to exit without saving any data", "Out of memory", MB_ICONEXCLAMATION|MB_RETRYCANCEL))
	{
		_TrayMgr.Remove ();
		ExitProcess (0);
	}
#endif
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

bool fsSetFilePointer (HANDLE hFile, __int64 iPosition, DWORD dwMethod)
{
	LARGE_INTEGER li;
	li.QuadPart = iPosition;

	if (INVALID_SET_FILE_POINTER == SetFilePointer (hFile, li.LowPart, &li.HighPart, dwMethod) &&
			NO_ERROR != GetLastError ())
		return false;

	return true;
}

UINT64 fsGetFileSize (HANDLE hFile)
{
	DWORD dw1, dw2;
	dw1 = GetFileSize (hFile, &dw2);

	return dw1 | UINT64 (dw2) << 32;
}

int fsGetFTimeDaysDelta (FILETIME t1, FILETIME t2)
{
	__int64 u1, u2;

	u1 = __int64 (t1.dwHighDateTime) << 32 | t1.dwLowDateTime; 
	u2 = __int64 (t2.dwHighDateTime) << 32 | t2.dwLowDateTime;
	
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

char vmsGetExeDriveLetter ()
{
	static char _chResult = 0;
	if (_chResult)
		return _chResult;
	char sz [MAX_PATH] = "";
	GetModuleFileName (NULL, sz, MAX_PATH);
	return _chResult = sz [0];
}

void vmsCopyFiles (LPCSTR pszSrcFolder, LPCSTR pszDstFolder, LPCSTR pszFileMask)
{

#ifndef FDM_DLDR__RAWCODEONLY

	CString str = pszSrcFolder;
	if (str.Right (1) != '\\')
		str += '\\';
	str += pszFileMask;
	
	CString strDst = pszDstFolder;
	if (strDst.Right (1) != '\\')
		strDst += '\\';
	
	CFileFind ff;
	
	BOOL bResult = ff.FindFile (str);
	while (bResult)
	{
		CopyFile (ff.GetFilePath (), strDst + ff.GetFileName (), FALSE);
		bResult = ff.FindNextFile ();
	}

#else

	CString str = pszSrcFolder;
	if (str.LastChar () != '\\')
		str += '\\';
	str += pszFileMask;
	
	CString strDst = pszDstFolder;
	if (strDst.LastChar () != '\\')
		strDst += '\\';

	WIN32_FIND_DATA wfdFindFileData;
	HANDLE hFile = ::FindFirstFile((LPTSTR)str, &wfdFindFileData);

	if (hFile == INVALID_HANDLE_VALUE)
		return;
	
	BOOL bResult = TRUE;
	while (bResult)
	{
		CopyFile (wfdFindFileData.cFileName, strDst + wfdFindFileData.cFileName, FALSE);
		bResult = FindNextFile (hFile, &wfdFindFileData);
	}

	FindClose(hFile);

#endif

}
