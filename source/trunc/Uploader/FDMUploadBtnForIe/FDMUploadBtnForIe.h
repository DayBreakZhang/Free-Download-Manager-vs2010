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

#ifndef __FDMUploadBtnForIe_h__
#define __FDMUploadBtnForIe_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

 

#ifndef __IFDMUploadBtnForIe_FWD_DEFINED__
#define __IFDMUploadBtnForIe_FWD_DEFINED__
typedef interface IFDMUploadBtnForIe IFDMUploadBtnForIe;
#endif 	

#ifndef __FDMUploadBtnForIe_FWD_DEFINED__
#define __FDMUploadBtnForIe_FWD_DEFINED__

#ifdef __cplusplus
typedef class FDMUploadBtnForIe FDMUploadBtnForIe;
#else
typedef struct FDMUploadBtnForIe FDMUploadBtnForIe;
#endif 

#endif 	

#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

#ifndef __IFDMUploadBtnForIe_INTERFACE_DEFINED__
#define __IFDMUploadBtnForIe_INTERFACE_DEFINED__

 

EXTERN_C const IID IID_IFDMUploadBtnForIe;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FA4FD29A-921D-435D-96F9-0CAE6F6CE028")
    IFDMUploadBtnForIe : public IDispatch
    {
    public:
    };
    
#else 	

    typedef struct IFDMUploadBtnForIeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFDMUploadBtnForIe * This,
             REFIID riid,
             
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFDMUploadBtnForIe * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFDMUploadBtnForIe * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFDMUploadBtnForIe * This,
             UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFDMUploadBtnForIe * This,
             UINT iTInfo,
             LCID lcid,
             ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFDMUploadBtnForIe * This,
             REFIID riid,
             LPOLESTR *rgszNames,
             UINT cNames,
             LCID lcid,
             DISPID *rgDispId);
        
         HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFDMUploadBtnForIe * This,
             DISPID dispIdMember,
             REFIID riid,
             LCID lcid,
             WORD wFlags,
             DISPPARAMS *pDispParams,
             VARIANT *pVarResult,
             EXCEPINFO *pExcepInfo,
             UINT *puArgErr);
        
        END_INTERFACE
    } IFDMUploadBtnForIeVtbl;

    interface IFDMUploadBtnForIe
    {
        CONST_VTBL struct IFDMUploadBtnForIeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS

#define IFDMUploadBtnForIe_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFDMUploadBtnForIe_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFDMUploadBtnForIe_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 

#define IFDMUploadBtnForIe_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFDMUploadBtnForIe_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFDMUploadBtnForIe_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFDMUploadBtnForIe_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif 

#endif 	

#endif 	

#ifndef __FDMUPLOADBTNFORIELib_LIBRARY_DEFINED__
#define __FDMUPLOADBTNFORIELib_LIBRARY_DEFINED__

 

EXTERN_C const IID LIBID_FDMUPLOADBTNFORIELib;

EXTERN_C const CLSID CLSID_FDMUploadBtnForIe;

#ifdef __cplusplus

class DECLSPEC_UUID("FD4E2FF8-973C-4A19-89BD-8E86B3CFCFE1")
FDMUploadBtnForIe;
#endif
#endif 

#ifdef __cplusplus
}
#endif

#endif

