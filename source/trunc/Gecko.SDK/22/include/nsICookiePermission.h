/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cookie/nsICookiePermission.idl
 */

#ifndef __gen_nsICookiePermission_h__
#define __gen_nsICookiePermission_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICookie2; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIChannel; /* forward declaration */

typedef int32_t  nsCookieAccess;


/* starting interface:    nsICookiePermission */
#define NS_ICOOKIEPERMISSION_IID_STR "11ddd4ed-8f5b-40b3-b2a0-27c20ea1c88d"

#define NS_ICOOKIEPERMISSION_IID \
  {0x11ddd4ed, 0x8f5b, 0x40b3, \
    { 0xb2, 0xa0, 0x27, 0xc2, 0x0e, 0xa1, 0xc8, 0x8d }}

class NS_NO_VTABLE nsICookiePermission : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEPERMISSION_IID)

  enum {
    ACCESS_DEFAULT = 0,
    ACCESS_ALLOW = 1,
    ACCESS_DENY = 2,
    ACCESS_SESSION = 8,
    ACCESS_ALLOW_FIRST_PARTY_ONLY = 9,
    ACCESS_LIMIT_THIRD_PARTY = 10
  };

  /* void setAccess (in nsIURI aURI, in nsCookieAccess aAccess); */
  NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess) = 0;

  /* nsCookieAccess canAccess (in nsIURI aURI, in nsIChannel aChannel); */
  NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval) = 0;

  /* boolean canSetCookie (in nsIURI aURI, in nsIChannel aChannel, in nsICookie2 aCookie, inout boolean aIsSession, inout int64_t aExpiry); */
  NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, bool *aIsSession, int64_t *aExpiry, bool *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookiePermission, NS_ICOOKIEPERMISSION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEPERMISSION \
  NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess); \
  NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval); \
  NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, bool *aIsSession, int64_t *aExpiry, bool *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEPERMISSION(_to) \
  NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess) { return _to SetAccess(aURI, aAccess); } \
  NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval) { return _to CanAccess(aURI, aChannel, _retval); } \
  NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, bool *aIsSession, int64_t *aExpiry, bool *_retval) { return _to CanSetCookie(aURI, aChannel, aCookie, aIsSession, aExpiry, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEPERMISSION(_to) \
  NS_IMETHOD SetAccess(nsIURI *aURI, nsCookieAccess aAccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAccess(aURI, aAccess); } \
  NS_IMETHOD CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanAccess(aURI, aChannel, _retval); } \
  NS_IMETHOD CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, bool *aIsSession, int64_t *aExpiry, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CanSetCookie(aURI, aChannel, aCookie, aIsSession, aExpiry, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookiePermission : public nsICookiePermission
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIEPERMISSION

  nsCookiePermission();

private:
  ~nsCookiePermission();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookiePermission, nsICookiePermission)

nsCookiePermission::nsCookiePermission()
{
  /* member initializers and constructor code */
}

nsCookiePermission::~nsCookiePermission()
{
  /* destructor code */
}

/* void setAccess (in nsIURI aURI, in nsCookieAccess aAccess); */
NS_IMETHODIMP nsCookiePermission::SetAccess(nsIURI *aURI, nsCookieAccess aAccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsCookieAccess canAccess (in nsIURI aURI, in nsIChannel aChannel); */
NS_IMETHODIMP nsCookiePermission::CanAccess(nsIURI *aURI, nsIChannel *aChannel, nsCookieAccess *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean canSetCookie (in nsIURI aURI, in nsIChannel aChannel, in nsICookie2 aCookie, inout boolean aIsSession, inout int64_t aExpiry); */
NS_IMETHODIMP nsCookiePermission::CanSetCookie(nsIURI *aURI, nsIChannel *aChannel, nsICookie2 *aCookie, bool *aIsSession, int64_t *aExpiry, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * The nsICookiePermission implementation is an XPCOM service registered
 * under the ContractID:
 */
#define NS_COOKIEPERMISSION_CONTRACTID "@mozilla.org/cookie/permission;1"

#endif /* __gen_nsICookiePermission_h__ */
