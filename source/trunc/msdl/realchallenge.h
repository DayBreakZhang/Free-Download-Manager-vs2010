/***********************************************************************
 *    realchallenge.h : for downloading from real server using rtsp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file includes functions for calculating Real ClientChallenge
 * strings, and the code is based on xine-lib and mplayer.
 * Thank you so much.
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


#ifndef __REALCHALLENGE_H__
#define __REALCHALLENGE_H__


void real_calc_challenge2_and_checksum (char *challenge, /* in */
					char *response, char *chksum); /* outs */

#endif /* __REALCHALLENGE_H__ */
