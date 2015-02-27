/***********************************************************************
 *    sdpwms.h: interpret wms protocol sdp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * WMS sdp specific operations.
 * based on Windows Media Player transaction.
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


#ifndef __SDPWMS_H__
#define __SDPWMS_H__


struct sdpwms_stream_t {

  char *id;
  int streamnum;
  char *control;

};



struct sdpwms_t {
  
  int asf_header_len;
  uint8_t *asf_header;
  
  struct list_h *streams; /* sdpwms_stream_t list */
  
};



struct sdpwms_t *new_sdpwms_t(void);
void free_sdpwms_t(struct sdpwms_t *p);
struct sdpwms_t *wmserver_parse_sdp(char *data);


#endif /* __SDPWMS_H__ */

