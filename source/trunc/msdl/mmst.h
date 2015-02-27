/***********************************************************************
 *    mmst.h:  downloading via mmst (Microsoft Media Service over TCP)
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on mms implementation of mplayer,
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


#ifndef __MMST_H__
#define __MMST_H__


enum {
    HDR_BUF_SIZE = 8192, /* 8Kb */
};

/*
 * mmst protocol specific datas.
 */
struct mmst_ctrl_t {
    int seq_num;
    int num_stream_ids;
 
    struct asf_headerinfo_t *hinfo;
};

struct stream_t *mmst_streaming_init();

int mmst_streaming_start(struct stream_t *stream);
int mmst_streaming_read(struct stream_t *stream, uint8_t *buffer,
			size_t buffer_size);
void mmst_streaming_close(struct stream_t *stream);


#endif /* __MMST_STREAM_H__ */
