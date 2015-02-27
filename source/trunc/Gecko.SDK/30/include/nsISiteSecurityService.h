/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsISiteSecurityService.idl
 */

#ifndef __gen_nsISiteSecurityService_h__
#define __gen_nsISiteSecurityService_h__


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


/* starting interface:    nsISiteSecurityService */
#define NS_ISITESECURITYSERVICE_IID_STR "b20a9242-5732-45bc-9fa0-a178154f2721"

#define NS_ISITESECURITYSERVICE_IID \
  {0xb20a9242, 0x5732, 0x45bc, \
    { 0x9f, 0xa0, 0xa1, 0x78, 0x15, 0x4f, 0x27, 0x21 }}

class NS_NO_VTABLE nsISiteSecurityService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISITESECURITYSERVICE_IID)

  enum {
    HEADER_HSTS = 0U,
    HEADER_HKPK = 1U,
    HEADER_OMS = 2U
  };

  /* void processHeader (in uint32_t aType, in nsIURI aSourceURI, in string aHeader, in uint32_t aFlags, [optional] out unsigned long long aMaxAge, [optional] out boolean aIncludeSubdomains); */
  NS_IMETHOD ProcessHeader(uint32_t aType, nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains) = 0;

  /* void removeState (in uint32_t aType, in nsIURI aURI, in uint32_t aFlags); */
  NS_IMETHOD RemoveState(uint32_t aType, nsIURI *aURI, uint32_t aFlags) = 0;

  /* boolean isSecureHost (in uint32_t aType, in string aHost, in uint32_t aFlags); */
  NS_IMETHOD IsSecureHost(uint32_t aType, const char * aHost, uint32_t aFlags, bool *_retval) = 0;

  /* boolean shouldIgnoreHeaders (in nsISupports aSecurityInfo); */
  NS_IMETHOD ShouldIgnoreHeaders(nsISupports *aSecurityInfo, bool *_retval) = 0;

  /* boolean isSecureURI (in uint32_t aType, in nsIURI aURI, in uint32_t aFlags); */
  NS_IMETHOD IsSecureURI(uint32_t aType, nsIURI *aURI, uint32_t aFlags, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISiteSecurityService, NS_ISITESECURITYSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISITESECURITYSERVICE \
  NS_IMETHOD ProcessHeader(uint32_t aType, nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains); \
  NS_IMETHOD RemoveState(uint32_t aType, nsIURI *aURI, uint32_t aFlags); \
  NS_IMETHOD IsSecureHost(uint32_t aType, const char * aHost, uint32_t aFlags, bool *_retval); \
  NS_IMETHOD ShouldIgnoreHeaders(nsISupports *aSecurityInfo, bool *_retval); \
  NS_IMETHOD IsSecureURI(uint32_t aType, nsIURI *aURI, uint32_t aFlags, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISITESECURITYSERVICE(_to) \
  NS_IMETHOD ProcessHeader(uint32_t aType, nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains) { return _to ProcessHeader(aType, aSourceURI, aHeader, aFlags, aMaxAge, aIncludeSubdomains); } \
  NS_IMETHOD RemoveState(uint32_t aType, nsIURI *aURI, uint32_t aFlags) { return _to RemoveState(aType, aURI, aFlags); } \
  NS_IMETHOD IsSecureHost(uint32_t aType, const char * aHost, uint32_t aFlags, bool *_retval) { return _to IsSecureHost(aType, aHost, aFlags, _retval); } \
  NS_IMETHOD ShouldIgnoreHeaders(nsISupports *aSecurityInfo, bool *_retval) { return _to ShouldIgnoreHeaders(aSecurityInfo, _retval); } \
  NS_IMETHOD IsSecureURI(uint32_t aType, nsIURI *aURI, uint32_t aFlags, bool *_retval) { return _to IsSecureURI(aType, aURI, aFlags, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISITESECURITYSERVICE(_to) \
  NS_IMETHOD ProcessHeader(uint32_t aType, nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessHeader(aType, aSourceURI, aHeader, aFlags, aMaxAge, aIncludeSubdomains); } \
  NS_IMETHOD RemoveState(uint32_t aType, nsIURI *aURI, uint32_t aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveState(aType, aURI, aFlags); } \
  NS_IMETHOD IsSecureHost(uint32_t aType, const char * aHost, uint32_t aFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSecureHost(aType, aHost, aFlags, _retval); } \
  NS_IMETHOD ShouldIgnoreHeaders(nsISupports *aSecurityInfo, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldIgnoreHeaders(aSecurityInfo, _retval); } \
  NS_IMETHOD IsSecureURI(uint32_t aType, nsIURI *aURI, uint32_t aFlags, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSecureURI(aType, aURI, aFlags, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSiteSecurityService : public nsISiteSecurityService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISITESECURITYSERVICE

  nsSiteSecurityService();

private:
  ~nsSiteSecurityService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSiteSecurityService, nsISiteSecurityService)

nsSiteSecurityService::nsSiteSecurityService()
{
  /* member initializers and constructor code */
}

nsSiteSecurityService::~nsSiteSecurityService()
{
  /* destructor code */
}

/* void processHeader (in uint32_t aType, in nsIURI aSourceURI, in string aHeader, in uint32_t aFlags, [optional] out unsigned long long aMaxAge, [optional] out boolean aIncludeSubdomains); */
NS_IMETHODIMP nsSiteSecurityService::ProcessHeader(uint32_t aType, nsIURI *aSourceURI, const char * aHeader, uint32_t aFlags, uint64_t *aMaxAge, bool *aIncludeSubdomains)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeState (in uint32_t aType, in nsIURI aURI, in uint32_t aFlags); */
NS_IMETHODIMP nsSiteSecurityService::RemoveState(uint32_t aType, nsIURI *aURI, uint32_t aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSecureHost (in uint32_t aType, in string aHost, in uint32_t aFlags); */
NS_IMETHODIMP nsSiteSecurityService::IsSecureHost(uint32_t aType, const char * aHost, uint32_t aFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean shouldIgnoreHeaders (in nsISupports aSecurityInfo); */
NS_IMETHODIMP nsSiteSecurityService::ShouldIgnoreHeaders(nsISupports *aSecurityInfo, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSecureURI (in uint32_t aType, in nsIURI aURI, in uint32_t aFlags); */
NS_IMETHODIMP nsSiteSecurityService::IsSecureURI(uint32_t aType, nsIURI *aURI, uint32_t aFlags, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_SSSERVICE_CONTRACTID "@mozilla.org/ssservice;1"
#define STS_PERMISSION "sts/use"
#define STS_SUBDOMAIN_PERMISSION "sts/subd"

#endif /* __gen_nsISiteSecurityService_h__ */
