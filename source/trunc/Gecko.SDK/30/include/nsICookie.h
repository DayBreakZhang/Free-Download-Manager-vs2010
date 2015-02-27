/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsICookie.idl
 */

#ifndef __gen_nsICookie_h__
#define __gen_nsICookie_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
typedef int32_t  nsCookieStatus;

typedef int32_t  nsCookiePolicy;


/* starting interface:    nsICookie */
#define NS_ICOOKIE_IID_STR "8684966b-1877-4f0f-8155-be4490b96bf7"

#define NS_ICOOKIE_IID \
  {0x8684966b, 0x1877, 0x4f0f, \
    { 0x81, 0x55, 0xbe, 0x44, 0x90, 0xb9, 0x6b, 0xf7 }}

class NS_NO_VTABLE nsICookie : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIE_IID)

  /* readonly attribute ACString name; */
  NS_IMETHOD GetName(nsACString & aName) = 0;

  /* readonly attribute AUTF8String value; */
  NS_IMETHOD GetValue(nsACString & aValue) = 0;

  /* readonly attribute boolean isDomain; */
  NS_IMETHOD GetIsDomain(bool *aIsDomain) = 0;

  /* readonly attribute AUTF8String host; */
  NS_IMETHOD GetHost(nsACString & aHost) = 0;

  /* readonly attribute AUTF8String path; */
  NS_IMETHOD GetPath(nsACString & aPath) = 0;

  /* readonly attribute boolean isSecure; */
  NS_IMETHOD GetIsSecure(bool *aIsSecure) = 0;

  /* readonly attribute uint64_t expires; */
  NS_IMETHOD GetExpires(uint64_t *aExpires) = 0;

  enum {
    STATUS_UNKNOWN = 0,
    STATUS_ACCEPTED = 1,
    STATUS_DOWNGRADED = 2,
    STATUS_FLAGGED = 3,
    STATUS_REJECTED = 4
  };

  /* readonly attribute nsCookieStatus status; */
  NS_IMETHOD GetStatus(nsCookieStatus *aStatus) = 0;

  enum {
    POLICY_UNKNOWN = 0,
    POLICY_NONE = 1,
    POLICY_NO_CONSENT = 2,
    POLICY_IMPLICIT_CONSENT = 3,
    POLICY_EXPLICIT_CONSENT = 4,
    POLICY_NO_II = 5
  };

  /* readonly attribute nsCookiePolicy policy; */
  NS_IMETHOD GetPolicy(nsCookiePolicy *aPolicy) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookie, NS_ICOOKIE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIE \
  NS_IMETHOD GetName(nsACString & aName); \
  NS_IMETHOD GetValue(nsACString & aValue); \
  NS_IMETHOD GetIsDomain(bool *aIsDomain); \
  NS_IMETHOD GetHost(nsACString & aHost); \
  NS_IMETHOD GetPath(nsACString & aPath); \
  NS_IMETHOD GetIsSecure(bool *aIsSecure); \
  NS_IMETHOD GetExpires(uint64_t *aExpires); \
  NS_IMETHOD GetStatus(nsCookieStatus *aStatus); \
  NS_IMETHOD GetPolicy(nsCookiePolicy *aPolicy); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIE(_to) \
  NS_IMETHOD GetName(nsACString & aName) { return _to GetName(aName); } \
  NS_IMETHOD GetValue(nsACString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD GetIsDomain(bool *aIsDomain) { return _to GetIsDomain(aIsDomain); } \
  NS_IMETHOD GetHost(nsACString & aHost) { return _to GetHost(aHost); } \
  NS_IMETHOD GetPath(nsACString & aPath) { return _to GetPath(aPath); } \
  NS_IMETHOD GetIsSecure(bool *aIsSecure) { return _to GetIsSecure(aIsSecure); } \
  NS_IMETHOD GetExpires(uint64_t *aExpires) { return _to GetExpires(aExpires); } \
  NS_IMETHOD GetStatus(nsCookieStatus *aStatus) { return _to GetStatus(aStatus); } \
  NS_IMETHOD GetPolicy(nsCookiePolicy *aPolicy) { return _to GetPolicy(aPolicy); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIE(_to) \
  NS_IMETHOD GetName(nsACString & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD GetValue(nsACString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD GetIsDomain(bool *aIsDomain) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsDomain(aIsDomain); } \
  NS_IMETHOD GetHost(nsACString & aHost) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHost(aHost); } \
  NS_IMETHOD GetPath(nsACString & aPath) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPath(aPath); } \
  NS_IMETHOD GetIsSecure(bool *aIsSecure) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSecure(aIsSecure); } \
  NS_IMETHOD GetExpires(uint64_t *aExpires) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpires(aExpires); } \
  NS_IMETHOD GetStatus(nsCookieStatus *aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStatus(aStatus); } \
  NS_IMETHOD GetPolicy(nsCookiePolicy *aPolicy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPolicy(aPolicy); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookie : public nsICookie
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIE

  nsCookie();

private:
  ~nsCookie();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookie, nsICookie)

nsCookie::nsCookie()
{
  /* member initializers and constructor code */
}

nsCookie::~nsCookie()
{
  /* destructor code */
}

/* readonly attribute ACString name; */
NS_IMETHODIMP nsCookie::GetName(nsACString & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String value; */
NS_IMETHODIMP nsCookie::GetValue(nsACString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isDomain; */
NS_IMETHODIMP nsCookie::GetIsDomain(bool *aIsDomain)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String host; */
NS_IMETHODIMP nsCookie::GetHost(nsACString & aHost)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String path; */
NS_IMETHODIMP nsCookie::GetPath(nsACString & aPath)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSecure; */
NS_IMETHODIMP nsCookie::GetIsSecure(bool *aIsSecure)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute uint64_t expires; */
NS_IMETHODIMP nsCookie::GetExpires(uint64_t *aExpires)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsCookieStatus status; */
NS_IMETHODIMP nsCookie::GetStatus(nsCookieStatus *aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsCookiePolicy policy; */
NS_IMETHODIMP nsCookie::GetPolicy(nsCookiePolicy *aPolicy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICookie_h__ */
