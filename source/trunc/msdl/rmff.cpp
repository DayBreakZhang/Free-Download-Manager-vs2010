/***********************************************************************
 *    rmff.c: for using rmff header (real media file format)
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is mainly(totally) based on rmff.c in xine-lib,
 * and include code from xine.
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
 * (from MPlayer-1.0rc2/stream/realrtsp/rmff.c)
 */

/*
 * This file was ported to MPlayer from xine CVS rmff.c,v 1.3 2002/12/24 01:30:22
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
 * functions for real media file format
 * adopted from joschkas real tools
 */


#include "stdafx.h"

#include "snprintf.h"
#include "msdl.h"
#include "msdllib.h"
#include "rmff.h"


struct rmff_header_t *new_rmff_header_t(void)
{
    struct rmff_header_t *p = (struct rmff_header_t *)xmalloc(sizeof(struct rmff_header_t));
    return p;
}



/*
 * writes header data to a buffer
 */
static void rmff_dump_fileheader(struct rmff_fileheader_t *fileheader,
				 uint8_t *buffer)
{
    if (!fileheader) return;
  
    put32_be(buffer,     fileheader->object_id);
    put32_be(buffer + 4, fileheader->size);
    put16_be(buffer + 8, fileheader->object_version);
    put32_be(buffer + 10,fileheader->file_version);
    put32_be(buffer + 14,fileheader->num_headers);
}

static void rmff_dump_prop(struct rmff_prop_t *prop,uint8_t *buffer)
{

    if (!prop) return;
  
    put32_be(buffer,     prop->object_id);
    put32_be(buffer + 4, prop->size);
    put16_be(buffer + 8, prop->object_version);
    put32_be(buffer + 10,prop->max_bit_rate);
    put32_be(buffer + 14,prop->avg_bit_rate);
    put32_be(buffer + 18,prop->max_packet_size);
    put32_be(buffer + 22,prop->avg_packet_size);
    put32_be(buffer + 26,prop->num_packets);
    put32_be(buffer + 30,prop->duration);
    put32_be(buffer + 34,prop->preroll);
    put32_be(buffer + 38,prop->index_offset);
    put32_be(buffer + 42,prop->data_offset);
    put16_be(buffer + 46,prop->num_streams);  
    put16_be(buffer + 48,prop->flags);
}

static void rmff_dump_mdpr(struct rmff_mdpr_t *mdpr,uint8_t *buffer)
{

    int s1, s2, s3;

    if (!mdpr) return;
  
    put32_be(buffer,mdpr->object_id);
    put32_be(buffer + 4,mdpr->size);
    put16_be(buffer + 8,mdpr->object_version);
    put16_be(buffer + 10,mdpr->stream_number);
    put32_be(buffer + 12,mdpr->max_bit_rate);
    put32_be(buffer + 16,mdpr->avg_bit_rate);
    put32_be(buffer + 20,mdpr->max_packet_size);
    put32_be(buffer + 24,mdpr->avg_packet_size);
    put32_be(buffer + 28,mdpr->start_time);
    put32_be(buffer + 32,mdpr->preroll);
    put32_be(buffer + 36,mdpr->duration);

    put8(buffer + 40,mdpr->stream_name_size);
    s1 = mdpr->stream_name_size;
    memcpy(buffer + 41,mdpr->stream_name,s1);
  
    put8(buffer + 41 + s1,mdpr->mime_type_size);
    s2 = mdpr->mime_type_size;
    memcpy(buffer + 42 + s1,mdpr->mime_type,s2);
  
    put32_be(buffer + 42 + s1 + s2,mdpr->type_specific_len);
    s3 = mdpr->type_specific_len;
    memcpy(buffer + 46 + s1 + s2,mdpr->type_specific_data,s3);
}

static void rmff_dump_cont(struct rmff_cont_t *cont,uint8_t *buffer)
{

    int s1,s2,s3,s4;

    if (!cont) return;
  
    put32_be(buffer,cont->object_id);
    put32_be(buffer + 4,cont->size);
    put16_be(buffer + 8,cont->object_version);
  
    put16_be(buffer + 10,cont->title_len);
    s1 = cont->title_len;
    memcpy(buffer + 12,cont->title,s1);
  
    put16_be(buffer + 12 + s1,cont->author_len);
    s2 = cont->author_len;
    memcpy(buffer + 14 + s1,cont->author,s2);
  
    put16_be(buffer + 14 + s1 + s2,cont->copyright_len);
    s3 = cont->copyright_len;
    memcpy(buffer + 16 + s1 + s2,cont->copyright,s3);
  
    put16_be(buffer + 16 + s1 + s2 + s3,cont->comment_len);
    s4 = cont->comment_len;
    memcpy(buffer + 18 + s1 + s2,cont->comment,s4);
}

static void rmff_dump_dataheader(struct rmff_data_t *data,uint8_t *buffer)
{

    if (!data) return;

    put32_be(buffer,data->object_id);
    put32_be(buffer + 4,data->size);
    put16_be(buffer + 8,data->object_version);
    put32_be(buffer + 10,data->num_packets);
    put32_be(buffer + 14,data->next_data_header);
}

int rmff_dump_header(struct rmff_header_t *h,uint8_t *buffer)
{
    int written=0;
    struct rmff_mdpr_t **stream=h->streams;

    rmff_dump_fileheader(h->fileheader, &buffer[written]);
    written+=h->fileheader->size;
    rmff_dump_prop(h->prop, &buffer[written]);
    written+=h->prop->size;
    rmff_dump_cont(h->cont, &buffer[written]);
    written+=h->cont->size;
    if (stream)
	{
	    while(*stream)
		{
		    rmff_dump_mdpr(*stream, &buffer[written]);
		    written+=(*stream)->size;
		    stream++;
		}
	}
  
    rmff_dump_dataheader(h->data, &buffer[written]);
    written+=18;

    return written;
}


/*
 * format ph to buffer to valid data structure for file
 */
void rmff_dump_pheader(struct rmff_pheader_t *ph,uint8_t *data)
{
    data[0] = (ph->object_version>>8) & 0xff;
    data[1] = (ph->object_version)    & 0xff;
    data[2] = (ph->length >> 8)       & 0xff;
    data[3] = (ph->length)            & 0xff;
    data[4] = (ph->stream_number>>8)  & 0xff;
    data[5] = (ph->stream_number)     & 0xff;
    data[6] = (ph->timestamp>>24)     & 0xff;
    data[7] = (ph->timestamp>>16)     & 0xff;
    data[8] = (ph->timestamp>>8)      & 0xff;
    data[9] = (ph->timestamp)         & 0xff;
    data[10] = ph->reserved;
    data[11] = ph->flags;
}


int rmff_read_pheader(uint8_t *data,struct rmff_pheader_t *ph)
{
    ph->object_version = get16_be(data);
    ph->length         = get16_be(data + 2);
    ph->stream_number  = get16_be(data + 4);
    ph->timestamp      = get32_be(data + 6);
    ph->reserved       = get8(data + 10);
    ph->flags          = get8(data + 11);
    
    return ph->length;
}





struct rmff_fileheader_t *new_rmff_fileheader(uint32_t num_headers)
{

    struct rmff_fileheader_t *fileheader = (rmff_fileheader_t *)xmalloc(sizeof(struct rmff_fileheader_t));

    fileheader->object_id=RMF_TAG;
    fileheader->size=18;
    fileheader->object_version=0;
    fileheader->file_version=0;
    fileheader->num_headers=num_headers;

    return fileheader;
}

struct rmff_prop_t *new_rmff_prop (uint32_t max_bit_rate,
				   uint32_t avg_bit_rate,
				   uint32_t max_packet_size,
				   uint32_t avg_packet_size,
				   uint32_t num_packets,
				   uint32_t duration,
				   uint32_t preroll,
				   uint32_t index_offset,
				   uint32_t data_offset,
				   uint16_t num_streams,
				   uint16_t flags )
{

    struct rmff_prop_t *prop = (rmff_prop_t *)xmalloc(sizeof(struct rmff_prop_t));

    prop->object_id=PROP_TAG;
    prop->size=50;
    prop->object_version=0;

    prop->max_bit_rate=max_bit_rate;
    prop->avg_bit_rate=avg_bit_rate;
    prop->max_packet_size=max_packet_size;
    prop->avg_packet_size=avg_packet_size;
    prop->num_packets=num_packets;
    prop->duration=duration;
    prop->preroll=preroll;
    prop->index_offset=index_offset;
    prop->data_offset=data_offset;
    prop->num_streams=num_streams;
    prop->flags=flags;
   
    return prop;
}

struct rmff_mdpr_t *new_rmff_mdpr(uint16_t   stream_number,
				  uint32_t   max_bit_rate,
				  uint32_t   avg_bit_rate,
				  uint32_t   max_packet_size,
				  uint32_t   avg_packet_size,
				  uint32_t   start_time,
				  uint32_t   preroll,
				  uint32_t   duration,
				  const char *stream_name,
				  const char *mime_type,
				  uint32_t   type_specific_len,
				  const uint8_t *type_specific_data )
{
  
    struct rmff_mdpr_t *mdpr = (rmff_mdpr_t *)xmalloc(sizeof(struct rmff_mdpr_t));
  
    mdpr->object_id=MDPR_TAG;
    mdpr->object_version=0;

    mdpr->stream_number=stream_number;
    mdpr->max_bit_rate=max_bit_rate;
    mdpr->avg_bit_rate=avg_bit_rate;
    mdpr->max_packet_size=max_packet_size;
    mdpr->avg_packet_size=avg_packet_size;
    mdpr->start_time=start_time;
    mdpr->preroll=preroll;
    mdpr->duration=duration;
    mdpr->stream_name_size=0;
    if (stream_name) {
	mdpr->stream_name=strdup(stream_name);
	mdpr->stream_name_size=strlen(stream_name);
    }
    mdpr->mime_type_size=0;
    if (mime_type) {
	mdpr->mime_type=strdup(mime_type);
	mdpr->mime_type_size=strlen(mime_type);
    }
    mdpr->type_specific_len=type_specific_len;
    mdpr->type_specific_data = (char *)xmalloc(sizeof(char)*type_specific_len);
    memcpy(mdpr->type_specific_data,type_specific_data,type_specific_len);
    mdpr->mlti_data=NULL;
  
    mdpr->size=mdpr->stream_name_size+mdpr->mime_type_size+mdpr->type_specific_len+46;

    return mdpr;
}

struct rmff_cont_t *new_rmff_cont(const char *title, const char *author, const char *copyright, const char *comment)
{

    struct rmff_cont_t *cont = (rmff_cont_t *)xmalloc(sizeof(struct rmff_cont_t));

    cont->object_id=CONT_TAG;
    cont->object_version=0;

    cont->title=NULL;
    cont->author=NULL;
    cont->copyright=NULL;
    cont->comment=NULL;
  
    cont->title_len=0;
    cont->author_len=0;
    cont->copyright_len=0;
    cont->comment_len=0;
  
    if (title) {
	cont->title_len=strlen(title);
	cont->title=strdup(title);
    }
    if (author) {
	cont->author_len=strlen(author);
	cont->author=strdup(author);
    }
    if (copyright) {
	cont->copyright_len=strlen(copyright);
	cont->copyright=strdup(copyright);
    }
    if (comment) {
	cont->comment_len=strlen(comment);
	cont->comment=strdup(comment);
    }
    cont->size=cont->title_len+cont->author_len+cont->copyright_len+cont->comment_len+18;

    return cont;
}

struct rmff_data_t *new_rmff_dataheader(uint32_t num_packets,
					uint32_t next_data_header)
{
  
    struct rmff_data_t *data = (rmff_data_t *)xmalloc(sizeof(struct rmff_data_t));

    data->object_id=DATA_TAG;
    data->size=18;
    data->object_version=0;
    data->num_packets=num_packets;
    data->next_data_header=next_data_header;

    return data;
}
 


/*
 * totaly based on xine-lib rmff_print_header function
 * print rmff_header
 */
void rmff_print_header(struct rmff_header_t *h)
{

    struct rmff_mdpr_t *stream;

    if(!h) return;
  
    display(MSDL_DBG,"=----- RMFF header -----=\n");

    if(h->fileheader) {
	display(MSDL_DBG,
		"FILE:\n"
		"      file version      : %d\n"
		"      number of headers : %d\n",
		h->fileheader->file_version,
		h->fileheader->num_headers);
    }
  
    if(h->cont) {
	display(MSDL_DBG,
		"CONT:\n"
		"      title      : %s\n"
		"      author     : %s\n"
		"      copyright  : %s\n"
		"      comment    : %s\n",
		h->cont->title,h->cont->author,
		h->cont->copyright,h->cont->comment);
    }

    if(h->prop) {
	char flags[100]; /* this is enough */
	snprintf(flags,100,"%s %s %s\n",
		 (h->prop->flags & PN_SAVE_ENABLED) ? "save_enabled" : "",
		 (h->prop->flags & PN_PERFECT_PLAY_ENABLED) ? "perfect_play_enabled" : "",
		 (h->prop->flags & PN_LIVE_BROADCAST) ? "live_broadcast" : "");
    
    
	display(MSDL_DBG,
		"PROP:\n"
		"      bitrate (max/avg)     : %i/%i\n"
		"      packet size(max/avg)  : %i/%i\n"
		"      packets        : %i\n"
		"      duration       : %i\n"
		"      pre-buffer     : %i\n"
		"      index_offset   : %i (%x)\n"
		"      data offset    : %i (%x)\n"
		"      media streams  : %i\n"
		"      flags          : %s\n",
		h->prop->max_bit_rate,h->prop->avg_bit_rate,
		h->prop->max_packet_size,h->prop->avg_packet_size,
		h->prop->num_packets,
		h->prop->duration,
		h->prop->preroll,
		h->prop->index_offset,h->prop->index_offset,
		h->prop->data_offset,h->prop->data_offset,
		h->prop->num_streams,
		flags);
    }
  
  
    if(h->streams) {
	int i;
	for(i = 0 ; (stream = h->streams[i]) ; i++) {
	    display(MSDL_DBG,
		    "STREAM %i:\n"
		    "      stream name [mime-type]  : %s [%s]\n"
		    "      bitrate (max/avg)        : %i/%i\n"
		    "      packet size (max/avg)    : %i/%i\n"
		    "      start time   : %i\n"
		    "      pre-buffer   : %i ms\n"
		    "      duration     : %i ms\n"
		    "      type specific data : %d bytes\n",
		    stream->stream_number,
		    stream->stream_name,stream->mime_type,
		    stream->max_bit_rate,stream->avg_bit_rate,
		    stream->max_packet_size,stream->avg_packet_size,
		    stream->start_time,
		    stream->preroll,
		    stream->duration,
		    stream->type_specific_len);
      
	    dbgdump(stream->type_specific_data,stream->type_specific_len);
	    display(MSDL_DBG,"\n");
	}
    }
  
    if(h->data) {
	display(MSDL_DBG,
		"DATA:\n"
		"      size      : %i\n"
		"      packets   : %i\n"
		"      next DATA : 0x%08x\n",
		h->data->size,
		h->data->num_packets,
		h->data->next_data_header);
    }
  
}



/*
 * totaly based on xine-lib rmff_fix_header function
 * fix rmff header to write at the beginning of file
 */
void rmff_fix_header(struct rmff_header_t *h)
{

    unsigned int num_headers=0;
    unsigned int header_size=0;
    struct rmff_mdpr_t **streams;
    int num_streams=0;

    if (!h) {
	display(MSDL_ERR,"rmff_fix_header: fatal: no header given.\n");
	return;
    }

    if (!h->streams) {
	display(MSDL_DBG,"rmff_fix_header: warning: no MDPR chunks\n");
    }
    else {
	streams=h->streams;
	while (*streams) {
	    num_streams++;
	    num_headers++;
	    header_size+=(*streams)->size;
	    streams++;
	}
    }
  
    if (h->prop) {
	if (h->prop->size != 50) {
	    display(MSDL_DBG,"rmff_fix_header: correcting prop.size from %i to %i\n",
		    h->prop->size, 50);
	    h->prop->size=50;
	}
	if (h->prop->num_streams != num_streams) {
	    display(MSDL_DBG,"rmff_fix_header: correcting prop.num_streams from %i to %i\n",
		    h->prop->num_streams, num_streams);
	    h->prop->num_streams=num_streams;
	}
	num_headers++;
	header_size+=50;
    } 
    else
	display(MSDL_ERR,"rmff_fix_header: warning: no PROP chunk.\n");
  
    if (h->cont) {
	num_headers++;
	header_size+=h->cont->size;
    }
    else
	display(MSDL_DBG,"rmff_fix_header: warning: no CONT chunk.\n");

    if (!h->data) {
	display(MSDL_DBG,"rmff_fix_header: no DATA chunk, creating one\n");
    
	h->data = (rmff_data_t *)xmalloc(sizeof(struct rmff_data_t));
	h->data->object_id=DATA_TAG;
	h->data->object_version=0;
	h->data->size=34;
	h->data->num_packets=0;
	h->data->next_data_header=0;
    }
    num_headers++;

  
    if (!h->fileheader) {
	display(MSDL_DBG,"rmff_fix_header: no fileheader, creating one");

	h->fileheader = (rmff_fileheader_t *)xmalloc(sizeof(struct rmff_fileheader_t));
	h->fileheader->object_id=RMF_TAG;
	h->fileheader->size=34;
	h->fileheader->object_version=0;
	h->fileheader->file_version=0;
	h->fileheader->num_headers=num_headers+1;
    }
    header_size+=h->fileheader->size;
    num_headers++;

    if(h->fileheader->num_headers != num_headers) {
	display(MSDL_DBG,"rmff_fix_header: setting num_headers from %i to %i\n",
		h->fileheader->num_headers, num_headers); 

	h->fileheader->num_headers=num_headers;
    }

    if(h->prop) {
	if (h->prop->data_offset != header_size) {
	    display(MSDL_DBG,"rmff_fix_header: setting prop.data_offset from %i to %i\n",
		    h->prop->data_offset, header_size); 
      
	    h->prop->data_offset=header_size;
	}
	if (h->prop->num_packets == 0) {
	    int p=(int)(h->prop->avg_bit_rate/8.0*(h->prop->duration/1000.0)/h->prop->avg_packet_size);

	    display(MSDL_DBG,"rmff_fix_header: assuming prop.num_packets=%i\n", p); 

	    h->prop->num_packets=p;
	}
	if (h->data->num_packets == 0) {
	    display(MSDL_DBG,"rmff_fix_header: assuming data.num_packets=%i\n",
		    h->prop->num_packets); 

	    h->data->num_packets=h->prop->num_packets;
	}
    
	display(MSDL_DBG,"rmff_fix_header: assuming data.size=%i\n",
		h->prop->num_packets*h->prop->avg_packet_size); 
    
	h->data->size=h->prop->num_packets*h->prop->avg_packet_size;
    }
}



int rmff_get_header_size(struct rmff_header_t *h)
{

    if (!h) return 0;
    if (!h->prop) return -1;

    return h->prop->data_offset+18;
  
}

void free_rmff_header_t(struct rmff_header_t *h)
{

    if (!h) return;

    if (h->fileheader) free(h->fileheader);
    if (h->prop) free(h->prop);
    if (h->data) free(h->data);
    if (h->cont) {
	free(h->cont->title);
	free(h->cont->author);
	free(h->cont->copyright);
	free(h->cont->comment);
	free(h->cont);
    }
    if (h->streams) {
	struct rmff_mdpr_t **s=h->streams;

	while(*s) {
	    free((*s)->stream_name);
	    free((*s)->mime_type);
	    free((*s)->type_specific_data);
	    free(*s);
	    s++;
	}
	free(h->streams);
    }
    free(h);
}
