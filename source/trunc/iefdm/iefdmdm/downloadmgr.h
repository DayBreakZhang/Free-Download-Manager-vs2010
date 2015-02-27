/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#pragma warning( disable: 4049 )  

 

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif 

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif 

#ifndef __downloadmgr_h__
#define __downloadmgr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

 

#ifndef __IDownloadManager_FWD_DEFINED__
#define __IDownloadManager_FWD_DEFINED__
typedef interface IDownloadManager IDownloadManager;
#endif 	

#include "unknwn.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

 

#pragma comment(lib,"uuid.lib")

DEFINE_GUID(IID_IDownloadManager, 0x988934a4, 0x064b, 0x11d3, 0xbb, 0x80, 0x0, 0x10, 0x4b, 0x35, 0xe7, 0xf9);
#define SID_SDownloadManager IID_IDownloadManager

extern RPC_IF_HANDLE __MIDL_itf_downloadmgr_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_downloadmgr_0000_v0_0_s_ifspec;

#ifndef __IDownloadManager_INTERFACE_DEFINED__
#define __IDownloadManager_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IDownloadManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("988934A4-064B-11D3-BB80-00104B35E7F9")
    IDownloadManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Download( 
             IMoniker *pmk,
             IBindCtx *pbc,
             DWORD dwBindVerb,
             LONG grfBINDF,
             BINDINFO *pBindInfo,
             LPCOLESTR pszHeaders,
             LPCOLESTR pszRedir,
             UINT uiCP) = 0;
        
    };
    
#else 	

    typedef struct IDownloadManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDownloadManager * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDownloadManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDownloadManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *Download )( 
            IDownloadManager * This,
             IMoniker *pmk,
             IBindCtx *pbc,
             DWORD dwBindVerb,
             LONG grfBINDF,
             BINDINFO *pBindInfo,
             LPCOLESTR pszHeaders,
             LPCOLESTR pszRedir,
             UINT uiCP);
        
        END_INTERFACE
    } IDownloadManagerVtbl;

    interface IDownloadManager
    {
        CONST_VTBL struct IDownloadManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IDownloadManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDownloadManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDownloadManager_Release(This)	\
    (This)->lpVtbl -> Release(This)

#define IDownloadManager_Download(This,pmk,pbc,dwBindVerb,grfBINDF,pBindInfo,pszHeaders,pszRedir,uiCP)	\
    (This)->lpVtbl -> Download(This,pmk,pbc,dwBindVerb,grfBINDF,pBindInfo,pszHeaders,pszRedir,uiCP)

#endif 

#endif 	

HRESULT STDMETHODCALLTYPE IDownloadManager_Download_Proxy( 
    IDownloadManager * This,
     IMoniker *pmk,
     IBindCtx *pbc,
     DWORD dwBindVerb,
     LONG grfBINDF,
     BINDINFO *pBindInfo,
     LPCOLESTR pszHeaders,
     LPCOLESTR pszRedir,
     UINT uiCP);

void __RPC_STUB IDownloadManager_Download_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

#endif 	

#ifdef __cplusplus
}
#endif

#endif

