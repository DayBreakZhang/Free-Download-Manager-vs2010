/***********************************************************************
 *    sdpcommon.h:  sdp common operations
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


#ifndef __SDPCOMMON_H__
#define __SDPCOMMON_H__


int base64_decode(char *enc,char *dec,int decsize);
int is_line(char *line,char *keyword,char **buf,int *len);
char *next_line(char *data);
int keep_dec_size(char **buf,int *buflen,int keep);


#endif /* __SDPCOMMON_H__ */
