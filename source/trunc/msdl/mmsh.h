/***********************************************************************
 *    mmsh.h:  downloading via mmsh (Microsoft Media Service over HTTP)
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on mmsh implementation of mplayer,
 * and Windows Media Player transaction I saw through
 * packet monitoring program, wireshark (http://www.wireshark.org/)
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


#ifndef __MMSH_H__
#define __MMSH_H__


/*
 * structure to control media stream.
 */
struct mmsh_ctrl_t {
    int streaming_type;       /* type of asf streaming */
    int packet_size;
    
    int keepalive_sock;       /* mmsh requires socket only for KeepAlive!! */
    
    uint32_t client_id;       /* it is integer between 0 and 4,294,967,295 (0xffffffff) */
    uint32_t playlist_id;     /* it is integer between 0 and 4,294,967,295 (0xffffffff) */

    uint32_t resume_start_ts; /* for mmsh resume */
  
    struct asf_headerinfo_t *hinfo;
};

struct stream_t *mmsh_streaming_init();

int mmsh_streaming_start(struct stream_t *stream);

int mmsh_streaming_read(struct stream_t *stream,
			uint8_t *buffer, size_t buffer_size);
void mmsh_streaming_close(struct stream_t *stream);
int mmsh_prepare_resuming(struct stream_t *stream);

#endif /* __MMSH_H__ */
