/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include <Windows.h>

#include "mozilla/ModuleUtils.h"

#include "FDMUrl.h"
#include "FDMUrlListReceiver.h"
#include "FDMUrlReceiver.h"
#include "FDMForFirefox.h"
#include "FDMFirefoxExtension.h"
#include "FDMFfCacheMonitor.h"

#include <vector>
#include <string>
#include "vmsBinaryFileVersionInfo.h"

NS_GENERIC_FACTORY_CONSTRUCTOR(CFDMUrl)
NS_GENERIC_FACTORY_CONSTRUCTOR(CFDMUrlListReceiver)
NS_GENERIC_FACTORY_CONSTRUCTOR(CFDMUrlReceiver)
NS_GENERIC_FACTORY_CONSTRUCTOR(CFDMForFirefox)
NS_GENERIC_FACTORY_CONSTRUCTOR(CFDMFirefoxExtension)
NS_GENERIC_FACTORY_CONSTRUCTOR(CFDMFfCacheMonitor)

NS_DEFINE_NAMED_CID(FDMURL_CID);
NS_DEFINE_NAMED_CID(FDMURLLISTRECEIVER_CID);
NS_DEFINE_NAMED_CID(FDMURLRECEIVER_CID);
NS_DEFINE_NAMED_CID(FDMFORFIREFOX_CID);
NS_DEFINE_NAMED_CID(FDMFIREFOXEXTENSION_CID);
NS_DEFINE_NAMED_CID(FDMFFCACHEMONITOR_CID);

static const mozilla::Module::CIDEntry kModuleCIDs [] = {
	{&kFDMURL_CID, false, NULL, CFDMUrlConstructor},
	{&kFDMURLLISTRECEIVER_CID, false, NULL, CFDMUrlListReceiverConstructor},
	{&kFDMURLRECEIVER_CID, false, NULL, CFDMUrlReceiverConstructor},
	{&kFDMFORFIREFOX_CID, false, NULL, CFDMForFirefoxConstructor},
	{&kFDMFIREFOXEXTENSION_CID, false, NULL, CFDMFirefoxExtensionConstructor},
	{&kFDMFFCACHEMONITOR_CID, false, NULL, CFDMFfCacheMonitorConstructor},
	{NULL}
};

static const mozilla::Module::ContractIDEntry kModuleContracts[] = {
	{FDMURL_CONTRACTID, &kFDMURL_CID},
	{FDMURLLISTRECEIVER_CONTRACTID, &kFDMURLLISTRECEIVER_CID},
	{FDMURLRECEIVER_CONTRACTID, &kFDMURLRECEIVER_CID},
	{FDMFORFIREFOX_CONTRACTID, &kFDMFORFIREFOX_CID},
	{FDMFIREFOXEXTENSION_CONTRACTID, &kFDMFIREFOXEXTENSION_CID},
	{FDMFFCACHEMONITOR_CONTRACTID, &kFDMFFCACHEMONITOR_CID},
	{NULL}
};

static const mozilla::Module::CategoryEntry kModuleCategories[] = {
	{"my-category", "my-key", FDMURL_CONTRACTID},
	{"my-category", "my-key", FDMURLLISTRECEIVER_CONTRACTID},
	{"my-category", "my-key", FDMURLRECEIVER_CONTRACTID},
	{"my-category", "my-key", FDMFORFIREFOX_CONTRACTID},
	{"my-category", "my-key", FDMFIREFOXEXTENSION_CONTRACTID},
	{"my-category", "my-key", FDMFFCACHEMONITOR_CONTRACTID},
	{NULL}
};

static mozilla::Module kModule = {
	2, 
	kModuleCIDs,
	kModuleContracts,
	kModuleCategories
};

NSMODULE_DEFN(nsFdmFfModule) = &kModule;

NS_IMPL_MOZILLA192_NSGETMODULE(&kModule);

HMODULE _hModule = NULL;

void vmsAdjustKModuleValue ()
{
	TCHAR tsz [MAX_PATH] = _T ("");
	GetModuleFileName (NULL, tsz, _countof (tsz));
	if (*tsz == 0)
		return;
	vmsBinaryFileVersionInfo bfvi;
	if (!bfvi.Retrieve (tsz))
		return;
	if (bfvi.m_appVersion.empty ())
		return;
	switch (bfvi.m_appVersion [0].dwVal)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		kModule.mVersion = 1;
		break;

	case 5:
		kModule.mVersion = 2;
		break;

	default:
		kModule.mVersion = bfvi.m_appVersion [0].dwVal;
		break;
	}
};

BOOL WINAPI DllMain (HINSTANCE hDll, DWORD fdwReason, LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{
		_hModule = hDll;

		vmsAdjustKModuleValue ();
	}
	return TRUE;
}

