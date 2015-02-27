/***********************************************************************
 *   wmserver.c : for downloading from WMServer using rtsp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on information shown on wireshark,
 * analyzing transaction of Windows media player.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *
 ***********************************************************************/ 


#ifndef __WMSERVER_H__
#define __WMSERVER_H__




int wmserver_setup_and_get_header(struct stream_t *stream,
				  struct asf_headerinfo_t **asf_headerinfo_ret);
int wmserver_check_announce_continue(struct stream_t *stream);
int rtsp_wmserver_get_data(struct stream_t *stream,uint8_t *buffer,size_t size);
int wmserver_rtp_get_media_packet(struct stream_t *stream,
				  uint8_t *buffer,size_t max_size);

#endif /* __WMSERVER_H__ */
