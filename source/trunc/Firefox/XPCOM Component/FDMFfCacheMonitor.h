/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FDMFFCACHEMONITOR_H__5033AAB8_80DE_4E6E_AF73_0688BC0C36C9__INCLUDED_)
#define AFX_FDMFFCACHEMONITOR_H__5033AAB8_80DE_4E6E_AF73_0688BC0C36C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "common.h"

#define FDMFFCACHEMONITOR_CONTRACTID "@freedownloadmanager.org/FDMFfCacheMonitor;1"
#define FDMFFCACHEMONITOR_CLASSNAME "Free Download Manager cache monitor component for Firefox"

#define FDMFFCACHEMONITOR_CID { 0xebfec047, 0xf68d, 0x491e, { 0x8d, 0x7d, 0x26, 0x8b, 0x9c, 0x76, 0x2c, 0xb7 } }

class CFDMFfCacheMonitor : public IFDMFfCacheMonitor 
{
public:
	NS_DECL_ISUPPORTS
	NS_DECL_IFDMFFCACHEMONITOR

	CFDMFfCacheMonitor();

private:
	virtual ~CFDMFfCacheMonitor();

};

#endif 
