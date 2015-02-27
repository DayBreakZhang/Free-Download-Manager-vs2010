/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHTTPRESOURCECONTAINER_H__53946559_48A1_440D_B688_E3609F07DFD3__INCLUDED_)
#define AFX_VMSHTTPRESOURCECONTAINER_H__53946559_48A1_440D_B688_E3609F07DFD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsHttpRequest.h"
#include "vmsHttpResponse.h"

class vmsHttpResourceContainer  
{
public:
	
	
	
	virtual BOOL ProcessRequest (vmsHttpRequest &request, vmsHttpResponse &response) = NULL;

	vmsHttpResourceContainer();
	virtual ~vmsHttpResourceContainer();

};

#endif 
