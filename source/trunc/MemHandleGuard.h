/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef MEMHANDLEGUARD_INCLUDED_FILE
#define MEMHANDLEGUARD_INCLUDED_FILE

class CMemHandleGuard
{
public:
	CMemHandleGuard(LPVOID& pMemPtr, bool& bFailedToRelease);
	virtual ~CMemHandleGuard();

private:
	LPVOID& m_pMemPtr;
	bool& m_bFailedToRelease;
};

#endif
