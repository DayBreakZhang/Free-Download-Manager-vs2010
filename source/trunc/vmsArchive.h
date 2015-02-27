/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSARCHIVE_H__445E6510_F791_4E22_809D_17DF225A6762__INCLUDED_)
#define AFX_VMSARCHIVE_H__445E6510_F791_4E22_809D_17DF225A6762__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsArchiveCallback.h"

enum vmsArchiveExtractError 
{
	AEE_NO_ERROR,
	AEE_GENERIC_ERROR,
	AEE_ABORTED_BY_USER,
};

class vmsArchive  
{
public:
	vmsArchiveExtractError get_LastExtractError();
	void set_ArchiveCallback (vmsArchiveCallback* pAC);
	
	
	
	virtual bool Extract (LPCSTR pszArchive, LPCSTR pszOutFolder) = NULL;

	vmsArchive();
	virtual ~vmsArchive();

protected:
	vmsArchiveCallback* m_pAC;
	vmsArchiveExtractError m_errExtract;
};

#endif 
