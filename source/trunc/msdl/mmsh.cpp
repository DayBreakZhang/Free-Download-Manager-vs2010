/***********************************************************************
 *    mmsh.c:  downloading via mmsh (Microsoft Media Service over HTTP)
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

/*
 * Some code or data in this file is based on
 * MPlayer project
 * (MPlayer-1.0rc2/stream/stream/asf_streaming.c)
 */


#include "stdafx.h"

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "http.h"
#include "asf.h"
#include "mmsh.h"
#include "snprintf.h"


/* Windows Media Player stuff */
const char mmsh_useragent[]   = "User-Agent: NSPlayer/11.08.0005.0000";
const char mmsh_xclientguid[] = "Pragma: xclientGuid={00000000-0000-0000-0000-000000000000}";
const char mmsh_xacceptauth[] = "X-Accept-Authentication: Negotiate, NTLM, Digest, Basic";


/*
 * definitions of type of ASF streaming
 */
enum {
  
    ASF_Unknown_e,
    ASF_Seekable_e,
    ASF_Nonseekable_e,
    ASF_Authenticate_e,

} ASF_streaming_types;



/* 
 * asf chunk magics
 */
enum {

    ASF_STREAMING_CLEAR     = 0x4324,          /* $C */
    ASF_STREAMING_DATA      = 0x4424,          /* $D */
    ASF_STREAMING_END_TRANS = 0x4524,          /* $E */
    ASF_STREAMING_HEADER    = 0x4824,          /* $H */
    ASF_STREAMING_META      = 0x4d24,          /* $M */
  
    ASF_STREAMING_DATA2     = 0x44a4,
};




static struct mmsh_ctrl_t *new_mmsh_ctrl_t(void);

static void free_mmsh_ctrl_t(struct mmsh_ctrl_t *ctrlt);

static int mmsh_request_common(struct stream_t *stream,
			       struct http_header_t *http_hdr);

static struct http_header_t *mmsh_1st_request(struct stream_t *stream,
					      struct http_header_t *http_hdr);

static struct http_header_t *mmsh_keepalive_request(struct stream_t *stream,
						    struct http_header_t *http_hdr);

static struct http_header_t *mmsh_media_request(struct stream_t *stream,
						struct http_header_t *http_hdr);

static int mmsh_parse_response(struct mmsh_ctrl_t *mmsh_ctrl,
			       struct http_header_t *http_hdr);

static int asf_streaming(struct asf_stream_chunk_t *stream_chunk);

static int mmsh_get_asf_header(struct stream_t *stream,uint8_t **asfheader,
			       struct asf_stream_chunk_t *first_chunk);

static int mmsh_get_media_packet(struct stream_t *stream,
				 uint8_t *buffer, size_t max_size);

/*
 * allocate/free mmsh_ctrl_t
 */
static struct mmsh_ctrl_t *new_mmsh_ctrl_t(void)
{
    struct mmsh_ctrl_t *ctrlt = 
	(struct mmsh_ctrl_t *)xmalloc(sizeof(struct mmsh_ctrl_t));
    ctrlt->hinfo = new_asf_headerinfo_t();
    return ctrlt;
}


static void free_mmsh_ctrl_t(struct mmsh_ctrl_t *ctrlt)
{
    if(!ctrlt) return;

    if(ctrlt->keepalive_sock > 0) closesocket(ctrlt->keepalive_sock);
    if(ctrlt->hinfo) free_asf_headerinfo_t(ctrlt->hinfo);

    free(ctrlt);
}




/*
 * set common part for mmsh request (for 1st and 2nd request)
 * return value:   1 ... success
 *                -1 ... failure
 */
static int mmsh_request_common(struct stream_t *stream,
			       struct http_header_t *http_hdr)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct url_t *url = NULL;
    struct download_opts_t *dlopts = NULL;
  
    char str[BUFSIZE_1K];
  
    /* Sanity Check */
    if(stream_ctrl == NULL || http_hdr == NULL) {
	display(MSDL_ERR,
		"mmsh_request_common: argument invalid\n");
	return -1;
    }
    
    url = stream->url;
    dlopts = stream->dlopts;
    if((url == NULL) || (dlopts == NULL)) {
	return -1;
    }
  
    http_set_field(http_hdr, "Accept: */*");
    http_set_field(http_hdr, mmsh_useragent);
    
    http_add_basic_authentication(http_hdr,
				  (url->username) ? url->username : stream->dlopts->username,
				  (url->password) ? url->password : stream->dlopts->password);
    
    /* proxy check. use "http://" for proxy. */
    if(dlopts->http_proxy) {
	char *new_url = (char *)xmalloc(7 + strlen(url->file) + 1);
	/* use "http://" because it is http proxy!! */
	sprintf(new_url,"http://%s",url->file);
	http_set_uri(http_hdr,new_url);
	free(new_url);
    }
    else {
	http_set_uri(http_hdr,url->filepath);
    }
  
    snprintf(str,BUFSIZE_1K,"Host: %.220s",url->hostname); /* %.220s:%d,port*/
    http_set_field(http_hdr,str);
    
    http_set_field(http_hdr,mmsh_xclientguid);
    return 1;
}



/* very first mmsh request */
static struct http_header_t *mmsh_1st_request(struct stream_t *stream,
					      struct http_header_t *http_hdr)
{
    char str[BUFSIZE_1K];

    if(mmsh_request_common(stream,http_hdr) < 0) {
	display(MSDL_ERR,
		"mmsh_request_common fialed\n");
	return NULL;
    }
    
    snprintf(str,BUFSIZE_1K,
	     "Pragma: no-cache,rate=1.000,stream-time=%u,stream-offset=%u:%u,packet-num=%u,max-duration=%u",
	     0,                                              /* start time in milliseconds  */
	     0xffffffff,0xffffffff,
	     0xffffffff,                                     /* packet_num                  */
	     0);

    /* for some reason this is required */
    http_set_field(http_hdr,str);
    
    http_set_field(http_hdr,"Connection: Close");
    http_request_get(http_hdr);

    return http_hdr;
}


static struct http_header_t *mmsh_keepalive_request(struct stream_t *stream,
						    struct http_header_t *http_hdr)
{
    /* MUST use the socket different from stream->sock. */

    char str[128] = "\0";
    
    if(mmsh_request_common(stream,http_hdr) < 0) {
	display(MSDL_ERR,
		"mmsh_request_common fialed\n");
	return NULL;
    }
    
    /* there MUST NOT be Content-length field, and the content MUST be zero. */
    snprintf(str,127,
	     "Pragma: client-id=%u",stream->stream_ctrl->mmsh_ctrl->client_id);
    http_set_field(http_hdr,str);
    http_set_field(http_hdr,"Pragma: xKeepAliveInPause=1");
    http_set_field(http_hdr,"Connection: Keep-Alive");
    http_request_post(http_hdr);
    
    return http_hdr;
}



/*
 * mmsh_request : make request to the server
 */
static struct http_header_t *mmsh_media_request(struct stream_t *stream,
						struct http_header_t *http_hdr)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct mmsh_ctrl_t *mmsh_ctrl = stream_ctrl->mmsh_ctrl;
    char *ptr = NULL;

    int asf_streams_count = 0;
    char str[BUFSIZE_1K];

    uint32_t start_time    = 0;
    uint64_t stream_offset = 0xffffffffffffffff; /* used for Pragma stream-offset = %u:%u, default is 0xffffffff:0xffffffff */
    uint32_t max_duration  = 0;
    
    if(mmsh_request_common(stream,http_hdr) < 0) {
	display(MSDL_ERR,
		"mmsh_request_common fialed\n");
	return NULL;
    }

    if(stream->resumeinfo->resume_req_success) {
	start_time    = mmsh_ctrl->resume_start_ts;
	//stream_offset = stream->resumeinfo->resume_start_offset;
	display(MSDL_VER,
		"mmsh request to stream from %ums\n",start_time);
    }

    snprintf(str,BUFSIZE_1K,
	     "Pragma: no-cache,rate=1.000,stream-time=%u,stream-offset=%u:%u,packet-num=%u,max-duration=%u",
	     start_time,                                     /* start time in milliseconds  */
	     (unsigned int)(stream_offset >> 32),            /* high 32 bits where to start */
	     (unsigned int)(stream_offset & 0xffffffff),     /* low  32 bits where to start */
	     0xffffffff,                                     /* packet_num                  */
	     max_duration);
    http_set_field(http_hdr,str);
    /* MMSH part */

    snprintf(str,127,
	     "Pragma: client-id=%u",stream->stream_ctrl->mmsh_ctrl->client_id);
    http_set_field(http_hdr,str);
    
    http_set_field(http_hdr,"Pragma: version11-enabled=1");    
    http_set_field(http_hdr,"Pragma: xPlayStrm=1");


    /* snprintf(str,127, */
    /* 	     "Pragma: playlist-seek-id=%u",stream->stream_ctrl->mmsh_ctrl->playlist_id); */
    /* http_set_field(http_hdr,str); */
    
    /* taken from windows media player */
    http_set_field(http_hdr,"Pragma: LinkBW=2147483647, AccelBW=2147483647, AccelDuration=18000");
    
    ptr = str;
    ptr += sprintf(ptr,"Pragma: stream-switch-entry=");
    if(mmsh_ctrl->hinfo->streams->n_audio > 0) {
	int enable = 0;
	int stream_id = 0;
	int i = 0;
	/*printf("mmsh_ctrl->n_audio : %d\n",mmsh_ctrl->n_audio); */
	for(i = 0; i < mmsh_ctrl->hinfo->streams->n_audio; i++) {
	    stream_id = mmsh_ctrl->hinfo->streams->audio_streams[i];
	    /*printf("stream_id = %d %d\n",stream_id,mmsh_ctrl->audio_id); */
	    if(stream_id == mmsh_ctrl->hinfo->streams->audio_id) {
		enable = 0; /* enable stream  */
	    }
	    else {
		enable = 2; /* disable stream */
	    }
	    asf_streams_count++;
	    ptr += sprintf(ptr,"ffff:%d:%d ",stream_id,enable);
	}
    }
    if(mmsh_ctrl->hinfo->streams->n_video > 0) {
	int enable = 0;
	int stream_id = 0;
	int i = 0;
	for(i = 0; i < mmsh_ctrl->hinfo->streams->n_video; i++) {
	    stream_id = mmsh_ctrl->hinfo->streams->video_streams[i];
	    if(stream_id == mmsh_ctrl->hinfo->streams->video_id) {
		enable = 0; /* enable stream  */
	    }
	    else {
		enable = 2; /* disable stream */
	    }
	    asf_streams_count++;
	    ptr += sprintf(ptr,"ffff:%d:%d ",stream_id,enable);
	}
    }
    http_set_field(http_hdr,str);

    snprintf(str,BUFSIZE_1K,"Pragma: stream-switch-count=%d",asf_streams_count);
    http_set_field(http_hdr,str);
	
    if(stream->dlopts->speed) {
	char *reason = NULL;
	int  guessed_speed = 0;
	
	if(speed_valid_and_guess(stream->dlopts->speed,&guessed_speed,&reason)) { /* speed valid string */
	    snprintf(str,BUFSIZE_1K - 1,"Pragma: Speed=%s",stream->dlopts->speed);
	}
	else { /* invlalid, use guessed value */
	    if(guessed_speed == 0) {
		guessed_speed = 1; /* default speed 1.000 */
	    }
	    snprintf(str,BUFSIZE_1K - 1,"Pragma: Speed=%d.000",guessed_speed);
	    display(MSDL_ERR,
		    "option \"-s %s\" is invalid as a mmsh speed request\n"
		    ": %s\n"
		    "send \"%s\" instead\n",
		    stream->dlopts->speed,reason,str);
	}
	http_set_field(http_hdr,str);
    }

  
    http_set_field(http_hdr,"Connection: Keep-Alive");
    http_request_get(http_hdr);

    return http_hdr;
}



/*
 *  asf_header_check :  check if http_hdr->body is ASF object.
 *                     return value :  0 ... it was NOT asf object
 *                                     1 ... OK it was ASF object!
 */
int asf_header_check(struct http_header_t *http_hdr)
{
    struct asf_obj_header_t *asfobjh;
    if(!http_hdr) return 0;
    if(http_hdr->body == NULL || http_hdr->body_len < sizeof(struct asf_obj_header_t))
	return 0;
    asfobjh = (struct asf_obj_header_t *)http_hdr->body;
    /* get GUID first 4 byte for check */
    if(get32_le(asfobjh->guid) == 0x75b22630) return 1;
    return 0;
}



/*
 * returns content_type value.
 * this function is based on MPlayer /MPlayer/stream/asf_streaming.c
 */
int mmsh_streaming_type(char *content_type,char *features,
			struct http_header_t *http_hdr)
{
    if(content_type == NULL) return ASF_Unknown_e;

    
    if(!strcmp(content_type, "application/octet-stream") ||
       !strcmp(content_type, "application/vnd.ms.wms-hdr.asfv1") ||
       !strcmp(content_type, "application/x-mms-framed") ||
       !strcmp(content_type, "video/x-ms-asf")) {               
    
	if(strstr(features, "seekable") ) {
	    display(MSDL_VER,"seekable ASF stream\n");
	    return ASF_Seekable_e;
	} else {
	    display(MSDL_VER,"non-seekable ASF stream\n");
	    return ASF_Nonseekable_e;
	}
    }
    else {
	display(MSDL_VER,"content type: %s\n",content_type);
	return ASF_Unknown_e;
    }
}


/*
 * receive mmsh message from stream->sock.
 * use http_recv_header first.
 *               return status code : success
 *                               -1 : failure
 */
int mmsh_recv_header(struct stream_t *stream,struct http_header_t *http_hdr)
{
    int ret = 0;

    ret = http_recv_header_get(stream,http_hdr);    
    if(ret < 0) {
	display(MSDL_ERR,"MMSH header parse error by http header parse error\n");
	return -1;
    }

    ret = mmsh_parse_response(stream->stream_ctrl->mmsh_ctrl,http_hdr);
    if(ret < 0) {
	display(MSDL_ERR,"mmsh_parse_response failed\n");
	return -1;
    }

    return http_hdr->status_code;
}



/*
 * mmsh_parse_response : addtional header parse for mmsh
 *                       do this after http_parse_response
 * basically parse Pragma lines.
 * return value:  1 ... success
 *               -1 ... failure
 */
static int mmsh_parse_response(struct mmsh_ctrl_t *mmsh_ctrl,
			       struct http_header_t *http_hdr)
{
    char *content_type, *pragma;
    char features[128] = "\0";
    
    content_type = http_get_field(http_hdr, "Content-Type");

    pragma = http_get_field(http_hdr, "Pragma");
    while(pragma != NULL) {
	char *p = NULL;	
	/* we have to get features="" string to judge mmsh stream type */

	if((p = xstrcasestr(pragma,"features=")) != NULL) { /* found */
	    char *startp = NULL;
	    char *endp = NULL;

	    p += 9;
	    while(*p == ' ') p++; /* skip whitespace */
	    startp = p; /* save start pos */
	    if(*p == '\"') { /* if '"', go to next '"' or EOS */
		p++;
		while(*p != '\"' && *p != '\0') p++;
	    }
	    if(*p == '\0') { /* EOS */
		endp = p;
	    }
	    else if(*p == '\"'){
		endp = p+1; /* char after '"' */
	    }
	    /* "aaa", */
	    if(endp - startp < 128) {
		strncpy(features,startp,endp-startp);
		features[endp - startp] = '\0';
	    }
	    else {
		strncpy(features,startp,127);
		features[127] = '\0';
	    }
	}
	
	if((p = xstrcasestr(pragma,"client-id=")) != NULL) {
	    uint32_t id = 0;
	    
	    p += 10;
	    while(*p == ' ') p++; /* skip whitespace */

	    for(;'0' <= *p && *p <= '9'; p++) {
		id *= 10;
		id += *p - '0';
	    }
	    
	    mmsh_ctrl->client_id = id;
	}

	
	/*
	  ==caution==
	  if there are multipule features, get the newest one
	*/
	
	pragma = http_get_next_field(http_hdr); /* keep getting Pragma lines. */
    }
    
    mmsh_ctrl->streaming_type
	= mmsh_streaming_type(content_type,features,http_hdr);
    
    return 1;
}



/*
 * interpret asf_stream_chunk.
 *           return value: type of chunk
 */
static int asf_streaming(struct asf_stream_chunk_t *stream_chunk)
{
    
    /* little endian */
    display(MSDL_DBG,"ASF chunk == type: 0x%02x, size: %d (0x%02x), seq: 0x%04x\n",
	    le2me_16(stream_chunk->type),
	    le2me_16(stream_chunk->size),le2me_16(stream_chunk->size), 
	    le2me_32(stream_chunk->seqnum));
  
    switch(le2me_16(stream_chunk->type)) {
    case ASF_STREAMING_CLEAR:          /* $C  Clear ASF configuration  */
	display(MSDL_DBG,"Clearing ASF stream configuration\n");
	break;
    
    case ASF_STREAMING_DATA:           /* $D  Data follows             */
    case ASF_STREAMING_DATA2:
	/*display(MSDL_DBG,"Data follows\n"); */
	break;
    
    case ASF_STREAMING_END_TRANS:      /* $E  End of transfer          */
	display(MSDL_DBG,"Transfer complete!!\n");
	break;

    case ASF_STREAMING_HEADER:         /* $H  ASF Header chunk follows */
	/* display(MSDL_DBG,"ASF header chunk follows\n"); */
	break;
    case ASF_STREAMING_META:
	break;

    default:
	display(MSDL_DBG,"not ASF chunk: [0x%x]!!\n",
		le2me_16(stream_chunk->type));
    }
    return le2me_16(stream_chunk->type);
}



/*
 * fallback from mmsh to http WITHOUT re-sending GET
 * message to server.
 * this will be more pleasant to server.
 *
 * this function must be called when
 * [ no data in http_hdr->body (already moved)]
 * [ http_hdr is alreadyh set ]
 *    return value:    
 */
int mmsh_fallback_to_http(struct stream_t *stream,
			  struct http_header_t *http_hdr)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    int ret;
    display(MSDL_VER,"probably not mmsh. fallback to http.\n");
  
    /* quit mmsh, and start http */
    free_mmsh_ctrl_t(stream_ctrl->mmsh_ctrl);
    stream_ctrl->http_ctrl = new_http_ctrl_t();
  
    stream->start = http_streaming_start;
    stream->read  = http_streaming_read;
    stream->close = http_streaming_close;

    /* read content-length */
    ret = http_parse_response(stream_ctrl->http_ctrl,http_hdr);
    stream->stream_ctrl->file_size = stream_ctrl->http_ctrl->content_length;
  
  
    /* 
       free_http_header(http_hdr);  don't free it here.
       it will be free()ed later
    */
  
    stream_ctrl->protocol = HTTP;
  
    return ret;
}



/*
 * get entire asf header.
 * this function is needed because asf_header might come
 * within more than 2 packets.
 *  *** CAUTION ***
 *  DO NOT FORGET TO free() asfheader later!!
 *  all header is going to stored in buffer.
 *                    return value:   -1  ... failure
 *                                  other ... length of asf header
 */
static int mmsh_get_asf_header(struct stream_t *stream,uint8_t **asfheader,
			       struct asf_stream_chunk_t *first_chunk)
{
    struct asf_stream_chunk_t chunk;
    struct asf_stream_chunk_extra_t chunk_extra;
    struct asf_header_t asfh;
    uint8_t *buffer = NULL;
  
    int asf_header_len = 0;
    int total;
    int ret;
  
    total = 0;
    memcpy(&chunk,first_chunk,sizeof(chunk));
  
    for(;;) {
	/* read chunk extra */
	if(read_data(stream,&chunk_extra,sizeof(chunk_extra)) <= 0) {
	    goto failed;
	}

	ret = le2me_16(chunk.size) - sizeof(chunk);
    
	buffer = (uint8_t *)xrealloc(buffer,ret + total);
    
	stream->stream_ctrl->packet_count++; /* increment packet count */
    
	ret = read_data(stream,buffer + total,ret);
	if(ret < 0) {
	    goto failed;
	}
    
	if(asf_header_len == 0) { /* first loop */
	    if(ret < sizeof(struct asf_header_t)) {
		display(MSDL_ERR,"1st chunk %d shorter than asf_header_t\n",ret);
		goto failed;
	    }
	    memcpy(&asfh,buffer,sizeof(struct asf_header_t));
	    asf_header_len = le2me_64(asfh.objh.size);
	    if(asf_header_len == 0) {
		display(MSDL_ERR,"asf_header_len is zero\n");
		goto failed;
	    }
	}
    
	total += ret;
    
	if(total >= asf_header_len) {
	    break; /* got entire header --- break */
	}
	else {
	    int chunk_type;
	    /* get chunk for next loop */
	    if(read_data(stream,&chunk,sizeof(chunk)) <= 0) {
		goto failed;
	    }
	    
	    chunk_type = asf_streaming(&chunk);
      
	    if(chunk_type != ASF_STREAMING_HEADER) { /* not a header packet */
		display(MSDL_ERR,"non-header paceket when header packet expected\n");
		goto failed;
	    }
	}
    } 
  
    *asfheader = buffer;
    return total;
  
  failed:
    free(buffer);
    *asfheader = NULL;
    return -1;
}




/*
 * starts mms over http streaming. (mmsh)
 * 
 *    return value :   negative or 0  ... error
 *                                 1  ... success
 */
int mmsh_streaming_start(struct stream_t *stream)
{
  
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct mmsh_ctrl_t *mmsh_ctrl = stream_ctrl->mmsh_ctrl;
    struct url_t *url = stream->url;
    struct download_opts_t *dlopts = stream->dlopts;
    struct http_header_t *http_hdr = NULL;

    int asf_header_len = 0;
  
    int sock = 0; /* socket to use   */
    int ret = 0;

    stream_ctrl->status = STREAMING_HANDSHAKING;
  
    mmsh_ctrl->streaming_type = ASF_Unknown_e;
    
    if(dlopts->bandwidth) {
	stream_ctrl->bandwidth = dlopts->bandwidth;
    }
    else {
	stream_ctrl->bandwidth = INT_MAX_BANDWIDTH;
    }
    
    set_serverinfo_by_proxy_string(stream->serverinfo,url->hostname,url->port,
				   dlopts->http_proxy,
				   HTTP_PORT,HTTP_PROXY_PORT);
    /* proxy setting: done */
    sock = server_connect(stream->serverinfo->connect_host,stream->serverinfo->connect_port);
    if(sock < 0) {
	return sock; /* failure */
    }
    stream->netsock->sock = sock; /* set socket# to stream_t */

    
    /* send 1st request */
    stream_ctrl->packet_count = 0;    
    http_hdr = new_http_header();

    if(dlopts->resume_download) {
	http_prepare_resuming(stream);
    }
    /* byte range specified */
    if(dlopts->byterange) {
	http_set_byterange_field(http_hdr,dlopts->byterange);
    }
    
    mmsh_1st_request(stream,http_hdr);

    http_send_header(stream,http_hdr);
    free_http_header(http_hdr);
    http_hdr = NULL;
    
    /* get 1st reply */
    http_hdr = new_http_header();
    mmsh_recv_header(stream,http_hdr);
    ret = http_process_reply(stream,http_hdr); // interpret http_hdr which just received
    if(ret < 0) {
	goto failed; // including complete
    }
    
    switch(mmsh_ctrl->streaming_type) {
    case ASF_Seekable_e:
    case ASF_Nonseekable_e:
    {
	struct asf_stream_chunk_t chunk; /* for chunk header for asf header */
	int chunk_type; /* little endian */
	uint8_t *buffer = NULL;
	
	stream->stream_ctrl->protocol = MMSH;
	
	/* we are supposed to get the ASF header! ( 100% ) */
	display(MSDL_VER,"1st response from server...  \n");
	
	/* keep getting chunk until it stops getting META */
	for(;;) {
	    if(read_data(stream,&chunk,sizeof(chunk)) <= 0) {
		goto failed;
	    }
	    
	    chunk_type = asf_streaming(&chunk);
	    if(chunk_type == ASF_STREAMING_META) { /* if $M, try agian */
		char *p = NULL;		

		/* we might need playlist-gen-id, which is written in $M packet  */
		buffer = (uint8_t *)xmalloc(chunk.size - 4);		    
		if(read_data(stream,buffer,chunk.size - 4) <= 0) {
		    free(buffer);
		    goto failed;
		}
		
		if((p = strstr((char *)buffer + 4,"playlist-gen-id="))) { /* +4 for skipping the size field */
		    p += strlen("playlist-gen-id=");
		    mmsh_ctrl->playlist_id = atoi(p);
		    display(MSDL_VER,"playlist-gen-id = %d\n",mmsh_ctrl->playlist_id);
		}

		free(buffer);
	    }
	    else {
		break;
	    }
	} 
	
	if(chunk_type == ASF_STREAMING_HEADER) {
	  
	    /* header may come within more than 2 packets */
	    asf_header_len = mmsh_get_asf_header(stream,&buffer,&chunk);
	  
	    if(asf_header_len < 0) {
		goto failed;
	    }
	  
	    display(MSDL_VER,"ASF header received (size = %d)\n",asf_header_len);
	  
	    /* interpret M$ asf header */
	    ret = asf_interpret_header(mmsh_ctrl->hinfo,stream_ctrl->bandwidth,
				       buffer,asf_header_len);
	  
	    /* set necessary information to mmsh_ctrl */
	    stream_ctrl->file_size = mmsh_ctrl->hinfo->fileh->file_size;

	    stream_ctrl->packet_length = mmsh_ctrl->packet_size =
		mmsh_ctrl->hinfo->fileh->max_packet_size;
	    /* and everything is done */
	  
	    free(buffer);
	    buffer = NULL;
	  
	    if(ret < 0) {
		goto failed;
	    }
	  
	    if(mmsh_ctrl->hinfo->streams->n_audio == 0 &&
	       mmsh_ctrl->hinfo->streams->n_video == 0) {
		/* this means no stream to DL */
		display(MSDL_ERR,"No stream to download!\n");
		goto failed;
	    }
	    display(MSDL_VER,"\n");
	}
	else if(chunk_type == ASF_STREAMING_CLEAR || 
		chunk_type == ASF_STREAMING_DATA  || 
		chunk_type == ASF_STREAMING_END_TRANS) {
	    display(MSDL_ERR,"ASF header expected!!\n");
	    goto failed;
	}
	else { /* not mmsh, try http here. */
	  
	    /* push back "chunk" to be read again */	  
	    stream_data_push_back(stream,&chunk,sizeof(chunk));
	    mmsh_fallback_to_http(stream,http_hdr);
	    goto http_fallback;
	}
	break;
    }
    case ASF_Unknown_e:
	mmsh_fallback_to_http(stream,http_hdr);
	goto http_fallback;
	
    default: /* should not come here */
	goto failed;
	break;
    }

    
    /* allways comes here to free http_hdr */
    if(http_hdr) free_http_header(http_hdr);
    http_hdr = NULL;

    closesocket(sock);
    sock = server_connect(stream->serverinfo->connect_host,stream->serverinfo->connect_port);
    if(sock < 0) {
	return sock; /* failure */
    }
    stream->netsock->sock = sock; /* set socket# to stream_t */

    /* prepare_resuming used to be here */
    if(dlopts->resume_download) {
	mmsh_prepare_resuming(stream);
    }
    
    /* do the actual mmsh request */    
    http_hdr = new_http_header();
    mmsh_media_request(stream,http_hdr);
    http_send_header(stream,http_hdr);
    free_http_header(http_hdr);
    http_hdr = NULL;
    
    http_hdr = new_http_header();
    ret = mmsh_recv_header(stream,http_hdr);
    if(ret < 0) {
	display(MSDL_ERR,"MMSH connection failed\n");
	goto failed;
    }
    
    if(!is_http_response_ok(ret)) { /* MMSH request error */
	display(MSDL_ERR,"%d %s\n",http_hdr->status_code,http_hdr->reason_phrase);
	goto failed;
    }
    
    free_http_header(http_hdr);
    http_hdr = NULL;

    if(mmsh_ctrl->streaming_type != ASF_Seekable_e &&
       mmsh_ctrl->streaming_type != ASF_Nonseekable_e) {
	display(MSDL_ERR,"mmsh request failed\n");
	goto failed;
    }
    
    stream->stream_ctrl->status = STREAMING_DOWNLOADING;
    return 1;

  http_fallback:
    free_http_header(http_hdr);
    http_hdr = NULL;
    return 1;
    
  failed:
    free_http_header(http_hdr);
    if(sock) closesocket(sock);
    http_hdr = NULL;
    return 0;
}



/*
 * read from media stream.
 * 
 * fill 'buffer' with data, and buffer size is 'max_size'.
 * receive one chunk from stream->sock, and fills 'max_size' bytes to buffer.
 * and if there are more bytes in the chunk, the data is stored to
 * stream->stream_ctrl->buffer.
 *
 *    return value: positive value ... bytes written to buffer.
 *                  0              ... END OF FILE
 *                              or ... Clear EVERYTHING!!! RESET!!!
 *                 -1              ... ERROR
 */
static int mmsh_get_media_packet(struct stream_t *stream,
				 uint8_t *buffer, size_t max_size)
{
  
    static struct asf_stream_chunk_t chunk;
    static struct asf_stream_chunk_extra_t chunk_extra;
    int chunk_size = 0;
    int chunk_type;
    
    int data_follows_f;
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct mmsh_ctrl_t *mmsh_ctrl = stream_ctrl->mmsh_ctrl;

  
    do {
	data_follows_f = 1;
    
	/* get chunk header from network. */
	if(read_data(stream,&chunk,sizeof(chunk)) <= 0) {
	    goto failed;
	}

	/* little endian. (asf streaming interpret as little endian.) */
	chunk_type = asf_streaming(&chunk);

	/*HTTP message packet ... continue, we don't need the data. throw it away. */
	if(!(memcmp((uint8_t *)&chunk,"HTTP",4))) {
	    struct http_header_t *http_hdr;
	    char *field = NULL;
	    int len = 0;
      
	    stream_data_push_back(stream,(uint8_t *)&chunk,sizeof(chunk));
	    http_hdr = new_http_header();
	    http_recv_header(stream,http_hdr);

	    if((field = http_get_field(http_hdr,"Content-Length")) != NULL) {
		while(*field == ' ') field++;
		len = atoi(field);
	    }

	    free_http_header(http_hdr);
      
	    if(len) {
		uint8_t *buf = (uint8_t *)xmalloc(len);
		if(read_data(stream,buf,len) <= 0) {
		    free(buf);
		    goto failed;
		}
		free(buf); /* Ignore all */
	    }

	    data_follows_f = 0; /* don't forget to clear this. as no data follows */
	}
	else if(chunk_type == ASF_STREAMING_END_TRANS) {
      
	    stream_ctrl->status = STREAMING_FINISHED;
	    display(MSDL_DBG,"Transaction finished normally!\n");
	    return 0;
	}
	else if(chunk_type == ASF_STREAMING_CLEAR) {
	    stream_ctrl->status = STREAMING_REWIND;
      
	    /* reset every headerinfo data */
	    free_asf_headerinfo_t(mmsh_ctrl->hinfo);
	    mmsh_ctrl->hinfo = new_asf_headerinfo_t();

	    display(MSDL_VER,"\nClear Configuration! reset!\n");
	    data_follows_f = 0; /* loop again , and get header/data/eof packet */
	}
	else if(chunk_type == ASF_STREAMING_DATA   ||
		chunk_type == ASF_STREAMING_DATA2  ||
		chunk_type == ASF_STREAMING_HEADER) {
	    if(read_data(stream,&chunk_extra,sizeof(chunk_extra)) <= 0) {
		goto failed;
	    }
	}
	else if(chunk_type == ASF_STREAMING_META){
	    char *buffer = NULL;
	    char *p = NULL;
	    
	    buffer = (char *)xmalloc(chunk.size - 4);
	    if(read_data(stream,buffer,chunk.size - 4) <= 0) {
		free(buffer);
		goto failed;
	    }
	    display(MSDL_DBG,"Metadata ----\n");
	    dbgdump(buffer, chunk.size - 4);
	    display(MSDL_DBG,"-(%d B)--------\n",chunk.size - 4);

	    if((p = strstr((char *)buffer + 4,"playlist-gen-id="))) { /* +4 for skipping the size feild */
	    	p += strlen("playlist-gen-id=");
	    	mmsh_ctrl->playlist_id = atoi(p);
	    	display(MSDL_VER,"playlist-gen-id = %d\n",mmsh_ctrl->playlist_id);
	    }

	    free(buffer);
	    data_follows_f = 0;
	}
	else { /* ignore this*/
	    display(MSDL_ERR,"unknown packet type!!\n");
	}
    
    } while(data_follows_f == 0);
  
    /* 
       size of this chunk. ( media stream data )
       >>> CAUTION <<< 
       chunk_size is size of chunk to get from network, but
       have to write mmsh_ctrl->packet_size bytes in ASF file.
       so 0 padding of 'mmsh_ctrl->packet_size - chunk_size' bytes
       is necessary.
    */
    chunk_size = le2me_16(chunk.size) - sizeof(chunk);
  
    stream_ctrl->packet_count++; /* increment received packet count */

    /*
      keepalive stuff
     */
    if(stream_ctrl->packet_count % 200 == 0) {
	/*
	  MMSH server requires Keep-Alive packet from client.
	  We use non-pipelined mode in msdl, so it MUST be an POST request
	  
	  o MUST use the different socket currently using 
	  o MUST not include the Content-Length header
	  o must include the client-id: header to tell which connection to Keep-Alive.
	  
	  the header is made in mmsh_keepalive_request().
	*/
	
	if(mmsh_ctrl->keepalive_sock == 0) {
	    display(MSDL_ERR,"\n"); /* because server_connect will output a message */
	    int sock = server_connect_with_timeout(stream->serverinfo->connect_host,
						   stream->serverinfo->connect_port,
						   4.0); /* because we cannot stop here. */
	    if(sock < 0) {
		display(MSDL_ERR,"mmsh: Keepalive socket connect failed\n");
	    }
	    else {
		mmsh_ctrl->keepalive_sock = sock; /* set sock */
	    }
	}
	
	if(mmsh_ctrl->keepalive_sock > 0) {
	    struct http_header_t *http_hdr = NULL;
	    
	    http_hdr = new_http_header();
	    http_hdr = mmsh_keepalive_request(stream,http_hdr);
	    
	    if(xsend(mmsh_ctrl->keepalive_sock,http_hdr->buffer,http_hdr->buffer_len) < 0) {
		display(MSDL_DBG,"mmsh: Keepalive request send failed\n");
		closesocket(mmsh_ctrl->keepalive_sock);
		mmsh_ctrl->keepalive_sock = 0;    /* closesocket, and set 0 */
	    }
	    else { /* sent keep-alive packet */
		display(MSDL_DBG,
			"Keep-alive packet sent\n"
			"-----------------------------------\n"
			"%s\n"
			"-----------------------------------\n",
			http_hdr->buffer);
	    }
	    free_http_header(http_hdr);
	}
    }
  
    /* header or data, as other packets are already processed */ 
    if(chunk_type == ASF_STREAMING_HEADER) {
	int ret = 0;
	struct asf_headerinfo_t *hinfo = mmsh_ctrl->hinfo;
    
	display(MSDL_DBG,"ASF Header received\n");


	if(stream_ctrl->status == STREAMING_RESUME_BUFFERING) { /* when buffering, dont write header to the file */

	    /* header coming, but we don't need it */
	    if(read_data(stream, stream->stream_ctrl->write_buffer, chunk_size) <= 0) {
		goto failed;
	    }
	    /* we don't touch whats inside write_buffer, just ignore */
	    
	    return 0; /* we don't care about the header. ASF_STREAMING_DATA is what I want */
	}


	if(chunk_size <= max_size) { /* header can be stored in buffer */
	    /* buffer is long enogh. */
	    ret = read_data(stream,buffer,chunk_size);
	    if(ret <= 0) {
		goto failed;
	    }
	    /* no padding, because this is ASF header */
	}
	else { /* buffer is not long enough for header. */
	    /* data is to be written in file, so it goes to write_buffer */
	    if(read_data(stream, stream->stream_ctrl->write_buffer, chunk_size) <= 0) {
		goto failed;
	    }
	    memcpy(buffer, stream_ctrl->write_buffer, max_size);
	    stream_ctrl->write_pos = max_size;
	    stream_ctrl->write_data_len = chunk_size - max_size;
	    ret = max_size;
	}
	
	/*
	  interpret asf_header.
	  it has to be done here and doing complecated stuff because
      
	  . there is "clear configuration" packet, thus header comes multiple times.
	  . header we receive in 'mmsh_streaming_start' and one which we got in this
	    function differs.
	  . we don't know in how many packets the header will come.

	  and there are necessary stuff after asf_header, so
	  asf_header_len is not likely asfh.objh.size(pure header length, not
	  including the "necessary stuff").
	  
	  :) it sucks...
	*/
    
	/* copy asf header */
	hinfo->asf_header = (uint8_t *)xrealloc(hinfo->asf_header,
				     hinfo->asf_header_len + chunk_size); /* expand buffer to the enough size */

	memcpy(hinfo->asf_header + hinfo->asf_header_len,
	       (chunk_size <= max_size) ? buffer : stream_ctrl->write_buffer,
	       chunk_size);
	hinfo->asf_header_len += chunk_size; /* accumulate */
    
	if(hinfo->asf_header_len >= sizeof(struct asf_header_t) && 
	   hinfo->asf_header_len >=
	   le2me_64(((struct asf_header_t *)hinfo->asf_header)->objh.size)) {
	    if(asf_get_file_property(hinfo->asf_header,
				     hinfo->asf_header_len,
				     hinfo->fileh) < 0) {
		display(MSDL_ERR,"asf_get_file_property error\n");
		goto failed;
	    }
      
	    stream_ctrl->packet_length = mmsh_ctrl->packet_size =
		hinfo->fileh->max_packet_size;
	    stream_ctrl->file_size = hinfo->fileh->file_size;
	}

	return ret;
    }
    else {
	display(MSDL_DBG,"ASF Data received\n");
	if(mmsh_ctrl->packet_size < chunk_size) {
	    display(MSDL_ERR,"chunk size(%d) bigger than pakcet size(%d). Possible an error\n",
		    chunk_size,mmsh_ctrl->packet_size);
	    goto failed;
	}

	/* if buffering (for resuming), do special thing */
	if(stream_ctrl->status == STREAMING_RESUME_BUFFERING) {
	    uint32_t send_time_of_this_packet = 0;	    
	    if(read_data(stream,stream_ctrl->write_buffer,chunk_size) <= 0) {
		goto failed;
	    }
	    
	    asf_data_packet_get_send_time(stream_ctrl->write_buffer,
					  &send_time_of_this_packet);
	    display(MSDL_DBG,
		    "target ts: %d [0x%x], current packet ts: %d [0x%x]\n",
		    mmsh_ctrl->resume_start_ts,
		    mmsh_ctrl->resume_start_ts,
		    send_time_of_this_packet,send_time_of_this_packet);
	    
	    if(send_time_of_this_packet == mmsh_ctrl->resume_start_ts) { /* the packet to write has come */
		stream_ctrl->status = STREAMING_DOWNLOADING; /* remove resuming flag */
	    
		if(max_size > mmsh_ctrl->packet_size) {  /* go to buffer       */
		    memcpy(buffer,stream_ctrl->write_buffer,chunk_size);
		    memset(buffer + chunk_size,0,mmsh_ctrl->packet_size - chunk_size); /* padding */
		    stream_ctrl->write_data_len = 0;
		    stream_ctrl->write_pos = 0;
		
		    return mmsh_ctrl->packet_size;
		}
		else {                                       /* go to write_buffer */
		    memset(stream_ctrl->write_buffer + chunk_size,0,
			   mmsh_ctrl->packet_size - chunk_size); /* padding */
		    memcpy(buffer,stream_ctrl->write_buffer,max_size);
		    stream_ctrl->write_data_len = mmsh_ctrl->packet_size - max_size;
		    stream_ctrl->write_pos = max_size;

		    return max_size;
		}
	    }
	    else if(send_time_of_this_packet > stream_ctrl->mmsh_ctrl->resume_start_ts) {
		/* this means resuming failed, because time stamp is different */
		display(MSDL_ERR,
			"resume buffeing: timestamp error\n"
			"                 suggest downloading from beginning\n");
		goto failed;
	    }
	    else {  /* ignore -> just get the next chunk, it was not what I want */
		if(send_time_of_this_packet == 0) {
		    display(MSDL_ERR,
			    "\n"
			    "mmsh: Seek Request failed, server started streaming from the beginning..\n");
		}
		
		return 0;
	    }
	}

	if(mmsh_ctrl->packet_size <= max_size) {
	    /* buffer is bigger enough for this chunk. */
	    if(read_data(stream, buffer, chunk_size) <= 0) {
		goto failed;
	    }
	    memset(buffer + chunk_size, 0,mmsh_ctrl->packet_size - chunk_size); /* padding */
	    return  mmsh_ctrl->packet_size;
	}
	else { /* max_size < packet_size .. cannot write in buffer. */
	    if(read_data(stream, stream_ctrl->write_buffer, chunk_size) <= 0) {
		goto failed;
	    }
	    /*
	      this is OK because netsock->buffer is empty
	      when entered this function. 
	    */
	    memset(stream_ctrl->write_buffer + chunk_size, 0, /* padding */
		   mmsh_ctrl->packet_size - chunk_size);
	    memcpy(buffer,stream_ctrl->write_buffer, max_size);
	    stream_ctrl->write_data_len = mmsh_ctrl->packet_size - max_size;
	    stream_ctrl->write_pos = max_size;
	    
	    return max_size;
	}
    }
    
  failed: /* probably timeout error */
    return -1;
}



/*
 * read mms over http stream. filles buffer, and buffer size is 'size' 
 *
 *        read cached data from stream->netsock->buffer
 *        check for to see if network access is necessary
 *        get chunk(media packet) from network.
 *
 *  return value: bytes written to buffer. -1 if error.
 */
int mmsh_streaming_read(struct stream_t *stream,
			uint8_t *buffer, size_t buffer_size)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    size_t pos = 0; /* how many bytes are in 'buffer' */
    int network_read = 0;

    if(buffer_size == 0) {
	display(MSDL_ERR,"buffer_size must be bigger than 0\n");
	return -1;
    }
  
    if(stream_ctrl->write_data_len) { /* there are waiting data to be written */
    
	if(buffer_size <= stream_ctrl->write_data_len) {
	    /*
	      buffer_size < stream_ctrl->write_data_len...
	      fill buffer, and return.
	    */
	    memcpy(buffer,stream_ctrl->write_buffer + stream_ctrl->write_pos,
		   buffer_size);
	    stream_ctrl->write_data_len -= buffer_size;
	    stream_ctrl->write_pos += buffer_size;
	    return buffer_size;
	}
	else { 
	    /*
	      stream_ctrl->write_data_len < buffer_size,
	      have to read from network.
	    */
	    memcpy(buffer,stream_ctrl->write_buffer + stream_ctrl->write_pos,
		   stream_ctrl->write_data_len);
	    pos = stream_ctrl->write_data_len;
	    /* and stream_ctrl->write_buffer is empty. */
	    stream_ctrl->write_data_len = 0;
	    stream_ctrl->write_pos = 0;
	}
    }
    
    stream_ctrl->write_data_len = 0;
    stream_ctrl->write_pos = 0;
    
    /* still have to get data from network. */
    if(stream_ctrl->status != STREAMING_FINISHED) { /* not finished */
	network_read = mmsh_get_media_packet(stream, buffer + pos, buffer_size - pos);
    }
  
    if(stream_ctrl->status == STREAMING_RESUME_BUFFERING && network_read >= 0) {
	return 0;
    }
    else if(network_read >= 0) { /* network read success */
	return (network_read + pos);
    }
    else {
        return -1; /* error */
    }
}



int mmsh_prepare_resuming(struct stream_t *stream)
{
    /* search local file which has same name with straem*/
    uint32_t last_send_time = 0;
    uint64_t seek_pos = 0;
    int ret = 0;
    
    /*
     * find same file name
     */
    
    ret = asf_get_npt_of_last_packet(stream->localfile,&last_send_time,&seek_pos);
    if(ret < 0) {
	goto failed;
    }
    if((last_send_time / 1000) <  10 /*MINIMUM_RESUME_START_TIME*/) {
	display(MSDL_ERR,
		"file \"%s\" has only %d sec, just start from beginning\n",
		stream->localfile,last_send_time / 1000);
	goto failed;
    }
    
    stream->stream_ctrl->mmsh_ctrl->resume_start_ts = last_send_time;
    /* above, RESUME_BUFFERING_TIME is 0 in mmsh, as mmsh has stream-time and stream-offset to tell the range */

    stream->resumeinfo->resume_start_offset = seek_pos;
    stream->resumeinfo->resume_req_success = 1;

    display(MSDL_DBG,
	    "mmsh resume: start ts: %d [0x%x]   pos: %lld [0x%llx]\n",
	    last_send_time,last_send_time,seek_pos,seek_pos);

    return 1;

  failed:
    stream->resumeinfo->resume_start_offset = 0; /* don't check request result */
    stream->resumeinfo->resume_req_success = 0;
    return -1;
}



struct stream_t *mmsh_streaming_init()
{
    struct stream_t *stream = streaming_init_common();
    stream->stream_ctrl->mmsh_ctrl = new_mmsh_ctrl_t();
  
    stream->start = mmsh_streaming_start;
    stream->read  = mmsh_streaming_read;
	stream->close = mmsh_streaming_close;
   
    return stream;
}



void mmsh_streaming_close(struct stream_t *stream)
{
    if(stream->netsock->sock > 0) {
	closesocket(stream->netsock->sock);
    }

    free_mmsh_ctrl_t(stream->stream_ctrl->mmsh_ctrl);
    streaming_close_common(stream);
}

