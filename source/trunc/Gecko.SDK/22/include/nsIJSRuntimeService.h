/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/js/xpconnect/idl/nsIJSRuntimeService.idl
 */

#ifndef __gen_nsIJSRuntimeService_h__
#define __gen_nsIJSRuntimeService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIXPCScriptable; /* forward declaration */


/* starting interface:    nsIJSRuntimeService */
#define NS_IJSRUNTIMESERVICE_IID_STR "364bcec3-7034-4a4e-bff5-b3f796ca9771"

#define NS_IJSRUNTIMESERVICE_IID \
  {0x364bcec3, 0x7034, 0x4a4e, \
    { 0xbf, 0xf5, 0xb3, 0xf7, 0x96, 0xca, 0x97, 0x71 }}

class NS_NO_VTABLE nsIJSRuntimeService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSRUNTIMESERVICE_IID)

  /* readonly attribute JSRuntime runtime; */
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime) = 0;

  /* readonly attribute nsIXPCScriptable backstagePass; */
  NS_IMETHOD GetBackstagePass(nsIXPCScriptable * *aBackstagePass) = 0;

  /* [noscript,notxpcom] void registerGCCallback (in JSGCCallback func); */
  NS_IMETHOD_(void) RegisterGCCallback(JSGCCallback func) = 0;

  /* [noscript,notxpcom] void unregisterGCCallback (in JSGCCallback func); */
  NS_IMETHOD_(void) UnregisterGCCallback(JSGCCallback func) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSRuntimeService, NS_IJSRUNTIMESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSRUNTIMESERVICE \
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime); \
  NS_IMETHOD GetBackstagePass(nsIXPCScriptable * *aBackstagePass); \
  NS_IMETHOD_(void) RegisterGCCallback(JSGCCallback func); \
  NS_IMETHOD_(void) UnregisterGCCallback(JSGCCallback func); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSRUNTIMESERVICE(_to) \
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime) { return _to GetRuntime(aRuntime); } \
  NS_IMETHOD GetBackstagePass(nsIXPCScriptable * *aBackstagePass) { return _to GetBackstagePass(aBackstagePass); } \
  NS_IMETHOD_(void) RegisterGCCallback(JSGCCallback func) { return _to RegisterGCCallback(func); } \
  NS_IMETHOD_(void) UnregisterGCCallback(JSGCCallback func) { return _to UnregisterGCCallback(func); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSRUNTIMESERVICE(_to) \
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRuntime(aRuntime); } \
  NS_IMETHOD GetBackstagePass(nsIXPCScriptable * *aBackstagePass) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBackstagePass(aBackstagePass); } \
  NS_IMETHOD_(void) RegisterGCCallback(JSGCCallback func); \
  NS_IMETHOD_(void) UnregisterGCCallback(JSGCCallback func); 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsJSRuntimeService : public nsIJSRuntimeService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIJSRUNTIMESERVICE

  nsJSRuntimeService();

private:
  ~nsJSRuntimeService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsJSRuntimeService, nsIJSRuntimeService)

nsJSRuntimeService::nsJSRuntimeService()
{
  /* member initializers and constructor code */
}

nsJSRuntimeService::~nsJSRuntimeService()
{
  /* destructor code */
}

/* readonly attribute JSRuntime runtime; */
NS_IMETHODIMP nsJSRuntimeService::GetRuntime(JSRuntime **aRuntime)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIXPCScriptable backstagePass; */
NS_IMETHODIMP nsJSRuntimeService::GetBackstagePass(nsIXPCScriptable * *aBackstagePass)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void registerGCCallback (in JSGCCallback func); */
NS_IMETHODIMP_(void) nsJSRuntimeService::RegisterGCCallback(JSGCCallback func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void unregisterGCCallback (in JSGCCallback func); */
NS_IMETHODIMP_(void) nsJSRuntimeService::UnregisterGCCallback(JSGCCallback func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSRuntimeService_h__ */
