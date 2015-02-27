/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsCriticalSection.h"

class vmsInterfaceHook
{
public:
	struct Entry
	{
		LPVOID* ppvVat;
		int nMethod;
		LPVOID pvOriginalFn;
	};

public:
	vmsInterfaceHook(void);
	virtual ~vmsInterfaceHook(void);

protected:
	vector <Entry> m_vHooks;
	vmsCriticalSection m_csHooks;
public:
	bool HookMethod(LPVOID pvObject, LPVOID pfnHook, int nMethod);
	int findHookIndex(LPVOID pvObject, int nMethod) const;
	const Entry* getHook(int nIndex) const;
};

