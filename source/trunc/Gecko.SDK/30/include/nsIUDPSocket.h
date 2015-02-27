/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM ../../../dist/idl\nsIUDPSocket.idl
 */

#ifndef __gen_nsIUDPSocket_h__
#define __gen_nsIUDPSocket_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsINetAddr; /* forward declaration */

class nsIUDPSocketListener; /* forward declaration */

class nsIUDPMessage; /* forward declaration */

class nsISocketTransport; /* forward declaration */

class nsIOutputStream; /* forward declaration */

namespace mozilla {
namespace net {
union NetAddr;
}
}

/* starting interface:    nsIUDPSocket */
#define NS_IUDPSOCKET_IID_STR "6efe692d-f0b0-4a9e-9e63-837c7452446d"

#define NS_IUDPSOCKET_IID \
  {0x6efe692d, 0xf0b0, 0x4a9e, \
    { 0x9e, 0x63, 0x83, 0x7c, 0x74, 0x52, 0x44, 0x6d }}

class NS_NO_VTABLE nsIUDPSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKET_IID)

  /* void init (in long aPort, in boolean aLoopbackOnly); */
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly) = 0;

  /* [noscript] void initWithAddress ([const] in NetAddrPtr aAddr); */
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void asyncListen (in nsIUDPSocketListener aListener); */
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) = 0;

  /* readonly attribute long port; */
  NS_IMETHOD GetPort(int32_t *aPort) = 0;

  /* [noscript] NetAddr getAddress (); */
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) = 0;

  /* unsigned long send (in AUTF8String host, in unsigned short port, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) = 0;

  /* unsigned long sendWithAddr (in nsINetAddr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) = 0;

  /* [noscript] unsigned long sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocket, NS_IUDPSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKET \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly); \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener); \
  NS_IMETHOD GetPort(int32_t *aPort); \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval); \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval); \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval); \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly) { return _to Init(aPort, aLoopbackOnly); } \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr) { return _to InitWithAddress(aAddr); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) { return _to AsyncListen(aListener); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) { return _to GetAddress(_retval); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) { return _to Send(host, port, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) { return _to SendWithAddr(addr, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) { return _to SendWithAddress(addr, data, dataLength, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aPort, aLoopbackOnly); } \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithAddress(aAddr); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD AsyncListen(nsIUDPSocketListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncListen(aListener); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(_retval); } \
  NS_IMETHOD Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(host, port, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddr(addr, data, dataLength, _retval); } \
  NS_IMETHOD SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendWithAddress(addr, data, dataLength, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocket : public nsIUDPSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKET

  nsUDPSocket();

private:
  ~nsUDPSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPSocket, nsIUDPSocket)

nsUDPSocket::nsUDPSocket()
{
  /* member initializers and constructor code */
}

nsUDPSocket::~nsUDPSocket()
{
  /* destructor code */
}

/* void init (in long aPort, in boolean aLoopbackOnly); */
NS_IMETHODIMP nsUDPSocket::Init(int32_t aPort, bool aLoopbackOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWithAddress ([const] in NetAddrPtr aAddr); */
NS_IMETHODIMP nsUDPSocket::InitWithAddress(const mozilla::net::NetAddr *aAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUDPSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncListen (in nsIUDPSocketListener aListener); */
NS_IMETHODIMP nsUDPSocket::AsyncListen(nsIUDPSocketListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsUDPSocket::GetPort(int32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getAddress (); */
NS_IMETHODIMP nsUDPSocket::GetAddress(mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long send (in AUTF8String host, in unsigned short port, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocket::Send(const nsACString & host, uint16_t port, const uint8_t *data, uint32_t dataLength, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* unsigned long sendWithAddr (in nsINetAddr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocket::SendWithAddr(nsINetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] unsigned long sendWithAddress ([const] in NetAddrPtr addr, [array, size_is (dataLength), const] in uint8_t data, in unsigned long dataLength); */
NS_IMETHODIMP nsUDPSocket::SendWithAddress(const mozilla::net::NetAddr *addr, const uint8_t *data, uint32_t dataLength, uint32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPSocketListener */
#define NS_IUDPSOCKETLISTENER_IID_STR "2e4b5dd3-7358-4281-b81f-10c62ef39cb5"

#define NS_IUDPSOCKETLISTENER_IID \
  {0x2e4b5dd3, 0x7358, 0x4281, \
    { 0xb8, 0x1f, 0x10, 0xc6, 0x2e, 0xf3, 0x9c, 0xb5 }}

class NS_NO_VTABLE nsIUDPSocketListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSOCKETLISTENER_IID)

  /* void onPacketReceived (in nsIUDPSocket aSocket, in nsIUDPMessage aMessage); */
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) = 0;

  /* void onStopListening (in nsIUDPSocket aSocket, in nsresult aStatus); */
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPSocketListener, NS_IUDPSOCKETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSOCKETLISTENER \
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage); \
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSOCKETLISTENER(_to) \
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) { return _to OnPacketReceived(aSocket, aMessage); } \
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) { return _to OnStopListening(aSocket, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSOCKETLISTENER(_to) \
  NS_IMETHOD OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPacketReceived(aSocket, aMessage); } \
  NS_IMETHOD OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopListening(aSocket, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPSocketListener : public nsIUDPSocketListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSOCKETLISTENER

  nsUDPSocketListener();

private:
  ~nsUDPSocketListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPSocketListener, nsIUDPSocketListener)

nsUDPSocketListener::nsUDPSocketListener()
{
  /* member initializers and constructor code */
}

nsUDPSocketListener::~nsUDPSocketListener()
{
  /* destructor code */
}

/* void onPacketReceived (in nsIUDPSocket aSocket, in nsIUDPMessage aMessage); */
NS_IMETHODIMP nsUDPSocketListener::OnPacketReceived(nsIUDPSocket *aSocket, nsIUDPMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopListening (in nsIUDPSocket aSocket, in nsresult aStatus); */
NS_IMETHODIMP nsUDPSocketListener::OnStopListening(nsIUDPSocket *aSocket, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPMessage */
#define NS_IUDPMESSAGE_IID_STR "333d5d69-8117-4aa6-9e16-2dd4fd6aeba6"

#define NS_IUDPMESSAGE_IID \
  {0x333d5d69, 0x8117, 0x4aa6, \
    { 0x9e, 0x16, 0x2d, 0xd4, 0xfd, 0x6a, 0xeb, 0xa6 }}

class NS_NO_VTABLE nsIUDPMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPMESSAGE_IID)

  /* readonly attribute nsINetAddr fromAddr; */
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) = 0;

  /* readonly attribute ACString data; */
  NS_IMETHOD GetData(nsACString & aData) = 0;

  /* readonly attribute nsIOutputStream outputStream; */
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPMessage, NS_IUDPMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPMESSAGE \
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr); \
  NS_IMETHOD GetData(nsACString & aData); \
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPMESSAGE(_to) \
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) { return _to GetFromAddr(aFromAddr); } \
  NS_IMETHOD GetData(nsACString & aData) { return _to GetData(aData); } \
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) { return _to GetOutputStream(aOutputStream); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPMESSAGE(_to) \
  NS_IMETHOD GetFromAddr(nsINetAddr * *aFromAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFromAddr(aFromAddr); } \
  NS_IMETHOD GetData(nsACString & aData) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetData(aData); } \
  NS_IMETHOD GetOutputStream(nsIOutputStream * *aOutputStream) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOutputStream(aOutputStream); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPMessage : public nsIUDPMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPMESSAGE

  nsUDPMessage();

private:
  ~nsUDPMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPMessage, nsIUDPMessage)

nsUDPMessage::nsUDPMessage()
{
  /* member initializers and constructor code */
}

nsUDPMessage::~nsUDPMessage()
{
  /* destructor code */
}

/* readonly attribute nsINetAddr fromAddr; */
NS_IMETHODIMP nsUDPMessage::GetFromAddr(nsINetAddr * *aFromAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute ACString data; */
NS_IMETHODIMP nsUDPMessage::GetData(nsACString & aData)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIOutputStream outputStream; */
NS_IMETHODIMP nsUDPMessage::GetOutputStream(nsIOutputStream * *aOutputStream)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIUDPSocket_h__ */
