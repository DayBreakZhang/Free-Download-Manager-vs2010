

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Apr 28 18:11:05 2014
 */
/* Compiler settings for c:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/other-licenses/ia2/AccessibleText2.idl:
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

#ifndef __AccessibleText2_h__
#define __AccessibleText2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAccessibleText2_FWD_DEFINED__
#define __IAccessibleText2_FWD_DEFINED__
typedef interface IAccessibleText2 IAccessibleText2;

#endif 	/* __IAccessibleText2_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oaidl.h"
#include "oleacc.h"
#include "IA2CommonTypes.h"
#include "AccessibleText.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAccessibleText2_INTERFACE_DEFINED__
#define __IAccessibleText2_INTERFACE_DEFINED__

/* interface IAccessibleText2 */
/* [uuid][object] */ 


EXTERN_C const IID IID_IAccessibleText2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9690A9CC-5C80-4DF5-852E-2D5AE4189A54")
    IAccessibleText2 : public IAccessibleText
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_attributeRange( 
            /* [in] */ long offset,
            /* [in] */ BSTR filter,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *attributeValues) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAccessibleText2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAccessibleText2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAccessibleText2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAccessibleText2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *addSelection )( 
            IAccessibleText2 * This,
            /* [in] */ long startOffset,
            /* [in] */ long endOffset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_attributes )( 
            IAccessibleText2 * This,
            /* [in] */ long offset,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *textAttributes);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_caretOffset )( 
            IAccessibleText2 * This,
            /* [retval][out] */ long *offset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_characterExtents )( 
            IAccessibleText2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2CoordinateType coordType,
            /* [out] */ long *x,
            /* [out] */ long *y,
            /* [out] */ long *width,
            /* [retval][out] */ long *height);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_nSelections )( 
            IAccessibleText2 * This,
            /* [retval][out] */ long *nSelections);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_offsetAtPoint )( 
            IAccessibleText2 * This,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ enum IA2CoordinateType coordType,
            /* [retval][out] */ long *offset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_selection )( 
            IAccessibleText2 * This,
            /* [in] */ long selectionIndex,
            /* [out] */ long *startOffset,
            /* [retval][out] */ long *endOffset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_text )( 
            IAccessibleText2 * This,
            /* [in] */ long startOffset,
            /* [in] */ long endOffset,
            /* [retval][out] */ BSTR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_textBeforeOffset )( 
            IAccessibleText2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2TextBoundaryType boundaryType,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_textAfterOffset )( 
            IAccessibleText2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2TextBoundaryType boundaryType,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_textAtOffset )( 
            IAccessibleText2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2TextBoundaryType boundaryType,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *text);
        
        HRESULT ( STDMETHODCALLTYPE *removeSelection )( 
            IAccessibleText2 * This,
            /* [in] */ long selectionIndex);
        
        HRESULT ( STDMETHODCALLTYPE *setCaretOffset )( 
            IAccessibleText2 * This,
            /* [in] */ long offset);
        
        HRESULT ( STDMETHODCALLTYPE *setSelection )( 
            IAccessibleText2 * This,
            /* [in] */ long selectionIndex,
            /* [in] */ long startOffset,
            /* [in] */ long endOffset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_nCharacters )( 
            IAccessibleText2 * This,
            /* [retval][out] */ long *nCharacters);
        
        HRESULT ( STDMETHODCALLTYPE *scrollSubstringTo )( 
            IAccessibleText2 * This,
            /* [in] */ long startIndex,
            /* [in] */ long endIndex,
            /* [in] */ enum IA2ScrollType scrollType);
        
        HRESULT ( STDMETHODCALLTYPE *scrollSubstringToPoint )( 
            IAccessibleText2 * This,
            /* [in] */ long startIndex,
            /* [in] */ long endIndex,
            /* [in] */ enum IA2CoordinateType coordinateType,
            /* [in] */ long x,
            /* [in] */ long y);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_newText )( 
            IAccessibleText2 * This,
            /* [retval][out] */ IA2TextSegment *newText);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_oldText )( 
            IAccessibleText2 * This,
            /* [retval][out] */ IA2TextSegment *oldText);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_attributeRange )( 
            IAccessibleText2 * This,
            /* [in] */ long offset,
            /* [in] */ BSTR filter,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *attributeValues);
        
        END_INTERFACE
    } IAccessibleText2Vtbl;

    interface IAccessibleText2
    {
        CONST_VTBL struct IAccessibleText2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccessibleText2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAccessibleText2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAccessibleText2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAccessibleText2_addSelection(This,startOffset,endOffset)	\
    ( (This)->lpVtbl -> addSelection(This,startOffset,endOffset) ) 

#define IAccessibleText2_get_attributes(This,offset,startOffset,endOffset,textAttributes)	\
    ( (This)->lpVtbl -> get_attributes(This,offset,startOffset,endOffset,textAttributes) ) 

#define IAccessibleText2_get_caretOffset(This,offset)	\
    ( (This)->lpVtbl -> get_caretOffset(This,offset) ) 

#define IAccessibleText2_get_characterExtents(This,offset,coordType,x,y,width,height)	\
    ( (This)->lpVtbl -> get_characterExtents(This,offset,coordType,x,y,width,height) ) 

#define IAccessibleText2_get_nSelections(This,nSelections)	\
    ( (This)->lpVtbl -> get_nSelections(This,nSelections) ) 

#define IAccessibleText2_get_offsetAtPoint(This,x,y,coordType,offset)	\
    ( (This)->lpVtbl -> get_offsetAtPoint(This,x,y,coordType,offset) ) 

#define IAccessibleText2_get_selection(This,selectionIndex,startOffset,endOffset)	\
    ( (This)->lpVtbl -> get_selection(This,selectionIndex,startOffset,endOffset) ) 

#define IAccessibleText2_get_text(This,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_text(This,startOffset,endOffset,text) ) 

#define IAccessibleText2_get_textBeforeOffset(This,offset,boundaryType,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_textBeforeOffset(This,offset,boundaryType,startOffset,endOffset,text) ) 

#define IAccessibleText2_get_textAfterOffset(This,offset,boundaryType,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_textAfterOffset(This,offset,boundaryType,startOffset,endOffset,text) ) 

#define IAccessibleText2_get_textAtOffset(This,offset,boundaryType,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_textAtOffset(This,offset,boundaryType,startOffset,endOffset,text) ) 

#define IAccessibleText2_removeSelection(This,selectionIndex)	\
    ( (This)->lpVtbl -> removeSelection(This,selectionIndex) ) 

#define IAccessibleText2_setCaretOffset(This,offset)	\
    ( (This)->lpVtbl -> setCaretOffset(This,offset) ) 

#define IAccessibleText2_setSelection(This,selectionIndex,startOffset,endOffset)	\
    ( (This)->lpVtbl -> setSelection(This,selectionIndex,startOffset,endOffset) ) 

#define IAccessibleText2_get_nCharacters(This,nCharacters)	\
    ( (This)->lpVtbl -> get_nCharacters(This,nCharacters) ) 

#define IAccessibleText2_scrollSubstringTo(This,startIndex,endIndex,scrollType)	\
    ( (This)->lpVtbl -> scrollSubstringTo(This,startIndex,endIndex,scrollType) ) 

#define IAccessibleText2_scrollSubstringToPoint(This,startIndex,endIndex,coordinateType,x,y)	\
    ( (This)->lpVtbl -> scrollSubstringToPoint(This,startIndex,endIndex,coordinateType,x,y) ) 

#define IAccessibleText2_get_newText(This,newText)	\
    ( (This)->lpVtbl -> get_newText(This,newText) ) 

#define IAccessibleText2_get_oldText(This,oldText)	\
    ( (This)->lpVtbl -> get_oldText(This,oldText) ) 


#define IAccessibleText2_get_attributeRange(This,offset,filter,startOffset,endOffset,attributeValues)	\
    ( (This)->lpVtbl -> get_attributeRange(This,offset,filter,startOffset,endOffset,attributeValues) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAccessibleText2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


