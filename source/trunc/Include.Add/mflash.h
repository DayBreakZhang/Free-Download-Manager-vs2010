/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu May 26 02:50:05 2005
 */
/* Compiler settings for D:\DOCUME~1\aler\LOCALS~1\Temp\IDL1E5.tmp:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __Flash_h__
#define __Flash_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IShockwaveFlash_FWD_DEFINED__
#define __IShockwaveFlash_FWD_DEFINED__
typedef interface IShockwaveFlash IShockwaveFlash;
#endif 	/* __IShockwaveFlash_FWD_DEFINED__ */


#ifndef ___IShockwaveFlashEvents_FWD_DEFINED__
#define ___IShockwaveFlashEvents_FWD_DEFINED__
typedef interface _IShockwaveFlashEvents _IShockwaveFlashEvents;
#endif 	/* ___IShockwaveFlashEvents_FWD_DEFINED__ */


#ifndef __IFlashFactory_FWD_DEFINED__
#define __IFlashFactory_FWD_DEFINED__
typedef interface IFlashFactory IFlashFactory;
#endif 	/* __IFlashFactory_FWD_DEFINED__ */


#ifndef __IDispatchEx_FWD_DEFINED__
#define __IDispatchEx_FWD_DEFINED__
typedef interface IDispatchEx IDispatchEx;
#endif 	/* __IDispatchEx_FWD_DEFINED__ */


#ifndef __IFlashObjectInterface_FWD_DEFINED__
#define __IFlashObjectInterface_FWD_DEFINED__
typedef interface IFlashObjectInterface IFlashObjectInterface;
#endif 	/* __IFlashObjectInterface_FWD_DEFINED__ */


#ifndef __IServiceProvider_FWD_DEFINED__
#define __IServiceProvider_FWD_DEFINED__
typedef interface IServiceProvider IServiceProvider;
#endif 	/* __IServiceProvider_FWD_DEFINED__ */


#ifndef __ShockwaveFlash_FWD_DEFINED__
#define __ShockwaveFlash_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShockwaveFlash ShockwaveFlash;
#else
typedef struct ShockwaveFlash ShockwaveFlash;
#endif /* __cplusplus */

#endif 	/* __ShockwaveFlash_FWD_DEFINED__ */


#ifndef __FlashProp_FWD_DEFINED__
#define __FlashProp_FWD_DEFINED__

#ifdef __cplusplus
typedef class FlashProp FlashProp;
#else
typedef struct FlashProp FlashProp;
#endif /* __cplusplus */

#endif 	/* __FlashProp_FWD_DEFINED__ */


#ifndef __FlashObjectInterface_FWD_DEFINED__
#define __FlashObjectInterface_FWD_DEFINED__

#ifdef __cplusplus
typedef class FlashObjectInterface FlashObjectInterface;
#else
typedef struct FlashObjectInterface FlashObjectInterface;
#endif /* __cplusplus */

#endif 	/* __FlashObjectInterface_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __ShockwaveFlashObjects_LIBRARY_DEFINED__
#define __ShockwaveFlashObjects_LIBRARY_DEFINED__

/* library ShockwaveFlashObjects */
/* [helpstring][version][uuid] */ 








EXTERN_C const IID LIBID_ShockwaveFlashObjects;

#ifndef __IShockwaveFlash_INTERFACE_DEFINED__
#define __IShockwaveFlash_INTERFACE_DEFINED__

/* interface IShockwaveFlash */
/* [object][oleautomation][dual][helpstring][uuid] */ 


EXTERN_C const IID IID_IShockwaveFlash;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D27CDB6C-AE6D-11CF-96B8-444553540000")
    IShockwaveFlash : public IDispatch
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ReadyState( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalFrames( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Playing( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Playing( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Quality( 
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Quality( 
            /* [in] */ int pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_ScaleMode( 
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_ScaleMode( 
            /* [in] */ int pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_AlignMode( 
            /* [retval][out] */ int __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_AlignMode( 
            /* [in] */ int pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BackgroundColor( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BackgroundColor( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Loop( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Loop( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Movie( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Movie( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FrameNum( 
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FrameNum( 
            /* [in] */ long pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetZoomRect( 
            /* [in] */ long left,
            /* [in] */ long top,
            /* [in] */ long right,
            /* [in] */ long bottom) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Zoom( 
            /* [in] */ int factor) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Pan( 
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ int mode) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Play( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Back( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Forward( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Rewind( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE StopPlay( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GotoFrame( 
            /* [in] */ long FrameNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CurrentFrame( 
            /* [retval][out] */ long __RPC_FAR *FrameNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsPlaying( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Playing) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PercentLoaded( 
            /* [retval][out] */ long __RPC_FAR *percent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FrameLoaded( 
            /* [in] */ long FrameNum,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *loaded) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FlashVersion( 
            /* [retval][out] */ long __RPC_FAR *version) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WMode( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_WMode( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SAlign( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SAlign( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Menu( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Menu( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Base( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Base( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Scale( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Scale( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_DeviceFont( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_DeviceFont( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_EmbedMovie( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_EmbedMovie( 
            /* [in] */ VARIANT_BOOL pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_BGColor( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_BGColor( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Quality2( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Quality2( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadMovie( 
            /* [in] */ int layer,
            /* [in] */ BSTR url) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TGotoFrame( 
            /* [in] */ BSTR target,
            /* [in] */ long FrameNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TGotoLabel( 
            /* [in] */ BSTR target,
            /* [in] */ BSTR label) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TCurrentFrame( 
            /* [in] */ BSTR target,
            /* [retval][out] */ long __RPC_FAR *FrameNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TCurrentLabel( 
            /* [in] */ BSTR target,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TPlay( 
            /* [in] */ BSTR target) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TStopPlay( 
            /* [in] */ BSTR target) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVariable( 
            /* [in] */ BSTR name,
            /* [in] */ BSTR value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariable( 
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TSetProperty( 
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [in] */ BSTR value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TGetProperty( 
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TCallFrame( 
            /* [in] */ BSTR target,
            /* [in] */ int FrameNum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TCallLabel( 
            /* [in] */ BSTR target,
            /* [in] */ BSTR label) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TSetPropertyNum( 
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [in] */ double value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TGetPropertyNum( 
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SWRemote( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SWRemote( 
            /* [in] */ BSTR pVal) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_FlashVars( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_FlashVars( 
            /* [in] */ BSTR pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShockwaveFlashVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IShockwaveFlash __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IShockwaveFlash __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ReadyState )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TotalFrames )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Playing )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Playing )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Quality )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Quality )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ int pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ScaleMode )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ScaleMode )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ int pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AlignMode )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ int __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AlignMode )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ int pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BackgroundColor )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BackgroundColor )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ long pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Loop )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Loop )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Movie )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Movie )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FrameNum )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FrameNum )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ long pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetZoomRect )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ long left,
            /* [in] */ long top,
            /* [in] */ long right,
            /* [in] */ long bottom);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Zoom )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ int factor);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Pan )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ long x,
            /* [in] */ long y,
            /* [in] */ int mode);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Play )( 
            IShockwaveFlash __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IShockwaveFlash __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Back )( 
            IShockwaveFlash __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Forward )( 
            IShockwaveFlash __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Rewind )( 
            IShockwaveFlash __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopPlay )( 
            IShockwaveFlash __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GotoFrame )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ long FrameNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CurrentFrame )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *FrameNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsPlaying )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Playing);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PercentLoaded )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *percent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FrameLoaded )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ long FrameNum,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *loaded);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FlashVersion )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *version);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WMode )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_WMode )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SAlign )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SAlign )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Menu )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Menu )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Base )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Base )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Scale )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Scale )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DeviceFont )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DeviceFont )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EmbedMovie )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_EmbedMovie )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BGColor )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BGColor )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Quality2 )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Quality2 )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadMovie )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ int layer,
            /* [in] */ BSTR url);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TGotoFrame )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ long FrameNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TGotoLabel )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ BSTR label);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TCurrentFrame )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [retval][out] */ long __RPC_FAR *FrameNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TCurrentLabel )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TPlay )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TStopPlay )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVariable )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariable )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TSetProperty )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [in] */ BSTR value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TGetProperty )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TCallFrame )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ int FrameNum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TCallLabel )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ BSTR label);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TSetPropertyNum )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [in] */ double value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TGetPropertyNum )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR target,
            /* [in] */ int property,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SWRemote )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SWRemote )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FlashVars )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FlashVars )( 
            IShockwaveFlash __RPC_FAR * This,
            /* [in] */ BSTR pVal);
        
        END_INTERFACE
    } IShockwaveFlashVtbl;

    interface IShockwaveFlash
    {
        CONST_VTBL struct IShockwaveFlashVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShockwaveFlash_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShockwaveFlash_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShockwaveFlash_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShockwaveFlash_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IShockwaveFlash_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IShockwaveFlash_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IShockwaveFlash_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IShockwaveFlash_get_ReadyState(This,pVal)	\
    (This)->lpVtbl -> get_ReadyState(This,pVal)

#define IShockwaveFlash_get_TotalFrames(This,pVal)	\
    (This)->lpVtbl -> get_TotalFrames(This,pVal)

#define IShockwaveFlash_get_Playing(This,pVal)	\
    (This)->lpVtbl -> get_Playing(This,pVal)

#define IShockwaveFlash_put_Playing(This,pVal)	\
    (This)->lpVtbl -> put_Playing(This,pVal)

#define IShockwaveFlash_get_Quality(This,pVal)	\
    (This)->lpVtbl -> get_Quality(This,pVal)

#define IShockwaveFlash_put_Quality(This,pVal)	\
    (This)->lpVtbl -> put_Quality(This,pVal)

#define IShockwaveFlash_get_ScaleMode(This,pVal)	\
    (This)->lpVtbl -> get_ScaleMode(This,pVal)

#define IShockwaveFlash_put_ScaleMode(This,pVal)	\
    (This)->lpVtbl -> put_ScaleMode(This,pVal)

#define IShockwaveFlash_get_AlignMode(This,pVal)	\
    (This)->lpVtbl -> get_AlignMode(This,pVal)

#define IShockwaveFlash_put_AlignMode(This,pVal)	\
    (This)->lpVtbl -> put_AlignMode(This,pVal)

#define IShockwaveFlash_get_BackgroundColor(This,pVal)	\
    (This)->lpVtbl -> get_BackgroundColor(This,pVal)

#define IShockwaveFlash_put_BackgroundColor(This,pVal)	\
    (This)->lpVtbl -> put_BackgroundColor(This,pVal)

#define IShockwaveFlash_get_Loop(This,pVal)	\
    (This)->lpVtbl -> get_Loop(This,pVal)

#define IShockwaveFlash_put_Loop(This,pVal)	\
    (This)->lpVtbl -> put_Loop(This,pVal)

#define IShockwaveFlash_get_Movie(This,pVal)	\
    (This)->lpVtbl -> get_Movie(This,pVal)

#define IShockwaveFlash_put_Movie(This,pVal)	\
    (This)->lpVtbl -> put_Movie(This,pVal)

#define IShockwaveFlash_get_FrameNum(This,pVal)	\
    (This)->lpVtbl -> get_FrameNum(This,pVal)

#define IShockwaveFlash_put_FrameNum(This,pVal)	\
    (This)->lpVtbl -> put_FrameNum(This,pVal)

#define IShockwaveFlash_SetZoomRect(This,left,top,right,bottom)	\
    (This)->lpVtbl -> SetZoomRect(This,left,top,right,bottom)

#define IShockwaveFlash_Zoom(This,factor)	\
    (This)->lpVtbl -> Zoom(This,factor)

#define IShockwaveFlash_Pan(This,x,y,mode)	\
    (This)->lpVtbl -> Pan(This,x,y,mode)

#define IShockwaveFlash_Play(This)	\
    (This)->lpVtbl -> Play(This)

#define IShockwaveFlash_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define IShockwaveFlash_Back(This)	\
    (This)->lpVtbl -> Back(This)

#define IShockwaveFlash_Forward(This)	\
    (This)->lpVtbl -> Forward(This)

#define IShockwaveFlash_Rewind(This)	\
    (This)->lpVtbl -> Rewind(This)

#define IShockwaveFlash_StopPlay(This)	\
    (This)->lpVtbl -> StopPlay(This)

#define IShockwaveFlash_GotoFrame(This,FrameNum)	\
    (This)->lpVtbl -> GotoFrame(This,FrameNum)

#define IShockwaveFlash_CurrentFrame(This,FrameNum)	\
    (This)->lpVtbl -> CurrentFrame(This,FrameNum)

#define IShockwaveFlash_IsPlaying(This,Playing)	\
    (This)->lpVtbl -> IsPlaying(This,Playing)

#define IShockwaveFlash_PercentLoaded(This,percent)	\
    (This)->lpVtbl -> PercentLoaded(This,percent)

#define IShockwaveFlash_FrameLoaded(This,FrameNum,loaded)	\
    (This)->lpVtbl -> FrameLoaded(This,FrameNum,loaded)

#define IShockwaveFlash_FlashVersion(This,version)	\
    (This)->lpVtbl -> FlashVersion(This,version)

#define IShockwaveFlash_get_WMode(This,pVal)	\
    (This)->lpVtbl -> get_WMode(This,pVal)

#define IShockwaveFlash_put_WMode(This,pVal)	\
    (This)->lpVtbl -> put_WMode(This,pVal)

#define IShockwaveFlash_get_SAlign(This,pVal)	\
    (This)->lpVtbl -> get_SAlign(This,pVal)

#define IShockwaveFlash_put_SAlign(This,pVal)	\
    (This)->lpVtbl -> put_SAlign(This,pVal)

#define IShockwaveFlash_get_Menu(This,pVal)	\
    (This)->lpVtbl -> get_Menu(This,pVal)

#define IShockwaveFlash_put_Menu(This,pVal)	\
    (This)->lpVtbl -> put_Menu(This,pVal)

#define IShockwaveFlash_get_Base(This,pVal)	\
    (This)->lpVtbl -> get_Base(This,pVal)

#define IShockwaveFlash_put_Base(This,pVal)	\
    (This)->lpVtbl -> put_Base(This,pVal)

#define IShockwaveFlash_get_Scale(This,pVal)	\
    (This)->lpVtbl -> get_Scale(This,pVal)

#define IShockwaveFlash_put_Scale(This,pVal)	\
    (This)->lpVtbl -> put_Scale(This,pVal)

#define IShockwaveFlash_get_DeviceFont(This,pVal)	\
    (This)->lpVtbl -> get_DeviceFont(This,pVal)

#define IShockwaveFlash_put_DeviceFont(This,pVal)	\
    (This)->lpVtbl -> put_DeviceFont(This,pVal)

#define IShockwaveFlash_get_EmbedMovie(This,pVal)	\
    (This)->lpVtbl -> get_EmbedMovie(This,pVal)

#define IShockwaveFlash_put_EmbedMovie(This,pVal)	\
    (This)->lpVtbl -> put_EmbedMovie(This,pVal)

#define IShockwaveFlash_get_BGColor(This,pVal)	\
    (This)->lpVtbl -> get_BGColor(This,pVal)

#define IShockwaveFlash_put_BGColor(This,pVal)	\
    (This)->lpVtbl -> put_BGColor(This,pVal)

#define IShockwaveFlash_get_Quality2(This,pVal)	\
    (This)->lpVtbl -> get_Quality2(This,pVal)

#define IShockwaveFlash_put_Quality2(This,pVal)	\
    (This)->lpVtbl -> put_Quality2(This,pVal)

#define IShockwaveFlash_LoadMovie(This,layer,url)	\
    (This)->lpVtbl -> LoadMovie(This,layer,url)

#define IShockwaveFlash_TGotoFrame(This,target,FrameNum)	\
    (This)->lpVtbl -> TGotoFrame(This,target,FrameNum)

#define IShockwaveFlash_TGotoLabel(This,target,label)	\
    (This)->lpVtbl -> TGotoLabel(This,target,label)

#define IShockwaveFlash_TCurrentFrame(This,target,FrameNum)	\
    (This)->lpVtbl -> TCurrentFrame(This,target,FrameNum)

#define IShockwaveFlash_TCurrentLabel(This,target,pVal)	\
    (This)->lpVtbl -> TCurrentLabel(This,target,pVal)

#define IShockwaveFlash_TPlay(This,target)	\
    (This)->lpVtbl -> TPlay(This,target)

#define IShockwaveFlash_TStopPlay(This,target)	\
    (This)->lpVtbl -> TStopPlay(This,target)

#define IShockwaveFlash_SetVariable(This,name,value)	\
    (This)->lpVtbl -> SetVariable(This,name,value)

#define IShockwaveFlash_GetVariable(This,name,pVal)	\
    (This)->lpVtbl -> GetVariable(This,name,pVal)

#define IShockwaveFlash_TSetProperty(This,target,property,value)	\
    (This)->lpVtbl -> TSetProperty(This,target,property,value)

#define IShockwaveFlash_TGetProperty(This,target,property,pVal)	\
    (This)->lpVtbl -> TGetProperty(This,target,property,pVal)

#define IShockwaveFlash_TCallFrame(This,target,FrameNum)	\
    (This)->lpVtbl -> TCallFrame(This,target,FrameNum)

#define IShockwaveFlash_TCallLabel(This,target,label)	\
    (This)->lpVtbl -> TCallLabel(This,target,label)

#define IShockwaveFlash_TSetPropertyNum(This,target,property,value)	\
    (This)->lpVtbl -> TSetPropertyNum(This,target,property,value)

#define IShockwaveFlash_TGetPropertyNum(This,target,property,pVal)	\
    (This)->lpVtbl -> TGetPropertyNum(This,target,property,pVal)

#define IShockwaveFlash_get_SWRemote(This,pVal)	\
    (This)->lpVtbl -> get_SWRemote(This,pVal)

#define IShockwaveFlash_put_SWRemote(This,pVal)	\
    (This)->lpVtbl -> put_SWRemote(This,pVal)

#define IShockwaveFlash_get_FlashVars(This,pVal)	\
    (This)->lpVtbl -> get_FlashVars(This,pVal)

#define IShockwaveFlash_put_FlashVars(This,pVal)	\
    (This)->lpVtbl -> put_FlashVars(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_ReadyState_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_ReadyState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_TotalFrames_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_TotalFrames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Playing_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Playing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Playing_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IShockwaveFlash_put_Playing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Quality_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Quality_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Quality_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ int pVal);


void __RPC_STUB IShockwaveFlash_put_Quality_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_ScaleMode_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_ScaleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_ScaleMode_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ int pVal);


void __RPC_STUB IShockwaveFlash_put_ScaleMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_AlignMode_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ int __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_AlignMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_AlignMode_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ int pVal);


void __RPC_STUB IShockwaveFlash_put_AlignMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_BackgroundColor_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_BackgroundColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_BackgroundColor_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ long pVal);


void __RPC_STUB IShockwaveFlash_put_BackgroundColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Loop_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Loop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Loop_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IShockwaveFlash_put_Loop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Movie_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Movie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Movie_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_Movie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_FrameNum_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_FrameNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_FrameNum_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ long pVal);


void __RPC_STUB IShockwaveFlash_put_FrameNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_SetZoomRect_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ long left,
    /* [in] */ long top,
    /* [in] */ long right,
    /* [in] */ long bottom);


void __RPC_STUB IShockwaveFlash_SetZoomRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Zoom_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ int factor);


void __RPC_STUB IShockwaveFlash_Zoom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Pan_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ long x,
    /* [in] */ long y,
    /* [in] */ int mode);


void __RPC_STUB IShockwaveFlash_Pan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Play_Proxy( 
    IShockwaveFlash __RPC_FAR * This);


void __RPC_STUB IShockwaveFlash_Play_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Stop_Proxy( 
    IShockwaveFlash __RPC_FAR * This);


void __RPC_STUB IShockwaveFlash_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Back_Proxy( 
    IShockwaveFlash __RPC_FAR * This);


void __RPC_STUB IShockwaveFlash_Back_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Forward_Proxy( 
    IShockwaveFlash __RPC_FAR * This);


void __RPC_STUB IShockwaveFlash_Forward_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_Rewind_Proxy( 
    IShockwaveFlash __RPC_FAR * This);


void __RPC_STUB IShockwaveFlash_Rewind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_StopPlay_Proxy( 
    IShockwaveFlash __RPC_FAR * This);


void __RPC_STUB IShockwaveFlash_StopPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_GotoFrame_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ long FrameNum);


void __RPC_STUB IShockwaveFlash_GotoFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_CurrentFrame_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *FrameNum);


void __RPC_STUB IShockwaveFlash_CurrentFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_IsPlaying_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Playing);


void __RPC_STUB IShockwaveFlash_IsPlaying_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_PercentLoaded_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *percent);


void __RPC_STUB IShockwaveFlash_PercentLoaded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_FrameLoaded_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ long FrameNum,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *loaded);


void __RPC_STUB IShockwaveFlash_FrameLoaded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_FlashVersion_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *version);


void __RPC_STUB IShockwaveFlash_FlashVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_WMode_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_WMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_WMode_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_WMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_SAlign_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_SAlign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_SAlign_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_SAlign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Menu_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Menu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Menu_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IShockwaveFlash_put_Menu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Base_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Base_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Base_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_Base_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Scale_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Scale_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_Scale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_DeviceFont_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_DeviceFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_DeviceFont_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IShockwaveFlash_put_DeviceFont_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_EmbedMovie_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_EmbedMovie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_EmbedMovie_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL pVal);


void __RPC_STUB IShockwaveFlash_put_EmbedMovie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_BGColor_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_BGColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_BGColor_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_BGColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_Quality2_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_Quality2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_Quality2_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_Quality2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_LoadMovie_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ int layer,
    /* [in] */ BSTR url);


void __RPC_STUB IShockwaveFlash_LoadMovie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TGotoFrame_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ long FrameNum);


void __RPC_STUB IShockwaveFlash_TGotoFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TGotoLabel_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ BSTR label);


void __RPC_STUB IShockwaveFlash_TGotoLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TCurrentFrame_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [retval][out] */ long __RPC_FAR *FrameNum);


void __RPC_STUB IShockwaveFlash_TCurrentFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TCurrentLabel_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_TCurrentLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TPlay_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target);


void __RPC_STUB IShockwaveFlash_TPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TStopPlay_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target);


void __RPC_STUB IShockwaveFlash_TStopPlay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_SetVariable_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [in] */ BSTR value);


void __RPC_STUB IShockwaveFlash_SetVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_GetVariable_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR name,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_GetVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TSetProperty_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ int property,
    /* [in] */ BSTR value);


void __RPC_STUB IShockwaveFlash_TSetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TGetProperty_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ int property,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_TGetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TCallFrame_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ int FrameNum);


void __RPC_STUB IShockwaveFlash_TCallFrame_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TCallLabel_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ BSTR label);


void __RPC_STUB IShockwaveFlash_TCallLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TSetPropertyNum_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ int property,
    /* [in] */ double value);


void __RPC_STUB IShockwaveFlash_TSetPropertyNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_TGetPropertyNum_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR target,
    /* [in] */ int property,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_TGetPropertyNum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_SWRemote_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_SWRemote_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_SWRemote_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_SWRemote_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_get_FlashVars_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IShockwaveFlash_get_FlashVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE IShockwaveFlash_put_FlashVars_Proxy( 
    IShockwaveFlash __RPC_FAR * This,
    /* [in] */ BSTR pVal);


void __RPC_STUB IShockwaveFlash_put_FlashVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShockwaveFlash_INTERFACE_DEFINED__ */


#ifndef ___IShockwaveFlashEvents_DISPINTERFACE_DEFINED__
#define ___IShockwaveFlashEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IShockwaveFlashEvents */
/* [hidden][helpstring][uuid] */ 


EXTERN_C const IID DIID__IShockwaveFlashEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D27CDB6D-AE6D-11CF-96B8-444553540000")
    _IShockwaveFlashEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IShockwaveFlashEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IShockwaveFlashEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IShockwaveFlashEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IShockwaveFlashEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IShockwaveFlashEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IShockwaveFlashEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IShockwaveFlashEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IShockwaveFlashEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IShockwaveFlashEventsVtbl;

    interface _IShockwaveFlashEvents
    {
        CONST_VTBL struct _IShockwaveFlashEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IShockwaveFlashEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IShockwaveFlashEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IShockwaveFlashEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IShockwaveFlashEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IShockwaveFlashEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IShockwaveFlashEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IShockwaveFlashEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IShockwaveFlashEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IFlashFactory_INTERFACE_DEFINED__
#define __IFlashFactory_INTERFACE_DEFINED__

/* interface IFlashFactory */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IFlashFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D27CDB70-AE6D-11CF-96B8-444553540000")
    IFlashFactory : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IFlashFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFlashFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFlashFactory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFlashFactory __RPC_FAR * This);
        
        END_INTERFACE
    } IFlashFactoryVtbl;

    interface IFlashFactory
    {
        CONST_VTBL struct IFlashFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFlashFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFlashFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFlashFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFlashFactory_INTERFACE_DEFINED__ */


#ifndef __IFlashObjectInterface_INTERFACE_DEFINED__
#define __IFlashObjectInterface_INTERFACE_DEFINED__

/* interface IFlashObjectInterface */
/* [object][helpstring][uuid] */ 


EXTERN_C const IID IID_IFlashObjectInterface;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D27CDB72-AE6D-11CF-96B8-444553540000")
    IFlashObjectInterface : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IFlashObjectInterfaceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IFlashObjectInterface __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IFlashObjectInterface __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( __stdcall __RPC_FAR *GetDispID )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ unsigned long grfdex,
            /* [out] */ long __RPC_FAR *pid);
        
        HRESULT ( __stdcall __RPC_FAR *RemoteInvokeEx )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ long id,
            /* [in] */ unsigned long lcid,
            /* [in] */ unsigned long dwFlags,
            /* [in] */ DISPPARAMS __RPC_FAR *pdp,
            /* [out] */ VARIANT __RPC_FAR *pvarRes,
            /* [out] */ EXCEPINFO __RPC_FAR *pei,
            /* [in] */ IServiceProvider __RPC_FAR *pspCaller,
            /* [in] */ unsigned int cvarRefArg,
            /* [in] */ unsigned int __RPC_FAR *rgiRefArg,
            /* [out][in] */ VARIANT __RPC_FAR *rgvarRefArg);
        
        HRESULT ( __stdcall __RPC_FAR *DeleteMemberByName )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ unsigned long grfdex);
        
        HRESULT ( __stdcall __RPC_FAR *DeleteMemberByDispID )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ long id);
        
        HRESULT ( __stdcall __RPC_FAR *GetMemberProperties )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ long id,
            /* [in] */ unsigned long grfdexFetch,
            /* [out] */ unsigned long __RPC_FAR *pgrfdex);
        
        HRESULT ( __stdcall __RPC_FAR *GetMemberName )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ long id,
            /* [out] */ BSTR __RPC_FAR *pbstrName);
        
        HRESULT ( __stdcall __RPC_FAR *GetNextDispID )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [in] */ unsigned long grfdex,
            /* [in] */ long id,
            /* [out] */ long __RPC_FAR *pid);
        
        HRESULT ( __stdcall __RPC_FAR *GetNameSpaceParent )( 
            IFlashObjectInterface __RPC_FAR * This,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);
        
        END_INTERFACE
    } IFlashObjectInterfaceVtbl;

    interface IFlashObjectInterface
    {
        CONST_VTBL struct IFlashObjectInterfaceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFlashObjectInterface_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFlashObjectInterface_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFlashObjectInterface_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFlashObjectInterface_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IFlashObjectInterface_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IFlashObjectInterface_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IFlashObjectInterface_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IFlashObjectInterface_GetDispID(This,bstrName,grfdex,pid)	\
    (This)->lpVtbl -> GetDispID(This,bstrName,grfdex,pid)

#define IFlashObjectInterface_RemoteInvokeEx(This,id,lcid,dwFlags,pdp,pvarRes,pei,pspCaller,cvarRefArg,rgiRefArg,rgvarRefArg)	\
    (This)->lpVtbl -> RemoteInvokeEx(This,id,lcid,dwFlags,pdp,pvarRes,pei,pspCaller,cvarRefArg,rgiRefArg,rgvarRefArg)

#define IFlashObjectInterface_DeleteMemberByName(This,bstrName,grfdex)	\
    (This)->lpVtbl -> DeleteMemberByName(This,bstrName,grfdex)

#define IFlashObjectInterface_DeleteMemberByDispID(This,id)	\
    (This)->lpVtbl -> DeleteMemberByDispID(This,id)

#define IFlashObjectInterface_GetMemberProperties(This,id,grfdexFetch,pgrfdex)	\
    (This)->lpVtbl -> GetMemberProperties(This,id,grfdexFetch,pgrfdex)

#define IFlashObjectInterface_GetMemberName(This,id,pbstrName)	\
    (This)->lpVtbl -> GetMemberName(This,id,pbstrName)

#define IFlashObjectInterface_GetNextDispID(This,grfdex,id,pid)	\
    (This)->lpVtbl -> GetNextDispID(This,grfdex,id,pid)

#define IFlashObjectInterface_GetNameSpaceParent(This,ppunk)	\
    (This)->lpVtbl -> GetNameSpaceParent(This,ppunk)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFlashObjectInterface_INTERFACE_DEFINED__ */


#ifndef __IDispatchEx_INTERFACE_DEFINED__
#define __IDispatchEx_INTERFACE_DEFINED__

/* interface IDispatchEx */
/* [object][uuid] */ 


EXTERN_C const IID IID_IDispatchEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6EF9860-C720-11D0-9337-00A0C90DCAA9")
    IDispatchEx : public IDispatch
    {
    public:
        virtual HRESULT __stdcall GetDispID( 
            /* [in] */ BSTR bstrName,
            /* [in] */ unsigned long grfdex,
            /* [out] */ long __RPC_FAR *pid) = 0;
        
        virtual HRESULT __stdcall RemoteInvokeEx( 
            /* [in] */ long id,
            /* [in] */ unsigned long lcid,
            /* [in] */ unsigned long dwFlags,
            /* [in] */ DISPPARAMS __RPC_FAR *pdp,
            /* [out] */ VARIANT __RPC_FAR *pvarRes,
            /* [out] */ EXCEPINFO __RPC_FAR *pei,
            /* [in] */ IServiceProvider __RPC_FAR *pspCaller,
            /* [in] */ unsigned int cvarRefArg,
            /* [in] */ unsigned int __RPC_FAR *rgiRefArg,
            /* [out][in] */ VARIANT __RPC_FAR *rgvarRefArg) = 0;
        
        virtual HRESULT __stdcall DeleteMemberByName( 
            /* [in] */ BSTR bstrName,
            /* [in] */ unsigned long grfdex) = 0;
        
        virtual HRESULT __stdcall DeleteMemberByDispID( 
            /* [in] */ long id) = 0;
        
        virtual HRESULT __stdcall GetMemberProperties( 
            /* [in] */ long id,
            /* [in] */ unsigned long grfdexFetch,
            /* [out] */ unsigned long __RPC_FAR *pgrfdex) = 0;
        
        virtual HRESULT __stdcall GetMemberName( 
            /* [in] */ long id,
            /* [out] */ BSTR __RPC_FAR *pbstrName) = 0;
        
        virtual HRESULT __stdcall GetNextDispID( 
            /* [in] */ unsigned long grfdex,
            /* [in] */ long id,
            /* [out] */ long __RPC_FAR *pid) = 0;
        
        virtual HRESULT __stdcall GetNameSpaceParent( 
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDispatchExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDispatchEx __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDispatchEx __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IDispatchEx __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( __stdcall __RPC_FAR *GetDispID )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ unsigned long grfdex,
            /* [out] */ long __RPC_FAR *pid);
        
        HRESULT ( __stdcall __RPC_FAR *RemoteInvokeEx )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ long id,
            /* [in] */ unsigned long lcid,
            /* [in] */ unsigned long dwFlags,
            /* [in] */ DISPPARAMS __RPC_FAR *pdp,
            /* [out] */ VARIANT __RPC_FAR *pvarRes,
            /* [out] */ EXCEPINFO __RPC_FAR *pei,
            /* [in] */ IServiceProvider __RPC_FAR *pspCaller,
            /* [in] */ unsigned int cvarRefArg,
            /* [in] */ unsigned int __RPC_FAR *rgiRefArg,
            /* [out][in] */ VARIANT __RPC_FAR *rgvarRefArg);
        
        HRESULT ( __stdcall __RPC_FAR *DeleteMemberByName )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ BSTR bstrName,
            /* [in] */ unsigned long grfdex);
        
        HRESULT ( __stdcall __RPC_FAR *DeleteMemberByDispID )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ long id);
        
        HRESULT ( __stdcall __RPC_FAR *GetMemberProperties )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ long id,
            /* [in] */ unsigned long grfdexFetch,
            /* [out] */ unsigned long __RPC_FAR *pgrfdex);
        
        HRESULT ( __stdcall __RPC_FAR *GetMemberName )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ long id,
            /* [out] */ BSTR __RPC_FAR *pbstrName);
        
        HRESULT ( __stdcall __RPC_FAR *GetNextDispID )( 
            IDispatchEx __RPC_FAR * This,
            /* [in] */ unsigned long grfdex,
            /* [in] */ long id,
            /* [out] */ long __RPC_FAR *pid);
        
        HRESULT ( __stdcall __RPC_FAR *GetNameSpaceParent )( 
            IDispatchEx __RPC_FAR * This,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);
        
        END_INTERFACE
    } IDispatchExVtbl;

    interface IDispatchEx
    {
        CONST_VTBL struct IDispatchExVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDispatchEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDispatchEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDispatchEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDispatchEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDispatchEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDispatchEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDispatchEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDispatchEx_GetDispID(This,bstrName,grfdex,pid)	\
    (This)->lpVtbl -> GetDispID(This,bstrName,grfdex,pid)

#define IDispatchEx_RemoteInvokeEx(This,id,lcid,dwFlags,pdp,pvarRes,pei,pspCaller,cvarRefArg,rgiRefArg,rgvarRefArg)	\
    (This)->lpVtbl -> RemoteInvokeEx(This,id,lcid,dwFlags,pdp,pvarRes,pei,pspCaller,cvarRefArg,rgiRefArg,rgvarRefArg)

#define IDispatchEx_DeleteMemberByName(This,bstrName,grfdex)	\
    (This)->lpVtbl -> DeleteMemberByName(This,bstrName,grfdex)

#define IDispatchEx_DeleteMemberByDispID(This,id)	\
    (This)->lpVtbl -> DeleteMemberByDispID(This,id)

#define IDispatchEx_GetMemberProperties(This,id,grfdexFetch,pgrfdex)	\
    (This)->lpVtbl -> GetMemberProperties(This,id,grfdexFetch,pgrfdex)

#define IDispatchEx_GetMemberName(This,id,pbstrName)	\
    (This)->lpVtbl -> GetMemberName(This,id,pbstrName)

#define IDispatchEx_GetNextDispID(This,grfdex,id,pid)	\
    (This)->lpVtbl -> GetNextDispID(This,grfdex,id,pid)

#define IDispatchEx_GetNameSpaceParent(This,ppunk)	\
    (This)->lpVtbl -> GetNameSpaceParent(This,ppunk)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IDispatchEx_GetDispID_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ unsigned long grfdex,
    /* [out] */ long __RPC_FAR *pid);


void __RPC_STUB IDispatchEx_GetDispID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_RemoteInvokeEx_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ long id,
    /* [in] */ unsigned long lcid,
    /* [in] */ unsigned long dwFlags,
    /* [in] */ DISPPARAMS __RPC_FAR *pdp,
    /* [out] */ VARIANT __RPC_FAR *pvarRes,
    /* [out] */ EXCEPINFO __RPC_FAR *pei,
    /* [in] */ IServiceProvider __RPC_FAR *pspCaller,
    /* [in] */ unsigned int cvarRefArg,
    /* [in] */ unsigned int __RPC_FAR *rgiRefArg,
    /* [out][in] */ VARIANT __RPC_FAR *rgvarRefArg);


void __RPC_STUB IDispatchEx_RemoteInvokeEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_DeleteMemberByName_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ BSTR bstrName,
    /* [in] */ unsigned long grfdex);


void __RPC_STUB IDispatchEx_DeleteMemberByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_DeleteMemberByDispID_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ long id);


void __RPC_STUB IDispatchEx_DeleteMemberByDispID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_GetMemberProperties_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ long id,
    /* [in] */ unsigned long grfdexFetch,
    /* [out] */ unsigned long __RPC_FAR *pgrfdex);


void __RPC_STUB IDispatchEx_GetMemberProperties_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_GetMemberName_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ long id,
    /* [out] */ BSTR __RPC_FAR *pbstrName);


void __RPC_STUB IDispatchEx_GetMemberName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_GetNextDispID_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [in] */ unsigned long grfdex,
    /* [in] */ long id,
    /* [out] */ long __RPC_FAR *pid);


void __RPC_STUB IDispatchEx_GetNextDispID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT __stdcall IDispatchEx_GetNameSpaceParent_Proxy( 
    IDispatchEx __RPC_FAR * This,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppunk);


void __RPC_STUB IDispatchEx_GetNameSpaceParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDispatchEx_INTERFACE_DEFINED__ */


#ifndef __IServiceProvider_INTERFACE_DEFINED__
#define __IServiceProvider_INTERFACE_DEFINED__

/* interface IServiceProvider */
/* [object][uuid] */ 


EXTERN_C const IID IID_IServiceProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D5140C1-7436-11CE-8034-00AA006009FA")
    IServiceProvider : public IUnknown
    {
    public:
        virtual HRESULT __stdcall RemoteQueryService( 
            /* [in] */ GUID __RPC_FAR *guidService,
            /* [in] */ GUID __RPC_FAR *riid,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppvObject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IServiceProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IServiceProvider __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IServiceProvider __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IServiceProvider __RPC_FAR * This);
        
        HRESULT ( __stdcall __RPC_FAR *RemoteQueryService )( 
            IServiceProvider __RPC_FAR * This,
            /* [in] */ GUID __RPC_FAR *guidService,
            /* [in] */ GUID __RPC_FAR *riid,
            /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppvObject);
        
        END_INTERFACE
    } IServiceProviderVtbl;

    interface IServiceProvider
    {
        CONST_VTBL struct IServiceProviderVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IServiceProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IServiceProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IServiceProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IServiceProvider_RemoteQueryService(This,guidService,riid,ppvObject)	\
    (This)->lpVtbl -> RemoteQueryService(This,guidService,riid,ppvObject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT __stdcall IServiceProvider_RemoteQueryService_Proxy( 
    IServiceProvider __RPC_FAR * This,
    /* [in] */ GUID __RPC_FAR *guidService,
    /* [in] */ GUID __RPC_FAR *riid,
    /* [out] */ IUnknown __RPC_FAR *__RPC_FAR *ppvObject);


void __RPC_STUB IServiceProvider_RemoteQueryService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IServiceProvider_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ShockwaveFlash;

#ifdef __cplusplus

class DECLSPEC_UUID("D27CDB6E-AE6D-11CF-96B8-444553540000")
ShockwaveFlash;
#endif

EXTERN_C const CLSID CLSID_FlashProp;

#ifdef __cplusplus

class DECLSPEC_UUID("1171A62F-05D2-11D1-83FC-00A0C9089C5A")
FlashProp;
#endif

EXTERN_C const CLSID CLSID_FlashObjectInterface;

#ifdef __cplusplus

class DECLSPEC_UUID("D27CDB71-AE6D-11CF-96B8-444553540000")
FlashObjectInterface;
#endif
#endif /* __ShockwaveFlashObjects_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
