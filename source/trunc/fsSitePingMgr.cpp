/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "fsSitePingMgr.h"
#include "inetutil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

fsSitePingMgr::fsSitePingMgr()
{
	m_hDllIcmp = LoadLibrary ("icmp.dll");
	if (m_hDllIcmp)
	{
		m_pfnIcmpCreateFile = (HANDLE (WINAPI *)(void))
			GetProcAddress (m_hDllIcmp, "IcmpCreateFile");

		m_pfnIcmpCloseHandle = (BOOL (WINAPI *)(HANDLE))
			GetProcAddress (m_hDllIcmp, "IcmpCloseHandle");

		m_pfnIcmpSendEcho = (DWORD (WINAPI *)
			(HANDLE,DWORD,LPVOID,WORD,PIPINFO,LPVOID,DWORD,DWORD))
			GetProcAddress (m_hDllIcmp, "IcmpSendEcho");
    }
}

fsSitePingMgr::~fsSitePingMgr()
{
	if (m_hDllIcmp)
		FreeLibrary (m_hDllIcmp);
}

DWORD fsSitePingMgr::Ping(LPCSTR pszSite)
{
   
    IPINFO ipInfo;
    

	WORD w = MAKEWORD (1,1);
	WSADATA data;
	::WSAStartup (w, &data);

	if (TestState () == FALSE)
		return SPM_PINGERR;

    HANDLE hFile = m_pfnIcmpCreateFile();

    if (hFile == NULL || hFile == INVALID_HANDLE_VALUE)
		return SPM_PINGERR;

    ipInfo.Ttl = 238; 
    ipInfo.Tos = 0;
    ipInfo.IPFlags = 0;
    ipInfo.OptSize = 0;
    ipInfo.Options = NULL;

	ULONG dwIp = fsGetSiteIp (pszSite);
	
	if (dwIp == 0)
	{
		m_pfnIcmpCloseHandle (hFile);
		return SPM_PINGERR;
	}

	char reply [sizeof (ICMPECHO)+50];
	ICMPECHO* iep = (ICMPECHO*) reply;
	iep->RTTime = 0xffffffff;

	char buftosend [32];
	memset (buftosend, 0, sizeof (buftosend));
    
     m_pfnIcmpSendEcho(
        hFile,        
        dwIp,        
        buftosend,            
        sizeof (buftosend),                
        NULL,        
        iep,       
        sizeof (reply),
        5000);            
 
    m_pfnIcmpCloseHandle (hFile);

	if (!iep->Status) 
		return iep->RTTime;
	else
		return SPM_PINGERR;
}

BOOL fsSitePingMgr::TestState()
{
	return m_hDllIcmp && m_pfnIcmpCloseHandle && m_pfnIcmpCreateFile &&
		m_pfnIcmpSendEcho;
}
