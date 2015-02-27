/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/indexedDB/nsIIDBOpenDBRequest.idl
 */

#ifndef __gen_nsIIDBOpenDBRequest_h__
#define __gen_nsIIDBOpenDBRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */


/* starting interface:    nsIIDBOpenDBRequest */
#define NS_IIDBOPENDBREQUEST_IID_STR "2d6c5ef4-b84a-45ae-9030-eb6cfc65bb26"

#define NS_IIDBOPENDBREQUEST_IID \
  {0x2d6c5ef4, 0xb84a, 0x45ae, \
    { 0x90, 0x30, 0xeb, 0x6c, 0xfc, 0x65, 0xbb, 0x26 }}

class NS_NO_VTABLE nsIIDBOpenDBRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIDBOPENDBREQUEST_IID)

  /* [implicit_jscontext] attribute jsval onblocked; */
  NS_IMETHOD GetOnblocked(JSContext* cx, JS::Value *aOnblocked) = 0;
  NS_IMETHOD SetOnblocked(JSContext* cx, const JS::Value & aOnblocked) = 0;

  /* [implicit_jscontext] attribute jsval onupgradeneeded; */
  NS_IMETHOD GetOnupgradeneeded(JSContext* cx, JS::Value *aOnupgradeneeded) = 0;
  NS_IMETHOD SetOnupgradeneeded(JSContext* cx, const JS::Value & aOnupgradeneeded) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIDBOpenDBRequest, NS_IIDBOPENDBREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIDBOPENDBREQUEST \
  NS_IMETHOD GetOnblocked(JSContext* cx, JS::Value *aOnblocked); \
  NS_IMETHOD SetOnblocked(JSContext* cx, const JS::Value & aOnblocked); \
  NS_IMETHOD GetOnupgradeneeded(JSContext* cx, JS::Value *aOnupgradeneeded); \
  NS_IMETHOD SetOnupgradeneeded(JSContext* cx, const JS::Value & aOnupgradeneeded); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIDBOPENDBREQUEST(_to) \
  NS_IMETHOD GetOnblocked(JSContext* cx, JS::Value *aOnblocked) { return _to GetOnblocked(cx, aOnblocked); } \
  NS_IMETHOD SetOnblocked(JSContext* cx, const JS::Value & aOnblocked) { return _to SetOnblocked(cx, aOnblocked); } \
  NS_IMETHOD GetOnupgradeneeded(JSContext* cx, JS::Value *aOnupgradeneeded) { return _to GetOnupgradeneeded(cx, aOnupgradeneeded); } \
  NS_IMETHOD SetOnupgradeneeded(JSContext* cx, const JS::Value & aOnupgradeneeded) { return _to SetOnupgradeneeded(cx, aOnupgradeneeded); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIDBOPENDBREQUEST(_to) \
  NS_IMETHOD GetOnblocked(JSContext* cx, JS::Value *aOnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnblocked(cx, aOnblocked); } \
  NS_IMETHOD SetOnblocked(JSContext* cx, const JS::Value & aOnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnblocked(cx, aOnblocked); } \
  NS_IMETHOD GetOnupgradeneeded(JSContext* cx, JS::Value *aOnupgradeneeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnupgradeneeded(cx, aOnupgradeneeded); } \
  NS_IMETHOD SetOnupgradeneeded(JSContext* cx, const JS::Value & aOnupgradeneeded) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnupgradeneeded(cx, aOnupgradeneeded); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIDBOpenDBRequest : public nsIIDBOpenDBRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIDBOPENDBREQUEST

  nsIDBOpenDBRequest();

private:
  ~nsIDBOpenDBRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIDBOpenDBRequest, nsIIDBOpenDBRequest)

nsIDBOpenDBRequest::nsIDBOpenDBRequest()
{
  /* member initializers and constructor code */
}

nsIDBOpenDBRequest::~nsIDBOpenDBRequest()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval onblocked; */
NS_IMETHODIMP nsIDBOpenDBRequest::GetOnblocked(JSContext* cx, JS::Value *aOnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBOpenDBRequest::SetOnblocked(JSContext* cx, const JS::Value & aOnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onupgradeneeded; */
NS_IMETHODIMP nsIDBOpenDBRequest::GetOnupgradeneeded(JSContext* cx, JS::Value *aOnupgradeneeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIDBOpenDBRequest::SetOnupgradeneeded(JSContext* cx, const JS::Value & aOnupgradeneeded)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIIDBOpenDBRequest_h__ */
