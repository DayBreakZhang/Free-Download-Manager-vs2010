/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cache/nsICacheListener.idl
 */

#ifndef __gen_nsICacheListener_h__
#define __gen_nsICacheListener_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsICache_h__
#include "nsICache.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICacheEntryDescriptor; /* forward declaration */


/* starting interface:    nsICacheListener */
#define NS_ICACHELISTENER_IID_STR "8eadf2ed-8cac-4961-8025-6da6d5827e74"

#define NS_ICACHELISTENER_IID \
  {0x8eadf2ed, 0x8cac, 0x4961, \
    { 0x80, 0x25, 0x6d, 0xa6, 0xd5, 0x82, 0x7e, 0x74 }}

class NS_NO_VTABLE nsICacheListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHELISTENER_IID)

  /* void onCacheEntryAvailable (in nsICacheEntryDescriptor descriptor, in nsCacheAccessMode accessGranted, in nsresult status); */
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status) = 0;

  /* void onCacheEntryDoomed (in nsresult status); */
  NS_IMETHOD OnCacheEntryDoomed(nsresult status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheListener, NS_ICACHELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHELISTENER \
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status); \
  NS_IMETHOD OnCacheEntryDoomed(nsresult status); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHELISTENER(_to) \
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status) { return _to OnCacheEntryAvailable(descriptor, accessGranted, status); } \
  NS_IMETHOD OnCacheEntryDoomed(nsresult status) { return _to OnCacheEntryDoomed(status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHELISTENER(_to) \
  NS_IMETHOD OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryAvailable(descriptor, accessGranted, status); } \
  NS_IMETHOD OnCacheEntryDoomed(nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryDoomed(status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheListener : public nsICacheListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHELISTENER

  nsCacheListener();

private:
  ~nsCacheListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheListener, nsICacheListener)

nsCacheListener::nsCacheListener()
{
  /* member initializers and constructor code */
}

nsCacheListener::~nsCacheListener()
{
  /* destructor code */
}

/* void onCacheEntryAvailable (in nsICacheEntryDescriptor descriptor, in nsCacheAccessMode accessGranted, in nsresult status); */
NS_IMETHODIMP nsCacheListener::OnCacheEntryAvailable(nsICacheEntryDescriptor *descriptor, nsCacheAccessMode accessGranted, nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onCacheEntryDoomed (in nsresult status); */
NS_IMETHODIMP nsCacheListener::OnCacheEntryDoomed(nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheListener_h__ */
