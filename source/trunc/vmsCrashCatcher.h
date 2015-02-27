/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include <DbgHelp.h>
class vmsCrashCatcher
{
public:

	vmsCrashCatcher() : m_pEP (NULL), m_dwThreadId (0), m_dwpFaultModuleCrashAddress (NULL)
	{
		assert (m_pThis == NULL);
		if (m_pThis != NULL)
			throw 0;
		m_pThis = this;
		Initialize ();
	}

	virtual ~vmsCrashCatcher(void)
	{
		if (m_pThis == this)
		{
			SetUnhandledExceptionFilter (m_pPrevFilter);
			m_pPrevFilter = NULL;
			m_pThis = NULL;
		}
	}

protected:

	void Initialize ()
	{
		assert (m_pPrevFilter == NULL);
		m_pPrevFilter = SetUnhandledExceptionFilter (_UnhandledExceptionFilter);
	}

	static vmsCrashCatcher* m_pThis;
	static LPTOP_LEVEL_EXCEPTION_FILTER m_pPrevFilter;
	tstring m_tstrDumpFile;
	tstring m_tstrFaultModuleName;
	DWORD_PTR m_dwpFaultModuleCrashAddress;

	struct threadCreateDumpParams
	{
		DWORD dwThreadId;
		_EXCEPTION_POINTERS *info;
	};

	_EXCEPTION_POINTERS *m_pEP;
	DWORD m_dwThreadId;

	static DWORD WINAPI _threadCreateDump (LPVOID lp)
	{
		vmsCrashCatcher *pthis = (vmsCrashCatcher*)lp;

		

		MINIDUMP_EXCEPTION_INFORMATION eInfo;
		eInfo.ThreadId = pthis->m_dwThreadId;
		eInfo.ExceptionPointers = pthis->m_pEP;
		eInfo.ClientPointers = FALSE;

		TCHAR tszTmpFile [MAX_PATH] = _T ("");
		TCHAR tszTmpPath [MAX_PATH] = _T ("");
		GetTempPath (MAX_PATH, tszTmpPath);
		GetTempFileName (tszTmpPath, _T ("tmp"), 0, tszTmpFile);

		HANDLE hFile = CreateFile (tszTmpFile, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
			0, NULL);

		if (hFile == INVALID_HANDLE_VALUE)
			return 0;

		BOOL bDumpCreated = MiniDumpWriteDump (GetCurrentProcess(), GetCurrentProcessId(), hFile, 
			(MINIDUMP_TYPE) (MiniDumpScanMemory | MiniDumpWithIndirectlyReferencedMemory | MiniDumpWithDataSegs | MiniDumpWithProcessThreadData),
			&eInfo, NULL, NULL);

		CloseHandle (hFile);

		

		MEMORY_BASIC_INFORMATION mbi;
		SIZE_T nSize = VirtualQuery (pthis->m_pEP->ExceptionRecord->ExceptionAddress, &mbi, sizeof(mbi));
		if (nSize)
		{
			pthis->m_dwpFaultModuleCrashAddress = (DWORD_PTR)pthis->m_pEP->ExceptionRecord->ExceptionAddress - (DWORD_PTR)mbi.AllocationBase;
			TCHAR tszModule [MAX_PATH] = _T ("");
			GetModuleFileName ((HMODULE)mbi.AllocationBase, tszModule, _countof (tszModule));
			if (*tszModule)
				pthis->m_tstrFaultModuleName = _tcsrchr (tszModule, '\\') ? _tcsrchr (tszModule, '\\') + 1 : tszModule;			
		}

		if (bDumpCreated)
		{
			pthis->m_tstrDumpFile = tszTmpFile;
			pthis->onCrashDumpCreated ();
		}
		else
		{
			DeleteFile (tszTmpFile);
		}

		return 0;
	}

	static LONG WINAPI _UnhandledExceptionFilter (_EXCEPTION_POINTERS *info)
	{
		static BOOL _b = FALSE;
		
		if (_b)
			return m_pPrevFilter ? m_pPrevFilter (info) : EXCEPTION_EXECUTE_HANDLER;

		_b = TRUE;

		m_pThis->m_dwThreadId = GetCurrentThreadId ();
		m_pThis->m_pEP = info;
	
		WaitForSingleObject (
			CreateThread (NULL, 0, _threadCreateDump, m_pThis, 0, NULL), INFINITE);

		return m_pPrevFilter ? m_pPrevFilter (info) : EXCEPTION_EXECUTE_HANDLER;
	}

	virtual void onCrashDumpCreated () = NULL;
};

__declspec(selectany) vmsCrashCatcher* vmsCrashCatcher::m_pThis = NULL;
__declspec(selectany) LPTOP_LEVEL_EXCEPTION_FILTER vmsCrashCatcher::m_pPrevFilter = NULL;