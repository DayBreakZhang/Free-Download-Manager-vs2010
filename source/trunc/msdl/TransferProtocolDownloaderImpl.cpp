#include "stdafx.h"
#include <direct.h>

#include "msdl.h"
#include "msdllib.h"
#include "mmst.h"
#include "mmsh.h"
#include "http.h"
#include "rtsp.h"
#include "getopt_long.h"

#include "TransferProtocolObjectImpl.h"
#include "TransferProtocolDownloader.h"
#include "TransferProtocolDownloaderImpl.h"

extern char m_szLastError[1000];

/*
	* meta_f ... 1 --> always metafile
	*            0 --> don't know, judge from name
	*           -1 --> NEVER.
	*/
struct target_t* TransferProtocolDownloaderImpl::new_target_t(char *name,int meta_f)
{
	struct target_t *t = (target_t *)xmalloc(sizeof(struct target_t));
	t->target_name = strdup(name);
	t->metafile_f = meta_f;
	return t;
}

struct options_t* TransferProtocolDownloaderImpl::new_options_t(void)
{
	struct options_t *opt = (options_t *)xmalloc(sizeof(struct options_t));
	memset(opt,0,sizeof(struct options_t));
	return opt;
}

struct download_opts_t* TransferProtocolDownloaderImpl::new_download_opts_t(void)
{
	struct download_opts_t *dlopts = (download_opts_t *)xmalloc(sizeof(struct download_opts_t));
	memset(dlopts,0,sizeof(struct download_opts_t));
    
	return dlopts;
}

struct dlresult_t* new_dlresult_t(void)
{
	struct dlresult_t *dlr = (dlresult_t *)xmalloc(sizeof(struct dlresult_t));
	memset(dlr,0,sizeof(struct dlresult_t));
	return dlr;
}

struct stream_t* TransferProtocolDownloaderImpl::streaming_init(struct url_t *url,struct download_opts_t *dlopts)
{
	stream = NULL;

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
	case RTSP:
	case RTSP_WMS:
	case RTSP_REAL:
	stream = rtsp_streaming_init();
	break;

	default:
	sprintf(m_szLastError, "protocol [ %s:// ] not supported", url->protocol);
	return NULL;
	}
	
	stream->url = url;
	stream->dlopts = dlopts;
	return stream;
}

void free_target_t(struct target_t *t)
{
    if(!t) {
	return;
    }
    free(t->target_name);
    free(t);
}

void TransferProtocolDownloaderImpl::free_options_t(struct options_t *opt)
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

void TransferProtocolDownloaderImpl::free_download_opts_t(struct download_opts_t *dlopts)
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

void TransferProtocolDownloaderImpl::free_dlresult_t(struct dlresult_t *dlr)
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
int /*TransferProtocolDownloaderImpl::*/filename_cmp(void *a,void *b)
{
    char *s = (char *)a,*t = (char *)b;
    s = strrchr(s,'/') + 1;
    t = strrchr(t,'/') + 1;
    
    return strcmp(s,t);
}


//static void print_usage(void);
//static struct list_h *set_options(struct options_t *options,int argc,char **argv);


TransferProtocolDownloader* WINAPI createTransferProtocolDownloader ()
{
	TransferProtocolDownloaderImpl *p = new TransferProtocolDownloaderImpl;
	p->AddRef ();
	return p;
}

TransferProtocolDownloaderImpl::TransferProtocolDownloaderImpl(void)
{
	m_cRefs = 0;
	m_nAverage_speed = 0;
	real_downloaded_size = 0;
	size_written = 0;
	m_bThreadRunning = false;
	hThread = NULL;

	options = NULL;
	target = NULL;
	stream = NULL;

	m_nSectionCount = 0;

	memset(m_szLastError, 0, sizeof(char));
}

TransferProtocolDownloaderImpl::~TransferProtocolDownloaderImpl(void)
{
	Stop ();
	while (WAIT_TIMEOUT == WaitForSingleObject (hThread, 500))
	{
		if (m_bNeedStop || IsDone ())
			TerminateThread (hThread, 0);
	}
	CloseHandle (hThread);

    clean_dispinfo();

	/////////////////////////////////////////////////////////////////////////////
	// The Winsock DLL is acceptable. Proceed to use it. 

	// Add network programming using Winsock here 

	// then call WSACleanup when down using the Winsock dll 
    
    WSACleanup();

	if (options)
		free_options_t (options);
}

BOOL TransferProtocolDownloaderImpl::InitTpStream(LPCSTR pszUrl, LPCSTR pszOutputPath, int nStreamingSpeed)
{
	targets = NULL;
    options = new_options_t();
	char protocol[5] = {0};
	if (strstr (pszUrl, "mmsh"))
		strcpy(protocol, "mmsh");
	else if (strstr (pszUrl, "mmst"))
		strcpy(protocol, "mmst");
	else if(strstr (pszUrl, "mms"))
		strcpy(protocol, "mmst");
	else if (strstr (pszUrl, "rtsp"))
		strcpy(protocol, "rtsp");

	else // protocol [ %s:// ] not supported
		return false;
	
	char szStrSpeed [100];
	sprintf (szStrSpeed, "%d", nStreamingSpeed);
	char *argv[9]={"msdl.exe", "-p", protocol, "-s", szStrSpeed, "-o", (char*)pszOutputPath, "-c", (char*)pszUrl};
	
    targets = set_options(options,9,argv);
    init_dispinfo(options);

    //display(MSDL_DBG,"%s %s\n",PACKAGE,VERSION);
    //signal(SIGPIPE,SIG_IGN);            // Ignore sigpipe, because we don't need it 

	////////////////////////////////////////////////////////////////////////////////////////
	WORD wVersionRequested;
    WSADATA wsaData;
    int err;

	// Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h 
    wVersionRequested = MAKEWORD(2, 2);

    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {
        // Tell the user that we could not find a usable 
        // Winsock DLL.                                  
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

	// Confirm that the WinSock DLL supports 2.2.
	// Note that if the DLL supports versions greater    
	// than 2.2 in addition to 2.2, it will still return 
	// 2.2 in wVersion since that is the version we      
	// requested.                                        

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        // Tell the user that we could not find a usable 
        // WinSock DLL.                                  
        printf("Could not find a usable version of Winsock.dll\n");
        WSACleanup();
        return 1;
    }
    else
        printf("The Winsock 2.2 dll was found okay\n");
	////////////////////////////////////////////////////////////////////////////////////////

	return TRUE;
}

int TransferProtocolDownloaderImpl::msdl(struct target_t *target,struct options_t *options,struct dlresult_t *result)
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
		/*display(MSDL_NOR,
			"recursive download with stdout is not supported.\n"
			"must save the metafile localy for recursive download.");*/
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
	    //display(MSDL_ERR,"input file \"%s\" does not contain any url\n",target->target_name);
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
 * download target_str ==> local_save_file
 * and append success/failure results to results list.
 * return value: 1 (do_download() return) ... success
 *               0 ... file already downloaded, and nothing to do
 *              -1 ... faliure
 */
int TransferProtocolDownloaderImpl::download_target(char *target_str,struct options_t *options,struct dlresult_t *result,
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
 * now from version 1.2.6 you can set multiple local filename for multiple targets
 * means -o file1 -o file2 -o file3,,, stuff.
 * 
 * now it messes with options->local_filename_list
 * make it work as queue.
 */
char* TransferProtocolDownloaderImpl::create_local_file_name(char *target_str,struct options_t *options)
{
    char *local_filename = NULL;
    struct list_h *list = options->local_filename_list;

    if(list && list->p && strcmp((const char *)list->p,"")) { /* NOT the empty filename you want to set */
	local_filename = strdup((const char *)list->p);
	//list_h_free_head(&(options->local_filename_list),free); /* string list */
    }
    else if(target_str && strcmp(target_str,"")) {
	char *p = strrchr(target_str,'/');
	if(p && (p[1] != '\0')) { /* do not allow local_filename to be "" (p[0] == '/' now)*/
	    local_filename = strdup(p + 1);
	}
    }

    /* still no filename --> set default filename */
    if((!local_filename) || !strcmp(local_filename,"")) {
		const char default_file_name_for_empty[] = "file";
		local_filename = strdup(default_file_name_for_empty); /* allocate default file name */
    }
    
    return local_filename;
}

struct download_opts_t* TransferProtocolDownloaderImpl::set_dlopts_from_options(struct options_t *options,
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



/*
 * allocate url  and dlopts, from target_str and options
 * return value:  1 ... success  0 ... failure
 */
int TransferProtocolDownloaderImpl::prepare_download(char *target_str,struct options_t *options,
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
	//display(MSDL_VER,"ignored \"%s\"\n",target_str);
	goto ignore;
    }

    /*
     * check if target url is valid
     */
    if(!url->hostname || !strcmp(url->hostname,"")) {
	//display(MSDL_NOR,"ignored \"%s\" (no host information)\n",target_str);
	goto ignore;
    }
    else if(!url->filepath || !strcmp(url->filepath,"")) {
	//display(MSDL_NOR,"warning: \"%s\" (no filepath)\n",target_str);
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
		sprintf(m_szLastError, "protocol [ %s ] not supported: ignore this option",
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
int TransferProtocolDownloaderImpl::do_download(const char *local_name,struct url_t *url,struct download_opts_t *dlopts)
{
    int ret = 0;
    int retry_again = 0;
    
    /*
      display download file name
    */
    if(strcmp(local_name,"-")) {
	//display(MSDL_NOR,"download [ %s ]\n",local_name);
    }
    //display(MSDL_VER,"url: %s\n",url->url);
    
    /*
      download file
    */
    do {
	retry_again = 0;
	ret = streaming_download(local_name,url,dlopts);
	
	if((ret == -2) && ((dlopts->auto_retry > 0) || (dlopts->auto_retry == AUTO_RETRY_INFINITE))) {

	    if(dlopts->auto_retry == AUTO_RETRY_INFINITE) {
		//display(MSDL_NOR,"*** try downloading again \n",dlopts->auto_retry);
	    }
	    else {
		dlopts->auto_retry--;
		//display(MSDL_NOR,"*** try downloading again (%d more tries) ***\n",dlopts->auto_retry);
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
void TransferProtocolDownloaderImpl::display_protocol(struct stream_t *stream)
{
    //display(MSDL_VER,"download protocol: ");
    switch (stream->stream_ctrl->protocol) {
    case MMST:
	//display(MSDL_VER,"mmst");
	break;
    case MMSH:
	//display(MSDL_VER,"mmsh");
	break;
    case RTSP_REAL:
	//display(MSDL_VER,"rtsp - real");
	break;
    case RTSP_WMS:
	//display(MSDL_VER,"rtsp - wms");
	break;
    case HTTP:
	//display(MSDL_VER,"http");
	break;
    case FTP:
	//display(MSDL_VER,"ftp");
	break;
    default:
	//display(MSDL_ERR," :) ...bug");
	break;
    }
  
    //display(MSDL_VER,"\n\n");
}

FILE* fopen_mkdir(char* name, const char* mode)
{
	int ch = '\\';
	// Search backward
	const char *pdest = strrchr( name, ch );
	int result = (int)(pdest - name);
	if (result && pdest != NULL)
	{
		char *dir = new char[result + 1];
		strncpy (dir, name, result);
		dir[result] = '\0';
		int res = _mkdir(dir);
		delete (dir);
	}
	return fopen(name, mode);
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
int TransferProtocolDownloaderImpl::streaming_download(const char *local_file,struct url_t *url,struct download_opts_t *dlopts)
{
	//vmsAUTOLOCKSECTION (m_csDownload);
    int ret = 0;
    stream = NULL;
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
		m_nSectionCount = 1;
	    break;
	}
	else if(stream->stream_ctrl->status == STREAMING_OTHER_PROTOCOL) {
	    /* retry required (maximum chance is 'retries' times) */
	    dlopts->dl_protocol = stream->stream_ctrl->retry_protocol;
	    
	    stream->close(stream); /* close stream for this protocol */
	    //stream = NULL;
	    continue;
	}
	else if(stream->stream_ctrl->status == STREAMING_NO_NEED_TO_DOWNLOAD) {
	    /*display(MSDL_NOR,"file \"%s\" already complete: not downloading\n",
		    stream->localfile);*/
	    goto already_done;
	}
	else if(stream->stream_ctrl->status == STREAMING_REDIRECTED) {
	    if(stream->stream_ctrl->retry_urlstr) {
		struct url_t *newurl = new_url_t(stream->stream_ctrl->retry_urlstr);
		if(!newurl) {
		    //display(MSDL_ERR,"invalid redirection url %s",stream->stream_ctrl->retry_urlstr);
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
		//display(MSDL_ERR,"stream_ctrl->retry_urlstr not set\n");
		goto failed;
	    }
	}
	else {
	    /* protocol initiation error */
	    //display(MSDL_ERR,"cannot establish stream\n");
	    goto failed;
	}
    }
  
    if(retries <= 0) {
	//display(MSDL_ERR,"no more retry chance\n");
	goto failed;
    }
    else { /* success --> start streaming */

	size_written = 0;         /* size written to file (current offset of file) */
	real_downloaded_size = 0; /* bytes got from network                        */
	
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
	if(stream->resumeinfo->resume_req_success && stream->stream_ctrl->total_packets > 0) {
	    if((fp = fopen(stream->localfile,"ab")) == NULL) { /* append open */
		/*display(MSDL_ERR,"error: open existing file \"%s\"\n",
			stream->localfile);*/
		perror("");
		resume_seek_ok = 0;
	    }
	    else {
		if(fseek(fp,stream->resumeinfo->resume_start_offset,SEEK_SET) < 0) {
		    /*display(MSDL_ERR,"error: cannot seek \"%s\" to [%x]\n",
			    stream->localfile,stream->resumeinfo->resume_start_offset);*/
		    perror("");
		    resume_seek_ok = 0;
		    fclose(fp); /* close file */
		}
		else { /* success */
		    /*display(MSDL_NOR,"resume: seek OK, start writing from %lld [0x%x]\n",
			    stream->resumeinfo->resume_start_offset,
			    stream->resumeinfo->resume_start_offset);*/
		
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
		//display(MSDL_NOR,"file content written to stdout\n");
	    }
		else if((fp = fopen_mkdir(stream->localfile,"wb")) == NULL) {
			//display(MSDL_ERR,"cannot create file \"%s\"\n",stream->localfile);
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
		    /*display(MSDL_NOR,
			    "Stream timeout set. Quit streaming after %lld sec\n",(long long)stream_timeout_time);*/
		}
		else {
		    /*display(MSDL_ERR,
			    "Stream timeout ignored.\n");*/
		    stream_timeout_time = 0;
		}

		free(timestr);
	    }
	    else {
		/*display(MSDL_ERR,
			"option \"--stream-timeout %s\" : invalid argument\n"
			"%s\n"
			"set no stream timeout\n",
			stream->dlopts->stream_timeout,reason);*/
		stream_timeout_time = 0;
	    }
	}

	for(;;) {

		if (m_bNeedStop)
			break;
    
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
		    //display(MSDL_VER,"rewind file!!\n");
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
		    //display(MSDL_ERR,"\nwrite failed\n");
		    perror("");
		    goto failed;
		}
		
		if(fflush(fp) != 0) { /* fflush returns 0 when succeeded */ /* shoud I do this every time? */
		    //display(MSDL_ERR,"\nflush failed\n");
		    perror("");
		    goto failed;
		}

		
		/* stream TIMEOUT check */
		if(stream_timeout_time) {
		    time_t uptime = progress_get_dl_uptime(&pgi,NULL);
		    if(stream_timeout_time < uptime) {
			/*display(MSDL_ERR,
				"\nTime is UP!!. Quit streaming\n");*/
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
		//display_progress_info(stream->stream_ctrl->file_size,size_written,-1,-1);
		continue;
	    }
	    else if(stream->stream_ctrl->status == STREAMING_FINISHED) {
		/*
		  show 100%, because 99% sucks ...
		  have to do this because stream->stream_ctrl->file_size
		  may show wrong file size.
		*/
		m_nAverage_speed = progress_get_average_bandwidth(&pgi,real_downloaded_size);
	    
		display_progress_info(size_written,size_written, m_nAverage_speed,0);
		//display(MSDL_NOR,"\nfinished!!\n");
		break;
	    }
	    /*
	      return value is 0 if failure
	    */
	    else { /* error while download */
		//display(MSDL_ERR,"!!! aborted by error !!!\n");
		goto failed_while_downloading;
	    }
	}  
    }
    
    //display(MSDL_NOR,"\n");
    //if(stream) stream->close(stream);
	//stream = NULL;
    if(buffer) free(buffer);
    if(fp != stdout)       fclose(fp);
    return 1;

  already_done:
    //display(MSDL_NOR,"\n");
    if(stream) stream->close(stream);
	stream = NULL;
    if(buffer) free(buffer);
    if(fp && fp != stdout) fclose(fp);
    return 0;

  failed:
    //display(MSDL_NOR,"\n");
    //if(stream) stream->close(stream);
	//stream = NULL;
    if(buffer) free(buffer);
    if(fp && fp != stdout) fclose(fp);
    return -1;

  failed_while_downloading: /* --> can retry later */
    //display(MSDL_NOR,"\n");
    //if(stream) stream->close(stream);
	//stream = NULL;
    if(buffer) free(buffer);
    if(fp && fp != stdout) fclose(fp);
    return -2;
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
int TransferProtocolDownloaderImpl::is_metafile(char *name)
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
int TransferProtocolDownloaderImpl::get_url_list_from_file(char *filename,struct list_h **ret)
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
	//display(MSDL_ERR,"cannot open file %s\n",filename);
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
		    /*display(MSDL_VER,"file: <%s> is not uniq, ignore this\n",
			    strrchr(sep,'/') + 1);*/
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

DWORD TransferProtocolDownloaderImpl::_tpThread (LPVOID lp)
{
	TransferProtocolDownloaderImpl* pthis = (TransferProtocolDownloaderImpl*)lp;
	
	// for displaying finished time 
    time_t start_time,fin_time,diffsec;
    
    start_time = time(NULL);

	struct dlresult_t *result = new_dlresult_t();
    for(pthis->target = pthis->targets; pthis->target ; pthis->target = pthis->target->next) {
 
		pthis->msdl((target_t *)pthis->target->p,pthis->options,result);

    }
    
    fin_time = time(NULL);

    int success = 0;
    int failed = 0;

    success = list_h_num(result->success_list);
    failed = list_h_num(result->failed_list);

    diffsec = fin_time - start_time;
    
    /*display(MSDL_NOR,"FINISHED --%02d:%02d:%02d--\n",
	    diffsec/3600,(diffsec%3600)/60,diffsec % 60);*/
    
    // don't display anything if only one file target 
    if(success > 1) {
	//display(MSDL_NOR,"%d files downloaded\n",success);
    }
    else if(success == 0 && failed > 0) {
	//display(MSDL_NOR,"ALL download failed\n");
		if(pthis->stream) pthis->stream->stream_ctrl->status = STREAMING_FAILED;
    }

    // print failed log so that later user can copy-and-paste :) 
    if(failed > 0) {
	struct list_h *p = NULL;
	//display(MSDL_NOR,"fialed: %d files\n",list_h_num(result->failed_list));
	for(p = result->failed_list ; p ; p = p->next) {
	    //display(MSDL_NOR,"%s\n",p->p);
	}
    }
  
	//free_dlresult_t(result);

	pthis->m_bThreadRunning = false;
	return 0;
}

BOOL TransferProtocolDownloaderImpl::Start()
{
	if (m_bThreadRunning) return FALSE;

	vmsAUTOLOCKSECTION (m_csDownload);
	m_bThreadRunning = true;
	m_bNeedStop = false;
	m_nSectionCount = 0;
	DWORD dw;
	hThread = CreateThread (NULL, 0, _tpThread, this, 0, &dw);

	return TRUE;
}

BOOL TransferProtocolDownloaderImpl::ReStart()
{
	if (m_bThreadRunning) return FALSE;

	vmsAUTOLOCKSECTION (m_csDownload);
	
	if (options) options->resume = 0;

	return TRUE;
}

BOOL TransferProtocolDownloaderImpl::Stop()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	m_bNeedStop = true;
	m_nAverage_speed = 0;
	m_nSectionCount = 0;
	return TRUE;
}

UINT TransferProtocolDownloaderImpl::get_DownloadSpeed ()
{
	m_nAverage_speed = progress_get_average_bandwidth(&pgi,real_downloaded_size);
	return m_nAverage_speed;
}

float TransferProtocolDownloaderImpl::get_PercentDone ()
{
	UINT64 nTotalFileSize = get_TotalFilesSize ();
	float fPercentDone = nTotalFileSize ? (float)
		((double)get_TotalDownloadedBytesCount() / nTotalFileSize * 100.0) : 0.0;
	if(IsLiveStreaming() || fPercentDone > 100.0) fPercentDone = -1.00;
	return fPercentDone;
}

BOOL TransferProtocolDownloaderImpl::IsDone()
{
	vmsAUTOLOCKSECTION (m_csDownload);

	return stream == NULL ? FALSE : (stream->stream_ctrl->status == STREAMING_FINISHED);
}

int TransferProtocolDownloaderImpl::get_ConnectionCount ()
{
	return 0;
}

TransportProtocolStateEx TransferProtocolDownloaderImpl::get_State()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	TransportProtocolStateEx enState = stream == NULL ? STREAMING_FINISHED : (TransportProtocolStateEx)stream->stream_ctrl->status;
	return enState;
}


/*
 * read arguments. returns target url
 */
struct list_h* TransferProtocolDownloaderImpl::set_options(struct options_t *options,int argc,char **argv)
{
    int ch = 0;
    int option_index = 0;
    int target_count = 0; /* argument count */
    struct list_h *targets = NULL;
    struct target_t *t = NULL;

    struct option long_options[] = {
	{"output",1,0,'o'},      // equal to '-o' 
	{"logfile",1,0,'l'},     //          '-l' 
	{"protocol",1,0,'p'},    //          '-p' 
	{"quiet",0,0,'q'},       //          '-q' 
	{"bandwidth",1,0,'b'},   //          '-b' 
	{"speed",1,0,'s'},       //          '-s' 
	{"range",1,0,'r'},       //          '-r' 
	{"continue",0,0,'c'},    //          '-c' 
	{"auto-retry",1,0,'a'},  //          '-a' 
	{"metafile",1,0,'m'},    //          '-m' 
	{"no-metafile",1,0,'n'}, //          '-n' 
	{"help",0,0,'h'},        //          '-h' 
	{"verbose",0,0,'v'},     //          '-v' 
	{"version",0,0,'V'},     //          '-V' 
	{"byterange",1,0,0},
	{"username",1,0,0},
	{"password",1,0,0},
	{"no-proxy",0,0,0},       // turn off proxy, no matter HTTP_PROXY set  
	{"no-passive-ftp",0,0,0}, // do not use passive mode in ftp            
	{"stream-timeout",1,0,0}, // force stream finish by time @arg (ex. 20s 

	{"debug",0,0,0},          // debug messages, super verbose mode        
	{NULL,0,0,0}
    };
    char *env = NULL;
    
    
    /*
      set default options
     */
    options->loglevel = MSDL_NOR; /* normal */
    options->no_passive_ftp_f = 0;

    
    /*
      get environment variable
    */
    if((env = getenv("HTTP_PROXY"))) {
	options->http_proxy = strdup(env);
    }

	//add command
    
    
    /*
      set command line options
    */
	optind = 1;
    while(1) {
	
	ch = getopt_long(argc,argv,"o:l:p:b:s:r:a:m:n:hcVvq",long_options,&option_index);
    
	if(ch == -1) /* end of options */
	    break;
    
	switch(ch) {
      
	case 0:   /* long options, such as --help */
	    
	    if(!strcmp(long_options[option_index].name,"username")) {
		if(options->username) free(options->username);
		options->username = strdup(optarg);
	    }
	    else if(!strcmp(long_options[option_index].name,"password")) {
		if(options->password) free(options->password);
		options->password = strdup(optarg);
	    }
	    else if(!strcmp(long_options[option_index].name,"byterange")) {
		if(options->byterange) free(options->byterange);
		options->byterange = strdup(optarg);
	    }
	    else if(!strcmp(long_options[option_index].name,"no-proxy")) {
		if(options->http_proxy) free(options->http_proxy);
		options->http_proxy = NULL;
	    }
	    else if(!strcmp(long_options[option_index].name,"no-passive-ftp")) {
		options->no_passive_ftp_f = 1;
	    }
	    else if(!strcmp(long_options[option_index].name,"stream-timeout")) {
		if(options->stream_timeout) free(options->stream_timeout);
		options->stream_timeout = strdup(optarg);
	    }
	    else if(!strcmp(long_options[option_index].name,"debug")) {
		options->loglevel = MSDL_DBG;
		dispinfo_set_loglevel(MSDL_DBG);
	    }
	    
	    break;
      
	case 'p': /* specify protocol               */
	    if(options->protocol) free(options->protocol);
	    options->protocol = strdup(optarg);
	    break;
      
	case 'o': /* output file name specification */
	    list_h_append(&(options->local_filename_list),strdup(optarg));
	    break;

	case 'l':
	    if(options->logfile) free(options->logfile);
	    options->logfile = strdup(optarg);
	    break;
      
	case 'b': /* bandwidth                      */
	    options->bandwidth = atoi(optarg);
	    break;
	    
	case 's': /* speed (for rtsp)               */
	    if(options->speed) free(options->speed);
	    options->speed = strdup(optarg);
	    break;

	case 'r': /* range (for rtsp)               */
	    if(options->range) free(options->range);
	    options->range = strdup(optarg);
	    break;

	case 'c': /* resume download target         */
	    options->resume = 1;
	    break;
	    
	case 'a':
	    options->auto_retry_times = atoi(optarg);
	    if(options->auto_retry_times == 0) { /* if argument == 0, set default value */
		if(!strcmp(optarg,"inf")) {
		    options->auto_retry_times = AUTO_RETRY_INFINITE;
		}
		else {
		    options->auto_retry_times = AUTO_RETRY_DEFAULT;
		}
	    }
	    break;

	case 'm': /* treat as metafile              */
	    t = new_target_t(optarg,IS_METAFILE);
	    list_h_append(&targets,t);
	    target_count++;
	    break;
	    
	case 'n': /* do NOT treat as metafile       */
	    t = new_target_t(optarg,FORCE_NOT_METAFILE);
	    list_h_append(&targets,t);
	    target_count++;
	    break;
	    
	case 'h': /* help                           */
	    //print_package_info();
	    //print_usage();
	    goto exit_now;
	    break;

	case 'V': /* version                        */
	    //print_package_info();
	    goto exit_now;
	    break;

	case 'v': /* verbose                        */
	    if(options->loglevel != MSDL_DBG) { /* MSDL_DBG has more priority */
		options->loglevel = MSDL_VER;
		dispinfo_set_loglevel(MSDL_VER);
	    }
	    break;
	    
	case 'q': /* quiet                          */
	    /* when met option, don't display anything */
	    options->loglevel = MSDL_QUIET;
	    dispinfo_set_loglevel(MSDL_QUIET);
	    break;
	    
	default:
	    //display(MSDL_ERR,"cannot recognize option '%c'\n",ch);
	    //print_usage();
	    goto exit_now;
	}
    }
  
    if(optind < argc) {
    
	while(optind < argc) {
	    t = new_target_t(argv[optind++],0);
	    list_h_append(&targets,t);
	    target_count++;
	}
    }
  
    options->targets = targets;
    
  
    if(target_count == 0) {
	//display(MSDL_ERR,"no target\n");
	//print_usage();
	goto exit_now;
    }
  
    /*
      show warnings
    */
    
    if(options->protocol && target_count > 1) {
	/*display(MSDL_ERR,
		"warning: protocol specified but trying to \n"
		"         download more than 1 files. keep \n"
		"         in mind that protocol you specified\n"
		"         will be applied to all targets, thus\n"
		"         some files can not be downloaded.\n");*/
    }

    if(options->bandwidth) {
	/*display(MSDL_ERR,
		"warning: you have set bandwidth to %d\n"
		"         for this setting, you might not receive\n"
		"         best quality stream.\n",options->bandwidth);*/
    }

    if(options->auto_retry_times == AUTO_RETRY_INFINITE) {
	/*display(MSDL_NOR,
		"warning: you have set download tries to infinite\n");*/
    }

    return targets;

  exit_now:
    free_options_t(options);
    exit(1);
}

UINT64 TransferProtocolDownloaderImpl::get_TotalFilesSize ()
{
	return (stream) ? (IsLiveStreaming()) ? size_written : stream->stream_ctrl->file_size : size_written;
}

UINT64 TransferProtocolDownloaderImpl::get_TotalDownloadedBytesCount ()
{
	UINT64 nFileSize = get_TotalFilesSize();
	return (size_written > nFileSize) ? nFileSize : size_written;
}

int TransferProtocolDownloaderImpl::get_NumberOfSections ()
{
	return 1;
}

int TransferProtocolDownloaderImpl::get_StreamingSpeed ()
{
	return options->speed ? atol(options->speed) : 0;
}

int TransferProtocolDownloaderImpl::get_DownloadingSectionCount()
{
	vmsAUTOLOCKSECTION (m_csDownload);
	return m_nSectionCount;
}

LPCSTR TransferProtocolDownloaderImpl::get_LastError()
{
	return m_szLastError;
}

BOOL TransferProtocolDownloaderImpl::IsLiveStreaming ()
{
	return (stream && stream->stream_ctrl->status == 1) ? (stream->stream_ctrl->total_packets > 0) ? FALSE : TRUE : FALSE;
}
