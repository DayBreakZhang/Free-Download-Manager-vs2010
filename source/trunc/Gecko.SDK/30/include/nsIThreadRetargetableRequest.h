/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIThreadRetargetableRequest.idl
 */

#ifndef __gen_nsIThreadRetargetableRequest_h__
#define __gen_nsIThreadRetargetableRequest_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIEventTarget; /* forward declaration */


/* starting interface:    nsIThreadRetargetableRequest */
#define NS_ITHREADRETARGETABLEREQUEST_IID_STR "27b84c48-5a73-4ba4-a8a4-8b5e649a145e"

#define NS_ITHREADRETARGETABLEREQUEST_IID \
  {0x27b84c48, 0x5a73, 0x4ba4, \
    { 0xa8, 0xa4, 0x8b, 0x5e, 0x64, 0x9a, 0x14, 0x5e }}

class NS_NO_VTABLE nsIThreadRetargetableRequest : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITHREADRETARGETABLEREQUEST_IID)

  /* void retargetDeliveryTo (in nsIEventTarget aNewTarget); */
  NS_IMETHOD RetargetDeliveryTo(nsIEventTarget *aNewTarget) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIThreadRetargetableRequest, NS_ITHREADRETARGETABLEREQUEST_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITHREADRETARGETABLEREQUEST \
  NS_IMETHOD RetargetDeliveryTo(nsIEventTarget *aNewTarget); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITHREADRETARGETABLEREQUEST(_to) \
  NS_IMETHOD RetargetDeliveryTo(nsIEventTarget *aNewTarget) { return _to RetargetDeliveryTo(aNewTarget); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITHREADRETARGETABLEREQUEST(_to) \
  NS_IMETHOD RetargetDeliveryTo(nsIEventTarget *aNewTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->RetargetDeliveryTo(aNewTarget); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsThreadRetargetableRequest : public nsIThreadRetargetableRequest
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITHREADRETARGETABLEREQUEST

  nsThreadRetargetableRequest();

private:
  ~nsThreadRetargetableRequest();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsThreadRetargetableRequest, nsIThreadRetargetableRequest)

nsThreadRetargetableRequest::nsThreadRetargetableRequest()
{
  /* member initializers and constructor code */
}

nsThreadRetargetableRequest::~nsThreadRetargetableRequest()
{
  /* destructor code */
}

/* void retargetDeliveryTo (in nsIEventTarget aNewTarget); */
NS_IMETHODIMP nsThreadRetargetableRequest::RetargetDeliveryTo(nsIEventTarget *aNewTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIThreadRetargetableRequest_h__ */
