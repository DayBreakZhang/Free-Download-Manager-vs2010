/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM e:/builds/moz2_slave/rel-m-beta-xr_w32_bld-00000000/build/netwerk/base/public/nsIUDPServerSocket.idl
 */

#ifndef __gen_nsIUDPServerSocket_h__
#define __gen_nsIUDPServerSocket_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#ifndef __gen_nsINetAddr_h__
#include "nsINetAddr.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIUDPServerSocketListener; /* forward declaration */

class nsIUDPMessage; /* forward declaration */

class nsISocketTransport; /* forward declaration */

class nsIOutputStream; /* forward declaration */

#include "mozilla/net/DNS.h"

/* starting interface:    nsIUDPServerSocket */
#define NS_IUDPSERVERSOCKET_IID_STR "c2a38bd0-024b-4ae8-bcb2-20d766b54389"

#define NS_IUDPSERVERSOCKET_IID \
  {0xc2a38bd0, 0x024b, 0x4ae8, \
    { 0xbc, 0xb2, 0x20, 0xd7, 0x66, 0xb5, 0x43, 0x89 }}

class NS_NO_VTABLE nsIUDPServerSocket : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSERVERSOCKET_IID)

  /* void init (in long aPort, in boolean aLoopbackOnly); */
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly) = 0;

  /* [noscript] void initWithAddress ([const] in NetAddrPtr aAddr); */
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr) = 0;

  /* void close (); */
  NS_IMETHOD Close(void) = 0;

  /* void asyncListen (in nsIUDPServerSocketListener aListener); */
  NS_IMETHOD AsyncListen(nsIUDPServerSocketListener *aListener) = 0;

  /* readonly attribute long port; */
  NS_IMETHOD GetPort(int32_t *aPort) = 0;

  /* [noscript] NetAddr getAddress (); */
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPServerSocket, NS_IUDPSERVERSOCKET_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSERVERSOCKET \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly); \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr); \
  NS_IMETHOD Close(void); \
  NS_IMETHOD AsyncListen(nsIUDPServerSocketListener *aListener); \
  NS_IMETHOD GetPort(int32_t *aPort); \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSERVERSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly) { return _to Init(aPort, aLoopbackOnly); } \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr) { return _to InitWithAddress(aAddr); } \
  NS_IMETHOD Close(void) { return _to Close(); } \
  NS_IMETHOD AsyncListen(nsIUDPServerSocketListener *aListener) { return _to AsyncListen(aListener); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return _to GetPort(aPort); } \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) { return _to GetAddress(_retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSERVERSOCKET(_to) \
  NS_IMETHOD Init(int32_t aPort, bool aLoopbackOnly) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aPort, aLoopbackOnly); } \
  NS_IMETHOD InitWithAddress(const mozilla::net::NetAddr *aAddr) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitWithAddress(aAddr); } \
  NS_IMETHOD Close(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->Close(); } \
  NS_IMETHOD AsyncListen(nsIUDPServerSocketListener *aListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->AsyncListen(aListener); } \
  NS_IMETHOD GetPort(int32_t *aPort) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPort(aPort); } \
  NS_IMETHOD GetAddress(mozilla::net::NetAddr *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAddress(_retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPServerSocket : public nsIUDPServerSocket
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSERVERSOCKET

  nsUDPServerSocket();

private:
  ~nsUDPServerSocket();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPServerSocket, nsIUDPServerSocket)

nsUDPServerSocket::nsUDPServerSocket()
{
  /* member initializers and constructor code */
}

nsUDPServerSocket::~nsUDPServerSocket()
{
  /* destructor code */
}

/* void init (in long aPort, in boolean aLoopbackOnly); */
NS_IMETHODIMP nsUDPServerSocket::Init(int32_t aPort, bool aLoopbackOnly)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] void initWithAddress ([const] in NetAddrPtr aAddr); */
NS_IMETHODIMP nsUDPServerSocket::InitWithAddress(const mozilla::net::NetAddr *aAddr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void close (); */
NS_IMETHODIMP nsUDPServerSocket::Close()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void asyncListen (in nsIUDPServerSocketListener aListener); */
NS_IMETHODIMP nsUDPServerSocket::AsyncListen(nsIUDPServerSocketListener *aListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long port; */
NS_IMETHODIMP nsUDPServerSocket::GetPort(int32_t *aPort)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] NetAddr getAddress (); */
NS_IMETHODIMP nsUDPServerSocket::GetAddress(mozilla::net::NetAddr *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPServerSocketListener */
#define NS_IUDPSERVERSOCKETLISTENER_IID_STR "0500a336-29b2-4df1-9103-911f8ee0a569"

#define NS_IUDPSERVERSOCKETLISTENER_IID \
  {0x0500a336, 0x29b2, 0x4df1, \
    { 0x91, 0x03, 0x91, 0x1f, 0x8e, 0xe0, 0xa5, 0x69 }}

class NS_NO_VTABLE nsIUDPServerSocketListener : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IUDPSERVERSOCKETLISTENER_IID)

  /* void onPacketReceived (in nsIUDPServerSocket aServ, in nsIUDPMessage aMessage); */
  NS_IMETHOD OnPacketReceived(nsIUDPServerSocket *aServ, nsIUDPMessage *aMessage) = 0;

  /* void onStopListening (in nsIUDPServerSocket aServ, in nsresult aStatus); */
  NS_IMETHOD OnStopListening(nsIUDPServerSocket *aServ, nsresult aStatus) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIUDPServerSocketListener, NS_IUDPSERVERSOCKETLISTENER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIUDPSERVERSOCKETLISTENER \
  NS_IMETHOD OnPacketReceived(nsIUDPServerSocket *aServ, nsIUDPMessage *aMessage); \
  NS_IMETHOD OnStopListening(nsIUDPServerSocket *aServ, nsresult aStatus); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIUDPSERVERSOCKETLISTENER(_to) \
  NS_IMETHOD OnPacketReceived(nsIUDPServerSocket *aServ, nsIUDPMessage *aMessage) { return _to OnPacketReceived(aServ, aMessage); } \
  NS_IMETHOD OnStopListening(nsIUDPServerSocket *aServ, nsresult aStatus) { return _to OnStopListening(aServ, aStatus); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIUDPSERVERSOCKETLISTENER(_to) \
  NS_IMETHOD OnPacketReceived(nsIUDPServerSocket *aServ, nsIUDPMessage *aMessage) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnPacketReceived(aServ, aMessage); } \
  NS_IMETHOD OnStopListening(nsIUDPServerSocket *aServ, nsresult aStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->OnStopListening(aServ, aStatus); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsUDPServerSocketListener : public nsIUDPServerSocketListener
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIUDPSERVERSOCKETLISTENER

  nsUDPServerSocketListener();

private:
  ~nsUDPServerSocketListener();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsUDPServerSocketListener, nsIUDPServerSocketListener)

nsUDPServerSocketListener::nsUDPServerSocketListener()
{
  /* member initializers and constructor code */
}

nsUDPServerSocketListener::~nsUDPServerSocketListener()
{
  /* destructor code */
}

/* void onPacketReceived (in nsIUDPServerSocket aServ, in nsIUDPMessage aMessage); */
NS_IMETHODIMP nsUDPServerSocketListener::OnPacketReceived(nsIUDPServerSocket *aServ, nsIUDPMessage *aMessage)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void onStopListening (in nsIUDPServerSocket aServ, in nsresult aStatus); */
NS_IMETHODIMP nsUDPServerSocketListener::OnStopListening(nsIUDPServerSocket *aServ, nsresult aStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIUDPMessage */
#define NS_IUDPMESSAGE_IID_STR "1587698a-60b6-4a8d-9df9-708cd793e24b"

#define NS_IUDPMESSAGE_IID \
  {0x1587698a, 0x60b6, 0x4a8d, \
    { 0x9d, 0xf9, 0x70, 0x8c, 0xd7, 0x93, 0xe2, 0x4b }}

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


#endif /* __gen_nsIUDPServerSocket_h__ */
