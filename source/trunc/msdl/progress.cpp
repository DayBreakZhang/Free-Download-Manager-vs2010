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
#include "stdafx.h"

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "progress.h"
#include "snprintf.h"

#include "gettimeofday.h"

static void fill_buffer_with_ws(char *buffer,int buflen);


void progress_dl_start(struct progressinfo_t *pgi)
{	
    gettimeofday(&(pgi->tv_dl_start),NULL);
    memcpy(&(pgi->tv_last_disp_update), &(pgi->tv_dl_start),sizeof(struct timeval));
    memcpy(&(pgi->tv_last_speed_update),&(pgi->tv_dl_start),sizeof(struct timeval));
    memcpy(&(pgi->tv_last_etl_speed_update), &(pgi->tv_dl_start),sizeof(struct timeval));
    
    pgi->last_speed_size_written = 0;
    pgi->last_etl_speed_size_written = 0;
    pgi->speed = 0;
    pgi->etl_speed = 0;
}


void progress_update(struct progressinfo_t *pgi,
		     uint64_t entire_size,uint64_t size_written)
{
    /*
     * tv_last_time is to update download speed.
     */
    struct timeval tv_cur_time;
    struct timeval tv_diff_disp;              /* time since last display update   */
    struct timeval tv_diff_speed;             /* time since last speed update     */
    struct timeval tv_diff_etl_speed;         /* time since last etl speed update */
    struct timeval tv_uptime;                 /* time since donwload start        */

    gettimeofday(&tv_cur_time,NULL);

    timersub(&tv_cur_time,&(pgi->tv_last_disp_update),&tv_diff_disp);
    timersub(&tv_cur_time,&(pgi->tv_last_speed_update),&tv_diff_speed);
    timersub(&tv_cur_time,&(pgi->tv_last_etl_speed_update),&tv_diff_etl_speed);
    timersub(&tv_cur_time,&(pgi->tv_dl_start),&tv_uptime);
    
    /* 1 sec speed update     */
    if(tv_diff_speed.tv_sec >= PROGRESS_SPEED_UPDATE_THRESHOLD) {
	/* update speed */
	pgi->speed = (size_written - pgi->last_speed_size_written) / tv_diff_speed.tv_sec;
	/* update last_* info */
	pgi->last_speed_size_written = size_written;
	memcpy(&(pgi->tv_last_speed_update),&tv_cur_time,sizeof(struct timeval));
    }
    /* last 3 second speed for remain time guess */
    if(tv_diff_etl_speed.tv_sec >= PROGRESS_ETL_SPEED_UPDATE_THRESHOLD) {
	/* update etl speed */
	pgi->etl_speed =
	    (size_written - pgi->last_etl_speed_size_written) / tv_diff_etl_speed.tv_sec;
		
	pgi->last_etl_speed_size_written = size_written;
	memcpy(&(pgi->tv_last_etl_speed_update),&tv_cur_time,sizeof(struct timeval));
    }
    /* 0.5 sec display update */
    if(tv_diff_disp.tv_sec >= 1 || tv_diff_disp.tv_usec > 500000) {
	/* update output */
	
	/*
	 * if uptime was less than 8 seconds, don't display ETA.
	 * you can just wait.
	 */
	if(tv_uptime.tv_sec < PROGRESS_ETL_DISPLAY_MIN_TIME) {
	    display_progress_info(entire_size,size_written,pgi->speed,-1);
	}
	else {
	    display_progress_info(entire_size,size_written,pgi->speed,pgi->etl_speed);
	}
	/* update display */
	memcpy(&(pgi->tv_last_disp_update),&tv_cur_time,sizeof(struct timeval));
    }
}



/*
 * progress line look like this..
 * DL: xxxxx/xxxxx B -- xxx%           6.1K/s (11chars)    ETA --:--:-- 
 *
 * @filsize    : entire file size (what server told)
 * @downloaded : current file size (downloaded)
 * @speed      : speed to display bandwidth
 * @etl_speed  : speed for ETA
 */
void display_progress_info(uint64_t filesize,uint64_t downloaded,
			   int64_t speed,int64_t etl_speed)
{
    int termwidth = get_current_termwidth();
    
    char *buffer = (char *)xmalloc(termwidth);
    static char column1[45];
    static char column2[11];
    static char column3[13];
    
    memset(buffer,0,termwidth);
    
    create_recved_bytes(column1,45,filesize,downloaded);
    strncat(buffer,column1,termwidth - 1);
    fill_buffer_with_ws(buffer,termwidth-24);

    create_dl_speed(column2,11,speed);
    strncat(buffer,column2,termwidth - 1);
    fill_buffer_with_ws(buffer,termwidth-13);
    
    create_remain_time(column3,13,filesize,downloaded,etl_speed);
    strncat(buffer,column3,termwidth - 1);
    fill_buffer_with_ws(buffer,termwidth);
    
    display(MSDL_NOR,"\r%s",buffer);
    free(buffer);
}


/*
 * get time since pgi.tv_dl_start
 * return value: uptime in second
 */
time_t progress_get_dl_uptime(struct progressinfo_t *pgi,struct timeval *tv_uptime)
{
    struct timeval tvu,tvcur;
    
    gettimeofday(&tvcur,NULL);
    timersub(&tvcur,&(pgi->tv_dl_start),&tvu);
    
    if(tv_uptime) {
	memcpy(tv_uptime,&tvu,sizeof(struct timeval));
    }

    return tvu.tv_sec;
}


/*
 * get donwload bandwidth so far.
 * counts from dl_start in progressinfo
 * return value: bandwidth
 */
int64_t progress_get_average_bandwidth(struct progressinfo_t *pgi,uint64_t current_size)
{
    struct timeval tv_uptime;
    double seconds;

    progress_get_dl_uptime(pgi,&tv_uptime);
    if(tv_uptime.tv_sec == 0 && tv_uptime.tv_usec == 0) {
	return -1; /* 0 microseconds passed, which is very illegal... */
    }
    else {
	seconds = tv_uptime.tv_sec + (double)tv_uptime.tv_usec * 0.000001;
	return (int64_t)((double)current_size / seconds);
    }
    return -1;
}




static void fill_buffer_with_ws(char *buffer,int buflen)
{
    if(strlen(buffer) < buflen) {
	memset(buffer + strlen(buffer),' ',buflen - strlen(buffer) - 1);
    }
    buffer[buflen - 1] = '\0';
}


/*
 * display download progress.
 */
void create_recved_bytes(char *buffer,int width,
			 uint64_t filesize,uint64_t downloaded)
{
    memset(buffer,0,width);

    if(width < 45) {
	return;
    }

    if(filesize == 0 || downloaded > filesize * 2) { /* don't display over 200%, it's probably real-time stream */
	snprintf(buffer,width - 1,"DL: %lld B",(long long)downloaded);
    }
    else {
	/* snprintf is safe. */
	snprintf(buffer,width - 1,"DL: %lld/%lld B -- %3d%%", /* 15chars + numsx2 */
		 (long long)downloaded,
		 (long long)filesize,
		 (int)(((double)downloaded/(double)filesize) * 100));
    }
}



/*
 * display download speed.
 * empty string if speed < 0
 */
void create_dl_speed(char *buffer,int width,
		     int64_t speed)
{
    memset(buffer,0,width);

    if(width < 11) {
	return;
    }

    if(speed < 0) {
	strncpy(buffer,"",width);
    }
    else if(speed > 1000000000000LL) {
	snprintf(buffer,width - 1,"%.1fT/s",(double)speed / 1000000000000LL);
    }
    else if(speed > 1000000000) {
	snprintf(buffer,width - 1,"%.1fG/s",(double)speed / 1000000000);
    }
    else if(speed > 1000000) {
	snprintf(buffer,width - 1,"%.1fM/s",(double)speed / 1000000);
    }
    else if(speed > 1000) {
	snprintf(buffer,width - 1,"%.1fK/s",(double)speed / 1000);
    }
    else {
	snprintf(buffer,width - 1,"%.1dB/s",(int)speed);
    }
}



/*
 * display ETL (Estimated Time Left)
 * empty string if etl_speed < 0
 */
void create_remain_time(char *buffer,int width,
			uint64_t entire_size,uint64_t current_size,int64_t etl_speed)
{
    memset(buffer,0,width);

    if(width < 13) {
	return; /* prevent overflow */
    }

    if(etl_speed < 0) {
	strncpy(buffer,"",width);
    }
    else if(entire_size && entire_size == current_size) {
	snprintf(buffer,width - 1,"Complete");                  /* 8 chars */
    }
    else if(entire_size) {
	uint64_t etl = 0;

	if(etl_speed) {
	    etl = (entire_size - current_size)/ etl_speed;
	}
	
	if((etl_speed == 0) || (etl / 3600) > 100) { /* etl == 0 || 2slow:) */
	    snprintf(buffer,width - 1,"ETA --:--");             /* 9 chars */
	}
	else {
	    if(etl/3600) { /* have to display hour */
		snprintf(buffer,width - 1,"ETA %02d:%02d:%02d", /* 12 chars */
			 (int)(etl / 3600),(int)((etl % 3600 / 60)),(int)(etl % 60));
	    }
	    else {
		snprintf(buffer,width - 1,"ETA %02d:%02d",      /* 9 chars  */
			 (int)((etl % 3600 / 60)),(int)(etl % 60));

	    }
	}
    }
}
