/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBRequest.idl
 */

#ifndef __gen_nsIIDBRequest_h__
#define __gen_nsIIDBRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMDOMError; /* forward declaration */

class nsIDOMEventListener; /* forward declaration */

class nsIIDBTransaction; /* forward declaration */


/* starting interface:    nsIIDBRequest */
#define NS_IIDBREQUEST_IID_STR "006f39d6-342e-4935-a438-365611fd9491"

#define NS_IIDBREQUEST_IID \
  {0x006f39d6, 0x342e, 0x4935, \
    { 0xa4, 0x38, 0x36, 0x56, 0x11, 0xfd, 0x94, 0x91 }}

class NS_NO_VTABLE nsIIDBRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBREQUEST_IID)

  /* readonly attribute jsval result; */
  NS_IMETHOD GetResult(JS::Value *aResult) = 0;

  /* readonly attribute nsIDOMDOMError error; */
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) = 0;

  /* readonly attribute nsISupports source; */
  NS_IMETHOD GetSource(nsISupports * *aSource) = 0;

  /* readonly attribute nsIIDBTransaction transaction; */
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) = 0;

  /* readonly attribute DOMString readyState; */
  NS_IMETHOD GetReadyState(nsAString & aReadyState) = 0;

  /* [implicit_jscontext] attribute jsval onsuccess; */
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess) = 0;
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess) = 0;

  /* [implicit_jscontext] attribute jsval onerror; */
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) = 0;
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBRequest, NS_IIDBREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBREQUEST \
  NS_IMETHOD GetResult(JS::Value *aResult); \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError); \
  NS_IMETHOD GetSource(nsISupports * *aSource); \
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction); \
  NS_IMETHOD GetReadyState(nsAString & aReadyState); \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess); \
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess); \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror); \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBREQUEST(_to) \
  NS_IMETHOD GetResult(JS::Value *aResult) { return _to GetResult(aResult); } \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) { return _to GetError(aError); } \
  NS_IMETHOD GetSource(nsISupports * *aSource) { return _to GetSource(aSource); } \
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) { return _to GetTransaction(aTransaction); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return _to GetReadyState(aReadyState); } \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess) { return _to GetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess) { return _to SetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return _to GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return _to SetOnerror(cx, aOnerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBREQUEST(_to) \
  NS_IMETHOD GetResult(JS::Value *aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResult(aResult); } \
  NS_IMETHOD GetError(nsIDOMDOMError * *aError) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetError(aError); } \
  NS_IMETHOD GetSource(nsISupports * *aSource) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSource(aSource); } \
  NS_IMETHOD GetTransaction(nsIIDBTransaction * *aTransaction) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTransaction(aTransaction); } \
  NS_IMETHOD GetReadyState(nsAString & aReadyState) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReadyState(aReadyState); } \
  NS_IMETHOD GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsuccess(cx, aOnsuccess); } \
  NS_IMETHOD GetOnerror(JSContext* cx, JS::Value *aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnerror(cx, aOnerror); } \
  NS_IMETHOD SetOnerror(JSContext* cx, const JS::Value & aOnerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnerror(cx, aOnerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBRequest : public nsIIDBRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBREQUEST

  nsIDBRequest();

private:
  ~nsIDBRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBRequest, nsIIDBRequest)

nsIDBRequest::nsIDBRequest()
{
  /* member initializers and constructor code */
}

nsIDBRequest::~nsIDBRequest()
{
  /* destructor code */
}

/* readonly attribute jsval result; */
NS_IMETHODIMP nsIDBRequest::GetResult(JS::Value *aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMDOMError error; */
NS_IMETHODIMP nsIDBRequest::GetError(nsIDOMDOMError * *aError)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports source; */
NS_IMETHODIMP nsIDBRequest::GetSource(nsISupports * *aSource)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIIDBTransaction transaction; */
NS_IMETHODIMP nsIDBRequest::GetTransaction(nsIIDBTransaction * *aTransaction)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString readyState; */
NS_IMETHODIMP nsIDBRequest::GetReadyState(nsAString & aReadyState)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsuccess; */
NS_IMETHODIMP nsIDBRequest::GetOnsuccess(JSContext* cx, JS::Value *aOnsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBRequest::SetOnsuccess(JSContext* cx, const JS::Value & aOnsuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onerror; */
NS_IMETHODIMP nsIDBRequest::GetOnerror(JSContext* cx, JS::Value *aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBRequest::SetOnerror(JSContext* cx, const JS::Value & aOnerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBRequest_h__ */
