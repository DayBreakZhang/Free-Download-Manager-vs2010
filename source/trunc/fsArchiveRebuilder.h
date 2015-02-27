/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSARCHIVEREBUILDER_H__12229CAE_4DBE_4E89_875D_4378C0C6E8FD__INCLUDED_)
#define AFX_FSARCHIVEREBUILDER_H__12229CAE_4DBE_4E89_875D_4378C0C6E8FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsArchiveRebuilderStream.h"

namespace fsArchive
{

enum fsArchiveRebuilderResult
{
	ARR_BADARCHIVE	= 100,	
	ARR_STREAMERROR	= 101,	
	
	
	
	ARR_APPRES	= 500,
};

struct fsArchiveFilePosition
{
	
	DWORD dwSrcBegin;	
	
	
	DWORD dwDstBegin;
	DWORD dwSrcEnd;	
	DWORD dwDstEnd;
};

class fsArchiveRebuilder  
{
public:
	
	void SetFileSize (DWORD dw);
	
	void SetSFXSize (DWORD dw);
	
	UINT64 GetResultingArchiveSize();
	
	virtual DWORD OpenArchive (fsArchiveStream* in);
	
	virtual int GetFileCount () = NULL;
	
	virtual fsString GetFileName (int iFile) = NULL;
	
	virtual BOOL RebuildArchive (fs::list <fsString> vFileNames) = NULL;
	
	virtual const fsArchiveFilePosition* GetFilePosition (int iFile) = NULL;
	
	DWORD SaveArchiveHeaders (fsArchiveStream *out);
	
	fsArchiveRebuilder();
	virtual ~fsArchiveRebuilder();

protected:
	
	virtual DWORD RetreiveArchiveContent() = NULL;
	
	virtual DWORD SaveArchiveHeaders_imp () = NULL;
	fsArchiveStream* m_out;	
	fsArchiveStream* m_in;	
	UINT64 m_uResArchiveSize;	
	BOOL m_dwSFXSize;	
	DWORD m_dwFileSize;	
};

};	

#endif 
