/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIHttpProtocolHandler.idl
 */

#ifndef __gen_nsIHttpProtocolHandler_h__
#define __gen_nsIHttpProtocolHandler_h__


#ifndef __gen_nsIProxiedProtocolHandler_h__
#include "nsIProxiedProtocolHandler.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIHttpProtocolHandler */
#define NS_IHTTPPROTOCOLHANDLER_IID_STR "c48126d9-2ddd-485b-a51a-378e917e75f8"

#define NS_IHTTPPROTOCOLHANDLER_IID \
  {0xc48126d9, 0x2ddd, 0x485b, \
    { 0xa5, 0x1a, 0x37, 0x8e, 0x91, 0x7e, 0x75, 0xf8 }}

class NS_NO_VTABLE nsIHttpProtocolHandler : public nsIProxiedProtocolHandler {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPPROTOCOLHANDLER_IID)

  /* readonly attribute ACString userAgent; */
  NS_IMETHOD GetUserAgent(nsACString & aUserAgent) = 0;

  /* readonly attribute ACString appName; */
  NS_IMETHOD GetAppName(nsACString & aAppName) = 0;

  /* readonly attribute ACString appVersion; */
  NS_IMETHOD GetAppVersion(nsACString & aAppVersion) = 0;

  /* readonly attribute ACString platform; */
  NS_IMETHOD GetPlatform(nsACString & aPlatform) = 0;

  /* readonly attribute ACString oscpu; */
  NS_IMETHOD GetOscpu(nsACString & aOscpu) = 0;

  /* readonly attribute ACString misc; */
  NS_IMETHOD GetMisc(nsACString & aMisc) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpProtocolHandler, NS_IHTTPPROTOCOLHANDLER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPPROTOCOLHANDLER \
  NS_IMETHOD GetUserAgent(nsACString & aUserAgent); \
  NS_IMETHOD GetAppName(nsACString & aAppName); \
  NS_IMETHOD GetAppVersion(nsACString & aAppVersion); \
  NS_IMETHOD GetPlatform(nsACString & aPlatform); \
  NS_IMETHOD GetOscpu(nsACString & aOscpu); \
  NS_IMETHOD GetMisc(nsACString & aMisc); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPPROTOCOLHANDLER(_to) \
  NS_IMETHOD GetUserAgent(nsACString & aUserAgent) { return _to GetUserAgent(aUserAgent); } \
  NS_IMETHOD GetAppName(nsACString & aAppName) { return _to GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsACString & aAppVersion) { return _to GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetPlatform(nsACString & aPlatform) { return _to GetPlatform(aPlatform); } \
  NS_IMETHOD GetOscpu(nsACString & aOscpu) { return _to GetOscpu(aOscpu); } \
  NS_IMETHOD GetMisc(nsACString & aMisc) { return _to GetMisc(aMisc); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPPROTOCOLHANDLER(_to) \
  NS_IMETHOD GetUserAgent(nsACString & aUserAgent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUserAgent(aUserAgent); } \
  NS_IMETHOD GetAppName(nsACString & aAppName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppName(aAppName); } \
  NS_IMETHOD GetAppVersion(nsACString & aAppVersion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAppVersion(aAppVersion); } \
  NS_IMETHOD GetPlatform(nsACString & aPlatform) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPlatform(aPlatform); } \
  NS_IMETHOD GetOscpu(nsACString & aOscpu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOscpu(aOscpu); } \
  NS_IMETHOD GetMisc(nsACString & aMisc) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMisc(aMisc); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpProtocolHandler : public nsIHttpProtocolHandler
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPPROTOCOLHANDLER

  nsHttpProtocolHandler();

private:
  ~nsHttpProtocolHandler();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpProtocolHandler, nsIHttpProtocolHandler)

nsHttpProtocolHandler::nsHttpProtocolHandler()
{
  /* member initializers and constructor code */
}

nsHttpProtocolHandler::~nsHttpProtocolHandler()
{
  /* destructor code */
}

/* readonly attribute ACString userAgent; */
NS_IMETHODIMP nsHttpProtocolHandler::GetUserAgent(nsACString & aUserAgent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString appName; */
NS_IMETHODIMP nsHttpProtocolHandler::GetAppName(nsACString & aAppName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString appVersion; */
NS_IMETHODIMP nsHttpProtocolHandler::GetAppVersion(nsACString & aAppVersion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString platform; */
NS_IMETHODIMP nsHttpProtocolHandler::GetPlatform(nsACString & aPlatform)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString oscpu; */
NS_IMETHODIMP nsHttpProtocolHandler::GetOscpu(nsACString & aOscpu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString misc; */
NS_IMETHODIMP nsHttpProtocolHandler::GetMisc(nsACString & aMisc)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

// ----------- Categories -----------
/**
 * At initialization time, the HTTP handler will initialize each service
 * registered under this category:
 */
#define NS_HTTP_STARTUP_CATEGORY "http-startup-category"
// ----------- Observer topics -----------
/**
 * nsIObserver notification corresponding to startup category.  Services
 * registered under the startup category will receive this observer topic at
 * startup if they implement nsIObserver.  The "subject" of the notification
 * is the nsIHttpProtocolHandler instance.
 */
#define NS_HTTP_STARTUP_TOPIC "http-startup"
/**
 * This observer topic is notified when an HTTP channel is opened.
 * It is similar to http-on-modify-request, except that
 * 1) The notification is guaranteed to occur before on-modify-request, during
 *    the AsyncOpen call itself.
 * 2) It only occurs for the initial open of a channel, not for internal
 *    asyncOpens that happen during redirects, etc.
 * 3) Some information (most notably nsIProxiedChannel.proxyInfo) may not be set
 *    on the channel object yet.
 *
 * The "subject" of the notification is the nsIHttpChannel instance.
 *
 * Generally the 'http-on-modify-request' notification is preferred unless the
 * synchronous, during-asyncOpen behavior that this notification provides is
 * required.
 */
#define NS_HTTP_ON_OPENING_REQUEST_TOPIC "http-on-opening-request"
/**
 * Before an HTTP request is sent to the server, this observer topic is
 * notified.  The observer of this topic can then choose to set any additional
 * headers for this request before the request is actually sent to the server.
 * The "subject" of the notification is the nsIHttpChannel instance.
 */
#define NS_HTTP_ON_MODIFY_REQUEST_TOPIC "http-on-modify-request"
/**
 * After an HTTP server response is received, this observer topic is notified.
 * The observer of this topic can interrogate the response.  The "subject" of
 * the notification is the nsIHttpChannel instance.
 */
#define NS_HTTP_ON_EXAMINE_RESPONSE_TOPIC "http-on-examine-response"
/**
 * The observer of this topic is notified after the received HTTP response
 * is merged with data from the browser cache.  This means that, among other
 * things, the Content-Type header will be set correctly.
 */
#define NS_HTTP_ON_EXAMINE_MERGED_RESPONSE_TOPIC "http-on-examine-merged-response"
/**
 * The observer of this topic is notified before data is read from the cache.
 * The notification is sent if and only if there is no network communication
 * at all.
 */
#define NS_HTTP_ON_EXAMINE_CACHED_RESPONSE_TOPIC "http-on-examine-cached-response"

#endif /* __gen_nsIHttpProtocolHandler_h__ */
