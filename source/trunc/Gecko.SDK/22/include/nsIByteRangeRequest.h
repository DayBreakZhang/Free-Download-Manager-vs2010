/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIByteRangeRequest.idl
 */

#ifndef __gen_nsIByteRangeRequest_h__
#define __gen_nsIByteRangeRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIByteRangeRequest */
#define NS_IBYTERANGEREQUEST_IID_STR "c1b1f426-7e83-4759-9f88-0e1b17f49366"

#define NS_IBYTERANGEREQUEST_IID \
  {0xc1b1f426, 0x7e83, 0x4759, \
    { 0x9f, 0x88, 0x0e, 0x1b, 0x17, 0xf4, 0x93, 0x66 }}

class NS_NO_VTABLE nsIByteRangeRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IBYTERANGEREQUEST_IID)

  /* readonly attribute boolean isByteRangeRequest; */
  NS_IMETHOD GetIsByteRangeRequest(bool *aIsByteRangeRequest) = 0;

  /* readonly attribute long long startRange; */
  NS_IMETHOD GetStartRange(int64_t *aStartRange) = 0;

  /* readonly attribute long long endRange; */
  NS_IMETHOD GetEndRange(int64_t *aEndRange) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIByteRangeRequest, NS_IBYTERANGEREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIBYTERANGEREQUEST \
  NS_IMETHOD GetIsByteRangeRequest(bool *aIsByteRangeRequest); \
  NS_IMETHOD GetStartRange(int64_t *aStartRange); \
  NS_IMETHOD GetEndRange(int64_t *aEndRange); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIBYTERANGEREQUEST(_to) \
  NS_IMETHOD GetIsByteRangeRequest(bool *aIsByteRangeRequest) { return _to GetIsByteRangeRequest(aIsByteRangeRequest); } \
  NS_IMETHOD GetStartRange(int64_t *aStartRange) { return _to GetStartRange(aStartRange); } \
  NS_IMETHOD GetEndRange(int64_t *aEndRange) { return _to GetEndRange(aEndRange); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIBYTERANGEREQUEST(_to) \
  NS_IMETHOD GetIsByteRangeRequest(bool *aIsByteRangeRequest) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsByteRangeRequest(aIsByteRangeRequest); } \
  NS_IMETHOD GetStartRange(int64_t *aStartRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStartRange(aStartRange); } \
  NS_IMETHOD GetEndRange(int64_t *aEndRange) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEndRange(aEndRange); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsByteRangeRequest : public nsIByteRangeRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIBYTERANGEREQUEST

  nsByteRangeRequest();

private:
  ~nsByteRangeRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsByteRangeRequest, nsIByteRangeRequest)

nsByteRangeRequest::nsByteRangeRequest()
{
  /* member initializers and constructor code */
}

nsByteRangeRequest::~nsByteRangeRequest()
{
  /* destructor code */
}

/* readonly attribute boolean isByteRangeRequest; */
NS_IMETHODIMP nsByteRangeRequest::GetIsByteRangeRequest(bool *aIsByteRangeRequest)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long startRange; */
NS_IMETHODIMP nsByteRangeRequest::GetStartRange(int64_t *aStartRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long long endRange; */
NS_IMETHODIMP nsByteRangeRequest::GetEndRange(int64_t *aEndRange)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIByteRangeRequest_h__ */
