/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTASK_DELETEFILE_H__553B77E3_A361_4E98_9330_4D5A4012ED72__INCLUDED_)
#define AFX_VMSTASK_DELETEFILE_H__553B77E3_A361_4E98_9330_4D5A4012ED72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsTask.h"

class vmsTask_DeleteFile : public vmsTask  
{
public:
	void setFile (LPCTSTR ptsz);
	bool Do();
	vmsTask_DeleteFile();
	virtual ~vmsTask_DeleteFile();

protected:
	tstring m_tstrFile;
};

#endif 
