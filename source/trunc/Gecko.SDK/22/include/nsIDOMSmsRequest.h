/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/dom/mobilemessage/interfaces/nsIDOMSmsRequest.idl
 */

#ifndef __gen_nsIDOMSmsRequest_h__
#define __gen_nsIDOMSmsRequest_h__


#ifndef __gen_nsIDOMDOMRequest_h__
#include "nsIDOMDOMRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozSmsRequest */
#define NS_IDOMMOZSMSREQUEST_IID_STR "d77cafb5-7a91-4631-9597-5e4dcc9d90a5"

#define NS_IDOMMOZSMSREQUEST_IID \
  {0xd77cafb5, 0x7a91, 0x4631, \
    { 0x95, 0x97, 0x5e, 0x4d, 0xcc, 0x9d, 0x90, 0xa5 }}

class NS_NO_VTABLE nsIDOMMozSmsRequest : public nsIDOMDOMRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZSMSREQUEST_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozSmsRequest, NS_IDOMMOZSMSREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZSMSREQUEST \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZSMSREQUEST(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZSMSREQUEST(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozSmsRequest : public nsIDOMMozSmsRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZSMSREQUEST

  nsDOMMozSmsRequest();

private:
  ~nsDOMMozSmsRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozSmsRequest, nsIDOMMozSmsRequest)

nsDOMMozSmsRequest::nsDOMMozSmsRequest()
{
  /* member initializers and constructor code */
}

nsDOMMozSmsRequest::~nsDOMMozSmsRequest()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMSmsRequest_h__ */
