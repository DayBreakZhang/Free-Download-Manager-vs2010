/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSAVIIDX1BUILDER_H__9149F315_4E74_4E81_B14A_CBE57B23BA16__INCLUDED_)
#define AFX_FSAVIIDX1BUILDER_H__9149F315_4E74_4E81_B14A_CBE57B23BA16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include <windows.h>
#include <limits.h>

class fsAVIIdx1Builder  
{
public:
	
	UINT64 Get_Idx1StartPosition();
	
	
	
	
	BOOL BuildIdx1 (HANDLE in, HANDLE out, UINT64 uInMaxPos = _UI64_MAX);
	
	fsAVIIdx1Builder();
	virtual ~fsAVIIdx1Builder();

protected:
	UINT64 m_uIdx1Start;
};

#endif 
