/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/cookie/nsICookieManager2.idl
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
#define NS_ICOOKIEMANAGER2_IID_STR "daf0caa7-b431-4b4d-ba51-08c179bb9dfe"

#define NS_ICOOKIEMANAGER2_IID \
  {0xdaf0caa7, 0xb431, 0x4b4d, \
    { 0xba, 0x51, 0x08, 0xc1, 0x79, 0xbb, 0x9d, 0xfe }}

class NS_NO_VTABLE nsICookieManager2 : public nsICookieManager {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEMANAGER2_IID)

  /* void add (in AUTF8String aHost, in AUTF8String aPath, in ACString aName, in ACString aValue, in boolean aIsSecure, in boolean aIsHttpOnly, in boolean aIsSession, in int64_t aExpiry); */
  NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, bool aIsSecure, bool aIsHttpOnly, bool aIsSession, int64_t aExpiry) = 0;

  /* boolean cookieExists (in nsICookie2 aCookie); */
  NS_IMETHOD CookieExists(nsICookie2 *aCookie, bool *_retval) = 0;

  /* unsigned long countCookiesFromHost (in AUTF8String aHost); */
  NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, uint32_t *_retval) = 0;

  /* nsISimpleEnumerator getCookiesFromHost (in AUTF8String aHost); */
  NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator * *_retval) = 0;

  /* void importCookies (in nsIFile aCookieFile); */
  NS_IMETHOD ImportCookies(nsIFile *aCookieFile) = 0;

  /* nsISimpleEnumerator getCookiesForApp (in unsigned long appId, in boolean onlyBrowserElement); */
  NS_IMETHOD GetCookiesForApp(uint32_t appId, bool onlyBrowserElement, nsISimpleEnumerator * *_retval) = 0;

  /* void removeCookiesForApp (in unsigned long appId, in boolean onlyBrowserElement); */
  NS_IMETHOD RemoveCookiesForApp(uint32_t appId, bool onlyBrowserElement) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookieManager2, NS_ICOOKIEMANAGER2_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEMANAGER2 \
  NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, bool aIsSecure, bool aIsHttpOnly, bool aIsSession, int64_t aExpiry); \
  NS_IMETHOD CookieExists(nsICookie2 *aCookie, bool *_retval); \
  NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, uint32_t *_retval); \
  NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD ImportCookies(nsIFile *aCookieFile); \
  NS_IMETHOD GetCookiesForApp(uint32_t appId, bool onlyBrowserElement, nsISimpleEnumerator * *_retval); \
  NS_IMETHOD RemoveCookiesForApp(uint32_t appId, bool onlyBrowserElement); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEMANAGER2(_to) \
  NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, bool aIsSecure, bool aIsHttpOnly, bool aIsSession, int64_t aExpiry) { return _to Add(aHost, aPath, aName, aValue, aIsSecure, aIsHttpOnly, aIsSession, aExpiry); } \
  NS_IMETHOD CookieExists(nsICookie2 *aCookie, bool *_retval) { return _to CookieExists(aCookie, _retval); } \
  NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, uint32_t *_retval) { return _to CountCookiesFromHost(aHost, _retval); } \
  NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator * *_retval) { return _to GetCookiesFromHost(aHost, _retval); } \
  NS_IMETHOD ImportCookies(nsIFile *aCookieFile) { return _to ImportCookies(aCookieFile); } \
  NS_IMETHOD GetCookiesForApp(uint32_t appId, bool onlyBrowserElement, nsISimpleEnumerator * *_retval) { return _to GetCookiesForApp(appId, onlyBrowserElement, _retval); } \
  NS_IMETHOD RemoveCookiesForApp(uint32_t appId, bool onlyBrowserElement) { return _to RemoveCookiesForApp(appId, onlyBrowserElement); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEMANAGER2(_to) \
  NS_IMETHOD Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, bool aIsSecure, bool aIsHttpOnly, bool aIsSession, int64_t aExpiry) { return !_to ? NS_ERROR_NULL_POINTER : _to->Add(aHost, aPath, aName, aValue, aIsSecure, aIsHttpOnly, aIsSession, aExpiry); } \
  NS_IMETHOD CookieExists(nsICookie2 *aCookie, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CookieExists(aCookie, _retval); } \
  NS_IMETHOD CountCookiesFromHost(const nsACString & aHost, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CountCookiesFromHost(aHost, _retval); } \
  NS_IMETHOD GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookiesFromHost(aHost, _retval); } \
  NS_IMETHOD ImportCookies(nsIFile *aCookieFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->ImportCookies(aCookieFile); } \
  NS_IMETHOD GetCookiesForApp(uint32_t appId, bool onlyBrowserElement, nsISimpleEnumerator * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCookiesForApp(appId, onlyBrowserElement, _retval); } \
  NS_IMETHOD RemoveCookiesForApp(uint32_t appId, bool onlyBrowserElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveCookiesForApp(appId, onlyBrowserElement); } 

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

/* void add (in AUTF8String aHost, in AUTF8String aPath, in ACString aName, in ACString aValue, in boolean aIsSecure, in boolean aIsHttpOnly, in boolean aIsSession, in int64_t aExpiry); */
NS_IMETHODIMP nsCookieManager2::Add(const nsACString & aHost, const nsACString & aPath, const nsACString & aName, const nsACString & aValue, bool aIsSecure, bool aIsHttpOnly, bool aIsSession, int64_t aExpiry)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean cookieExists (in nsICookie2 aCookie); */
NS_IMETHODIMP nsCookieManager2::CookieExists(nsICookie2 *aCookie, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long countCookiesFromHost (in AUTF8String aHost); */
NS_IMETHODIMP nsCookieManager2::CountCookiesFromHost(const nsACString & aHost, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getCookiesFromHost (in AUTF8String aHost); */
NS_IMETHODIMP nsCookieManager2::GetCookiesFromHost(const nsACString & aHost, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void importCookies (in nsIFile aCookieFile); */
NS_IMETHODIMP nsCookieManager2::ImportCookies(nsIFile *aCookieFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsISimpleEnumerator getCookiesForApp (in unsigned long appId, in boolean onlyBrowserElement); */
NS_IMETHODIMP nsCookieManager2::GetCookiesForApp(uint32_t appId, bool onlyBrowserElement, nsISimpleEnumerator * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeCookiesForApp (in unsigned long appId, in boolean onlyBrowserElement); */
NS_IMETHODIMP nsCookieManager2::RemoveCookiesForApp(uint32_t appId, bool onlyBrowserElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsICookieManager2_h__ */
