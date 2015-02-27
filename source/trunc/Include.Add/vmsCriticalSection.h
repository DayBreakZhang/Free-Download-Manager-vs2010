/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __VMS_CRITICAL_SECTION_
#define __VMS_CRITICAL_SECTION_

class vmsCriticalSection : public CRITICAL_SECTION
{
public:
	vmsCriticalSection () {InitializeCriticalSection (this);}
	virtual ~vmsCriticalSection () {DeleteCriticalSection (this);}

private:
	vmsCriticalSection (const vmsCriticalSection&) {assert (false);}
	vmsCriticalSection& operator = (const vmsCriticalSection&) {assert (false);}
};

class vmsCriticalSectionAutoLock
{
public:
	vmsCriticalSectionAutoLock (LPCRITICAL_SECTION pcs = NULL) : m_pcs (pcs) {
		if (m_pcs)
			EnterCriticalSection (m_pcs);
	}
	~vmsCriticalSectionAutoLock () {
		if (m_pcs)
			LeaveCriticalSection (m_pcs);
	}
	void Attach (LPCRITICAL_SECTION pcs)
	{
		Unlock ();
		m_pcs = pcs;
		if (m_pcs)
			EnterCriticalSection (m_pcs);
	}
	void Unlock () {
		if (m_pcs)
		{
			LeaveCriticalSection (m_pcs);
			m_pcs = NULL;
		}
	}
protected:
	LPCRITICAL_SECTION m_pcs;
};

#define vmsAUTOLOCKSECTION(sect) vmsCriticalSectionAutoLock csal_##sect (&sect)
#define vmsAUTOLOCKSECTION_PTR(sect) vmsCriticalSectionAutoLock csal_##sect (sect)

#define vmsAUTOLOCKSECTION_UNLOCK(sect) csal_##sect.Unlock()

class vmsCriticalSectionEx : protected vmsCriticalSection
{
public:
	void Lock () 
	{
		::EnterCriticalSection (this);
		m_cLocks++;
	}
        void Unlock ()
        {
        	assert (m_cLocks > 0);
		m_cLocks--;
		::LeaveCriticalSection (this);
        }
        bool isLocked () const 
        {
        	return m_cLocks > 0;
        }

public:
	vmsCriticalSectionEx () {m_cLocks = 0;}
	virtual ~vmsCriticalSectionEx () {}

protected:
	int m_cLocks;
};

#endif