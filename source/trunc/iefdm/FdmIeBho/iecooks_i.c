

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Nov 24 21:33:01 2014
 */
/* Compiler settings for iecooks.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IFDMIEBHO,0x40D3F599,0x74F0,0x44D3,0xB0,0x59,0x76,0xC0,0xF1,0x2C,0x0D,0x6E);


MIDL_DEFINE_GUID(IID, IID_IFDMIEStat,0x64844F4D,0x492F,0x429E,0x88,0x1C,0xD7,0xF1,0x06,0x25,0x97,0x38);


MIDL_DEFINE_GUID(IID, LIBID_IEFDMBHOLib,0x351A47E5,0xB59E,0x4CF2,0xB8,0x1A,0xB6,0x51,0xD7,0x5F,0xE9,0x44);


MIDL_DEFINE_GUID(CLSID, CLSID_FDMIEBHO,0xCC59E0F9,0x7E43,0x44FA,0x9F,0xAA,0x83,0x77,0x85,0x0B,0xF2,0x05);


MIDL_DEFINE_GUID(CLSID, CLSID_FDMIEStat,0xD4D6EAB8,0x009E,0x4EED,0x81,0x4E,0x48,0x91,0xD7,0xE1,0x74,0x1B);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



