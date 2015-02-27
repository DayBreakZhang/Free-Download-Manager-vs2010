

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Mon Apr 28 18:11:02 2014
 */
/* Compiler settings for c:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/other-licenses/ia2/AccessibleHypertext2.idl:
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

#ifndef __AccessibleHypertext2_h__
#define __AccessibleHypertext2_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAccessibleHypertext2_FWD_DEFINED__
#define __IAccessibleHypertext2_FWD_DEFINED__
typedef interface IAccessibleHypertext2 IAccessibleHypertext2;

#endif 	/* __IAccessibleHypertext2_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"
#include "oaidl.h"
#include "oleacc.h"
#include "AccessibleHypertext.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAccessibleHypertext2_INTERFACE_DEFINED__
#define __IAccessibleHypertext2_INTERFACE_DEFINED__

/* interface IAccessibleHypertext2 */
/* [uuid][object] */ 


EXTERN_C const IID IID_IAccessibleHypertext2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF64D89F-8287-4B44-8501-A827453A6077")
    IAccessibleHypertext2 : public IAccessibleHypertext
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_hyperlinks( 
            /* [size_is][size_is][out] */ IAccessibleHyperlink ***hyperlinks,
            /* [retval][out] */ long *nHyperlinks) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAccessibleHypertext2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAccessibleHypertext2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAccessibleHypertext2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAccessibleHypertext2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *addSelection )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long startOffset,
            /* [in] */ long endOffset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_attributes )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long offset,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *textAttributes);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_caretOffset )( 
            IAccessibleHypertext2 * This,
            /* [retval][out] */ long *offset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_characterExtents )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2CoordinateType coordType,
            /* [out] */ long *x,
            /* [out] */ long *y,
            /* [out] */ long *width,
            /* [retval][out] */ long *height);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_nSelections )( 
            IAccessibleHypertext2 * This,
            /* [retval][out] */ long *nSelections);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_offsetAtPoint )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ enum IA2CoordinateType coordType,
            /* [retval][out] */ long *offset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_selection )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long selectionIndex,
            /* [out] */ long *startOffset,
            /* [retval][out] */ long *endOffset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_text )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long startOffset,
            /* [in] */ long endOffset,
            /* [retval][out] */ BSTR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_textBeforeOffset )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2TextBoundaryType boundaryType,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_textAfterOffset )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2TextBoundaryType boundaryType,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_textAtOffset )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long offset,
            /* [in] */ enum IA2TextBoundaryType boundaryType,
            /* [out] */ long *startOffset,
            /* [out] */ long *endOffset,
            /* [retval][out] */ BSTR *text);
        
        HRESULT ( STDMETHODCALLTYPE *removeSelection )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long selectionIndex);
        
        HRESULT ( STDMETHODCALLTYPE *setCaretOffset )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long offset);
        
        HRESULT ( STDMETHODCALLTYPE *setSelection )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long selectionIndex,
            /* [in] */ long startOffset,
            /* [in] */ long endOffset);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_nCharacters )( 
            IAccessibleHypertext2 * This,
            /* [retval][out] */ long *nCharacters);
        
        HRESULT ( STDMETHODCALLTYPE *scrollSubstringTo )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long startIndex,
            /* [in] */ long endIndex,
            /* [in] */ enum IA2ScrollType scrollType);
        
        HRESULT ( STDMETHODCALLTYPE *scrollSubstringToPoint )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long startIndex,
            /* [in] */ long endIndex,
            /* [in] */ enum IA2CoordinateType coordinateType,
            /* [in] */ long x,
            /* [in] */ long y);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_newText )( 
            IAccessibleHypertext2 * This,
            /* [retval][out] */ IA2TextSegment *newText);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_oldText )( 
            IAccessibleHypertext2 * This,
            /* [retval][out] */ IA2TextSegment *oldText);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_nHyperlinks )( 
            IAccessibleHypertext2 * This,
            /* [retval][out] */ long *hyperlinkCount);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_hyperlink )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long index,
            /* [retval][out] */ IAccessibleHyperlink **hyperlink);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_hyperlinkIndex )( 
            IAccessibleHypertext2 * This,
            /* [in] */ long charIndex,
            /* [retval][out] */ long *hyperlinkIndex);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_hyperlinks )( 
            IAccessibleHypertext2 * This,
            /* [size_is][size_is][out] */ IAccessibleHyperlink ***hyperlinks,
            /* [retval][out] */ long *nHyperlinks);
        
        END_INTERFACE
    } IAccessibleHypertext2Vtbl;

    interface IAccessibleHypertext2
    {
        CONST_VTBL struct IAccessibleHypertext2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccessibleHypertext2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAccessibleHypertext2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAccessibleHypertext2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAccessibleHypertext2_addSelection(This,startOffset,endOffset)	\
    ( (This)->lpVtbl -> addSelection(This,startOffset,endOffset) ) 

#define IAccessibleHypertext2_get_attributes(This,offset,startOffset,endOffset,textAttributes)	\
    ( (This)->lpVtbl -> get_attributes(This,offset,startOffset,endOffset,textAttributes) ) 

#define IAccessibleHypertext2_get_caretOffset(This,offset)	\
    ( (This)->lpVtbl -> get_caretOffset(This,offset) ) 

#define IAccessibleHypertext2_get_characterExtents(This,offset,coordType,x,y,width,height)	\
    ( (This)->lpVtbl -> get_characterExtents(This,offset,coordType,x,y,width,height) ) 

#define IAccessibleHypertext2_get_nSelections(This,nSelections)	\
    ( (This)->lpVtbl -> get_nSelections(This,nSelections) ) 

#define IAccessibleHypertext2_get_offsetAtPoint(This,x,y,coordType,offset)	\
    ( (This)->lpVtbl -> get_offsetAtPoint(This,x,y,coordType,offset) ) 

#define IAccessibleHypertext2_get_selection(This,selectionIndex,startOffset,endOffset)	\
    ( (This)->lpVtbl -> get_selection(This,selectionIndex,startOffset,endOffset) ) 

#define IAccessibleHypertext2_get_text(This,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_text(This,startOffset,endOffset,text) ) 

#define IAccessibleHypertext2_get_textBeforeOffset(This,offset,boundaryType,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_textBeforeOffset(This,offset,boundaryType,startOffset,endOffset,text) ) 

#define IAccessibleHypertext2_get_textAfterOffset(This,offset,boundaryType,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_textAfterOffset(This,offset,boundaryType,startOffset,endOffset,text) ) 

#define IAccessibleHypertext2_get_textAtOffset(This,offset,boundaryType,startOffset,endOffset,text)	\
    ( (This)->lpVtbl -> get_textAtOffset(This,offset,boundaryType,startOffset,endOffset,text) ) 

#define IAccessibleHypertext2_removeSelection(This,selectionIndex)	\
    ( (This)->lpVtbl -> removeSelection(This,selectionIndex) ) 

#define IAccessibleHypertext2_setCaretOffset(This,offset)	\
    ( (This)->lpVtbl -> setCaretOffset(This,offset) ) 

#define IAccessibleHypertext2_setSelection(This,selectionIndex,startOffset,endOffset)	\
    ( (This)->lpVtbl -> setSelection(This,selectionIndex,startOffset,endOffset) ) 

#define IAccessibleHypertext2_get_nCharacters(This,nCharacters)	\
    ( (This)->lpVtbl -> get_nCharacters(This,nCharacters) ) 

#define IAccessibleHypertext2_scrollSubstringTo(This,startIndex,endIndex,scrollType)	\
    ( (This)->lpVtbl -> scrollSubstringTo(This,startIndex,endIndex,scrollType) ) 

#define IAccessibleHypertext2_scrollSubstringToPoint(This,startIndex,endIndex,coordinateType,x,y)	\
    ( (This)->lpVtbl -> scrollSubstringToPoint(This,startIndex,endIndex,coordinateType,x,y) ) 

#define IAccessibleHypertext2_get_newText(This,newText)	\
    ( (This)->lpVtbl -> get_newText(This,newText) ) 

#define IAccessibleHypertext2_get_oldText(This,oldText)	\
    ( (This)->lpVtbl -> get_oldText(This,oldText) ) 


#define IAccessibleHypertext2_get_nHyperlinks(This,hyperlinkCount)	\
    ( (This)->lpVtbl -> get_nHyperlinks(This,hyperlinkCount) ) 

#define IAccessibleHypertext2_get_hyperlink(This,index,hyperlink)	\
    ( (This)->lpVtbl -> get_hyperlink(This,index,hyperlink) ) 

#define IAccessibleHypertext2_get_hyperlinkIndex(This,charIndex,hyperlinkIndex)	\
    ( (This)->lpVtbl -> get_hyperlinkIndex(This,charIndex,hyperlinkIndex) ) 


#define IAccessibleHypertext2_get_hyperlinks(This,hyperlinks,nHyperlinks)	\
    ( (This)->lpVtbl -> get_hyperlinks(This,hyperlinks,nHyperlinks) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAccessibleHypertext2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


