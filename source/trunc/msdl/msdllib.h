/***********************************************************************
 *    msdllib.h:  utility functions
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * utility functions.
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


#ifndef __MSDLLIB_H__
#define __MSDLLIB_H__

#include "stdafx.h"

#define ssize_t size_t;

/*
 * functions to handle bitorder
 * 
 * bswap_* : swap upper and lower bits
 * put*_*  : put number to p in specified bitorder
 * get*_*  : get number from p in specified bitorder
 */


static inline uint16_t bswap_16(uint16_t x)
{
    return (x>>8) | (x<<8);
}

static inline uint32_t bswap_32(uint32_t x)
{
    x= ((x<<8)&0xFF00FF00) | ((x>>8)&0x00FF00FF);
    return (x>>16) | (x<<16);
}

static inline uint64_t bswap_64(uint64_t x)
{
    x= ((x<< 8)&0xFF00FF00FF00FF00ULL) | ((x>> 8)&0x00FF00FF00FF00FFULL);
    x= ((x<<16)&0xFFFF0000FFFF0000ULL) | ((x>>16)&0x0000FFFF0000FFFFULL);
    return (x>>32) | (x<<32);
}

static inline void put32_be(void *p,uint32_t x)
{
    *((uint8_t *)p    ) = x >> 24 & 0xff;
    *((uint8_t *)p + 1) = x >> 16 & 0xff;
    *((uint8_t *)p + 2) = x >>  8 & 0xff;
    *((uint8_t *)p + 3) = x       & 0xff;
}

static inline void put32_le(void *p,uint32_t x)
{
    *((uint8_t *)p    ) = x       & 0xff;
    *((uint8_t *)p + 1) = x >>  8 & 0xff;
    *((uint8_t *)p + 2) = x >> 16 & 0xff;
    *((uint8_t *)p + 3) = x >> 24 & 0xff;
}

static inline void put16_be(void *p,uint16_t x)
{
    *((uint8_t *)p    ) = x >>8   & 0xff;
    *((uint8_t *)p + 1) = x       & 0xff;
}

static inline void put16_le(void *p,uint16_t x)
{
    *((uint8_t *)p    ) = x       & 0xff;
    *((uint8_t *)p + 1) = x >>8   & 0xff;
}

static inline void put8(void *p,uint8_t x)
{
    *(uint8_t *)p       = x       & 0xff;
}


static inline uint32_t get32_be(void *p)
{
    return *(uint8_t *)p << 24 | *((uint8_t *)p + 1) << 16 |
	*((uint8_t *)p + 2) << 8 | *((uint8_t *)p + 3);
}

static inline uint32_t get32_le(void *p)
{
    return *(uint8_t *)p | *((uint8_t *)p + 1) << 8 |
	*((uint8_t *)p + 2) << 16 | *((uint8_t *)p + 3) << 24;
}

static inline uint64_t get64_be(void *p)
{
    return (uint64_t)get32_be((uint8_t *)p) << 32 | (uint64_t)get32_be((uint8_t *)p + 4);
}

static inline uint64_t get64_le(void *p)
{
    return (uint64_t)get32_le((uint8_t *)p + 4) << 32 | (uint64_t)get32_le((uint8_t *)p);
}

static inline uint16_t get16_be(void *p)
{
    return *(uint8_t *)p << 8 | *((uint8_t *)p + 1);
}

static inline uint16_t get16_le(void *p)
{
    return *(uint8_t *)p | *((uint8_t *)p + 1) << 8;
}

static inline uint8_t get8(void *p)
{
    return *(uint8_t *)p;
}

/* get n bytes little endian */
static inline uint64_t getnb_le(void *p,int n)
{
    uint64_t val = 0;
    for(; n > 0 ; n--) {
	val <<= 8;
	val += *((uint8_t *)p + n - 1);
    }
    return val;
}

/* get n bytes big endian */
static inline uint64_t getnb_be(void *p,int n)
{
    uint64_t val = 0;
    int i = 0;
    for(; i < n; i++) {
	val <<= 8;
	val += *((uint8_t *)p + i);
    }
    return val;
}





/*
 * Big/Little Endian to Machine Endian
 */
#ifdef WORDS_BIGENDIAN

#define be2me_16(x) (x)
#define be2me_32(x) (x)
#define be2me_64(x) (x)
#define le2me_16(x) bswap_16(x)
#define le2me_32(x) bswap_32(x)
#define le2me_64(x) bswap_64(x)

#else /* LITTLE ENDIAN */

#define be2me_16(x) bswap_16(x)
#define be2me_32(x) bswap_32(x)
#define be2me_64(x) bswap_64(x)
#define le2me_16(x) (x)
#define le2me_32(x) (x)
#define le2me_64(x) (x)

#endif


/* list head */
struct list_h {
    void *p;
    struct list_h *next;
    struct list_h *prev;
};

/* insert NULL after freeing memory */
#define free(p) do {free((p));(p) = NULL;} while(0)


char *xstrcasechr(const char *s1,int c);
char *xstrstr(const char *s1,const char *s2);
char *xstrcasestr(const char *s1,const char *s2);


void *xmalloc(const size_t size);
void *xrealloc(void *p,const size_t size);

/* list  */
struct list_h *new_list_h(void *p);
struct list_h *list_h_append(struct list_h **list,void *p);
struct list_h *search_list_h(struct list_h *list,void *p,int (*comp)(void *,void *));
struct list_h *list_h_free_head(struct list_h **list,void (*free_er)(void *));
int list_h_num(struct list_h *list);

void free_list_h(struct list_h *list,void (*free_er)(void *));

int get_filesize(const char *path,uint64_t *size);
int get_line(char **lineptr,size_t *n,FILE *fp);
int get_delim(char **lineptr,size_t *n,int delim,FILE *fp);
void dbgdump(const void *str,int size);

#endif /* __MSDLLIB_H__ */
