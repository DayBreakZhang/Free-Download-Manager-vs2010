/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFDMAPIIMPL_H__BC1554F9_9C84_4923_A585_358A29C3DD3A__INCLUDED_)
#define AFX_VMSFDMAPIIMPL_H__BC1554F9_9C84_4923_A585_358A29C3DD3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Plugins API/fdm.h"

class vmsFdmApiImpl : public vmsFdmApi  
{
public:
	HWND getFdmWindowHandle();
	vmsFdmApiDownloadsMgr* getDownloadsMgr();
	void ShutdownFdm();
	UINT getFdmBuildNumber();
	static vmsFdmApiImpl& o();
	vmsFdmApiImpl();
	virtual ~vmsFdmApiImpl();

};

#endif 
