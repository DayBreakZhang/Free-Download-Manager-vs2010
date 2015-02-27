/***********************************************************************
 *    msdl.h:  media stream download header file.
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 * See README for program usage and information.
 * See COPYING for license information.
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


#ifndef __MSDL_H__
#define __MSDL_H__

//#include <inttypes.h>

enum {
    STREAM_CHECK_DATA_TIME = 5,
};

enum {
    AUTO_RETRY_DEFAULT  = 10,
    AUTO_RETRY_INFINITE = -1,
};

/*
 * for parsing command line and environment options
 */
struct options_t {
    struct list_h *local_filename_list;

    char *logfile;
    char *protocol;
    char *username;
    char *password;
    char *http_proxy;

    int loglevel; /* 0:quiet   1:normal   2:verbose   3:debug */
    int auto_retry_times;
    int resume;
    
    unsigned int bandwidth;

    
    char *speed;
    char *range;

    /* ftp  */
    int no_passive_ftp_f; /* default is passive ftp */

    /* http & ftp */
    char *byterange;

    /* timeouts */
    char *stream_timeout;
    
    struct list_h *targets; /* target_t list */
};



enum {
    FORCE_NOT_METAFILE = -1,
    IS_NOT_METAFILE = 0,
    IS_METAFILE = 1,
};


struct target_t {
    int metafile_f; /* tri-state */
    char *target_name;
};



/*
 * option to pass to download_streaming function.
 * everything not file pointer and url goes here.
 */
struct download_opts_t {
    int dl_protocol;      /* specify protocol */
    
    unsigned int bandwidth;
    char *speed;
    char *range;             /* the range option in string   : "3.0-5.0"*/
    char *byterange;
    
    int auto_retry;
    int resume_download;  /* resume flag     */

    union {
	char *proxy;      /* raw string data */
	char *http_proxy; /* proxy string    */
    };

    /* ftp optoins */
    int no_passive_ftp; /* ftp default is passive mode */


    char *stream_timeout;

    /* username & password */
    char *username;
    char *password;
};


struct dlresult_t {
    struct list_h *success_list; /* char[] array */
    struct list_h *failed_list;  /* char[] array */
};


struct target_t *new_target_t(char *name,int meta_f);
void free_target_t(struct target_t *t);
struct options_t *new_options_t(void);
void free_options_t(struct options_t *opt);
struct download_opts_t *new_download_opts_t(void);
void free_download_opts_t(struct download_opts_t *dlopts);
struct dlresult_t *new_dlresult_t(void);
void free_dlresult_t(struct dlresult_t *dlr);

int msdl(struct target_t *target,struct options_t *options,
	 struct dlresult_t *result);




#endif /* __MSDL_H__ */
