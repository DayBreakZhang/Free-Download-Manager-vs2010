/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsUTorrentDownloadsDb.h"
#include "vmsFdmBtObjectImpl.h"

class vmsUTorrentDownloadsDbImpl :
	public vmsFdmBtObjectImpl <vmsUTorrentDownloadsDb>
{
public:
	virtual BOOL ImportUtorrentDownloads (LPCSTR pszTorrentFile);
	virtual int getDownloadCount ()
	{
		return m_vDownloads.size ();
	}
	virtual const Download* getDownload (int nIndex)
	{
		assert (nIndex >= 0 && nIndex < m_vDownloads.size ());
		return &m_vDownloads [nIndex];
	}

	vmsUTorrentDownloadsDbImpl(void);
	virtual ~vmsUTorrentDownloadsDbImpl(void);

protected:
	std::vector <vmsUTorrentDownloadsDb::Download> m_vDownloads;
};