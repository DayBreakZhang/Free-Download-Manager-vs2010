/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/protocol/http/nsIHttpChannelInternal.idl
 */

#ifndef __gen_nsIHttpChannelInternal_h__
#define __gen_nsIHttpChannelInternal_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsTArray.h"
class nsCString;
class nsISocketTransport; /* forward declaration */

class nsIAsyncInputStream; /* forward declaration */

class nsIAsyncOutputStream; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIProxyInfo; /* forward declaration */


/* starting interface:    nsIHttpUpgradeListener */
#define NS_IHTTPUPGRADELISTENER_IID_STR "4b967b6d-cd1c-49ae-a457-23ff76f5a2e8"

#define NS_IHTTPUPGRADELISTENER_IID \
  {0x4b967b6d, 0xcd1c, 0x49ae, \
    { 0xa4, 0x57, 0x23, 0xff, 0x76, 0xf5, 0xa2, 0xe8 }}

class NS_NO_VTABLE nsIHttpUpgradeListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPUPGRADELISTENER_IID)

  /* void onTransportAvailable (in nsISocketTransport aTransport, in nsIAsyncInputStream aSocketIn, in nsIAsyncOutputStream aSocketOut); */
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpUpgradeListener, NS_IHTTPUPGRADELISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPUPGRADELISTENER \
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPUPGRADELISTENER(_to) \
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) { return _to OnTransportAvailable(aTransport, aSocketIn, aSocketOut); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPUPGRADELISTENER(_to) \
  NS_IMETHOD OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnTransportAvailable(aTransport, aSocketIn, aSocketOut); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpUpgradeListener : public nsIHttpUpgradeListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPUPGRADELISTENER

  nsHttpUpgradeListener();

private:
  ~nsHttpUpgradeListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpUpgradeListener, nsIHttpUpgradeListener)

nsHttpUpgradeListener::nsHttpUpgradeListener()
{
  /* member initializers and constructor code */
}

nsHttpUpgradeListener::~nsHttpUpgradeListener()
{
  /* destructor code */
}

/* void onTransportAvailable (in nsISocketTransport aTransport, in nsIAsyncInputStream aSocketIn, in nsIAsyncOutputStream aSocketOut); */
NS_IMETHODIMP nsHttpUpgradeListener::OnTransportAvailable(nsISocketTransport *aTransport, nsIAsyncInputStream *aSocketIn, nsIAsyncOutputStream *aSocketOut)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIHttpChannelInternal */
#define NS_IHTTPCHANNELINTERNAL_IID_STR "74d13d41-85cd-490f-9942-300d0c01c726"

#define NS_IHTTPCHANNELINTERNAL_IID \
  {0x74d13d41, 0x85cd, 0x490f, \
    { 0x99, 0x42, 0x30, 0x0d, 0x0c, 0x01, 0xc7, 0x26 }}

class NS_NO_VTABLE nsIHttpChannelInternal : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IHTTPCHANNELINTERNAL_IID)

  /* attribute nsIURI documentURI; */
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) = 0;
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) = 0;

  /* void getRequestVersion (out unsigned long major, out unsigned long minor); */
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) = 0;

  /* void getResponseVersion (out unsigned long major, out unsigned long minor); */
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) = 0;

  /* void setCookie (in string aCookieHeader); */
  NS_IMETHOD SetCookie(const char * aCookieHeader) = 0;

  /* void setupFallbackChannel (in string aFallbackKey); */
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) = 0;

  /* attribute boolean forceAllowThirdPartyCookie; */
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) = 0;
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) = 0;

  /* readonly attribute boolean canceled; */
  NS_IMETHOD GetCanceled(bool *aCanceled) = 0;

  /* attribute boolean channelIsForDownload; */
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) = 0;
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) = 0;

  /* readonly attribute AUTF8String localAddress; */
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) = 0;

  /* readonly attribute int32_t localPort; */
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) = 0;

  /* readonly attribute AUTF8String remoteAddress; */
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) = 0;

  /* readonly attribute int32_t remotePort; */
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) = 0;

  /* [noscript] void setCacheKeysRedirectChain (in StringArray cacheKeys); */
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) = 0;

  /* void HTTPUpgrade (in ACString aProtocolName, in nsIHttpUpgradeListener aListener); */
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) = 0;

  /* attribute boolean allowSpdy; */
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) = 0;
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) = 0;

  /* attribute boolean loadAsBlocking; */
  NS_IMETHOD GetLoadAsBlocking(bool *aLoadAsBlocking) = 0;
  NS_IMETHOD SetLoadAsBlocking(bool aLoadAsBlocking) = 0;

  /* attribute boolean loadUnblocked; */
  NS_IMETHOD GetLoadUnblocked(bool *aLoadUnblocked) = 0;
  NS_IMETHOD SetLoadUnblocked(bool aLoadUnblocked) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIHttpChannelInternal, NS_IHTTPCHANNELINTERNAL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIHTTPCHANNELINTERNAL \
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI); \
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI); \
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor); \
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor); \
  NS_IMETHOD SetCookie(const char * aCookieHeader); \
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey); \
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie); \
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie); \
  NS_IMETHOD GetCanceled(bool *aCanceled); \
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload); \
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload); \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress); \
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort); \
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress); \
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort); \
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys); \
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener); \
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy); \
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy); \
  NS_IMETHOD GetLoadAsBlocking(bool *aLoadAsBlocking); \
  NS_IMETHOD SetLoadAsBlocking(bool aLoadAsBlocking); \
  NS_IMETHOD GetLoadUnblocked(bool *aLoadUnblocked); \
  NS_IMETHOD SetLoadUnblocked(bool aLoadUnblocked); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIHTTPCHANNELINTERNAL(_to) \
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) { return _to GetDocumentURI(aDocumentURI); } \
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) { return _to SetDocumentURI(aDocumentURI); } \
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) { return _to GetRequestVersion(major, minor); } \
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) { return _to GetResponseVersion(major, minor); } \
  NS_IMETHOD SetCookie(const char * aCookieHeader) { return _to SetCookie(aCookieHeader); } \
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) { return _to SetupFallbackChannel(aFallbackKey); } \
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) { return _to GetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) { return _to SetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD GetCanceled(bool *aCanceled) { return _to GetCanceled(aCanceled); } \
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) { return _to GetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) { return _to SetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) { return _to GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) { return _to GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) { return _to GetRemoteAddress(aRemoteAddress); } \
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) { return _to GetRemotePort(aRemotePort); } \
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) { return _to SetCacheKeysRedirectChain(cacheKeys); } \
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) { return _to HTTPUpgrade(aProtocolName, aListener); } \
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) { return _to GetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) { return _to SetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD GetLoadAsBlocking(bool *aLoadAsBlocking) { return _to GetLoadAsBlocking(aLoadAsBlocking); } \
  NS_IMETHOD SetLoadAsBlocking(bool aLoadAsBlocking) { return _to SetLoadAsBlocking(aLoadAsBlocking); } \
  NS_IMETHOD GetLoadUnblocked(bool *aLoadUnblocked) { return _to GetLoadUnblocked(aLoadUnblocked); } \
  NS_IMETHOD SetLoadUnblocked(bool aLoadUnblocked) { return _to SetLoadUnblocked(aLoadUnblocked); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIHTTPCHANNELINTERNAL(_to) \
  NS_IMETHOD GetDocumentURI(nsIURI * *aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDocumentURI(aDocumentURI); } \
  NS_IMETHOD SetDocumentURI(nsIURI *aDocumentURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDocumentURI(aDocumentURI); } \
  NS_IMETHOD GetRequestVersion(uint32_t *major, uint32_t *minor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRequestVersion(major, minor); } \
  NS_IMETHOD GetResponseVersion(uint32_t *major, uint32_t *minor) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetResponseVersion(major, minor); } \
  NS_IMETHOD SetCookie(const char * aCookieHeader) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCookie(aCookieHeader); } \
  NS_IMETHOD SetupFallbackChannel(const char * aFallbackKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetupFallbackChannel(aFallbackKey); } \
  NS_IMETHOD GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetForceAllowThirdPartyCookie(aForceAllowThirdPartyCookie); } \
  NS_IMETHOD GetCanceled(bool *aCanceled) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCanceled(aCanceled); } \
  NS_IMETHOD GetChannelIsForDownload(bool *aChannelIsForDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD SetChannelIsForDownload(bool aChannelIsForDownload) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetChannelIsForDownload(aChannelIsForDownload); } \
  NS_IMETHOD GetLocalAddress(nsACString & aLocalAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalAddress(aLocalAddress); } \
  NS_IMETHOD GetLocalPort(int32_t *aLocalPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocalPort(aLocalPort); } \
  NS_IMETHOD GetRemoteAddress(nsACString & aRemoteAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemoteAddress(aRemoteAddress); } \
  NS_IMETHOD GetRemotePort(int32_t *aRemotePort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRemotePort(aRemotePort); } \
  NS_IMETHOD SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCacheKeysRedirectChain(cacheKeys); } \
  NS_IMETHOD HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->HTTPUpgrade(aProtocolName, aListener); } \
  NS_IMETHOD GetAllowSpdy(bool *aAllowSpdy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD SetAllowSpdy(bool aAllowSpdy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAllowSpdy(aAllowSpdy); } \
  NS_IMETHOD GetLoadAsBlocking(bool *aLoadAsBlocking) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadAsBlocking(aLoadAsBlocking); } \
  NS_IMETHOD SetLoadAsBlocking(bool aLoadAsBlocking) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadAsBlocking(aLoadAsBlocking); } \
  NS_IMETHOD GetLoadUnblocked(bool *aLoadUnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadUnblocked(aLoadUnblocked); } \
  NS_IMETHOD SetLoadUnblocked(bool aLoadUnblocked) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadUnblocked(aLoadUnblocked); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsHttpChannelInternal : public nsIHttpChannelInternal
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIHTTPCHANNELINTERNAL

  nsHttpChannelInternal();

private:
  ~nsHttpChannelInternal();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsHttpChannelInternal, nsIHttpChannelInternal)

nsHttpChannelInternal::nsHttpChannelInternal()
{
  /* member initializers and constructor code */
}

nsHttpChannelInternal::~nsHttpChannelInternal()
{
  /* destructor code */
}

/* attribute nsIURI documentURI; */
NS_IMETHODIMP nsHttpChannelInternal::GetDocumentURI(nsIURI * *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetDocumentURI(nsIURI *aDocumentURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getRequestVersion (out unsigned long major, out unsigned long minor); */
NS_IMETHODIMP nsHttpChannelInternal::GetRequestVersion(uint32_t *major, uint32_t *minor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getResponseVersion (out unsigned long major, out unsigned long minor); */
NS_IMETHODIMP nsHttpChannelInternal::GetResponseVersion(uint32_t *major, uint32_t *minor)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setCookie (in string aCookieHeader); */
NS_IMETHODIMP nsHttpChannelInternal::SetCookie(const char * aCookieHeader)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void setupFallbackChannel (in string aFallbackKey); */
NS_IMETHODIMP nsHttpChannelInternal::SetupFallbackChannel(const char * aFallbackKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean forceAllowThirdPartyCookie; */
NS_IMETHODIMP nsHttpChannelInternal::GetForceAllowThirdPartyCookie(bool *aForceAllowThirdPartyCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetForceAllowThirdPartyCookie(bool aForceAllowThirdPartyCookie)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean canceled; */
NS_IMETHODIMP nsHttpChannelInternal::GetCanceled(bool *aCanceled)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean channelIsForDownload; */
NS_IMETHODIMP nsHttpChannelInternal::GetChannelIsForDownload(bool *aChannelIsForDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetChannelIsForDownload(bool aChannelIsForDownload)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String localAddress; */
NS_IMETHODIMP nsHttpChannelInternal::GetLocalAddress(nsACString & aLocalAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t localPort; */
NS_IMETHODIMP nsHttpChannelInternal::GetLocalPort(int32_t *aLocalPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AUTF8String remoteAddress; */
NS_IMETHODIMP nsHttpChannelInternal::GetRemoteAddress(nsACString & aRemoteAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute int32_t remotePort; */
NS_IMETHODIMP nsHttpChannelInternal::GetRemotePort(int32_t *aRemotePort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void setCacheKeysRedirectChain (in StringArray cacheKeys); */
NS_IMETHODIMP nsHttpChannelInternal::SetCacheKeysRedirectChain(nsTArray<nsCString> *cacheKeys)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void HTTPUpgrade (in ACString aProtocolName, in nsIHttpUpgradeListener aListener); */
NS_IMETHODIMP nsHttpChannelInternal::HTTPUpgrade(const nsACString & aProtocolName, nsIHttpUpgradeListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean allowSpdy; */
NS_IMETHODIMP nsHttpChannelInternal::GetAllowSpdy(bool *aAllowSpdy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetAllowSpdy(bool aAllowSpdy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean loadAsBlocking; */
NS_IMETHODIMP nsHttpChannelInternal::GetLoadAsBlocking(bool *aLoadAsBlocking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetLoadAsBlocking(bool aLoadAsBlocking)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean loadUnblocked; */
NS_IMETHODIMP nsHttpChannelInternal::GetLoadUnblocked(bool *aLoadUnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsHttpChannelInternal::SetLoadUnblocked(bool aLoadUnblocked)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIHttpChannelInternal_h__ */
