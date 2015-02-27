/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/




#ifndef HEADER_DES_H
#define HEADER_DES_H

typedef unsigned char des_cblock[8];
typedef struct des_ks_struct
	{
	union	{
		des_cblock _;
		
		unsigned long pad[2];
		} ks;
#undef _
#define _	ks._
	} des_key_schedule[16];

#define DES_KEY_SZ 	(sizeof(des_cblock))
#define DES_SCHEDULE_SZ (sizeof(des_key_schedule))

#define DES_ENCRYPT	1
#define DES_DECRYPT	0

#define DES_CBC_MODE	0
#define DES_PCBC_MODE	1

#define C_Block des_cblock
#define Key_schedule des_key_schedule
#define ENCRYPT DES_ENCRYPT
#define DECRYPT DES_DECRYPT
#define KEY_SZ DES_KEY_SZ
#define string_to_key des_string_to_key
#define read_pw_string des_read_pw_string
#define random_key des_random_key
#define pcbc_encrypt des_pcbc_encrypt
#define set_key des_set_key
#define key_sched des_key_sched
#define ecb_encrypt des_ecb_encrypt
#define cbc_encrypt des_cbc_encrypt
#define cbc_cksum des_cbc_cksum
#define quad_cksum des_quad_cksum


typedef struct des_ks_struct bit_64;

extern int des_check_key;	
extern int des_rw_mode;		

int des_3ecb_encrypt(des_cblock *input,des_cblock *output,\
	des_key_schedule ks1,des_key_schedule ks2,int encrypt);
unsigned long des_cbc_cksum(des_cblock *input,des_cblock *output,\
	long length,des_key_schedule schedule,des_cblock *ivec);
int des_cbc_encrypt(des_cblock *input,des_cblock *output,long length,\
	des_key_schedule schedule,des_cblock *ivec,int encrypt);
int des_3cbc_encrypt(des_cblock *input,des_cblock *output,long length,\
	des_key_schedule sk1,des_key_schedule sk2,\
	des_cblock *ivec1,des_cblock *ivec2,int encrypt);
int des_cfb_encrypt(unsigned char *in,unsigned char *out,int numbits,\
	long length,des_key_schedule schedule,des_cblock *ivec,int encrypt);
int des_ecb_encrypt(des_cblock *input,des_cblock *output,\
	des_key_schedule ks,int encrypt);
int des_encrypt(unsigned long *input,unsigned long *output,
	des_key_schedule ks, int encrypt);
int des_enc_read(int fd,char *buf,int len,des_key_schedule sched,\
	des_cblock *iv);
int des_enc_write(int fd,char *buf,int len,des_key_schedule sched,\
	des_cblock *iv);
#ifdef PERL5
char *des_crypt(const char *buf,const char *salt);
#else
char *crypt(char *buf,char *salt);
#endif
int des_ofb_encrypt(unsigned char *in,unsigned char *out,\
	int numbits,long length,des_key_schedule schedule,des_cblock *ivec);
int des_pcbc_encrypt(des_cblock *input,des_cblock *output,long length,\
	des_key_schedule schedule,des_cblock *ivec,int encrypt);
unsigned long des_quad_cksum(des_cblock *input,des_cblock *output,\
	long length,int out_count,des_cblock *seed);
void des_random_seed(des_cblock key);
int des_random_key(des_cblock ret);
int des_read_password(des_cblock *key,char *prompt,int verify);
int des_read_2passwords(des_cblock *key1,des_cblock *key2, \
	char *prompt,int verify);
int des_read_pw_string(char *buf,int length,char *prompt,int verify);
void des_set_odd_parity(des_cblock *key);
int des_is_weak_key(des_cblock *key);
int des_set_key(des_cblock *key,des_key_schedule schedule);
int des_key_sched(des_cblock *key,des_key_schedule schedule);
int des_string_to_key(char *str,des_cblock *key);
int des_string_to_2keys(char *str,des_cblock *key1,des_cblock *key2);
#endif
