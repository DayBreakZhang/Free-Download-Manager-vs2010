/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include <IPHlpApi.h>

class vmsIpHelper
{
public:
	vmsIpHelper(void);
	~vmsIpHelper(void);

protected:
	PIP_ADAPTER_INFO m_pAdapters;
public:
	bool GetAdaptersInfo(void);
	PIP_ADAPTER_INFO FindAdapterByIfIndex(DWORD dwIndex);
};

