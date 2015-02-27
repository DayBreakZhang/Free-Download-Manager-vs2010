/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICacheEntryDoomCallback.idl
 */

#ifndef __gen_nsICacheEntryDoomCallback_h__
#define __gen_nsICacheEntryDoomCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsICacheEntryDoomCallback */
#define NS_ICACHEENTRYDOOMCALLBACK_IID_STR "2f8896be-232f-4140-afb3-1faffb56f3c6"

#define NS_ICACHEENTRYDOOMCALLBACK_IID \
  {0x2f8896be, 0x232f, 0x4140, \
    { 0xaf, 0xb3, 0x1f, 0xaf, 0xfb, 0x56, 0xf3, 0xc6 }}

class NS_NO_VTABLE nsICacheEntryDoomCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICACHEENTRYDOOMCALLBACK_IID)

  /* void onCacheEntryDoomed (in nsresult aResult); */
  NS_IMETHOD OnCacheEntryDoomed(nsresult aResult) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICacheEntryDoomCallback, NS_ICACHEENTRYDOOMCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICACHEENTRYDOOMCALLBACK \
  NS_IMETHOD OnCacheEntryDoomed(nsresult aResult); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICACHEENTRYDOOMCALLBACK(_to) \
  NS_IMETHOD OnCacheEntryDoomed(nsresult aResult) { return _to OnCacheEntryDoomed(aResult); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICACHEENTRYDOOMCALLBACK(_to) \
  NS_IMETHOD OnCacheEntryDoomed(nsresult aResult) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnCacheEntryDoomed(aResult); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCacheEntryDoomCallback : public nsICacheEntryDoomCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICACHEENTRYDOOMCALLBACK

  nsCacheEntryDoomCallback();

private:
  ~nsCacheEntryDoomCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCacheEntryDoomCallback, nsICacheEntryDoomCallback)

nsCacheEntryDoomCallback::nsCacheEntryDoomCallback()
{
  /* member initializers and constructor code */
}

nsCacheEntryDoomCallback::~nsCacheEntryDoomCallback()
{
  /* destructor code */
}

/* void onCacheEntryDoomed (in nsresult aResult); */
NS_IMETHODIMP nsCacheEntryDoomCallback::OnCacheEntryDoomed(nsresult aResult)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICacheEntryDoomCallback_h__ */
