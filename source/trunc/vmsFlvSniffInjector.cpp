/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fdm.h"
#include "vmsFlvSniffInjector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFlvSniffInjector::vmsFlvSniffInjector()
{
	m_bNeverFreeInjectedDlls = true;

#ifdef _DEBUG
	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MAX_PATH);
	_tcsrchr (tsz, '\\') [0] = 0;
	_tcsrchr (tsz, '\\') [0] = 0;
	_tcsrchr (tsz, '\\') [1] = 0;

	tstring tstr = tsz;
	m_vtstrDllsToInject.push_back (tstr + _T ("AppWinSockSniffDll\\detoured.dll"));
	m_vtstrDllsToInject.push_back (tstr + _T ("bin\\debug\\flvsniff.dll"));

	for (size_t i = 0; i < m_vtstrDllsToInject.size (); i++)
		ASSERT (GetFileAttributes (m_vtstrDllsToInject [i].c_str ()) != DWORD (-1));
#else
	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, MAX_PATH);
	_tcsrchr (tsz, '\\') [1] = 0;

	tstring tstr = tsz;
	m_vtstrDllsToInject.push_back (tstr + _T ("detoured.dll"));
	m_vtstrDllsToInject.push_back (tstr + _T ("flvsniff.dll"));
#endif

	getFsdiProcessList (_App.FlvMonitoring_ProcessList (), m_vtstrNamesOfProcesesToMonitor);

	m_bEnabled = false;
	m_htJob = NULL;
}

vmsFlvSniffInjector::~vmsFlvSniffInjector()
{
	Enable (false);
	assert (m_htJob == NULL);
}

vmsFlvSniffInjector& vmsFlvSniffInjector::o()
{
	static vmsFlvSniffInjector o;
	return o;
}

void vmsFlvSniffInjector::setProcessList(std::vector <tstring> &v)
{
	EnterCriticalSection (&m_csProcessList);
	m_vtstrNamesOfProcesesToMonitor = v;
	LeaveCriticalSection (&m_csProcessList);
}

void vmsFlvSniffInjector::Enable(bool b)
{
	if (b == m_bEnabled)
		return;

	if (m_bEnabled)
	{
		m_bEnabled = false;
		WaitForSingleObject (m_htJob, INFINITE);
		CloseHandle (m_htJob);
		m_htJob = NULL;
	}
	else
	{
		m_bEnabled = true;
		DWORD dw;
		m_htJob = CreateThread (NULL, 0, _threadJob, this, 0, &dw);
	}
}

DWORD WINAPI vmsFlvSniffInjector::_threadJob(LPVOID lp)
{
	vmsFlvSniffInjector *pthis = (vmsFlvSniffInjector*)lp;

	while (pthis->m_bEnabled)
	{
		pthis->DoJob ();
		for (int i = 0; i < 20 && pthis->m_bEnabled; i++)
			Sleep (50);
	}

	if (!pthis->m_bNeverFreeInjectedDlls)
		pthis->FreeDllsFromProcesses ();

	return 0;
}
