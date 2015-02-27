/***********************************************************************
 *    network.h: network related utility functions
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * network non-related stuff should go msdllib.h
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



#ifndef __NETWORK_H__
#define __NETWORK_H__

#include <stdint.h>
#include "url.h"


/*
 * default ports. MMSH is MMS over HTTP, so HTTP port is used.
 */
enum {
    HTTP_PORT = 80,
    HTTP_PROXY_PORT = 8080,
    MMS_PORT  = 1755,
    RTSP_PORT = 554,
    FTP_PORT  = 21,
};



/*
 * protocol type listing
 */
enum {
    UNKNOWN_PROTOCOL = 0, /* unknown protocol                    */
    MMST,             /* mms over tcp                        */
    MMSH,             /* mms over http                       */
    HTTP,             /* http                                */
    RTSP,             /* rtsp (real time streaming protocol) */
    FTP,              /* ftp                                 */
    RTSP_REAL,        /* rtsp - real /helix                  */
    RTSP_WMS,         /* rtsp - windows media server         */
};



/*
 * buffer sizes. don't touch BUF_SIZE !!!
 */
enum {
    BUF_SIZE = 1024000,    /* buffer for netsock->buffer, write_buffer */
    BUFSIZE_4_DL = 10240, /* 10kb                                     */
    BUFSIZE_1K = 1024,
};



enum {
    INT_MAX_BANDWIDTH = 0x7fffffff, /* INT MAX as maximum bandwidth */
};



enum {
    SERVER_CONNECT_TIMEOUT  = 12, /* 12 sec    */
    GET_DATA_TIMEOUT = 180,       /* 3 Minutes */
    XRECV_TIMEOUT = 180,
};


struct serverinfo_t {
    char *connect_host; /* points to host or proxy_host,the host which msdl directory connects to */
    int   connect_port;

    char *host;
    int   port;

    char *proxy_host;
    int   proxy_port;
};



struct netsock_t {
    int sock;                 /* socket to get stream from                  */
    
    uint8_t *buffer;          /* buffer for data which read from network    */
    uint32_t buffer_size;     /* size of malloc() [physical size of buffer] */
    uint32_t data_len;        /* how many bytes to be read from now         */
    uint32_t buffer_pos;      /* read by here so far                        */
};


struct resumeinfo_t {
    int resume_req_success;       /* seek request for resume succeeded  */
    uint64_t resume_start_offset; /* start writing to file from here    */
};



/*
 * specifies stream.
 */
struct stream_t {
    struct serverinfo_t *serverinfo;   /* connection information     */ /* new */
    struct netsock_t *netsock;         /* socket and network buffer  */ /* new */
    struct stream_ctrl_t *stream_ctrl; /* status of the stream       */ /* new */
    struct resumeinfo_t *resumeinfo;   /* information for resuming   */ /* new */
    char *localfile;                   /* name of local file         */ /* new */
    
    struct download_opts_t *dlopts;    /* download options           */ /* pointer */
    struct url_t *url;                 /* url to download.           */ /* pointer */


    
    /* downloading functions */
    int (*start)(struct stream_t *);                   /* stream starter */
    int (*read)(struct stream_t *, uint8_t *,size_t);  /* stream reader  */
    void (*close)(struct stream_t *);                  /* stream closer  */
};



/*
 * streaming status which goes to steram_ctrl->status
 */
enum TransportProtocolStateEx{
    STREAMING_HANDSHAKING,       /* handshaking, doing setup                */
    STREAMING_DOWNLOADING,       /* downloading stream                      */
    STREAMING_FINISHED,          /* end of steam packet received, etc.      */
    STREAMING_REWIND,            /* rewind before write data                */
    STREAMING_RESUME_BUFFERING,  /* buffering to seek to undownloaded point */
    STREAMING_NO_NEED_TO_DOWNLOAD,  /* file already downloaded              */
    STREAMING_OTHER_PROTOCOL,    /* use other protocol to download this url */
    STREAMING_REDIRECTED,        /* has to download from different location */
	STREAMING_FAILED
};



/*
 * protocol unspecific datas.
 */
struct stream_ctrl_t {
    int protocol;               /* downloading protocol                       */

    int packet_length;          /* length of each packet for this stream.     */

    uint64_t file_size;         /* size of downloading file                   */
  
    int total_packets;          /* number of packets to be received.          */
    int packet_count;           /* how many packet received                   */
    
    uint8_t *write_buffer;      /* data to write to file (buffer)             */
    uint32_t write_buffer_size; /* malloc()ed size                            */
    uint32_t write_data_len;    /* how many bytes to be written from now      */
    uint32_t write_pos;         /* written by here so far                     */

    unsigned int bandwidth;     /* bandwidth                                  */
    int status;                 /* playing status                             */
    int retry_protocol;         /* protocol to try again                      */
    char *retry_urlstr;         /* url to try again                           */
    
    union {
	void *data;               /* protocol specific datas goes here          */
	struct mmst_ctrl_t *mmst_ctrl;  /* easy access for mmst_ctrl_t          */
	struct mmsh_ctrl_t *mmsh_ctrl;  /* same as above.                       */
	struct http_ctrl_t *http_ctrl;  /* same as above.                       */
	struct rtsp_ctrl_t *rtsp_ctrl;  /* same                                 */
	struct ftp_ctrl_t  *ftp_ctrl;   /* same                                 */
    };
};



struct stream_t *new_stream_t(void);
void free_stream_t(struct stream_t *st);

struct stream_t *streaming_init_common();
void streaming_close_common(struct stream_t *stream);

struct netsock_t *new_netsock_t(void);
void free_netsock_t(struct netsock_t *ns);

struct serverinfo_t *new_serverinfo_t(void);
void free_serverinfo_t(struct serverinfo_t *si);

struct stream_ctrl_t *new_stream_ctrl_t(void);
void free_stream_ctrl_t(struct stream_ctrl_t *sc);

struct resumeinfo_t *new_resumeinfo_t(void);
void free_resumeinfo_t(struct resumeinfo_t *ri);

void set_serverinfo(struct serverinfo_t *serverinfo,
		    char *target_host,int target_port,
		    char *proxy_host,int proxy_port,int protocol_default_port);
void set_serverinfo_by_proxy_string(struct serverinfo_t *serverinfo,
				    char *host,int port,char *proxy_string,
				    int protocol_default_port,int proxy_default_port);

char *create_time_str_from_many_formats(const char *str,char **reason_ret);
int speed_valid_and_guess(const char *str,int *guessed_speed,char **reason_ret);
char *make_byterange_from_filesize(uint64_t filesize);
int protocol_type_from_string(char *protocol);

int sock_check_data(int sock,const double timeout);

int server_connect(const char *servername,const int port);
int server_connect_with_timeout(const char *servername,const int port,const double timeout);

int waiting_socket(int family,int port);
int accept_connection(int wait_sock);

int xrecv(int sock,void *buf,size_t count);
int xsend(int sock,void *buf,size_t count);

int stream_check_data(struct stream_t *stream,const double timeout);
int get_data(int sock, void *buf, size_t count);
int read_data(struct stream_t *stream, void *buffer, size_t size);
int recv_data(struct stream_t *stream, void *buffer, size_t max);
int stream_data_push_back(struct stream_t *stream,void *buffer,int size);

const char* inetntop(int af, const void* src, char* dst, int cnt);

#endif /* __NETWORK_H__ */
