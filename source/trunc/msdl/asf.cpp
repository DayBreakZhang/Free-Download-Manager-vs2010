/***********************************************************************
 *    asf.c:  for interpreting ASF(Advanced Systems Format) format
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on asf implementation of mplayer,
 * and various information on the internet about ASF.
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
 * Some code or data in this file is based on
 * MPlayer project
 * (MPlayer-1.0rc2/stream/libmpdemux/asfheader.c)
 */


#include "stdafx.h"
#include "msdllib.h"
#include "network.h"
#include "asf.h"



/*
  guid
*/
const uint8_t asf_stream_header_guid[ASF_GUID_LENGTH] =
{0x91, 0x07, 0xdc, 0xb7, 0xb7, 0xa9, 0xcf, 0x11,
 0x8e, 0xe6, 0x00, 0xc0, 0x0c, 0x20, 0x53, 0x65};

const uint8_t asf_file_header_guid[ASF_GUID_LENGTH] = 
{0xa1, 0xdc, 0xab, 0x8c, 0x47, 0xa9, 0xcf, 0x11,
 0x8e, 0xe4, 0x00, 0xc0, 0x0c, 0x20, 0x53, 0x65};

const uint8_t asf_content_desc_guid[ASF_GUID_LENGTH] =
{0x33, 0x26, 0xb2, 0x75, 0x8e, 0x66, 0xcf, 0x11,
 0xa6, 0xd9, 0x00, 0xaa, 0x00, 0x62, 0xce, 0x6c};

const uint8_t asf_stream_group_guid[ASF_GUID_LENGTH] =
{0xce, 0x75, 0xf8, 0x7b, 0x8d, 0x46, 0xd1, 0x11,
 0x8d, 0x82, 0x00, 0x60, 0x97, 0xc9, 0xa2, 0xb2};

const uint8_t asf_header_object_guid[ASF_GUID_LENGTH] =
{0x30, 0x26, 0xb2, 0x75, 0x8e, 0x66, 0xcf, 0x11,
 0xa6, 0xd9, 0x00, 0xaa, 0x00, 0x62, 0xce, 0x6c};

const uint8_t asf_data_object_guid[ASF_GUID_LENGTH] =
{0x36, 0x26, 0xb2, 0x75, 0x8e, 0x66, 0xcf, 0x11,
 0xa6, 0xd9, 0x00, 0xaa, 0x00, 0x62, 0xce, 0x6c};

const uint8_t asf_ext_stream_embed_stream_header[ASF_GUID_LENGTH] =
{0xe2, 0x65, 0xfb, 0x3a, 0xef, 0x47, 0xf2, 0x40,
 0xac, 0x2c, 0x70, 0xa9, 0x0d, 0x71, 0xd3, 0x43};

const uint8_t asf_ext_stream_audio[ASF_GUID_LENGTH] =
{0x9d, 0x8c, 0x17, 0x31, 0xe1, 0x03, 0x28, 0x45,
 0xb5, 0x82, 0x3d, 0xf9, 0xdb, 0x22, 0xf5, 0x03};

const uint8_t asf_ext_stream_header[ASF_GUID_LENGTH] =
{0xCB, 0xA5, 0xE6, 0x14, 0x72, 0xC6, 0x32, 0x43,
 0x83, 0x99, 0xA9, 0x69, 0x52, 0x06, 0x5B, 0x5A};


static int max_idx(int s_count,int *s_rates,int bound);
static struct asf_file_header_t *new_asf_file_header_t(void);
static void free_asf_file_header_t(struct asf_file_header_t *ast);

static struct asf_streams_t *new_asf_streams_t(void);
static void free_asf_streams_t(struct asf_streams_t *ast);



static struct asf_file_header_t *new_asf_file_header_t(void)
{
    struct asf_file_header_t *afht =
	(struct asf_file_header_t *)xmalloc(sizeof(struct asf_file_header_t));
    return afht;
}



static void free_asf_file_header_t(struct asf_file_header_t *afht)
{
    free(afht);
}



static struct asf_streams_t *new_asf_streams_t(void)
{
    struct asf_streams_t *ast =
	(struct asf_streams_t *)xmalloc(sizeof(struct asf_streams_t));
    return ast;
}



static void free_asf_streams_t(struct asf_streams_t *ast)
{
    if(ast->audio_streams) free(ast->audio_streams);
    if(ast->video_streams) free(ast->video_streams);
    free(ast);
}



struct asf_headerinfo_t *new_asf_headerinfo_t(void)
{
    struct asf_headerinfo_t *info =
	(struct asf_headerinfo_t *)xmalloc(sizeof(struct asf_headerinfo_t));

    info->asf_header = NULL;
    info->asf_header_len = 0;

    info->fileh = new_asf_file_header_t();
    info->streams = new_asf_streams_t();
    return info;
}



void free_asf_headerinfo_t(struct asf_headerinfo_t *info)
{
    if(!info) return;

    if(info->asf_header) free(info->asf_header);

    if(info->fileh) free_asf_file_header_t(info->fileh);
    if(info->streams) free_asf_streams_t(info->streams);
    free(info);
}



/* 
 * buffer is starting of asf header, and asf_header_size is its size.
 * in asf_choose_best_streams, choose highest streams which works fine
 * with specified bandwidth(bw).
 * all parsed result will be available in asf_http_ctrl;
 *              *** THIS IS A WRAPPER FUNCTION ***
 *                 return value:      1 ... success
 *                                   -1 ... error
 */
int asf_interpret_header(struct asf_headerinfo_t *hinfo,const int bw,
			 const uint8_t *buffer,const size_t asf_header_size)
{
    int ret = 0;
    /*
      The ASF header might come in more than 2 packets. so we have to 
      get all chunks before construct asf_header_t(asfh).
    */  
    ret = asf_get_file_property(buffer,
				asf_header_size,
				hinfo->fileh);
    if(ret < 0) { /* error */
	display(MSDL_ERR,"packet size get error\n");
	return -1;
    }
    
    ret = asf_choose_best_streams(buffer,asf_header_size,
				  bw, /* choose maximum bandwidth */
				  hinfo->streams);
    return ret;
}



int find_asf_guid(const uint8_t *buffer,int cur_pos,const uint8_t *guid,int buffer_len)
{
    int i = 0;
    for(i = cur_pos; i < buffer_len - 19 ; i++) {
	if((uint8_t)guid[0] == (uint8_t)buffer[i]) {
	    if(memcmp(buffer + i,guid,ASF_GUID_LENGTH) == 0)
		return i + 16 + 8; /* point after guid + length */
	}
    }
    return -1;
}



/*
 * find best idx
 */
static int max_idx(int s_count,int *s_rates,int bound)
{
    int i = 0, best = -1, rate = -1;
    for(i = 0; i< s_count; i++) {
	if(s_rates[i] > rate && s_rates[i] <= bound) {
	    rate = s_rates[i];
	    best = i;
	}
    }
    return best;
}



/*
 * get file property.
 * return value        packet size  ... success
 *                              -1  ... error
 */
int asf_get_file_property(const uint8_t *header,int asf_header_size,
			  struct asf_file_header_t *fileh)
{
    int pos = 0;
    int packet_size = 0;
  
    /*
      examine file properties
    */
    pos = find_asf_guid(header,0,asf_file_header_guid,asf_header_size);
    
    if(pos < 0) {
	goto failed;
    }
    
    if((pos + sizeof(struct asf_file_header_t )) > asf_header_size) {/* 2big */
	goto failed;
    }
    
    memcpy((uint8_t *)fileh,header + pos,sizeof(struct asf_file_header_t));
    
    /* little endian */
    fileh->file_size       = le2me_64(fileh->file_size);
    fileh->creation_time   = le2me_64(fileh->creation_time);
    fileh->num_packets     = le2me_64(fileh->num_packets);
    fileh->play_duration   = le2me_64(fileh->play_duration);
    fileh->send_duration   = le2me_64(fileh->send_duration);
    fileh->preroll         = le2me_64(fileh->preroll);
    fileh->flags           = le2me_32(fileh->flags);
    fileh->min_packet_size = le2me_32(fileh->min_packet_size);
    fileh->max_packet_size = le2me_32(fileh->max_packet_size);
    fileh->max_bitrate     = le2me_32(fileh->max_bitrate);
    
    display(MSDL_VER,"file size = %lld\n",fileh->file_size);
    display(MSDL_VER,"play_duration = %d\n",
	    fileh->play_duration/10000000);
    display(MSDL_VER,"send_duration = %d\n",
	    fileh->send_duration/10000000);
    display(MSDL_VER,"# of packets = %d\n",
	    fileh->num_packets);
    display(MSDL_VER,"flags = %x\n",
	    fileh->flags);
	
    packet_size = fileh->max_packet_size;

    display(MSDL_VER,"packet_size = %d\n",
	    fileh->max_packet_size);
    display(MSDL_VER,"min_packsize = %d\n",
	    fileh->min_packet_size);
    
    return packet_size;
    
  failed:
    return -1;
}



/*
 * choose best audio and video streams, below bw.
 * 'header' is an asf header, and 'asf_header_size' is its size.
 * the result will be in 'streams'
 *             return value:   1  ... success
 *                            -1  ... failed
 */
int asf_choose_best_streams(const uint8_t *header, int asf_header_size,
			    int bw, struct asf_streams_t *streams)
{

    int i = 0,pos = 0,start = 0;
    int *v_rates = NULL, *a_rates = NULL;
    int v_rate = 0, a_rate = 0, v_idx = -1, a_idx = -1;
  
    /*
      header is entire ASF header, including very first asf_header_t.
    */
    pos = sizeof(struct asf_header_t);
    start = pos;
  
    /*
      choose best (fastest) streams
    */
  
    while((pos = find_asf_guid(header,pos,asf_stream_header_guid,asf_header_size)) >= 0) {
	struct asf_stream_header_t *streamh = 
	    (struct asf_stream_header_t *)(header + pos);

	pos += sizeof(struct asf_stream_header_t);
	if(pos > asf_header_size)  /* error */
	    return -1;
    
    
	/* get ASF GUID PREFIX (first 4 byte of GUID) */
	switch(get32_le(streamh->type)) {
	    
	case ASF_AUDIO_STREAM: /* audio stream */
	    display(MSDL_VER,"audio stream detected!!!!\n");
	    if(streams->audio_streams == NULL) { /* no audio stream registerd yet */
		streams->audio_streams = (int *)xmalloc(sizeof(int));
		streams->n_audio = 1;
	    }
	    else { /* more audio streams.!! */
		streams->n_audio++;
		streams->audio_streams = 
		    (int *)xrealloc(streams->audio_streams,
				    streams->n_audio * sizeof(int));
	    }
	    streams->audio_streams[streams->n_audio - 1] =
		le2me_16(streamh->stream_no);
	    break;
      
	case ASF_VIDEO_STREAM: /* video streams */
	    display(MSDL_VER,"video stream detected!!!!\n");
	    if(streams->video_streams == NULL) { /* no video stream registerd yet */
		streams->video_streams = (int *)xmalloc(sizeof(int));
		streams->n_video = 1;
	    }
	    else { /* more video streams.!! */
		streams->n_video++;
		streams->video_streams = 
		    (int *)xrealloc(streams->video_streams,
				    streams->n_video * sizeof(int));
	    }
	    streams->video_streams[streams->n_video - 1] =
		le2me_16(streamh->stream_no);
	    break;
      
	case ASF_COMMAND_MEDIA_STREAM: /* Command media stream... whatever*/
	    display(MSDL_VER,"Command media stream detected, but ignore this.\n");
	    break;
      
	case ASF_FILE_TRANSFER_MEDIA_STREAM: /* File transfer media stream... 
						I don't know what the heck this is.*/
	    display(MSDL_VER,"File transfer stream detected, but ignore this.\n");
	    break;
      
	}
    }

    a_rates = (int *)xmalloc(streams->n_audio * sizeof(int));
    v_rates = (int *)xmalloc(streams->n_video * sizeof(int));

  
    pos = find_asf_guid(header,start,asf_stream_group_guid,asf_header_size);
    if(pos >= 0) {
	/* stream bitrate proterties object */

	int stream_count = 0;
	uint8_t *ptr = (uint8_t *)header + pos;
	
	display(MSDL_VER,"stream bitrate properties object\n");
    
	stream_count = get16_le(ptr); /* little endian. */
	ptr += sizeof(uint16_t);
	if(ptr > header + asf_header_size) goto failed;
	display(MSDL_VER,"stream count = [0x%x] [%u]\n",stream_count,stream_count);
	display(MSDL_VER,"audio streams: %d, video streams: %d\n",
		streams->n_audio,streams->n_video);

	for(i = 0; i < stream_count; i++) {
	    uint32_t rate = 0;
	    int id = 0;
	    int j = 0;
      
	    id = get16_le(ptr);
	    ptr += sizeof(uint16_t);
	    if(ptr > header + asf_header_size) goto failed;
	    rate = get32_le(ptr);
	    ptr += sizeof(uint32_t);
	    if(ptr > header + asf_header_size) goto failed;
      
	    display(MSDL_VER,
		    "stream_id   = [0x%x] [%u]\n"
		    "max bitrate = [0x%x] [%u]\n",
		    id,id,rate,rate);
      
	    for(j = 0; j < streams->n_audio; j++) {
		if(id == streams->audio_streams[j]) {
		    display(MSDL_VER,"is audio stream\n");
		    a_rates[j] = rate;
		    break;
		}
	    }
	    for(j = 0; j < streams->n_video; j++) {
		if(id == streams->video_streams[j]) {
		    display(MSDL_VER,"is video stream\n");
		    v_rates[j] = rate;
		    break;
		}
	    }
	}
    }

    /* just to make sure bw is not Zero! */
    if(bw == 0) {
	bw = INT_MAX_BANDWIDTH;
    }

    if(streams->n_audio) {
	/* find lowest-bitrate audio stream */
	a_rate = a_rates[0];
	a_idx = 0;
	for(i = 0; i < streams->n_audio; i++) {
	    if(a_rates[i] < a_rate) {
		a_rate = a_rates[i];
		a_idx = i;
	    }
	}
	if(max_idx(streams->n_video,v_rates,bw - a_rate) < 0) {
	    /* both audio and video are not possible, try video only next */
	    a_idx = -1;
	    a_rate = 0;
	}
    }
  
    /* find best video stream */
    v_idx = max_idx(streams->n_video,v_rates,bw - a_rate);
    if(v_idx >= 0) {
	v_rate = v_rates[v_idx];
    }
  
    /* find best auido stream */
    a_idx = max_idx(streams->n_audio,a_rates,bw - v_rate);

    free(v_rates);
    v_rates = NULL;
    free(a_rates);
    a_rates = NULL;

    if(a_idx < 0 && v_idx < 0) {
	display(MSDL_ERR,"bandwidth too low ... cannot get streams.");
	return -1;
    }
  
  
    if(a_idx >= 0) {
	streams->audio_id = streams->audio_streams[a_idx];
    }
    else if(streams->n_audio) {
	display(MSDL_ERR,"Bandwidth too too small so deselected audio....sad.\n");
    }
  
    if(v_idx >= 0) {
	streams->video_id = streams->video_streams[v_idx];
    }
    else if(streams->n_video) {
	display(MSDL_ERR,"Bandwidth too too small so deselected video....sad.\n");
    }
  
  
    return 1;

  failed:
    free(v_rates);
    free(a_rates);
    return -1;

}

/*
 * get send_time of ASF data packet
 * return value: 1
 */
int asf_data_packet_get_send_time(uint8_t *packet,uint32_t *send_time)
{
    struct asf_data_packet_header_t adph;
    
    asf_parse_data_packet_header(packet,&adph);
    *send_time = adph.ppi.send_time;

    return 1;
}


/*
 * get info for resuming
 * @send_time  : last packet npt    (out)
 * @seek_offset: last packet offset (out)
 * return value:   1 ... success
 *                -1 ... failure
 */
int asf_get_npt_of_last_packet(char *local_filename,uint32_t *send_time,uint64_t *seek_offset)
{
    FILE *lfp = NULL;
    uint8_t *asf_header_buffer = NULL;
    uint32_t header_buffer_size = ASF_HEADER_READ_AT_ONCE;
    uint32_t header_buffer_filled = 0;
    uint8_t *last_packet_buffer = NULL;
    
    size_t ret = 0;
    uint64_t asf_header_object_size = 0;
    uint64_t asf_packet_start_offset = 0;
    struct asf_file_header_t *fileh = NULL;
    int packet_size = 0;
    uint64_t file_size = 0;
    uint64_t last_data_packet_offset = 0;
    uint32_t last_send_time = 0;


    enum {
	ASF_DATA_OBJECT_HEADER_SIZE = 16 + 8 + 16 + 8 + 2,
    };


    if((lfp = fopen(local_filename,"rb")) == NULL) {
	display(MSDL_ERR,
		"resume \"%s\" : cannot open file for resume\n",local_filename);
	goto failed;
    }
    
    asf_header_buffer = (uint8_t *)xmalloc(header_buffer_size);
    /* read */
    ret = fread(asf_header_buffer,sizeof(uint8_t),header_buffer_size,lfp);
    if(!ret) {
	if(ferror(lfp)) {
	    display(MSDL_ERR,"resume \"%s\": asf_header_buffer_read_failed\n");
	    goto failed;
	}
    }
    
    header_buffer_filled = ret;

    if(ret < ASF_HEADER_READ_AT_ONCE) {
	if(ferror(lfp)) {
	    display(MSDL_ERR,"resume \"%s\": cannot read file \n",local_filename);
	}
	else {
	    display(MSDL_ERR,"resume \"%s\": too small for resume\n",local_filename);
	}
	/* couldn't read, or just only very small amount of data in file*/
	goto failed;
    }
    
    if(memcmp(asf_header_buffer,asf_header_object_guid,ASF_GUID_LENGTH)) {
	/* not the asf file */
	display(MSDL_ERR,"resume \"%s\": not an asf file\n",local_filename);
	goto failed;
    }
    asf_header_object_size = get64_le(asf_header_buffer + ASF_GUID_LENGTH);
    
    /* fill header buffer */
    if(asf_header_object_size + ASF_DATA_OBJECT_HEADER_SIZE > header_buffer_size) {
	header_buffer_size = asf_header_object_size + ASF_DATA_OBJECT_HEADER_SIZE;
	asf_header_buffer = (uint8_t *)xrealloc(asf_header_buffer,header_buffer_size);
	
	ret = fread(asf_header_buffer + header_buffer_filled,
		    sizeof(uint8_t),
		    header_buffer_size - header_buffer_filled,
		    lfp);
	if(!ret) {
	    if(ferror(lfp)) {
		display(MSDL_ERR,"resume \"%s\": asf_header_buffer_read_failed\n");
		goto failed;
	    }
	}
    }
    
    /* make sure all file properties object is read in memory */

    fileh = new_asf_file_header_t();
    packet_size = asf_get_file_property(asf_header_buffer,
					asf_header_object_size,
					fileh);
    if(packet_size < 0) {
	display(MSDL_ERR,"resume \"%s\": asf file header error\n",local_filename);
	goto failed;
    }

    if(memcmp(asf_header_buffer + asf_header_object_size,asf_data_object_guid,ASF_GUID_LENGTH)) {
	display(MSDL_ERR,"resume \"%s\": could not find ASF_data_object\n",local_filename);
	goto failed;
    }

    asf_packet_start_offset = asf_header_object_size + ASF_DATA_OBJECT_HEADER_SIZE;
    
    ret = get_filesize(local_filename,&file_size);
    if(ret < 0) {
	/* stat() failed */
	goto failed;
    }
    
    if(file_size < (packet_size * 2)) { /* not likely, but this will cause problem below */
	display(MSDL_ERR,"resume \"%s\": not enough data for getting resume info\n",local_filename);
	goto failed;
    }
    last_data_packet_offset = file_size - ((file_size - asf_packet_start_offset) % packet_size) - packet_size;
    display(MSDL_DBG,
	    "resume \"%s\": last asf data packet is at 0x%x\n",local_filename,
	    last_data_packet_offset);
    
    last_packet_buffer = (uint8_t *)xmalloc(packet_size);
    fseek(lfp,last_data_packet_offset,SEEK_SET);
    ret = fread(last_packet_buffer,sizeof(uint8_t),packet_size,lfp);
    if(ret < packet_size) {
	display(MSDL_ERR,"resume \"%s\": coulnd't read last packet\n",local_filename);
	goto failed;
    }
    
    asf_data_packet_get_send_time(last_packet_buffer,&last_send_time);
    
    if(lfp) fclose(lfp);
    if(asf_header_buffer) free(asf_header_buffer);
    if(last_packet_buffer) free(last_packet_buffer);
    if(fileh) free_asf_file_header_t(fileh);
    
    display(MSDL_NOR,
	    "resume \"%s\": try to resume from %ds\n",local_filename,last_send_time / 1000);
    *send_time = last_send_time;
    *seek_offset = last_data_packet_offset;
    return 1;
    
  failed:
    if(lfp) fclose(lfp);
    if(asf_header_buffer) free(asf_header_buffer);
    if(last_packet_buffer) free(last_packet_buffer);
    if(fileh) free_asf_file_header_t(fileh);
    display(MSDL_ERR,"just get file from beginning.\n");
    *send_time = 0;
    *seek_offset = 0;
    return -1;
}


/* 
 * parse asf_data_packet (@packet) and put the data in adph
 */
int asf_parse_data_packet_header(uint8_t *packet,struct asf_data_packet_header_t *adph)
{
    uint8_t ecd_flags = packet[0];
    uint8_t length_type_flags = 0;
    uint8_t property_flags = 0;
    int ppi_offset = 0;
    int next_offset = 0; /* length type dependent stuff */
    const int length_type_table[4] = {0,1,2,4};

    adph->ecd.error_correction_data_length = ecd_flags & 0x0f;
    adph->ecd.opaque_data_present          = (ecd_flags >> 4) & 0x01;
    adph->ecd.error_correction_length_type = (ecd_flags >> 5) & 0x03;
    adph->ecd.error_correction_present     = (ecd_flags >> 7) & 0x01;
    
    if(adph->ecd.error_correction_present) {
	ppi_offset = 1 + adph->ecd.error_correction_data_length;
    }
    else {
	ppi_offset = 1;
    }
    
    length_type_flags = packet[ppi_offset];
    property_flags    = packet[ppi_offset + 1];

    adph->ppi.multiple_payloads_present = length_type_flags & 0x01;
    adph->ppi.sequence_type             = (length_type_flags >> 1) & 0x03;
    adph->ppi.padding_length_type       = (length_type_flags >> 3) & 0x03;
    adph->ppi.packet_length_type        = (length_type_flags >> 5) & 0x03;
    adph->ppi.error_correction_present  = (length_type_flags >> 7) & 0x01;
    
    adph->ppi.replicated_data_length_type          = property_flags & 0x03;
    adph->ppi.offset_into_media_object_length_type = (property_flags >> 2) & 0x03;
    adph->ppi.media_object_number_length_type      = (property_flags >> 4) & 0x03;
    adph->ppi.stream_number_length_type            = (property_flags >> 6) & 0x03;
    
    next_offset = ppi_offset + 2;

    /* packet length  */
    adph->ppi.packet_length = 
	getnb_le(packet + next_offset,length_type_table[adph->ppi.packet_length_type]);
    next_offset += length_type_table[adph->ppi.packet_length_type];

    /* sequence       */
    adph->ppi.sequence = 
	getnb_le(packet + next_offset,length_type_table[adph->ppi.sequence_type]);
    next_offset += length_type_table[adph->ppi.sequence_type];

    /* padding length */
    adph->ppi.padding_length = 
	getnb_le(packet + next_offset,length_type_table[adph->ppi.padding_length_type]);
    next_offset += length_type_table[adph->ppi.padding_length_type];
    
    adph->ppi.send_time = get32_le(packet + next_offset);
    next_offset += sizeof(uint32_t);
    
    adph->ppi.duration = get16_le(packet + next_offset);
    next_offset += sizeof(uint16_t);
    
    return next_offset;
}

