/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSSTRINGRECENTLIST_H__96BB04B7_84A0_41F8_9862_9D05601C5912__INCLUDED_)
#define AFX_VMSSTRINGRECENTLIST_H__96BB04B7_84A0_41F8_9862_9D05601C5912__INCLUDED_

#include "vmsStringList.h"	
#if _MSC_VER > 1000
#pragma once
#endif 

class vmsStringRecentList  
{
public:
	BOOL Load (HANDLE hFile);
	BOOL Save (HANDLE hFile);
	void Clear();
	LPCSTR get_String (int nIndex) const;
	int get_Count () const;
	void Add(LPCSTR psz);
	vmsStringRecentList();
	virtual ~vmsStringRecentList();

protected:
	int m_nMaxEntries;
	vmsStringList m_vList;
};

#endif 
