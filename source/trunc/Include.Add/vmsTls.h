/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __VMS_TLS_H_
#define __VMS_TLS_H_

class vmsTls 
{
public:
	void setValue (LPVOID lp) {
		TlsSetValue (m_dwIndex, lp);
	}

	LPVOID getValue () {
		return TlsGetValue (m_dwIndex);
	}
	bool isTlsAllocatedSuccessfully () const {
		return m_dwIndex != TLS_OUT_OF_INDEXES;
	}
public:
	vmsTls () {
		m_dwIndex = TlsAlloc ();
		if (isTlsAllocatedSuccessfully ())
			setValue (NULL);
	}
	~vmsTls () {
		TlsFree (m_dwIndex);
	}
protected:
	DWORD m_dwIndex;
};

#endif