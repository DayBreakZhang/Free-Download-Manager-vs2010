/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/



#ifndef TORRENT_uTorrentParser_HPP_INCLUDED
#define TORRENT_uTorrentParser_HPP_INCLUDED

#include <string>
#include <vector>


#ifdef _MSC_VER
#pragma warning(push, 1)
#endif

#include <boost/optional.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/shared_array.hpp>

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "libtorrent/entry.hpp"
#include "libtorrent/lazy_entry.hpp"
#include "libtorrent/socket.hpp"
#include "libtorrent/peer_id.hpp"
#include "libtorrent/size_type.hpp"
#include "libtorrent/config.hpp"
#include "libtorrent/time.hpp"
#include "libtorrent/intrusive_ptr_base.hpp"
#include "libtorrent/assert.hpp"
#include "libtorrent/file_storage.hpp"
#include "libtorrent/torrent_info.hpp"

namespace libtorrent
{

	class TORRENT_EXPORT uTorrentParser : public torrent_info
	{
	public:

#ifndef TORRENT_NO_DEPRECATE


		TORRENT_DEPRECATED_PREFIX
		uTorrentParser(entry const& torrent_file) TORRENT_DEPRECATED;
		TORRENT_DEPRECATED_PREFIX

#endif

		std::vector<std::pair<std::string, std::string>> get_mTorrents() { return mTorrents;}

	private:
		bool parse_torrent_file(lazy_entry const& libtorrent, error_code& ec);

		sha1_hash m_info_hash;
		std::vector<std::pair<std::string, std::string>> mTorrents;

	};
}

#endif 

