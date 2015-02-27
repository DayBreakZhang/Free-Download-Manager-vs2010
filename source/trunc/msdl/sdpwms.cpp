/***********************************************************************
 *    sdpwms.c: interpret wms protocol sdp
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

#include "stdafx.h"

#include "msdllib.h"
#include "sdpcommon.h"
#include "sdpwms.h"



static void free_sdpwms_stream_t(struct sdpwms_stream_t *p);
static struct sdpwms_stream_t *new_sdpwms_stream_t(void);


struct sdpwms_t *new_sdpwms_t(void)
{
    struct sdpwms_t *p = (sdpwms_t *)xmalloc(sizeof(struct sdpwms_t));
    return p;
}



void free_sdpwms_t(struct sdpwms_t *p)
{
    free(p->asf_header);
    free_list_h(p->streams,(void (*)(void *))free_sdpwms_stream_t);
  
    free(p);
}



static struct sdpwms_stream_t *new_sdpwms_stream_t(void)
{
    struct sdpwms_stream_t *p = (sdpwms_stream_t *)xmalloc(sizeof(struct sdpwms_stream_t));
    return p;
}



static void free_sdpwms_stream_t(struct sdpwms_stream_t *p)
{
    free(p->id);
    free(p->control);

    free(p);
}



struct sdpwms_stream_t *sdpwms_parse_stream(char **data)
{
    struct sdpwms_stream_t *stream;
    char *p = *data;
    char *buf = NULL;
    int buf_len = 0; /* don't touch it!! after here */
    char *decoded = NULL;
    int decoded_len = 0; /* don't touch it after here*/
    decoded_len = 0; /* shut up compiler !! */

  
    stream = new_sdpwms_stream_t();
  
    if(is_line(p,"m=",&buf,&buf_len)) {
	stream->id = strdup(buf);
	display(MSDL_VER,"stream: %s\n",stream->id);
	p = next_line(p);
    }
    else {
	display(MSDL_ERR,"no 'm=' line\n");
	free_sdpwms_stream_t(stream);
	return NULL;
    }
  
    for( ; p && *p && (p[0] != 'm'); ) {
    
	if(is_line(p,"a=control:",&buf,&buf_len)) {
	    stream->control = strdup(buf);
	    p = next_line(p);
	}
	else if(is_line(p,"a=stream:",&buf,&buf_len)) {
	    stream->streamnum = atoi(buf);
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



/*
 * parse sdp. compared to real-rtsp, it doesn't do much here
 * because asf_header will have all stream information.
 * thus it only does simplest stuff, extract asf header.
 */
struct sdpwms_t *wmserver_parse_sdp(char *data)
{
    char *p;                      /* always points first char of line in 'data' */
    char *buf = NULL;
    int buf_len = 0;              /* don't touch it after here !!*/
    char *decoded = NULL;
    int decoded_len = 0;          /* don't touch it after here   */
    struct sdpwms_t *desc = NULL;
    struct sdpwms_stream_t *stream = NULL;
  
    desc = new_sdpwms_t();

    for(p = data ; p && *p ; ) {
    
	if(is_line(p,"a=pgmpu:data:application/vnd.ms.wms-hdr.asfv1;base64,",&buf,&buf_len)) {
	    keep_dec_size(&decoded,&decoded_len,strlen(buf));
	    desc->asf_header_len = base64_decode(buf,decoded,decoded_len);
	    desc->asf_header = (uint8_t *)xmalloc(desc->asf_header_len);
	    memcpy(desc->asf_header,decoded,desc->asf_header_len);
	    p = next_line(p);
	}
	else if(is_line(p,"m=",&buf,&buf_len)) { /* stream description */
	    stream = sdpwms_parse_stream(&p);    /* p is at the end of stream desc */
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


