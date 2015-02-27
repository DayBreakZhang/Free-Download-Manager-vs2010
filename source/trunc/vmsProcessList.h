/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_VMSPROCESSLIST_H__444E969D_40A9_47F1_848E_240E358F5C50__INCLUDED_)
#define AFX_VMSPROCESSLIST_H__444E969D_40A9_47F1_848E_240E358F5C50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "vmsCommandLine.h"

struct vmsProcessListItem
{
	tstring tstrExeName;
	vmsCommandLine cmdline;
	DWORD dwProcessId;
};

class vmsProcessList  
{
public:
	enum GenerateListMethod
	{
		GetExeNamesOnly,
		GetFullPathToExes,
		GetFullCommandLine,
	};
public:
	int findProcessIndex (const vmsCommandLine &cl, bool bAtLeastExeMatchOnly = false) const;
	void GenerateList(GenerateListMethod enMethod = GetExeNamesOnly);
	int findProcessIndex (LPCTSTR ptszExeName) const;
	const vmsProcessListItem* getProcess (int nIndex) const;
	int getProcessCount () const;

	vmsProcessList();
	virtual ~vmsProcessList();

protected:
	std::vector <vmsProcessListItem> m_vItems;

};

#endif 
