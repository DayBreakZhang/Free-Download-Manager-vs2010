/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSEVENTSMGR_H__E2192B1F_EA57_41D6_9F36_601379609A9D__INCLUDED_)
#define AFX_FSEVENTSMGR_H__E2192B1F_EA57_41D6_9F36_601379609A9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"
#include "vmsPersistObject.h"

struct fsDescEvent;

struct fsDescEvent
{
	fsDescEvent () : pszEvent(0) {}

	LPSTR pszEvent;			
	COLORREF clrBg;			
	COLORREF clrText;		
	FILETIME timeEvent;		
	int iImage;				
};

struct vmsPersistableDescEventWrapper : public vmsObject, public vmsPersistObject
{
	fsDescEvent deEvent;

	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	vmsPersistableDescEventWrapper& operator = (const  vmsPersistableDescEventWrapper&);
};

typedef vmsObjectSmartPtr<vmsPersistableDescEventWrapper> vmsPersistableDescEventWrapperSmartPtr;

class fsEventsMgr : public vmsPersistObject
{
public:
	
	void add (fsDescEvent* ev);
	
	void clear();
	
	fsDescEvent* GetEvent (UINT uIndex);
	
	UINT GetEventCount();
	
	
	BOOL Save (HANDLE hFile);
	
	BOOL Load (HANDLE hFile);

	virtual void getObjectItselfStateBuffer(LPBYTE pb, LPDWORD pdwSize, bool bSaveToStorage);
	virtual bool loadObjectItselfFromStateBuffer(LPBYTE pb, LPDWORD pdwSize, DWORD dwVer);
	
	fsEventsMgr();
	virtual ~fsEventsMgr();

protected:
	
	fs::list <vmsPersistableDescEventWrapperSmartPtr> m_vEvents;	
};

#endif 
