/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrefetchService.idl
 */

#ifndef __gen_nsIPrefetchService_h__
#define __gen_nsIPrefetchService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMNode; /* forward declaration */

class nsISimpleEnumerator; /* forward declaration */


/* starting interface:    nsIPrefetchService */
#define NS_IPREFETCHSERVICE_IID_STR "bc4dbb34-b148-11e2-b82c-08002734a811"

#define NS_IPREFETCHSERVICE_IID \
  {0xbc4dbb34, 0xb148, 0x11e2, \
    { 0xb8, 0x2c, 0x08, 0x00, 0x27, 0x34, 0xa8, 0x11 }}

class NS_NO_VTABLE nsIPrefetchService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFETCHSERVICE_IID)

  /* void prefetchURI (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) = 0;

  /* nsISimpleEnumerator enumerateQueue (); */
  NS_IMETHOD EnumerateQueue(nsISimpleEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefetchService, NS_IPREFETCHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFETCHSERVICE \
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit); \
  NS_IMETHOD EnumerateQueue(nsISimpleEnumerator * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFETCHSERVICE(_to) \
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) { return _to PrefetchURI(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_IMETHOD EnumerateQueue(nsISimpleEnumerator * *_retval) { return _to EnumerateQueue(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFETCHSERVICE(_to) \
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefetchURI(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_IMETHOD EnumerateQueue(nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateQueue(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrefetchService : public nsIPrefetchService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPREFETCHSERVICE

  nsPrefetchService();

private:
  ~nsPrefetchService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrefetchService, nsIPrefetchService)

nsPrefetchService::nsPrefetchService()
{
  /* member initializers and constructor code */
}

nsPrefetchService::~nsPrefetchService()
{
  /* destructor code */
}

/* void prefetchURI (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
NS_IMETHODIMP nsPrefetchService::PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateQueue (); */
NS_IMETHODIMP nsPrefetchService::EnumerateQueue(nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrefetchService_h__ */
