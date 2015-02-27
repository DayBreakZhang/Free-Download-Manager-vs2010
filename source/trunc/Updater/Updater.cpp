/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <string>

HANDLE StartProcess (LPCSTR pszName, LPCSTR pszArgs)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory (&si, sizeof (si));
	si.cb = sizeof (si);
	ZeroMemory (&pi, sizeof (pi));

	char sz [MAX_PATH] = "\"";
	lstrcat (sz, pszName);
	lstrcat (sz, "\"");
	
	if (pszArgs && *pszArgs)
	{
		lstrcat (sz, " ");
		lstrcat (sz, pszArgs);
	}

	if (FALSE == CreateProcess (NULL, sz, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		return NULL;

	return pi.hProcess;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	HANDLE hMutex;
	DWORD dwLastError;

	

	if (*lpCmdLine++ != '"')
		return 0;

	std::string strProcessExe, strAppMutex, strUpgradeExe, strUpgradeExeArgs,
		strDeleteDistribFlags;

	while (*lpCmdLine && *lpCmdLine != '"')
		strProcessExe += *lpCmdLine++;
	if (*lpCmdLine == 0)
		return 0;
	lpCmdLine += 2;

	if (*lpCmdLine++ != '"')
		return 0;
	while (*lpCmdLine && *lpCmdLine != '"')
		strAppMutex += *lpCmdLine++;
	if (*lpCmdLine == 0)
		return 0;
	lpCmdLine += 2;

	if (*lpCmdLine++ != '"')
		return 0;
	while (*lpCmdLine && *lpCmdLine != '"')
		strUpgradeExe += *lpCmdLine++;
	if (*lpCmdLine == 0)
		return 0;
	lpCmdLine += 2;

	if (*lpCmdLine++ != '"')
		return 0;
	while (*lpCmdLine && *lpCmdLine != '"')
		strUpgradeExeArgs += *lpCmdLine++;
	if (*lpCmdLine == 0)
		return 0;
	lpCmdLine += 2;

	if (*lpCmdLine++ != '"')
		return 0;
	while (*lpCmdLine && *lpCmdLine != '"')
		strDeleteDistribFlags += *lpCmdLine++;
	
	if (strProcessExe == "" || strAppMutex == "" || strUpgradeExe == "")
		return 0;

	
	do
	{
		hMutex = CreateMutex (NULL, TRUE, strAppMutex.c_str ());
	
		dwLastError = GetLastError ();
		CloseHandle (hMutex);

		Sleep (300);
	}
	while (dwLastError == ERROR_ALREADY_EXISTS);

	
	
	HANDLE hUpdate = StartProcess (strUpgradeExe.c_str (), strUpgradeExeArgs.c_str ());

	if (hUpdate == NULL)
		MessageBox (NULL, "Can't find upgrade distributive file.", "Update error", MB_ICONERROR);
	else
		WaitForSingleObject (hUpdate, INFINITE);

	if (strDeleteDistribFlags == "1")
		DeleteFile (strUpgradeExe.c_str ());

	
	StartProcess (strProcessExe.c_str (), NULL);

	return 0;
}

