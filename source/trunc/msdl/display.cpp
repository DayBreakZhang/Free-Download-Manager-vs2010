/***********************************************************************
 *    display.c:  utility functions
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * screen display function.
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
#include "display.h"


/*******************************************************
 **                   GLOBALs     
 */
struct displayinfo_t dispinfo = {
    MSDL_NOR, /* default log level    */
    1,        /* default use color    */
    80,       /* default term width   */
    NULL,
};


/*
 * escape sequence for each color
 */
static char *disp_colors[NUM_COLORS] = {HL_NONE,
					HL_RED,
					HL_GREEN,
					HL_YELLOW,
					HL_BLUE,
					HL_MAGENTA,
					HL_CYAN};


void dispinfo_set_loglevel(int loglevel)
{
    dispinfo.loglevel = loglevel;
}



void init_dispinfo(struct options_t *options)
{
    FILE *fp = NULL;

    memset(&dispinfo,0,sizeof(struct displayinfo_t));
    
    dispinfo.loglevel = options->loglevel;
    dispinfo.use_color = 1;//options->use_color;
    dispinfo.termwidth = 80;
    
    /* setup log file fp */
    if(options->logfile) {
	if((fp = fopen(options->logfile,"wb")) ==  NULL) {
	    display(MSDL_ERR,"cannot create log file \"%s\n",options->logfile);
	    perror("");
	    fp = NULL; /* just to make sure */
	}
	dispinfo.logfp = fp;
    }
    else {
	dispinfo.logfp = NULL;
    }
    

}


/* must call this */
void clean_dispinfo(void)
{
    if(dispinfo.logfp) fclose(dispinfo.logfp);
}



int get_current_termwidth(void)
{
    return 80;
}


int get_current_loglevel(void)
{
    return dispinfo.loglevel;
}


/*
 * print escape sequence to stderr
 */
void colorize(int color)
{
    if(dispinfo.use_color) {
	fprintf(stderr,"%s",disp_colors[color]);
    }
}



/*
 * display message
 *         valid flag are : MSDL_ERR   --> go to stderr
 *                          MSDL_NOR   --> go to stderr (but normal message)
 *                          MSDL_VER   --> verbose level output
 *                          MSDL_DBG   --> debug level output
 */
void display(const int flag,const char *fmt, ...)
{
    va_list ap;
    FILE *out = NULL;
    
    if((flag & 0x0f) > dispinfo.loglevel) {
	return;
    }

    va_start(ap,fmt);

    if(dispinfo.logfp) {
	out = dispinfo.logfp;
    }
    else if(flag & MSDL_OUTPUT_ERR) { /* error output --> stderr */
	out = stderr; /* stderr */
    }
    else {
	out = stderr;
    }

    vfprintf(out,fmt,ap);
    fflush(out);
    
    va_end(ap);
}



/*
 * exit after displaying error message
 */
void fatal_error(const char *fmt, ...)
{
    va_list ap;

    va_start(ap,fmt);


    vfprintf(stderr,fmt,ap);
    fflush(stderr);
    
    va_end(ap);
    exit(1);
}

