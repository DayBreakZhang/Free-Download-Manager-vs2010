/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIAuthInformation.idl
 */

#ifndef __gen_nsIAuthInformation_h__
#define __gen_nsIAuthInformation_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIAuthInformation */
#define NS_IAUTHINFORMATION_IID_STR "0d73639c-2a92-4518-9f92-28f71fea5f20"

#define NS_IAUTHINFORMATION_IID \
  {0x0d73639c, 0x2a92, 0x4518, \
    { 0x9f, 0x92, 0x28, 0xf7, 0x1f, 0xea, 0x5f, 0x20 }}

class NS_NO_VTABLE nsIAuthInformation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAUTHINFORMATION_IID)

  enum {
    AUTH_HOST = 1U,
    AUTH_PROXY = 2U,
    NEED_DOMAIN = 4U,
    ONLY_PASSWORD = 8U,
    PREVIOUS_FAILED = 16U
  };

  /* readonly attribute unsigned long flags; */
  NS_IMETHOD GetFlags(uint32_t *aFlags) = 0;

  /* readonly attribute AString realm; */
  NS_IMETHOD GetRealm(nsAString & aRealm) = 0;

  /* readonly attribute AUTF8String authenticationScheme; */
  NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme) = 0;

  /* attribute AString username; */
  NS_IMETHOD GetUsername(nsAString & aUsername) = 0;
  NS_IMETHOD SetUsername(const nsAString & aUsername) = 0;

  /* attribute AString password; */
  NS_IMETHOD GetPassword(nsAString & aPassword) = 0;
  NS_IMETHOD SetPassword(const nsAString & aPassword) = 0;

  /* attribute AString domain; */
  NS_IMETHOD GetDomain(nsAString & aDomain) = 0;
  NS_IMETHOD SetDomain(const nsAString & aDomain) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAuthInformation, NS_IAUTHINFORMATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAUTHINFORMATION \
  NS_IMETHOD GetFlags(uint32_t *aFlags); \
  NS_IMETHOD GetRealm(nsAString & aRealm); \
  NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme); \
  NS_IMETHOD GetUsername(nsAString & aUsername); \
  NS_IMETHOD SetUsername(const nsAString & aUsername); \
  NS_IMETHOD GetPassword(nsAString & aPassword); \
  NS_IMETHOD SetPassword(const nsAString & aPassword); \
  NS_IMETHOD GetDomain(nsAString & aDomain); \
  NS_IMETHOD SetDomain(const nsAString & aDomain); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAUTHINFORMATION(_to) \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return _to GetFlags(aFlags); } \
  NS_IMETHOD GetRealm(nsAString & aRealm) { return _to GetRealm(aRealm); } \
  NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme) { return _to GetAuthenticationScheme(aAuthenticationScheme); } \
  NS_IMETHOD GetUsername(nsAString & aUsername) { return _to GetUsername(aUsername); } \
  NS_IMETHOD SetUsername(const nsAString & aUsername) { return _to SetUsername(aUsername); } \
  NS_IMETHOD GetPassword(nsAString & aPassword) { return _to GetPassword(aPassword); } \
  NS_IMETHOD SetPassword(const nsAString & aPassword) { return _to SetPassword(aPassword); } \
  NS_IMETHOD GetDomain(nsAString & aDomain) { return _to GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsAString & aDomain) { return _to SetDomain(aDomain); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAUTHINFORMATION(_to) \
  NS_IMETHOD GetFlags(uint32_t *aFlags) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFlags(aFlags); } \
  NS_IMETHOD GetRealm(nsAString & aRealm) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealm(aRealm); } \
  NS_IMETHOD GetAuthenticationScheme(nsACString & aAuthenticationScheme) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAuthenticationScheme(aAuthenticationScheme); } \
  NS_IMETHOD GetUsername(nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUsername(aUsername); } \
  NS_IMETHOD SetUsername(const nsAString & aUsername) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUsername(aUsername); } \
  NS_IMETHOD GetPassword(nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPassword(aPassword); } \
  NS_IMETHOD SetPassword(const nsAString & aPassword) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPassword(aPassword); } \
  NS_IMETHOD GetDomain(nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDomain(aDomain); } \
  NS_IMETHOD SetDomain(const nsAString & aDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDomain(aDomain); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAuthInformation : public nsIAuthInformation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTHINFORMATION

  nsAuthInformation();

private:
  ~nsAuthInformation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAuthInformation, nsIAuthInformation)

nsAuthInformation::nsAuthInformation()
{
  /* member initializers and constructor code */
}

nsAuthInformation::~nsAuthInformation()
{
  /* destructor code */
}

/* readonly attribute unsigned long flags; */
NS_IMETHODIMP nsAuthInformation::GetFlags(uint32_t *aFlags)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString realm; */
NS_IMETHODIMP nsAuthInformation::GetRealm(nsAString & aRealm)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String authenticationScheme; */
NS_IMETHODIMP nsAuthInformation::GetAuthenticationScheme(nsACString & aAuthenticationScheme)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString username; */
NS_IMETHODIMP nsAuthInformation::GetUsername(nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAuthInformation::SetUsername(const nsAString & aUsername)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString password; */
NS_IMETHODIMP nsAuthInformation::GetPassword(nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAuthInformation::SetPassword(const nsAString & aPassword)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString domain; */
NS_IMETHODIMP nsAuthInformation::GetDomain(nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsAuthInformation::SetDomain(const nsAString & aDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAuthInformation_h__ */
