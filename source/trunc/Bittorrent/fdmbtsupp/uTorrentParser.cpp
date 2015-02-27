/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "stdafx.h"
#include "libtorrent/pch.hpp"

#include <ctime>

#if !defined TORRENT_NO_DEPRECATE && TORRENT_USE_IOSTREAM
#include <iostream>
#include <iomanip>
#endif

#include <iterator>
#include <algorithm>
#include <set>

#ifdef _MSC_VER
#pragma warning(push, 1)
#endif

#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <boost/bind.hpp>

#ifdef _MSC_VER
#pragma warning(pop)
#endif

#include "libtorrent/config.hpp"
#include "../libtorrent/src/torrent_info.cpp"
#include "uTorrentParser.h"
#include "libtorrent/bencode.hpp"
#include "libtorrent/hasher.hpp"
#include "libtorrent/entry.hpp"
#include "libtorrent/file.hpp"
#include "libtorrent/utf8.hpp"

namespace gr = boost::gregorian;

namespace libtorrent
{

#ifndef TORRENT_NO_DEPRECATE
	
	uTorrentParser::uTorrentParser(entry const& torrent_file)
		: torrent_info(m_info_hash)
	{
		std::vector<char> tmp;
		std::back_insert_iterator<std::vector<char> > out(tmp);
		bencode(out, torrent_file);

		lazy_entry e;
		if (tmp.size() == 0 || lazy_bdecode(&tmp[0], &tmp[0] + tmp.size(), e) != 0)
		{
#ifndef BOOST_NO_EXCEPTIONS
			throw invalid_torrent_file(errors::invalid_bencoding);
#endif
			return;
		}
		error_code ec;
#ifndef BOOST_NO_EXCEPTIONS
		if (!parse_torrent_file(e, ec))
			throw invalid_torrent_file(ec);
#else
		parse_torrent_file(e, ec);
#endif
	}
#endif

	bool uTorrentParser::parse_torrent_file(lazy_entry const& torrent_file, error_code& ec)
	{
		if (torrent_file.type() != lazy_entry::dict_t)
		{
			ec = errors::torrent_is_no_dict;
			return false;
		}

		mTorrents.clear();
		
		
		for (int i = 0, end(torrent_file.dict_size()); i < end; ++i)
		{
			std::pair<std::string, lazy_entry const*> n = torrent_file.dict_at(i);
			if (lazy_entry::dict_t == n.second->type())
			{
				std::pair<std::string, std::string> torrent;
				torrent.first = n.first;
				torrent.second = n.second->dict_find_string_value("path");
				std::string caption = n.second->dict_find_string_value("caption");
				if (caption.length() > 0) {
					size_t pos = torrent.second.find(caption.c_str(), 0, caption.length());
					torrent.second = torrent.second.substr(0, pos);
				}
				mTorrents.push_back(torrent);
			}			
		}

		return true;
	}
}