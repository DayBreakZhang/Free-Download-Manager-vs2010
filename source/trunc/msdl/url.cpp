/***********************************************************************
 *    url.c: url utility functions
 ***********************************************************************
 * Copyright (C) 2008 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * url related utility functions, and url parser
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
 * (from MPlayer-1.0rc2/url.c)
 */

/* 
 * URL Helper
 * by Bertrand Baudet <bertrand_baudet@yahoo.com>
 * (C) 2001, MPlayer team.
 */

#include "stdafx.h"

#include "msdllib.h"
#include "network.h"



static void string_separate(const char *original,const char *needle,
			    char **pre,char **post);
static void free_url_members(struct url_t *u);

static void string_separate(const char *original,const char *needle,
			    char **pre,char **post)
{
    char *p = NULL;
    int len = 0;

    p = (char *)strstr(original,needle);
    if(p) { /* found */
	len = p - original;
	*pre = (char *)xmalloc(len + 1);
	strncpy(*pre,original,len);
	(*pre)[len] = '\0';
	
	p += strlen(needle);
	*post = strdup(p);
    }
    else { /* cannot separate */
	*pre = NULL;
	*post = NULL;
    }
}

static void free_url_members(struct url_t *u)
{
    if(u->url)      free(u->url);
    if(u->protocol) free(u->protocol);
    if(u->hostname) free(u->hostname);
    if(u->file)     free(u->file);
    if(u->filepath) free(u->filepath);
    if(u->username) free(u->username);
    if(u->password) free(u->password);
}


void copy_url_t(struct url_t *url,struct url_t *srcurl)
{
    free_url_members(url);
    url->url      = (srcurl->url)      ? strdup(srcurl->url)      : NULL;
    url->protocol = (srcurl->protocol) ? strdup(srcurl->protocol) : NULL;
    url->hostname = (srcurl->hostname) ? strdup(srcurl->hostname) : NULL;
    url->file     = (srcurl->file)     ? strdup(srcurl->file)     : NULL;
    url->filepath = (srcurl->filepath) ? strdup(srcurl->filepath) : NULL;
    url->username = (srcurl->username) ? strdup(srcurl->username) : NULL;
    url->password = (srcurl->password) ? strdup(srcurl->password) : NULL;
}


/*
 * prot://user:password@host:port/path
 */
struct url_t *new_url_t(const char *url_str)
{
    struct url_t *url = NULL;
    char *pre = NULL,*post = NULL;
    char *server_part = NULL;
    char *path_part = NULL;
    char *user_pass = NULL;
    char *host_port = NULL;

    if(!strstr(url_str,"://")) {
	return NULL; /* invalid url*/
    }

    url = (struct url_t *)xmalloc(sizeof(struct url_t));
    
    /* exmp://foo.bar.com/example/hoge.asf */
    url->url = strdup(url_str);
    
    string_separate(url->url,"://",&pre,&post);
    if(pre) {
	url->protocol = strdup(pre);
	url->file = strdup(post);
	free(pre);
	free(post);
	
	string_separate(url->file,"/",&pre,&post);
	if(pre) {
	    server_part = strdup(pre);
	    path_part = strdup(post);
	    free(pre);
	    free(post);
	}
	else {
	    server_part = strdup(url->file);
	}
    }
    
    /* interpret server_part */
    if(server_part) {
	string_separate(server_part,"@",&pre,&post);
	if(pre) { /* user[:pass]'@'host[:port] */
	    user_pass = strdup(pre);
	    host_port = strdup(post);

	    free(pre);
	    free(post);
	}
	else {    /* host[:port] */
	    host_port = strdup(server_part);
	}
	

	/* interpret user_pass */
	if(user_pass) {
	    string_separate(user_pass,":",&pre,&post);
	    if(pre) {
		url->username = strdup(pre);
		url->password = strdup(post);
		free(pre);
		free(post);
	    }
	    else {
		url->username = strdup(user_pass);
	    }
	}

	/* interpret  host_port */
	if(host_port) {
	    string_separate(host_port,":",&pre,&post);
	    if(pre) {
		url->hostname = strdup(pre);
		url->port = atoi(post);
		free(pre);
		free(post);
	    }
	    else {
		url->hostname = strdup(host_port);
		url->port = 0;
	    }
	}
    }
    
    /* interpret path_part */
    if(path_part) {
	int len = strlen(path_part) + 2;
	url->filepath = (char *)xmalloc(len);
	strncpy(url->filepath,"/",len);
	strncat(url->filepath,path_part,len);
    }

    url->protocol_type = protocol_type_from_string(url->protocol);

    /*
      printf("url :%s\n"
      "prot:%s\n"
      "host:%s\n"
      "port:%d\n"
      "file:%s\n"
      "path:%s\n"
      "type:%d\n"
      "user:%s\n"
      "pass:%s\n"
      ,url->url,url->protocol,url->hostname,url->port,url->file,url->filepath,url->protocol_type,
      url->username,url->password);
    */
    
    if(server_part)  free(server_part);
    if(path_part)    free(path_part);
    if(user_pass)    free(user_pass);
    if(host_port)    free(host_port);
    
    return url;

}


void free_url_t(struct url_t *u)
{
    if(!u) return;

    free_url_members(u);
    free(u);
}



/*
 *  unescape url string.
 *  such as : change '%41' to 'A'.
 */
void url_unescape_string(char *dst,char *src)
{
    uint8_t ch,ch1,ch2;
    int i,len;
  
    len = strlen(src);
  
    for(i = 0; i < len; i++) {
	ch = src[i];
	if(ch == '%' && (i < len - 2)) { /* need two more chars after '%' */
	    ch1 = toupper(src[i+1]);
	    ch2 = toupper(src[i+2]);     /* uppercase chars */
      
	    if((('0' <= ch1 && ch1 <= '9') || ('A' <= ch1 && ch1 <= 'F')) && 
	       (('0' <= ch2 && ch2 <= '9') || ('A' <= ch2 && ch2 <= 'F'))) {
		ch1 = ('0' <= ch1 && ch1 <= '9') ? ch1 - '0' : ch1 - 'A';
		ch2 = ('0' <= ch2 && ch2 <= '9') ? ch2 - '0' : ch2 - 'A';
		ch = (ch1 << 4) | ch2;
		i += 2;
	    }
	}
	*dst++ = ch;
    }
    *dst++='\0';
}



/*
 * return true if 'c' is valid url character
 */

