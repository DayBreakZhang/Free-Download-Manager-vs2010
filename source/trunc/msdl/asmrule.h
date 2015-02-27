/***********************************************************************
 *    asmrule.h: interpretting ASMRuleBook in SDP header.
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * based on syntax description in xine-lib program, asmrp.c
 * 
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


#ifndef __ASMRULE_H__
#define __ASMRULE_H__


enum {
    S_ERROR = -1,
    S_NULL,
    S_AND,
    S_OR,

    /* comperizon */
    S_LESS,             /* 3 */
    S_LESSEQ,
    S_EQ,
    S_MOREEQ,
    S_MORE,             /* 7 */
    /* comparizon */
  
    S_ID, /* $Bandwidth or $OLDfoobar */
    S_NUM,

    S_SUBSTI, /* not used for Not So Serious parse*/
  
    S_LPAREN,
    S_RPAREN,
  
} symbols;



enum {
    O_ERR = -1,
    O_NULL,
    O_AND,
    O_OR,

    /* comparizon */
    O_LESS,        /* 3 */
    O_LESSEQ,
    O_EQ,
    O_MOREEQ,
    O_MORE,        /* 7 */
    /* comparizon */
  
    O_ID, /* $Bandwidth or $OLDfoobar */
    O_NUM,
  
} operators;


struct c_desc { /* condetion_desc */
    char *whole_line;
    char *cur_p;

    int op;
    int val;
    char *id;
    int id_len;
    /* ignores ID, just tell that it was id by setting O_ID */
};


struct node_t {
    int op;
    struct node_t *left;
    struct node_t *right;
};


int asmrule_match(char *rulestr,int bw);





#endif /* __AMSRP_H__ */
