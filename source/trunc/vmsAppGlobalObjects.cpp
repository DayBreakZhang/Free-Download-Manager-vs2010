/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "vmsAppGlobalObjects.h"
#include "vmsFirefoxMonitoring.h"

std::tr1::shared_ptr <vmsFirefoxExtensionUpdateMgr> _spFfExtUpdateMgr;

void vmsAppGlobalObjects::Create2 (bool currentBuildFirstRun)
{
	_spFfExtUpdateMgr.reset (new vmsFirefoxExtensionUpdateMgr (currentBuildFirstRun));
	if (_spFfExtUpdateMgr->isExtensionPathChanged () && vmsFirefoxMonitoring::IsInstalled ())
		vmsFirefoxMonitoring::Install (true);
}