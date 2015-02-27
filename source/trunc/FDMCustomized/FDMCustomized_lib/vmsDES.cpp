/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#include "vmsDES.h"
#include "libdes\des_locl.h"
#include "libdes\podd.h"
#include "libdes\sk.h"
#include "libdes\spr.h"

static int check_parity(des_cblock *key);

int des_check_key=0;

void des_set_odd_parity(des_cblock *key)
	{
	int i;

	for (i=0; i<DES_KEY_SZ; i++)
		(*key)[i]=odd_parity[(*key)[i]];
	}

static int check_parity(des_cblock *key)
	{
	int i;

	for (i=0; i<DES_KEY_SZ; i++)
		{
		if ((*key)[i] != odd_parity[(*key)[i]])
			return(0);
		}
	return(1);
	}

#define NUM_WEAK_KEY	16
static des_cblock weak_keys[NUM_WEAK_KEY]={
	
	0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01,
	0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,
	0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,
	0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,
	
	0x01,0xFE,0x01,0xFE,0x01,0xFE,0x01,0xFE,
	0xFE,0x01,0xFE,0x01,0xFE,0x01,0xFE,0x01,
	0x1F,0xE0,0x1F,0xE0,0x0E,0xF1,0x0E,0xF1,
	0xE0,0x1F,0xE0,0x1F,0xF1,0x0E,0xF1,0x0E,
	0x01,0xE0,0x01,0xE0,0x01,0xF1,0x01,0xF1,
	0xE0,0x01,0xE0,0x01,0xF1,0x01,0xF1,0x01,
	0x1F,0xFE,0x1F,0xFE,0x0E,0xFE,0x0E,0xFE,
	0xFE,0x1F,0xFE,0x1F,0xFE,0x0E,0xFE,0x0E,
	0x01,0x1F,0x01,0x1F,0x01,0x0E,0x01,0x0E,
	0x1F,0x01,0x1F,0x01,0x0E,0x01,0x0E,0x01,
	0xE0,0xFE,0xE0,0xFE,0xF1,0xFE,0xF1,0xFE,
	0xFE,0xE0,0xFE,0xE0,0xFE,0xF1,0xFE,0xF1};

int des_is_weak_key(des_cblock *key)
	{
	int i;

	for (i=0; i<NUM_WEAK_KEY; i++)
		
		if (memcmp(weak_keys[i],key,sizeof(key)) == 0) return(1);
	return(0);
	}

#define HPERM_OP(a,t,n,m) ((t)=((((a)<<(16-(n)))^(a))&(m)),\
	(a)=(a)^(t)^(t>>(16-(n))))

static char shifts2[16]={0,0,1,1,1,1,1,1,0,1,1,1,1,1,1,0};

int des_set_key(des_cblock *key, des_key_schedule schedule)
	{
	register unsigned long c,d,t,s;
	register unsigned char *in;
	register unsigned long *k;
	register int i;

	if (des_check_key)
		{
		if (!check_parity(key))
			return(-1);

		if (des_is_weak_key(key))
			return(-2);
		}

	k=(unsigned long *)schedule;
	in=(unsigned char *)key;

	c2l(in,c);
	c2l(in,d);

	 

	
	PERM_OP (d,c,t,4,0x0f0f0f0fL);
	HPERM_OP(c,t,-2,0xcccc0000L);
	HPERM_OP(d,t,-2,0xcccc0000L);
	PERM_OP (d,c,t,1,0x55555555L);
	PERM_OP (c,d,t,8,0x00ff00ffL);
	PERM_OP (d,c,t,1,0x55555555L);
	d=	(((d&0x000000ffL)<<16)| (d&0x0000ff00L)     |
		 ((d&0x00ff0000L)>>16)|((c&0xf0000000L)>>4));
	c&=0x0fffffffL;

	for (i=0; i<ITERATIONS; i++)
		{
		if (shifts2[i])
			{ c=((c>>2)|(c<<26)); d=((d>>2)|(d<<26)); }
		else
			{ c=((c>>1)|(c<<27)); d=((d>>1)|(d<<27)); }
		c&=0x0fffffffL;
		d&=0x0fffffffL;
		
		s=	des_skb[0][ (c    )&0x3f                ]|
			des_skb[1][((c>> 6)&0x03)|((c>> 7)&0x3c)]|
			des_skb[2][((c>>13)&0x0f)|((c>>14)&0x30)]|
			des_skb[3][((c>>20)&0x01)|((c>>21)&0x06) |
						  ((c>>22)&0x38)];
		t=	des_skb[4][ (d    )&0x3f                ]|
			des_skb[5][((d>> 7)&0x03)|((d>> 8)&0x3c)]|
			des_skb[6][ (d>>15)&0x3f                ]|
			des_skb[7][((d>>21)&0x0f)|((d>>22)&0x30)];

		
		*(k++)=((t<<16)|(s&0x0000ffffL))&0xffffffffL;
		s=     ((s>>16)|(t&0xffff0000L));

		s=(s<<4)|(s>>28);
		*(k++)=s&0xffffffffL;
		}
	return(0);
	}

int des_key_sched(des_cblock *key,des_key_schedule schedule)
	{
	return(des_set_key(key,schedule));
	}

int des_ecb_encrypt(des_cblock *input,des_cblock *output,des_key_schedule ks,int encrypt)
	{
	register unsigned long l0,l1;
	register unsigned char *in,*out;
	unsigned long ll[2];

	in=(unsigned char *)input;
	out=(unsigned char *)output;
	c2l(in,l0);
	c2l(in,l1);
	ll[0]=l0;
	ll[1]=l1;
	des_encrypt(ll,ll,ks,encrypt);
	l0=ll[0];
	l1=ll[1];
	l2c(l0,out);
	l2c(l1,out);
	l0=l1=ll[0]=ll[1]=0;
	return(0);
	}

int des_encrypt(unsigned long *input,unsigned long *output,des_key_schedule ks,int encrypt)
	{
	register unsigned long l,r,t,u;
#ifdef ALT_ECB
	register unsigned char *des_SP=(unsigned char *)des_SPtrans;
#endif
#ifdef MSDOS
	union fudge {
		unsigned long  l;
		unsigned short s[2];
		unsigned char  c[4];
		} U,T;
#endif
	register int i;
	register unsigned long *s;

	l=input[0];
	r=input[1];

	IP(l,r,t);
	
	t=(r<<1)|(r>>31);
	r=(l<<1)|(l>>31);
	l=t;

	
	l&=0xffffffffL;
	r&=0xffffffffL;

	s=(unsigned long *)ks;
	
	if (encrypt)
		{
		for (i=0; i<32; i+=4)
			{
			D_ENCRYPT(l,r,i+0); 
			D_ENCRYPT(r,l,i+2); 
			}
		}
	else
		{
		for (i=30; i>0; i-=4)
			{
			D_ENCRYPT(l,r,i-0); 
			D_ENCRYPT(r,l,i-2); 
			}
		}
	l=(l>>1)|(l<<31);
	r=(r>>1)|(r<<31);
	
	l&=0xffffffffL;
	r&=0xffffffffL;

	FP(r,l,t);
	output[0]=l;
	output[1]=r;
	l=r=t=u=0;
	return(0);
	}

vmsDES::vmsDES()
{

}

vmsDES::~vmsDES()
{

}

void vmsDES::set_Key(DES_KEY szKey)
{
	des_set_key ((des_cblock*)szKey, m_hardkey);
}

void vmsDES::Encrypt(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize)
{
	DoDES (pbIn, pbOut, dwSize, TRUE);
}

void vmsDES::Decrypt(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize)
{
	DoDES (pbIn, pbOut, dwSize, FALSE);
}

void vmsDES::DoDES(LPBYTE pbIn, LPBYTE pbOut, DWORD dwSize, BOOL bEncrypt)
{
	int op = bEncrypt ? DES_ENCRYPT : DES_DECRYPT;

	while (dwSize)
	{
		if (dwSize < 8)
			throw "DES error: buffer is not 8-aligned"; 
		else
		{
			des_ecb_encrypt ((des_cblock*)pbIn, (des_cblock*)pbOut, m_hardkey, op);
			pbIn += 8; pbOut += 8;
			dwSize -= 8;
		}
	}
}
