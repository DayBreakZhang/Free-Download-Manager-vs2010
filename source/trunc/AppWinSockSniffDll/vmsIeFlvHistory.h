/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSIEFLVHISTORY_H__3BE96C7F_5CE7_4137_9D4C_3BCBAF80014A__INCLUDED_)
#define AFX_VMSIEFLVHISTORY_H__3BE96C7F_5CE7_4137_9D4C_3BCBAF80014A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsBrowserFlvHistory.h"

class vmsIeFlvHistory : public vmsBrowserFlvHistory
{
public:
	void Gather();
	vmsIeFlvHistory();
	virtual ~vmsIeFlvHistory();

};

#endif 
