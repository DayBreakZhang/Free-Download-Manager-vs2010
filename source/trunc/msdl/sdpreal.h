/***********************************************************************
 *    sdpreal.c: interpret real protocol sdp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is mainly(totally) based on sdp.c in xine-lib,
 * and includes code from xine.
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


#ifndef __SDPREAL_H__
#define __SDPREAL_H__


struct sdpreal_stream_t {

    char *id;
    char *bandwidth;

    int stream_id;
  
    int duration;
    int preroll;
    int start_time;

    int max_bit_rate;
    int avg_bit_rate;
    int max_packet_size;
    int avg_packet_size;
  
    char *stream_name;
    int stream_name_size;
    char *mime_type;
    int mime_type_size;
    uint8_t *mlti_data;
    int mlti_data_size;
    char *asm_rule_book;
    int asm_rule_book_size;

};



struct sdpreal_t {
  
    char *title;
    char *author;
    char *copyright;
    char *keywords;
    char *abstract;
    int flags;
    int stream_count;
  

    struct list_h *streams; /* sdpreal_stream_t list */
  
};

struct sdpreal_t *sdpreal_parse(char *data);
void free_sdpreal_t(struct sdpreal_t *p);


#endif /* __SDPREAL_H__ */
