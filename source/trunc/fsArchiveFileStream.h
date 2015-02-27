/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSARCHIVEFILESTREAM_H__45E93C38_3666_426D_82A8_3E66455B6DD1__INCLUDED_)
#define AFX_FSARCHIVEFILESTREAM_H__45E93C38_3666_426D_82A8_3E66455B6DD1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsArchiveRebuilderStream.h"

namespace fsArchive
{

class fsArchiveFileStream : public fsArchiveStream  
{
public:
	
	HANDLE Detach();
	
	void Attach (HANDLE hFile);
	
	void Close();
	
	DWORD Open (LPCSTR pszFile, DWORD dwGenFlags);
	
	BOOL Seek (UINT64 dist, fsSeekType met);
	
	int Write (LPVOID buf, int cBytes);
	
	int Read (LPVOID buf, int cBytes);
	fsArchiveFileStream();
	virtual ~fsArchiveFileStream();

protected:
	HANDLE m_hFile;	
};

};

#endif 
