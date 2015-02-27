/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIStrictTransportSecurityService.idl
 */

#ifndef __gen_nsIStrictTransportSecurityService_h__
#define __gen_nsIStrictTransportSecurityService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIObserver; /* forward declaration */

class nsIHttpChannel; /* forward declaration */


/* starting interface:    nsIStrictTransportSecurityService */
#define NS_ISTRICTTRANSPORTSECURITYSERVICE_IID_STR "c6138514-f212-4747-98c2-7abfce3be293"

#define NS_ISTRICTTRANSPORTSECURITYSERVICE_IID \
  {0xc6138514, 0xf212, 0x4747, \
    { 0x98, 0xc2, 0x7a, 0xbf, 0xce, 0x3b, 0xe2, 0x93 }}

class NS_NO_VTABLE nsIStrictTransportSecurityService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTRICTTRANSPORTSECURITYSERVICE_IID)

  /* void processStsHeader (in nsIURI aSourceURI, in string aHeader, in uint32_t aFlags, [optional] out unsigned long long aMaxAge, [optional] out boolean aIncludeSubdomains); */
  NS_IMETHOD ProcessStsHeader(nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains) = 0;

  /* void removeStsState (in nsIURI aURI, in uint32_t aFlags); */
  NS_IMETHOD RemoveStsState(nsIURI *aURI, uint32_t aFlags) = 0;

  /* boolean shouldIgnoreStsHeader (in nsISupports aSecurityInfo); */
  NS_IMETHOD ShouldIgnoreStsHeader(nsISupports *aSecurityInfo, bool *_retval) = 0;

  /* boolean isStsHost (in string aHost, in uint32_t aFlags); */
  NS_IMETHOD IsStsHost(const char * aHost, uint32_t aFlags, bool *_retval) = 0;

  /* boolean isStsURI (in nsIURI aURI, in uint32_t aFlags); */
  NS_IMETHOD IsStsURI(nsIURI *aURI, uint32_t aFlags, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStrictTransportSecurityService, NS_ISTRICTTRANSPORTSECURITYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTRICTTRANSPORTSECURITYSERVICE \
  NS_IMETHOD ProcessStsHeader(nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains); \
  NS_IMETHOD RemoveStsState(nsIURI *aURI, uint32_t aFlags); \
  NS_IMETHOD ShouldIgnoreStsHeader(nsISupports *aSecurityInfo, bool *_retval); \
  NS_IMETHOD IsStsHost(const char * aHost, uint32_t aFlags, bool *_retval); \
  NS_IMETHOD IsStsURI(nsIURI *aURI, uint32_t aFlags, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTRICTTRANSPORTSECURITYSERVICE(_to) \
  NS_IMETHOD ProcessStsHeader(nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains) { return _to ProcessStsHeader(aSourceURI, aHeader, aFlags, aMaxAge, aIncludeSubdomains); } \
  NS_IMETHOD RemoveStsState(nsIURI *aURI, uint32_t aFlags) { return _to RemoveStsState(aURI, aFlags); } \
  NS_IMETHOD ShouldIgnoreStsHeader(nsISupports *aSecurityInfo, bool *_retval) { return _to ShouldIgnoreStsHeader(aSecurityInfo, _retval); } \
  NS_IMETHOD IsStsHost(const char * aHost, uint32_t aFlags, bool *_retval) { return _to IsStsHost(aHost, aFlags, _retval); } \
  NS_IMETHOD IsStsURI(nsIURI *aURI, uint32_t aFlags, bool *_retval) { return _to IsStsURI(aURI, aFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTRICTTRANSPORTSECURITYSERVICE(_to) \
  NS_IMETHOD ProcessStsHeader(nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessStsHeader(aSourceURI, aHeader, aFlags, aMaxAge, aIncludeSubdomains); } \
  NS_IMETHOD RemoveStsState(nsIURI *aURI, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveStsState(aURI, aFlags); } \
  NS_IMETHOD ShouldIgnoreStsHeader(nsISupports *aSecurityInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldIgnoreStsHeader(aSecurityInfo, _retval); } \
  NS_IMETHOD IsStsHost(const char * aHost, uint32_t aFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsStsHost(aHost, aFlags, _retval); } \
  NS_IMETHOD IsStsURI(nsIURI *aURI, uint32_t aFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsStsURI(aURI, aFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStrictTransportSecurityService : public nsIStrictTransportSecurityService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTRICTTRANSPORTSECURITYSERVICE

  nsStrictTransportSecurityService();

private:
  ~nsStrictTransportSecurityService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStrictTransportSecurityService, nsIStrictTransportSecurityService)

nsStrictTransportSecurityService::nsStrictTransportSecurityService()
{
  /* member initializers and constructor code */
}

nsStrictTransportSecurityService::~nsStrictTransportSecurityService()
{
  /* destructor code */
}

/* void processStsHeader (in nsIURI aSourceURI, in string aHeader, in uint32_t aFlags, [optional] out unsigned long long aMaxAge, [optional] out boolean aIncludeSubdomains); */
NS_IMETHODIMP nsStrictTransportSecurityService::ProcessStsHeader(nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeStsState (in nsIURI aURI, in uint32_t aFlags); */
NS_IMETHODIMP nsStrictTransportSecurityService::RemoveStsState(nsIURI *aURI, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean shouldIgnoreStsHeader (in nsISupports aSecurityInfo); */
NS_IMETHODIMP nsStrictTransportSecurityService::ShouldIgnoreStsHeader(nsISupports *aSecurityInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isStsHost (in string aHost, in uint32_t aFlags); */
NS_IMETHODIMP nsStrictTransportSecurityService::IsStsHost(const char * aHost, uint32_t aFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isStsURI (in nsIURI aURI, in uint32_t aFlags); */
NS_IMETHODIMP nsStrictTransportSecurityService::IsStsURI(nsIURI *aURI, uint32_t aFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_STSSERVICE_CONTRACTID "@mozilla.org/stsservice;1"
#define STS_PERMISSION "sts/use"
#define STS_SUBDOMAIN_PERMISSION "sts/subd"

#endif /* __gen_nsIStrictTransportSecurityService_h__ */
