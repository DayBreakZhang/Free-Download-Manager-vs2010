/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-cen-xr-w32-bld/build/netwerk/protocol/http/nsIHttpChannelAuthProvider.idl
 */

#ifndef __gen_nsIHttpChannelAuthProvider_h__
#define __gen_nsIHttpChannelAuthProvider_h__


#ifndef __gen_nsICancelable_h__
#include "nsICancelable.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIHttpChannel; /* forward declaration */

class nsIHttpAuthenticableChannel; /* forward declaration */


/* starting interface:    nsIHttpChannelAuthProvider */
#define NS_IHTTPCHANNELAUTHPROVIDER_IID_STR "c68f3def-c7c8-4ee8-861c-eef49a48b702"

#define NS_IHTTPCHANNELAUTHPROVIDER_IID \
  {0xc68f3def, 0xc7c8, 0x4ee8, \
    { 0x86, 0x1c, 0xee, 0xf4, 0x9a, 0x48, 0xb7, 0x02 }}

/**
 * nsIHttpChannelAuthProvider
 *
 * This interface is intended for providing authentication for http-style
 * channels, like nsIHttpChannel and nsIWebSocket, which implement the
 * nsIHttpAuthenticableChannel interface.
 *
 * When requesting pages AddAuthorizationHeaders MUST be called
 * in order to get the http cached headers credentials. When the request is
 * unsuccessful because of receiving either a 401 or 407 http response code
 * ProcessAuthentication MUST be called and the page MUST be requested again
 * with the new credentials that the user has provided. After a successful
 * request, checkForSuperfluousAuth MAY be called, and disconnect MUST be
 * called.
 */
class NS_NO_VTABLE NS_SCRIPTABLE nsIHttpChannelAuthProvider : public nsICancelable {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELAUTHPROVIDER_IID)

  /**
   * Initializes the http authentication support for the channel.
   * Implementations must hold a weak reference of the channel.
   */
  /* void init (in nsIHttpAuthenticableChannel channel); */
  NS_SCRIPTABLE NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel) = 0;

  /**
   * Upon receipt of a server challenge, this function is called to determine
   * the credentials to send.
   *
   * @param httpStatus
   *        the http status received.
   * @param sslConnectFailed
   *        if the last ssl tunnel connection attempt was or not successful.
   * @param callback
   *        the callback to be called when it returns NS_ERROR_IN_PROGRESS.
   *        The implementation must hold a weak reference.
   *
   * @returns NS_OK if the credentials were got and set successfully.
   *          NS_ERROR_IN_PROGRESS if the credentials are going to be asked to
   *                               the user. The channel reference must be
   *                               alive until the feedback from
   *                               nsIHttpAuthenticableChannel's methods or
   *                               until disconnect be called.
   */
  /* void processAuthentication (in unsigned long httpStatus, in boolean sslConnectFailed); */
  NS_SCRIPTABLE NS_IMETHOD ProcessAuthentication(PRUint32 httpStatus, PRBool sslConnectFailed) = 0;

  /**
   * Add credentials from the http auth cache.
   */
  /* void addAuthorizationHeaders (); */
  NS_SCRIPTABLE NS_IMETHOD AddAuthorizationHeaders(void) = 0;

  /**
   * Check if an unnecessary(and maybe malicious) url authentication has been
   * provided.
   */
  /* void checkForSuperfluousAuth (); */
  NS_SCRIPTABLE NS_IMETHOD CheckForSuperfluousAuth(void) = 0;

  /**
   * Cancel pending user auth prompts and release the callback and channel
   * weak references.
   */
  /* void disconnect (in nsresult status); */
  NS_SCRIPTABLE NS_IMETHOD Disconnect(nsresult status) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelAuthProvider, NS_IHTTPCHANNELAUTHPROVIDER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELAUTHPROVIDER \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel); \
  NS_SCRIPTABLE NS_IMETHOD ProcessAuthentication(PRUint32 httpStatus, PRBool sslConnectFailed); \
  NS_SCRIPTABLE NS_IMETHOD AddAuthorizationHeaders(void); \
  NS_SCRIPTABLE NS_IMETHOD CheckForSuperfluousAuth(void); \
  NS_SCRIPTABLE NS_IMETHOD Disconnect(nsresult status); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELAUTHPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel) { return _to Init(channel); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessAuthentication(PRUint32 httpStatus, PRBool sslConnectFailed) { return _to ProcessAuthentication(httpStatus, sslConnectFailed); } \
  NS_SCRIPTABLE NS_IMETHOD AddAuthorizationHeaders(void) { return _to AddAuthorizationHeaders(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckForSuperfluousAuth(void) { return _to CheckForSuperfluousAuth(); } \
  NS_SCRIPTABLE NS_IMETHOD Disconnect(nsresult status) { return _to Disconnect(status); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELAUTHPROVIDER(_to) \
  NS_SCRIPTABLE NS_IMETHOD Init(nsIHttpAuthenticableChannel *channel) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(channel); } \
  NS_SCRIPTABLE NS_IMETHOD ProcessAuthentication(PRUint32 httpStatus, PRBool sslConnectFailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->ProcessAuthentication(httpStatus, sslConnectFailed); } \
  NS_SCRIPTABLE NS_IMETHOD AddAuthorizationHeaders(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddAuthorizationHeaders(); } \
  NS_SCRIPTABLE NS_IMETHOD CheckForSuperfluousAuth(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->CheckForSuperfluousAuth(); } \
  NS_SCRIPTABLE NS_IMETHOD Disconnect(nsresult status) { return !_to ? NS_ERROR_NULL_POINTER : _to->Disconnect(status); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelAuthProvider : public nsIHttpChannelAuthProvider
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELAUTHPROVIDER

  nsHttpChannelAuthProvider();

private:
  ~nsHttpChannelAuthProvider();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpChannelAuthProvider, nsIHttpChannelAuthProvider)

nsHttpChannelAuthProvider::nsHttpChannelAuthProvider()
{
  /* member initializers and constructor code */
}

nsHttpChannelAuthProvider::~nsHttpChannelAuthProvider()
{
  /* destructor code */
}

/* void init (in nsIHttpAuthenticableChannel channel); */
NS_IMETHODIMP nsHttpChannelAuthProvider::Init(nsIHttpAuthenticableChannel *channel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void processAuthentication (in unsigned long httpStatus, in boolean sslConnectFailed); */
NS_IMETHODIMP nsHttpChannelAuthProvider::ProcessAuthentication(PRUint32 httpStatus, PRBool sslConnectFailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addAuthorizationHeaders (); */
NS_IMETHODIMP nsHttpChannelAuthProvider::AddAuthorizationHeaders()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void checkForSuperfluousAuth (); */
NS_IMETHODIMP nsHttpChannelAuthProvider::CheckForSuperfluousAuth()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void disconnect (in nsresult status); */
NS_IMETHODIMP nsHttpChannelAuthProvider::Disconnect(nsresult status)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelAuthProvider_h__ */
