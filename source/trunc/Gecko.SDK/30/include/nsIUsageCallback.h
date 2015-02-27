/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUsageCallback.idl
 */

#ifndef __gen_nsIUsageCallback_h__
#define __gen_nsIUsageCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIUsageCallback */
#define NS_IUSAGECALLBACK_IID_STR "7b0f9928-0ddc-42c7-b9f2-6b2308b90b18"

#define NS_IUSAGECALLBACK_IID \
  {0x7b0f9928, 0x0ddc, 0x42c7, \
    { 0xb9, 0xf2, 0x6b, 0x23, 0x08, 0xb9, 0x0b, 0x18 }}

class NS_NO_VTABLE nsIUsageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUSAGECALLBACK_IID)

  /* void onUsageResult (in nsIURI aURI, in unsigned long long aUsage, in unsigned long long aFileUsage, in unsigned long aAppId, in boolean aInMozBrowserOnly); */
  NS_IMETHOD OnUsageResult(nsIURI *aURI, uint64_t aUsage, uint64_t aFileUsage, uint32_t aAppId, bool aInMozBrowserOnly) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUsageCallback, NS_IUSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUSAGECALLBACK \
  NS_IMETHOD OnUsageResult(nsIURI *aURI, uint64_t aUsage, uint64_t aFileUsage, uint32_t aAppId, bool aInMozBrowserOnly); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUSAGECALLBACK(_to) \
  NS_IMETHOD OnUsageResult(nsIURI *aURI, uint64_t aUsage, uint64_t aFileUsage, uint32_t aAppId, bool aInMozBrowserOnly) { return _to OnUsageResult(aURI, aUsage, aFileUsage, aAppId, aInMozBrowserOnly); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUSAGECALLBACK(_to) \
  NS_IMETHOD OnUsageResult(nsIURI *aURI, uint64_t aUsage, uint64_t aFileUsage, uint32_t aAppId, bool aInMozBrowserOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnUsageResult(aURI, aUsage, aFileUsage, aAppId, aInMozBrowserOnly); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUsageCallback : public nsIUsageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUSAGECALLBACK

  nsUsageCallback();

private:
  ~nsUsageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUsageCallback, nsIUsageCallback)

nsUsageCallback::nsUsageCallback()
{
  /* member initializers and constructor code */
}

nsUsageCallback::~nsUsageCallback()
{
  /* destructor code */
}

/* void onUsageResult (in nsIURI aURI, in unsigned long long aUsage, in unsigned long long aFileUsage, in unsigned long aAppId, in boolean aInMozBrowserOnly); */
NS_IMETHODIMP nsUsageCallback::OnUsageResult(nsIURI *aURI, uint64_t aUsage, uint64_t aFileUsage, uint32_t aAppId, bool aInMozBrowserOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUsageCallback_h__ */
