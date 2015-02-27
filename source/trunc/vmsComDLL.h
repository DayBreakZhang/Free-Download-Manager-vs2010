/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSCOMDLL_H__897037E0_6B9C_43C9_AD42_EC05A479F4B9__INCLUDED_)
#define AFX_VMSCOMDLL_H__897037E0_6B9C_43C9_AD42_EC05A479F4B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsDLL.h"

class vmsComDLL : public vmsDLL  
{
public:
	
	HRESULT RegisterServer (bool bRegister);
	
	virtual bool Load(LPCSTR pszDll);

	vmsComDLL();
	virtual ~vmsComDLL();

protected:
	
	typedef HRESULT (_stdcall *FNDLLRS)(void);
	
	FNDLLRS m_pfnRegServer, m_pfnUnregServer;

};

#endif 
