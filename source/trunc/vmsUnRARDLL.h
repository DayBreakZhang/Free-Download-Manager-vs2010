/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSUNRARDLL_H__3C62C56A_FEA7_4A2A_A83A_D6F5809CB142__INCLUDED_)
#define AFX_VMSUNRARDLL_H__3C62C56A_FEA7_4A2A_A83A_D6F5809CB142__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsDLL.h"
#include <archive\unrar.h>

class vmsUnRARDLL : public vmsDLL  
{
public:
	int RARCloseArchive (HANDLE hArcData);
	int RARProcessFile (HANDLE hArcData,int Operation,char *DestPath,char *DestName);
	int RARReadHeader (HANDLE hArcData,struct RARHeaderData *HeaderData);
	void RARSetCallback (HANDLE hArcData,UNRARCALLBACK Callback,LONG UserData);
	HANDLE RAROpenArchiveEx (struct RAROpenArchiveDataEx *ArchiveData);

	virtual bool Load (LPCSTR pszDll);
	virtual void Free();

	vmsUnRARDLL(LPCSTR pszDll = NULL);
	virtual ~vmsUnRARDLL();

protected:
	typedef HANDLE (PASCAL *FNRAROAEX)(struct RAROpenArchiveDataEx *ArchiveData);
	typedef void   (PASCAL *FNRARSC)(HANDLE hArcData,UNRARCALLBACK Callback,LONG UserData);
	typedef int    (PASCAL *FNRARRH)(HANDLE hArcData,struct RARHeaderData *HeaderData);
	typedef int    (PASCAL *FNRARPF)(HANDLE hArcData,int Operation,char *DestPath,char *DestName);
	typedef int    (PASCAL *FNRARCA)(HANDLE hArcData);
	FNRAROAEX m_pfnRAROpenArchiveEx;
	FNRARSC m_pfnRARSetCallback;
	FNRARRH m_pfnRARReadHeader;
	FNRARPF m_pfnRARProcessFile;
	FNRARCA m_pfnRARCloseArchive;
};

#endif 
