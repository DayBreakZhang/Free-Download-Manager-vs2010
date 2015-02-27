/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/quota/nsIQuotaRequest.idl
 */

#ifndef __gen_nsIQuotaRequest_h__
#define __gen_nsIQuotaRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIQuotaRequest */
#define NS_IQUOTAREQUEST_IID_STR "d96769ed-63ac-4070-ac5a-4b0e1728618a"

#define NS_IQUOTAREQUEST_IID \
  {0xd96769ed, 0x63ac, 0x4070, \
    { 0xac, 0x5a, 0x4b, 0x0e, 0x17, 0x28, 0x61, 0x8a }}

class NS_NO_VTABLE nsIQuotaRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IQUOTAREQUEST_IID)

  /* void cancel (); */
  NS_IMETHOD Cancel(void) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIQuotaRequest, NS_IQUOTAREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIQUOTAREQUEST \
  NS_IMETHOD Cancel(void); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIQUOTAREQUEST(_to) \
  NS_IMETHOD Cancel(void) { return _to Cancel(); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIQUOTAREQUEST(_to) \
  NS_IMETHOD Cancel(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Cancel(); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsQuotaRequest : public nsIQuotaRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIQUOTAREQUEST

  nsQuotaRequest();

private:
  ~nsQuotaRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsQuotaRequest, nsIQuotaRequest)

nsQuotaRequest::nsQuotaRequest()
{
  /* member initializers and constructor code */
}

nsQuotaRequest::~nsQuotaRequest()
{
  /* destructor code */
}

/* void cancel (); */
NS_IMETHODIMP nsQuotaRequest::Cancel()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIQuotaRequest_h__ */
