/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSFTPFILES_H__9903206C_EB0F_46C8_A778_FF0D15F795F5__INCLUDED_)
#define AFX_FSFTPFILES_H__9903206C_EB0F_46C8_A778_FF0D15F795F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsInternetFiles.h"
#include "fsinet.h"	
#include "fsFtpConnection.h"	

class fsFtpFiles : public fsInternetFiles  
{
public:
	
	fsInternetResult GetList (LPCSTR pszUrl);
	void Abort();
	LPCSTR GetLastError();
	

	
	void SetServer (fsFtpConnection* pServer);
	
	void Reload (BOOL bReload = TRUE);
	
	
	fsFtpFiles();
	virtual ~fsFtpFiles();

protected:
	fsFtpConnection* m_pServer;	
	BOOL m_bReload;				
	BOOL m_bAbort;				
	
	fsInternetResult BuildList();
};

#endif 
