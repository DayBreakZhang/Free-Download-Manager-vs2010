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

#ifndef __UploadShellExt_h__
#define __UploadShellExt_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

 

#ifndef __IFdmUplShlExt_FWD_DEFINED__
#define __IFdmUplShlExt_FWD_DEFINED__
typedef interface IFdmUplShlExt IFdmUplShlExt;
#endif 	

#ifndef __IFdmUplSendToShlExt_FWD_DEFINED__
#define __IFdmUplSendToShlExt_FWD_DEFINED__
typedef interface IFdmUplSendToShlExt IFdmUplSendToShlExt;
#endif 	

#ifndef __IFdmUplShellExts_FWD_DEFINED__
#define __IFdmUplShellExts_FWD_DEFINED__
typedef interface IFdmUplShellExts IFdmUplShellExts;
#endif 	

#ifndef __FdmUplShlExt_FWD_DEFINED__
#define __FdmUplShlExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class FdmUplShlExt FdmUplShlExt;
#else
typedef struct FdmUplShlExt FdmUplShlExt;
#endif 

#endif 	

#ifndef __FdmUplSendToShlExt_FWD_DEFINED__
#define __FdmUplSendToShlExt_FWD_DEFINED__

#ifdef __cplusplus
typedef class FdmUplSendToShlExt FdmUplSendToShlExt;
#else
typedef struct FdmUplSendToShlExt FdmUplSendToShlExt;
#endif 

#endif 	

#ifndef __FdmUplShellExts_FWD_DEFINED__
#define __FdmUplShellExts_FWD_DEFINED__

#ifdef __cplusplus
typedef class FdmUplShellExts FdmUplShellExts;
#else
typedef struct FdmUplShellExts FdmUplShellExts;
#endif 

#endif 	

#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

#ifndef __IFdmUplShlExt_INTERFACE_DEFINED__
#define __IFdmUplShlExt_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IFdmUplShlExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FC2E7A4-2324-4D35-83B4-B7A93A5D7056")
    IFdmUplShlExt : public IDispatch
    {
    public:
    };
    
#else 	

    typedef struct IFdmUplShlExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFdmUplShlExt * This,
             REFIID riid,
             
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFdmUplShlExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFdmUplShlExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFdmUplShlExt * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFdmUplShlExt * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFdmUplShlExt * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFdmUplShlExt * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
        END_INTERFACE
    } IFdmUplShlExtVtbl;

    interface IFdmUplShlExt
    {
        CONST_VTBL struct IFdmUplShlExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IFdmUplShlExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFdmUplShlExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFdmUplShlExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define IFdmUplShlExt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFdmUplShlExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFdmUplShlExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFdmUplShlExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif 

#endif 	

#endif 	

#ifndef __IFdmUplSendToShlExt_INTERFACE_DEFINED__
#define __IFdmUplSendToShlExt_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IFdmUplSendToShlExt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5DCFA753-37FC-4EF7-8578-0706E58CB7B1")
    IFdmUplSendToShlExt : public IDispatch
    {
    public:
    };
    
#else 	

    typedef struct IFdmUplSendToShlExtVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFdmUplSendToShlExt * This,
             REFIID riid,
             
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFdmUplSendToShlExt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFdmUplSendToShlExt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFdmUplSendToShlExt * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFdmUplSendToShlExt * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFdmUplSendToShlExt * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFdmUplSendToShlExt * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
        END_INTERFACE
    } IFdmUplSendToShlExtVtbl;

    interface IFdmUplSendToShlExt
    {
        CONST_VTBL struct IFdmUplSendToShlExtVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IFdmUplSendToShlExt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFdmUplSendToShlExt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFdmUplSendToShlExt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define IFdmUplSendToShlExt_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFdmUplSendToShlExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFdmUplSendToShlExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFdmUplSendToShlExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif 

#endif 	

#endif 	

#ifndef __IFdmUplShellExts_INTERFACE_DEFINED__
#define __IFdmUplShellExts_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IFdmUplShellExts;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FD5847BA-895F-4B07-9850-CED00297F6B6")
    IFdmUplShellExts : public IDispatch
    {
    public:
        virtual  HRESULT STDMETHODCALLTYPE get_ShowInExplorerContextMenu( 
             BOOL *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ShowInExplorerContextMenu( 
             BOOL newVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE get_ShowInSendToContextMenu( 
             BOOL *pVal) = 0;
        
        virtual  HRESULT STDMETHODCALLTYPE put_ShowInSendToContextMenu( 
             BOOL newVal) = 0;
        
    };
    
#else 	

    typedef struct IFdmUplShellExtsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFdmUplShellExts * This,
             REFIID riid,
             
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFdmUplShellExts * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFdmUplShellExts * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFdmUplShellExts * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFdmUplShellExts * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFdmUplShellExts * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFdmUplShellExts * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
         HRESULT ( STDMETHODCALLTYPE *get_ShowInExplorerContextMenu )( 
            IFdmUplShellExts * This,
             BOOL *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_ShowInExplorerContextMenu )( 
            IFdmUplShellExts * This,
             BOOL newVal);
        
         HRESULT ( STDMETHODCALLTYPE *get_ShowInSendToContextMenu )( 
            IFdmUplShellExts * This,
             BOOL *pVal);
        
         HRESULT ( STDMETHODCALLTYPE *put_ShowInSendToContextMenu )( 
            IFdmUplShellExts * This,
             BOOL newVal);
        
        END_INTERFACE
    } IFdmUplShellExtsVtbl;

    interface IFdmUplShellExts
    {
        CONST_VTBL struct IFdmUplShellExtsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IFdmUplShellExts_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFdmUplShellExts_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFdmUplShellExts_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define IFdmUplShellExts_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFdmUplShellExts_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFdmUplShellExts_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFdmUplShellExts_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#define IFdmUplShellExts_get_ShowInExplorerContextMenu(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowInExplorerContextMenu(This,pVal) ) 

#define IFdmUplShellExts_put_ShowInExplorerContextMenu(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowInExplorerContextMenu(This,newVal) ) 

#define IFdmUplShellExts_get_ShowInSendToContextMenu(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowInSendToContextMenu(This,pVal) ) 

#define IFdmUplShellExts_put_ShowInSendToContextMenu(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowInSendToContextMenu(This,newVal) ) 

#endif 

#endif 	

#endif 	

#ifndef __UPLOADSHELLEXTLib_LIBRARY_DEFINED__
#define __UPLOADSHELLEXTLib_LIBRARY_DEFINED__

 

EXTERN_C const IID LIBID_UPLOADSHELLEXTLib;

EXTERN_C const CLSID CLSID_FdmUplShlExt;

#ifdef __cplusplus

class DECLSPEC_UUID("F49C55B9-D417-45A1-A6E7-D6E057946280")
FdmUplShlExt;
#endif

EXTERN_C const CLSID CLSID_FdmUplSendToShlExt;

#ifdef __cplusplus

class DECLSPEC_UUID("8D97E4FE-18C2-48D4-85E7-31D29576F735")
FdmUplSendToShlExt;
#endif

EXTERN_C const CLSID CLSID_FdmUplShellExts;

#ifdef __cplusplus

class DECLSPEC_UUID("AF39CEB8-76E0-4177-BD37-54A87F426224")
FdmUplShellExts;
#endif
#endif 

#ifdef __cplusplus
}
#endif

#endif

