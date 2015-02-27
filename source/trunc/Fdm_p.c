

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Nov 24 21:33:14 2014
 */
/* Compiler settings for Fdm.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif /* __RPCPROXY_H_VERSION__ */


#include "Fdm.h"

#define TYPE_FORMAT_STRING_SIZE   1159                              
#define PROC_FORMAT_STRING_SIZE   2275                              
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   2            

typedef struct _Fdm_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } Fdm_MIDL_TYPE_FORMAT_STRING;

typedef struct _Fdm_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } Fdm_MIDL_PROC_FORMAT_STRING;

typedef struct _Fdm_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } Fdm_MIDL_EXPR_FORMAT_STRING;


static const RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const Fdm_MIDL_TYPE_FORMAT_STRING Fdm__MIDL_TypeFormatString;
extern const Fdm_MIDL_PROC_FORMAT_STRING Fdm__MIDL_ProcFormatString;
extern const Fdm_MIDL_EXPR_FORMAT_STRING Fdm__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWGUrlReceiver_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWGUrlReceiver_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWGUrlListReceiver_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWGUrlListReceiver_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFdmFlvDownload_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFdmFlvDownload_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFDM_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFDM_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFDMDownload_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFDMDownload_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFDMDownloadsStat_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFDMDownloadsStat_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFdmTorrentFilesRcvr_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFdmTorrentFilesRcvr_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFDMFlashVideoDownloads_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFDMFlashVideoDownloads_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFdmUiWindow_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFdmUiWindow_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const Fdm_MIDL_PROC_FORMAT_STRING Fdm__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_Url */


	/* Procedure get_Url */


	/* Procedure get_Url */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 18 */	NdrFcShort( 0x1 ),	/* 1 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 24 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Url */


	/* Procedure put_Url */


	/* Procedure put_Url */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x1 ),	/* 1 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */


	/* Parameter newVal */

/* 60 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowAddDownloadDialog */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 82 */	NdrFcShort( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 88 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 96 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowAddPageDownloadDialog */

/* 102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0xa ),	/* 10 */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 126 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Referer */


	/* Procedure get_Comment */

/* 132 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 134 */	NdrFcLong( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0xb ),	/* 11 */
/* 140 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x8 ),	/* 8 */
/* 146 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 148 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 150 */	NdrFcShort( 0x1 ),	/* 1 */
/* 152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 156 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 158 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 160 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */


	/* Return value */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 164 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Referer */


	/* Procedure put_Comment */

/* 168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0xc ),	/* 12 */
/* 176 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 182 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 184 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x1 ),	/* 1 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 192 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 194 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 196 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */


	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Referer */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0xd ),	/* 13 */
/* 212 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 220 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 222 */	NdrFcShort( 0x1 ),	/* 1 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 228 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 232 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Referer */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0xe ),	/* 14 */
/* 248 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 256 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x1 ),	/* 1 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 264 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 266 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 268 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 272 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddDownload */

/* 276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 282 */	NdrFcShort( 0xf ),	/* 15 */
/* 284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_CheckExtension */

/* 306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 312 */	NdrFcShort( 0x10 ),	/* 16 */
/* 314 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 318 */	NdrFcShort( 0x24 ),	/* 36 */
/* 320 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 322 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 330 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_CheckExtension */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x11 ),	/* 17 */
/* 350 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 358 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 364 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 368 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 374 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_IgnoreSize */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x12 ),	/* 18 */
/* 386 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x24 ),	/* 36 */
/* 392 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 394 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 402 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 406 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_IgnoreSize */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x13 ),	/* 19 */
/* 422 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 428 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 430 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 438 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UseSkipExtsList */

/* 450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x14 ),	/* 20 */
/* 458 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 462 */	NdrFcShort( 0x24 ),	/* 36 */
/* 464 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 466 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 474 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 476 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 480 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 482 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UseSkipExtsList */

/* 486 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 488 */	NdrFcLong( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x15 ),	/* 21 */
/* 494 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 500 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 502 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 510 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 512 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 516 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 518 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UIState */

/* 522 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 524 */	NdrFcLong( 0x0 ),	/* 0 */
/* 528 */	NdrFcShort( 0x16 ),	/* 22 */
/* 530 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 536 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 538 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 540 */	NdrFcShort( 0x1 ),	/* 1 */
/* 542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 546 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 548 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 550 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 552 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 554 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 556 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ForceSilent */

/* 558 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 560 */	NdrFcLong( 0x0 ),	/* 0 */
/* 564 */	NdrFcShort( 0x17 ),	/* 23 */
/* 566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x24 ),	/* 36 */
/* 572 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 574 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 582 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 584 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 588 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 590 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 592 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ForceSilent */

/* 594 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 596 */	NdrFcLong( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x18 ),	/* 24 */
/* 602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 608 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 610 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 618 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 620 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 626 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Cookies */

/* 630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x19 ),	/* 25 */
/* 638 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 644 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 646 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 648 */	NdrFcShort( 0x1 ),	/* 1 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 654 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 658 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 660 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 662 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 664 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Cookies */

/* 666 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 668 */	NdrFcLong( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x1a ),	/* 26 */
/* 674 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x8 ),	/* 8 */
/* 680 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 682 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x1 ),	/* 1 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 690 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 692 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 694 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 696 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 700 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_PostData */

/* 702 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 704 */	NdrFcLong( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x1b ),	/* 27 */
/* 710 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x8 ),	/* 8 */
/* 716 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 718 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 720 */	NdrFcShort( 0x1 ),	/* 1 */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 726 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 728 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 730 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 732 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 734 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_PostData */

/* 738 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 740 */	NdrFcLong( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x1c ),	/* 28 */
/* 746 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 752 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 754 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x1 ),	/* 1 */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 762 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 764 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 766 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 770 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ForceSilentEx */

/* 774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x1d ),	/* 29 */
/* 782 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x24 ),	/* 36 */
/* 788 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 790 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 798 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 800 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 806 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ForceSilentEx */

/* 810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 816 */	NdrFcShort( 0x1e ),	/* 30 */
/* 818 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 824 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 826 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 832 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 836 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ForceDownloadAutoStart */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x1f ),	/* 31 */
/* 854 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x24 ),	/* 36 */
/* 860 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 862 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 870 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 872 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 878 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ForceDownloadAutoStart */

/* 882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x20 ),	/* 32 */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 896 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 906 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DisableMaliciousChecking */

/* 918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x21 ),	/* 33 */
/* 926 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x24 ),	/* 36 */
/* 932 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 942 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DisableMaliciousChecking */

/* 954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x22 ),	/* 34 */
/* 962 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 968 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 970 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DisableURLExistsCheck */

/* 990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x23 ),	/* 35 */
/* 998 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1004 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1006 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1014 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1022 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_DisableURLExistsCheck */

/* 1026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1032 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1034 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1036 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1038 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1040 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1042 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FileName */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x25 ),	/* 37 */
/* 1070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1076 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1078 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1080 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1086 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1090 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FileName */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x26 ),	/* 38 */
/* 1106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1114 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1122 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FlashVideoDownload */

/* 1134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x27 ),	/* 39 */
/* 1142 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1148 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1150 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1158 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FlashVideoDownload */

/* 1170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1178 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1184 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1186 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_FileSize */

/* 1206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x29 ),	/* 41 */
/* 1214 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1220 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1222 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1224 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1230 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1234 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1238 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_FileSize */

/* 1242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x2a ),	/* 42 */
/* 1250 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1256 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1258 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1262 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1266 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1270 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_OriginalURL */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x2b ),	/* 43 */
/* 1286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1292 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1294 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1302 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_OriginalURL */

/* 1314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x2c ),	/* 44 */
/* 1322 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1328 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1330 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1334 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1338 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1342 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_UserAgent */

/* 1350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x2d ),	/* 45 */
/* 1358 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1364 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1366 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1368 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1374 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1376 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1378 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_UserAgent */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x2e ),	/* 46 */
/* 1394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1400 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1402 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1410 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Comment */

/* 1422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1428 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1436 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1438 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1440 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1446 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1450 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1454 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Comment */

/* 1458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0xa ),	/* 10 */
/* 1466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1470 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1472 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1474 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1482 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1486 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddUrlToList */

/* 1494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0xd ),	/* 13 */
/* 1502 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1510 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1518 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowAddUrlListDialog */

/* 1524 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1526 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1530 */	NdrFcShort( 0xe ),	/* 14 */
/* 1532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1538 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1540 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1546 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1550 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetUrlListFromDocumentSelection */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0xf ),	/* 15 */
/* 1562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1568 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1570 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDispatch */

/* 1578 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1582 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 1584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Cookies */

/* 1590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1598 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1602 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1604 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1606 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1608 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1614 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1618 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1622 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Cookies */

/* 1626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1632 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1634 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1640 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1642 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1646 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1650 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1654 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1658 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Url */

/* 1662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1676 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1678 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1686 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1688 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1690 */	NdrFcShort( 0x4e ),	/* Type Offset=78 */

	/* Return value */

/* 1692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1694 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Url */

/* 1698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1712 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1714 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 1722 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1724 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1726 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 1728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1730 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Shutdown */

/* 1734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1740 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1742 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1750 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bAskUser */

/* 1758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1760 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1766 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_DownloadText */

/* 1770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1778 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1784 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1786 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1788 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nTextIndex */

/* 1794 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1800 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 1802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1804 */	NdrFcShort( 0x20 ),	/* Type Offset=32 */

	/* Return value */

/* 1806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1808 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Handle */


	/* Procedure get_DownloadCount */

/* 1812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1818 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1820 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1826 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1828 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 1836 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1838 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1840 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1844 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Download */

/* 1848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1856 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1862 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1864 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nIndex */

/* 1872 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1874 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pVal */

/* 1878 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1880 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1882 */	NdrFcShort( 0x64 ),	/* Type Offset=100 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure BuildListOfDownloads */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1898 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1900 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bIncludeCompleted */

/* 1914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bIncludeRunning */

/* 1920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateBtDownload */

/* 1932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1940 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1946 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1948 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 1950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1952 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrFile */

/* 1956 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 1958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1960 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 1962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ForceSilent */

/* 1968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1976 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1980 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1982 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1984 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1990 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVal */

/* 1992 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1994 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1998 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2000 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2002 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_ForceSilent */

/* 2004 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2006 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2010 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2012 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2016 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2018 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2020 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2026 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter newVal */

/* 2028 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2030 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2034 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2036 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessIeDocument */

/* 2040 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2042 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2046 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2048 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2054 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2056 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDispatch */

/* 2064 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2066 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2068 */	NdrFcShort( 0x3c ),	/* Type Offset=60 */

	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessHtml */

/* 2076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2084 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2090 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2092 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2096 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrHost */

/* 2100 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2104 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Parameter bstrHtml */

/* 2106 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2110 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2114 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFromUrl */

/* 2118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2124 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2132 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2134 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2138 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrUrl */

/* 2142 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2146 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 2148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowAddDownloadDialog */

/* 2154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2160 */	NdrFcShort( 0xa ),	/* 10 */
/* 2162 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2168 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2170 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2176 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrSrcWebPageUrl */

/* 2178 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2180 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2182 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Parameter pDld */

/* 2184 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2188 */	NdrFcShort( 0x7a ),	/* Type Offset=122 */

	/* Return value */

/* 2190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShowAddDownloadsDialog */

/* 2196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2202 */	NdrFcShort( 0xb ),	/* 11 */
/* 2204 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2210 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2212 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 2214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2216 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bstrSrcWebPageUrl */

/* 2220 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2222 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2224 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Parameter pDownloads */

/* 2226 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 2228 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2230 */	NdrFcShort( 0x47c ),	/* Type Offset=1148 */

	/* Return value */

/* 2232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2234 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitForWindowCreation */

/* 2238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2244 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2246 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2252 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2254 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter uTimeoutMilliseconds */

/* 2262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2264 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2270 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const Fdm_MIDL_TYPE_FORMAT_STRING Fdm__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x1c ),	/* Offset= 28 (32) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0xe ),	/* Offset= 14 (22) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 20 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 22 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 24 */	NdrFcShort( 0x8 ),	/* 8 */
/* 26 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (10) */
/* 28 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 30 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 32 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 34 */	NdrFcShort( 0x0 ),	/* 0 */
/* 36 */	NdrFcShort( 0x4 ),	/* 4 */
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0xffde ),	/* Offset= -34 (6) */
/* 42 */	
			0x12, 0x0,	/* FC_UP */
/* 44 */	NdrFcShort( 0xffea ),	/* Offset= -22 (22) */
/* 46 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 48 */	NdrFcShort( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x4 ),	/* 4 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (42) */
/* 56 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 58 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 60 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 62 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */
/* 70 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 72 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 74 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 76 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 78 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 80 */	NdrFcShort( 0x2 ),	/* Offset= 2 (82) */
/* 82 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 84 */	NdrFcLong( 0x454a4044 ),	/* 1162494020 */
/* 88 */	NdrFcShort( 0x16ec ),	/* 5868 */
/* 90 */	NdrFcShort( 0x4d64 ),	/* 19812 */
/* 92 */	0x90,		/* 144 */
			0x69,		/* 105 */
/* 94 */	0xc5,		/* 197 */
			0xb8,		/* 184 */
/* 96 */	0x83,		/* 131 */
			0x2b,		/* 43 */
/* 98 */	0x7b,		/* 123 */
			0x55,		/* 85 */
/* 100 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 102 */	NdrFcShort( 0x2 ),	/* Offset= 2 (104) */
/* 104 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 106 */	NdrFcLong( 0x8f2b3016 ),	/* -1892995050 */
/* 110 */	NdrFcShort( 0x17d4 ),	/* 6100 */
/* 112 */	NdrFcShort( 0x447a ),	/* 17530 */
/* 114 */	0xb2,		/* 178 */
			0x7,		/* 7 */
/* 116 */	0xff,		/* 255 */
			0xa8,		/* 168 */
/* 118 */	0x95,		/* 149 */
			0x7a,		/* 122 */
/* 120 */	0x83,		/* 131 */
			0x4a,		/* 74 */
/* 122 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 124 */	NdrFcLong( 0xe66b63b0 ),	/* -429169744 */
/* 128 */	NdrFcShort( 0x49f8 ),	/* 18936 */
/* 130 */	NdrFcShort( 0x47e3 ),	/* 18403 */
/* 132 */	0xa9,		/* 169 */
			0xba,		/* 186 */
/* 134 */	0x79,		/* 121 */
			0x92,		/* 146 */
/* 136 */	0x87,		/* 135 */
			0xb5,		/* 181 */
/* 138 */	0x9e,		/* 158 */
			0x87,		/* 135 */
/* 140 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 142 */	NdrFcShort( 0x2 ),	/* Offset= 2 (144) */
/* 144 */	
			0x12, 0x0,	/* FC_UP */
/* 146 */	NdrFcShort( 0x3d8 ),	/* Offset= 984 (1130) */
/* 148 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 150 */	NdrFcShort( 0x18 ),	/* 24 */
/* 152 */	NdrFcShort( 0xa ),	/* 10 */
/* 154 */	NdrFcLong( 0x8 ),	/* 8 */
/* 158 */	NdrFcShort( 0x5a ),	/* Offset= 90 (248) */
/* 160 */	NdrFcLong( 0xd ),	/* 13 */
/* 164 */	NdrFcShort( 0x90 ),	/* Offset= 144 (308) */
/* 166 */	NdrFcLong( 0x9 ),	/* 9 */
/* 170 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (364) */
/* 172 */	NdrFcLong( 0xc ),	/* 12 */
/* 176 */	NdrFcShort( 0x2bc ),	/* Offset= 700 (876) */
/* 178 */	NdrFcLong( 0x24 ),	/* 36 */
/* 182 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (924) */
/* 184 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 188 */	NdrFcShort( 0x302 ),	/* Offset= 770 (958) */
/* 190 */	NdrFcLong( 0x10 ),	/* 16 */
/* 194 */	NdrFcShort( 0x31c ),	/* Offset= 796 (990) */
/* 196 */	NdrFcLong( 0x2 ),	/* 2 */
/* 200 */	NdrFcShort( 0x336 ),	/* Offset= 822 (1022) */
/* 202 */	NdrFcLong( 0x3 ),	/* 3 */
/* 206 */	NdrFcShort( 0x350 ),	/* Offset= 848 (1054) */
/* 208 */	NdrFcLong( 0x14 ),	/* 20 */
/* 212 */	NdrFcShort( 0x36a ),	/* Offset= 874 (1086) */
/* 214 */	NdrFcShort( 0xffff ),	/* Offset= -1 (213) */
/* 216 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 218 */	NdrFcShort( 0x4 ),	/* 4 */
/* 220 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 226 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 228 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 230 */	NdrFcShort( 0x4 ),	/* 4 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x1 ),	/* 1 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	0x12, 0x0,	/* FC_UP */
/* 242 */	NdrFcShort( 0xff24 ),	/* Offset= -220 (22) */
/* 244 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 246 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 248 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 252 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 254 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 256 */	NdrFcShort( 0x4 ),	/* 4 */
/* 258 */	NdrFcShort( 0x4 ),	/* 4 */
/* 260 */	0x11, 0x0,	/* FC_RP */
/* 262 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (216) */
/* 264 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 266 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 268 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 280 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 282 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 284 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 286 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 290 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 296 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 300 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 302 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 304 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (268) */
/* 306 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 308 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x6 ),	/* Offset= 6 (320) */
/* 316 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 318 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 320 */	
			0x11, 0x0,	/* FC_RP */
/* 322 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (286) */
/* 324 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 326 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 334 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 336 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 338 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 340 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 342 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 346 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 352 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 356 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 358 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 360 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (324) */
/* 362 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 364 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x6 ),	/* Offset= 6 (376) */
/* 372 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 374 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 376 */	
			0x11, 0x0,	/* FC_RP */
/* 378 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (342) */
/* 380 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 382 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 384 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 386 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 388 */	NdrFcShort( 0x2 ),	/* Offset= 2 (390) */
/* 390 */	NdrFcShort( 0x10 ),	/* 16 */
/* 392 */	NdrFcShort( 0x2f ),	/* 47 */
/* 394 */	NdrFcLong( 0x14 ),	/* 20 */
/* 398 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 400 */	NdrFcLong( 0x3 ),	/* 3 */
/* 404 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 406 */	NdrFcLong( 0x11 ),	/* 17 */
/* 410 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 412 */	NdrFcLong( 0x2 ),	/* 2 */
/* 416 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 418 */	NdrFcLong( 0x4 ),	/* 4 */
/* 422 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 424 */	NdrFcLong( 0x5 ),	/* 5 */
/* 428 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 430 */	NdrFcLong( 0xb ),	/* 11 */
/* 434 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 436 */	NdrFcLong( 0xa ),	/* 10 */
/* 440 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 442 */	NdrFcLong( 0x6 ),	/* 6 */
/* 446 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (678) */
/* 448 */	NdrFcLong( 0x7 ),	/* 7 */
/* 452 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 454 */	NdrFcLong( 0x8 ),	/* 8 */
/* 458 */	NdrFcShort( 0xfe60 ),	/* Offset= -416 (42) */
/* 460 */	NdrFcLong( 0xd ),	/* 13 */
/* 464 */	NdrFcShort( 0xff3c ),	/* Offset= -196 (268) */
/* 466 */	NdrFcLong( 0x9 ),	/* 9 */
/* 470 */	NdrFcShort( 0xff6e ),	/* Offset= -146 (324) */
/* 472 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 476 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (684) */
/* 478 */	NdrFcLong( 0x24 ),	/* 36 */
/* 482 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (692) */
/* 484 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 488 */	NdrFcShort( 0xcc ),	/* Offset= 204 (692) */
/* 490 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 494 */	NdrFcShort( 0xfc ),	/* Offset= 252 (746) */
/* 496 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 500 */	NdrFcShort( 0xfa ),	/* Offset= 250 (750) */
/* 502 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 506 */	NdrFcShort( 0xf8 ),	/* Offset= 248 (754) */
/* 508 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 512 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (758) */
/* 514 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 518 */	NdrFcShort( 0xf4 ),	/* Offset= 244 (762) */
/* 520 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 524 */	NdrFcShort( 0xf2 ),	/* Offset= 242 (766) */
/* 526 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 530 */	NdrFcShort( 0xdc ),	/* Offset= 220 (750) */
/* 532 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 536 */	NdrFcShort( 0xda ),	/* Offset= 218 (754) */
/* 538 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 542 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (770) */
/* 544 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 548 */	NdrFcShort( 0xda ),	/* Offset= 218 (766) */
/* 550 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 554 */	NdrFcShort( 0xdc ),	/* Offset= 220 (774) */
/* 556 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 560 */	NdrFcShort( 0xda ),	/* Offset= 218 (778) */
/* 562 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 566 */	NdrFcShort( 0xd8 ),	/* Offset= 216 (782) */
/* 568 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 572 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (786) */
/* 574 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 578 */	NdrFcShort( 0xdc ),	/* Offset= 220 (798) */
/* 580 */	NdrFcLong( 0x10 ),	/* 16 */
/* 584 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 586 */	NdrFcLong( 0x12 ),	/* 18 */
/* 590 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 592 */	NdrFcLong( 0x13 ),	/* 19 */
/* 596 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 598 */	NdrFcLong( 0x15 ),	/* 21 */
/* 602 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 604 */	NdrFcLong( 0x16 ),	/* 22 */
/* 608 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 610 */	NdrFcLong( 0x17 ),	/* 23 */
/* 614 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 616 */	NdrFcLong( 0xe ),	/* 14 */
/* 620 */	NdrFcShort( 0xba ),	/* Offset= 186 (806) */
/* 622 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 626 */	NdrFcShort( 0xbe ),	/* Offset= 190 (816) */
/* 628 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 632 */	NdrFcShort( 0xbc ),	/* Offset= 188 (820) */
/* 634 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 638 */	NdrFcShort( 0x70 ),	/* Offset= 112 (750) */
/* 640 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 644 */	NdrFcShort( 0x6e ),	/* Offset= 110 (754) */
/* 646 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 650 */	NdrFcShort( 0x6c ),	/* Offset= 108 (758) */
/* 652 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 656 */	NdrFcShort( 0x62 ),	/* Offset= 98 (754) */
/* 658 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 662 */	NdrFcShort( 0x5c ),	/* Offset= 92 (754) */
/* 664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x0 ),	/* Offset= 0 (668) */
/* 670 */	NdrFcLong( 0x1 ),	/* 1 */
/* 674 */	NdrFcShort( 0x0 ),	/* Offset= 0 (674) */
/* 676 */	NdrFcShort( 0xffff ),	/* Offset= -1 (675) */
/* 678 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 682 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 684 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 686 */	NdrFcShort( 0x2 ),	/* Offset= 2 (688) */
/* 688 */	
			0x12, 0x0,	/* FC_UP */
/* 690 */	NdrFcShort( 0x1b8 ),	/* Offset= 440 (1130) */
/* 692 */	
			0x12, 0x0,	/* FC_UP */
/* 694 */	NdrFcShort( 0x20 ),	/* Offset= 32 (726) */
/* 696 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 698 */	NdrFcLong( 0x2f ),	/* 47 */
/* 702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 708 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 710 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 712 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 714 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 716 */	NdrFcShort( 0x1 ),	/* 1 */
/* 718 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 720 */	NdrFcShort( 0x4 ),	/* 4 */
/* 722 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 724 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 726 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 728 */	NdrFcShort( 0x10 ),	/* 16 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0xa ),	/* Offset= 10 (742) */
/* 734 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 736 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 738 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (696) */
/* 740 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 742 */	
			0x12, 0x0,	/* FC_UP */
/* 744 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (714) */
/* 746 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 748 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 750 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 752 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 754 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 756 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 758 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 760 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 762 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 764 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 766 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 768 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 770 */	
			0x12, 0x0,	/* FC_UP */
/* 772 */	NdrFcShort( 0xffa2 ),	/* Offset= -94 (678) */
/* 774 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 776 */	NdrFcShort( 0xfd22 ),	/* Offset= -734 (42) */
/* 778 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 780 */	NdrFcShort( 0xfe00 ),	/* Offset= -512 (268) */
/* 782 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 784 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (324) */
/* 786 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 788 */	NdrFcShort( 0x2 ),	/* Offset= 2 (790) */
/* 790 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 792 */	NdrFcShort( 0x2 ),	/* Offset= 2 (794) */
/* 794 */	
			0x12, 0x0,	/* FC_UP */
/* 796 */	NdrFcShort( 0x14e ),	/* Offset= 334 (1130) */
/* 798 */	
			0x12, 0x10,	/* FC_UP [pointer_deref] */
/* 800 */	NdrFcShort( 0x2 ),	/* Offset= 2 (802) */
/* 802 */	
			0x12, 0x0,	/* FC_UP */
/* 804 */	NdrFcShort( 0x14 ),	/* Offset= 20 (824) */
/* 806 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 808 */	NdrFcShort( 0x10 ),	/* 16 */
/* 810 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 812 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 814 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 816 */	
			0x12, 0x0,	/* FC_UP */
/* 818 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (806) */
/* 820 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 822 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 824 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 826 */	NdrFcShort( 0x20 ),	/* 32 */
/* 828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 830 */	NdrFcShort( 0x0 ),	/* Offset= 0 (830) */
/* 832 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 834 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 836 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 838 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 840 */	NdrFcShort( 0xfe34 ),	/* Offset= -460 (380) */
/* 842 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 844 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x4 ),	/* 4 */
/* 848 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 854 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 856 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 858 */	NdrFcShort( 0x4 ),	/* 4 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x1 ),	/* 1 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	0x12, 0x0,	/* FC_UP */
/* 870 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (824) */
/* 872 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 874 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 876 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 878 */	NdrFcShort( 0x8 ),	/* 8 */
/* 880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x6 ),	/* Offset= 6 (888) */
/* 884 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 886 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 888 */	
			0x11, 0x0,	/* FC_RP */
/* 890 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (844) */
/* 892 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 894 */	NdrFcShort( 0x4 ),	/* 4 */
/* 896 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 900 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 902 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 904 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 906 */	NdrFcShort( 0x4 ),	/* 4 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 910 */	NdrFcShort( 0x1 ),	/* 1 */
/* 912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 916 */	0x12, 0x0,	/* FC_UP */
/* 918 */	NdrFcShort( 0xff40 ),	/* Offset= -192 (726) */
/* 920 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 922 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 924 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 930 */	NdrFcShort( 0x6 ),	/* Offset= 6 (936) */
/* 932 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 934 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 936 */	
			0x11, 0x0,	/* FC_RP */
/* 938 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (892) */
/* 940 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 944 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 946 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 948 */	NdrFcShort( 0x10 ),	/* 16 */
/* 950 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 952 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 954 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (940) */
			0x5b,		/* FC_END */
/* 958 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 960 */	NdrFcShort( 0x18 ),	/* 24 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0xa ),	/* Offset= 10 (974) */
/* 966 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 968 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 970 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (946) */
/* 972 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 974 */	
			0x11, 0x0,	/* FC_RP */
/* 976 */	NdrFcShort( 0xfd4e ),	/* Offset= -690 (286) */
/* 978 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 980 */	NdrFcShort( 0x1 ),	/* 1 */
/* 982 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 988 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 990 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 994 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 996 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 998 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1000 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1002 */	0x12, 0x0,	/* FC_UP */
/* 1004 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (978) */
/* 1006 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1008 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1010 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 1012 */	NdrFcShort( 0x2 ),	/* 2 */
/* 1014 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1020 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 1022 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1026 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1028 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1030 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1032 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1034 */	0x12, 0x0,	/* FC_UP */
/* 1036 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1010) */
/* 1038 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1040 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1042 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1046 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1052 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1054 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1058 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1060 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1062 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1064 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1066 */	0x12, 0x0,	/* FC_UP */
/* 1068 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1042) */
/* 1070 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1072 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1074 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 1076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1078 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1084 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1086 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 1088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1090 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 1092 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 1094 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1096 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1098 */	0x12, 0x0,	/* FC_UP */
/* 1100 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (1074) */
/* 1102 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 1104 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 1106 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 1108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1110 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1112 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1114 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 1116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1118 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 1120 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 1122 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 1124 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1126 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1106) */
/* 1128 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1130 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 1132 */	NdrFcShort( 0x28 ),	/* 40 */
/* 1134 */	NdrFcShort( 0xffec ),	/* Offset= -20 (1114) */
/* 1136 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1136) */
/* 1138 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1140 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1142 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1144 */	NdrFcShort( 0xfc1c ),	/* Offset= -996 (148) */
/* 1146 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1148 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1150 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1152 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0xfc08 ),	/* Offset= -1016 (140) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            },
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWGUrlReceiver, ver. 0.0,
   GUID={0x454A4044,0x16EC,0x4D64,{0x90,0x69,0xC5,0xB8,0x83,0x2B,0x7B,0x55}} */

#pragma code_seg(".orpc")
static const unsigned short IWGUrlReceiver_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72,
    102,
    132,
    168,
    204,
    240,
    276,
    306,
    342,
    378,
    414,
    450,
    486,
    522,
    558,
    594,
    630,
    666,
    702,
    738,
    774,
    810,
    846,
    882,
    918,
    954,
    990,
    1026,
    1062,
    1098,
    1134,
    1170,
    1206,
    1242,
    1278,
    1314,
    1350,
    1386
    };

static const MIDL_STUBLESS_PROXY_INFO IWGUrlReceiver_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IWGUrlReceiver_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWGUrlReceiver_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IWGUrlReceiver_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(47) _IWGUrlReceiverProxyVtbl = 
{
    &IWGUrlReceiver_ProxyInfo,
    &IID_IWGUrlReceiver,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_Url */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_Url */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::ShowAddDownloadDialog */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::ShowAddPageDownloadDialog */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_Comment */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_Comment */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_Referer */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_Referer */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::AddDownload */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_CheckExtension */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_CheckExtension */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_IgnoreSize */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_IgnoreSize */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_UseSkipExtsList */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_UseSkipExtsList */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_UIState */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_ForceSilent */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_ForceSilent */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_Cookies */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_Cookies */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_PostData */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_PostData */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_ForceSilentEx */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_ForceSilentEx */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_ForceDownloadAutoStart */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_ForceDownloadAutoStart */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_DisableMaliciousChecking */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_DisableMaliciousChecking */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_DisableURLExistsCheck */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_DisableURLExistsCheck */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_FileName */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_FileName */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_FlashVideoDownload */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_FlashVideoDownload */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_FileSize */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_FileSize */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_OriginalURL */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_OriginalURL */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::get_UserAgent */ ,
    (void *) (INT_PTR) -1 /* IWGUrlReceiver::put_UserAgent */
};


static const PRPC_STUB_FUNCTION IWGUrlReceiver_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IWGUrlReceiverStubVtbl =
{
    &IID_IWGUrlReceiver,
    &IWGUrlReceiver_ServerInfo,
    47,
    &IWGUrlReceiver_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IWGUrlListReceiver, ver. 0.0,
   GUID={0x42E8D680,0xA18B,0x4CAA,{0xAC,0xE0,0x18,0xEA,0x05,0xE4,0xA0,0x56}} */

#pragma code_seg(".orpc")
static const unsigned short IWGUrlListReceiver_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    1422,
    1458,
    132,
    168,
    1494,
    1524,
    1554,
    1590,
    1626
    };

static const MIDL_STUBLESS_PROXY_INFO IWGUrlListReceiver_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IWGUrlListReceiver_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWGUrlListReceiver_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IWGUrlListReceiver_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IWGUrlListReceiverProxyVtbl = 
{
    &IWGUrlListReceiver_ProxyInfo,
    &IID_IWGUrlListReceiver,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::get_Url */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::put_Url */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::get_Comment */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::put_Comment */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::get_Referer */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::put_Referer */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::AddUrlToList */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::ShowAddUrlListDialog */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::GetUrlListFromDocumentSelection */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::get_Cookies */ ,
    (void *) (INT_PTR) -1 /* IWGUrlListReceiver::put_Cookies */
};


static const PRPC_STUB_FUNCTION IWGUrlListReceiver_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IWGUrlListReceiverStubVtbl =
{
    &IID_IWGUrlListReceiver,
    &IWGUrlListReceiver_ServerInfo,
    18,
    &IWGUrlListReceiver_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFdmFlvDownload, ver. 0.0,
   GUID={0xE66B63B0,0x49F8,0x47E3,{0xA9,0xBA,0x79,0x92,0x87,0xB5,0x9E,0x87}} */

#pragma code_seg(".orpc")
static const unsigned short IFdmFlvDownload_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1662,
    1698
    };

static const MIDL_STUBLESS_PROXY_INFO IFdmFlvDownload_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFdmFlvDownload_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFdmFlvDownload_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFdmFlvDownload_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IFdmFlvDownloadProxyVtbl = 
{
    &IFdmFlvDownload_ProxyInfo,
    &IID_IFdmFlvDownload,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFdmFlvDownload::get_Url */ ,
    (void *) (INT_PTR) -1 /* IFdmFlvDownload::put_Url */
};


static const PRPC_STUB_FUNCTION IFdmFlvDownload_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFdmFlvDownloadStubVtbl =
{
    &IID_IFdmFlvDownload,
    &IFdmFlvDownload_ServerInfo,
    9,
    &IFdmFlvDownload_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFDM, ver. 0.0,
   GUID={0xF8FA5B48,0xB7A2,0x4BC6,{0x83,0x89,0x95,0x87,0x64,0x3A,0x46,0x60}} */

#pragma code_seg(".orpc")
static const unsigned short IFDM_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1734
    };

static const MIDL_STUBLESS_PROXY_INFO IFDM_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDM_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFDM_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDM_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IFDMProxyVtbl = 
{
    &IFDM_ProxyInfo,
    &IID_IFDM,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFDM::Shutdown */
};


static const PRPC_STUB_FUNCTION IFDM_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IFDMStubVtbl =
{
    &IID_IFDM,
    &IFDM_ServerInfo,
    8,
    &IFDM_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFDMDownload, ver. 0.0,
   GUID={0x8F2B3016,0x17D4,0x447A,{0xB2,0x07,0xFF,0xA8,0x95,0x7A,0x83,0x4A}} */

#pragma code_seg(".orpc")
static const unsigned short IFDMDownload_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    1770
    };

static const MIDL_STUBLESS_PROXY_INFO IFDMDownload_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDMDownload_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFDMDownload_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDMDownload_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IFDMDownloadProxyVtbl = 
{
    &IFDMDownload_ProxyInfo,
    &IID_IFDMDownload,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFDMDownload::get_Url */ ,
    (void *) (INT_PTR) -1 /* IFDMDownload::put_Url */ ,
    (void *) (INT_PTR) -1 /* IFDMDownload::get_DownloadText */
};


static const PRPC_STUB_FUNCTION IFDMDownload_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFDMDownloadStubVtbl =
{
    &IID_IFDMDownload,
    &IFDMDownload_ServerInfo,
    10,
    &IFDMDownload_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFDMDownloadsStat, ver. 0.0,
   GUID={0x1B26E4A2,0x7F09,0x4365,{0x9A,0xB8,0x13,0xE6,0x89,0x1E,0x42,0xCB}} */

#pragma code_seg(".orpc")
static const unsigned short IFDMDownloadsStat_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1812,
    1848,
    1890
    };

static const MIDL_STUBLESS_PROXY_INFO IFDMDownloadsStat_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDMDownloadsStat_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFDMDownloadsStat_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDMDownloadsStat_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IFDMDownloadsStatProxyVtbl = 
{
    &IFDMDownloadsStat_ProxyInfo,
    &IID_IFDMDownloadsStat,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFDMDownloadsStat::get_DownloadCount */ ,
    (void *) (INT_PTR) -1 /* IFDMDownloadsStat::get_Download */ ,
    (void *) (INT_PTR) -1 /* IFDMDownloadsStat::BuildListOfDownloads */
};


static const PRPC_STUB_FUNCTION IFDMDownloadsStat_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFDMDownloadsStatStubVtbl =
{
    &IID_IFDMDownloadsStat,
    &IFDMDownloadsStat_ServerInfo,
    10,
    &IFDMDownloadsStat_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFdmTorrentFilesRcvr, ver. 0.0,
   GUID={0x21402197,0xBB5B,0x476C,{0xAA,0x1D,0x3F,0xFE,0xD8,0xED,0x81,0x3A}} */

#pragma code_seg(".orpc")
static const unsigned short IFdmTorrentFilesRcvr_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1932,
    1968,
    2004
    };

static const MIDL_STUBLESS_PROXY_INFO IFdmTorrentFilesRcvr_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFdmTorrentFilesRcvr_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFdmTorrentFilesRcvr_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFdmTorrentFilesRcvr_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IFdmTorrentFilesRcvrProxyVtbl = 
{
    &IFdmTorrentFilesRcvr_ProxyInfo,
    &IID_IFdmTorrentFilesRcvr,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFdmTorrentFilesRcvr::CreateBtDownload */ ,
    (void *) (INT_PTR) -1 /* IFdmTorrentFilesRcvr::get_ForceSilent */ ,
    (void *) (INT_PTR) -1 /* IFdmTorrentFilesRcvr::put_ForceSilent */
};


static const PRPC_STUB_FUNCTION IFdmTorrentFilesRcvr_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFdmTorrentFilesRcvrStubVtbl =
{
    &IID_IFdmTorrentFilesRcvr,
    &IFdmTorrentFilesRcvr_ServerInfo,
    10,
    &IFdmTorrentFilesRcvr_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFDMFlashVideoDownloads, ver. 0.0,
   GUID={0x0DC81A74,0x1FBD,0x4EF6,{0x82,0xB2,0xDE,0x3F,0xA0,0x5E,0x82,0x33}} */

#pragma code_seg(".orpc")
static const unsigned short IFDMFlashVideoDownloads_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    2040,
    2076,
    2118,
    2154,
    2196
    };

static const MIDL_STUBLESS_PROXY_INFO IFDMFlashVideoDownloads_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDMFlashVideoDownloads_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFDMFlashVideoDownloads_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFDMFlashVideoDownloads_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(12) _IFDMFlashVideoDownloadsProxyVtbl = 
{
    &IFDMFlashVideoDownloads_ProxyInfo,
    &IID_IFDMFlashVideoDownloads,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFDMFlashVideoDownloads::ProcessIeDocument */ ,
    (void *) (INT_PTR) -1 /* IFDMFlashVideoDownloads::ProcessHtml */ ,
    (void *) (INT_PTR) -1 /* IFDMFlashVideoDownloads::CreateFromUrl */ ,
    (void *) (INT_PTR) -1 /* IFDMFlashVideoDownloads::ShowAddDownloadDialog */ ,
    (void *) (INT_PTR) -1 /* IFDMFlashVideoDownloads::ShowAddDownloadsDialog */
};


static const PRPC_STUB_FUNCTION IFDMFlashVideoDownloads_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFDMFlashVideoDownloadsStubVtbl =
{
    &IID_IFDMFlashVideoDownloads,
    &IFDMFlashVideoDownloads_ServerInfo,
    12,
    &IFDMFlashVideoDownloads_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFdmUiWindow, ver. 0.0,
   GUID={0x4FEB1BAD,0x35AD,0x4a08,{0xB6,0xEC,0xE6,0xD8,0x32,0xF1,0xED,0x4D}} */

#pragma code_seg(".orpc")
static const unsigned short IFdmUiWindow_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    1812,
    2238
    };

static const MIDL_STUBLESS_PROXY_INFO IFdmUiWindow_ProxyInfo =
    {
    &Object_StubDesc,
    Fdm__MIDL_ProcFormatString.Format,
    &IFdmUiWindow_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFdmUiWindow_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    Fdm__MIDL_ProcFormatString.Format,
    &IFdmUiWindow_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IFdmUiWindowProxyVtbl = 
{
    &IFdmUiWindow_ProxyInfo,
    &IID_IFdmUiWindow,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch::GetTypeInfoCount */ ,
    0 /* IDispatch::GetTypeInfo */ ,
    0 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFdmUiWindow::get_Handle */ ,
    (void *) (INT_PTR) -1 /* IFdmUiWindow::WaitForWindowCreation */
};


static const PRPC_STUB_FUNCTION IFdmUiWindow_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFdmUiWindowStubVtbl =
{
    &IID_IFdmUiWindow,
    &IFdmUiWindow_ServerInfo,
    9,
    &IFdmUiWindow_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    Fdm__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x700022b, /* MIDL Version 7.0.555 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * const _Fdm_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFDMDownloadProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWGUrlReceiverProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFDMProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFDMFlashVideoDownloadsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWGUrlListReceiverProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFdmTorrentFilesRcvrProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFDMDownloadsStatProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFdmUiWindowProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFdmFlvDownloadProxyVtbl,
    0
};

const CInterfaceStubVtbl * const _Fdm_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFDMDownloadStubVtbl,
    ( CInterfaceStubVtbl *) &_IWGUrlReceiverStubVtbl,
    ( CInterfaceStubVtbl *) &_IFDMStubVtbl,
    ( CInterfaceStubVtbl *) &_IFDMFlashVideoDownloadsStubVtbl,
    ( CInterfaceStubVtbl *) &_IWGUrlListReceiverStubVtbl,
    ( CInterfaceStubVtbl *) &_IFdmTorrentFilesRcvrStubVtbl,
    ( CInterfaceStubVtbl *) &_IFDMDownloadsStatStubVtbl,
    ( CInterfaceStubVtbl *) &_IFdmUiWindowStubVtbl,
    ( CInterfaceStubVtbl *) &_IFdmFlvDownloadStubVtbl,
    0
};

PCInterfaceName const _Fdm_InterfaceNamesList[] = 
{
    "IFDMDownload",
    "IWGUrlReceiver",
    "IFDM",
    "IFDMFlashVideoDownloads",
    "IWGUrlListReceiver",
    "IFdmTorrentFilesRcvr",
    "IFDMDownloadsStat",
    "IFdmUiWindow",
    "IFdmFlvDownload",
    0
};

const IID *  const _Fdm_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _Fdm_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Fdm, pIID, n)

int __stdcall _Fdm_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _Fdm, 9, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _Fdm, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _Fdm, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _Fdm, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _Fdm, 9, *pIndex )
    
}

const ExtendedProxyFileInfo Fdm_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Fdm_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Fdm_StubVtblList,
    (const PCInterfaceName * ) & _Fdm_InterfaceNamesList,
    (const IID ** ) & _Fdm_BaseIIDList,
    & _Fdm_IID_Lookup, 
    9,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

