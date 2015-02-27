/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIIOService.idl
 */

#ifndef __gen_nsIIOService_h__
#define __gen_nsIIOService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIProtocolHandler; /* forward declaration */

class nsIChannel; /* forward declaration */

class nsIURI; /* forward declaration */

class nsIFile; /* forward declaration */


/* starting interface:    nsIIOService */
#define NS_IIOSERVICE_IID_STR "bddeda3f-9020-4d12-8c70-984ee9f7935e"

#define NS_IIOSERVICE_IID \
  {0xbddeda3f, 0x9020, 0x4d12, \
    { 0x8c, 0x70, 0x98, 0x4e, 0xe9, 0xf7, 0x93, 0x5e }}

class NS_NO_VTABLE nsIIOService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IIOSERVICE_IID)

  /* nsIProtocolHandler getProtocolHandler (in string aScheme); */
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) = 0;

  /* unsigned long getProtocolFlags (in string aScheme); */
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) = 0;

  /* nsIURI newURI (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) = 0;

  /* nsIURI newFileURI (in nsIFile aFile); */
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) = 0;

  /* nsIChannel newChannelFromURI (in nsIURI aURI); */
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) = 0;

  /* nsIChannel newChannel (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) = 0;

  /* attribute boolean offline; */
  NS_IMETHOD GetOffline(bool *aOffline) = 0;
  NS_IMETHOD SetOffline(bool aOffline) = 0;

  /* boolean allowPort (in long aPort, in string aScheme); */
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) = 0;

  /* ACString extractScheme (in AUTF8String urlString); */
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIIOService, NS_IIOSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIIOSERVICE \
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval); \
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval); \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval); \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval); \
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval); \
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval); \
  NS_IMETHOD GetOffline(bool *aOffline); \
  NS_IMETHOD SetOffline(bool aOffline); \
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval); \
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIIOSERVICE(_to) \
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) { return _to GetProtocolHandler(aScheme, _retval); } \
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) { return _to GetProtocolFlags(aScheme, _retval); } \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) { return _to NewURI(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) { return _to NewFileURI(aFile, _retval); } \
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) { return _to NewChannelFromURI(aURI, _retval); } \
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) { return _to NewChannel(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return _to GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return _to SetOffline(aOffline); } \
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) { return _to AllowPort(aPort, aScheme, _retval); } \
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) { return _to ExtractScheme(urlString, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIIOSERVICE(_to) \
  NS_IMETHOD GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolHandler(aScheme, _retval); } \
  NS_IMETHOD GetProtocolFlags(const char * aScheme, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocolFlags(aScheme, _retval); } \
  NS_IMETHOD NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewURI(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD NewFileURI(nsIFile *aFile, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewFileURI(aFile, _retval); } \
  NS_IMETHOD NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannelFromURI(aURI, _retval); } \
  NS_IMETHOD NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->NewChannel(aSpec, aOriginCharset, aBaseURI, _retval); } \
  NS_IMETHOD GetOffline(bool *aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOffline(aOffline); } \
  NS_IMETHOD SetOffline(bool aOffline) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOffline(aOffline); } \
  NS_IMETHOD AllowPort(int32_t aPort, const char * aScheme, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->AllowPort(aPort, aScheme, _retval); } \
  NS_IMETHOD ExtractScheme(const nsACString & urlString, nsACString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->ExtractScheme(urlString, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsIOService : public nsIIOService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIIOSERVICE

  nsIOService();

private:
  ~nsIOService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsIOService, nsIIOService)

nsIOService::nsIOService()
{
  /* member initializers and constructor code */
}

nsIOService::~nsIOService()
{
  /* destructor code */
}

/* nsIProtocolHandler getProtocolHandler (in string aScheme); */
NS_IMETHODIMP nsIOService::GetProtocolHandler(const char * aScheme, nsIProtocolHandler * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long getProtocolFlags (in string aScheme); */
NS_IMETHODIMP nsIOService::GetProtocolFlags(const char * aScheme, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI newURI (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsIOService::NewURI(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI newFileURI (in nsIFile aFile); */
NS_IMETHODIMP nsIOService::NewFileURI(nsIFile *aFile, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannelFromURI (in nsIURI aURI); */
NS_IMETHODIMP nsIOService::NewChannelFromURI(nsIURI *aURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIChannel newChannel (in AUTF8String aSpec, in string aOriginCharset, in nsIURI aBaseURI); */
NS_IMETHODIMP nsIOService::NewChannel(const nsACString & aSpec, const char * aOriginCharset, nsIURI *aBaseURI, nsIChannel * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean offline; */
NS_IMETHODIMP nsIOService::GetOffline(bool *aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsIOService::SetOffline(bool aOffline)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean allowPort (in long aPort, in string aScheme); */
NS_IMETHODIMP nsIOService::AllowPort(int32_t aPort, const char * aScheme, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* ACString extractScheme (in AUTF8String urlString); */
NS_IMETHODIMP nsIOService::ExtractScheme(const nsACString & urlString, nsACString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif

/**
 * We send notifications through nsIObserverService with topic
 * NS_IOSERVICE_GOING_OFFLINE_TOPIC and data NS_IOSERVICE_OFFLINE
 * when 'offline' has changed from false to true, and we are about
 * to shut down network services such as DNS. When those
 * services have been shut down, we send a notification with
 * topic NS_IOSERVICE_OFFLINE_STATUS_TOPIC and data
 * NS_IOSERVICE_OFFLINE.
 *
 * When 'offline' changes from true to false, then after
 * network services have been restarted, we send a notification
 * with topic NS_IOSERVICE_OFFLINE_STATUS_TOPIC and data
 * NS_IOSERVICE_ONLINE.
 */
#define NS_IOSERVICE_GOING_OFFLINE_TOPIC  "network:offline-about-to-go-offline"
#define NS_IOSERVICE_OFFLINE_STATUS_TOPIC "network:offline-status-changed"
#define NS_IOSERVICE_OFFLINE              "offline"
#define NS_IOSERVICE_ONLINE               "online"

#endif /* __gen_nsIIOService_h__ */
