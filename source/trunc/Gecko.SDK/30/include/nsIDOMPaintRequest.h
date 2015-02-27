/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIDOMPaintRequest.idl
 */

#ifndef __gen_nsIDOMPaintRequest_h__
#define __gen_nsIDOMPaintRequest_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMClientRect; /* forward declaration */


/* starting interface:    nsIDOMPaintRequest */
#define NS_IDOMPAINTREQUEST_IID_STR "9eb5268f-73a4-41da-9790-d21fcefd5ffa"

#define NS_IDOMPAINTREQUEST_IID \
  {0x9eb5268f, 0x73a4, 0x41da, \
    { 0x97, 0x90, 0xd2, 0x1f, 0xce, 0xfd, 0x5f, 0xfa }}

class NS_NO_VTABLE nsIDOMPaintRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMPAINTREQUEST_IID)

  /* readonly attribute nsIDOMClientRect clientRect; */
  NS_IMETHOD GetClientRect(nsIDOMClientRect * *aClientRect) = 0;

  /* [binaryname(XPCOMReason)] readonly attribute DOMString reason; */
  NS_IMETHOD GetXPCOMReason(nsAString & aReason) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMPaintRequest, NS_IDOMPAINTREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMPAINTREQUEST \
  NS_IMETHOD GetClientRect(nsIDOMClientRect * *aClientRect); \
  NS_IMETHOD GetXPCOMReason(nsAString & aReason); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMPAINTREQUEST(_to) \
  NS_IMETHOD GetClientRect(nsIDOMClientRect * *aClientRect) { return _to GetClientRect(aClientRect); } \
  NS_IMETHOD GetXPCOMReason(nsAString & aReason) { return _to GetXPCOMReason(aReason); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMPAINTREQUEST(_to) \
  NS_IMETHOD GetClientRect(nsIDOMClientRect * *aClientRect) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientRect(aClientRect); } \
  NS_IMETHOD GetXPCOMReason(nsAString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetXPCOMReason(aReason); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMPaintRequest : public nsIDOMPaintRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMPAINTREQUEST

  nsDOMPaintRequest();

private:
  ~nsDOMPaintRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMPaintRequest, nsIDOMPaintRequest)

nsDOMPaintRequest::nsDOMPaintRequest()
{
  /* member initializers and constructor code */
}

nsDOMPaintRequest::~nsDOMPaintRequest()
{
  /* destructor code */
}

/* readonly attribute nsIDOMClientRect clientRect; */
NS_IMETHODIMP nsDOMPaintRequest::GetClientRect(nsIDOMClientRect * *aClientRect)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(XPCOMReason)] readonly attribute DOMString reason; */
NS_IMETHODIMP nsDOMPaintRequest::GetXPCOMReason(nsAString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMPaintRequest_h__ */
