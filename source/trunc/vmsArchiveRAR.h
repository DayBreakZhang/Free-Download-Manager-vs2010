/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSARCHIVERAR_H__520A98B5_957C_4390_84BF_6D20F164985C__INCLUDED_)
#define AFX_VMSARCHIVERAR_H__520A98B5_957C_4390_84BF_6D20F164985C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsArchive.h"
#include "vmsUnRARDLL.h"	

class vmsArchiveRAR : public vmsArchive  
{
public:
	virtual bool Extract (LPCSTR pszArchive, LPCSTR pszOutFolder);
	vmsArchiveRAR();
	virtual ~vmsArchiveRAR();

protected:
	vmsUnRARDLL m_unrar;
};

#endif 
