/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIJSRuntimeService.idl
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

#include "jsapi.h"  // for JSGCStatus
typedef void
(* xpcGCCallback)(JSGCStatus status);
typedef bool
(* xpcContextCallback)(JSContext* cx, unsigned operation);
class nsIBackstagePass; /* forward declaration */


/* starting interface:    nsIJSRuntimeService */
#define NS_IJSRUNTIMESERVICE_IID_STR "2ac111f2-e492-488e-85df-353c453e98f3"

#define NS_IJSRUNTIMESERVICE_IID \
  {0x2ac111f2, 0xe492, 0x488e, \
    { 0x85, 0xdf, 0x35, 0x3c, 0x45, 0x3e, 0x98, 0xf3 }}

class NS_NO_VTABLE nsIJSRuntimeService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IJSRUNTIMESERVICE_IID)

  /* readonly attribute JSRuntime runtime; */
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime) = 0;

  /* [noscript,notxpcom] void registerGCCallback (in xpcGCCallback func); */
  NS_IMETHOD_(void) RegisterGCCallback(xpcGCCallback func) = 0;

  /* [noscript,notxpcom] void unregisterGCCallback (in xpcGCCallback func); */
  NS_IMETHOD_(void) UnregisterGCCallback(xpcGCCallback func) = 0;

  /* [noscript,notxpcom] void registerContextCallback (in xpcContextCallback func); */
  NS_IMETHOD_(void) RegisterContextCallback(xpcContextCallback func) = 0;

  /* [noscript,notxpcom] void unregisterContextCallback (in xpcContextCallback func); */
  NS_IMETHOD_(void) UnregisterContextCallback(xpcContextCallback func) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIJSRuntimeService, NS_IJSRUNTIMESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIJSRUNTIMESERVICE \
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime); \
  NS_IMETHOD_(void) RegisterGCCallback(xpcGCCallback func); \
  NS_IMETHOD_(void) UnregisterGCCallback(xpcGCCallback func); \
  NS_IMETHOD_(void) RegisterContextCallback(xpcContextCallback func); \
  NS_IMETHOD_(void) UnregisterContextCallback(xpcContextCallback func); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIJSRUNTIMESERVICE(_to) \
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime) { return _to GetRuntime(aRuntime); } \
  NS_IMETHOD_(void) RegisterGCCallback(xpcGCCallback func) { return _to RegisterGCCallback(func); } \
  NS_IMETHOD_(void) UnregisterGCCallback(xpcGCCallback func) { return _to UnregisterGCCallback(func); } \
  NS_IMETHOD_(void) RegisterContextCallback(xpcContextCallback func) { return _to RegisterContextCallback(func); } \
  NS_IMETHOD_(void) UnregisterContextCallback(xpcContextCallback func) { return _to UnregisterContextCallback(func); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIJSRUNTIMESERVICE(_to) \
  NS_IMETHOD GetRuntime(JSRuntime **aRuntime) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRuntime(aRuntime); } \
  NS_IMETHOD_(void) RegisterGCCallback(xpcGCCallback func); \
  NS_IMETHOD_(void) UnregisterGCCallback(xpcGCCallback func); \
  NS_IMETHOD_(void) RegisterContextCallback(xpcContextCallback func); \
  NS_IMETHOD_(void) UnregisterContextCallback(xpcContextCallback func); 

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

/* [noscript,notxpcom] void registerGCCallback (in xpcGCCallback func); */
NS_IMETHODIMP_(void) nsJSRuntimeService::RegisterGCCallback(xpcGCCallback func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void unregisterGCCallback (in xpcGCCallback func); */
NS_IMETHODIMP_(void) nsJSRuntimeService::UnregisterGCCallback(xpcGCCallback func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void registerContextCallback (in xpcContextCallback func); */
NS_IMETHODIMP_(void) nsJSRuntimeService::RegisterContextCallback(xpcContextCallback func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript,notxpcom] void unregisterContextCallback (in xpcContextCallback func); */
NS_IMETHODIMP_(void) nsJSRuntimeService::UnregisterContextCallback(xpcContextCallback func)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIJSRuntimeService_h__ */
