/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma once

#define BTPI_INTERESTING			0x1

#define BTPI_CHOKED					0x2

#define BTPI_REMOTE_INTERSTED		0x4

#define BTPI_REMOTE_CHOCKED			0x8

#define BTPI_SUPPORTS_EXTENSIONS	0x10

#define BTPI_LOCAL_CONNECTION		0x20

#define BTPI_HANDSHAKE				0x40

#define BTPI_CONNECTING				0x80

#define BTPI_QUEUED					0x100

#define BTPI_ON_PAROLE				0x200

#define BTPI_SEED					0x400

#define BTPI_OPTIMISTIC_UNCHOKE		0x800
#define BTPI_RC4_ENCRYPTED			0x100000
#define BTPI_PLAINTEXT_ENCRYPTED	0x200000

class vmsBtDownloadPeerInfo
{
public:
	virtual void get_Ip (LPSTR psz) = NULL;
	virtual void get_Client (LPSTR psz) = NULL;
	virtual int get_DownloadSpeed () = NULL;
	virtual int get_UploadSpeed () = NULL;
	virtual UINT64 get_BytesDownloaded () = NULL;
	virtual UINT64 get_BytesUploaded () = NULL;
	virtual UINT get_Flags () = NULL;
};
