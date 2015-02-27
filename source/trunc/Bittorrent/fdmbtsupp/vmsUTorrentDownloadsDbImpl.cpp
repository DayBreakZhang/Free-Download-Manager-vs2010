/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsUTorrentDownloadsDbImpl.h"
#include "uTorrentParser.h"
#include <atlbase.h>

vmsUTorrentDownloadsDb* WINAPI vms_CreateUTorrentDownloadsDbObject ()
{
	vmsUTorrentDownloadsDbImpl *p = new vmsUTorrentDownloadsDbImpl;
	p->AddRef ();
	return p;
}

vmsUTorrentDownloadsDbImpl::vmsUTorrentDownloadsDbImpl(void)
{
	m_cRefs = 0;
}

vmsUTorrentDownloadsDbImpl::~vmsUTorrentDownloadsDbImpl(void)
{
}

BOOL vmsUTorrentDownloadsDbImpl::ImportUtorrentDownloads (LPCSTR pszDownloadsDbFile)
{
	m_vDownloads.clear ();

	HANDLE hFile = CreateFileA (pszDownloadsDbFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dwSize = GetFileSize (hFile, NULL);

	LPBYTE pbTorrent = new BYTE [dwSize];
	
	BOOL b = ReadFile (hFile, pbTorrent, dwSize, &dwSize, NULL);

	CloseHandle (hFile);

	if (b) {
		
		try {
			
			libtorrent::uTorrentParser * uTorrent = 0;
			uTorrent = new libtorrent::uTorrentParser (
			libtorrent::bdecode (pbTorrent, pbTorrent + dwSize));
			std::vector<std::pair<std::string, std::string>> uTorrentsDownloads = uTorrent->get_mTorrents();
			for (size_t i = 0; i < uTorrentsDownloads.size (); i++)
			{
				vmsUTorrentDownloadsDb::Download dl;
				dl.strTorrentFileName = uTorrentsDownloads [i].first;
				int iRL = MultiByteToWideChar (CP_UTF8, 0, uTorrentsDownloads [i].second.c_str(), -1, NULL, 0);
				wchar_t *pwsz = new wchar_t [++iRL]; *pwsz = 0;
				MultiByteToWideChar (CP_UTF8, 0, uTorrentsDownloads [i].second.c_str(), -1, pwsz, iRL);
				USES_CONVERSION;
				dl.strOutputPath = W2A (pwsz);
				delete [] pwsz;
				m_vDownloads.push_back (dl);
			}
			if (uTorrent) delete uTorrent;
			b = TRUE;
		}
		catch (...) {
			b = FALSE;
		}
	}

	delete [] pbTorrent;

	return b;
}
