/***********************************************************************
 *    asf.h:  for undersanding ASF(Advanced Systems Format) format
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


#ifndef __ASF_H__
#define __ASF_H__


enum {
    ASF_GUID_LENGTH = 16,
    ASF_HEADER_READ_AT_ONCE = 10000,
};


enum {
    ASF_AUDIO_STREAM = 0xf8699e40,
    ASF_VIDEO_STREAM = 0xbc19efc0,
    ASF_COMMAND_MEDIA_STREAM = 0x59dacfc0,
    ASF_FILE_TRANSFER_MEDIA_STREAM = 0x91bd222c,
};




/*
 * ASF Object header
 */
struct /*__attribute__((packed))*/  asf_obj_header_t {
    uint8_t guid[ASF_GUID_LENGTH];
    uint64_t size;
}; 


/*
 * M$ ASF Header!!
 */
struct /*__attribute__((packed))*/ asf_header_t {
    struct asf_obj_header_t objh; /* object header       */
    uint32_t cno;                 /* number of subchunks */
    uint8_t v1;                   /* unknown (0x01)      */
    uint8_t v2;                   /* unknown (0x02)      */
};


/* 
 * M$ ASF file header.
 */
struct /*__attribute__((packed))*/ asf_file_header_t {
    uint8_t  stream_id[ASF_GUID_LENGTH];  /* stream GUID */
    uint64_t file_size;
    uint64_t creation_time;  /* File creation time FILETIME 8                        */
    uint64_t num_packets;    /* Number of packets UINT64 8                           */
    uint64_t play_duration;  /* Timestamp of the end position UINT64 8               */
    uint64_t send_duration;  /* Duration of the playback UINT64 8                    */
    uint64_t preroll;        /* Time to bufferize before playing UINT32 4            */
    uint32_t flags;          /* Unknown, maybe flags (usually contains 2) UINT32 4   */
    uint32_t min_packet_size;/* Min size of the packet, in bytes UINT32 4            */
    uint32_t max_packet_size;/* Max size of the packet  UINT32 4                     */
    uint32_t max_bitrate;    /* Maximum bitrate of the media (sum of all the stream) */
};

struct /*__attribute__((packed))*/ asf_stream_header_t {
    uint8_t type[ASF_GUID_LENGTH];        /* Stream type (audio/video) GUID 16    */
    uint8_t concealment[ASF_GUID_LENGTH]; /* Audio error concealment type GUID 16 */
    uint64_t unk1;        /* Unknown, maybe reserved ( usually contains 0 ) UINT64 8 */
    uint32_t type_size;   /* Total size of type-specific data UINT32 4               */
    uint32_t stream_size; /* Size of stream-specific data UINT32 4                   */
    uint16_t stream_no;   /* Stream number UINT16 2                                  */
    uint32_t unk2;        /* Unknown UINT32 4                                        */
};



struct /*__attribute__((packed))*/ asf_stream_chunk_t {
    uint16_t type;
    uint16_t size;
    uint32_t seqnum;
};



struct /*__attribute__((packed))*/ asf_stream_chunk_extra_t {
    uint16_t unknown;
    uint16_t size_confirm;
};


struct error_correction_data {
    /* error correction flags */
    int error_correction_data_length;
    int opaque_data_present;
    int error_correction_length_type;
    int error_correction_present;
};


struct payload_parsing_information {
    /*length type flags*/
    int multiple_payloads_present;
    int sequence_type;
    int padding_length_type;
    int packet_length_type;
    int error_correction_present;
    /* property flags */
    int replicated_data_length_type;
    int offset_into_media_object_length_type;
    int media_object_number_length_type;
    int stream_number_length_type;

    uint32_t packet_length;
    uint32_t sequence;
    uint32_t padding_length;
    uint32_t send_time;
    uint32_t duration;
};


struct asf_data_packet_header_t {
    struct error_correction_data ecd;
    struct payload_parsing_information ppi;
};




struct asf_streams_t {
    int audio_id,video_id; /* best stuff. (ids)   */
    int n_audio, n_video;  /* numbers of streams  */
    int *audio_streams,*video_streams; /* streams */
};



struct asf_headerinfo_t {
    uint8_t *asf_header;              /* raw header         */
    int asf_header_len;               /* its length         */
    struct asf_file_header_t *fileh;  /* basic information  */
    struct asf_streams_t *streams;    /* stream information */
};



struct asf_headerinfo_t *new_asf_headerinfo_t(void);
void free_asf_headerinfo_t(struct asf_headerinfo_t *info);

int asf_interpret_header(struct asf_headerinfo_t *hinfo,const int bw,
			 const uint8_t *buffer,const size_t asf_header_size);

int find_asf_guid(const uint8_t *buffer,int cur_pos,const uint8_t *guid,int buffer_len);

int asf_get_file_property(const uint8_t *header,int asf_header_size,
			  struct asf_file_header_t *fileh);
int asf_choose_best_streams(const uint8_t *header, int asf_header_size,
			    int bw, struct asf_streams_t *streams);

int asf_get_npt_of_last_packet(char *local_filename,uint32_t *send_time,uint64_t *seek_offset);

int asf_parse_data_packet_header(uint8_t *packet,struct asf_data_packet_header_t *adph);

int asf_data_packet_get_send_time(uint8_t *packet,uint32_t *send_time);

#endif /* __ASF_H__ */
