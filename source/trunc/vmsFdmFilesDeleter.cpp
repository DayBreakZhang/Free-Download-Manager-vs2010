/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsFdmFilesDeleter.h"
#include "FdmApp.h"
#include "DlgElevateRequired.h"
#include "vmsElevatedFdm.h"
#include "VistaFx/VistaFx.h"

vmsFdmFilesDeleter::vmsFdmFilesDeleter(void)
{
}

vmsFdmFilesDeleter::~vmsFdmFilesDeleter(void)
{
}

bool vmsFdmFilesDeleter::DeleteBrowserPluginFiles(std::vector <std::auto_ptr <vmsBrowserPluginFileDeleter> >& vFiles)
{
	bool bOK = true;

	std::vector <vmsKnownBrowsers::Browser> vPluginsToDeleteElevated;

	for (size_t i = 0; i < vFiles.size (); i++)
	{
		vFiles [i]->setOnDeleteErrorHandler (onBrowserPluginFileDeleteError);

		if (vFiles [i]->DeleteFileEx ())
			continue;

		
		if (vFiles [i]->getErrorType () == vmsFileDeleter::NotEnoughRights && VistaFx::IsVistaOrHigher () && !IsUserAnAdmin ())
		{
			vPluginsToDeleteElevated.push_back (vFiles [i]->getBrowser ());
			continue;
		}

		bOK = false;
	}

	if (!vPluginsToDeleteElevated.empty ())
	{
		if (!vmsElevatedFdm::o ().InstallIntegration (vPluginsToDeleteElevated, false, true))
			bOK = false;
	}
	
	return bOK;
}

bool vmsFdmFilesDeleter::onBrowserPluginFileDeleteError(vmsFileDeleter* pDeleter)
{
	if (pDeleter->getErrorType () != vmsFileDeleter::FileIsInUse)
		return false;

	vmsBrowserPluginFileDeleter *pBrPlDeleter = (vmsBrowserPluginFileDeleter*)pDeleter;
	bool bBrowserWasRunning = false;

	while (vmsKnownBrowsers::isBrowserRunning (pBrPlDeleter->getBrowser ()))
	{
		bBrowserWasRunning = true;
		CString str;
		str.Format (LS (L_CANT_DEL_BR_PLUG_BR_IS_RUNNING), vmsKnownBrowsers::getBrowserUiName (pBrPlDeleter->getBrowser ()));
		if (IDCANCEL == MessageBox (NULL, str, _T ("Free Download Manager"), MB_OKCANCEL | MB_ICONEXCLAMATION | MB_SYSTEMMODAL))
			return false;
	}

	if (!bBrowserWasRunning)
	{
		CString str;
		str.Format (LS (L_CANT_DEL_BR_PLUG_WILL_BE_DEL_AT_REBOOT), vmsKnownBrowsers::getBrowserUiName (pBrPlDeleter->getBrowser ()));
		MessageBox (NULL, str, _T ("Free Download Manager"), MB_ICONEXCLAMATION | MB_SYSTEMMODAL);
	}

	return bBrowserWasRunning;
}
