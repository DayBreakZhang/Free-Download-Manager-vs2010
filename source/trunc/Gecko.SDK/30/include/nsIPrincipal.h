/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIPrincipal.idl
 */

#ifndef __gen_nsIPrincipal_h__
#define __gen_nsIPrincipal_h__


#ifndef __gen_nsISerializable_h__
#include "nsISerializable.h"
#endif

#include "mozilla/Assertions.h"
#include "mozilla/DebugOnly.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
struct JSPrincipals;
#include "nsCOMPtr.h"
#include "nsTArray.h"
class nsIURI; /* forward declaration */

class nsIContentSecurityPolicy; /* forward declaration */


/* starting interface:    nsIPrincipal */
#define NS_IPRINCIPAL_IID_STR "204555e7-04ad-4cc8-9f0e-840615cc43e8"

#define NS_IPRINCIPAL_IID \
  {0x204555e7, 0x04ad, 0x4cc8, \
    { 0x9f, 0x0e, 0x84, 0x06, 0x15, 0xcc, 0x43, 0xe8 }}

class nsIPrincipal : public nsISerializable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPRINCIPAL_IID)

  /* boolean equals (in nsIPrincipal other); */
  NS_IMETHOD Equals(nsIPrincipal *other, bool *_retval) = 0;

  /* boolean equalsConsideringDomain (in nsIPrincipal other); */
  NS_IMETHOD EqualsConsideringDomain(nsIPrincipal *other, bool *_retval) = 0;

     inline bool Equals(nsIPrincipal* aOther) {
      bool equal = false;
      return NS_SUCCEEDED(Equals(aOther, &equal)) && equal;
    }
    inline bool EqualsConsideringDomain(nsIPrincipal* aOther) {
      bool equal = false;
      return NS_SUCCEEDED(EqualsConsideringDomain(aOther, &equal)) && equal;
    }
      /* [noscript] readonly attribute unsigned long hashValue; */
  NS_IMETHOD GetHashValue(uint32_t *aHashValue) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* [noscript] attribute nsIURI domain; */
  NS_IMETHOD GetDomain(nsIURI * *aDomain) = 0;
  NS_IMETHOD SetDomain(nsIURI *aDomain) = 0;

  /* readonly attribute string origin; */
  NS_IMETHOD GetOrigin(char * *aOrigin) = 0;

  /* boolean subsumes (in nsIPrincipal other); */
  NS_IMETHOD Subsumes(nsIPrincipal *other, bool *_retval) = 0;

  /* boolean subsumesConsideringDomain (in nsIPrincipal other); */
  NS_IMETHOD SubsumesConsideringDomain(nsIPrincipal *other, bool *_retval) = 0;

     inline bool Subsumes(nsIPrincipal* aOther) {
      bool subsumes = false;
      return NS_SUCCEEDED(Subsumes(aOther, &subsumes)) && subsumes;
    }
    inline bool SubsumesConsideringDomain(nsIPrincipal* aOther) {
      bool subsumes = false;
      return NS_SUCCEEDED(SubsumesConsideringDomain(aOther, &subsumes)) && subsumes;
    }
      /* void checkMayLoad (in nsIURI uri, in boolean report, in boolean allowIfInheritsPrincipal); */
  NS_IMETHOD CheckMayLoad(nsIURI *uri, bool report, bool allowIfInheritsPrincipal) = 0;

  /* [noscript] attribute nsIContentSecurityPolicy csp; */
  NS_IMETHOD GetCsp(nsIContentSecurityPolicy * *aCsp) = 0;
  NS_IMETHOD SetCsp(nsIContentSecurityPolicy *aCsp) = 0;

  /* readonly attribute AUTF8String jarPrefix; */
  NS_IMETHOD GetJarPrefix(nsACString & aJarPrefix) = 0;

  /* readonly attribute ACString baseDomain; */
  NS_IMETHOD GetBaseDomain(nsACString & aBaseDomain) = 0;

  enum {
    APP_STATUS_NOT_INSTALLED = 0,
    APP_STATUS_INSTALLED = 1,
    APP_STATUS_PRIVILEGED = 2,
    APP_STATUS_CERTIFIED = 3
  };

  /* [infallible] readonly attribute unsigned short appStatus; */
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) = 0;
  inline uint16_t GetAppStatus()
  {
    uint16_t result;
    mozilla::DebugOnly<nsresult> rv = GetAppStatus(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute unsigned long appId; */
  NS_IMETHOD GetAppId(uint32_t *aAppId) = 0;
  inline uint32_t GetAppId()
  {
    uint32_t result;
    mozilla::DebugOnly<nsresult> rv = GetAppId(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isInBrowserElement; */
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) = 0;
  inline bool GetIsInBrowserElement()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsInBrowserElement(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean unknownAppId; */
  NS_IMETHOD GetUnknownAppId(bool *aUnknownAppId) = 0;
  inline bool GetUnknownAppId()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetUnknownAppId(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

  /* [infallible] readonly attribute boolean isNullPrincipal; */
  NS_IMETHOD GetIsNullPrincipal(bool *aIsNullPrincipal) = 0;
  inline bool GetIsNullPrincipal()
  {
    bool result;
    mozilla::DebugOnly<nsresult> rv = GetIsNullPrincipal(&result);
    MOZ_ASSERT(NS_SUCCEEDED(rv));
    return result;
  }

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIPrincipal, NS_IPRINCIPAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPRINCIPAL \
  NS_IMETHOD Equals(nsIPrincipal *other, bool *_retval); \
  NS_IMETHOD EqualsConsideringDomain(nsIPrincipal *other, bool *_retval); \
  NS_IMETHOD GetHashValue(uint32_t *aHashValue); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetDomain(nsIURI * *aDomain); \
  NS_IMETHOD SetDomain(nsIURI *aDomain); \
  NS_IMETHOD GetOrigin(char * *aOrigin); \
  NS_IMETHOD Subsumes(nsIPrincipal *other, bool *_retval); \
  NS_IMETHOD SubsumesConsideringDomain(nsIPrincipal *other, bool *_retval); \
  NS_IMETHOD CheckMayLoad(nsIURI *uri, bool report, bool allowIfInheritsPrincipal); \
  NS_IMETHOD GetCsp(nsIContentSecurityPolicy * *aCsp); \
  NS_IMETHOD SetCsp(nsIContentSecurityPolicy *aCsp); \
  NS_IMETHOD GetJarPrefix(nsACString & aJarPrefix); \
  NS_IMETHOD GetBaseDomain(nsACString & aBaseDomain); \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus); \
  NS_IMETHOD GetAppId(uint32_t *aAppId); \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement); \
  NS_IMETHOD GetUnknownAppId(bool *aUnknownAppId); \
  NS_IMETHOD GetIsNullPrincipal(bool *aIsNullPrincipal); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPRINCIPAL(_to) \
  NS_IMETHOD Equals(nsIPrincipal *other, bool *_retval) { return _to Equals(other, _retval); } \
  NS_IMETHOD EqualsConsideringDomain(nsIPrincipal *other, bool *_retval) { return _to EqualsConsideringDomain(other, _retval); } \
  NS_IMETHOD GetHashValue(uint32_t *aHashValue) { return _to GetHashValue(aHashValue); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetDomain(nsIURI * *aDomain) { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(nsIURI *aDomain) { return _to SetDomain(aDomain); } \
  NS_IMETHOD GetOrigin(char * *aOrigin) { return _to GetOrigin(aOrigin); } \
  NS_IMETHOD Subsumes(nsIPrincipal *other, bool *_retval) { return _to Subsumes(other, _retval); } \
  NS_IMETHOD SubsumesConsideringDomain(nsIPrincipal *other, bool *_retval) { return _to SubsumesConsideringDomain(other, _retval); } \
  NS_IMETHOD CheckMayLoad(nsIURI *uri, bool report, bool allowIfInheritsPrincipal) { return _to CheckMayLoad(uri, report, allowIfInheritsPrincipal); } \
  NS_IMETHOD GetCsp(nsIContentSecurityPolicy * *aCsp) { return _to GetCsp(aCsp); } \
  NS_IMETHOD SetCsp(nsIContentSecurityPolicy *aCsp) { return _to SetCsp(aCsp); } \
  NS_IMETHOD GetJarPrefix(nsACString & aJarPrefix) { return _to GetJarPrefix(aJarPrefix); } \
  NS_IMETHOD GetBaseDomain(nsACString & aBaseDomain) { return _to GetBaseDomain(aBaseDomain); } \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) { return _to GetAppStatus(aAppStatus); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return _to GetAppId(aAppId); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return _to GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetUnknownAppId(bool *aUnknownAppId) { return _to GetUnknownAppId(aUnknownAppId); } \
  NS_IMETHOD GetIsNullPrincipal(bool *aIsNullPrincipal) { return _to GetIsNullPrincipal(aIsNullPrincipal); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPRINCIPAL(_to) \
  NS_IMETHOD Equals(nsIPrincipal *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Equals(other, _retval); } \
  NS_IMETHOD EqualsConsideringDomain(nsIPrincipal *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->EqualsConsideringDomain(other, _retval); } \
  NS_IMETHOD GetHashValue(uint32_t *aHashValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHashValue(aHashValue); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetDomain(nsIURI * *aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(nsIURI *aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } \
  NS_IMETHOD GetOrigin(char * *aOrigin) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrigin(aOrigin); } \
  NS_IMETHOD Subsumes(nsIPrincipal *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Subsumes(other, _retval); } \
  NS_IMETHOD SubsumesConsideringDomain(nsIPrincipal *other, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SubsumesConsideringDomain(other, _retval); } \
  NS_IMETHOD CheckMayLoad(nsIURI *uri, bool report, bool allowIfInheritsPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckMayLoad(uri, report, allowIfInheritsPrincipal); } \
  NS_IMETHOD GetCsp(nsIContentSecurityPolicy * *aCsp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCsp(aCsp); } \
  NS_IMETHOD SetCsp(nsIContentSecurityPolicy *aCsp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCsp(aCsp); } \
  NS_IMETHOD GetJarPrefix(nsACString & aJarPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJarPrefix(aJarPrefix); } \
  NS_IMETHOD GetBaseDomain(nsACString & aBaseDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBaseDomain(aBaseDomain); } \
  NS_IMETHOD GetAppStatus(uint16_t *aAppStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppStatus(aAppStatus); } \
  NS_IMETHOD GetAppId(uint32_t *aAppId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppId(aAppId); } \
  NS_IMETHOD GetIsInBrowserElement(bool *aIsInBrowserElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsInBrowserElement(aIsInBrowserElement); } \
  NS_IMETHOD GetUnknownAppId(bool *aUnknownAppId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnknownAppId(aUnknownAppId); } \
  NS_IMETHOD GetIsNullPrincipal(bool *aIsNullPrincipal) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsNullPrincipal(aIsNullPrincipal); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsPrincipal : public nsIPrincipal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPRINCIPAL

  nsPrincipal();

private:
  ~nsPrincipal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsPrincipal, nsIPrincipal)

nsPrincipal::nsPrincipal()
{
  /* member initializers and constructor code */
}

nsPrincipal::~nsPrincipal()
{
  /* destructor code */
}

/* boolean equals (in nsIPrincipal other); */
NS_IMETHODIMP nsPrincipal::Equals(nsIPrincipal *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean equalsConsideringDomain (in nsIPrincipal other); */
NS_IMETHODIMP nsPrincipal::EqualsConsideringDomain(nsIPrincipal *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute unsigned long hashValue; */
NS_IMETHODIMP nsPrincipal::GetHashValue(uint32_t *aHashValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP nsPrincipal::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIURI domain; */
NS_IMETHODIMP nsPrincipal::GetDomain(nsIURI * *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrincipal::SetDomain(nsIURI *aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute string origin; */
NS_IMETHODIMP nsPrincipal::GetOrigin(char * *aOrigin)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean subsumes (in nsIPrincipal other); */
NS_IMETHODIMP nsPrincipal::Subsumes(nsIPrincipal *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean subsumesConsideringDomain (in nsIPrincipal other); */
NS_IMETHODIMP nsPrincipal::SubsumesConsideringDomain(nsIPrincipal *other, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkMayLoad (in nsIURI uri, in boolean report, in boolean allowIfInheritsPrincipal); */
NS_IMETHODIMP nsPrincipal::CheckMayLoad(nsIURI *uri, bool report, bool allowIfInheritsPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] attribute nsIContentSecurityPolicy csp; */
NS_IMETHODIMP nsPrincipal::GetCsp(nsIContentSecurityPolicy * *aCsp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsPrincipal::SetCsp(nsIContentSecurityPolicy *aCsp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String jarPrefix; */
NS_IMETHODIMP nsPrincipal::GetJarPrefix(nsACString & aJarPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString baseDomain; */
NS_IMETHODIMP nsPrincipal::GetBaseDomain(nsACString & aBaseDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute unsigned short appStatus; */
NS_IMETHODIMP nsPrincipal::GetAppStatus(uint16_t *aAppStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute unsigned long appId; */
NS_IMETHODIMP nsPrincipal::GetAppId(uint32_t *aAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isInBrowserElement; */
NS_IMETHODIMP nsPrincipal::GetIsInBrowserElement(bool *aIsInBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean unknownAppId; */
NS_IMETHODIMP nsPrincipal::GetUnknownAppId(bool *aUnknownAppId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [infallible] readonly attribute boolean isNullPrincipal; */
NS_IMETHODIMP nsPrincipal::GetIsNullPrincipal(bool *aIsNullPrincipal)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIExpandedPrincipal */
#define NS_IEXPANDEDPRINCIPAL_IID_STR "f3e177df-6a5e-489f-80a7-2dd1481471d8"

#define NS_IEXPANDEDPRINCIPAL_IID \
  {0xf3e177df, 0x6a5e, 0x489f, \
    { 0x80, 0xa7, 0x2d, 0xd1, 0x48, 0x14, 0x71, 0xd8 }}

class NS_NO_VTABLE nsIExpandedPrincipal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IEXPANDEDPRINCIPAL_IID)

  /* [noscript] readonly attribute PrincipalArray whiteList; */
  NS_IMETHOD GetWhiteList(nsTArray<nsCOMPtr<nsIPrincipal> > **aWhiteList) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIExpandedPrincipal, NS_IEXPANDEDPRINCIPAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIEXPANDEDPRINCIPAL \
  NS_IMETHOD GetWhiteList(nsTArray<nsCOMPtr<nsIPrincipal> > **aWhiteList); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIEXPANDEDPRINCIPAL(_to) \
  NS_IMETHOD GetWhiteList(nsTArray<nsCOMPtr<nsIPrincipal> > **aWhiteList) { return _to GetWhiteList(aWhiteList); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIEXPANDEDPRINCIPAL(_to) \
  NS_IMETHOD GetWhiteList(nsTArray<nsCOMPtr<nsIPrincipal> > **aWhiteList) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetWhiteList(aWhiteList); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsExpandedPrincipal : public nsIExpandedPrincipal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIEXPANDEDPRINCIPAL

  nsExpandedPrincipal();

private:
  ~nsExpandedPrincipal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsExpandedPrincipal, nsIExpandedPrincipal)

nsExpandedPrincipal::nsExpandedPrincipal()
{
  /* member initializers and constructor code */
}

nsExpandedPrincipal::~nsExpandedPrincipal()
{
  /* destructor code */
}

/* [noscript] readonly attribute PrincipalArray whiteList; */
NS_IMETHODIMP nsExpandedPrincipal::GetWhiteList(nsTArray<nsCOMPtr<nsIPrincipal> > **aWhiteList)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIPrincipal_h__ */
