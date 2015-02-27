/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsProcessList.h"
#include <tlhelp32.h>
#include "vmsSystem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsProcessList::vmsProcessList()
{

}

vmsProcessList::~vmsProcessList()
{

}

void vmsProcessList::GenerateList(GenerateListMethod enMethod)
{
	m_vItems.clear ();

	HANDLE hSnapshot = CreateToolhelp32Snapshot (TH32CS_SNAPALL, NULL);
	ASSERT (hSnapshot != INVALID_HANDLE_VALUE);
    if (hSnapshot == INVALID_HANDLE_VALUE) 	
		return;
	    
    PROCESSENTRY32 pe = {sizeof (PROCESSENTRY32)}; 
    BOOL bOk = Process32First (hSnapshot, &pe);
    while (bOk)
    {
        bOk = Process32Next (hSnapshot, &pe);

		vmsProcessListItem item;
		item.tstrExeName = pe.szExeFile;
		item.dwProcessId = pe.th32ProcessID;

		switch (enMethod)
		{
		case GetExeNamesOnly:
			break;

		case GetFullPathToExes:
			HANDLE hProcess; hProcess = OpenProcess (PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, 
				FALSE, item.dwProcessId);
			if (hProcess != NULL)
			{
				TCHAR tsz [MAX_PATH] = _T ("\"");
				if (vmsSystem::GetModuleFileNameEx (hProcess, NULL, tsz+1, MAX_PATH-2))
				{
					_tcscat (tsz, _T ("\""));
					item.cmdline.fromString (tsz);
				}
				CloseHandle (hProcess);
			}
			break;

		case GetFullCommandLine:
			TCHAR tsz [MAX_PATH]; UINT nSize; nSize = MAX_PATH;
			if (vmsSystem::GetProcessCommandLine (item.dwProcessId, tsz, &nSize))
				item.cmdline.fromString (tsz);
			break;
		}

		m_vItems.push_back (item);
    }

	ASSERT (m_vItems.size () != 0);
	
	CloseHandle (hSnapshot);
}

int vmsProcessList::getProcessCount() const
{
	return m_vItems.size ();
}

const vmsProcessListItem* vmsProcessList::getProcess(int nIndex) const
{
	return &m_vItems [nIndex];
}

int vmsProcessList::findProcessIndex(LPCTSTR ptszExeName) const
{
	if (ptszExeName == NULL)
		return -1;

	for (int i = 0; i < m_vItems.size (); i++)
	{
		if (_tcsicmp (m_vItems [i].tstrExeName.c_str (), ptszExeName) == 0)
			return i;
	}

	return -1;
}

int vmsProcessList::findProcessIndex(const vmsCommandLine &cl, bool bAtLeastExeMatchOnly) const
{
	for (size_t i = 0; i < m_vItems.size (); i++)
	{
		if (m_vItems [i].cmdline == cl)
			return i;
	}

	if (bAtLeastExeMatchOnly)
	{
		for (size_t i = 0; i < m_vItems.size (); i++)
		{
			if (_tcsicmp (m_vItems [i].cmdline.getExe (), cl.getExe ()) == 0)
				return i;
		}
	}

	return -1;
}
