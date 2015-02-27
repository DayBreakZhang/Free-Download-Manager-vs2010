/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#if !defined(AFX_FSARCHIVEINTERNETSTREAM_H__946F6956_97AD_4C5B_9AC9_0BFB1A26F480__INCLUDED_)
#define AFX_FSARCHIVEINTERNETSTREAM_H__946F6956_97AD_4C5B_9AC9_0BFB1A26F480__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif 

#include "fsArchiveRebuilderStream.h"

class fsArchiveInternetStream : public fsArchive::fsArchiveStream  
{
public:
	
	void Set_MaxRetriesCount (UINT cMax);
	fsInternetResult GetLastNetworkErr();
	
	void Stop();
	
	void Close();
	
	BOOL Seek (UINT64 uDistance, fsArchive::fsSeekType enType);
	
	int Write(LPVOID pBuffer, int cBytes);
	
	int Read (LPVOID pBuffer, int cBytes);
	
	fsInternetResult Open (class fsInternetDownloader* dldr, UINT64 uStartPos = 0);
	
	fsArchiveInternetStream();
	virtual ~fsArchiveInternetStream();

protected:
	UINT m_cMaxRetries;
	fsInternetResult m_irLastErr;
	BOOL m_bOpened;
	
	fsInternetResult Open_imp (UINT64 uStartPos);
	UINT64 m_uCurPos;	
	class fsInternetDownloader* m_dldr;
	BOOL m_bNeedStop;	
	fsInternetURLFile m_file;	
};

#endif 
