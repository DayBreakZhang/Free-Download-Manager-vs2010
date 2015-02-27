/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsProcessesInjector.h"
#include "vmsProcessList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsProcessesInjector::vmsProcessesInjector()
{
	InitializeCriticalSection (&m_csProcessList);
	m_bNeverFreeInjectedDlls = false;
}

vmsProcessesInjector::~vmsProcessesInjector()
{
	DeleteCriticalSection (&m_csProcessList);
}

void vmsProcessesInjector::DoJob()
{
	if (m_vtstrNamesOfProcesesToMonitor.empty ())
		return;

	vmsProcessList pl;
	pl.GenerateList ();

	std::vector <DWORD> vdwPIDs;

	EnterCriticalSection (&m_csProcessList);

	for (int i = 0; i < pl.getProcessCount (); i++)
	{
		const vmsProcessListItem *process = pl.getProcess (i);

		size_t j = 0;
		for (j = 0; j < m_vtstrNamesOfProcesesToMonitor.size (); j++)
		{
			if (_tcsicmp (m_vtstrNamesOfProcesesToMonitor [j].c_str (), process->tstrExeName.c_str ()) == 0)
				break;
		}

		if (j == m_vtstrNamesOfProcesesToMonitor.size ())
			continue;

		vdwPIDs.push_back (process->dwProcessId);
	}

	std::vector <ProcessedProcess> vProcesses;

	size_t j = 0;
	for (j = 0; j < vdwPIDs.size (); j++)
	{
		DWORD dwPID = vdwPIDs [j];

		size_t k = 0;
		for (k = 0; k < m_vProcesses.size (); k++)
		{
			if (m_vProcesses [k].dwPID == dwPID)
				break;
		}

		if (k == m_vProcesses.size ())
		{
			ProcessedProcess pp;
			pp.dwPID = dwPID;
			InjectIntoProcess (&pp);
			vProcesses.push_back (pp);
		}
		else
		{
			vProcesses.push_back (m_vProcesses [k]);
		}	
	}

	for (j = 0; j < m_vProcesses.size (); j++)
	{
		DWORD dwPID = m_vProcesses [j].dwPID;
		size_t k = 0;
		for (k = 0; k < vProcesses.size (); k++)
		{
			if (dwPID == vProcesses [k].dwPID)
				break;
		}

		if (k == vProcesses.size ())
		{
			if (!m_bNeverFreeInjectedDlls)
				FreeDllsFromProcess (&m_vProcesses [j]);
		}
	}

	m_vProcesses = vProcesses;

	LeaveCriticalSection (&m_csProcessList);
}

HMODULE LoadDllIntoProcess (HANDLE hProcess, LPCSTR pszDllName)
{
	HANDLE hThread = NULL;
	
	void* pLibRemote = NULL;   
	
	DWORD  hLibModule = 0;   
	HMODULE hKernel32 = ::GetModuleHandle(_T ("Kernel32"));
	
	
	
	
	
	
	pLibRemote = ::VirtualAllocEx (hProcess, NULL, strlen (pszDllName)+1, MEM_COMMIT, 
		PAGE_READWRITE);
	if (!pLibRemote)
		return NULL;
	if (!::WriteProcessMemory (hProcess, pLibRemote, (void*)pszDllName, strlen (pszDllName)+1, 
		NULL))
	{
		::VirtualFreeEx (hProcess, pLibRemote, strlen (pszDllName)+1, MEM_RELEASE);
		return NULL;
	}
	
	static const char _TMP_SZ [] = "_FDM_DEALWITHKAV__LoadLibraryA";
	int len = strlen (_TMP_SZ);
	LPSTR psz = (LPSTR) GetModuleHandle (NULL);
	while (strncmp (psz, _TMP_SZ, len))
		psz++;
	psz += 18;
	
	
	
	hThread = CreateRemoteThread (hProcess, NULL, 0, 
		(LPTHREAD_START_ROUTINE)GetProcAddress (hKernel32, psz), 
		pLibRemote, 0, NULL);
	if (hThread != NULL)
	{
		::WaitForSingleObject (hThread, INFINITE);
		
		
		::GetExitCodeThread (hThread, &hLibModule);
		
		
		::CloseHandle (hThread);
	}
		
	::VirtualFreeEx (hProcess, pLibRemote, strlen (pszDllName)+1, MEM_RELEASE);
	
	return (HMODULE)hLibModule;
}

BOOL FreeDllFromProcess (HANDLE hProcess, HMODULE hDll)
{
	HANDLE hThread = NULL;
	HMODULE hKernel32 = ::GetModuleHandle(_T ("Kernel32"));
	
	static const char _TMP_SZ [] = "_FDM_DEALWITHKAV__FreeLibrary";
	int len = strlen (_TMP_SZ);
	LPSTR psz = (LPSTR) GetModuleHandle (NULL);
	while (strncmp (psz, _TMP_SZ, len))
		psz++;
	psz += 18;
	
	
	
	hThread = CreateRemoteThread (hProcess, NULL, 0, 
		(LPTHREAD_START_ROUTINE)GetProcAddress (hKernel32, psz), 
		hDll, 0, NULL);
	
	DWORD dwResult = FALSE;
	
	if (hThread)
	{
		::WaitForSingleObject (hThread, INFINITE);
		
		
		::GetExitCodeThread (hThread, &dwResult);
		
		
		::CloseHandle (hThread);
	}
	
	return dwResult;
}

void vmsProcessesInjector::InjectIntoProcess(ProcessedProcess *pp)
{
	HANDLE hProcess = OpenProcess (PROCESS_ALL_ACCESS, FALSE, pp->dwPID);
	ASSERT (hProcess != NULL);

	pp->vhInjectedDlls.clear ();

	if (!hProcess)
		return;

	for (size_t i = 0; i < m_vtstrDllsToInject.size (); i++)
	{
		HMODULE h = LoadDllIntoProcess (hProcess, m_vtstrDllsToInject [i].c_str ());
		if (h)
			pp->vhInjectedDlls.push_back (h);
	}

	CloseHandle (hProcess);
}

void vmsProcessesInjector::FreeDllsFromProcesses()
{
	EnterCriticalSection (&m_csProcessList);

	for (size_t i = 0; i < m_vProcesses.size (); i++)
		FreeDllsFromProcess (&m_vProcesses [i]);

	m_vProcesses.clear ();

	LeaveCriticalSection (&m_csProcessList);
}

void vmsProcessesInjector::FreeDllsFromProcess(ProcessedProcess *pp)
{
	HANDLE hProcess = OpenProcess (PROCESS_ALL_ACCESS, FALSE, pp->dwPID);
	if (!hProcess)
		return;
	
	for (size_t j = 0; j < pp->vhInjectedDlls.size (); j++)
		FreeDllFromProcess (hProcess, pp->vhInjectedDlls [j]);

	CloseHandle (hProcess);
}
