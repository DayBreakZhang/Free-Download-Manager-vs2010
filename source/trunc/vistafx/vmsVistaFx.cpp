/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsVistaFx.h"
#include "shellapi.h"

#pragma data_seg("shdata")

HHOOK _hHook = NULL;
char _szPath [MAX_PATH] = "";
char _szParameters [MAX_PATH] = "";
char _szDirectory [MAX_PATH] = "";
UINT _uRunMsg = 0;
#pragma data_seg()
#pragma comment(linker, "/section:shdata,rws")

vmsVistaFx::vmsVistaFx()
{

}

vmsVistaFx::~vmsVistaFx()
{

}

BOOL vmsVistaFx::IsElevated()
{
	HANDLE hToken = NULL;

	if (FALSE == OpenProcessToken (GetCurrentProcess (), TOKEN_QUERY, &hToken))
		return FALSE;

	TOKEN_ELEVATION te = {0};
	DWORD dwReturnLength = 0;

	GetTokenInformation (hToken, (TOKEN_INFORMATION_CLASS)20, &te, sizeof (te), &dwReturnLength);
	
	CloseHandle (hToken);

	return te.TokenIsElevated; 
}

BOOL vmsVistaFx::RunNonElevated(LPCSTR pszPath, LPCSTR pszParameters, LPCSTR pszDirectory)
{
	if (IsWow64 ())
		return FALSE;

	while (_hHook)
		Sleep (10);

	if (_uRunMsg == 0)
		_uRunMsg = RegisterWindowMessage ("VistaFx_Run_msg");
	if (_uRunMsg == 0)
		return FALSE;

	HWND hwndShell = FindWindow ("Progman", NULL);
	if (hwndShell == NULL)
		return FALSE;

	HMODULE hModule = NULL;	

	if (FALSE == GetModuleHandleEx (GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
			(LPCTSTR)_HookProc, &hModule))
		return FALSE;

	_hHook = SetWindowsHookEx (WH_CALLWNDPROCRET, _HookProc, hModule, 0);
	if (_hHook == NULL)
		return FALSE;

	lstrcpy (_szPath, pszPath);
	lstrcpy (_szParameters, pszParameters);
	lstrcpy (_szDirectory, pszDirectory);

	SendMessage (hwndShell, _uRunMsg, 0, 0);

	UnhookWindowsHookEx (_hHook);
	_hHook = NULL;

	return TRUE;
}

LRESULT CALLBACK vmsVistaFx::_HookProc(int code, WPARAM wp, LPARAM lp)
{
	if (code >= 0 && lp)
    {
	    CWPRETSTRUCT * pwrs = (CWPRETSTRUCT*) lp;
        if (pwrs->message == _uRunMsg)
			ShellExecute (NULL, "open", _szPath, _szParameters, _szDirectory, SW_SHOW);
    }

	return CallNextHookEx (_hHook, code, wp, lp);
}

BOOL vmsVistaFx::IsWow64()
{
	typedef BOOL (WINAPI *FNIW64P)(HANDLE, LPBOOL);
	FNIW64P pfn = (FNIW64P) GetProcAddress (GetModuleHandle ("kernel32"), "IsWow64Process");
	BOOL b64 = FALSE;
	if (pfn)
		pfn (GetCurrentProcess (), &b64);
	return b64;
}
