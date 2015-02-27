/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFdmCrashReporter.h"
#include "Include.Add/vmsCommandLineParser.h"
#include "vmsCommandLine.h"
#include "DlgUnhExc2.h"
#include "vmsAppMutex.h"

vmsFdmCrashReporter::vmsFdmCrashReporter(void)
{
}

vmsFdmCrashReporter::~vmsFdmCrashReporter(void)
{
}

void vmsFdmCrashReporter::onCrashDumpCreated ()
{
	vmsCommandLine cl;
	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, _countof (tsz));
	cl.setExe (tsz);
	tstring tstrArgs = _T ("-submitDump=\"");
	tstrArgs += m_tstrDumpFile;
	tstrArgs += _T ("\" -faultModule=\"");
	tstrArgs += m_tstrFaultModuleName;
	tstrArgs += _T ("\" -faultModuleCrashAddr=");
	_stprintf_s <MAX_PATH> (tsz, _T ("%I64x"), (UINT64)m_dwpFaultModuleCrashAddress);
	tstrArgs += tsz;
	cl.setArgs (tstrArgs.c_str ());
	cl.Execute ();
	
	TerminateProcess (GetCurrentProcess (), 1);
}

bool vmsFdmCrashReporter::CheckIfSubmitDumpIsRequestedByCommandLine(bool& bContinue)
{
	vmsCommandLineParser cp;

	const vmsCommandLineParser::Argument *pArgDump = cp.findArgument (_T ("submitDump"));
	if (!pArgDump)
		return false;

	const vmsCommandLineParser::Argument *pArgFaultModule = cp.findArgument (_T ("faultModule"));
	const vmsCommandLineParser::Argument *pArgFaultModuleCrashAddr = cp.findArgument (_T ("faultModuleCrashAddr"));

	bContinue = true;

	if (GetFileAttributes (pArgDump->second.c_str ()) == DWORD (-1))
		return true;

	bContinue = false;

	extern vmsAppMutex _appMutex;
	_appMutex.CloseMutex ();

	CoInitialize (NULL);

	CDlgUnhExc2 dlg;
	INT_PTR nRes = dlg.DoModal ();

	if (dlg.m_bRestartApp)
	{
		vmsCommandLine cl;
		TCHAR tsz [MAX_PATH] = _T ("");
		GetModuleFileName (NULL, tsz, _countof (tsz));
		cl.setExe (tsz);
		cl.Execute ();
	}

	if (nRes == IDOK)
	{
		std::string strXml;
		UINT64 uCrashAddr = 0;
		if (pArgFaultModuleCrashAddr)
			_stscanf (pArgFaultModuleCrashAddr->second.c_str (), _T ("%I64x"), &uCrashAddr);
		vmsCrashReporter::GenerateXml (_T ("Free Download Manager"), vmsFdmAppMgr::getVersion ()->m_tstrFileVersion.c_str (), 
			dlg.m_strDescription, pArgFaultModule ? pArgFaultModule->second.c_str () : NULL, (DWORD_PTR)uCrashAddr, NULL, strXml);

		SubmitDumpToServer (_T ("freedownloadmanager.org"), _T ("/dump.php"), pArgDump->second.c_str (), strXml.c_str ());
	}

	DeleteFile (pArgDump->second.c_str ());

	CoUninitialize ();

	return true;
}
