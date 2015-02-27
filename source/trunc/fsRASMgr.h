/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSRASMGR_H__F883A1B7_5803_4B21_B746_1FFC223A8DCA__INCLUDED_)
#define AFX_FSRASMGR_H__F883A1B7_5803_4B21_B746_1FFC223A8DCA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <ras.h>
#include <raserror.h>
#include "list.h"

class fsRASMgr  
{
public:
	
	BOOL EnumEntries();
	
	UINT GetEntriesCount();
	
	LPCSTR GetEntry (UINT nEntry);

	
	
	BOOL EnumConnections();
	int GetConnectionCount();
	LPRASCONN GetConnection (int iIndex);
	
	fsRASMgr();
	virtual ~fsRASMgr();

protected:
	fs::list <CString> m_vEntries;		
	fs::list <RASCONN> m_vConns;		
};

#endif 
