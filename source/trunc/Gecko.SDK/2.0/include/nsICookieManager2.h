/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/cookie/nsICookieManager2.idl
 */

#ifndef __gen_nsICookieManager2_h__
#define __gen_nsICookieManager2_h__


#ifndef __gen_nsICookieManager_h__
#include "nsICookieManager.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsICookie2; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsICookieManager2 */
#define NS_ICOOKIEMANAGER2_IID_STR "94628d1d-8b31-4baa-b474-9c872c440f90"

#define NS_ICOOKIEMANAGER2_IID \
  {0x94628d1d, 0x8b31, 0x4baa, \
    { 0xb4, 0x74, 0x9c, 0x87, 0x2c, 0x44, 0x0f, 0x90 }}

/** 
 * Additions to the frozen nsICookieManager
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsICookieManager2 : public nsICookieManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEMANAGER2_IID)

  /**
   * Add a cookie. nsICookieService is the normal way to do this. This
   * method is something of a backdoor.
   *
   * @param aHost
   *        the host or domain for which the cookie is set. presence of a
   *        leading dot indicates a domain cookie; otherwise, the cookie
   *        is treated as a non-domain cookie (see RFC2109). The host string
   *        will be normalized to ASCII or ACE; any trailing dot will be
   *        stripped. To be a domain cookie, the host must have at least two
   *        subdomain parts (e.g. '.foo.com', not '.com'), otherwise an
   *        exception will be thrown. An empty string is acceptable
   *        (e.g. file:// URI's).
   * @param aPath
   *        path within the domain for which the cookie is valid
   * @param aName
   *        cookie name
   * @param aValue
   *        cookie data
   * @param aIsSecure
   *        true if the cookie should only be sent over a secure connection.
   * @param aIsHttpOnly
   *        true if the cookie should only be sent to, and can only be
   *        modified by, an http connection.
   * @param aIsSession
   *        true if the cookie should exist for the current session only.
   *        see aExpiry.
   * @param aExpiry
   *        expiration date, in seconds since midnight (00:00:00), January 1,
   *        1970 UTC. note that expiry time will also be honored for session cookies;
   *        in this way, the more restrictive of the two will take effect.
   */
  /* void add (in AUTF8String aHost, in AUTF8String aPath, in ACString aName, in ACString aValue, in boolean aIsSecure, in boolean aIsHttpOnly, in boolean aIsSession, in PRInt64 aExpiry); */
  NS_SCRIPTABLE NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, PRBool aIsSecure, PRBool aIsHttpOnly, PRBool aIsSession, PRInt64 aExpiry) = 0;

  /**
   * Find whether a given cookie already exists.
   *
   * @param aCookie
   *        the cookie to look for
   *
   * @return true if a cookie was found which matches the host, path, and name
   *         fields of aCookie
   */
  /* boolean cookieExists (in nsICookie2 aCookie); */
  NS_SCRIPTABLE NS_IMETHOD CookieExists(nsICookie2 *aCookie, PRBool *_retval NS_OUTPARAM) = 0;

  /**
   * Count how many cookies exist within the base domain of 'aHost'.
   * Thus, for a host "weather.yahoo.com", the base domain would be "yahoo.com",
   * and any host or domain cookies for "yahoo.com" and its subdomains would be
   * counted.
   *
   * @param aHost
   *        the host string to search for, e.g. "google.com". this should consist
   *        of only the host portion of a URI. see @add for a description of
   *        acceptable host strings.
   *
   * @return the number of cookies found.
   */
  /* unsigned long countCookiesFromHost (in AUTF8String aHost); */
  NS_SCRIPTABLE NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, PRUint32 *_retval NS_OUTPARAM) = 0;

  /**
   * Returns an enumerator of cookies that exist within the base domain of
   * 'aHost'. Thus, for a host "weather.yahoo.com", the base domain would be
   * "yahoo.com", and any host or domain cookies for "yahoo.com" and its
   * subdomains would be returned.
   *
   * @param aHost
   *        the host string to search for, e.g. "google.com". this should consist
   *        of only the host portion of a URI. see @add for a description of
   *        acceptable host strings.
   *
   * @return an nsISimpleEnumerator of nsICookie2 objects.
   *
   * @see countCookiesFromHost
   */
  /* nsISimpleEnumerator getCookiesFromHost (in AUTF8String aHost); */
  NS_SCRIPTABLE NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator **_retval NS_OUTPARAM) = 0;

  /**
   * Import an old-style cookie file. Imported cookies will be added to the
   * existing database. If the database contains any cookies the same as those
   * being imported (i.e. domain, name, and path match), they will be replaced.
   *
   * @param aCookieFile the file to import, usually cookies.txt
   */
  /* void importCookies (in nsIFile aCookieFile); */
  NS_SCRIPTABLE NS_IMETHOD ImportCookies(nsIFile *aCookieFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookieManager2, NS_ICOOKIEMANAGER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEMANAGER2 \
  NS_SCRIPTABLE NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, PRBool aIsSecure, PRBool aIsHttpOnly, PRBool aIsSession, PRInt64 aExpiry); \
  NS_SCRIPTABLE NS_IMETHOD CookieExists(nsICookie2 *aCookie, PRBool *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, PRUint32 *_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator **_retval NS_OUTPARAM); \
  NS_SCRIPTABLE NS_IMETHOD ImportCookies(nsIFile *aCookieFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEMANAGER2(_to) \
  NS_SCRIPTABLE NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, PRBool aIsSecure, PRBool aIsHttpOnly, PRBool aIsSession, PRInt64 aExpiry) { return _to Add(aHost, aPath, aName, aValue, aIsSecure, aIsHttpOnly, aIsSession, aExpiry); } \
  NS_SCRIPTABLE NS_IMETHOD CookieExists(nsICookie2 *aCookie, PRBool *_retval NS_OUTPARAM) { return _to CookieExists(aCookie, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, PRUint32 *_retval NS_OUTPARAM) { return _to CountCookiesFromHost(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator **_retval NS_OUTPARAM) { return _to GetCookiesFromHost(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ImportCookies(nsIFile *aCookieFile) { return _to ImportCookies(aCookieFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEMANAGER2(_to) \
  NS_SCRIPTABLE NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, PRBool aIsSecure, PRBool aIsHttpOnly, PRBool aIsSession, PRInt64 aExpiry) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(aHost, aPath, aName, aValue, aIsSecure, aIsHttpOnly, aIsSession, aExpiry); } \
  NS_SCRIPTABLE NS_IMETHOD CookieExists(nsICookie2 *aCookie, PRBool *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CookieExists(aCookie, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, PRUint32 *_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->CountCookiesFromHost(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator **_retval NS_OUTPARAM) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookiesFromHost(aHost, _retval); } \
  NS_SCRIPTABLE NS_IMETHOD ImportCookies(nsIFile *aCookieFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCookies(aCookieFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookieManager2 : public nsICookieManager2
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIEMANAGER2

  nsCookieManager2();

private:
  ~nsCookieManager2();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookieManager2, nsICookieManager2)

nsCookieManager2::nsCookieManager2()
{
  /* member initializers and constructor code */
}

nsCookieManager2::~nsCookieManager2()
{
  /* destructor code */
}

/* void add (in AUTF8String aHost, in AUTF8String aPath, in ACString aName, in ACString aValue, in boolean aIsSecure, in boolean aIsHttpOnly, in boolean aIsSession, in PRInt64 aExpiry); */
NS_IMETHODIMP nsCookieManager2::Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, PRBool aIsSecure, PRBool aIsHttpOnly, PRBool aIsSession, PRInt64 aExpiry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean cookieExists (in nsICookie2 aCookie); */
NS_IMETHODIMP nsCookieManager2::CookieExists(nsICookie2 *aCookie, PRBool *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long countCookiesFromHost (in AUTF8String aHost); */
NS_IMETHODIMP nsCookieManager2::CountCookiesFromHost(const nsACString & aHost, PRUint32 *_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getCookiesFromHost (in AUTF8String aHost); */
NS_IMETHODIMP nsCookieManager2::GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator **_retval NS_OUTPARAM)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importCookies (in nsIFile aCookieFile); */
NS_IMETHODIMP nsCookieManager2::ImportCookies(nsIFile *aCookieFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICookieManager2_h__ */
