/***********************************************************************
 *    http.c: for downloading via http (Hyper Text Transfer Protocol)
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
 * (from MPlayer-1.0rc2/stream/http.c)
 */

/* 
 * HTTP Helper
 * by Bertrand Baudet <bertrand_baudet@yahoo.com>
 * (C) 2001, MPlayer team.
 */


#include "stdafx.h"

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "http.h"
#include "snprintf.h"

const char http_useragent[] = "User-Agent: MSDL";



/*
 * new_http_header : create new HTTP header
 */
struct http_header_t *new_http_header(void)
{
    struct http_header_t *hdr;
    hdr = (struct http_header_t *)xmalloc(sizeof(struct http_header_t));
    return hdr;
}



/*
 * free HTTP header
 */
void free_http_header(struct http_header_t *h)
{
    struct http_field_t *field, *prev;
  
    if(h == NULL) return; /* http_hdr is not malloc()ed yet. */
  
    if(h->protocol) free(h->protocol);
    if(h->method) free(h->method);
    if(h->uri) free(h->uri);
    if(h->reason_phrase) free(h->reason_phrase);
    if(h->field_search) free(h->field_search);
    if(h->buffer) free(h->buffer);
    field = h->first_field;

    for(field = h->first_field; field ; ) {
	if(field->field_name)
	    free(field->field_name);
	prev = field;
	field = field->next;
	free(prev);
    }
    free(h);
}



/*
 * returns first filed with 'field name'.
 * http_get_next_field will get next field with 'filed_name'
 */
char *http_get_field(struct http_header_t *http_hdr, const char *field_name)
{
    if(!http_hdr || !field_name) return NULL;
  
    http_hdr->field_search_pos = http_hdr->first_field;
    http_hdr->field_search = (char *)xrealloc(http_hdr->field_search,
					      strlen(field_name) + 1);
    /* copy field name first */
    
    strcpy(http_hdr->field_search, field_name);

    /* get first field value with this field_name. */
    return http_get_next_field(http_hdr);
}



/*
 * return field string after "http_hdr->field_search".
 *        NULL if not found.
 */
char *http_get_next_field(struct http_header_t *http_hdr)
{
    char *ptr;
    struct http_field_t *field;

    if(!http_hdr) return NULL;
    field = http_hdr->field_search_pos;
  
    while(field) {
	ptr = strstr(field->field_name,":");
	if(ptr == NULL) return NULL; /* the header is not valid... */
	if(!strncmp(field->field_name,http_hdr->field_search,
			ptr - field->field_name)) { /* found field!!!! */
	    ptr++; /* skip ':' */
	    while(*ptr == ' ') ptr++; /* skip %20 */
	    http_hdr->field_search_pos = field->next; /* points to next field */
	    return ptr; /* return the string without filed name!! */
	}
	field = field->next;
    }
    return NULL; /* NOT FOUND */
}



/*
 * http_set_field : make new field and attach it to last_field->next.
 */
void http_set_field(struct http_header_t *http_hdr, const char *field_name)
{
    struct http_field_t *new_field;
  
    if(http_hdr == NULL || field_name == NULL) return;
  
    new_field = (http_field_t *)xmalloc(sizeof(struct http_field_t));

    new_field->next = NULL;
    new_field->field_name = (char *)xmalloc(strlen(field_name) + 1);
    strcpy(new_field->field_name, field_name);
  
    if(http_hdr->last_field == NULL) {
	http_hdr->first_field = new_field; /* this was first filed!! */
    }
    else {
	http_hdr->last_field->next = new_field; /* attach to last    */
    }
    http_hdr->last_field = new_field;
    http_hdr->field_nb++;
}



/*
 * send 'http_hdr' to network. it has to be built by build_request funcs
 *                return value:  what xsend returned
 */
int http_send_header(struct stream_t *stream,
		     struct http_header_t *http_hdr)
{
    int ret;
  
    /* dbg */
    display(MSDL_DBG,"SEND http header ------------>\n"
	    "%s\n--(%d bytes)---------------<\n",
	    http_hdr->buffer,(int)http_hdr->buffer_len);
  
    ret = xsend(stream->netsock->sock,http_hdr->buffer,http_hdr->buffer_len);
    return ret;
}



/*
 * receive rtsp header and set rtsp_ctrl 
 *              return status code : success
 *                               -1 : failure
 */
int http_recv_header(struct stream_t *stream,struct http_header_t *http_hdr)
{
    int ret = 0;

    ret = http_recv_header_get(stream,http_hdr);
    if(ret < 0) {
	return -1;
    }

    ret = http_parse_response(stream->stream_ctrl->http_ctrl,http_hdr);
    if(ret < 0) {
	return -1;
    }

    return http_hdr->status_code;
}



/*
 * receive http message from stream->sock.
 *      header is guraranteed to be complete after this function,
 *      body should not be complete.
 *      so search Content-length and get all the body later.
 *               return status code : success
 *                               -1 : failure
 */
int http_recv_header_get(struct stream_t *stream, struct http_header_t *http_hdr)
{
    int ret = 0,i = 0,total = 0;
  
    http_hdr->buffer_len = 0;
    http_hdr->buffer = NULL;
    total = 0;
  
    do { /* get http reply */
	http_hdr->buffer_len += BUFSIZE_1K;
	http_hdr->buffer = (char *)xrealloc(http_hdr->buffer,
					    http_hdr->buffer_len + 1);
	
	i = recv_data(stream,http_hdr->buffer + total,http_hdr->buffer_len - total);
	if(i <= 0) {
	    display(MSDL_ERR,"http_recv_header error: recv_data() returned %d\n",i);
	    goto failed;
	}
	total += i;
  
	http_hdr->buffer[total] = '\0';
    } while(!http_is_entire_header(http_hdr));
    
    /* http_hdr->buffer_size is length in buffer, not the malloc()ed size.  */
    http_hdr->buffer_len = total;
    http_hdr->buffer[total] = '\0';

  
    /*
     * actually 2 protocols uses http, so 
     * don't mess with stream_ctrl->*_ctrl
     */
    ret = http_response_parse(http_hdr);
    if(ret < 0) {
	display(MSDL_ERR,"response HTTP header parse failed\n");
	goto failed;
    }
  
    /* push body back !!! */
    if(http_hdr->body_len) {
	stream_data_push_back(stream,http_hdr->body,http_hdr->body_len);
    }
  
    /* http_hdr->buffer *ONLY* contains header, no body follows */
    memset(http_hdr->body,0,http_hdr->body_len);

    /* dbg */
    display(MSDL_DBG,
	    "Resopnse header===========\n"
	    "%s\n"
	    "--(%d bytes)-------------------\n",
	    http_hdr->buffer,(int)http_hdr->buffer_len);
    

    /* success */
    return http_hdr->status_code;
    
  failed:
    if(http_hdr->buffer) free(http_hdr->buffer);
    http_hdr->buffer = NULL;
    return -1;
}



/* table for base 64 */
const char b64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/*
 * base64_encode : base 64 encode.
 *
 * enc:    string to base64 encode.
 * enclen: length of enc
 * out:    output base64 encoded result.
 * outmax: length of out (buffer length)
 *
 * copied from Mplayer/stream/http.c
 */
int base64_encode(const void *enc,int enclen,char *out,int outsize)
{
    unsigned char *encbuf;
    int outlen;
    unsigned int bits;
    unsigned int shift;
 
    encbuf = (unsigned char*)enc;
    outlen = 0;
    bits = 0;
    shift = 0;
    outsize &= ~3;
  
    while( outlen < outsize ) {
	if( enclen>0 ) {
	    /* Shift in byte */
	    bits <<= 8;
	    bits |= *encbuf;
	    shift += 8;
	    /* Next byte     */
	    encbuf++;
	    enclen--;
	} else if( shift>0 ) {
	    /* Pad last bits to 6 bits - will end next loop */
	    bits <<= 6 - shift;
	    shift = 6;
	} else {
	    /*
	      As per RFC 2045, section 6.8, 
	      pad output as necessary: 0 to 2 '=' chars.
	    */
	    while( outlen & 3 ){
		*out++ = '=';
		outlen++;
	    }
  
	    return outlen;
	}
 
	/* Encode 6 bit segments */
	while( shift>=6 ) {
	    shift -= 6;
	    *out = b64[ (bits >> shift) & 0x3F ];
	    out++;
	    outlen++;
	}
    }
  
    /* output overflow */
    return -1;
}



/*
 * add BASIC authentication string to header.
 *                return value: 0
 */
int http_add_basic_authentication(struct http_header_t *http_hdr,
				  const char *username, const char *password)
{
    char *auth = NULL, *user_pass = NULL, *b64_user_pass = NULL;
    int encoded_len ,pass_len = 0, out_len;
  
    int res = -1;
    /* username cannot be NULL. */
    if(http_hdr == NULL || username == NULL)  return -1;
  
    if(password != NULL) {
	pass_len = strlen(password);
    }

    user_pass = (char *)xmalloc(strlen(username) + pass_len + 2);
    sprintf(user_pass, "%s:%s",username,(password == NULL) ? "" : password);
  
    /* base64 encode with at least 33% more data than the original size. */
    encoded_len = strlen(user_pass) * 2;
    b64_user_pass = (char *)xmalloc(encoded_len);
  
    out_len = base64_encode(user_pass,strlen(user_pass),
			    b64_user_pass,encoded_len);
    if(out_len < 0) {
	fatal_error("Base64 output overflow!!\n");
    }
  
    b64_user_pass[out_len] = '\0';
    auth = (char *)xmalloc(encoded_len + 22);
  
    sprintf(auth,"Authorization: Basic %s",b64_user_pass);
    http_set_field(http_hdr,auth);
    res = 0;
 
    free(user_pass);
    free(b64_user_pass);
    free(auth);
    
    return res;
}



int http_print_authenticate_required(struct http_header_t *http_hdr)
{
    char *auth = NULL;
  
    auth = http_get_field(http_hdr,"WWW-Authenticate");
    if(auth) { /* found!!!  */
	char *auth_space = NULL;
	auth_space = strstr(auth,"realm=");
	if(auth_space != NULL) auth_space += 6;
	display(MSDL_NOR,"authentication required %s!!\n",auth_space);
    }
    else {     /* not found */
	display(MSDL_NOR,"authentication required!!\n");
    }
  
    return 0;
}


char *http_redirect_new_url(struct http_header_t *http_hdr)
{
    char *loc = NULL;
    loc = http_get_field(http_hdr,"Location");
    if(loc) {
	return strdup(loc);
    }
    else {
	display(MSDL_ERR,"Location: field does not exist, maybe invalid redirection\n");
	return NULL;
    }
}



/*
 * return url encoded string from src. malloced.
 */
char *http_encode_uri(const char *src)
{
    int i = 0,j = 0;
    int newlen  = 0;
    char *dst   = NULL;


    for(i = 0 ; src[i] != '\0' ; i++) { /* 1st path: see how many characters required */
	if(is_url_valid_char((int)src[i])) {
	    newlen += 1;
	}
	else {
	    newlen += 3; /* %XX */
	}
    }

    dst = (char *)xmalloc(newlen + 16);
    
    for(i = 0, j = 0 ; src[i] != '\0' ;) {
	if(is_url_valid_char((int)src[i])) { /* just put the same character there */
	    dst[j] = src[i];
	    j++; i++;
	}	
	else {
	    unsigned char cur = (unsigned char)src[i];
	    int h = (cur >> 4), l = (cur & 0x0F);
	    dst[j] =     '%';
	    dst[j + 1] = (h >= 0x0A) ? (h - 0x0A + 'A') : (h + '0');
	    dst[j + 2] = (l >= 0x0A) ? (l - 0x0A + 'A') : (l + '0');
	    
	    i += 1;
	    j += 3;
	}
    }
    dst[j] = '\0';
    
    return dst; /* retunn malloc string */
}



void http_set_uri(struct http_header_t *http_hdr,const char *uri)
{
    if(http_hdr == NULL || uri == NULL) return;

    http_hdr->uri = http_encode_uri(uri);
}



void http_set_method(struct http_header_t *http_hdr, const char *method)
{
    if(http_hdr == NULL || method == NULL) return;

    http_hdr->method = strdup(method);
}



char *http_request_get(struct http_header_t *http_hdr)
{
    http_set_method(http_hdr,"GET");
  
    return (http_build_request(http_hdr));
}


char *http_request_head(struct http_header_t *http_hdr)
{
    http_set_method(http_hdr,"HEAD");
  
    return (http_build_request(http_hdr));
}



char *http_request_post(struct http_header_t *http_hdr)
{
    http_set_method(http_hdr,"POST");
  
    return (http_build_request(http_hdr));
}




/*
 * make complete http_header_t.
 * the request string goes to http_hdr->buffer
 *             return value:   http_hdr->buffer ( built request )
 */
char *http_build_request(struct http_header_t *http_hdr)
{
    char *ptr = NULL;
    int len = 0;
    struct http_field_t *field;
  

    if(http_hdr->uri == NULL) {
	http_set_uri(http_hdr,"/");
    }
    
    /*
     * culculate the request length.
     */

    /* method line */
    len = strlen(http_hdr->method) + strlen(http_hdr->uri) + 12;
    /* fields */
    field = http_hdr->first_field;
    while(field) {
	len += strlen(field->field_name) + 2;
	field = field->next;
    }
    /* CRLF */
    len += 2;
    /* request body */
    if(http_hdr->body) {
	len += http_hdr->body_len;
    }
  

    /*
     * free the buffer which used 4 last request.
     */
    if(http_hdr->buffer) {
	free(http_hdr->buffer);
	http_hdr->buffer = NULL;
    }
  
    http_hdr->buffer_len = len;
    http_hdr->buffer = (char *)xmalloc(len + 1); /* 1 for '\0' */
  
  
    /* 
     * build the request
     */
    ptr = http_hdr->buffer;
    /* method line */
    ptr += sprintf(ptr,"%s %s HTTP/1.%d\r\n",
		   http_hdr->method,http_hdr->uri,http_hdr->http_minor_version);
    field = http_hdr->first_field;
    /* fields */
    while(field != NULL) {
	ptr += sprintf(ptr,"%s\r\n",field->field_name);
	field = field->next;
    }
    ptr += sprintf(ptr,"\r\n");
  
    if(http_hdr->body != NULL) {
	memcpy(ptr,http_hdr->body,http_hdr->body_len);
    }
    
    return http_hdr->buffer;
}




/*
 * concatinate http_hdr->buffer and response.
 * return value is new buffer size. (not counting NULL char)
 */
int http_response_append(struct http_header_t *http_hdr,
			 char *response,int len)
{
    if(http_hdr == NULL || response == NULL || len < 0) return 0;
    
    /* *** caution *** */
    /* http_hdr->buffer_size does NOT include '\0' at the end. */
  
    /*
      if(http_hdr->buffer_size + len + 1 > HDR_SIZE_MAX) { // +1 for '\0'
      display(MSDL_ERR,"%d maybe recv failed\n",http_hdr->buffer_size);
      return -1;
      }
    */
    http_hdr->buffer = (char *)xrealloc(http_hdr->buffer,
					http_hdr->buffer_len + len + 1);
    /* concat buffer. */
    memcpy(http_hdr->buffer + http_hdr->buffer_len, response, len);
    http_hdr->buffer_len += len;
    http_hdr->buffer[http_hdr->buffer_len] = '\0'; /* terminate. */

    return http_hdr->buffer_len;
}



/*
 * judges if http_hdr is complete HTTP header, or still needs some parts.
 *    return value :       0 ... NOT complete
 *                         1 ... COMPLETE!!
 */
int http_is_entire_header(struct http_header_t *http_hdr)
{
    if(http_hdr == NULL) return 0; /* unlikely, but error */
  
    if(http_hdr->buffer == NULL) return 0;   /* nothing received. */
    
    if(strstr(http_hdr->buffer,"\r\n\r\n") || 
       strstr(http_hdr->buffer,"\n\n")) {
	return 1;
    }

    return 0;
}



/*
 * http_response_parse :  parse http response header 
 * make http_hdr from raw data in http_hdr->buffer
 *
 *    return value :        -1 ... ERROR
 *                           0 ... already parsed.
 *                           1 ... success.
 */
int http_response_parse(struct http_header_t *http_hdr)
{
    char *hdr_ptr, *ptr;
    char *field = NULL;
  
    int pos_hdr_sep, hdr_sep_len;
    size_t len;
  
    if(http_hdr == NULL) return -1;
    if(http_hdr->is_parsed) return 0; /* already parsed. */
  
  
    /*
      1. get protocol.
    */
    hdr_ptr = strstr(http_hdr->buffer, " ");
    if(hdr_ptr == NULL) {
	display(MSDL_ERR,"Malformed answer : No %20 separator\n");
	return -1;
    }
  
    len = hdr_ptr - http_hdr->buffer;
    http_hdr->protocol = (char *)xmalloc(len + 1);
    strncpy(http_hdr->protocol,http_hdr->buffer,len);
    http_hdr->protocol[len] = '\0';
  
  
    /* get (useless) minor version here. */
    if(!strncmp(http_hdr->protocol,"HTTP",4)) {
	if(sscanf(http_hdr->protocol+5,"1.%d",
		  &(http_hdr->http_minor_version)) != 1)
	    display(MSDL_ERR,"Malformed answer: http minor version unsepcified\n");
	/* actually, lack of HTTP version is not fatal AT ALL. */
    }

    /*
      2. get status code
    */
    if(sscanf(++hdr_ptr,"%d",&(http_hdr->status_code)) != 1) {
	display(MSDL_ERR,"Malformed answer : No http status code!!\n");
	return -1;
    } 
  
    hdr_ptr += 4; /* "[0-9][0-9][0-9] " */
  
    /*
      3. get reason phrase
    */
    ptr = strstr(hdr_ptr,"\n");
    if(ptr == NULL) {
	display(MSDL_ERR,"Malformed answer : unable to get reason_phrase\n");
	return -1;
    }
    len = ptr - hdr_ptr; /* len of reason phrase. */
  
    http_hdr->reason_phrase = (char *)xmalloc(len + 1);
    strncpy(http_hdr->reason_phrase,hdr_ptr,len);
    if(http_hdr->reason_phrase[len - 1] == '\r') { /* M$ style newline! */
	len --; /* we don't need \r. */
    }
    http_hdr->reason_phrase[len] = '\0'; /* terminate string */

    hdr_sep_len = 4; /* header separator length */
    ptr = strstr(http_hdr->buffer,"\r\n\r\n");
    if(!ptr) {
	ptr = strstr(http_hdr->buffer,"\n\n");
	if(!ptr) {
	    display(MSDL_ERR,"Header may be incomplete!\n");
	    return -1;
	}
	hdr_sep_len = 2;
    }
    pos_hdr_sep = ptr - http_hdr->buffer;

    /* points to first line after method line. */
    hdr_ptr = strstr(http_hdr->buffer,"\n") + 1;

  
    /* get all fields. they are separated by '\n' */
    do {
	ptr = hdr_ptr;
	while(*ptr != '\r' && *ptr != '\n') ptr++;
	len  = ptr - hdr_ptr;

	if(len == 0) break; /* met \n\n --> end of header! */
    
	field = (char *)xrealloc(field,len + 1); /* +1 for '\0' */
	strncpy(field,hdr_ptr,len);
	field[len] = '\0';
    
	http_set_field(http_hdr,field);
	hdr_ptr = ptr + ((*ptr == '\r') ? 2 : 1); /* points to next line */
    } while(hdr_ptr < (http_hdr->buffer + pos_hdr_sep));
  
    if(field) {
	free(field);
    }

    if(pos_hdr_sep + hdr_sep_len < http_hdr->buffer_len) {
	/* response has data within. --> store data !! or data will be lost! */
	http_hdr->body = http_hdr->buffer + pos_hdr_sep + hdr_sep_len;
	/* now its pointing to data in buffer. */
	http_hdr->body_len = http_hdr->buffer_len - (pos_hdr_sep + hdr_sep_len);
    }
  
    http_hdr->is_parsed = 1;
  
    return 1;
}



/*
 * return value:  0: not valid   1: valid
 * reason_ret ... NULL: no error
 *                error reason string: some error
 */

int http_byterange_spec_valid(const char *str,char **reason_ret)
{
    const char *p = str;
    for(; *p ; p++) {
	if(!isdigit(*p)) {
	    *reason_ret = "http: byterange must be all digits";
	    return 0;
	}
    }

    *reason_ret = NULL;
    return 1;
}



/* 
 * check if Range: string is valid
 * return value ... 0: not valid  1: valid
 * reason_ret ... NULL: no error
 *                error reason string: some error
 */
int http_byterange_valid(const char *str,char **reason_ret)
{
    char *p = NULL;
    char *range_str = NULL;
    int valid = 0;
    char *reason = NULL;

    p = strchr(const_cast<char*>(str),'-');
    if(p == NULL) { /* have to have exactly one '-' */
	reason = "must use \'-\' to tell range";
	if(reason_ret) {
	    *reason_ret = reason;
	}
	return 0;
    }
    else if(p == str) { /* ( "-" npt-time ) */
	valid = http_byterange_spec_valid(p + 1,reason_ret);
	return valid;
    }
    else { /* 00.23- */
	int start_str_len = p - str;
	if(*(p+1) != '\0') { /* not 00.23- */
	    if(!http_byterange_spec_valid(p + 1,reason_ret)) { /* check end string */
		return 0;
	    }
	}
	/* end string OK */

	/* check start string */
	range_str = (char *)xmalloc(start_str_len + 1);
	strncpy(range_str,str,start_str_len);
	range_str[start_str_len] = '\0';
	valid = http_byterange_spec_valid(range_str,reason_ret);
	free(range_str);
	
	return valid;
    }
    return 0;
}




void http_set_byterange_field(struct http_header_t *http_hdr,const char *rangestr)
{
    char *buffer = (char *)xmalloc(BUFSIZE_1K);
    char *reason = NULL;

    if(http_byterange_valid(rangestr,&reason)) { /* valid */
	snprintf(buffer,BUFSIZE_1K - 1,"Range: bytes=%s",rangestr);
	http_set_field(http_hdr,buffer);
    }
    else {
	display(MSDL_ERR,
		"invalid byterange \"%s\"\n"
		"%s\n",rangestr,reason);
    }
    
    free(buffer);
}





/*
 * prepare_resuming for http
 * set resumeinfo->resume_start_offset & resume_req_success
 *
 * return value:     1 ... success
 *                  -1 ... failed
 */
int http_prepare_resuming(struct stream_t *stream)
{
    int ret = 0;
    uint64_t filesize = 0;

    /*
     * find same file name
     */
    
    ret = get_filesize(stream->localfile,&filesize);
    if(ret < 0) {
	display(MSDL_ERR,
		"http resume: no such file \"%s\", not resuming\n",stream->localfile);
	goto failed;
    }

    if(stream->dlopts->byterange) {
	free(stream->dlopts->byterange);
    }
    
    stream->dlopts->byterange = make_byterange_from_filesize(filesize);
    stream->resumeinfo->resume_start_offset = filesize;
    
    display(MSDL_DBG,
	    "http resume: start pos: %lld [%llx]\n",
	    filesize,filesize);

    return 1;

  failed:
    stream->resumeinfo->resume_start_offset = 0; /* don't check request result */
    stream->resumeinfo->resume_req_success = 0;
    return -1;
}


/*
 * set standard fields for HTTP.
 * set uri
 * Accept:
 * User-Agent:
 * Host:
 *
 */
int http_set_standard_fields(struct stream_t *stream,
			     struct http_header_t *http_hdr)
{
    struct url_t *url = NULL;
    struct download_opts_t *dlopts = NULL;
    char str[BUFSIZE_1K];
    
    if(stream == NULL || http_hdr == NULL) {
	return -1;
    }
    
    url = stream->url;
    dlopts = stream->dlopts;
    if((url == NULL) || (dlopts == NULL)) {
	return -1;
    }
    
    http_set_field(http_hdr, "Accept: */*");
    http_set_field(http_hdr, http_useragent);

    http_add_basic_authentication(http_hdr,
				  (url->username) ? url->username : stream->dlopts->username,
				  (url->password) ? url->password : stream->dlopts->password);
    
    if(dlopts->http_proxy) {
	http_set_uri(http_hdr,url->url);
    }
    else {
	http_set_uri(http_hdr,url->filepath);
    }
    
    
    snprintf(str,BUFSIZE_1K,"Host: %.220s:%d",stream->serverinfo->host,stream->serverinfo->port);
    http_set_field(http_hdr,str);
  
  
    http_set_field(http_hdr,"Connection: Close");
    
    return 1;
}


int is_http_response_ok(int status_code)
{
    return ((200 <= status_code) && (status_code <= 299)) ? 1 : 0;
}


/*
 * parse http response
 * return value:   1 ... success
 *                -1 ... parse error
 */
int http_parse_response(struct http_ctrl_t *http_ctrl,
			struct http_header_t *http_hdr)
{
    char *content_length = NULL;

    content_length = http_get_field(http_hdr, "Content-Length");
    if(content_length) {
	http_ctrl->content_length = atoi(content_length);
    }
    else {
	http_ctrl->content_length = 0;
    }
    
    return 1;
}


/*
 * send GET request and perse response
 * return value:    1 ... success
 *                 -1 ... comp
 */
int http_get(struct stream_t *stream)
{
    struct http_header_t *http_hdr = NULL;
    struct download_opts_t *dlopts = stream->dlopts;
    int ret = 0;

    http_hdr = new_http_header();

    http_set_standard_fields(stream,http_hdr);

    if(dlopts->resume_download) {
	http_prepare_resuming(stream);
    }
    
    /* byte range specified */
    if(dlopts->byterange) {
	http_set_byterange_field(http_hdr,dlopts->byterange);
    }

    http_request_get(http_hdr);
    http_send_header(stream,http_hdr);
    free_http_header(http_hdr);
    
    http_hdr = new_http_header();
    http_recv_header(stream,http_hdr);
    ret = http_process_reply(stream,http_hdr); // interpret http_hdr which just received
    if(ret < 0) {
	goto failed; // including complete
    }

    free_http_header(http_hdr);
    return 1;

  failed:
    free_http_header(http_hdr);
    return -1;
}


int http_process_reply(struct stream_t *stream,struct http_header_t *http_hdr)
{
    int status_code = http_hdr->status_code;
    
    if(status_code < 0) {
	display(MSDL_ERR,"response HTTP header parse failed\n");
	goto failed;
    }
    if(stream->dlopts->resume_download) {  /* resume case */
	if(status_code == 206) { /* byterange req success */
	    stream->resumeinfo->resume_req_success = 1;
	}
	else if (status_code == 416){
	    stream->resumeinfo->resume_req_success = 0;
	    stream->stream_ctrl->status = STREAMING_NO_NEED_TO_DOWNLOAD;
	    goto complete;
	}
	else {
	    stream->resumeinfo->resume_req_success = 0;
	}
    }

    if(!is_http_response_ok(status_code)) { /* other error case */
	if(status_code == 301 || status_code == 302 || status_code == 303 || status_code == 307) {
	    char *newurlstr = NULL;  // HERE
	    newurlstr = http_redirect_new_url(http_hdr);
	    display(MSDL_NOR,"redirect to %s\n",newurlstr);
	    if(newurlstr) {
		stream->stream_ctrl->retry_urlstr = newurlstr;
		stream->stream_ctrl->status = STREAMING_REDIRECTED;
	    }
	    goto failed;
	}
	else if(status_code == 401) {
	    http_print_authenticate_required(http_hdr);
	    goto failed;
	}
	else {
	    display(MSDL_ERR,"%d %s\n",http_hdr->status_code,http_hdr->reason_phrase);
	    goto failed;
	}
    }

    return 1;

  complete:
  failed:
    return -1;
}



/*
 * starts mmst streaming(actually this is downlaoding).
 * 
 *    return value :   negative or 0  ... error
 *                                 1  ... success
 */
int http_streaming_start(struct stream_t *stream)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct http_ctrl_t *http_ctrl = stream_ctrl->http_ctrl;
    struct url_t *url = stream->url;

    int sock = 0;
    int ret = 0;
  
    stream_ctrl->status = STREAMING_HANDSHAKING;
    
    set_serverinfo_by_proxy_string(stream->serverinfo,url->hostname,url->port,
				   stream->dlopts->http_proxy,
				   HTTP_PORT,HTTP_PROXY_PORT);
    sock = server_connect(stream->serverinfo->connect_host,stream->serverinfo->connect_port);
    if(sock < 0) {
	goto failed;
    }
    stream->netsock->sock = sock;

    ret = http_get(stream);
    if(ret < 0) {
	if(stream_ctrl->status == STREAMING_NO_NEED_TO_DOWNLOAD) {
	    goto complete;
	}
	else {
	    goto failed;
	}
    }
    
    /* set file size to download */
    stream_ctrl->file_size = http_ctrl->content_length;
    stream_ctrl->status = STREAMING_DOWNLOADING;
    stream_ctrl->protocol = HTTP;

    return 1;
  
  failed:
  complete:
    return 0;
}



/*
 * read http (stream). filles buffer, and buffer size is 'size' 
 *
 *        read cached data from stream->netsock->buffer
 *        check for to see if network access is necessary
 *        get chunk(media packet) from network.
 *
 *  return value: bytes written to buffer. -1 if error.
 */
int http_streaming_read(struct stream_t *stream,
			uint8_t *buffer, size_t buffer_size)
{
    struct http_ctrl_t *http_ctrl = stream->stream_ctrl->http_ctrl;
    int ret;
  
    if(http_ctrl->content_length) {
	int rest = http_ctrl->content_length - http_ctrl->down_length;
    
	if(rest == 0) { /* finished */
	    ret = 0;
	}
	else { /* needs to get from network or buffer */
	    int recv_length = (rest > buffer_size) ? buffer_size : rest; /* smaller */
	    ret = recv_data(stream,buffer,recv_length);
	    http_ctrl->down_length += ret;
	}
    }
    else {
	/*
	  recv() returns 0 if we call recv on
	  already shutdown()ed socket
	*/
	ret = recv_data(stream,buffer,buffer_size);
    }
  
  
    if(ret == 0) {
	stream->stream_ctrl->status = STREAMING_FINISHED;
    }

    return ret;
}



struct http_ctrl_t *new_http_ctrl_t(void)
{
    struct http_ctrl_t *ctrl = (http_ctrl_t *)xmalloc(sizeof(struct http_ctrl_t));
    return ctrl;
}



void free_http_ctrl_t(struct http_ctrl_t *ctrl)
{
    free(ctrl);
}



struct stream_t *http_streaming_init()
{
    struct stream_t *stream = streaming_init_common();
    stream->stream_ctrl->http_ctrl = new_http_ctrl_t();
  
    stream->start = http_streaming_start;
    stream->read  = http_streaming_read;
    stream->close = http_streaming_close;
  
    return stream;
}



void http_streaming_close(struct stream_t *stream)
{
    if(stream->netsock->sock > 0) {
	closesocket(stream->netsock->sock);
    }
    
    free_http_ctrl_t(stream->stream_ctrl->http_ctrl);
    streaming_close_common(stream);
}
