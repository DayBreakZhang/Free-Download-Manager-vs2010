/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheEntryOpenCallback.idl
 */

#ifndef __gen_nsICacheEntryOpenCallback_h__
#define __gen_nsICacheEntryOpenCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheEntry; /* forward declaration */

class nsIApplicationCache; /* forward declaration */


/* starting interface:    nsICacheEntryOpenCallback */
#define NS_ICACHEENTRYOPENCALLBACK_IID_STR "1fc9fe11-c6ac-4748-94bd-8555a5a12b94"

#define NS_ICACHEENTRYOPENCALLBACK_IID \
  {0x1fc9fe11, 0xc6ac, 0x4748, \
    { 0x94, 0xbd, 0x85, 0x55, 0xa5, 0xa1, 0x2b, 0x94 }}

class NS_NO_VTABLE nsICacheEntryOpenCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRYOPENCALLBACK_IID)

  enum {
    ENTRY_WANTED = 0U,
    RECHECK_AFTER_WRITE_FINISHED = 1U,
    ENTRY_NEEDS_REVALIDATION = 2U,
    ENTRY_NOT_WANTED = 3U
  };

  /* unsigned long onCacheEntryCheck (in nsICacheEntry aEntry, in nsIApplicationCache aApplicationCache); */
  NS_IMETHOD OnCacheEntryCheck(nsICacheEntry *aEntry, nsIApplicationCache *aApplicationCache, uint32_t *_retval) = 0;

  /* void onCacheEntryAvailable (in nsICacheEntry aEntry, in boolean aNew, in nsIApplicationCache aApplicationCache, in nsresult aResult); */
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntry *aEntry, bool aNew, nsIApplicationCache *aApplicationCache, nsresult aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntryOpenCallback, NS_ICACHEENTRYOPENCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRYOPENCALLBACK \
  NS_IMETHOD OnCacheEntryCheck(nsICacheEntry *aEntry, nsIApplicationCache *aApplicationCache, uint32_t *_retval); \
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntry *aEntry, bool aNew, nsIApplicationCache *aApplicationCache, nsresult aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRYOPENCALLBACK(_to) \
  NS_IMETHOD OnCacheEntryCheck(nsICacheEntry *aEntry, nsIApplicationCache *aApplicationCache, uint32_t *_retval) { return _to OnCacheEntryCheck(aEntry, aApplicationCache, _retval); } \
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntry *aEntry, bool aNew, nsIApplicationCache *aApplicationCache, nsresult aResult) { return _to OnCacheEntryAvailable(aEntry, aNew, aApplicationCache, aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRYOPENCALLBACK(_to) \
  NS_IMETHOD OnCacheEntryCheck(nsICacheEntry *aEntry, nsIApplicationCache *aApplicationCache, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryCheck(aEntry, aApplicationCache, _retval); } \
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntry *aEntry, bool aNew, nsIApplicationCache *aApplicationCache, nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryAvailable(aEntry, aNew, aApplicationCache, aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntryOpenCallback : public nsICacheEntryOpenCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRYOPENCALLBACK

  nsCacheEntryOpenCallback();

private:
  ~nsCacheEntryOpenCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheEntryOpenCallback, nsICacheEntryOpenCallback)

nsCacheEntryOpenCallback::nsCacheEntryOpenCallback()
{
  /* member initializers and constructor code */
}

nsCacheEntryOpenCallback::~nsCacheEntryOpenCallback()
{
  /* destructor code */
}

/* unsigned long onCacheEntryCheck (in nsICacheEntry aEntry, in nsIApplicationCache aApplicationCache); */
NS_IMETHODIMP nsCacheEntryOpenCallback::OnCacheEntryCheck(nsICacheEntry *aEntry, nsIApplicationCache *aApplicationCache, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCacheEntryAvailable (in nsICacheEntry aEntry, in boolean aNew, in nsIApplicationCache aApplicationCache, in nsresult aResult); */
NS_IMETHODIMP nsCacheEntryOpenCallback::OnCacheEntryAvailable(nsICacheEntry *aEntry, bool aNew, nsIApplicationCache *aApplicationCache, nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheEntryOpenCallback_h__ */
