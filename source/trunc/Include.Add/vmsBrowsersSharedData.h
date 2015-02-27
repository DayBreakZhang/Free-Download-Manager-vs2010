/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsSharedData.h"
#include "vmsLowIntegrityLevel.h"

#define vmsBrowsersSharedData_MAXBROWSERPROCESSES	100

class vmsBrowsersSharedData
{
protected:
	struct DataStruct
	{
		DWORD	dwActiveDownloadsCount;
		DWORD	dwPID; 
	};
public:
	vmsBrowsersSharedData () 
	{
		OSVERSIONINFO ver;
		ZeroMemory (&ver, sizeof (ver));
		ver.dwOSVersionInfoSize = sizeof (ver);
		GetVersionEx (&ver);

		m_hmxData = CreateMutex (ver.dwMajorVersion > 5 ? &vmsLowLabelSecurityAttributes () : NULL, 
			FALSE, _T ("A89138B6-0898-4dd5-AA1F-673973F61421"));
		if (!m_hmxData && GetLastError () == ERROR_ACCESS_DENIED)
			m_hmxData = OpenMutex (SYNCHRONIZE, FALSE, _T ("A89138B6-0898-4dd5-AA1F-673973F61421"));

		if (m_hmxData)
		{
			WaitForSingleObject (m_hmxData, INFINITE);
			if (!m_data.Aquire (_T ("B75DD868-61F6-420c-811E-D9514561353A")))
			{
				
				m_data.Aquire (_T ("B75DD868-61F6-420c-811E-D9514561353A"), false, vmsBrowsersSharedData_MAXBROWSERPROCESSES * sizeof (DataStruct), FILE_MAP_ALL_ACCESS, 
					ver.dwMajorVersion > 5 ? &vmsLowLabelSecurityAttributes () : NULL);
				DataStruct *pData = (DataStruct*) m_data.getData ();
				if (pData)
					ZeroMemory (pData, vmsBrowsersSharedData_MAXBROWSERPROCESSES * sizeof (DataStruct));				
			}
			ReleaseMutex (m_hmxData);
		}
	}

	~vmsBrowsersSharedData () 
	{
		if (m_hmxData)
			CloseHandle (m_hmxData);
	}
public:
	bool ModifyActiveDownloadsCount (int cDiff)
	{
		if (!cDiff)
			return true;
		if (!m_hmxData)
			return false;
		DataStruct *pData = getDataStructForThisProcess ();
		if (pData)
			pData->dwActiveDownloadsCount += cDiff;
		return pData != NULL;
	}
	DWORD getActiveDownloadsCount (bool bInThisProcessOnly = false)
	{
		DataStruct *pData = bInThisProcessOnly ? getDataStructForThisProcess () : (DataStruct*) m_data.getData ();
		if (!pData)
			return 0;
		if (bInThisProcessOnly)
			return pData->dwActiveDownloadsCount;
		RemoveNonExistingProcessFromList ();
		DWORD dwResult = 0;
		for (size_t i = 0; i < vmsBrowsersSharedData_MAXBROWSERPROCESSES; i++)
			dwResult += pData [i].dwActiveDownloadsCount;
		return dwResult;
	}
protected:
	void RemoveNonExistingProcessFromList ()
	{
		DataStruct *pData = (DataStruct*) m_data.getData ();
		if (!pData)
			return;
		WaitForSingleObject (m_hmxData, INFINITE);
		for (size_t i = 0; i < vmsBrowsersSharedData_MAXBROWSERPROCESSES; i++)
		{
			if (pData [i].dwPID && !isProcessAlive (pData [i].dwPID))
			{
				pData [i].dwPID = 0;
				pData [i].dwActiveDownloadsCount = 0;
			}
		}
		ReleaseMutex (m_hmxData);
	}
	static bool isProcessAlive (DWORD dwPID)
	{
		HANDLE hProcess = OpenProcess (SYNCHRONIZE, FALSE, dwPID);
		if (!hProcess)
			hProcess = OpenProcess (PROCESS_QUERY_INFORMATION, FALSE, dwPID);
		if (!hProcess)
			hProcess = OpenProcess (PROCESS_QUERY_LIMITED_INFORMATION, FALSE, dwPID);
		if (hProcess)
			CloseHandle (hProcess);
		return hProcess != NULL;			
	}
	DataStruct* getDataStructForThisProcess ()
	{
		DataStruct *pData = (DataStruct*) m_data.getData ();
		if (!pData)
			return NULL;
		DWORD dwPID = GetCurrentProcessId ();
		for (size_t i = 0; i < vmsBrowsersSharedData_MAXBROWSERPROCESSES; i++)
		{
			if (pData [i].dwPID == dwPID)
				return pData;
		}
		WaitForSingleObject (m_hmxData, INFINITE);
		DataStruct *pResult = NULL;
		for (size_t i = 0; i < vmsBrowsersSharedData_MAXBROWSERPROCESSES; i++)
		{
			if (!pData [i].dwPID)
			{
				pResult = pData + i;
				break;
			}
		}
		if (!pResult) for (size_t i = 0; i < vmsBrowsersSharedData_MAXBROWSERPROCESSES; i++)
		{
			if (!isProcessAlive (pData [i].dwPID))
			{
				pResult = pData + i;
				break;
			}
		}
		if (pResult)
		{
			pResult->dwPID = dwPID;
			pResult->dwActiveDownloadsCount = 0;
		}
		ReleaseMutex (m_hmxData);
		return pResult;
	}
	vmsSharedData m_data;
	HANDLE m_hmxData;
};