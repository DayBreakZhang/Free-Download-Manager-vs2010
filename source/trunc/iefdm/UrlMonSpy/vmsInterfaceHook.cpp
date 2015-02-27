/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "StdAfx.h"
#include "vmsInterfaceHook.h"

vmsInterfaceHook::vmsInterfaceHook(void)
{
}

vmsInterfaceHook::~vmsInterfaceHook(void)
{
}

bool vmsInterfaceHook::HookMethod (LPVOID pvObject, LPVOID pfnHook, int nMethod)
{
	vmsCriticalSectionAutoLock csal (&m_csHooks);

	int nIndex = findHookIndex (pvObject, nMethod);
	if (nIndex != -1)
		return true;

	Entry hook;
	hook.ppvVat = *(LPVOID**)pvObject;
	hook.nMethod = nMethod;
	hook.pvOriginalFn = hook.ppvVat [nMethod];

	DWORD dw = 0;
	if (FALSE == VirtualProtect (hook.ppvVat, sizeof (LONG_PTR) * (hook.nMethod+1), PAGE_EXECUTE_READWRITE, &dw))
		return false;

	m_vHooks.push_back (hook);

	assert (hook.ppvVat [hook.nMethod] != pfnHook);
	hook.ppvVat [hook.nMethod] = pfnHook;

	return true;
}

int vmsInterfaceHook::findHookIndex(LPVOID pvObject, int nMethod) const
{
	LPVOID *ppvVat = *(LPVOID**)pvObject;
	for (size_t i = 0; i < m_vHooks.size (); i++)
	{
		if (m_vHooks [i].ppvVat == ppvVat && m_vHooks [i].nMethod == nMethod)
			return (int)i;
	}
	return -1;
}

const vmsInterfaceHook::Entry* vmsInterfaceHook::getHook(int nIndex) const
{
	assert (nIndex >= 0 && nIndex < m_vHooks.size ());
	if (nIndex < 0 || nIndex >= (int)m_vHooks.size ())
		return NULL;
	return &m_vHooks [nIndex];
}
