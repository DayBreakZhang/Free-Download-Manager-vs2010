/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/uriloader/prefetch/nsIPrefetchService.idl
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
#define NS_IPREFETCHSERVICE_IID_STR "cba513eb-c457-4b93-832c-1a979e66edd1"

#define NS_IPREFETCHSERVICE_IID \
  {0xcba513eb, 0xc457, 0x4b93, \
    { 0x83, 0x2c, 0x1a, 0x97, 0x9e, 0x66, 0xed, 0xd1 }}

class NS_NO_VTABLE nsIPrefetchService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPREFETCHSERVICE_IID)

  /* void prefetchURI (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) = 0;

  /* void prefetchURIForOfflineUse (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
  NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) = 0;

  /* nsISimpleEnumerator enumerateQueue (in boolean aIncludeNormalItems, in boolean aIncludeOfflineItems); */
  NS_IMETHOD EnumerateQueue(bool aIncludeNormalItems, bool aIncludeOfflineItems, nsISimpleEnumerator * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrefetchService, NS_IPREFETCHSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPREFETCHSERVICE \
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit); \
  NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit); \
  NS_IMETHOD EnumerateQueue(bool aIncludeNormalItems, bool aIncludeOfflineItems, nsISimpleEnumerator * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPREFETCHSERVICE(_to) \
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) { return _to PrefetchURI(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) { return _to PrefetchURIForOfflineUse(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_IMETHOD EnumerateQueue(bool aIncludeNormalItems, bool aIncludeOfflineItems, nsISimpleEnumerator * *_retval) { return _to EnumerateQueue(aIncludeNormalItems, aIncludeOfflineItems, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPREFETCHSERVICE(_to) \
  NS_IMETHOD PrefetchURI(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefetchURI(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_IMETHOD PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit) { return !_to ? NS_ERROR_NULL_POINTER : _to->PrefetchURIForOfflineUse(aURI, aReferrerURI, aSource, aExplicit); } \
  NS_IMETHOD EnumerateQueue(bool aIncludeNormalItems, bool aIncludeOfflineItems, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EnumerateQueue(aIncludeNormalItems, aIncludeOfflineItems, _retval); } 

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

/* void prefetchURIForOfflineUse (in nsIURI aURI, in nsIURI aReferrerURI, in nsIDOMNode aSource, in boolean aExplicit); */
NS_IMETHODIMP nsPrefetchService::PrefetchURIForOfflineUse(nsIURI *aURI, nsIURI *aReferrerURI, nsIDOMNode *aSource, bool aExplicit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator enumerateQueue (in boolean aIncludeNormalItems, in boolean aIncludeOfflineItems); */
NS_IMETHODIMP nsPrefetchService::EnumerateQueue(bool aIncludeNormalItems, bool aIncludeOfflineItems, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrefetchService_h__ */
