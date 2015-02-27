/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSTRINGLIST_H__C29CF9E3_9C2B_42BF_A976_4F2B69F7DF0B__INCLUDED_)
#define AFX_VMSSTRINGLIST_H__C29CF9E3_9C2B_42BF_A976_4F2B69F7DF0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "list.h"

class vmsStringList  
{
public:
	void Clear();
	
	BOOL Load (HANDLE hFile);
	BOOL Save (HANDLE hFile);
	LPCSTR get_String (int nIndex) const;
	void Del (int nIndex);
	int get_Count() const;
	void Add (LPCSTR psz);

	vmsStringList();
	virtual ~vmsStringList();

protected:
	fs::list <fsString> m_vList;
};

#endif 
