/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBtDownloadPeerInfoListImpl.h"
#include "vmsBtDownloadImpl.h"

vmsBtDownloadPeerInfoListImpl::vmsBtDownloadPeerInfoListImpl(void)
{
}

vmsBtDownloadPeerInfoListImpl::~vmsBtDownloadPeerInfoListImpl(void)
{
}

int vmsBtDownloadPeerInfoListImpl::get_PeerCount ()
{
	return (int)m_vPeers.size ();
}

vmsBtDownloadPeerInfo* vmsBtDownloadPeerInfoListImpl::get_Peer (int nIndex)
{
	return &m_vPeers [nIndex];
}

bool vmsBtDownloadPeerInfoListImpl::UpdateList ()
{
	m_dld->check_handle_is_valid ();
	std::vector<libtorrent::peer_info> v;
	m_dld->GetHandle().get_peer_info (v);
	std::vector <vmsBtDownloadPeerInfoImpl> vPeers;

	for (size_t i = 0; i < v.size (); i++)
	{
		vmsBtDownloadPeerInfoImpl peer;
		libtorrent::peer_info *p = &v [i];
		
		
		peer.m_peer = *p;
		vPeers.push_back (peer);
	}

	bool bChanged = vPeers.size () != m_vPeers.size ();
	if (bChanged == false)
	{
		for (size_t i = 0; i < vPeers.size (); i++)
		{
			if (vPeers [i].m_peer.ip != m_vPeers [i].m_peer.ip)
			{
				bChanged = true;
				break;
			}
		}
	}

	m_vPeers = vPeers;
	return bChanged;
}