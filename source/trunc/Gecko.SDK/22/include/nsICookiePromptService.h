/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/extensions/cookie/nsICookiePromptService.idl
 */

#ifndef __gen_nsICookiePromptService_h__
#define __gen_nsICookiePromptService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMWindow; /* forward declaration */

class nsICookie; /* forward declaration */


/* starting interface:    nsICookiePromptService */
#define NS_ICOOKIEPROMPTSERVICE_IID_STR "72f8bb14-2810-4f38-8d0d-290c5401f54e"

#define NS_ICOOKIEPROMPTSERVICE_IID \
  {0x72f8bb14, 0x2810, 0x4f38, \
    { 0x8d, 0x0d, 0x29, 0x0c, 0x54, 0x01, 0xf5, 0x4e }}

class NS_NO_VTABLE nsICookiePromptService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICOOKIEPROMPTSERVICE_IID)

  enum {
    DENY_COOKIE = 0U,
    ACCEPT_COOKIE = 1U,
    ACCEPT_SESSION_COOKIE = 2U
  };

  /* long cookieDialog (in nsIDOMWindow parent, in nsICookie cookie, in ACString hostname, in long cookiesFromHost, in boolean changingCookie, out boolean rememberDecision); */
  NS_IMETHOD CookieDialog(nsIDOMWindow *parent, nsICookie *cookie, const nsACString & hostname, int32_t cookiesFromHost, bool changingCookie, bool *rememberDecision, int32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsICookiePromptService, NS_ICOOKIEPROMPTSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICOOKIEPROMPTSERVICE \
  NS_IMETHOD CookieDialog(nsIDOMWindow *parent, nsICookie *cookie, const nsACString & hostname, int32_t cookiesFromHost, bool changingCookie, bool *rememberDecision, int32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICOOKIEPROMPTSERVICE(_to) \
  NS_IMETHOD CookieDialog(nsIDOMWindow *parent, nsICookie *cookie, const nsACString & hostname, int32_t cookiesFromHost, bool changingCookie, bool *rememberDecision, int32_t *_retval) { return _to CookieDialog(parent, cookie, hostname, cookiesFromHost, changingCookie, rememberDecision, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICOOKIEPROMPTSERVICE(_to) \
  NS_IMETHOD CookieDialog(nsIDOMWindow *parent, nsICookie *cookie, const nsACString & hostname, int32_t cookiesFromHost, bool changingCookie, bool *rememberDecision, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CookieDialog(parent, cookie, hostname, cookiesFromHost, changingCookie, rememberDecision, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsCookiePromptService : public nsICookiePromptService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICOOKIEPROMPTSERVICE

  nsCookiePromptService();

private:
  ~nsCookiePromptService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsCookiePromptService, nsICookiePromptService)

nsCookiePromptService::nsCookiePromptService()
{
  /* member initializers and constructor code */
}

nsCookiePromptService::~nsCookiePromptService()
{
  /* destructor code */
}

/* long cookieDialog (in nsIDOMWindow parent, in nsICookie cookie, in ACString hostname, in long cookiesFromHost, in boolean changingCookie, out boolean rememberDecision); */
NS_IMETHODIMP nsCookiePromptService::CookieDialog(nsIDOMWindow *parent, nsICookie *cookie, const nsACString & hostname, int32_t cookiesFromHost, bool changingCookie, bool *rememberDecision, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

#define NS_COOKIEPROMPTSERVICE_CONTRACTID "@mozilla.org/embedcomp/cookieprompt-service;1"

#endif /* __gen_nsICookiePromptService_h__ */
