/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMS7ZIPARCHIVE_H__20D226EB_843A_4611_9967_99E67DCD3CF1__INCLUDED_)
#define AFX_VMS7ZIPARCHIVE_H__20D226EB_843A_4611_9967_99E67DCD3CF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsArchive.h"
#include "vms7zipFormatDLL.h"
#include <archive\mycom.h>
struct IInArchive;
struct IInStream;

class vms7zipArchive : public vmsArchive
{
public:
	virtual bool Extract (LPCSTR pszArchive, LPCSTR pszOutFolder);
	vms7zipArchive();
	virtual ~vms7zipArchive();

protected:
	bool Find7zipDLL(vms7zipFormatDLL &dll, LPCSTR pszArchive, bool bByExt, CMyComPtr <IInStream> &spFile, CMyComPtr <IInArchive> &spArc);
};

#endif 
