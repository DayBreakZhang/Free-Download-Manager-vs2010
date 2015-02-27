/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSARCHIVEREBUILDERSTREAM_H__D693D1B0_F3E1_435B_B52C_2F6057611340__INCLUDED_)
#define AFX_FSARCHIVEREBUILDERSTREAM_H__D693D1B0_F3E1_435B_B52C_2F6057611340__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

namespace fsArchive
{

#define ASE_NOMOREDATA	(1000)

enum fsSeekType
{
	ST_BEGIN,
	ST_CURRENT,
	ST_END,
};

class fsArchiveStream  
{
public:
	virtual BOOL Seek (UINT64 uDistance, fsSeekType enType) = NULL;
	
	virtual int Write (LPVOID pBuffer, int cBytes) = NULL;
	
	virtual int Read (LPVOID pBuffer, int cBytes) = NULL;
	DWORD GetLastError () {return m_dwLastError;}
	fsArchiveStream();
	virtual ~fsArchiveStream();

protected:
	DWORD m_dwLastError;
};

}; 

#endif 
