/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSTASK_COPYFILE_H__017F31B6_5F46_41E0_AAF4_7E4E0EF2E01D__INCLUDED_)
#define AFX_VMSTASK_COPYFILE_H__017F31B6_5F46_41E0_AAF4_7E4E0EF2E01D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsTask.h"

class vmsTask_CopyFile : public vmsTask  
{
public:
	bool Do();
	void setDstFile (LPCTSTR ptsz);
	void setSrcFile (LPCTSTR ptszSrc);
	vmsTask_CopyFile();
	virtual ~vmsTask_CopyFile();

protected:
	tstring m_tstrDstFile;
	tstring m_tstrSrcFile;
};

#endif 
