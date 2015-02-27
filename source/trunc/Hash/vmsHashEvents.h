/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSHASHEVENTS_H__50EE80F4_0CC4_4E62_9293_9DB3C9CBB210__INCLUDED_)
#define AFX_VMSHASHEVENTS_H__50EE80F4_0CC4_4E62_9293_9DB3C9CBB210__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <stdlib.h> 

class vmsHashEvents  
{
public:
	virtual bool OnProgressChanged (double fPercentage) = NULL;

	vmsHashEvents();
	virtual ~vmsHashEvents();

};

#endif 
