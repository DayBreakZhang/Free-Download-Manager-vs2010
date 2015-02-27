/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/content/base/public/nsIContentPolicy.idl
 */

#ifndef __gen_nsIContentPolicy_h__
#define __gen_nsIContentPolicy_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsIPrincipal_h__
#include "nsIPrincipal.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIDOMNode; /* forward declaration */

typedef uint32_t  nsContentPolicyType;


/* starting interface:    nsIContentPolicy */
#define NS_ICONTENTPOLICY_IID_STR "e48e3024-f302-4a16-b8b6-2034d3a4b279"

#define NS_ICONTENTPOLICY_IID \
  {0xe48e3024, 0xf302, 0x4a16, \
    { 0xb8, 0xb6, 0x20, 0x34, 0xd3, 0xa4, 0xb2, 0x79 }}

class NS_NO_VTABLE nsIContentPolicy : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTENTPOLICY_IID)

  enum {
    TYPE_OTHER = 1U,
    TYPE_SCRIPT = 2U,
    TYPE_IMAGE = 3U,
    TYPE_STYLESHEET = 4U,
    TYPE_OBJECT = 5U,
    TYPE_DOCUMENT = 6U,
    TYPE_SUBDOCUMENT = 7U,
    TYPE_REFRESH = 8U,
    TYPE_XBL = 9U,
    TYPE_PING = 10U,
    TYPE_XMLHTTPREQUEST = 11U,
    TYPE_DATAREQUEST = 11U,
    TYPE_OBJECT_SUBREQUEST = 12U,
    TYPE_DTD = 13U,
    TYPE_FONT = 14U,
    TYPE_MEDIA = 15U,
    TYPE_WEBSOCKET = 16U,
    TYPE_CSP_REPORT = 17U,
    REJECT_REQUEST = -1,
    REJECT_TYPE = -2,
    REJECT_SERVER = -3,
    REJECT_OTHER = -4,
    ACCEPT = 1
  };

  /* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) = 0;

  /* short shouldProcess (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContentPolicy, NS_ICONTENTPOLICY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTENTPOLICY \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval); \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTENTPOLICY(_to) \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) { return _to ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, aRequestPrincipal, _retval); } \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) { return _to ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, aRequestPrincipal, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTENTPOLICY(_to) \
  NS_IMETHOD ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldLoad(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeTypeGuess, aExtra, aRequestPrincipal, _retval); } \
  NS_IMETHOD ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShouldProcess(aContentType, aContentLocation, aRequestOrigin, aContext, aMimeType, aExtra, aRequestPrincipal, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContentPolicy : public nsIContentPolicy
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTENTPOLICY

  nsContentPolicy();

private:
  ~nsContentPolicy();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContentPolicy, nsIContentPolicy)

nsContentPolicy::nsContentPolicy()
{
  /* member initializers and constructor code */
}

nsContentPolicy::~nsContentPolicy()
{
  /* destructor code */
}

/* short shouldLoad (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeTypeGuess, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
NS_IMETHODIMP nsContentPolicy::ShouldLoad(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeTypeGuess, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* short shouldProcess (in nsContentPolicyType aContentType, in nsIURI aContentLocation, in nsIURI aRequestOrigin, in nsISupports aContext, in ACString aMimeType, in nsISupports aExtra, [optional] in nsIPrincipal aRequestPrincipal); */
NS_IMETHODIMP nsContentPolicy::ShouldProcess(nsContentPolicyType aContentType, nsIURI *aContentLocation, nsIURI *aRequestOrigin, nsISupports *aContext, const nsACString & aMimeType, nsISupports *aExtra, nsIPrincipal *aRequestPrincipal, int16_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContentPolicy_h__ */
