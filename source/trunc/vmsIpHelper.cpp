/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsIpHelper.h"

vmsIpHelper::vmsIpHelper(void) : 
	m_pAdapters (NULL)
{
	
}

vmsIpHelper::~vmsIpHelper(void)
{
	SAFE_DELETE_BYTE_ARRAY (m_pAdapters);
}

bool vmsIpHelper::GetAdaptersInfo(void)
{
	SAFE_DELETE_BYTE_ARRAY (m_pAdapters);

	DWORD dwSize = 0;

	if (ERROR_BUFFER_OVERFLOW != ::GetAdaptersInfo (NULL, &dwSize))
		return false;

	m_pAdapters = (PIP_ADAPTER_INFO) new BYTE [dwSize];

	if (NO_ERROR != ::GetAdaptersInfo (m_pAdapters, &dwSize))
	{
		SAFE_DELETE_BYTE_ARRAY (m_pAdapters);
		return false;
	}

	return true;
}

PIP_ADAPTER_INFO vmsIpHelper::FindAdapterByIfIndex(DWORD dwIndex)
{
	PIP_ADAPTER_INFO pAdapter = m_pAdapters;
	while (pAdapter && pAdapter->Index != dwIndex)
		pAdapter = pAdapter->Next;
	return pAdapter;
}
