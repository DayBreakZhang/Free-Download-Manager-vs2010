/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIProtocolProxyCallback.idl
 */

#ifndef __gen_nsIProtocolProxyCallback_h__
#define __gen_nsIProtocolProxyCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */

class nsICancelable; /* forward declaration */


/* starting interface:    nsIProtocolProxyCallback */
#define NS_IPROTOCOLPROXYCALLBACK_IID_STR "a9967200-f95e-45c2-beb3-9b060d874bfd"

#define NS_IPROTOCOLPROXYCALLBACK_IID \
  {0xa9967200, 0xf95e, 0x45c2, \
    { 0xbe, 0xb3, 0x9b, 0x06, 0x0d, 0x87, 0x4b, 0xfd }}

class NS_NO_VTABLE nsIProtocolProxyCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROTOCOLPROXYCALLBACK_IID)

  /* void onProxyAvailable (in nsICancelable aRequest, in nsIURI aURI, in nsIProxyInfo aProxyInfo, in nsresult aStatus); */
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProtocolProxyCallback, NS_IPROTOCOLPROXYCALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROTOCOLPROXYCALLBACK \
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROTOCOLPROXYCALLBACK(_to) \
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus) { return _to OnProxyAvailable(aRequest, aURI, aProxyInfo, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROTOCOLPROXYCALLBACK(_to) \
  NS_IMETHOD OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnProxyAvailable(aRequest, aURI, aProxyInfo, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProtocolProxyCallback : public nsIProtocolProxyCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROTOCOLPROXYCALLBACK

  nsProtocolProxyCallback();

private:
  ~nsProtocolProxyCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProtocolProxyCallback, nsIProtocolProxyCallback)

nsProtocolProxyCallback::nsProtocolProxyCallback()
{
  /* member initializers and constructor code */
}

nsProtocolProxyCallback::~nsProtocolProxyCallback()
{
  /* destructor code */
}

/* void onProxyAvailable (in nsICancelable aRequest, in nsIURI aURI, in nsIProxyInfo aProxyInfo, in nsresult aStatus); */
NS_IMETHODIMP nsProtocolProxyCallback::OnProxyAvailable(nsICancelable *aRequest, nsIURI *aURI, nsIProxyInfo *aProxyInfo, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProtocolProxyCallback_h__ */
