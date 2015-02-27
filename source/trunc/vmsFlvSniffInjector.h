/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFLVSNIFFINJECTOR_H__BFBC515D_DC0A_4CC6_832C_CD40E08A1D97__INCLUDED_)
#define AFX_VMSFLVSNIFFINJECTOR_H__BFBC515D_DC0A_4CC6_832C_CD40E08A1D97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsProcessesInjector.h"

#define FSDI_PROCESS_IE				(1<<0)
#define FSDI_PROCESS_FIREFOX		(1<<1)
#define FSDI_PROCESS_OPERA			(1<<2)
#define FSDI_PROCESS_NETSCAPE		(1<<3)
#define FSDI_PROCESS_SAFARI			(1<<4)
#define FSDI_PROCESS_CHROME			(1<<5)
#define FSDI_PROCESS_SEAMONKEY		(1<<6)

inline void getFsdiProcessList (DWORD dwFsdi, std::vector <tstring> &v)
{
	v.clear ();
	if (dwFsdi & FSDI_PROCESS_IE)
		v.push_back ("iexplore.exe");
	if (dwFsdi & FSDI_PROCESS_FIREFOX)
		v.push_back ("firefox.exe");
	if (dwFsdi & FSDI_PROCESS_OPERA)
		v.push_back ("opera.exe");
	if (dwFsdi & FSDI_PROCESS_NETSCAPE)
		v.push_back ("navigator.exe");
	if (dwFsdi & FSDI_PROCESS_SAFARI)
		v.push_back ("safari.exe");
	if (dwFsdi & FSDI_PROCESS_CHROME)
		v.push_back ("chrome.exe");
	if (dwFsdi & FSDI_PROCESS_SEAMONKEY)
		v.push_back ("seamonkey.exe");
}

class vmsFlvSniffInjector : protected vmsProcessesInjector  
{
public:
	void Enable (bool b);
	void setProcessList (std::vector <tstring> &v);
	static vmsFlvSniffInjector& o();
	vmsFlvSniffInjector();
	virtual ~vmsFlvSniffInjector();

protected:
	bool m_bEnabled;
	static DWORD WINAPI _threadJob (LPVOID lp);
	HANDLE m_htJob;
};

#endif 
