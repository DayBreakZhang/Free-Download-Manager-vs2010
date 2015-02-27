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



#ifndef __DISPLAY_H__
#define __DISPLAY_H__


#ifndef COLOR_SUPPORT
#define COLOR_SUPPORT 1
#endif


/*
 * color escape sequence defines
 */
#if COLOR_SUPPORT == 1

#define HL_NONE     "\033[m"
#define HL_RED      "\033[01;31m"
#define HL_GREEN    "\033[01;32m"
#define HL_YELLOW   "\033[01;33m"
#define HL_BLUE     "\033[01;34m"
#define HL_MAGENTA  "\033[01;35m"
#define HL_CYAN     "\033[01;36m"

#else 

#define HL_NONE	    ""
#define HL_RED      ""
#define HL_GREEN    ""
#define HL_YELLOW   ""
#define HL_BLUE     ""
#define HL_MAGENTA  ""
#define HL_CYAN     ""

#endif


/*
 * colors available in most color terminals...
 */
enum {
    C_DEFAULT = 0,
    C_RED,
    C_GREEN,
    C_YELLOW,
    C_BLUE,
    C_MAGENTA,
    C_CYAN,
    NUM_COLORS,
} colors_available;



/*
 * display levels
 */
enum {
    MSDL_OUTPUT_ERR = 1 << 4, /* stderr output */
    
    MSDL_QUIET = 0,     /* no message */
    MSDL_NOR   = 1,     /* normal     */
    MSDL_VER   = 2,     /* verbose    */
    MSDL_DBG   = 3,     /* debug      */

    MSDL_ERR = MSDL_NOR | MSDL_OUTPUT_ERR,
} display_flags;


struct displayinfo_t {
    int loglevel;
    int use_color;
    int termwidth;
    FILE *logfp;
};


struct options_t;

void init_dispinfo(struct options_t *options);
void clean_dispinfo(void);
void dispinfo_set_loglevel(int lovlevel);
int get_current_termwidth(void);
int get_current_loglevel(void);
void colorize(int color);
void display(const int flag,const char *fmt, ...);
void fatal_error(const char *fmt, ...);


#endif /* __DISPLAY_H__ */

