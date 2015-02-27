/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

 

#pragma warning( disable: 4049 )  

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __fuminterfaces_h__
#define __fuminterfaces_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

 

#ifndef __IUploadPackage_FWD_DEFINED__
#define __IUploadPackage_FWD_DEFINED__
typedef interface IUploadPackage IUploadPackage;
#endif 	

#ifndef __IUploader_FWD_DEFINED__
#define __IUploader_FWD_DEFINED__
typedef interface IUploader IUploader;
#endif 	

#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IUploadPackage_INTERFACE_DEFINED__
#define __IUploadPackage_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IUploadPackage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D650F6EB-68C1-4ac9-A6F5-8BF7D469815A")
    IUploadPackage : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE Add( 
             BSTR bstrPathName) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_Name( 
             BSTR *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_Name( 
             BSTR newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetFileCount( 
             long *pCount) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetFilePath( 
             long nIndex,
             BSTR *pbstrPathName) = 0;
        
    };
    
#else 	

    typedef struct IUploadPackageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUploadPackage * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUploadPackage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUploadPackage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUploadPackage * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUploadPackage * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUploadPackage * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUploadPackage * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
         HRESULT ( STDMETHODCALLTYPE *Add )( 
            IUploadPackage * This,
             BSTR bstrPathName);
        
         HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IUploadPackage * This,
             BSTR *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            IUploadPackage * This,
             BSTR newVal);
        
         HRESULT ( STDMETHODCALLTYPE *GetFileCount )( 
            IUploadPackage * This,
             long *pCount);
        
         HRESULT ( STDMETHODCALLTYPE *GetFilePath )( 
            IUploadPackage * This,
             long nIndex,
             BSTR *pbstrPathName);
        
        END_INTERFACE
    } IUploadPackageVtbl;

    interface IUploadPackage
    {
        CONST_VTBL struct IUploadPackageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IUploadPackage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUploadPackage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUploadPackage_Release(This)	\
    (This)->lpVtbl -> Release(This)

#define IUploadPackage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUploadPackage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUploadPackage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUploadPackage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#define IUploadPackage_Add(This,bstrPathName)	\
    (This)->lpVtbl -> Add(This,bstrPathName)

#define IUploadPackage_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IUploadPackage_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define IUploadPackage_GetFileCount(This,pCount)	\
    (This)->lpVtbl -> GetFileCount(This,pCount)

#define IUploadPackage_GetFilePath(This,nIndex,pbstrPathName)	\
    (This)->lpVtbl -> GetFilePath(This,nIndex,pbstrPathName)

#endif 

#endif 	

 HRESULT STDMETHODCALLTYPE IUploadPackage_Add_Proxy( 
    IUploadPackage * This,
     BSTR bstrPathName);

void __RPC_STUB IUploadPackage_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

 HRESULT STDMETHODCALLTYPE IUploadPackage_get_Name_Proxy( 
    IUploadPackage * This,
     BSTR *pVal);

void __RPC_STUB IUploadPackage_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

 HRESULT STDMETHODCALLTYPE IUploadPackage_put_Name_Proxy( 
    IUploadPackage * This,
     BSTR newVal);

void __RPC_STUB IUploadPackage_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

 HRESULT STDMETHODCALLTYPE IUploadPackage_GetFileCount_Proxy( 
    IUploadPackage * This,
     long *pCount);

void __RPC_STUB IUploadPackage_GetFileCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

 HRESULT STDMETHODCALLTYPE IUploadPackage_GetFilePath_Proxy( 
    IUploadPackage * This,
     long nIndex,
     BSTR *pbstrPathName);

void __RPC_STUB IUploadPackage_GetFilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

#endif 	

#ifndef __IUploader_INTERFACE_DEFINED__
#define __IUploader_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IUploader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17462C30-17BA-4e40-B722-6E803A0618BB")
    IUploader : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE CreateUpload( 
             IUploadPackage *pPkg,
             BOOL bDialogReq,
             long *pUplId) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetUploadTargetUrl( 
             long lId,
             BSTR *pbstrUrl) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE GetUploadPackageName( 
             long lId,
             BSTR *pbstrName) = 0;
        
    };
    
#else 	

    typedef struct IUploaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUploader * This,
             REFIID riid,
             void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUploader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUploader * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUploader * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUploader * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUploader * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUploader * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
         HRESULT ( STDMETHODCALLTYPE *CreateUpload )( 
            IUploader * This,
             IUploadPackage *pPkg,
             BOOL bDialogReq,
             long *pUplId);
        
         HRESULT ( STDMETHODCALLTYPE *GetUploadTargetUrl )( 
            IUploader * This,
             long lId,
             BSTR *pbstrUrl);
        
         HRESULT ( STDMETHODCALLTYPE *GetUploadPackageName )( 
            IUploader * This,
             long lId,
             BSTR *pbstrName);
        
        END_INTERFACE
    } IUploaderVtbl;

    interface IUploader
    {
        CONST_VTBL struct IUploaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IUploader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUploader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUploader_Release(This)	\
    (This)->lpVtbl -> Release(This)

#define IUploader_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUploader_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUploader_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUploader_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#define IUploader_CreateUpload(This,pPkg,bDialogReq,pUplId)	\
    (This)->lpVtbl -> CreateUpload(This,pPkg,bDialogReq,pUplId)

#define IUploader_GetUploadTargetUrl(This,lId,pbstrUrl)	\
    (This)->lpVtbl -> GetUploadTargetUrl(This,lId,pbstrUrl)

#define IUploader_GetUploadPackageName(This,lId,pbstrName)	\
    (This)->lpVtbl -> GetUploadPackageName(This,lId,pbstrName)

#endif 

#endif 	

 HRESULT STDMETHODCALLTYPE IUploader_CreateUpload_Proxy( 
    IUploader * This,
     IUploadPackage *pPkg,
     BOOL bDialogReq,
     long *pUplId);

void __RPC_STUB IUploader_CreateUpload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

 HRESULT STDMETHODCALLTYPE IUploader_GetUploadTargetUrl_Proxy( 
    IUploader * This,
     long lId,
     BSTR *pbstrUrl);

void __RPC_STUB IUploader_GetUploadTargetUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

 HRESULT STDMETHODCALLTYPE IUploader_GetUploadPackageName_Proxy( 
    IUploader * This,
     long lId,
     BSTR *pbstrName);

void __RPC_STUB IUploader_GetUploadPackageName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);

#endif 	

#ifndef __FumInterfacesLib_LIBRARY_DEFINED__
#define __FumInterfacesLib_LIBRARY_DEFINED__

 

EXTERN_C const IID LIBID_FumInterfacesLib;
#endif 

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

#ifdef __cplusplus
}
#endif

#endif

