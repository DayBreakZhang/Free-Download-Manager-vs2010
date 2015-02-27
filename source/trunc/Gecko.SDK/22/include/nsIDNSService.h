/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/dns/nsIDNSService.idl
 */

#ifndef __gen_nsIDNSService_h__
#define __gen_nsIDNSService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICancelable; /* forward declaration */

class nsIEventTarget; /* forward declaration */

class nsIDNSRecord; /* forward declaration */

class nsIDNSListener; /* forward declaration */

#include "nsTArray.h"
namespace mozilla { namespace net {
    struct DNSCacheEntries;
} }

/* starting interface:    nsIDNSService */
#define NS_IDNSSERVICE_IID_STR "f1971942-19db-44bf-81e8-d15df220a39f"

#define NS_IDNSSERVICE_IID \
  {0xf1971942, 0x19db, 0x44bf, \
    { 0x81, 0xe8, 0xd1, 0x5d, 0xf2, 0x20, 0xa3, 0x9f }}

class NS_NO_VTABLE nsIDNSService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDNSSERVICE_IID)

  /* nsICancelable asyncResolve (in AUTF8String aHostName, in unsigned long aFlags, in nsIDNSListener aListener, in nsIEventTarget aListenerTarget); */
  NS_IMETHOD AsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable * *_retval) = 0;

  /* void cancelAsyncResolve (in AUTF8String aHostName, in unsigned long aFlags, in nsIDNSListener aListener, in nsresult aReason); */
  NS_IMETHOD CancelAsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsresult aReason) = 0;

  /* nsIDNSRecord resolve (in AUTF8String aHostName, in unsigned long aFlags); */
  NS_IMETHOD Resolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSRecord * *_retval) = 0;

  /* [noscript] void getDNSCacheEntries (in EntriesArray args); */
  NS_IMETHOD GetDNSCacheEntries(nsTArray<mozilla::net::DNSCacheEntries> *args) = 0;

  /* readonly attribute AUTF8String myHostName; */
  NS_IMETHOD GetMyHostName(nsACString & aMyHostName) = 0;

  enum {
    RESOLVE_BYPASS_CACHE = 1U,
    RESOLVE_CANONICAL_NAME = 2U,
    RESOLVE_PRIORITY_MEDIUM = 4U,
    RESOLVE_PRIORITY_LOW = 8U,
    RESOLVE_SPECULATE = 16U,
    RESOLVE_DISABLE_IPV6 = 32U,
    RESOLVE_OFFLINE = 64U,
    RESOLVE_DISABLE_IPV4 = 128U
  };

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDNSService, NS_IDNSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDNSSERVICE \
  NS_IMETHOD AsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable * *_retval); \
  NS_IMETHOD CancelAsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsresult aReason); \
  NS_IMETHOD Resolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSRecord * *_retval); \
  NS_IMETHOD GetDNSCacheEntries(nsTArray<mozilla::net::DNSCacheEntries> *args); \
  NS_IMETHOD GetMyHostName(nsACString & aMyHostName); \

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDNSSERVICE(_to) \
  NS_IMETHOD AsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable * *_retval) { return _to AsyncResolve(aHostName, aFlags, aListener, aListenerTarget, _retval); } \
  NS_IMETHOD CancelAsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsresult aReason) { return _to CancelAsyncResolve(aHostName, aFlags, aListener, aReason); } \
  NS_IMETHOD Resolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSRecord * *_retval) { return _to Resolve(aHostName, aFlags, _retval); } \
  NS_IMETHOD GetDNSCacheEntries(nsTArray<mozilla::net::DNSCacheEntries> *args) { return _to GetDNSCacheEntries(args); } \
  NS_IMETHOD GetMyHostName(nsACString & aMyHostName) { return _to GetMyHostName(aMyHostName); } \

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDNSSERVICE(_to) \
  NS_IMETHOD AsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncResolve(aHostName, aFlags, aListener, aListenerTarget, _retval); } \
  NS_IMETHOD CancelAsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsresult aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->CancelAsyncResolve(aHostName, aFlags, aListener, aReason); } \
  NS_IMETHOD Resolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSRecord * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Resolve(aHostName, aFlags, _retval); } \
  NS_IMETHOD GetDNSCacheEntries(nsTArray<mozilla::net::DNSCacheEntries> *args) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDNSCacheEntries(args); } \
  NS_IMETHOD GetMyHostName(nsACString & aMyHostName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMyHostName(aMyHostName); } \

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDNSService : public nsIDNSService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDNSSERVICE

  nsDNSService();

private:
  ~nsDNSService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDNSService, nsIDNSService)

nsDNSService::nsDNSService()
{
  /* member initializers and constructor code */
}

nsDNSService::~nsDNSService()
{
  /* destructor code */
}

/* nsICancelable asyncResolve (in AUTF8String aHostName, in unsigned long aFlags, in nsIDNSListener aListener, in nsIEventTarget aListenerTarget); */
NS_IMETHODIMP nsDNSService::AsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsIEventTarget *aListenerTarget, nsICancelable * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void cancelAsyncResolve (in AUTF8String aHostName, in unsigned long aFlags, in nsIDNSListener aListener, in nsresult aReason); */
NS_IMETHODIMP nsDNSService::CancelAsyncResolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSListener *aListener, nsresult aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDNSRecord resolve (in AUTF8String aHostName, in unsigned long aFlags); */
NS_IMETHODIMP nsDNSService::Resolve(const nsACString & aHostName, uint32_t aFlags, nsIDNSRecord * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void getDNSCacheEntries (in EntriesArray args); */
NS_IMETHODIMP nsDNSService::GetDNSCacheEntries(nsTArray<mozilla::net::DNSCacheEntries> *args)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String myHostName; */
NS_IMETHODIMP nsDNSService::GetMyHostName(nsACString & aMyHostName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDNSService_h__ */
