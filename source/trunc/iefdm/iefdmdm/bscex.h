/*
  Free Download Manager Copyright (c) 2003-2014 FreeDownloadManager.ORG
*/

#ifndef __BSCEX_H_
#define __BSCEX_H_

#ifndef __IBindStatusCallbackEx_FWD_DEFINED__
#define __IBindStatusCallbackEx_FWD_DEFINED__
typedef interface IBindStatusCallbackEx IBindStatusCallbackEx;
#endif

#ifndef __IBindStatusCallbackEx_INTERFACE_DEFINED__
#define __IBindStatusCallbackEx_INTERFACE_DEFINED__

typedef IBindStatusCallbackEx *LPBINDSTATUSCALLBACKEX;
typedef enum __WIDL_urlmon_generated_name_00000005 {
    BINDF2_DISABLEBASICOVERHTTP = 0x1,
    BINDF2_DISABLEAUTOCOOKIEHANDLING = 0x2,
    BINDF2_READ_DATA_GREATER_THAN_4GB = 0x4,
    BINDF2_DISABLE_HTTP_REDIRECT_XSECURITYID = 0x8,
    BINDF2_RESERVED_3 = 0x20000000,
    BINDF2_RESERVED_2 = 0x40000000,
    BINDF2_RESERVED_1 = 0x80000000
} BINDF2;
DEFINE_GUID(IID_IBindStatusCallbackEx, 0xaaa74ef9, 0x8ee7, 0x4659, 0x88,0xd9, 0xf8,0xc5,0x04,0xda,0x73,0xcc);
#if defined(__cplusplus) && !defined(CINTERFACE)
interface IBindStatusCallbackEx : public IBindStatusCallback
{
    virtual HRESULT STDMETHODCALLTYPE GetBindInfoEx(
        DWORD *grfBINDF,
        BINDINFO *pbindinfo,
        DWORD *grfBINDF2,
        DWORD *pdwReserved) = 0;

};
#else
typedef struct IBindStatusCallbackExVtbl {
    BEGIN_INTERFACE

    
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IBindStatusCallbackEx* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IBindStatusCallbackEx* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IBindStatusCallbackEx* This);

    
    HRESULT (STDMETHODCALLTYPE *OnStartBinding)(
        IBindStatusCallbackEx* This,
        DWORD dwReserved,
        IBinding *pib);

    HRESULT (STDMETHODCALLTYPE *GetPriority)(
        IBindStatusCallbackEx* This,
        LONG *pnPriority);

    HRESULT (STDMETHODCALLTYPE *OnLowResource)(
        IBindStatusCallbackEx* This,
        DWORD reserved);

    HRESULT (STDMETHODCALLTYPE *OnProgress)(
        IBindStatusCallbackEx* This,
        ULONG ulProgress,
        ULONG ulProgressMax,
        ULONG ulStatusCode,
        LPCWSTR szStatusText);

    HRESULT (STDMETHODCALLTYPE *OnStopBinding)(
        IBindStatusCallbackEx* This,
        HRESULT hresult,
        LPCWSTR szError);

    HRESULT (STDMETHODCALLTYPE *GetBindInfo)(
        IBindStatusCallbackEx* This,
        DWORD *grfBINDF,
        BINDINFO *pbindinfo);

    HRESULT (STDMETHODCALLTYPE *OnDataAvailable)(
        IBindStatusCallbackEx* This,
        DWORD grfBSCF,
        DWORD dwSize,
        FORMATETC *pformatetc,
        STGMEDIUM *pstgmed);

    HRESULT (STDMETHODCALLTYPE *OnObjectAvailable)(
        IBindStatusCallbackEx* This,
        REFIID riid,
        IUnknown *punk);

    
    HRESULT (STDMETHODCALLTYPE *GetBindInfoEx)(
        IBindStatusCallbackEx* This,
        DWORD *grfBINDF,
        BINDINFO *pbindinfo,
        DWORD *grfBINDF2,
        DWORD *pdwReserved);

    END_INTERFACE
} IBindStatusCallbackExVtbl;
interface IBindStatusCallbackEx {
    CONST_VTBL IBindStatusCallbackExVtbl* lpVtbl;
};

#ifdef COBJMACROS

#define IBindStatusCallbackEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBindStatusCallbackEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBindStatusCallbackEx_Release(This) (This)->lpVtbl->Release(This)

#define IBindStatusCallbackEx_OnStartBinding(This,dwReserved,pib) (This)->lpVtbl->OnStartBinding(This,dwReserved,pib)
#define IBindStatusCallbackEx_GetPriority(This,pnPriority) (This)->lpVtbl->GetPriority(This,pnPriority)
#define IBindStatusCallbackEx_OnLowResource(This,reserved) (This)->lpVtbl->OnLowResource(This,reserved)
#define IBindStatusCallbackEx_OnProgress(This,ulProgress,ulProgressMax,ulStatusCode,szStatusText) (This)->lpVtbl->OnProgress(This,ulProgress,ulProgressMax,ulStatusCode,szStatusText)
#define IBindStatusCallbackEx_OnStopBinding(This,hresult,szError) (This)->lpVtbl->OnStopBinding(This,hresult,szError)
#define IBindStatusCallbackEx_GetBindInfo(This,grfBINDF,pbindinfo) (This)->lpVtbl->GetBindInfo(This,grfBINDF,pbindinfo)
#define IBindStatusCallbackEx_OnDataAvailable(This,grfBSCF,dwSize,pformatetc,pstgmed) (This)->lpVtbl->OnDataAvailable(This,grfBSCF,dwSize,pformatetc,pstgmed)
#define IBindStatusCallbackEx_OnObjectAvailable(This,riid,punk) (This)->lpVtbl->OnObjectAvailable(This,riid,punk)

#define IBindStatusCallbackEx_GetBindInfoEx(This,grfBINDF,pbindinfo,grfBINDF2,pdwReserved) (This)->lpVtbl->GetBindInfoEx(This,grfBINDF,pbindinfo,grfBINDF2,pdwReserved)
#endif

#endif

HRESULT STDMETHODCALLTYPE IBindStatusCallbackEx_RemoteGetBindInfoEx_Proxy(
    IBindStatusCallbackEx* This,
    DWORD *grfBINDF,
    RemBINDINFO *pbindinfo,
    RemSTGMEDIUM *pstgmed,
    DWORD *grfBINDF2,
    DWORD *pdwReserved);
void __RPC_STUB IBindStatusCallbackEx_RemoteGetBindInfoEx_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT CALLBACK IBindStatusCallbackEx_GetBindInfoEx_Proxy(
    IBindStatusCallbackEx* This,
    DWORD *grfBINDF,
    BINDINFO *pbindinfo,
    DWORD *grfBINDF2,
    DWORD *pdwReserved);
HRESULT __RPC_STUB IBindStatusCallbackEx_GetBindInfoEx_Stub(
    IBindStatusCallbackEx* This,
    DWORD *grfBINDF,
    RemBINDINFO *pbindinfo,
    RemSTGMEDIUM *pstgmed,
    DWORD *grfBINDF2,
    DWORD *pdwReserved);

#endif  

#endif 