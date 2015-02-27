/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSOBJECT_H__7595731C_4D83_4B41_A552_4D9EDDC23912__INCLUDED_)
#define AFX_VMSOBJECT_H__7595731C_4D83_4B41_A552_4D9EDDC23912__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

class vmsObject  
{
public:
	void Release();
	void AddRef();
	vmsObject();
	virtual ~vmsObject();

protected:
	long m_cRefs;

};

#endif 
