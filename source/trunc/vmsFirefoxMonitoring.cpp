/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "FdmApp.h"
#include "vmsFirefoxMonitoring.h"
#include "vmsFirefoxExtensionInstaller.h"
#include "vmsAppGlobalObjects.h"
#include "vmsFirefoxUtil.h"
#include "vmsFirefoxExtensionInfo.h"
#include "vmsTmpFileName.h"

#define FLASHGOT_CID	"{19503e42-ca3c-4c27-b1e2-9cdb2170ee34}"
#define FDM_CID			"fdm_ffext@freedownloadmanager.org"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

vmsFirefoxMonitoring::vmsFirefoxMonitoring()
{

}

vmsFirefoxMonitoring::~vmsFirefoxMonitoring()
{

}

bool vmsFirefoxMonitoring::IsInstalled()
{
	return vmsFirefoxExtensionInstaller::IsInstalled (FDM_CID, true);
}

bool vmsFirefoxMonitoring::IsFlashGotInstalled()
{
	return vmsFirefoxExtensionInstaller::IsInstalled (FLASHGOT_CID, true);
}

bool vmsFirefoxMonitoring::Install(bool bInstall)
{
	assert (_spFfExtUpdateMgr != NULL);
	CString strPath;
	if (!_spFfExtUpdateMgr)
	{
		strPath = ((CFdmApp*)AfxGetApp ())->m_strAppPath;
		strPath += "Firefox\\Extension";
	}
	else
	{
		strPath = _spFfExtUpdateMgr->getExtensionPath ();
	}
	return vmsFirefoxExtensionInstaller::Do (FDM_CID, strPath, bInstall);
}

bool vmsFirefoxMonitoring::IsEnabledInFirefox(bool &bEnabled)
{
	TCHAR tszPath [MAX_PATH] = _T ("");
	if (!vmsFirefoxUtil::GetDefaultProfilePath (tszPath))
		return false;
	if (!*tszPath)
		return false;

	vmsFirefox26ExtensionInfo fei26;
	if(CheckEnabled(fei26, tszPath, _T ("\\extensions.json"), bEnabled))
		return true;

	vmsFirefoxExtensionInfo fei;
	if(CheckEnabled(fei, tszPath, _T ("\\extensions.sqlite"), bEnabled))
		return true;

	return false;
}

bool vmsFirefoxMonitoring::CheckEnabled(vmsFirefoxExtensionInfo& fei,
		LPCTSTR profile, LPCTSTR file, bool& bEnabled)
{
	bEnabled = false;
	TCHAR tszPath[MAX_PATH];
	_tcsncpy(tszPath, profile, MAX_PATH);
	_tcsncat(tszPath, file, MAX_PATH);

	if (!fei.Read (tszPath, FDM_CID))
	{
		vmsTmpFileName tmpFile;
		if (!CopyFile (tszPath, tmpFile, FALSE))
			return false;
		if (!fei.Read (tmpFile, FDM_CID))
			return false;
	}

	bEnabled = !fei.m_iAppDisabled && !fei.m_iSoftDisabled && !fei.m_iUserDisabled;

	return true;
}
