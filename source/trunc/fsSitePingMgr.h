/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSSITEPINGMGR_H__1BAAAB51_387A_48AF_AE8E_ED94B0C8F2F8__INCLUDED_)
#define AFX_FSSITEPINGMGR_H__1BAAAB51_387A_48AF_AE8E_ED94B0C8F2F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#define SPM_PINGERR	UINT_MAX

typedef struct tagIPINFO
{
    BYTE Ttl;                
    BYTE Tos;                
    BYTE IPFlags;            
    BYTE OptSize;            
    BYTE FAR *Options;    
}IPINFO, *PIPINFO;

typedef struct tagICMPECHO
{
    ULONG Source;            
    ULONG Status;            
    ULONG RTTime;            
    WORD DataSize;        
    WORD Reserved;        
    void FAR *pData;        
    IPINFO    ipInfo;            
}ICMPECHO, *PICMPECHO;

class fsSitePingMgr  
{
public:
	
	DWORD Ping (LPCSTR pszSite);
	
	BOOL TestState();
	
	fsSitePingMgr();
	virtual ~fsSitePingMgr();

protected:
	HANDLE (WINAPI *m_pfnIcmpCreateFile)(VOID);
	BOOL (WINAPI *m_pfnIcmpCloseHandle)(HANDLE);
	DWORD (WINAPI *m_pfnIcmpSendEcho)(HANDLE,DWORD,LPVOID,WORD,PIPINFO,LPVOID,DWORD,DWORD);
	HMODULE m_hDllIcmp;	

};

#endif 
