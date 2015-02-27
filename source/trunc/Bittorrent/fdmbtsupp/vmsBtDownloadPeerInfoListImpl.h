/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once
#include "vmsbtdownloadpeerinfolist.h"
#include "vmsBtDownloadPeerInfoImpl.h"

class vmsBtDownloadPeerInfoListImpl :
	public vmsBtDownloadPeerInfoList
{
public:
	bool UpdateList ();
	int get_PeerCount ();
	vmsBtDownloadPeerInfo* get_Peer (int nIndex);

	class vmsBtDownloadImpl* m_dld;

	vmsBtDownloadPeerInfoListImpl(void);
public:
	virtual ~vmsBtDownloadPeerInfoListImpl(void);

protected:
	std::vector <vmsBtDownloadPeerInfoImpl> m_vPeers;
};
