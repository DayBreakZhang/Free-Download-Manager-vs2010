/***********************************************************************
 *    real.h : for downloading from real server using rtsp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on rtsp (real) implementation of 
 * mplayer and xine, and includes code from both projects.
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


#ifndef __REAL_H__
#define __REAL_H__

int real_get_last_npt_of_file(char *local_filename,uint32_t *send_time,uint64_t *seek_offset);

int real_setup_and_get_header(struct stream_t *stream,
			      struct rmff_header_t **rmff_header_ret);
int real_rdt_get_media_packet(struct stream_t *stream,
			      uint8_t *buffer,size_t max_size);
int real_rtsp_options(struct stream_t *stream,struct rtsp_header_t **rtsp_hdr_ret);

#endif /* __REAL_H__ */
