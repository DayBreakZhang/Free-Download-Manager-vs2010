/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsSystem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsSystem::vmsSystem()
{

}

vmsSystem::~vmsSystem()
{

}

tstring vmsSystem::GetRegisteredExePath(LPCTSTR ptszExeName)
{
	CRegKey key;
	tstring tstr = _T ("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\");
	tstr += ptszExeName;
	if (ERROR_SUCCESS != key.Open (HKEY_LOCAL_MACHINE, tstr.c_str (), KEY_READ))
	{
		if (ERROR_SUCCESS != key.Open (HKEY_CURRENT_USER, tstr.c_str (), KEY_READ))
			return _T ("");
	}
	TCHAR tsz [MAX_PATH] = _T ("");
	DWORD dw = MAX_PATH;
	key.QueryValue (tsz, _T ("Path"), &dw);
	return tsz;
}

DWORD vmsSystem::GetModuleFileNameEx(HANDLE hProcess, HMODULE hModule, LPTSTR ptszFileName, DWORD nSize)
{
	typedef DWORD (WINAPI *FNGMFNEX)(HANDLE, HMODULE, LPTSTR, DWORD);
	HMODULE hDll = LoadLibrary (_T ("Psapi.dll"));
	if (hDll == NULL)
		return 0;

	#if defined (UNICODE) || defined (_UNICODE)
		FNGMFNEX pfn = (FNGMFNEX) GetProcAddress (hDll, "GetModuleFileNameExW");
	#else
		FNGMFNEX pfn = (FNGMFNEX) GetProcAddress (hDll, "GetModuleFileNameExA");
	#endif

	DWORD dwRet = 0;

	if (pfn)
		dwRet = pfn (hProcess, hModule, ptszFileName, nSize);

	FreeLibrary (hDll);

	return dwRet;
}

bool vmsSystem::GetProcessCommandLine(DWORD dwPID, LPTSTR ptszCmdLine, UINT *puSize)
{
	HANDLE hProcess = OpenProcess (PROCESS_VM_READ, FALSE, dwPID);
	if (hProcess == NULL)
		return false;

	HMODULE hKernel32 = GetModuleHandle (_T ("kernel32.dll"));
	
#if defined (UNICODE) || defined (_UNICODE)
	FARPROC pfnGCL = GetProcAddress (hKernel32, "GetCommandLineW");
#else
	FARPROC pfnGCL = GetProcAddress (hKernel32, "GetCommandLineA");
#endif

	BYTE abTmp [6]; SIZE_T nRead = 0;
	ReadProcessMemory (hProcess, pfnGCL, abTmp, 6, &nRead);

	if (nRead != 6)
	{
		CloseHandle (hProcess);
		return false;
	}

	LPTSTR ptszProcessCmdLine = (LPTSTR) (DWORD_PTR) (* (DWORD_PTR*)(abTmp+1));

	ReadProcessMemory (hProcess, ptszProcessCmdLine, abTmp, 4, &nRead);

	ptszProcessCmdLine = (LPTSTR) (DWORD_PTR) (* (DWORD_PTR*)(abTmp));

	UINT nSize = LOBYTE (LOWORD (GetVersion())) <= 5 ? 8191 : 2047;
	LPTSTR ptsz = (LPTSTR)alloca (nSize+1);

	*ptsz = 0;

	ReadProcessMemory (hProcess, ptszProcessCmdLine, ptsz, nSize, NULL);

	CloseHandle (hProcess);

	if (*puSize <= _tcslen (ptsz))
	{
		*puSize = _tcslen (ptsz);
		return false;
	}

	_tcscpy (ptszCmdLine, ptsz);

	return *ptsz != 0;
}

BOOL vmsSystem::IsWow64()
{
	typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE hProcess,PBOOL Wow64Process);
    LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)
		GetProcAddress (GetModuleHandle ("kernel32"), "IsWow64Process");
    BOOL bIsWow64 = FALSE;
    
    if (NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process (GetCurrentProcess (), &bIsWow64))
        {
            
        }
    }

    return bIsWow64;

}

BOOL vmsSystem::SetFilePointer(HANDLE hFile, UINT64 uPos, DWORD dwMethod)
{
	LONG lOffsetHi = 0;
	UINT64 uOffset = uPos;
	
	while (uOffset > DWORD (-1))
	{
		::SetFilePointer (hFile, -1, &lOffsetHi, dwMethod);
		if (GetLastError ())
			return FALSE;
		uOffset -= DWORD (-1);
		dwMethod = FILE_CURRENT;
		lOffsetHi = 0;
	}
	::SetFilePointer (hFile, DWORD (uOffset), &lOffsetHi, dwMethod);
	return TRUE;
}
