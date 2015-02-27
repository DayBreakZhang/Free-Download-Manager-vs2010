/***********************************************************************
 *    network.c: network related utility functions
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * network-unrelated functions goes to msdllib.c
 *
 * struct stream_t is a stream describer, and 
 * stream_ctrl is stream controller, actually works as a
 * network buffer and wrapper for all supported protocols.
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


#include "stdafx.h"
#include <fcntl.h>

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "snprintf.h"

/*#ifndef INET6_ADDRSTRLEN
#define INET6_ADDRSTRLEN 46
#endif*/

#define F_GETFL         3
#define F_SETFL         4
#define O_NONBLOCK      00004000


int fcntl( int fd, int cmd, unsigned param )
{
	unsigned long	val;

	if ( cmd == F_SETFL && param == O_NONBLOCK )
	{
		val = 1;
		if ( ioctlsocket( fd, FIONBIO, &val ) == 0 )
			return 0;
	}

	return -1;
}

/*
 * setup stream_t
 */
struct stream_t *new_stream_t(void)
{
    struct stream_t *st = (struct stream_t *)xmalloc(sizeof(struct stream_t));
    return st;
}



/*
 * free stream_t
 */
void free_stream_t(struct stream_t *st)
{
    if(!st) return;
    
    free(st);
}


struct stream_t *streaming_init_common()
{
    struct stream_t *stream = new_stream_t();
    
    stream->serverinfo = new_serverinfo_t();
    stream->netsock = new_netsock_t();
    stream->stream_ctrl = new_stream_ctrl_t();
    stream->resumeinfo = new_resumeinfo_t();

    return stream;
}


void streaming_close_common(struct stream_t *stream)
{
    free(stream->localfile);
    free_resumeinfo_t(stream->resumeinfo);
    free_stream_ctrl_t(stream->stream_ctrl);
    free_netsock_t(stream->netsock);
    free_serverinfo_t(stream->serverinfo);
    free_stream_t(stream);
}


/*
 * setup buffer, setup URL.
 */
struct stream_ctrl_t *new_stream_ctrl_t(void)
{
  
    struct stream_ctrl_t *sc =
	(struct stream_ctrl_t *)xmalloc(sizeof(struct stream_ctrl_t));

    sc->write_buffer = (uint8_t *)xmalloc(BUF_SIZE);
    sc->write_buffer_size = BUF_SIZE;
    
    return sc;
}



struct serverinfo_t *new_serverinfo_t(void)
{
    struct serverinfo_t *si = 
	(struct serverinfo_t *)xmalloc(sizeof(struct serverinfo_t));

    return si;
}


void free_serverinfo_t(struct serverinfo_t *si)
{
    if(!si) return;

    si->connect_host = NULL;
    if(si->host)       free(si->host);
    if(si->proxy_host) free(si->proxy_host);
    free(si);
}



struct netsock_t *new_netsock_t(void)
{
    struct netsock_t *ns = 
	(struct netsock_t *)xmalloc(sizeof(struct netsock_t));
    ns->buffer = (uint8_t *)xmalloc(BUF_SIZE);
    ns->buffer_size = BUF_SIZE;
    
    return ns;
}


void free_netsock_t(struct netsock_t *ns)
{
    if(!ns) return;

    if(ns->buffer) free(ns->buffer);
    free(ns);
}


struct resumeinfo_t *new_resumeinfo_t(void)
{
    struct resumeinfo_t *ri =
	(struct resumeinfo_t *)xmalloc(sizeof(struct resumeinfo_t));
    ri->resume_req_success  = 0;
    ri->resume_start_offset = 0;

    return ri;
}


void free_resumeinfo_t(struct resumeinfo_t *ri)
{
    free(ri);
}



/*
 * free stream_ctrl;
 */
void free_stream_ctrl_t(struct stream_ctrl_t *sc)
{
    if(!sc) return;
    
    /* if(sc->url) free_url_t(sc->url); not malloc()ed in new_stream_ctrl_t,
       thus, free this outside free_stream_ctrl_t().*/
    if(sc->write_buffer) free(sc->write_buffer);
    if(sc->retry_urlstr)   free(sc->retry_urlstr);

    free(sc);
}



/*
 * set server information
 */
void set_serverinfo(struct serverinfo_t *serverinfo,
		    char *target_host,int target_port,
		    char *proxy_host,int proxy_port,int protocol_default_port)
{
    if(!serverinfo) {
	display(MSDL_ERR,"set_serverinfo: argument NULL\n");
	return;
    }
    
    serverinfo->host = strdup(target_host);
    serverinfo->port = (target_port) ? target_port : protocol_default_port;
    
    serverinfo->connect_host = serverinfo->host;
    serverinfo->connect_port = serverinfo->port;

    if(proxy_host) {
	serverinfo->proxy_host = strdup(proxy_host);
	serverinfo->proxy_port = proxy_port;

	serverinfo->connect_host = serverinfo->proxy_host; /* reset host to connect() */
	serverinfo->connect_port = serverinfo->proxy_port; /* reset port to connect() */
    }
    else {
	serverinfo->proxy_host = NULL;
	serverinfo->proxy_port = 0;
    }
}



void set_serverinfo_by_proxy_string(struct serverinfo_t *serverinfo,
				    char *host,int port,char *proxy_string,
				    int protocol_default_port,int proxy_default_port)
{
    char *proxy_str = NULL;
    int proxy_port = 0;

    if(proxy_string) {
	char *port_str = NULL;
	proxy_str = strdup(proxy_string);
	port_str = strchr(proxy_str,':');
	
	if(!port_str) {
	    display(MSDL_NOR,"proxy port not specified, assuming %d\n",proxy_default_port);
	    proxy_port = proxy_default_port;
	}
	else {
	    *port_str = '\0';/* separate proxy_str*/
	    port_str++;
	    proxy_port = atoi(port_str);
	    if(!proxy_port) {
		proxy_port = proxy_default_port;
	    }
	}
    }
    
    set_serverinfo(serverinfo,host,port,proxy_str,proxy_port,protocol_default_port);
    
    if(proxy_str) free(proxy_str);
}



/*
 * str: [ npt-hh ":" npt-mm ":" ] npt-ss [ "." *DIGIT ] | [00h][00m][00s] ["." *DIGIT]
 * create 28983 like string from many formats like "8h3m3s" or "8:3:3"
 *
 * return value:    NULL: really inacceptable, such as "0.0a1"
 *              npt-time: rtsp npt valid string (malloc)
 */
char *create_time_str_from_many_formats(const char *str,char **reason_ret)
{
    enum {
	SEC = 0,
	MIN,
	HOUR,
	DAY,   /* joke */
	YEAR,  /* joke */
	NUM_COLS,
    };
    
    enum {
	NOT_SEPARATED = 0,
	COLON_SEPARATED,
	CHAR_SEPARATED,
    };

    int i = 0;
    int j = 0; /* only to slide sep_time */
    int len = strlen(str);
    int sep_time_filled[NUM_COLS] = {0};
    uint64_t sep_time[NUM_COLS] = {0}; /* separated time */
    int separated_way = NOT_SEPARATED;
    int met_colon = 0;
    uint64_t value = 0;
    int npt_acceptable = 1;
    char *str_after_dot = "\0";        /* points to empty string by default. includes '.' itself */
    char *npt_time = NULL;
    char *reason = NULL;

    
    value = 0;
    met_colon = 0;
    npt_acceptable = 1;
    for(i = 0 ; (i < len) && npt_acceptable ; i++) {
	if('0' <= str[i] && str[i] <= '9') {
	    value *= 10;
	    value += str[i] - '0';
	}
	else if(str[i] == '.') { /* just seconds, like 3323.3 */
	    char *dot_pos = (char *)str + i;
	    if((i == 0) || (i == len - 1)) { /* dot was at the beginning or end of string */
		reason = "\'.\' at the beginning or end of string";
		npt_acceptable = 0;
		break;
	    }
	    i++;
	    for(; i < len ; i++) {
		if(('0' <= str[i]) && (str[i] <= '9')) {
		    continue;
		}
		else {
		    reason = "invalid char after \'.\'";
		    npt_acceptable = 0;
		    break;
		}
	    }
	    /* string after dot was valid */
	    if(npt_acceptable) {
		str_after_dot = dot_pos;
	    }
	}
	else if(str[i] == ':') {     /* colon can be a separator, like 3:3:2 */
	    if(separated_way == CHAR_SEPARATED) {
		reason = "confusing time separator";
		npt_acceptable = 0;
		break;
	    }
	    
	    separated_way = COLON_SEPARATED;
	    if(met_colon < NUM_COLS - 1) { /* separator = column = 1 */
		
		for(j = NUM_COLS - 1; j ; j--) {
		    sep_time[j] = sep_time[j - 1]; /* slide */
		}
		sep_time[0] = value;
		
		met_colon++;
		value = 0; /* reset value */
		continue;
	    }
	    else { /* too many colons, return */
		reason = "too many colons";
		npt_acceptable = 0;
		break;
	    }
	}
	else if(tolower(str[i]) == 'h' || tolower(str[i]) == 'm' || tolower(str[i]) == 's' ||
		tolower(str[i]) == 'y'|| tolower(str[i]) == 'd') { /* hour, minute, stuff */
	    if(separated_way == COLON_SEPARATED) {
		reason = "confusing time separator";
		npt_acceptable = 0;
		break;
	    }
	    separated_way = CHAR_SEPARATED;
	    
	    switch(tolower(str[i])) {
	    case 'y':
		if(sep_time_filled[YEAR]) {
		    reason = "year already specified";
		    npt_acceptable = 0;
		    break;
		}
		sep_time[YEAR] = value;
		sep_time_filled[YEAR] = 1;
		break;
	    case 'd':
		if(sep_time_filled[DAY]) {
		    reason = "day already specified";
		    npt_acceptable = 0;
		    break;
		}
		sep_time[DAY] = value;
		sep_time_filled[DAY] = 1;
		break;
	    case 'h':
		if(sep_time_filled[HOUR]) {
		    reason = "hour already specified";
		    npt_acceptable = 0;
		    break;
		}
		sep_time[HOUR] = value;
		sep_time_filled[HOUR] = 1;
		break;
	    case 'm':
		if(sep_time_filled[MIN]) {
		    reason = "minute already specified";
		    npt_acceptable = 0;
		    break;
		}
		sep_time[MIN] = value;
		sep_time_filled[MIN] = 1;
		break;
	    case 's':
		if(sep_time_filled[SEC]) {
		    reason = "second already specified";
		    npt_acceptable = 0;
		    break;
		}
		sep_time[SEC] = value;
		sep_time_filled[SEC] = 1;
		break;
	    default:
		break;
	    }

	    value = 0;
	}
	else {     /* invalid chraracter */
	    reason = "invalid character";
	    npt_acceptable = 0;
	    break;
	}
    }
    if(separated_way != CHAR_SEPARATED) {
	for(j = NUM_COLS - 1; j ; j--) {
	    sep_time[j] = sep_time[j - 1]; /* slide */
	}
	sep_time[0] = value;
    }
    else { /* CHAR_SEPARATED */
	if(!sep_time_filled[SEC]) {
	    sep_time[0] = value;
	}
	else if(value){ /* has some value */
	    reason = "second already specified";
	    npt_acceptable = 0;
	}
    }
    
    
    if(!npt_acceptable) {
	if(reason_ret) {
	    *reason_ret = reason;
	}
	return NULL;
    }
    else {
	uint64_t sec = 0;
	npt_time = (char *)xmalloc(BUFSIZE_1K + strlen(str_after_dot));
	/* hhmmss format */
	/*
	  sec   = sep_time[SEC] % 60;
	  carry = sep_time[SEC] / 60;
	  min   = (sep_time[MIN] + carry) % 60;
	  carry = (sep_time[min] + carry) / 60;
	  hour = (sep_time[YEAR] * 365 + sep_time[DAY]) * 24 + sep_time[HOUR] + carry;
	  snprintf(npt_time,BUFSIZE_1K - 1 + strlen(str_after_dot),"%llu:%d:%d.%s",
	  (long long unsigned int)hour,(int)min,(int)sec,str_after_dot);
	*/
	
	/* sec format */
	sec = (((sep_time[YEAR] * 365 + sep_time[DAY]) * 24 + sep_time[HOUR]) * 60 +
	    sep_time[MIN]) * 60 + sep_time[SEC];
	snprintf(npt_time,BUFSIZE_1K - 1 + strlen(str_after_dot),"%llu%s",
		 (long long unsigned int)sec,str_after_dot);
	
	reason = "";
	if(reason_ret) {
	    *reason_ret = reason;
	}

	return npt_time;
    }
    return NULL;
}


/*
 * return true if Speed string was valid
 * return value ... 1: valid   0: not valid
 *   reason_ret ... "": no error   some string: error reason
 */
int speed_valid_and_guess(const char *str,int *guessed_speed,char **reason_ret)
{
    /* 1*DIGIT [ "." *DIGIT ] */
    int i = 0;
    int len = strlen(str);
    int speed_valid = 1;
    char *reason = NULL;
    int value = 0;

    value = 0;
    speed_valid = 1;
    for(i = 0 ; i < len ; i++) {
	if('0' <= str[i] && str[i] <= '9') {
	    value *= 10;
	    value += str[i] - '0';
	    continue;
	}
	else if(str[i] == '.') {
	    if(i == 0) {
		reason = "\'.\' at the beginning of speed string";
		speed_valid = 0;
		break;
	    }
	    i++;
	    for(; i < len ; i++) {
		if(('0' <= str[i]) && (str[i] <= '9')) {
		    continue;
		}
		else {
		    reason = "invalid char after \'.\'";
		    speed_valid = 0;
		    break;
		}
	    }
	}
	else {
	    reason = "invalid character";
	    speed_valid = 0;
	    break;
	}
    }


    if(speed_valid) {
	reason = "";
	if(reason_ret) {
	    *reason_ret = reason;
	}
	/* do not care about guessed_speed */
	return speed_valid;
    }

    /* invalid */
    if(guessed_speed) {
	*guessed_speed = value;
    }
    if(reason_ret) {
	*reason_ret = reason;
    }
    return 0;
}



char *make_byterange_from_filesize(uint64_t filesize)
{
    char *rangestr = (char *)xmalloc(256);
    snprintf(rangestr,255,"%llu-",(long long unsigned int)filesize);
    return rangestr;
}



/*
 * (url_t)->protocol_type.
 * sets UNKNONW_PROTOCOL if protocol string not supported.
 */
int protocol_type_from_string(char *protocol)
{
    int protocol_type = UNKNOWN_PROTOCOL;
    
    if(!strcmp(protocol,"mms") || 
       !strcmp(protocol,"mmst")) {
	protocol_type = MMST;
    }
    else if(!strcmp(protocol,"mmsh")) {
	protocol_type = MMSH;
    }
    else if(!strcmp(protocol,"http")) {
	protocol_type = HTTP;
    }
    else if(!strcmp(protocol,"rtsp")) {
	protocol_type = RTSP;
    }
    else if(!strcmp(protocol,"ftp")) {
	protocol_type = FTP;
    }
    else {
	protocol_type = UNKNOWN_PROTOCOL;
    }
  
    return protocol_type;
}

/*
 * use default timeout value.
 */
int server_connect(const char *servername,const int port)
{
    return (server_connect_with_timeout(servername,port,SERVER_CONNECT_TIMEOUT));
}

const char* inetntop(int af, const void* src, char* dst, int cnt)
{
	struct sockaddr_in srcaddr;

	memset(&srcaddr, 0, sizeof(struct sockaddr_in));
	memcpy(&(srcaddr.sin_addr), src, sizeof(srcaddr.sin_addr));

	srcaddr.sin_family = af;
	if (WSAAddressToString((struct sockaddr*) &srcaddr, sizeof(struct sockaddr_in), 0, (LPWSTR)dst, (LPDWORD) &cnt) != 0) {
		DWORD rv = WSAGetLastError();
		printf("WSAAddressToString() : %d\n",rv);
		return NULL;
	}
	return dst;
}

/*
 * connect to 'servername' with 'port'.
 *           return value :    socket number ... success
 *                             -1            ... error
 */
int server_connect_with_timeout(const char *servername,const int port,const double timeout)
{
    
    int sock_server = 0;
    int ret;
    
    char hoststr[INET6_ADDRSTRLEN + 4]; /* IPv4 / IPv6 dual */
    char portstr[8];
    fd_set set;
    struct addrinfo hints,*result = NULL;
    
    struct timeval tv;    
    int try_count = 0;
    

    if(!servername) {
	goto failed;
    }
    
    if(0 <= port && port <= 0xffff) { /* valid params  */
	snprintf(portstr,7,"%d",port);
    }
    else {
	display(MSDL_ERR,"port number %d not valid",port);
	goto failed;
    }
    
    memset(&hints,0,sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    
    ret = getaddrinfo(servername,portstr,&hints,&result);
    if(ret != 0) {
	display(MSDL_ERR,"Host [ %s ] not found. (%s)\n",servername,gai_strerror(ret));
	goto failed;
    }
    

    if(result->ai_family == AF_INET6) {
	inetntop(result->ai_family,
		  &((struct sockaddr_in6 *)result->ai_addr)->sin6_addr,
		  hoststr,
		  sizeof(hoststr));
    }
    else { /* default IPv4 */
	inetntop(result->ai_family,
		  &((struct sockaddr_in *)result->ai_addr)->sin_addr,
		  hoststr,
		  sizeof(hoststr));
    }
    
    /* display host:ports */
    display(MSDL_NOR,"Host: [ %s:%s ]  ",hoststr,portstr);
    
    
    sock_server = socket(result->ai_family,result->ai_socktype,result->ai_protocol);
  
    if(sock_server == -1) {
	display(MSDL_ERR,"socket() error");
	return -1;
    }
    
    /* Turn the socket to non-blocking socket, so we can timeout. */
    fcntl(sock_server,F_SETFL,fcntl(sock_server,F_GETFL, O_NONBLOCK) | O_NONBLOCK);
    
    if(connect(sock_server,result->ai_addr,result->ai_addrlen) == -1) {
	/* failed not because it was non-blocking */
	if(errno != EINPROGRESS) {
	    display(MSDL_ERR,"connect() failed");
	    goto failed;
	}
    }
  
    for(;;) { /* display "connect ... " <- dots */
	
	tv.tv_sec  = (long)(timeout / 5);
	tv.tv_usec = (long)(((timeout / 5) - (long)(timeout /5)) * 1000000);

	FD_ZERO(&set);
	FD_SET(sock_server,&set);
	
	ret = select(sock_server+1,NULL,&set,NULL,&tv);

	if(ret < 0) { /* select failed! */
	    display(MSDL_ERR,"select() failed");
	    goto failed;
	}
	else if(ret > 0) break;
	else if(try_count >= 4) { /* repeat tv.tv_sec 5 times */
	    display(MSDL_ERR,"timeout!\n");
	    goto failed;
	}
    
	display(MSDL_NOR,".");
	try_count++;
    }
  
    /* Turn the socket to blocking, as we don't need it. */
    fcntl(sock_server, F_SETFL, fcntl(sock_server,F_GETFL, O_NONBLOCK) & ~O_NONBLOCK);
  
    display(MSDL_NOR,"  connected!\n");
    
    freeaddrinfo(result);
    return sock_server;
    
    /* failure */
  failed:
    if(sock_server) closesocket(sock_server);
    if(result) freeaddrinfo(result);
    return -1;
}




/*
 * prepare listning socket opening 'port'.
 * protocol family can be specified by 'family'
 *
 *           return value :       sock ... success
 *                                  -1 ... failure
 */
int waiting_socket(int family,int port)
{
    int sock;
    int ret;
    char portstr[8];
    struct addrinfo hints,*result = NULL;
    
    if(port < 0 || 0xffff < port) {
	display(MSDL_ERR,"internal: invalid port number\n");
	goto failed;
    }
    
    memset(portstr,0,8);
    snprintf(portstr,7,"%d",port);
    

    memset(&hints,0,sizeof(hints));
    hints.ai_family = family;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    
    ret = getaddrinfo(NULL,portstr,&hints,&result);
    if(ret != 0) {
	perror("getaddrinfo() failed");
	goto failed;
    }

    sock = socket(result->ai_family,result->ai_socktype,result->ai_protocol);
    if(sock < 0) {
	perror("socket() failed");
	goto failed;
    }
    

    ret = bind(sock,(struct sockaddr *)result->ai_addr,result->ai_addrlen);
    if(ret < 0) {
	perror("bind() failed");
	goto failed;
    }
    

    ret = listen(sock,1);
    if(ret < 0) {
	perror("listen() failed");
	goto failed;
    }

    freeaddrinfo(result);
    return sock;
    
  failed:
    if(result) freeaddrinfo(result);
    return -1;
}



/*
 * accept connectoin from client.
 * return value :         sock .. success
 *                          -1 .. failure
 */
int accept_connection(int wait_sock)
{
    struct sockaddr_storage ss;
    socklen_t sslen;
    int sock;
    int ret;
    
    ret = sock_check_data(wait_sock,15);
    if(ret <= 0) {
	return -1;
    }
    
    sslen = sizeof(ss);
    sock = accept(wait_sock,(struct sockaddr *)&ss,&sslen);
    if(sock == -1) {
	perror("accept() failed");
	return -1;
    }

    return sock;
}



/*
 * this is wrapper for recv, and has timeout.
 * return value:            length --> success
 *                              -1 --> error/timeout
 *                               0 --> eof
 */
int xrecv(int sock,void *buf,size_t count)
{
    fd_set fds;
    struct timeval tv;
    int retval;
  
    tv.tv_sec  = XRECV_TIMEOUT;
    tv.tv_usec = 0;
  
    FD_ZERO(&fds);
    FD_SET(sock,&fds);

    retval = select(sock + 1,&fds,NULL,NULL,&tv);
    if(retval == -1) {  /* select() Error (system call error) */
	perror("select() failed\n");
	goto failed;
    }
    else if(!retval) {  /* No data arrived (error)*/
	display(MSDL_ERR,"timeout!! could not receive data\n");
	goto failed;
    }

    retval = recv(sock,(char *)buf,count,0);
  
    if(retval < 0) {       /* recv()   Error (system call error) */
	perror("recv() failed\n");
	goto failed;
    }

    return retval;
  
  failed:
    return -1;
}



/*
 * send() wrapper
 */
int xsend(int sock,void *buf,size_t count)
{
    /* ignore SIGPIPE, this means if the server has closed the connection, ignore. ret will be < 0 anyways */
    /*int ret = send(sock,buf,count,MSG_NOSIGNAL);*/
    int ret = send(sock,(const char *)buf,count,0);
    return ret;
}



int sock_check_data(int sock,const double timeout)
{

    fd_set fds;
    struct timeval tv;
    int ret;
    
    FD_ZERO(&fds);
    FD_SET(sock,&fds);

    tv.tv_sec  = (long)timeout;
    tv.tv_usec = (long)((timeout - (long)timeout) * 1000000);
    
    ret = select(sock + 1,&fds,NULL,NULL,&tv);

    if(ret == -1) {
	perror("stream_check_data: select() failed");
    }
    
    return ret;
}



int stream_check_data(struct stream_t *stream,const double timeout)
{
    if(stream->netsock->data_len) {
	return 1;
    }
    
    return sock_check_data(stream->netsock->sock,timeout);
}



/*
 * recv count bytes of data from sock to buf.
 * this is only used when count bytes of data are
 * supposed to come from sock.
 * this function must be used when 'count' bytes are guaranteed
 * to be received.
 *          return value: length --> success.
 *                        0      --> eof
 *                        -1     --> timeout or error (fatal)
 */
int get_data(int sock,void *buf,size_t count)
{
    int len;
    size_t total = 0;
  
    while(total < count) { /* more data to recv. */
    
	len = xrecv(sock,(uint8_t *)buf + total,count - total);
    
	if(len < 0) {       /* Error. timeout, syscall error */
	    goto failed;
	}
	else if(len == 0) { /* EOF */
	    display(MSDL_ERR,"met EOF when %d bytes are to come\n",count);
	    goto meteof;
	}
    
	total += len;
    }
  
    return total;
  
  meteof:
    return 0;
  
  failed:
    return -1;
}



/*
 * read 'size' bytes from *resources*. (read JUST size bytes, otherwise fails)
 *
 *       *resources* are : [in this order]
 *                    1. netsock->buffer (data which came with http header)
 *                    2. netsock->sock   (network)
 *
 *               return value : size which read.
 *                              -1 ... error/timeout
 */
int read_data(struct stream_t *stream, void *buffer, size_t size)
{
    struct netsock_t *netsock = stream->netsock;
    int len = 0; /* how many bytes are stored in 'buffer' */

    /*
      printf("read_data size = %d   netsock->data_len = %d,"
             " netsock->buffer_pos = %d\n",
	     size,netsock->data_len, netsock->buffer_pos);
    */

    if(netsock->data_len) {
	/* there is a data to read in netsock->buffer */
    
	len = (size < netsock->data_len)
	    ? size : netsock->data_len; /* smaller */
    
	memcpy((uint8_t *)buffer,netsock->buffer + netsock->buffer_pos,len);
    
	netsock->buffer_pos += len;
	netsock->data_len -= len;
    
	if(netsock->data_len == 0) {
	    netsock->buffer_pos = 0;
	}
    }
    if(len < size) {
	int ret = get_data(netsock->sock,(uint8_t *)buffer + len, size - len);
	if(ret < 0) { /* get_data mets timeout/error */
	    return -1;
	}
	else {
	    len += ret;
	}
    }
    return len;
}



/*
 * different from read_data, this function's 3ed argument is 
 * max byte to read from stream.
 * return value:             len ... bytes stored in buffer
 *                             0 ... 
 *                            -1 ... timeout
 */
int recv_data(struct stream_t *stream,void *buffer,size_t max)
{
    struct netsock_t *netsock = stream->netsock;
    int len; /* how many bytes are stored in 'buffer' */
    int ret;
  
    if((len = netsock->data_len)) {
	/* there is a data to read in netsock->buffer */
    
	len = (max < len) ? max : len; /* smaller */
    
	memcpy((uint8_t *)buffer,netsock->buffer + netsock->buffer_pos,len);
    
	netsock->buffer_pos += len;
	netsock->data_len -= len;
    
	if(netsock->data_len == 0) {
	    netsock->buffer_pos = 0;
	}
    }
  
    /* still network stream can be read. */
    if(len < max) {
	if(!len || sock_check_data(netsock->sock,0)) {/* just check there are some data now */
	    ret = xrecv(netsock->sock,(uint8_t *)buffer + len,max - len);
	    if(ret < 0) {
		return -1;
	    }
	    else {
		len += ret;
		/*
		  when sock was shut down by server and nothing was in buffer,
		  len == 0 and ret == 0 so return 0, this is OK.
		 */
	    }
	}
    }
    return len;
}



/*
 * push data to netsock->buffer so that the data can be read later
 */
int stream_data_push_back(struct stream_t *stream,void *buffer,int size)
{
    struct netsock_t *netsock = stream->netsock;
  
    if(netsock->data_len) {
	memmove(netsock->buffer + netsock->buffer_pos + size,
		netsock->buffer + netsock->buffer_pos,
		netsock->data_len);

    }
    memcpy(netsock->buffer + netsock->buffer_pos,buffer,size);
    netsock->data_len += size;  
  
    return (netsock->data_len);
}


