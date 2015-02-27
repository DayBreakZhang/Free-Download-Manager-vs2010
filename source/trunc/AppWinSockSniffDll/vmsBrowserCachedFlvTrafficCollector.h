/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSBROWSERCACHEDFLVTRAFFICCOLLECTOR_H__FB0DF659_AFE5_4B10_A8E1_03D2CE8A1F0D__INCLUDED_)
#define AFX_VMSBROWSERCACHEDFLVTRAFFICCOLLECTOR_H__FB0DF659_AFE5_4B10_A8E1_03D2CE8A1F0D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpTrafficCollector.h"

class vmsBrowserCachedFlvTrafficCollector : public vmsHttpTrafficCollector  
{
public:
	static bool DoesCurrentProcessHaveCache();
	void AddSourceDialog (const HttpDialog* pDlg);
	static vmsBrowserCachedFlvTrafficCollector& o();
	vmsBrowserCachedFlvTrafficCollector();
	virtual ~vmsBrowserCachedFlvTrafficCollector();

protected:
	void Initialize();
};

#endif 
