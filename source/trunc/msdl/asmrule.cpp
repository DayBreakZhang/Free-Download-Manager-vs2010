/***********************************************************************
 *    asmrule.c: interpretting ASMRuleBook in SDP header.
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

/*
 * Copyright notice of MPlayer project
 * which some part of msdl is based on.
 * (from MPlayer-1.0rc2/stream/realrtsp/asmrp.c)
 */

/*
 * This file was ported to MPlayer from xine CVS asmrp.c,v 1.2 2002/12/17 16:49:48
 */
/*
 * Copyright (C) 2002 the xine project
 *
 * This file is part of xine, a free video player.
 * 
 * xine is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * xine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 *
 *
 * a parser for real's asm rules
 *
 * grammar for these rules:
 *

   rule_book  = { rule }
   rule       = ( '#' condition { ',' assignment } | [ assignment {',' assignment} ]) ';'
   assignment = id '=' const
   const      = ( number | string )
   condition  = comp_expr { ( '&&' | '||' ) comp_expr }
   comp_expr  = operand { ( '<' | '<=' | '==' | '>=' | '>' ) operand }
   operand    = ( '$' id | num | '(' condition ')' )

 */


#include "stdafx.h"
#include "msdllib.h"
#include "asmrule.h"



static struct c_desc *new_c_desc(char *asmrule);
static void free_c_desc(struct c_desc *cd);
static struct node_t *new_node_t(int o,struct node_t *l,struct node_t *r);
static void free_node_t(struct node_t *p);
static int get_sym(struct c_desc *cd);
static struct node_t *cond_expr(struct c_desc *cd);
static struct node_t *comp_expr(struct c_desc *cd);
static struct node_t *term_expr(struct c_desc *cd);

static int eval_tree(struct node_t *p);



/* 
 * this must be thread safe . no global, no static.
 *           return value  next symbol : success
 *                              S_NULL : end
 *                             S_ERROR : error
 *  forereading is not necessary , so do not do it.
 */
static int get_sym(struct c_desc *cd)
{
    char *p;
    int len;
    int val;
  
    /* skip white space */
    while(*cd->cur_p == ' ') cd->cur_p++;
  
    if(*cd->cur_p == '$') { /* $Foobar */
	p = cd->cur_p + 1;
	while(isalpha(*p)) p++;
	len = p - cd->cur_p - 1;
    
	if(cd->id_len < len + 1) {
	    cd->id = (char *)xrealloc(cd->id,len + 1);
	    cd->id_len = len + 1;
	}
	memcpy(cd->id,cd->cur_p + 1,len);
	cd->id[len] = '\0';
	cd->cur_p = p;
	cd->op = S_ID;
    }
    else if(isdigit(*cd->cur_p)) {
	val = 0;
	while(isdigit(*cd->cur_p)) { /* always decimal */
	    val *= 10;
	    val += *cd->cur_p - '0';
	    cd->cur_p++;
	}
	cd->op = S_NUM;
	cd->val = val;
    }
    else if(*cd->cur_p == '<') {
	cd->cur_p++;
	if(*cd->cur_p == '=') {
	    cd->cur_p++;
	    cd->op = S_LESSEQ;
	}
	else {
	    cd->op = S_LESS;
	}
    }
    else if(*cd->cur_p == '>') {
	cd->cur_p++;
	if(*cd->cur_p == '=') {
	    cd->cur_p++;
	    cd->op = S_MOREEQ;
	}
	else {
	    cd->op = S_MORE;
	}
    }
    else if(*cd->cur_p == '&') {
	cd->cur_p++;
	if(*cd->cur_p == '&') {
	    cd->cur_p++;
	    cd->op = S_AND;
	}
	else {
	    cd->op = S_ERROR;   /* & operator is not supported */
	}
    }
    else if(*cd->cur_p == '|') {
	cd->cur_p++;
	if(*cd->cur_p == '|') {
	    cd->cur_p++;
	    cd->op = S_OR;
	}
	else {
	    cd->op = S_ERROR;   /* | operator is not supported */
	}
    }
    else if(*cd->cur_p == '=') {
	cd->cur_p++;
	if(*cd->cur_p == '=') {
	    cd->cur_p++;
	    cd->op = S_EQ;
	}
	else {
	    cd->op = S_SUBSTI;
	}
    }
    else if(*cd->cur_p == '(') {
	cd->cur_p++;
	cd->op = S_LPAREN;
    }
    else if(*cd->cur_p == ')') {
	cd->cur_p++;
	cd->op = S_RPAREN;
    }
    else if(*cd->cur_p == ',' || *cd->cur_p == ';') { /*end of condition ',' */
	cd->op = S_NULL; /*END*/
    }
    else {
	display(MSDL_ERR,"asmrule: syntax error\n");
	cd->op = S_ERROR;
    }
  
    return cd->op;
}



static struct node_t *new_node_t(int o,struct node_t *l,struct node_t *r)
{
    struct node_t *n = (struct node_t *)xmalloc(sizeof(struct node_t));
    n->op = o;
    n->left= l;
    n->right = r;
  
    return n;
}



static void free_node_t(struct node_t *p)
{
    if(!p) return; /* just to make sure*/
  
    if(p->op == O_ID || p->op == O_NUM) {
	/* p->left is char *, or int * (malloced)*/
	free(p->left);
	p->left = NULL;
    }
    else {
	if(p->left) free_node_t(p->left);
	if(p->right) free_node_t(p->right);
    }
    free(p);
}





static struct c_desc *new_c_desc(char *asmrule)
{
    struct c_desc *cd = (struct c_desc *)xmalloc(sizeof(struct c_desc));
    cd->whole_line = asmrule;
    cd->cur_p = cd->whole_line;

    cd->op = S_NULL;
    cd->val = 0;
    cd->id = (char *)xmalloc(100);
    cd->id_len = 100;

    get_sym(cd);
    return cd;
}



static void free_c_desc(struct c_desc *cd)
{
    if(!cd) return;
    if(cd->id) free(cd->id);
    free(cd);
}



static struct node_t *term_expr(struct c_desc *cd)
{
    struct node_t *p;
    char *id;
    int *i;
  
    switch(cd->op) {

    case S_NUM:
	i = (int *)xmalloc(sizeof(int));
	*i = cd->val;
	p = new_node_t(O_NUM,(struct node_t *)i,NULL);
	get_sym(cd);
	break;
    
    case S_ID:
	id = strdup(cd->id);
	p = new_node_t(O_ID,(struct node_t *)id,NULL);
	get_sym(cd);
	break;
    
    case S_LPAREN:
	get_sym(cd);
	p = cond_expr(cd);
	if(!p) { /* NULL */
	    display(MSDL_ERR,"asmrule: parse error\n");
	}
	else if(cd->op != S_RPAREN) {
	    display(MSDL_ERR,"asmrule: no closing ')'\n");
	}
	get_sym(cd);
	break;

    default:
	display(MSDL_ERR,"asmrule: syntax error at %s\n",cd->cur_p);
	p = NULL;
    }
  
    return p;
}



static struct node_t *comp_expr(struct c_desc *cd)
{
    int tok,opr;
    struct node_t *p,*q;
  
    p = term_expr(cd);
  
    /* don't do while, see syntax. */
    if(S_LESS <= cd->op && cd->op <= S_MORE) {
	tok = cd->op;
	get_sym(cd);
	q = term_expr(cd);

	switch(tok) {
	case S_LESS:   opr = O_LESS;   break;
	case S_LESSEQ: opr = O_LESSEQ; break;
	case S_EQ:     opr = O_EQ;     break;
	case S_MOREEQ: opr = O_MOREEQ; break;
	case S_MORE:   opr = O_MORE;   break;
	default:       opr = O_ERR;    break; /* impossible */
	}
	p = new_node_t(opr,p,q);
    }
  
    return p;
}



static struct node_t *cond_expr(struct c_desc *cd)
{
    int tok,opr;
    struct node_t *p,*q;
  
    p = comp_expr(cd);
  
    /* don't do while, see syntax */
    if(cd->op == S_AND || cd->op == S_OR) {
	tok = cd->op;
	get_sym(cd);
	q = comp_expr(cd);
    
	if(tok == S_AND)     opr = O_AND;
	else if(tok == S_OR) opr = O_OR;
	else                 opr = O_ERR; /* impossible */
    
	p = new_node_t(opr,p,q);
    }
  
    return p;
}




/*
 * change id to val. change O_ID to O_NUM
 */
static void insert_id_value(struct node_t *p,char *id,int val)
{
    int *i;
    if(!p) return;
  
    if(p->op == O_ID) {
	if(!strcmp((char *)p->left,id)) {
	    free(p->left);
	    p->left = NULL;
	    i = (int *)xmalloc(sizeof(int));
	    *i = val;
	    p->left = (struct node_t *)i;
	    p->op = O_NUM;
	}
    }
    else if(p->op == O_NUM){
	/* do nothing */
	return;
    }
    else {
	if(p->left)  insert_id_value(p->left,id,val);
	if(p->right) insert_id_value(p->right,id,val);
    }
}



#ifdef DEBUG
/* debugging function */
static void tree_debug(struct node_t *p)
{
    if(p == NULL) {
	printf("NULL!!!!\n");
	return;
    }
  
    if(p->op == O_NUM) {
	printf("number: %d\n",*(int *)p->left);
    }
    else if(p->op == O_ID) {
	printf("id: %s\n",(char *)p->left);
    }
    else { /* tree node */
	tree_debug(p->left);
	printf("op : %d\n",p->op);
	tree_debug(p->right);
    }
}
#endif /* DEBUG */

/*
 * eval by boolean.
 *           return value :    value : num
 *                                 1 : true (bool)
 *                                 0 : false (bool) of error 
 */
static int eval_tree(struct node_t *p)
{
    int lval,rval;
    if(!p) return 0; /* this should not happen in this function */

    switch (p->op) {

    case O_NUM:
	return *(int *)p->left;

    case O_ID: /* not inserted id --> 0 */
	return 0;
    
    case O_AND:
    case O_OR:
    case O_LESS:
    case O_LESSEQ:
    case O_EQ:
    case O_MOREEQ:
    case O_MORE:
	lval = eval_tree(p->left);
	rval = eval_tree(p->right);
	if(p->op == O_AND)    return (lval && rval);
	if(p->op == O_OR)     return (lval || rval);
	if(p->op == O_LESS)   return (lval < rval);
	if(p->op == O_LESSEQ) return (lval <= rval);
	if(p->op == O_EQ)     return (lval == rval);
	if(p->op == O_MORE)   return (lval >= rval);
	if(p->op == O_MOREEQ) return (lval > rval);

    default:
	return 0;
    }
}



/*
 * judge if bw is OK in 'rulestr'
 *          return value:     0 ... no, it's not OK.
 *                        non 0 ... yes, it is. use this rule.
 */
int asmrule_match(char *rulestr,int bw)
{
    int ret = 0;
    struct node_t *p;
    struct c_desc *cd;
  
    if(rulestr[0] != '#') { /* asmrule always start with #*/
	return 1; /* if not, it's no description rule --> always match */
    }
  
    cd = new_c_desc(rulestr + 1);
  
    p = cond_expr(cd);

    /*tree_debug(p); debugging*/
  
    insert_id_value(p,"OldPNMPlayer",0); /* we don't care about old player */
    insert_id_value(p,"Bandwidth",bw);
  
    ret = eval_tree(p);
  
    free_node_t(p);
    free_c_desc(cd);
  
    return ret;
}

