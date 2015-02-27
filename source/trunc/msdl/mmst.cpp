/***********************************************************************
 *    mmst.c:  downloading via mmst (Microsoft Media Service over TCP)
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file is based on mms implementation of mplayer,
 * and Windows Media Player transaction I saw through
 * packet monitoring program, wireshark (http://www.wireshark.org/)
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
 * (from MPlayer-1.0rc2/stream/asf_mmst_streaming.c)
 */

/*
 * MMST implementation taken from the xine-mms plugin made by
 * Major MMS (http://geocities.com/majormms/).
 * Ported to MPlayer by Abhijeet Phatak <abhijeetphatak@yahoo.com>.
 *
 * Information about the MMS protocol can be found at http://get.to/sdp
 *
 * copyright (C) 2002 Abhijeet Phatak <abhijeetphatak@yahoo.com>
 * copyright (C) 2002 the xine project
 * copyright (C) 2000-2001 major mms
 *
 * This file is part of MPlayer.
 *
 * MPlayer is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * MPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 */


#include "stdafx.h"

#include "msdl.h"
#include "msdllib.h"
#include "network.h"
#include "asf.h"
#include "mmst.h"
#include "snprintf.h"


static struct mmst_ctrl_t *new_mmst_ctrl_t(void);
static void free_mmst_ctrl_t(struct mmst_ctrl_t *mctrl);
static int mmst_get_command_packet(struct stream_t *stream);


static struct mmst_ctrl_t *new_mmst_ctrl_t(void)
{
    struct mmst_ctrl_t *mctrl = (mmst_ctrl_t *)xmalloc(sizeof(struct mmst_ctrl_t));
    mctrl->seq_num = 0;
    mctrl->num_stream_ids = 0;
    mctrl->hinfo = new_asf_headerinfo_t();

    return mctrl;
}

static void free_mmst_ctrl_t(struct mmst_ctrl_t *mctrl)
{
    if(mctrl->hinfo) free_asf_headerinfo_t(mctrl->hinfo);
    if(mctrl) free(mctrl);
}


/*
 * send command
 */
static void send_command(struct stream_t *stream,int command,
			 uint32_t f1,uint32_t f2,
			 int length,uint8_t *data)
{
    int len8 = (length+7) / 8;
    uint8_t *cmd = (uint8_t *)xmalloc(len8 * 8 + 0x30); // 0x30 for header.
  
    /* put data in little endian */
    put32_le(cmd + 0x00,0x00000001);   /* rep | version | versionMinor | padding */
    put32_le(cmd + 0x04,0xB00BFACE);   /* sessionId                              */
    put32_le(cmd + 0x08,len8*8 + 32);  /* messageLength                          */
    put32_le(cmd + 0x0C,0x20534d4d);   /* "MMS "                                 */
    put32_le(cmd + 0x10,len8 + 4);     /* chunkCount                             */
    put32_le(cmd + 0x14,stream->stream_ctrl->mmst_ctrl->seq_num); /*  seq | MBZ  */
    stream->stream_ctrl->mmst_ctrl->seq_num++;
    put32_le(cmd + 0x18,0x00);         /* timeSent */
    put32_le(cmd + 0x1C,0x00);         /* timeSent */
    
    
    put32_le(cmd + 0x20,len8+2);       /* chunkLen */
    put32_le(cmd + 0x24,0x00030000 | command); /* dir | command */
    put32_le(cmd + 0x28,f1);
    put32_le(cmd + 0x2C,f2);
  
    memcpy(cmd + 0x30, data, length);
    if(length & 0x07) { /* do padding */
	memset(cmd + 0x30 + length, 0, 8 - (length & 0x07));
    }
  
  
    display(MSDL_DBG,"=-send-------------------------------------------=\n");
    dbgdump(cmd,len8 * 8 + 0x30);
    display(MSDL_DBG,"\n=------------------------------------------------=\n");
  
  
    if(xsend(stream->netsock->sock,cmd,len8*8+0x30) != (len8*8+0x30)){
	perror("send() failed");
    }
  
    free(cmd);
}



/*
 * convert string to UTF16, so that mms server can understand.
 */
static void string_utf16(char *dst,char *src,int len)
{
    int i;

    if(len > 499) len = 499;
    for(i = 0; i < len; i ++) {
	dst[i * 2] = src[i];
	dst[i * 2 + 1] = 0;
    }
    dst[i * 2] = 0;
    dst[i * 2 + 1] = 0;
}



/*
 * get Micro$oft ASF header.
 * return value:      asf header length : success
 *                             negative : failure
 */
static int mmst_get_asf_header(struct stream_t *stream, uint8_t *header)
{
    int header_len = 0;       /* total header length. */
    uint32_t packet_len = 0;  /* length of this packet. */
    int command;
    uint8_t pre_header[8];    /* pre_header, before header. */
  
  
    while(1) { /* we have to collect all header packet together. */
    
	/* first, for each packet,get pre_header and know packet length etc... */
	if(read_data(stream,pre_header,8) <= 0) { /* read_data() failed. */
	    goto failed;
	}
	if(pre_header[4] == 0x02) { /*   header packet   */

	    packet_len = get16_le(((uint8_t *)&pre_header) + 6) - 8;
      
	    if(packet_len < 0 || HDR_BUF_SIZE - header_len < packet_len) {
		display(MSDL_ERR,"invalid header size\n");
		goto failed;
	    }
      
	    if(read_data(stream,header + header_len, packet_len) <= 0) {
		/* read_data failed */
		goto failed;
	    }
      
	    header_len += packet_len; /* accumulate */
      
	    /* end of header. */
	    if(header[header_len - 1] == 1 && header[header_len - 2] == 1) {
		/* success, got M$ ASF header, in header packet */
		return header_len;
	    }
	}
	else { /* command packet received. */
	    uint8_t *combuf;
      
	    if(read_data(stream,&packet_len,4) <= 0) {
		display(MSDL_ERR,"read_data for packet_len failed\n");
		goto failed;
	    }
      
	    packet_len = get32_le(&packet_len) + 4;

	    if(packet_len < 0 || BUF_SIZE < packet_len) {
		display(MSDL_ERR,"%x: invalid packet size\n",packet_len,BUF_SIZE);
		goto failed;
	    }

	    combuf = (uint8_t *)xmalloc(packet_len);
      
	    if(read_data(stream,combuf,packet_len) <= 0) {
		/* error */
		free(combuf);
		goto failed;
	    }
      
	    command = get32_le(combuf + 24) & 0xFFFF;
	    if(command == 0x1b) {
		send_command(stream,0x1b,
			     0,
			     0,
			     0,
			     combuf);
	    }
	    free(combuf);
	}
    }

  failed:
    return -1;
}



/*
 * start mmst streaming.
 * 
 *    return value :   negative or 0  ... error
 *                                 1  ... success
 */
int mmst_streaming_start(struct stream_t *stream)
{
    struct url_t *url = stream->url;
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    struct mmst_ctrl_t *mmst_ctrl = stream_ctrl->mmst_ctrl;
    
    uint8_t *buffer = NULL;
    uint8_t *buffer2 = NULL;
    uint8_t *asf_header = NULL;
    int ret = 0;
    int asf_header_len = 0;
    char *path = NULL, *escaped_path = NULL;
    int sock = 0; /* socket to use */
    int pos = 0;
    int i = 0;
  
    stream->stream_ctrl->status = STREAMING_HANDSHAKING;
  
    buffer = (uint8_t *)xmalloc(BUFSIZE_1K);  /* send buffer. used for data to send */
    buffer2 = (uint8_t *)xmalloc(BUFSIZE_1K); /* working buffer                     */
    
    
    escaped_path = strchr(url->file,'/') + 1;
    path = (char *)xmalloc(strlen(escaped_path) + 1);
    
  
    /* remove something like '%41' in url. */
    url_unescape_string(path,escaped_path);
    
    if(stream->dlopts->bandwidth) {
	stream_ctrl->bandwidth = stream->dlopts->bandwidth;
    }
    else {
	stream_ctrl->bandwidth = INT_MAX_BANDWIDTH;
    }
    
    set_serverinfo(stream->serverinfo,url->hostname,url->port,NULL,0,MMS_PORT);
    sock = server_connect(stream->serverinfo->connect_host,stream->serverinfo->connect_port);
    if(sock < 0) { /* couldn't connect for some reason. */
	free(path);

	/* if mms failed, mmsh will be tried */
	display(MSDL_ERR,"mmst connection not established\n");
	display(MSDL_ERR,
		"server probably does not accept mmst\n"
		"retry using mmsh protocol\n");
	stream->stream_ctrl->status = STREAMING_OTHER_PROTOCOL;
	stream->stream_ctrl->retry_protocol = MMSH;
	
	goto failed;
    }
  
    stream->netsock->sock = sock;
    mmst_ctrl->seq_num = 0;
  
    /*
     * first thing to do: 0x01 command, do the protocol initiation.
     */
    snprintf((char *)buffer2,BUFSIZE_1K - 1,
	     "\034\003NSPlayer/7.0.0.1956; {33715801-BAB3-9D85-24E9-03B90328270A}; Host: %s",
	     stream->serverinfo->host);
  
    string_utf16((char *)buffer,(char *)buffer2,
		 strlen((char *)buffer2));
  
    /*  send !! */
    send_command(stream,1,
		 0,
		 0x0004000b,
		 strlen((char *)buffer2)*2+2,
		 buffer);
    
    /* 1st reply */
    if(mmst_get_command_packet(stream) < 0) {
	free(path);
	display(MSDL_ERR,"mmst message could not received\n");
	display(MSDL_ERR,
		"server probably does not accept mmst\n"
		"retry using mmsh protocol\n");
	stream->stream_ctrl->status = STREAMING_OTHER_PROTOCOL;
	stream->stream_ctrl->retry_protocol = MMSH;
	
	goto failed;
    }
  
    /*
     * 0x02 command. send details of the local IP addr
     */
    string_utf16((char *)buffer + 8,
		 "\002\000\\\\192.168.0.1\\TCP\\1037", 24);
    memset(buffer,0,8);
    send_command(stream,2,
		 0,
		 0,
		 24*2+10,
		 buffer);
  
    /* 2nd reply */
    mmst_get_command_packet(stream);
  
    /*
     * 0x05 command, send request file path.
     */
    string_utf16((char *)buffer + 8,path,strlen(path));
    memset(buffer,0,8);
    send_command(stream,5,
		 0,
		 0,
		 strlen(path) * 2 + 10,
		 buffer);
  
    free(path);
  
    mmst_get_command_packet(stream);
  
  
    /*
     * 0x15 cmmand  The ASF header chunk request, include ?session variable
     * for pre header.
     * After this command sent server should reply with 0x11 command and then
     * header chunk with header comes.
     */
    memset(buffer,0,40);
    buffer[0x20] = 2;
    send_command(stream,0x15,
		 1,
		 0,
		 40,
		 buffer);
  
    /*
     * header goes to asf_header, which is actually stream_ctrl->write_buffer.
     *    ( write_buffer because this header is directly written to file)
     */
    asf_header_len = mmst_get_asf_header(stream,stream_ctrl->write_buffer);
    if(asf_header_len <= 0) { /* failed */
	display(MSDL_ERR,"cannot receive M$ asf header\n");
	goto failed;
    }
    asf_header = stream_ctrl->write_buffer;
    stream_ctrl->write_pos = 0;
  
  
    /* asf header starting from stream_ctrl->write_buffer + 0. */
    stream_ctrl->write_data_len = asf_header_len;
  
    mmst_ctrl->hinfo->asf_header = (uint8_t *)xmalloc(asf_header_len);
    memcpy(mmst_ctrl->hinfo->asf_header,asf_header,asf_header_len);
  
    ret = asf_interpret_header(mmst_ctrl->hinfo,stream_ctrl->bandwidth,
			       asf_header,asf_header_len);

    {
	display(MSDL_DBG,"ASF_HEADER---------------------\n");
	dbgdump(asf_header,asf_header_len);
	display(MSDL_DBG,"\n-------------------------------\n");
    }

    if(ret < 0) {
	display(MSDL_ERR,"cannot receive packet length\n");
	goto failed;
    }

    /* set file size to download */
    stream_ctrl->file_size = mmst_ctrl->hinfo->fileh->file_size;
  
    display(MSDL_VER,
	    "ASF header length: %d bytes\n"
	    "packet length    : %d bytes\n",
	    asf_header_len,mmst_ctrl->hinfo->fileh->max_packet_size);
  
    stream_ctrl->packet_length = mmst_ctrl->hinfo->fileh->max_packet_size;
    mmst_ctrl->num_stream_ids = 
	mmst_ctrl->hinfo->streams->n_audio + mmst_ctrl->hinfo->streams->n_video;
  
    /*
     * 0x33 command, not understood very well
     */
    memset(buffer,0,mmst_ctrl->num_stream_ids * 6 + 2);
    pos = 0;
    display(MSDL_VER,"number of audio stream : %d, video stream = %d\n"
	    "best audio stream : %d, video stream : %d\n",
	    mmst_ctrl->hinfo->streams->n_audio,
	    mmst_ctrl->hinfo->streams->n_video,
	    mmst_ctrl->hinfo->streams->audio_id,
	    mmst_ctrl->hinfo->streams->video_id);
    
    /*
     * chunkLen : 4bytes
     * MID      : 4bytes
     * cStreamEntries : 4bytes  (num of entries)
     * cStreamEntries : (variable, each 6 bytes)
     *
     * typedef struct {
     *     WORD wSrcStreamNumber;
     *     WORD wDstStreamNumber;
     *     WORD wThinningLevel;
     * } STREAM_SWITCH_ENTRY;
     *
     */
    
    pos = 0;
    for(i = 0 ; i < mmst_ctrl->hinfo->streams->n_audio; i++) {
	buffer[pos + 0] = 0xFF;
	buffer[pos + 1] = 0xFF;
	buffer[pos + 2] = mmst_ctrl->hinfo->streams->audio_streams[i];
	buffer[pos + 3] = mmst_ctrl->hinfo->streams->audio_streams[i] >> 8;

	if(mmst_ctrl->hinfo->streams->audio_streams[i] == 
 	   mmst_ctrl->hinfo->streams->audio_id) {
	    display(MSDL_DBG,"enable audio stream[%d]\n",mmst_ctrl->hinfo->streams->audio_id);
	    buffer[pos + 4] = 0x00;
	    buffer[pos + 5] = 0x00; 
	}
	else {
	    display(MSDL_DBG,"disable audio stream[%d]\n",mmst_ctrl->hinfo->streams->audio_id);
	    buffer[pos + 4] = 0x02;
	    buffer[pos + 5] = 0x00; 
	}
	pos += 6;
    }
    for(i = 0 ; i < mmst_ctrl->hinfo->streams->n_video; i++) {
	buffer[pos + 0] = 0xFF;
	buffer[pos + 1] = 0xFF;
	buffer[pos + 2] = mmst_ctrl->hinfo->streams->video_streams[i];
	buffer[pos + 3] = mmst_ctrl->hinfo->streams->video_streams[i] >> 8;

	if(mmst_ctrl->hinfo->streams->video_streams[i] == 
 	   mmst_ctrl->hinfo->streams->video_id) {
	    display(MSDL_DBG,"enable video stream[%d]\n",mmst_ctrl->hinfo->streams->audio_id);
	    buffer[pos + 4] = 0x00;
	    buffer[pos + 5] = 0x00; 
	}
	else {
	    display(MSDL_DBG,"disable video stream[%d]\n",mmst_ctrl->hinfo->streams->audio_id);
	    buffer[pos + 4] = 0x02;
	    buffer[pos + 5] = 0x00; 
	}
	pos += 6;
    }    
    
    send_command(stream,0x33,
		 mmst_ctrl->num_stream_ids,                                          /* cStreamEntries */
		 buffer[0] | (buffer[1] << 8) | (buffer[2] <<16) | (buffer[3] <<24), /* dirty shift */
		 pos - 4,
		 buffer + 4);
    mmst_get_command_packet(stream);
    
    /*
     * 0x07 command. includes ?session value and maximum media stream time
     */
    memset(buffer,0,40);
    for(i = 8 ; i < 16 ; i++) {
	buffer[i] = 0xFF;
    }
    buffer[20] = 0x04;
    send_command(stream,0x07,
		 1,
		 0,
		 24,
		 buffer);
  
    /**   now everything is done, wait for media packets !!!   **/
  
    free(buffer);
    free(buffer2);

    /* set status */
    stream_ctrl->status = STREAMING_DOWNLOADING;
    stream_ctrl->protocol = MMST;

    return 1; /* success */

  failed:
    free(buffer);
    free(buffer2);
    return 0;
}



/*
 * get COMMAND PACKET ONLY , ignore data in commands.
 * data (media) packets are all ignored, as they are not expected.
 * should be used only in mmst_streaming_start
 */
static int mmst_get_command_packet(struct stream_t *stream)
{
    uint8_t *pre_header[8];
    uint32_t packet_len;
    uint32_t command;
    uint8_t *combuf;

    while(1) {
	combuf = NULL;

	if(read_data(stream,pre_header,8) <= 0) { /* read_data() failed. */
	    goto failed;
	}
    
	if(read_data(stream,&packet_len,4) <= 0) {
	    display(MSDL_ERR,"read_data for packet_len failed\n");
	    goto failed;
	}
    
	packet_len = get32_le(&packet_len) + 4;
    
	if(packet_len < 0 || BUF_SIZE < packet_len) {
	    display(MSDL_ERR,"%x: invalid packet size\n",packet_len,BUF_SIZE);
	    goto failed;
	}
      
	combuf = (uint8_t *)xmalloc(packet_len);
      
	if(read_data(stream,combuf,packet_len) <= 0) {
	    /* error */
	    free(combuf);
	    goto failed;
	}
	
	display(MSDL_DBG,"=-recv (command)-----------------------------------=\n");
	dbgdump(combuf,packet_len);
	display(MSDL_DBG,"\n=--------------------------------------------------=\n");

	command = get32_le(combuf + 24) & 0xFFFF;
	if(command == 0x1b) {
	    send_command(stream,0x1b,
			 0,
			 0,
			 0,
			 combuf);
	    free(combuf);
	}
	else {
	    free(combuf);
	    break;
	}
    }
  
    return 0;

  failed:
    if(combuf) free(combuf);
    return -1;
}




/*
 * get each media packet.
 *
 * when media packet: get 'packet_len' bytes of data from sock, and store them to buffer.
 *                    if max_size was smaller(buffer was too small), the rest goes to
 *                    netsock->buffer.
 *
 *    command packet: don't do anything to buffer.
 *
 *   return value   :  positive value ... bytes written to 'buffer'.
 *                     0 ... END OF FILE
 *                    -1 ... Error.
 */
static int mmst_get_media_packet(struct stream_t *stream, uint8_t *buffer, size_t max_size)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    uint8_t pre_header[8];
    uint32_t packet_len;
    uint32_t command;
    int ret;
  

    while (1) {
    
	stream_ctrl->write_data_len = 0;
    
	if(read_data(stream,pre_header,8) <= 0) {
	    display(MSDL_ERR,"could not receive packet pre header\n");
	    goto failed;
	}
  
	if(pre_header[4] == 0x04) { /*   media packet   */

	    packet_len = get16_le(((uint8_t *)&pre_header) + 6) - 8;
      
	    stream_ctrl->packet_count++; /* increment packet count */
      
	    if(packet_len < 0) {
		display(MSDL_ERR,"%d: invalid packet size\n",packet_len);
		goto failed;
	    }
      
	    if(stream_ctrl->packet_length <= max_size) {
		/* buffer is bigger than incoming packet (and padding) */
		ret = read_data(stream, buffer, packet_len);
		if(ret < 0) {
		    display(MSDL_ERR,"couldn't read from netwrok failed\n");
		    goto failed;
		}
		memset(buffer + ret, 0, stream_ctrl->packet_length - ret); /* padding */
		ret = stream_ctrl->packet_length;
	    }
	    else { /* buffer is NOT big enough for incoming packet.. (and padding) */
		ret = read_data(stream, stream_ctrl->write_buffer, packet_len);
		if(ret < 0) {
		    display(MSDL_ERR,"couldn't read from netwrok failed\n");
		    goto failed;
		}
		/* this is OK because stream_ctrl->write_buffer is empty */
		memset(stream_ctrl->write_buffer + packet_len, 0, /* padding */
		       stream_ctrl->packet_length - packet_len);
		memcpy(buffer,stream_ctrl->write_buffer, max_size);
		ret = stream_ctrl->write_pos = max_size;
		stream_ctrl->write_data_len = stream_ctrl->packet_length - max_size;
	    }
      
	    return ret;
	}
    
	else { /*   command packet    */
	    uint8_t *combuf;
      
	    /* check command packet signiture */
	    if(get32_le(((uint8_t *)&pre_header) + 4) != 0xB00BFACE) {
		display(MSDL_ERR,"missing command signiture!\n");
		goto failed;
	    }
      
	    if(read_data(stream, &packet_len,4) <= 0) {
		display(MSDL_ERR,"command packet length read failed\n");
		goto failed;
	    }
    
	    packet_len = get32_le(&packet_len) + 4;

	    if(packet_len < 0 || packet_len > BUF_SIZE) {
		display(MSDL_ERR,"%d: invalid packet size\n",packet_len);
		goto failed;
	    }

	    combuf = (uint8_t *)xmalloc(packet_len);
      
	    /* get command packet */
	    if(read_data(stream, combuf, packet_len) <= 0) {
		display(MSDL_ERR,"command data read failed\n");
		free(combuf);
		goto failed;
	    }

	    command = get32_le(combuf + 24) & 0xFFFF;
      
	    if(command == 0x1B) {
		send_command(stream,0x1B,
			     0,
			     0,
			     0,
			     combuf);
	    }
	    else if(command == 0x1E) { /* End Of Stream (EOS) */
		stream_ctrl->status = STREAMING_FINISHED;
		free(combuf);
		return 0; /* End Of Stream!! */
	    }
	    else if(command == 0x05) {
		; /* wired packet, ignore this (not UNKNOWN) */
	    }	
	    else if(command == 0x21) {
		; /* wired packet, ignroe this (not UNKNOWN) */
	    }
	    else {
		display(MSDL_DBG,"unknown command %x (ignore this)\n",command);
	    }

	    free(combuf);
	} /* command packet */
    } /* while(1) */
  
    return 0;
  
  failed:
    return -1;
}



/*
 * read mms over http stream. filles buffer, and buffer size is 'size' 
 *
 *        read cached data from stream->stream_ctrl->write_buffer
 *        check for to see if network access is necessary
 *        get chunk(media packet) from network.
 *
 *  return value: bytes written to buffer.
 */
int mmst_streaming_read(struct stream_t *stream, uint8_t *buffer,
			size_t buffer_size)
{
    struct stream_ctrl_t *stream_ctrl = stream->stream_ctrl;
    size_t pos = 0; /* how many bytes written to buffer. */
    int ret = 0;

    if(stream_ctrl->write_data_len) {
	/* there are some data to copy in stream_ctrl->write_buffer */
	if(buffer_size <= stream_ctrl->write_data_len) {
	    /* 
	       buffer_size < stream_ctrl->write_data_len...
	       fill buffer, and return.
	    */
	    memcpy(buffer,stream_ctrl->write_buffer + stream_ctrl->write_pos,
		   buffer_size);
      
	    stream_ctrl->write_data_len -= buffer_size;
	    stream_ctrl->write_pos += buffer_size;
	    return buffer_size;
	}
	else {
	    /* 
	       stream_ctrl->write_data_len < buffer_size, 
	       have to read from network.
	    */
	    memcpy(buffer,stream_ctrl->write_buffer + stream_ctrl->write_pos,
		   stream_ctrl->write_data_len);
	    pos = stream_ctrl->write_data_len;
	    /* and stream_ctrl->write_buffer is empty. */
	    stream_ctrl->write_data_len = 0;
	    stream_ctrl->write_pos = 0;
	}
    }

    stream_ctrl->write_data_len = 0;
    stream_ctrl->write_pos = 0;
    
    if(stream_ctrl->status != STREAMING_FINISHED) {
	/*
	  still have to get data from network.
	  there are buffer_size - pos bytes to be filled (max)
	*/
	ret = mmst_get_media_packet(stream, buffer + pos, buffer_size - pos);
    }
  
    if(ret >= 0) {
	return ret + pos;
    }
    else {
        return -1;
    }
}





struct stream_t *mmst_streaming_init()
{
    struct stream_t *stream = streaming_init_common();
    stream->stream_ctrl->mmst_ctrl = new_mmst_ctrl_t();
    
    stream->start = mmst_streaming_start;
    stream->read  = mmst_streaming_read;
    stream->close = mmst_streaming_close;
  
    return stream;
}



void mmst_streaming_close(struct stream_t *stream)
{
    if(stream->netsock->sock > 0) { /* valid socket */
	closesocket(stream->netsock->sock);
    }

    free_mmst_ctrl_t(stream->stream_ctrl->mmst_ctrl);
    streaming_close_common(stream);
}

