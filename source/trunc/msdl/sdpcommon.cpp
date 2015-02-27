/***********************************************************************
 *    sdpcommon.c:  sdp common operations
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * Common operations to handle sdp (session description protocol) data.
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

#include "msdllib.h"
#include "sdpcommon.h"



/*
 *
 * it's alwasys [decoded length] < [encoded length]  (it's guranteed)
 *
 *   return value:    length of original (before base64 encode string) bytearray
 *
 */
int base64_decode(char *enc,char *dec,int decsize)
{
    int i,j;
    char dtable[256];
  
    
    for( i = 0; i < 255; i++) {
	dtable[i] = 0x80;
    }
    for(i = 'A' ; i <= 'Z'; i++) {
	dtable[i] = 0 + (i - 'A');
    }
    for(i = 'a' ; i <= 'z'; i++) {
	dtable[i] = 26 + (i - 'a');
    }
    for(i = '0' ; i <= '9'; i++) {
	dtable[i] = 52 + (i - '0');

    }
    dtable['+'] = 62;
    dtable['/'] = 63;
    dtable['='] = 0;
    
    
    for(i = j = 0; i<strlen(enc) ; i += 4) {
	char input[4], output[3];
	
	input[0] = dtable[(enc[i + 0] & 0xff)];
	input[1] = dtable[(enc[i + 1] & 0xff)];
	input[2] = dtable[(enc[i + 2] & 0xff)];
	input[3] = dtable[(enc[i + 3] & 0xff)];
    
    
	output[0] = (input[0] << 2) | (input[1] >> 4);
	output[1] = (input[1] << 4) | (input[2] >> 2);
	output[2] = (input[2] << 6) | (input[3]);
	
	if(j >= decsize) goto overflow;
	dec[j] = output[0];
	if(enc[i + 2] == '=') return j+1;
	
	if(j + 1 >= decsize) goto overflow;
	dec[j + 1] = output[1];
	if(enc[i + 3] == '=') return j+2;

	if(j + 2 >= decsize) goto overflow;
	dec[j + 2] = output[2];
	j += 3;
    }

    return j;
    
  overflow:
    display(MSDL_ERR,"internal error: base64 overflow!\n");
    return -1;
}



int is_line(char *line,char *keyword,char **buf,int *len)
{
  
    if(!strncmp(line,keyword,strlen(keyword))) {
	int newlen;

	line += strlen(keyword);
	newlen = strchr(line,'\n') ? (strchr(line,'\n') - line) : strlen(line);
	if(line[newlen - 1] == '\r') newlen--;
    
	if(*line == '"') {
	    char *last;
	    last = line + newlen;
	    while(*last != '"') last--;
	    newlen = last - line - 1; /* 1 is for " */
	    line++; /* points to inside "foo" */
	}
    
	if(*len < newlen + 1) {
	    *buf = (char *)xrealloc(*buf,newlen + 1);
	    *len = newlen + 1;
	}
    
	memcpy(*buf,line,newlen);
	(*buf)[newlen] = 0;
	/* printf("is_line %s newlen = %d\n%s\n",keyword,newlen,*buf); */
    
	return 1;
    }
    else {
	return 0;
    }
}



char *next_line(char *data)
{
    data = strchr(data,'\n');
    if(data) data++;
    return data;
}



int keep_dec_size(char **buf,int *buflen,int keep)
{
    if(*buflen < keep) {
	*buflen = keep;
	*buf = (char *)xrealloc(*buf,keep);
	return keep;
    }
    else return *buflen;
}


