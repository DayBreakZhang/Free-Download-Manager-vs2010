/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSYSTEM_H__E8A307A8_FDB6_4B68_A093_E97CCD237F91__INCLUDED_)
#define AFX_VMSSYSTEM_H__E8A307A8_FDB6_4B68_A093_E97CCD237F91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsSystem  
{
public:
	static BOOL SetFilePointer (HANDLE hFile, UINT64 uPos, DWORD dwMethod);
	static BOOL IsWow64 ();
	static bool GetProcessCommandLine (DWORD dwPID, LPTSTR ptszCmdLine, UINT *puSize);
	static DWORD GetModuleFileNameEx (HANDLE hProcess, HMODULE hModule, LPTSTR ptszFileName, DWORD nSize);
	static tstring GetRegisteredExePath (LPCTSTR ptszExeName);
	vmsSystem();
	virtual ~vmsSystem();

};

#endif 
