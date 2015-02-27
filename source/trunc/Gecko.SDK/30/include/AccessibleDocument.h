

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Apr 28 18:11:01 2014
 */
/* Compiler settings for c:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/other-licenses/ia2/AccessibleDocument.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, app_config, c_ext, robust
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

#ifndef __AccessibleDocument_h__
#define __AccessibleDocument_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAccessibleDocument_FWD_DEFINED__
#define __IAccessibleDocument_FWD_DEFINED__
typedef interface IAccessibleDocument IAccessibleDocument;

#endif 	/* __IAccessibleDocument_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oaidl.h"
#include "oleacc.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAccessibleDocument_INTERFACE_DEFINED__
#define __IAccessibleDocument_INTERFACE_DEFINED__

/* interface IAccessibleDocument */
/* [uuid][object] */ 


EXTERN_C const IID IID_IAccessibleDocument;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C48C7FCF-4AB5-4056-AFA6-902D6E1D1149")
    IAccessibleDocument : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_anchorTarget( 
            /* [retval][out] */ IUnknown **accessible) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAccessibleDocumentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAccessibleDocument * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAccessibleDocument * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAccessibleDocument * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_anchorTarget )( 
            IAccessibleDocument * This,
            /* [retval][out] */ IUnknown **accessible);
        
        END_INTERFACE
    } IAccessibleDocumentVtbl;

    interface IAccessibleDocument
    {
        CONST_VTBL struct IAccessibleDocumentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccessibleDocument_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAccessibleDocument_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAccessibleDocument_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAccessibleDocument_get_anchorTarget(This,accessible)	\
    ( (This)->lpVtbl -> get_anchorTarget(This,accessible) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAccessibleDocument_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


