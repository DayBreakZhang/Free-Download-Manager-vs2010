/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIWebSocketChannel.idl
 */

#ifndef __gen_nsIWebSocketChannel_h__
#define __gen_nsIWebSocketChannel_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInterfaceRequestor; /* forward declaration */

class nsILoadGroup; /* forward declaration */

class nsIWebSocketListener; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsIWebSocketChannel */
#define NS_IWEBSOCKETCHANNEL_IID_STR "9ee5874c-ec39-4bc2-b2d7-194a4c98c9d2"

#define NS_IWEBSOCKETCHANNEL_IID \
  {0x9ee5874c, 0xec39, 0x4bc2, \
    { 0xb2, 0xd7, 0x19, 0x4a, 0x4c, 0x98, 0xc9, 0xd2 }}

class NS_NO_VTABLE nsIWebSocketChannel : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IWEBSOCKETCHANNEL_IID)

  /* readonly attribute nsIURI originalURI; */
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI) = 0;

  /* readonly attribute nsIURI URI; */
  NS_IMETHOD GetURI(nsIURI * *aURI) = 0;

  /* attribute nsIInterfaceRequestor notificationCallbacks; */
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) = 0;
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) = 0;

  /* readonly attribute nsISupports securityInfo; */
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) = 0;

  /* attribute nsILoadGroup loadGroup; */
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) = 0;
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup) = 0;

  /* attribute ACString protocol; */
  NS_IMETHOD GetProtocol(nsACString & aProtocol) = 0;
  NS_IMETHOD SetProtocol(const nsACString & aProtocol) = 0;

  /* readonly attribute ACString extensions; */
  NS_IMETHOD GetExtensions(nsACString & aExtensions) = 0;

  /* void asyncOpen (in nsIURI aURI, in ACString aOrigin, in nsIWebSocketListener aListener, in nsISupports aContext); */
  NS_IMETHOD AsyncOpen(nsIURI *aURI, const nsACString & aOrigin, nsIWebSocketListener *aListener, nsISupports *aContext) = 0;

  /* void close (in unsigned short aCode, in AUTF8String aReason); */
  NS_IMETHOD Close(uint16_t aCode, const nsACString & aReason) = 0;

  enum {
    CLOSE_NORMAL = 1000U,
    CLOSE_GOING_AWAY = 1001U,
    CLOSE_PROTOCOL_ERROR = 1002U,
    CLOSE_UNSUPPORTED_DATATYPE = 1003U,
    CLOSE_NO_STATUS = 1005U,
    CLOSE_ABNORMAL = 1006U,
    CLOSE_INVALID_PAYLOAD = 1007U,
    CLOSE_POLICY_VIOLATION = 1008U,
    CLOSE_TOO_LARGE = 1009U,
    CLOSE_EXTENSION_MISSING = 1010U,
    CLOSE_INTERNAL_ERROR = 1011U,
    CLOSE_TLS_FAILED = 1015U
  };

  /* void sendMsg (in AUTF8String aMsg); */
  NS_IMETHOD SendMsg(const nsACString & aMsg) = 0;

  /* void sendBinaryMsg (in ACString aMsg); */
  NS_IMETHOD SendBinaryMsg(const nsACString & aMsg) = 0;

  /* void sendBinaryStream (in nsIInputStream aStream, in unsigned long length); */
  NS_IMETHOD SendBinaryStream(nsIInputStream *aStream, uint32_t length) = 0;

  /* attribute unsigned long pingInterval; */
  NS_IMETHOD GetPingInterval(uint32_t *aPingInterval) = 0;
  NS_IMETHOD SetPingInterval(uint32_t aPingInterval) = 0;

  /* attribute unsigned long pingTimeout; */
  NS_IMETHOD GetPingTimeout(uint32_t *aPingTimeout) = 0;
  NS_IMETHOD SetPingTimeout(uint32_t aPingTimeout) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIWebSocketChannel, NS_IWEBSOCKETCHANNEL_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIWEBSOCKETCHANNEL \
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI); \
  NS_IMETHOD GetURI(nsIURI * *aURI); \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks); \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks); \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo); \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup); \
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup); \
  NS_IMETHOD GetProtocol(nsACString & aProtocol); \
  NS_IMETHOD SetProtocol(const nsACString & aProtocol); \
  NS_IMETHOD GetExtensions(nsACString & aExtensions); \
  NS_IMETHOD AsyncOpen(nsIURI *aURI, const nsACString & aOrigin, nsIWebSocketListener *aListener, nsISupports *aContext); \
  NS_IMETHOD Close(uint16_t aCode, const nsACString & aReason); \
  NS_IMETHOD SendMsg(const nsACString & aMsg); \
  NS_IMETHOD SendBinaryMsg(const nsACString & aMsg); \
  NS_IMETHOD SendBinaryStream(nsIInputStream *aStream, uint32_t length); \
  NS_IMETHOD GetPingInterval(uint32_t *aPingInterval); \
  NS_IMETHOD SetPingInterval(uint32_t aPingInterval); \
  NS_IMETHOD GetPingTimeout(uint32_t *aPingTimeout); \
  NS_IMETHOD SetPingTimeout(uint32_t aPingTimeout); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIWEBSOCKETCHANNEL(_to) \
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI) { return _to GetOriginalURI(aOriginalURI); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return _to GetURI(aURI); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return _to GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return _to SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return _to GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return _to GetLoadGroup(aLoadGroup); } \
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup) { return _to SetLoadGroup(aLoadGroup); } \
  NS_IMETHOD GetProtocol(nsACString & aProtocol) { return _to GetProtocol(aProtocol); } \
  NS_IMETHOD SetProtocol(const nsACString & aProtocol) { return _to SetProtocol(aProtocol); } \
  NS_IMETHOD GetExtensions(nsACString & aExtensions) { return _to GetExtensions(aExtensions); } \
  NS_IMETHOD AsyncOpen(nsIURI *aURI, const nsACString & aOrigin, nsIWebSocketListener *aListener, nsISupports *aContext) { return _to AsyncOpen(aURI, aOrigin, aListener, aContext); } \
  NS_IMETHOD Close(uint16_t aCode, const nsACString & aReason) { return _to Close(aCode, aReason); } \
  NS_IMETHOD SendMsg(const nsACString & aMsg) { return _to SendMsg(aMsg); } \
  NS_IMETHOD SendBinaryMsg(const nsACString & aMsg) { return _to SendBinaryMsg(aMsg); } \
  NS_IMETHOD SendBinaryStream(nsIInputStream *aStream, uint32_t length) { return _to SendBinaryStream(aStream, length); } \
  NS_IMETHOD GetPingInterval(uint32_t *aPingInterval) { return _to GetPingInterval(aPingInterval); } \
  NS_IMETHOD SetPingInterval(uint32_t aPingInterval) { return _to SetPingInterval(aPingInterval); } \
  NS_IMETHOD GetPingTimeout(uint32_t *aPingTimeout) { return _to GetPingTimeout(aPingTimeout); } \
  NS_IMETHOD SetPingTimeout(uint32_t aPingTimeout) { return _to SetPingTimeout(aPingTimeout); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIWEBSOCKETCHANNEL(_to) \
  NS_IMETHOD GetOriginalURI(nsIURI * *aOriginalURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOriginalURI(aOriginalURI); } \
  NS_IMETHOD GetURI(nsIURI * *aURI) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetURI(aURI); } \
  NS_IMETHOD GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNotificationCallbacks(aNotificationCallbacks); } \
  NS_IMETHOD GetSecurityInfo(nsISupports * *aSecurityInfo) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSecurityInfo(aSecurityInfo); } \
  NS_IMETHOD GetLoadGroup(nsILoadGroup * *aLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLoadGroup(aLoadGroup); } \
  NS_IMETHOD SetLoadGroup(nsILoadGroup *aLoadGroup) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLoadGroup(aLoadGroup); } \
  NS_IMETHOD GetProtocol(nsACString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetProtocol(aProtocol); } \
  NS_IMETHOD SetProtocol(const nsACString & aProtocol) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetProtocol(aProtocol); } \
  NS_IMETHOD GetExtensions(nsACString & aExtensions) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExtensions(aExtensions); } \
  NS_IMETHOD AsyncOpen(nsIURI *aURI, const nsACString & aOrigin, nsIWebSocketListener *aListener, nsISupports *aContext) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncOpen(aURI, aOrigin, aListener, aContext); } \
  NS_IMETHOD Close(uint16_t aCode, const nsACString & aReason) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(aCode, aReason); } \
  NS_IMETHOD SendMsg(const nsACString & aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMsg(aMsg); } \
  NS_IMETHOD SendBinaryMsg(const nsACString & aMsg) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendBinaryMsg(aMsg); } \
  NS_IMETHOD SendBinaryStream(nsIInputStream *aStream, uint32_t length) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendBinaryStream(aStream, length); } \
  NS_IMETHOD GetPingInterval(uint32_t *aPingInterval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPingInterval(aPingInterval); } \
  NS_IMETHOD SetPingInterval(uint32_t aPingInterval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPingInterval(aPingInterval); } \
  NS_IMETHOD GetPingTimeout(uint32_t *aPingTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPingTimeout(aPingTimeout); } \
  NS_IMETHOD SetPingTimeout(uint32_t aPingTimeout) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPingTimeout(aPingTimeout); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsWebSocketChannel : public nsIWebSocketChannel
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIWEBSOCKETCHANNEL

  nsWebSocketChannel();

private:
  ~nsWebSocketChannel();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsWebSocketChannel, nsIWebSocketChannel)

nsWebSocketChannel::nsWebSocketChannel()
{
  /* member initializers and constructor code */
}

nsWebSocketChannel::~nsWebSocketChannel()
{
  /* destructor code */
}

/* readonly attribute nsIURI originalURI; */
NS_IMETHODIMP nsWebSocketChannel::GetOriginalURI(nsIURI * *aOriginalURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIURI URI; */
NS_IMETHODIMP nsWebSocketChannel::GetURI(nsIURI * *aURI)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsIInterfaceRequestor notificationCallbacks; */
NS_IMETHODIMP nsWebSocketChannel::GetNotificationCallbacks(nsIInterfaceRequestor * *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocketChannel::SetNotificationCallbacks(nsIInterfaceRequestor *aNotificationCallbacks)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsISupports securityInfo; */
NS_IMETHODIMP nsWebSocketChannel::GetSecurityInfo(nsISupports * *aSecurityInfo)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute nsILoadGroup loadGroup; */
NS_IMETHODIMP nsWebSocketChannel::GetLoadGroup(nsILoadGroup * *aLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocketChannel::SetLoadGroup(nsILoadGroup *aLoadGroup)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute ACString protocol; */
NS_IMETHODIMP nsWebSocketChannel::GetProtocol(nsACString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocketChannel::SetProtocol(const nsACString & aProtocol)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString extensions; */
NS_IMETHODIMP nsWebSocketChannel::GetExtensions(nsACString & aExtensions)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncOpen (in nsIURI aURI, in ACString aOrigin, in nsIWebSocketListener aListener, in nsISupports aContext); */
NS_IMETHODIMP nsWebSocketChannel::AsyncOpen(nsIURI *aURI, const nsACString & aOrigin, nsIWebSocketListener *aListener, nsISupports *aContext)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (in unsigned short aCode, in AUTF8String aReason); */
NS_IMETHODIMP nsWebSocketChannel::Close(uint16_t aCode, const nsACString & aReason)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendMsg (in AUTF8String aMsg); */
NS_IMETHODIMP nsWebSocketChannel::SendMsg(const nsACString & aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendBinaryMsg (in ACString aMsg); */
NS_IMETHODIMP nsWebSocketChannel::SendBinaryMsg(const nsACString & aMsg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendBinaryStream (in nsIInputStream aStream, in unsigned long length); */
NS_IMETHODIMP nsWebSocketChannel::SendBinaryStream(nsIInputStream *aStream, uint32_t length)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long pingInterval; */
NS_IMETHODIMP nsWebSocketChannel::GetPingInterval(uint32_t *aPingInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocketChannel::SetPingInterval(uint32_t aPingInterval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long pingTimeout; */
NS_IMETHODIMP nsWebSocketChannel::GetPingTimeout(uint32_t *aPingTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsWebSocketChannel::SetPingTimeout(uint32_t aPingTimeout)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIWebSocketChannel_h__ */
