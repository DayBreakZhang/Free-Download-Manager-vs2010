/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIProxiedProtocolHandler.idl
 */

#ifndef __gen_nsIProxiedProtocolHandler_h__
#define __gen_nsIProxiedProtocolHandler_h__


#ifndef __gen_nsIProtocolHandler_h__
#include "nsIProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */


/* starting interface:    nsIProxiedProtocolHandler */
#define NS_IPROXIEDPROTOCOLHANDLER_IID_STR "2b63fe69-b0fc-48f2-a2df-adb795a4ce5c"

#define NS_IPROXIEDPROTOCOLHANDLER_IID \
  {0x2b63fe69, 0xb0fc, 0x48f2, \
    { 0xa2, 0xdf, 0xad, 0xb7, 0x95, 0xa4, 0xce, 0x5c }}

class NS_NO_VTABLE nsIProxiedProtocolHandler : public nsIProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IPROXIEDPROTOCOLHANDLER_IID)

  /* nsIChannel newProxiedChannel (in nsIURI uri, in nsIProxyInfo proxyInfo, in unsigned long proxyResolveFlags, in nsIURI proxyURI); */
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIProxiedProtocolHandler, NS_IPROXIEDPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIPROXIEDPROTOCOLHANDLER \
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIPROXIEDPROTOCOLHANDLER(_to) \
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) { return _to NewProxiedChannel(uri, proxyInfo, proxyResolveFlags, proxyURI, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIPROXIEDPROTOCOLHANDLER(_to) \
  NS_IMETHOD NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewProxiedChannel(uri, proxyInfo, proxyResolveFlags, proxyURI, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsProxiedProtocolHandler : public nsIProxiedProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIPROXIEDPROTOCOLHANDLER

  nsProxiedProtocolHandler();

private:
  ~nsProxiedProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsProxiedProtocolHandler, nsIProxiedProtocolHandler)

nsProxiedProtocolHandler::nsProxiedProtocolHandler()
{
  /* member initializers and constructor code */
}

nsProxiedProtocolHandler::~nsProxiedProtocolHandler()
{
  /* destructor code */
}

/* nsIChannel newProxiedChannel (in nsIURI uri, in nsIProxyInfo proxyInfo, in unsigned long proxyResolveFlags, in nsIURI proxyURI); */
NS_IMETHODIMP nsProxiedProtocolHandler::NewProxiedChannel(nsIURI *uri, nsIProxyInfo *proxyInfo, uint32_t proxyResolveFlags, nsIURI *proxyURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIProxiedProtocolHandler_h__ */
