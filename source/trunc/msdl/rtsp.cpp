/***********************************************************************
 *    rtsp.c: for downloading via rtsp (Real Time Streaming Protocol)
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


/*
 * Copyright notice of MPlayer project
 * which some part of msdl is based on.
 * (from MPlayer-1.0rc2/stream/realrtsp/.c)
 */

/*
 * This file was ported to MPlayer from xine CVS rtsp.c,v 1.9 2003/04/10 02:30:48
 */

/*
 * Copyright (C) 2000-2002 the xine project
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 *
 *
 * a minimalistic implementation of rtsp protocol,
 * *not* RFC 2326 compilant yet.
 *
 *    2006, Benjamin Zores and Vincent Mussard
 *      fixed a lot of RFC compliance issues.
 */

/*
 * Copyright notice of xine-lib project
 * which some part of msdl is based on.
 * (from xine-lib-1.1.14/src/input/librtsp/rtsp.c)
 */

/*
 * Copyright (C) 2000-2003 the xine project
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
 * a minimalistic implementation of rtsp protocol,
 * *not* RFC 2326 compilant yet.
 */


#include "stdafx.h"

#include "snprintf.h"
#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "real.h"
#include "rmff.h"
#include "asf.h"
#include "wmserver.h"
#include "rtsp.h"

char m_szLastError[1000];

const char rtsp_protocol_version[] = "RTSP/1.0";


/* defined in real.c */
extern const char rtsp_protocol_version[];
extern const char real_clientid[];
extern const char real_companyid[];
extern const char real_useragent[];
extern const char real_clientchallenge[];
extern const char real_playerstarttime[];
extern const char real_transport[];

static struct rtsp_ctrl_t *new_rtsp_ctrl_t(void);
static void free_rtsp_ctrl_t(struct rtsp_ctrl_t *ctrlt);
static int rtsp_recv_header_get(struct stream_t *stream, struct rtsp_header_t *rtsp_hdr);
int rtsp_parse_response(struct rtsp_ctrl_t *rtsp_ctrl,
			struct rtsp_header_t *rtsp_header);




/*
 * read rtsp stream. filles buffer, and buffer size is 'size' 
 *
 *        read cached data from stream->netsock->buffer
 *        check for to see if network access is necessary
 *        get chunk(media packet) from network.
 *
 *  return value: bytes written to buffer. -1 if error.
 *                                          0 if buffering
 */
int rtsp_streaming_read(struct stream_t *stream,
			uint8_t *buffer, size_t buffer_size)
{
  
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    size_t pos = 0; // how many bytes are in 'buffer'
    int ret = 0;

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
	ret = stream_ctrl->rtsp_ctrl->get_media_packet(stream,buffer + pos,
							   buffer_size - pos);
    }


    
    if(stream_ctrl->status == STREAMING_RESUME_BUFFERING) { /* TODO: check ret > 0 neccessary? */
	return 0;
    }
    else if(ret >= 0) {
	return (ret + pos);
    }
    else {
        return -1; /* error */
    }
}



/*
 * find Content-Length field in rtsp_hdr, and read (and trash) following data
 * return value:   bytes received and discarded
 *                -1 ... failed
 */
int rtsp_ignore_data_after_header(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr)
{
    char *field = NULL;
    int body_left = 0;
    
    if((field = rtsp_get_field(rtsp_hdr,"Content-Length")) != NULL) {
	uint8_t *ignorebuf = NULL;
	
	while(*field == ' ') field++;
	body_left = atoi(field);
	if(body_left) {
	    ignorebuf = (uint8_t *)xmalloc(body_left);
	    if(read_data(stream,ignorebuf,body_left) <= 0) {
		free(ignorebuf);
		goto failed;
	    }
	    free(ignorebuf);
	}
    }

    return body_left;

  failed:
    return -1;
}


int is_rtsp_response_ok(int status_code)
{
    return ((200 <= status_code) && (status_code <= 299)) ? 1 : 0;
}


/*
 * receive rtsp header but ignore its message, etc..
 * this function is purely for making code more readable.
 *
 *       return value:  what rtsp_recv_header returned
 *                      -1 ... failed;
 */
int rtsp_recv_header_ignore_message(struct stream_t *stream)
{
    struct rtsp_header_t *rtsp_hdr = NULL;
    int ret = 0;

    
    rtsp_hdr = new_rtsp_header();
    ret = rtsp_recv_header(stream,rtsp_hdr);
    
    /* if content-length field, get all following data */
    if(rtsp_ignore_data_after_header(stream,rtsp_hdr) < 0) {
	return -1;
    }
    
    free_rtsp_header(rtsp_hdr);
    return ret;
}



/*
 * alloc new rtsp_header_t and set standard fields for send.
 * this function is purely for making code more readable.
 *
 * return value:  what rtsp_recv_header returned (status code: success  -1: failure)
 */
struct rtsp_header_t *new_rtsp_header_with_standard_fields(struct rtsp_ctrl_t *rtsp_ctrl)
{
    struct rtsp_header_t *rtsp_hdr;

    rtsp_hdr = new_rtsp_header();
    rtsp_set_standard_fields(rtsp_ctrl,rtsp_hdr);
    
    return rtsp_hdr;
}
    

/*
 * send rtsp_request and free it.
 * this function is purely for making code more readable.
 *
 * return value:  what rtsp_send request returned. (status code: success  -1: failure)
 */
int rtsp_send_request_and_free(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr)
{
    int ret;
    
    ret = rtsp_send_request(stream,rtsp_hdr);
    free_rtsp_header(rtsp_hdr);
    
    return ret;
}


/*
 * make range string
 */
char *rtsp_make_range_from_timestamp(uint32_t range_ts)
{
    char *rangestr = (char *)xmalloc(256);
    snprintf(rangestr,255,"%d.000-",(range_ts / 1000));
    return rangestr;
}


/*
 * set Range: field to rtsp_hdr.
 */
void rtsp_set_range_field(struct rtsp_header_t *rtsp_hdr,const char *rangestr)
{
    char *buffer = (char *)xmalloc(BUFSIZE_1K);

    /* range specified */
    if(rangestr) {
	char *reason = NULL;
	
	if(rtsp_npt_range_valid(rangestr,&reason)) { /* valid */
	    snprintf(buffer,BUFSIZE_1K - 1,"Range: npt=%s",rangestr);
	}
	else {
	    char *npt_range_str = NULL;
	    npt_range_str = rtsp_range_to_npt_range(rangestr,&reason);
	    if(npt_range_str) { /* acceptable   */
		snprintf(buffer,BUFSIZE_1K - 1,"Range: npt=%s",npt_range_str);
		display(MSDL_VER,
			"send \"%s\" for Range\n",
			npt_range_str);
		free(npt_range_str);
	    }
	    else {              /* really inacceptable */
		strncpy(buffer,"Range: npt=0.000-",BUFSIZE_1K - 1);
		display(MSDL_ERR,
			"option \"-r %s\" is invalid as a rtsp range request\n"
			": %s\n"
			"send \"%s\" instead\n",
			rangestr,reason,buffer);
	    }
	}
    }
    else { /* default range, from beginning */
	strncpy(buffer,"Range: npt=0.000-",BUFSIZE_1K - 1);
    }
    rtsp_set_field(rtsp_hdr,buffer);

    free(buffer);
}


/*
 * set Speed: field to rtsp_hdr.
 */
void rtsp_set_speed_field(struct rtsp_header_t *rtsp_hdr,const char *speedstr)
{
    char *buffer = (char *)xmalloc(BUFSIZE_1K);
    
    /* speed specified */
    if(speedstr) {

	char *reason = NULL;
	int  guessed_speed = 0;
	
	if(speed_valid_and_guess(speedstr,&guessed_speed,&reason)) {
	    snprintf(buffer,BUFSIZE_1K - 1,"Speed: %s",speedstr);	    
	}
	else { /* invlalid, use guessed value */
	    if(guessed_speed == 0) {
		guessed_speed = 1; /* default speed 1.000 */
	    }
	    snprintf(buffer,BUFSIZE_1K - 1,"Speed: %d.000",guessed_speed);
	    display(MSDL_ERR,
		    "option \"-s %s\" is invalid as a rtsp speed request\n"
		    ": %s\n"
		    "send \"%s\" instead\n",
		    speedstr,reason,buffer);
	}
    }
    else { /* set default speed */
	strncpy(buffer,"Speed: 1.000",BUFSIZE_1K - 1);
    }
    rtsp_set_field(rtsp_hdr,buffer);

    free(buffer);
}



/*
 *
 * str: [ npt-hh ":" npt-mm ":" ] npt-ss [ "." *DIGIT ] | [00h][00m][00s] ["." *DIGIT]
 *              
 * return value:    NULL: really inacceptable, such as "0.0a1"
 *              npt-time: rtsp npt valid string (malloc)
 */
char *rtsp_time_to_npt_time(const char *str,char **reason_ret)
{
    if(!strcmp(str,"now")) {
	char *npt_time = strdup("now");
	if(reason_ret) {
	    *reason_ret = "";
	}
	return npt_time;
    }

    return create_time_str_from_many_formats(str,reason_ret);
}



/*
 * change dlopts -r option to npt-range string
 * return value:  NULL: str was inacceptable
 *                 npt: npt range part (ex. 12.345-67.890) (malloc)
 */
char *rtsp_range_to_npt_range(const char *str,char **reason_ret)
{
    /*
      npt-range    =   ( npt-time "-" [ npt-time ] ) | ( "-" npt-time )
      npt-time     =   "now" | npt-sec | npt-hhmmss
      npt-sec      =   1*DIGIT [ "." *DIGIT ]
      npt-hhmmss   =   npt-hh ":" npt-mm ":" npt-ss [ "." *DIGIT ]
      npt-hh       =   1*DIGIT     ; any positive number
      npt-mm       =   1*2DIGIT    ; 0-59
      npt-ss       =   1*2DIGIT    ; 0-59
    */
    char *npt_range_str = NULL;
    char *reason = NULL;

    if(rtsp_npt_range_valid(str,reason_ret)) {  /* if str was rfc valid npt range string, return that.*/
	npt_range_str = strdup(str); /* to integrate interface, copy it */
	reason = "";
	if(reason_ret) {
	    *reason_ret = reason;
	}
	return npt_range_str;
    }
    else { /* not valid, but allocate rfc valid npt string */
	char *p = NULL;
	p = strchr(const_cast<char*>(str),'-');
	if(p == NULL) { /* really inacceptable. */
	    reason = "must use \'-\' to tell range";
	    if(reason_ret) {
		*reason_ret = reason;
	    }
	    return NULL;
	}
	else if(p == str) { /* "-" npt-time(invalid) */
	    char *npt_time_str = rtsp_time_to_npt_time(p + 1,reason_ret);
	    if(!npt_time_str) { /* really inacceptable*/
		return NULL;
	    }
	    npt_range_str = (char *)xmalloc(strlen(npt_time_str) + 2);
	    npt_range_str[0] = '-';
	    strcpy(npt_range_str + 1,npt_time_str);
	    npt_range_str[strlen(npt_time_str) + 1] = '\0';
	    free(npt_time_str);

	    return npt_range_str;
	}
	else {
	    char *npt_start_time_str = NULL;
	    char *npt_end_time_str = NULL;
	    char *original_start_time_str = NULL;
	    int start_str_len = p - str;
	    if(*(p+1) == '\0') { /* npt-time "-" */
		npt_end_time_str = (char *)xmalloc(2);
		npt_end_time_str[0] = '\0';
	    }
	    else {               /* npt-time "-" npt-time */
		if(rtsp_npt_time_valid(p + 1,reason_ret)) { /* check end string */
		    /* end string OK --> direct copy */
		    npt_end_time_str = strdup(p + 1);
		}
		else {
		    /* end string NOT OK */
		    npt_end_time_str = rtsp_time_to_npt_time(p + 1,reason_ret);
		    if(!npt_end_time_str) { /* really inacceptable */
			return NULL;
		    }
		}
	    }
	    
	    original_start_time_str = (char *)xmalloc(start_str_len + 1);
	    strncpy(original_start_time_str,str,start_str_len);
	    original_start_time_str[start_str_len] = '\0';

	    if(rtsp_npt_time_valid(original_start_time_str,reason_ret)) {
		/* start string OK --> direct copy */
		npt_start_time_str = strdup(original_start_time_str);
	    }
	    else {
		/* start string NOT OK */
		npt_start_time_str = rtsp_time_to_npt_time(original_start_time_str,reason_ret);
		if(!npt_start_time_str) { /* really inacceptable */
		    free(original_start_time_str);
		    free(npt_end_time_str);
		    return NULL;
		}
	    }

	    npt_range_str = (char *)xmalloc(strlen(npt_start_time_str) +
				    strlen(npt_end_time_str) + 2);
	    strcpy(npt_range_str,npt_start_time_str);
	    strcat(npt_range_str,"-");
	    strcat(npt_range_str,npt_end_time_str);
	    npt_range_str[strlen(npt_start_time_str) + strlen(npt_end_time_str) + 1] = '\0';
	    
	    free(npt_start_time_str);
	    free(npt_end_time_str);
	    free(original_start_time_str);

	    return npt_range_str;
	}
    }
    
    return NULL;
}



/*
 * check if npt-range string is valid.
 * this function is to only check validity.
 * return value ... 0: not valid  1: valid
 * reason_ret ... NULL: no error
 *                error reason string: some error
 */
int rtsp_npt_range_valid(const char *str,char **reason_ret)
{
    char *p = NULL;
    char *npttime_str = NULL;
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
    if(p == str) { /* ( "-" npt-time ) */
	valid = rtsp_npt_time_valid(p + 1,reason_ret);
	return valid;
    }
    else { /* 00.23- */
	int start_str_len = p - str;
	if(*(p+1) != '\0') { /* not 00.23- */
	    if(!rtsp_npt_time_valid(p + 1,reason_ret)) { /* check end string */
		return 0;
	    }
	}
	/* end string OK */

	/* check start string */
	npttime_str = (char *)xmalloc(start_str_len + 1);
	strncpy(npttime_str,str,start_str_len);
	npttime_str[start_str_len] = '\0';
	valid = rtsp_npt_time_valid(npttime_str,reason_ret);
	free(npttime_str);
	
	return valid;
    }
    return 0;
}



/*
 * check if npt-time string is valid.
 * this function is to only check validity.
 * return value ... 0: not valid  1: valid
 * reason_ret   ... "": no error    some string: error reason
 *      
 */
int rtsp_npt_time_valid(const char *str,char **reason_ret)
{
    int len = strlen(str);
    int i = 0;
    int npt_sec_valid = 1;
    int npt_hhmmss_valid = 1;
    int met_colon = 0;
    int mmss_value = 0;
    char *reason = NULL;
    
    if(!strcmp(str,"now")) { /* "now" is valid */
	reason = "";
	if(reason_ret) {
	    *reason_ret = reason;
	}
	return 1;
    }

    /*
      Actually, we can check npt-sec validity and npt-hhmmss at the same time.
      to do that, change 
      - if(met_colon < 2) {
      + if((met_colon != 0) && (met_colon < 2)) {
      
      I'm not doing this to respect rfc 2326, which wirtes like below.
      "npt-time     =   "now" | npt-sec | npt-hhmmss"
      
     */


    /* check npt-sec validity */
    npt_sec_valid = 1;
    for(i = 0; (i < len) && npt_sec_valid ; i++) {
	if('0' <= str[i] && str[i] <= '9') {
	    continue;
	}
	else if(str[i] == '.') {
	    if((i == 0) || (i == len - 1) || str[i-1] == ':') {
		/* dot was at the beginning or end of string, or right after colon */
		reason = "\'.\' at the beginning or end of string, or right after colon";
		npt_sec_valid = 0;
		break;
	    }
	    i++;
	    for(; i < len ; i++) {
		if(('0' <= str[i]) && (str[i] <= '9')) {
		    continue;
		}
		else {
		    reason = "invalid character after \'.\'";
		    npt_sec_valid = 0;
		    break;
		}
	    }
	}
	else {     /* invalid character found */
	    reason = "invalid character";
	    npt_sec_valid = 0;
	    break;
	}
    }
    if(npt_sec_valid) {
	reason = "";
	if(reason_ret) {
	    *reason_ret = reason;
	}
	return npt_sec_valid;
    }


    /* check npt-hhmmss validity*/
    npt_hhmmss_valid = 1;
    met_colon = 0;
    mmss_value = 0;
    for(i = 0 ; (i < len) && npt_hhmmss_valid ; i++) {
	if('0' <= str[i] && str[i] <= '9') {
	    if(met_colon == 0) { /* npt-hh can be any positive number */
		continue;
	    }
	    else {              /* npt-mm and npt-ss must be less than 60*/
		mmss_value *= 10;
		mmss_value += str[i] - '0';

		if(mmss_value >= 60) {
		    reason = "value more than 59 in mmss";
		    npt_hhmmss_valid = 0;
		    break;
		}
		continue;
	    }
	}
	else if(str[i] == '.') {
	    if((i == 0) || (i == len - 1) || (str[i-1] == ':')) {
		reason = "\'.\' at the beginning or end of string, or right after colon";
		npt_hhmmss_valid = 0;
		break;
	    }
	    i++;
	    for(; i < len ; i++) {
		if(('0' <= str[i]) && (str[i] <= '9')) {
		    continue;
		}
		else {
		    reason = "invalid char after \'.\'";
		    npt_hhmmss_valid = 0;
		    break;
		}
	    }
	}
	else if(str[i] == ':') { /* have to have 2 colons */
	    if((i == 0) || (i == len - 1) || (str[i-1] == ':')) {
		reason = "\':\' at invalid position";
		npt_hhmmss_valid = 0;
		break;
	    }
	    mmss_value = 0;          /* reset mmss_value */
	    if(met_colon < 2) {
		met_colon++;
		continue;
	    }
	    else { /* too many colons, return */
		reason = "too many colons";
		npt_hhmmss_valid = 0;
		break;
	    }
	}
	else {     /* invalid chraracter      */
	    reason = "invalid character";
	    npt_hhmmss_valid = 0;
	    break;
	}
    }
    if(met_colon < 2) {
	if(reason == NULL) {
	    reason = "there must be exactly 2 or 0colons";
	}
	npt_hhmmss_valid = 0;
    }

    if(npt_hhmmss_valid) {
	reason = "";
	if(reason_ret) {
	    *reason_ret = reason;
	}
	return npt_hhmmss_valid;
    }

    /* invalid */
    if(reason_ret) {
	*reason_ret = reason;
    }
    return 0;
}


/*
 * receive rtsp header and set rtsp_ctrl 
 *              return status code : success
 *                               -1 : failure
 */
int rtsp_recv_header(struct stream_t *stream,struct rtsp_header_t *rtsp_hdr)
{
    int ret = 0;

    ret = rtsp_recv_header_get(stream,rtsp_hdr);
    if(ret < 0) {
	return -1;
    }

    ret = rtsp_parse_response(stream->stream_ctrl->rtsp_ctrl,rtsp_hdr);
    if(ret < 0) {
	return -1;
    }

    return rtsp_hdr->status_code;
}



/*
 * receive rtsp message from stream->sock.
 *      header is guraranteed to be complete after this function,
 *      body should not be complete.
 *      get header only, have to get body later after this function.
 *               return status code : success
 *                               -1 : failure
 */
static int rtsp_recv_header_get(struct stream_t *stream, struct rtsp_header_t *rtsp_hdr)
{
    int ret = 0,i = 0,total = 0;
  
    rtsp_hdr->buffer_len = 0;
    rtsp_hdr->buffer = NULL;
    total = 0;
  
    do { /* get rtsp reply */
	rtsp_hdr->buffer_len += BUFSIZE_1K;
	rtsp_hdr->buffer = (char *)xrealloc(rtsp_hdr->buffer,
					    rtsp_hdr->buffer_len + 1);

	i = recv_data(stream,rtsp_hdr->buffer + total,BUFSIZE_1K);
	if(i <= 0) {
	    display(MSDL_ERR,"rtsp_recv_header error: recv_data() returned %d\n",i);
	    goto failed;
	}
	total += i;
    
	rtsp_hdr->buffer[total] = '\0'; /* for rtsp_is_entire_header */
    } while(!rtsp_is_entire_header(rtsp_hdr));
    
    /* rtsp_hdr->buffer_size is length in buffer, not the malloc()ed size.  */
    rtsp_hdr->buffer_len = total;
    rtsp_hdr->buffer[total] = '\0';
  

    ret = rtsp_response_parse(rtsp_hdr);
    if(ret < 0) {
	display(MSDL_ERR,"response RTSP header parse failed\n");
	goto failed;
    }

    /* push body back !!! */
    if(rtsp_hdr->body_len) {
	stream_data_push_back(stream,rtsp_hdr->body,rtsp_hdr->body_len);
    }
  
    /* rtsp_hdr->buffer *ONLY* contains header, no body follows */
    memset(rtsp_hdr->body,0,rtsp_hdr->body_len);

    /* dbg */
    display(MSDL_DBG,"rtsp header===========\n"
	    "%s\n"
	    "==(%d bytes)====================\n",
	    rtsp_hdr->buffer,strlen(rtsp_hdr->buffer));
  
 
   /* success */
    return rtsp_hdr->status_code;
  
  failed:
    if(rtsp_hdr->buffer) free(rtsp_hdr->buffer);
    rtsp_hdr->buffer = NULL;
    return -1;
}



/*
 * set fields which are common in all rtsp packet. 
 * CSeq and Session field should be present in
 * every rtsp packet.
 */
int rtsp_set_standard_fields(struct rtsp_ctrl_t *rtsp_ctrl,
			     struct rtsp_header_t *rtsp_hdr)
{
    char buf[20];
    snprintf(buf,20,"Cseq: %u",rtsp_ctrl->cseq);
    rtsp_set_field(rtsp_hdr,buf);
  
    if(rtsp_ctrl->session) {
	char *buf2;
	buf2 = (char *)xmalloc(strlen(rtsp_ctrl->session) + 15);
	sprintf(buf2,"Session: %s",rtsp_ctrl->session);
	rtsp_set_field(rtsp_hdr,buf2);
	free(buf2);
    }

    return 0;
}


/*
 * send rtsp header (rtsp_hdr->buffer)
 */
int rtsp_send_request(struct stream_t *stream,
		      struct rtsp_header_t *rtsp_hdr)
{
    int ret;
  
    /* dbg */
    display(MSDL_DBG,"SEND rtsp header ------------>\n"
	    "%s\n--(%d bytes)---------------<\n",
	    rtsp_hdr->buffer,(int)rtsp_hdr->buffer_len);
    
    ret = xsend(stream->netsock->sock,rtsp_hdr->buffer,rtsp_hdr->buffer_len);
  
    /* OK change stream->stream_ctrl->rtsp_ctrl->cseq!! */
    stream->stream_ctrl->rtsp_ctrl->cseq++;
  
    return ret;
}



/*
 * set basic stuff and send OPTIONS request.
 * this can be used to determine  which protocol to use,
 * depending on its server.
 *              return value    sock : success
 *                                -1 : failure
 */
int rtsp_connect(struct stream_t *stream)
{
    int sock;
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct rtsp_ctrl_t *rtsp_ctrl = stream_ctrl->rtsp_ctrl;
    struct url_t *url = stream->url;
    
    
    set_serverinfo(stream->serverinfo,url->hostname,url->port,NULL,0,RTSP_PORT);
  
    rtsp_ctrl->server = NULL;
    rtsp_ctrl->cseq = 1;
    rtsp_ctrl->server_state = 0;
    rtsp_ctrl->server_caps  = 0;
    rtsp_ctrl->session = NULL;
    rtsp_ctrl->get_media_packet = NULL;
    /* make mrl */
    rtsp_make_mrl(rtsp_ctrl,stream->serverinfo->host,stream->serverinfo->port,url->filepath);

    sock = server_connect(stream->serverinfo->connect_host,stream->serverinfo->connect_port);
    if(sock < 0) { /* couldn't connect for some reason. (port closed maybe) */
	goto failed;
    }

    
    stream->netsock->sock = sock; /* save socket id */
    return sock;

  failed:
    return -1;
}




/*
 * make mrl from url and set to rtsp_ctrl->mrl
 * mrl is "rtsp://server.com:port/path/to/file.foo"
 * --IMPORTANT--
 * request URI must be complete according to RFC
 */
int rtsp_make_mrl(struct rtsp_ctrl_t *rtsp_ctrl,char *host,int port,char *filepath)
{
    int len = 0;
    len = strlen(host) + strlen(filepath) + 32; /* 32 is enough */
  
    rtsp_ctrl->mrl = (char *)xmalloc(len);
    snprintf(rtsp_ctrl->mrl,len,"rtsp://%s:%i%s",
	     host,port,filepath);
    return 1;
}



/*
 * parse rtsp response
 * return value:   1 ... success
 *                -1 ... parse error
 */
int rtsp_parse_response(struct rtsp_ctrl_t *rtsp_ctrl,
			struct rtsp_header_t *rtsp_hdr)
{
    char *field;
    int answer_cseq;

    if((field = rtsp_get_field(rtsp_hdr,"Alert")) != NULL) {
	display(MSDL_ERR,"*** Alert ***\n%s\n",field);
    }

  
    if((field = rtsp_get_field(rtsp_hdr,"Cseq")) != NULL) {
	sscanf(field,"%d",&answer_cseq);
	if(answer_cseq != rtsp_ctrl->cseq - 1) {
	    /* -1 because cseq is incremented in build_request */
	    display(MSDL_DBG,"warning: Cseq mismatch, got %u, expected %u\n",
		    answer_cseq,rtsp_ctrl->cseq - 1);
	}
    }
  
    if((field = rtsp_get_field(rtsp_hdr,"Server")) != NULL) {
	while(*field == ' ') field++;
	if(rtsp_ctrl->server) { /* already has it */
	    if(strcmp(rtsp_ctrl->server,field)) { /* different server */
		display(MSDL_DBG,"warning: got different server\n"
			"    old: %s\n"
			"    new: %s\n",rtsp_ctrl->server,field);
		free(rtsp_ctrl->server);
		rtsp_ctrl->server = strdup(field);
	    }
	}
	else { /* not set yet */
	    rtsp_ctrl->server = strdup(field);
	}
    }
  
    if((field = rtsp_get_field(rtsp_hdr,"Session")) != NULL) {
	while(*field == ' ') field++;
	if(rtsp_ctrl->session) {
	    if(strcmp(rtsp_ctrl->session,field)) { /* different session */
		display(MSDL_DBG,"warning: got different session\n"
			"    old: [%s]\n"
			"    new: [%s]\n",rtsp_ctrl->session,field);
		free(rtsp_ctrl->session);
		rtsp_ctrl->session = strdup(field);
	    }
	}
	else {
	    rtsp_ctrl->session = strdup(field);
	}
    }
  
    /* real only, ignore in other protocol... */
    if((field = rtsp_get_field(rtsp_hdr,"RealChallenge1")) != NULL) {
	while(*field == ' ') field++;
	if(rtsp_ctrl->challenge) {
	    if(strcmp(rtsp_ctrl->challenge,field)) { /* different server */
		display(MSDL_DBG,"warning: got different client challenge\n"
			"    old: %s\n"
			"    new: %s\n",rtsp_ctrl->challenge,field);
		free(rtsp_ctrl->challenge);
		rtsp_ctrl->challenge = strdup(field);
	    }
	}
	else {
	    rtsp_ctrl->challenge = strdup(field);
	}
    }
    
    return 1;
}



/*
 * rtsp_response_parse :  parse rtsp response header 
 * make rtsp_hdr from raw data in rtsp_hdr->buffer
 *
 *    return value :        -1 ... ERROR
 *                           0 ... already parsed.
 *                           1 ... success.
 */
int rtsp_response_parse(struct rtsp_header_t *rtsp_hdr)
{
  
    char *hdr_ptr, *ptr;
    char *field = NULL;
  
    int pos_hdr_sep, hdr_sep_len;
    size_t len;
  
    if(rtsp_hdr == NULL) return -1;
    if(rtsp_hdr->is_parsed) return 0; /* already parsed. */
    
    /* get first word  */
    hdr_ptr = strstr(rtsp_hdr->buffer, " ");
    if(hdr_ptr == NULL) {
	display(MSDL_ERR,"Malformed answer : No %20 separator\n");
	return -1;
    }
  
    len = hdr_ptr - rtsp_hdr->buffer;
    rtsp_hdr->protocol = (char *)xmalloc(len + 1);
    strncpy(rtsp_hdr->protocol,rtsp_hdr->buffer,len);
    rtsp_hdr->protocol[len] = '\0';
  

    /* 1. set method */
    rtsp_hdr->method = strdup(rtsp_hdr->protocol);
  
    if(!strncmp(rtsp_hdr->protocol,"RTSP",4)) { /* RTSP message*/
    
	/* 2. get RTSP status code */
	if(sscanf(++hdr_ptr,"%d",&(rtsp_hdr->status_code)) != 1) {
	    display(MSDL_ERR,"Malformed answer : No rtsp status code!!\n");
	    return -1;
	} 
    
	hdr_ptr += 4; /* "[0-9][0-9][0-9] " */
    
	/* 3. get reason phrase */
	ptr = strstr(hdr_ptr,"\n");
	if(ptr == NULL) {
	    display(MSDL_ERR,"Malformed answer : unable to get reason_phrase\n");
	    return -1;
	}
	len = ptr - hdr_ptr; // len of reason phrase.

	rtsp_hdr->reason_phrase = (char *)xmalloc(len + 1);
	strncpy(rtsp_hdr->reason_phrase,hdr_ptr,len);
	if(rtsp_hdr->reason_phrase[len - 1] == '\r') { // M$ style newline!
	    len --; // we don't need \r.
	}
	rtsp_hdr->reason_phrase[len] = '\0'; // terminate string
    } 
    else if(!strncmp(rtsp_hdr->protocol,"SET_PARAMETER",strlen("SET_PARAMETER"))) {
	rtsp_hdr->status_code = RTSP_STATUS_SET_PARAMETER;
    }
    else if(!strncmp(rtsp_hdr->protocol,"OPTIONS",strlen("OPTIONS"))) {
	rtsp_hdr->status_code = RTSP_STATUS_OPTIONS;
    }
    else if(!strncmp(rtsp_hdr->protocol,"ANNOUNCE",strlen("ANNOUNCE"))) {
	rtsp_hdr->status_code = RTSP_STATUS_ANNOUNCE;
    }
    else {  /* NOT RTSP ---> abort */
	display(MSDL_ERR,"Protocol not RTSP, server says '%s'",rtsp_hdr->protocol);
	return -1;
    }
  
  
    hdr_sep_len = 4; /* header separator length */
    ptr = strstr(rtsp_hdr->buffer,"\r\n\r\n");
    if(!ptr) {
	ptr = strstr(rtsp_hdr->buffer,"\n\n");
	if(!ptr) {
	    display(MSDL_ERR,"Header may be incomplete!\n");
	    return -1;
	}
	hdr_sep_len = 2;
    }
    pos_hdr_sep = ptr - rtsp_hdr->buffer;
  
    /* points to first line after method line. */
    hdr_ptr = strstr(rtsp_hdr->buffer,"\n") + 1;

    /* parse of first line [DONE] */
  
  
    /* get all fields. they are separated by '\n' */
    do {
	ptr = hdr_ptr;
	while(*ptr != '\r' && *ptr != '\n') ptr++;
	len  = ptr - hdr_ptr;

	if(len == 0) break; /* met \n\n --> end of header! */
    
	field = (char *)xrealloc(field,len + 1); // +1 for '\0'
	strncpy(field,hdr_ptr,len);
	field[len] = '\0';
    
    
	rtsp_set_field(rtsp_hdr,field);
	hdr_ptr = ptr + ((*ptr == '\r') ? 2 : 1); /* points to next line */
    } while(hdr_ptr < (rtsp_hdr->buffer + pos_hdr_sep));
  
    if(field) {
	free(field);
    }

    /*
      rtsp_hdr->buffer_len is length of header total data received
    */
    if(pos_hdr_sep + hdr_sep_len < rtsp_hdr->buffer_len) {
	rtsp_hdr->body = rtsp_hdr->buffer + (pos_hdr_sep + hdr_sep_len);
	rtsp_hdr->body_len = rtsp_hdr->buffer_len - (pos_hdr_sep + hdr_sep_len);
    }
  
    /* mark parsed */
    rtsp_hdr->is_parsed = 1;
    
  
    return 1;
}





/*
 * start rtsp streaming.
 * 
 *    return value :   negative or 0  ... error
 *                                 1  ... success
 */
int rtsp_streaming_start(struct stream_t *stream)
{
    
    struct rtsp_header_t *rtsp_answer = NULL;

    int header_size;
  
    char *answer = NULL; /* temporary pointer */
    char *server = NULL;
    char *redirected = NULL;

    stream->stream_ctrl->status = STREAMING_HANDSHAKING;

    if(stream->dlopts->dl_protocol == RTSP_WMS) {
	server = strdup("WMServer");
    }
    else { /* still don't know which rtsp protocol, or REAL specified (need challenge) */
	
	stream->netsock->sock = rtsp_connect(stream);
	if(stream->netsock->sock < 0) {
		strcpy(m_szLastError, "cannot establish rtsp connection");
	    goto failed;
	}
	
	real_rtsp_options(stream,&rtsp_answer);

	if(rtsp_answer == NULL) {
		strcpy(m_szLastError, "rtsp connection failed");
	    goto failed;
	}
	
	/* get server name */
	if((answer = rtsp_get_field(rtsp_answer,"Server")) != NULL) {
	    while(*answer == ' ') answer++;  /* skip space */
	    server = strdup(answer);
	}
	else {
	    if((rtsp_get_field(rtsp_answer,"RealChallenge1")) != NULL) {
		server = strdup("Real");
	    }
	    else {
		server = strdup("Unknown Server");
	    }
	}
    }
  
    /* real or helix server (supported) */
    if(strstr(server,"Real") || strstr(server,"Helix")) {
	
	/* real-rtsp */
	struct rmff_header_t *rmff_header = NULL;	
	int ret = 0;

	/* connection is already setup, by real_rtsp_options called above */
	/* this is the function to do almost all setup process */
	ret = real_setup_and_get_header(stream,&rmff_header);
	
	if((!rmff_header) || (ret <= 0)) { /*  NOT OK  */
	    if((answer = rtsp_get_field(rtsp_answer,"Location")) != NULL) {
		/* redirected */
		while(*answer == ' ') answer++;
		
		redirected = strdup(answer);
		display(MSDL_NOR,"redirected to %s\n",redirected);
		/*
		  TODO redirection support
		  and I have never seen example...
		*/
		goto failed;
	    }
	    else {
		display(MSDL_ERR,"real/helix connection not established\n");
		goto failed;
	    }
	}
    
	/* OK, connection established */
	
	header_size = rmff_dump_header(rmff_header,
				       stream->stream_ctrl->write_buffer);
	stream->stream_ctrl->write_data_len = header_size;
    
	display(MSDL_VER,"rmff_header_size = %d\n",header_size);

	
	/* All Green */
	stream->stream_ctrl->rtsp_ctrl->rmff_header = rmff_header;
	stream->stream_ctrl->file_size     = rmff_header->data->size;
	stream->stream_ctrl->total_packets = rmff_header->data->num_packets;

	stream->stream_ctrl->rtsp_ctrl->get_media_packet = real_rdt_get_media_packet;
	/* to distinguish which rtsp */
	stream->stream_ctrl->rtsp_ctrl->rtsp_protocol = RTSP_REAL_PROTOCOL;
	/* for msdl function to know protocol */
	stream->stream_ctrl->protocol = RTSP_REAL;

    }
    else if(strstr(server,"WMServer")) {
	
	/* try rtsp-wms */
	struct asf_headerinfo_t *asf_headerinfo = NULL;
	int ret = 0;
	
	/*
	 * Clean up first.
	 */
	if(stream->netsock->sock) {
	    closesocket(stream->netsock->sock);
	}
	
	/* free rtsp_ctrl_t */
	free_rtsp_ctrl_t(stream->stream_ctrl->rtsp_ctrl);
	stream->stream_ctrl->rtsp_ctrl = new_rtsp_ctrl_t();
	/* free serverinfo_t */
	free_serverinfo_t(stream->serverinfo);
	stream->serverinfo = new_serverinfo_t();
	
	/* DO NOT MESS WITH
	 * stream_t->netsock,
	 * stream_t->url,
	 * stream_t->dlopts,
	 * stream_t->resumeinfo,
	 * these are still valid (or just nothing (resumeinfo))
	 */

	/* re-establish rtsp connection for WMServer */
	stream->netsock->sock = rtsp_connect(stream);

	if(stream->netsock->sock < 0) {
	    /*
	      couldn't connect for some reason.
	      (rtsp port probably closed)
	     */
	    display(MSDL_ERR,"rtsp-wms connection not established\n");
	    display(MSDL_ERR,"server probably does not accept rtsp\n"
		    "retry using mmst protocol\n");

	    stream->stream_ctrl->status = STREAMING_OTHER_PROTOCOL;
	    stream->stream_ctrl->retry_protocol = MMST;	    
	    goto failed;
	}

    
	ret = wmserver_setup_and_get_header(stream,&asf_headerinfo);

	if(ret == 0) { /* retry    */
	    /* probably non-wmserver */
	    display(MSDL_ERR,"server probably does not accept rtsp\n"
		    "retry using mmst protocol\n",server);
	    stream->stream_ctrl->status = STREAMING_OTHER_PROTOCOL;
	    stream->stream_ctrl->retry_protocol = MMST;	    
	    
	    goto failed;
	}
	else if((!asf_headerinfo) || (ret < 0)) {       /* no retry */
	    display(MSDL_ERR,"rtsp setup failed\n");
	    goto failed;
	}

	
	/* All Green */
	stream->stream_ctrl->rtsp_ctrl->asf_headerinfo = asf_headerinfo;    /* set infomation */
	stream->stream_ctrl->packet_length = asf_headerinfo->fileh->max_packet_size;
	stream->stream_ctrl->file_size = asf_headerinfo->fileh->file_size;
	stream->stream_ctrl->total_packets = asf_headerinfo->fileh->num_packets;

	stream->stream_ctrl->rtsp_ctrl->get_media_packet = wmserver_rtp_get_media_packet;

	/* distinguish which rtsp */
	stream->stream_ctrl->rtsp_ctrl->rtsp_protocol = RTSP_WMS_PROTOCOL;
	/* for msdl function to know protocol */
	stream->stream_ctrl->protocol = RTSP_WMS;
	
    }
    else { /* unsupported servers */
	sprintf(m_szLastError, "server type [%s] not supported\n",server);
	
	stream->stream_ctrl->rtsp_ctrl->rtsp_protocol = RTSP_UNKNOWN_PROTOCOL;
	goto failed;
    }

    
    if(server) free(server);
    if(rtsp_answer) free_rtsp_header(rtsp_answer);
    if(redirected) free(redirected);
  
    stream->stream_ctrl->status = STREAMING_DOWNLOADING;
    
    return 1; /* success */
  
  failed:
    if(server)      free(server);
    if(rtsp_answer) free_rtsp_header(rtsp_answer);
    if(redirected)  free(redirected);
    return -1;
}




/*
 * new_rtsp_header : create new RTSP header
 */
struct rtsp_header_t *new_rtsp_header(void)
{
    struct rtsp_header_t *hdr;
    hdr = (struct rtsp_header_t *)xmalloc(sizeof(struct rtsp_header_t));
    return hdr;
}



/*
 * free RTSP header
 */
void free_rtsp_header(struct rtsp_header_t *h)
{
    struct rtsp_field_t *field, *prev;
  
    if(h == NULL) return; // rtsp_hdr is not malloc()ed yet.

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
 * rtsp_get_next_field will get next field with 'filed_name'
 */
char *rtsp_get_field(struct rtsp_header_t *rtsp_hdr, const char *field_name)
{
    if(!rtsp_hdr || !field_name) return NULL;
  
    rtsp_hdr->field_search_pos = rtsp_hdr->first_field;
    rtsp_hdr->field_search = (char *)xrealloc(rtsp_hdr->field_search,
					      strlen(field_name) + 1);
    /* copy field name first. */
    strcpy(rtsp_hdr->field_search, field_name);

    /* get first field value with this field_name. */
    return rtsp_get_next_field(rtsp_hdr);
}



/*
 * return field string after "rtsp_hdr->field_search".
 *        NULL if not found.
 */
char *rtsp_get_next_field(struct rtsp_header_t *rtsp_hdr)
{
    char *ptr;
    struct rtsp_field_t *field;

    if(!rtsp_hdr) return NULL;
    field = rtsp_hdr->field_search_pos;
  
    while(field) {
	ptr = strstr(field->field_name,":");
	if(ptr == NULL) return NULL; // the header is not valid...
	if(!strncmp(field->field_name,rtsp_hdr->field_search,
			ptr - field->field_name)) { // found field!!!!
	    ptr++; // skip colon.
	    while(*ptr == ' ') ptr++; // skip %20
	    rtsp_hdr->field_search_pos = field->next; // points to next field.
	    return ptr; // return the string without filed name!!
	}
	field = field->next;
    }
    return NULL; // NOT FOUND
}



/*
 * rtsp_set_field : make new field and attach it to last_field->next.
 */
void rtsp_set_field(struct rtsp_header_t *rtsp_hdr, const char *field_name)
{
    struct rtsp_field_t *new_field;
  
    if(rtsp_hdr == NULL || field_name == NULL) return;
  
    new_field = (rtsp_field_t *)xmalloc(sizeof(struct rtsp_field_t));

    new_field->next = NULL;
    new_field->field_name = (char *)xmalloc(strlen(field_name) + 1);
    strcpy(new_field->field_name, field_name);
  
    if(rtsp_hdr->last_field == NULL) {
	rtsp_hdr->first_field = new_field; // this was first filed!!
    }
    else {
	rtsp_hdr->last_field->next = new_field; // attach to last.
    }
    rtsp_hdr->last_field = new_field;
    rtsp_hdr->field_nb++;
}



void rtsp_set_uri(struct rtsp_header_t *rtsp_hdr,const char *uri)
{
    if(rtsp_hdr == NULL || uri == NULL) return;
    rtsp_hdr->uri = (char *)xmalloc(strlen(uri) + 1);
    strcpy(rtsp_hdr->uri,uri);
}



void rtsp_set_method(struct rtsp_header_t *rtsp_hdr, const char *method)
{
    if(rtsp_hdr == NULL || method == NULL) return;

    rtsp_hdr->method = (char *)xmalloc(strlen(method) + 1);
    strcpy(rtsp_hdr->method,method);
}



/*
 * wrappers for each request
 */
int rtsp_200ok(struct stream_t *stream,int cseq,char *session)
{
    int ret;
    int buflen = 100 + strlen(rtsp_protocol_version) + strlen(session);
    char *buf = (char *)xmalloc(buflen + 1);
  
    snprintf(buf,buflen,
	     "%s 200 OK\r\n"
	     "Cseq: %u\r\n"
	     "Session: %s\r\n"
	     "\r\n",
	     rtsp_protocol_version,
	     cseq,
	     session);
  
    ret = xsend(stream->netsock->sock,buf,strlen(buf));
    display(MSDL_DBG,"=send 200 OK============\n%s\n=================\n",buf);
  
    free(buf);
    return ret;
}



/* OPTIONS */
char *rtsp_request_options(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"OPTIONS");
    rtsp_set_uri(rtsp_hdr,request_uri);
    return (rtsp_build_request(rtsp_hdr));
}


/* DESCRIBE */
char *rtsp_request_describe(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"DESCRIBE");
    rtsp_set_uri(rtsp_hdr,request_uri);
    return (rtsp_build_request(rtsp_hdr));
}


/* SETUP */
char *rtsp_request_setup(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"SETUP");
    rtsp_set_uri(rtsp_hdr,request_uri);  
    return (rtsp_build_request(rtsp_hdr));
}


/* SET_PARAMETER */
char *rtsp_request_set_parameter(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"SET_PARAMETER");
    rtsp_set_uri(rtsp_hdr,request_uri);
    return (rtsp_build_request(rtsp_hdr));
}


/* GET_PARAMETER */
char *rtsp_request_get_parameter(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"GET_PARAMETER");
    rtsp_set_uri(rtsp_hdr,request_uri);
    return (rtsp_build_request(rtsp_hdr));
}


/* PLAY */
char *rtsp_request_play(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"PLAY");
    rtsp_set_uri(rtsp_hdr,request_uri);
    return (rtsp_build_request(rtsp_hdr));
}


/* TEARDOWN */
char *rtsp_request_teardown(struct rtsp_header_t *rtsp_hdr,char *request_uri)
{
    rtsp_set_method(rtsp_hdr,"TEARDOWN");
    rtsp_set_uri(rtsp_hdr,request_uri);
    return (rtsp_build_request(rtsp_hdr));
}



/*
 * make complete rtsp_header_t.
 * firstline is first line, such as OPTIONS, DESCRIBE, etc... (see rtsp)
 * the request string goes to rtsp_hdr->buffer
 */
char *rtsp_build_request(struct rtsp_header_t *rtsp_hdr)
{
    char *ptr;
    int len = 0;
    struct rtsp_field_t *field;

    if(!rtsp_hdr) return NULL;
    if(!rtsp_hdr->method) return NULL;
    if(!rtsp_hdr->uri) return NULL;
  
    /*
     * culculate the request length.
     */
    len = strlen(rtsp_hdr->method) + strlen(rtsp_hdr->uri) +
	strlen(rtsp_protocol_version) + 2 + 2 ; /* 3 is for spaces between*/
  
    /* fields */
    field = rtsp_hdr->first_field;
    while(field) {
	len += strlen(field->field_name) + 2;
	field = field->next;
    }
    /* CRLF at the end */
    len += 2;
    /* request body    */
    if(rtsp_hdr->body) {
	len += rtsp_hdr->body_len;
    }
  
    if(rtsp_hdr->buffer) {
	free(rtsp_hdr->buffer);
	rtsp_hdr->buffer = NULL;
    }
 
    if(rtsp_hdr->body_len)
	len += rtsp_hdr->body_len;
  
    rtsp_hdr->buffer_len = len;
    rtsp_hdr->buffer = (char *)xmalloc(len + 1); /* 1 for '\0' */
  
    /* 
     * build the request
     */
    ptr = rtsp_hdr->buffer;

    ptr += sprintf(ptr,"%s %s %s\r\n",rtsp_hdr->method,rtsp_hdr->uri,
		   rtsp_protocol_version);
  
    field = rtsp_hdr->first_field;
    /* fields */
    while(field != NULL) {
	ptr += sprintf(ptr,"%s\r\n",field->field_name);
	field = field->next;
    }
    ptr += sprintf(ptr,"\r\n");
  
    if(rtsp_hdr->body != NULL) {
	memcpy(ptr,rtsp_hdr->body,rtsp_hdr->body_len);
    }
  
    return rtsp_hdr->buffer;
}



/*
 * judges if rtsp_hdr is complete RTSP header, or still needs some parts.
 *    return value :       0 ... NOT complete
 *                         1 ... COMPLETE!!
 */
int rtsp_is_entire_header(struct rtsp_header_t *rtsp_hdr)
{
    if(rtsp_hdr == NULL) return 0; /* unlikely, but error */
  
    if(rtsp_hdr->buffer == NULL) return 0;   /* nothing received. */

    if(strstr(rtsp_hdr->buffer,"\r\n\r\n") ||
       strstr(rtsp_hdr->buffer,"\n\n")) {
	return 1;
    }
  
    return 0;
}


static struct rtsp_ctrl_t *new_rtsp_ctrl_t(void)
{
    struct rtsp_ctrl_t *ctrlt = 
	(struct rtsp_ctrl_t *)xmalloc(sizeof(struct rtsp_ctrl_t));

    /* allocate other protocol controllers in
       each protocol initiation functions,
       such as rmff_header or asf_headerinfo...
    */
  
    ctrlt->prev_ts = -1;
    ctrlt->prev_stream_number = -1;
    ctrlt->rtsp_protocol = RTSP_UNKNOWN_PROTOCOL; /* off course unknown by default */
    return ctrlt;
}


static void free_rtsp_ctrl_t(struct rtsp_ctrl_t *ctrlt)
{
    if(ctrlt->rtsp_protocol == RTSP_REAL_PROTOCOL) {
	if(ctrlt->rmff_header) {
	    free_rmff_header_t(ctrlt->rmff_header);
	}
    }
    else if(ctrlt->rtsp_protocol == RTSP_WMS_PROTOCOL) {
	if(ctrlt->asf_headerinfo) {
	    free_asf_headerinfo_t(ctrlt->asf_headerinfo);
	}
    }

    if(ctrlt->mrl)   free(ctrlt->mrl);
    if(ctrlt->server) free(ctrlt->server);
    if(ctrlt->session) free(ctrlt->session);
    if(ctrlt->etag)     free(ctrlt->etag);
    if(ctrlt->challenge) free(ctrlt->challenge);
  
    free(ctrlt);
}



struct stream_t *rtsp_streaming_init()
{
    struct stream_t *stream = streaming_init_common();
    stream->stream_ctrl->rtsp_ctrl = new_rtsp_ctrl_t();
  
    stream->start = rtsp_streaming_start;
    stream->read  = rtsp_streaming_read;
    stream->close = rtsp_streaming_close;
  
    return stream;
}



void rtsp_streaming_close(struct stream_t *stream)
{
    if(stream == NULL) return;
    
    /* TEARDOWN */
    if(stream->stream_ctrl->status == STREAMING_DOWNLOADING || 
       stream->stream_ctrl->status == STREAMING_FINISHED) {
	struct rtsp_header_t *rtsp_hdr;
	int ret;
	/* send teardown request to make server happier. */
	rtsp_hdr = new_rtsp_header_with_standard_fields(stream->stream_ctrl->rtsp_ctrl);
	rtsp_request_teardown(rtsp_hdr,stream->stream_ctrl->rtsp_ctrl->mrl);
	ret = rtsp_send_request_and_free(stream,rtsp_hdr);
    }
  
    if(stream->netsock->sock > 0) { /* valid socket --> close */
	closesocket(stream->netsock->sock);
    }
    
    free_rtsp_ctrl_t(stream->stream_ctrl->rtsp_ctrl);
    streaming_close_common(stream);
}


