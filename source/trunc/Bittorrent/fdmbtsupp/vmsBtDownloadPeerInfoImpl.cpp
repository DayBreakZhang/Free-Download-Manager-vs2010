/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBtDownloadPeerInfoImpl.h"

vmsBtDownloadPeerInfoImpl::vmsBtDownloadPeerInfoImpl(void)
{
}

vmsBtDownloadPeerInfoImpl::~vmsBtDownloadPeerInfoImpl(void)
{
}

void vmsBtDownloadPeerInfoImpl::get_Ip (LPSTR psz)
{
	strcpy (psz, m_peer.ip.address ().to_string ().c_str ());
}

void vmsBtDownloadPeerInfoImpl::get_Client (LPSTR psz)
{
	strcpy (psz, m_peer.client.c_str ());
}

int vmsBtDownloadPeerInfoImpl::get_DownloadSpeed ()
{
	return (int)m_peer.payload_down_speed;
}

int vmsBtDownloadPeerInfoImpl::get_UploadSpeed ()
{
	return (int)m_peer.payload_up_speed;
}

UINT64 vmsBtDownloadPeerInfoImpl::get_BytesDownloaded ()
{
	return m_peer.total_download;
}

UINT64 vmsBtDownloadPeerInfoImpl::get_BytesUploaded ()
{
	return m_peer.total_upload;
}

UINT vmsBtDownloadPeerInfoImpl::get_Flags ()
{
	return m_peer.flags;
}