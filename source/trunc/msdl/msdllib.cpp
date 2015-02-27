/***********************************************************************
 *    msdllib.c:  utility functions
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


#include "stdafx.h"
#include <sys/stat.h>

#include "msdl.h"
#include "msdllib.h"
#include "network.h"



/* ignore case strchr */
char *xstrcasechr(const char *s1,int c)
{
    const char *hey = s1;
    int ch = tolower(c);
    if(!c) {
	return (char *)(s1 + strlen(s1));
    }
    
    for(;*hey && tolower(*hey) != ch;hey++);
    if(*hey) {
	return (char *)hey;
    }
    
    return NULL;
}

/* strstr */
char *xstrstr(const char *s1,const char *s2)
{
    const char *hey = s1;
    const size_t len = strlen(s2);
    if(len) {
	for(;(hey = strchr(hey,*s2)) != 0;hey++) {
	    if(!strncmp(hey,s2,len)) {
		return (char *)hey;
	    }
	}
    }
    return (char *)hey;
}

/* ignor case strstr */
char *xstrcasestr(const char *s1,const char *s2)
{
    const char *hey = s1;
    const size_t len = strlen(s2);
    if(len) {
	for(;(hey = xstrcasechr(hey,*s2)) != 0;hey++) {
	    if(!strncmp(hey,s2,len)) {
		return (char *)hey;
	    }
	}
    }
    return (char *)hey;
}




/*
 * malloc() wrapper
 */
void *xmalloc(const size_t size)
{
    void *p = malloc(size);
    if(!p) {
	fatal_error("could not allocate memory\n");
    }
    memset(p,0,size);
    return p;
}



/*
 * realloc() wrapper
 */
void *xrealloc(void *p,const size_t size)
{
    p = realloc(p,size);
    if(!p) {
	fatal_error("could not reallocate memory\n");
    }
    return p;
}


/*
 * list manipulation functions
 * new, append, search and free
 */
struct list_h *new_list_h(void *p)
{
    struct list_h *newl = (list_h *)xmalloc(sizeof(struct list_h));
    newl->p = p;
    newl->next = NULL;
    newl->prev = NULL;
    return newl;
}


/*
 * append 'p' to 'list'
 */
struct list_h *list_h_append(struct list_h **list,void *p)
{
    /* non-recursive method for fast append */
    struct list_h **cur,**prev;

    for(cur = prev = list ; *cur ; prev = cur,cur = &((*cur)->next));
    /* now *cur points to NULL */
    *cur = new_list_h(p);
    (*cur)->next = NULL;
    (*cur)->prev = *prev; /* if first element, prev is itself*/

    return *cur;
}



/*
 * free first one element of the list, works like queue.
 * return value: new list.
 * do    newone = list_h_free_head(oldone,p,free); etc.
 */
struct list_h *list_h_free_head(struct list_h **list,void (*free_er)(void *))
{
    struct list_h *del = *list;
    if(del == NULL) {
	return NULL; /* do nothing, just return */
    }
    
    *list = (*list)->next;
    
    free_er(del->p);
    free(del);

    return *list;
}



/*
 * count elements in list_h
 */
int list_h_num(struct list_h *list)
{
    int num;
  
    for(num = 0; list ; list = list->next) num++;
    return num;
}



/*
 * search list_h, using 'comp' function.
 */
struct list_h *search_list_h(struct list_h *list,void *p,
			     int (*comp)(void *,void *))
{
    struct list_h *iter;
    if(list == NULL) return NULL;

    /* non-recursive */
    for(iter = list ; iter ; iter = iter->next) {
	if(!comp(iter->p,p))
	    break;
    }
    
    return iter;
}


void free_list_h(struct list_h *list,void (*free_er)(void *))
{
    struct list_h *cur,*next;
    if(list == NULL) return; 

    /* non-recursive */
    for(cur = list ; cur ; cur = next) {
	next = cur->next;
	free_er(cur->p);
	free(cur);
    }
}



/* only4string debuginfo function */
void print_list_h(struct list_h *list)
{
    if(list == NULL) return;

    printf("%s\n",(char *)list->p);
    print_list_h(list->next);
}


/*
 * file utils
 */


/*
 * get file size
 * return value 1 ... success
 *             -1 ... failed
 */
int get_filesize(const char *path,uint64_t *size)
{
    if(!path) {
	goto failed;
    }

    struct stat s;
    if(stat(path,&s) < 0) {
	display(MSDL_ERR,"get_filesize %s: stat() error\n",path);
	perror("");
	goto failed;
    }
    
    *size = (uint64_t)s.st_size;
    return 1;
    
  failed:
    *size = 0;
    return -1;
}

int get_line(char **lineptr,size_t *n,FILE *fp)
{
    return (get_delim(lineptr,n,'\n',fp));
}
	    


/*
 *  return value    read bytes ... bytes in lineptr (not including '\0' at the end)
 *                          -1 ... failed / EOF
 */
int get_delim(char **lineptr,size_t *n,int delim,FILE *fp)
{
    size_t cursize = 0;

    if(lineptr == NULL || n == NULL || fp == NULL) {
	display(MSDL_ERR,"wrong arg to get_delim\n");
	return -1;
    }

    if(*lineptr == NULL || *n == 0) { /* has to allocate buffer */
	*n = BUFSIZE_1K;
	*lineptr = (char *)xmalloc(*n);
	if(*lineptr == NULL) {
	    return -1;
	}
    }

    for(;;) {
	int i = fgetc(fp);
	
	if(cursize + 1 >= *n) { /* buffer must be longer */
	    char *newptr = NULL;
	    *n += BUFSIZE_1K;
	    newptr = (char *)xrealloc(*lineptr,*n);
	    if(!newptr) {
		return -1;
	    }
	    *lineptr = newptr;
	}

	if(i == EOF) { /* failed to get char (EOF or error )*/
	    if(!cursize) {
		return -1;
	    }
	    
	    (*lineptr)[cursize] = '\0';
	    return cursize;
	}

	(*lineptr)[cursize] = i;
	cursize++;
	if(i == delim) {
	    break;
	}
    }

    (*lineptr)[cursize] = '\0';
    return cursize;
}




void dbgdump(const void *str,int size)
{
    if(get_current_loglevel() == MSDL_DBG) {
	int i = 0;
	for(; i < size ; i++) {
	    display(MSDL_DBG,"%02x ",((unsigned char *)str)[i]);
	    if(i % 16 == 15) {
		int j = i - 15;
		display(MSDL_DBG,"    |");
		for(; j <= i ; j++ ) {
		    char c = ((char *)str)[j];
		    if(isprint(c)) display(MSDL_DBG,"%c",c);
		    else           display(MSDL_DBG," ");
		}
		display(MSDL_DBG,"|\n");
	    }
	}
    }
}
