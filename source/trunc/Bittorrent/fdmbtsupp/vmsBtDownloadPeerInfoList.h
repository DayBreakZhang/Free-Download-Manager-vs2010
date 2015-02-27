/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#include "vmsBtDownloadPeerInfo.h"

class vmsBtDownloadPeerInfoList
{
public:
	virtual int get_PeerCount () = NULL;
	virtual vmsBtDownloadPeerInfo* get_Peer (int nIndex) = NULL;
	
	virtual bool UpdateList () = NULL;
};
