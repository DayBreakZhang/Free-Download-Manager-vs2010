/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSEVENTSMGR_H__E2192B1F_EA57_41D6_9F36_601379609A9D__INCLUDED_)
#define AFX_FSEVENTSMGR_H__E2192B1F_EA57_41D6_9F36_601379609A9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

struct fsDescEvent
{
	LPSTR pszEvent;			
	COLORREF clrBg;			
	COLORREF clrText;		
	FILETIME timeEvent;		
	int iImage;				
};

class fsEventsMgr  
{
public:
	
	void add (fsDescEvent* ev);
	
	void clear();
	
	fsDescEvent* GetEvent (UINT uIndex);
	
	UINT GetEventCount();
	
	
	BOOL Save (HANDLE hFile);
	
	BOOL Load (HANDLE hFile);
	
	fsEventsMgr();
	virtual ~fsEventsMgr();

protected:
	fs::list <fsDescEvent> m_vEvents;	
};

#endif 
