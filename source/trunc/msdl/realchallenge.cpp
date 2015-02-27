/***********************************************************************
 *    realchallenge.c : for downloading from real server using rtsp
 ***********************************************************************
 * Copyright (C) 2007 metro <me_t_ro@yahoo.com>
 *
 * This file is part of msdl, media stream downloader
 *
 * This file includes functions for calculating Real ClientChallenge
 * strings, and the code is based on xine-lib and mplayer.
 * Thank you so much.
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


enum {
    XOR_TABLE_LEN = 37,
};


static void hash(char *field, char *param);
static void call_hash (char *key, char *challenge, unsigned int len);
static void calc_response (char *result, char *field);



/*
 * This data is taken from xine-lib program.
 * used to calculate clientchallenge2.
 */
static const unsigned char xor_table[] = {
    0x05, 0x18, 0x74, 0xd0, 0x0d, 0x09, 0x02, 0x53,
    0xc0, 0x01, 0x05, 0x05, 0x67, 0x03, 0x19, 0x70,
    0x08, 0x27, 0x66, 0x10, 0x10, 0x72, 0x08, 0x09,
    0x63, 0x11, 0x03, 0x71, 0x08, 0x08, 0x70, 0x02,
    0x10, 0x57, 0x05, 0x18, 0x54, 0x00, 0x00, 0x00 };


/*
 * This function is taken from xine-lib program.
 * used to calculate clientchallenge2.
 */
static void hash(char *field, char *param)
{

    uint32_t a, b, c, d;
 

    /* fill variables */
    a = get32_le(field);
    b = get32_le(field+4);
    c = get32_le(field+8);
    d = get32_le(field+12);
  
  
    a = ((b & c) | (~b & d)) + get32_le((param+0x00)) + a - 0x28955B88;
    a = ((a << 0x07) | (a >> 0x19)) + b;
    d = ((a & b) | (~a & c)) + get32_le((param+0x04)) + d - 0x173848AA;
    d = ((d << 0x0c) | (d >> 0x14)) + a;
    c = ((d & a) | (~d & b)) + get32_le((param+0x08)) + c + 0x242070DB;
    c = ((c << 0x11) | (c >> 0x0f)) + d;
    b = ((c & d) | (~c & a)) + get32_le((param+0x0c)) + b - 0x3E423112;
    b = ((b << 0x16) | (b >> 0x0a)) + c;
    a = ((b & c) | (~b & d)) + get32_le((param+0x10)) + a - 0x0A83F051;
    a = ((a << 0x07) | (a >> 0x19)) + b;
    d = ((a & b) | (~a & c)) + get32_le((param+0x14)) + d + 0x4787C62A;
    d = ((d << 0x0c) | (d >> 0x14)) + a;
    c = ((d & a) | (~d & b)) + get32_le((param+0x18)) + c - 0x57CFB9ED;
    c = ((c << 0x11) | (c >> 0x0f)) + d;
    b = ((c & d) | (~c & a)) + get32_le((param+0x1c)) + b - 0x02B96AFF;
    b = ((b << 0x16) | (b >> 0x0a)) + c;
    a = ((b & c) | (~b & d)) + get32_le((param+0x20)) + a + 0x698098D8;
    a = ((a << 0x07) | (a >> 0x19)) + b;
    d = ((a & b) | (~a & c)) + get32_le((param+0x24)) + d - 0x74BB0851;
    d = ((d << 0x0c) | (d >> 0x14)) + a;
    c = ((d & a) | (~d & b)) + get32_le((param+0x28)) + c - 0x0000A44F;
    c = ((c << 0x11) | (c >> 0x0f)) + d;
    b = ((c & d) | (~c & a)) + get32_le((param+0x2C)) + b - 0x76A32842;
    b = ((b << 0x16) | (b >> 0x0a)) + c;
    a = ((b & c) | (~b & d)) + get32_le((param+0x30)) + a + 0x6B901122;
    a = ((a << 0x07) | (a >> 0x19)) + b;
    d = ((a & b) | (~a & c)) + get32_le((param+0x34)) + d - 0x02678E6D;
    d = ((d << 0x0c) | (d >> 0x14)) + a;
    c = ((d & a) | (~d & b)) + get32_le((param+0x38)) + c - 0x5986BC72;
    c = ((c << 0x11) | (c >> 0x0f)) + d;
    b = ((c & d) | (~c & a)) + get32_le((param+0x3c)) + b + 0x49B40821;
    b = ((b << 0x16) | (b >> 0x0a)) + c;
  
    a = ((b & d) | (~d & c)) + get32_le((param+0x04)) + a - 0x09E1DA9E;
    a = ((a << 0x05) | (a >> 0x1b)) + b;
    d = ((a & c) | (~c & b)) + get32_le((param+0x18)) + d - 0x3FBF4CC0;
    d = ((d << 0x09) | (d >> 0x17)) + a;
    c = ((d & b) | (~b & a)) + get32_le((param+0x2c)) + c + 0x265E5A51;
    c = ((c << 0x0e) | (c >> 0x12)) + d;
    b = ((c & a) | (~a & d)) + get32_le((param+0x00)) + b - 0x16493856;
    b = ((b << 0x14) | (b >> 0x0c)) + c;
    a = ((b & d) | (~d & c)) + get32_le((param+0x14)) + a - 0x29D0EFA3;
    a = ((a << 0x05) | (a >> 0x1b)) + b;
    d = ((a & c) | (~c & b)) + get32_le((param+0x28)) + d + 0x02441453;
    d = ((d << 0x09) | (d >> 0x17)) + a;
    c = ((d & b) | (~b & a)) + get32_le((param+0x3c)) + c - 0x275E197F;
    c = ((c << 0x0e) | (c >> 0x12)) + d;
    b = ((c & a) | (~a & d)) + get32_le((param+0x10)) + b - 0x182C0438;
    b = ((b << 0x14) | (b >> 0x0c)) + c;
    a = ((b & d) | (~d & c)) + get32_le((param+0x24)) + a + 0x21E1CDE6;
    a = ((a << 0x05) | (a >> 0x1b)) + b;
    d = ((a & c) | (~c & b)) + get32_le((param+0x38)) + d - 0x3CC8F82A;
    d = ((d << 0x09) | (d >> 0x17)) + a;
    c = ((d & b) | (~b & a)) + get32_le((param+0x0c)) + c - 0x0B2AF279;
    c = ((c << 0x0e) | (c >> 0x12)) + d;
    b = ((c & a) | (~a & d)) + get32_le((param+0x20)) + b + 0x455A14ED;
    b = ((b << 0x14) | (b >> 0x0c)) + c;
    a = ((b & d) | (~d & c)) + get32_le((param+0x34)) + a - 0x561C16FB;
    a = ((a << 0x05) | (a >> 0x1b)) + b;
    d = ((a & c) | (~c & b)) + get32_le((param+0x08)) + d - 0x03105C08;
    d = ((d << 0x09) | (d >> 0x17)) + a;
    c = ((d & b) | (~b & a)) + get32_le((param+0x1c)) + c + 0x676F02D9;
    c = ((c << 0x0e) | (c >> 0x12)) + d;
    b = ((c & a) | (~a & d)) + get32_le((param+0x30)) + b - 0x72D5B376;
    b = ((b << 0x14) | (b >> 0x0c)) + c;
  
    a = (b ^ c ^ d) + get32_le((param+0x14)) + a - 0x0005C6BE;
    a = ((a << 0x04) | (a >> 0x1c)) + b;
    d = (a ^ b ^ c) + get32_le((param+0x20)) + d - 0x788E097F;
    d = ((d << 0x0b) | (d >> 0x15)) + a;
    c = (d ^ a ^ b) + get32_le((param+0x2c)) + c + 0x6D9D6122;
    c = ((c << 0x10) | (c >> 0x10)) + d;
    b = (c ^ d ^ a) + get32_le((param+0x38)) + b - 0x021AC7F4;
    b = ((b << 0x17) | (b >> 0x09)) + c;
    a = (b ^ c ^ d) + get32_le((param+0x04)) + a - 0x5B4115BC;
    a = ((a << 0x04) | (a >> 0x1c)) + b;
    d = (a ^ b ^ c) + get32_le((param+0x10)) + d + 0x4BDECFA9;
    d = ((d << 0x0b) | (d >> 0x15)) + a;
    c = (d ^ a ^ b) + get32_le((param+0x1c)) + c - 0x0944B4A0;
    c = ((c << 0x10) | (c >> 0x10)) + d;
    b = (c ^ d ^ a) + get32_le((param+0x28)) + b - 0x41404390;
    b = ((b << 0x17) | (b >> 0x09)) + c;
    a = (b ^ c ^ d) + get32_le((param+0x34)) + a + 0x289B7EC6;
    a = ((a << 0x04) | (a >> 0x1c)) + b;
    d = (a ^ b ^ c) + get32_le((param+0x00)) + d - 0x155ED806;
    d = ((d << 0x0b) | (d >> 0x15)) + a;
    c = (d ^ a ^ b) + get32_le((param+0x0c)) + c - 0x2B10CF7B;
    c = ((c << 0x10) | (c >> 0x10)) + d;
    b = (c ^ d ^ a) + get32_le((param+0x18)) + b + 0x04881D05;
    b = ((b << 0x17) | (b >> 0x09)) + c;
    a = (b ^ c ^ d) + get32_le((param+0x24)) + a - 0x262B2FC7;
    a = ((a << 0x04) | (a >> 0x1c)) + b;
    d = (a ^ b ^ c) + get32_le((param+0x30)) + d - 0x1924661B;
    d = ((d << 0x0b) | (d >> 0x15)) + a;
    c = (d ^ a ^ b) + get32_le((param+0x3c)) + c + 0x1fa27cf8;
    c = ((c << 0x10) | (c >> 0x10)) + d;
    b = (c ^ d ^ a) + get32_le((param+0x08)) + b - 0x3B53A99B;
    b = ((b << 0x17) | (b >> 0x09)) + c;
  
    a = ((~d | b) ^ c)  + get32_le((param+0x00)) + a - 0x0BD6DDBC;
    a = ((a << 0x06) | (a >> 0x1a)) + b; 
    d = ((~c | a) ^ b)  + get32_le((param+0x1c)) + d + 0x432AFF97;
    d = ((d << 0x0a) | (d >> 0x16)) + a; 
    c = ((~b | d) ^ a)  + get32_le((param+0x38)) + c - 0x546BDC59;
    c = ((c << 0x0f) | (c >> 0x11)) + d; 
    b = ((~a | c) ^ d)  + get32_le((param+0x14)) + b - 0x036C5FC7;
    b = ((b << 0x15) | (b >> 0x0b)) + c; 
    a = ((~d | b) ^ c)  + get32_le((param+0x30)) + a + 0x655B59C3;
    a = ((a << 0x06) | (a >> 0x1a)) + b; 
    d = ((~c | a) ^ b)  + get32_le((param+0x0C)) + d - 0x70F3336E;
    d = ((d << 0x0a) | (d >> 0x16)) + a; 
    c = ((~b | d) ^ a)  + get32_le((param+0x28)) + c - 0x00100B83;
    c = ((c << 0x0f) | (c >> 0x11)) + d; 
    b = ((~a | c) ^ d)  + get32_le((param+0x04)) + b - 0x7A7BA22F;
    b = ((b << 0x15) | (b >> 0x0b)) + c; 
    a = ((~d | b) ^ c)  + get32_le((param+0x20)) + a + 0x6FA87E4F;
    a = ((a << 0x06) | (a >> 0x1a)) + b; 
    d = ((~c | a) ^ b)  + get32_le((param+0x3c)) + d - 0x01D31920;
    d = ((d << 0x0a) | (d >> 0x16)) + a; 
    c = ((~b | d) ^ a)  + get32_le((param+0x18)) + c - 0x5CFEBCEC;
    c = ((c << 0x0f) | (c >> 0x11)) + d; 
    b = ((~a | c) ^ d)  + get32_le((param+0x34)) + b + 0x4E0811A1;
    b = ((b << 0x15) | (b >> 0x0b)) + c; 
    a = ((~d | b) ^ c)  + get32_le((param+0x10)) + a - 0x08AC817E;
    a = ((a << 0x06) | (a >> 0x1a)) + b; 
    d = ((~c | a) ^ b)  + get32_le((param+0x2c)) + d - 0x42C50DCB;
    d = ((d << 0x0a) | (d >> 0x16)) + a; 
    c = ((~b | d) ^ a)  + get32_le((param+0x08)) + c + 0x2AD7D2BB;
    c = ((c << 0x0f) | (c >> 0x11)) + d; 
    b = ((~a | c) ^ d)  + get32_le((param+0x24)) + b - 0x14792C6F;
    b = ((b << 0x15) | (b >> 0x0b)) + c; 
  
  
    a += get32_le(field);
    b += get32_le(field+4);
    c += get32_le(field+8);
    d += get32_le(field+12);

    put32_le(field,    a);
    put32_le(field+4,  b);
    put32_le(field+8,  c);
    put32_le(field+12, d);
}



/*
 * This function is taken from xine-lib program.
 * used to calculate clientchallenge2.
 */
static void call_hash (char *key, char *challenge, unsigned int len)
{

    char *ptr1, *ptr2;
    uint32_t a, b, c, d, tmp;
  
    ptr1=(key+16);
    ptr2=(key+20);
  
    a = get32_le(ptr1);
    b = (a >> 3) & 0x3f;
    a += len * 8;
    put32_le(ptr1, a);
  
    if (a < (len << 3))
	{
	    ptr2 += 4;
	}

    tmp = get32_le(ptr2) + (len >> 0x1d);
    put32_le(ptr2, tmp);
    a = 64 - b;
    c = 0;  
    if (a <= len)
	{
    
	    memcpy(key+b+24, challenge, a);
	    hash(key, key+24);
	    c = a;
	    d = c + 0x3f;
    
	    while ( d < len ) {
		hash(key, challenge+d-0x3f);
		d += 64;
		c += 64;
	    }
	    b = 0;
	}
  
    memcpy(key+b+24, challenge+c, len-c);
}



/*
 * This function is taken from xine-lib program.
 * used to calculate clientchallenge2.
 */
static void calc_response (char *result, char *field)
{
  
    char buf1[128];
    char buf2[128];
    unsigned int i;
  
    memset(buf1, 0, 64);
    *buf1 = 128;
  
    memcpy(buf2, field+16, 8);
  
    i = (get32_le((buf2)) >> 3) & 0x3f;
 
    if (i < 56) {
	i = 56 - i;
    } else {
	i = 120 - i;
    }

    call_hash(field, buf1, i);
    call_hash(field, buf2, 8);

    memcpy(result, field, 16);

}



/*
 * This function is taken from xine-lib program.
 * used to calculate clientchallenge2.
 */
static void calc_response_string (char *result, char *challenge) {
 
    char field[128];
    char zres[20];
    int  i;
  
    /* initialize our field */
    put32_be(field,      0x01234567);
    put32_be(field + 4,  0x89abcdef);
    put32_be(field + 8,  0xfedcba98);
    put32_be(field + 12, 0x76543210);
    put32_be(field + 16, 0x00000000);
    put32_be(field + 20, 0x00000000);
  
    /* calculate response */
    call_hash(field, challenge, 64);
    calc_response(zres,field);
 
    /* convert zres to ascii string */
    for (i=0; i<16; i++ ) {
	char a, b;
    
	a = (zres[i] >> 4) & 0x0f;
	b = zres[i] & 0x0f;

	result[i*2]   = ((a<10) ? (a+48) : (a+87)) & 0xff;
	result[i*2+1] = ((b<10) ? (b+48) : (b+87)) & 0xff;
    }
}



/*
 * This function is taken from xine-lib program.
 * used to calculate clientchallenge2.
 * response must be longer than 64b, and chksum must be longer than 34b
 *
 */
void real_calc_challenge2_and_checksum (char *challenge, /* in */
					char *response, char *chksum) /* outs */
{

    int   ch_len, resp_len;
    int   i;
    char *ptr;
    char  buf[128];

    /* initialize return values */
    memset(response, 0, 64);
    memset(chksum, 0, 34);
  
    /* initialize buffer */
    memset(buf, 0, 128);
    ptr=buf;
    put32_be(ptr, 0xa1e9149d);
    ptr+=4;
    put32_be(ptr, 0x0e6b3b59);
    ptr+=4;

    /* some (length) checks */
    if(challenge != NULL) {
	ch_len = strlen(challenge);
	
	if(ch_len == 40) { /* what a hack... */
	    challenge[32]=0;
	    ch_len=32;
	}
	if ( ch_len > 56 ) ch_len=56;
    
	/* copy challenge to buf */
	memcpy(ptr, challenge, ch_len);
    }
  
    /* xor challenge bytewise with xor_table */
    for (i=0; i<XOR_TABLE_LEN; i++) {
	ptr[i] = ptr[i] ^ xor_table[i];
    }
    calc_response_string(response, buf);

    /* add tail */
    resp_len = strlen(response);
    strcpy(&response[resp_len], "01d0a8e3");

    /* calculate checksum */
    for (i=0; i<resp_len/4; i++) {
	chksum[i] = response[i*4];
    }
}

