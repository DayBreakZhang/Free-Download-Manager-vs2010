/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSPROCESSESINJECTOR_H__CE05CDB8_274C_4898_8BDC_85719C353D4E__INCLUDED_)
#define AFX_VMSPROCESSESINJECTOR_H__CE05CDB8_274C_4898_8BDC_85719C353D4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsProcessesInjector  
{
public:
	void DoJob();
	vmsProcessesInjector();
	virtual ~vmsProcessesInjector();

protected:
	struct ProcessedProcess
	{
		DWORD dwPID;
		std::vector <HMODULE> vhInjectedDlls;
	};

protected:
	void FreeDllsFromProcess (ProcessedProcess *pp);
	CRITICAL_SECTION m_csProcessList;
	void FreeDllsFromProcesses ();
	void InjectIntoProcess (ProcessedProcess *pp);
	
	std::vector <ProcessedProcess> m_vProcesses;
	std::vector <tstring> m_vtstrNamesOfProcesesToMonitor;
	std::vector <tstring> m_vtstrDllsToInject;
	bool m_bNeverFreeInjectedDlls;
};

#endif 
