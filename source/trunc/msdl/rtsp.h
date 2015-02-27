/***********************************************************************
 *    rtsp.h: for downloading via rtsp (Real Time Streaming Protocol)
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on rtsp implementation of 
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



#ifndef __RTSP_H__
#define __RTSP_H__

extern char m_szLastError[1000];

enum {
    RTSP_STATUS_OK = 200,
    RTSP_STATUS_SET_PARAMETER = 10,
    RTSP_STATUS_OPTIONS = 20,
    RTSP_STATUS_ANNOUNCE = 30,
};



enum {
    RTSP_UNKNOWN_PROTOCOL = 0,
    RTSP_REAL_PROTOCOL,
    RTSP_WMS_PROTOCOL,
};


enum {
    MINIMUM_RESUME_START_TIME = 10,   /* second     */
    RESUME_BUFFERING_TIME = 3 * 1000, /* milisecond */
}; /* resume */


struct rtsp_field_t {
    char *field_name;
    struct rtsp_field_t *next;
};



struct rtsp_ctrl_t {
    int rtsp_protocol;    /* which rtsp protocol, such as RTSP_REAL_PROTOCOL */
  
    char *mrl;            /* this is rtsp-conpatible URL. rtsp://ss:port/pp  */
    char *server;
    uint32_t server_state;
    uint32_t server_caps;

    uint32_t cseq;
    char *session;
    char *etag;
    char *challenge; /* only in Real */
    
    uint32_t resume_start_ts; /* only in wmserver */

    int (*get_media_packet)(struct stream_t *stream,
			    uint8_t *buffer,size_t max_size);
  
    /* data for rtsp_read. it has to hold last previous packet data. */
    int prev_ts;
    int prev_stream_number;
    
    union {
	struct rmff_header_t *rmff_header;
	struct asf_headerinfo_t *asf_headerinfo;
    };
};


struct rtsp_header_t {
    char *protocol;
    char *method;
    char *uri;
    unsigned int status_code;
    char *reason_phrase;
    unsigned int rtsp_minor_version;
    unsigned int content_length;
  

    /* field variables */
    struct rtsp_field_t *first_field;
    struct rtsp_field_t *last_field;
    unsigned int field_nb;
    char *field_search;
    struct rtsp_field_t *field_search_pos;
  
    /* body variables */
    char *body;
    size_t body_len;                 /* NOT include '\0' at the end. */
    char *buffer;
    size_t buffer_len;               /* NOT include '\0' at the end. */
    unsigned int is_parsed;
  
};



struct rtsp_header_t *new_rtsp_header(void);
void free_rtsp_header(struct rtsp_header_t *h);
char *rtsp_get_next_field(struct rtsp_header_t *rtsp_hdr);
char *rtsp_get_field(struct rtsp_header_t *rtsp_hdr, const char *field_name);
void rtsp_set_field(struct rtsp_header_t *rtsp_hdr, const char *field_name);

void rtsp_set_uri(struct rtsp_header_t *rtsp_hdr,const char *uri);
void rtsp_set_method(struct rtsp_header_t *rtsp_hdr, const char *method);
char *rtsp_build_request(struct rtsp_header_t *rtsp_hdr);

int rtsp_is_entire_header(struct rtsp_header_t *rtsp_hdr);
int rtsp_response_parse(struct rtsp_header_t *rtsp_hdr);
struct stream_t *rtsp_streaming_init();
int rtsp_streaming_read(struct stream_t *stream,
			uint8_t *buffer, size_t buffer_size);
void rtsp_streaming_close(struct stream_t *stream);

struct rtsp_header_t *new_rtsp_header_with_standard_fields(struct rtsp_ctrl_t *rtsp_ctrl);
int rtsp_send_request_and_free(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr);
int is_rtsp_response_ok(int status_code);
int rtsp_recv_header_ignore_message(struct stream_t *stream);
int rtsp_ignore_data_after_header(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr);
int rtsp_recv_header(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr);

int rtsp_set_standard_fields(struct rtsp_ctrl_t *rtsp_ctrl,
			     struct rtsp_header_t *rtsp_hdr);

int rtsp_200ok(struct stream_t *stream,int cseq,char *session);

char *rtsp_request_options(struct rtsp_header_t *rtsp_hdr,char *request_uri);
char *rtsp_request_describe(struct rtsp_header_t *rtsp_hdr,char *request_uri);
char *rtsp_request_set_parameter(struct rtsp_header_t *rtsp_hdr,char *request_uri);
char *rtsp_request_get_parameter(struct rtsp_header_t *rtsp_hdr,char *request_uri);
char *rtsp_request_setup(struct rtsp_header_t *rtsp_hdr,char *request_uri);
char *rtsp_request_play(struct rtsp_header_t *rtsp_hdr,char *request_uri);
char *rtsp_request_teardown(struct rtsp_header_t *rtsp_hdr,char *request_uri);


int rtsp_send_request(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr);
int rtsp_recv_header(struct stream_t *stream, struct rtsp_header_t *rtsp_hdr);
int rtsp_make_mrl(struct rtsp_ctrl_t *rtsp_ctrl,char *host,int port,char *filepath);


char *rtsp_make_range_from_timestamp(uint32_t range_ts);
int rtsp_npt_time_valid(const char *str,char **reason_ret);
int rtsp_npt_range_valid(const char *str,char **reason_ret);
char *rtsp_time_to_npt_time(const char *str,char **reason_ret);
char *rtsp_range_to_npt_range(const char *str,char **reason_ret);


void rtsp_set_range_field(struct rtsp_header_t *rtsp_hdr,const char *rangestr);
void rtsp_set_speed_field(struct rtsp_header_t *rtsp_hdr,const char *speedstr);

#endif /* __RTSP_H__ */