/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/




#include <stdio.h>
#ifdef _MSC_VER
  #include "des.h"
#else
  #include "libdes/des.h"
#endif 



#include <string.h>

#define bcopy(b1,b2,len) memcpy(b2, b1, (size_t)(len))
#define bzero(b,len) memset(b, 0, (size_t)(len))
#define bcmp(b1,b2,len) memcmp(b1, b2, (size_t)(len))
#define index(s1,char) strchr(s1,char)

#if !defined(_LIBC) || defined(NOCONST)
#define const
#endif

#ifdef __STDC__
#define PROTO
#endif

#ifdef RAND
#define random() rand()
#define srandom(s) srand(s)
#endif

#define ITERATIONS 16
#define HALF_ITERATIONS 8


#define MAXWRITE	(1024*16)
#define BSIZE		(MAXWRITE+4)

#define c2l(c,l)	(l =((unsigned long)(*((c)++)))    , \
			 l|=((unsigned long)(*((c)++)))<< 8, \
			 l|=((unsigned long)(*((c)++)))<<16, \
			 l|=((unsigned long)(*((c)++)))<<24)


#define c2ln(c,l1,l2,n)	{ \
			c+=n; \
			l1=l2=0; \
			switch (n) { \
			case 8: l2 =((unsigned long)(*(--(c))))<<24; \
			case 7: l2|=((unsigned long)(*(--(c))))<<16; \
			case 6: l2|=((unsigned long)(*(--(c))))<< 8; \
			case 5: l2|=((unsigned long)(*(--(c))));     \
			case 4: l1 =((unsigned long)(*(--(c))))<<24; \
			case 3: l1|=((unsigned long)(*(--(c))))<<16; \
			case 2: l1|=((unsigned long)(*(--(c))))<< 8; \
			case 1: l1|=((unsigned long)(*(--(c))));     \
				} \
			}

#define l2c(l,c)	(*((c)++)=(unsigned char)(((l)    )&0xff), \
			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>24)&0xff))


#define HDRSIZE 4

#define n2l(c,l)	(l =((unsigned long)(*((c)++)))<<24, \
			 l|=((unsigned long)(*((c)++)))<<16, \
			 l|=((unsigned long)(*((c)++)))<< 8, \
			 l|=((unsigned long)(*((c)++))))

#define l2n(l,c)	(*((c)++)=(unsigned char)(((l)>>24)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \
			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \
			 *((c)++)=(unsigned char)(((l)    )&0xff))


#define l2cn(l1,l2,c,n)	{ \
			c+=n; \
			switch (n) { \
			case 8: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \
			case 7: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \
			case 6: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \
			case 5: *(--(c))=(unsigned char)(((l2)    )&0xff); \
			case 4: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \
			case 3: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \
			case 2: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \
			case 1: *(--(c))=(unsigned char)(((l1)    )&0xff); \
				} \
			}


#ifdef ALT_ECB
#define D_ENCRYPT(L,R,S) \
	u=((R^s[S  ])<<2);	\
	t= R^s[S+1]; \
	t=((t>>2)+(t<<30)); \
	L^= \
	*(unsigned long *)(des_SP+0x0100+((t    )&0xfc))+ \
	*(unsigned long *)(des_SP+0x0300+((t>> 8)&0xfc))+ \
	*(unsigned long *)(des_SP+0x0500+((t>>16)&0xfc))+ \
	*(unsigned long *)(des_SP+0x0700+((t>>24)&0xfc))+ \
	*(unsigned long *)(des_SP+       ((u    )&0xfc))+ \
  	*(unsigned long *)(des_SP+0x0200+((u>> 8)&0xfc))+ \
  	*(unsigned long *)(des_SP+0x0400+((u>>16)&0xfc))+ \
 	*(unsigned long *)(des_SP+0x0600+((u>>24)&0xfc));
#else 
#ifdef MSDOS
#define D_ENCRYPT(L,R,S)	\
	U.l=R^s[S+1]; \
	T.s[0]=((U.s[0]>>4)|(U.s[1]<<12))&0x3f3f; \
	T.s[1]=((U.s[1]>>4)|(U.s[0]<<12))&0x3f3f; \
	U.l=(R^s[S  ])&0x3f3f3f3f; \
	L^=	des_SPtrans[1][(T.c[0])]| \
		des_SPtrans[3][(T.c[1])]| \
		des_SPtrans[5][(T.c[2])]| \
		des_SPtrans[7][(T.c[3])]| \
		des_SPtrans[0][(U.c[0])]| \
		des_SPtrans[2][(U.c[1])]| \
		des_SPtrans[4][(U.c[2])]| \
		des_SPtrans[6][(U.c[3])];
#else
#define D_ENCRYPT(L,R,S)	\
	u=(R^s[S  ]); \
	t=R^s[S+1]; \
	t=((t>>4)+(t<<28)); \
	L^=	des_SPtrans[1][(t    )&0x3f]| \
		des_SPtrans[3][(t>> 8)&0x3f]| \
		des_SPtrans[5][(t>>16)&0x3f]| \
		des_SPtrans[7][(t>>24)&0x3f]| \
		des_SPtrans[0][(u    )&0x3f]| \
		des_SPtrans[2][(u>> 8)&0x3f]| \
		des_SPtrans[4][(u>>16)&0x3f]| \
		des_SPtrans[6][(u>>24)&0x3f];
#endif
#endif

	
#define PERM_OP(a,b,t,n,m) ((t)=((((a)>>(n))^(b))&(m)),\
	(b)^=(t),\
	(a)^=((t)<<(n)))

#define IP(l,r,t) \
	PERM_OP(r,l,t, 4,0x0f0f0f0fL); \
	PERM_OP(l,r,t,16,0x0000ffffL); \
	PERM_OP(r,l,t, 2,0x33333333L); \
	PERM_OP(l,r,t, 8,0x00ff00ffL); \
	PERM_OP(r,l,t, 1,0x55555555L);

#define FP(l,r,t) \
	PERM_OP(l,r,t, 1,0x55555555L); \
	PERM_OP(r,l,t, 8,0x00ff00ffL); \
	PERM_OP(l,r,t, 2,0x33333333L); \
	PERM_OP(r,l,t,16,0x0000ffffL); \
	PERM_OP(l,r,t, 4,0x0f0f0f0fL);


