/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTASK_H__F1444144_0EB2_4D7A_A71E_543249580272__INCLUDED_)
#define AFX_VMSTASK_H__F1444144_0EB2_4D7A_A71E_543249580272__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsTask  
{
public:
	virtual bool Do () = NULL;

	vmsTask();
	virtual ~vmsTask();

};

#endif 
