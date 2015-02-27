/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "vmsBtFileImpl.h"
#include "common.h"
#include <fstream>
#include <boost/filesystem/operations.hpp>
using namespace boost::filesystem;
#include <libtorrent/file_pool.hpp>
#include <libtorrent/storage.hpp>
#include <libtorrent/hasher.hpp>
#include "libtorrent/utf8.hpp"
#include <atlbase.h>

vmsBtFile* WINAPI vmsBt_CreateTorrentFileObject ()
{
	vmsBtFileImpl *p = new vmsBtFileImpl;
	p->AddRef ();
	return p;
}

vmsBtFileImpl::vmsBtFileImpl()
	: m_isMagnet(FALSE)
	, m_torrent(NULL)
	, m_pCreate_torrent(NULL)
	, m_cRefs(0)
{
}

vmsBtFileImpl::~vmsBtFileImpl()
{
	if (m_torrent)
		delete m_torrent;
	if (m_pCreate_torrent)
		delete m_pCreate_torrent;
}

BOOL vmsBtFileImpl::IsMagnetLink()
{
	return m_isMagnet;
}

BOOL vmsBtFileImpl::LoadFromFile (LPCSTR pszTorrentFile)
{
	SAFE_DELETE (m_torrent);

	HANDLE hFile = CreateFileA (pszTorrentFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
		return FALSE;

	DWORD dwSize = GetFileSize (hFile, NULL);

	LPBYTE pbTorrent = new BYTE [dwSize];
	
	BOOL b = ReadFile (hFile, pbTorrent, dwSize, &dwSize, NULL);

	CloseHandle (hFile);

	if (b)
		b = LoadFromBuffer (pbTorrent, dwSize);

	delete [] pbTorrent;

	return b;
}

BOOL vmsBtFileImpl::LoadFromBuffer (LPBYTE pbTorrent, DWORD dwTorrentSize)
{
	SAFE_DELETE (m_torrent);

	try {
		m_torrent = new libtorrent::torrent_info (
			libtorrent::bdecode (pbTorrent, pbTorrent + dwTorrentSize));
	}
	catch (...) {
		return FALSE;
	}

	return TRUE;
}

BOOL vmsBtFileImpl::LoadFromMagnetLink (LPCSTR pszMagnetLink)
{
	
	m_magnetLink = pszMagnetLink;

	libtorrent::sha1_hash hash;
	std::vector<std::string> trackers;

	boost::system::error_code ec;
	boost::optional<std::string> display_name = libtorrent::url_has_argument(m_magnetLink, "dn");
	if (display_name) 
		m_strMagnetDisplayName = libtorrent::unescape_string(display_name->c_str(), ec);
	else
		m_strMagnetDisplayName.clear ();

	std::string temp = m_magnetLink;
	boost::optional<std::string> tracker_string = libtorrent::url_has_argument(m_magnetLink, "tr");
	while (tracker_string.is_initialized())
	{
		trackers.push_back(libtorrent::unescape_string(tracker_string->c_str(), ec));

		int start = temp.find("tr");
		int end = temp.find("tr", start);

		if (start == -1 || end == -1)
		{
			break;
		}
		temp.erase(start, end);
		tracker_string = libtorrent::url_has_argument(temp, "tr");
	}

	boost::optional<std::string> btih = libtorrent::url_has_argument(m_magnetLink, "xt");
	if (!btih) 
	{
		return FALSE;
	}
	if (btih->compare(0, 9, "urn:btih:") != 0)
	{
		return FALSE;
	}

	if (btih->size() == 40 + 9) 
	{
		libtorrent::from_hex(&(*btih)[9], 40, (char*)&hash[0]);
	}
	else 
	{
		hash.assign(libtorrent::base32decode(btih->substr(9)));
	}

	libtorrent::torrent_info newTorrentInfo = libtorrent::torrent_info(hash);
	for (std::vector<std::string>::iterator iter = trackers.begin(); iter != trackers.end(); ++iter)
	{
		newTorrentInfo.add_tracker(*iter);
	}

	m_torrent = new libtorrent::torrent_info(newTorrentInfo);

	m_isMagnet = TRUE;
	return TRUE;
}

BOOL vmsBtFileImpl::LoadFromMagnetMetadata (vmsBtFile* torrentFile)
{
	if (torrentFile == NULL || torrentFile->IsMagnetLink() == FALSE)
	{
		return FALSE;
	}
	vmsBtFileImpl* impl = static_cast<vmsBtFileImpl*>(torrentFile);
	if (impl->m_torrent == NULL || impl->m_torrent->is_valid() == false)
	{
		return FALSE;
	}
	m_torrent = new libtorrent::torrent_info(*impl->m_torrent);
	m_magnetLink = torrentFile->GetMagnetLink();
	m_isMagnet = TRUE;

	return TRUE;
}

LPCSTR vmsBtFileImpl::GetMagnetLink()
{
	return m_magnetLink.c_str();
}

void vmsBtFileImpl::Release ()
{
	if (InterlockedDecrement (&m_cRefs) == 0)
		delete this;
}

void vmsBtFileImpl::AddRef ()
{
	InterlockedIncrement (&m_cRefs);
}

int vmsBtFileImpl::get_FileCount ()
{
	return m_torrent->num_files ();
}

void vmsBtFileImpl::get_FileName (int nIndex, LPSTR pszRes)
{
	strcpy (pszRes, m_torrent->file_at (nIndex).path.string ().c_str ());
}

UINT64 vmsBtFileImpl::get_FileSize (int nIndex)
{
	return m_torrent->file_at (nIndex).size;
}

UINT64 vmsBtFileImpl::get_TotalFilesSize ()
{
	return m_torrent->total_size ();
}

void vmsBtFileImpl::get_TorrentName (LPSTR pszRes)
{
	if (!m_torrent->name ().empty ())
		strcpy (pszRes, m_torrent->name ().c_str ());
	else
		strcpy (pszRes, m_strMagnetDisplayName.c_str ());
}

BOOL vmsBtFileImpl::get_TorrentBuffer (LPBYTE pbRes, DWORD dwSize, DWORD *pdwTorrentSize)
{
	std::vector <char> v;

	if (m_torrent) 
	{
		libtorrent::create_torrent t(*m_torrent);
		libtorrent::bencode(std::back_inserter (v), t.generate());
	}
	else if (m_pCreate_torrent)
	{
		libtorrent::bencode(std::back_inserter (v), m_pCreate_torrent->generate());
	}
	else return FALSE;

	*pdwTorrentSize = v.size ();

	if (pbRes == NULL)
		return TRUE;

	if (dwSize < v.size ())
		return FALSE;

	for (size_t i = 0; i < v.size (); i++)
		*pbRes++ = v [i];

	return TRUE;
}

void vmsBtFileImpl::get_InfoHash (LPSTR pszRes)
{
	const libtorrent::sha1_hash& hash = m_torrent->info_hash ();
	for (size_t i = 0; i < hash.size; i++)
	{
		sprintf (pszRes, "%02x", (int)hash [i]);
		pszRes += strlen (pszRes);
	}
}

BOOL vmsBtFileImpl::getInfoHash2 (LPBYTE pb, LPDWORD pdwBufSize)
{
	if (!pdwBufSize)
		return FALSE;

	const libtorrent::sha1_hash& hash = m_torrent->info_hash ();
	if (!pb)
	{
		*pdwBufSize = hash.size;
		return TRUE;
	}

	if (*pdwBufSize < hash.size)
	{
		*pdwBufSize = hash.size;
		return FALSE;
	}

	*pdwBufSize = hash.size;
	for (size_t i = 0; i < hash.size; i++)
		*pb++ = hash [i];

	return TRUE;
}

void vmsBtFileImpl::get_TrackerUrl (LPSTR pszRes, int nIndex)
{
	const std::vector <libtorrent::announce_entry> &v = m_torrent->trackers ();
	strcpy (pszRes, size_t(nIndex) < v.size () ? v [nIndex].url.c_str () : "");
}

int vmsBtFileImpl::get_TrackerCount ()
{
	return m_torrent->trackers ().size ();
}

void vmsBtFileImpl::get_TorrentComment(LPSTR pszRes)
{
	strcpy (pszRes, m_torrent->comment ().c_str ());
}

int vmsBtFileImpl::get_PieceCount ()
{
	return m_torrent->num_pieces ();
}

int vmsBtFileImpl::get_PieceSize ()
{
	return (int)m_torrent->piece_size (0);
}

void add_files (libtorrent::file_storage& fs, wpath const& p, wpath const& l, LPBOOL pbNeedCancel)
{
	if (l.leaf ()[0] == '.') 
		return;

	wpath f(p / l);

	if (is_directory (f))
	{
		typedef basic_directory_iterator<wpath> directory_iterator;
		for (directory_iterator i (f), end; i != end; ++i)
		{
			add_files (fs, p, l / i->leaf (), pbNeedCancel);
			if (pbNeedCancel && *pbNeedCancel)
				return;
		}
	}
	else
	{
		fs.add_file(l, file_size (f));
	}
}

UINT64 get_files_size (wpath const& p, wpath const& l, LPBOOL pbNeedCancel)
{
	if (l.leaf ()[0] == '.') 
		return 0;

	wpath f(p / l);

	UINT64 s = 0;

	if (is_directory (f))
	{
		typedef basic_directory_iterator<wpath> directory_iterator;
		for (directory_iterator i (f), end; i != end; ++i)
		{
			s += get_files_size (p, l / i->leaf (), pbNeedCancel);
			if (pbNeedCancel && *pbNeedCancel)
				return 0;
		}
	}
	else
	{
		s += file_size (f);
	}

	return s;
}

BOOL vmsBtFileImpl::CreateNewTorrent (LPCSTR pszSrcPath, LPCSTR pszTrackers, LPCSTR pszUrlSeeds, 
	LPCSTR pszCreator, LPCSTR pszComment, int iPieceSize, int *pnCreateProgress, BOOL *pbNeedCancel)
{
	USES_CONVERSION;
	return CreateNewTorrent2 (A2CW (pszSrcPath), pszTrackers, pszUrlSeeds, pszCreator, pszComment, iPieceSize, pnCreateProgress, pbNeedCancel);
}

BOOL vmsBtFileImpl::GenerateFastResumeDataForSeed (LPCSTR pszSrcFolderOrFile, LPBYTE pbData, DWORD dwSize, LPDWORD pdwSize)
{
	libtorrent::entry ret (libtorrent::entry::dictionary_t);

	ret ["file-format"] = "libtorrent resume file";
	ret ["file-version"] = 1;

	ret ["allocation"] = "full";

	ret ["info-hash"] = std::string ((char*)m_torrent->info_hash ().begin(), (char*)m_torrent->info_hash ().end());

	int block_size = 1024; 
	if (m_torrent->piece_length () < block_size)
		block_size = (int)m_torrent->piece_length ();
	int num_blocks_per_piece =
		static_cast<int>(m_torrent->piece_length ()) / block_size;

	ret ["blocks per piece"] = num_blocks_per_piece;

	std::vector<int> piece_index;
	piece_index.reserve (m_torrent->num_pieces ());
	for (int i = 0; i < m_torrent->num_pieces(); ++i)
		piece_index.push_back (i);
	libtorrent::entry::list_type& slots = ret ["slots"].list ();
	std::copy (piece_index.begin (), piece_index.end (), std::back_inserter (slots));

	std::vector<std::pair<libtorrent::size_type, std::time_t> > file_sizes = 
		libtorrent::get_filesizes (const_cast<libtorrent::file_storage&>(m_torrent->files()), libtorrent::fs::complete (pszSrcFolderOrFile));

	ret ["file sizes"] = libtorrent::entry::list_type ();
	libtorrent::entry::list_type& fl = ret ["file sizes"].list ();
	for (std::vector<std::pair<libtorrent::size_type, std::time_t> >::iterator i
			= file_sizes.begin (), end (file_sizes.end ()); i != end; ++i)
	{
		libtorrent::entry::list_type p;
		p.push_back (libtorrent::entry(i->first));
		p.push_back (libtorrent::entry(i->second));
		fl.push_back (libtorrent::entry(p));
	}

	

	std::vector <char> v;
	libtorrent::bencode (std::back_inserter (v), ret);

	*pdwSize = v.size ();

	if (pbData == NULL)
		return TRUE;

	if (dwSize < v.size ())
		return FALSE;

	if (!v.empty ())
		CopyMemory (pbData, &v[0], v.size ());

	return TRUE;
}

void vmsBtFileImpl::get_FileName2 (int nIndex, LPSTR pszRes, DWORD dwBuffSize)
{
	if (m_torrent == NULL || nIndex >= m_torrent->num_files())
	{
		return;
	}
	strncpy (pszRes, m_torrent->file_at (nIndex).path.string ().c_str (), dwBuffSize - 1);
	pszRes [dwBuffSize - 1] = 0;
}

void vmsBtFileImpl::get_TorrentName2 (LPSTR pszRes, DWORD dwBuffSize)
{
	if (!m_torrent->name ().empty ())
		strncpy (pszRes, m_torrent->name ().c_str (), dwBuffSize - 1);
	else
		strncpy (pszRes, m_strMagnetDisplayName.c_str (), dwBuffSize - 1);
	pszRes [dwBuffSize - 1] = 0;
}

void vmsBtFileImpl::get_TrackerUrl2 (LPSTR pszRes, int nIndex, DWORD dwBuffSize)
{
	const std::vector <libtorrent::announce_entry> &v = m_torrent->trackers ();
	strncpy (pszRes, size_t(nIndex) < v.size () ? v [nIndex].url.c_str () : "", dwBuffSize - 1);
	pszRes [dwBuffSize - 1] = 0;
}

void vmsBtFileImpl::get_TorrentComment2 (LPSTR pszRes, DWORD dwBuffSize)
{
	strncpy (pszRes, m_torrent->comment ().c_str (), dwBuffSize - 1);
	pszRes [dwBuffSize - 1] = 0;
}

BOOL vmsBtFileImpl::CreateNewTorrent2 (LPCWSTR pszSrcPath, LPCSTR pszTrackers, LPCSTR pszUrlSeeds, 
	LPCSTR pszCreator, LPCSTR pszComment, int iPieceSize, int *pnCreateProgress, BOOL *pbNeedCancel)
{
	if (pnCreateProgress)
		*pnCreateProgress = 0;

	try
	{
		wpath full_path = complete (wpath (pszSrcPath));

		if (iPieceSize == 0)
		{
			UINT64 uTotalSize = get_files_size (full_path.branch_path (), full_path.leaf (), pbNeedCancel);

			if (uTotalSize > 2 * 1024*1024*1024ui64)
				iPieceSize = 4*1024*1024;
			else if (uTotalSize > 1 * 1024*1024*1024ui64)
				iPieceSize = 2*1024*1024;
			else if (uTotalSize > 500*1024*1024ui64)
				iPieceSize = 1024*1024;
			else if (uTotalSize > 200*1024*1024ui64)
				iPieceSize = 512*1024;
			else
				iPieceSize = 256*1024;
		}

		libtorrent::file_storage fs;
		add_files (fs, full_path.branch_path (), full_path.leaf (), pbNeedCancel);

		SAFE_DELETE (m_pCreate_torrent);
		m_pCreate_torrent = new libtorrent::create_torrent(fs, iPieceSize);

		while (*pszTrackers)
		{
			m_pCreate_torrent->add_tracker(pszTrackers);
			pszTrackers += strlen (pszTrackers) + 1;
			if (*pszTrackers && FALSE == IsCharAlphaA (*pszTrackers))
				return FALSE; 
		}

		
		

		std::string strPath;
		libtorrent::wchar_utf8(full_path.branch_path().string(), strPath);
		libtorrent::file_pool fp;
		boost::scoped_ptr<libtorrent::storage_interface> st(
			default_storage_constructor (fs, 0, strPath, fp));

		int num = m_pCreate_torrent->num_pieces ();
		std::vector <char> buf (iPieceSize);
		for (int i = 0; i < num; ++i)
		{
			st->read (&buf [0], i, 0, (int)m_pCreate_torrent->piece_size (i));
			libtorrent::hasher h (&buf [0], (int)m_pCreate_torrent->piece_size (i));
			m_pCreate_torrent->set_hash (i, h.final ());
			if (pnCreateProgress)
				*pnCreateProgress = MulDiv (i+1, 100, num);
			if (pbNeedCancel && *pbNeedCancel)
				return FALSE;
		}

		

		if (pszCreator)
			m_pCreate_torrent->set_creator(pszCreator);

		if (pszComment)
			m_pCreate_torrent->set_comment (pszComment);

		if (pszUrlSeeds)
		{
			while (*pszUrlSeeds)
			{
				m_pCreate_torrent->add_url_seed (pszUrlSeeds);
				pszUrlSeeds += strlen (pszUrlSeeds) + 1;
				if (!IsCharAlphaA (*pszUrlSeeds))
					return FALSE; 
			}
		}

		
		
		
		LPBYTE pb; DWORD dw; 
		if (FALSE == get_TorrentBuffer (NULL, 0, &dw))
		{
			SAFE_DELETE (m_pCreate_torrent);
			return FALSE;
		}
		if (dw) {
			pb = new BYTE [dw];		
			get_TorrentBuffer (pb, dw, &dw);
			BOOL b = LoadFromBuffer (pb, dw);
			delete [] pb;
			return b;
		}
	}
	catch (std::exception&)
	{
		SAFE_DELETE (m_pCreate_torrent);
		return FALSE;
	}

	return TRUE;
}

BOOL vmsBtFileImpl::IsValid()
{
	return m_torrent != NULL ? m_torrent->is_valid() : FALSE;
}
