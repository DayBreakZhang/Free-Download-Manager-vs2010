/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSFDMAPIDOWNLOADIMPL_H__0F383C63_0071_4051_B278_83B0D1A1A331__INCLUDED_)
#define AFX_VMSFDMAPIDOWNLOADIMPL_H__0F383C63_0071_4051_B278_83B0D1A1A331__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "Plugins API/fdm.h"

class vmsFdmApiDownloadImpl : public vmsFdmApiDownload  
{
public:
	vmsFdmApiDownloadImpl();
	virtual ~vmsFdmApiDownloadImpl();

public:
	UINT getId();
	float getProgress();
	void getUrl (LPSTR pszUrl);
	void getFileName (LPSTR pszFileName);
	void DeleteFileOnDisk ();
	void DeleteDownload (BOOL bAskConfirmation);
	void PerformCommand (vmsFdmApiDownloadCommand enCmd);
	vmsFdmApiDownloadState getState();
	vmsDownloadSmartPtr m_dld;
};

#endif 
