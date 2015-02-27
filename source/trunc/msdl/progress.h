/***********************************************************************
 *    progress.c:  download management functions
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 * display progress of donwload.
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


#ifndef __PROGRESS_H__
#define __PROGRESS_H__


enum {
    PROGRESS_SPEED_UPDATE_THRESHOLD = 1,
    PROGRESS_ETL_SPEED_UPDATE_THRESHOLD = 6,
    PROGRESS_ETL_DISPLAY_MIN_TIME = 8,
};



struct progressinfo_t {
/*    uint64_t entire_size;                      entire file size             */
/*    uint64_t size_written;                     current donwloaded file size */
    
    uint64_t last_speed_size_written;         /* size when speed was updated last time     */
    uint64_t last_etl_speed_size_written;     /* size when etl speed was updated last time */
    
    int64_t speed;
    int64_t etl_speed;

    struct timeval tv_dl_start;               /* when download started */
    struct timeval tv_last_disp_update;       /* time when display updated last time   */
    struct timeval tv_last_speed_update;      /* time when speed updated last time     */
    struct timeval tv_last_etl_speed_update;  /* time when etl speed updated last time */
    
};


void progress_dl_start(struct progressinfo_t *pgi);
void progress_update(struct progressinfo_t *pgi,
		     uint64_t entire_size,uint64_t size_written);
time_t progress_get_dl_uptime(struct progressinfo_t *pgi,struct timeval *tv_uptime);
int64_t progress_get_average_bandwidth(struct progressinfo_t *pgi,uint64_t current_size);

void display_progress_info(uint64_t filesize,uint64_t downloaded,
			   int64_t speed,int64_t etl_speed);

void create_recved_bytes(char *buffer,int width,
			 uint64_t filesize,uint64_t downloaded);
void create_dl_speed(char *buffer,int width,
		     int64_t speed);
void create_remain_time(char *buffer,int width,
			uint64_t entire_size,uint64_t current_size,int64_t etl_speed);



#endif /* __PROGRESS_H__ */
