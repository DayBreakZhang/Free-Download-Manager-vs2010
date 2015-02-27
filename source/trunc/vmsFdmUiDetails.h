/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsKnownBrowsers.h"
class vmsFdmUiDetails
{
public:
	struct KnownBrowserData
	{
		vmsKnownBrowsers::Browser enBrowser;
		UINT nCtrlId;
		DWORD dwUserSwitchedOnFlag; 
		UINT nCantInstallMsgLngId;
		UINT nCantDeinstallMgrLngId;
	};
public:
	static const KnownBrowserData* getKnownBrowsersData (size_t &cBrowsers) 
	{
		static const KnownBrowserData aBrowsers [] = {
			{vmsKnownBrowsers::Opera, IDC_OPERA, MONITOR_USERSWITCHEDON_OPERA, L_CANTINITOPMONITOR, L_CANTDEINITOPMONITOR},
			{vmsKnownBrowsers::Netscape, IDC_NETSCAPE, MONITOR_USERSWITCHEDON_NETSCAPE, L_CANTINITNETMONITOR, L_CANTDEINITNETMONITOR},
			{vmsKnownBrowsers::MozillaSuite, IDC_MOZILLA, MONITOR_USERSWITCHEDON_SEAMONKEY, L_CANTINITMOZMONITOR, L_CANTDEINITMOZMONITOR},
			{vmsKnownBrowsers::Safari, IDC_SAFARI, MONITOR_USERSWITCHEDON_SAFARI, L_CANTINITSAFARIMONITOR, L_CANTDEINITSAFARIMONITOR},
		};
		cBrowsers = _countof (aBrowsers);
		return aBrowsers;
	}
public:
	vmsFdmUiDetails(void);
	~vmsFdmUiDetails(void);
};

