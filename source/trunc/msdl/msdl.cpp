/***********************************************************************
 *    msdl.c:  download management functions
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


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ctype.h>
//#include <unistd.h>
//#include <getopt.h>
//#include <sys/time.h>

#include "msdl.h"
#include "msdllib.h"
#include "display.h"
#include "progress.h"
#include "network.h"
#include "mmst.h"
#include "mmsh.h"
#include "http.h"
#include "ftp.h"
#include "rtsp.h"




struct download_opts_t *set_dlopts_from_options(struct options_t *options,
						struct download_opts_t *dlopts);
static char *create_local_file_name(char *target_str,struct options_t *options);

static int download_target(char *target_str,
			   struct options_t *options,struct dlresult_t *result,
			   char **local_name);
static int prepare_download(char *target_str,struct options_t *options,
			    struct url_t **url_ret,struct download_opts_t **dlopts_ret,
			    char **local_name);
static int do_download(const char *local_name,struct url_t *url,struct download_opts_t *dlopts);

static int streaming_download(const char *local_file,struct url_t *url,
			      struct download_opts_t *dlopts);
static void display_protocol(struct stream_t *stream);
static int filename_cmp(void *a,void *b);
static int is_metafile(char *name);
static int get_url_list_from_file(char *filename,struct list_h **ret);


const char default_file_name_for_empty[] = "file";


/*
 * meta_f ... 1 --> always metafile
 *            0 --> don't know, judge from name
 *           -1 --> NEVER.
 */
struct target_t *new_target_t(char *name,int meta_f)
{
    struct target_t *t = (target_t *)xmalloc(sizeof(struct target_t));
    t->target_name = strdup(name);
    t->metafile_f = meta_f;
    return t;
}



void free_target_t(struct target_t *t)
{
    if(!t) {
	return;
    }
    free(t->target_name);
    free(t);
}



struct options_t *new_options_t(void)
{
    struct options_t *opt = (options_t *)xmalloc(sizeof(struct options_t));
    memset(opt,0,sizeof(struct options_t));
    return opt;
}



void free_options_t(struct options_t *opt)
{
    if(!opt) {
	return;
    }
    
    if(opt->protocol)       free(opt->protocol);
    if(opt->logfile)        free(opt->logfile);
    if(opt->username)       free(opt->username);
    if(opt->password)       free(opt->password);
    if(opt->http_proxy)     free(opt->http_proxy);
    if(opt->speed)          free(opt->speed);
    if(opt->range)          free(opt->range);
    if(opt->byterange)      free(opt->byterange);
    if(opt->stream_timeout) free(opt->stream_timeout);
    
    free_list_h(opt->local_filename_list,free);                /* string list   */
    free_list_h(opt->targets,(void (*)(void *))free_target_t); /* target_t list */

    free(opt);
}


struct download_opts_t *new_download_opts_t(void)
{
    struct download_opts_t *dlopts = (download_opts_t *)xmalloc(sizeof(struct download_opts_t));
    memset(dlopts,0,sizeof(struct download_opts_t));
    
    return dlopts;
}


struct download_opts_t *set_dlopts_from_options(struct options_t *options,
						struct download_opts_t *dlopts)
{
    /*
      set download options, such as bandwidth, some mode, etc.
      !!!! CAUTION !!!!
      these options are applied to all download in target list.
    */

    if((options == NULL) || (dlopts == NULL)) {
	return NULL;
    }
    
    if(options->bandwidth) {
	dlopts->bandwidth = options->bandwidth;
    }
  
    if(options->no_passive_ftp_f) {
	dlopts->no_passive_ftp = 1;
    }
    
    if(options->speed) {
	dlopts->speed = strdup(options->speed);
    }

    if(options->range) {
	dlopts->range = strdup(options->range);
    }

    if(options->byterange) {
	dlopts->byterange = strdup(options->byterange);
    }
    
    if(options->auto_retry_times) {
	dlopts->auto_retry = options->auto_retry_times;
    }

    if(options->stream_timeout) {
	dlopts->stream_timeout = strdup(options->stream_timeout);
    }

    if(options->resume) {
	dlopts->resume_download = 1;
    }

    if(options->username) {
	dlopts->username = strdup(options->username);
    }

    if(options->password) {
	dlopts->password = strdup(options->password);
    }

    if(options->http_proxy) {
	dlopts->http_proxy = strdup(options->http_proxy);
    }

    return dlopts;
}



void free_download_opts_t(struct download_opts_t *dlopts)
{
    if(!dlopts) {
	return;
    }

    if(dlopts->speed) free(dlopts->speed);
    if(dlopts->range) free(dlopts->range);
    if(dlopts->byterange) free(dlopts->byterange);
    if(dlopts->stream_timeout) free(dlopts->stream_timeout);
    if(dlopts->username) free(dlopts->username);
    if(dlopts->password) free(dlopts->password);
    
    free(dlopts);
}



struct dlresult_t *new_dlresult_t(void)
{
    struct dlresult_t *dlr = (dlresult_t *)xmalloc(sizeof(struct dlresult_t));
    memset(dlr,0,sizeof(struct dlresult_t));
    return dlr;
}



void free_dlresult_t(struct dlresult_t *dlr)
{
    if(!dlr) {
	return;
    }
    if(dlr->success_list) free_list_h(dlr->success_list,free);
    if(dlr->failed_list)  free_list_h(dlr->failed_list,free);
  
    free(dlr);
}




/*
 * take 2 urls, a and b. only use filename at the end of url.
 *           return value:     0 ... same file
 *                       : non 0 ... file name differs
 */
static int filename_cmp(void *a,void *b)
{
    char *s = (char *)a,*t = (char *)b;
    s = strrchr(s,'/') + 1;
    t = strrchr(t,'/') + 1;
    
    return strcmp(s,t);
}



/*
 * files with these extensions are regarded as metafiles.
 */
char *metafile_prefixes[] = {
    /* Windows Media metafiles */
    "asx",
    "wvx",
    "wax",
    /* Real Audio metafiles */
    "ram",
    "rpm",
    "smi",
};

char *metafile_starts[] = {
    "meta",
};



/*
 * judge if url 'name' is windows/real media metafile or not, from 
 * metafile_prefixes described above
 *            return value:   0  ... not
 *                            1  ... yes it is.
 */
static int is_metafile(char *name)
{
    int i = 0;
    char *p = NULL;
  
    if((p = strrchr(name,'.'))) {
	p++;
	for(i = 0; i < sizeof(metafile_prefixes)/sizeof(char *) ; i++) {
	    if(!strcmp(metafile_prefixes[i],p)) return 1;
	}
    }
  
    if((p = strrchr(name,'/'))) {
	p++;
	for(i = 0; i < sizeof(metafile_starts)/sizeof(char *) ; i++) {
	    if(!strncmp(metafile_starts[i],p,strlen(metafile_starts[i]))) return 1;
	}
    }

    return 0;
}



/*
 * get string(url) list from file 'filename'
 * for not downloading same URLs again and again,
 * this function returns list via "uniq" filter.
 *
 * @ret  string list ... success
 *       NULL        ... no url in file
 *
 * return value: count ... URLs appear in the file
 *                  -1 ... could not open file
 */
static int get_url_list_from_file(char *filename,struct list_h **ret)
{
    FILE *localfp = NULL;
    struct list_h *url_list = NULL;
    size_t linesize = 0;
    char *line = NULL;
    int i = 0;

    int url_count = 0;
    
    /* 
       try to download first url in the list
       --> maybe playlist contain same url twice
    */
    if((localfp = fopen(filename,"rb")) == NULL) {
	display(MSDL_ERR,"cannot open file %s\n",filename);
	goto failed;
    }
    
    for(;;i++) {
	char *p   = NULL;
	char *sep = NULL;

	int len = get_line(&line,&linesize,localfp);
	if(len < 0) {
	    if(feof(localfp)) {
		break;
	    }
	    else {
		goto failed;
	    }
	}
	
	p = line;
	while((sep = strstr(p,"://"))) { /* contains url string */
	    int url_len = 0;

	    /* protocol is alphabet */
	    for(sep--; sep >= p && isalpha(*sep) ; sep--); 
	    sep++;
	    for(url_len = 0; is_url_valid_char(sep[url_len]); url_len++);
	    sep[url_len] = '\0';
      
	    /* for not downloading same file again and again */
	    if(sep[url_len - 1] != '/') { /*ignore directories */
		
		if(search_list_h(url_list,sep,filename_cmp) == NULL) {
		    /* same file not found */
		    list_h_append(&url_list,strdup(sep));
		    url_count++;
		}
		else {
		    display(MSDL_VER,"file: <%s> is not uniq, ignore this\n",
			    strrchr(sep,'/') + 1);
		}
	    }
      
	    p = &(sep[url_len]) + 1;
	}
    }
    
    free(line);
    fclose(localfp);
    *ret = url_list;
    return url_count;

  failed:
    free(line);
    *ret = NULL;
    return -1;
}



/*
 * main download manager function 
 *
 * 'target' is url or local file which contains url(s) to download
 * 
 * return value:       number of files which successfully donwloaded
 *
 */
int msdl(struct target_t *target,struct options_t *options,struct dlresult_t *result)
{
    int downloaded_files_count = 0;
    int ret;
    
    /*
      set urls to download.
    */
    if(strstr(target->target_name,"://")) { /* network file case */
	char *local_filename = NULL;
	
	ret = download_target(target->target_name,
			      options,
			      result,
			      &local_filename); /* local filename will be returned (may be changed)*/
	
	/* we got metafile from network --> have to download what's inside */
	if((target->metafile_f != FORCE_NOT_METAFILE) && /* -1 is no-metafile flag */
	   (is_metafile(target->target_name) || target->metafile_f == IS_METAFILE) &&
	   (ret >= 0)) { /* download must be success(1) or already done(0)*/

	    if(!strcmp(local_filename,"-")) {
		display(MSDL_NOR,
			"recursive download with stdout is not supported.\n"
			"must save the metafile localy for recursive download.");
	    }
	    else {
		struct target_t *new_target = NULL;
	    
		/* recursive download */                 /* DO NOT DO RECURSIVE AGAIN*/
		new_target = new_target_t(local_filename,FORCE_NOT_METAFILE);
	    
		/* rcursive download file */
		downloaded_files_count += msdl(new_target,options,result);
		free_target_t(new_target);
	    }
	}
	
	if(local_filename) free(local_filename);
    }
    else { /* file list (local file) */
	struct list_h *p = NULL;                  /* iterator */
	struct list_h *target_str_list = NULL;    /* string   */
	int ret = 0;
	ret = get_url_list_from_file(target->target_name,&target_str_list);

	if(ret < 0) { /*could not open file*/
	    return 0;
	}
	else if(ret == 0) {
	    display(MSDL_ERR,"input file \"%s\" does not contain any url\n",target->target_name);
	    return 0;
	}
	
	/* download each files the list*/
	for(p = target_str_list ; p ; p = p->next) {
	    char *target_str = (char *)p->p;
	    struct target_t *target_in_file = NULL;
	    /*
	      create file which contains downloaded data.
	    */
	    target_in_file = new_target_t(target_str,FORCE_NOT_METAFILE);
	    
	    downloaded_files_count += msdl(target_in_file,options,result);

	    free_target_t(target_in_file);
	}
	free_list_h(target_str_list,free);
    }
    
    return downloaded_files_count;
}



/*
 * now from version 1.2.6 you can set multiple local filename for multiple targets
 * means -o file1 -o file2 -o file3,,, stuff.
 * 
 * now it messes with options->local_filename_list
 * make it work as queue.
 */
static char *create_local_file_name(char *target_str,struct options_t *options)
{
    char *local_filename = NULL;
    struct list_h *list = options->local_filename_list;

    if(list && list->p && strcmp((const char *)list->p,"")) { /* NOT the empty filename you want to set */
	local_filename = strdup((const char *)list->p);
	list_h_free_head(&(options->local_filename_list),free); /* string list */
    }
    else if(target_str && strcmp(target_str,"")) {
	char *p = strrchr(target_str,'/');
	if(p && (p[1] != '\0')) { /* do not allow local_filename to be "" (p[0] == '/' now)*/
	    local_filename = strdup(p + 1);
	}
    }

    /* still no filename --> set default filename */
    if((!local_filename) || !strcmp(local_filename,"")) {
	local_filename = strdup(default_file_name_for_empty); /* allocate default file name */
    }
    
    return local_filename;
}



/*
 * download target_str ==> local_save_file
 * and append success/failure results to results list.
 * return value: 1 (do_download() return) ... success
 *               0 ... file already downloaded, and nothing to do
 *              -1 ... faliure
 */
static int download_target(char *target_str,struct options_t *options,struct dlresult_t *result,
			   char **local_name)
{
    struct url_t *url = NULL;                 /* for each target url   */    
    struct download_opts_t *dlopts = NULL;
    int ret = 0;

    ret = prepare_download(target_str, options, 
			   &url,&dlopts,
			   local_name);       /* local filename will be determined */
    if(!ret) {
	goto failed;
    }
    
    ret = do_download(*local_name,url,dlopts);
    
    if(ret > 0) {             /* succeeded */
	list_h_append(&result->success_list,strdup(target_str));
    }
    else if(ret < 0) {        /* failed    */
	list_h_append(&result->failed_list,strdup(target_str));
    }
    else {
	/* ret == 0 which is NO_NEED_TO_DOWNLOAD */
	/* it's not download success but of course not failure */
	/* do nothing  and 0 will be returned */
    }

    
    if(url)             free_url_t(url);
    if(dlopts)          free_download_opts_t(dlopts);
    return ret;

  failed:
    if(url)             free_url_t(url);
    if(dlopts)          free_download_opts_t(dlopts);
    return -1;
}



/*
 * allocate url  and dlopts, from target_str and options
 * return value:  1 ... success  0 ... failure
 */
static int prepare_download(char *target_str,struct options_t *options,
			    struct url_t **url_ret,struct download_opts_t **dlopts_ret,
			    char **local_name)
{
    struct url_t *url = NULL;                 /* for each target url   */    
    struct download_opts_t *dlopts = NULL;
    
    /*
      check if target is really a file
    */
    
    url = new_url_t(target_str);
    if(url == NULL) { /* invalid URL, just continue */
	display(MSDL_VER,"ignored \"%s\"\n",target_str);
	goto ignore;
    }

    /*
     * check if target url is valid
     */
    if(!url->hostname || !strcmp(url->hostname,"")) {
	display(MSDL_NOR,"ignored \"%s\" (no host information)\n",target_str);
	goto ignore;
    }
    else if(!url->filepath || !strcmp(url->filepath,"")) {
	display(MSDL_NOR,"warning: \"%s\" (no filepath)\n",target_str);
    }
    
    *local_name = create_local_file_name(url->filepath,options);
    
    dlopts = new_download_opts_t();
    set_dlopts_from_options(options,dlopts);
    dlopts->dl_protocol = url->protocol_type;

    /*
      if url starts with "http", try MMSH first, and fallback on HTTP.
      also, if MMST and HTTP_PROXY specified, use http.
    */
    if(url->protocol_type == HTTP ||
       (url->protocol_type == MMST && dlopts->http_proxy)) {
	dlopts->dl_protocol = MMSH;
    }

    /*
      if url starts with "mms", try rtsp because it's the standard.
      pure mmst protocol is obsolate.
    */
    if(url->protocol_type == MMST) {
	dlopts->dl_protocol = RTSP_WMS;
    }
    
    /*
      choose protocol if specified
    */
    if(options->protocol) {
	dlopts->dl_protocol = protocol_type_from_string(options->protocol);
	if(dlopts->dl_protocol == UNKNOWN_PROTOCOL) {
	    display(MSDL_ERR,"protocol [ %s ] not supported: ignore this option \n",
		    options->protocol);
	    dlopts->dl_protocol = url->protocol_type;
	}
    }
    
    *url_ret = url;
    *dlopts_ret = dlopts;
    return 1;

  ignore:
    if(url)      free_url_t(url);
    if(dlopts)   free_download_opts_t(dlopts);
    *url_ret = NULL;
    *dlopts_ret = NULL;
    return 0;
}



/*
 * do actual download
 * streaming_download() wrapper
 * return value:   what streaming_download returns 
 * ((CAUTION))
 * streaming_download will return 0 if no need for downloading, and
 * in metafile case, it should be continue
 */
static int do_download(const char *local_name,struct url_t *url,struct download_opts_t *dlopts)
{
    int ret = 0;
    int retry_again = 0;
    
    /*
      display download file name
    */
    if(strcmp(local_name,"-")) {
	display(MSDL_NOR,"download [ %s ]\n",local_name);
    }
    display(MSDL_VER,"url: %s\n",url->url);
    
    /*
      download file
    */
    do {
	retry_again = 0;
	ret = streaming_download(local_name,url,dlopts);
	
	if((ret == -2) && ((dlopts->auto_retry > 0) || (dlopts->auto_retry == AUTO_RETRY_INFINITE))) {

	    if(dlopts->auto_retry == AUTO_RETRY_INFINITE) {
		display(MSDL_NOR,"*** try downloading again \n",dlopts->auto_retry);
	    }
	    else {
		dlopts->auto_retry--;
		display(MSDL_NOR,"*** try downloading again (%d more tries) ***\n",dlopts->auto_retry);
	    }

	    dlopts->resume_download = 1; /* set resume enable when retry */
	    retry_again = 1;
	}
	
    } while(retry_again);
    
    return ret;
}



/*
 * print protocol name to screen.
 */
static void display_protocol(struct stream_t *stream)
{
    display(MSDL_VER,"download protocol: ");
    switch (stream->stream_ctrl->protocol) {
    case MMST:
	display(MSDL_VER,"mmst");
	break;
    case MMSH:
	display(MSDL_VER,"mmsh");
	break;
    case RTSP_REAL:
	display(MSDL_VER,"rtsp - real");
	break;
    case RTSP_WMS:
	display(MSDL_VER,"rtsp - wms");
	break;
    case HTTP:
	display(MSDL_VER,"http");
	break;
    case FTP:
	display(MSDL_VER,"ftp");
	break;
    default:
	display(MSDL_ERR," :) ...bug");
	break;
    }
  
    display(MSDL_VER,"\n\n");
}

struct stream_t *streaming_init(struct url_t *url,struct download_opts_t *dlopts)
{
    struct stream_t *stream = NULL;

    switch(dlopts->dl_protocol) {
    case MMST:
	stream = mmst_streaming_init();
	break;
    case HTTP:
	stream = http_streaming_init();
	break;
    case MMSH:
	stream = mmsh_streaming_init();
	break;
    case FTP:
	stream = ftp_streaming_init();
	break;
    case RTSP:
    case RTSP_WMS:
    case RTSP_REAL:
	stream = rtsp_streaming_init();
	break;

    default:
	display(MSDL_ERR,"protocol [ %s:// ] not supported\n",url->protocol);
	return NULL;
    }
	
    stream->url = url;
    stream->dlopts = dlopts;
    return stream;
}

/*
 * main downloading function.
 * select DLing function according to url->protocol.
 * download 'url' to 'localfile'
 *
 *      return value;   1 ... succeeded
 *                      0 ... did nothing,  failure don't count (probably we already downloaded the file)
 *                     -1 ... failed
 *                     -2 ... failed while downloading, which means
 *                            protocol negotiation succeeded
 *                            thus, can retry later
 */
int streaming_download(const char *local_file,struct url_t *url,struct download_opts_t *dlopts)
{
    int ret = 0;
    struct stream_t *stream = NULL;
    int retries = 0;
    FILE *fp = NULL;	
    uint8_t *buffer = NULL;	
    
    /*
      download header.
    */
    for(retries = 4 ; retries > 0 ; retries--) {
	stream = streaming_init(url,dlopts);
	if(stream == NULL) {
	    goto failed;
	}
	
	stream->localfile = strdup(local_file);

	/*
	  protocol initiation
	*/
	ret = stream->start(stream);
	
	if(ret > 0) {
	    /* success */
	    break;
	}
	else if(stream->stream_ctrl->status == STREAMING_OTHER_PROTOCOL) {
	    /* retry required (maximum chance is 'retries' times) */
	    dlopts->dl_protocol = stream->stream_ctrl->retry_protocol;
	    
	    stream->close(stream); /* close stream for this protocol */
	    stream = NULL;
	    continue;
	}
	else if(stream->stream_ctrl->status == STREAMING_NO_NEED_TO_DOWNLOAD) {
	    display(MSDL_NOR,"file \"%s\" already complete: not downloading\n",
		    stream->localfile);
	    goto already_done;
	}
	else if(stream->stream_ctrl->status == STREAMING_REDIRECTED) {
	    if(stream->stream_ctrl->retry_urlstr) {
		struct url_t *newurl = new_url_t(stream->stream_ctrl->retry_urlstr);
		if(!newurl) {
		    display(MSDL_ERR,"invalid redirection url %s",stream->stream_ctrl->retry_urlstr);
		    goto failed;
		}
		else {
		    char *p = strrchr(stream->stream_ctrl->retry_urlstr,'/');
		    if(!p || p[1] == '\0') { /* not found , or "/" */
			free(stream->localfile);
			stream->localfile = strdup(local_file); /* copy the 'before redirection' filename */
			
		    }
		    else { /* filename found */
			free(stream->localfile);
			stream->localfile = strdup(p+1);        /* set new filename                       */
		    }

		    /* reset url members to new one */
		    copy_url_t(url,newurl);
		    free_url_t(newurl);
		    
		    stream->close(stream);
		    stream = NULL;
		    continue;
		}
	    }
	    else {
		display(MSDL_ERR,"stream_ctrl->retry_urlstr not set\n");
		goto failed;
	    }
	}
	else {
	    /* protocol initiation error */
	    display(MSDL_ERR,"cannot establish stream\n");
	    goto failed;
	}
    }
  
    if(retries <= 0) {
	display(MSDL_ERR,"no more retry chance\n");
	goto failed;
    }
    else { /* success --> start streaming */

	uint64_t size_written = 0;         /* size written to file (current offset of file) */
	uint64_t real_downloaded_size = 0; /* bytes got from network                        */
	struct progressinfo_t pgi;
	int resume_seek_ok = 0;
	time_t stream_timeout_time = 0;
	
	/* success initialize */
	
	/*
	 * display download protocol.
	 * -- IMPORTANT --
	 * this may differ from dlopts->dl_protocol or url->protocol_type,
	 * as those are just request. there might be fallbacks or retries.
	 */
	display_protocol(stream);

	/*
	  download media.
	*/
	resume_seek_ok = 0;
	if(stream->resumeinfo->resume_req_success) {
	    if((fp = fopen(stream->localfile,"r+b")) == NULL) { /* append open */
		display(MSDL_ERR,"error: open existing file \"%s\"\n",
			stream->localfile);
		perror("");
		resume_seek_ok = 0;
	    }
	    else {
		if(fseek(fp,stream->resumeinfo->resume_start_offset,SEEK_SET) < 0) {
		    display(MSDL_ERR,"error: cannot seek \"%s\" to [%x]\n",
			    stream->localfile,stream->resumeinfo->resume_start_offset);
		    perror("");
		    resume_seek_ok = 0;
		    fclose(fp); /* close file */
		}
		else { /* success */
		    display(MSDL_NOR,"resume: seek OK, start writing from %lld [0x%x]\n",
			    stream->resumeinfo->resume_start_offset,
			    stream->resumeinfo->resume_start_offset);
		
		    stream->stream_ctrl->status = STREAMING_RESUME_BUFFERING;
		    progress_dl_start(&pgi);

		    pgi.last_speed_size_written = stream->resumeinfo->resume_start_offset;
		    pgi.last_etl_speed_size_written = stream->resumeinfo->resume_start_offset;
		    size_written = stream->resumeinfo->resume_start_offset;
		
		    resume_seek_ok = 1;
		}
	    }
	}
    
	if(!resume_seek_ok) {  /* not resuming --> just open normally */
	    /* create file here */
	    if(!strcmp(stream->localfile,"-")) { /* stdout */
		fp = stdout;
		display(MSDL_NOR,"file content written to stdout\n");
	    }
	    else if((fp = fopen(stream->localfile,"wb")) ==  NULL) {
		display(MSDL_ERR,"cannot create file \"%s\"\n",stream->localfile);
		perror("");
		goto failed;
	    }
	    progress_dl_start(&pgi);	
	}
    
	buffer = (uint8_t *)xmalloc(BUFSIZE_4_DL);
	real_downloaded_size = 0;



	/*
	  set stream timeout time for --stream-timeout option.
	  this option is to force msdl to quit streaming after @ seconds, minutes, etc.
	 */
	stream_timeout_time = 0;
	if(stream->dlopts->stream_timeout) {
	    char *reason = NULL;
	    char *timestr = create_time_str_from_many_formats(stream->dlopts->stream_timeout,&reason);
	    if(timestr) {
		stream_timeout_time = (time_t)atoi(timestr);
		if(stream_timeout_time > 0) {
		    display(MSDL_NOR,
			    "Stream timeout set. Quit streaming after %lld sec\n",(long long)stream_timeout_time);
		}
		else {
		    display(MSDL_ERR,
			    "Stream timeout ignored.\n");
		    stream_timeout_time = 0;
		}

		free(timestr);
	    }
	    else {
		display(MSDL_ERR,
			"option \"--stream-timeout %s\" : invalid argument\n"
			"%s\n"
			"set no stream timeout\n",
			stream->dlopts->stream_timeout,reason);
		stream_timeout_time = 0;
	    }
	}

	for(;;) {
    
	    if((stream->stream_ctrl->write_data_len < BUFSIZE_4_DL) &&   /* write queue not enough  */
	       stream_check_data(stream,STREAM_CHECK_DATA_TIME) <= 0) {  /* nothing to read         */
		/* some error or data didn't come within few(default 5) seconds*/
		display_progress_info(stream->stream_ctrl->file_size,size_written,0,0);
	    }
	
	    ret = stream->read(stream,buffer,BUFSIZE_4_DL);
	
	    /* 
	       write received packet directory to file.
	       everything, such as padding has been done alrady, just write it.
	    */
	
	    if(ret > 0) { /* success */
	    
		if(stream->stream_ctrl->status == STREAMING_REWIND) {
		    /*
		      have to write data AFTER deleting all current file content.
		    */
		    display(MSDL_VER,"rewind file!!\n");
		    rewind(fp);
		    size_written = 0;
		    real_downloaded_size = 0;
		    stream->stream_ctrl->packet_count = 0;
		    stream->stream_ctrl->status = STREAMING_DOWNLOADING;
		    /* continue as download restart */
		    progress_dl_start(&pgi);
		}
	    
		size_written += ret;
		real_downloaded_size += ret;
		progress_update(&pgi,stream->stream_ctrl->file_size,size_written);
		/*
		  display(MSDL_DBG,"\npacket count: %d\n",stream->stream_ctrl->packet_count);
		  display(MSDL_DBG,"ftell: %d [%x] --> write %d [%x]\n",ftell(fp),ftell(fp),ret,ret);
		*/
		if((fwrite(buffer,sizeof(uint8_t),ret,fp)) < ret) {
		    display(MSDL_ERR,"\nwrite failed\n");
		    perror("");
		    goto failed;
		}
		
		if(fflush(fp) != 0) { /* fflush returns 0 when succeeded */ /* shoud I do this every time? */
		    display(MSDL_ERR,"\nflush failed\n");
		    perror("");
		    goto failed;
		}

		
		/* stream TIMEOUT check */
		if(stream_timeout_time) {
		    time_t uptime = progress_get_dl_uptime(&pgi,NULL);
		    if(stream_timeout_time < uptime) {
			display(MSDL_ERR,
				"\nTime is UP!!. Quit streaming\n");
			/* stream-timeout has passed, quit streaming */
			break;
		    }
		}
	    }
	    else if(stream->stream_ctrl->status == STREAMING_RESUME_BUFFERING && ret >= 0) { /*HERE*/
		/*
		 * just do nothing, stream->read will automatically seek to THAT position,
		 * and remove STREAMING_RESUME_BUFFERING.
		 */
		display_progress_info(stream->stream_ctrl->file_size,size_written,-1,-1);
		continue;
	    }
	    else if(stream->stream_ctrl->status == STREAMING_FINISHED) {
		/*
		  show 100%, because 99% sucks ...
		  have to do this because stream->stream_ctrl->file_size
		  may show wrong file size.
		*/
		int64_t average_speed = progress_get_average_bandwidth(&pgi,real_downloaded_size);
	    
		display_progress_info(size_written,size_written,average_speed,0);
		display(MSDL_NOR,"\nfinished!!\n");
		break;
	    }
	    /*
	      return value is 0 if failure
	    */
	    else { /* error while download */
		display(MSDL_ERR,"!!! aborted by error !!!\n");
		goto failed_while_downloading;
	    }
	}  
    }
    
    display(MSDL_NOR,"\n");
    if(stream) stream->close(stream);
    if(buffer) free(buffer);
    if(fp != stdout)       fclose(fp);
    return 1;

  already_done:
    display(MSDL_NOR,"\n");
    if(stream) stream->close(stream);
    if(buffer) free(buffer);
    if(fp && fp != stdout) fclose(fp);
    return 0;

  failed:
    display(MSDL_NOR,"\n");
    if(stream) stream->close(stream);
    if(buffer) free(buffer);
    if(fp && fp != stdout) fclose(fp);
    return -1;

  failed_while_downloading: /* --> can retry later */
    display(MSDL_NOR,"\n");
    if(stream) stream->close(stream);
    if(buffer) free(buffer);
    if(fp && fp != stdout) fclose(fp);
    return -2;
}
