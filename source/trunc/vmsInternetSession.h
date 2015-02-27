/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSINTERNETSESSION_H__D02A0038_60AB_46ED_8961_C277CA35463C__INCLUDED_)
#define AFX_VMSINTERNETSESSION_H__D02A0038_60AB_46ED_8961_C277CA35463C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "downloadproperties.h"

class vmsInternetSession : public fsInternetSession
{
public:
	fsInternetResult Create (LPCSTR pszAgent, fsInternetAccessTypeEx enAT, LPCSTR pszProxyName, fsNetworkProtocol enProtocol);

	vmsInternetSession();
	virtual ~vmsInternetSession();

};

#endif 
