

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Mon Feb 29 17:42:16 2016
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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __iecooks_h__
#define __iecooks_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFDMIEBHO_FWD_DEFINED__
#define __IFDMIEBHO_FWD_DEFINED__
typedef interface IFDMIEBHO IFDMIEBHO;
#endif 	/* __IFDMIEBHO_FWD_DEFINED__ */


#ifndef __IFDMIEStat_FWD_DEFINED__
#define __IFDMIEStat_FWD_DEFINED__
typedef interface IFDMIEStat IFDMIEStat;
#endif 	/* __IFDMIEStat_FWD_DEFINED__ */


#ifndef __FDMIEBHO_FWD_DEFINED__
#define __FDMIEBHO_FWD_DEFINED__

#ifdef __cplusplus
typedef class FDMIEBHO FDMIEBHO;
#else
typedef struct FDMIEBHO FDMIEBHO;
#endif /* __cplusplus */

#endif 	/* __FDMIEBHO_FWD_DEFINED__ */


#ifndef __FDMIEStat_FWD_DEFINED__
#define __FDMIEStat_FWD_DEFINED__

#ifdef __cplusplus
typedef class FDMIEStat FDMIEStat;
#else
typedef struct FDMIEStat FDMIEStat;
#endif /* __cplusplus */

#endif 	/* __FDMIEStat_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFDMIEBHO_INTERFACE_DEFINED__
#define __IFDMIEBHO_INTERFACE_DEFINED__

/* interface IFDMIEBHO */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFDMIEBHO;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40D3F599-74F0-44D3-B059-76C0F12C0D6E")
    IFDMIEBHO : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ProgressChange( 
            long Progress,
            long ProgressMax) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeNavigate2( 
            IDispatch *__MIDL__IFDMIEBHO0000,
            VARIANT *url,
            VARIANT *flags,
            VARIANT *tfn,
            VARIANT *pd,
            VARIANT *headers,
            VARIANT_BOOL *bCancel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadBegin( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DownloadComplete( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE DocumentComplete( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE WindowStateChanged( 
            DWORD dwFlags,
            DWORD dwValidFlagsMask) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NavigateComplete2( 
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StatusTextChange( 
            /* [in] */ BSTR bstrText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFDMIEBHOVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFDMIEBHO * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFDMIEBHO * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFDMIEBHO * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFDMIEBHO * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFDMIEBHO * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFDMIEBHO * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFDMIEBHO * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProgressChange )( 
            IFDMIEBHO * This,
            long Progress,
            long ProgressMax);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BeforeNavigate2 )( 
            IFDMIEBHO * This,
            IDispatch *__MIDL__IFDMIEBHO0000,
            VARIANT *url,
            VARIANT *flags,
            VARIANT *tfn,
            VARIANT *pd,
            VARIANT *headers,
            VARIANT_BOOL *bCancel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadBegin )( 
            IFDMIEBHO * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DownloadComplete )( 
            IFDMIEBHO * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DocumentComplete )( 
            IFDMIEBHO * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WindowStateChanged )( 
            IFDMIEBHO * This,
            DWORD dwFlags,
            DWORD dwValidFlagsMask);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NavigateComplete2 )( 
            IFDMIEBHO * This,
            /* [in] */ IDispatch *pDisp,
            /* [in] */ VARIANT *URL);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *StatusTextChange )( 
            IFDMIEBHO * This,
            /* [in] */ BSTR bstrText);
        
        END_INTERFACE
    } IFDMIEBHOVtbl;

    interface IFDMIEBHO
    {
        CONST_VTBL struct IFDMIEBHOVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFDMIEBHO_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFDMIEBHO_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFDMIEBHO_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFDMIEBHO_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFDMIEBHO_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFDMIEBHO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFDMIEBHO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFDMIEBHO_ProgressChange(This,Progress,ProgressMax)	\
    ( (This)->lpVtbl -> ProgressChange(This,Progress,ProgressMax) ) 

#define IFDMIEBHO_BeforeNavigate2(This,__MIDL__IFDMIEBHO0000,url,flags,tfn,pd,headers,bCancel)	\
    ( (This)->lpVtbl -> BeforeNavigate2(This,__MIDL__IFDMIEBHO0000,url,flags,tfn,pd,headers,bCancel) ) 

#define IFDMIEBHO_DownloadBegin(This)	\
    ( (This)->lpVtbl -> DownloadBegin(This) ) 

#define IFDMIEBHO_DownloadComplete(This)	\
    ( (This)->lpVtbl -> DownloadComplete(This) ) 

#define IFDMIEBHO_DocumentComplete(This,pDisp,URL)	\
    ( (This)->lpVtbl -> DocumentComplete(This,pDisp,URL) ) 

#define IFDMIEBHO_WindowStateChanged(This,dwFlags,dwValidFlagsMask)	\
    ( (This)->lpVtbl -> WindowStateChanged(This,dwFlags,dwValidFlagsMask) ) 

#define IFDMIEBHO_NavigateComplete2(This,pDisp,URL)	\
    ( (This)->lpVtbl -> NavigateComplete2(This,pDisp,URL) ) 

#define IFDMIEBHO_StatusTextChange(This,bstrText)	\
    ( (This)->lpVtbl -> StatusTextChange(This,bstrText) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFDMIEBHO_INTERFACE_DEFINED__ */


#ifndef __IFDMIEStat_INTERFACE_DEFINED__
#define __IFDMIEStat_INTERFACE_DEFINED__

/* interface IFDMIEStat */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IFDMIEStat;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("64844F4D-492F-429E-881C-D7F106259738")
    IFDMIEStat : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DownloadCount( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFDMIEStatVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFDMIEStat * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFDMIEStat * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFDMIEStat * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFDMIEStat * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFDMIEStat * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFDMIEStat * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFDMIEStat * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DownloadCount )( 
            IFDMIEStat * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IFDMIEStatVtbl;

    interface IFDMIEStat
    {
        CONST_VTBL struct IFDMIEStatVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFDMIEStat_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFDMIEStat_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFDMIEStat_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFDMIEStat_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFDMIEStat_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFDMIEStat_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFDMIEStat_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFDMIEStat_get_DownloadCount(This,pVal)	\
    ( (This)->lpVtbl -> get_DownloadCount(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFDMIEStat_INTERFACE_DEFINED__ */



#ifndef __IEFDMBHOLib_LIBRARY_DEFINED__
#define __IEFDMBHOLib_LIBRARY_DEFINED__

/* library IEFDMBHOLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_IEFDMBHOLib;

EXTERN_C const CLSID CLSID_FDMIEBHO;

#ifdef __cplusplus

class DECLSPEC_UUID("CC59E0F9-7E43-44FA-9FAA-8377850BF205")
FDMIEBHO;
#endif

EXTERN_C const CLSID CLSID_FDMIEStat;

#ifdef __cplusplus

class DECLSPEC_UUID("D4D6EAB8-009E-4EED-814E-4891D7E1741B")
FDMIEStat;
#endif
#endif /* __IEFDMBHOLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


