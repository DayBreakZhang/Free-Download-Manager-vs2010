/***********************************************************************
 *    http.h: for downloading via http (Hyper Text Transfer Protocol)
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on http implementation of mplayer.
 * mplayer's http implementation was very nice.
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
 * (from MPlayer-1.0rc2/stream/http.h)
 */

/* 
 * HTTP Helper
 * by Bertrand Baudet <bertrand_baudet@yahoo.com>
 * (C) 2001, MPlayer team.
 */



#ifndef __HTTP_H__
#define __HTTP_H__


struct http_field_t {
    char *field_name;
    struct http_field_t *next;
};


struct http_header_t {
    char *protocol;
    char *method;
    char *uri;
    unsigned int status_code;
    char *reason_phrase;
    unsigned int http_minor_version;
  
    /* field variables */
    struct http_field_t *first_field;
    struct http_field_t *last_field;
    unsigned int field_nb;
    char *field_search;
    struct http_field_t *field_search_pos;
  
    /* body variables */
    char *body;
    size_t body_len;
    char *buffer;
    size_t buffer_len; /* this is NOT the malloc()ed size, the data length. */
    unsigned int is_parsed;
};



struct http_ctrl_t {
    uint64_t content_length;  /* file size                  */
    uint64_t down_length;     /* size alrady downlaoded     */
};



struct http_header_t *new_http_header(void);
void free_http_header(struct http_header_t *h);
char *http_get_next_field(struct http_header_t *http_hdr);
char *http_get_field(struct http_header_t *http_hdr, const char *field_name);
void http_set_field(struct http_header_t *http_hdr, const char *field_name);

int http_send_header(struct stream_t *stream,struct http_header_t *http_hdr);
int http_recv_header(struct stream_t *stream,struct http_header_t *http_hdr);
int http_recv_header_get(struct stream_t *stream,struct http_header_t *http_hdr);
int http_process_reply(struct stream_t *stream,struct http_header_t *http_hdr);

char *http_encode_uri(const char *src);
int base64_encode(const void *enc,int enclen,char *out,int outsize);
int http_add_basic_authentication(struct http_header_t *http_hdr,
				    const char *username, const char *password);
char *http_redirect_new_url(struct http_header_t *http_hdr);
int http_print_authenticate_required(struct http_header_t *http_hdr);
void http_set_uri(struct http_header_t *http_hdr,const char *uri);
void http_set_method(struct http_header_t *http_hdr, const char *method);

char *http_request_get(struct http_header_t *http_hdr);
char *http_request_head(struct http_header_t *http_hdr);
char *http_request_post(struct http_header_t *http_hdr);
char *http_build_request(struct http_header_t *http_hdr);
int http_response_append(struct http_header_t *http_hdr,
			 char *response,int len);
int http_is_entire_header(struct http_header_t *http_hdr);
int http_response_parse(struct http_header_t *http_hdr);
int is_http_response_ok(int status_code);

int http_prepare_resuming(struct stream_t *stream);
void http_set_byterange_field(struct http_header_t *http_hdr,const char *rangestr);


/* for downloading http */
struct stream_t *http_streaming_init();
int http_streaming_start(struct stream_t *stream);
int http_streaming_read(struct stream_t *stream,
			uint8_t *buffer, size_t buffer_size);
void http_streaming_close(struct stream_t *stream);
struct http_ctrl_t *new_http_ctrl_t(void);
void free_http_ctrl_t(struct http_ctrl_t *ctrl);
int http_parse_response(struct http_ctrl_t *http_ctrl,
			struct http_header_t *http_hdr);



#endif
