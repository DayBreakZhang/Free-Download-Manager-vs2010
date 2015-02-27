/***********************************************************************
 *    real.c : for downloading from real server using rtsp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on rtsp (real) implementation of 
 * mplayer and xine, and includes code from both projects.
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
 * (from MPlayer-1.0rc2/stream/realrtsp/real.c)
 */

/*
 * This file was ported to MPlayer from xine CVS real.c,v 1.8 2003/03/30 17:11:50
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
 * special functions for real streams.
 * adopted from joschkas real tools.
 *
 */

#include "stdafx.h"

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "rtsp.h"
#include "realchallenge.h"
#include "rmff.h"
#include "sdpreal.h"
#include "snprintf.h"
#include "real.h"

/* realplayer specific stuff */
const char real_clientid[] = "ClientID: Linux_2.6_10.0.0.0_play32_RN01_EN_586";
const char real_useragent[] = "User-Agent: RealMedia Player Version 10.0.0.0 (linux-2.6-libc6-gcc4.1-i586)";
const char real_companyid[] = "CompanyID: X160hPo6JmsD6Vger24oAg==";
const char real_clientchallenge[] = "ClientChallenge: cd7cb1ac431e8d1ad4d2fadb8cf762d1";
const char real_playerstarttime[] = "PlayerStarttime: [19/03/2007:21:42:56 00:00]";
const char real_transport[] = "Transport: x-pn-tng/tcp;mode=play,rtp/avp/tcp;unicast;mode=play";



static int real_process_header(struct stream_t *stream);
static int real_process_media_packet(struct stream_t *stream,uint8_t *header,
				     uint8_t *buffer,size_t max_size);
int real_prepare_resuming(struct stream_t *stream);
int real_get_last_npt_of_file(char *local_filename,uint32_t *send_time,uint64_t *seek_offset);


/*
 * count rules 
 *     >>>> CAUTION <<<<
 * starting '#' is not necessary, but ending ';' is necessary, so 
 * couting ; is correct.
 */
static int count_rules(char *asmrule)
{
    int count = 0;
    while(*asmrule)
	if(*(asmrule++) == ';') count++;
  
    return count;
}

static char *next_rule(char *data)
{
    data = strchr(data,';');
    return data + 1;
}



/*
 * finds rule which matches bandwidth.
 *          return value:    number of matched rules
 * rulearray contains its rule numbers.
 */
int find_asmrule_match(char *asmrule,int **matched,int bw)
{
    int i;
    int rules;
    int matchedrules = 0;

    rules = count_rules(asmrule);
  
    *matched = (int *)xmalloc(sizeof(int) * rules);
  
    for(i = 0; i < rules ;i++) {
	/* copy one rule to string*/
	if(asmrule_match(asmrule,bw)) { /* match!! */
	    display(MSDL_DBG,"rule[%d] = %d matched\n",matchedrules,i);
	    (*matched)[matchedrules] = i;
	    matchedrules++;
	}
	asmrule = next_rule(asmrule);
    }
  
    return matchedrules;
}



/*
 * copy mlti_data('type specific data') to it's buffer.
 *
 * *buf is malloc()ed in this function. don't forget to free later
 */
static int select_mlti_data(uint8_t *mlti_data,int mlti_data_size,
			    int match,uint8_t **buf)
{

    int numrules,codec,size;
    int i;
  
    if(!mlti_data) return 0; /* just to make sure */

    if(memcmp(mlti_data,"MLTI",4)) {
	display(MSDL_DBG,
		"'MLTI' not found on OpaqueData base64 decoded string\n");
	*buf = (uint8_t *)xmalloc(mlti_data_size);
	memcpy(*buf,mlti_data,mlti_data_size);
	return mlti_data_size;
    }
  
    mlti_data += 4;
  
    numrules = get16_be(mlti_data);
    if(match >= numrules) {
	display(MSDL_ERR,"matched rule >= number of rules .. strange ...\n");
	return 0;
    }
  
    mlti_data += (match + 1) * 2;
  
    codec = get16_be(mlti_data);
  
    mlti_data += (numrules - match) * 2;

    numrules = get16_be(mlti_data);
  
    if(codec >= numrules) {
	display(MSDL_ERR,"number of codecs >= number of codecs .. strange ...\n");
	return 0;
    }
  
    mlti_data += 2;
  
    for(i = 0; i < codec ; i++) {
	size = get32_be(mlti_data);
	mlti_data += size + 4;
    }

    size = get32_be(mlti_data);
  
    *buf = (uint8_t *)xmalloc(size);
    memcpy(*buf,mlti_data + 4,size);
  
    return size;
}



/*
 * parse sdp(stream description) lines.
 * 
 * subscribe is "Subscribe: " which is send with SET_PARAMETER request.
 *
 */
struct rmff_header_t *real_parse_sdp(char *data,char **subscribe,int bw)
{
  
    struct sdpreal_t *desc;
    struct list_h *p;
    struct rmff_header_t *rmff_header;
    uint8_t *buf;
    int *matched; /* array of matched rules. malloced in find_asmrule_match */
    int matched_rules;
    int i,j;
    int mlti_data_len;
  
    int subscribe_len = BUFSIZE_1K;
    char subbuf[32];
  
    int duration =0;
    int max_bit_rate = 0;
    int avg_bit_rate = 0;
    int max_packet_size = 0;
    int avg_packet_size = 0;

    desc = sdpreal_parse(data);
  
    rmff_header = new_rmff_header_t();
    rmff_header->fileheader = new_rmff_fileheader(4 + desc->stream_count);
    rmff_header->cont = new_rmff_cont(desc->title,desc->author,
				      desc->copyright,desc->abstract);
    rmff_header->data = new_rmff_dataheader(0,0);
    rmff_header->streams =
	(rmff_mdpr_t**)xmalloc(sizeof(struct rmff_mdpr_t*) * (desc->stream_count + 1));
    display(MSDL_VER,"number of streams: %u\n",desc->stream_count);
  
    *subscribe = (char *)xmalloc(subscribe_len);
    strcpy(*subscribe,"Subscribe: ");
  
    for(i = 0,p = desc->streams; i < desc->stream_count; i++,p = p->next) {
    
	struct sdpreal_stream_t *stream = (sdpreal_stream_t *)p->p;
  
	/*  Subscribe: stream=0;rule=16,stream=0;rule=17 */
    
	matched_rules = find_asmrule_match(stream->asm_rule_book,
					   &matched,bw);
	if((strlen(*subscribe) + 32 * matched_rules) > subscribe_len) {
	    /* subscribe should be longer */
	    subscribe_len = (subscribe_len * 2 >
			     strlen(*subscribe) + 32 * matched_rules) ?
		subscribe_len * 2 : strlen(*subscribe) + 32 * matched_rules;
	    *subscribe = (char *)xrealloc(*subscribe,subscribe_len);
	}
    
	for(j = 0; j < matched_rules ; j++) {
	    snprintf(subbuf,sizeof(subbuf),"stream=%u;rule=%u,",i,matched[j]);
	    strcat(*subscribe,subbuf);
	}
    
	buf = NULL;
	if(!stream->mlti_data) {
	    mlti_data_len = 0;
	}
	else {
	    /* buf is malloc()ed inside select_mlti_data */
	    mlti_data_len = select_mlti_data(stream->mlti_data,
					     stream->mlti_data_size,
					     matched[0],&buf);
	}
    
	rmff_header->streams[i] =
	    new_rmff_mdpr(stream->stream_id,
			  stream->max_bit_rate,
			  stream->avg_bit_rate,
			  stream->max_packet_size,
			  stream->avg_packet_size,
			  stream->start_time,
			  stream->preroll,
			  stream->duration,
			  stream->stream_name,
			  stream->mime_type,
			  mlti_data_len,
			  buf);
    
	duration = (duration > stream->duration) ? 
	    duration : stream->duration;
	max_bit_rate += stream->max_bit_rate;
	avg_bit_rate += stream->avg_bit_rate;
	max_packet_size = (max_packet_size > stream->max_packet_size) ?
	    max_packet_size : stream->max_packet_size;
    
	if(avg_packet_size) {
	    avg_packet_size = (avg_packet_size + stream->avg_packet_size) / 2;
	}
	else {
	    avg_packet_size = stream->avg_packet_size;
	}
    
	if(matched) {
	    free(matched);
	    matched = NULL;
	}
	if(buf) {
	    free(buf);
	    buf = NULL;
	}
    
    }
  
    if((*subscribe)[strlen(*subscribe) -1 ] == ',') {
	(*subscribe)[strlen(*subscribe) -1 ] = '\0'; /* delete last comma */
    }
  
    rmff_header->prop =
	new_rmff_prop(max_bit_rate,
		      avg_bit_rate,
		      max_packet_size,
		      avg_packet_size,
		      0,
		      duration,
		      0,0,0,
		      desc->stream_count,
		      desc->flags);

    rmff_fix_header(rmff_header);
  
    free_sdpreal_t(desc);

    rmff_print_header(rmff_header);
  
    return rmff_header;
}



/*
 * send OPTIONS request, this is used as very first trial to server
 * we will need rtsp_hdr later, so return that.
 * return value:   -1: failure   status_code: success, rtsp_hdr_ret(malloc)
 */
int real_rtsp_options(struct stream_t *stream,struct rtsp_header_t **rtsp_hdr_ret)
{
    int ret = 0;
    struct rtsp_ctrl_t *rtsp_ctrl = stream->stream_ctrl->rtsp_ctrl;
    struct rtsp_header_t *rtsp_hdr = NULL;
    char *options_uri = NULL;
    int options_uri_len = 0;

    /* default is rtsp-real (becasue OPTIONS req is supported) */
    rtsp_hdr = new_rtsp_header_with_standard_fields(rtsp_ctrl);
    
    rtsp_set_field(rtsp_hdr,real_useragent);
    rtsp_set_field(rtsp_hdr,"GUID: 00000000-0000-0000-0000-000000000000");
    rtsp_set_field(rtsp_hdr,real_clientid);  
    rtsp_set_field(rtsp_hdr,"Pragma: initiate-session");
    rtsp_set_field(rtsp_hdr,"RegionData: 0");
    rtsp_set_field(rtsp_hdr,real_clientchallenge);
    rtsp_set_field(rtsp_hdr,real_companyid);
    rtsp_set_field(rtsp_hdr,real_playerstarttime);
    
    
    options_uri_len = strlen(stream->serverinfo->host) + 20;
    options_uri = (char *)xmalloc(options_uri_len);
    snprintf(options_uri,options_uri_len,"rtsp://%s:%i",
	     stream->serverinfo->host,stream->serverinfo->port);
    
    rtsp_request_options(rtsp_hdr,options_uri);
    rtsp_send_request_and_free(stream,rtsp_hdr);
    
    rtsp_hdr = new_rtsp_header();
    ret = rtsp_recv_header(stream,rtsp_hdr);
    if(ret < 0) {
	goto failed;
    }

    *rtsp_hdr_ret = rtsp_hdr;
    
    if(options_uri) free(options_uri);
    return ret;

  failed:
    if(rtsp_hdr)    free_rtsp_header(rtsp_hdr);
    if(options_uri) free(options_uri);
    *rtsp_hdr_ret = NULL;
    return -1;
}



/*
 * send DESCRIBE request
 * return value:   -1: failure   status_code: success
 */
static int real_rtsp_describe(struct stream_t *stream,char **description_ret)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct rtsp_ctrl_t *rtsp_ctrl = stream_ctrl->rtsp_ctrl;
    struct rtsp_header_t *rtsp_hdr = NULL;

    char *description = NULL;
    char *buffer = (char *)xmalloc(BUFSIZE_1K);
    char *field = NULL;
    int len = 0;
    int ret = 0;
    
    rtsp_hdr = new_rtsp_header_with_standard_fields(rtsp_ctrl);
    rtsp_set_field(rtsp_hdr, "Accept: application/sdp");
    rtsp_set_field(rtsp_hdr, real_useragent);
    rtsp_set_field(rtsp_hdr, "Require: com.real.retain-entity-for-setup");
  
    snprintf(buffer,BUFSIZE_1K - 1,"Bandwidth: %u",stream_ctrl->bandwidth);
    rtsp_set_field(rtsp_hdr,buffer); 
  
    rtsp_set_field(rtsp_hdr, "Language: en-US");
    rtsp_set_field(rtsp_hdr, "RegionData: 0");
    rtsp_set_field(rtsp_hdr, real_clientid);
    rtsp_set_field(rtsp_hdr, "GUID: 00000000-0000-0000-0000-000000000000");
    rtsp_set_field(rtsp_hdr, "SupportsMaximumASMBandwidth: 1");
  
  
    rtsp_request_describe(rtsp_hdr,rtsp_ctrl->mrl);
    rtsp_send_request_and_free(stream,rtsp_hdr);
    
    rtsp_hdr = new_rtsp_header();
    ret = rtsp_recv_header(stream,rtsp_hdr);
    if(ret < 0) {
	free_rtsp_header(rtsp_hdr);
	goto failed;
    }
    
    /* NOT OK */
    if(!is_rtsp_response_ok(rtsp_hdr->status_code)) { 
	display(MSDL_ERR,"DESCRIBE request returned: %d (%s)\n",
		rtsp_hdr->status_code,rtsp_hdr->reason_phrase);
	
	field = rtsp_get_field(rtsp_hdr,"Alert");
	if(field) {
	    while(*field == ' ') field++;
	    display(MSDL_ERR,"message from server --> %s\n",field);
	}
	free_rtsp_header(rtsp_hdr);
	goto failed;
    }

    len = 0;
    /* Content-length must be present */
    if((field = rtsp_get_field(rtsp_hdr,"Content-length")) != NULL) {
	while(*field == ' ') field++;
	len = atoi(field);
    }
    else { /* no Content-length */
	display(MSDL_ERR,"warning: No Content-length in fields!!\n");
    }
  
    if((field = rtsp_get_field(rtsp_hdr,"ETag")) != NULL) {
	while(*field == ' ') field++;
	rtsp_ctrl->etag = strdup(field);
    }
    else {
	display(MSDL_ERR,"warning: No ETag!!\n");
	rtsp_ctrl->etag = NULL;
    }

    free_rtsp_header(rtsp_hdr);  
    
    /*
      copy description (sdp)
    */
    description = (char *)xmalloc(len + 1);
    if(read_data(stream,(uint8_t *)description,len) < 0) {
	goto failed;
    }
    description[len] = '\0';
  
    display(MSDL_DBG,"==================\n%s\n=(%d bytes)========\n",
	    description,(int)strlen(description));
    
    
    if(buffer) free(buffer);
    *description_ret = description;
    return ret;
    
  failed:
    if(description) free(description);
    if(buffer) free(buffer);
    *description_ret = NULL;
    return -1;
}



/*
 * send SETUP requst. 2 setups for multiple streams.
 * return value ...     what rtsp_recv_header returned
 */
static int real_rtsp_setup(struct stream_t *stream,struct rmff_header_t *rmff_header)
{
    struct rtsp_ctrl_t *rtsp_ctrl = stream->stream_ctrl->rtsp_ctrl;
    struct rtsp_header_t *rtsp_hdr = NULL;
    char *buffer = (char *)xmalloc(BUFSIZE_1K);
    int ret = 0;
    char challenge2[64];
    char checksum[34];
    
    rtsp_hdr = new_rtsp_header_with_standard_fields(rtsp_ctrl);
    
    real_calc_challenge2_and_checksum(rtsp_ctrl->challenge,challenge2,checksum);
  
    snprintf(buffer,BUFSIZE_1K - 1,"RealChallenge2: %s, sd=%s",
	     challenge2,checksum);
    rtsp_set_field(rtsp_hdr,buffer);
    snprintf(buffer,BUFSIZE_1K - 1,"If-Match: %s",rtsp_ctrl->etag);
    rtsp_set_field(rtsp_hdr,buffer);
    rtsp_set_field(rtsp_hdr,"RDTFeatureLevel: 2");
    rtsp_set_field(rtsp_hdr,real_transport);
    snprintf(buffer,BUFSIZE_1K - 1,"%s/streamid=0",rtsp_ctrl->mrl);
    rtsp_request_setup(rtsp_hdr,buffer);
    rtsp_send_request_and_free(stream,rtsp_hdr);
    
    /* receive message for SETUP */
    ret = rtsp_recv_header_ignore_message(stream);
    
    
    /*
      send messages if multiple stream exists (max is 2 streams anyways...)
    */
    if(rmff_header->prop->num_streams > 1) {
	rtsp_hdr = new_rtsp_header_with_standard_fields(rtsp_ctrl);

	rtsp_set_field(rtsp_hdr,real_transport);
	snprintf(buffer,BUFSIZE_1K - 1,"If-Match: %s",rtsp_ctrl->etag);
	rtsp_set_field(rtsp_hdr,buffer);
	snprintf(buffer,BUFSIZE_1K - 1,"%s/streamid=1",rtsp_ctrl->mrl);
	rtsp_request_setup(rtsp_hdr,buffer);
    
	rtsp_send_request_and_free(stream,rtsp_hdr);
	
	/* receive message for SETUP */
	ret = rtsp_recv_header_ignore_message(stream);
    }
    
    free(buffer);
    return ret; 
}



/*
 * send SET_PARAMETER, with stream choosing subscribe.
 * return value ...     what rtsp_recv_header returned
 */
static int real_rtsp_set_parameter(struct stream_t *stream,char *subscribe)
{
    struct rtsp_ctrl_t *rtsp_ctrl = stream->stream_ctrl->rtsp_ctrl;
    struct rtsp_header_t *rtsp_hdr = NULL;
    int ret = 0;
    
    rtsp_hdr = new_rtsp_header_with_standard_fields(rtsp_ctrl);
    rtsp_set_field(rtsp_hdr,subscribe);
    if(stream->dlopts->bandwidth) { /* when user specified bandwidth */
	char *buffer = (char *)xmalloc(BUFSIZE_1K);
	snprintf(buffer,BUFSIZE_1K - 1,
		 "SetDeliveryBandwidth: Bandwidth=%d;BackOff=0",stream->dlopts->bandwidth);
	rtsp_set_field(rtsp_hdr,buffer);
	free(buffer);
    }
    
    rtsp_request_set_parameter(rtsp_hdr,rtsp_ctrl->mrl);
    rtsp_send_request_and_free(stream,rtsp_hdr);
    ret = rtsp_recv_header_ignore_message(stream);

    return ret;
}


/*
 * send PLAY request
 * return value ...     what rtsp_recv_header returned
 */
static int real_rtsp_play(struct stream_t *stream)
{
    struct rtsp_ctrl_t *rtsp_ctrl = stream->stream_ctrl->rtsp_ctrl;
    struct rtsp_header_t *rtsp_hdr = NULL;
 
    char *field = NULL;
    int ret = 0;
    
    /* 
     * Sending part 
     */
    rtsp_hdr = new_rtsp_header_with_standard_fields(rtsp_ctrl);

    if(stream->dlopts->resume_download) {
	real_prepare_resuming(stream);
    }

    if(stream->dlopts->bandwidth) { /* when user specified bandwidth */
	char *buffer = (char *)xmalloc(BUFSIZE_1K);
	snprintf(buffer,BUFSIZE_1K - 1,
		 "Bandwidth: %d",stream->dlopts->bandwidth);
	rtsp_set_field(rtsp_hdr,buffer);
	free(buffer);
    }
    
    rtsp_set_range_field(rtsp_hdr,stream->dlopts->range);
    rtsp_set_speed_field(rtsp_hdr,stream->dlopts->speed);
    
    rtsp_request_play(rtsp_hdr,rtsp_ctrl->mrl);
  
    rtsp_send_request_and_free(stream,rtsp_hdr);
    
    
    /* 
     * Receiving part 
     */
    /* receive message for PLAY request */
    rtsp_hdr = new_rtsp_header();
    ret = rtsp_recv_header(stream,rtsp_hdr);
    
    if(!is_rtsp_response_ok(rtsp_hdr->status_code)) { 
	display(MSDL_ERR,"PLAY request returned: %d (%s)\n",
		rtsp_hdr->status_code,rtsp_hdr->reason_phrase);
	
	field = rtsp_get_field(rtsp_hdr,"Alert");
	if(field) {
	    while(*field == ' ') field++;
	    display(MSDL_ERR,"message from server --> %s\n",field);
	}
	free_rtsp_header(rtsp_hdr);
	goto failed;
    }

    /* display real speed (might differ from user requested) */
    if((field = rtsp_get_field(rtsp_hdr,"Speed")) != NULL) {    
	if(stream->dlopts->speed) {
	    while(*field == ' ') field++;
	    display(MSDL_NOR,"Speed: %s\n",field);
	}
    }
    if((field = rtsp_get_field(rtsp_hdr,"Range")) != NULL) {    
	if(stream->dlopts->range) {
	    while(*field == ' ') field++;
	    display(MSDL_NOR,"Range: %s\n",field);
	}
    }

    /* skip content-length bytes from network */
    rtsp_ignore_data_after_header(stream,rtsp_hdr);
    free_rtsp_header(rtsp_hdr);
    
    return ret;

  failed:
    return -1;
}




/*
 * send SETUP,SEND_REQUEST,PLAY requests.
 *
 *      return value               1: success
 *                                -1: error
 */
int real_setup_and_get_header(struct stream_t *stream,
			      struct rmff_header_t **rmff_header_ret)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct rmff_header_t *rmff_header = NULL;
    
    char *description = NULL;
    char *subscribe = NULL;

    /*
      !!!CAUTION!!!
      setting maxbw too high may cause download failure!!
    */
    
    /* don't use this value, its just for choosing highest rate stream */
    if(stream->dlopts->bandwidth) {
	stream_ctrl->bandwidth = stream->dlopts->bandwidth;
    }
    else {
	stream_ctrl->bandwidth = 10485800;
    }


    if(real_rtsp_describe(stream,&description) < 0) {
	goto failed;
    }
    
    /* parse sdp and get information about file to download */
    rmff_header = real_parse_sdp(description,&subscribe,stream_ctrl->bandwidth);
    if(!rmff_header) {
	goto failed;
    }


    display(MSDL_VER,"sdp parse done.\n");

    /* send SETUP request */
    if(real_rtsp_setup(stream,rmff_header) < 0) {
	goto failed;
    }
    
    /* send SET_PARAMETER request to download stream */
    if(real_rtsp_set_parameter(stream,subscribe) < 0) {
	goto failed;
    }
    
    /*  send PLAY request to download stream */
    if(real_rtsp_play(stream) < 0) {
	goto failed;
    }
    
    free(subscribe);
    free(description);
    
    *rmff_header_ret = rmff_header;
    return 1;
  
  failed:
    if(subscribe) free(subscribe);
    if(description) free(description);
    if(rmff_header) free_rmff_header_t(rmff_header);
    *rmff_header_ret = NULL;
    return -1;
}



/*
 * read from media stream. (real rdp packet)
 * 
 * fill 'buffer' with data, and buffer size is 'max_size'.
 * receive one chunk from netsock->sock, and fills 'max_size' bytes to buffer.
 * and if there are more bytes in the chunk, the data is stored to
 * stream->netsock->buffer.
 *
 *    return value: positive value ... bytes written to buffer.
 *                  0              ... END OF STREAM
 *                 -1              ... ERROR
 */
int real_rdt_get_media_packet(struct stream_t *stream,
			      uint8_t *buffer,size_t max_size)
{
    int ret = 0;
    uint8_t header[8];
    
    ret = read_data(stream,header,8);
    if(ret < 0) {
	goto failed;
    }

    while(!strncmp((char *)header,"SET_",4) ||
	  !strncmp((char *)header,"GET_",4) ||
	  !strncmp((char *)header,"OPTI",4) ||
	  !strncmp((char *)header,"RTSP",4) ||
	  !strncmp((char *)header,"ANNO",4)) {
	
	stream_data_push_back(stream,header,8); /* push back header */
	ret = real_process_header(stream);
	if(ret < 0) {
	    goto failed;
	}
	
	ret = read_data(stream,header,8);
	if(ret < 8) {
	    goto failed;
	}
    }
    
    ret = real_process_media_packet(stream,header,buffer,max_size);
    return ret;

  failed:
    return -1;
}


/*
 * process rtsp header coming among rtsp real media packet
 * 
 * return value:       status code ... normal proceed case
 *                               0 ... EOF packet (not possible)
 *                              -1 ... error
 */
static int real_process_header(struct stream_t *stream)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct rtsp_ctrl_t *rtsp_ctrl = stream_ctrl->rtsp_ctrl;
    struct rtsp_header_t *rtsp_hdr = NULL;
    int status_code = 0;
    int bodylen = 0;
    uint8_t *body = NULL;
    char *field = NULL;
    int got_cseq = 0;

    rtsp_hdr = new_rtsp_header();
    status_code = rtsp_recv_header(stream,rtsp_hdr);
    if(status_code < 0) {
	goto failed;
    }
    
    
    /* get content length data */
    if((field = rtsp_get_field(rtsp_hdr,"Content-length")) != NULL) {
	while(*field == ' ') field++;
	bodylen = atoi(field);	
	body = (uint8_t *)xmalloc(bodylen);
	bodylen = read_data(stream,body,bodylen);
    }
    /* get Cseq, for sending OK back */
    if((field = rtsp_get_field(rtsp_hdr,"Cseq")) != NULL) {
	while(*field == ' ') field++;
	got_cseq = atoi(field);	
    }


    if(!strncmp(rtsp_hdr->protocol,"RTSP",4)) { /* RTSP/1.0 200 OK , ignore this */
	/*
	  somehow RTSP message reply can be found among rdt messages.
	  send nothing.
	*/
	if(!got_cseq == rtsp_ctrl->cseq - 1) {
	    display(MSDL_DBG,"CSeq mismatch: expected %d, got %d",
		    rtsp_ctrl->cseq - 1,got_cseq);
	}
	/* DO NOT send RTSP OK */
    }
    else { /* not RTSP, whatever it is, send OK would be just fine  */
	rtsp_200ok(stream,got_cseq,rtsp_ctrl->session);
    }
    

    if(rtsp_hdr) free_rtsp_header(rtsp_hdr);      
    if(body)     free(body);
    return status_code;

  failed:
    if(body)     free(body);
    if(rtsp_hdr) free_rtsp_header(rtsp_hdr);
    return -1;
}



static int real_process_media_packet(struct stream_t *stream,uint8_t *header,
				     uint8_t *buffer,size_t max_size)
{
    int ret = 0;
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct rmff_pheader_t ph = {0};
    int size = 0;
    int seq = 0;
    int flags1 = 0,flags2 = 0;
    uint32_t ts = 0;

    if(header[0] != 0x24) {
	display(MSDL_ERR,"wrong rdt magic : [0x%02x]\n",header[0]);
	/* dump header*/
	dbgdump(header,8);
	display(MSDL_DBG,"\n");
	goto failed;
    }

    size = (header[1] << 16) + (header[2] << 8) + header[3];
    flags1 = header[4];
  
    if((flags1!=0x40) && (flags1!=0x42)) {
	display(MSDL_DBG,"wrong rdt flags1 : [0x%02x]\n",flags1);
	if(header[6] == 0x06) {
	    display(MSDL_DBG,"got end of stream packet\n");
	    stream_ctrl->status = STREAMING_FINISHED;
	    return 0;
	}
	header[0] = header[5];
	header[1] = header[6];
	header[2] = header[7];
	
	ret = read_data(stream,header + 3,5);
	if(ret < 5) goto failed;
    
	ret = read_data(stream,header + 4,4);
	if(ret < 4) goto failed;
    
	flags1 = header[4];
	size -= 9;
    
    }
    flags2 = header[7];
    seq = (header[5] << 8) + header[6];
    ret = read_data(stream,header,6);
    if(ret < 6) goto failed;
  
    ts = get32_be(header);
    stream_ctrl->packet_count++;
    display(MSDL_DBG,"ts:%u size:%u, flags1:0x%02x, seq:%d, flags2:%x\n",
	    ts,size,flags1,seq,flags2);
    
    size += 2;
  
    ph.object_version = 0;
    ph.length = size;
    ph.stream_number = (flags1>>1) & 1;
    ph.timestamp = ts;
    ph.reserved = 0;
  
    if((flags2 & 1) == 0 &&
       (stream_ctrl->rtsp_ctrl->prev_ts != ts ||
	stream_ctrl->rtsp_ctrl->prev_stream_number != ph.stream_number)) {
	stream_ctrl->rtsp_ctrl->prev_ts = ts;
	stream_ctrl->rtsp_ctrl->prev_stream_number = ph.stream_number;
	ph.flags = 2;
    }
    else {
	ph.flags = 0;
    }
  

    /*
     * Keep Alive SET_PARAMETER
     */
    /*if(!(stream_ctrl->packet_count % 200)) {
	struct rtsp_header_t *rtsp_hdr;
	rtsp_hdr = new_rtsp_header_with_standard_fields(stream_ctrl->rtsp_ctrl);
	if(stream->dlopts->bandwidth) {
	    char *buffer = xmalloc(BUFSIZE_1K);
	    snprintf(buffer,BUFSIZE_1K - 1,
		     "SetDeliveryBandwidth: Bandwidth=%d;BackOff=0",stream->dlopts->bandwidth);
	    rtsp_set_field(rtsp_hdr,buffer);
	    free(buffer);
	}
	rtsp_request_set_parameter(rtsp_hdr,stream_ctrl->rtsp_ctrl->mrl);
	rtsp_send_request_and_free(stream,rtsp_hdr);
	}*/

    
    /* if buffering, do special thing */
    if(stream_ctrl->status == STREAMING_RESUME_BUFFERING) {
	display(MSDL_DBG,
		"target ts: %d [0x%x], current packet ts: %d [0x%x]\n",
		stream_ctrl->rtsp_ctrl->resume_start_ts,
		stream_ctrl->rtsp_ctrl->resume_start_ts,
		ph.timestamp,ph.timestamp);

	if(ph.timestamp == stream_ctrl->rtsp_ctrl->resume_start_ts) {
	    stream_ctrl->status = STREAMING_DOWNLOADING; /* fallthrouh */
	}
	else {
	    int ret = 0;
	    ret = read_data(stream,stream_ctrl->write_buffer,size - 12); /* trash data */
	    if(ret <= 0) goto failed;
	    return 0;
	}
    }


    if(max_size > size) {
	/* all data can go to buffer --> just do it!! */
	rmff_dump_pheader(&ph,buffer);
	size -= 12;
	ret = read_data(stream,buffer + 12,size);
	if(ret <= 0) goto failed;
    
	return ret + 12;
    }
    else {
	/*
	  buffer is not enough.. copy max_size data to 
	  buffer and the rest goes to netsock->buffer.
	*/
	rmff_dump_pheader(&ph,stream_ctrl->write_buffer);
    
	ret = read_data(stream,stream_ctrl->write_buffer + 12,size - 12);
	if(ret <= 0) goto failed;
	
	/*
	  it is guranteed that netsock->buffer is
	  empty when it comes here!
	  --> reset stream_ctrl->write_pos and so on...
	*/
    	memcpy(buffer,stream_ctrl->write_buffer,max_size);
	stream_ctrl->write_data_len = size - max_size;
	stream_ctrl->write_pos = max_size;
    
	return max_size;
    }
    
  failed:
    return -1;
}




/*
 * prepare_resuming for real rtsp
 * return value:     1 ... success
 *                  -1 ... failed
 */
int real_prepare_resuming(struct stream_t *stream)
{
    uint32_t last_send_time = 0;
    uint64_t seek_pos = 0;

    int ret = 0;

    ret = real_get_last_npt_of_file(stream->localfile,&last_send_time,&seek_pos);
    if(ret < 0) {
	goto failed;
    }
    
    if((last_send_time / 1000) < MINIMUM_RESUME_START_TIME) {
	display(MSDL_ERR,
		"file \"%s\" has only %d sec, just start from beginning\n",
		stream->localfile,last_send_time / 1000);
	goto failed;
    }

    stream->stream_ctrl->rtsp_ctrl->resume_start_ts = last_send_time;

    if(stream->dlopts->range) {
	free(stream->dlopts->range);
    }
    stream->dlopts->range =
	rtsp_make_range_from_timestamp(last_send_time - RESUME_BUFFERING_TIME);
    stream->resumeinfo->resume_start_offset = seek_pos;
    stream->resumeinfo->resume_req_success = 1;
    
    display(MSDL_DBG,
	    "real resume: start ts: %d [0x%x]  pos: %lld [0x%llx]\n",
	    last_send_time,last_send_time,seek_pos,seek_pos);
    
    return 1;
  failed:
    stream->resumeinfo->resume_start_offset = 0;
    stream->resumeinfo->resume_req_success  = 0;
    return -1;
}





/*
 * get info for resuming
 * @send_time  : last packet npt    (out)
 * @seek_offset: last packet offset (out)
 * return value:   1 ... success
 *                -1 ... failure
 */
int real_get_last_npt_of_file(char *local_filename,uint32_t *send_time,uint64_t *seek_offset)
{
    FILE *lfp = NULL;
    uint32_t header_buffer_size = 400;
    uint32_t header_buffer_filled = 0;
    uint8_t *rmff_header_buffer = NULL;
    int ret = 0;
    uint64_t file_size = 0;
    uint64_t rmff_data_start_pos = 0;
    uint64_t curpos = 0;
    uint8_t phbuf[18];
    struct rmff_pheader_t ph = {0};
    uint32_t last_ts = 0,this_ts = 0;
    uint64_t last_ts_offset = 0;
    
    if((lfp = fopen(local_filename,"rb")) == NULL) {
	display(MSDL_ERR,
		"resume \"%s\" : cannot open file for resume\n",local_filename);
	goto failed;
    }
    
    rmff_header_buffer = (uint8_t *)xmalloc(header_buffer_size);
    /* 1st read */
    ret = fread(rmff_header_buffer,sizeof(uint8_t),header_buffer_size,lfp);
    header_buffer_filled = ret;
    
    if(ret < header_buffer_size) {
	if(ferror(lfp)) {
	    display(MSDL_ERR,"resume \"%s\": cannot read file \n",local_filename);
	}
	else {
	    display(MSDL_ERR,"resume \"%s\": too small for resume\n",local_filename);
	}
	/* couldn't read, or just only very small amount of data in file*/
	goto failed;
    }
    
    if(get32_be(rmff_header_buffer) != RMF_TAG) {
	/* not the rmff file */
	display(MSDL_ERR,"resume \"%s\": not an real file\n",local_filename);
	goto failed;
    }

    ret = get_filesize(local_filename,&file_size);
    if(ret < 0) {
	/* stat() failed */
	goto failed;
    }

    rmff_data_start_pos = get32_be(rmff_header_buffer + 60) + 18;
    last_ts = 0;
    
    for(curpos = rmff_data_start_pos;
	curpos + sizeof(struct rmff_pheader_t) <= file_size;) {
	
	fseek(lfp,curpos,SEEK_SET);
	ret = fread(phbuf,sizeof(uint8_t),sizeof(struct rmff_pheader_t),lfp);
	rmff_read_pheader(phbuf,&ph);
	if(ret < sizeof(struct rmff_pheader_t)) {
	    display(MSDL_ERR,"resume \"%s\": pheader read error",local_filename);
	    goto failed;
	}
	this_ts = ph.timestamp;
	/*
	printf("this_ts = %d [%x] ph_length = %d %x,cur:%x last:%x (%d)\n",
	this_ts,this_ts,
	ph.length,ph.length,
	curpos,
	last_ts_offset,last_ts_offset);
	*/
	if(this_ts > last_ts) { /* renew ts */
	    last_ts = this_ts;
	    last_ts_offset = curpos;
	    this_ts = 0;
	}
	
	curpos += ph.length;
    }
    
    fclose(lfp);
    free(rmff_header_buffer);
    *send_time = last_ts;
    *seek_offset = last_ts_offset;

    return 1;

  failed:
    if(lfp) fclose(lfp);
    if(rmff_header_buffer) free(rmff_header_buffer);
    *send_time = 0;
    *seek_offset = 0;
    return -1;
}
