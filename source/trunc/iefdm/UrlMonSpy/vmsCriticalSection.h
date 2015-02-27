/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __VMS_CRITICAL_SECTION_
#define __VMS_CRITICAL_SECTION_

class vmsCriticalSection : public CRITICAL_SECTION
{
public:
	vmsCriticalSection () {InitializeCriticalSection (this);}
	~vmsCriticalSection () {DeleteCriticalSection (this);}
};

class vmsCriticalSectionAutoLock
{
public:
	vmsCriticalSectionAutoLock (LPCRITICAL_SECTION pcs) : m_pcs (pcs) {
		assert (m_pcs != NULL); 
		EnterCriticalSection (m_pcs);
	}
	~vmsCriticalSectionAutoLock () {LeaveCriticalSection (m_pcs);}
protected:
	LPCRITICAL_SECTION m_pcs;
};

#endif