/***********************************************************************
 *    main.c:  cli specific stuff
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

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "getopt_long.h"

#include "TransferProtocolObjectImpl.h"
#include "TransferProtocolDownloader.h"
#include "TransferProtocolDownloaderImpl.h"

static void print_usage(void);
static struct list_h *set_options(struct options_t *options,int argc,char **argv);

/*
 * msdl -- media stream downloader ---
 * main entry point
 */
/*int main(int argc,char **argv)
{
    struct list_h *targets = NULL,*target;
    struct dlresult_t *result;
    struct options_t *options;
    

    int success = 0;
    int failed = 0;
  
    // for displaying finished time 
    time_t start_time,fin_time,diffsec;
    
    start_time = time(NULL);
    
    options = new_options_t();
    targets = set_options(options,argc,argv);
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


    result  = new_dlresult_t();
    for(target = targets; target ; target = target->next) {
  
	msdl((target_t *)target->p,options,result);
	
    }
    
    fin_time = time(NULL);
  
    success = list_h_num(result->success_list);
    failed = list_h_num(result->failed_list);

    diffsec = fin_time - start_time;
    
    display(MSDL_NOR,"FINISHED --%02d:%02d:%02d--\n",
	    diffsec/3600,(diffsec%3600)/60,diffsec % 60);
    
    // don't display anything if only one file target 
    if(success > 1) {
	display(MSDL_NOR,"%d files downloaded\n",success);
    }
    else if(success == 0 && failed > 0) {
	display(MSDL_NOR,"ALL download failed\n");
    }


    // print failed log so that later user can copy-and-paste :) 
    if(failed > 0) {
	struct list_h *p = NULL;
	display(MSDL_NOR,"fialed: %d files\n",list_h_num(result->failed_list));
	for(p = result->failed_list ; p ; p = p->next) {
	    display(MSDL_NOR,"%s\n",p->p);
	}
    }
  
    free_options_t(options);
    free_dlresult_t(result);
    
    clean_dispinfo();

	/////////////////////////////////////////////////////////////////////////////
	// The Winsock DLL is acceptable. Proceed to use it. 

	// Add network programming using Winsock here 

	// then call WSACleanup when down using the Winsock dll 
    
    WSACleanup();
    
    return failed;
}*/



//char *package_info = 
    //PACKAGE " " VERSION " : Media Stream DownLoader\n";



/*char *usage =
    "Usage: " PACKAGE " [options] targets\n"
    "  -o, --output <localfile>    specify output file name. '-o -': stdout.\n"
    "  -l, --logfile <logfile>     print log to logfile instead of console.\n"
    "  -v, --verbose               show verbose messages.\n"
    "  -V, --version               show version information.\n"
    "  -q, --quiet                 do quietly. no output.\n"
    "  -c, --continue <url>        continue (resume) downloading.\n"
    "  -a, --auto-retry <num>      auto-retry aborted download. (num times).\n"
    "  -b, --bandwidth <bandwidth> set bandwidth.\n"
    "  -s, --speed <speed>         set streaming speed.\n"
    "  -r, --range <range>         set range (for RTSP), default \"0.000-\".\n"
    "  -m, --metafile <url>        treat url as metafile.\n"
    "  -n, --no-metafile <url>     DO NOT treat url as metafile.\n"
    "  -h, --help                  display this help.\n"
    "  -p, --protocol <protocol>   specify download protocol.\n"
    "      --byterange <range>     set byte range (for http and ftp).\n"
    "      --username <username>   user name for basic authentication.\n"
    "      --password <password>   password for basic authentication.\n"
    "      --no-proxy              DO NOT use proxy, even if HTTP_PROXY set.\n"
    "      --no-passive-ftp        DO NOT use passive mode in FTP.\n"
    "      --stream-timeout <time> Quit Streaming after time.\n"
    "      --debug                 show debug message (super verbose).\n"
    "Supported protocols: mms(mmst) mmsh rtsp http ftp\n"
    "To use proxy for mms, mmsh, and http, set HTTP_PROXY variable.\n"
    "\"-s\" and \"-r\" are for *-rtsp, and these options may be ignored.\n"
    "If you find any bugs, please report to <" PACKAGE_BUGREPORT ">.\n";
	*/



/*
 * print package info
 */
static void print_package_info(void)
{
    //display(MSDL_NOR,"%s",package_info);
}



/*
 * print usage
 */
static void print_usage(void)
{
    //display(MSDL_NOR,"%s",usage);
}



BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
