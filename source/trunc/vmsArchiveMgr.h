/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSARCHIVEMGR_H__EA5080C6_6467_4666_AF70_639ECE5CD370__INCLUDED_)
#define AFX_VMSARCHIVEMGR_H__EA5080C6_6467_4666_AF70_639ECE5CD370__INCLUDED_

#include "vmsArchiveRAR.h"	
#include "vms7zipArchive.h"	
#include "vmsArchive.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class vmsArchiveMgr  
{
public:
	vmsArchiveExtractError get_LastExtractError();
	void set_ArchiveCallback (vmsArchiveCallback* pAC);
	bool Extract (LPCSTR pszArchive, LPCSTR pszOutFolder);
	vmsArchiveMgr();
	virtual ~vmsArchiveMgr();

protected:
	
	vms7zipArchive m_7zip;
	
	vmsArchiveRAR m_rar;
	
	vmsArchive* m_pUsedArchive;
};

#endif 
