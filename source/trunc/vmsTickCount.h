/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
class vmsTickCount
{
public:
	vmsTickCount(void);
	~vmsTickCount(void);
	static UINT64 GetTickCount64(void);
	static UINT64 WINAPI myGetTickCount64(void);
protected:
	static vmsCriticalSection *m_pcsMyGetTickCount64;
};

