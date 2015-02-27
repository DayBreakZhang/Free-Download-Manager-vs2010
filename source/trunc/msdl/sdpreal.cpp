/***********************************************************************
 *    sdpreal.c: interpret real protocol sdp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is mainly based on sdp.c in xine-lib,
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



/*
 * Copyright notice of MPlayer project
 * which some part of msdl is based on.
 * (from xine-lib-1.1.14/src/input/libreal/sdpplin.c)
 */

/*
 * Copyright (C) 2002-2003 the xine project
 *
 * This file is part of xine, a free video player.
 *
 * xine is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * xine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110, USA
 *
 * sdp/sdpplin parser.
 */


#include "stdafx.h"

#include "msdllib.h"
#include "sdpcommon.h"
#include "sdpreal.h"


static struct sdpreal_stream_t *new_sdpreal_stream_t(void);
static void free_sdpreal_stream_t(struct sdpreal_stream_t *p);




static struct sdpreal_t *new_sdpreal_t(void)
{
    struct sdpreal_t *p = (sdpreal_t *)xmalloc(sizeof(struct sdpreal_t));
    return p;
}



void free_sdpreal_t(struct sdpreal_t *p)
{
  
    if(p->title) free(p->title);
    if(p->author) free(p->author);
    if(p->copyright) free(p->copyright);
    if(p->keywords) free(p->keywords);
    if(p->abstract) free(p->abstract);
  
    free_list_h(p->streams,(void (*)(void *))free_sdpreal_stream_t);

    free(p);
}



static struct sdpreal_stream_t *new_sdpreal_stream_t(void)
{
    struct sdpreal_stream_t *p =
	(struct sdpreal_stream_t *)xmalloc(sizeof(struct sdpreal_stream_t));
    return p;
}



static void free_sdpreal_stream_t(struct sdpreal_stream_t *p)
{
  
    if(p->id) free(p->id);
    if(p->bandwidth) free(p->bandwidth);
    if(p->stream_name) free(p->stream_name);
    if(p->mime_type) free(p->mime_type);
    if(p->mlti_data) free(p->mlti_data);
    if(p->asm_rule_book) free(p->asm_rule_book);

    free(p);
}



struct sdpreal_stream_t *sdpreal_parse_stream(char **data)
{
    struct sdpreal_stream_t *stream;
    char *p = *data;
    char *buf = NULL;
    int buf_len = 0; /* don't touch it!! after here */
    char *decoded = NULL;
    int decoded_len = 0; /* don't touch it after here*/
  
    stream = new_sdpreal_stream_t();
  
    if(is_line(p,"m=",&buf,&buf_len)) {
	stream->id = strdup(buf);
	display(MSDL_VER,"stream: %s\n",stream->id);
	p = next_line(p);
    }
    else {
	display(MSDL_ERR,"no 'm=' line\n");
	free_sdpreal_stream_t(stream);
	return NULL;
    }
  
    for( ; p && *p && (p[0] != 'm'); ) {
    
	if(is_line(p,"a=control:streamid=",&buf,&buf_len)) {
	    stream->stream_id = atoi(buf);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=MaxBitRate:integer;",&buf,&buf_len)) {
	    stream->max_bit_rate = atoi(buf);
	    if(!stream->avg_bit_rate)
		stream->avg_bit_rate = stream->max_bit_rate;
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=MaxPacketSize:integer;",&buf,&buf_len)) {
	    stream->max_packet_size = atoi(buf);
	    if(!stream->avg_packet_size)
		stream->avg_packet_size = stream->max_packet_size;
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=StartTime:integer;",&buf,&buf_len)) {
	    stream->start_time = atoi(buf);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=Preroll:integer;",&buf,&buf_len)) {
	    stream->preroll = atoi(buf);
	    p = next_line(p);
	}

	else if(is_line(p,"a=length:npt=",&buf,&buf_len)) {
	    stream->duration = (uint32_t)(atof(buf)*1000);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=StreamName:string;",&buf,&buf_len)) {
	    stream->stream_name = strdup(buf);
	    stream->stream_name_size = strlen(stream->stream_name);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=mimetype:string;",&buf,&buf_len)) {
	    stream->mime_type = strdup(buf);
	    stream->mime_type_size = strlen(stream->mime_type);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=OpaqueData:buffer;",&buf,&buf_len)) {
	    keep_dec_size(&decoded,&decoded_len,strlen(buf));
	    stream->mlti_data_size = base64_decode(buf,decoded,decoded_len);
	    stream->mlti_data = (uint8_t *)xmalloc(stream->mlti_data_size);
	    memcpy(stream->mlti_data,decoded,stream->mlti_data_size);
	    p = next_line(p);
	    display(MSDL_DBG,"mlti data size: %i\n%s\n",
		    stream->mlti_data_size,stream->mlti_data);
	}
    
	else if(is_line(p,"a=ASMRuleBook:string;",&buf,&buf_len)) {
	    stream->asm_rule_book = strdup(buf);
	    p = next_line(p);
	}
    
	else {
	    p = next_line(p);
	}
    }
  
    free(buf);
    free(decoded);
  
    *data = p;

    return stream;
}



struct sdpreal_t *sdpreal_parse(char *data)
{
  
    struct sdpreal_t *desc;
    struct sdpreal_stream_t *stream;
    char *p; /* always points first char of line in 'data' */
    char *buf = NULL;
    int buf_len = 0; /* don't touch it after here !!*/
    char *decoded = NULL;
    int decoded_len = 0; /* don't touch it after here*/
  

    desc = new_sdpreal_t();
  
    for(p = data ; p && *p ; ) {
    
	if(is_line(p,"a=Title:buffer;",&buf,&buf_len)) {
	    keep_dec_size(&decoded,&decoded_len,strlen(buf));
	    base64_decode(buf,decoded,decoded_len);
	    desc->title = strdup(decoded);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=Author:buffer;",&buf,&buf_len)) {
	    keep_dec_size(&decoded,&decoded_len,strlen(buf));
	    base64_decode(buf,decoded,decoded_len);
	    desc->author = strdup(decoded);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=Copyright:buffer;",&buf,&buf_len)) {
	    keep_dec_size(&decoded,&decoded_len,strlen(buf));
	    base64_decode(buf,decoded,decoded_len);
	    desc->copyright = strdup(decoded);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=Abstract:buffer;",&buf,&buf_len)) {
	    keep_dec_size(&decoded,&decoded_len,strlen(buf));
	    base64_decode(buf,decoded,decoded_len);
	    desc->abstract = strdup(decoded);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=StreamCount:integer;",&buf,&buf_len)) {
	    desc->stream_count = atoi(buf);
	    //desc->stream = (struct sdpreal_stream_t **)xmalloc(sizeof(struct sdpreal_stream_t *) * desc->stream_count);
	    p = next_line(p);
	}
    
	else if(is_line(p,"a=Flags:integer;",&buf,&buf_len)) {
	    desc->flags = atoi(buf);
	    p = next_line(p);
	}
    
	else if(is_line(p,"m=",&buf,&buf_len)) { /* stream description */
	    stream = sdpreal_parse_stream(&p); /* p is at the end of stream desc */
	    //desc->stream[stream->stream_id] = stream;
	    list_h_append(&desc->streams,stream);
	}
    
	else {
	    p = next_line(p);
	}
    }
  
    free(buf);
    free(decoded);

    return desc;
}

