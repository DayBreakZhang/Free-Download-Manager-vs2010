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
 * (from MPlayer-1.0rc2/url.h)
 */

/* 
 * URL Helper
 * by Bertrand Baudet <bertrand_baudet@yahoo.com>
 * (C) 2001, MPlayer team.
 */



#ifndef __URL_H__
#define __URL_H__

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * example:       exmp://foo.bar.com/example/hoge.asf
 */
struct url_t {
    char *url;         /* exmp://foo.bar.com/example/hoge.asf */
    char *protocol;    /* exmp                                */
    char *hostname;    /* foo.bar.com                         */
    char *file;        /* foo.bar.com/example/hoge.asf        */
    char *filepath;    /* /example/hoge.asf                   */
    unsigned int port; /* some port                           */
    int protocol_type; /* protocol type                       */
    char *username;
    char *password;
};

struct url_t *new_url_t(const char *url);
void free_url_t(struct url_t *u);
void copy_url_t(struct url_t *url,struct url_t *srcurl);
//inline int is_url_valid_char(int c);
inline int is_url_valid_char(int c)
{
    return (isalpha(c) ||
	    isdigit(c) ||
	    c == '_' ||
	    c == '%' ||
	    c == '+' ||
	    c == '*' ||
	    c == '!' ||
	    c == '?' ||
	    c == ':' ||
	    c == ';' ||
	    c == '.' ||
	    c == ',' ||
	    c == '/' ||
	    c == '~' ||
	    c == '-' ||
	    c == '=' ||
	    c == '&' ||
	    c == '#' ||
	    c == '@' ||
	    c == '$');

}

void url_unescape_string(char *dst,char *src);


#endif /* __URL_H__ */
