/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIURIChecker.idl
 */

#ifndef __gen_nsIURIChecker_h__
#define __gen_nsIURIChecker_h__


#ifndef __gen_nsIRequest_h__
#include "nsIRequest.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIRequestObserver; /* forward declaration */


/* starting interface:    nsIURIChecker */
#define NS_IURICHECKER_IID_STR "4660c1a1-be2d-4c78-9baf-c22984176c28"

#define NS_IURICHECKER_IID \
  {0x4660c1a1, 0xbe2d, 0x4c78, \
    { 0x9b, 0xaf, 0xc2, 0x29, 0x84, 0x17, 0x6c, 0x28 }}

class NS_NO_VTABLE nsIURIChecker : public nsIRequest {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURICHECKER_IID)

  /* void init (in nsIURI aURI); */
  NS_IMETHOD Init(nsIURI *aURI) = 0;

  /* readonly attribute nsIChannel baseChannel; */
  NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) = 0;

  /* void asyncCheck (in nsIRequestObserver aObserver, in nsISupports aContext); */
  NS_IMETHOD AsyncCheck(nsIRequestObserver *aObserver, nsISupports *aContext) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIChecker, NS_IURICHECKER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURICHECKER \
  NS_IMETHOD Init(nsIURI *aURI); \
  NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel); \
  NS_IMETHOD AsyncCheck(nsIRequestObserver *aObserver, nsISupports *aContext); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURICHECKER(_to) \
  NS_IMETHOD Init(nsIURI *aURI) { return _to Init(aURI); } \
  NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) { return _to GetBaseChannel(aBaseChannel); } \
  NS_IMETHOD AsyncCheck(nsIRequestObserver *aObserver, nsISupports *aContext) { return _to AsyncCheck(aObserver, aContext); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURICHECKER(_to) \
  NS_IMETHOD Init(nsIURI *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aURI); } \
  NS_IMETHOD GetBaseChannel(nsIChannel * *aBaseChannel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseChannel(aBaseChannel); } \
  NS_IMETHOD AsyncCheck(nsIRequestObserver *aObserver, nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncCheck(aObserver, aContext); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIChecker : public nsIURIChecker
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURICHECKER

  nsURIChecker();

private:
  ~nsURIChecker();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIChecker, nsIURIChecker)

nsURIChecker::nsURIChecker()
{
  /* member initializers and constructor code */
}

nsURIChecker::~nsURIChecker()
{
  /* destructor code */
}

/* void init (in nsIURI aURI); */
NS_IMETHODIMP nsURIChecker::Init(nsIURI *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIChannel baseChannel; */
NS_IMETHODIMP nsURIChecker::GetBaseChannel(nsIChannel * *aBaseChannel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncCheck (in nsIRequestObserver aObserver, in nsISupports aContext); */
NS_IMETHODIMP nsURIChecker::AsyncCheck(nsIRequestObserver *aObserver, nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIChecker_h__ */
