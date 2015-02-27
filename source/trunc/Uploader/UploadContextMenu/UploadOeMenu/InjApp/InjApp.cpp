/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include <tlhelp32.h>
#include <assert.h>

HANDLE _hevAppShutdown = NULL;

HANDLE FindMsimnProcess ()
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot (TH32CS_SNAPALL, NULL);
    if (hSnapshot == INVALID_HANDLE_VALUE) 
		return NULL;

	HANDLE hOE = NULL;
    
    PROCESSENTRY32 pe = {sizeof (PROCESSENTRY32)}; 
    BOOL bOk = Process32First (hSnapshot, &pe);
    while (bOk && hOE == NULL)
    {
        bOk = Process32Next (hSnapshot, &pe);

        if (stricmp (pe.szExeFile, "msimn.exe") == 0)
			hOE = OpenProcess (PROCESS_ALL_ACCESS, FALSE, pe.th32ProcessID);
    }

	CloseHandle (hSnapshot);

	return hOE;
};

HMODULE LoadDllIntoProcess (HANDLE hProcess, LPCSTR pszDllName)
{
	HANDLE hThread;
	
	void* pLibRemote;   
                      
	DWORD  hLibModule;   
	HMODULE hKernel32 = ::GetModuleHandle("Kernel32");

	
	

	
	
	pLibRemote = ::VirtualAllocEx (hProcess, NULL, strlen (pszDllName)+1, MEM_COMMIT, 
		PAGE_READWRITE);
	::WriteProcessMemory (hProcess, pLibRemote, (void*)pszDllName, strlen (pszDllName)+1, 
		NULL);

	
	
	hThread = ::CreateRemoteThread (hProcess, NULL, 0, 
		(LPTHREAD_START_ROUTINE)GetProcAddress (hKernel32, "LoadLibraryA"), pLibRemote, 
		0, NULL );
	::WaitForSingleObject (hThread, INFINITE);

	
	::GetExitCodeThread (hThread, &hLibModule);

	
	::CloseHandle (hThread);
	::VirtualFreeEx (hProcess, pLibRemote, strlen (pszDllName)+1, MEM_RELEASE);

	return (HMODULE)hLibModule;
}

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	_hevAppShutdown = CreateEvent (NULL, TRUE, FALSE, "fum - oe - injapp");
	if (GetLastError () == ERROR_ALREADY_EXISTS)
		return 0;

	bool bFound = false;

	do
	{
		HANDLE hOe = FindMsimnProcess ();
		
		if (!hOe == !bFound)
		{
			if (hOe)
				CloseHandle (hOe);
			continue;
		}

		bFound = hOe != NULL;

		if (bFound == false)
			continue;

		#ifdef _DEBUG
			HMODULE hDll = LoadDllIntoProcess (hOe, 
				"D:\\VCW\\FDM\\FDM\\Uploader\\UploadContextMenu\\UploadOeMenu\\InjDll\\Debug\\fumoei.dll");
			assert (hDll != NULL);
		#else
			char sz [MAX_PATH];
			GetModuleFileName (NULL, sz, MAX_PATH);
			lstrcpy (strrchr (sz, '\\') + 1, "fumoei.dll");
			HMODULE hDll = LoadDllIntoProcess (hOe, sz);
		#endif

		CloseHandle (hOe);
	}
	while (WaitForSingleObject (_hevAppShutdown, 3000) == WAIT_TIMEOUT);

	return 0;
}

