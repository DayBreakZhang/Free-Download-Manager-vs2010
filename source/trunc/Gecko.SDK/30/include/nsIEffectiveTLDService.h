/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIEffectiveTLDService.idl
 */

#ifndef __gen_nsIEffectiveTLDService_h__
#define __gen_nsIEffectiveTLDService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */


/* starting interface:    nsIEffectiveTLDService */
#define NS_IEFFECTIVETLDSERVICE_IID_STR "68067eb5-ad8d-43cb-a043-1cc85ebe06e7"

#define NS_IEFFECTIVETLDSERVICE_IID \
  {0x68067eb5, 0xad8d, 0x43cb, \
    { 0xa0, 0x43, 0x1c, 0xc8, 0x5e, 0xbe, 0x06, 0xe7 }}

class NS_NO_VTABLE nsIEffectiveTLDService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEFFECTIVETLDSERVICE_IID)

  /* ACString getPublicSuffix (in nsIURI aURI); */
  NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval) = 0;

  /* ACString getBaseDomain (in nsIURI aURI, [optional] in uint32_t aAdditionalParts); */
  NS_IMETHOD GetBaseDomain(nsIURI *aURI, uint32_t aAdditionalParts, nsACString & _retval) = 0;

  /* ACString getPublicSuffixFromHost (in AUTF8String aHost); */
  NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval) = 0;

  /* ACString getBaseDomainFromHost (in AUTF8String aHost, [optional] in uint32_t aAdditionalParts); */
  NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, uint32_t aAdditionalParts, nsACString & _retval) = 0;

  /* ACString getNextSubDomain (in AUTF8String aHost); */
  NS_IMETHOD GetNextSubDomain(const nsACString & aHost, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIEffectiveTLDService, NS_IEFFECTIVETLDSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEFFECTIVETLDSERVICE \
  NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval); \
  NS_IMETHOD GetBaseDomain(nsIURI *aURI, uint32_t aAdditionalParts, nsACString & _retval); \
  NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval); \
  NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, uint32_t aAdditionalParts, nsACString & _retval); \
  NS_IMETHOD GetNextSubDomain(const nsACString & aHost, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEFFECTIVETLDSERVICE(_to) \
  NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval) { return _to GetPublicSuffix(aURI, _retval); } \
  NS_IMETHOD GetBaseDomain(nsIURI *aURI, uint32_t aAdditionalParts, nsACString & _retval) { return _to GetBaseDomain(aURI, aAdditionalParts, _retval); } \
  NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval) { return _to GetPublicSuffixFromHost(aHost, _retval); } \
  NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, uint32_t aAdditionalParts, nsACString & _retval) { return _to GetBaseDomainFromHost(aHost, aAdditionalParts, _retval); } \
  NS_IMETHOD GetNextSubDomain(const nsACString & aHost, nsACString & _retval) { return _to GetNextSubDomain(aHost, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEFFECTIVETLDSERVICE(_to) \
  NS_IMETHOD GetPublicSuffix(nsIURI *aURI, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicSuffix(aURI, _retval); } \
  NS_IMETHOD GetBaseDomain(nsIURI *aURI, uint32_t aAdditionalParts, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDomain(aURI, aAdditionalParts, _retval); } \
  NS_IMETHOD GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPublicSuffixFromHost(aHost, _retval); } \
  NS_IMETHOD GetBaseDomainFromHost(const nsACString & aHost, uint32_t aAdditionalParts, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDomainFromHost(aHost, aAdditionalParts, _retval); } \
  NS_IMETHOD GetNextSubDomain(const nsACString & aHost, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNextSubDomain(aHost, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsEffectiveTLDService : public nsIEffectiveTLDService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEFFECTIVETLDSERVICE

  nsEffectiveTLDService();

private:
  ~nsEffectiveTLDService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsEffectiveTLDService, nsIEffectiveTLDService)

nsEffectiveTLDService::nsEffectiveTLDService()
{
  /* member initializers and constructor code */
}

nsEffectiveTLDService::~nsEffectiveTLDService()
{
  /* destructor code */
}

/* ACString getPublicSuffix (in nsIURI aURI); */
NS_IMETHODIMP nsEffectiveTLDService::GetPublicSuffix(nsIURI *aURI, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getBaseDomain (in nsIURI aURI, [optional] in uint32_t aAdditionalParts); */
NS_IMETHODIMP nsEffectiveTLDService::GetBaseDomain(nsIURI *aURI, uint32_t aAdditionalParts, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getPublicSuffixFromHost (in AUTF8String aHost); */
NS_IMETHODIMP nsEffectiveTLDService::GetPublicSuffixFromHost(const nsACString & aHost, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getBaseDomainFromHost (in AUTF8String aHost, [optional] in uint32_t aAdditionalParts); */
NS_IMETHODIMP nsEffectiveTLDService::GetBaseDomainFromHost(const nsACString & aHost, uint32_t aAdditionalParts, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString getNextSubDomain (in AUTF8String aHost); */
NS_IMETHODIMP nsEffectiveTLDService::GetNextSubDomain(const nsACString & aHost, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIEffectiveTLDService_h__ */
